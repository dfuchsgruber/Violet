/*
 * battle.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_STATE_H_
#define INCLUDE_C_BATTLE_STATE_H_

#define BATTLE_DOUBLE 0x1
#define BATTLE_LINK 0x2
#define BATTLE_WILD 0x4
#define BATTLE_TRAINER 0x8
#define BATTLE_OAK 0x10
#define BATTLE_5 0x20
#define BATTLE_MULTI 0x40
#define BATTLE_SAFARI 0x80
#define BATTLE_TOWER 0x100
#define BATTLE_TUTORIAL 0x200
#define BATTLE_ROAMER 0x400
#define BATTLE_EREADER 0x800
#define BATTLE_12 0x1000
#define BATTLE_LEGENDARY 0x2000
#define BATTLE_31 0x80000000


typedef struct {
	u8 name[7];
	u8 hold_effect;
	u8 item_effect[18];
	u8 hold_effect_parameter;
	u8 filler; // ???
} enigma_berry_stru;

extern enigma_berry_stru enigma_berries[4];

// mostly taken from prets firered
// https://github.com/pret/pokefirered/blob/master/include/battle.h
typedef struct {
    u8 turn_effect_idx;
    u8 turn_effect_side;
    u8 field_2;
    u8 turn_counter_idx;
    u8 wrapped_move[8]; // ask gamefreak why they declared it that way
    u8 move_target[4];
    u8 exp_getter_idx;
    u8 field_11;
    u8 victory_song_idx;
    u8 dynamic_move_type;
    u8 wrapped_by[4];
    u16 assist_possible_moves[5 * 4]; // 5 mons, each of them knowing 4 moves
    u8 field_40;
    u8 field_41;
    u8 field_42;
    u8 field_43;
    u8 field_44;
    u8 field_45;
    u8 field_46;
    u8 field_47;
    u8 focus_punch_side;
    u8 battler_preventing_switchout;
    u8 money_multiplier;
    u8 saved_turn_action_number;
    u8 switch_in_abilities_counter;
    u8 fainted_actions_state;
    u8 fainted_actions_side;
    u8 field_4F;
    u16 experience;
    u8 field_52;
    u8 sent_in_battlers;
    u8 selection_script_finished[4];
    u8 field_58[4];
    u8 battler_to_switch_into[4];
    u8 field_60[4][3];
    u8 run_attempts;
    u8 caught_pokemon_nickname[11];
    u8 field_78;
    u8 safari_go_near_count;
    u8 safari_throw_count;
    u8 safari_escape_factor;
    u8 safari_catch_factor;
    u8 field_7D;
    u8 field_7E;
    u8 form_to_change_into;
    u8 chosen_move_slots[4];
    u8 state_id_after_selection_script[4];
    u8 field_88;
    u8 field_89;
    u8 field_8A;
    u8 field_8B;
    u8 field_8C;
    u8 field_8D;
    u8 string_move_type;
    u8 experience_getter_side;
    u8 field_90;
    u8 field_91;
    u8 field_92;
    u8 field_93;
    u8 wally_battle_state;
    u8 wally_moves_state;
    u8 wally_wait_frames;
    u8 wally_move_frames;
    u8 mirror_moves[8]; // ask gamefreak why they declared it that way
    u8 field_A0;
    u8 field_A1;
    u8 field_A2;
    u8 field_A3;
    u8 field_A4;
    u8 field_A5;
    u8 field_A6;
    u8 field_A7;
    u16 hp_on_switch_out[2];
    u32 saved_battle_types_flag;
    u8 ability_preventing_switch_out;
    u8 hp_scale;
    u8 synchronize_move_effect;
    u8 field_B3;
    u8 field_B4;
    u8 field_B5;
    u8 field_B6;
    u8 field_B7;
    // void (*savedCallback)(void);
    u16 items_consumed[4];
    u8 chosen_item[4]; // why is this an u8?
    u8 ai_item_type[2];
    u8 ai_item_flags[2];
    u16 choiced_move[4];
    u16 changed_items[4];
    u8 intimidate_side;
    u8 switch_in_items_count;
    u8 field_DA;
    u8 turn_side_tracker;
    u8 fillerDC[0xDF-0xDC];
    u8 field_DF;
    u8 mirror_move_arrays[32];
    u16 castform_palette[4][16];
    u8 field_180;
    u8 field_181;
    u8 field_182;
    u8 field_183;
    enigma_berry_stru enigma_berry;
    u8 wish_perish_song_state;
    u8 wish_perish_song_battler;
    u8 overworld_weather_done;
    u8 attack_cancler_idx;
    u8 field_1A4[96];
    u8 field_204[104];
    u8 field_26C[40];
    u8 ai_battler_to_switch_into[4];
    u8 field_298[8];
    u8 field_2A0;
    u8 field_2A1;
    u8 field_2A2;
} battle_state_t;


extern u32 battle_flags;
extern battle_state_t *battle_state;
extern u8 battle_trainer_kind;
extern u8 battle_result;
extern u16 battle_trainer_id;
extern u8 battle_stat_change[];
extern u8 battle_effects[4]; // Probably there even more, 0x3 is the target effect
extern u16 battle_dynamic_base_power;
extern u16 battle_current_turn_seed; // Random state that is fixed for one turn

/**
 * Checks if the battle is a double battle
 * @return whether the battle is a double battle
 */
bool battle_is_double();

/**
 * Callback1 for the battle engine
 */
void battle_callback1();


#endif /* INCLUDE_C_BATTLE_STATE_H_ */
