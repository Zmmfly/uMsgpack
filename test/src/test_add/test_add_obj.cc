#include "test_add.h"

tadd_def(fixmap)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0x8f
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
        err = ump_add_fixmap(hd, 0xf);
        if (err != UMP_EOK) {
            msg = "add fixmap failed";
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

tadd_def(fixarr)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0x9f
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
        err = ump_add_fixarr(hd, 0xf);
        if (err != UMP_EOK) {
            msg = "add fixarr failed";
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

tadd_def(nil)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xc0
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
        err = ump_add_nil(hd);
        if (err != UMP_EOK) {
            msg = "add nil failed";
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

tadd_def(false)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xc2
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
        err = ump_add_bool(hd, false);
        if (err != UMP_EOK) {
            msg = "add bool failed";
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

tadd_def(true)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xc3
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
        err = ump_add_bool(hd, true);
        if (err != UMP_EOK) {
            msg = "add bool failed";
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

tadd_def(arr16)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xdc,
            0x11, 0x22
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
        err = ump_add_arr16(hd, 0x1122);
        if (err != UMP_EOK) {
            msg = "add arr16 failed";
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

tadd_def(arr32)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xdd,
            0x11, 0x22, 0x33, 0x44,
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
        err = ump_add_arr32(hd, 0x11223344);
        if (err != UMP_EOK) {
            msg = "add array32 failed";
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

tadd_def(map16)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xde,
            0x11, 0x22
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
        err = ump_add_map16(hd, 0x1122);
        if (err) {
            msg = "add map16 failed";
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

tadd_def(map32)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xdf,
            0x11, 0x22, 0x33, 0x44
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
        err = ump_add_map32(hd, 0x11223344);
        if (err) {
            msg = "add map32 failed";
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
