#ifndef HSAVE
#define HSAVE

#include "types.h"
#include "map/header.h"
#include "dungeon/dungeon2.h"
#include "rtc.h"
#include "pokemon/virtual.h"
#include "pokemon/breeding.h"
#include "map/ceometria_gym.h"
#include "trainer/party.h"
#include "pokemon/roamer.h"
#include "overworld/npc.h"
#include "color.h"
#include "item/bag.h"

#define NUM_SECTORS 32
#define NUM_SECTORS_PER_SAVEFILE 14

#define SECTOR_SIZE 0x1000
#define SECTOR_SIZE_FOOTER 128
#define SECTOR_SIZE_DATA (SECTOR_SIZE - SECTOR_SIZE_FOOTER)

typedef struct {
    u16 offset;
    u16 size;
} save_section_locations_t;

extern const save_section_locations_t save_section_locations[NUM_SECTORS_PER_SAVEFILE];

typedef struct {
    u8 data[SECTOR_SIZE_DATA];
    u8 unused[SECTOR_SIZE_FOOTER - 12]; // Unused portion of the footer
    u16 id;
    u16 checksum;
    u32 signature;
    u32 counter;
} save_sector_t;

extern save_sector_t gp_save_sector_buffer;
extern save_sector_t *save_sector_buffer;

/**
 * Reads a sector from the flash
 * @param sector_id the id of the sector to read
 * @param buffer where to put the entire sector
 * @return unused
*/
bool read_flash_sector(u8 sector_id, save_sector_t *buffer);


typedef struct warp_save_t {
	u8 bank, map, exit, field_3;
	s16 x, y;
} warp_save_t;

typedef struct  {
    u8 name[7];
    u8 firmness;
    u16 size;
    u8 max_yield;
    u8 min_yield;
    const u8 * description_1;
    const u8 * description_2;
    u8 stage_duration;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 smoothness;
    u8 field_0x1b;
    u8 item_effect[18];
    u8 hold_effect;
    u8 hold_effect_parameter;
    u32 checksum;
} enigma_berry_t;

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
    u16 map_music_override; // Cleared when entering a new map
    u8 map_weather;
    u8 map_weather_cycle_idx; // Used on Route 119 initially, maybe we can have our own weather cycles in the jungle areas?
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
    /*0x0294*/ u16 coins;
    /*0x0296*/ u16 registered_item; // registered for use with SELECT button
    /*0x0298*/ bag_item_t pc_items[MAX_NUM_PC_ITEMS];
    /*0x0310*/ bag_item_t bag_pocket_items[MAX_NUM_BAG_ITEMS];
    /*0x03b8*/ bag_item_t bag_pocket_key_items[MAX_NUM_BAG_KEY_ITEMS];
    /*0x0430*/ bag_item_t bag_pocket_pokeballs[MAX_NUM_BAG_POKEBALLS];
    /*0x0464*/ bag_item_t bag_pocket_tm_hms[MAX_NUM_BAG_TM_HMS];
    /*0x054c*/ bag_item_t bag_pocket_berries[MAX_NUM_BAG_BERRIES];
    /*0x0638*/ u16 trainer_rematch_step_counter;
    /*0x063A*/ u8 ALIGNED(2) trainer_rematches[100];
    /*0x06A0*/ npc npcs[NUM_NPCS];
    // 0x8e0
    map_event_person persons[64];
    // 0x20E0
    u8 flags[288];
    u16 vars[256];
    u32 sav_keys[64]; // This is one of the whackest names for stuff I have so far... At one point this should be renamed to: game stat
    u16 dungeon_blocks[56 * 56]; // Previously questlog
    int dungeon_nodes[16][2];
    u8 tm_used_flags[16];
    bag_item_t bag_pocket_bait[MAX_NUM_BAG_BAIT];
    u8 questlog[112];
    u8 field_4864[80];
    u16 mail_words[2][9]; // Might be there are more than 2 mails
    u8 unknown_4[620];
    // 0x2F80
    daycare_stru daycare;
    u8 field_12444[52];
    roamer_state_t roamer;
    u8 roamer_old_overhead[12]; // 12 bytes were retrieved refactoring the old roamer
    enigma_berry_t enigma_berry;
    u8 field_12570[2936];
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
    u8 keys_switched; //original key swtiching
    // 0x14
    u8 text_speed : 3;
    u8 tbox_style : 5;
    u8 sound_is_mono : 1;
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
    u32 encryption_key;
} saveblock2;

#define PLAYER_TID (u32)(save2->tid_0 + (save2->tid_1 << 8) + (save2->tid_2 << 16) + (save2->tid_3 << 24))



typedef struct {
    u8 berry : 6;
    u8 yields_flower : 1; // if a lotus flower is yielded
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
    u8 healing_place_idx;
    u16 rod_equipped_bait[3];
    u32 money_backup;
    //trash memory (generall a vector memory)
    u8 trash_flags2[16];
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
    u8 shell_flags[16];
    u8 trash_flags[16];
    struct {
        u8 manual_hm_usage : 1;
        u8 dns_disabled : 1;
        u8 detector_notifications : 2;
        u8 wonder_dust_automatic_quantity_disabled : 1;
        // padding for future settings
        u8 item_obtaining_descriptions_disabled : 1;
        u8 start_menu_scanner_disabled;
        u8 field_2;
        u8 field_3; 
    } settings;
    bag_item_t __attribute__((aligned(4))) bag_pocket_medicine[MAX_NUM_BAG_MEDICINE];
    u16 bag_pocket;
    u16 pokedex_species;
    u8 pokedex_sorting;
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

extern saveblock1 *save1;
extern saveblock2 *save2;
extern EWRAM custom_memory csave;

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
