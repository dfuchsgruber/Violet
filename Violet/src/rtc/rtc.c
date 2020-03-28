#include "types.h"
#include "siirtc.h"
#include "rtc.h"
#include "save.h"
#include "io.h"
#include "debug.h"

// Taken from: https://github.com/pret/pokeemerald/blob/master/src/rtc.c

static const s32 sNumDaysInMonths[12] =
{
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31,
};

void RtcDisableInterrupts(void)
{
    fmem.rtc_saved_interrupts = IO_IME;
    IO_IME = 0;
}

void RtcRestoreInterrupts(void)
{
    IO_IME = fmem.rtc_saved_interrupts;
}

u32 ConvertBcdToBinary(u8 bcd)
{
    if (bcd > 0x9F)
        return 0xFF;

    if ((bcd & 0xF) <= 9)
        return (u32)((10 * ((bcd >> 4) & 0xF)) + (bcd & 0xF));
    else
        return 0xFF;
}
/**


bool IsLeapYear(u32 year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;

    return true;
}

u16 ConvertDateToDayCount(u8 year, u8 month, u8 day)
{
    s32 i;
    int dayCount = 0;

    for (i = year - 1; i >= 0; i--)
    {
        dayCount += 365;

        if (IsLeapYear((u32)i) == true)
            dayCount++;
    }

    for (i = 0; i < month - 1; i++)
        dayCount += sNumDaysInMonths[i];

    if (month > MONTH_FEB && IsLeapYear(year) == true)
        dayCount++;

    dayCount += day;

    return (u16)dayCount;
}

void ConvertDayCountToDate(int day_count, u8 *year, u8 *month, u8 *day) {
    *year = 0;
    int days_in_year;
    while (true) {
        days_in_year = 365 + (IsLeapYear(*year) ? 1 : 0);
        if (day_count >= days_in_year) {
            day_count -= days_in_year;
            ++*year;
        } else {
            break;
        }
    }
    *month = 1;
    while (true) {
        int days_in_month = sNumDaysInMonths[*month] + (*month == MONTH_FEB && IsLeapYear(*year) ? 1 : 0);
        if (day_count >= days_in_month) {
            day_count -= days_in_month;
            ++*month;
        } else {
            break;
        }
    }
    *day = (u8)(day_count + 1);
}

u16 RtcGetDayCount(struct SiiRtcInfo *rtc)
{
    u8 year = (u8)ConvertBcdToBinary(rtc->year);
    u8 month =  (u8)ConvertBcdToBinary(rtc->month);
    u8 day =  (u8)ConvertBcdToBinary(rtc->day);
    return (u16)ConvertDateToDayCount(year, month, day);
}
**/

void RtcInit(void)
{
    fmem.rtc_error_status = 0;

    RtcDisableInterrupts();
    SiiRtcUnprotect();
    fmem.rtc_probe_result = SiiRtcProbe();
    RtcRestoreInterrupts();

    if ((fmem.rtc_probe_result & 0xF) != 1)
    {
        fmem.rtc_error_status = RTC_INIT_ERROR;
        return;
    }

    if (fmem.rtc_probe_result & 0xF0)
        fmem.rtc_error_status = RTC_INIT_WARNING;
    else
        fmem.rtc_error_status = 0;

    RtcGetRawInfo(&fmem.gp_rtc);
    dprintf("After initialization, error state of rtc is 0x%x\n", fmem.rtc_error_status);
    fmem.rtc_error_status = RtcCheckInfo(&fmem.gp_rtc);
}

u16 RtcGetErrorStatus(void)
{
    return fmem.rtc_error_status;
}

bool RtcInErrorousState() {
    SiiRtcGetDateTime(&fmem.gp_rtc);
    dprintf("RTC state: y:%d, m:%d, d:%d, h:%d, m:%d, s:%d, state 0x%x\n", fmem.gp_rtc.year, fmem.gp_rtc.month, fmem.gp_rtc.day, fmem.gp_rtc.hour, fmem.gp_rtc.minute, fmem.gp_rtc.second, fmem.gp_rtc.status);
    dprintf("RTC in error state 0x%x\n", fmem.rtc_error_status);
    return (fmem.rtc_error_status & RTC_ERR_FLAG_MASK) != 0;
}
void RtcGetInfo(struct SiiRtcInfo *rtc)
{
    /**
    if (fmem.rtc_error_status & RTC_ERR_FLAG_MASK)
        *rtc = fmem.gp_rtc;
    else
    **/
        RtcGetRawInfo(rtc);
}

void RtcGetDateTime(struct SiiRtcInfo *rtc)
{
    RtcDisableInterrupts();
    SiiRtcGetDateTime(rtc);
    RtcRestoreInterrupts();
}

void RtcGetStatus(struct SiiRtcInfo *rtc)
{
    RtcDisableInterrupts();
    SiiRtcGetStatus(rtc);
    RtcRestoreInterrupts();
}

void RtcGetRawInfo(struct SiiRtcInfo *rtc)
{
    RtcGetStatus(rtc);
    RtcGetDateTime(rtc);
}

u16 RtcCheckInfo(struct SiiRtcInfo *rtc)
{
    u16 errorFlags = 0;
    s32 year;
    s32 month;
    s32 value;

    if (rtc->status & SIIRTCINFO_POWER)
        errorFlags |= RTC_ERR_POWER_FAILURE;

    if (!(rtc->status & SIIRTCINFO_24HOUR))
        errorFlags |= RTC_ERR_12HOUR_CLOCK;

    year = (s32)ConvertBcdToBinary(rtc->year);

    if (year == 0xFF)
        errorFlags |= RTC_ERR_INVALID_YEAR;

    month = (s32)ConvertBcdToBinary(rtc->month);

    if (month == 0xFF || month == 0 || month > 12)
        errorFlags |= RTC_ERR_INVALID_MONTH;

    value = (s32)ConvertBcdToBinary(rtc->day);

    if (value == 0xFF)
        errorFlags |= RTC_ERR_INVALID_DAY;

    if (month == MONTH_FEB)
    {
        if (value > is_leap_year(year) + sNumDaysInMonths[month - 1])
            errorFlags |= RTC_ERR_INVALID_DAY;
    }
    else
    {
        if (value > sNumDaysInMonths[month - 1])
            errorFlags |= RTC_ERR_INVALID_DAY;
    }

    value = (s32)ConvertBcdToBinary(rtc->hour);

    if (value > 24)
        errorFlags |= RTC_ERR_INVALID_HOUR;

    value = (s32)ConvertBcdToBinary(rtc->minute);

    if (value > 60)
        errorFlags |= RTC_ERR_INVALID_MINUTE;

    value = (s32)ConvertBcdToBinary(rtc->second);

    if (value > 60)
        errorFlags |= RTC_ERR_INVALID_SECOND;

    return errorFlags;
}

void RtcReset(void)
{
    RtcDisableInterrupts();
    SiiRtcReset();
    RtcRestoreInterrupts();
}

void rtc_read(timestamp_t *t) {
    SiiRtcInfo_t raw_t = {0};
    RtcGetStatus(&raw_t);
    t->year = (u8)ConvertBcdToBinary(raw_t.year);
    t->month = (u8)ConvertBcdToBinary(raw_t.month);
    t->day = (u8)ConvertBcdToBinary(raw_t.day);
    t->hour = (u8)ConvertBcdToBinary(raw_t.hour);
    t->minute = (u8)ConvertBcdToBinary(raw_t.minute);
    t->second = (u8)ConvertBcdToBinary(raw_t.second);
}