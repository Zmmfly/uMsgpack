#include "uMsgpack.h"

int ump_get_fixstr(ump_handle_t hd, char* buf, uint32_t* len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    uint8_t mlen  = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        mlen = type&0x1f;
        type = type&0xe0;

        if ( type != ump_type_fstr ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (buf == NULL) {
            *len = mlen;
            err  = UMP_EOK;
            break;
        }

        err = ump_st_read(hd, 1, buf, *len > mlen ? mlen : *len, false);
        if (err != UMP_EOK) break;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_str8(ump_handle_t hd, char* buf, uint32_t* len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    uint8_t mlen = 0;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_s8 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, &mlen, 1, false);
        if (err != UMP_EOK) break;

        if (buf == NULL) {
            *len = mlen;
            break;
        }

        err = ump_st_read(hd, 2, buf, *len > mlen ? mlen : *len, false);
        if (err != UMP_EOK) break;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_str16(ump_handle_t hd, char* buf, uint32_t* len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    uint8_t be[2];
    union {
        uint16_t u16;
        uint8_t  u8[2];
    }be16;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }
        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_s16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 2, false);
        if (err != UMP_EOK) break;

        be16.u8[1] = be[0];
        be16.u8[0] = be[1];

        if (buf == NULL) {
            *len = be16.u16;
            err  = UMP_EOK;
            break;
        }

        err = ump_st_read(hd, 3, buf, *len > be16.u16 ? be16.u16 : *len, false);
        if (err != UMP_EOK) break;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_str32(ump_handle_t hd, char* buf, uint32_t* len)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = 0;
    uint8_t be[4];
    union {
        uint32_t u32;
        uint8_t  u8[4];
    }be32;
    do{
        if (ump_check_handle(hd) != UMP_EOK || len == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_s32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 4, false);
        if (err != UMP_EOK) break;

        be32.u8[3] = be[0];
        be32.u8[2] = be[1];
        be32.u8[1] = be[2];
        be32.u8[0] = be[3];

        if (buf == NULL) {
            *len = be32.u32;
            err = UMP_EOK;
            break;
        }

        err = ump_st_read(hd, 5, buf, *len > be32.u32 ? be32.u32 : *len, false);
        if (err != UMP_EOK) break;

        err = UMP_EOK;
    }while(0);
    return err;
}
