#include "test_add.h"

tadd_def(fixstr)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    char             buf_exp[] = "hello world, this is a test";
    do{
        hd = t_add_create_ump();
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        st = (ump_stream_mem_t)hd->stream;
        buf = (uint8_t*)st->buf;

        //do something
        // msg = "not implemented";
        err = ump_add_fixstr(hd, buf_exp, sizeof(buf_exp));
        if (err != UMP_EOK) {
            msg = "add fixstr failed";
            break;
        }

        if (buf[0] != 0xbc) {
            msg = "type error";
            break;
        }

        if (memcmp(buf+1, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(str8)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    char             buf_exp[] = "hello world, this is a test";
    do{
        hd = t_add_create_ump();
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        st = (ump_stream_mem_t)hd->stream;
        buf = (uint8_t*)st->buf;

        //do something
        // msg = "not implemented";
        err = ump_add_str8(hd, buf_exp, sizeof(buf_exp));
        if (err != UMP_EOK) {
            msg = "add str8 failed";
            break;
        }

        if (buf[0] != 0xd9) {
            msg = "type error";
            break;
        }

        if (buf[1] != sizeof(buf_exp)) {
            msg = "size error";
            break;
        }

        if (memcmp(buf+2, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(str16)
{
    bool ret = false;
    int err;
    uint8_t*         buf       = nullptr;
    ump_handle_t     hd        = nullptr;
    ump_stream_mem_t st        = nullptr;
    char             buf_exp[] = "hello world, this is a test";
    do{
        hd = t_add_create_ump();
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        st = (ump_stream_mem_t)hd->stream;
        buf = (uint8_t*)st->buf;

        //do something
        // msg = "not implemented";
        err = ump_add_str16(hd, buf_exp, sizeof(buf_exp));
        if (err != UMP_EOK) {
            msg = "add str16 failed";
            break;
        }

        if (buf[0] != 0xda) {
            msg = "type error";
            break;
        }

        if (buf[1] != 0x00 || buf[2] != 0x1c) {
            msg = "size error";
            break;
        }

        if (memcmp(buf+3, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(str32)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    char             buf_exp[] = "hello world, this is a test";
    do{
        hd = t_add_create_ump();
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        st = (ump_stream_mem_t)hd->stream;
        buf = (uint8_t*)st->buf;

        //do something
        // msg = "not implemented";
        err = ump_add_str32(hd, buf_exp, sizeof(buf_exp));
        if (err != UMP_EOK) {
            msg = "add str32 failed";
            break;
        }

        if (buf[0] != 0xdb) {
            msg = "type error";
            break;
        }

        if (buf[1] != 0x00 || buf[2] != 0x00 || buf[3] != 0x00 || buf[4] != 0x1c) {
            msg = "size error";
            break;
        }

        if (memcmp(buf+5, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}
