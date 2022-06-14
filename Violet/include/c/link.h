#ifndef H_LINK
#define H_LINK

#include "types.h"

/**
 * @brief Checks if link is active and should be waited for
 * 
 * @return true 
 * @return false 
 */
bool menu_util_link_is_active();

/**
 * @brief Checks if links is active and busy.
 * 
 * @return true 
 * @return false 
 */
bool menu_util_link_is_busy();

#endif