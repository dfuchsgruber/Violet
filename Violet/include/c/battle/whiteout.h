/*
 * whiteout.h
 *
 *  Created on: Sep 5, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_WHITEOUT_H_
#define INCLUDE_C_BATTLE_WHITEOUT_H_

#include "types.h"
#include "text.h"

typedef struct {
    u8 bank, map, target_person;
    s16 x, y;
} healing_place2_t;

/**
 * Callback that returns to the overworld map and plays the map music.
 **/
void battle_map_reload_and_play_map_music();

/**
 * Callback for whiteout
 **/
void whiteout_callback1();

extern const tboxdata tboxdata_whiteout_text;

/**
 * Callback that prints the "ran to center..." text.
 **/
void whiteout_callback_print_text(u8 self);

/**
 * Checks if a battle result is a loss, i.e. if the player should faint.
 * @param result the battle result to check
 * @return if the result is a loss
 **/
bool battle_result_is_loss(u8 result);

/**
 * Prints the whiteout message.
 * @param self self-reference to the callback
 * @param str the string to print
 * @param x x offset
 * @param y y offset
 * @return if the text has finished
 **/
bool whiteout_print_string(u8 self, const u8 *str, u8 x, u8 y);

#endif /* INCLUDE_C_BATTLE_WHITEOUT_H_ */
