#include "test_add.h"

tadd_def(pfixint)
{
    bool ret = false;
    int err;
    ump_handle_t     hd = nullptr;
    ump_stream_mem_t st = nullptr;
    do{
        hd = t_add_create_ump();
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        st = (ump_stream_mem_t)hd->stream;

        err = ump_add_pfixint(hd, 200);
        if (err == UMP_EOK) {
            msg = "range overflow, but not expected return: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_pfixint(hd, 0x7f);
        if (err != UMP_EOK) {
            msg = "range not overflow, but not expected return:";
            msg += std::to_string(err);
            break;
        }
        err = (int)ump_add_pfixint(hd, 0x20);

        if ( ((uint8_t*)st->buf)[0] != 0x7f ) {
            msg = "value 0x75 error";
            break;
        }

        if ( ((uint8_t*)st->buf)[1] != 0x20 ) {
            msg = "value 0x20 error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(f32)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xca, 
            0x3f, 0x0c, 0xcc, 0xcd, 
        0xca, 
            0x3f, 0xa3, 0xd7, 0x0a
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
        err = ump_add_f32(hd, 0.55);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }
        err = ump_add_f32(hd, 1.28);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
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

tadd_def(f64)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xcb, 
            0x3F, 0xE1, 0x99, 0x99, 0x99, 0x99, 0x99, 0x9A, 
        0xcb, 
            0x3F ,0xF4 ,0x7A ,0xE1 ,0x47 ,0xAE ,0x14 ,0x7B,
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
        err = ump_add_f64(hd, 0.55);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }
        err = ump_add_f64(hd, 1.28);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
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

tadd_def(u8)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xcc,
            0xff,
        0xcc,
            0xaa
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
        err = ump_add_u8(hd, 0xff);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_u8(hd, 0xaa);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
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

tadd_def(u16)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xcd,
            0xaa, 0xbb,
        0xcd,
            0xff, 0xee
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
        err = ump_add_u16(hd, 0xaabb);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_u16(hd, 0xffee);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
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

tadd_def(u32)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xce,
            0x11, 0x22, 0x33, 0x44,
        0xce,
            0x55, 0x66, 0x77, 0x88
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
        err = ump_add_u32(hd, 0x11223344);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_u32(hd, 0x55667788);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
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

tadd_def(u64)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xcf,
            0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
        0xcf,
            0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22
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
        err = ump_add_u64(hd, 0x1122334455667788);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_u64(hd, 0x9988776655443322);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
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

tadd_def(i8)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xd0,
            0x81,   // -127
        0xd0,
            0x40,   // 64
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
        err = ump_add_i8(hd, -127);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_i8(hd, 64);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
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

tadd_def(i16)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xd1,
            0x80, 0x01,   // -32767
        0xd1,
            0x7F, 0xFF,   // 32767
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
        err = ump_add_i16(hd, -32767);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_i16(hd, 32767);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            utils::hex::dump(buf, sizeof(buf_exp));
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(i32)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xd2,
            0x80, 0x00, 0x00, 0x01,   // -2147483647
        0xd2,
            0x7F, 0xFF, 0xFF, 0xFF,   // 2147483647
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
        err = ump_add_i32(hd, -2147483647);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_i32(hd, 2147483647);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            utils::hex::dump(buf, sizeof(buf_exp));
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(i64)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t         buf_exp[] = {
        0xd3,
            0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   // -9223372036854775807
        0xd3,
            0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,   // 9223372036854775807
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
        err = ump_add_i64(hd, -9223372036854775807);
        if (err != UMP_EOK) {
            msg = "Add value0 failed: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_i64(hd, 9223372036854775807u);
        if (err != UMP_EOK) {
            msg = "Add value1 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (memcmp(buf, buf_exp, sizeof(buf_exp)) != 0) {
            msg = "value error";
            utils::hex::dump(buf, sizeof(buf_exp));
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}

tadd_def(nfixint)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
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
        err = ump_add_nfixint(hd, -17);
        if (err == UMP_EOK) {
            msg = "range overflow, but not expected return: ";
            msg += std::to_string(err);
            break;
        }

        err = ump_add_nfixint(hd, -5);
        if (err != UMP_EOK) {
            msg = "range not overflow, but not expected return:";
            msg += std::to_string(err);
            break;
        }

        ump_add_nfixint(hd, -1);

        if (buf[0] != 0xfb || buf[1] != 0xff) {
            msg = "value error";
            break;
        }

        ret = true;
    }while(0);
    if (hd) t_add_destroy_ump(hd);
    return ret;
}
