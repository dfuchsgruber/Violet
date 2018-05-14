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
    int is_dual_battle;
    u16 ai;
    u16 field_1E;
    u8 pokemon_cnt;
    u8 field_21;
    u8 field_22;
    u8 field_23;
    trainer_pokemon *party;

} trainer;

trainer trainers [TRAINER_CNT];

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

#endif /* INCLUDE_C_TRAINER_TRAINER_H_ */
