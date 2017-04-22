#ifndef H_TRAINER
#define H_TRAINER

#include "pokemon.h"
#include "types.h"
#include "stdbool.h"


#define TRAINER_CNT 0x2E8

#define FLAG_IS_FRACTION_CHOSEN 0x925
#define FLAG_IS_REVOLUTION_FRACTION 0x926

#define TRAINERCLASS_PKMN_TRAINER 0x0
#define TRAINERCLASS_PKMN_TRAINER2 0x1
#define TRAINERCLASS_POLIZIST 0x2
#define TRAINERCLASS_REVOLUTIONAER 0x3
#define TRAINERCLASS_AROMALADY 0x4
#define TRAINERCLASS_RUINENMANIAC 0x5
#define TRAINERCLASS_FORSCHERIN 0x6
#define TRAINERCLASS_PLANSCHER 0x7
#define TRAINERCLASS_PLANSCHER2 0x8
#define TRAINERCLASS_ASS_TRAINER 0x9
#define TRAINERCLASS_HEXE 0xa
#define TRAINERCLASS_LADY 0xb
#define TRAINERCLASS_SCHOENHEIT 0xc
#define TRAINERCLASS_SCHNOESEL 0xd
#define TRAINERCLASS_POKEMANIAC 0xe
#define TRAINERCLASS_SCHWIMMER 0xf
#define TRAINERCLASS_SCHWARZGURT 0x10
#define TRAINERCLASS_GITARRIST 0x11
#define TRAINERCLASS_HITZKOPF 0x12
#define TRAINERCLASS_CAMPER 0x13
#define TRAINERCLASS_KAEFERMANIAC 0x14
#define TRAINERCLASS_PSYCHO 0x15
#define TRAINERCLASS_GENTLEMAN 0x16
#define TRAINERCLASS_TOP_VIER 0x17
#define TRAINERCLASS_LEITERALD 0x18
#define TRAINERCLASS_SCHULKIND 0x19
#define TRAINERCLASS_SEN_AND_JUN 0x1a
#define TRAINERCLASS_POKEFAN 0x1b
#define TRAINERCLASS_EXPERTE 0x1c
#define TRAINERCLASS_TEENAGER 0x1d
#define TRAINERCLASS_CHAMP 0x1e
#define TRAINERCLASS_ANGLER 0x1f
#define TRAINERCLASS_TRIATHLET 0x20
#define TRAINERCLASS_DRACHENPROFI 0x21
#define TRAINERCLASS_VOGELFAENGER 0x22
#define TRAINERCLASS_NINJAJUNGE 0x23
#define TRAINERCLASS_KAEMPFERIN 0x24
#define TRAINERCLASS_SCHIRMDAME 0x25
#define TRAINERCLASS_SCHWIMMERIN 0x26
#define TRAINERCLASS_PICKNICKER 0x27
#define TRAINERCLASS_ZWIL 0x28
#define TRAINERCLASS_MATROSE 0x29
#define TRAINERCLASS_SNOWBOARDER 0x2a
#define TRAINERCLASS_PKMN_SAMMLER 0x2b
#define TRAINERCLASS_PKMN_TRAINER4 0x2c
#define TRAINERCLASS_PKMN_ZUECHTER 0x2d
#define TRAINERCLASS_PKMN_RANGER 0x2e
#define TRAINERCLASS_MAGMA_BOSS 0x2f
#define TRAINERCLASS_TEAM_MAGMA 0x30
#define TRAINERCLASS_GOERE 0x31
#define TRAINERCLASS_KAEFERSAMMLER 0x32
#define TRAINERCLASS_PICKNICKER3 0x33
#define TRAINERCLASS_JUNGES_GLUECK 0x34
#define TRAINERCLASS_ALTES_PAAR 0x35
#define TRAINERCLASS_GESCHWISTER 0x36
#define TRAINERCLASS_WOLKENREITER 0x37
#define TRAINERCLASS_VIOLET_VORS 0x38
#define TRAINERCLASS_TEENAGER2 0x39
#define TRAINERCLASS_KAEFERSAMMLER2 0x3a
#define TRAINERCLASS_GOERE2 0x3b
#define TRAINERCLASS_MATROSE2 0x3c
#define TRAINERCLASS_CAMPER2 0x3d
#define TRAINERCLASS_PICKNICKER2 0x3e
#define TRAINERCLASS_POKEMANIAC2 0x3f
#define TRAINERCLASS_STREBER 0x40
#define TRAINERCLASS_WANDERER 0x41
#define TRAINERCLASS_BIKER 0x42
#define TRAINERCLASS_DIEB 0x43
#define TRAINERCLASS_MECHANIKER 0x44
#define TRAINERCLASS_ANGLER3 0x45
#define TRAINERCLASS_SCHWIMMER2 0x46
#define TRAINERCLASS_GLATZKOPF 0x47
#define TRAINERCLASS_SPIELER 0x48
#define TRAINERCLASS_SCHOENHEIT2 0x49
#define TRAINERCLASS_SCHWIMMERIN2 0x4a
#define TRAINERCLASS_PSYCHO2 0x4b
#define TRAINERCLASS_ROCKER 0x4c
#define TRAINERCLASS_JONGLEUR 0x4d
#define TRAINERCLASS_DOMPTEUR 0x4e
#define TRAINERCLASS_VOGELFAENGER2 0x4f
#define TRAINERCLASS_SCHWARZGURT2 0x50
#define TRAINERCLASS_RIVALE 0x51
#define TRAINERCLASS_FORSCHER 0x52
#define TRAINERCLASS_BOSS 0x53
#define TRAINERCLASS_ARENALEITER 0x54
#define TRAINERCLASS_TEAM_VIOLET 0x55
#define TRAINERCLASS_ASS_TRAINER2 0x56
#define TRAINERCLASS_TOP_VIER2 0x57
#define TRAINERCLASS_GENTLEMAN2 0x58
#define TRAINERCLASS_RIVALE2 0x59
#define TRAINERCLASS_CHAMP2 0x5a
#define TRAINERCLASS_EXORZISTIN 0x5b
#define TRAINERCLASS_ZWIL2 0x5c
#define TRAINERCLASS_PRIMAPAAR 0x5d
#define TRAINERCLASS_JUNGES_GLUECK2 0x5e
#define TRAINERCLASS_MUEHLENSIPPE 0x5f
#define TRAINERCLASS_GESCHWISTER2 0x60
#define TRAINERCLASS_PKMN_PROF 0x61
#define TRAINERCLASS_SPIELER2 0x62
#define TRAINERCLASS_MUEHLENMAEDEL 0x63
#define TRAINERCLASS_PLANSCHER3 0x64
#define TRAINERCLASS_PKMN_ZUECHTER2 0x65
#define TRAINERCLASS_PKMN_RANGER2 0x66
#define TRAINERCLASS_AROMALADY2 0x67
#define TRAINERCLASS_RUINENMANIAC2 0x68
#define TRAINERCLASS_LADY2 0x69
#define TRAINERCLASS_MALERIN 0x6a

#define TRAINER_AI_STRATEGY_NONE 0
#define TRAINER_AI_NO_EFFECTLESS_OR_NEGATIVE_EFFECTS (1 << 0)
#define TRAINER_AI_VARIABILITY (1 << 1)
#define TRAINER_AI_SUPER_EFFECTIVE (1 << 2)
#define TRAINER_AI_STATUS_MOVES_PREFERED_IN_FIRST_ROUND (1 << 3)
#define TRAINER_AI_PREFER_CERTAIN_MOVES (1 << 4)
#define TRAINER_AI_PREFER_NO_DAMAGE_MOVES (1 << 5)
#define TRAINER_AI_PREFER_NO_DAMAGE_MOVES_IF_OTHER_POKEMON_IN_PARTY (1 << 6)
#define TRAINER_AI_CONSIDER_PERECNTUAL_HP (1 << 8)
#define TRAINER_AI_FLEE (1 << 29)
#define TRAINER_AI_SAFARI_ZONE (1 << 30)
#define TRAINER_AI_FLEE_IF_HP_LOW (1 << 31)

#define TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(build, ability_bit, hidden_ability, shiny, level, species)\
{\
        {build, ability_bit, hidden_ability, shiny}, \
        0x0,\
        level,\
        0,\
        species,\
         0x0 \
}

#define TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(build, ability_bit, hidden_ability, shiny, level, species, item)\
{\
        {build, ability_bit, hidden_ability, shiny}, \
        0x0,\
        level,\
        0,\
        species,\
        item\
}

#define TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(build, ability_bit, hidden_ability, shiny, level, species, move0, move1, move2, move3)\
{\
        {build, ability_bit, hidden_ability, shiny}, \
        0x0,\
        level,\
        0,\
        species,\
        {move0, move1, move2, move3},\
        0x0\
}

#define TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(build, ability_bit, hidden_ability, shiny, level, species, item, move0, move1, move2, move3)\
{\
        {build, ability_bit, hidden_ability, shiny}, \
        0x0,\
        level,\
        0,\
        species,\
        item,\
        {move0, move1, move2, move3}\
}

typedef struct build_field {
    u8 build : 5;
    u8 ability : 1;
    u8 hability : 1;
    u8 shinyness : 1;

} build_field;




typedef struct {
    build_field build;
    u8 field_1;
    u8 level;
    u8 field_3;
    u16 species;
    u16 field_6;
} trainer_pokemon_default_item_default_attacks;

typedef struct {
    build_field build;
    u8 field_1;
    u8 level;
    u8 field_3;
    u16 species;
    u16 item;
} trainer_pokemon_custom_item_default_attacks;

typedef struct {
    build_field build;
    u8 field_1;
    u8 level;
    u8 field_3;
    u16 species;
    u16 moves[4];
    u16 field_6;
} trainer_pokemon_default_item_custom_attacks;

typedef struct {
    build_field build;
    u8 field_1;
    u8 level;
    u8 field_3;
    u16 species;
    u16 item;
    u16 moves[4];
} trainer_pokemon_custom_item_custom_attacks;

typedef union{
    trainer_pokemon_default_item_default_attacks default_item_default_attacks;
    trainer_pokemon_custom_item_default_attacks custom_item_default_attacks;
    trainer_pokemon_default_item_custom_attacks default_item_custom_attacks;
    trainer_pokemon_custom_item_custom_attacks custom_item_custom_attacks;
} trainer_pokemon;

typedef struct {
    u8 uses_custom_moves : 1;
    u8 uses_custom_items : 1;
    u8 field_0_filler : 6;
    u8 trainerclass;

    struct encounter_and_gender {
        u8 encounter : 7;
        u8 gender : 1;
    } encounter_and_gender;
    u8 sprite;
    u8 name[12];
    u16 items[4];
    int is_dual_battle;
    u16 ai;
    u16 field_1E;
    u8 pokemon_cnt;
    u8 field_21;
    u8 field_22;
    u8 field_23;
    trainer_pokemon *party;

} trainer;


typedef struct build {
    u8 nature : 5;
    u8 evs[6];
    u16 prefered_item;
} build;

union union_build_field {
    u8 value;
    build_field bitfield;
};

typedef struct trainer_items {
    u16 items[4];
    u8 cnt;

} trainer_items;

typedef struct trainer_variables {
    u16 kind_of_battle;
    u16 trainer_id;
    u16 overworld_target;
    u16 padding;
    pstring *challange_text;
    pstring *defeat_text;
    u16 trainer_var_0;
    u16 trainer_var_1;
    script *script_later;
    script *script_continue;
    u16 reserved_word_xse;

} trainer_variables;


trainer trainers [TRAINER_CNT];
trainer_variables *trainer_vars = (trainer_variables*) 0x020386AC;

void build_trainer_poke(union union_build_field field, pokemon *poke);

void load_trainer_items(trainer_items *t_items);

bool checktrainerflag(u16 trainer_id);
bool trainer_can_npc_challange_player(u16 trainer_id);
bool special_x36_check_loaded_trainerflag();
void special_prepeare_player_facing();


//Trainer parties
trainer_pokemon_default_item_default_attacks trainer_party_x0[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1[1];
trainer_pokemon_default_item_default_attacks trainer_party_x2[1];
trainer_pokemon_default_item_default_attacks trainer_party_x3[1];
trainer_pokemon_default_item_default_attacks trainer_party_x4[1];
trainer_pokemon_default_item_default_attacks trainer_party_x5[2];
trainer_pokemon_default_item_default_attacks trainer_party_x6[2];
trainer_pokemon_default_item_default_attacks trainer_party_x7[4];
trainer_pokemon_default_item_default_attacks trainer_party_x8[2];
trainer_pokemon_default_item_default_attacks trainer_party_x9[2];
trainer_pokemon_default_item_default_attacks trainer_party_xa[2];
trainer_pokemon_default_item_default_attacks trainer_party_xb[3];
trainer_pokemon_default_item_default_attacks trainer_party_xc[3];
trainer_pokemon_default_item_default_attacks trainer_party_xd[2];
trainer_pokemon_default_item_default_attacks trainer_party_xe[3];
trainer_pokemon_default_item_default_attacks trainer_party_xf[2];
trainer_pokemon_default_item_default_attacks trainer_party_x10[2];
trainer_pokemon_default_item_default_attacks trainer_party_x11[3];
trainer_pokemon_default_item_default_attacks trainer_party_x12[2];
trainer_pokemon_default_item_default_attacks trainer_party_x13[2];
trainer_pokemon_default_item_default_attacks trainer_party_x14[2];
trainer_pokemon_default_item_default_attacks trainer_party_x15[1];
trainer_pokemon_default_item_default_attacks trainer_party_x16[3];
trainer_pokemon_default_item_default_attacks trainer_party_x17[2];
trainer_pokemon_default_item_default_attacks trainer_party_x18[2];
trainer_pokemon_default_item_default_attacks trainer_party_x19[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1b[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1c[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1e[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x20[2];
trainer_pokemon_default_item_default_attacks trainer_party_x21[3];
trainer_pokemon_default_item_default_attacks trainer_party_x22[4];
trainer_pokemon_custom_item_custom_attacks trainer_party_x23[4];
trainer_pokemon_default_item_default_attacks trainer_party_x24[2];
trainer_pokemon_default_item_default_attacks trainer_party_x25[3];
trainer_pokemon_default_item_default_attacks trainer_party_x26[3];
trainer_pokemon_default_item_default_attacks trainer_party_x27[3];
trainer_pokemon_default_item_default_attacks trainer_party_x28[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x29[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2a[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2b[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2d[4];
trainer_pokemon_default_item_default_attacks trainer_party_x2e[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x30[4];
trainer_pokemon_default_item_default_attacks trainer_party_x31[2];
trainer_pokemon_default_item_default_attacks trainer_party_x32[2];
trainer_pokemon_default_item_default_attacks trainer_party_x33[2];
trainer_pokemon_default_item_default_attacks trainer_party_x34[2];
trainer_pokemon_default_item_default_attacks trainer_party_x35[2];
trainer_pokemon_default_item_default_attacks trainer_party_x36[3];
trainer_pokemon_default_item_default_attacks trainer_party_x37[3];
trainer_pokemon_default_item_default_attacks trainer_party_x38[5];
trainer_pokemon_default_item_default_attacks trainer_party_x39[1];
trainer_pokemon_default_item_default_attacks trainer_party_x3a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x3b[4];
trainer_pokemon_default_item_default_attacks trainer_party_x3c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x3d[3];
trainer_pokemon_default_item_default_attacks trainer_party_x3e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x3f[1];
trainer_pokemon_default_item_default_attacks trainer_party_x40[5];
trainer_pokemon_default_item_default_attacks trainer_party_x41[2];
trainer_pokemon_default_item_default_attacks trainer_party_x42[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x43[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x44[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x45[3];
trainer_pokemon_default_item_default_attacks trainer_party_x46[2];
trainer_pokemon_default_item_default_attacks trainer_party_x47[2];
trainer_pokemon_default_item_default_attacks trainer_party_x48[2];
trainer_pokemon_default_item_default_attacks trainer_party_x49[2];
trainer_pokemon_default_item_default_attacks trainer_party_x4a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x4b[2];
trainer_pokemon_custom_item_custom_attacks trainer_party_x4c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x4d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x4e[1];
trainer_pokemon_default_item_default_attacks trainer_party_x4f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x50[3];
trainer_pokemon_default_item_default_attacks trainer_party_x51[2];
trainer_pokemon_default_item_default_attacks trainer_party_x52[1];
trainer_pokemon_default_item_default_attacks trainer_party_x53[2];
trainer_pokemon_default_item_default_attacks trainer_party_x54[3];
trainer_pokemon_default_item_default_attacks trainer_party_x55[2];
trainer_pokemon_default_item_default_attacks trainer_party_x56[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x57[1];
trainer_pokemon_default_item_default_attacks trainer_party_x58[4];
trainer_pokemon_default_item_default_attacks trainer_party_x59[2];
trainer_pokemon_default_item_default_attacks trainer_party_x5a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x5b[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_x5c[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_x5d[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_x5e[3];
trainer_pokemon_default_item_default_attacks trainer_party_x5f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x60[2];
trainer_pokemon_default_item_default_attacks trainer_party_x61[5];
trainer_pokemon_default_item_default_attacks trainer_party_x62[2];
trainer_pokemon_default_item_default_attacks trainer_party_x63[3];
trainer_pokemon_default_item_default_attacks trainer_party_x64[2];
trainer_pokemon_default_item_default_attacks trainer_party_x65[2];
trainer_pokemon_default_item_default_attacks trainer_party_x66[2];
trainer_pokemon_default_item_default_attacks trainer_party_x67[3];
trainer_pokemon_default_item_default_attacks trainer_party_x68[1];
trainer_pokemon_default_item_default_attacks trainer_party_x69[3];
trainer_pokemon_default_item_default_attacks trainer_party_x6a[4];
trainer_pokemon_default_item_default_attacks trainer_party_x6b[2];
trainer_pokemon_default_item_default_attacks trainer_party_x6c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x6d[3];
trainer_pokemon_default_item_default_attacks trainer_party_x6e[4];
trainer_pokemon_default_item_default_attacks trainer_party_x6f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x70[1];
trainer_pokemon_default_item_default_attacks trainer_party_x71[3];
trainer_pokemon_default_item_default_attacks trainer_party_x72[2];
trainer_pokemon_default_item_default_attacks trainer_party_x73[3];
trainer_pokemon_default_item_default_attacks trainer_party_x74[3];
trainer_pokemon_default_item_default_attacks trainer_party_x75[2];
trainer_pokemon_default_item_default_attacks trainer_party_x76[3];
trainer_pokemon_default_item_default_attacks trainer_party_x77[2];
trainer_pokemon_default_item_default_attacks trainer_party_x78[2];
trainer_pokemon_default_item_default_attacks trainer_party_x79[1];
trainer_pokemon_default_item_default_attacks trainer_party_x7a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x7b[3];
trainer_pokemon_default_item_default_attacks trainer_party_x7c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x7d[3];
trainer_pokemon_default_item_default_attacks trainer_party_x7e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x7f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x80[2];
trainer_pokemon_default_item_default_attacks trainer_party_x81[1];
trainer_pokemon_default_item_default_attacks trainer_party_x82[3];
trainer_pokemon_default_item_default_attacks trainer_party_x83[1];
trainer_pokemon_default_item_default_attacks trainer_party_x84[6];
trainer_pokemon_default_item_default_attacks trainer_party_x85[2];
trainer_pokemon_default_item_default_attacks trainer_party_x86[2];
trainer_pokemon_default_item_default_attacks trainer_party_x87[3];
trainer_pokemon_default_item_default_attacks trainer_party_x88[2];
trainer_pokemon_default_item_default_attacks trainer_party_x89[2];
trainer_pokemon_default_item_default_attacks trainer_party_x8a[1];
trainer_pokemon_default_item_default_attacks trainer_party_x8b[2];
trainer_pokemon_default_item_default_attacks trainer_party_x8c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x8d[3];
trainer_pokemon_default_item_default_attacks trainer_party_x8e[1];
trainer_pokemon_default_item_default_attacks trainer_party_x8f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x90[1];
trainer_pokemon_default_item_default_attacks trainer_party_x91[3];
trainer_pokemon_default_item_default_attacks trainer_party_x92[2];
trainer_pokemon_default_item_default_attacks trainer_party_x93[3];
trainer_pokemon_default_item_default_attacks trainer_party_x94[2];
trainer_pokemon_default_item_default_attacks trainer_party_x95[4];
trainer_pokemon_default_item_default_attacks trainer_party_x96[1];
trainer_pokemon_default_item_default_attacks trainer_party_x97[2];
trainer_pokemon_default_item_default_attacks trainer_party_x98[3];
trainer_pokemon_default_item_default_attacks trainer_party_x99[2];
trainer_pokemon_default_item_default_attacks trainer_party_x9a[4];
trainer_pokemon_default_item_default_attacks trainer_party_x9b[1];
trainer_pokemon_default_item_default_attacks trainer_party_x9c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x9d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x9e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x9f[6];
trainer_pokemon_default_item_default_attacks trainer_party_xa0[2];
trainer_pokemon_default_item_default_attacks trainer_party_xa1[4];
trainer_pokemon_default_item_default_attacks trainer_party_xa2[2];
trainer_pokemon_default_item_default_attacks trainer_party_xa3[2];
trainer_pokemon_default_item_default_attacks trainer_party_xa4[3];
trainer_pokemon_default_item_default_attacks trainer_party_xa5[2];
trainer_pokemon_default_item_default_attacks trainer_party_xa6[1];
trainer_pokemon_default_item_custom_attacks trainer_party_xa7[2];
trainer_pokemon_default_item_default_attacks trainer_party_xa8[1];
trainer_pokemon_default_item_default_attacks trainer_party_xa9[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_xaa[1];
trainer_pokemon_default_item_default_attacks trainer_party_xab[4];
trainer_pokemon_default_item_default_attacks trainer_party_xac[3];
trainer_pokemon_default_item_default_attacks trainer_party_xad[3];
trainer_pokemon_default_item_default_attacks trainer_party_xae[3];
trainer_pokemon_default_item_default_attacks trainer_party_xaf[2];
trainer_pokemon_default_item_default_attacks trainer_party_xb0[2];
trainer_pokemon_default_item_default_attacks trainer_party_xb1[3];
trainer_pokemon_default_item_default_attacks trainer_party_xb2[4];
trainer_pokemon_default_item_default_attacks trainer_party_xb3[1];
trainer_pokemon_default_item_default_attacks trainer_party_xb4[2];
trainer_pokemon_default_item_default_attacks trainer_party_xb5[3];
trainer_pokemon_default_item_default_attacks trainer_party_xb6[2];
trainer_pokemon_default_item_default_attacks trainer_party_xb7[4];
trainer_pokemon_default_item_default_attacks trainer_party_xb8[1];
trainer_pokemon_default_item_default_attacks trainer_party_xb9[2];
trainer_pokemon_default_item_default_attacks trainer_party_xba[3];
trainer_pokemon_default_item_custom_attacks trainer_party_xbb[2];
trainer_pokemon_default_item_default_attacks trainer_party_xbc[2];
trainer_pokemon_default_item_default_attacks trainer_party_xbd[3];
trainer_pokemon_default_item_default_attacks trainer_party_xbe[1];
trainer_pokemon_default_item_default_attacks trainer_party_xbf[4];
trainer_pokemon_default_item_default_attacks trainer_party_xc0[4];
trainer_pokemon_default_item_default_attacks trainer_party_xc1[6];
trainer_pokemon_default_item_default_attacks trainer_party_xc2[2];
trainer_pokemon_default_item_default_attacks trainer_party_xc3[3];
trainer_pokemon_default_item_default_attacks trainer_party_xc4[2];
trainer_pokemon_default_item_default_attacks trainer_party_xc5[2];
trainer_pokemon_default_item_default_attacks trainer_party_xc6[3];
trainer_pokemon_default_item_default_attacks trainer_party_xc7[2];
trainer_pokemon_default_item_default_attacks trainer_party_xc8[1];
trainer_pokemon_custom_item_default_attacks trainer_party_xc9[3];
trainer_pokemon_default_item_default_attacks trainer_party_xca[3];
trainer_pokemon_default_item_default_attacks trainer_party_xcb[1];
trainer_pokemon_default_item_default_attacks trainer_party_xcc[2];
trainer_pokemon_default_item_default_attacks trainer_party_xcd[2];
trainer_pokemon_default_item_default_attacks trainer_party_xce[2];
trainer_pokemon_default_item_custom_attacks trainer_party_xcf[4];
trainer_pokemon_default_item_custom_attacks trainer_party_xd0[3];
trainer_pokemon_default_item_custom_attacks trainer_party_xd1[2];
trainer_pokemon_default_item_default_attacks trainer_party_xd2[6];
trainer_pokemon_default_item_default_attacks trainer_party_xd3[4];
trainer_pokemon_default_item_default_attacks trainer_party_xd4[2];
trainer_pokemon_default_item_default_attacks trainer_party_xd5[3];
trainer_pokemon_default_item_default_attacks trainer_party_xd6[1];
trainer_pokemon_default_item_default_attacks trainer_party_xd7[2];
trainer_pokemon_default_item_default_attacks trainer_party_xd8[2];
trainer_pokemon_default_item_default_attacks trainer_party_xd9[1];
trainer_pokemon_default_item_default_attacks trainer_party_xda[4];
trainer_pokemon_default_item_default_attacks trainer_party_xdb[2];
trainer_pokemon_default_item_default_attacks trainer_party_xdc[3];
trainer_pokemon_default_item_default_attacks trainer_party_xdd[1];
trainer_pokemon_default_item_default_attacks trainer_party_xde[3];
trainer_pokemon_default_item_default_attacks trainer_party_xdf[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_xe0[4];
trainer_pokemon_custom_item_custom_attacks trainer_party_xe1[4];
trainer_pokemon_custom_item_custom_attacks trainer_party_xe2[4];
trainer_pokemon_default_item_default_attacks trainer_party_xe3[2];
trainer_pokemon_default_item_default_attacks trainer_party_xe4[4];
trainer_pokemon_default_item_default_attacks trainer_party_xe5[6];
trainer_pokemon_custom_item_default_attacks trainer_party_xe6[4];
trainer_pokemon_default_item_default_attacks trainer_party_xe7[6];
trainer_pokemon_default_item_default_attacks trainer_party_xe8[2];
trainer_pokemon_default_item_default_attacks trainer_party_xe9[2];
trainer_pokemon_default_item_default_attacks trainer_party_xea[2];
trainer_pokemon_default_item_default_attacks trainer_party_xeb[2];
trainer_pokemon_default_item_default_attacks trainer_party_xec[3];
trainer_pokemon_default_item_default_attacks trainer_party_xed[2];
trainer_pokemon_default_item_default_attacks trainer_party_xee[4];
trainer_pokemon_default_item_default_attacks trainer_party_xef[3];
trainer_pokemon_default_item_default_attacks trainer_party_xf0[2];
trainer_pokemon_default_item_default_attacks trainer_party_xf1[5];
trainer_pokemon_default_item_default_attacks trainer_party_xf2[2];
trainer_pokemon_default_item_default_attacks trainer_party_xf3[1];
trainer_pokemon_default_item_default_attacks trainer_party_xf4[4];
trainer_pokemon_default_item_default_attacks trainer_party_xf5[2];
trainer_pokemon_default_item_default_attacks trainer_party_xf6[1];
trainer_pokemon_default_item_default_attacks trainer_party_xf7[2];
trainer_pokemon_default_item_default_attacks trainer_party_xf8[3];
trainer_pokemon_default_item_default_attacks trainer_party_xf9[3];
trainer_pokemon_default_item_default_attacks trainer_party_xfa[2];
trainer_pokemon_default_item_default_attacks trainer_party_xfb[2];
trainer_pokemon_default_item_default_attacks trainer_party_xfc[2];
trainer_pokemon_default_item_default_attacks trainer_party_xfd[2];
trainer_pokemon_default_item_default_attacks trainer_party_xfe[1];
trainer_pokemon_default_item_default_attacks trainer_party_xff[4];
trainer_pokemon_default_item_default_attacks trainer_party_x100[2];
trainer_pokemon_default_item_default_attacks trainer_party_x101[3];
trainer_pokemon_default_item_default_attacks trainer_party_x102[2];
trainer_pokemon_default_item_default_attacks trainer_party_x103[2];
trainer_pokemon_default_item_default_attacks trainer_party_x104[2];
trainer_pokemon_default_item_default_attacks trainer_party_x105[2];
trainer_pokemon_default_item_default_attacks trainer_party_x106[3];
trainer_pokemon_default_item_default_attacks trainer_party_x107[1];
trainer_pokemon_default_item_default_attacks trainer_party_x108[2];
trainer_pokemon_default_item_default_attacks trainer_party_x109[4];
trainer_pokemon_default_item_default_attacks trainer_party_x10a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x10b[1];
trainer_pokemon_default_item_default_attacks trainer_party_x10c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x10d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x10e[1];
trainer_pokemon_default_item_default_attacks trainer_party_x10f[3];
trainer_pokemon_default_item_default_attacks trainer_party_x110[2];
trainer_pokemon_default_item_default_attacks trainer_party_x111[2];
trainer_pokemon_default_item_default_attacks trainer_party_x112[2];
trainer_pokemon_default_item_default_attacks trainer_party_x113[3];
trainer_pokemon_default_item_default_attacks trainer_party_x114[5];
trainer_pokemon_default_item_default_attacks trainer_party_x115[2];
trainer_pokemon_default_item_default_attacks trainer_party_x116[3];
trainer_pokemon_default_item_default_attacks trainer_party_x117[3];
trainer_pokemon_default_item_default_attacks trainer_party_x118[4];
trainer_pokemon_default_item_default_attacks trainer_party_x119[2];
trainer_pokemon_default_item_default_attacks trainer_party_x11a[3];
trainer_pokemon_default_item_default_attacks trainer_party_x11b[1];
trainer_pokemon_default_item_default_attacks trainer_party_x11c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x11d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x11e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x11f[4];
trainer_pokemon_default_item_default_attacks trainer_party_x120[4];
trainer_pokemon_default_item_default_attacks trainer_party_x121[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x122[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x123[4];
trainer_pokemon_default_item_default_attacks trainer_party_x124[1];
trainer_pokemon_default_item_default_attacks trainer_party_x125[2];
trainer_pokemon_default_item_default_attacks trainer_party_x126[2];
trainer_pokemon_default_item_default_attacks trainer_party_x127[3];
trainer_pokemon_default_item_default_attacks trainer_party_x128[1];
trainer_pokemon_default_item_default_attacks trainer_party_x129[2];
trainer_pokemon_default_item_default_attacks trainer_party_x12a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x12b[4];
trainer_pokemon_default_item_default_attacks trainer_party_x12c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x12d[5];
trainer_pokemon_default_item_default_attacks trainer_party_x12e[4];
trainer_pokemon_default_item_default_attacks trainer_party_x12f[1];
trainer_pokemon_default_item_default_attacks trainer_party_x130[2];
trainer_pokemon_default_item_default_attacks trainer_party_x131[4];
trainer_pokemon_default_item_default_attacks trainer_party_x132[3];
trainer_pokemon_default_item_default_attacks trainer_party_x133[2];
trainer_pokemon_default_item_default_attacks trainer_party_x134[1];
trainer_pokemon_default_item_default_attacks trainer_party_x135[4];
trainer_pokemon_default_item_default_attacks trainer_party_x136[3];
trainer_pokemon_default_item_default_attacks trainer_party_x137[4];
trainer_pokemon_default_item_default_attacks trainer_party_x138[2];
trainer_pokemon_default_item_default_attacks trainer_party_x139[3];
trainer_pokemon_default_item_default_attacks trainer_party_x13a[4];
trainer_pokemon_default_item_default_attacks trainer_party_x13b[2];
trainer_pokemon_default_item_default_attacks trainer_party_x13c[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x13d[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x13e[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x13f[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x140[1];
trainer_pokemon_custom_item_default_attacks trainer_party_x141[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x142[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x143[1];
trainer_pokemon_custom_item_default_attacks trainer_party_x144[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x145[3];
trainer_pokemon_default_item_default_attacks trainer_party_x146[1];
trainer_pokemon_default_item_default_attacks trainer_party_x147[1];
trainer_pokemon_default_item_default_attacks trainer_party_x148[1];
trainer_pokemon_custom_item_custom_attacks trainer_party_x149[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_x14a[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_x14b[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_x14c[4];
trainer_pokemon_custom_item_custom_attacks trainer_party_x14d[4];
trainer_pokemon_custom_item_custom_attacks trainer_party_x14e[4];
trainer_pokemon_default_item_default_attacks trainer_party_x14f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x150[3];
trainer_pokemon_default_item_default_attacks trainer_party_x151[1];
trainer_pokemon_default_item_default_attacks trainer_party_x152[2];
trainer_pokemon_default_item_default_attacks trainer_party_x153[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x154[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x155[5];
trainer_pokemon_default_item_default_attacks trainer_party_x156[2];
trainer_pokemon_default_item_default_attacks trainer_party_x157[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x158[3];
trainer_pokemon_default_item_default_attacks trainer_party_x159[2];
trainer_pokemon_default_item_default_attacks trainer_party_x15a[3];
trainer_pokemon_default_item_default_attacks trainer_party_x15b[2];
trainer_pokemon_default_item_default_attacks trainer_party_x15c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x15d[4];
trainer_pokemon_default_item_custom_attacks trainer_party_x15e[5];
trainer_pokemon_default_item_default_attacks trainer_party_x15f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x160[3];
trainer_pokemon_default_item_default_attacks trainer_party_x161[2];
trainer_pokemon_default_item_default_attacks trainer_party_x162[2];
trainer_pokemon_default_item_default_attacks trainer_party_x163[2];
trainer_pokemon_default_item_default_attacks trainer_party_x164[2];
trainer_pokemon_default_item_default_attacks trainer_party_x165[2];
trainer_pokemon_default_item_default_attacks trainer_party_x166[2];
trainer_pokemon_default_item_default_attacks trainer_party_x167[2];
trainer_pokemon_default_item_default_attacks trainer_party_x168[3];
trainer_pokemon_default_item_default_attacks trainer_party_x169[4];
trainer_pokemon_default_item_default_attacks trainer_party_x16a[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x16b[5];
trainer_pokemon_default_item_default_attacks trainer_party_x16c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x16d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x16e[3];
trainer_pokemon_default_item_default_attacks trainer_party_x16f[3];
trainer_pokemon_default_item_default_attacks trainer_party_x170[2];
trainer_pokemon_default_item_default_attacks trainer_party_x171[3];
trainer_pokemon_default_item_default_attacks trainer_party_x172[2];
trainer_pokemon_default_item_default_attacks trainer_party_x173[4];
trainer_pokemon_default_item_default_attacks trainer_party_x174[2];
trainer_pokemon_default_item_default_attacks trainer_party_x175[2];
trainer_pokemon_default_item_default_attacks trainer_party_x176[3];
trainer_pokemon_default_item_default_attacks trainer_party_x177[3];
trainer_pokemon_default_item_default_attacks trainer_party_x178[2];
trainer_pokemon_default_item_default_attacks trainer_party_x179[3];
trainer_pokemon_default_item_default_attacks trainer_party_x17a[1];
trainer_pokemon_default_item_default_attacks trainer_party_x17b[1];
trainer_pokemon_default_item_default_attacks trainer_party_x17c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x17d[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x17e[4];
trainer_pokemon_default_item_default_attacks trainer_party_x17f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x180[2];
trainer_pokemon_default_item_default_attacks trainer_party_x181[4];
trainer_pokemon_default_item_default_attacks trainer_party_x182[3];
trainer_pokemon_default_item_default_attacks trainer_party_x183[3];
trainer_pokemon_default_item_default_attacks trainer_party_x184[3];
trainer_pokemon_default_item_default_attacks trainer_party_x185[1];
trainer_pokemon_default_item_default_attacks trainer_party_x186[5];
trainer_pokemon_default_item_default_attacks trainer_party_x187[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x188[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x189[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x18a[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x18b[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x18c[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x18d[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x18e[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x18f[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x190[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x191[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x192[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x193[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x194[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x195[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x196[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x197[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x198[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x199[5];
trainer_pokemon_custom_item_custom_attacks trainer_party_x19a[5];
trainer_pokemon_custom_item_custom_attacks trainer_party_x19b[5];
trainer_pokemon_custom_item_custom_attacks trainer_party_x19c[5];
trainer_pokemon_custom_item_custom_attacks trainer_party_x19d[5];
trainer_pokemon_custom_item_custom_attacks trainer_party_x19e[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_x19f[4];
trainer_pokemon_custom_item_custom_attacks trainer_party_x1a0[4];
trainer_pokemon_custom_item_custom_attacks trainer_party_x1a1[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x1a2[4];
trainer_pokemon_default_item_custom_attacks trainer_party_x1a3[4];
trainer_pokemon_default_item_custom_attacks trainer_party_x1a4[4];
trainer_pokemon_default_item_default_attacks trainer_party_x1a5[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1a6[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1a7[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1a8[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1a9[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1aa[4];
trainer_pokemon_default_item_default_attacks trainer_party_x1ab[4];
trainer_pokemon_default_item_default_attacks trainer_party_x1ac[4];
trainer_pokemon_default_item_default_attacks trainer_party_x1ad[5];
trainer_pokemon_default_item_default_attacks trainer_party_x1ae[5];
trainer_pokemon_default_item_default_attacks trainer_party_x1af[5];
trainer_pokemon_default_item_default_attacks trainer_party_x1b0[5];
trainer_pokemon_default_item_default_attacks trainer_party_x1b1[5];
trainer_pokemon_default_item_default_attacks trainer_party_x1b2[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x1b3[6];
trainer_pokemon_default_item_custom_attacks trainer_party_x1b4[6];
trainer_pokemon_default_item_custom_attacks trainer_party_x1b5[6];
trainer_pokemon_custom_item_custom_attacks trainer_party_x1b6[6];
trainer_pokemon_custom_item_custom_attacks trainer_party_x1b7[6];
trainer_pokemon_custom_item_custom_attacks trainer_party_x1b8[6];
trainer_pokemon_default_item_default_attacks trainer_party_x1b9[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1ba[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1bb[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1bc[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1bd[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1be[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1bf[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1c0[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1c1[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1c2[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1c3[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1c4[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1c5[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1c6[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1c7[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1c8[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1c9[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1ca[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1cb[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1cc[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1cd[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1ce[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1cf[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1d0[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1d1[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1d2[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1d3[5];
trainer_pokemon_default_item_default_attacks trainer_party_x1d4[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1d5[4];
trainer_pokemon_default_item_custom_attacks trainer_party_x1d6[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1d7[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1d8[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1d9[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1da[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1db[4];
trainer_pokemon_default_item_default_attacks trainer_party_x1dc[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1dd[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1de[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1df[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1e0[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1e1[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1e2[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1e3[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1e4[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x1e5[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1e6[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1e7[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x1e8[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1e9[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1ea[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1eb[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1ec[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1ed[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1ee[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1ef[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1f0[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1f1[1];
trainer_pokemon_default_item_default_attacks trainer_party_x1f2[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1f3[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1f4[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1f5[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1f6[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1f7[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1f8[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1f9[3];
trainer_pokemon_default_item_default_attacks trainer_party_x1fa[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1fb[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1fc[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1fd[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1fe[2];
trainer_pokemon_default_item_default_attacks trainer_party_x1ff[1];
trainer_pokemon_default_item_default_attacks trainer_party_x200[1];
trainer_pokemon_default_item_default_attacks trainer_party_x201[1];
trainer_pokemon_default_item_default_attacks trainer_party_x202[1];
trainer_pokemon_default_item_default_attacks trainer_party_x203[1];
trainer_pokemon_default_item_default_attacks trainer_party_x204[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x205[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x206[2];
trainer_pokemon_default_item_default_attacks trainer_party_x207[3];
trainer_pokemon_default_item_default_attacks trainer_party_x208[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x209[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x20a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x20b[2];
trainer_pokemon_default_item_default_attacks trainer_party_x20c[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x20d[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x20e[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x20f[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x210[1];
trainer_pokemon_default_item_default_attacks trainer_party_x211[1];
trainer_pokemon_default_item_default_attacks trainer_party_x212[1];
trainer_pokemon_default_item_default_attacks trainer_party_x213[2];
trainer_pokemon_default_item_default_attacks trainer_party_x214[3];
trainer_pokemon_default_item_default_attacks trainer_party_x215[2];
trainer_pokemon_default_item_default_attacks trainer_party_x216[3];
trainer_pokemon_custom_item_custom_attacks trainer_party_x217[2];
trainer_pokemon_default_item_default_attacks trainer_party_x218[2];
trainer_pokemon_default_item_default_attacks trainer_party_x219[2];
trainer_pokemon_default_item_default_attacks trainer_party_x21a[4];
trainer_pokemon_default_item_default_attacks trainer_party_x21b[3];
trainer_pokemon_default_item_default_attacks trainer_party_x21c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x21d[3];
trainer_pokemon_default_item_default_attacks trainer_party_x21e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x21f[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x220[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x221[5];
trainer_pokemon_default_item_default_attacks trainer_party_x222[3];
trainer_pokemon_default_item_default_attacks trainer_party_x223[2];
trainer_pokemon_default_item_default_attacks trainer_party_x224[3];
trainer_pokemon_default_item_default_attacks trainer_party_x225[1];
trainer_pokemon_default_item_default_attacks trainer_party_x226[3];
trainer_pokemon_default_item_default_attacks trainer_party_x227[5];
trainer_pokemon_custom_item_default_attacks trainer_party_x228[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x229[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x22a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x22b[3];
trainer_pokemon_default_item_default_attacks trainer_party_x22c[4];
trainer_pokemon_custom_item_default_attacks trainer_party_x22d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x22e[3];
trainer_pokemon_default_item_default_attacks trainer_party_x22f[4];
trainer_pokemon_default_item_default_attacks trainer_party_x230[2];
trainer_pokemon_default_item_default_attacks trainer_party_x231[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x232[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x233[1];
trainer_pokemon_custom_item_default_attacks trainer_party_x234[3];
trainer_pokemon_default_item_default_attacks trainer_party_x235[2];
trainer_pokemon_default_item_default_attacks trainer_party_x236[3];
trainer_pokemon_default_item_default_attacks trainer_party_x237[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x238[2];
trainer_pokemon_default_item_default_attacks trainer_party_x239[3];
trainer_pokemon_default_item_default_attacks trainer_party_x23a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x23b[2];
trainer_pokemon_default_item_default_attacks trainer_party_x23c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x23d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x23e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x23f[1];
trainer_pokemon_default_item_default_attacks trainer_party_x240[2];
trainer_pokemon_default_item_default_attacks trainer_party_x241[2];
trainer_pokemon_default_item_default_attacks trainer_party_x242[1];
trainer_pokemon_default_item_default_attacks trainer_party_x243[2];
trainer_pokemon_default_item_default_attacks trainer_party_x244[2];
trainer_pokemon_default_item_default_attacks trainer_party_x245[2];
trainer_pokemon_default_item_default_attacks trainer_party_x246[1];
trainer_pokemon_default_item_default_attacks trainer_party_x247[2];
trainer_pokemon_default_item_default_attacks trainer_party_x248[1];
trainer_pokemon_default_item_default_attacks trainer_party_x249[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x24a[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x24b[3];
trainer_pokemon_default_item_default_attacks trainer_party_x24c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x24d[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x24e[4];
trainer_pokemon_custom_item_default_attacks trainer_party_x24f[3];
trainer_pokemon_custom_item_default_attacks trainer_party_x250[2];
trainer_pokemon_default_item_default_attacks trainer_party_x251[3];
trainer_pokemon_default_item_default_attacks trainer_party_x252[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x253[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x254[3];
trainer_pokemon_default_item_default_attacks trainer_party_x255[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x256[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x257[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x258[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x259[2];
trainer_pokemon_default_item_default_attacks trainer_party_x25a[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x25b[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x25c[1];
trainer_pokemon_default_item_default_attacks trainer_party_x25d[2];
trainer_pokemon_custom_item_custom_attacks trainer_party_x25e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x25f[3];
trainer_pokemon_default_item_default_attacks trainer_party_x260[3];
trainer_pokemon_default_item_default_attacks trainer_party_x261[1];
trainer_pokemon_default_item_default_attacks trainer_party_x262[3];
trainer_pokemon_default_item_default_attacks trainer_party_x263[1];
trainer_pokemon_default_item_default_attacks trainer_party_x264[4];
trainer_pokemon_default_item_default_attacks trainer_party_x265[2];
trainer_pokemon_default_item_default_attacks trainer_party_x266[3];
trainer_pokemon_default_item_default_attacks trainer_party_x267[2];
trainer_pokemon_default_item_default_attacks trainer_party_x268[4];
trainer_pokemon_default_item_default_attacks trainer_party_x269[1];
trainer_pokemon_default_item_default_attacks trainer_party_x26a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x26b[3];
trainer_pokemon_default_item_default_attacks trainer_party_x26c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x26d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x26e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x26f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x270[1];
trainer_pokemon_default_item_default_attacks trainer_party_x271[1];
trainer_pokemon_default_item_default_attacks trainer_party_x272[1];
trainer_pokemon_default_item_default_attacks trainer_party_x273[2];
trainer_pokemon_default_item_default_attacks trainer_party_x274[2];
trainer_pokemon_default_item_default_attacks trainer_party_x275[2];
trainer_pokemon_default_item_default_attacks trainer_party_x276[3];
trainer_pokemon_default_item_default_attacks trainer_party_x277[3];
trainer_pokemon_default_item_default_attacks trainer_party_x278[3];
trainer_pokemon_default_item_default_attacks trainer_party_x279[3];
trainer_pokemon_default_item_default_attacks trainer_party_x27a[3];
trainer_pokemon_default_item_default_attacks trainer_party_x27b[3];
trainer_pokemon_default_item_default_attacks trainer_party_x27c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x27d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x27e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x27f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x280[1];
trainer_pokemon_default_item_default_attacks trainer_party_x281[1];
trainer_pokemon_default_item_default_attacks trainer_party_x282[1];
trainer_pokemon_default_item_default_attacks trainer_party_x283[2];
trainer_pokemon_default_item_default_attacks trainer_party_x284[2];
trainer_pokemon_default_item_default_attacks trainer_party_x285[2];
trainer_pokemon_default_item_default_attacks trainer_party_x286[2];
trainer_pokemon_default_item_default_attacks trainer_party_x287[2];
trainer_pokemon_default_item_default_attacks trainer_party_x288[5];
trainer_pokemon_default_item_default_attacks trainer_party_x289[5];
trainer_pokemon_default_item_default_attacks trainer_party_x28a[3];
trainer_pokemon_default_item_default_attacks trainer_party_x28b[2];
trainer_pokemon_default_item_default_attacks trainer_party_x28c[2];
trainer_pokemon_default_item_default_attacks trainer_party_x28d[4];
trainer_pokemon_default_item_default_attacks trainer_party_x28e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x28f[2];
trainer_pokemon_default_item_default_attacks trainer_party_x290[4];
trainer_pokemon_default_item_default_attacks trainer_party_x291[4];
trainer_pokemon_default_item_default_attacks trainer_party_x292[5];
trainer_pokemon_default_item_default_attacks trainer_party_x293[5];
trainer_pokemon_default_item_default_attacks trainer_party_x294[5];
trainer_pokemon_default_item_default_attacks trainer_party_x295[4];
trainer_pokemon_default_item_default_attacks trainer_party_x296[2];
trainer_pokemon_default_item_default_attacks trainer_party_x297[2];
trainer_pokemon_default_item_default_attacks trainer_party_x298[3];
trainer_pokemon_default_item_default_attacks trainer_party_x299[3];
trainer_pokemon_default_item_default_attacks trainer_party_x29a[2];
trainer_pokemon_default_item_default_attacks trainer_party_x29b[3];
trainer_pokemon_default_item_default_attacks trainer_party_x29c[3];
trainer_pokemon_default_item_default_attacks trainer_party_x29d[2];
trainer_pokemon_default_item_default_attacks trainer_party_x29e[2];
trainer_pokemon_default_item_default_attacks trainer_party_x29f[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2a0[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2a1[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2a2[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2a3[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2a4[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2a5[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2a6[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2a7[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2a8[4];
trainer_pokemon_default_item_default_attacks trainer_party_x2a9[4];
trainer_pokemon_default_item_default_attacks trainer_party_x2aa[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2ab[4];
trainer_pokemon_default_item_default_attacks trainer_party_x2ac[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2ad[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2ae[6];
trainer_pokemon_default_item_default_attacks trainer_party_x2af[1];
trainer_pokemon_default_item_default_attacks trainer_party_x2b0[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2b1[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2b2[1];
trainer_pokemon_custom_item_default_attacks trainer_party_x2b3[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2b4[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2b5[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2b6[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2b7[1];
trainer_pokemon_custom_item_default_attacks trainer_party_x2b8[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2b9[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2ba[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2bb[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2bc[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2bd[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2be[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x2bf[1];
trainer_pokemon_default_item_default_attacks trainer_party_x2c0[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2c1[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2c2[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2c3[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2c4[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2c5[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2c6[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2c7[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x2c8[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2c9[1];
trainer_pokemon_default_item_default_attacks trainer_party_x2ca[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2cb[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2cc[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x2cd[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x2ce[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2cf[4];
trainer_pokemon_default_item_custom_attacks trainer_party_x2d0[2];
trainer_pokemon_default_item_custom_attacks trainer_party_x2d1[2];
trainer_pokemon_custom_item_default_attacks trainer_party_x2d2[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2d3[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x2d4[3];
trainer_pokemon_default_item_custom_attacks trainer_party_x2d5[1];
trainer_pokemon_default_item_custom_attacks trainer_party_x2d6[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x2d7[5];
trainer_pokemon_default_item_custom_attacks trainer_party_x2d8[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2d9[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2da[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2db[3];
trainer_pokemon_default_item_default_attacks trainer_party_x2dc[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2dd[2];
trainer_pokemon_default_item_default_attacks trainer_party_x2de[2];
trainer_pokemon_custom_item_custom_attacks trainer_party_x2df[5];
trainer_pokemon_custom_item_custom_attacks trainer_party_x2e0[5];
trainer_pokemon_custom_item_custom_attacks trainer_party_x2e1[5];
trainer_pokemon_custom_item_custom_attacks trainer_party_x2e2[5];
trainer_pokemon_custom_item_custom_attacks trainer_party_x2e3[6];
trainer_pokemon_custom_item_custom_attacks trainer_party_x2e4[6];
trainer_pokemon_custom_item_custom_attacks trainer_party_x2e5[6];
trainer_pokemon_custom_item_custom_attacks trainer_party_x2e6[2];

#endif