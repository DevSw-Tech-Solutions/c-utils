#ifndef _BUF_UTIL_H_
#define _BUF_UTIL_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Public Defines ------------------------------------------------------------------------------------------------------

// Public Typedefs and Structures --------------------------------------------------------------------------------------

// Public Variables (externs) ------------------------------------------------------------------------------------------

// Public Functions Declarations ---------------------------------------------------------------------------------------

bool buf_IsAllBytesEqual(const uint8_t *pBytes, size_t len);

#endif
