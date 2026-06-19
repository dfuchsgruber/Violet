#ifndef H_TILE_INPUT_H_
#define H_TILE_INPUT_H_

#include "types.h"
#include "tile/coordinate.h"

typedef struct {
    u8 a_pressed:1;
    u8 check_wild_encounter:1;
    u8 start_pressed:1;
    u8 select_pressed:1;
    u8 held_direction:1;
    u8 held_direction2:1;
    u8 took_step:1;
    u8 b_pressed:1;
    u8 r_pressed:1;
    u8 input_field_1_0:1;
    u8 input_field_1_1:1;
    u8 input_field_1_2:1;
    u8 input_field_1_3:1;
    u8 dpad_direction_pressed;
} overworld_input_t;

extern overworld_input_t overworld_input_record;

void overworld_input_clear(overworld_input_t *input);

/**
 * Resets the target trainer npc, text color and if the sign script is a signpost.
*/
void npc_and_signpost_reset();

/**
 * Triggers step-based scripts.
    * @param position the current player position
    * @param behaviour the behaviour of the tile stepped on
    * @param direction the direction the player is facing
 * @return true if a script was triggered, false otherwise.
 */
bool trigger_step_based_scripts(position_t *position, u16 behaviour, u8 direction);

/**
 * Tries to trigger a wildbattle.
    * @param block_attributes the attributes of the tile to trigger on
 * @return if a wild battle was triggered
 */
bool trigger_wildbattle(u32 block_attributes);

/**
 * Tries to trigger an arrow warp.
    * @param position the current player position
    * @param behaviour the behaviour of the tile to trigger on
    * @param direction the direction the player is facing
 * @return if an arrow warp was triggered
 */
bool trigger_arrow_warp(position_t *position, u16 behaviour, u8 direction);

/**
 * Tries to trigger a warp by stepping on a certain tile.
    * @param position the current player position
    * @param behaviour the behaviour of the tile to trigger on
    * @param direction the direction the player is facing
 * @return if a step warp was triggered
*/
bool trigger_on_step_warp(position_t *position, u16 behaviour, u8 direction);

/**
 * Triggers the use of a registered key item.
 * @return true if a key item was used, false otherwise.
 */
bool trigger_registered_key_item();

#endif