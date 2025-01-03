#include "str_util.h"
#include "char_util.h"
#include "lang_util.h"
#include <assert.h>
#include <ctype.h>
#include <string.h>

// Private Defines -----------------------------------------------------------------------------------------------------

// Private Typedefs and Structures -------------------------------------------------------------------------------------

// Private Functions Declarations (statics) ----------------------------------------------------------------------------

// Private Variables (statics) -----------------------------------------------------------------------------------------

// Public Variables ----------------------------------------------------------------------------------------------------

// Public Functions Definitions ----------------------------------------------------------------------------------------

void str_KeepOnlyNumbers(char *pTarget, const char *pSource) {
   if ((NULL != pTarget) && (NULL != pSource)) {
      while (*pSource) {
         if (isdigit((unsigned char)*pSource)) {
            *pTarget = *pSource;
            pTarget++;
         }
         pSource++;
      }
      *pTarget = '\0'; // Finaliza a string de destino.
   }
}

bool str_IsOnlyNumbers(const char *pSource) {
   bool isOnlyNumbers = false;

   if (NULL != pSource) {
      size_t len = strlen(pSource);

      if (len > 0) {
         isOnlyNumbers = true;

         for (size_t i = 0; (i < len) && isOnlyNumbers; i++) {
            isOnlyNumbers = isdigit((unsigned char)pSource[i]);
         }
      }
   }

   return (isOnlyNumbers);
}

void str_ClearContent(char *pStr) {
   assert(NULL != pStr);

   pStr[0] = ASC_NUL;
}

void str_Trim(char *pStr) {
   assert(pStr);
   size_t tamStr = strlen(pStr);
   size_t firstValidCharIndex = 0;
   size_t lastValidCharIndex;

   lastValidCharIndex = (tamStr - 1);

   if (tamStr > 0) {
      for (size_t i = 0; i < tamStr; i++) {
         if (pStr[i] > ASC_SP)
         {
            firstValidCharIndex = i;
            break;
         }
      }

      for (size_t i = 0; i < tamStr; i++) {
         if (pStr[(tamStr - 1) - i] > ASC_SP)
         {
            lastValidCharIndex = (tamStr - 1) - i;
            break;
         }
      }

      if ((firstValidCharIndex > 0) ||
          (lastValidCharIndex < (tamStr - 1))) {
         tamStr = (lastValidCharIndex + 1) - firstValidCharIndex;

         if (firstValidCharIndex > 0) {
            memmove(pStr, &pStr[firstValidCharIndex], tamStr);
         }

         pStr[tamStr] = ASC_NUL;
      }
   }
}

void str_EnsureLeftPadding(char *const pStr, const char paddingChar, const size_t size) {
   assert(IS_POINTER_NOT_NULL(pStr));

   const size_t currentLength = strlen(pStr);
   const size_t paddingLength = (size > currentLength) ? size - currentLength : 0;

   if (paddingLength > 0)
   {
      pStr[size] = ASC_NUL;

      for (size_t i = 0; i < currentLength; i++) {
         pStr[size - (1 + i)] = pStr[currentLength - (1 + i)];
      }

      for (size_t i = 0; i < paddingLength; i++) {
         pStr[i] = paddingChar;
      }
   }
}

void str_EnsureRightPadding(char *const pStr, const char paddingChar, const size_t size) {
   assert(IS_POINTER_NOT_NULL(pStr));

   const size_t currentLength = strlen(pStr);
   const size_t paddingLength = (size > currentLength) ? size - currentLength : 0;

   if (paddingLength > 0)
   {
      pStr[size] = ASC_NUL;

      for (size_t i = 0; i < paddingLength; i++) {
         pStr[currentLength + i] = paddingChar;
      }
   }
}

void str_EnsureNullTerminated(char *pStr, size_t totalSizeWithNull) {
   pStr[totalSizeWithNull - 1] = ASC_NUL;
}

void str_CopySubstring(char *pDest, const char *pSrc, size_t length) {
   strncpy(pDest, pSrc, length);
   str_EnsureNullTerminated(pDest, length + 1);
}

bool str_IsEqual(const char *pStr1, const char *pStr2) {
   return (strcmp(pStr1, pStr2) == 0);
}

bool str_IsDifferent(const char *pStr1, const char *pStr2) {
   return (strcmp(pStr1, pStr2) != 0);
}

// Private Functions Definitions (statics) -----------------------------------------------------------------------------
