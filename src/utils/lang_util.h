#ifndef _LANG_UTIL_H_
#define _LANG_UTIL_H_

#include <stdbool.h>
#include <stdint.h>

// Public Defines ------------------------------------------------------------------------------------------------------

#define LANG_NAME 'C'

#define INFINITE_LOOP() while (1)

#define UNUSED(element) ((void)(element))
#define RETURN_IGNORED(function) UNUSED(function)

#define IS_POINTER_NULL(pointer) (NULL == (pointer))
#define IS_POINTER_NOT_NULL(pointer) (!IS_POINTER_NULL(pointer))

#define RUN_AND_RETURN_IF_ERROR(functionReturningErrorCode)                                                            \
   {                                                                                                                   \
      error_t runResult = functionReturningErrorCode;                                                                  \
      IF_TRUE_RETURN_VAL(ERROR_NONE != runResult, runResult);                                                          \
   }

#define IF_TRUE_RETURN_VAL(condition, val)                                                                             \
   if (condition) {                                                                                                    \
      return val;                                                                                                      \
   }

// Public Typedefs and Structures --------------------------------------------------------------------------------------

// Public Variables (externs) ------------------------------------------------------------------------------------------

// Public Functions Declarations ---------------------------------------------------------------------------------------

#endif
