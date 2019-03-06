/*
 * npc.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_NPC_H_
#define INCLUDE_C_OVERWORLD_NPC_H_

#include "oam.h"

typedef struct npc {

    struct {
        u8 active : 1;
        u8 in_motion : 1;
        u8 is_obstacle : 1;
        u8 is_obstacle_2 : 1;
        u8 flag_4 : 1;
        u8 flag_5 : 1;
        u8 flag_6 : 1;
        u8 reset : 1;
    } flags;
    u8 visual_cntrl;
    u8 field_2;
    u8 field_3;

    u8 oam_id;
    u8 sprite;
    u8 behavior_type;
    u8 trainer_trigger;

    u8 overworld_id;
    u8 map;
    u8 bank;

    struct {
        u8 current : 4;
        u8 previous : 4;
    } height;

    s16 origin_x;
    s16 origin_y;

    s16 dest_x;
    s16 dest_y;

    s16 from_x;
    s16 from_y;

    struct npc_facing {
        u8 lower : 4;
        u8 higher : 4;
    } facing;

    struct rectangle {
        u8 x : 4;
        u8 y : 4;
    } rectangle;
    u8 oam_surf;
    u8 oam_bike;

    u8 field_1C;
    u8 sight_range;
    u8 behavior_tile_to;
    u8 behavior_tile_current;

    u8 field_20;
    u8 step_countdown;
    u8 field_22;
    u8 field_23;
} npc;

typedef struct {
    u8 state;
    u8 bike;
    u8 running2;
    u8 running1;
    u8 std_oam_id;
    u8 player_npc_id;
    u8 is_locked;
    u8 gender;
    u8 mode;
    u8 unkown[3];
} player_state_t;

extern npc npcs[];
extern player_state_t player_state;

/**
 * Checks if a tile is blocked for an npc in a given directions
 * @param n the npc instance to check
 * @param x x coordinate of the npc
 * @param y y coordinate of the npc
 * @param direction the direction the npc attempts to walk
 * @return the enumerated obstacle cause
 */
u8 npc_is_tile_blocked(npc *n, s16 x, s16 y, u8 direction);

/**
 * Checks if a npc sees the player
 * @param n the npc instance to check
 * @param the enumerated obstacle cause
 */
u8 npc_sees_player(npc *n);

/**
 * Stops the animation of a npc instance
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 */
bool npc_anim_stop(npc *n, oam_object *target);

/***
 * Intializes the walking animation for a npc
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @param direction the direction to walk into
 * @param unkown TODO
 */
void npc_anim_init_walk(npc *n, oam_object *target, u8 direction, u8 unkown);

/**
 * Checks if the walking of a npc object is finished
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the animation is finished
 */
bool npc_anim_walk_is_finished(npc *n, oam_object *target);

/**
 * Initializes an npc animation in the north-east (no) direction
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the animation initialized is already finished
 */
bool npc_anim_diag_ne_init(npc *n, oam_object *target);

/**
 * Initializes an npc animation in the north-west (nw) direction
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the animation initialized is already finished
 */
bool npc_anim_diag_nw_init(npc *n, oam_object *target);


/**
 * Initializes an npc animation in the south-east (so) direction
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the animation initialized is already finished
 */
bool npc_anim_diag_se_init(npc *n, oam_object *target);

/**
 * Initializes an npc animation in the south-west (sw) direction
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the animation initialized is already finished
 */
bool npc_anim_diag_sw_init(npc *n, oam_object *target);

/**
 * Updates the coordinates of a npc object walking diagonal
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @param direction the direction to walk into (diagonal)
 */
void npc_diag_update_pos(npc *n, oam_object *target, u8 direction);

/**
 * Checks whether the targeted tile instead triggers a diagonal movement
 * @param n the target npc
 * @param x_to_origin the x coordinate to target
 * @param y_to_origin the y coordinate to target
 * @param direction the walking direction
 * @param role_to the behavoiur of the tile to target
 */
u8 block_triggers_diagnoal_move(npc *n, s16 x_to_origin, s16 y_to_origin, u8 direction, u8 role_to);

/**
 * Moves an npc to a position computing a path using a-star
 * @param ow_id the overworld to move
 * @param dest_x the x coordinate to move to
 * @param dest_y the y coordinate to move to
 */
void npc_move_to(u8 ow_id, s16 dest_x, s16 dest_y);

/**
 * A big callback function to free the resources allocated by npc_move_to
 * @param self id of this callback
 */
void npc_move_to_freeing_callback(u8 self);

/**
 * Special: wrapped npc_move_to function with target to the tile the player faces
 */
void special_move_npc_to_player();

/**
 * Special: wrapped npc_move_to function with arbitrary target
 */
void special_move_npc_to();

/**
 * Returns the script associated with a npc
 * @param npc_id the npc_id to target
 * @return the script
 */
u8 *npc_get_script(u8 npc_id);

/**
 * Finds an overworld in the npc object state if present and returns the npc id
 * @param overworld_id the overworld id to look for
 * @param map the map id to look on
 * @param bank the map bank to look on
 * @param result offset to store the npc id if found
 * @return whether the overworld was found in the npc state
 */
bool npc_get_id_by_overworld_id(u8 overworld_id, u8 map, u8 bank, u8 *result);

/**
 * Applies a list of movements to an overworld
 * @param overworld_id the id of the overworld
 * @param map the map id the overworld is present in
 * @param bank the map bank the overworld is present in
 * @param moves the list of movements, terminated by 254
 */
void npc_apply_movement(u8 overworld_id, u8 map, u8 bank, u8 *moves);

/**
 * Sets the player state and executes the tile animation based on a movement he takes
 * @param movement the movement of the player anim
 * @param unkown TODO (usually set to 2)
 */
void npc_player_set_state_and_execute_tile_anim(u8 movement, u8 unkown);

/**
 * Sets the player's state to bike
 * @param state the exact player state
 */
void npc_player_set_bike_state(u8 state);

/**
 * Gets the facing of the player
 * @return the facing of the player
 */
u8 player_get_facing();

#endif /* INCLUDE_C_OVERWORLD_NPC_H_ */
