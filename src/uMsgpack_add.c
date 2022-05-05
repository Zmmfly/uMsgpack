#include "uMsgpack.h"
#include "uMsgpack_def.h"

int ump_add_pfixint(ump_handle_t hd, uint8_t val)
{
    err = UMP_FAIL;
    uint8_t type = ump_type_pfint;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;

        if (val > 128) {
            err = UMP_ERR_RANGEOVF;
            break;
        }

        type |= val;
        
        err = ump_st_write(hd, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_fixmap(ump_handle_t hd, uint8_t val)
{
    err = UMP_FAIL;
    uint8_t type = ump_type_fixmap;
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

        err = ump_st_write(hd, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_fixarray(ump_handle_t hd, uint8_t val)
{
    err = UMP_FAIL;
    uint8_t type = ump_type_fixarr;
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

        err = ump_st_write(hd, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_fixstr(ump_handle_t hd, const char* val, uint8_t len)
{
    err = UMP_FAIL;
    uint8_t type = ump_type_fixstr;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        if (len > 32) {
            err = UMP_ERR_RANGEOVF;
            break;
        }

        err = ump_st_req(hd, 1 + len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, len, true);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_nil(ump_handle_t hd)
{
    err = UMP_FAIL;
    uint8_t type = ump_type_nil;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_bool(ump_handle_t hd, bool val)
{
    err = UMP_FAIL;
    uint8_t type = val ? ump_type_true : ump_type_false;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
    }while(0);
    return err;
}

int ump_add_bin8(ump_handle_t hd, const void* val, uint8_t len)
{
    err = UMP_FAIL;
    uint8_t type = ump_type_bin8;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 2+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &len, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, len, true);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_bin16(ump_handle_t hd, const void* val, uint16_t len)
{
    err = UMP_FAIL;
    uint8_t be[2];
    uint8_t type = ump_type_bin16;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 3 + len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = len>>8;
        be[1] = len;
        err = ump_st_write(hd, be, 2, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, len, true);
    }while(0);
    return err;
}

int ump_add_bin32(ump_handle_t hd, const void* val, uint32_t len)
{
    err = UMP_FAIL;
    uint8_t be[4];
    uint8_t type = ump_type_bin32;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 5+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = len >> 24;
        be[1] = len >> 16;
        be[2] = len >> 8;
        be[3] = len;
        err = ump_st_write(hd, be, 4, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, len, true);
    }while(0);
    return err;
}

int ump_add_ext8(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    err = UMP_FAIL;
    uint8_t mtype = ump_type_ext8;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 3+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &len, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, len, true);
    }while(0);
    return err;
}

int ump_add_ext16(ump_handle_t hd, const void* val, uint16_t len, uint8_t type)
{
    err = UMP_FAIL;
    uint8_t mtype = ump_type_ext16;
    uint8_t be[2];
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 4+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &mtype, 1, true);
        if (err != UMP_EOK) break;

        be[0] = len >> 8;
        be[1] = len;
        err = ump_st_write(hd, be, 2, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err !- UMP_EOK) break;

        err = ump_st_write(hd, val, len, true);
    }while(0);
    return err;
}

int ump_add_ext32(ump_handle_t hd, const void* val, uint32_t len, uint8_t type)
{
    err = UMP_FAIL;
    uint8_t mtype = ump_type_ext32;
    uint8_t be[4];
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 6+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &mtype, 1, true);
        if (err != UMP_EOK) break;

        be[0] = len >> 24;
        be[1] = len >> 16;
        be[2] = len >> 8;
        be[3] = len;
        err = ump_st_write(hd, be, 4, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, len, true);
    }while(0);
    return err;
}

int ump_add_f32(ump_handle_t hd, float val)
{
    err = UMP_FAIL;
    union{
        float f32;
        uint8_t u8[4];
    }fu;
    uint8_t be[4];
    uint8_t type = ump_type_f32;

    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 5);
        if (err != UMP_EOK) break;

		fu.f32 = val;
        be[0] = fu.u8[3];
        be[1] = fu.u8[2];
        be[2] = fu.u8[1];
        be[3] = fu.u8[0];

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, be, 4, true);
    }while(0);
    return err;
}

int ump_add_f64(ump_handle_t hd, double val)
{
    err = UMP_FAIL;
    union{
        double f64;
        uint8_t u8[8];
    }fu;
    uint8_t be[8];
    uint8_t type = ump_type_f64;

    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

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

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, be, 8, true);
    }while(0);
    return err;
}

int ump_add_u8(ump_handle_t hd, uint8_t val)
{
    err = UMP_FAIL;
    uint8_t type = ump_type_u8;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 2);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &val, 1, true);
    }while(0);
    return err;
}

int ump_add_u16(ump_handle_t hd, uint16_t val)
{
    err = UMP_FAIL;
    uint8_t be[2];
    uint8_t type = ump_type_u16;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 3);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = val >> 8;
        be[1] = val;

        err = ump_st_write(hd, be, 2, true);
    }while(0);
    return err;
}

int ump_add_u32(ump_handle_t hd, uint32_t val)
{
    err = UMP_FAIL;
    uint8_t be[4];
    uint8_t type = ump_type_u32;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 5);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = val >> 24;
        be[1] = val >> 16;
        be[2] = val >> 8;
        be[3] = val;

        err = ump_st_write(hd, be, 4, true);
    }while(0);
    return err;
}

int ump_add_u64(ump_handle_t hd, uint64_t val)
{
    err = UMP_FAIL;
    uint8_t be[8];
    uint8_t type = ump_type_u64;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 9);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = val >> 56;
        be[1] = val >> 48;
        be[2] = val >> 40;
        be[3] = val >> 32;
        be[4] = val >> 24;
        be[5] = val >> 16;
        be[6] = val >> 8;
        be[7] = val;

        err = ump_st_write(hd, be, 8, true);
    }while(0);
    return err;
}

int ump_add_i8(ump_handle_t hd, int8_t val)
{
    err = UMP_FAIL;
    uint8_t type = ump_type_i8;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 2);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &val, 1, true);
    }while(0);
    return err;
}

int ump_add_i16(ump_handle_t hd, int16_t val)
{
    err = UMP_FAIL;
    uint8_t be[4];
    uint8_t type = ump_type_i16;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 3);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = (uint16_t)val >> 8;
        be[1] = (uint16_t)val;

        err = ump_st_write(hd, be, 4, true);
    }while(0);
    return err;
}

int ump_add_i32(ump_handle_t hd, int32_t val)
{
    err = UMP_FAIL;
    uint8_t be[4];
    uint8_t type = ump_type_i32;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 5);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = (uint32_t)val >> 24;
        be[1] = (uint32_t)val >> 16;
        be[2] = (uint32_t)val >> 8;
        be[3] = (uint32_t)val;

        err = ump_st_write(hd, be, 4, true);
    }while(0);
    return err;
}

int ump_add_i64(ump_handle_t hd, int64_t val)
{
    err = UMP_FAIL;
    uint8_t be[8];
    uint8_t type = ump_type_i64;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 9);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        be[0] = (uint64_t)val >> 56;
        be[1] = (uint64_t)val >> 48;
        be[2] = (uint64_t)val >> 40;
        be[3] = (uint64_t)val >> 32;
        be[4] = (uint64_t)val >> 24;
        be[5] = (uint64_t)val >> 16;
        be[6] = (uint64_t)val >> 8;
        be[7] = (uint64_t)val;

        err = ump_st_write(hd, be, 8, true);
    }while(0);
    return err;
}

int ump_add_fixext1(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    err = UMP_FAIL;
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

		err = ump_st_write(hd, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, 1, true);
    }while(0);
    return err;
}

int ump_add_fixext2(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    err = UMP_FAIL;
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

		err = ump_st_write(hd, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, 2, true);
    }while(0);
    return err;
}

int ump_add_fixext4(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    err = UMP_FAIL;
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

		err = ump_st_write(hd, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, 4, true);
    }while(0);
    return err;
}

int ump_add_fixext8(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    err = UMP_FAIL;
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

		err = ump_st_write(hd, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, 8, true);
    }while(0);
    return err;
}

int ump_add_fixext16(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
{
    err = UMP_FAIL;
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

		err = ump_st_write(hd, &mtype, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, val, 16, true);
    }while(0);
    return err;
}

int ump_add_str8(ump_handle_t hd, const char* val, uint8_t len)
{
    err = UMP_FAIL;
    uint8_t type = ump_type_s8;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        if (val == NULL || len == 0) {
            err = UMP_ERR_INVALID_ARG;
            break;
        }

        err = ump_st_req(hd, 2+len);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &type, 1, true);
        if (err != UMP_EOK) break;

        err = ump_st_write(hd, &len, 1, true);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_str16(ump_handle_t hd, const char* val, uint16_t len)
{
    err = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_str32(ump_handle_t hd, const char* val, uint32_t len)
{
    err = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_array16(ump_handle_t hd, uint16_t len)
{
    err = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_array32(ump_handle_t hd, uint32_t len)
{
    err = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_map16(ump_handle_t hd, uint16_t len)
{
    err = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_map32(ump_handle_t hd, uint32_t len)
{
    err = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_nfixint(ump_handle_t hd, int8_t val)
{
    err = UMP_FAIL;
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}
