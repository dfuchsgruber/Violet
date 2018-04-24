/*
 * battler.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_BATTLER_H_
#define INCLUDE_C_BATTLE_BATTLER_H_

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
    u8 unkown[16];
}battler_status;


battler* battlers = (battler*) 0x02023BE4;

u8 *attack_targets = (u8*) 0x02023BD6;
u8 *attacking_battler = (u8*)0x02023D6B;
u8 *defending_battler = (u8*)0x02023D6C;
u8 *active_battler = (u8*)0x02023BC4;
u8 *battler_oams = (u8*) 0x02023D44;
u8 *battler_cnt = (u8*) 0x02023BCC;
u16 *battler_team_slots = (u16*) 0x02023BCE;
u8 *battler_attacking_order = (u8*)0x02023BDE;

battler_status *battler_statuses = (battler_status*)0x02023E8C;

#endif /* INCLUDE_C_BATTLE_BATTLER_H_ */
