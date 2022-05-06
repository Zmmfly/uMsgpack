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

int ump_add_fixext1(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    ump_err err   = UMP_FAIL;
    uint8_t mtype = ump_type_fe1;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

		if (val == NULL || len != 1) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 3);
        if (err != UMP_EOK) break;

		err = ump_st_write(hd, 0, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, 1, true);
    }while(0);
    return err;
}

int ump_add_fixext2(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    ump_err err   = UMP_FAIL;
    uint8_t mtype = ump_type_fe2;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

		if (val == NULL || len != 2) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 4);
        if (err != UMP_EOK) break;

		err = ump_st_write(hd, 0, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, 2, true);
    }while(0);
    return err;
}

int ump_add_fixext4(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    ump_err err   = UMP_FAIL;
    uint8_t mtype = ump_type_fe4;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

		if (val == NULL || len != 4) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 6);
        if (err != UMP_EOK) break;

		err = ump_st_write(hd, 0, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, 4, true);
    }while(0);
    return err;
}

int ump_add_fixext8(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    ump_err err   = UMP_FAIL;
    uint8_t mtype = ump_type_fe8;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

		if (val == NULL || len != 8) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 10);
        if (err != UMP_EOK) break;

		err = ump_st_write(hd, 0, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, 8, true);
    }while(0);
    return err;
}

int ump_add_fixext16(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    ump_err err   = UMP_FAIL;
    uint8_t mtype = ump_type_fe16;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

		if (val == NULL || len != 16) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 18);
        if (err != UMP_EOK) break;

		err = ump_st_write(hd, 0, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, 16, true);
    }while(0);
    return err;
}
