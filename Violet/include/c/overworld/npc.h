/*
 * npc.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_NPC_H_
#define INCLUDE_C_OVERWORLD_NPC_H_

#include "oam.h"
#include "superstate.h"

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
    u8 field1;
    u8 running2;
    u8 tile_state;
    u8 oam_idx;
    u8 npc_idx;
    u8 is_locked;
    u8 gender;
    u8 mode;
    u8 unkown[3];
} player_state_t;

#define PLAYER_STATE_WALKING 1
#define PLAYER_STATE_MACH_BIKE 2
#define PLAYER_STATE_ACRO_BIKE 4
#define PLAYER_STATE_SURFING 8

#define PLAYER_STATE_BIKING (PLAYER_STATE_MACH_BIKE | PLAYER_STATE_ACRO_BIKE)

extern npc npcs[];
extern player_state_t player_state;
// Npc idx of the trainer to battle
extern u8 trainer_npc_idx;

/**
 * Checks if a tile is blocked for an npc in a given directions
 * @param n the npc instance to check
 * @param x x coordinate of the npc
 * @param y y coordinate of the npc
 * @param direction the direction the npc attempts to walk
 * @return the enumerated obstacle cause
 */
u8 npc_get_collision(npc *n, s16 x, s16 y, u8 direction);

/**
 * Checks if a npc sees the player
 * @param n the npc instance to check
 * @param the enumerated obstacle cause
 */
u8 npc_sees_player(npc *n);


/**
 * Makes a npc face into a direction.
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @param direction the direciton in which to face 
 * @return whether the animation has finished
 **/
bool npc_movement_animation_set_direction(npc *n, oam_object *target, u8 direction);

/**
 * Initializes walking down slowly.
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 **/
bool npc_anim_walk_down_slowly_init(npc *n, oam_object *target);


/**
 * Initializes walking down in a direction.
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 **/
bool npc_anim_walk_slowly_init(npc *n, oam_object *target, u8 direction);

/**
 * Initializes walking down slowly.
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 **/
bool npc_anim_slow_walk_slowly_finished(npc *n, oam_object *target);


/**
 * Pauses for some frames.
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 **/
bool npc_anim_pause_init(oam_object *target, u16 frames);

/**
 * Checks if pausing for some frames has finished.
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 **/
bool npc_anim_pause_finished(npc *n, oam_object *target);

/**
 * Locks the facing of a npc
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 **/
bool npc_anim_lock_facing(npc *n, oam_object *target);

/**
 * Unlocks the facing of a npc
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 **/
bool npc_anim_unlock_facing(npc *n, oam_object *target);

/**
 * Makes a npc face downwards.
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 **/
bool npc_anim_face_down(npc *n, oam_object *target);

/**
 * Makes a npc face upwards.
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 **/
bool npc_anim_face_up(npc *n, oam_object *target);

/**
 * Stops the animation of a npc instance
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @return whether the method was sucessfull
 */
bool npc_anim_stop(npc *n, oam_object *target);

enum {
    NPC_ANIM_SPEED_WALK_NORMAL = 0,
    NPC_ANIM_SPEED_WALK_RUNNING = 1,
    NPC_ANIM_SPEED_WALK_RIDING = 2,
    NPC_ANIM_SPEED_WALK_VERY_FAST = 3,
    NPC_ANIM_SPEED_WALK_SLIDE = 4
};

/***
 * Intializes the walking animation for a npc
 * @param n the npc instance
 * @param target the oam object associated with the npc
 * @param direction the direction to walk into
 * @param unkown TODO
 */
void npc_anim_init_walk(npc *n, oam_object *target, u8 direction, u8 speed);

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

// Person idx that is targeted by npc_apply_movement
u8 npc_movement_target_person_idx;

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

/**
 * Stops the movements of all non-player npcs
 **/
void npc_stop_all_movements_but_players();

/**
 * Stops the movements (i.e. freezes) all npcs but the player and a target npc.
 * @param npc_idx the npc which is excluded from lockall
 **/
void npc_stop_all_movements_but_one(u8 npc_idx);

/**
 * A callback that is executed when the player transits from water (surfing) to land (walking / biking).
 * @param self self-reference
 **/
void player_transition_water_to_land_callback(u8 self);

/**
 * Checks if the animation of a npc has finished.
 * @param n the npc to check if it has its animation finished
 * @return if the npc has its animation finished
 **/
bool npc_animation_finished(npc *n);

/**
 * Updates the picture of an npc.
 * @param n the npc to update the picture of
 * @param picture the picture that the npc is supposed to show
 **/
void npc_update_picture(npc *n, u8 picture);

/**
 * Gets the movement idx for facing in a certain direction.
 * @param direction the direction to face into
 * @return the movement idx associated with this facing direction for facing
 **/
u8 npc_get_facing_movement_by_direction(u8 direction);

/**
 * Executes a facing move of an npc.
 * @param n the npc that executes the facing move
 * @param movement the movement to execute. This is supposed to resemble a facing move.
 **/
void npc_do_facing_move(npc *n, u8 movement);

/**
 * Updates the delay field of oams associated with npcs for all npcs present.
 **/
void npc_update_oam_delay_all();

/**
 * Callback that lets the player transit to a biking state.
 * @param self self reference
 **/
void player_transition_to_bike(u8 self);

/**
 * Checks if the player state disables them to use a bike
 * @return if the current player state and position disables biking
 **/
bool player_state_disables_bike();

/**
 * Attempts to transit from water to land, if the player is at a given position.
 * @param x the x coordinate of the target block
 * @param y the y coordinate of the target block
 * @param direction the direction the player is attempting to transit in
 * @return if a transition from water to land happened
 **/
bool npc_player_attempt_transition_water_to_land(s16 x,s16 y,u8 direction);

/**
 * Checks if a movable boulder npc is at a given position.
 * @param x the x coordinate of the boulder
 * @param y the y coordinate of the boulder
 * @param direction the direction to move the boulder in
 * @return if a movable boulder exists at this location
 **/ 
bool npc_is_movable_boulder_at(s16 x,s16 y,u8 direction);

/**
 * Checks what collision there is for the player to walk into a certain direction.
 * @param direction the direction the player attempts to walk into
 * @return collision which collision there is
 **/
u8 npc_player_collision(u8 direction);

/**
 * Checks what collision there is for the player to bike into a certain direction.
 * @param direction the direction the player attempts to bike into
 * @return collision which collision there is
 **/
u8 npc_player_collision_on_bike(u8 direction);

/**
 * Initializes a move for the player to jump over a block (ledges).
 * @param direction the direction in which to jump.
 **/
void npc_player_init_move_jump(u8 direction);

/**
 * Initializes a move for the player to face a certain direction (warps).
 * @param direction the direction in which to face.
 **/
void npc_player_init_move_face(u8 direction);

/**
 * Initializes a move for the player to walk in place and creates the blocked soundeffect.
 * @param direction the direction in which to be blocked.
 **/
void npc_player_init_move_blocked(u8 direction);

/**
 * Plays the adequate sound effect for colliding into a certain direction.
 * @param direction the direction to attempt to walk into.
 **/
void npc_player_sound_collision(u8 direction);

/**
 * Initializes a move for the player to surf.
 * @param direction the direction in which to be go.
 **/
void npc_player_init_move_surfing(u8 direction);

/**
 * Initializes the player sliding on the left foot
 * @param direction the direction in which to slide in
 **/
void npc_player_init_move_sliding_on_left_foot(u8 direction);

/**
 * Initializes the player running.
 * @param direction the direction in which to run in.
 **/
void npc_player_init_move_running(u8 direction);

/**
 * Initializes the player walking.
 * @param direction the direction in which to walk in.
 **/
void npc_player_init_move_walking(u8 direction);

/**
 * Initializes the player slowly walking
 * @param direction the direction in which to slowly walk in
 **/
void npc_player_init_move_walking_slow(u8 direction);

/**
 * Initializes the player biking into a direction
 * @param direction the direction in which to bike in
 **/
void npc_player_init_move_bike(u8 direction);

/**
 * Initializes the player on the bike being blocked into a direction
 * @param direction the direction in which attempted to bike in
 **/
void npc_player_init_move_bike_blocked(u8 direction);

/**
 * Checks if an npc is not allowed to run.
 * @param behaviour the behaviour the npc is on
 * @return if the npc is prevented to run
 **/
bool npc_can_not_run(u8 behaviour);

/**
 * Checks if the player npc is walking towards rock stairs (which slow the player down)
 * @param direction in which direction the player npc walks
 * @return if the tile it walks towards are rock stairs
 **/
bool npc_player_walking_towards_rock_stairs(u8 direction);

/**
 * Sets the direction a npc is facing in.
 * @param the target npc
 * @param direction in which direction to face in
 */
void npc_set_facing(npc *n, u8 direction);


/**
 * Makes the player face into a direction.
 * @param direction the direction to face into
 **/
void npc_player_set_facing(u8 direction);

/**
 * Controls the player npc using the input when on a bike.
 * @param direction the direction to move into
 * @param keys_new newly pressed keys (for acro bike)
 * @param keys_held held keys
 **/
void player_npc_controll_biking(u8 direction, key keys_new, key keys_held);

/**
 * Controls the player npc using the input when not on a bike.
 * @param direction the direction to move into
 * @param keys_held held keys
 **/
void player_npc_controll_not_biking(u8 direction, key keys_held);

/**
 * Gets the npc idx of a person on a certain map.
 * @param person_idx the idx of the person to get
 * @param map_idx the map on which the person is
 * @param bank the bank on which the person is
 * @return the npc_idx associated with the person or 16 on failure
 **/
u8 npc_get_by_person_idx(u8 person_idx, u8 map_idx, u8 bank);

extern void (*npc_movements_oam_callbacks[])(oam_object*);

#endif /* INCLUDE_C_OVERWORLD_NPC_H_ */
