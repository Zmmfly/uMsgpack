#ifndef __U_MSGPACK_ST_FILE_H__
#define __U_MSGPACK_ST_FILE_H__

#include "uMsgpack_def.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct ump_stream_file
{
    ump_stream stream;
    FILE* fp;
    char *path;
    uint64_t len;
    uint64_t max;
    uint64_t pos;
    ump_memop_t memop;
}ump_stream_file;
typedef ump_stream_file* ump_stream_file_t;

/**
 * @brief Create a stream for file.
 * 
 * @param path File path
 * @param memop memory operation
 * @return ump_stream_file_t 
 */
ump_stream_file_t ump_st_file_create(const char* path, ump_memop_t memop);

/**
 * @brief Open a stream for file.
 * 
 * @param st 
 * @param maxsize The max size for add data, if 0, no limit or for decode.
 * @param seek2end Seek to end of file, usually for append data to file.
 * @return int 
 */
int ump_st_file_open(ump_stream_file_t st, uint64_t maxsize, bool seek2end);

/**
 * @brief Close a stream for file.
 * 
 * @param st 
 * @return int 
 */
int ump_st_file_close(ump_stream_file_t st);

/**
 * @brief Destroy a stream for file.
 * 
 * @param st 
 */
void ump_st_file_destroy(ump_stream_file_t st);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __U_MSGPACK_ST_FILE_H__
