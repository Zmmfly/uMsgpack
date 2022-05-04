#include "uMsgpack_utils.h"

/**
 * @brief Check ump handle is valid or not.
 * 
 * @param hd 
 * @return int 
 */
int ump_check_handle(ump_handle_t hd)
{
    if (hd == NULL) return UMP_ERR_NULLPTR;
    if (hd->stream == NULL) return UMP_ERR_INVALID_STREAM;
    if (hd->stream->fn == NULL) return UMP_ERR_INVALID_STREAM;
    return UMP_EOK;
}

/**
 * @brief ump open stream.
 * 
 * @param hd 
 * @return int 
 */
int ump_st_open(ump_handle_t hd)
{
    int ret = ump_check_handle(hd);
    if (ret != UMP_EOK) return ret;
    ret = UMP_FAIL;
    do{
        ret = hd->stream->fn(hd->stream, UMP_OP_OPEN, hd->stream->ctx);
    }while(0);
    return ret;
}

/**
 * @brief ump stream done.
 * 
 * @param hd 
 * @return int 
 */
int ump_st_done(ump_handle_t hd)
{
    int ret = ump_check_handle(hd);
    if (ret != UMP_EOK) return ret;
    ret = UMP_FAIL;
    do{
        ret = hd->stream->fn(hd->stream, UMP_OP_DONE, hd->stream->ctx);
    }while(0);
    return ret;
}

/**
 * @brief ump close stream.
 * 
 * @param hd 
 * @return int 
 */
int ump_st_close(ump_handle_t hd)
{
    int ret = ump_check_handle(hd);
    if (ret != UMP_EOK) return ret;
    ret = UMP_FAIL;
    do{
        ret = hd->stream->fn(hd->stream, UMP_OP_CLOSE, hd->stream->ctx);
    }while(0);
    return ret;
}

/**
 * @brief ump read data from stream.
 * 
 * @param hd 
 * @param ptr 
 * @param len 
 * @param move move pos after read
 * @return int 
 */
int ump_st_read(ump_handle_t hd, void* ptr, size_t len, bool move)
{
    ump_arg_read arg;
    int ret = ump_check_handle(hd);
    if (ret != UMP_EOK) return ret;
    ret = UMP_FAIL;
    do{
        if (ptr == NULL || len == 0) {
            ret = UMP_ERR_INVALID_ARG;
            break;
        }
        arg.ptr = ptr;
        arg.len = len;
        arg.mov = move;
        ret = hd->stream->fn(hd->stream, UMP_OP_RD, &arg);
    }while(0);
    return ret;
}

/**
 * @brief ump write data to stream.
 * 
 * @param hd 
 * @param ptr 
 * @param len 
 * @param move move pos after write
 * @return int 
 */
int ump_st_write(ump_handle_t hd, void* ptr, size_t len, bool move)
{
    ump_arg_write arg;
    int ret = ump_check_handle(hd);
    if (ret != UMP_EOK) return ret;
    ret = UMP_FAIL;
    do{
        if (ptr == NULL || len == 0) {
            ret = UMP_ERR_INVALID_ARG;
            break;
        }
        arg.ptr = ptr;
        arg.len = len;
        arg.mov = move;
        ret = hd->stream->fn(hd->stream, UMP_OP_WR, &arg);
    }while(0);
    return ret;
}

/**
 * @brief ump seek stream.
 * 
 * @param hd 
 * @param offset 
 * @param whence 
 * @return int 
 */
int ump_st_seek(ump_handle_t hd, uint64_t offset, ump_seek_dir whence)
{
    ump_arg_seek arg;
    int ret = ump_check_handle(hd);
    if (ret != UMP_EOK) return ret;
    ret = UMP_FAIL;
    do{
        arg.off = offset;
        arg.whe = whence;
        ret = hd->stream->fn(hd->stream, UMP_OP_SEEK, &arg);
    }while(0);
    return ret;
}

/**
 * @brief ump tell stream.
 * 
 * @param hd 
 * @param offset 
 * @return int 
 */
int ump_st_tell(ump_handle_t hd, uint64_t* offset)
{
    int ret = ump_check_handle(hd);
    if (ret != UMP_EOK) return ret;
    ret = UMP_FAIL;
    do{
        if (offset == NULL) {
            ret = UMP_ERR_INVALID_ARG;
            break;
        }
        ret = hd->stream->fn(hd->stream, UMP_OP_TELL, offset);
    }while(0);
    return ret;
}

/**
 * @brief ump request free space from stream.
 * 
 * @param hd 
 * @param len 
 * @return int 
 */
int ump_st_req(ump_handle_t hd, uint64_t len)
{
    int ret = ump_check_handle(hd);
    if (ret != UMP_EOK) return ret;
    ret = UMP_FAIL;
    do{
        ret = hd->stream->fn(hd->stream, UMP_OP_REQ, &len);
    }while(0);
    return ret;
}
