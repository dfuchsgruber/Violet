#ifndef HSAVE
#define HSAVE

#include "dungeon/dungeon2.h"
#include "pokepad/state.h"
#include "pokepad/pokedex/state.h"
#include "map/wild_pokemon.h"
#include "map/event.h"
#include "map/header.h"
#include "map/footer.h"
#include "pokepad/wondertrade.h"
#include "anim_engine.h"
#include "multichoice.h"
#include "trainerschool_test.h"
#include "rtc.h"
#include "ev_menu.h"
#include "pokemon/virtual.h"

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
    u8 unkown_1[0x8]; // probably also a warp save
    warp_save_t last_map; // ????
    warp_save_t healingplace;
    warp_save_t last_outdoor_map;
    u8 unkown[0x4];
    u8 flash_circle_size;
    u8 field_31;
    u16 current_footer_id;
    //0x34
    u8 unkown_2[0x8AC];
    map_event_person persons[256];
    //TODO


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
    u8 tbox_style;
    u8 sound_state : 1;
    u8 unkown_2 : 7;
    u8 unkown_3[0x2];
    u8 unkown_4[0x4];
    pid_t icognito_pid;
    // 0x20
    pid_t pandir_pid;
    u8 unkown_5[0x4];
    u8 pokedex_caught_flags[0x34]; //416 flags
    u8 pokedex_seen_flags[0x34]; //416 flags
} saveblock2;

typedef struct custom_memory {
    u8 flag_extension[0x80]; //additional 0x400 flags (0x900-0xD00)
    u8 pokedex_seen_extension[0x40]; //additional 512 flags
    u8 pokedex_caught_extension[0x40]; //additional 512 flags
    u8 gp_freespace[0x100];
    u16 var_extension[0x100]; //Additional 256 vars (0x5000-0x50FF)
    u8 dungeon_flags[0x10]; // mapheader dmapheader (part I)
    u8 unused0[0xC]; // mapheader dmapheader (part II);
    u8 unused1[0x1C]; // mapfooter dmapfooter;
    
    //Dungeon Memory I
    u8 unused2[0x14]; // wild_pokemon_data dwild_data;
    u8 unused3[0x8]; // dwild_habitat_grass;
    u8 unused4[0x8]; // wild_pokemon_habitat dwild_habitat_water;
    u8 unused5[0x8]; // wild_pokemon_habitat dwild_habitat_rod;
    u8 unused6[0x8]; // wild_pokemon_habitat dwild_habitat_radar;
    u8 unused7[0xC]; // Deprecated (0x30 bytes)
    u8 unused8[0x14]; // map_events devents;
    u8 unused9[0x10]; // map_event_warp ladder;
    u8 unused10[0x18 * 5]; // map_event_person dpers[5];
    
    //trash memory (generall a vector memory)
    u8 trash_flags[16];
    rtc_timestamp a_gen_time;
    u32 tmp_hash_seed;
    rtc_timestamp fossil_gen_time;
    u8 any_tmp_flags[16];
    map_event_person pokeradar_person;
    
    //Dungeon Memory II
    dungeon_generator2 dg2;
    // wild_pokemon_entry dwild_data_grass[12];
    // wild_pokemon_entry dwild_data_water[5];
    // wild_pokemon_entry dwild_data_rod[10];
    // wild_pokemon_entry dwild_data_radar[5];

} custom_memory;

#define DMAP_PERSONS 25
#define DMAP_WARPS 1

typedef struct {
    u8 dmap_header_initialized : 1;
    u8 dmap_blocks_initialized : 1;
    u8 dmap_unused : 6;
    u8 battle_bg_index;
    u8 unused_2;
    u8 unused_3;
    pokepad_memory *pad_mem;
    wondertrade_memory *wtrade_mem;
    pokedex_memory *dex_mem;
    void *fp_mem;
    ev_menu_state_stru *ev_menu_state;
    u8 *additional_levelscript_4;
    u16 dmart[32]; //max 32 items per mart
    ae_memory *ae_mem;
    tileset *current_tileset_1;
    tileset *current_tileset_2;
    u8 dma0_dump[4];
    int gp_stack_size;
    int gp_stack[GP_STACK_SIZE];
    int battle_custom_status[4];
    u8 mugshot_oam_id;
    u8 mugshot_tb_id;
    multichoice_t dynamic_choice;
    u16 tile_anim_clks_0[8];
    u16 tile_anim_clks_1[8];
    trainerschool_test_memory *tst_mem;
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
    
} floating_memory;

extern saveblock1 *save1;
extern saveblock2 *save2;
extern custom_memory cmem;
extern floating_memory fmem;

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
u32 tmp_hash(u32 seq[], size_t size);

/**
 * Updates the seed for the tmp hash system if the cycle (one day) has passed
 */
void tmp_hash_update_seed();

/**
 * Randomly generates a new seed for the tmp hash system
 */
void tmp_hash_new_seed();

#endif
