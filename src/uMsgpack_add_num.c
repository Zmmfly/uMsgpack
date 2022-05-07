#include "uMsgpack.h"
#include "uMsgpack_def.h"

int ump_add_pfixint(ump_handle_t hd, uint8_t val)
{
    uint8_t type = ump_type_pfint;
    ump_err err  = UMP_ERR_RANGEOVF;
    do{
        if (val > 127) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;

        type |= val;
        
        err = ump_st_write(hd, 0, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_f32(ump_handle_t hd, float val)
{
    union{
        float f32;
        uint8_t u8[4];
    }fu;
    uint8_t be[4];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_f32;

    do{
        err = ump_st_req(hd, 5);
        if (err != UMP_EOK) break;

		fu.f32 = val;
        be[0]  = fu.u8[3];
        be[1]  = fu.u8[2];
        be[2]  = fu.u8[1];
        be[3]  = fu.u8[0];

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, be, 4, true);
    }while(0);
    return err;
}

int ump_add_f64(ump_handle_t hd, double val)
{
    union{
        double f64;
        uint8_t u8[8];
    }fu;
    uint8_t be[8];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_f64;

    do{
        err = ump_st_req(hd, 9);
        if (err != UMP_EOK) break;

		fu.f64 = val;
        be[0] = fu.u8[7];
        be[1] = fu.u8[6];
        be[2] = fu.u8[5];
        be[3] = fu.u8[4];
        be[4] = fu.u8[3];
        be[5] = fu.u8[2];
        be[6] = fu.u8[1];
        be[7] = fu.u8[0];

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, be, 8, true);
    }while(0);
    return err;
}

int ump_add_u8(ump_handle_t hd, uint8_t val)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_u8;
    do{
        err = ump_st_req(hd, 2);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &val, 1, true);
    }while(0);
    return err;
}

int ump_add_u16(ump_handle_t hd, uint16_t val)
{
    uint8_t be[2];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_u16;
    do{
        err = ump_st_req(hd, 3);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = val >> 8;
        be[1] = val & 0xff;

        err = ump_st_write(hd, 0, be, 2, true);
    }while(0);
    return err;
}

int ump_add_u32(ump_handle_t hd, uint32_t val)
{
    uint8_t be[4];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_u32;
    do{
        err = ump_st_req(hd, 5);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = val >> 24;
        be[1] = val >> 16;
        be[2] = val >> 8;
        be[3] = val & 0xff;

        err = ump_st_write(hd, 0, be, 4, true);
    }while(0);
    return err;
}

int ump_add_u64(ump_handle_t hd, uint64_t val)
{
    uint8_t be[8];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_u64;
    do{
        err = ump_st_req(hd, 9);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = val >> 56;
        be[1] = val >> 48;
        be[2] = val >> 40;
        be[3] = val >> 32;
        be[4] = val >> 24;
        be[5] = val >> 16;
        be[6] = val >> 8;
        be[7] = val & 0xff;

        err = ump_st_write(hd, 0, be, 8, true);
    }while(0);
    return err;
}

int ump_add_i8(ump_handle_t hd, int8_t val)
{
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_i8;
    do{
        err = ump_st_req(hd, 2);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &val, 1, true);
    }while(0);
    return err;
}

int ump_add_i16(ump_handle_t hd, int16_t val)
{
    union{
        uint8_t u8[2];
        int16_t i16;
    }iu;
    uint8_t be[2];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_i16;
    do{
        err = ump_st_req(hd, 3);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        iu.i16 = val;
        be[0] = iu.u8[1];
        be[1] = iu.u8[0];

        err = ump_st_write(hd, 0, be, 2, true);
    }while(0);
    return err;
}

int ump_add_i32(ump_handle_t hd, int32_t val)
{
    union {
        uint8_t u8[4];
        int32_t i32;
    }iu;
    uint8_t be[4];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_i32;
    do{
        err = ump_st_req(hd, 5);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        iu.i32 = val;
        be[0] = iu.u8[3];
        be[1] = iu.u8[2];
        be[2] = iu.u8[1];
        be[3] = iu.u8[0];

        err = ump_st_write(hd, 0, be, 4, true);
    }while(0);
    return err;
}

int ump_add_i64(ump_handle_t hd, int64_t val)
{
    union {
        uint8_t u8[8];
        int64_t i64;
    }iu;
    uint8_t be[8];
    ump_err err  = UMP_FAIL;
    uint8_t type = ump_type_i64;
    do{
        err = ump_st_req(hd, 9);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, 0, &type, 1, true);
        if (err != UMP_EOK) break;

        iu.i64 = val;
        be[0] = iu.u8[7];
        be[1] = iu.u8[6];
        be[2] = iu.u8[5];
        be[3] = iu.u8[4];
        be[4] = iu.u8[3];
        be[5] = iu.u8[2];
        be[6] = iu.u8[1];
        be[7] = iu.u8[0];

        err = ump_st_write(hd, 0, be, 8, true);
    }while(0);
    return err;
}

int ump_add_nfixint(ump_handle_t hd, int8_t val)
{
    uint8_t type = ump_type_nfint;
    ump_err err  = UMP_ERR_RANGEOVF;
    do{
        if (val > 15 || val < -16) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;

        type |= val;

        err = ump_st_write(hd, 0, &type, 1, true);
    }while(0);
    return err;
}
