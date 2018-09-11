/*
 * attack.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_ATTACK_H_
#define INCLUDE_C_BATTLE_ATTACK_H_

extern u16 active_attack;
extern u8 active_attack_slot;
extern u32 attack_result;

extern int damage_to_apply;
extern int damage_caused;

extern u8 attack_anim_target_index;
extern u8 attack_anim_user_index;
extern u16 attack_anim_additional_animation;
extern u8 attack_anim_tasks_running;

void damage_apply_multiplier(int multiplier);

#endif /* INCLUDE_C_BATTLE_ATTACK_H_ */
