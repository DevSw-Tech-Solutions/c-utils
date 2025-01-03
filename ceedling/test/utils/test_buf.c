#include "buf_util.h"
#include "unity.h"
#include <string.h>

void test_keepOnlyNumbers(void) {
   uint8_t buf1[7] = {3, 3, 3, 3, 3, 3, 3};
   uint8_t buf2[7] = {3, 3, 3, 3, 1, 3, 3};

   TEST_ASSERT_TRUE(buf_IsAllBytesEqual(buf1, sizeof(buf1)));
   TEST_ASSERT_FALSE(buf_IsAllBytesEqual(buf2, sizeof(buf2)));
}
