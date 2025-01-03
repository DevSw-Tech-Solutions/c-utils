#include "conv_util.h"
#include "char_util.h"
#include "int_util.h"
#include "lang_util.h"
#include "str_util.h"
#include <assert.h>
#include <string.h>

// Private Defines -----------------------------------------------------------------------------------------------------

#define CONV_YEAR_COMPLEMENT 2000

// Private Typedefs and Structures -------------------------------------------------------------------------------------

// Private Functions Declarations (statics) ----------------------------------------------------------------------------

static bool isCharAscii(unsigned char code);
static bool isUtf8CodeWith2bytes(unsigned char code);
static bool isUtf8CodeWith3bytes(unsigned char code);
static bool isUtf8CodeWith4bytes(unsigned char code);

// Private Variables (statics) -----------------------------------------------------------------------------------------

// Public Variables ----------------------------------------------------------------------------------------------------

// Public and Private Functions Definitions ----------------------------------------------------------------------------

int conv_Char2Int(char c) {
   int i = -1;

   if ((c >= '0') && (c <= '9')) {
      i = (c - '0');
   }

   return (i);
}

char conv_Int2Char(int i) {
   char c = ASC_NUL;

   if ((i >= 0) && (i <= 9)) {
      c = (i + '0');
   }

   return (c);
}

void conv_Int2Str(uint32_t decIntFrom, char *pStrTo) {
   assert(IS_POINTER_NOT_NULL(pStrTo));

   const int numLenMax = 10;

   STR_DECLARE(char, numStr, numLenMax);
   int numStrTargetIndex = numLenMax;
   numStr[numStrTargetIndex] = ASC_NUL;

   if (0 == decIntFrom) {
      numStr[--numStrTargetIndex] = '0';
   } else {
      while ((decIntFrom > 0) && (numStrTargetIndex > 0)) {
         numStr[--numStrTargetIndex] = conv_Int2Char(decIntFrom % 10);
         decIntFrom /= 10;
      }
   }

   strcpy(pStrTo, &numStr[numStrTargetIndex]);
}

uint32_t conv_Str2Int(const char *pInStr) {
   uint32_t integer = 0;

   for (size_t i = 0; pInStr[i] != ASC_NUL; i++) {
      uint32_t digit = (uint32_t)conv_Char2Int(pInStr[i]);
      integer *= 10;
      integer += digit;
   }

   return (integer);
}

error_t conv_Utf8ToIso88591(const char *pUtf8Str, char *pIsoStr) {
   IF_TRUE_RETURN_VAL(IS_POINTER_NULL(pUtf8Str) || IS_POINTER_NULL(pIsoStr), ERROR_PARAMETER);

   const char replacementChar = '?';

   size_t utf8Index = 0;
   size_t isoIndex = 0;
   const unsigned char *src = (const unsigned char *)pUtf8Str;
   unsigned char *dst = (unsigned char *)pIsoStr;

   while (src[utf8Index]) {
      unsigned char byte = src[utf8Index++];
      unsigned char converted = replacementChar;

      if (isCharAscii(byte)) {
         converted = byte;
      } else if (isUtf8CodeWith2bytes(byte)) {
         converted = src[utf8Index++] - 0x80 + 0xC0;
      } else if (isUtf8CodeWith3bytes(byte)) {
         utf8Index += 2;
      } else if (isUtf8CodeWith4bytes(byte)) {
         utf8Index += 3;
      }

      dst[isoIndex++] = converted;
   }

   dst[isoIndex] = ASC_NUL;
   return (ERROR_NONE);
}

uint16_t conv_YearFrom2To4Digits(uint8_t yearIn2Digits) {
   return ((uint16_t)yearIn2Digits + CONV_YEAR_COMPLEMENT);
}

uint8_t conv_YearFrom4To2Digits(uint16_t yearIn4Digits) {
   return ((uint8_t)yearIn4Digits - CONV_YEAR_COMPLEMENT);
}

static bool isCharAscii(unsigned char code) {
   return (code < 0x80);
}
static bool isUtf8CodeWith2bytes(unsigned char code) {
   return ((code & 0xE0) == 0xC0);
}
static bool isUtf8CodeWith3bytes(unsigned char code) {
   return ((code & 0xF0) == 0xE0);
}
static bool isUtf8CodeWith4bytes(unsigned char code) {
   return ((code & 0xF8) == 0xF0);
}
