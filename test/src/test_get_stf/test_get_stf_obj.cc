#include "test_gstf.h"

tgstf_def(fixmap)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint32_t     num       = 0;
    uint8_t      msgpack[] = {
        0x81
    };
    do{
        hd = t_gstf_create_ump("gstf_fixmap.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // fixmap
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_fmap) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_fixmap(hd, &num);
        if (err != UMP_EOK) {
            msg = "ump_get_fixmap failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (num != 1) {
            msg = "ump_get_fixmap num error: ";
            msg += std::to_string(num);
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(fixarr)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint32_t     num       = 0;
    uint8_t      be[4]     = {0x00, 0x00, 0x00, 0x00};
    uint8_t      msgpack[] = {
        0x91
    };
    do{
        hd = t_gstf_create_ump("gstf_fixarr.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // fixarr
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_farr) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_fixarr(hd, &num);
        if (err != UMP_EOK) {
            msg = "ump_get_fixarr failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (num != 1) {
            msg = "ump_get_fixarr num error: ";
            msg += std::to_string(num);
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(nil)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_false;
    uint8_t      be[4]     = {0x00, 0x00, 0x00, 0x00};
    uint8_t      msgpack[] = {
        0xc0
    };
    do{
        hd = t_gstf_create_ump("gstf_nil.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // nil
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_nil) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_nil(hd);
        if (err != UMP_EOK) {
            msg = "ump_get_nil failed: ";
            msg += ump_strerr(err);
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(false)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    bool         out       = true;
    uint8_t      be[4]     = {0x00, 0x00, 0x00, 0x00};
    uint8_t      msgpack[] = {
        0xc2
    };
    do{
        hd = t_gstf_create_ump("gstf_false.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // false
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_false) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_bool(hd, &out);
        if (err != UMP_EOK) {
            msg = "ump_get_bool failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (out != false) {
            msg = "ump_get_bool out error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(true)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    bool         out       = false;
    uint8_t      be[4]     = {0x00, 0x00, 0x00, 0x00};
    uint8_t      msgpack[] = {
        0xc3
    };
    do{
        hd = t_gstf_create_ump("gstf_true.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // true
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_true) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_bool(hd, &out);
        if (err != UMP_EOK) {
            msg = "ump_get_bool failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (out != true) {
            msg = "ump_get_bool out error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(fixext1)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint8_t      mtype     = 0;
    uint8_t      data[1]   = {0};
    uint32_t     len       = sizeof(data);
    uint8_t      msgpack[] = {
        0xd4, 0xA1, 0xF2
    };
    do{
        hd = t_gstf_create_ump("gstf_fixext1.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // fixext1
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_fe1) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_fixext1(hd, data, &len, &mtype);
        if (err != UMP_EOK) {
            msg = "ump_get_fixext1 failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (mtype != 0xA1) {
            msg = "ump_get_fixext1 mtype error";
            break;
        }

        if (data[0] != 0xF2) {
            msg = "ump_get_fixext1 data error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(fixext2)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint8_t      mtype     = 0;
    uint8_t      data[2]   = {0};
    uint32_t     len       = sizeof(data);
    uint8_t      msgpack[] = {
        0xd5, 0xA2, 0xBC, 0xAD
    };
    do{
        hd = t_gstf_create_ump("gstf_fixext2.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // fixext2
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_fe2) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_fixext2(hd, data, &len, &mtype);
        if (err != UMP_EOK) {
            msg = "ump_get_fixext2 failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (mtype != 0xA2) {
            msg = "ump_get_fixext2 mtype error";
            break;
        }

        if (data[0] != 0xBC || data[1] != 0xAD) {
            msg = "ump_get_fixext2 data error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(fixext4)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint8_t      mtype     = 0;
    uint8_t      data[4]   = {0};
    uint32_t     len       = sizeof(data);
    uint8_t      msgpack[] = {
        0xd6, 0xA3, 0xBC, 0xAD, 0xBE, 0xEF
    };
    do{
        hd = t_gstf_create_ump("gstf_fixext4.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // fixext4
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_fe4) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_fixext4(hd, data, &len, &mtype);
        if (err != UMP_EOK) {
            msg = "ump_get_fixext4 failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (mtype != 0xA3) {
            msg = "ump_get_fixext4 mtype error";
            break;
        }

        if (data[0] != 0xBC || data[1] != 0xAD || data[2] != 0xBE || data[3] != 0xEF) {
            msg = "ump_get_fixext4 data error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(fixext8)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint8_t      mtype     = 0;
    uint8_t      data[8]   = {0};
    uint32_t     len       = sizeof(data);
    uint8_t      msgpack[] = {
        0xd7, 0xA4, 0xBC, 0xAD, 0xBE, 0xEF, 0xBC, 0xAD, 0xBE, 0xEF
    };
    do{
        hd = t_gstf_create_ump("gstf_fixext8.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // fixext8
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_fe8) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_fixext8(hd, data, &len, &mtype);
        if (err != UMP_EOK) {
            msg = "ump_get_fixext8 failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (mtype != 0xA4) {
            msg = "ump_get_fixext8 mtype error";
            break;
        }

        if (data[0] != 0xBC || data[1] != 0xAD || data[2] != 0xBE || data[3] != 0xEF ||
            data[4] != 0xBC || data[5] != 0xAD || data[6] != 0xBE || data[7] != 0xEF) {
            msg = "ump_get_fixext8 data error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(fixext16)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint8_t      mtype     = 0;
    uint8_t      data[16]  = {0};
    uint32_t     len       = sizeof(data);
    uint8_t      msgpack[] = {
        0xd8, 0xA5, 
        0xBC, 0xAD, 0xBE, 0xEF, 0xBC, 0xAD, 0xBE, 0xEF,
        0xBC, 0xAD, 0xBE, 0xEF, 0xBC, 0xAD, 0xBE, 0xEF
    };
    do{
        hd = t_gstf_create_ump("gstf_fixext16.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // fixext16
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_fe16) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_fixext16(hd, data, &len, &mtype);
        if (err != UMP_EOK) {
            msg = "ump_get_fixext16 failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (mtype != 0xA5) {
            msg = "ump_get_fixext16 mtype error";
            break;
        }

        if (data[0] != 0xBC || data[1] != 0xAD || data[2] != 0xBE || data[3] != 0xEF ||
            data[4] != 0xBC || data[5] != 0xAD || data[6] != 0xBE || data[7] != 0xEF ||
            data[8] != 0xBC || data[9] != 0xAD || data[10] != 0xBE || data[11] != 0xEF ||
            data[12] != 0xBC || data[13] != 0xAD || data[14] != 0xBE || data[15] != 0xEF) 
        {
            msg = "ump_get_fixext16 data error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(arr16)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint32_t     num       = 0;
    uint8_t      msgpack[] = {
        0xdc, 0x11, 0x22
    };
    do{
        hd = t_gstf_create_ump("gstf_arr16.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // arr16
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_a16) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_arr16(hd, &num);
        if (err != UMP_EOK) {
            msg = "ump_get_arr16 failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (num != 0x1122) {
            msg = "ump_get_arr16 num error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(arr32)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint32_t     num       = 0;
    uint8_t      msgpack[] = {
        0xdd, 0x11, 0x22, 0x33, 0x44
    };
    do{
        hd = t_gstf_create_ump("gstf_arr32.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // arr32
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_a32) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_arr32(hd, &num);
        if (err != UMP_EOK) {
            msg = "ump_get_arr32 failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (num != 0x11223344) {
            msg = "ump_get_arr32 num error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(map16)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint32_t     num       = 0;
    uint8_t      msgpack[] = {
        0xde, 0x11, 0x22
    };
    do{
        hd = t_gstf_create_ump("gstf_map16.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // map16
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_m16) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_map16(hd, &num);
        if (err != UMP_EOK) {
            msg = "ump_get_map16 failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (num != 0x1122) {
            msg = "ump_get_map16 num error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(map32)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint32_t     num       = 0;
    uint8_t      msgpack[] = {
        0xdf, 0x11, 0x22, 0x33, 0x44
    };
    do{
        hd = t_gstf_create_ump("gstf_map32.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        // map32
        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_m32) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_map32(hd, &num);
        if (err != UMP_EOK) {
            msg = "ump_get_map32 failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (num != 0x11223344) {
            msg = "ump_get_map32 num error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}
