#include "types.h"
#include "siirtc.h"
#include "rtc.h"
#include "vars.h"
#include "constants/vars.h"
#include "save.h"
#include "debug.h"
#include "constants/time_types.h"
#include "text.h"

static const int days_per_month[12] =
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

bool is_leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int timestamp_to_days(timestamp_t *t) {
	int days = 0;
	for (int i = 0; i < t->year; i++) {
		days += 365;
		if (is_leap_year(i)) days++;
	}
	for (int i = 0; i < t->month - 1; i++) {
		days += days_per_month[i];
		if (i > MONTH_FEB && is_leap_year(t->year))
        	days++;
	}
	days += t->day - 1;
	return days;
}

u64 timestamp_to_seconds(timestamp_t *t) {
	int days = timestamp_to_days(t);
	return (u64)(days * 24 * 60 * 60 + t->hour * 60 * 60 + t->minute * 60 + t->second * 60);
}

void days_to_timestamp(int days, timestamp_t *result) {
	int years;
	for (years = 0; ; years++) {
		int days_in_year = 365 + is_leap_year(years);
		if (days < days_in_year)
			break;
		days -= days_in_year;
	}
	int months;
	for (months = 0; ; months++) {
		if (days < days_per_month[months])
			break;
		days -= days_per_month[months];
	}
	result->year = (u8) years;
	result->month = (u8) (months + 1); // 1-based
	result->day = (u8)(days + 1); // 1-based
}


bool time_test() {
	switch(*var_access(TIME_TYPE)) {
	case TIME_TYPE_RTC:
		return !RtcInErrorousState();;
	case TIME_TYPE_INGAME_CLOCK:
		return save2->hours_played != 999 || save2->minutes_played != 59;
	default:
		derrf("Unkown time type %d (test)\n", *var_access(TIME_TYPE));
		return false;
	}
}

#define INGAME_CLOCK_SPEED_UP 5 // 1s ingame time equals 5 seconds on the ingame clock

void time_ingame_clock_read(timestamp_t *s) {
	int seconds_played = INGAME_CLOCK_SPEED_UP * save2->seconds_played;
	s->second = (u8)(seconds_played % 60);
	int minutes_played = (INGAME_CLOCK_SPEED_UP * save2->minutes_played) + (seconds_played / 60);
	s->minute = (u8)(minutes_played % 60);
	int hours_played = (INGAME_CLOCK_SPEED_UP * save2->hours_played) + (minutes_played / 60);
	s->hour = (u8)(hours_played % 24);
	int days_played = hours_played / 24;
	days_to_timestamp(days_played, s);
}


void time_read(timestamp_t *t) {
	switch (*var_access(TIME_TYPE)) {
	case TIME_TYPE_RTC:
		// Read from rtc
		rtc_read(t);
		break;
	case TIME_TYPE_INGAME_CLOCK:
		// Read from the ingame clock
		time_ingame_clock_read(t);
		break;
	default :
		derrf("Unkown time type %d\n", *var_access(TIME_TYPE));
	}
}

void time_reset_events() {
	// Reset the a_gen_time
    time_read(&(cmem.a_gen_time));
    // Reset the fossil gen time
    time_read(&(cmem.fossil_gen_time));
}

void time_reset_ingame_clock() {
	// Reset the game time (only available at 999:99 time)
	save2->hours_played = 0;
	save2->minutes_played = 0;
	save2->seconds_played = 0;
	save2->milliseconds_played = 0;
	ingame_clock_status = 1; // clk is running again
}


u16 special_time_get() {
    timestamp_t stamp = {0};
    time_read(&stamp);
    switch (*var_access(0x8004)) {

        case 0:
            return stamp.year;
        case 1:
            return stamp.month;
        case 2:
            return stamp.day;
        case 3:
            return 0xFF;
        case 4:
            return stamp.hour;
        case 5:
            return stamp.minute;
        case 6:
            return stamp.second;
        default:
            return 0xFF;
    }
}

void buffer_time() {
    timestamp_t s = {0};
    time_read(&s);
	itoa(buffer0, s.hour, 2, 2);
	itoa(buffer1, s.minute, 2, 2);
}
