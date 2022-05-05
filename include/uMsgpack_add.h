#ifndef __U_MSGPACK_ADD_H__
#define __U_MSGPACK_ADD_H__

#include "uMsgpack_def.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int ump_add_pfixint(ump_handle_t hd, uint8_t val);

int ump_add_fixmap(ump_handle_t hd, uint8_t val);
int ump_add_fixarr(ump_handle_t hd, uint8_t val);

int ump_add_fixstr(ump_handle_t hd, const char* val, uint8_t len);
int ump_add_nil(ump_handle_t hd);
int ump_add_bool(ump_handle_t hd, bool val);

int ump_add_bin8(ump_handle_t hd, const void* val, uint8_t len);
int ump_add_bin16(ump_handle_t hd, const void* val, uint16_t len);
int ump_add_bin32(ump_handle_t hd, const void* val, uint32_t len);

int ump_add_ext8(ump_handle_t hd, const void* val, uint8_t len, uint8_t type);
int ump_add_ext16(ump_handle_t hd, const void* val, uint16_t len, uint8_t type);
int ump_add_ext32(ump_handle_t hd, const void* val, uint32_t len, uint8_t type);

int ump_add_f32(ump_handle_t hd, float val);
int ump_add_f64(ump_handle_t hd, double val);

int ump_add_u8(ump_handle_t hd, uint8_t val);
int ump_add_u16(ump_handle_t hd, uint16_t val);
int ump_add_u32(ump_handle_t hd, uint32_t val);
int ump_add_u64(ump_handle_t hd, uint64_t val);

int ump_add_i8(ump_handle_t hd, int8_t val);
int ump_add_i16(ump_handle_t hd, int16_t val);
int ump_add_i32(ump_handle_t hd, int32_t val);
int ump_add_i64(ump_handle_t hd, int64_t val);

int ump_add_fixext1(ump_handle_t hd, const void* val, uint8_t len, uint8_t type);
int ump_add_fixext2(ump_handle_t hd, const void* val, uint8_t len, uint8_t type);
int ump_add_fixext4(ump_handle_t hd, const void* val, uint8_t len, uint8_t type);
int ump_add_fixext8(ump_handle_t hd, const void* val, uint8_t len, uint8_t type);
int ump_add_fixext16(ump_handle_t hd, const void* val, uint8_t len, uint8_t type);

int ump_add_str8(ump_handle_t hd, const char* val, uint8_t len);
int ump_add_str16(ump_handle_t hd, const char* val, uint16_t len);
int ump_add_str32(ump_handle_t hd, const char* val, uint32_t len);

int ump_add_arr16(ump_handle_t hd, uint16_t len);
int ump_add_arr32(ump_handle_t hd, uint32_t len);

int ump_add_map16(ump_handle_t hd, uint16_t len);
int ump_add_map32(ump_handle_t hd, uint32_t len);

int ump_add_nfixint(ump_handle_t hd, int8_t val);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __U_MSGPACK_H__
