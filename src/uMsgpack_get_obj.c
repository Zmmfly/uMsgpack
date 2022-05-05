#include "uMsgpack.h"

int ump_get_fixmap(ump_handle_t hd, uint32_t* val)
{
    ump_err err = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( (type&0xf0) != ump_type_fmap ) {
            err = UMP_ERR_TYPE;
            break;
        }

        *val = type & 0x0f;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_fixarr(ump_handle_t hd, uint32_t* val)
{
    ump_err err = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( (type&0xf0) != ump_type_farr ) {
            err = UMP_ERR_TYPE;
            break;
        }

        *val = type & 0x0f;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_nil(ump_handle_t hd)
{
ump_err err = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_nil ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_bool(ump_handle_t hd, bool* val)
{
    ump_err err = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_true && type != ump_type_false ) {
            err = UMP_ERR_TYPE;
            break;
        }

        *val = (type == ump_type_true);

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_arr16(ump_handle_t hd, uint32_t* len)
{
    uint8_t be[2];
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_a16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 2, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        *len = be[0];
        *len <<= 8;
        *len |= be[1];

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_arr32(ump_handle_t hd, uint32_t* len)
{
    uint8_t be[4];
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_a32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 4, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        *len = be[0];
        *len <<= 8;
        *len |= be[1];
        *len <<= 8;
        *len |= be[2];
        *len <<= 8;
        *len |= be[3];

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_map16(ump_handle_t hd, uint32_t* len)
{
uint8_t be[2];
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_m16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 2, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        *len = be[0];
        *len <<= 8;
        *len |= be[1];

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_map32(ump_handle_t hd, uint32_t* len)
{
    uint8_t be[4];
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_m32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 4, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        *len = be[0];
        *len <<= 8;
        *len |= be[1];
        *len <<= 8;
        *len |= be[2];
        *len <<= 8;
        *len |= be[3];

        err = UMP_EOK;
    }while(0);
    return err;
}
