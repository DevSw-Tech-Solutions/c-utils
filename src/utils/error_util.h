#ifndef _ERROR_H_
#define _ERROR_H_

// Public Defines ------------------------------------------------------------------------------------------------------

// Public Typedefs and Structures --------------------------------------------------------------------------------------

typedef enum {
   ERROR_NONE,
   ERROR_PARAMETER,
   ERROR_ID_NOT_FOUND,
   ERROR_MISSING_INIT,
   ERROR_INSUFFICIENT_MEMORY,
   ERROR_FILE,
} error_t;

#endif
