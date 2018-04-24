/*
 * attack.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_ATTACK_H_
#define INCLUDE_C_BATTLE_ATTACK_H_

u16 *active_attack = (u16*) 0x02023D4A;
u8 *active_attack_slot = (u8*)0x02023D48;
u32 *attack_result = (u32*)0x02023DCC;

int *damage_to_apply = (int*)0x2023D50;
int *damage_caused = (int*)0x02023D54;

u8 *attack_anim_target_index = (u8*)0x02037F1B;
u8 *attack_anim_user_index = (u8*)0x02037F1A;
u16 *attack_anim_additional_animation = (u16*)0x2037F02;
u8 *attack_anim_tasks_running = (u8*)0x02037EE2;

void damage_apply_multiplier(int multiplier);

#endif /* INCLUDE_C_BATTLE_ATTACK_H_ */
