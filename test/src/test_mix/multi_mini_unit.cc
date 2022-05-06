#include "test_mix.h"
#include "test_get.h"

typedef union num_un{
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    uint64_t u64;
    int8_t i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;
}num_un;

static uint8_t      msgpack[] = {
    /* positive fixint, 14 */
    0x0e,
    /* fixstr */
    0xaf,
        'H', 'e', 'l', 'l', 'o', ',', 'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!',
    /* nil */
    0xc0,
    /* false */
    0xc2,
    /* true */
    0xc3,
    /* bin8 */
    0xc4, 0x06, 
        'Z', 'm', 'm', 'f', 'l', 'y',
    /* bin16 */
    0xc5, 0x00, 0x04, 
        'H', 'a', 'l', 'o',
    /* bin32 */
    0xc6, 0x00, 0x00, 0x00, 0x0c,
        'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!',
    /* ext8 */
    0xc7, 
        0x08, 
        0x01, 
        'u', 'M', 's', 'g', 'p', 'a', 'c', 'k',
    /* ext16 */
    0xc8, 
        0x00, 0x0B, 
        0x02,
        'N', 'e', 'w', ' ', 'M', 's', 'g', 'p', 'a', 'c', 'k',
    /* ext32 */
    0xc9, 
        0x00, 0x00, 0x00, 0x09, 
        0x03,
        'l', 'i', 'g', 'h', 't', 'w', 'e', 'i', 'g',
    /* float32, 0.005 */
    0xca, 
        0x3b, 0xa3, 0xd7, 0x0a,
    /* float64, 0.00005 */
    0xcb, 
        0x3F, 0x0A, 0x36, 0xE2, 0xEB, 0x1C, 0x43, 0x2D,
    /* uint8 */
    0xcc, 
        0x01,
    /* uint16 */
    0xcd,
        0x03, 0x04,
    /* uint32 */
    0xce,
        0x05, 0x06, 0x07, 0x08,
    /* uint64 */
    0xcf,
        0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
    /* int8, 1 */
    0xd0, 
        0x01,
    /* int16, 772 */
    0xd1,
        0x03, 0x04,
    /* int32, 84281096 */
    0xd2,
        0x05, 0x06, 0x07, 0x08,
    /* int64, -8572026794359779568 */
    0xd3,
        0x89, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
    /* str8 */
    0xd9, 0x05, 
        'H', 'e', 'l', 'l', 'o',
    /* str16 */
    0xda, 0x00, 0x04, 
        'H', 'a', 'l', 'o',
    /* str32 */
    0xdb, 0x00, 0x00, 0x00, 0x0c,
        'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!',
    /* negative fixint, -1 */
    0xff
};

static ump_type msgpack_type_seq[] = {
    ump_type_pfint,
    ump_type_fstr,
    ump_type_nil,
    ump_type_false,
    ump_type_true,
    ump_type_b8,
    ump_type_b16,
    ump_type_b32,
    ump_type_e8,
    ump_type_e16,
    ump_type_e32,
    ump_type_f32,
    ump_type_f64,
    ump_type_u8,
    ump_type_u16,
    ump_type_u32,
    ump_type_u64,
    ump_type_i8,
    ump_type_i16,
    ump_type_i32,
    ump_type_i64,
    ump_type_s8,
    ump_type_s16,
    ump_type_s32,
    ump_type_nfint,
};

tmix_def(multi_miniunit)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    num_un num1;
    num_un num2;
    do{
        hd = t_get_create_ump(msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        for (size_t i=0; i<sizeof(msgpack_type_seq)/sizeof(ump_type); i++)
        {
            err = ump_next(hd, &type);
            if (err != UMP_EOK) {
                msg = "No.";
                msg += std::to_string(i);
                msg += ", ump_next failed: ";
                msg += ump_strerr(err);
                break;
            }

            if (type != msgpack_type_seq[i]) {
                msg = "No.";
                msg += std::to_string(i);
                msg += ", type is not expected: ";
                msg += std::to_string(type);
                msg += ", expected: ";
                msg += std::to_string(msgpack_type_seq[i]);
                break;
            }
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOF || err == UMP_EOK) {
            msg = "ump_next end error: ";
            msg += ump_strerr(err);
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_get_destroy_ump(hd);
    return ret;
}