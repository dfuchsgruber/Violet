/*
 * battler.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_BATTLER_H_
#define INCLUDE_C_BATTLE_BATTLER_H_

#include <stdbool.h>

#define STAT_ATTACK 0
#define STAT_DEFENSE 1
#define STAT_INITIATIVE 2
#define STAT_SPECIAL_ATTACK 3
#define STAT_SPECIAL_DEFENSE 4

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
    u32 pid;
    u32 status1;
    u32 status2;
    u32 tid;
} battler;

#define STATUS1_SLEEPING 7
#define STATUS1_POISONED 8
#define STATUS1_BURNED 16
#define STATUS1_BADLY_POISONED 0x80

#define STATUS2_ATTACK_CHARGED 0x1000


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
}battler_status;

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



extern battler battlers[4];
extern battler_status battler_statuses[4];
extern battler_damage_taken_stru battler_damage_taken[4];

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

/**
 * Checks if a battler is an opponent
 * @param index The battler index
 * @return Whether the battler is an opponent
 */
bool battler_is_opponent(u8 index);


#endif /* INCLUDE_C_BATTLE_BATTLER_H_ */
