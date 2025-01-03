#ifndef _STR_UTIL_H_
#define _STR_UTIL_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Public Defines ------------------------------------------------------------------------------------------------------

#define LINE_BREAK "\r\n"

#define STR_NULL_TERMINATOR_SIZE 1
#define STR_DECLARE(type, name, contentLength) type name[contentLength + STR_NULL_TERMINATOR_SIZE]

// Public Typedefs and Structures --------------------------------------------------------------------------------------

// Public Variables (externs) ------------------------------------------------------------------------------------------

// Public Functions Declarations ---------------------------------------------------------------------------------------

void str_KeepOnlyNumbers(char *pTarget, const char *pSource);
bool str_IsOnlyNumbers(const char *pSource);

void str_ClearContent(char *pStr);

void str_Trim(char *pStr);

void str_EnsureLeftPadding(char *const pStr, const char paddingChar, const size_t size);
void str_EnsureRightPadding(char *const pStr, const char paddingChar, const size_t size);

void str_EnsureNullTerminated(char *pStr, size_t totalSizeWithNull);

void str_CopySubstring(char *pDest, const char *pSource, size_t length);

bool str_IsEqual(const char *pStr1, const char *pStr2);
bool str_IsDifferent(const char *pStr1, const char *pStr2);

#endif
