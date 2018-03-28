/*
 * cloud.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_CLOUD_H_
#define INCLUDE_C_TILE_CLOUD_H_

extern script script_cloud_none_ref;
extern script script_use_cloud_ref;
extern script script_use_cloud_back_ref;
extern script script_cloud_facings[5];
extern script script_cloud_force_ref[5];

script cloud_trigger(bool back);
void cloud_enter();

#endif /* INCLUDE_C_TILE_CLOUD_H_ */
