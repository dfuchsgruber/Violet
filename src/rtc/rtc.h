#include "../header/types.h"
#include "../header/romfuncs.h"

#ifndef RTC
#define RTC

typedef struct rtc_timestamp{
	
	u8 year;
	u8 month;
	u8 day;
	u8 day_of_week;
	u8 hour;
	u8 minute;
	u8 second;
}rtc_timestamp;


typedef struct gpio {
	
	u16 data;
	u16 out;
	u16 cntrl;
	
}gpio;

static gpio *gpios = (gpio *)0x080000C4;

#endif