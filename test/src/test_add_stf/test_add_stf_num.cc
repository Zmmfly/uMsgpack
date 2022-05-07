#include "test_astf.h"

tastf_def(pfixint)
{
    bool ret = false;
    int err;
    ump_handle_t     hd = nullptr;
    char buf_exp[] = {
        0x7f
    };
    do{
        hd = t_astf_create_ump("stf_pfixint.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_pfixint(hd, 0x7f);
        if (err != UMP_EOK) {
            msg = "add pfixint failed:";
            msg += ump_strerr(err);
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_pfixint.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(f32)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xca, 
            0x3f, 0x0c, 0xcc, 0xcd
    };
    do{
        hd = t_astf_create_ump("stf_f32.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_f32(hd, 0.55);
        if (err != UMP_EOK) {
            msg = "add f32 failed:";
            msg += ump_strerr(err);
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_f32.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(f64)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xcb, 
            0x3F, 0xE1, 0x99, 0x99, 0x99, 0x99, 0x99, 0x9A
    };
    do{
        hd = t_astf_create_ump("stf_f64.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_f64(hd, 0.55);
        if (err != UMP_EOK) {
            msg = "add f64 failed:";
            msg += ump_strerr(err);
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_f64.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(u8)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xcc,
            0xaa
    };
    do{
        hd = t_astf_create_ump("stf_u8.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_u8(hd, 0xaa);
        if (err != UMP_EOK) {
            msg = "add u8 failed:";
            msg += ump_strerr(err);
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_u8.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(u16)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xcd,
            0xaa, 0xbb,
        0xcd,
            0xff, 0xee
    };
    do{
        hd = t_astf_create_ump("stf_u16.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_u16(hd, 0xaabb);
        if (err != UMP_EOK) {
            msg = "add u16 failed:";
            msg += ump_strerr(err);
            break;
        }

        err = ump_add_u16(hd, 0xffee);
        if (err != UMP_EOK) {
            msg = "add u16 failed:";
            msg += ump_strerr(err);
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_u16.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(u32)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xce,
            0x11, 0x22, 0x33, 0x44,
        0xce,
            0x55, 0x66, 0x77, 0x88
    };
    do{
        hd = t_astf_create_ump("stf_u32.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_u32(hd, 0x11223344);
        if (err != UMP_EOK) {
            msg = "add u32 failed:";
            msg += ump_strerr(err);
            break;
        }

        err = ump_add_u32(hd, 0x55667788);
        if (err != UMP_EOK) {
            msg = "add u32 failed:";
            msg += ump_strerr(err);
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_u32.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(u64)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xcf,
            0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
        0xcf,
            0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22
    };
    do{
        hd = t_astf_create_ump("stf_u64.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_u64(hd, 0x1122334455667788);
        if (err != UMP_EOK) {
            msg = "add u64 failed:";
            msg += ump_strerr(err);
            break;
        }

        err = ump_add_u64(hd, 0x9988776655443322);
        if (err != UMP_EOK) {
            msg = "add u64 failed:";
            msg += ump_strerr(err);
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_u64.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(i8)
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
        hd = t_astf_create_ump("stf_i8.umpk");
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

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_i8.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(i16)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xd1,
            0x80, 0x01,   // -32767
        0xd1,
            0x7F, 0xFF,   // 32767
    };
    do{
        hd = t_astf_create_ump("stf_i16.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

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

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_i16.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(i32)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xd2,
            0x80, 0x00, 0x00, 0x01,   // -2147483647
        0xd2,
            0x7F, 0xFF, 0xFF, 0xFF,   // 2147483647
    };
    do{
        hd = t_astf_create_ump("stf_i32.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

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

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_i32.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(i64)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xd3,
            0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,   // -9223372036854775807
        0xd3,
            0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,   // 9223372036854775807
    };
    do{
        hd = t_astf_create_ump("stf_i64.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

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

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_i64.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(nfixint)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t           buf_exp[] = {
        0xfb
    };
    do{
        hd = t_astf_create_ump("stf_nfixint.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_nfixint(hd, -5);
        if (err != UMP_EOK) {
            msg = "range not overflow, but not expected return:";
            msg += std::to_string(err);
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_nfixint.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
            msg = "dump size not equal";
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}
