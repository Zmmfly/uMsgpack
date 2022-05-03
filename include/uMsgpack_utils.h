#ifndef __U_MSGPACK_UTILS_H__
#define __U_MSGPACK_UTILS_H__

#include "uMsgpack_def.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int ump_st_open(ump_handle* hd);
int ump_st_done(ump_handle* hd);
int ump_st_close(ump_handle* hd);

int ump_st_read(ump_handle* hd, void* ptr, size_t len);
int ump_st_write(ump_handle* hd, void* ptr, size_t len);
int ump_st_seek(ump_handle* hd, uint64_t offset, ump_seek_dir whence);
int ump_st_tell(ump_handle* hd, uint64_t* offset);
int ump_st_req(ump_handle* hd, uint64_t len);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __U_MSGPACK_UTILS_H__