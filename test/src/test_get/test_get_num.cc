#include "test_get.h"

tget_def(pfixint)
{
    bool ret = true;
    uint8_t msgpack[] = {
        0x7f, 0x70
    };
    int err;
    int8_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_get_create_ump(msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_pfint) {
            msg = "ump type is not pfixint";
            break;
        }

        err = ump_get_pfixint(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get pfixint 0 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != 0x7f) {
            msg = "ump pfixint value 0 error";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next should not be failed";
            break;
        }

        err = ump_get_pfixint(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get pfixint 1 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != 0x70) {
            msg = "ump pfixint value 1 error";
            break;
        }

        err = ump_next(hd, &type);
        if (err == UMP_EOK) {
            msg = "ump next should be eof";
            break;
        }
    }while(0);
    return ret;
}

tget_def(nfixint)
{
    bool ret = true;
    uint8_t msgpack[] = {
        246, 251
    };
    int err;
    int8_t val;
    ump_type type;
    ump_handle_t hd = nullptr;
    do{
        hd = t_get_create_ump(msgpack, sizeof(msgpack));
        if (hd == nullptr) {
            msg = "create ump handle with pseudo failed";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next failed: ";
            msg += std::to_string(err);
            break;
        }

        if (type != ump_type_nfint) {
            msg = "ump type is not pfixint";
            break;
        }

        err = ump_get_nfixint(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get pfixint 0 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != -10) {
            msg = "ump pfixint value 0 error";
            break;
        }

        err = ump_next(hd, &type);
        if (err != UMP_EOK) {
            msg = "ump next should not be failed";
            break;
        }

        err = ump_get_nfixint(hd, &val);
        if (err != UMP_EOK) {
            msg = "ump get pfixint 1 failed: ";
            msg += std::to_string(err);
            break;
        }

        if (val != -5) {
            msg = "ump pfixint value 1 error";
            break;
        }

        err = ump_next(hd, &type);
        if (err == UMP_EOK) {
            msg = "ump next should be eof";
            break;
        }
    }while(0);
    return ret;
}
