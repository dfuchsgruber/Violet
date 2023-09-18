/*
 * levelscript.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_LEVELSCRIPT_H_
#define INCLUDE_C_MAP_LEVELSCRIPT_H_

// Map levelscript header
typedef struct {
    u8 type;
    UNALIGNED_32 levelscript;
} levelscript_header_t;


/**
 * Checks if a levelscript can be triggered and returns it
 * @param type the levelscript type to trigger
 * @return the levelscript
 */
const u8 *map_levelscript_get_if_triggered(u8 type);

/**
 * Triggers a levelscript of a certain type on the current map if it provides one. No varchecks
 * are performed
 * @param type the levelscript type to trigger
 */
void map_levelscript_init_no_var_check(u8 type);

/**
 * Tries to automatically use flash.
 * @return true if flash is used automatically
 **/
bool map_flash_try_automatic_usage();

#endif /* INCLUDE_C_MAP_LEVELSCRIPT_H_ */
