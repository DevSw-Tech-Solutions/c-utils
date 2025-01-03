#include "rtc_util.h"
#include "conv_util.h"
#include "lang_util.h"
#include "limits_util.h"
#include <assert.h>
#include <string.h>

// Private Defines -----------------------------------------------------------------------------------------------------

// Private Typedefs and Structures -------------------------------------------------------------------------------------

// Private Functions Declarations (statics) ----------------------------------------------------------------------------

static uint32_t extractNumberFromString(const char *pSrc, int length);
static int8_t invertTimezoneSignal(int8_t timezone);
static bool isNegativeTimezone(const char *pTimezone);

// Private Variables (statics) -----------------------------------------------------------------------------------------

// Public Variables ----------------------------------------------------------------------------------------------------

// Public and Private Functions Definitions ----------------------------------------------------------------------------

bool rtc_IsValid(const rtc_t *pRtc) {
   IF_TRUE_RETURN_VAL(pRtc == NULL, false);

   if ((pRtc->month <= MAX_MONTH) && (pRtc->month >= MIN_MONTH) && (pRtc->hour <= MAX_HOUR) &&
       (pRtc->minute <= MAX_MINUTE) && (pRtc->second <= MAX_SECOND) && (pRtc->timezone >= MIN_TIMEZONE) &&
       (pRtc->timezone <= MAX_TIMEZONE) && (pRtc->day <= rtc_daysInMonth(pRtc->month, pRtc->year)) &&
       (pRtc->day >= MIN_DAY)) {
      return (true);
   } else {
      return (false);
   }
}

bool rtc_IsLeapYear(uint16_t year) {
   return ((((year % 4u) == 0u) && (year % 100u != 0u)) || (year % 400u == 0u));
}

uint8_t rtc_daysInMonth(uint8_t month, uint16_t year) {
   assert((month >= MIN_MONTH) && (month <= MAX_MONTH));

   uint8_t daysPerMonth[] = {31u, 28u, 31u, 30u, 31u, 30u, 31u, 31u, 30u, 31u, 30u, 31u};

   if (rtc_IsLeapYear(year))
      daysPerMonth[2 - 1] = 29u;

   return (daysPerMonth[month - 1]);
}

rtc_weekday_t rtc_GetWeekday(const rtc_t *pRtc) {
   int32_t day = pRtc->day;
   int32_t month = pRtc->month;
   int32_t year = pRtc->year;
   int32_t weekday = 0;

   day += (month < 3) ? (year--) : (year - 2);
   weekday = (((23 * month) / 9) + day + 4 + (year / 4) - (year / 100) + (year / 400)) % 7;

   return ((rtc_weekday_t)weekday);
}

error_t rtc_ConvDtoToRtc(const rtc_dto_t *pSource, rtc_t *pTarget) {
   IF_TRUE_RETURN_VAL(pSource == NULL || pTarget == NULL, ERROR_PARAMETER);

   pTarget->year = rtc_ExtractYearFromDate(pSource->date);
   pTarget->month = rtc_ExtractMonthFromDate(pSource->date);
   pTarget->day = rtc_ExtractDayFromDate(pSource->date);
   pTarget->hour = rtc_ExtractHourFromTime(pSource->time);
   pTarget->minute = rtc_ExtractMinuteFromTime(pSource->time);
   pTarget->second = rtc_ExtractSecondFromTime(pSource->time);
   pTarget->timezone = rtc_ExtractTimezone(pSource->timezone);

   return ERROR_NONE;
}

uint16_t rtc_ExtractYearFromDate(const char *pDate) {
   // Format: "dd/mm/yyyy".
   //  Index:  0123456789.
   const int start = 6, length = 4;

   return (uint16_t)extractNumberFromString(&pDate[start], length);
}

uint8_t rtc_ExtractMonthFromDate(const char *pDate) {
   const int start = 3, length = 2;

   return (uint8_t)extractNumberFromString(&pDate[start], length);
}

uint8_t rtc_ExtractDayFromDate(const char *pDate) {
   const int start = 0, length = 2;

   return (uint8_t)extractNumberFromString(&pDate[start], length);
}

uint8_t rtc_ExtractHourFromTime(const char *pTime) {
   // Format: "hh:mm:ss".
   //  Index:  01234567.
   const int start = 0, length = 2;

   return (uint8_t)extractNumberFromString(&pTime[start], length);
}

uint8_t rtc_ExtractMinuteFromTime(const char *pTime) {
   const int start = 3, length = 2;

   return (uint8_t)extractNumberFromString(&pTime[start], length);
}

uint8_t rtc_ExtractSecondFromTime(const char *pTime) {
   const int start = 6, length = 2;

   return (uint8_t)extractNumberFromString(&pTime[start], length);
}

int8_t rtc_ExtractTimezone(const char *pTimezone) {
   // Format: "±hh".
   int8_t timezone = extractNumberFromString(&pTimezone[1], 2);

   if (isNegativeTimezone(pTimezone)) {
      timezone = invertTimezoneSignal(timezone);
   }

   return (timezone);
}

static uint32_t extractNumberFromString(const char *pSrc, int length) {
   STR_DECLARE(char, numberString, length);

   str_CopySubstring(numberString, pSrc, length);

   return (conv_Str2Int(numberString));
}

static int8_t invertTimezoneSignal(int8_t timezone) {
   return (timezone * -1);
}

static bool isNegativeTimezone(const char *pTimezone) {
   return (pTimezone[0] == '-');
}