#ifndef __U_MSGPACK_H__
#define __U_MSGPACK_H__

#include "uMsgpack_def.h"
#include "uMsgpack_add.h"
#include "uMsgpack_get.h"
#include "uMsgpack_stmem.h"
#include "uMsgpack_stfile.h"
#include "uMsgpack_utils.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Initialize uMsgpack handle with stream
 * 
 * @param hd 
 * @param st 
 * @return int UMP_ERR_*
 */
int ump_init(ump_handle_t hd, ump_stream_t st);

/**
 * @brief Get next msgpack object, and get its type, using for decoding
 * 
 * @param hd uMsgpack handle
 * @param type out param, type of msgpack object
 * @param size if type is str or bin or ext, this will be the size of the object
 * @return int UMP_ERR_*
 */
int ump_next(ump_handle_t hd, ump_type_t type, uint32_t *size);

/**
 * @brief Convert ump error code to string
 * 
 * @param umperr 
 * @return const char* 
 */
const char* ump_strerr(int umperr);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __U_MSGPACK_H__
