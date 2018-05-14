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
    MISALIGNED_32 levelscript;
} levelscript_head;


/**
 * Checks if a levelscript can be triggered and returns it
 * @param type the levelscript type to trigger
 * @return the levelscript
 */
u8 *map_levelscript_get_if_triggered(u8 type);

#endif /* INCLUDE_C_MAP_LEVELSCRIPT_H_ */
