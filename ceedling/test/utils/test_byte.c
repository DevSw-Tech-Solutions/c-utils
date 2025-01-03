#include "byte_util.h"
#include "unity.h"
#include <string.h>

void test_constants(void) {
   TEST_ASSERT_EQUAL(1024, KB);
   TEST_ASSERT_EQUAL(8, SET_BIT(3));
}
