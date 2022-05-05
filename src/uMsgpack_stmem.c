#include <string.h>
#include "uMsgpack_stmem.h"
#include "uMsgpack_utils.h"

#ifdef CONFIG_UMSGPACK_DEFAULT_MEMOP
#include <stdlib.h>
ump_memop ump_memop_default = {
    .malloc  = malloc,
    .calloc  = calloc,
    .realloc = realloc,
    .free    = free
};
#endif

int ump_st_mem_fn(ump_stream_t hd, ump_opcode opcode, void* arg);

/**
 * @brief Create a ump_stream_mem
 * 
 * @param len The length of the buffer initalized
 * @param memop 
 * @return ump_stream_mem_t 
 */
ump_stream_mem_t ump_st_mem_create(uint64_t len, ump_memop_t memop)
{
    bool             valid  = false;
    ump_stream_mem_t mem_st = NULL;
    do{
        if (memop == NULL) break;
        if (memop->malloc == NULL || memop->calloc == NULL) break;
        if (memop->free == NULL || memop->realloc == NULL) break;

        // create mem stream
        mem_st = (ump_stream_mem_t)memop->calloc(1, sizeof(ump_stream_mem));
        if (mem_st == NULL) break;

        // init mem stream
        mem_st->stream.fn = ump_st_mem_fn;
        mem_st->buf = memop->calloc(1, len);
        if (mem_st->buf == NULL) break;
        mem_st->spc = len;
        mem_st->memop = memop;

        valid = true;
    }while(0);
    if (valid) return mem_st;
    if (mem_st) {
        if (mem_st->buf) {
            mem_st->memop->free(mem_st->buf);
        }
        mem_st->memop->free(mem_st);
        mem_st = NULL;
    }
    return mem_st;
}

/**
 * @brief Create a mem stream for a given buffer
 * @note This function does not copy or free the input buffer.
 * 
 * @param buf 
 * @param len 
 * @param memop 
 * @return ump_stream_mem_t 
 */
ump_stream_mem_t ump_st_mem_create_with(void* buf, uint64_t len, ump_memop_t memop)
{
    bool             valid  = false;
    ump_stream_mem_t mem_st = NULL;
    do{
        if (buf == NULL || len == 0) break;
        if (memop == NULL) break;
        if (memop->malloc == NULL || memop->calloc == NULL) break;
        if (memop->free == NULL || memop->realloc == NULL) break;

        // create mem stream
        mem_st = (ump_stream_mem_t)memop->calloc(1, sizeof(ump_stream_mem));
        if (mem_st == NULL) break;

        // init mem stream
        mem_st->stream.fn = ump_st_mem_fn;
        mem_st->buf   = buf;
        mem_st->spc   = 0;
        mem_st->len   = len;
        mem_st->memop = memop;

        valid = true;
    }while(0);
    if (valid) return mem_st;
    if (mem_st) {
        if (mem_st->buf) {
            mem_st->memop->free(mem_st->buf);
        }
        mem_st->memop->free(mem_st);
        mem_st = NULL;
    }
    return mem_st;
}

/**
 * @brief Destroy a ump_stream_mem
 * @note This function will free the buffer if spc not zero.
 * 
 * @param st 
 * @return int 
 */
int ump_st_mem_destroy(ump_stream_mem_t st)
{
    ump_err err = UMP_FAIL;
    do{
        if (st == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        if (st->memop == NULL) {
            err = UMP_ERR_INVALID_STREAM;
            break;
        }
        if (st->spc != 0 && st->buf) {
            st->memop->free(st->buf);
        }
        st->memop->free(st);
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_mem_open(ump_stream_mem_t hd, void* arg)
{
    ump_err err = UMP_FAIL;
    do{
        if (hd == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        if (hd->buf == NULL && hd->spc) {
            hd->buf = hd->memop->malloc(hd->spc);
            err = (hd->buf == NULL) ? UMP_ERR_NOMEM : UMP_EOK;
            break;
        }
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_mem_done(ump_stream_mem_t hd, void* arg)
{
    ump_err err = UMP_FAIL;
    do{
        if (hd == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        //do something
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_mem_close(ump_stream_mem_t hd, void* arg)
{
    ump_err err = UMP_FAIL;
    do{
        if (hd == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }

        if (hd->buf == NULL || hd->memop == NULL) {
            err = UMP_ERR_INVALID_STREAM;
        }

        if (hd->buf != NULL && hd->spc == 0) {
            err = UMP_ERR_CLOSE4DECODE;
            break;
        }

        hd->memop->free(hd->buf);
        hd->buf = NULL;
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_mem_read(ump_stream_mem_t hd, void *arg)
{
    ump_err err = UMP_FAIL;
    ump_arg_read_t rdarg = (ump_arg_read_t) arg;
    do{
        if (hd == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        if (rdarg == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        if (rdarg->ptr == NULL || rdarg->len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (hd->len - (hd->pos + rdarg->off) < rdarg->len) {
            err = UMP_ERR_RANGEOVF;
            break;
        }
        memcpy(rdarg->ptr, hd->buf + hd->pos + rdarg->off, rdarg->len);
        if (rdarg->mov) {
            hd->pos += rdarg->len;
            hd->pos += rdarg->off;
        }
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_mem_write(ump_stream_mem_t hd, void *arg)
{
    ump_err err = UMP_FAIL;
    ump_arg_write_t wrarg = (ump_arg_write_t) arg;
    do{
        if (hd == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        if (wrarg == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        if (wrarg->ptr == NULL || wrarg->len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if ( (hd->pos+wrarg->off+wrarg->len) > hd->spc) {
            err = UMP_ERR_RANGEOVF;
            break;
        }
        memcpy(hd->buf+hd->pos+wrarg->off, wrarg->ptr, wrarg->len);
        if (wrarg->mov) {
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

int ump_st_mem_seek(ump_stream_mem_t hd, void* arg)
{
    ump_err err = UMP_FAIL;
    ump_arg_seek_t sekarg = (ump_arg_seek_t)arg;
    do{
        if (sekarg == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }

        if (sekarg->whe == UMP_SEEK_BEG) {
            if (sekarg->off < 0) {
                err = UMP_ERR_RANGEOVF;
                break;
            }

            if (hd->spc == 0) {
                if (sekarg->off > hd->len) {
                    err = UMP_ERR_RANGEOVF;
                    break;
                } else if (sekarg->off == hd->len) {
                    err = UMP_ERR_EOF;
                    break;
                }
            } else {
                if (sekarg->off > hd->spc) {
                    err = UMP_ERR_RANGEOVF;
                    break;
                } else if (sekarg->off == hd->spc) {
                    err = UMP_ERR_EOF;
                    break;
                }
            }
            hd->pos = sekarg->off;
        }
        else if (sekarg->whe == UMP_SEEK_CUR) {
            if (((sekarg->off + hd->pos) < 0) || ((sekarg->off + hd->pos) > (hd->spc==0?hd->len:hd->spc))) 
            {
                err = UMP_ERR_RANGEOVF;
                break;
            }
            hd->pos += sekarg->off;
        }
        else if (sekarg->whe == UMP_SEEK_END) {
            if ((sekarg->off + hd->len) > (hd->spc==0?hd->len:hd->spc)) {
                err = UMP_ERR_RANGEOVF;
                break;
            }
            hd->pos = hd->len + sekarg->off;
        }
        else {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_mem_tell(ump_stream_mem_t hd, void* arg)
{
    ump_err err = UMP_FAIL;
    uint64_t* out = (uint64_t*)arg;
    do{
        if (out == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        //TODO pos ? or pos+1 ?
        *out = hd->pos;
        //*out = hd->pos+1;
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_mem_req(ump_stream_mem_t hd, void* arg)
{
    ump_err err = UMP_FAIL;
    uint64_t req = 0;
    uint8_t rev = 20;
    void *tmp = NULL;
    do{
        if (arg == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        if (hd == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }
        if (hd->memop == NULL) {
            err = UMP_ERR_INVALID_MEMOP;
        }
        req = *((uint64_t*)arg);
        if (req == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (req < (hd->spc - hd->pos) ) {
            err = UMP_EOK;
            break;
        }
        tmp = hd->memop->realloc(hd->buf, hd->spc + req + rev);
        if (tmp == NULL) {
            err = UMP_ERR_NOMEM;
            break;
        }
        hd->buf = tmp;
        hd->spc = hd->spc + req + rev;
        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_st_mem_fn(ump_stream_t hd, ump_opcode opcode, void* arg)
{
    ump_err err = UMP_FAIL;
    ump_stream_mem_t memst = (ump_stream_mem_t)hd;
    do{
        if (hd == NULL) {
            err = UMP_ERR_NULLPTR;
            break;
        }

        if (memst->buf == NULL) {
            err = UMP_ERR_INVALID_STREAM;
            break;
        }

        switch(opcode) {
            case UMP_OP_OPEN:
                err = ump_st_mem_open(memst, arg);
                break;
            case UMP_OP_RD:
                err = ump_st_mem_read(memst, arg);
                break;
            case UMP_OP_WR:
                err = ump_st_mem_write(memst, arg);
                break;
            case UMP_OP_SEEK:
                err = ump_st_mem_seek(memst, arg);
                break;
            case UMP_OP_TELL:
                err = ump_st_mem_tell(memst, arg);
                break;
            case UMP_OP_DONE:
                err = ump_st_mem_done(memst, arg);
                break;
            case UMP_OP_CLOSE:
                err = ump_st_mem_close(memst, arg);
                break;
            case UMP_OP_REQ:
                err = ump_st_mem_req(memst, arg);
                break;
            default:
                err = UMP_ERR_UNSUPPORTED;
                break;
        }
    }while(0);
    return err;
}
