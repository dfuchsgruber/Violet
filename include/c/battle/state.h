/*
 * battle.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_STATE_H_
#define INCLUDE_C_BATTLE_STATE_H_

typedef struct {
    u32 double_battle : 1;
    u32 link_battle : 1;
    u32 wild_battle : 1;
    u32 trainer_battle : 1;
    u32 oak_battle : 1;
    u32 flag_5 : 1;
    u32 multi_battle : 1;
    u32 safari_battle : 1;
    u32 items_prohibited : 1;
    u32 catch_tutorial : 1;
    u32 flag_A : 1;
    u32 items_prohibited2 : 1;
    u32 flag_C : 1;
    u32 flag_D : 1;
    u32 unkown : 18;
} battle_state_t;


battle_state_t *battle_state = (battle_state_t*) 0x02022B4C;

u16 *trainer_id = (u16*) 0x020386AE;
u8 *stat_change = (u8*) 0x02023FC4;

#endif /* INCLUDE_C_BATTLE_STATE_H_ */
