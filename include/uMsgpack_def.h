#ifndef __U_MSGPACK_DEF_H__
#define __U_MSGPACK_DEF_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "uMsgpack_type.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef enum ump_err
{
    /* no error */
    UMP_EOK = 0,
    UMP_EOF,
    UMP_FAIL = -200,
    UMP_ERR_UNKNOWN,
    UMP_ERR_UNSUPPORTED,
    UMP_ERR_NULLPTR,
    UMP_ERR_NOMEM,
    UMP_ERR_RANGEOVF,
    UMP_ERR_TYPE,
    UMP_ERR_READ,
    UMP_ERR_WRITE,
    UMP_ERR_OPEN,
    UMP_ERR_CLOSE,
    UMP_ERR_IO,
    UMP_ERR_DECODEONLY,
    UMP_ERR_INVALID_ARG,
    UMP_ERR_INVALID_TYPE,
    UMP_ERR_INVALID_STREAM,
    UMP_ERR_INVALID_MEMOP,
    UMP_ERR_INVALID_HANDLE,
}ump_err;

/**
 * @brief uMsgpack stream operations, used in uMsgpack internal, not for user.
 *        And, OPEN and CLOSE, and DONE, are not used for current version.
 * 
 */
typedef enum ump_opcode
{
    UMP_OP_RD,
    UMP_OP_REQ,
    UMP_OP_WR,
    UMP_OP_SEEK,
    UMP_OP_TELL,
    UMP_OP_MAX
}ump_opcode;

/**
 * @brief Memory operations, used in uMsgpack internal, its useful for non-standard memory management.
 * 
 */
typedef struct ump_memop{
    void* (*malloc)(size_t);
    void* (*calloc)(size_t, size_t);
    void* (*realloc)(void*, size_t);
    void (*free)(void*);
}ump_memop;
typedef ump_memop* ump_memop_t;

/**
 * @brief open arg is ctx
 * 
 */
typedef void* ump_arg_open;

/**
 * @brief read arg
 * 
 * @param ptr the buf ptr
 * @param len the buf len for want to read
 * 
 */
typedef struct ump_arg_read
{
    void *ptr;
    int64_t off;
    size_t len;
    bool mov;
}ump_arg_read;
typedef ump_arg_read* ump_arg_read_t;

typedef ump_arg_read ump_arg_write;
typedef ump_arg_write* ump_arg_write_t;

/**
 * @brief seek dir arg enum
 * 
 */
typedef enum ump_seek_dir
{
    /* position for begin */
    UMP_SEEK_BEG,
    /* position for current */
    UMP_SEEK_CUR,
    /* position for end */
    UMP_SEEK_END,
    UMP_SEEK_MAX
}ump_seek_dir;

/**
 * @brief seek arg
 * 
 * @param off offset for dir
 * @param whe seek whence
 * 
 */
typedef struct ump_arg_seek
{
    int64_t off;
    ump_seek_dir whe;
}ump_arg_seek;
typedef ump_arg_seek* ump_arg_seek_t;

/**
 * @brief tell arg, relative to the starting position
 * 
 */
typedef uint64_t ump_arg_tell;
typedef ump_arg_tell* ump_arg_tell_t;

/**
 * @brief req arg, request for memory
 * 
 */
typedef uint64_t ump_arg_req;
typedef ump_arg_req* ump_arg_req_t;

/**
 * @brief done arg, and open arg, and close arg, are NULL for current version.
 * 
 */
//typedef void* ump_arg_done;

/**
 * @brief ump stream handle
 * 
 */
typedef struct ump_stream ump_stream;
typedef ump_stream* ump_stream_t;
typedef int(*ump_stream_fn_t)(ump_stream_t handle, ump_opcode opcode, void* oparg);
typedef struct ump_stream
{
    ump_stream_fn_t fn;
}ump_stream;
// typedef ump_stream* ump_stream_t;

/**
 * @brief ump handle
 * 
 */
typedef struct ump_handle
{
    ump_stream_t stream;
    ump_err err;
    uint64_t dec_pos;
    uint64_t dec_nxt;
}ump_handle;
typedef ump_handle* ump_handle_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __U_MSGPACK_DEF_H__