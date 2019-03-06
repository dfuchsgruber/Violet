/*
 * summary.h
 *
 *  Created on: Mar 3, 2019
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_SUMMARY_H_
#define INCLUDE_C_OVERWORLD_SUMMARY_H_

#include "types.h"
#include "pokemon/virtual.h"
#include "text.h"

typedef struct {
	u8 unkown[0x3004];
	u8 tbox_memo;
	u8 unkown2[0x1FF];
	u8 sanity;
	u8 unkown3[0x8B];
	pokemon current_pokemon;
	pokemon *current_pokemon_in_party; // may refer to opponents pokemon?
} summary_state_stru;

extern summary_state_stru *summary_state;

extern tbox_font_colormap summary_egg_memo_fontcolmap;

#endif /* INCLUDE_C_OVERWORLD_SUMMARY_H_ */
