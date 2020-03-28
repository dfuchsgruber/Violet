

#ifndef GUARD_RTC_UTIL_H
#define GUARD_RTC_UTIL_H

#include "siirtc.h"

#define RTC_INIT_ERROR         0x0001
#define RTC_INIT_WARNING       0x0002

#define RTC_ERR_12HOUR_CLOCK   0x0010
#define RTC_ERR_POWER_FAILURE  0x0020
#define RTC_ERR_INVALID_YEAR   0x0040
#define RTC_ERR_INVALID_MONTH  0x0080
#define RTC_ERR_INVALID_DAY    0x0100
#define RTC_ERR_INVALID_HOUR   0x0200
#define RTC_ERR_INVALID_MINUTE 0x0400
#define RTC_ERR_INVALID_SECOND 0x0800

#define RTC_ERR_FLAG_MASK      0x0FF0

extern struct Time gLocalTime;

void RtcDisableInterrupts(void);
void RtcRestoreInterrupts(void);
void RtcInit(void);
bool RtcInErrorousState();
u16 RtcGetErrorStatus(void);
void RtcGetInfo(struct SiiRtcInfo *rtc);
void RtcGetDateTime(struct SiiRtcInfo *rtc);
void RtcGetStatus(struct SiiRtcInfo *rtc);
void RtcGetRawInfo(struct SiiRtcInfo *rtc);
u16 RtcCheckInfo(struct SiiRtcInfo *rtc);
void RtcReset(void);
bool is_leap_year(int year);



u8 ingame_clock_status;

typedef struct {
    u8 year; // [0, [
    u8 month; // [1, 12]
    u8 day; // [1, 31]
    u8 hour; // [0, 59]
    u8 minute; // [0, 59]
    u8 second; // [0, 59]
} timestamp_t;


/**
 * Reads from the rtc.
 * @param t where to store the time
 **/
void rtc_read(timestamp_t *t);

/**
 * Gets the current game time (either rtc or built-in frame counter.)
 * @param s target timestamp to return the time at
 */
void time_read(timestamp_t *s);

/**
 * Gets the current game time from the ingame clock.
 * @param s target timestamp to return the time at
 */
void time_ingame_clock_read(timestamp_t *s);

/**
 * Resets all time based events.
 */
void time_reset_events();

/**
 * Checks if the current time system (rtc or ingame time) works.
 * @return if the current time system works.
 **/
bool time_test();

/**
 * Calculates how many days have passed in a certain timestamp.
 * @param t the timestamp
 * @return how many days have passed in a timestamp
 **/
int timestamp_to_days(timestamp_t *t);

/**
 * Sets a timestamp to a certain amounts of days that have passed.
 * @param days how many days have passed
 * @param result the timestamp to initalize the year, month and day of
 **/
void days_to_timestamp(int days, timestamp_t *result);

/**
 * Calcualtes how many seconds a timestamp contains.
 * @param t the timestamp
 * @return how many seconds the timestamp contains
 **/
u64 timestamp_to_seconds(timestamp_t *t);

#endif // GUARD_RTC_UTIL_H

