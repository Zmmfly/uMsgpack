#include "uMsgpack.h"
#include "uMsgpack_def.h"

int ump_add_bin8(ump_handle_t hd, const void* val, uint8_t len)
{
    uint8_t type = ump_type_b8;
    ump_err err  = UMP_ERR_INVALID_ARG;
    do{
        if (val == NULL || len == 0) break;

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
    uint8_t type = ump_type_b16;
    ump_err err  = UMP_ERR_INVALID_ARG;
    do{
        if (val == NULL || len == 0) break;

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
    uint8_t type = ump_type_b32;
    ump_err err  = UMP_ERR_INVALID_ARG;
    do{
        if (val == NULL || len == 0) break;

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
    uint8_t mtype = ump_type_e8;
    ump_err err   = UMP_ERR_INVALID_ARG;
    do{
        if (val == NULL || len == 0) break;

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
    uint8_t mtype = ump_type_e16;
    ump_err err   = UMP_ERR_INVALID_ARG;
    do{
        if (val == NULL || len == 0) break;

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
    uint8_t mtype = ump_type_e32;
    ump_err err   = UMP_ERR_INVALID_ARG;
    do{
        if (val == NULL || len == 0) break;

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
