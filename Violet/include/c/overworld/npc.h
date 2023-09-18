/*
 * npc.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_NPC_H_
#define INCLUDE_C_OVERWORLD_NPC_H_

#include "types.h"
#include "oam.h"
#include "superstate.h"
#include "constants/overworld/npc_pathfinding_speeds.h"
#include "map/event.h"

typedef struct npc {

    struct {
        // 0x0
        u32 active : 1;
        u32 in_motion : 1;
        u32 trigger_ground_effects_on_move : 1;
        u32 trigger_ground_effects_on_stop : 1;
        u32 covering_ground_effects_disabled : 1;
        u32 landing_jump : 1;
        u32 held_movement_active : 1;
        u32 held_movement_finished : 1;
        // 0x1
        u32 frozen : 1;
        u32 direction_locked : 1;
        u32 animation_disabled : 1;
        u32 animation_enabled : 1;
        u32 inanimate : 1;
        u32 invisible : 1;
        u32 is_offscreen : 1;
        u32 is_camera_viewport : 1;
        // 0x2
        u32 is_player : 1;
        u32 has_reflection : 1;
        u32 in_short_grass : 1;
        u32 in_shallow_flowing_water : 1;
        u32 in_sand_pile : 1;
        u32 in_hot_springs : 1;
        u32 has_shadow : 1;
        u32 saved_oam_animation_paused : 1;
        // 0x3
        u32 saved_oam_rotscale_animation_paused : 1;
        u32 jump_landing_ground_effect_disabled : 1;
        u32 fixed_priority : 1;
        u32 has_rage_sprite : 1;
    } flags;

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

    s16 dest_x; // current coordiantes
    s16 dest_y;

    s16 from_x; // previous coordinates
    s16 from_y;

    struct npc_facing {
        u8 facing : 4; // lower
        u8 movement : 4; // upper
    } direction;

    struct rectangle {
        u8 x : 4;
        u8 y : 4;
    } rectangle;
    u8 oam_surf;
    u8 oam_bike;

    u8 movement_action_idx;
    u8 sight_range;
    u8 behavior_tile;
    u8 behavior_tile_previous;

    u8 movement_direction_previous;
    u8 step_countdown;
    u8 player_copyable_movement;
    u8 collision_type;
} npc;

enum {
    COLLISION_TYPE_NORMAL = 0,
    COLLISION_TYPE_NO_COLLISION,
};

enum {
    RUNNING_STATE_NOT_MOVING,
    RUNNING_STATE_TURNING,
    RUNNING_STATE_MOVING,
};

enum {
    BIKE_STATE_NORMAL,
    BIKE_STATE_TURNING,
    BIKE_STATE_SLOPE
};

#define OVERWORLD_IDX_VIEWPORT 0x7F

typedef struct {
    u8 state;
    u8 field1;
    u8 running_state; //running2
    u8 tile_transition_state; // tile_state
    u8 oam_idx;
    u8 npc_idx;
    u8 is_locked;
    u8 gender;
    u8 bike_state;
    u8 new_direction_backup;
    u8 bike_step_counter;
    u8 bike_speed;
    u32 direction_history;
    u32 button_history;
    u8 direction_timer_history[8];
    u16 last_spin_tile;
} player_state_t;

typedef struct { // State with which the player is initialized after warping
    u8 state;
    u8 direction;
    u8 field2;
} player_initial_state_t; 

extern player_initial_state_t player_initial_state;

/**
 * Keeps track of how many blocks the player has traversed with their bike
 * @param block_cnt how many blocks have been traversed
 **/
void npc_player_bike_set_block_count(u8 block_cnt);

#define PLAYER_STATE_WALKING 1
#define PLAYER_STATE_MACH_BIKE 2
#define PLAYER_STATE_ACRO_BIKE 4
#define PLAYER_STATE_SURFING 8
#define PLAYER_STATE_RUNNING 128

#define PLAYER_STATE_BIKING (PLAYER_STATE_MACH_BIKE | PLAYER_STATE_ACRO_BIKE)

#define NUM_NPCS 16

extern npc npcs[NUM_NPCS];
extern player_state_t player_state;
// Npc idx of the trainer to battle
extern u8 trainer_npc_idx;

/**
 * Saves the player's current state as initial state (after warping)
 **/
void player_save_initial_state();

/**
 * Resets the initial state of the player (after warping)
 **/
void player_reset_initial_state();

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
void npc_move_to(u8 ow_id, s16 dest_x, s16 dest_y, u8 speed);

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
const u8 *npc_get_script(u8 npc_id);

/**
 * Finds an overworld in the npc object state if present and returns the npc id
 * @param overworld_id the overworld id to look for
 * @param map the map id to look on
 * @param bank the map bank to look on
 * @param result offset to store the npc id if found
 * @return if the npc search was unsucessful, i.e. return value of true indicates failure
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
 * Checks if a callback for applymovement is active with that npc
 * @param overworld_id the overworld id to look for
 * @param map the map id to look on
 * @param bank the map bank to look on
 * @return whether a movement is finished
 **/
bool npc_movement_callback_is_finished(u8 overworld_id, u8 map, u8 bank);

/**
 * Executes a single movement for an npc
 * @param n the npc
 * @param move the movement to execute
 * @return if the movement has finished
 **/
bool npc_apply_movement_execute_movement(npc *n, u8 move);

/**
 * Gets the flag to clear for a strength boulder npc
 * @param overworld_idx the overworld id to look for
 * @param map_idx the map_idx the map idx
 * @param bank the map bank to look on
 * @return the strength flag to clear
 **/
u16 npc_get_strength_flag(u8 overworld_idx, u8 map_idx, u8 bank);

// Person idx that is targeted by npc_apply_movement
extern u8 npc_movement_target_person_idx;

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
 * Initializes the player into a direction on fastest speed
 * @param direction the direction in which to move in
 **/
void npc_player_init_move_fastest(u8 direction);

/**
 * Gets the movement idx of the sliding (probably this is wrongly labeled and just fastest) direcitonal
 * @param dir in which direction to slide
 * @return the corresponding movement idx
 **/
u8 npc_player_get_movement_idx_by_direction_sliding(u8 dir);

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
 * Gets which transition function will be executed for the player's bike state.
 * @param direction direction in which to travel
 * @param keys_new newly pressed keys
 * @param keys_held held keys
 * @return idx which transition function to execute
 **/
u8 player_npc_get_bike_transition_state(u8 *direction, key keys_new, key keys_held);

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

/**
 * Gets the animation of an oam by the direction its facing
 * @param facing the direction
 * @return the animation idx
 **/
u8 npc_get_animation_idx_by_facing(u8 facing);

/**
 * Returns the direction opposite of another
 * @param direciton the direction to get the opposite of
 * @return the opposite direction
 **/
u8 direction_get_opposite(u8 direction);

extern void (*npc_movements_oam_callbacks[])(oam_object*);

/**
 * Gets the an npc at a position
 * @param x the x coordinate
 * @param y the y coordinate
 * @return npc_idx the idx of the npc at this position. If None, returns NUM_NPCS.
 **/
u8 npc_get_by_position(s16 x, s16);

/**
 * Tries to create a new npc from a person and its oam as well
 * @param person the person from which to create the npc from
 * @param template the oam template for the oam
 * @param map_idx the map idx of the person
 * @param bank the bank of the person
 * @param camera_x the x of the camera
 * @param camery_y the y of the camera
 * @return npc_idx the idx of the npc created or NUM_NPCS on failure
 **/
u8 npc_create_with_oam_by_person(map_event_person *person, oam_template *template, u8 map_idx, u8 bank, s16 camera_x, s16 camera_y);

/**
 * Gets the animation idx that corresponds to moving in a certain direction.
 * @param direction the direction
 * @return the animation idx
 **/
u8 npc_get_animation_idx_by_movement_direction(u8 direction);

/**
 * Applys an animation to an npc and loops it.
 * @param n the npc to apply the animation to
 * @param target the oam object of the npc
 * @param anim_idx the animation to loop
 **/
u8 npc_apply_animation_looping(npc *n, oam_object *o, u8 anim_idx);

/**
 * Applies a jumping movement to an npc.
 * @param n the target npc
 * @param target the corresponding oam
 * @param direction the direction in which to jump
 * @param speed the speed with which to jump
 * @param jump_height how high to jump
 **/
void npc_apply_jump(npc *n, oam_object *target, u8 direction, u8 speed, u8 jump_height);

/**
 * Checks if a jumping animation is active for a npc
 * @param n the npc to check
 * @param target the corresponding oam
 * @return if a jumping animation is active
 **/
bool npc_anim_jump_is_finished(npc *n, oam_object *target);

/**
 * Sets the direction of an npc
 * @param n the npc
 * @param direction the direction
 **/
void npc_set_direction (npc *n, u8 direction);

/**
 * Updates the coordinates of an npc and updates the previous coordinates.
 * @param n the npc
 * @param x x coordinate
 * @param y y coordinate
 **/
void npc_update_coordinates(npc *n, s16 x, s16 y);

/** Updates the coordinates of an npc to its current position and updates the previous as well.
 * Basically this is equivalent to a move with zero distance.
 * @param n the npc
 **/
void npc_update_coordinates_with_current(npc *n);

/**
 * @brief Sets the offset of the surf blob under a player
 * 
 * @param oam_idx_surf the oam idx of the surf blob
 * @param has_offset if it has an offset
 * @param offset the offset to set
 */
void player_npc_set_surf_blob_offset(u8 oam_idx_surf, bool has_offset, u16 offset);

enum {
    JUMP_HEIGHT_12,
    JUMP_HEIGHT_6,
    JUMP_HEIGHT_10,
};

enum {
    JUMP_SPEED_IN_PLACE,
    JUMP_SPEED_1,
    JUMP_SPEED_2,
    JUMP_SPEED_3,
};

/**
 * Sets the jumping parameters of an npc's oam
 * @param target the target oam
 * @param direction in which direction to jump
 * @param speed the jumping speed
 * @param height the jumping height
 **/
void npc_oam_set_jump_parameters(oam_object *target, u8 direction, u8 speed, u8 height);

/**
 * Moves the coordinates of an oam by one pixel in a direction
 * @param target the oam
 * @param direction in which direction to move
 **/
void npc_oam_apply_direction(oam_object *target, u8 direction);

/**
 * Gets the y displacement of frame `idx`.
 * @param idx the current frame
 * @param height the jump height type
 * @return the y displacement
 **/
s8 npc_jump_get_y(u8 idx, u8 height);

/**
 * Creates a camera npc given a person.
 * @param p the person to base the camera npc on
 * @return the camera npc idx
 **/
u8 npc_create_camera_by_person(map_event_person *p);

/**
 * Searches for an empty slot to place the npc in.
 * @param person_idx person to create
 * @param map_idx on which map
 * @param on which bank
 * @param idx where to put the slot
 * @return `true` if no slot is available or the npc is already loaded
 **/
bool npc_get_empty_idx(u16 person_idx, u8 map_idx, u8 bank, u8 *idx);

/**
 * Clears an npc
 * @param n the npc to clear
 **/
void npc_clear (npc *n);

/**
 * Updates an npcs picture considering possible dynamic pictures
 * @param n the npc to update
 **/
void npc_set_dynamic_picture(npc *n);

/**
 * Checks if two heights are compatible (i.e. they are deemed "on the same level")
 * @param height_0 the first height
 * @param height_1 the second height
 * @return if the two heights are on the same level
 **/
bool heights_compatible(u8 height_0, u8 height_b);

/**
 * Shifts the coordinates of all active npcs at camera update.
 **/
void npc_shift_coordinates_at_camera_update();

/**
 * Deletes all npcs outside the viewport
 **/
void npc_delete_all_outside_viewport();

/**
 * Creates all npcs within the viewport if they are not already present
 * @param camera_x the camera offset with which to load
 * @param camera_y the camera offset with which to load
 **/
void npc_create_all_in_viewport_if_not_present(s16 camera_x, s16 camera_y);

/**
 * @brief Clears the held movement of an npc if the movement is active
 * 
 * @param n the npc
 */
void npc_clear_held_movement_if_active(npc *n);

enum {
    PLAYER_TRANSITION_NORMAL,
    PLAYER_TRANSITION_BIKE,
    PLAYER_TRANSITION_FISH,
    PLAYER_TRANSITION_SURF,
    PLAYER_TRANSITION_STOP_SURFING_SOUTH,
    PLAYER_TRANSITION_STOP_SURFING_NORTH,
    PLAYER_TRANSITION_STOP_SURFING_WEST,
    PLAYER_TRANSITION_STOP_SURFING_EAST,
    PLAYER_TRANSITION_VS_SEEKER,
};

/**
 * @brief Executes a player state transition
 * 
 * @param player_transition_type the transition type
 */
void player_transition(u8 player_transition_type);

// Initial facing direction per behaviour
extern const u8 behaviour_initial_facing_directions[80];
extern const u8 behaviour_has_range[80];

#endif /* INCLUDE_C_OVERWORLD_NPC_H_ */
