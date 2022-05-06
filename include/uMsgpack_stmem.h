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
    uint64_t spc;
    uint64_t len;
    uint64_t pos;
    ump_memop_t memop;
}ump_stream_mem;
typedef ump_stream_mem* ump_stream_mem_t;

/**
 * @brief Create memory stream for given length and memory operation
 * 
 * @param len 
 * @param memop 
 * @return ump_stream_mem_t NULL on error
 */
ump_stream_mem_t ump_st_mem_create(uint64_t len, ump_memop_t memop);

/**
 * @brief Create memory stream for given buffer and memory operation, this stream will not copy and 
 *  free the buffer
 * 
 * @param buf 
 * @param len 
 * @param memop 
 * @return ump_stream_mem_t NULL on error
 */
ump_stream_mem_t ump_st_mem_create_with(void* buf, uint64_t len, ump_memop_t memop);

/**
 * @brief Destroy memory stream
 * 
 * @param st 
 * @return int UMP_EOK on success
 */
int ump_st_mem_destroy(ump_stream_mem_t st);

/**
 * @brief Get memory stream buffer, the buffer is not copied, invalid after stream destroyed or reallocated
 * 
 * @param st 
 * @return uint8_t* 
 */
uint8_t* ump_st_mem_get_buf(ump_stream_mem_t st, uint64_t* len);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __U_MSGPACK_ST_MEM_H__