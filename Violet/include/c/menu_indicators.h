#ifndef H_MENU_INDICATORS
#define H_MENU_INDICATORS

#include "types.h"

typedef struct {
    u8 arrow0_type;
    u8 arrow0_x;
    u8 arrow0_y;
    u8 arrow1_type;
    u8 arrow1_x;
    u8 arrow1_y;
    u16 fully_up_threshold;
    u16 fully_down_threshold;
    u16 tiles_tag;
    u16 pal_tag;
    u8 pal_num;
};

/**
 * Removes a scroll indicator arrow pair
 * @param callback_idx the callback of the scroll indicators
 **/
void scroll_indicator_delete(u8 callback_idx);



#endif
