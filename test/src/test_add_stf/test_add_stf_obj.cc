#include "test_astf.h"

tastf_def(fixmap)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0x8f
    };
    do{
        hd = t_astf_create_ump("stf_fixmap.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_fixmap(hd, 0xf);
        if (err != UMP_EOK) {
            msg = "add fixmap failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_fixmap.umpk", std::ios::binary | std::ios::in);
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

tastf_def(fixarr)
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
        hd = t_astf_create_ump("stf_fixarr.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_fixarr(hd, 0xf);
        if (err != UMP_EOK) {
            msg = "add fixarr failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_fixarr.umpk", std::ios::binary | std::ios::in);
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

tastf_def(nil)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xc0
    };
    do{
        hd = t_astf_create_ump("stf_nil.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_nil(hd);
        if (err != UMP_EOK) {
            msg = "add nil failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_nil.umpk", std::ios::binary | std::ios::in);
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

tastf_def(false)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xc2
    };
    do{
        hd = t_astf_create_ump("stf_false.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_bool(hd, false);
        if (err != UMP_EOK) {
            msg = "add bool failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_false.umpk", std::ios::binary | std::ios::in);
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

tastf_def(true)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xc3
    };
    do{
        hd = t_astf_create_ump("stf_true.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_bool(hd, true);
        if (err != UMP_EOK) {
            msg = "add bool failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_true.umpk", std::ios::binary | std::ios::in);
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

tastf_def(arr16)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xdc,
            0x11, 0x22
    };
    do{
        hd = t_astf_create_ump("stf_arr16.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_arr16(hd, 0x1122);
        if (err != UMP_EOK) {
            msg = "add arr16 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_arr16.umpk", std::ios::binary | std::ios::in);
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

tastf_def(arr32)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xdd,
            0x11, 0x22, 0x33, 0x44,
    };
    do{
        hd = t_astf_create_ump("stf_arr32.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_arr32(hd, 0x11223344);
        if (err != UMP_EOK) {
            msg = "add array32 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_arr32.umpk", std::ios::binary | std::ios::in);
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

tastf_def(map16)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xde,
            0x11, 0x22
    };
    do{
        hd = t_astf_create_ump("stf_map16.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_map16(hd, 0x1122);
        if (err) {
            msg = "add map16 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_map16.umpk", std::ios::binary | std::ios::in);
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

tastf_def(map32)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xdf,
            0x11, 0x22, 0x33, 0x44
    };
    do{
        hd = t_astf_create_ump("stf_map32.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_map32(hd, 0x11223344);
        if (err) {
            msg = "add map32 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_map32.umpk", std::ios::binary | std::ios::in);
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

tastf_def(fixext1)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xd4, 0x01,
            0x00
    };
    do{
        hd = t_astf_create_ump("stf_fixext1.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_fixext1(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext1 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_fixext1.umpk", std::ios::binary | std::ios::in);
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

tastf_def(fixext2)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xd5, 0x01,
            0x00, 0x01
    };
    do{
        hd = t_astf_create_ump("stf_fixext2.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_fixext2(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext2 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_fixext2.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
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

tastf_def(fixext4)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xd6, 0x01,
            0x00, 0x01, 0x02, 0x03
    };
    do{
        hd = t_astf_create_ump("stf_fixext4.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_fixext4(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext4 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_fixext4.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
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

tastf_def(fixext8)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xd7, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
    };
    do{
        hd = t_astf_create_ump("stf_fixext8.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_fixext8(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext8 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_fixext8.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
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

tastf_def(fixext16)
{
    bool ret = false;
    int err;
    ump_handle_t     hd  = nullptr;
    uint8_t         buf_exp[] = {
        0xd8, 0x01,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
    };
    do{
        hd = t_astf_create_ump("stf_fixext16.umpk");
        if (hd == nullptr) {
            msg = "create ump handle failed";
            break;
        }

        err = ump_add_fixext16(hd, buf_exp+2, sizeof(buf_exp) - 2, 1);
        if (err != UMP_EOK) {
            msg = "add fixext16 failed";
            break;
        }

        ump_st_file_close((ump_stream_file_t)hd->stream);

        std::ifstream ifs("stf_fixext16.umpk", std::ios::binary | std::ios::in);
        std::stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();
        std::string str = ss.str();

        if (str.size() != sizeof(buf_exp)) {
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
