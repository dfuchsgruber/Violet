/*
 * attack.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_ATTACK_H_
#define INCLUDE_C_BATTLE_ATTACK_H_

#include "attack.h"
#include "constants/attack_results.h"
#include "oam.h"

#define ATTACK_NO_EFFECT (ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)

extern u16 active_attack;
extern u8 active_attack_slot;
extern u32 attack_result;
extern u8 critical_hit_multiplier;

extern int damage_to_apply;
extern int damage_caused;

extern u16 move_power;
extern u16 moves_used[4];

#define BATTLE_ANIMATION_OAM_BASE 10000

extern graphic battle_animation_graphics[];
extern palette battle_animation_palettes[];

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

/**
 * Initializes a special battle animation
 * @param active the active battler
 * @param attacking the attacking battler
 * @param defending the defending battler
 * @param idx which animation to show
 **/
void battle_animation_special(u8 active, u8 attacking, u8 defending, u8 idx);

extern u8 *battle_animation_script;
extern u8 battle_animation_number_active_tasks;
extern u8 battle_animation_delay;
extern u8 battle_animation_user; 
extern u8 battle_animation_target;
extern u16 battle_animation_arguments[8];
extern u16 battle_animation_move_power;
extern u8 battle_animation_active;

#define STAT_ANIM_PLUS1(stat)  (15 + stat - 1)
#define STAT_ANIM_PLUS2(stat)  (39 + stat - 1)
#define STAT_ANIM_MINUS1(stat)  ( 22 + stat - 1)
#define STAT_ANIM_MINUS2(stat)  ( 46 + stat - 1)
#define STAT_ANIM_MULTIPLE_PLUS1(stat)  ( 55 + stat - 1)
#define STAT_ANIM_MULTIPLE_PLUS2(stat)  ( 56 + stat - 1)
#define STAT_ANIM_MULTIPLE_MINUS1(stat)  ( 57 + stat - 1)
#define STAT_ANIM_MULTIPLE_MINUS2(stat)  ( 58  + stat - 1)

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

/**
 * Applies multipliers to a current multiplier for attack effectiveness.
 * @param the type of the attack
 * @param defender_type1 the first defender type
 * @param defender_type2 the second defender type
 **/
void attack_apply_effectiveness_multiplier(u8 attacking_type, u8 defender_type1, u8 defender_type2, u8 *multiplier);

#define MOVE_LIMITATION_ZEROMOVE                (1 << 0)
#define MOVE_LIMITATION_PP                      (1 << 1)
#define MOVE_LIMITATION_DISABLED                (1 << 2)
#define MOVE_LIMITATION_TORMENTED               (1 << 3)
#define MOVE_LIMITATION_TAUNT                   (1 << 4)
#define MOVE_LIMITATION_IMPRISON                (1 << 5)
#define MOVE_LIMITATION_ALL 0xFF

/**
 * Gets the limtations on all moves of a battler.
 * @param battler_idx the target battler
 * @param current_limitations bitfield that indicates current move limitations
 * @param check_limitations flags to which limitations to check
 * @return limitations bitfield that indicates if a move is unusable
 **/
u8 battler_check_move_limitations(u8 battler_idx, u8 current_limitations, u8 check_limitations);

/**
 * Initializes a linear translation for the oam and executes the saved callback afterwards.
 * The destination x, y pair is given at private[2], private[4], and the duration is given at private[0]
 * @param self self-reference
 **/
void battle_animation_oam_callback_initialize_linear_translation(oam_object *self);

/**
 * Sets the continuation for an oam used in a battle animation.
 * @param self the oam to set the continuation of
 * @param continuation the function that is to be executed as continuation (e.g. for translations)
 **/
void battle_animation_set_continuation(oam_object *self, void (*continuation)(oam_object*));

/**
 * Deletes and frees all resources of an oam used in a battle animation.
 * @param self the oam to free
 **/
void battle_animation_oam_delete(oam_object *self);

/**
 * Oam callback that flickers out the oam after private[2] frames 
 * (flickering out starts 10 frames earlier, the sprite is gone after private[2] frames)
 * @param self self-reference
 **/
void battle_animation_oam_callback_roots_flicker_out(oam_object *self);

#endif /* INCLUDE_C_BATTLE_ATTACK_H_ */
