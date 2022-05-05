#include "test_add.h"

tadd_def(bin8)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xc4, 0x10,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
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
        err = ump_add_bin8(hd, buf_exp+2, sizeof(buf_exp) - 2);
        if (err != UMP_EOK) {
            msg = "add bin8 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(bin16)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xc5, 0x00, 0x10,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
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
        err = ump_add_bin16(hd, buf_exp+3, sizeof(buf_exp) - 3);
        if (err != UMP_EOK) {
            msg = "add bin16 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(bin32)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xc6, 0x00, 0x00, 0x00, 0x10,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
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
        err = ump_add_bin32(hd, buf_exp+5, sizeof(buf_exp) - 5);
        if (err != UMP_EOK) {
            msg = "add bin32 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(ext8)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xc7, 0x10, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
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
        err = ump_add_ext8(hd, buf_exp+3, sizeof(buf_exp) - 3, 1);
        if (err != UMP_EOK) {
            msg = "add ext8 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(ext16)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xc8, 0x00, 0x10, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
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
        err = ump_add_ext16(hd, buf_exp+4, sizeof(buf_exp) - 4, 1);
        if (err != UMP_EOK) {
            msg = "add ext16 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(ext32)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xc9, 0x00, 0x00, 0x00, 0x10, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
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
        err = ump_add_ext32(hd, buf_exp+6, sizeof(buf_exp) - 6, 1);
        if (err != UMP_EOK) {
            msg = "add ext32 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(fixext1)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xd4, 0x01,
            0x00
    };
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
        err = ump_add_fixext1(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext1 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(fixext2)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xd5, 0x01,
            0x00, 0x01
    };
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
        err = ump_add_fixext2(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext2 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(fixext4)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xd6, 0x01,
            0x00, 0x01, 0x02, 0x03
    };
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
        err = ump_add_fixext4(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext4 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(fixext8)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xd7, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
    };
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
        err = ump_add_fixext8(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext8 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(fixext16)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xd8, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
    };
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
        err = ump_add_fixext16(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext16 failed";
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}
