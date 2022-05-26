#include "test_get.h"

static std::string chkstr = "Hello,uMsgpack!";

tget_def(fixstr)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      msgpack[] = {
        0xAF, 
            'H', 'e', 'l', 'l', 'o', 
            ',', 'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_get_create_ump(msgpack, sizeof(msgpack));
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

        if (type != ump_type_fstr) {
            msg = "ump next type error: ";
            msg += std::to_string(type);
            break;
        }

        // err = ump_get_fixstr(hd, nullptr, &len);
        // if (err != UMP_EOK) {
        //     msg = "ump_get_fstr len failed: ";
        //     msg += ump_strerr(err);
        //     break;
        // }

        if (len != 0xf) {
            msg = "ump_get_fixstr len error: ";
            msg += std::to_string(len);
            break;
        }

        err = ump_get_fixstr(hd, buf, &len);
        if (err != UMP_EOK) {
            msg = "ump_get_fixstr value failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (chkstr != buf) {
            msg = "ump_get_fixstr value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_get_destroy_ump(hd);
    return ret;
}

tget_def(str8)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      msgpack[] = {
        0xd9, 0x0f,
            'H', 'e', 'l', 'l', 'o', ',', 
            'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_get_create_ump(msgpack, sizeof(msgpack));
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

        if (type != ump_type_s8) {
            msg = "ump next type error";
            break;
        }

        // err = ump_get_str8(hd, nullptr, &len);
        // if (err != UMP_EOK) {
        //     msg = "ump_get_str8 len failed: ";
        //     msg += ump_strerr(err);
        //     break;
        // }

        if (len != 0xf) {
            msg = "ump_get_str8 len error";
            break;
        }

        err = ump_get_str8(hd, buf, &len);
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
    if (hd) t_get_destroy_ump(hd);
    return ret;
}

tget_def(str16)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      msgpack[] = {
        0xda, 0x00, 0x0f,
            'H', 'e', 'l', 'l', 'o', ',', 
            'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_get_create_ump(msgpack, sizeof(msgpack));
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

        if (type != ump_type_s16) {
            msg = "ump next type error";
            break;
        }

        // err = ump_get_str16(hd, nullptr, &len);
        // if (err != UMP_EOK) {
        //     msg = "ump_get_str16 len failed: ";
        //     msg += ump_strerr(err);
        //     break;
        // }

        if (len != 0xf) {
            msg = "ump_get_str16 len error";
            break;
        }

        err = ump_get_str16(hd, buf, &len);
        if (err != UMP_EOK) {
            msg = "ump_get_str16 value failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (chkstr != buf) {
            msg  = "ump_get_str16 value error: ";
            msg += buf;
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_get_destroy_ump(hd);
    return ret;
}

tget_def(str32)
{
    bool         ret       = false;
    ump_handle_t hd        = nullptr;
    int          err       = UMP_FAIL;
    ump_type     type      = ump_type_nil;
    char         buf[128]  = {0};
    uint32_t     len       = 0;
    uint8_t      msgpack[] = {
        0xdb, 0x00, 0x00, 0x00, 0x0f,
            'H', 'e', 'l', 'l', 'o', ',', 
            'u', 'M', 's', 'g', 'p', 'a', 'c', 'k', '!'
    };
    do{
        hd = t_get_create_ump(msgpack, sizeof(msgpack));
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

        if (type != ump_type_s32) {
            msg = "ump next type error";
            break;
        }

        // err = ump_get_str32(hd, nullptr, &len);
        // if (err != UMP_EOK) {
        //     msg = "ump_get_str32 len failed: ";
        //     msg += ump_strerr(err);
        //     break;
        // }

        if (len != 0xf) {
            msg = "ump_get_str32 len error";
            break;
        }

        err = ump_get_str32(hd, buf, &len);
        if (err != UMP_EOK) {
            msg = "ump_get_str32 value failed: ";
            msg += ump_strerr(err);
            break;
        }

        if (chkstr != buf) {
            msg  = "ump_get_str32 value error: ";
            msg += buf;
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_get_destroy_ump(hd);
    return ret;
}

