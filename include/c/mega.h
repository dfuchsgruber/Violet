#ifndef H_MEGA
#define H_MEGA


#define MEGA_ICON_TAG 0x134F
#define MEGA_CNT 4

#include "battle/battler.h"
#include "oam.h"

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

#endif
