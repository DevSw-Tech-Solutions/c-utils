#ifndef _CONV_UTIL_H_
#define _CONV_UTIL_H_

#include "error_util.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Public Defines ------------------------------------------------------------------------------------------------------

// Public Typedefs and Structures --------------------------------------------------------------------------------------

// Public Variables (externs) ------------------------------------------------------------------------------------------

// Public Functions Declarations ---------------------------------------------------------------------------------------

int conv_Char2Int(char c);
char conv_Int2Char(int i);

void conv_Int2Str(uint32_t decIntFrom, char *pStrTo);
uint32_t conv_Str2Int(const char *pInStr);

error_t conv_Utf8ToIso88591(const char *pUtf8Str, char *pIsoStr);

uint16_t conv_YearFrom2To4Digits(uint8_t yearIn2Digits);
uint8_t conv_YearFrom4To2Digits(uint16_t yearIn4Digits);

#endif
