#include "../header/types.h"
#include "../header/color.h"


int abs (int i){
	if (i < 0){
		return -i;
	}
	return i;
}

int signum (int i){
	if (i < 0){
		return -1;
	}else if (i > 0){
		return 1;
	}
	return 0;
}

color alpha_blend (color original, color overlay, u8 alpha){
	
	int i_alpha = 16 - alpha;
	int red = ((overlay.rgb.red * alpha)>>4) + ((original.rgb.red * i_alpha)>>4);
	int green = ((overlay.rgb.green * alpha)>>4) + ((original.rgb.green * i_alpha)>>4);
	int blue = ((overlay.rgb.blue * alpha)>>4) + ((original.rgb.blue * i_alpha)>>4);
	u16 value = (u16)(red | (green << 5) | (blue << 10));
	color c = {value};
	return c;
	
}