#ifndef H_POKEMON
#define H_POKEMON

#include "types.h"
#include "stdbool.h"
#include "oams.h"
#include "evolution.h"
#include "abilities.h"

#define POKEMON_CNT 0x1B9

#define LANGUAGE_JAP 0x201
#define LANGUAGE_ENG 0x202
#define LANGUAGE_FRA 0x203
#define LANGUAGE_ITA 0x204
#define LANGUAGE_GER 0x205
#define LANGUAGE_KOR 0x206
#define LANGUAGE_ESP 0x207

#define NATURE_ROBUST 0 //+a-a
#define NATURE_SOLO 1 //+a-d
#define NATURE_MUTIG 2 //+a-i
#define NATURE_HART 3 //+a-sa
#define NATURE_FRECH 4 //+a-sd
#define NATURE_KUEHN 5 //+v-a
#define NATURE_SANFT 6
#define NATURE_LOCKER 7
#define NATURE_PFIFFIG 8
#define NATURE_LASCH 9
#define NATURE_SCHEU 10
#define NATURE_HASTIG 11
#define NATURE_ERNST 12
#define NATURE_FROH 13
#define NATURE_NAIV 14
#define NATURE_MAESSIG 15
#define NATURE_MILD 16
#define NATURE_RUHIG 17
#define NATURE_ZAGHAFT 18
#define NATURE_HITZIG 19
#define NATURE_STILL 20
#define NATURE_ZART 21
#define NATURE_FORSCH 22
#define NATURE_SACHT 23
#define NATURE_KAUZIG 24

#define ATTRIBUTE_PID 0
#define ATTRIBUTE_TID 1
#define ATTRIBUTE_NICKNAME 2
#define ATTRIBUTE_LANGUAGE 3
#define ATTRIBUTE_SANITY_0 4
#define ATTRIBUTE_SANITY_1 5
#define ATTRIBUTE_SANITY_2 6
#define ATTRIBUTE_OT_NAME 7
#define ATTRIBUTE_MARKINGS 8
#define ATTRIBUTE_CHECKSUM 9
#define ATTRIBUTE_FILLER 0xA
#define ATTRIBUTE_SPECIES 0xB
#define ATTRIBUTE_ITEM 0xC
#define ATTRIBUTE_ATTACK1 0xD
#define ATTRIBUTE_ATTACK2 0xE
#define ATTRIBUTE_ATTACK3 0xF
#define ATTRIBUTE_ATTACK4 0x10
#define ATTRIBUTE_PP1 0x11
#define ATTRIBUTE_PP2 0x12
#define ATTRIBUTE_PP3 0x13
#define ATTRIBUTE_PP4 0x14
#define ATTRIBUTE_PP_BONUSES 0x15
#define ATTRIBUTE_COOLNESS 0x16
#define ATTRIBUTE_BEAUTY 0x17
#define ATTRIBUTE_CUTENESS 0x18
#define ATTRIBUTE_EXP 0x19
#define ATTRIBUTE_HP_EV 0x1A
#define ATTRIBUTE_ATT_EV 0x1B
#define ATTRIBUTE_DEF_EV 0x1C
#define ATTRIBUTE_INIT_EV 0x1D
#define ATTRIBUTE_SATT_EV 0x1E
#define ATTRIBUTE_SDEF_EV 0x1F
#define ATTRIBUTE_HAPPINESS 0x20
#define ATTRIBUTE_SMARTNESS 0x21
#define ATTRIBUTE_POKERUS 0x22
#define ATTRIBUTE_CATCH_LOCATION 0x23
#define ATTRIBUTE_CATCH_LEVEL 0x24
#define ATTRIBUTE_U0 0x25
#define ATTRIBUTE_CATCH_INFO 0x26
#define ATTRIBUTE_HP_IV 0x27
#define ATTRIBUTE_ATT_IV 0x28
#define ATTRIBUTE_DEF_IV 0x29
#define ATTRIBUTE_INIT_IV 0x2A
#define ATTRIBUTE_SATT_IV 0x2B
#define ATTRIBUTE_SDEF_IV 0x2C
#define ATTRIBUTE_IS_EGG 0x2D
#define ATTRIBUTE_ABILITY 0x2E
#define ATTRIBUTE_TOUGHNESS 0x2F
#define ATTRIBUTE_SHEEN 0x30
#define ATTRIBUTE_U1 0x31
#define ATTRIBUTE_U2 0x32
#define ATTRIBUTE_U3 0x33
#define ATTRIBUTE_U4 0x34
#define ATTRIBUTE_U5 0x35
#define ATTRIBUTE_U6 0x36
#define ATTRIBUTE_STATUS 0x37
#define ATTRIBUTE_LEVEL 0x38
#define ATTRIBUTE_CURRENT_HP 0x39
#define ATTRIBUTE_TOTAL_HP 0x3A
#define ATTRIBUTE_ATK 0x3B
#define ATTRIBUTE_DEF 0x3C
#define ATTRIBUTE_INIT 0x3D
#define ATTRIBUTE_SATK 0x3E
#define ATTRIBUTE_SDEF 0x3F
#define ATTRIBUTE_SPECIES2 0x41

typedef struct marking {
    u8 circle : 1;
    u8 square : 1;
    u8 triangle : 1;
    u8 heart : 1;
    u8 padding : 4;
} marking;

typedef union {
    u32 value;

    struct {
        u32 ability : 1;
        u32 gender_partial : 7;
        u32 shinyness : 16;
        u32 nature : 5;
        u32 form : 3;
    } fields;
} pid;

typedef struct pokemon {
    pid pid;
    u32 tid;
    u8 nickname [10];
    u16 language;
    u8 ot_name [7];
    marking markings;
    u16 checksum;
    u16 padding;
    u16 encrypted_substructure [24];
    u32 status_condition;
    u8 level;
    u8 pokerus_remaining_byte;
    u16 current_hp;
    u16 total_hp;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 sattack;
    u16 sdefense;

} pokemon;

typedef struct {
    u16 move_id : 9;
    u16 level : 7;
} pokemon_move;



pokemon_move *pokemon_moves[POKEMON_CNT];

pokemon *player_pokemon = (pokemon*) 0x02024284;
pokemon *opponent_pokemon = (pokemon*) 0x0202402C;

void outdoor_move_buffer_load(pokemon *pokemon, u8 index);
void pokemon_load_name_as_string(pokemon *pokemon, u8 *buffer);
void pokemon_new(pokemon *space, u16 species, u8 level, u8 ev_split,
        bool pid_determined, pid pid, bool tid_determined, u32 tid);
u8 pokemon_get_egg_moves(pokemon *p, u16 *space); //returns cnt (max 10, requires 10 space)
u16 pokemon_append_attack(pokemon *p, u16 attack);
void pokemon_rotate_and_push_attack(pokemon *p, u16 attack);
void pokemon_spawn_by_algorithm_generate_ivs(bool *iv_det, int seed);
void pokemon_spawn_by_seed_algorithm(pokemon *p, u16 species, u8 level, u8 ev_spread, bool tid_determined, u32 tid, u16(*seed_generator)());

u8 get_pokemons_ability(pokemon *poke);
u8 write_ability_into_dbuf(pokemon *poke);

graphic pokemon_frontsprites[POKEMON_CNT];
graphic pokemon_backsprites[POKEMON_CNT];
palette pokemon_pals[POKEMON_CNT];
palette pokemon_shiny_pals[POKEMON_CNT];
u8 pokemon_icon_usage[POKEMON_CNT];
pokemon_move *pokemon_moves[POKEMON_CNT];
u8 pokemon_tm_compatibility [POKEMON_CNT][8];
const void *pokemon_icons[POKEMON_CNT];
u32 pokemon_player_y[POKEMON_CNT];
u8 pokemon_altitude[POKEMON_CNT];
u32 pokemon_enemy_y[POKEMON_CNT];
u8 pokemon_item_animations[POKEMON_CNT][5];
u32 pokemon_tutor_compatibility[POKEMON_CNT];

pokemon_evolution pokemon_evolutions[POKEMON_CNT][5];

void special_heal_team_index();
void pokemon_team_remove();
void pokemon_team_knows_hm();
bool pokemon_knows_hm(pokemon *p);

u8 pokemon_get_nature(pokemon *target);

#endif
