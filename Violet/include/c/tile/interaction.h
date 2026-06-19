#ifndef H_TILE_INTERACTION
#define H_TILE_INTERACTION

#include "tile/block.h"
#include "types.h"

/**
 * Get the interaction script for a water tile.
 * @param tile_position the position of the tile
 * @param behaviour the tile behaviour
 * @param player_facing the direction the player is facing
 */
const u8 *tile_interaction_get_by_water(const position_t *tile_position, u16 behaviour, u8 player_facing);

/**
 * Get the interaction script for a signpost tile.
 * @param position the position of the tile
 * @param behaviour the tile behaviour
 * @param direction the direction the player is facing
 */
const u8 *tile_interaction_get_by_signpost(const position_t *position, u16 behaviour, u8 direction);

/**
 * Get the interaction script for a tile with a specific behaviour.
 * @param position the position of the tile
 * @param behaviour the tile behaviour
 * @param direction the direction the player is facing
 */
const u8 *tile_interaction_get_by_person(const position_t *position, u16 behaviour, u8 direction);

/**
 * Get the interaction script for a tile with a specific behaviour.
 * @param tile_position the position of the tile
 * @param behaviour the tile behaviour
 * @param direction the direction the player is facing
 * @param interaction_sound pointer to store the interaction sound ID
 * @return pointer to the interaction script, or NULL if no interaction is found
 */
const u8 *tile_interaction_get_by_tile_behaviour(const position_t *tile_position, u16 behaviour, u8 direction, u16 *interaction_sound);

/**
    * Checks if a signpost script should be triggered by a collision and initializes it.
    * @param position the position of the tile
    * @param behaviour the tile behaviour
    * @param direction the direction the player is facing
    * @return if a signpost script was triggered
 */
u8 signpost_overworld_script_initialize_by_collision(const position_t *position, u16 behaviour, u8 faced_direction);

/**
    * Checks if a tile interaction script should be triggered by a collision and initializes it.
    * @param position the position of the tile
    * @param behaviour the tile behaviour
    * @param direction the direction the player is facing
    * @return if a tile interaction script was triggered
*/
u8 overworld_script_initialize_by_tile_interaction(position_t *position, u16 behaviour, u8 direction);

// TODO: this is currently always an empty trash can -- should we make a dynamic system here as well?
extern const u8 ow_script_trash[];
extern const u8 ow_script_rock_climb[];
extern const u8 ow_script_crafting_cauldron[];
extern const u8 ow_script_region_map[];
extern const u8 ow_script_pokemon_center_sign[];

#endif