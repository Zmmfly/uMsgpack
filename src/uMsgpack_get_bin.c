#include "uMsgpack.h"

int ump_get_bin8(ump_handle_t hd, void* buf, uint32_t* len)
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

        if ( type != ump_type_b8 ) {
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

int ump_get_bin16(ump_handle_t hd, void* buf, uint32_t* len)
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

        if ( type != ump_type_b16 ) {
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

int ump_get_bin32(ump_handle_t hd, void* buf, uint32_t* len)
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

        if ( type != ump_type_b32 ) {
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


int ump_get_ext8(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    uint8_t be[1];
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL || type == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &mtype, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( mtype != ump_type_e8 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (ump_st_read(hd, 2, type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = be[0];
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

int ump_get_ext16(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    uint8_t be[2];
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL || type == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &mtype, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( mtype != ump_type_e16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 2, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (ump_st_read(hd, 3, type, 1, false) != UMP_EOK) {
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

        if (ump_st_read(hd, 4, buf, *len, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_ext32(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    uint8_t be[4];
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL || type == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &mtype, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( mtype != ump_type_e32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 4, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (ump_st_read(hd, 5, type, 1, false) != UMP_EOK) {
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

        if (ump_st_read(hd, 6, buf, *len, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}


int ump_get_fixext1(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL || type == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &mtype, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( mtype != ump_type_fixe1 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = 1;
            err = UMP_EOK;
            break;
        }

        if (*len < 1) break;

        if (ump_st_read(hd, 2, buf, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_fixext2(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL || type == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &mtype, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( mtype != ump_type_fixe2 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = 2;
            err = UMP_EOK;
            break;
        }

        if (*len < 2) break;

        if (ump_st_read(hd, 2, buf, 2, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_fixext4(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL || type == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &mtype, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( mtype != ump_type_fixe4 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = 4;
            err = UMP_EOK;
            break;
        }

        if (*len < 4) break;

        if (ump_st_read(hd, 2, buf, 4, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_fixext8(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL || type == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &mtype, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( mtype != ump_type_fixe8 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = 8;
            err = UMP_EOK;
            break;
        }

        if (*len < 8) break;

        if (ump_st_read(hd, 2, buf, 8, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_fixext16(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL || type == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        if (ump_st_read(hd, 0, &mtype, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if ( mtype != ump_type_fixe16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, type, 1, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        if (buf == NULL) {
            *len = 16;
            err = UMP_EOK;
            break;
        }

        if (*len < 16) break;

        if (ump_st_read(hd, 2, buf, 16, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        err = UMP_EOK;
    }while(0);
    return err;
}

