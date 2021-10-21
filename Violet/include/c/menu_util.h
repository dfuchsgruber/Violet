#ifndef H_MENU_UTIL
#define H_MENU_UTIL

#include "types.h"

/**
 * Adjusts a quantity by processing key input and plays a proper sound. Up/Down toggles +- 1, while left/right toggles +-10. Wraps arround.
 * @param quantity the value to adjust
 * @param max the maximum value
 * @return if the value was adjusted by keys
 */
bool quantity_adjust_by_key_input(u16 *quantity, u16 max);

#endif
