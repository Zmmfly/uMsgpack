#include "uMsgpack_stfile.h"
#include <string.h>

int ump_st_file_read(ump_stream_file_t hd, void* arg)
{
    int            ret   = 0;
    ump_err        err   = UMP_FAIL;
    ump_arg_read_t rdarg = (ump_arg_read_t) arg;
    do{
        ret = fseeko64(hd->fp, hd->pos + rdarg->off, SEEK_SET);

        ret = fread(rdarg->ptr, 1, rdarg->len, hd->fp);
        if (ret < 0) {
            err = UMP_ERR_IO;
            break;
        }

        if (ret != rdarg->len) {
            err = UMP_ERR_READ;
            break;
        }

        if (!rdarg->mov) {
            fseeko64(hd->fp, -1 * rdarg->len - rdarg->off , SEEK_CUR);
        } else {
            hd->pos += rdarg->len;
            hd->pos += rdarg->off;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_file_req(ump_stream_file_t hd, void* arg)
{
    int           ret = 0;
    ump_err       err = UMP_FAIL;
    ump_arg_req_t req = (ump_arg_req_t) arg;
    do{
        if (*req == 0) break;

        if (hd->max != 0 && (hd->len + *req) > hd->max) {
            err = UMP_ERR_RANGEOVF;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_file_write(ump_stream_file_t hd, void* arg)
{
    int             ret   = 0;
    ump_err         err   = UMP_FAIL;
    ump_arg_write_t wrarg = (ump_arg_write_t) arg;
    do{
        ret = fseeko64(hd->fp, hd->pos + wrarg->off, SEEK_SET);

        ret = fwrite(wrarg->ptr, 1, wrarg->len, hd->fp);
        if (ret < 0) {
            err = UMP_ERR_IO;
            break;
        }

        if (ret != wrarg->len) {
            err = UMP_ERR_WRITE;
            break;
        }

        if (!wrarg->mov) {
            fseeko64(hd->fp, -1 * wrarg->len, SEEK_CUR);
        } else {
            hd->pos += wrarg->len;
            hd->pos += wrarg->off;
        }

        if (hd->pos >= hd->len) {
            hd->len += wrarg->len;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_file_seek(ump_stream_file_t hd, void* arg)
{
    int            ret     = 0;
    int            whence  = 0;
    ump_err        err     = UMP_FAIL;
    int64_t        pos     = 0;
    ump_arg_seek_t seekarg = (ump_arg_seek_t) arg;
    do{
        if (seekarg->whe == UMP_SEEK_BEG) {
            if (seekarg < 0) {
                err = UMP_ERR_RANGEOVF;
                break;
            }
            pos = seekarg->off;
        } else if (seekarg->whe == UMP_SEEK_END) {
            if (seekarg->off > hd->len) {
                err = UMP_ERR_RANGEOVF;
                break;
            }
            pos = hd->len - seekarg->off;
        } else if (seekarg->whe == UMP_SEEK_CUR) {
            pos = hd->pos + seekarg->off;
            if (pos < 0 || pos > hd->len) {
                err = UMP_ERR_RANGEOVF;
                break;
            }
        } else {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        ret = fseeko64(hd->fp, pos, SEEK_SET);
        if (ret < 0) {
            err = UMP_ERR_IO;
            break;
        }
        hd->pos = pos;
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_file_tell(ump_stream_file_t hd, void* arg)
{
    int64_t        ret     = 0;
    ump_err        err     = UMP_FAIL;
    ump_arg_tell_t tellarg = (ump_arg_tell_t) arg;
    do{
        ret = ftello64(hd->fp);
        if (ret < 0) {
            err = UMP_ERR_IO;
            break;
        }
        *tellarg = ret;
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_file_fn(ump_stream_t handle, ump_opcode opcode, void* oparg)
{
    ump_err           err = UMP_FAIL;
    ump_stream_file_t hd  = (ump_stream_file_t) handle;

    do {
        switch(opcode) {
            case UMP_OP_RD:
                err = ump_st_file_read(hd, oparg);
                break;
            case UMP_OP_REQ:
                err = ump_st_file_req(hd, oparg);
                break;
            case UMP_OP_WR:
                err = ump_st_file_write(hd, oparg);
                break;
            case UMP_OP_SEEK:
                err = ump_st_file_seek(hd, oparg);
                break;
            case UMP_OP_TELL:
                err = ump_st_file_tell(hd, oparg);
                break;
            default:
                err = UMP_ERR_UNSUPPORTED;
                break;
        }
    }while(0);
    return err;
}

ump_stream_file_t ump_st_file_create(const char* filepath, ump_memop_t memop)
{
    bool              ret = false;
    ump_stream_file_t st  = NULL;

    do{
        if (filepath == NULL || memop == NULL) break;
        if (memop->malloc == NULL || memop->free == NULL) break;
        st = (ump_stream_file_t)memop->calloc(1, sizeof(ump_stream_file));
        if (st == NULL) break;

        st->path = (char*)memop->calloc(1, strlen(filepath) + 1);
        if (st->path == NULL) break;
        
        strcpy(st->path, filepath);
        st->memop     = memop;
        st->stream.fn = ump_st_file_fn;

        ret = true;
    }while(0);

    if (!ret && st) {
        ump_st_file_destroy(st);
        st = NULL;
    }
    return st;
}

int ump_st_file_open(ump_stream_file_t st, uint64_t maxsize, bool seek2end)
{
    ump_err err = UMP_ERR_NULLPTR;
    do{
        if (st == NULL) break;
        if (st->path == NULL) break;

        st->fp  = fopen(st->path, "rb+");
        if (st->fp == NULL) {
            st->fp = fopen(st->path, "wb+");
            if (st->fp == NULL) {
                err = UMP_ERR_OPEN;
                break;
            }
        }
        st->max = maxsize;

        fseeko64(st->fp, 0, SEEK_END);
        st->len = ftello64(st->fp);
        if (!seek2end) {
            fseeko64(st->fp, 0, SEEK_SET);
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_file_close(ump_stream_file_t st)
{
    ump_err err = UMP_ERR_NULLPTR;
    do{
        if (st == NULL) break;
        if (st->fp == NULL) {
            err = UMP_EOK;
            break;
        }

        fclose(st->fp);
        st->fp = NULL;

        err = UMP_EOK;
    }while(0);
    return err;
}

void ump_st_file_destroy(ump_stream_file_t st)
{
    if (st == NULL) return;
    if (st->memop == NULL) return;
    if (st->memop->free == NULL) return;
    if (st->path) st->memop->free(st->path);
    if (st->fp != NULL) fclose(st->fp);
    st->memop->free(st);
}