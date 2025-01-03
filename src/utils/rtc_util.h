#ifndef _RTC_UTIL_H_
#define _RTC_UTIL_H_

// Includes ------------------------------------------------------------------------------------------------------------

#include "error_util.h"
#include "str_util.h"
#include <stdbool.h>
#include <stdint.h>

// Public Defines ------------------------------------------------------------------------------------------------------

#define RTC_DATE_STR_LENGTH (10)
#define RTC_TIME_STR_LENGTH (8)
#define RTC_TIMEZONE_STR_LENGTH (3)

// Public Typedefs and Structures --------------------------------------------------------------------------------------

typedef struct {
   uint16_t year;
   uint8_t month;
   uint8_t day;
   uint8_t hour;
   uint8_t minute;
   uint8_t second;
   int8_t timezone;
} rtc_t;

typedef enum {
   RTC_SUNDAY = 0,
   RTC_MONDAY,
   RTC_TUESDAY,
   RTC_WEDNESDAY,
   RTC_THURSDAY,
   RTC_FRIDAY,
   RTC_SATURDAY
} rtc_weekday_t;

typedef struct {
   STR_DECLARE(char, date, RTC_DATE_STR_LENGTH);         // Format: "dd/mm/aaaa".
   STR_DECLARE(char, time, RTC_TIME_STR_LENGTH);         // Format: "hh:mm:ss".
   STR_DECLARE(char, timezone, RTC_TIMEZONE_STR_LENGTH); // Format: "±hh".
} rtc_dto_t;

// Public Variables (externs) ------------------------------------------------------------------------------------------

// Public Functions Declarations ---------------------------------------------------------------------------------------

bool rtc_IsValid(const rtc_t *pRtc);

bool rtc_IsLeapYear(uint16_t year);
uint8_t rtc_daysInMonth(uint8_t month, uint16_t year);

rtc_weekday_t rtc_GetWeekday(const rtc_t *pRtc);

error_t rtc_ConvDtoToRtc(const rtc_dto_t *pSource, rtc_t *pTarget);

uint16_t rtc_ExtractYearFromDate(const char *pDate);
uint8_t rtc_ExtractMonthFromDate(const char *pDate);
uint8_t rtc_ExtractDayFromDate(const char *pDate);
uint8_t rtc_ExtractHourFromTime(const char *pTime);
uint8_t rtc_ExtractMinuteFromTime(const char *pTime);
uint8_t rtc_ExtractSecondFromTime(const char *pTime);
int8_t rtc_ExtractTimezone(const char *pTimezone);

#endif
