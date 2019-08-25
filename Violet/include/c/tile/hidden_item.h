/*
 * hidden_item.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_HIDDEN_ITEM_H_
#define INCLUDE_C_TILE_HIDDEN_ITEM_H_

typedef struct {
    u32 item : 16;
    u32 flag : 8;
    u32 amount : 4;
    u32 detector_disabled : 1;
    u32 chunk : 3;
} hidden_item_t;

typedef struct {
    u8 bank;
    u8 map_idx;
    u8 field_2;
    u8 field_3;
    u8 flags_10_percent[8];
    u8 flags_30_percent[8];
    u8 flags_40_percent[8];
} hidden_item_respawnable_chunk_t;

// Hidden item flags that respawn daily (this feature is turned of by tile.asm patch)
hidden_item_respawnable_chunk_t hidden_item_respawnable[15];

extern u8 script_hidden_item_trainer_tipp_shell[];
extern u8 script_hidden_item_trainer_tipp_mushroom[];
extern u8 script_hidden_item_add[];

#endif /* INCLUDE_C_TILE_HIDDEN_ITEM_H_ */
