#include "int_util.h"
#include "unity.h"
#include <string.h>

void test_constants(void) {
   TEST_ASSERT_TRUE(IS_EVEN(1000));
   TEST_ASSERT_TRUE(IS_ODD(-1));
}
