/*
 * tv.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

 #include "types.h"

#ifndef INCLUDE_C_TILE_TV_H_
#define INCLUDE_C_TILE_TV_H_

/**
    * Checks if the TV broadcast is currently on.
    * This is used to determine if the player can watch TV.
    * 
    * @return true if the TV broadcast is on, false otherwise.
*/
bool tv_broadcast_is_on();


void load_tv_text();
const u8 *get_tv_text();

#endif /* INCLUDE_C_TILE_TV_H_ */
