#ifndef H_ITEM_ANIMATION
#define H_ITEM_ANIMATION

#include "types.h"

/**
 * Checks if the item animation is disabled
 * @return if the item animation is disabled
 **/
bool item_animation_is_disabled();


extern u16 item_animation_get_animation_type(u16 item_idx);

#endif