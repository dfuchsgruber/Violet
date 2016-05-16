#include "../header/types.h"
#include "../header/romfuncs.h"
#include "../header/karma.h"


extern int signum(int i);
extern int abs(int i);

u16 addkarma(u16 *value){
	s16 v = (s16)(*value);
	s16 karma_points = (s16)(*vardecrypt(VAR_KARMA_POINTS) + v);
	if (karma_points > 200){
		karma_points = 200;
	}else if (karma_points < -200){
		karma_points = -200;
	}
	*vardecrypt(VAR_KARMA_POINTS) = (u16)karma_points;
	
	recalculate_karma();
	
	return (u16)v;
	
}

void recalculate_karma(){
	
	s16 karma_points = (s16)(*vardecrypt(VAR_KARMA_POINTS));
	s16 karma;
	if (abs(karma_points) < 200){
		karma = (s16)(__sqrt(80 * abs(karma_points)) * signum(karma_points)); //80 is numeric constant that provides a approximation	
	}else{
		karma = (s16)(127 * signum(karma_points));
	}
	*vardecrypt(VAR_KARMA) = (u16)karma;
	
}

