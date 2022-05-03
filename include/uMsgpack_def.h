#ifndef __U_MSGPACK_DEF_H__
#define __U_MSGPACK_DEF_H__

#include <stdint.h>
#include <stdbool.h>
#include "uMsgpack_type.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef enum ump_err
{
    /* no error */
    UMP_EOK = 0,
    /* fail */
    UMP_FAIL = -200,
    /* arg has null ptr */
    UMP_ERR_NULLPTR,
    /* arg has invalid value */
    UMP_ERR_INVALID_ARG,
    /* not enough memory */
    UMP_ERR_NOMEM,
    /* range overflow */
    UMP_ERR_RANGEOVF,
    /* not supported */
    UMP_ERR_UNSUPPORTED,
    /* invalid stream */
    UMP_ERR_INVALID_STREAM,
    /* type error */
    UMP_ERR_TYPE,
    /* ended */
    UMP_ERR_EOF,
    /* unknown error */
    UMP_ERR_UNKNOWN,
}ump_err;

typedef enum ump_opcode
{
    UMP_OP_OPEN,
    UMP_OP_RD,
    UMP_OP_WR,
    UMP_OP_SEEK,
    UMP_OP_TELL,
    UMP_OP_REQ,
    UMP_OP_DONE,
    UMP_OP_CLOSE,
    UMP_OP_MAX
}ump_opcode;

typedef struct ump_memop{
    void* (*malloc)(size_t);
    void* (*calloc)(size_t, size_t);
    void* (*realloc)(void*, size_t);
    void (*free)(void*);
}ump_memop;
typedef ump_memop* ump_memop_t;
extern ump_memop ump_memop_default;

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
    size_t len;
}ump_arg_read;

typedef ump_arg_read ump_arg_write;

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
    uint64_t off;
    ump_seek_dir whe;
}ump_arg_seek;

/**
 * @brief tell arg, relative to the starting position
 * 
 */
typedef uint64_t* ump_arg_tell;

/**
 * @brief req arg, request for memory
 * 
 */
typedef uint64_t* ump_arg_req;

/**
 * @brief done arg, ctx
 * 
 */
typedef void* ump_arg_done;

/**
 * @brief close arg, ctx
 * 
 */
typedef void* ump_arg_close;

/**
 * @brief ump stream handle
 * 
 */
typedef struct ump_stream ump_stream;
typedef ump_err(*ump_stream_fn_t)(ump_stream* handle, ump_opcode opcode, void* oparg);
typedef struct ump_stream
{
    void* ctx;
    ump_stream_fn_t fn;
}ump_stream;
typedef ump_stream* ump_stream_t;

/**
 * @brief ump handle
 * 
 */
typedef struct ump_handle
{
    ump_stream_t stream;
    ump_err lasterr;
    uint64_t dec_pos;
    uint64_t dec_nxt;
}ump_handle;
typedef ump_handle* ump_handle_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __U_MSGPACK_DEF_H__