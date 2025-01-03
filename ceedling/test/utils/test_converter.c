#include "conv_util.h"
#include "str_util.h"
#include "unity.h"
#include <string.h>

void test_char2Int(void) {
   TEST_ASSERT_EQUAL(0, conv_Char2Int('0'));
   TEST_ASSERT_EQUAL(1, conv_Char2Int('1'));
   TEST_ASSERT_EQUAL(2, conv_Char2Int('2'));
   TEST_ASSERT_EQUAL(3, conv_Char2Int('3'));
   TEST_ASSERT_EQUAL(4, conv_Char2Int('4'));
   TEST_ASSERT_EQUAL(5, conv_Char2Int('5'));
   TEST_ASSERT_EQUAL(6, conv_Char2Int('6'));
   TEST_ASSERT_EQUAL(7, conv_Char2Int('7'));
   TEST_ASSERT_EQUAL(8, conv_Char2Int('8'));
   TEST_ASSERT_EQUAL(9, conv_Char2Int('9'));
   TEST_ASSERT_EQUAL(-1, conv_Char2Int('A'));
   TEST_ASSERT_EQUAL(-1, conv_Char2Int('0' - 1));
   TEST_ASSERT_EQUAL(-1, conv_Char2Int('9' + 1));
}

void test_int2Char(void) {
   TEST_ASSERT_EQUAL_CHAR('0', conv_Int2Char(0));
   TEST_ASSERT_EQUAL_CHAR('1', conv_Int2Char(1));
   TEST_ASSERT_EQUAL_CHAR('2', conv_Int2Char(2));
   TEST_ASSERT_EQUAL_CHAR('3', conv_Int2Char(3));
   TEST_ASSERT_EQUAL_CHAR('4', conv_Int2Char(4));
   TEST_ASSERT_EQUAL_CHAR('5', conv_Int2Char(5));
   TEST_ASSERT_EQUAL_CHAR('6', conv_Int2Char(6));
   TEST_ASSERT_EQUAL_CHAR('7', conv_Int2Char(7));
   TEST_ASSERT_EQUAL_CHAR('8', conv_Int2Char(8));
   TEST_ASSERT_EQUAL_CHAR('9', conv_Int2Char(9));
   TEST_ASSERT_EQUAL_CHAR('\0', conv_Int2Char(10));
   TEST_ASSERT_EQUAL_CHAR('\0', conv_Int2Char(-1));
}

void test_int2Str(void) {
   STR_DECLARE(char, numStr, 10);

   conv_Int2Str(0, numStr);
   TEST_ASSERT_EQUAL_STRING("0", numStr);

   conv_Int2Str(4294967295, numStr);
   TEST_ASSERT_EQUAL_STRING("4294967295", numStr);

   conv_Int2Str(999999999, numStr);
   TEST_ASSERT_EQUAL_STRING("999999999", numStr);

   conv_Int2Str(1, numStr);
   TEST_ASSERT_EQUAL_STRING("1", numStr);

   conv_Int2Str(10, numStr);
   TEST_ASSERT_EQUAL_STRING("10", numStr);

   conv_Int2Str(100, numStr);
   TEST_ASSERT_EQUAL_STRING("100", numStr);

   conv_Int2Str(1000, numStr);
   TEST_ASSERT_EQUAL_STRING("1000", numStr);

   conv_Int2Str(10000, numStr);
   TEST_ASSERT_EQUAL_STRING("10000", numStr);

   conv_Int2Str(100000, numStr);
   TEST_ASSERT_EQUAL_STRING("100000", numStr);

   conv_Int2Str(1000000, numStr);
   TEST_ASSERT_EQUAL_STRING("1000000", numStr);

   conv_Int2Str(10000000, numStr);
   TEST_ASSERT_EQUAL_STRING("10000000", numStr);

   conv_Int2Str(100000000, numStr);
   TEST_ASSERT_EQUAL_STRING("100000000", numStr);

   conv_Int2Str(1000000000, numStr);
   TEST_ASSERT_EQUAL_STRING("1000000000", numStr);

   conv_Int2Str(1234567890, numStr);
   TEST_ASSERT_EQUAL_STRING("1234567890", numStr);
}

void test_utf8ToIso88591(void) {
   char utf8Str[100];
   char isoStr[100];

   strcpy(utf8Str, "Bênção");
   TEST_ASSERT_EQUAL(ERROR_NONE, conv_Utf8ToIso88591(utf8Str, isoStr));
   TEST_ASSERT_EQUAL_STRING("B\xEAn\xE7\xE3o", isoStr);
}

void test_str2Int(void) {
   TEST_ASSERT_EQUAL(123456789, conv_Str2Int("123456789"));
   TEST_ASSERT_EQUAL(999999999, conv_Str2Int("999999999"));
   TEST_ASSERT_EQUAL(100, conv_Str2Int("100"));
   TEST_ASSERT_EQUAL(2, conv_Str2Int("002"));
   TEST_ASSERT_EQUAL(0, conv_Str2Int("0"));
   TEST_ASSERT_EQUAL(1, conv_Str2Int("1"));
}

void test_yearFrom2To4Digits(void) {
   TEST_ASSERT_EQUAL(2024, conv_YearFrom2To4Digits(24));
}

void test_yearFrom4To2Digits(void) {
   TEST_ASSERT_EQUAL(24, conv_YearFrom4To2Digits(2024));
}