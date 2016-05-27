#include "types.h"
#include "romfuncs.h"

int modify_exp (int exp){
	
	int new_exp = exp;
	
	//Applying difficulty
	switch(*vardecrypt(0x50F9)){
		
		case 0:
			new_exp <<= 1; // 2.0
			break;
		case 1:
			new_exp += (new_exp >> 1); // 1.5
			break;
		case 3:
			new_exp -= (new_exp >> 2); // 0.75
			break;
		case 4:
			new_exp >>=1; //0.5
			break;
	}
	return new_exp;
}