/*
 * battle.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_STATE_H_
#define INCLUDE_C_BATTLE_STATE_H_

#include "battle/battlescript.h"
#include "item/item_effect.h"
#include "pokemon/virtual.h"
#include "constants/battle/battle_flags.h"
#include "save.h"
#include "overworld/pokemon_party_menu.h"
#include "constants/battle/battle_statuses.h"
#include "oam.h"
#include "attack.h"

typedef struct {
	u8 name[7];
	u8 hold_effect;
	item_effect_t item_effect;
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
    u16 assist_possible_moves[6 * 4]; // 6 mons, each of them knowing 4 moves
    u8 focus_punch_battler_idx;
    u8 battler_preventing_switchout;
    u8 money_multiplier;
    u8 saved_turn_action_number;
    u8 switch_in_abilities_counter;
    u8 fainted_actions_state;
    u8 fainted_actions_battler_idx;
    u8 field_4F;
    u16 experience;
    u8 field_52;
    u8 sent_in_battlers;
    u8 selection_script_finished[4];
    u8 switch_out_party_idxs[4];
    u8 battler_to_switch_into[4];
    u8 field_60[4][3];
    u8 run_attempts;
    u8 caught_pokemon_nickname[11];
    u8 field_78;
    u8 safari_go_near_count;
    u8 safari_throw_count;
    u8 safari_escape_factor;
    u8 safari_catch_factor;
    u8 link_battle_vs_oam_idxs[2];
    u8 form_to_change_into;
    u8 chosen_move_slots[4];
    u8 state_idx_after_selection_script[4];
    u8 field_88;
    u8 field_89;
    u8 field_8A;
    u8 field_8B;
    u8 field_8C;
    u8 field_8D;
    u8 string_move_type;
    u8 experience_getter_battler_idx;
    u8 field_90;
    u8 field_91;
    //u8 __ai_mon_to_switch_into[2]; // Dont use that... only one per side...
    u8 ai_switch_target_chosen; // Bitfield
    u8 field_93; // Refactoring of the 2 bytes above
    u8 wally_battle_state;
    u8 wally_moves_state;
    u8 wally_wait_frames;
    u8 wally_move_frames;
    u8 mirror_moves[4 * 2 * 2]; // ask gamefreak why they declared it that way
    u16 hp_on_switch_out[2];
    u8 ability_preventing_swich_out;
    u8 hp_scale;
    u16 saved_battle_type_flags;
    void (*saved_callback)();
    u8 synchronize_move_effect;
    u8 multiplayer_idx;
    u8 overworld_weather_done;
    u8 attack_canceler_state;
    u16 items_consumed[4];
    u8 chosen_item[4]; // why is this an u8?
    u8 ai_item_type[2];
    u8 ai_item_flags[2];
    u16 choiced_move[4];
    u16 changed_items[4];
    u8 intimidate_battler_idx;
    u8 switch_in_items_count;
    u8 field_DA;
    u8 turn_side_tracker;
    u8 fillerDC[0xDF-0xDC];
    u8 given_exp_mons;
    u8 last_taken_move_from[4 * 4 * 2];
    u16 castform_palette[4][16];
    u8 wish_perish_song_state;
    u8 wish_perish_song_battler;
    u8 field_182;
    u8 field_183;
    u8 field_184;
    u8 field_185;
    u8 field_186;
    u8 field_187;
    enigma_berry_stru enigma_berry;
    u8 field_1A4[0x5C];
} battle_state_t;

extern battle_state_t *battle_state;

#define GET_MOVE_TYPE(move, var)                             \
{                                                            \
    if (battle_state->dynamic_move_type)                     \
        var = battle_state->dynamic_move_type & 0x3F;        \
    else                                                     \
        var = attacks[move].type;                            \
}

#define MAX_ITEMS_DROPPED_PER_BATTLER 4
typedef struct {
    u16 items[4][4]; // 4 Items per owner (instead of only one for the AI) (the player one should be unused in theory...)
    u8 num_items[4]; // How many items each owner
    u32 saved_battle_flags;
    u8 handicap_introduced;
    u8 switch_in_handicap_effects_cnt;
    u8 end_of_turn_handicap_effects_cnt;
    u32 status_custom[4]; // Cleared before an attack
    u32 status_custom_persistent[4]; // Not cleared before an attack
    u8 attack_done_substate; // A substate that is used to trigger additional events for ending an attack with bsc cmd 0x49
    u8 before_attack_state;
    u8 throwing_pokeball : 1; // If active, this indicates that one player action is to throw a pokeball. This is needed to prevent two of these actions in a double wild battle
    u8 num_items_dropped[4]; // Items dropped per battler already
    u16 items_dropped[4][MAX_ITEMS_DROPPED_PER_BATTLER];
    u8 items_dropped_cnt[4][MAX_ITEMS_DROPPED_PER_BATTLER]; 
    u8 items_dropped_oams[MAX_ITEMS_DROPPED_PER_BATTLER];
    u8 items_dropped_done; // bitfield
    u8 item_dropping_battler; 
    u8 item_dropping_state; // Assumed to be zero initialized in a battle
    u8 item_dropping_summary_tbox_idx;
    u8 item_dropping_chance_increased_by_item : 1;
    u8 item_dropping_chance_increased_by_ability : 1;
    u8 aggresive_battler_idx; 
    u8 golden_apple_battler_idx;
    u32 fleeing_rng_seed;
    u32 fleeing_rng;
} battle_state2_t;

#define BATTLE_STATE2 ((battle_state2_t*)fmem.battle_state2)

typedef struct {
	void (*callbacks[8])(void);
	u8 size;
} battle_callbacks_stack_t;

typedef struct {
    u8 player_faint_cnt;
    u8 opponent_faint_cnt;
    u8 player_switches_cnt;
    u8 healing_items_cnt;
    u8 revives_cnt;
    u8 player_damaged : 1;
    u8 master_ball_used : 1;
    u8 ball_used : 4;
    u8 shiny_wild_pokemon : 1;
    u16 player_species_0;
    u8 player_nickname_0[11];
    u8 turns_cnt;
    u8 player_nickname_1[11];
    u8 pokeblock_cnt;
    u16 opponent_last_species;
    u16 player_last_used_move;
    u16 opponent_last_used_move;
    u16 player_species_2;
    u16 caught_species;
    u8 caught_nickname[11];
    u8 field_0x35;
    u8 catch_attempts[11];
} battle_results_t;

extern battle_results_t battle_results;

// Maybe in FRLG this differs, do not trust this too much...
typedef struct {
	u8 state;
	u8 moveset_idx;
	u16 current_move;
	s8 score[4];
	u32 result;
	u32 flags;
	u8 action;
	u8 logic_idx;
	u8 field_12[6];
	u8 rng[4];
} battle_ai_state;

typedef struct {
	u8 unkown[32];
	u8 abilities[4];
	u8 item_effects[4];
	u16 trainer_items[4];
	u8 trainer_item_count;
} battle_history_t;

typedef struct {
	void *secret_base; // maybe?
	void *flags; // maybe?
	battlescript_stack_t *battle_script_stack;
	battle_callbacks_stack_t *battle_callbacks_stack;
	u16 *stats_before_level_up;
	battle_ai_state *ai_state;
	battle_history_t *history;
	battlescript_stack_t *ai_script_stack;
} battle_struct_t;


typedef struct {
    /*0x0*/ u16 invisible : 1; // 0x1
            u16 sound_effect_low_hp : 1; // 0x2
            u16 behind_substitute : 1; // 0x4
            u16 flag_x8 : 1; // 0x8
            u16 hp_number_no_bars : 1; // 0x10
    /*0x2*/ u16 transformed_species;
} battle_sprite_info_t;

typedef struct {
    u16 anim_parameter; // to fill up later
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 ball_throw_state;
    u8 field_9_x1 : 1;
    u8 field_9_x2 : 1;
    u8 field_9_x1C : 3;
    u8 field_9_x20 : 1;
    u8 field_9_x40 : 1;
    u8 field_9_x80 : 1;
    u8 field_A;
    u8 field_B;
    s16 field_C;
    u8 field_E;
    u8 field_F;
} battle_animation_info_t;

typedef struct {
    u8 party_status_summary_shown : 1;
    u8 healthbox_is_bouncing : 1;
    u8 battler_is_bouncing : 1;
    u8 ball_anim_active : 1; // 0x8
    u8 status_anim_active : 1; // x10
    u8 anim_from_table_active : 1; // x20
    u8 special_anim_active : 1; //x40
    u8 flag_x80 : 1;
    u8 field_1_x1 : 1;
    u8 field_1_x1E : 5;
    u8 field_1_x40 : 1;
    u8 field_1_x80 : 1;
    u8 healthbox_bounce_sprite_idx;
    u8 battler_bounce_sprite_idx;
    u8 animation_state;
    u8 field_5;
    u8 matrix_number; // ??
    u8 shadow_sprite_oam_idx;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
} battle_healthbox_info_t;

typedef struct {
    u8 healthbox_oam_idx;
    s32 max_value;
    s32 old_value;
    s32 received_value;
    s32 current_value;
} battle_bar_info_t;

typedef struct {
    battle_sprite_info_t *sprite_info;
    battle_healthbox_info_t *healthbox_info;
    battle_animation_info_t *animation_info;
    battle_bar_info_t *bar_info;
} battle_sprite_data_t;

extern battle_sprite_data_t *battle_sprite_data;

extern u8 battle_healthbox_oams[4]; // Why is there a duplicate to the battle_sprite_data value?

extern u8 battle_animation_active;

extern battle_struct_t *battle_struct;
extern u32 battle_flags;
extern u8 battle_trainer_kind;
extern u8 battle_result;
extern u16 battle_trainer_id;
extern u8 battle_effects[4]; // Probably there even more, 0x3 is the target effect
extern u16 battle_dynamic_base_power;
extern u16 battle_current_turn_seed; // Random state that is fixed for one turn
extern u8 battle_action_current_turn; // idx from 0 to battler_cnt, not indexing the battlers but rather the turns themselfes (i.e. battlers ordered by turn order)
extern u8 battle_action;
extern void (*battle_main_callback)();
extern u16 battle_payday_money;

#define BATTLE_IS_WILD_DOUBLE ((battle_flags & BATTLE_DOUBLE) != 0 && (battle_flags & BATTLE_TRAINER) == 0)

extern void (*battle_actions[])();
extern void (*battle_end_turn_functions[])();

extern u8 battle_general_buffers0[4][512];
extern u8 battle_general_buffers1[4][512];

/**
 * Checks if the battle is a double battle
 * @return whether the battle is a double battle
 */
bool battle_is_double();

/**
 * Callback1 for the battle engine
 */
void battle_callback1();

/**
 * Callback1 that ends a pokedude battle
 **/
void battle_pokedude_callback_end();

/**
 * Gets the battle intro type.
 * @return the intro type used for battling.
 **/
u8 battle_get_intro_type();

/**
 * Initializes a battle.
 * @param intro_type the intro type of the battle
 * @param music the music to play during the battle
 **/
void battle_initialize(u8 intro_type, u16 music);

/**
 * Callback2 contiunation for wild  legendarybattles.
 **/
void battle_continuation_wild_legendary_battle_end();

/**
 * Reverts altnerative forms (megas, regents, Aeghislash) in the player party
 **/
void battle_alternative_forms_revert();

/**
 * Loads the party and index range that is available to the owner of a battler.
 * @param battler_idx the battler to check
 * @param first the first index available to the battler
 * @param last the first index not available to the battler
 * @return the party the indices refer to
 **/
pokemon *battler_load_party_range(u8 battler_idx, u8 *first, u8 *last);

/**
 * Checks if the current battle is a double multi battle.
 * @return if the battle is a double multi battle.
 **/
bool battle_is_multi_double();

/**
 * Checks if the current battle is a tag battle, i.e. with ally.
 * @return if the battle is a tag battle.
 **/
bool battle_is_tag();

/**
 * Checks if the current battle has two players (e.g. a partner)
 * @return if in a link multi battle or having an allied partner
 **/
bool battle_has_two_players();

/**
 * Checks if the current battle has two opponents, i.e. multi or against two trainers.
 * @return if the battle has two opponents
 **/
bool battle_has_two_opponents();

/**
 * Switches the party order in a link multi battle.
 * @param battler_idx the targeted battler that switches
 * @param i first position
 * @param j second position
 **/
void battle_link_multi_switch_party_order(u8 battler_idx, u8 i, u8 j);

/**
 * Action to execute when the turn is finished. Resets temporary variables. This is wrapped in battle_main.c by Violet
 **/
void battle_action_turn_finished();

/**
 * Probably copies data to showcase the partner pokemon in the party menu.
 **/
void sub_08010848();

/**
 * Callback1 that does initialization (mostly graphics) for a battle.
 **/
void battle_graphics_initialize();

/**
 * Handles events that are triggered before the very first turn of the battle.
 **/
void battle_events_before_first_turn();

/**
 * Introduces all aggresive battlers at the first turn. This is done after handicaps were introduced.
 **/
void battle_aggresive_battlers_introduce();

/**
 * Handles handicap effects triggered by a switch-in.
 * @param battler_idx the battler to apply the effect to
 * @return if any handicap effect was applicable
 **/
bool battle_handicap_switch_in_effects(u8 battler_idx);

/**
 * Executes effects due to handicaps before an attack starts.
 * @return if any effect, i.e. battlescript, was triggered
 **/
bool battle_handicap_before_attack_events();

/**
 * Executes new handicap effects after an attack was done.
 * @param if any handicap effect, i.e. battlescript, was triggered.
 **/
bool battle_handicap_attack_done();

/**
 * Executes new item effects after an attack was done.
 * @param if any item effect, i.e. battlescript, was triggered.
 **/
bool battle_items_attack_done_new();

/**
 * Executes the gunpowder battle item effect.
 * @return if the effect was applicable
 **/
bool battle_items_gunpowder();

/**
 * Executes the life-orb battle item effect.
 * @return if the effect was applicable
 **/
bool battle_items_life_orb();

/**
 * Executes new item effects after an attack was done, triggered by the defender's item.
 * @return if any effect was triggered
 **/
bool battle_items_attack_done_defender();

/**
 * Executes handicap effects that trigger at the end of the turn.
 * @return if any new handicap effect, i.e. battlescript was triggered.
 **/
bool battle_handicap_end_turn_effects();

/**
 * Executes field effects that trigger at the end of the turn (weather, light-screen, etc.)
 * @return if any new field effect, i.e. battlescript was triggered.
 **/
bool battle_end_turn_field_effects();

/**
 * Executes effects per battler at the end of the turn (wrap, ingrain, curse, etc.)
 * @return if any new effect, i.e. battlescript was triggered.
 **/
bool battle_end_turn_battler_effects();

/**
 * Executes battle item effects of the attacker before an attack
 * @return if any effect, i.e. battlescript was triggered
 **/
bool battle_item_before_attack_attacker();

/**
 * Executes battle item effects of the defender before an attack
 * @return if any effect, i.e. battlescript was triggered
 **/
bool battle_item_before_attack_defender();

/**
 * Function that handles the end of a turn when the battle continues, i.e. has not ended.
 **/
void battle_end_turn_handle_battle_continues();

/**
 * Callback for the sprite of a wild pokemon that moves it right
 * @param self self-reference
 **/
void battle_wild_pokemon_oam_callback_move_to_right(oam_object *self);

/**
 * Clears all battle handicaps.
 **/
void battle_handicap_clear();

/**
 * Sets a healthbox sprite invisible.
 * @param oam_idx the oam idx of the healthbox sprite
 **/
void battle_healthbox_set_invisible (u8 oam_idx);

/**
 * Gets some healthbox gfx tile.
 * @param tile the tile to get
 * @return pointer to the gfx
 **/
u8 *battle_healthbox_get_gfx(u8 tile);


#define BATTLE_GP_TBOX_IDX 12

#define BATTLE_GP_TBOX_DRAW 0
#define BATTLE_GP_TBOX_CLEAR 1
#define BATTLE_GP_TBOX_BG_0 0
#define BATTLE_GP_TBOX_BG_1 0x80
/**
 * Draws (or deletes) a general purpose battle tbox.
 * @param x0 upper left x coordinate (in multiples of 8 pixels)
 * @param y0 upper left y coordinate (in multiples of 8 pixels)
 * @param x1 lower right x coordinate (exclusive) (in multiples of 8 pixels)
 * @param y1 lower right y coordinate (exclusive) (in multiples of 8 pixels)
 * @param mode on which bg to draw / delete the box
 **/
void battle_gp_tbox_draw(u8 x0, u8 y0, u8 x1, u8 y1, u8 mode);

/**
 * Records the ability of a battler into the history
 * @param battler_idx the battler to load the ability of
 * @param ability the ability to load
 **/
void battle_record_ability(u8 battler_idx, u8 ability);

/**
 * Records the effect of an items battler
 * @param battler_idx the battler to record the ability of
 * @param hold_effect the hold effect to record
 **/
void battle_record_item_effect(u8 battler_idx, u8 hold_effect);

#endif /* INCLUDE_C_BATTLE_STATE_H_ */
