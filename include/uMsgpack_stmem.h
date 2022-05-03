#ifndef __U_MSGPACK_ST_MEM_H__
#define __U_MSGPACK_ST_MEM_H__

#include "uMsgpack_def.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


#ifdef CONFIG_UMSGPACK_DEFAULT_MEMOP
extern ump_memop ump_memop_default;
#endif

/**
 * @brief ump mem stream
 * 
 */
typedef struct ump_stream_mem
{
    ump_stream stream;
    void* buf;
    /* zero for decode */
    uint64_t spc;
    uint64_t len;
    uint64_t pos;
    ump_memop_t memop;
}ump_stream_mem;
typedef ump_stream_mem* ump_stream_mem_t;

ump_stream_mem_t ump_st_mem_create(uint64_t len, ump_memop_t memop);
ump_stream_mem_t ump_st_mem_create_with(const void* buf, uint64_t len, ump_memop_t memop);
int ump_st_mem_destroy(ump_stream_mem_t st);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __U_MSGPACK_ST_MEM_H__