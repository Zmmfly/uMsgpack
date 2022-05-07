#include "test_astf.h"

tastf_def(bin8)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xc4, 0x10,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
    do{
        hd = t_astf_create_ump("stf_bin8.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_bin8(hd, buf_exp+2, sizeof(buf_exp) - 2);
        if (err != UMP_EOK) {
            msg = "add bin8 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_bin8.umpk", std::ios::binary | std::ios::in);
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

tastf_def(bin16)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xc5, 0x00, 0x10,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
    do{
        hd = t_astf_create_ump("stf_bin16.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_bin16(hd, buf_exp+3, sizeof(buf_exp) - 3);
        if (err != UMP_EOK) {
            msg = "add bin16 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_bin16.umpk", std::ios::binary | std::ios::in);
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

tastf_def(bin32)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xc6, 0x00, 0x00, 0x00, 0x10,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
    do{
        hd = t_astf_create_ump("stf_bin32.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_bin32(hd, buf_exp+5, sizeof(buf_exp) - 5);
        if (err != UMP_EOK) {
            msg = "add bin32 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_bin32.umpk", std::ios::binary | std::ios::in);
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

tastf_def(ext8)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xc7, 0x10, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
    do{
        hd = t_astf_create_ump("stf_ext8.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_ext8(hd, buf_exp+3, sizeof(buf_exp) - 3, 1);
        if (err != UMP_EOK) {
            msg = "add ext8 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_ext8.umpk", std::ios::binary | std::ios::in);
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

tastf_def(ext16)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xc8, 0x00, 0x10, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
    do{
        hd = t_astf_create_ump("stf_ext16.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_ext16(hd, buf_exp+4, sizeof(buf_exp) - 4, 1);
        if (err != UMP_EOK) {
            msg = "add ext16 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_ext16.umpk", std::ios::binary | std::ios::in);
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

tastf_def(ext32)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xc9, 0x00, 0x00, 0x00, 0x10, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    };
    do{
        hd = t_astf_create_ump("stf_ext32.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_ext32(hd, buf_exp+6, sizeof(buf_exp) - 6, 1);
        if (err != UMP_EOK) {
            msg = "add ext32 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_ext32.umpk", std::ios::binary | std::ios::in);
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
