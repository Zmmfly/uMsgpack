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
    do{
        err = ump_check_handle(hd);
        if (err != UMP_EOK) break;

        err = ump_st_req(hd, 1);
        if (err != UMP_EOK) break;
    }while(0);
    return err;
}

int ump_add_f32(ump_handle_t hd, float val)
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

int ump_add_f64(ump_handle_t hd, double val)
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

int ump_add_u8(ump_handle_t hd, uint8_t val)
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

int ump_add_u16(ump_handle_t hd, uint16_t val)
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

int ump_add_u32(ump_handle_t hd, uint32_t val)
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

int ump_add_u64(ump_handle_t hd, uint64_t val)
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

int ump_add_i8(ump_handle_t hd, int8_t val)
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

int ump_add_i16(ump_handle_t hd, int16_t val)
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

int ump_add_i32(ump_handle_t hd, int32_t val)
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

int ump_add_i64(ump_handle_t hd, int64_t val)
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

int ump_add_fixext1(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
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

int ump_add_fixext2(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
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

int ump_add_fixext4(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
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

int ump_add_fixext8(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
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

int ump_add_fixext16(ump_handle_t hd, const void* val, uint8_t len, uint8_t type)
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

int ump_add_str8(ump_handle_t hd, const char* val, uint8_t len)
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
