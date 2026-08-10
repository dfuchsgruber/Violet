/*
 * cloud.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_CLOUD_H_
#define INCLUDE_C_TILE_CLOUD_H_
#include "types.h"


extern const u8 *script_cloud_none_ref;
extern const u8 *script_use_cloud_ref;
extern const u8 *script_use_cloud_back_ref;
extern const u8 *script_cloud_facings[5];
extern const u8 *script_cloud_force_ref[5];

const u8 *cloud_trigger(bool back);
void cloud_enter();

/**
 * Checks if the current map and player state allows the player to not dismount a cloud.
 * @return if the cloud can not be dismounted, i.e. the player has to be on a cloud
 **/
bool cloud_not_dismountable();

/**
 * Checks if the player should be forced off a cloud.
 * @return if the player should be forced off a cloud
 */
bool player_should_be_forced_off_cloud();

#endif /* INCLUDE_C_TILE_CLOUD_H_ */
