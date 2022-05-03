#ifndef __U_MSGPACK_GET_H__
#define __U_MSGPACK_GET_H__

#include "uMsgpack_def.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int ump_get_pfixint(ump_handle_t hd, int8_t* val);

int ump_get_fixmap(ump_handle_t hd, uint8_t* val);
int ump_get_fixarray(ump_handle_t hd, uint8_t* val);

int ump_get_fixstr(ump_handle_t hd, char* buf, uint8_t* len);
int ump_get_nil(ump_handle_t hd);
int ump_get_bool(ump_handle_t hd, bool* val);

int ump_get_bin8(ump_handle_t hd, void* buf, uint8_t* len);
int ump_get_bin16(ump_handle_t hd, void* buf, uint16_t* len);
int ump_get_bin32(ump_handle_t hd, void* buf, uint32_t* len);

int ump_get_ext8(ump_handle_t hd, void* buf, uint8_t* len, uint8_t* type);
int ump_get_ext16(ump_handle_t hd, void* buf, uint16_t* len, uint8_t* type);
int ump_get_ext32(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type);

int ump_get_f32(ump_handle_t hd, float* val);
int ump_get_f64(ump_handle_t hd, double* val);

int ump_get_u8(ump_handle_t hd, uint8_t* val);
int ump_get_u16(ump_handle_t hd, uint16_t* val);
int ump_get_u32(ump_handle_t hd, uint32_t* val);
int ump_get_u64(ump_handle_t hd, uint64_t* val);

int ump_get_i8(ump_handle_t hd, int8_t* val);
int ump_get_i16(ump_handle_t hd, int16_t* val);
int ump_get_i32(ump_handle_t hd, int32_t* val);
int ump_get_i64(ump_handle_t hd, int64_t* val);

int ump_get_fixext1(ump_handle_t hd, void* buf, uint8_t* len, uint8_t* type);
int ump_get_fixext2(ump_handle_t hd, void* buf, uint8_t* len, uint8_t* type);
int ump_get_fixext4(ump_handle_t hd, void* buf, uint8_t* len, uint8_t* type);
int ump_get_fixext8(ump_handle_t hd, void* buf, uint8_t* len, uint8_t* type);
int ump_get_fixext16(ump_handle_t hd, void* buf, uint8_t* len, uint8_t* type);

int ump_get_str8(ump_handle_t hd, char* buf, uint8_t* len);
int ump_get_str16(ump_handle_t hd, char* buf, uint16_t* len);
int ump_get_str32(ump_handle_t hd, char* buf, uint32_t* len);

int ump_get_array16(ump_handle_t hd, uint16_t len);
int ump_get_array32(ump_handle_t hd, uint32_t len);

int ump_get_map16(ump_handle_t hd, uint16_t len);
int ump_get_map32(ump_handle_t hd, uint32_t len);

int ump_get_nfixint(ump_handle_t hd, int8_t val);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __U_MSGPACK_GET_H__
