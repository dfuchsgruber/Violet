#ifndef H_TILE
#define H_TILE

#define DESERT_MAP 21
#define DESERT_BANK 3

#include <stdbool.h>

#include "anim_engine.h"
#include "oams.h"
#include "pokemon.h"

#define DIR_NONE 0
#define DIR_DOWN 1
#define DIR_UP 2
#define DIR_LEFT 3
#define DIR_RIGHT 4
#define DIR_DIANW 5
#define DIR_DIANE 6
#define DIR_DIASE 7
#define DIR_DIASW 8

#define FIELD_BEHAVIOR 0
#define FIELD_HM_USAGE 1


#define BEHAVIOR_SIDE_STAIR_WEST 0xB4
#define BEHAVIOR_SIDE_STAIR_EAST 0xB5

#define DIAG_NO 0x80
#define DIAG_SO 0x81
#define DIAG_SW 0x82
#define DIAG_NW 0x83

#define VAR_ASH 0x50D0
#define FLAG_ASHBAG 0x951

#define VAR_HATCHING_FASTENED_LEFT 0x50CE

typedef struct {
    s16 x;
    s16 y;
} coordinate;

typedef struct{
    u8 bank;
    u8 map;
    u8 triggered_by_behavior;
    bool apply_to_every_map;
    oam_template *temp;
    palette *pal;
    void (*init_func)();
}any_grass;

typedef struct bdata {
    u32 behavior : 9;
    u32 hm_usage : 5;
    u32 field_2 : 4;
    u32 field_3 : 6;
    u32 field_4 : 3;
    u32 field_5 : 2;
    u32 field_6 : 3;
    u32 field_7 : 1;

} bdata;

typedef union union_block_data {
    bdata data;
    u32 value;
} block_data;

typedef struct morgana_anim {
    u16 blocks[4];
    u16 walkfield;
} morgana_anim;


void do_fata_morgana();

void special_set_trashflag();
void generate_trash_item(u8 facing);
bool check_trashflag(u8 facing);
void set_trashflag(u8 facing);
int get_trash_hash_by_facing(u8 facing, int m);
int a_hash(s16 x, s16 y, u8 map, u8 bank, int m);
void new_a_vector();
u32 tile_get_field_by_pos(s16 x, s16 y, u8 field);
void ash_grass_step();

void load_tv_text();
u8 *get_tv_text();

coordinate *walking_directions = (coordinate*) 0x083A638C;

script cloud_trigger(bool back);
void cloud_enter();

void egg_warm_update();
bool pokemon_party_has_flamebody();
void pokemon_hatch_decrement(pokemon *p);

extern script script_cloud_none_ref;
extern script script_use_cloud_ref;
extern script script_use_cloud_back_ref;
extern script script_cloud_facings[5];
extern script script_cloud_force_ref[5];

#endif