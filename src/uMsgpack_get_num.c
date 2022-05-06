#include "uMsgpack.h"

int ump_get_pfixint(ump_handle_t hd, int8_t* val)
{
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( (type&0x80) != ump_type_pfint ) {
            err = UMP_ERR_TYPE;
            break;
        }

        *val = (int8_t)(type&0x7f);

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_f32(ump_handle_t hd, float* val)
{
    uint8_t be[4];
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    union{
        float f32;
        uint8_t u8[4];
    }fu;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_f32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 4, false);
        if (err != UMP_EOK) break;

        fu.u8[0] = be[3];
        fu.u8[1] = be[2];
        fu.u8[2] = be[1];
        fu.u8[3] = be[0];

        *val = fu.f32;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_f64(ump_handle_t hd, double* val)
{
    uint8_t be[8];
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    union{
        double f64;
        uint8_t u8[8];
    }fu;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_f64 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 8, false);
        if (err != UMP_EOK) break;

        fu.u8[0] = be[7];
        fu.u8[1] = be[6];
        fu.u8[2] = be[5];
        fu.u8[3] = be[4];
        fu.u8[4] = be[3];
        fu.u8[5] = be[2];
        fu.u8[6] = be[1];
        fu.u8[7] = be[0];

        *val = fu.f64;

        err = UMP_EOK;
    }while(0);
    return err;
}


int ump_get_u8(ump_handle_t hd, uint8_t* val)
{
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_u8 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, &type, 1, false);
        if (err != UMP_EOK) break;

        *val = type;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_u16(ump_handle_t hd, uint16_t* val)
{
    uint8_t be[2];
    union {
        uint16_t u16;
        uint8_t u8[2];
    } be16;
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_u16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 2, false);
        if (err != UMP_EOK) break;

        be16.u8[0] = be[1];
        be16.u8[1] = be[0];
        *val = be16.u16;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_u32(ump_handle_t hd, uint32_t* val)
{
    uint8_t be[4];
    union {
        uint32_t u32;
        uint8_t u8[4];
    } be32;
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_u32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 4, false);
        if (err != UMP_EOK) break;

        be32.u8[0] = be[3];
        be32.u8[1] = be[2];
        be32.u8[2] = be[1];
        be32.u8[3] = be[0];

        *val = be32.u32;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_u64(ump_handle_t hd, uint64_t* val)
{
    uint8_t be[8];
    union {
        uint64_t u64;
        uint8_t u8[8];
    } be64;
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_u64 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 8, false);
        if (err != UMP_EOK) break;

        be64.u8[0] = be[7];
        be64.u8[1] = be[6];
        be64.u8[2] = be[5];
        be64.u8[3] = be[4];
        be64.u8[4] = be[3];
        be64.u8[5] = be[2];
        be64.u8[6] = be[1];
        be64.u8[7] = be[0];

        *val = be64.u64;

        err = UMP_EOK;
    }while(0);
    return err;
}


int ump_get_i8(ump_handle_t hd, int8_t* val)
{
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_i8 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, &type, 1, false);
        if (err != UMP_EOK) break;

        *((uint8_t*)val) = type;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_i16(ump_handle_t hd, int16_t* val)
{
    uint8_t be[2];
    union {
        int16_t i16;
        uint8_t u8[2];
    } be16;
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_i16 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        err = ump_st_read(hd, 1, be, 2, false);
        if (err != UMP_EOK) break;

        be16.u8[0] = be[1];
        be16.u8[1] = be[0];
        *val = be16.i16;

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_i32(ump_handle_t hd, int32_t* val)
{
    uint8_t be[4];
    uint8_t type = 0;
    ump_err err  = UMP_FAIL;
    do{
        if (ump_check_handle(hd) != UMP_EOK || val == NULL) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_read(hd, 0, &type, 1, false);
        if (err != UMP_EOK) break;

        if ( type != ump_type_i32 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 4, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        *((uint32_t*)val) = be[0];
        *((uint32_t*)val) <<= 8;
        *((uint32_t*)val) |= be[1];
        *((uint32_t*)val) <<= 8;
        *((uint32_t*)val) |= be[2];
        *((uint32_t*)val) <<= 8;
        *((uint32_t*)val) |= be[3];

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_i64(ump_handle_t hd, int64_t* val)
{
    ump_err err = UMP_FAIL;
    uint8_t be[8];

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

        if ( type != ump_type_i64 ) {
            err = UMP_ERR_TYPE;
            break;
        }

        if (ump_st_read(hd, 1, be, 8, false) != UMP_EOK) {
            err = UMP_ERR_READ;
            break;
        }

        *((uint64_t*)val) = be[0];
        *((uint64_t*)val) <<= 8;
        *((uint64_t*)val) |= be[1];
        *((uint64_t*)val) <<= 8;
        *((uint64_t*)val) |= be[2];
        *((uint64_t*)val) <<= 8;
        *((uint64_t*)val) |= be[3];
        *((uint64_t*)val) <<= 8;
        *((uint64_t*)val) |= be[4];
        *((uint64_t*)val) <<= 8;
        *((uint64_t*)val) |= be[5];
        *((uint64_t*)val) <<= 8;
        *((uint64_t*)val) |= be[6];
        *((uint64_t*)val) <<= 8;
        *((uint64_t*)val) |= be[7];

        err = UMP_EOK;
    }while(0);
    return err;
}

int ump_get_nfixint(ump_handle_t hd, int8_t* val)
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

        if ( (type&0xe0) != ump_type_nfint ) {
            err = UMP_ERR_TYPE;
            break;
        }

        *((uint8_t*)val) = type;

        err = UMP_EOK;
    }while(0);
    return err;
}
