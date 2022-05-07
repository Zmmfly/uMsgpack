#include "test_gstf.h"
#include <math.h>

tgstf_def(pfixint)
{
    bool ret = true;
    uint8_t msgpack[] = {
        0x7f, 0x70
    };
    int err;
    int8_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_pfint.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_pfint) {
            msg = "ump type is not pfixint";
            break;
        }

        err = ump_get_pfixint(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get pfixint 0 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != 0x7f) {
            msg = "ump pfixint value 0 error: ";
            msg += std::to_string(val);
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next should not be failed";
            break;
        }

        err = ump_get_pfixint(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get pfixint 1 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != 0x70) {
            msg = "ump pfixint value 1 error: ";
            msg += std::to_string(val);
            break;
        }

        err = ump_next(hd, &type);
        if (err == UMP_EOK) {
            msg = "ump next should be eof";
            break;
        }
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(nfixint)
{
    bool ret = true;
    uint8_t msgpack[] = {
        246, 251
    };
    int err;
    int8_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_nfint.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_nfint) {
            msg = "ump type is not pfixint";
            break;
        }

        err = ump_get_nfixint(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get nfixint 0 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != -10) {
            msg = "ump nfixint value 0 error: ";
            msg += std::to_string(val);
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next should not be failed";
            break;
        }

        err = ump_get_nfixint(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get nfixint 1 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != -5) {
            msg = "ump nfixint value 1 error: ";
            msg += std::to_string(val);
            break;
        }

        err = ump_next(hd, &type);
        if (err == UMP_EOK) {
            msg = "ump next should be eof";
            break;
        }
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(f32)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xca, 0x3b, 0xa3, 0xd7, 0x0a
    };
    float val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_f32.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_f32) {
            msg = "ump next type error: ";
            msg += std::to_string(type);
            break;
        }

        err = ump_get_f32(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (fabs(0.005 - val) > 0.001) {
            msg = "ump value error: ";
            msg += std::to_string(val);
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(f64)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xcb, 0x3F, 0xE1, 0xEB, 0x85, 0x1E, 0xB8, 0x51, 0xEC
    };
    double val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_f64.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_f64) {
            char buf[4];
            msg = "ump next type error: ";
            snprintf(buf, 4, "%02x", type);
            msg += buf;
            break;
        }

        err = ump_get_f64(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (fabs(0.56 - val) > 0.00000001) {
            msg = "ump value error: ";
            msg += std::to_string(val);
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}


tgstf_def(u8)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xcc, 0xff
    };
    uint8_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_u8.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_u8) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_u8(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != 0xff) {
            msg = "ump u8 value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(u16)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xcd, 0xaa, 0xbb
    };
    uint16_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_u16.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_u16) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_u16(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != 0xaabb) {
            msg = "ump value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(u32)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xce, 0xaa, 0xbb, 0xcc, 0xdd
    };
    uint32_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_u32.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_u32) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_u32(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != 0xaabbccdd) {
            msg = "ump value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(u64)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xcf, 0x11, 0x22, 0x33, 0x44, 0xaa, 0xbb, 0xcc, 0xdd
    };
    uint64_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_u64.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_u64) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_u64(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != 0x11223344aabbccdd) {
            msg = "ump value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(i8)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xd0, 0x81
    };
    int8_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_i8.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_i8) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_i8(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != -127) {
            msg = "ump value error: ";
            msg += std::to_string(val);
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(i16)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xd1, 0xaa, 0xbb
    };
    int16_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_i16.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_i16) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_i16(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != -21829) {
            msg = "ump value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(i32)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xd2, 0xaa, 0xbb, 0xcc, 0xdd
    };
    int32_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_i32.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_i32) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_i32(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != -1430532899) {
            msg = "ump value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(i64)
{
    bool ret = false;
    int err = 0;
    uint8_t msgpack[] = {
        0xd3, 0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88
    };
    int64_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_gstf_create_ump("gstf_i64.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_i64) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_i64(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != -4822678189205112) {
            msg = "ump value error: ";
            msg += std::to_string(val);
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}