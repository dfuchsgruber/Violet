/*
 * wild_pokemon.c
 *
 *  Created on: Jun 3, 2018
 *      Author: dominik
 */

#include "types.h"
#include "constants/species.h"
#include "map/wild_pokemon.h"
#include "prng.h"
#include "dungeon/dungeon2.h"
#include "dungeon/cave.h"
#include "save.h"
#include "debug.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "flags.h"
#include "math.h"
#include "vars.h"
#include "pokemon/virtual.h"

u16 dungeon_cave_wild_pokemon_common[] = {
    POKEMON_SANDAN,
    POKEMON_ZUBAT,
    POKEMON_DIGDA,
    POKEMON_MACHOLLO,
    POKEMON_KLEINSTEIN,
    POKEMON_ONIX,
    POKEMON_TRAGOSSO,
    POKEMON_RABAUZ,
    POKEMON_NASGNET,
    POKEMON_MEDITIE,
    POKEMON_STOLLUNIOR,
    POKEMON_PUMMELUFF,
    0xFFFF
};

u16 dungeon_cave_wild_pokemon_rare[] = {
    POKEMON_SONNFEL,
    POKEMON_LUNASTEIN,
    POKEMON_SANDAMER,
    POKEMON_GEOROK,
    POKEMON_SKORGLA,
    POKEMON_BRONZEL,
    0xFFFF
};

u16 dungeon_cave_wild_pokemon_super_rare[] = {
    POKEMON_STOLLRAK,
    POKEMON_ZOBIRIS,
    POKEMON_LARVITAR,
    POKEMON_MASCHOCK,
    POKEMON_FLUNKIFER,
    POKEMON_GEOROK,
    POKEMON_KAUMALAT,
    POKEMON_BRONZONG,
    POKEMON_STAHLOS,
    0xFFFF
};

