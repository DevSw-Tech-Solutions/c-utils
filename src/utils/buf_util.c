#include "buf_util.h"

// Private Defines -----------------------------------------------------------------------------------------------------

// Private Typedefs and Structures -------------------------------------------------------------------------------------

// Private Functions Declarations (statics) ----------------------------------------------------------------------------

// Private Variables (statics) -----------------------------------------------------------------------------------------

// Public Variables ----------------------------------------------------------------------------------------------------

// Public and Private Functions Definitions ----------------------------------------------------------------------------

bool buf_IsAllBytesEqual(const uint8_t *pBytes, size_t len) {
   bool isAllBytesEqual = true;

   if (len > 0 && (pBytes != NULL)) {
      uint8_t firstByte = pBytes[0];

      for (size_t i = 1; i < len; i++) {
         if (pBytes[i] != firstByte) {
            isAllBytesEqual = false;
            break;
         }
      }
   } else {
      isAllBytesEqual = false;
   }

   return (isAllBytesEqual);
}
