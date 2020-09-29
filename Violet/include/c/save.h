#ifndef HSAVE
#define HSAVE

#include "dungeon/dungeon2.h"
#include "pokepad/state.h"
#include "pokepad/pokedex/state.h"
#include "pokepad/incubator.h"
#include "map/wild_pokemon.h"
#include "map/event.h"
#include "map/header.h"
#include "map/footer.h"
#include "pokepad/wondertrade.h"
#include "anim_engine.h"
#include "multichoice.h"
#include "rtc.h"
#include "ev_menu.h"
#include "pokemon/virtual.h"
#include "pokemon/breeding.h"
#include "map/ceometria_gym.h"
#include "trainer/party.h"
#include "pokemon/roamer.h"
#include "item/item_effect.h"
#include "trainer/virtual.h"
#include "overworld/palette.h"

#define GP_STACK_SIZE 16

typedef struct warp_save_t {
	u8 bank, map, exit, field_3;
	s16 x, y;
} warp_save_t;

typedef struct saveblock1 {
    s16 x_cam_orig; //camera origin
    s16 y_cam_orig; //camera origin
    u8 bank;
    u8 map;
    u8 last_exit;
    u8 field_7;
    s16 field_8, field_A; // this struct is very warp_like: field_8, field_A seem to be 0xFFFF
    u8 unknown_1[0x8]; // probably also a warp save
    warp_save_t last_map; // ????
    warp_save_t healingplace;
    warp_save_t last_outdoor_map;
    u8 player_is_surfing;
    u8 field_45;
    u8 map_weather;
    u8 dynamic_weather_idx;
    u8 flash_circle_size;
    u8 field_31;
    u16 current_footer_id;
    //0x34
    u8 saved_party_count;
    u8 field_35;
    u8 field_36;
    u8 field_37; // Probably 0x35 to 0x37 are padding
    pokemon saved_party[6];
    u32 money;
    u8 unknown_2_2[1612];
    // 0x8e0
    map_event_person persons[64];
    // 0x20E0
    u8 flags[288];
    u16 vars[256];
    u32 sav_keys[64]; // This is one of the whackest names for stuff I have so far... At one point this should be renamed to: game stat
    u8 field_4864[6640];
    u16 mail_words[2][9]; // Might be there are more than 2 mails
    u8 unknown_4[620];
    // 0x2F80
    daycare_stru daycare;
    u8 field_12444[52];
    roamer_state_t roamer;
    u8 roamer_old_overhead[12]; // 12 bytes were retrieved refactoring the old roamer
    u8 field_12524[28];
    item_effect_t enigma_berry_item_effect;
    u8 field_12570[2942];
    mini_daycare_stru mini_daycare;
} saveblock1;

typedef struct saveblock2 {
    u8 player_name[0x8];
    u8 player_is_female;
    u8 field_9;
    u8 tid_0;
    u8 tid_1;
    u8 tid_2;
    u8 tid_3;
    u16 hours_played;
    // 0x10
    u8 minutes_played;
    u8 seconds_played;
    u8 milliseconds_played;
    u8 detector_state; //original key swtiching
    // 0x14
    u8 text_speed : 3;
    u8 tbox_style : 5;
    u8 sound_state : 1;
    u8 battle_style : 1;
    u8 battle_animations_off : 1;
    u8 region_map_zoom : 1;
    u8 unknown_3[0x2];
    u8 unknown_4[0x4];
    pid_t icognito_pid;
    // 0x20
    pid_t pandir_pid;
    u8 unknown_5[0x4];
    u8 pokedex_caught_flags[0x34]; //416 flags
    u8 pokedex_seen_flags[0x34]; //416 flags
    u8 unknown_6[3728];
    u32 money;
} saveblock2;

#define PLAYER_TID (u32)(save2->tid_0 + (save2->tid_1 << 8) + (save2->tid_2 << 16) + (save2->tid_3 << 24))



typedef struct {
    u8 berry : 7;
    u8 fertilized : 1;
    u8 stage : 3;
    u8 yield : 3;
    u8 picked_once : 1;
    u8 replanted : 1;
    u16 minutes_to_next_stage;
} berry_tree;

typedef struct custom_memory {
    u8 flag_extension[0x80]; //additional 0x400 flags (0x900-0xD00)
    u8 pokedex_seen_extension[0x40]; //additional 512 flags
    u8 pokedex_caught_extension[0x40]; //additional 512 flags
    u8 gp_freespace[0x100];
    u16 var_extension[0x100]; //Additional 256 vars (0x5000-0x50FF)
    u8 dungeon_flags[0x10]; // mapheader dmapheader (part I)
    pid_t daycare_offspring_pid; // FRLG's desing does not allow for an entire word to be stored...
    u8 daycare_offspring_has_hidden_ability;
    u8 daycare_offspring_male; // Volbeat and Nidoran may alter their gender when breeding (y tho?)
    box_pokemon incubator_slots[3];
    u8 ally_battle_selected_party_idxs[3];
    u8 unused[7];
    u32 money_backup;
    //trash memory (generall a vector memory)
    u8 trash_flags[16];
    rtc_timestamp daily_events_last_update;
    u32 daily_events_seed;
    rtc_timestamp fossil_gen_time;
    u8 any_tmp_flags[16];
    map_event_person pokeradar_person;
    
    //Dungeon Memory II
    dungeon_generator2 dg2;
    ceometria_gym_state_t ceometria_gym_state;
    roamer_state_t roamers[NUM_ROAMERS];
    roamer_history_entry_t roamer_histories[NUM_ROAMERS][3];
    roamer_history_entry_t roamer_locations[NUM_ROAMERS];
    berry_tree berry_trees[256];
    u8 mushroom_flags[64];
    u8 shell_flags[32];
    
    /**
    struct {
        u8 flags[64];
        u8 is_large[64];
    } mushrooms;
    struct {
        u8 flags[32];
        u8 is_large[32];
        u8 is_heart_scale[32];
    } shells;
    **/

} custom_memory;

#define DMAP_PERSONS 25
#define DMAP_WARPS 1

typedef struct {
    int _hook_tmp_; // This variable is used to save r0 values while trying to hook something that uses r0-r3 already
    u8 dmap_header_initialized : 1;
    u8 dmap_blocks_initialized : 1;
    u8 pathfinding_npc_movements_waiting : 1;
    u8 siirct_locked : 1;
    u8 battle_bg_index;
    u8 npc_facing_movements[2];
    pokepad_memory *pad_mem; // TODO: migrate pointers to the gp state
    wondertrade_memory *wtrade_mem;
    pokedex_memory *dex_mem;
    incubator_state_stru *incubator_state;
    ev_menu_state_stru *ev_menu_state;
    void *gp_state;
    u8 *additional_levelscript_4;
    u16 dmart[32]; //max 32 items per mart
    ae_memory *ae_mem;
    tileset *current_tileset_1;
    tileset *current_tileset_2;
    u8 dma0_dump[4];
    int gp_stack_size;
    int gp_stack[GP_STACK_SIZE];
    u8 mugshot_oam_id;
    u8 mugshot_tb_id;
    u8 mugshot_active : 1;
    multichoice_t dynamic_choice;
    u16 tile_anim_clks_0[8];
    u16 tile_anim_clks_1[8];
    map_header_t dmapheader;
    map_footer_t dmapfooter;
    map_event_header_t dmapevents;
    map_event_person dpersons[DMAP_PERSONS];
    map_event_warp dwarps[DMAP_WARPS];
    wild_pokemon_data dwild_pokemon;
    wild_pokemon_habitat dwild_habitat_grass;
    wild_pokemon_habitat dwild_habitat_water;
    wild_pokemon_habitat dwild_habitat_radar;
    wild_pokemon_habitat dwild_habitat_rod;
    wild_pokemon_entry dwild_data_grass[12];
    wild_pokemon_entry dwild_data_water[5];
    wild_pokemon_entry dwild_data_radar[5];
    wild_pokemon_entry dwild_data_rod[10];
    u32 trainer_prng_state;
    trainer_pokemon_custom_item_custom_attacks dynamic_trainer_party[3];
    u8 roamer_last_encountered;
    u8 start_menu_clock_oam_idxs[4];
    u8 tbox_idx_braille;
    u8 pc_selection_context;
    void *mega_state;
    void *trainer_ai_state2;
    void *battle_state2;
    u8 trainers_cnt; // How many trainers are approaching
    u8 current_trainer;
    u8 trainers_npc_idxs[2];
    u8 *trainers_scripts[2];
    trainer_variables trainer_varsB;
    u16 ally_trainer_idx;
    u8 ally_trainer_backsprite_idx;
    u8 ally_trainer_party_preview;
    u32 battle_handicaps;
    rtc_timestamp berry_tree_time_last_update; // When were berry trees last updated?
    u8 berry_tree_time_last_updated_initialized : 1;
    u32 gp_rng;
    u8 gold_candy_active : 1;
    u8 gold_candy_levels_remaining : 7;
    struct {
        color_t previous_filter;
        color_t current_filter;
        color_t target_filter;
        u8 filter_transition_step; // 16 Blending steps
        u8 filter_transition_delay;
        u8 filter_transition_delay_counter;
    } weather;

} floating_memory;



extern saveblock1 *save1;
extern saveblock2 *save2;
extern custom_memory cmem;
extern floating_memory fmem;

extern warp_save_t warp_recent; // Recent map, bank and positions (i.e. when transitioning)

#define SAVE_KEY_SPLASH_USED 0x1A
#define SAVE_KEY_EGGS_HATCHED 0xD

/**
 * Increments a stat in the save file (key)
 * @param key the stat to increment
 */
void save_increment_key(u8 key);

/**
 * Gets a stat in the save file (key)
 * @param key the stat to get
 * @return the stat value
 */
int save_get_key(u8 index);

/**
 * Hashes a sequence based on the temporal seed (changes after some time)
 * @param sequence the sequence to hash
 * @param size the size of the sequence
 * @return the hash value of the sequence with the current temporal seed
 */
u32 daily_events_hash(u32 seq[], size_t size);

/**
 * Updates the seed for the tmp hash system if the cycle (one day) has passed
 */
void daily_events_proceed();

/**
 * Randomly generates a new seed for the tmp hash system
 */
void daily_events_new_seed();

/**
 * Sets the surfing field in save1 to false
 **/
void save_set_player_non_surfing();

/**
 * Adds a certain amount of money to an encrypted variable.
 * @param dst the encrypted destination where the money is to be added.
 * @param value the amount to add.
 **/
void money_add(u32 *dst, u32 value);

/**
 * Gets the amount of money from an encrypted variable.
 * @param dst the encrypted variable
 * @return the amount of money
 **/
u32 money_get(u32 *dst);

/**
 * Sets the amount of money to an encrypted variable.
 * @param dst where to put the value
 * @param amount the amount to set
 **/
void money_set(u32 *dst, u32 amount);

#endif
