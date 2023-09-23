#include "types.h"
#include "rtc.h"
#include "vars.h"
#include "constants/vars.h"
#include "save.h"
#include "debug.h"
#include "constants/time_types.h"
#include "text.h"
#include "berry.h"
#include "dns.h"

bool time_test() {
	switch(*var_access(TIME_TYPE)) {
	case TIME_TYPE_RTC:
		return rtc_test();
	case TIME_TYPE_INGAME_CLOCK:
		return save2->hours_played != 999 || save2->minutes_played != 59;
	default:
		ERROR("Unkown time type %d (test)\n", *var_access(TIME_TYPE));
		return false;
	}
}

void time_ingame_clock_read(rtc_timestamp *s) {
	int seconds_played = INGAME_CLOCK_SPEED_UP * save2->seconds_played;
	s->second = (u8)(seconds_played % 60);
	int minutes_played = (INGAME_CLOCK_SPEED_UP * save2->minutes_played) + (seconds_played / 60);
	s->minute = (u8)(minutes_played % 60);
	int hours_played = (INGAME_CLOCK_SPEED_UP * save2->hours_played) + (minutes_played / 60) + 12;
	s->hour = (u8)(hours_played % 24);
	int days_played = hours_played / 24;
	s->day = (u8)((days_played % 30) + 1);
	int months_played = (u8)(days_played / 30);
	s->month = (u8)((months_played % 12) + 1);
	int years_played = months_played / 12;
	s->year = (u8)(20 + years_played);
}


void time_read(rtc_timestamp *s) {
	switch (*var_access(TIME_TYPE)) {
	case TIME_TYPE_RTC:
		// Read from rtc
		rtc_read(s);
		break;

	case TIME_TYPE_INGAME_CLOCK:
		// Read from the ingame clock
		time_ingame_clock_read(s);
		break;
	default :
		ERROR("Unkown time type %d\n", *var_access(TIME_TYPE));
	}
}

void time_reset_events() {
	// Reset the a_gen_time
    time_read(&(csave.daily_events_last_update));
    // Reset the fossil gen time
    time_read(&(csave.fossil_gen_time));
	berry_tree_time_last_updated_initialized = 0;
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
    rtc_timestamp stamp = {0, 0, 0, 0, 0, 0, 0};
    time_read(&stamp);
    switch (*var_access(0x8004)) {

        case 0:
            return stamp.year;
        case 1:
            return stamp.month;
        case 2:
            return stamp.day;
        case 3:
            return stamp.day_of_week;
        case 4:
            return stamp.hour;
        case 5:
            return stamp.minute;
        case 6:
            return stamp.second;
        default:
            return 0;
    }
}

void buffer_time() {
    rtc_timestamp s = {0, 0, 0, 0, 0, 0, 0};
    time_read(&s);
	itoa(buffer0, s.hour, 2, 2);
	itoa(buffer1, s.minute, 2, 2);
}

void time_based_events_run() {
	DEBUG("Time Proceed.\n");
	berry_proceed();
    daily_events_proceed();
	// update_timezone();
}

void time_based_events_proceed(u16 *vars) {
	// After running time based events, wait 256 vblanks to switch into a waiting state, then wait another 0x1000 frames
	switch(vars[0]) {
		case 0: {
			if (super.local_vlbank_cnt & 0x100) {
				time_based_events_run();
				vars[0] = 1; 
			}
			break;
		}
		case 1: 
		default: {
			if (!(super.local_vlbank_cnt & 0x100)) {
				vars[0] = 0;
			}
		}
	}
}

