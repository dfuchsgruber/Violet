#ifndef H_MEGA
#define H_MEGA

#include "battle/battler.h"
#include "oam.h"
#include "constants/items.h"

#define MEGA_TRIGGER_TAG 0x134F
#define REGENT_TRIGGER_TAG 0x1350
#define MEGA_INDICATOR_TAG 0xA3A8

#define MEGA_EVOLUTION 1
#define REGENT_EVOLUTION 2

#define DEFAULT_KEYSTONE ITEM_MEGA_AMULETT

enum mega_trigger_state {
    MEGA_TRIGGER_SHOW,
    MEGA_TRIGGER_HIDE,
    MEGA_TRIGGER_IDLE
};

// These things are executed sequentially once mega evolution happens
enum mega_action_state {
    MEGA_ACTION_INITIALIZE,
    MEGA_ACTION_CHECK,
    MEGA_ACTION_CHECK_MEGA_EVOLUTION_PERFORMED, // This state is entered only after at least one mega evolution was performed
    MEGA_ACTION_BATTLE_ENTER_ABILITIES,
    MEGA_ACTION_INTIMIDATE,
    MEGA_ACTION_DONE,
};

typedef struct {
    u8 marked_for_mega_evolution[4]; // Stores the mega evolution types
    u8 owner_mega_evolved[4];
    u8 mega_action_state;
    u8 mega_action_current_slot;
} mega_state_t;

#define MEGA_STATE (*((mega_state_t*)(fmem.mega_state)))


typedef struct {
    u16 species;
    u16 mega_item;
    u16 mega_species;
    u16 type;
} mega_evolution_t;

/**
 * Returns the owner of a battler.
 * @param battler_idx the battler to check ownership of
 * @return the owner of the battler
 **/
u8 battler_get_owner(u8 battler_idx);

/** Gets the mega evolution a battler is able to perform.
 * @param battler_idx the idx of the battler
 * @return the mega evolution structure if any is possible
 **/
mega_evolution_t *battler_get_available_mega_evolution(u8 battler_idx);

/** Gets the oam idx of a mega trigger that affects a certain battler.
 * @param battler_idx the battler to affect. If 4 is given, any mega trigger will be found.
 * @return the oam idx of the mega trigger or 0x40 if none is present
 */
u8 mega_trigger_oam_idx_get(u8 battler_idx);

/**
 * Creates a mega trigger for a battler if the battler can perform mega evolution by either
 * spawning a new oam or recovering a mega trigger that is currently active (i.e. disappearing)
 * @param battler_idx the battler to create a trigger for
 **/
void mega_trigger_new(u8 battler_idx);

/**
 * Wrapper for the input handler that lets the player select a move
 **/
void _battle_controller_player_choose_move();


/**
 * Tries to execute mega evolutions for all battlers in turn order. That includes the transformation as well as battle enter abilities.
 * @return if a mega evolution is currently ongoing
 **/
bool battle_execute_action_mega_evolution();


/**
 * Get's the keystone a battler can interact with.
 * @param battler_idx the battler to mega evolve
 * @return the item idx of the keystone the battler interacts with
 **/
u16 battler_get_keystone(u8 battler_idx);

/**
 * Searches the mega evolution of a mega evolved species.
 * @param species the species of the mega evolved pokemon
 * @return the mega evolution associated with the mega species or NULL
 **/
mega_evolution_t *mega_evolution_get_by_mega_species(u16 species);


// ** OLD **

#define MEGA_ICON_TAG 0x134F
#define MEGA_CNT 6

typedef struct mega_table_entry {
    u16 species;
    u16 item;
    u16 target;
    u16 regent;

} mega_table_entry;

mega_table_entry megas[MEGA_CNT];

extern u8 *attack_anim_mega;
extern u8 *attack_anim_groudon;
extern u8 *attack_anim_kyogre;
extern u8 *attack_anim_rayquaza;

mega_table_entry *get_mega_if_can_mega_evolve(battler *b);

bool can_player_trigger_mega();
void* get_pokemon_offset_by_index(u8 index);
void battle_cb_do_megas();
mega_table_entry* get_mega_if_can_mega_evolve(battler *b);

void cb_mega_anim(u8 self);
extern void call_attack_anim_by_offset(u8 user_index, u8 unkown, u8* script);

u16 can_mega_evolve(battler *b);
mega_table_entry *get_mega_if_can_mega_evolve(battler *b);
void icon_callback(oam_object *self);
void mega_show_icon();

extern void restore_trigger_cbs();
void symbol_callback(oam_object *self);
void spawn_symbols(u8 state);

void spawn_trigger_cb();
void trigger_cb(u8 self);

void mega_disable_blurr(u8 slot);

u16 can_mega_evolve(battler *b);

void mega_oam_trigger_callback(oam_object *self);

#endif
