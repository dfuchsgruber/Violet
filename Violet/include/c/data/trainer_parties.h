#ifndef H_DATA_TRAINER
#define H_DATA_TRAINER

#include "types.h"
#include "constants/items.h"
#include "constants/attacks.h"
#include "constants/species.h"
#include "constants/trainer_builds.h"

#define TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(ivs, build, ability_bit, hidden_ability, shiny, level, species)\
{\
		ivs, \
        {.bitfield = {build, ability_bit, hidden_ability, shiny}}, \
        level,\
        0,\
        species,\
         0x0 \
}

#define TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(ivs, build, ability_bit, hidden_ability, shiny, level, species, item)\
{\
		ivs, \
        {.bitfield = {build, ability_bit, hidden_ability, shiny}}, \
        level,\
        0,\
        species,\
        item\
}

#define TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(ivs, build, ability_bit, hidden_ability, shiny, level, species, move0, move1, move2, move3)\
{\
		ivs, \
        {.bitfield = {build, ability_bit, hidden_ability, shiny}}, \
        level,\
        0,\
        species,\
        {move0, move1, move2, move3},\
        0x0\
}

#define TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(ivs, build, ability_bit, hidden_ability, shiny, level, species, item, move0, move1, move2, move3)\
{\
		ivs, \
        {.bitfield = {build, ability_bit, hidden_ability, shiny}}, \
        level,\
        0,\
        species,\
        item,\
        {move0, move1, move2, move3}\
}


static trainer_pokemon_default_item_default_attacks trainer_party_x0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,4,POKEMON_FIFFYEN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,4,POKEMON_DARTIRI)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,4,POKEMON_ZIGZACHS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,4,POKEMON_DARTIRI)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_ZUBAT)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_FRIZELBLIZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_SANDAN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,8,POKEMON_LICHTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_TRAUMATO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,5,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,5,POKEMON_SAMURZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_MYRAPLA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,10,POKEMON_FIFFYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,11,POKEMON_SLEIMA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_MOBAI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_FLABEBE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,8,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9,POKEMON_VOLTOBAL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xb[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_FIFFYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,8,POKEMON_FRIZELBLIZ)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9,POKEMON_PUPPANCE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9,POKEMON_PONITA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,10,POKEMON_ENECO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_RIOLU)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,13,POKEMON_MARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_CAMAUB)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x10[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,12,POKEMON_KNILZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,13,POKEMON_BISASAM)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x11[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9,POKEMON_MEDITIE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x12[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,13,POKEMON_KLEINSTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_NASGNET)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x13[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_WATTZAPF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_WAUMPEL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x14[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_FLABEBE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,8,POKEMON_EVOLI)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x15[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_ZIGZACHS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x16[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_KRAMURX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_RESLADERO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_SCHWALBINI)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x17[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9,POKEMON_TRASLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9,POKEMON_ABRA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x18[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,13,POKEMON_STARALILI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_DARTIRI)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x19[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_CLAVION),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_FUKANO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_NIDORANM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_NIDORANW)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,13,POKEMON_KASTADUR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_BISASAM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_FLABEBE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_STERNDU)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_KREBSCORPS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_KAUMALAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_DRATINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_KINDWURM)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_VOLTILAMM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_MAEHIKEL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x20[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_KANIVANHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_FLEGMON)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x21[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_BARSCHWA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_QUABBEL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x22[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_RIOLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_RABAUZ)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x23[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 17, POKEMON_DARTIGNIS, ITEM_NONE, ATTACK_GLUT, ATTACK_SCHNABEL, ATTACK_STAHLFLUEGEL, ATTACK_TACKLE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 18, POKEMON_TYRACROC, ITEM_ZAUBERWASSER, ATTACK_EISHIEB, ATTACK_KASKADE, ATTACK_KRATZER, ATTACK_DRACHENTANZ),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 16, POKEMON_BLANAS, ITEM_NONE, ATTACK_MOGELHIEB, ATTACK_FINTE, ATTACK_GIGASAUGER, ATTACK_SONDERSENSOR),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 18, POKEMON_KADABRA, ITEM_TSITRUBEERE, ATTACK_PSYSTRAHL, ATTACK_NONE, ATTACK_FOKUSSTOSS, ATTACK_ZAUBERSCHEIN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x24[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_WABLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_MACHOLLO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x25[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_GRIFFEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_NIDORANM)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x26[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_KRAMURX)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x27[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_DARTIRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_SCHWALBINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18,POKEMON_WABLU)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x28[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_BIBOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_BIBOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_BIBOR)
};

static trainer_pokemon_custom_item_default_attacks trainer_party_x29[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_BISASAM,ITEM_TSITRUBEERE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_SEEKID,ITEM_TSITRUBEERE)
};

static trainer_pokemon_custom_item_default_attacks trainer_party_x2a[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_GLUMANDA,ITEM_TSITRUBEERE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_LOCKSCHAL,ITEM_TSITRUBEERE)
};

static trainer_pokemon_custom_item_default_attacks trainer_party_x2b[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14,POKEMON_SCHIGGY,ITEM_TSITRUBEERE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15,POKEMON_WELUNO,ITEM_TSITRUBEERE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x2c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_FRIZELBLIZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_FIFFYEN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x2d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_VOLTOBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18,POKEMON_FRIZELBLIZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_MAGNETILO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x2e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18,POKEMON_BISAKNOSP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18,POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_MYRAPLA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x2f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18,POKEMON_FIFFYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,19,POKEMON_KIRLIA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x30[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18,POKEMON_LEDYBA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18,POKEMON_MEDITIE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x31[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_MACHOLLO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x32[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_KLEINSTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_ONIX)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x33[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,19,POKEMON_GRAMOKLES),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_SKORGLA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x34[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_TANNZA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_PHANPY)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x35[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_PORYGON_Z),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,19,POKEMON_FLOETTE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x36[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_KNOFENSA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,16,POKEMON_FLABEBE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x37[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,4,POKEMON_BUMMELZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,5,POKEMON_MARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,4,POKEMON_KNILZ)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x38[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_LICHTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_WAATY),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17,POKEMON_SCHWALBINI)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x39[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_SANDAN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x3a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_SNUBBULL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x3b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_OWEI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_PINSIR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_KANIVANHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_VULPIX)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x3c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_ELEKTEK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,19,POKEMON_TUSKA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_KIRLIA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x3d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_DUFLOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_BLANAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_ULTRIGARIA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x3e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_MAEHIKEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_KNILZ)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x3f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_LORBLATT)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x40[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_MYRAPLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_BLANAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_LOCKSCHAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_ULTRIGARIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_MAEHIKEL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x41[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_NIDORINA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x42[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,19,POKEMON_KREBSCORPS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,19,POKEMON_KARPADOR)
};

static trainer_pokemon_custom_item_default_attacks trainer_party_x43[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_PUDOX,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_PAPINELLA,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20,POKEMON_WEBARAK,ITEM_GIFTSTICH)
};

static trainer_pokemon_custom_item_default_attacks trainer_party_x44[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_GOLBAT,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_KRAMURX,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_MOLUNK,ITEM_NONE)
};

static trainer_pokemon_custom_item_default_attacks trainer_party_x45[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_VULPIX,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_STARAVIA,ITEM_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_FRIZELBLIZ,ITEM_NONE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x46[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_SPOINK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_WAATY)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x47[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_KAUMALAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_WABLU)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x48[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21,POKEMON_PUPPANCE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x49[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_NIDORINO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x4a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_KRAMURX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_ALPOLLO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x4b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_MAGNETON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_NIDORINA)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x4c[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 1, false, false, 25, POKEMON_ONIX, ITEM_SALKABEERE, ATTACK_STEINHAGEL, ATTACK_SCHAUFLER, ATTACK_EISENSCHWEIF, ATTACK_STEINKANTE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 26, POKEMON_GARADOS, ITEM_RABUTABEERE, ATTACK_DRACHENTANZ, ATTACK_BISS, ATTACK_NASSSCHWEIF, ATTACK_EISZAHN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE_FEMALE, 0x0, false, false, 26, POKEMON_MOLUNK, ITEM_GIFTSTICH, ATTACK_GIFTZAHN, ATTACK_FLAMMENWURF, ATTACK_MOGELHIEB, ATTACK_GIFTWOLKE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 28, POKEMON_VIPITIS, ITEM_PRUNUSBEERE, ATTACK_GIFTSCHWEIF, ATTACK_EISENSCHWEIF, ATTACK_NACHTHIEB, ATTACK_NASSSCHWEIF)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x4d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_STOLLUNIOR)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x4e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_MAGNAYEN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x4f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_NIDORINA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x50[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_KLEINSTEIN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x51[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_SNUBBULL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_SCHWALBINI)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x52[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_GEOROK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x53[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_DUFLOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,22,POKEMON_DARTIGNIS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x54[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_NOCKCHAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_KICKLEE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x55[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_BLANAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_LOMBRERO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x56[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0, 0,0x0,true,false,24,POKEMON_SCHLURP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0, 0,0x0,true,false,24,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0, 0,0x0,true,false,23,POKEMON_WATTZAPF)
};

static trainer_pokemon_custom_item_default_attacks trainer_party_x57[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_AERODACTYL,ITEM_NONE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x58[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_PUPPANCE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_DIGDA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_SKORGLA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x59[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_KLEINSTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_RESLADERO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x5a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_TUSKA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_ZOBIRIS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x5b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_ENEKORO)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x5c[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 29, POKEMON_STARAVIA, ITEM_NONE, ATTACK_STAHLFLUEGEL, ATTACK_AERO_ASS, ATTACK_NOTSITUATION, ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_SEESKULL, ITEM_TSITRUBEERE, ATTACK_DRACHENTANZ, ATTACK_NASSSCHWEIF, ATTACK_EISENSCHWEIF, ATTACK_GIFTSCHWEIF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 30, POKEMON_BISAKNOSP, ITEM_SINELBEERE, ATTACK_SCHLAFPUDER, ATTACK_RASIERBLATT, ATTACK_MATSCHBOMBE, ATTACK_EGELSAMEN)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x5d[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 29, POKEMON_STARAVIA, ITEM_NONE, ATTACK_STAHLFLUEGEL, ATTACK_AERO_ASS, ATTACK_NOTSITUATION, ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_STICHSCHAL, ITEM_TSITRUBEERE, ATTACK_LAUBKLINGE, ATTACK_FLUCH, ATTACK_ZORNKLINGE, ATTACK_GEDULD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 30, POKEMON_GLUTEXO, ITEM_SINELBEERE, ATTACK_GLUT, ATTACK_METALLKLAUE, ATTACK_RAUCHWOLKE, ATTACK_DUNKELKLAUE)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x5e[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 29, POKEMON_STARAVIA, ITEM_NONE, ATTACK_STAHLFLUEGEL, ATTACK_AERO_ASS, ATTACK_NOTSITUATION, ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_ORTHODOS, ITEM_TSITRUBEERE, ATTACK_FLAMMENRAD, ATTACK_BISS, ATTACK_SCHAUFLER, ATTACK_EISENSCHWEIF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 30, POKEMON_SCHILLOK, ITEM_SINELBEERE, ATTACK_AQUAWELLE, ATTACK_BISS, ATTACK_EISSTRAHL, ATTACK_EINIGLER)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x5f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_TUSKA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_DIGDA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x60[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_ONIX)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x61[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_MARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_FEURIGEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_ABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_TRASLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_MOBAI)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x62[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_LOMBRERO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_RIOLU)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x63[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_BRONZEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_FLUNKIFER)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x64[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_WABLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_RESLADERO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x65[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0, 0,0x0,false,false,27,POKEMON_EVOLI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0, 0,0x0,false,false,26,POKEMON_PIKACHU)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x66[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_WAATY),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_VULNONA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x67[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_BIBOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_WEBARAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_LEDIAN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x68[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_SKORGRO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x69[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_FLEGMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_KIRLIA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x6a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_NASGNET),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_RIOLU)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x6c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_LEDYBA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_LEDIAN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x6d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_KANGAMA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_DARTIGNIS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_MASKEREGEN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x6e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_MOGELBAUM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_PAPINELLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_VOLTENSO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x6f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_KAPILZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_CHEVRUMM)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x70[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_ELEKTEK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x71[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_DODU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_PONITA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_DARTIGNIS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x72[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_FLOETTE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x73[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_KINDWURM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_RIOLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_RESLADERO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x74[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_MENKI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_MASCHOCK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x75[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_SCHWALBINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_SCHWALBOSS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x76[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_SPOINK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_BRONZEL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x77[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_KIRLIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_MAGNAYEN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x78[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_SEEMON)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x79[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0,0,0,false,false,35,POKEMON_KICKLEE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x7a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_MENKI)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x7b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_TENTACHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_KREBSCORPS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x7c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_RIOLU)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x7d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_GERADAKS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_TROPIUS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_PONITA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x7e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_GEOROK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x7f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_PAPINELLA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x80[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_MEDITIE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x81[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_SKARABORN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x82[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_RIOLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_RASAFF)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x83[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_MASCHOCK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x84[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_ENEKORO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_MAGNETON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_AZUMARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_GRANBULL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_VULNONA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_HYPNO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x85[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_PUPPANCE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_BRONZEL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x86[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_VOLTENSO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x87[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_STARAPTOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_ELEVOLTEK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_NOKTUSKA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x88[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_PAPINELLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_SICHLOR)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x89[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_DODRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_KRAMURX)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x8a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_FORMEO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x8b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_NASGNET),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_MOLUNK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x8c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_SONNFEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_LUNASTEIN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x8d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_MEDITALIS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_SHUPPET)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x8e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_KADABRA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x8f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_ALPOLLO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x90[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_SLEIMOK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x91[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,40,POKEMON_GARADOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,40,POKEMON_FROSDEDJE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,40,POKEMON_LEPUMENTAS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x92[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_GLUTEXO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_CAMAUB)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x93[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_MAGBY)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x94[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_KIRLIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_VULPIX)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x95[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_CAMAUB),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_SCHNECKMAG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_MAGMAR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_GEOROK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x96[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,40,POKEMON_HUNDEMON)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x97[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_ORTHODOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_MAGNETON)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x98[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_ARKANI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_GRANBULL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_PANZAERON)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x99[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_CAMAUB),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_FUKANO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x9a[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_SCHNECKMAG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_FUKANO)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x9b[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,5,POKEMON_AZURILL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x9c[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_CAMERUPT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,40,POKEMON_NIDOQUEEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,41,POKEMON_MEDITALIS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x9d[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_ENEKORO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_FLOETTE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x9e[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_SLEIMOK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x9f[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_NIDORANW),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_LEDYBA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_PANDIR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_RIHORN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_FLUNKIFER)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_SCHNECKMAG)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_DIGDA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_CAMAUB),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_PUPPANCE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_ORTHODOS)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_GOLBAT)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_SPOINK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_KRAMURX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,40,POKEMON_MAGNAYEN)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,41,POKEMON_NIDORINA)
};

static trainer_pokemon_default_item_custom_attacks trainer_party_xa7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_LATERNECTO,ATTACK_NITROLADUNG,ATTACK_NONE,ATTACK_NONE,ATTACK_NONE),
	TRAINER_PARTY_DEFAULT_ITEM_CUSTOM_MOVES(0, TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE,0x1,false,false,28,POKEMON_LATERNECTO,ATTACK_NITROLADUNG,ATTACK_NONE,ATTACK_NONE,ATTACK_NONE)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,42,POKEMON_STOLLRAK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xa9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,42,POKEMON_URSARING),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,43,POKEMON_XATU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,42,POKEMON_SEESKULL)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_xaa[2] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 50, POKEMON_GROUDON, ITEM_MAGMAHERZ, ATTACK_FEUERSTURM, ATTACK_ERDBEBEN, ATTACK_SOLARSTRAHL, ATTACK_HYPERSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0, 0, 0, 45, POKEMON_KRAMSHEF, ITEM_SCHATTENGLAS, ATTACK_NACHTHIEB, ATTACK_FLIEGEN, ATTACK_STAHLFLUEGEL, ATTACK_KRAFTKOLOSS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xab[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_GLUTEXO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_ORTHODOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_MAGMAR)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xac[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_SCHNECKMAG),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_HUNDUSTER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_CAMAUB)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xad[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_SPOINK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_BRONZEL)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xae[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_TENTOXA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_AMPHAROS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_NOKTUSKA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xaf[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_LEPUMENTAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_DUOKLES)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xb0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_SLEIMA)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xb1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_KRAMURX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_MAGNETON)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xb2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_NIDOQUEEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_IKSBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_GALAGLADI)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_xb8[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 38, POKEMON_SKARABORN, ITEM_NANABBEERE, ATTACK_VIELENDER, ATTACK_NAHKAMPF, ATTACK_STEINKANTE, ATTACK_POWER_PUNCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 38, POKEMON_MEDITALIS, ITEM_NONE, ATTACK_ZEN_KOPFSTOSS, ATTACK_PROTZER, ATTACK_POWER_PUNCH, ATTACK_DURCHBRUCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 37, POKEMON_MACHOMEI, ITEM_SCHWARZGURT, ATTACK_WUCHTSCHLAG, ATTACK_STEINKANTE, ATTACK_ERDBEBEN, ATTACK_DONNERSCHLAG),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 37, POKEMON_RASAFF, ITEM_FOKUS_BAND, ATTACK_POWER_PUNCH, ATTACK_ANZIEHUNG, ATTACK_NACHTHIEB, ATTACK_STEINKANTE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 39, POKEMON_LUCARIO, ITEM_TAMOTBEERE, ATTACK_NAHKAMPF, ATTACK_STEINKANTE, ATTACK_ERDBEBEN, ATTACK_PATRONENHIEB)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xb3[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE, 0x0,false,false,5,POKEMON_WELUNO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, TRAINER_BUILD_SPECIAL_TANK, 0x0,false,false,5,POKEMON_SCHIGGY)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xb4[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE, 0x0,false,false,5,POKEMON_SEEKID),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, TRAINER_BUILD_SPECIAL_TANK, 0x0,false,false,5,POKEMON_BISASAM)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xb5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, TRAINER_BUILD_PHYSICAL_TANK, 0x0,false,false,5,POKEMON_LOCKSCHAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE,0x0,false,false,5,POKEMON_GLUMANDA)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_xb9[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 20, POKEMON_SCHILLOK, ITEM_NONE, ATTACK_AQUAWELLE, ATTACK_AURORASTRAHL, ATTACK_AURASPHAERE, ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE, 0x0, false, false, 21, POKEMON_ORTHODOS, ITEM_TSITRUBEERE, ATTACK_GLUT, ATTACK_BISS, ATTACK_ZERSCHNEIDER, ATTACK_KRATZER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 19, POKEMON_OWEI, ITEM_NONE, ATTACK_MEGASAUGER, ATTACK_KONFUSION, ATTACK_HYPNOSE, ATTACK_REFLEKTOR)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_xba[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 20, POKEMON_BISAKNOSP, ITEM_NONE, ATTACK_SCHLAFPUDER, ATTACK_EGELSAMEN, ATTACK_SAEURE, ATTACK_ENERGIEBALL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE, 0x0, false, false, 21, POKEMON_SEESKULL, ITEM_TSITRUBEERE, ATTACK_FINTE, ATTACK_AURORASTRAHL, ATTACK_AQUAWELLE, ATTACK_KONFUSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_MIXED_SWEEPER, 0x0, false, false, 19, POKEMON_MAGBY, ITEM_NONE, ATTACK_GLUT, ATTACK_DONNERSCHLAG, ATTACK_DURCHBRUCH, ATTACK_FINTE)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_xbb[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 20, POKEMON_GLUTEXO, ITEM_NONE, ATTACK_METALLKLAUE, ATTACK_FEUERSCHLAG, ATTACK_DRACHENTANZ, ATTACK_STEINHAGEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 21, POKEMON_STICHSCHAL, ITEM_TSITRUBEERE, ATTACK_LAUBKLINGE, ATTACK_NATUR_KRAFT, ATTACK_EISENABWEHR, ATTACK_DURCHBRUCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 19, POKEMON_MARILL, ITEM_NONE, ATTACK_EISHIEB, ATTACK_WASSERDUESE, ATTACK_KNUDDLER, ATTACK_SCHAUFLER)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_xbc[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 39, POKEMON_TURTOK, ITEM_ZAUBERWASSER, ATTACK_EISSTRAHL, ATTACK_SURFER, ATTACK_SCHAEDELWUMME, ATTACK_AURASPHAERE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 38, POKEMON_KOKOWEI, ITEM_LICHTLEHM, ATTACK_PSYCHOKINESE, ATTACK_REFLEKTOR, ATTACK_LICHTSCHILD, ATTACK_ENERGIEBALL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE, 0x0, false, false, 41, POKEMON_ZERBERTRES, ITEM_TSITRUBEERE, ATTACK_ZORNFEUER, ATTACK_FINSTERAURA, ATTACK_SONDERSENSOR, ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 40, POKEMON_KNARKSEL, ITEM_KIWANBEERE, ATTACK_TACKLE, ATTACK_DRACHENKLAUE, ATTACK_STEINHAGEL, ATTACK_SCHLITZER)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_xbd[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 39, POKEMON_BISAFLOR, ITEM_WUNDERSAAT, ATTACK_SCHLAFPUDER, ATTACK_EGELSAMEN, ATTACK_SYNTHESE, ATTACK_GIGASAUGER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 38, POKEMON_MAGMAR, ITEM_FEUERJUWEL, ATTACK_FLAMMENWURF, ATTACK_KONFUSTRAHL, ATTACK_FOKUSSTOSS, ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE, 0x0, false, false, 41, POKEMON_SKULLYDRA, ITEM_TSITRUBEERE, ATTACK_TSUNAMI, ATTACK_DRACHENPULS, ATTACK_FINSTERAURA, ATTACK_EISENSCHWEIF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 40, POKEMON_DRASCHEL, ITEM_KIWANBEERE, ATTACK_DRACHENKLAUE, ATTACK_SCHUTZSCHILD, ATTACK_BODYCHECK, ATTACK_GLUT)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_xbe[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE, 0x1, false, false, 39, POKEMON_GLURAK, ITEM_HOLZKOHLE, ATTACK_FLAMMENWURF, ATTACK_FLIEGEN, ATTACK_STEINHAGEL, ATTACK_DUNKELKLAUE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 38, POKEMON_AZUMARILL, ITEM_SEEGESANG, ATTACK_KNUDDLER, ATTACK_NASSSCHWEIF, ATTACK_KRAFTKOLOSS, ATTACK_EISHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 41, POKEMON_STAHLSTICH, ITEM_TSITRUBEERE, ATTACK_SAMENBOMBEN, ATTACK_STAHLSTREICH, ATTACK_SCHLITZER, ATTACK_SCHWERTTANZ),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 40, POKEMON_DRAGONIR, ITEM_KIWANBEERE, ATTACK_DONNERWELLE, ATTACK_DONNERBLITZ, ATTACK_DRACHENPULS, ATTACK_SURFER)
};


static trainer_pokemon_default_item_default_attacks trainer_party_xbf_inferior_gym[] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 36, POKEMON_DARTIGNIS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 35, POKEMON_CAMAUB),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 36, POKEMON_MAGMAR),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc0_inferior_gym[] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 39, POKEMON_CAMERUPT),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc1_inferior_gym[] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 35, POKEMON_VULNONA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 38, POKEMON_IGELAVAR),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc2_inferior_gym[] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 34, POKEMON_MAGCARGO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 35, POKEMON_FUKANO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 35, POKEMON_GLUTEXO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc3_inferior_gym[] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 40, POKEMON_GLURAK)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_xc4_inferior_gymleader[] = {
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
      0x0, true, false, 41, POKEMON_FIARO, ITEM_HACKATTACK,
      ATTACK_STURZFLUG, ATTACK_FLAMMENBLITZ, ATTACK_STAHLFLUEGEL, ATTACK_HITZEKOLLER),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 40, POKEMON_GLURAK, ITEM_SCHLOHKRAUT,
      ATTACK_HITZEKOLLER, ATTACK_WINDSCHNITT, ATTACK_SOLARSTRAHL, ATTACK_SONNENTAG),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
      0x0, false, false, 42, POKEMON_ARKANI, ITEM_SINELBEERE,
      ATTACK_TURBOTEMPO, ATTACK_KNIRSCHER, ATTACK_FLAMMENBLITZ, ATTACK_HITZEKOLLER),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 44, POKEMON_MAGBRANT, ITEM_TSITRUBEERE,
      ATTACK_HITZEKOLLER, ATTACK_FOKUSSTOSS, ATTACK_DONNERBLITZ, ATTACK_PSYCHOKINESE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc5_route_8_trainer_0[] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 21, POKEMON_RABAUZ),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 23, POKEMON_MACHOLLO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc6_route_8_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 20, POKEMON_QUABBEL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 22, POKEMON_SCHMERBE),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 21, POKEMON_BARSCHWA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc7_route_8_trainer_2[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 21, POKEMON_SICHLOR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 21, POKEMON_WEBARAK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc8_route_8_trainer_3[5] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 18, POKEMON_TOGEPI),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 18, POKEMON_MAMPFAXO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 19, POKEMON_MARILL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 18, POKEMON_MAGBY),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 19, POKEMON_MOBAI),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xc9_route_8_trainer_4[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_MEDITALIS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xcA_route_9_trainer_0[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_TENTACHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_WAILMER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_SEEMON),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xcb_route_9_trainer_1[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_MARILL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_KARNIMANI),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xcc_route_9_trainer_2[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_PELIPPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_STERNDU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_SCHILLOK)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xcd_route_9_trainer_3[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_SAGANABYSS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_AALABYSS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xce_route_9_trainer_4[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_KANIVANHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_STARMIE),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_WAILMER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xcf_route_9_trainer_5[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_DODRI),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_MEDITALIS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_VOLTENSO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd0_route_9_trainer_6[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_WAILORD)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd1_route_9_trainer_7[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_SEESKULL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_TOHAIDO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_WINGULL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd2_route_9_trainer_8[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 33, POKEMON_BARSCHWA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_GARADOS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd3_route_9_trainer_9[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_AZUMARILL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_SEEMOPS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_QUABBEL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd4_route_9_trainer_10[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_APOQUALLYP)
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd5_route_9_trainer_11[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_JUROB),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_TENTACHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd6_route_9_trainer_12[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_WAILMER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_KINGLER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_PELIPPER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd7_route_9_trainer_13[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_MUSCHAS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_TENTOXA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd8_route_10_trainer_0[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_STARMIE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xd9_route_10_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_KARPADOR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_SEEPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_GARADOS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xda_route_10_trainer_2[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_KANIVANHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_JUROB),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xdb_route_10_trainer_3[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_TOHAIDO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xdc_route_10_trainer_4[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_DODU),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_MASCHOCK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xdd_route_10_trainer_5[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_MARILL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_KANIVANHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_TENTACHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xde_route_10_trainer_6[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_AUSTOS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_KRABBY),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_WINGULL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xdf_route_10_trainer_7[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_MACHOMEI),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe0_route_10_trainer_8[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_PELIPPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_SCHWALBOSS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_MASKEREGEN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe1_route_11_trainer_0[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_QUABBEL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_WINGULL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_KANIVANHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe2_route_11_trainer_1[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_VOLTENSO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_DODU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe3_route_11_trainer_2[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_JUGONG),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe4_route_11_trainer_3[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_WAILMER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_PELIPPER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe5_route_11_trainer_4[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_NEBULAK),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_PARAGONI),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_SHUPPET),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe6_route_11_trainer_5[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_KADABRA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_XATU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe7_route_11_trainer_6[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_PERLU),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_AZUMARILL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_BARSCHWA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe8_route_11_trainer_7[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_KRABBY),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_TENTOXA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xe9_route_11_trainer_8[4] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_KARPADOR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_TENTACHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_QUABBEL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_TOHAIDO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xea_forest_cemetery_trainer_0[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_ALPOLLO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_ZWIRRLICHT),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_PARAGONI),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xeb_forest_cemetery_trainer_1[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_ARIADOS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_SICHLOR),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xec_forest_cemetery_trainer_2[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_BANETTE),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_NEBULAK),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_LICHTEL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xed_forest_cemetery_trainer_3[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_LATERNECTO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_SIMSALA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_TENGULIST),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xee_forest_cemetery_trainer_4[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 44, POKEMON_SKELABRA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xef_forest_cemetery_trainer_5[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_SHUPPET),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_ALPOLLO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xf0_forest_cemetery_trainer_6[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 43, POKEMON_TROMBORK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xf1_forest_cemetery_trainer_7[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_BRONZEL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_HYPNO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_GOLBAT),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xf2_forest_cemetery_trainer_8[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_SLEIMA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_SMOGON),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xfc_route_12_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_TRAUNFUGIL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_LATERNECTO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xfd_route_12_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_SEEPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_PELIPPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_LANTURN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xfe_route_12_trainer_2[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 44, POKEMON_GARADOS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_xff_route_12_trainer_3[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 43, POKEMON_STARAPTOR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 44, POKEMON_KREBUTACK),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_MEDITALIS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x100_route_12_trainer_4[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_APOQUALLYP),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_KANIVANHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x101_route_12_trainer_5[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_SEESKULL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_WAILORD),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x102_route_12_trainer_6[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_PELIPPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_SCHILLOK),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_TENTACHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x103_route_12_trainer_7[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 43, POKEMON_TURTOK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x104_route_12_trainer_8[4] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_KARPADOR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_TENTACHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_BARSCHWA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_GARADOS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x105_route_12_trainer_9[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_SCHWALBOSS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_XATU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x106_route_12_trainer_10[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_WAILMER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_SEEMON),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_TENTOXA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x107_route_12_trainer_11[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_MASCHOCK),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_KREBUTACK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x108_route_12_trainer_12[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_TENTACHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_PERLU),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_QUABBEL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x109_route_12_trainer_13[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_ARKANI),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_SLEIMOK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x10a_route_12_trainer_14[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_AZUMARILL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_GERADAKS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_REMORAID),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x10b_route_12_trainer_15[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_QUABBEL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_TYRACROC),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x10c_route_12_trainer_16[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_GEOWAZ),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_TROPIUS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_FEELINARA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x10d_route_12_trainer_17[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_TOHAIDO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_SMOGMOG),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x10e_route_12_trainer_18[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_MUNTIER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_RASAFF),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_AMBIDIFFEL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x10f_route_12_trainer_19[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_TENTOXA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_OCTILLERY),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x110_route_12_trainer_20[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_PELIPPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_SCHILLOK),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_KAPPALORES),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x111_route_2_clouds_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_PANZAERON),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_WABLU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x112_route_2_clouds_trainer_1[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_IKSBAT),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x113_route_2_clouds_trainer_2[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_PELIPPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_SCHWALBINI),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_DARTIGNIS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x114_route_2_clouds_trainer_3[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_AERODACTYL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x115_route_2_clouds_trainer_4[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_SCHWALBOSS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_DARTIRI),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_DODU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x116_route_5_clouds_trainer_2[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_DODU),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_TYRACROC),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x117_orina_city_clouds_trainer_0[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_TOGEKISS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x118_orina_city_clouds_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_FLAMARA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_VOLTENSO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_KRAMSHEF),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x119_orina_city_clouds_trainer_2[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_LEPUMENTAS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_GEOROK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x11a_route_6_clouds_trainer_0[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_FOLIPURBA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 33, POKEMON_GUARDEVOIR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_MAGNAYEN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x11b_route_6_clouds_trainer_1[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_DARTIGNIS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 33, POKEMON_LEDIAN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x11c_inferior_clouds_trainer_0[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_ALTARIA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x11d_route_4_clouds_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_DODU),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_WABLU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x11e_route_4_clouds_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 33, POKEMON_DARTIGNIS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_KRAMURX),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_PELIPPER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x11f_kaskada_clouds_trainer_0[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_LEPUMENTAS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x120_kaskada_clouds_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 29, POKEMON_NIDORINO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_RASAFF),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 30, POKEMON_MAGNAYEN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x121_felsige_oednis_clouds_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 29, POKEMON_IGELAVAR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_LOMBRERO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x122_felsige_oednis_clouds_trainer_1[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_MASKEREGEN),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_SCHWALBOSS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x123_silvania_clouds_trainer_0[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 29, POKEMON_KRAMURX),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 30, POKEMON_WINGULL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_DARTIGNIS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x124_route_3_clouds_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_MASKEREGEN),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_LEDIAN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x125_silvania_wald_clouds_trainer_0[4] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 28, POKEMON_SICHLOR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_BIBOR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 28, POKEMON_MASKEREGEN),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_LEDIAN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x126_silvania_wald_clouds_trainer_1[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_GIFLOR),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x127_route_8_clouds_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_SCHWALBOSS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_DARTIGNIS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x128_laubdorf_clouds_trainer_0[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_PAPINELLA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_ENEKORO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_FLOETTE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x129_route_9_clouds_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_KIRLIA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_BRONZONG),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x12a_route_9_clouds_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_SCHWALBOSS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_DODRI),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 33, POKEMON_SKORGLA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x12b_route_9_clouds_trainer_2[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_MAGMAR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_IGELAVAR),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x12c_aktania_clouds_trainer_0[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_GEOWAZ),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x12d_kuestenberg_clouds_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_TENTACHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_SCHILLOK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x12e_route_11_clouds_trainer_0[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 33, POKEMON_KARPADOR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_QUABBEL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_SEEPER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x12f_ceometria_clouds_trainer_0[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_NEBULAK),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 33, POKEMON_TRAUNFUGIL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_SHUPPET),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x130_route_12_clouds_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_GERADAKS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_LEDIAN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x131_route_12_clouds_trainer_1[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_FIARO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x132_route_12_clouds_trainer_2[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_VOLTENSO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_MAGNETON),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x133_haweiland_clouds_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_SANDAMER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_BRONZEL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x134_haweiland_clouds_trainer_1[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_LEDIAN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x135_haweiland_cargo_hall_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_KRABBY),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_KANIVANHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x136_haweiland_cargo_hall_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_KABUTO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_MUSCHAS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_QUABBEL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x137_haweiland_cargo_hall_trainer_2[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_TOHAIDO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x138_haweiland_cargo_hall_trainer_3[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_WINGULL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_AALABYSS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x139_haweiland_cargo_hall_trainer_4[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_KINGLER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_SAGANABYSS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_PELIPPER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x13a_haweiland_cargo_hall_trainer_5[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_KABUTOPS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_SEEMON),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_TOHAIDO),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x13b_haweiland_may[4] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
      0x0, false, false, 44, POKEMON_STARAPTOR, ITEM_HACKATTACK,
      ATTACK_STURZFLUG, ATTACK_NAHKAMPF, ATTACK_STAHLFLUEGEL, ATTACK_RUCKZUCKHIEB),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 46, POKEMON_SKULLYDRA, ITEM_TSITRUBEERE,
      ATTACK_TSUNAMI, ATTACK_DRACHENPULS, ATTACK_FINSTERAURA, ATTACK_EISSTRAHL),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_SPECIAL_WALL_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 45, POKEMON_GIFLOR, ITEM_UEBERRESTE,
      ATTACK_GIGASAUGER, ATTACK_MATSCHBOMBE, ATTACK_SYNTHESE, ATTACK_TOXIN),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_PHYSICAL_TANK,
      0x0, false, false, 43, POKEMON_FLAMARA, ITEM_HOLZKOHLE,
      ATTACK_FLAMMENBLITZ, ATTACK_KRAFTKOLOSS, ATTACK_WUNSCHTRAUM, ATTACK_SCHUTZSCHILD),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x13c_haweiland_may[4] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
      0x0, false, false, 44, POKEMON_STARAPTOR, ITEM_HACKATTACK,
      ATTACK_STURZFLUG, ATTACK_NAHKAMPF, ATTACK_STAHLFLUEGEL, ATTACK_RUCKZUCKHIEB),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_PHYSICAL_TANK,
      0x0, false, false, 46, POKEMON_STAHLSTICH, ITEM_TSITRUBEERE,
      ATTACK_LAUBKLINGE, ATTACK_STAHLSTREICH, ATTACK_SCHWERTTANZ, ATTACK_NAHKAMPF),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_SPECIAL_WALL_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 45, POKEMON_ARKANI, ITEM_HOLZKOHLE,
      ATTACK_FLAMMENBLITZ, ATTACK_TURBOTEMPO, ATTACK_KNIRSCHER, ATTACK_NAHKAMPF),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_SPECIAL_WALL_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 43, POKEMON_AQUANA, ITEM_UEBERRESTE,
      ATTACK_SURFER, ATTACK_EISSTRAHL, ATTACK_WUNSCHTRAUM, ATTACK_SCHUTZSCHILD),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x13d_haweiland_may[4] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
      0x0, false, false, 44, POKEMON_STARAPTOR, ITEM_HACKATTACK,
      ATTACK_STURZFLUG, ATTACK_NAHKAMPF, ATTACK_STAHLFLUEGEL, ATTACK_RUCKZUCKHIEB),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_PHYSICAL_TANK,
      0x0, false, false, 46, POKEMON_ZERBERTRES, ITEM_TSITRUBEERE,
      ATTACK_ZORNFEUER, ATTACK_FINSTERAURA, ATTACK_BLITZ, ATTACK_PSYCHOKINESE),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_SPECIAL_WALL_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 45, POKEMON_TENTOXA, ITEM_UEBERRESTE,
      ATTACK_TOXIN, ATTACK_SURFER, ATTACK_SCHUTZSCHILD, ATTACK_EISSTRAHL),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_PHYSICAL_SWEEPER_SPEED_PREFERENCE,
      0x0, false, false, 43, POKEMON_FOLIPURBA, ITEM_WUNDERSAAT,
      ATTACK_LAUBKLINGE, ATTACK_ABSCHLAG, ATTACK_AERO_ASS, ATTACK_KREUZSCHERE),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_ceometria_gym_leader[4] = {
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_TANK,
      0x0, true, false, 47, POKEMON_APOQUALLYP, ITEM_ZAUBERWASSER,
      ATTACK_GENESUNG, ATTACK_SPUKBALL, ATTACK_SURFER, ATTACK_IRRLICHT),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_SPECIAL_TANK,
      0x0, false, false, 46, POKEMON_TROMBORK, ITEM_TSITRUBEERE,
      ATTACK_SPUKBALL, ATTACK_ENERGIEBALL, ATTACK_EGELSAMEN, ATTACK_IRRLICHT),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(48,  TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 48, POKEMON_GENGAR, ITEM_BANNSTICKER,
      ATTACK_SPUKBALL, ATTACK_DONNERBLITZ, ATTACK_FOKUSSTOSS, ATTACK_MATSCHBOMBE),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_PHYSICAL_WALL_ATTACK_PREFERENCE,
      0x0, false, false, 49, POKEMON_ZWIRRFINST, ITEM_UEBERRESTE,
      ATTACK_SCHATTENSTOSS, ATTACK_IRRLICHT, ATTACK_LEIDTEILER, ATTACK_ERDBEBEN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x13f_route_7_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_GLUTEXO),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_FUKANO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x140_route_7_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_ONIX),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_MASCHOCK),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_GEOROK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x141_route_7_trainer_2[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_MAGNETON),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_VOLTENSO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x142_route_7_trainer_3[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_KANIVANHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_QUABBEL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_REMORAID),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x143_route_7_trainer_4[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 43, POKEMON_MACHOMEI),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x144_route_7_trainer_5[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_GERADAKS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_SMOGMOG),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_KIRLIA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x145_route_7_trainer_6[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_ULTRIGARIA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_CHEVRUMM),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x146_route_7_trainer_7[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_SCHWALBOSS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_DARTIGNIS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x147_route_7_trainer_8[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_HUNDEMON),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x148_route_7_trainer_9[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_DODRI),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_KICKLEE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x149_route_7_trainer_10[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_SANDAMER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_MARILL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_KRABBY),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x14a_route_7_trainer_11[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_STARMIE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x14b_route_7_trainer_12[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_TYRACROC),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_NIDORINA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x14c_route_7_trainer_13[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_MASCHOCK),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_PELIPPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_MAGNETON),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x14d_route_7_trainer_14[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_TENTACHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_QUABBEL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x14e_route_7_trainer_15[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 43, POKEMON_TURTOK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x14f_route_7_trainer_16[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_GERADAKS),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_OWEI),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_PIKACHU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x150_route_7_trainer_17[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_HUNDEMON),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_MAGNAYEN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x151_route_7_trainer_18[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_PELIPPER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 40, POKEMON_MASCHOCK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x152_route_7_trainer_19[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_WAILMER),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_QUABBEL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_SEESKULL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x153_route_7_trainer_20[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_AZUMARILL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x154_route_7_trainer_21[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_MAGNETON),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_KADABRA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_SLEIMOK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x155_route_7_trainer_22[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_KANIVANHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_GARADOS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x156_route_7_trainer_23[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_QUABBEL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_TENTACHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x157_route_7_trainer_24[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_KREBUTACK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x158_route_7_trainer_25[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_ENTORON),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_TENTACHA),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 38, POKEMON_TYRACROC),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x159_ardeal_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 43, POKEMON_STARAPTOR),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_DUOKLES),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x15a_ardeal_trainer_1[3] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 42, POKEMON_STICHSCHAL),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_HUNDEMON),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 43, POKEMON_GRIFFEL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x15b_ardeal_trainer_2[1] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 44, POKEMON_PSIANA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x15c_ardeal_trainer_3[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 44, POKEMON_IKSBAT),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 45, POKEMON_HYPNO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x15d_ardeal_trainer_4[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 45, POKEMON_SMOGMOG),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 43, POKEMON_SLEIMOK),
};


static trainer_pokemon_custom_item_custom_attacks trainer_party_x15e_ardeal_lucius[6] = {
	// TODO: Give Lucius a proper mega
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(31, TRAINER_BUILD_PHYSICAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 87, POKEMON_TROPIUS, ITEM_TROPIUSNIT, ATTACK_ERDBEBEN, ATTACK_DRACHENKLAUE, ATTACK_DONNERSCHLAG, ATTACK_STEINKANTE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(31, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 89, POKEMON_DURENGARD, ITEM_UEBERRESTE, ATTACK_KOENIGSSCHILD, ATTACK_STAHLSTREICH, ATTACK_SCHATTENSTOSS, ATTACK_SCHWERTTANZ),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(31, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 86, POKEMON_STAHLSTICH, ITEM_WUNDERSAAT, ATTACK_LAUBKLINGE, ATTACK_STAHLSTREICH, ATTACK_STEINKANTE, ATTACK_NAHKAMPF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(31, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 87, POKEMON_MILOTIC, ITEM_SEEGESANG, ATTACK_SURFER, ATTACK_EISSTRAHL, ATTACK_HYPNOSE, ATTACK_GENESUNG),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(31, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 88, POKEMON_BRUTALANDA, ITEM_LEBEN_ORB, ATTACK_WUTANFALL, ATTACK_ERDBEBEN, ATTACK_STEINKANTE, ATTACK_AERO_ASS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(31, TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 85, POKEMON_GLURAK, ITEM_SCHLOHKRAUT, ATTACK_HITZEKOLLER, ATTACK_WINDSCHNITT, ATTACK_FOKUSSTOSS, ATTACK_SOLARSTRAHL),
	};

	trainer_pokemon_custom_item_custom_attacks trainer_party_x15f_route_2_rival_plant_starter[2] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 10, POKEMON_BISASAM, ITEM_NONE, ATTACK_RANKENHIEB, ATTACK_TACKLE, ATTACK_HEULER, ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE, 0x0, false, false, 11, POKEMON_WELUNO, ITEM_SINELBEERE, ATTACK_GLUT, ATTACK_JAULER, ATTACK_KRATZER, ATTACK_NONE),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x160_route_2_rival_fire_starter[2] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 10, POKEMON_GLUMANDA, ITEM_NONE, ATTACK_KRATZER, ATTACK_HEULER, ATTACK_GLUT, ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE, 0x0, false, false, 11, POKEMON_SEEKID, ITEM_SINELBEERE, ATTACK_PFUND, ATTACK_SILBERBLICK, ATTACK_AQUAKNARRE, ATTACK_NONE),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x161_route_2_rival_water_starter[2] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 10, POKEMON_SCHIGGY, ITEM_NONE, ATTACK_TACKLE, ATTACK_AQUAKNARRE, ATTACK_PANZERSCHUTZ, ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 11, POKEMON_LOCKSCHAL, ITEM_SINELBEERE, ATTACK_PFUND, ATTACK_HAERTNER, ATTACK_RASIERBLATT, ATTACK_NONE),
};


static trainer_pokemon_default_item_default_attacks trainer_party_x162_route_2_east_trainer_0[2] = {
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 7, POKEMON_HORNLIU),
  TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 7, POKEMON_NINCADA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x163_route_2_trainer_0[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 12, POKEMON_PUMMELUFF),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x164_route_2_grunt_second[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 12, POKEMON_ZUBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 11, POKEMON_TRAUMATO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x165_route_2_twins[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 13, POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 13, POKEMON_VOLTOBAL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x166_route_2_trainer_1[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 11, POKEMON_DARTIRI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 10, POKEMON_ZIGZACHS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x167_route_3_trainer_0[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 18, POKEMON_MACHOLLO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x168_felsige_oednis_trainer_0[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 24, POKEMON_NASGNET),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x169_kuestenberg_felix[3] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0, 0, 0, 34, 
		POKEMON_MUNTIER, ITEM_SEIDENSCHAL, ATTACK_SCHLITZER, ATTACK_DUNKELKLAUE, ATTACK_AERO_ASS, ATTACK_NACHTHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_SPECIAL_TANK, 0, 0, 0, 36, 
		POKEMON_SCHLURP, ITEM_NORMALJUWEL, ATTACK_SLAM, ATTACK_SCHLECKER, ATTACK_DONNERBLITZ, ATTACK_FLAMMENWURF),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(17, TRAINER_BUILD_PHYSICAL_TANK, 0, 0, 0, 35, 
		POKEMON_KNUDDELUFF, ITEM_FLINKKLAUE, ATTACK_RISIKOTACKLE, ATTACK_KNUDDLER, ATTACK_DURCHBRUCH, ATTACK_DONNERSCHLAG),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x16a_kuestenberg_revolutionaer[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 33, POKEMON_DONPHAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 34, POKEMON_TOHAIDO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x16b_route_4_trainer_couple[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_SNUBBULL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_KNUDDELUFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 32, POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 33, POKEMON_NIDORINO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x16c_route_5_trainer_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 30, POKEMON_WABLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 31, POKEMON_KIRLIA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x16d_route_5_twins[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_LEDYBA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_GEHWEIHER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_PUMMELUFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_FLOETTE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x16e_route_6_trainer_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_KAPOERA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 39, POKEMON_MASCHOCK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x16f_route_6_couple[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 36, POKEMON_MARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 35, POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0, 0x0, false, false, 37, POKEMON_SNUBBULL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x171_volcano_grunt_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_GOLBAT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_MOLUNK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x172_volcano_grunt_1[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_ZOBIRIS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x173_volcano_grunt_2[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_NIDOKING),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_AMFIRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_OCTILLERY),
};


static trainer_pokemon_custom_item_custom_attacks trainer_party_x170_volcano_igva_ally[3] = {
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
      0x0, true, false, 41, POKEMON_FIARO, ITEM_HACKATTACK,
      ATTACK_STURZFLUG, ATTACK_FLAMMENBLITZ, ATTACK_STAHLFLUEGEL, ATTACK_HITZEKOLLER),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 40, POKEMON_GLURAK, ITEM_SCHLOHKRAUT,
      ATTACK_HITZEKOLLER, ATTACK_WINDSCHNITT, ATTACK_SOLARSTRAHL, ATTACK_SONNENTAG),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 44, POKEMON_MAGBRANT, ITEM_TSITRUBEERE,
      ATTACK_HITZEKOLLER, ATTACK_FOKUSSTOSS, ATTACK_DONNERBLITZ, ATTACK_PSYCHOKINESE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x174_route_9_swimmer_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_WAILMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_PELIPPER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x175_route_9_swimmer_1[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_REMORAID),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_SEEMOPS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x176_route_8_psycho_0[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,24,POKEMON_PSIANA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x177_route_8_couple[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_PAPINELLA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,23,POKEMON_PUDOX),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x178_route_10_couple[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_AUSTOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_ONIX),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x179_route_7_twins[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_VOLTOBAL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x17a_route_7_beatuy[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_ENEKORO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_SNUBBULL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x17b_route_7_picknicker[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_NIDORINO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x17c_route_12_couple[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_NIDORINO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x17d_route_11_couple[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_LOMBRERO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_BLANAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_ENEKORO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_VOLTENSO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x17e_ceometria_clouds_witch_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_TRAUNFUGIL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_ALPOLLO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x17f_ceometria_clouds_witch_1[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_ZWIRRLICHT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_LICHTEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_NEBULAK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x180_ceometria_clouds_ruin_maniac_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_DIGDA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_PUPPANCE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x181_dark_tower_trainer_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,40,POKEMON_PARAGONI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,41,POKEMON_BANETTE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x182_dark_tower_trainer_1[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_NEBULAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_ZOBIRIS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,40,POKEMON_QUABBEL),
};


static trainer_pokemon_default_item_default_attacks trainer_party_x183_dark_tower_trainer_2[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,41,POKEMON_TRAUNFUGIL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,40,POKEMON_ZWIRRLICHT),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x184_bbship_storage_pirate_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44,POKEMON_KREBSCORPS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,45,POKEMON_KANIVANHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x185_bbship_storage_pirate_1[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_TOHAIDO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x186_bbship_storage_pirate_2[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44,POKEMON_PERLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44,POKEMON_TYRACROC),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x187_bbship_storage_pirate_3[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,43,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,45,POKEMON_TENTACHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x188_bbship_storage_pirate_4[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44,POKEMON_LANTURN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,42,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,43,POKEMON_SEEMOPS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x189_bbship_storage_pirate_5[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44,POKEMON_REMORAID),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44,POKEMON_WAILMER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x18a_bbship_cells_pirate0[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,45,POKEMON_REMORAID),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,45,POKEMON_KARNIMANI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44,POKEMON_PERLU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x18b_bbship_canon_room_pirate0[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44,POKEMON_STERNDU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,43,POKEMON_WINGULL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_KINGLER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x18c_bbship_cabin_pirate0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,45,POKEMON_OCTILLERY),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_TENTACHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x18d_bbship_cabin_pirate1[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,45,POKEMON_KANIVANHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_SCHIGGY),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x18e_bbship_cabins_pirate0[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_BARSCHWA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_KRABBY),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_SEEJONG),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x18f_bbship_cabins_pirate1[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_SEEMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_PELIPPER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x190_bbship_cabins_pirate2[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_KANIVANHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_KREBSCORPS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x191_bbship_cabins_pirate3[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,49,POKEMON_KREBUTACK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x192_bbship_deck_pirate0[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_LAMPI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_STERNDU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,45,POKEMON_TENTACHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x193_bbship_deck_pirate1[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_SCHILLOK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x194_bbship_deck_pirate2[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_REMORAID),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44,POKEMON_WAILMER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x195_bbship_deck_pirate3[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,48,POKEMON_SAGANABYSS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_AUSTOS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x196_bbship_deck_pirate4[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,50,POKEMON_SKULLYDRA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x197_bbship_deck_pirate5[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_WELSAR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_AQUANA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,48,POKEMON_APOQUALLYP),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_TENTOXA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x198_bbship_deck_pirate6[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,46,POKEMON_GARADOS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,48,POKEMON_TOHAIDO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_KREBUTACK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,47,POKEMON_MAGNAYEN),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x199_bbship_blackbeard[5] = {
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(22,
      TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 49, POKEMON_TOHAIDO, ITEM_LEBEN_ORB,
      ATTACK_EISZAHN, ATTACK_KASKADE, ATTACK_KNIRSCHER, ATTACK_GIFTZAHN),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(22,
      TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
      0x0, false, false, 51, POKEMON_GARADOS, ITEM_UEBERRESTE,
      ATTACK_EISZAHN, ATTACK_DRACHENTANZ, ATTACK_ERDBEBEN, ATTACK_KASKADE),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(22,  TRAINER_BUILD_SPECIAL_TANK,
      0x0, true, false, 52, POKEMON_OCTILLERY, ITEM_OCTILLERYNIT,
      ATTACK_HYDROPUMPE, ATTACK_EISSTRAHL, ATTACK_LICHTKANONE, ATTACK_ENERGIEBALL),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(22,
      TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE,
      0x0, false, false, 50, POKEMON_SKULLYDRA, ITEM_ZAUBERWASSER,
      ATTACK_TSUNAMI, ATTACK_DRACHENPULS, ATTACK_FINSTERAURA, ATTACK_EISSTRAHL),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(22,
      TRAINER_BUILD_SPECIAL_WALL_SPECIAL_ATTACK_PREFERENCE,
      0, false, false, 49, POKEMON_LANTURN, ITEM_MARONBEERE,
      ATTACK_DONNERWELLE, ATTACK_SURFER, ATTACK_ERHOLUNG, ATTACK_DONNERBLITZ),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_test[2] = {
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
      TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
      0x0, false, false, 40, POKEMON_OCTILLERY, ITEM_OCTILLERYNIT,
      ATTACK_HITZEKOLLER, ATTACK_WINDSCHNITT, ATTACK_SOLARSTRAHL, ATTACK_SONNENTAG),
  TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
      0x0, true, false, 41, POKEMON_FIARO, ITEM_SCHWARZPULVER,
      ATTACK_STURZFLUG, ATTACK_FLAMMENBLITZ, ATTACK_STAHLFLUEGEL, ATTACK_HITZEKOLLER),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x19a_meriana_city_blackbelt_in_front_of_gym[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,5,POKEMON_MACHOLLO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,5,POKEMON_MENKI),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x19b_route_2_streber[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,6,POKEMON_SLEIMA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x19c_route_2_cave_hiker[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9,POKEMON_ONIX),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x19d_route_2_cave_school_kid[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,8,POKEMON_FLABEBE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,8,POKEMON_MARILL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x19e_route_2_cave_teenager[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,9, POKEMON_FUKANO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x19f_bruchfels_gym_trainer1[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,15, POKEMON_KLEINSTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,14, POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,13, POKEMON_MOBAI),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1a0_bruchfels_gym_trainer2[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,17, POKEMON_RIHORN),
};

// Lester's parties

static trainer_pokemon_custom_item_custom_attacks trainer_party_xb6[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x1, false, false, 15, POKEMON_ONIX, ITEM_SINELBEERE, ATTACK_FELSGRAB, ATTACK_STEINPOLITUR, ATTACK_KLAMMERGRIFF, ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 16, POKEMON_GEOROK, ITEM_LYDZIBEERE, ATTACK_INTENSITAET, ATTACK_STEINPOLITUR, ATTACK_FELSGRAB, ATTACK_FINALE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 17, POKEMON_STOLLUNIOR, ITEM_TSITRUBEERE, ATTACK_BODYCHECK, ATTACK_INTENSITAET, ATTACK_FELSGRAB, ATTACK_METALLKLAUE)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1a1_lester_difficulty_normal[4] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 17, POKEMON_NASGNET, ITEM_UEBERRESTE, ATTACK_DONNERWELLE, ATTACK_SANDSTURM, ATTACK_FUNKENSPRUNG, ATTACK_FELSGRAB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x1, false, false, 18, POKEMON_ONIX, ITEM_SINELBEERE, ATTACK_FELSGRAB, ATTACK_STEINPOLITUR, ATTACK_KLAMMERGRIFF, ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 17, POKEMON_GEOROK, ITEM_LYDZIBEERE, ATTACK_INTENSITAET, ATTACK_STEINPOLITUR, ATTACK_FELSGRAB, ATTACK_FINALE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 19, POKEMON_STOLLUNIOR, ITEM_TSITRUBEERE, ATTACK_BODYCHECK, ATTACK_INTENSITAET, ATTACK_FELSGRAB, ATTACK_METALLKLAUE),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1a2_lester_difficulty_hard[6] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 17, POKEMON_NASGNET, ITEM_UEBERRESTE, ATTACK_DONNERWELLE, ATTACK_SANDSTURM, ATTACK_FUNKENSPRUNG, ATTACK_FELSGRAB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x1, false, false, 18, POKEMON_ONIX, ITEM_SINELBEERE, ATTACK_FELSGRAB, ATTACK_STEINPOLITUR, ATTACK_KLAMMERGRIFF, ATTACK_NONE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 17, POKEMON_GEOROK, ITEM_LYDZIBEERE, ATTACK_INTENSITAET, ATTACK_STEINPOLITUR, ATTACK_FELSGRAB, ATTACK_FINALE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 19, POKEMON_STOLLUNIOR, ITEM_TSITRUBEERE, ATTACK_BODYCHECK, ATTACK_INTENSITAET, ATTACK_FELSGRAB, ATTACK_METALLKLAUE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 18, POKEMON_RIHORN, ITEM_GRANITSTEIN, ATTACK_HORNATTACKE, ATTACK_FELSGRAB, ATTACK_DONNERZAHN, ATTACK_STAMPFER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 18, POKEMON_AERODACTYL, ITEM_LEBEN_ORB, ATTACK_FELSGRAB, ATTACK_FLUEGELSCHLAG, ATTACK_DONNERZAHN, ATTACK_FEUERZAHN),
};

// Rosalie's parties

static trainer_pokemon_custom_item_custom_attacks trainer_party_xb7[4] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 24, POKEMON_BISAKNOSP, ITEM_TSITRUBEERE, ATTACK_EGELSAMEN, ATTACK_GIGASAUGER, ATTACK_TOXIN, ATTACK_MATSCHBOMBE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 25, POKEMON_KAPILZ, ITEM_NONE, ATTACK_TEMPOHIEB, ATTACK_PILZSPORE, ATTACK_KOPFNUSS, ATTACK_SAMENBOMBEN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_WALL_ATTACK_PREFERENCE, 0x0, false, false, 23, POKEMON_KASTADUR, ITEM_TSITRUBEERE, ATTACK_EGELSAMEN, ATTACK_VERWURZLER, ATTACK_GIGASAUGER, ATTACK_SCHUTZSCHILD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 26, POKEMON_KAPPALORES, ITEM_BLENDPUDER, ATTACK_DOPPELTEAM, ATTACK_EGELSAMEN, ATTACK_AQUAWELLE, ATTACK_GIGASAUGER)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1a4_rosalie_difficulty_normal[5] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 26, POKEMON_BISAKNOSP, ITEM_TSITRUBEERE, ATTACK_EGELSAMEN, ATTACK_GIGASAUGER, ATTACK_TOXIN, ATTACK_MATSCHBOMBE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 27, POKEMON_KAPILZ, ITEM_NONE, ATTACK_TEMPOHIEB, ATTACK_PILZSPORE, ATTACK_KOPFNUSS, ATTACK_SAMENBOMBEN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_WALL_ATTACK_PREFERENCE, 0x0, false, false, 25, POKEMON_KASTADUR, ITEM_TSITRUBEERE, ATTACK_EGELSAMEN, ATTACK_VERWURZLER, ATTACK_GIGASAUGER, ATTACK_SCHUTZSCHILD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 29, POKEMON_KAPPALORES, ITEM_BLENDPUDER, ATTACK_DOPPELTEAM, ATTACK_EGELSAMEN, ATTACK_AQUAWELLE, ATTACK_GIGASAUGER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_MIXED_SWEEPER, 0x0, false, false, 26, POKEMON_TENGULIST, ITEM_SCHATTENGLAS, ATTACK_FINSTERAURA, ATTACK_EXPLOSION, ATTACK_GIGASAUGER, ATTACK_MOGELHIEB)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1a5_rosalie_difficulty_hard[6] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 26, POKEMON_BISAKNOSP, ITEM_TSITRUBEERE, ATTACK_EGELSAMEN, ATTACK_GIGASAUGER, ATTACK_TOXIN, ATTACK_MATSCHBOMBE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 27, POKEMON_KAPILZ, ITEM_NONE, ATTACK_TEMPOHIEB, ATTACK_PILZSPORE, ATTACK_KOPFNUSS, ATTACK_SAMENBOMBEN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_PHYSICAL_WALL_ATTACK_PREFERENCE, 0x0, false, false, 25, POKEMON_KASTADUR, ITEM_TSITRUBEERE, ATTACK_EGELSAMEN, ATTACK_VERWURZLER, ATTACK_GIGASAUGER, ATTACK_SCHUTZSCHILD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 29, POKEMON_KAPPALORES, ITEM_BLENDPUDER, ATTACK_DOPPELTEAM, ATTACK_EGELSAMEN, ATTACK_AQUAWELLE, ATTACK_GIGASAUGER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_MIXED_SWEEPER, 0x0, false, false, 26, POKEMON_TENGULIST, ITEM_SCHATTENGLAS, ATTACK_FINSTERAURA, ATTACK_EXPLOSION, ATTACK_GIGASAUGER, ATTACK_MOGELHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(21, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 26, POKEMON_TROMBORK, ITEM_UEBERRESTE, ATTACK_SPUKBALL, ATTACK_IRRLICHT, ATTACK_GIGASAUGER, ATTACK_FLUCH)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1a3_felsige_oednis_koch[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,20, POKEMON_LORBLATT),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,19, POKEMON_PERLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,21, POKEMON_PORENTA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,18, POKEMON_MILTANK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1a6_felsige_oednis_cave_trainer_0[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_NIDORINA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_FUKANO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1a7_felsige_oednis_cave_trainer_1[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_SANDAN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_MASCHOCK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1a8_felsige_oednis_cave_trainer_2[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_SMOGON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_MOLUNK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1a9_felsige_oednis_cave_trainer_3[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_PIKACHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_ELEKTEK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_FRIZELBLIZ),
};

static trainer_pokemon_custom_item_default_attacks trainer_party_x1aa_felsige_oednis_cave_trainer_4[1] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_ZWIRRKLOP,ITEM_EVOLITH),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1ab_tafelberg_lower_trainer_0[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_WEBARAK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_WATTZAPF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30, POKEMON_ARIADOS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1ac_tafelberg_lower_trainer_1[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_RIHORN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_DIGDRI),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1ad_tafelberg_lower_trainer_2[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_DODU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_SCHWALBINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_STARAVIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,25,POKEMON_NATU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1ae_tafelberg_lower_trainer_3[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_MAGMAR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_ELEKTEK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1af_tafelberg_lower_trainer_4[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_AERODACTYL),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b0_tafelberg_lower_trainer_5[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_VULPIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_SNUBBULL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,26,POKEMON_NIDORINA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b1_tafelberg_lower_trainer_6[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,51,POKEMON_LUNASTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,52,POKEMON_SONNFEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,49,POKEMON_AMONITAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,50,POKEMON_KABUTO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b2_felsige_oednis_east_caves_trainer_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_RABAUZ),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b3_felsige_oednis_east_caves_trainer_1[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,27,POKEMON_ONIX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_MACHOLLO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b4_felsige_oednis_east_caves_trainer_2[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_URSARING),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b5_felsige_oednis_east_caves_trainer_3[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_FUKANO),
};


static trainer_pokemon_default_item_default_attacks trainer_party_x6b[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_SCHWALBINI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_WABLU)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b6_tafelberg_lapis_cave_trainer_1[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_GERADAKS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_LOMBRERO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_STARAVIA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b7_tafelberg_lapis_cave_trainer_2[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_MAGNAYEN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_VOLTENSO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b8_tafelberg_lapis_cave_trainer_3[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,28,POKEMON_NATU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_KIRLIA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1b9_tafelberg_lapis_cave_trainer_4[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_OCTILLERY),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1ba_tafelberg_revolutionary_3[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_ENEKORO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_AMBIDIFFEL),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1bb_tafelberg_trainer_0[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_GEHWEIHER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,29,POKEMON_PUDOX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_WATTZAPF),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1bc_tafelberg_trainer_1[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_MORLORD),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1bd_tafelberg_trainer_2[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_MARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_PUMMELUFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_KIRLIA),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1be_tafelberg_trainer_3[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_BLANAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_LOMBRERO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_VULPIX),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1bf_tafelberg_trainer_4[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38,POKEMON_SCHILLOK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_SEEMON),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1c0_tafelberg_trainer_5[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_SANDAMER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_NOKTUSKA),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1c1_route_4_north_cave_trainer_0[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,30,POKEMON_MEDITIE),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1c2_route_4_trainer_0[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_RASAFF),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1c3_route_4_trainer_1[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_DARTIGNIS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_PELIPPER),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_SCHWALBINI),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1c4_route_4_trainer_2[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_MAGNETON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_PIKACHU),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1c5_route_4_trainer_3[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_PUDOX),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_NINJASK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_GEHWEIHER),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1c6_route_4_trainer_4[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_KNUDDELUFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_ENEKORO),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1c7_route_4_trainer_5[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_KICKLEE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_MEDITIE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_MASCHOCK),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1c8_route_4_trainer_6[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_PONITA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_SCHILLOK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_MAGNAYEN),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1c9_route_4_trainer_7[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_CHANEIRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_TOGETIC),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_OWEI),
}; 

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1ca_route_4_cave_south_painter[4] = {	
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, TRAINER_BUILD_SPECIAL_TANK, 0x0, false, false, 47, POKEMON_PSIANA, ITEM_LICHTLEHM, ATTACK_GEDANKENGUT, ATTACK_PSYCHOKINESE, ATTACK_REFLEKTOR, ATTACK_LICHTSCHILD),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, TRAINER_BUILD_PHYSICAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 47, POKEMON_OCTILLERY, ITEM_ZAUBERWASSER, ATTACK_OCTAZOOKA, ATTACK_EISSTRAHL, ATTACK_AMPELLEUCHTE, ATTACK_KUGELSAAT),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 47, POKEMON_PANDIR, ITEM_SEIDENSCHAL, ATTACK_IRRSCHLAG, ATTACK_TIEFSCHLAG, ATTACK_DURCHBRUCH, ATTACK_STEINHAGEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 47, POKEMON_AMBIDIFFEL, ITEM_MORBBEERE, ATTACK_DOPPELSCHLAG, ATTACK_FEUERSCHLAG, ATTACK_EISHIEB, ATTACK_MOGELHIEB)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1cb_bluetenbach_gym_manus_easy[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 35, POKEMON_MEDITALIS, ITEM_NONE, ATTACK_ZEN_KOPFSTOSS, ATTACK_PROTZER, ATTACK_POWER_PUNCH, ATTACK_DURCHBRUCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 35, POKEMON_SKARABORN, ITEM_NANABBEERE, ATTACK_VIELENDER, ATTACK_DURCHBRUCH, ATTACK_STEINHAGEL, ATTACK_POWER_PUNCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 34, POKEMON_RASAFF, ITEM_FOKUS_BAND, ATTACK_POWER_PUNCH, ATTACK_ANZIEHUNG, ATTACK_NACHTHIEB, ATTACK_AERO_ASS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 36, POKEMON_LUCARIO, ITEM_TAMOTBEERE, ATTACK_DURCHBRUCH, ATTACK_STEINHAGEL, ATTACK_SCHAUFLER, ATTACK_PATRONENHIEB)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1cc_bluetenbach_gym_manus_hard[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 40, POKEMON_MEDITALIS, ITEM_NONE, ATTACK_ZEN_KOPFSTOSS, ATTACK_PROTZER, ATTACK_POWER_PUNCH, ATTACK_DURCHBRUCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 37, POKEMON_MACHOMEI, ITEM_SCHWARZGURT, ATTACK_WUCHTSCHLAG, ATTACK_STEINKANTE, ATTACK_ERDBEBEN, ATTACK_DONNERSCHLAG),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 41, POKEMON_SKARABORN, ITEM_NANABBEERE, ATTACK_VIELENDER, ATTACK_NAHKAMPF, ATTACK_STEINKANTE, ATTACK_POWER_PUNCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_TANK, 0x0, false, false, 40, POKEMON_RASAFF, ITEM_FOKUS_BAND, ATTACK_POWER_PUNCH, ATTACK_ANZIEHUNG, ATTACK_NACHTHIEB, ATTACK_STEINKANTE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_SPEED_PREFERENCE, 0x0, false, false, 41, POKEMON_RESLADERO, ITEM_SALKABEERE, ATTACK_AERO_ASS, ATTACK_DURCHBRUCH, ATTACK_DONNERSCHLAG, ATTACK_AUSDAUER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(11, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 43, POKEMON_LUCARIO, ITEM_TAMOTBEERE, ATTACK_NAHKAMPF, ATTACK_STEINKANTE, ATTACK_ERDBEBEN, ATTACK_PATRONENHIEB)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1cd_bluetenbach_gym_trainer_4[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_RIOLU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_MEDITIE),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1ce_bluetenbach_gym_trainer_5[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_KICKLEE),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1cf_bluetenbach_gym_trainer_6[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_RABAUZ),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1d0_bluetenbach_gym_trainer_7[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_NOCKCHAN),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1d1_route_5_trainer_6[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_GUARDEVOIR),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1d2_route_5_trainer_7[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_TYRACROC),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_KRABBY),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1d3_route_5_trainer_8[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_MARILL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_FLEGMON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_KREBSCORPS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_KARPADOR),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1d4_route_5_trainer_9[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37,POKEMON_GARADOS),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1d5_anemonia_clouds_trainer_0[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_PUPPANCE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_KLEINSTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_AMONITAS),
}; 

static trainer_pokemon_default_item_default_attacks trainer_party_x1d6_route_4_clouds_trainer_2[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_DUFLOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_ULTRIGARIA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1d7_route_4_clouds_trainer_3[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_ELEKTEK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1d8_route_4_clouds_trainer_4[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_QUABBEL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_TENTACHA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1d9_route_4_clouds_trainer_5[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_NASGNET),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_MASCHOCK),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1da_route_5_icarus_party[4] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 38, POKEMON_DARTIGNIS, ITEM_HOLZKOHLE, ATTACK_FLAMMENRAD, ATTACK_AERO_ASS, ATTACK_STAHLFLUEGEL, ATTACK_RUCKZUCKHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 39, POKEMON_STARAVIA, ITEM_FOKUS_BAND, ATTACK_AERO_ASS, ATTACK_DOPPELTEAM, ATTACK_RUCKZUCKHIEB, ATTACK_STAHLFLUEGEL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE, 0x0, false, false, 40, POKEMON_KINDWURM, ITEM_DRACOJUWEL, ATTACK_DRACHENKLAUE, ATTACK_GLUT, ATTACK_NASSSCHWEIF, ATTACK_KOPFNUSS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE, 0x0, false, true, 35, POKEMON_WABLU, ITEM_TSITRUBEERE, ATTACK_FLUEGELSCHLAG, ATTACK_FURIENSCHLAG, ATTACK_STAHLFLUEGEL, ATTACK_DONNERBLITZ)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1db_power_plant_inside_trainer_0[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_LEKTROBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_KADABRA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_ELEKTEK),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1dc_power_plant_inside_trainer_1[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_MAGNETILO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,34,POKEMON_FRIZELBLIZ),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_MAGNETON),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1dd_power_plant_inside_trainer_2[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_VOLTENSO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36,POKEMON_RAICHU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1de_route_7_north_couple[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_NIDORINO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39,POKEMON_NIDORINA),
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1df_route_7_north_cook[4] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_GRANBULL, ITEM_NORMALJUWEL, ATTACK_FRUSTRATION, ATTACK_DONNERSCHLAG, ATTACK_FEUERSCHLAG, ATTACK_EISHIEB),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_SLEIMOK, ITEM_GIFTJUWEL, ATTACK_GIFTHIEB, ATTACK_DURCHBRUCH, ATTACK_EXPLOSION, ATTACK_TOXIN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_CHEVRUMM, ITEM_PFLANZEJUWEL, ATTACK_RASIERBLATT, ATTACK_MILCHGETRAENK, ATTACK_EGELSAMEN, ATTACK_AERO_ASS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, 41, POKEMON_MOGELBAUM, ITEM_GESTEINJUWEL, ATTACK_STEINKANTE, ATTACK_EXPLOSION, ATTACK_DURCHBRUCH, ATTACK_DOPPELTEAM)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1e4_dungeon_forest_veteran[5] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_KOKOWEI, ITEM_LICHTLEHM, ATTACK_LICHTSCHILD, ATTACK_REFLEKTOR, ATTACK_GIGASAUGER, ATTACK_EGELSAMEN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_KREBUTACK, ITEM_WAHLBAND, ATTACK_KREUZSCHERE, ATTACK_KASKADE, ATTACK_KRAFTKOLOSS, ATTACK_KNIRSCHER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_DIGDRI, ITEM_FOKUS_BAND, ATTACK_ERDBEBEN, ATTACK_STEINHAGEL, ATTACK_AERO_ASS, ATTACK_VERFOLGUNG),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_CAMERUPT, ITEM_SAIMBEERE, ATTACK_FLAMMENWURF, ATTACK_ERDKRAEFTE, ATTACK_ANTIK_KRAFT, ATTACK_EXPLOSION),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_CRYSTAL_ONIX, ITEM_UEBERRESTE, ATTACK_STEINKANTE, ATTACK_ERDBEBEN, ATTACK_FLUCH, ATTACK_DRACHENPULS)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1e5_dungeon_forest_veteran[5] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_REXBLISAR, ITEM_TAMOTBEERE, ATTACK_EISSPLITTER, ATTACK_SAMENBOMBEN, ATTACK_WEISSNEBEL, ATTACK_DURCHBRUCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_BLUBELLA, ITEM_SONNEN_EI, ATTACK_SOLARSTRAHL, ATTACK_MONDGEWALT, ATTACK_MATSCHBOMBE, ATTACK_SCHLAFPUDER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_SEEDRAKING, ITEM_GEWITTER_EI, ATTACK_DRACHENPULS, ATTACK_SURFER, ATTACK_EISSTRAHL, ATTACK_REGENTANZ),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_SANDAMER, ITEM_WUESTEN_EI, ATTACK_DOPPELTEAM, ATTACK_ERDBEBEN, ATTACK_STEINHAGEL, ATTACK_DURCHBRUCH),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_KAPPALORES, ITEM_UEBERRESTE, ATTACK_SURFER, ATTACK_EISSTRAHL, ATTACK_GIGASAUGER, ATTACK_EGELSAMEN)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1e6_dungeon_forest_veteran[5] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_PSIANA, ITEM_UEBERRESTE, ATTACK_GEDANKENGUT, ATTACK_GAEHNER, ATTACK_PSYCHOKINESE, ATTACK_STAFETTE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_BLITZA, ITEM_GEWITTER_EI, ATTACK_DONNER, ATTACK_SPUKBALL, ATTACK_AGILITAET, ATTACK_STAFETTE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_AQUANA, ITEM_TSITRUBEERE, ATTACK_SURFER, ATTACK_SAEUREPANZER, ATTACK_EISSTRAHL, ATTACK_STAFETTE),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_GLAZIOLA, ITEM_TUNDRA_EI, ATTACK_DOPPELTEAM, ATTACK_BLIZZARD, ATTACK_STAFETTE, ATTACK_DELEGATOR),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_FEELINARA, ITEM_LICHTLEHM, ATTACK_REFLEKTOR, ATTACK_LICHTSCHILD, ATTACK_MONDGEWALT, ATTACK_STAFETTE)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1e7_dungeon_forest_veteran[5] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_GLURAK, ITEM_SONNEN_EI, ATTACK_FEUERSTURM, ATTACK_SOLARSTRAHL, ATTACK_WINDSCHNITT, ATTACK_DRACHENPULS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_MEGANIE, ITEM_UEBERRESTE, ATTACK_SYNTHESE, ATTACK_SCHLAFPUDER, ATTACK_SONNENTAG, ATTACK_SOLARSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_SKULLYDRA, ITEM_ZAUBERWASSER, ATTACK_TSUNAMI, ATTACK_EISSTRAHL, ATTACK_DRACHENPULS, ATTACK_FINSTERAURA),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_DRAGORAN, ITEM_KIWANBEERE, ATTACK_DRACHENTANZ, ATTACK_WUTANFALL, ATTACK_ERDBEBEN, ATTACK_AERO_ASS),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_METAGROSS, ITEM_WAHLBAND, ATTACK_EXPLOSION, ATTACK_STERNHIEB, ATTACK_ZEN_KOPFSTOSS, ATTACK_ERDBEBEN)
};

static trainer_pokemon_custom_item_custom_attacks trainer_party_x1e8_dungeon_forest_veteran[6] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_ZAPDOS, ITEM_KIWANBEERE, ATTACK_DONNERBLITZ, ATTACK_DONNERWELLE, ATTACK_HITZEWELLE, ATTACK_WINDSCHNITT),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_SUICUNE, ITEM_MARONBEERE, ATTACK_ERHOLUNG, ATTACK_GEDANKENGUT, ATTACK_SURFER, ATTACK_EISSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_LATIOS, ITEM_PRUNUSBEERE, ATTACK_DRACHENKLAUE, ATTACK_PSYCHOKINESE, ATTACK_DONNERBLITZ, ATTACK_EISSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_RELAXO, ITEM_UEBERRESTE, ATTACK_FLUCH, ATTACK_RISIKOTACKLE, ATTACK_ERHOLUNG, ATTACK_ERDBEBEN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_KNAKRACK, ITEM_WUESTEN_EI, ATTACK_DRACHENKLAUE, ATTACK_ERDBEBEN, ATTACK_STEINKANTE, ATTACK_FEUERZAHN),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(0x0, 0x0, 0x0, false, false, TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD, POKEMON_DURENGARD, ITEM_TSITRUBEERE, ATTACK_KOENIGSSCHILD, ATTACK_SCHWERTTANZ, ATTACK_SCHATTENSTOSS, ATTACK_STAHLSTREICH)
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1e9_route_2_east_trainer_1[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_NIDORANM),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,8,POKEMON_PIKACHU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1ea_route_2_east_trainer_2[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_KARPADOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,8,POKEMON_MUSCHAS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,7,POKEMON_STERNDU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1eb_route_4_south_cave_trainer_3[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,33,POKEMON_MASCHOCK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,31,POKEMON_RIOLU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1ec_route_4_south_cave_trainer_4[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_RASAFF),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,32,POKEMON_MEDITIE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1ed_route_4_south_cave_trainer_5[1] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_MEDITALIS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1ee_route_4_south_cave_trainer_6[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,35,POKEMON_KAPOERA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1ef_route_4_south_cave_trainer_7[2] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44, POKEMON_KIRLIA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,43, POKEMON_KADABRA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f0_route_4_south_cave_trainer_8[3] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,42, POKEMON_LEKTROBAL),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,42, POKEMON_MAGNETON),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,41, POKEMON_WATTZAPF),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f1_route_4_south_cave_trainer_9[4] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,45, POKEMON_RAICHU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,44, POKEMON_RELAXO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,45, POKEMON_RESLADERO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,43, POKEMON_RASAFF),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f2_route_2_clouds_trainer_5[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_DODU),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_SCHWALBOSS),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f3_route_2_clouds_trainer_6[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38, POKEMON_SCHMERBE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36, POKEMON_KREBSCORPS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_STERNDU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f4_route_2_clouds_trainer_7[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38, POKEMON_TRAUMATO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38, POKEMON_KADABRA),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f5_route_2_clouds_trainer_8[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_LUNASTEIN),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36, POKEMON_ONIX),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f6_route_2_clouds_trainer_9[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_FLOETTE),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36, POKEMON_GIFLOR),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36, POKEMON_ULTRIGARIA),
};

static trainer_pokemon_custom_item_default_attacks trainer_party_x1f7_sonnaufeld_trainer_0[] = {
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36, POKEMON_FORMEO, ITEM_SONNEN_EI),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36, POKEMON_FORMEO, ITEM_TUNDRA_EI),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36, POKEMON_FORMEO, ITEM_WUESTEN_EI),
	TRAINER_PARTY_CUSTOM_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36, POKEMON_FORMEO, ITEM_GEWITTER_EI),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f8_sonnaufeld_trainer_1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_ELEKTEK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,36, POKEMON_PIKACHU),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1f9_sonnaufeld_trainer_2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_ARKANI),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_VOLTENSO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,38, POKEMON_MAGNAYEN),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1fa_route2_clouds_cave_trainer_0[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_GEOROK),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_PUPPANCE),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1fb_route2_clouds_cave_trainer_1[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,39, POKEMON_SMOGMOG),
};

static trainer_pokemon_default_item_default_attacks trainer_party_x1fc_route2_clouds_fisherman_2[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_KANIVANHA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false,37, POKEMON_QUABBEL),
};

#endif 