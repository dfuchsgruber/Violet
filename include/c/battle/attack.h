/*
 * attack.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_ATTACK_H_
#define INCLUDE_C_BATTLE_ATTACK_H_

#include "attack.h"

extern u16 active_attack;
extern u8 active_attack_slot;
extern u32 attack_result;

extern int damage_to_apply;
extern int damage_caused;

extern u8 attack_anim_target_index;
extern u8 attack_anim_user_index;
extern u16 attack_anim_additional_animation[];
extern u8 attack_anim_tasks_running;

/**
 * Probably associates a battler with an attack, and finds the target(s)...
 *
 * @param attack The attack idx the active battler uses
 * @param consider_attack_targets if set the attack targets are ignored
 * @return the attack target of the active battler
 */
u8 attack_get_target_of_active_battler(u16 attack, bool ignore_attack_targets);

void damage_apply_multiplier(int multiplier);

extern u8 *attack_anim_script;

extern u8 *attack_anims[];

#endif /* INCLUDE_C_BATTLE_ATTACK_H_ */
