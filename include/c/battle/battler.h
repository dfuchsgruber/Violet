/*
 * battler.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_BATTLER_H_
#define INCLUDE_C_BATTLE_BATTLER_H_

#include <stdbool.h>
#include "types.h"
#include "pokemon/virtual.h"

typedef struct battler {
    u16 species;
    u16 stats[5];
    u16 moves[4];
    u32 ivs;
    u8 stat_changes[8];
    u8 ability;
    u8 type1;
    u8 type2;
    u8 field_23;
    u8 current_pp[4];
    u16 current_hp;
    u8 level;
    u8 happiness;
    u16 max_hp;
    u16 item;
    u8 name[11];
    u8 trigger;
    u8 ot[8];
    u32 custom_status; //to apply hacks
    pid_t pid;
    u32 status1;
    u32 status2;
    u32 tid;
} battler;

#define STATUS1_SLEEPING 7
#define STATUS1_POISONED 8
#define STATUS1_BURNED 16
#define STATUS1_FROZEN 32
#define STATUS1_PARALYZED 64
#define STATUS1_BADLY_POISONED 0x80
#define STATUS1_BADLY_POISONED_TURNS 0xF00
#define STATUS1_POISONED_ANY (STATUS1_POISONED | STATUS1_BADLY_POISONED)
#define STATUS1_ANY (STATUS1_SLEEPING | STATUS1_POISONED | STATUS1_BURNED | STATUS1_FROZEN | STATUS1_PARALYZED | STATUS1_BADLY_POISONED)

#define STATUS2_CONFUSED 7
#define STATUS2_FLINCHED 8
#define STATUS2_UPROARED 0x70
#define STATUS2_BIDE 0x300
#define STATUS2_LOCK_CONFUSE 0xC00
#define STATUS2_ATTACK_CHARGED 0x1000
#define STATUS2_WRAPPED 0xE000
#define STATUS2_INFATUATION 0xF0000
#define STATUS2_FOCUS_ENERGY 0x00100000
#define STATUS2_TRANSFORMED 0x00200000
#define STATUS2_RECHARGE 0x00400000
#define STATUS2_RAGE 0x00800000
#define STATUS2_SUBSTITUTE 0x01000000
#define STATUS2_DESTINY_BOND 0x02000000
#define STATUS2_ESCAPE_PREVENTION 0x04000000
#define STATUS2_NIGHTMARE 0x08000000
#define STATUS2_CURSED 0x10000000
#define STATUS2_FORESIGHT 0x20000000
#define STATUS2_DEFENSE_CURL 0x40000000
#define STATUS2_TORMENT 0x80000000

#define STATUS3_LEECHSEED_BATTLER       0x3
#define STATUS3_LEECHSEED               0x4
#define STATUS3_ALWAYS_HITS             0x18    // two bits
#define STATUS3_PERISH_SONG             0x20
#define STATUS3_ON_AIR                  0x40
#define STATUS3_UNDERGROUND             0x80
#define STATUS3_MINIMIZED               0x100
#define STATUS3_ROOTED                  0x400
#define STATUS3_CHARGED_UP              0x200
#define STATUS3_YAWN                    0x1800  // two bits
#define STATUS3_IMPRISONED_OTHERS       0x2000
#define STATUS3_GRUDGE                  0x4000
#define STATUS3_CANT_SCORE_A_CRIT       0x8000
#define STATUS3_MUDSPORT                0x10000
#define STATUS3_WATERSPORT              0x20000
#define STATUS3_UNDERWATER              0x40000
#define STATUS3_INTIMIDATE_POKES        0x80000
#define STATUS3_TRACE                   0x100000
#define STATUS3_SEMI_INVULNERABLE       (STATUS3_UNDERGROUND | STATUS3_ON_AIR | STATUS3_UNDERWATER)

#define CUSTOM_STATUS_AP_SPARER (1 << 0)
#define CUSTOM_STATUS_KINGS_SHIELD (1 << 1)
#define CUSTOM_STATUS_KINGS_SHIED_DROP (1 << 2)

typedef struct battler_status{
    u32 protect : 1;
    u32 endure : 1;
    u32 out_of_moves : 1;
    u32 helping_hand : 1;
    u32 bounce : 1;
    u32 steal : 1;
    u32 bit_6 : 1;
    u32 immobility : 1;
    u32 hurt_in_confusion : 1;
    u32 target_unaffected : 1;
    u32 charging : 1;
    u32 flee : 2;
    u32 used_imprisoned_move : 1;
    u32 love_immobility : 1;
    u32 used_disabled_move : 1;
    u32 used_taunted_move : 1;
    u32 bit_10 : 1;
    u32 flinched : 1;
    u32 not_first_strike : 1;
	int physical_damage;
	int special_damage;
	u8 physical_damage_battler;
	u8 special_damage_battler;
} battler_status;

typedef struct battler_damage_taken_stru {
	u8 stat_dropped : 1;
	u8 lighting_rod : 1;
	u8 restored_sprite : 1;
	u8 intimdated_foe : 1;
	u8 traced : 1;
	u8 pp_unaffected_by_pressure : 1;
	u8 bit_6;
	u8 used_focus_band : 1;
	int damage;
	int physical_damage;
	int special_damage;
	u8 physical_damage_battler;
	u8 special_damage_battler;
} battler_damage_taken_stru;

typedef struct {
    u8 reflect_turns;
    u8 reflect_battler_idx;
    u8 lightscreen_turns;
    u8 lightscreen_battler_idx;
    u8 mist_turns;
    u8 mist_battler_idx;
    u8 safeguard_turns;
    u8 safeguard_battler_idx;
    u8 follow_me_turns;
    u8 follow_me_target_battler_idx;
    u8 spikes_layers;
    u8 field_B;
} battle_side_timer_stru;

typedef struct {
	u16 reflect : 1;
	u16 lightscreen : 1;
	u16 status_2 : 1;
	u16 status_3 : 1;
	u16 status_spikes : 1;
	u16 status_safeguard : 1;
	u16 status_future_sight : 1;
	u16 status_mist : 1;
	u16 status_spikes_damaged : 1;
} battle_side_status_stru;

typedef struct {
	u8 future_sight_turns[4];
	u8 future_sight_attacking_battler_idx[4];
	int future_sight_damage[4];
	u16 future_sight_move[4];
	u8 wish_turns[4];
	u8 wish_target[4];
	u8 weather_turns;
	u8 knocked_off[2]; // One entry per side, bit per battler
	u8 field_2B;
} battler_timer_stru;

extern battler battlers[4];
extern battler_status battler_statuses[4];
extern battler_damage_taken_stru battler_damage_taken[4];
extern battle_side_timer_stru battle_side_timers[2];
extern battle_side_status_stru battle_side_statuses[2];
extern battler_timer_stru battler_timers;

#define DAMAGE_CAUSED ((battler_damage_taken[defending_battler].physical_damage != 0 || battler_damage_taken[defending_battler].special_damage != 0))

extern u8 attack_targets;
extern u8 attacking_battler;
extern u8 defending_battler;
extern u8 defending_battler_ability;
extern u8 active_battler;
extern u8 battler_oams[];
extern u8 battler_cnt;
extern u16 battler_team_slots[];
extern u8 battler_attacking_order[];
extern u32 battler_statuses3[4];
extern u8 item_target_battler;

/**
 * Checks if a battler is an opponent
 * @param index The battler index
 * @return Whether the battler is an opponent
 */
bool battler_is_opponent(u8 index);


#define ALIVE_EXCEPT_ACTIVE_BATTLER 0
#define ALIVE_ATTACKING_SIDE 1
#define ALIVE_DEFENDING_SIDE 2

/**
 * Counts the battlers alive for a side (i.e. in double battles).
 * @param side the side for which to count battlers alive (see above)
 * @return num_alive the number of battlers alive
 */
u8 battlers_alive(int side);

/**
 * Gets the position of a battler.
 * @param battler_idx the index of the battler
 * @return position position of the battler
 */
u8 battler_get_position(u8 battler_idx);

#endif /* INCLUDE_C_BATTLE_BATTLER_H_ */
