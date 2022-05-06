#ifndef __U_MSGPACK_TYPE_H__
#define __U_MSGPACK_TYPE_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef enum ump_type
{
    ump_type_pfint = 0x00,
    ump_type_fmap  = 0x80,
    ump_type_farr  = 0x90,
    ump_type_fstr  = 0xA0,
    ump_type_nil   = 0xC0,
    ump_type_false = 0xC2,
    ump_type_true  = 0xC3,
    ump_type_b8    = 0xC4,
    ump_type_b16   = 0xC5,
    ump_type_b32   = 0xC6,
    ump_type_e8    = 0xC7,
    ump_type_e16   = 0xC8,
    ump_type_e32   = 0xC9,
    ump_type_f32   = 0xCA,
    ump_type_f64   = 0xCB,
    ump_type_u8    = 0xCC,
    ump_type_u16   = 0xCD,
    ump_type_u32   = 0xCE,
    ump_type_u64   = 0xCF,
    ump_type_i8    = 0xD0,
    ump_type_i16   = 0xD1,
    ump_type_i32   = 0xD2,
    ump_type_i64   = 0xD3,
    ump_type_fe1   = 0xD4,
    ump_type_fe2   = 0xD5,
    ump_type_fe4   = 0xD6,
    ump_type_fe8   = 0xD7,
    ump_type_fe16  = 0xD8,
    ump_type_s8    = 0xD9,
    ump_type_s16   = 0xDA,
    ump_type_s32   = 0xDB,
    ump_type_a16   = 0xDC,
    ump_type_a32   = 0xDD,
    ump_type_m16   = 0xDE,
    ump_type_m32   = 0xDF,
    ump_type_nfint = 0xE0
}ump_type;
typedef ump_type* ump_type_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif