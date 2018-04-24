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


bool checktrainerflag(u16 trainer_id);
bool trainer_can_npc_challange_player(u16 trainer_id);
bool special_x36_check_loaded_trainerflag();
void special_prepeare_player_facing();

#endif /* INCLUDE_C_TRAINER_TRAINER_H_ */
