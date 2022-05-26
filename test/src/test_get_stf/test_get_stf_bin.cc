#include "test_gstf.h"

static std::string chkstr = "Hello,uMsgpack!";

tgstf_def(bin8)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      msgpack[] = {
        0xc4, 0x0f,
            'H', 'e', 'l', 'l', 'o', ',', 
            'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_gstf_create_ump("gstf_bin8.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        err = ump_next(hd, &type, &len);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_b8) {
            msg = "ump next type error";
            break;
        }

        // err = ump_get_bin8(hd, nullptr, &len);
        // if (err != UMP_EOK) {
        //     msg = "ump_get_str8 len failed: ";
        //     msg += ump_strerr(err);
        //     break;
        // }

        if (len != 0xf) {
            msg = "ump_get_bin8 len error: ";
            msg += std::to_string(len);
            break;
        }

        err = ump_get_bin8(hd, buf, &len);
        if (err != UMP_EOK) {
            msg = "ump_get_str8 value failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (chkstr != buf) {
            msg  = "ump_get_str8 value error: ";
            msg += buf;
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(bin16)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      msgpack[] = {
        0xc5, 0x00, 0x0f,
            'H', 'e', 'l', 'l', 'o', ',', 
            'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_gstf_create_ump("gstf_bin16.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        err = ump_next(hd, &type, &len);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_b16) {
            msg = "ump next type error";
            break;
        }

        // err = ump_get_bin16(hd, nullptr, &len);
        // if (err != UMP_EOK) {
        //     msg = "ump_get_bin16 len failed: ";
        //     msg += ump_strerr(err);
        //     break;
        // }

        if (len != 0xf) {
            msg = "ump_get_bin16 len error: ";
            msg += std::to_string(len);
            break;
        }

        err = ump_get_bin16(hd, buf, &len);
        if (err != UMP_EOK) {
            msg = "ump_get_bin16 value failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (chkstr != buf) {
            msg  = "ump_get_bin16 value error: ";
            msg += buf;
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(bin32)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      msgpack[] = {
        0xc6, 0x00, 0x00, 0x00, 0x0f,
            'H', 'e', 'l', 'l', 'o', ',', 
            'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_gstf_create_ump("gstf_bin32.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        err = ump_next(hd, &type, &len);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_b32) {
            msg = "ump next type error";
            break;
        }

        // err = ump_get_bin32(hd, nullptr, &len);
        // if (err != UMP_EOK) {
        //     msg = "ump_get_bin32 len failed: ";
        //     msg += ump_strerr(err);
        //     break;
        // }

        if (len != 0xf) {
            msg = "ump_get_bin32 len error: ";
            msg += std::to_string(len);
            break;
        }

        err = ump_get_bin32(hd, buf, &len);
        if (err != UMP_EOK) {
            msg = "ump_get_bin32 value failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (chkstr != buf) {
            msg  = "ump_get_bin32 value error: ";
            msg += buf;
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}


tgstf_def(ext8)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      dtype     = 0;
    uint8_t      msgpack[] = {
        0xc7, 0x0f, 0x01, 
            'H', 'e', 'l', 'l', 'o', ',', 
            'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_gstf_create_ump("gstf_ext8.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        err = ump_next(hd, &type, NULL);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_e8) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_ext8(hd, nullptr, &len, &dtype);
        if (err != UMP_EOK) {
            msg = "ump_get_ext8 len failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (len != 0xf) {
            msg = "ump_get_ext8 len error: ";
            msg += std::to_string(len);
            break;
        }

        if (dtype != 0x01) {
            msg = "ump_get_ext8 dtype error";
            break;
        }

        err = ump_get_ext8(hd, buf, &len, nullptr);
        if (err != UMP_EOK) {
            msg = "ump_get_ext8 value failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (chkstr != buf) {
            msg  = "ump_get_ext8 value error: ";
            msg += buf;
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(ext16)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint8_t      dtype     = 0;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      msgpack[] = {
        0xc8, 0x00, 0x0f, 0x02,
            'H', 'e', 'l', 'l', 'o', ',', 
            'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_gstf_create_ump("gstf_ext16.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        err = ump_next(hd, &type, NULL);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_e16) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_ext16(hd, nullptr, &len, &dtype);
        if (err != UMP_EOK) {
            msg = "ump_get_ext16 len failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (len != 0xf) {
            msg = "ump_get_ext16 len error: ";
            msg += std::to_string(len);
            break;
        }

        if (dtype != 0x02) {
            msg = "ump_get_ext16 dtype error";
            break;
        }

        err = ump_get_ext16(hd, buf, &len, nullptr);
        if (err != UMP_EOK) {
            msg = "ump_get_ext16 value failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (chkstr != buf) {
            msg  = "ump_get_ext16 value error: ";
            msg += buf;
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}

tgstf_def(ext32)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    uint8_t      dtype     = 0;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      msgpack[] = {
        0xc9, 0x00, 0x00, 0x00, 0x0f, 0x03,
            'H', 'e', 'l', 'l', 'o', ',', 
            'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_gstf_create_ump("gstf_ext32.umpk", msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        //do something
        err = ump_next(hd, &type, NULL);
        if (err != UMP_EOK) {
            msg = "ump_next failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (type != ump_type_e32) {
            msg = "ump next type error";
            break;
        }

        err = ump_get_ext32(hd, nullptr, &len, &dtype);
        if (err != UMP_EOK) {
            msg = "ump_get_ext32 len failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (len != 0xf) {
            msg = "ump_get_ext32 len error: ";
            msg += std::to_string(len);
            break;
        }

        if (dtype != 0x03) {
            msg = "ump_get_ext32 dtype error";
            break;
        }

        err = ump_get_ext32(hd, buf, &len, nullptr);
        if (err != UMP_EOK) {
            msg = "ump_get_ext32 value failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (chkstr != buf) {
            msg  = "ump_get_ext32 value error: ";
            msg += buf;
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_gstf_destroy_ump(hd);
    return ret;
}
