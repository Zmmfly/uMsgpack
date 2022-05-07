#include "uMsgpack.h"
#include "uMsgpack_def.h"

int ump_add_fixstr(ump_handle_t hd, const char* val, uint8_t len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_fstr;
    do{
        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        if (len > 32) {
            err = UMP_ERR_RANGEOVF;
            break;
        }

        type |= len;

        err = ump_st_req(hd, 1 + len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, len, true);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_str8(ump_handle_t hd, const char* val, uint8_t len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_s8;
    do{
        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 2+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &len, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, len, true);
    }while(0);
    return err;
}

int ump_add_str16(ump_handle_t hd, const char* val, uint16_t len)
{
    uint8_t be[2];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_s16;
    do{
        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 3 + len);
        if (err != UMP_EOK) break;

        be[0] = len >> 8;
        be[1] = len & 0xff;
        
        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, be, 2, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, len, true);
    }while(0);
    return err;
}

int ump_add_str32(ump_handle_t hd, const char* val, uint32_t len)
{
    uint8_t be[4];
    uint8_t type = ump_type_s32;
    ump_err err = UMP_FAIL;
    do{
        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 5 + len);
        if (err != UMP_EOK) break;

        be[0] = len >> 24;
        be[1] = len >> 16;
        be[2] = len >> 8;
        be[3] = len & 0xff;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, be, 4, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, len, true);
    }while(0);
    return err;
}