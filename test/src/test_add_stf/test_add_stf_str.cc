#include "test_astf.h"

tastf_def(fixstr)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    // char             buf_exp[] = "hello world, this is a test";
    uint8_t buf_exp[] = {
        0xbb, 
            'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ',', ' ', 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't'
    };
    do{
        hd = t_astf_create_ump("stf_fixstr.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_fixstr(hd, (char*)buf_exp+1, sizeof(buf_exp)-1);
        if (err != UMP_EOK) {
            msg = "add fixstr failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_fixstr.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();
        if (str.size() != sizeof(buf_exp) ) {
            msg = "dump size not equal: ";
            msg += std::to_string(str.size());
            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal: ";
            msg += std::to_string(str.size());
            break;
        }
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(str8)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t buf_exp[] = {
        0xd9, 0x1b,
            'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ',', ' ', 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't'
    };
    do{
        hd = t_astf_create_ump("stf_str8.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_str8(hd, (char*)buf_exp+2, sizeof(buf_exp)-2);
        if (err != UMP_EOK) {
            msg = "add str8 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_str8.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();
        if (str.size() != sizeof(buf_exp) ) {
            msg = "dump size not equal: ";
            msg += std::to_string(str.size());
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

tastf_def(str16)
{
    bool ret = false;
    int err;
    ump_handle_t     hd        = nullptr;
    uint8_t buf_exp[] = {
        0xda, 0x00, 0x1b,
            'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ',', ' ', 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't'
    };
    do{
        hd = t_astf_create_ump("stf_str16.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_str16(hd, (char*)buf_exp+3, sizeof(buf_exp)-3);
        if (err != UMP_EOK) {
            msg = "add str16 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_str16.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();
        if (str.size() != sizeof(buf_exp) ) {
            msg = "dump size not equal: ";

            break;
        }

        if (memcmp(buf_exp, str.data(), sizeof(buf_exp)) != 0) {
            msg = "dump data not equal";
            break;
        }
        ret = true;
        ret = true;
    }while(0);
    if (hd) t_astf_destroy_ump(hd);
    return ret;
}

tastf_def(str32)
{
    bool ret = false;
    int err;
    uint8_t*         buf = nullptr;
    ump_handle_t     hd  = nullptr;
    ump_stream_mem_t st  = nullptr;
    uint8_t buf_exp[] = {
        0xdb, 0x00, 0x00, 0x00, 0x1b,
            'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ',', ' ', 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't'
    };
    do{
        hd = t_astf_create_ump("stf_str32.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_str32(hd, (char*)buf_exp+5, sizeof(buf_exp)-5);
        if (err != UMP_EOK) {
            msg = "add str32 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_str32.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();
        if (str.size() != sizeof(buf_exp) ) {
            msg = "dump size not equal: ";
            msg += std::to_string(str.size());
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
