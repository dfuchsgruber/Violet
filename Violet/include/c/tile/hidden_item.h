/*
 * hidden_item.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_HIDDEN_ITEM_H_
#define INCLUDE_C_TILE_HIDDEN_ITEM_H_

enum hidden_item_field{
    HIDDEN_ITEM_IDX = 0,
    HIDDEN_FLAG = 1,
    HIDDEN_COUNT = 2,
    HIDDEN_UNDERFOOT = 3,
    HIDDEN_CHUNK = 4,
};

typedef struct {
    u32 item : 16;
    u32 flag : 8;
    u32 amount : 4;
    u32 detector_disabled : 1;
    u32 chunk : 3;
} hidden_item_t;

/**
 * Gets the field of a hidden item
 * @param hidden_item the hidden item structure
 * @param field which field to get
 * @return the field
 **/
int hidden_item_get_field(hidden_item_t hidden_item, u8 field);

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
extern const hidden_item_respawnable_chunk_t hidden_item_respawnable[15];

extern const u8 ow_script_hidden_item_mushroom[];
extern const u8 ow_script_hidden_item_mushroom_already_plucked[];
extern const u8 ow_script_hidden_item_shell[];
extern const u8 ow_script_hidden_item_shell_already_found[];

#endif /* INCLUDE_C_TILE_HIDDEN_ITEM_H_ */
