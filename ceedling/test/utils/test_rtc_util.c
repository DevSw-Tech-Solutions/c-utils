#include "conv_util.h"
#include "error_util.h"
#include "rtc_util.h"
#include "str_util.h"
#include "unity.h"
#include <string.h>

void test_execute(void) {
   rtc_dto_t dto = {.date = "21/11/2024", .time = "13:40:00", .timezone = "-03"};

   rtc_t rtc;

   TEST_ASSERT_EQUAL(ERROR_NONE, rtc_ConvDtoToRtc(&dto, &rtc));

   TEST_ASSERT_EQUAL(21, rtc.day);
   TEST_ASSERT_EQUAL(11, rtc.month);
   TEST_ASSERT_EQUAL(2024, rtc.year);
   TEST_ASSERT_EQUAL(13, rtc.hour);
   TEST_ASSERT_EQUAL(40, rtc.minute);
   TEST_ASSERT_EQUAL(0, rtc.second);
   TEST_ASSERT_EQUAL(-3, rtc.timezone);
}
