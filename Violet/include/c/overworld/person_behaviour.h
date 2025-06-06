#ifndef H_OVERWORLD_PERSON_BEHAVIOUR
#define H_OVERWORLD_PERSON_BEHAVIOUR

#include "types.h"
#include "oam.h"
#include "constants/person_behaviours.h"
#include "npc.h"

void behaviour_none_oam_callback(oam_object *o);
void behaviour_look_around_oam_callback(oam_object *o);
void behaviour_wander_around_oam_callback(oam_object *o);
void behaviour_wander_up_and_down_oam_callback(oam_object *o);
void behaviour_wander_down_and_up_oam_callback(oam_object *o);
void behaviour_wander_left_and_right_oam_callback(oam_object *o);
void behaviour_wander_right_and_left_oam_callback(oam_object *o);
void behaviour_face_up_oam_callback(oam_object *o);
void behaviour_face_down_oam_callback(oam_object *o);
void behaviour_face_left_oam_callback(oam_object *o);
void behaviour_face_right_oam_callback(oam_object *o);
void behaviour_player_oam_callback(oam_object *o);
void behaviour_face_down_and_up_oam_callback(oam_object *o);
void behaviour_face_left_and_right_oam_callback(oam_object *o);
void behaviour_face_up_and_left_oam_callback(oam_object *o);
void behaviour_face_up_and_right_oam_callback(oam_object *o);
void behaviour_face_down_and_left_oam_callback(oam_object *o);
void behaviour_face_down_and_right_oam_callback(oam_object *o);
void behaviour_face_down_up_and_left_oam_callback(oam_object *o);
void behaviour_face_down_up_and_right_oam_callback(oam_object *o);
void behaviour_face_up_left_and_right_oam_callback(oam_object *o);
void behaviour_face_down_left_and_right_oam_callback(oam_object *o);
void behaviour_rotate_counterclockwise_oam_callback(oam_object *o);
void behaviour_rotate_clockwise_oam_callback(oam_object *o);
void behaviour_walk_up_and_down_oam_callback(oam_object *o);
void behaviour_walk_down_and_up_oam_callback(oam_object *o);
void behaviour_walk_left_and_right_oam_callback(oam_object *o);
void behaviour_walk_right_and_left_oam_callback(oam_object *o);
void behaviour_walk_sequence_up_right_left_down_oam_callback(oam_object *o);
void behaviour_walk_sequence_right_left_down_up_oam_callback(oam_object *o);
void behaviour_walk_sequence_down_up_right_left_oam_callback(oam_object *o);
void behaviour_walk_sequence_left_down_up_right_oam_callback(oam_object *o);
void behaviour_walk_sequence_up_left_right_down_oam_callback(oam_object *o);
void behaviour_walk_sequence_left_right_down_up_oam_callback(oam_object *o);
void behaviour_walk_sequence_down_up_left_right_oam_callback(oam_object *o);
void behaviour_walk_sequence_right_down_up_left_oam_callback(oam_object *o);
void behaviour_walk_sequence_left_up_down_right_oam_callback(oam_object *o);
void behaviour_walk_sequence_up_down_right_left_oam_callback(oam_object *o);
void behaviour_walk_sequence_right_left_up_down_oam_callback(oam_object *o);
void behaviour_walk_sequence_down_right_left_up_oam_callback(oam_object *o);
void behaviour_walk_sequence_right_up_down_left_oam_callback(oam_object *o);
void behaviour_walk_sequence_up_down_left_right_oam_callback(oam_object *o);
void behaviour_walk_sequence_left_right_up_down_oam_callback(oam_object *o);
void behaviour_walk_sequence_down_left_right_up_oam_callback(oam_object *o);
void behaviour_walk_sequence_up_left_down_right_oam_callback(oam_object *o);
void behaviour_walk_sequence_down_right_up_left_oam_callback(oam_object *o);
void behaviour_walk_sequence_left_down_right_up_oam_callback(oam_object *o);
void behaviour_walk_sequence_right_up_left_down_oam_callback(oam_object *o);
void behaviour_walk_sequence_up_right_down_left_oam_callback(oam_object *o);
void behaviour_walk_sequence_down_left_up_right_oam_callback(oam_object *o);
void behaviour_walk_sequence_left_up_right_down_oam_callback(oam_object *o);
void behaviour_walk_sequence_right_down_left_up_oam_callback(oam_object *o);
void behaviour_copy_player_oam_callback(oam_object *o);
void behaviour_copy_player_opposite_oam_callback(oam_object *o);
void behaviour_copy_player_counterclockwise_oam_callback(oam_object *o);
void behaviour_copy_player_clockwise_oam_callback(oam_object *o);
void behaviour_tree_disguise_oam_callback(oam_object *o);
void behaviour_mountain_disguise_oam_callback(oam_object *o);
void behaviour_copy_player_in_grass_oam_callback(oam_object *o);
void behaviour_copy_player_opposite_in_grass_oam_callback(oam_object *o);
void behaviour_copy_player_counterclockwise_in_grass_oam_callback(oam_object *o);
void behaviour_copy_player_clockwise_in_grass_oam_callback(oam_object *o);
void behaviour_hidden_oam_callback(oam_object *o);
void behaviour_walk_in_place_down_oam_callback(oam_object *o);
void behaviour_walk_in_place_up_oam_callback(oam_object *o);
void behaviour_walk_in_place_left_oam_callback(oam_object *o);
void behaviour_walk_in_place_right_oam_callback(oam_object *o);
void behaviour_jog_in_place_down_oam_callback(oam_object *o);
void behaviour_jog_in_place_up_oam_callback(oam_object *o);
void behaviour_jog_in_place_left_oam_callback(oam_object *o);
void behaviour_jog_in_place_right_oam_callback(oam_object *o);
void behaviour_run_in_place_down_oam_callback(oam_object *o);
void behaviour_run_in_place_up_oam_callback(oam_object *o);
void behaviour_run_in_place_left_oam_callback(oam_object *o);
void behaviour_run_in_place_right_oam_callback(oam_object *o);
void behaviour_invisible_oam_callback(oam_object *o);
void behaviour_walk_slowly_in_place_down_oam_callback(oam_object *o);
void behaviour_walk_slowly_in_place_up_oam_callback(oam_object *o);
void behaviour_walk_slowly_in_place_left_oam_callback(oam_object *o);
void behaviour_walk_slowly_in_place_right_oam_callback(oam_object *o);

extern void (*const person_behaviour_oam_callbacks[NUM_BEHAVIOURS])(oam_object*);
extern const u8 person_behaviour_has_range[NUM_BEHAVIOURS];
extern const u8 person_behaviour_initial_direction[NUM_BEHAVIOURS];


/** * Updates the current movement of an NPC. This is called by the functionality behind it's person_behaviour.
 * 
 * @param n The NPC whose movement is to be updated.
 * @param o The OAM object representing the NPC's sprite.
 * @param callback The callback function to use for updating the movement.
 */

void npc_update_current_movement(npc *n, oam_object *o, u8 (*callback)(npc*, oam_object*));

#endif