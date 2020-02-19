#ifndef H_MEGA
#define H_MEGA



#include "battle/battler.h"
#include "oam.h"

#define MEGA_TRIGGER_TAG 0x134F
#define REGENT_TRIGGER_TAG 0x1350

typedef struct {
    u8 marked_for_mega_evolution : 4; // Mark banks for executing a mega evolution
    u8 mega_evolution_performed : 4; // Mark banks if they executed a mega evolution
    u8 trigger_oam;
    u8 trigger_oam_removing : 1; // If set, currently a trigger is being removed
} mega_state_t;

#define MEGA_EVOLUTION 0
#define REGENT_EVOLUTION 1

typedef struct {
    u16 species;
    u16 mega_item;
    u16 mega_species;
    u16 type;
} mega_evolution_t;

/** Gets the mega evolution a battler is able to perform.
 * @param battler_idx the idx of the battler
 * @return the mega evolution structure if any is possible
 **/
mega_evolution_t *battler_get_available_mega_evolution(u8 battler_idx);


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
