/*
 * virtual.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TRAINER_VIRTUAL_H_
#define INCLUDE_C_TRAINER_VIRTUAL_H_

#include "types.h"
#include "constants/trainer_battle_types.h"
#include "overworld/npc.h"

#define TRAINER_BATTLE_TYPE_IS_DOUBLE(type) ((type) == TRAINER_BATTLE_DOUBLE || (type) == TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE || (type) == TRAINER_BATTLE_REMATCH_DOUBLE || (type) == TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC)
 
typedef struct trainer_variables {
    u16 kind_of_battle;
    u16 trainer_id;
    u16 overworld_target;
    u16 padding;
    u8 *challange_text;
    u8 *defeat_text;
    u8 *victory_text;
    u8 *unable_to_battle_text;
    u8 *script_later;
    u8 *script_continue;
    u16 rival_flags;
} trainer_variables;

typedef struct {
    void *dst;
    u8 command;
} trainerbattle_configuration;

extern trainerbattle_configuration trainerbattle_configuration_single_with_continuation[];
extern trainerbattle_configuration trainerbattle_configuration_single_no_intro_text[];
extern trainerbattle_configuration trainerbattle_configuration_double[];
extern trainerbattle_configuration trainerbattle_configuration_single[];
extern trainerbattle_configuration trainerbattle_configuration_double_with_continuation[];
extern trainerbattle_configuration trainerbattle_configuration_losable[];

extern trainer_variables trainer_vars;

/**
 * Reads an unaligned hword form the trainer build mini script
 * @param src the source to read from
 * @return the hword that was read
 */
u16 trainer_get_unaligned_hword(void *src);

/**
 * Returns the flag associated with the current trainer
 * @return the flag
 */
u16 trainer_get_flag();

/**
 * Sets trainer flags (for both A and B trainer)
 **/
void trainer_set_flags();

/**
 * Continuation that is called after a trainerbattle ends
 */
void battle_trainerbattle_continuation();

/**
 * Configures all trainer variables
 * @param configuration the configuration according to which variables are to be configured
 * @param parameters the trainerbattle parameters
 **/
void trainerbattle_configure(trainerbattle_configuration *configuration, u8 *parameters);

/**
 * Configures the trainer variables and initalizes a script for challanging the player, single battle.
 * @param npc_idx the npc to move
 * @param ow_script the trainer script
 **/
void trainerbattle_configure_and_initialize_challange_script(u8 npc_idx, u8 *ow_script);


/**
 * Initializes and configures the trainer at fmem.current_trainer with a trainerbattle command.
 * @param script the trainerbattle command to initialize the trainer with.
 **/
u8 *trainer_configure_by_overworld_script(u8 *ow_script);

/**
 * Gets the npc idx of the currently approaching trainer npc and updates trainer_npc_idx and LASTTALKED.
 * @return the npc idx
 **/
u8 trainer_get_current_npc_idx();

/**
 * Moves a trainer npc to the player
 * @param n the npc to move to
 * @param distance how much it should be moved
 **/
void trainer_npc_move_to_player(npc *n, u8 distance);

/**
 * Sets the target npc_idx to the trainer that was loaded before.
 **/
void trainerbattle_load_target_npc();

/**
 * Starts the trainer battle, i.e. increments stats, loads the transition and starts the battle function. Battle flags should
 * be already set at this point.
 **/
void trainerbattle_start();

/**
 * Gets the sum of a trainer's party's first num pokemon's level.
 * @param trainer_idx the trainer
 * @param num how many mons to consider
 * @return total sum of the levels
 **/
u8 trainer_pokemon_get_total_level(u16 trainer_idx, u8 num);

/**
 * Gets the idx of the rematch trainer associated with a trainer.
 * @param trainer_idx the trainer idx to check
 * @return the assoicated rematch trainer idx
 **/
u16 trainer_get_rematch_idx(u16 trainer_idx);

// Ow script that does encounter music, intro speech and starts the battle.
extern u8 ow_script_trainerbatte_challange[];

// For double battles
extern u8 ow_script_trainerbattle_double[];

// For double battles in a rematch
extern u8 ow_script_trainerbattle_rematch_double[];

// Ow script that does the rematch battle
extern u8 ow_script_trainerbattle_rematch[];

// Challange script that executes the continuation afterwards
extern u8 ow_script_trainerbattle_with_continuation[];

// Challange script for double battles, that omits checking if the player has two viable pokemon (for ally battles)
extern u8 ow_script_trainerbattle_double_dont_check_enough_pokemon[];

#endif /* INCLUDE_C_TRAINER_VIRTUAL_H_ */
