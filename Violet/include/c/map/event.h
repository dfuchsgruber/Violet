/*
 * event.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_EVENT_H_
#define INCLUDE_C_MAP_EVENT_H_

#include "types.h"
#include "tile/coordinate.h"
#include "tile/hidden_item.h"
#include "constants/signpost_types.h"

typedef struct map_event_person {
    u8 target_index; // Used as a reference id for the person
    u8 overworld_index; //the picture to be displayed
    u8 script_std : 5;
    u8 in_connection : 3; // If set, refers to in which adjacent map to look for the person
    u8 argument; // Argument for a) script stds or b) the person that is referred to by `in_connection`
    s16 x;
    s16 y;
    u8 level;
    u8 behavior;
    u8 behavior_range_x : 4;
    u8 behavior_range_y : 4;
    u16 trainer_type_and_strength_flag;
    u16 alert_radius;
    u8 *script;
    u16 flag;
    u16 value;
} map_event_person;

#define MAP_EVENT_PERSON_VIEWPORT 0x7F

typedef struct map_event_warp {
    s16 x;
    s16 y;
    u8 height;
    u8 target_warp_id;
    u8 target_map;
    u8 target_bank;
} map_event_warp;

typedef struct map_event_script { //TODO
    s16 x;
    s16 y;
    u8 level;
    u8 field_5;
    u16 var;
    u16 value;
    u8 field_A;
    u8 field_B;
    u8 *script;
} map_event_script;

typedef struct {
    u32 item : 16;
    u32 idx : 5;
    u32 amount : 5;
    s32 center_x : 3;
    s32 center_y : 3;
} treasure_map_event_t;

typedef struct map_event_singpost { //TODO
    s16 x;
    s16 y;
    u8 level;
    u8 type;
    u16 flag;
    union {
        u8 *script;
        hidden_item_t hidden_item;
        treasure_map_event_t treasure_map;
    } value;
} map_event_signpost;

typedef struct map_events {
    u8 person_cnt;
    u8 warp_cnt;
    u8 script_cnt;
    u8 signpost_cnt;
    map_event_person *persons;
    map_event_warp *warps;
    map_event_script *scripts;
    map_event_signpost *signposts;
} map_event_header_t;

/**
 * Returns a person based on its target index and a bank, map tuple to identify it
 * @param target_idx target index of the person
 * @param map_id the person is on
 * @param bank mapbank which contains the map the person is on
 * @return pointer to the person
 */
map_event_person *map_get_person(u8 target_idx, u8 map_id, u8 bank);

/**
 * Gets the script of an person event.
 * @param target_idx target index of the person
 * @param map_id the person is on
 * @param bank mapbank which contains the map the person is on
 * @return the script associated with the person event
 */
u8 *person_get_script(u8 target_idx, u8 map_id, u8 bank);

/**
 * Deletes the npc of a person and sets it flag if it is present.
 * @param person_idx the person to delete
 * @param map_idx the index of the map the person is on
 * @param bank the bank of the map the person is on
 **/
void person_delete_npc_if_present(u8 person_idx, u8 map_idx, u8 bank);

/**
 * Gets the script type (pokecenter, etc.) of a signpost
 * @param behaviour behaviour of the signpost
 * @param direction in which direction the signspost was encountered
 * @return the script type or 255 if None
 **/
u8 signpost_get_script_type(u8 behaviour, u8 direction);

/**
 * Sets the position of a person.
 * @param person_idx the idx of the person
 * @param x the x coordinate
 * @param y the y coordinate
 **/
void person_set_position(u8 person_idx, s16 x, s16 y);

/**
 * Sets the position of a person.
 * @param person_idx the idx of the person
 * @param behaviour the behaviour to set
 **/
void person_set_behaviour(u8 person_idx, u8 behaviour);

#endif /* INCLUDE_C_MAP_EVENT_H_ */
