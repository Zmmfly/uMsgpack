#include "uMsgpack.h"
#include "uMsgpack_def.h"


int ump_add_fixmap(ump_handle_t hd, uint8_t val)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_fmap;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;

        if (val > 16) {
            err = UMP_ERR_RANGEOVF;
            break;
        }

        type |= val;

        err = ump_st_write(hd, 0, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_fixarr(ump_handle_t hd, uint8_t val)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_farr;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;

        if (val > 16) {
            err = UMP_ERR_RANGEOVF;
            break;
        }

        type |= val;

        err = ump_st_write(hd, 0, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_nil(ump_handle_t hd)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_nil;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_bool(ump_handle_t hd, bool val)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = val ? ump_type_true : ump_type_false;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_arr16(ump_handle_t hd, uint16_t len)
{
    uint8_t be[2];
    uint8_t type = ump_type_a16;
    ump_err err  = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 3);
        if (err != UMP_EOK) break;

        be[0] = len >> 8;
        be[1] = len & 0xff;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, be, 2, true);
    }while(0);
    return err;
}

int ump_add_arr32(ump_handle_t hd, uint32_t len)
{
    uint8_t be[4];
    uint8_t type = ump_type_a32;
    ump_err err  = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 5);
        if (err != UMP_EOK) break;

        be[0] = len >> 24;
        be[1] = len >> 16;
        be[2] = len >> 8;
        be[3] = len & 0xff;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, be, 4, true);
    }while(0);
    return err;
}

int ump_add_map16(ump_handle_t hd, uint16_t len)
{
    uint8_t be[2];
    uint8_t type = ump_type_m16;
    ump_err err  = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 3);
        if (err != UMP_EOK) break;

        be[0] = len >> 8;
        be[1] = len & 0xff;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, be, 2, true);
    }while(0);
    return err;
}

int ump_add_map32(ump_handle_t hd, uint32_t len)
{
    uint8_t be[4];
    uint8_t type = ump_type_m32;
    ump_err err  = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 5);
        if (err != UMP_EOK) break;

        be[0] = len >> 24;
        be[1] = len >> 16;
        be[2] = len >> 8;
        be[3] = len & 0xff;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, be, 4, true);
    }while(0);
    return err;
}

