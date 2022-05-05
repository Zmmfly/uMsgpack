#include "uMsgpack.h"

int ump_get_fixstr(ump_handle_t hd, char* buf, uint32_t* len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    uint8_t be[1];
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_s8 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = be[0];
            err = UMP_EOK;
            break;
        }

        if (ump_st_read(hd, 2, buf, be[0], false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_str8(ump_handle_t hd, char* buf, uint32_t* len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    uint8_t be[2];
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_s16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 2, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = be[0];
            *len <<= 8;
            *len |= be[1];
            err = UMP_EOK;
            break;
        }

        if (ump_st_read(hd, 3, buf, *len, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_str16(ump_handle_t hd, char* buf, uint32_t* len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    uint8_t be[2];
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_s16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 2, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = be[0];
            *len <<= 8;
            *len |= be[1];
            err = UMP_EOK;
            break;
        }

        if (ump_st_read(hd, 3, buf, *len, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_str32(ump_handle_t hd, char* buf, uint32_t* len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    uint8_t be[4];
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( type != ump_type_s32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 4, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = be[0];
            *len <<= 8;
            *len |= be[1];
            *len <<= 8;
            *len |= be[2];
            *len <<= 8;
            *len |= be[3];
            err = UMP_EOK;
            break;
        }

        if (ump_st_read(hd, 5, buf, *len, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}
