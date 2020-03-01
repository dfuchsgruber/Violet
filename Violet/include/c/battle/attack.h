/*
 * attack.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_ATTACK_H_
#define INCLUDE_C_BATTLE_ATTACK_H_

#include "attack.h"
#include "oam.h"

extern u16 active_attack;
extern u8 active_attack_slot;
extern u32 attack_result;
extern u8 critical_hit_multiplier;

extern int damage_to_apply;
extern int damage_caused;

extern u16 move_power;
extern u16 moves_used[4];

/**
 * Probably associates a battler with an attack, and finds the target(s)...
 *
 * @param attack The attack idx the active battler uses
 * @param consider_attack_targets if set the attack targets are ignored
 * @return the attack target of the active battler
 */
u8 attack_get_target_of_active_battler(u16 attack, bool ignore_attack_targets);

void damage_apply_multiplier(int multiplier);

/**
 * Returns the priority of an attack considering its user, i.e. abilities.
 * @param attack the attack to get the priority of
 * @param battler_idx the battler that uses the attack
 * @return the attack priority
 */
s8 battle_attack_priority_get(u16 attack, u8 battler_idx);

extern u8 *attack_anim_script;

extern u8 *attack_anims[];

// Battlescript for attack failed, reduces pp
extern u8 bsc_attack_failed_pp_reduce[];

/**
 * Clears the special-animation flag in the sprite data after the battle animation has finished.
 * @param self self-reference
 **/
void battle_special_anim_clear_flags_when_finished(u8 self);

/**
 * Initializes a battle animation, e.g. attack animations.
 * @param animations all animations
 * @param animation_idx the animation idx to execute
 * @param is_attack_anim if the animation initizalized is an attack animation
 **/
void battle_animation_initialize(u8 **animations,u8 animation_idx, bool is_attack_anim);

extern u8 *battle_animation_script;
extern u8 battle_animation_number_active_tasks;
extern u8 battle_animation_delay;
extern u8 battle_animation_user; 
extern u8 battle_animation_target;
extern u16 battle_animation_arguments[8];

/**
 * Loads the palette for an oam for a battle animation.
 * @param p the palette to load
 **/
void battle_animation_load_oam_palette(palette *p);

/**
 * Registers the tag of a gfx (oam) for battle animations.
 * @param the tag to register (not that all tags are relative to 10000). That is, all tags should be >= 10000
 **/
void battle_animation_register_gfx_tag(u16 tag);

void (*battle_animation_handler)();

/**
 * Battle animation handler that delays the animation script until the delay has finished.
 **/
void battle_animation_handler_delay();

/**
 * Removes a battle animation callback.
 * @param self self-reference
 **/
void battle_animation_big_callback_delete(u8 self);

extern u8 battle_animation_running;

void battle_animation_oam_particle_emission_above_battler_callback (oam_object *self);

#endif /* INCLUDE_C_BATTLE_ATTACK_H_ */
