/* 
 * File:   fieldmoves.h
 * Author: Domi
 *
 * Created on 12. Juni 2016, 19:05
 */

#ifndef FIELDMOVES_H
#define	FIELDMOVES_H

#include "types.h"
#include "stdbool.h"
#include "pokemon/virtual.h"
#include "constants/field_moves.h"

u16 field_moves[NUM_FIELD_MOVES + 1];

typedef struct {
    bool (*function)();
    int failure_message_idx;
} field_move_t;

void (*field_move_overworld_continuation)();

/**
* Tries to initialize the field move flash.
* @return if the field move flash could be initialized successfully.
*/
bool field_move_check_flash();
    
/**
* Tries to initialize the field move cut.
* @return if the field move cut could be initialized successfully.
*/
bool field_move_check_cut();
    
/**
* Tries to initialize the field move fly.
* @return if the field move fly could be initialized successfully.
*/
bool field_move_check_fly();
    
/**
* Tries to initialize the field move strength.
* @return if the field move strength could be initialized successfully.
*/
bool field_move_check_strength();
    
/**
* Tries to initialize the field move surf.
* @return if the field move surf could be initialized successfully.
*/
bool field_move_check_surf();
    
/**
* Tries to initialize the field move rock_smash.
* @return if the field move rock_smash could be initialized successfully.
*/
bool field_move_check_rock_smash();
    
/**
* Tries to initialize the field move waterfall.
* @return if the field move waterfall could be initialized successfully.
*/
bool field_move_check_waterfall();
    
/**
* Tries to initialize the field move rock_climb.
* @return if the field move rock_climb could be initialized successfully.
*/
bool field_move_check_rock_climb();
    
/**
* Tries to initialize the field move teleport.
* @return if the field move teleport could be initialized successfully.
*/
bool field_move_check_teleport();
    
/**
* Tries to initialize the field move dig.
* @return if the field move dig could be initialized successfully.
*/
bool field_move_check_dig();
    
/**
* Tries to initialize the field move softboiled.
* @return if the field move softboiled could be initialized successfully.
*/
bool field_move_check_softboiled();
    
/**
* Tries to initialize the field move sweet_scent.
* @return if the field move sweet_scent could be initialized successfully.
*/
bool field_move_check_sweet_scent();
    
/**
* Tries to initialize the field move secret_power.
* @return if the field move secret_power could be initialized successfully.
*/
bool field_move_check_secret_power();



/**
 * Initializes the field move softboiled from the pokemon party menu
 * @param self the own callback id
 */
void field_move_softboiled_init(u8 self);

/**
 * Initializes the field move fly from the pokemon party menu
 */
void field_move_fly_init();

/**
 * Initializes the error message for the fieldmove surfer
 */
void field_move_surfer_print_error();

/**
 * Loads the buffers for executing a field move
 * @param the pokemon executing the field move
 * @param index the field move index
 */
void field_move_load_buffers(pokemon *pokemon, u8 index);

/**
 * Contiuation for flash in the overworld.
 **/
void field_move_flash_overworld();

extern u8 ow_script_dungeon_enter_field[];
extern u8 ow_script_execute_rock_climb[];
extern u8 ow_script_field_move_golem_regirock[];

extern u8 str_field_move_description_flash[];
extern u8 str_field_move_description_cut[];
extern u8 str_field_move_description_fly[];
extern u8 str_field_move_description_strength[];
extern u8 str_field_move_description_surf[];
extern u8 str_field_move_description_rock_smash[];
extern u8 str_field_move_description_waterfall[];
extern u8 str_field_move_description_rock_climb[];
extern u8 str_field_move_description_teleport[];
extern u8 str_field_move_description_dig[];
extern u8 str_field_move_description_milk_drink[];
extern u8 str_field_move_description_softboiled[];
extern u8 str_field_move_description_sweet_scent[];
extern u8 str_field_move_description_secret_power[];

extern u8 str_field_move_usable_with_new_badge[];
extern u8 str_field_move_return_to_healing_place[];
extern u8 str_field_move_return_dig[];

#endif	/* FIELDMOVES_H */

