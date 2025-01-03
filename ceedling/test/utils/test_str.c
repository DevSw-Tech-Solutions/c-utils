#include "str_util.h"
#include "unity.h"
#include <string.h>

void test_keepOnlyNumbers(void) {
   char str1[] = "123.456.789-01";
   char str2[] = "123.456.789-01";

   str_KeepOnlyNumbers(str2, (const char *)str1);

   TEST_ASSERT_EQUAL_STRING("12345678901", str2);
   TEST_ASSERT_EQUAL_STRING("123.456.789-01", str1);
}

void test_clearContent(void) {
   char str[] = "Testing str_ClearContent";

   TEST_ASSERT_EQUAL_STRING("Testing str_ClearContent", str);
   str_ClearContent(str);
   TEST_ASSERT_EQUAL_STRING("", str);

   strcpy(str, "New test");
   TEST_ASSERT_EQUAL_STRING("New test", str);
   str_ClearContent(str);
   TEST_ASSERT_EQUAL_STRING("", str);
}

void test_trim(void) {
   char str[32] = "Testing str_Trim";

   TEST_ASSERT_EQUAL_STRING("Testing str_Trim", str);
   str_Trim(str);
   TEST_ASSERT_EQUAL_STRING("Testing str_Trim", str);

   strcpy(str, " New test");
   TEST_ASSERT_EQUAL_STRING(" New test", str);
   str_Trim(str);
   TEST_ASSERT_EQUAL_STRING("New test", str);

   strcpy(str, "  Other");
   TEST_ASSERT_EQUAL_STRING("  Other", str);
   str_Trim(str);
   TEST_ASSERT_EQUAL_STRING("Other", str);

   strcpy(str, "One more ");
   TEST_ASSERT_EQUAL_STRING("One more ", str);
   str_Trim(str);
   TEST_ASSERT_EQUAL_STRING("One more", str);

   strcpy(str, "123456789123456789  ");
   TEST_ASSERT_EQUAL_STRING("123456789123456789  ", str);
   str_Trim(str);
   TEST_ASSERT_EQUAL_STRING("123456789123456789", str);
}

void test_ensureLeftPadding(void) {
   STR_DECLARE(char, str, 10);

   strcpy(str, "123");
   str_EnsureLeftPadding(str, '0', 10);
   TEST_ASSERT_EQUAL_STRING("0000000123", str);

   strcpy(str, "");
   str_EnsureLeftPadding(str, 'R', 9);
   TEST_ASSERT_EQUAL_STRING("RRRRRRRRR", str);

   strcpy(str, "123456");
   str_EnsureLeftPadding(str, '0', 6);
   TEST_ASSERT_EQUAL_STRING("123456", str);
}

void test_ensureRightPadding(void) {
   STR_DECLARE(char, str, 10);

   strcpy(str, "123");
   str_EnsureRightPadding(str, ' ', 10);
   TEST_ASSERT_EQUAL_STRING("123       ", str);

   strcpy(str, "");
   str_EnsureRightPadding(str, 'R', 9);
   TEST_ASSERT_EQUAL_STRING("RRRRRRRRR", str);

   strcpy(str, "123456");
   str_EnsureRightPadding(str, '0', 6);
   TEST_ASSERT_EQUAL_STRING("123456", str);
}