#include "../header/types.h"
#include "../header/romfuncs.h"
#include "../header/rtc.h"
#include "../header/map.h"
#include "../header/color.h"

void callback_switch_timezone(){
	
	
	rtc_timestamp stamp = {0, 0, 0, 0, 0, 0 ,0};
	rtc_read(&stamp);
	if (stamp.hour >= 22 || stamp.hour <= 6){
		
		*vardecrypt(VAR_TIMEZONE) = 1; //night
	}else{
		*vardecrypt(VAR_TIMEZONE) = 0;
	}
	
	set_callback1((void*)0x08056829); //return to normal map reload
	
}