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

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

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

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

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

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

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

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

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
    union {
        uint16_t u16;
        uint8_t u8[2];
    } be16;
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_a16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 2, false);
        if (err != UMP_EOK) break;

        be16.u8[0] = be[1];
        be16.u8[1] = be[0];
        *len = be16.u16;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_arr32(ump_handle_t hd, uint32_t* len)
{
    uint8_t be[4];
    union {
        uint32_t u32;
        uint8_t u8[4];
    } be32;
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_a32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 4, false);
        if (err != UMP_EOK) break;

        be32.u8[0] = be[3];
        be32.u8[1] = be[2];
        be32.u8[2] = be[1];
        be32.u8[3] = be[0];
        *len = be32.u32;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_map16(ump_handle_t hd, uint32_t* len)
{
    uint8_t be[2];
    union {
        uint16_t u16;
        uint8_t u8[2];
    } be16;
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_m16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 2, false);
        if (err != UMP_EOK) break;

        be16.u8[0] = be[1];
        be16.u8[1] = be[0];
        *len = be16.u16;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_map32(ump_handle_t hd, uint32_t* len)
{
    uint8_t be[4];
    union {
        uint32_t u32;
        uint8_t  u8[4];
    } be32;
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_m32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 4, false);
        if (err != UMP_EOK) break;

        be32.u8[0] = be[3];
        be32.u8[1] = be[2];
        be32.u8[2] = be[1];
        be32.u8[3] = be[0];
        *len = be32.u32;

        err = UMP_EOK;
    }while(0);
    return err;
}


int ump_get_fixext1(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &mtype, 1, false);
        if (err != UMP_EOK) break;

        if ( mtype != ump_type_fe1 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (type) {
            err = ump_st_read(hd, 1, type, 1, false);
            if (err != UMP_EOK) break;
        }

        if (buf == NULL) {
            *len = 1;
            err = UMP_EOK;
            break;
        }

        if (*len < 1) break;

        err = ump_st_read(hd, 2, buf, 1, false);
        if (err != UMP_EOK) break;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_fixext2(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &mtype, 1, false);
        if (err != UMP_EOK) break;

        if ( mtype != ump_type_fe2 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (type){
            err = ump_st_read(hd, 1, type, 1, false);
            if (err != UMP_EOK) break;
        }

        if (buf == NULL) {
            *len = 2;
            err = UMP_EOK;
            break;
        }

        if (*len < 2) break;

        err = ump_st_read(hd, 2, buf, 2, false);
        if (err != UMP_EOK) break;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_fixext4(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &mtype, 1, false);
        if (err != UMP_EOK) break;

        if ( mtype != ump_type_fe4 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (type) {
            err = ump_st_read(hd, 1, type, 1, false);
            if (err != UMP_EOK) break;
        }

        if (buf == NULL) {
            *len = 4;
            err = UMP_EOK;
            break;
        }

        if (*len < 4) break;

        err = ump_st_read(hd, 2, buf, 4, false);
        if (err != UMP_EOK) break;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_fixext8(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &mtype, 1, false);
        if (err != UMP_EOK) break;

        if ( mtype != ump_type_fe8 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (type) {
            err = ump_st_read(hd, 1, type, 1, false);
            if (err != UMP_EOK) break;
        }

        if (buf == NULL) {
            *len = 8;
            err = UMP_EOK;
            break;
        }

        if (*len < 8) break;

        err = ump_st_read(hd, 2, buf, 8, false);
        if (err != UMP_EOK) break;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_fixext16(ump_handle_t hd, void* buf, uint32_t* len, uint8_t* type)
{
    ump_err err  = UMP_FAIL;
    uint8_t mtype = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &mtype, 1, false);
        if (err != UMP_EOK) break;

        if ( mtype != ump_type_fe16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (type) {
            err = ump_st_read(hd, 1, type, 1, false);
            if (err != UMP_EOK) break;
        }

        if (buf == NULL) {
            *len = 16;
            err = UMP_EOK;
            break;
        }

        if (*len < 16) break;

        err = ump_st_read(hd, 2, buf, 16, false);
        if (err != UMP_EOK) break;

        err = UMP_EOK;
    }while(0);
    return err;
}
