/*
 * trainer.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TRAINER_TRAINER_H_
#define INCLUDE_C_TRAINER_TRAINER_H_

#define TRAINER_CNT 0x2E8

#include "trainer/party.h"
#include "constants/trainerclasses.h"

typedef struct {
    u8 uses_custom_moves : 1;
    u8 uses_custom_items : 1;
    u8 field_0_filler : 6;
    u8 trainerclass;

    struct encounter_and_gender {
        u8 encounter : 7;
        u8 gender : 1;
    } encounter_and_gender;
    u8 sprite;
    u8 name[12];
    u16 items[4];
    u32 battle_state; // These flags are forced onto the battle state
    u16 ai;
    u16 field_1E;
    u8 pokemon_cnt;
    u8 field_21;
    u8 field_22;
    u8 field_23;
    trainer_pokemon *party;

} trainer;

trainer trainers[TRAINER_CNT];

u8 trainer_class_names[TRAINERCLASS_CNT][13];

u8 trainer_class_money_multipliers[TRAINERCLASS_CNT];

/**
 * Checks the flag of a trainer
 * @param trainer_id Id of the trainer
 * @return Weather the trainer was battled
 */
bool checktrainerflag(u16 trainer_id);

/**
 * Checks whether a trainer can challange the player (double battle, fraction etc.)
 * @param trainer_id Id of the trainer
 * @return Whether the trainer will challange the player
 */
bool trainer_will_challange_player(u16 trainer_id);

/**
 * Special 0x36: Checks if the loaded trainer was battled
 * @return Whether the loaded trainer was battled
 */
bool special_x36_check_loaded_trainerflag();

/**
 * Special: Prepeares the player to face the trainer approaching
 */
void special_prepeare_player_facing();

/**
 * Checks if the game state prohibits a trainerbattle.
 * @return if a trainerbattle is prohibited.
 **/
bool trainerbattle_not_initializable();

/**
 * Checks if a trainer with a certain script wants to battle.
 * @param script the trainerscript command
 * @return if the trainerflag is set
 **/
bool npc_trainer_check_flag(u8 *script);

/**
 * Checks if the player is able to participate in a double battle.
 * @return 0 if the player has two viable pokemon, 2 if the player is only one viable pokemon (don't ask me...)
 **/
int player_party_get_double_battle_viability();

/**
 * Initializes a trainerbattle if a trainer npc sees the player.
 * @param npc_idx the npc to check
 * @return how many trainers were found, i.e. 1 if a normal trainer was found, 2 if a double battle trainer was found, 0 else
 **/
int trainerbattle_initialize_by_npc_idx(u8 npc_idx);

/**
 * Gets the flag of the second opponent.
 * @return trainerflag of the second opponent.
 **/
u16 trainerB_get_flag();

#endif /* INCLUDE_C_TRAINER_TRAINER_H_ */
