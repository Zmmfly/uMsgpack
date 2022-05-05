#include "uMsgpack.h"
#include "uMsgpack_def.h"

int ump_add_bin8(ump_handle_t hd, const void* val, uint8_t len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_b8;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

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
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_bin16(ump_handle_t hd, const void* val, uint16_t len)
{
    uint8_t be[2];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_b16;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 3 + len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = len >> 8;
        be[1] = len & 0xff;
        err = ump_st_write(hd, 0, be, 2, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, len, true);
    }while(0);
    return err;
}

int ump_add_bin32(ump_handle_t hd, const void* val, uint32_t len)
{
    uint8_t be[4];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_b32;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 5+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = len >> 24;
        be[1] = len >> 16;
        be[2] = len >> 8;
        be[3] = len & 0xff;
        err = ump_st_write(hd, 0, be, 4, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, len, true);
    }while(0);
    return err;
}

int ump_add_ext8(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    ump_err err   = UMP_FAIL;
    uint8_t mtype = ump_type_e8;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 3+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &len, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, len, true);
    }while(0);
    return err;
}

int ump_add_ext16(ump_handle_t hd, const void* val, uint16_t len, uint8_t type)
{
    uint8_t be[2];
    ump_err err   = UMP_FAIL;
    uint8_t mtype = ump_type_e16;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 4+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &mtype, 1, true);
        if (err != UMP_EOK) break;

        be[0] = len >> 8;
        be[1] = len & 0xff;
        err = ump_st_write(hd, 0, be, 2, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, len, true);
    }while(0);
    return err;
}

int ump_add_ext32(ump_handle_t hd, const void* val, uint32_t len, uint8_t type)
{
    uint8_t be[4];
    ump_err err   = UMP_FAIL;
    uint8_t mtype = ump_type_e32;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 6+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &mtype, 1, true);
        if (err != UMP_EOK) break;

        be[0] = len >> 24;
        be[1] = len >> 16;
        be[2] = len >> 8;
        be[3] = len & 0xff;
        err = ump_st_write(hd, 0, be, 4, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, val, len, true);
    }while(0);
    return err;
}

int ump_add_fixext1(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    ump_err err   = UMP_FAIL;
    uint8_t mtype = ump_type_fixe1;
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
    uint8_t mtype = ump_type_fixe2;
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
    uint8_t mtype = ump_type_fixe4;
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
    uint8_t mtype = ump_type_fixe8;
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
    uint8_t mtype = ump_type_fixe16;
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