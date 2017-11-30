#include "types.h"
#include "pokemon.h"
#include "basestats.h"
#include "abilities.h"
#include "item.h"

basestat basestats[POKEMON_CNT] = {
    //POKEMON_POKEMON_0
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_BISASAM
    {
        45, 49, 49, 45, 65, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        180, //catch rate
        64, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_GRASS, //egg groups
        NOTDUENGER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        PHOTOGENESE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_BISAKNOSP
    {
        60, 62, 63, 60, 80, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        45, //catch rate
        141, //exp yield
        {0, 0, 0, 0, 1, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_GRASS, //egg groups
        NOTDUENGER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        PHOTOGENESE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_BISAFLOR
    {
        80, 82, 83, 80, 100, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        45, //catch rate
        208, //exp yield
        {0, 0, 0, 0, 2, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_GRASS, //egg groups
        NOTDUENGER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        PHOTOGENESE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_GLUMANDA
    {
        39, 52, 43, 65, 60, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        180, //catch rate
        65, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_DRAGON, //egg groups
        GROSSBRAND, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        UNGEBROCHEN, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_GLUTEXO
    {
        58, 64, 58, 80, 80, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        45, //catch rate
        142, //exp yield
        {0, 0, 0, 1, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_DRAGON, //egg groups
        GROSSBRAND, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        UNGEBROCHEN, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_GLURAK
    {
        78, 84, 78, 100, 109, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FLYING, //types
        45, //catch rate
        209, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_DRAGON, //egg groups
        GROSSBRAND, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        UNGEBROCHEN, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SCHIGGY
    {
        44, 48, 65, 43, 50, 64, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        180, //catch rate
        66, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        STURZBACH, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        REGENMUT, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SCHILLOK
    {
        59, 63, 80, 58, 65, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        45, //catch rate
        143, //exp yield
        {0, 0, 1, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        STURZBACH, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        REGENMUT, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_TURTOK
    {
        79, 83, 100, 78, 85, 105, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        45, //catch rate
        210, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        STURZBACH, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        REGENMUT, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_DARTIRI
    {
        45, 50, 43, 62, 40, 38, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        255, //catch rate
        60, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        14, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        FLAMMKOERPER, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ORKANSCHW, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_DARTIGNIS
    {
        62, 73, 55, 84, 56, 52, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FLYING, //types
        240, //catch rate
        80, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        FLAMMKOERPER, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ORKANSCHW, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_FIARO
    {
        78, 81, 71, 126, 74, 69, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FLYING, //types
        45, //catch rate
        200, //exp yield
        {0, 0, 0, 3, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_FLINKKLAUE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        FLAMMKOERPER, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ORKANSCHW, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_HORNLIU
    {
        40, 35, 30, 50, 20, 20, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_POISON, //types
        255, //catch rate
        52, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        PUDERABWEHR, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        GIFTDORN, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_KOKUNA
    {
        45, 25, 50, 35, 25, 25, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_POISON, //types
        120, //catch rate
        71, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        EXPIDERMIS, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        PANZERHAUT, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_BIBOR
    {
        65, 110, 60, 95, 45, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_POISON, //types
        45, //catch rate
        159, //exp yield
        {0, 2, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GIFTSTICH, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        EXTRADORN, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        HEXAPLAGA, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_STARALILI
    {
        40, 55, 30, 60, 30, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        255, //catch rate
        55, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        ADLERAUGE, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ALLROUNDER, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_STARAVIA
    {
        55, 75, 50, 80, 40, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        120, //catch rate
        113, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        BEDROHER, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        UNGEBROCHEN, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_STARAPTOR
    {
        85, 120, 70, 100, 59, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        45, //catch rate
        172, //exp yield
        {0, 0, 0, 3, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        BEDROHER, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        UNGEBROCHEN, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_BRONZEL
    {
        57, 24, 86, 23, 24, 86, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_PSYCHIC, //types
        255, //catch rate
        57, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ROBUSTHEIT, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_BRONZONG
    {
        67, 89, 116, 33, 79, 116, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_PSYCHIC, //types
        127, //catch rate
        116, //exp yield
        {0, 0, 1, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_LINKKABEL, ITEM_NONE, //common, rare item
        255, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ROBUSTHEIT, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_MAEHIKEL
    {
        66, 65, 48, 52, 62, 57, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        255, //catch rate
        78, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_KUHMUH_MILCH, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ROBUSTHEIT, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        NOTSCHUTZ, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_CHEVRUMM
    {
        123, 100, 62, 68, 97, 81, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        90, //catch rate
        189, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_BLATTSTEIN, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        AP_SPARER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        NOTSCHUTZ, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_PARAGONI
    {
        43, 70, 48, 38, 50, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_GRASS, //types
        220, //catch rate
        82, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_BANNSTICKER, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_AMORPHUS, //egg groups
        INNERE_KRAFT, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        LEBENSRAEUBER, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_TROMBORK
    {
        85, 110, 76, 56, 65, 82, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_GRASS, //types
        90, //catch rate
        190, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_TSITRUBEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_DRAGON, //egg groups
        INNERE_KRAFT, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        LEBENSRAEUBER, //hidden ability
        SHAPE_TENTACLES, //form
    },

    //POKEMON_PIKACHU
    {
        35, 55, 30, 90, 50, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        190, //catch rate
        82, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        10, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FAIRY, //egg groups
        STATIK, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        LERNFAEHIG, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_RAICHU
    {
        60, 90, 55, 100, 90, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        75, //catch rate
        122, //exp yield
        {0, 0, 0, 3, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        10, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FAIRY, //egg groups
        STATIK, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        LERNFAEHIG, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SANDAN
    {
        50, 75, 85, 40, 20, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        255, //catch rate
        93, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SANDSCHLEIER, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        SANDHERZ, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SANDAMER
    {
        75, 100, 110, 65, 45, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        90, //catch rate
        163, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_PUDERSAND, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SANDSCHLEIER, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        SANDHERZ, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_NIDORANW
    {
        55, 47, 52, 41, 40, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        235, //catch rate
        59, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        254, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        GIFTDORN, ABILITY_NONE, //abilities
        50, //safari rate
        1, //flip and color
        BLITZFAENGER, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_NIDORINA
    {
        70, 62, 67, 56, 55, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        120, //catch rate
        117, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        254, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        GIFTDORN, ABILITY_NONE, //abilities
        75, //safari rate
        1, //flip and color
        BLITZFAENGER, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_NIDOQUEEN
    {
        90, 82, 87, 76, 75, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_GROUND, //types
        45, //catch rate
        194, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        254, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        GIFTDORN, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        BLITZFAENGER, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_NIDORANM
    {
        46, 57, 40, 50, 40, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        235, //catch rate
        60, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        GIFTDORN, ABILITY_NONE, //abilities
        50, //safari rate
        6, //flip and color
        BEDROHER, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_NIDORINO
    {
        61, 72, 57, 65, 55, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        120, //catch rate
        118, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        GIFTDORN, ABILITY_NONE, //abilities
        75, //safari rate
        6, //flip and color
        BEDROHER, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_NIDOKING
    {
        81, 92, 77, 85, 85, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_GROUND, //types
        45, //catch rate
        195, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        GIFTDORN, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        BEDROHER, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_FLOETTE
    {
        54, 45, 47, 52, 75, 98, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FAIRY, TYPE_FAIRY, //types
        150, //catch rate
        110, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_WUNDERSAAT, //common, rare item
        254, //gender
        10, //egg cycles
        140, //base friendship
        0, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_FAIRY, //egg groups
        LERNFAEHIG, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        CURATOR, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_FLORGES
    {
        78, 65, 68, 75, 112, 154, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FAIRY, TYPE_FAIRY, //types
        25, //catch rate
        200, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_WUNDERSAAT, //common, rare item
        254, //gender
        10, //egg cycles
        140, //base friendship
        0, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_FAIRY, //egg groups
        LERNFAEHIG, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        CURATOR, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_VULPIX
    {
        38, 41, 40, 65, 50, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        190, //catch rate
        63, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_FRAGIABEERE, ITEM_NONE, //common, rare item
        191, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        FEUERFAENGER, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        SOLARKRAFT, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_VULNONA
    {
        73, 76, 75, 100, 81, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        75, //catch rate
        178, //exp yield
        {0, 0, 0, 1, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_FRAGIABEERE, ITEM_NONE, //common, rare item
        191, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        FEUERFAENGER, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        SOLARKRAFT, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_PUMMELUFF
    {
        115, 45, 20, 20, 45, 25, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FAIRY, //types
        170, //catch rate
        76, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_SINELBEERE, ITEM_NONE, //common, rare item
        191, //gender
        10, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_FAIRY, //egg groups
        CHARMEBOLZEN, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        CURATOR, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KNUDDELUFF
    {
        140, 70, 45, 45, 75, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FAIRY, //types
        50, //catch rate
        109, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_SINELBEERE, ITEM_NONE, //common, rare item
        191, //gender
        10, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_FAIRY, //egg groups
        CHARMEBOLZEN, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        CURATOR, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_ZUBAT
    {
        40, 45, 35, 55, 30, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_FLYING, //types
        255, //catch rate
        54, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        KONZENTRATOR, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        LEBENSRAEUBER, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_GOLBAT
    {
        75, 80, 70, 90, 65, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_FLYING, //types
        90, //catch rate
        171, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        KONZENTRATOR, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        LEBENSRAEUBER, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_MYRAPLA
    {
        45, 50, 55, 30, 75, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        255, //catch rate
        78, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        SPORENWIRT, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_DUFLOR
    {
        60, 65, 70, 40, 85, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        120, //catch rate
        132, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        SPORENWIRT, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_GIFLOR
    {
        75, 80, 85, 50, 100, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        45, //catch rate
        184, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        SPORENWIRT, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_FOLIPURBA
    {
        65, 110, 130, 95, 60, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        45, //catch rate
        197, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_MINIPILZ, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        50, //safari rate
        0, //flip and color
        LERNFAEHIG, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_FEELINARA
    {
        95, 65, 65, 60, 119, 139, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FAIRY, TYPE_FAIRY, //types
        45, //catch rate
        197, //exp yield
        {0, 2, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_SANFTGLOCKE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        AP_SPARER, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        CURATOR, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_WATTZAPF
    {
        50, 47, 50, 65, 57, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_ELECTRIC, //types
        200, //catch rate
        87, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        FACETTENAUGE, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        STATIK, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_VOLTULA
    {
        70, 77, 60, 108, 97, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_ELECTRIC, //types
        75, //catch rate
        167, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_SILBERSTAUB, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        FACETTENAUGE, ABILITY_NONE, //abilities
        75, //safari rate
        2, //flip and color
        STATIK, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_DIGDA
    {
        10, 55, 25, 95, 35, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        255, //catch rate
        81, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SANDSCHLEIER, AUSWEGSLOS, //abilities
        0, //safari rate
        5, //flip and color
        TECHNIKER, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_DIGDRI
    {
        35, 80, 50, 120, 50, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        50, //catch rate
        153, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SANDSCHLEIER, AUSWEGSLOS, //abilities
        0, //safari rate
        5, //flip and color
        TECHNIKER, //hidden ability
        SHAPE_MULTI, //form
    },

    //POKEMON_KASTADUR
    {
        44, 50, 91, 10, 24, 86, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_GRASS, //types
        200, //catch rate
        89, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_MINERAL, //egg groups
        RAUHAUT, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ROBUSTHEIT, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_TENTANTEL
    {
        74, 94, 131, 20, 54, 116, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_GRASS, //types
        90, //catch rate
        186, //exp yield
        {0, 0, 1, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_MINERAL, //egg groups
        RAUHAUT, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ROBUSTHEIT, //hidden ability
        SHAPE_TENTACLES, //form
    },

    //POKEMON_ENTON
    {
        50, 52, 48, 55, 65, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        190, //catch rate
        80, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        FEUCHTIGKEIT, WOLKE_SIEBEN, //abilities
        50, //safari rate
        2, //flip and color
        LUZID, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_ENTORON
    {
        80, 82, 78, 85, 95, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        75, //catch rate
        174, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        FEUCHTIGKEIT, WOLKE_SIEBEN, //abilities
        0, //safari rate
        1, //flip and color
        LUZID, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MENKI
    {
        40, 80, 35, 70, 35, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        190, //catch rate
        74, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        MUNTERKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        TOLLWUT, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_RASAFF
    {
        65, 105, 60, 95, 60, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        75, //catch rate
        149, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        MUNTERKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        TOLLWUT, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_FUKANO
    {
        55, 70, 45, 60, 70, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        190, //catch rate
        91, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_FRAGIABEERE, ITEM_NONE, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        BEDROHER, FEUERFAENGER, //abilities
        0, //safari rate
        5, //flip and color
        UNGEBROCHEN, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_ARKANI
    {
        90, 110, 80, 95, 100, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        75, //catch rate
        213, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_FRAGIABEERE, ITEM_NONE, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        BEDROHER, FEUERFAENGER, //abilities
        0, //safari rate
        5, //flip and color
        UNGEBROCHEN, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_GRAMOKLES
    {
        45, 80, 100, 28, 35, 37, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_GHOST, //types
        190, //catch rate
        105, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        ROBUSTHEIT, ABILITY_NONE, //abilities
        50, //safari rate
        7, //flip and color
        HOCHMUT, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_DUOKLES
    {
        59, 110, 150, 35, 45, 49, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_GHOST, //types
        70, //catch rate
        167, //exp yield
        {0, 1, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        ROBUSTHEIT, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        HOCHMUT, //hidden ability
        SHAPE_MULTI, //form
    },

    //POKEMON_DURENGARD
    {
        60, 50, 150, 60, 50, 150, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_GHOST, //types
        25, //catch rate
        244, //exp yield
        {0, 0, 2, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        TAKTIKWECHS, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_ABRA
    {
        25, 20, 15, 90, 105, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        200, //catch rate
        73, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_KRUEMMLOEFFEL, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        SYNCHRO, KONZENTRATOR, //abilities
        0, //safari rate
        5, //flip and color
        AP_SPARER, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_KADABRA
    {
        40, 35, 30, 105, 120, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        100, //catch rate
        145, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_KRUEMMLOEFFEL, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        SYNCHRO, KONZENTRATOR, //abilities
        0, //safari rate
        5, //flip and color
        LUZID, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SIMSALA
    {
        55, 50, 45, 120, 135, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        50, //catch rate
        186, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_KRUEMMLOEFFEL, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        SYNCHRO, KONZENTRATOR, //abilities
        0, //safari rate
        5, //flip and color
        LUZID, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_MACHOLLO
    {
        70, 80, 50, 35, 35, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        180, //catch rate
        88, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        ADRENALIN, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        MENTALKRAFT, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MASCHOCK
    {
        80, 100, 70, 45, 50, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        90, //catch rate
        146, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_FOKUS_BAND, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        ADRENALIN, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        MENTALKRAFT, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_MACHOMEI
    {
        90, 130, 80, 55, 65, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        45, //catch rate
        193, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_FOKUS_BAND, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        ADRENALIN, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        UNGEBROCHEN, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KNOFENSA
    {
        50, 75, 35, 40, 70, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        255, //catch rate
        84, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        NOTDUENGER, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_ULTRIGARIA
    {
        65, 90, 50, 55, 85, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        120, //catch rate
        151, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        NOTDUENGER, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_SARZENIA
    {
        80, 105, 65, 70, 100, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        45, //catch rate
        191, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        NOTDUENGER, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_TENTACHA
    {
        40, 40, 35, 70, 50, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_POISON, //types
        190, //catch rate
        105, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        NEUTRALTORSO, KLOAKENSOSSE, //abilities
        0, //safari rate
        1, //flip and color
        LEBENSRAEUBER, //hidden ability
        SHAPE_TENTACLES, //form
    },

    //POKEMON_TENTOXA
    {
        80, 70, 65, 100, 80, 120, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_POISON, //types
        60, //catch rate
        205, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        NEUTRALTORSO, KLOAKENSOSSE, //abilities
        0, //safari rate
        1, //flip and color
        LEBENSRAEUBER, //hidden ability
        SHAPE_TENTACLES, //form
    },

    //POKEMON_KLEINSTEIN
    {
        40, 80, 100, 20, 30, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_GROUND, //types
        255, //catch rate
        86, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        ROBUSTHEIT, STEINHAUPT, //abilities
        0, //safari rate
        5, //flip and color
        LEBENSRAEUBER, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_GEOROK
    {
        55, 95, 115, 35, 45, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_GROUND, //types
        120, //catch rate
        134, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GRANITSTEIN, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        ROBUSTHEIT, STEINHAUPT, //abilities
        0, //safari rate
        5, //flip and color
        FELSENKERN, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_GEOWAZ
    {
        80, 110, 130, 45, 55, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_GROUND, //types
        45, //catch rate
        177, //exp yield
        {0, 0, 3, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GRANITSTEIN, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        ROBUSTHEIT, STEINHAUPT, //abilities
        0, //safari rate
        5, //flip and color
        FELSENKERN, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_PONITA
    {
        50, 85, 55, 90, 65, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        190, //catch rate
        152, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ANGSTHASE, FEUERFAENGER, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_GALLOPA
    {
        65, 100, 70, 105, 80, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        60, //catch rate
        192, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ANGSTHASE, FEUERFAENGER, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_FLEGMON
    {
        90, 65, 65, 15, 40, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_PSYCHIC, //types
        190, //catch rate
        99, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        DOESIGKEIT, TEMPOMACHER, //abilities
        50, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_LAHMUS
    {
        95, 75, 110, 30, 100, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_PSYCHIC, //types
        75, //catch rate
        164, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        DOESIGKEIT, TEMPOMACHER, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MAGNETILO
    {
        25, 35, 70, 45, 95, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_STEEL, //types
        190, //catch rate
        89, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        MAGNETFALLE, ROBUSTHEIT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_MAGNETON
    {
        50, 60, 95, 70, 120, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_STEEL, //types
        60, //catch rate
        161, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_MAGNET, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        MAGNETFALLE, ROBUSTHEIT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_MULTI, //form
    },

    //POKEMON_PORENTA
    {
        66, 100, 70, 100, 88, 62, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        45, //catch rate
        94, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_LAUCHSTANGE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FIELD, //egg groups
        ADLERAUGE, KONZENTRATOR, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_DODU
    {
        35, 85, 45, 75, 35, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        190, //catch rate
        96, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        ANGSTHASE, FRUEHWECKER, //abilities
        50, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_DODRI
    {
        60, 110, 70, 100, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        45, //catch rate
        158, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_HACKATTACK, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        ANGSTHASE, FRUEHWECKER, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_JURBO
    {
        65, 45, 55, 45, 45, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        190, //catch rate
        100, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_WILBIRBEERE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        SPECKSCHICHT, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_JUGONG
    {
        90, 70, 80, 70, 70, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_ICE, //types
        75, //catch rate
        176, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_WILBIRBEERE, ITEM_EWIGES_EIS, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        SPECKSCHICHT, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_SLEIMA
    {
        80, 80, 50, 25, 40, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        190, //catch rate
        90, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        DUFTNOTE, WERTEHALTER, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_SLEIMOK
    {
        105, 105, 75, 50, 65, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        75, //catch rate
        157, //exp yield
        {1, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        DUFTNOTE, WERTEHALTER, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_MUSCHAS
    {
        30, 65, 100, 40, 45, 25, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        190, //catch rate
        97, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_PERLE, ITEM_RIESENPERLE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        PANZERHAUT, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_AUSTOS
    {
        50, 95, 180, 70, 85, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_ICE, //types
        60, //catch rate
        203, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_PERLE, ITEM_RIESENPERLE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        PANZERHAUT, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_NEBULAK
    {
        30, 35, 30, 80, 100, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_POISON, //types
        190, //catch rate
        95, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_ALPOLLO
    {
        45, 50, 45, 95, 115, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_POISON, //types
        90, //catch rate
        126, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_BANNSTICKER, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_GENGAR
    {
        60, 65, 60, 110, 130, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_POISON, //types
        45, //catch rate
        190, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_BANNSTICKER, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_ONIX
    {
        35, 45, 160, 70, 30, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_GROUND, //types
        45, //catch rate
        108, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GRANITSTEIN, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        STEINHAUPT, ROBUSTHEIT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_TRAUMATO
    {
        60, 48, 45, 42, 43, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        190, //catch rate
        102, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        INSOMNIA, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_HYPNO
    {
        85, 73, 70, 67, 73, 115, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        75, //catch rate
        165, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        INSOMNIA, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KRABBY
    {
        30, 105, 90, 50, 25, 25, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        225, //catch rate
        115, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        SCHERENMACHT, PANZERHAUT, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_KINGLER
    {
        55, 130, 115, 75, 50, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        60, //catch rate
        206, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        SCHERENMACHT, PANZERHAUT, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_VOLTOBAL
    {
        40, 30, 50, 100, 55, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        190, //catch rate
        103, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        LAERMSCHUTZ, STATIK, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_LEKTROBAL
    {
        60, 50, 70, 140, 80, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        60, //catch rate
        150, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        LAERMSCHUTZ, STATIK, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_OWEI
    {
        60, 40, 80, 40, 60, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_PSYCHIC, //types
        90, //catch rate
        98, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        75, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_MULTI, //form
    },

    //POKEMON_KOKOWEI
    {
        95, 95, 85, 55, 125, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_PSYCHIC, //types
        45, //catch rate
        212, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_TRAGOSSO
    {
        50, 50, 95, 35, 40, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        190, //catch rate
        87, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_KAMPFKNOCHEN, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        STEINHAUPT, BLITZFAENGER, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_KNOGGA
    {
        60, 80, 110, 45, 50, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        75, //catch rate
        124, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_KAMPFKNOCHEN, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        STEINHAUPT, BLITZFAENGER, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_KICKLEE
    {
        50, 120, 53, 87, 35, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        45, //catch rate
        139, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        FLEXIBILITAET, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_NOCKCHAN
    {
        50, 105, 79, 76, 35, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        45, //catch rate
        140, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        ADLERAUGE, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_SCHLURP
    {
        90, 55, 75, 30, 60, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        127, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        TEMPOMACHER, DOESIGKEIT, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SMOGON
    {
        40, 65, 95, 35, 60, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        190, //catch rate
        114, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_SMOGMOG
    {
        65, 90, 120, 60, 85, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        60, //catch rate
        173, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_MULTI, //form
    },

    //POKEMON_RIHORN
    {
        80, 85, 95, 25, 30, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_ROCK, //types
        120, //catch rate
        135, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        BLITZFAENGER, STEINHAUPT, //abilities
        75, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_RIZEROS
    {
        105, 130, 120, 40, 45, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_ROCK, //types
        60, //catch rate
        204, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        BLITZFAENGER, STEINHAUPT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_CHANEIRA
    {
        250, 5, 5, 50, 35, 105, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        30, //catch rate
        255, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GLUECKS_EI, //common, rare item
        254, //gender
        40, //egg cycles
        140, //base friendship
        4, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_FAIRY, //egg groups
        INNERE_KRAFT, EDELMUT, //abilities
        125, //safari rate
        9, //flip and color
        CURATOR, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_ZOBIRIS
    {
        50, 75, 75, 50, 65, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_GHOST, //types
        45, //catch rate
        98, //exp yield
        {0, 1, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        3, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        ADLERAUGE, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KANGAMA
    {
        105, 95, 80, 90, 40, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        175, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        254, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        FRUEHWECKER, ABILITY_NONE, //abilities
        125, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SEEPER
    {
        30, 40, 70, 60, 70, 25, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        225, //catch rate
        83, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_DRAGON, //egg groups
        WASSERTEMPO, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_SEEMON
    {
        55, 65, 95, 85, 95, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        75, //catch rate
        155, //exp yield
        {0, 0, 1, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_DRAGON, //egg groups
        GIFTDORN, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_QUABBEL
    {
        55, 40, 50, 40, 65, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_GHOST, //types
        225, //catch rate
        111, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_WATER_2, //egg groups
        H2O_ABSORBER, H2O_ABSORBER, //abilities
        50, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TENTACLES, //form
    },

    //POKEMON_APOQUALLYP
    {
        100, 60, 70, 60, 85, 105, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_GHOST, //types
        60, //catch rate
        170, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_WATER_2, //egg groups
        H2O_ABSORBER, H2O_ABSORBER, //abilities
        75, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TENTACLES, //form
    },

    //POKEMON_STERNDU
    {
        30, 45, 55, 85, 70, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        225, //catch rate
        106, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_STERNENSTAUB, ITEM_STERNENSTUECK, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        ERLEUCHTUNG, INNERE_KRAFT, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_STARMIE
    {
        60, 75, 85, 115, 100, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_PSYCHIC, //types
        60, //catch rate
        207, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_STERNENSTAUB, ITEM_STERNENSTUECK, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        ERLEUCHTUNG, INNERE_KRAFT, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_TRAUNFUGIL
    {
        60, 60, 60, 85, 85, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_GHOST, //types
        45, //catch rate
        157, //exp yield
        {0, 0, 0, 0, 1, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_BANNSTICKER, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        4, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_SICHLOR
    {
        70, 110, 80, 105, 55, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_FLYING, //types
        45, //catch rate
        187, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        HEXAPLAGA, ABILITY_NONE, //abilities
        125, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_GALAGLADI
    {
        68, 125, 65, 80, 65, 115, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_FIGHTING, //types
        45, //catch rate
        208, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        254, //gender
        25, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        WEGSPERRE, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_ELEKTEK
    {
        65, 83, 57, 105, 95, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        45, //catch rate
        156, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        63, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        STATIK, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MAGMAR
    {
        65, 95, 57, 93, 100, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        45, //catch rate
        167, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        63, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        FLAMMKOERPER, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_PINSIR
    {
        65, 125, 100, 85, 55, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_BUG, //types
        45, //catch rate
        200, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        SCHERENMACHT, ABILITY_NONE, //abilities
        125, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_TAUROS
    {
        75, 100, 95, 110, 40, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        211, //exp yield
        {0, 1, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        BEDROHER, ABILITY_NONE, //abilities
        125, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_KARPADOR
    {
        20, 10, 55, 80, 15, 20, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        255, //catch rate
        20, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        5, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_DRAGON, //egg groups
        WASSERTEMPO, ABILITY_NONE, //abilities
        25, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_GARADOS
    {
        95, 125, 79, 81, 60, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_FLYING, //types
        45, //catch rate
        214, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        5, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_DRAGON, //egg groups
        BEDROHER, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_LAPRAS
    {
        130, 85, 80, 60, 85, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_ICE, //types
        45, //catch rate
        219, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        40, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        H2O_ABSORBER, PANZERHAUT, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_DITTO
    {
        48, 48, 48, 48, 48, 48, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        35, //catch rate
        61, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_METALLSTAUB, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_DITTO, EGG_GROUP_DITTO, //egg groups
        FLEXIBILITAET, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_EVOLI
    {
        55, 55, 50, 55, 45, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        92, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        1, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ANGSTHASE, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_AQUANA
    {
        130, 65, 60, 65, 110, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        45, //catch rate
        196, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        35, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        H2O_ABSORBER, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_BLITZA
    {
        65, 65, 60, 130, 110, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        45, //catch rate
        197, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        35, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        VOLTABSORBER, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_FLAMARA
    {
        65, 130, 60, 65, 95, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        45, //catch rate
        198, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        35, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        FEUERFAENGER, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_PORYGON
    {
        65, 60, 70, 40, 85, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        130, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        FAEHRTE, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_AMONITAS
    {
        35, 40, 100, 35, 90, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_WATER, //types
        45, //catch rate
        120, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        30, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_3, //egg groups
        WASSERTEMPO, PANZERHAUT, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TENTACLES, //form
    },

    //POKEMON_AMOROSO
    {
        70, 60, 125, 55, 115, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_WATER, //types
        45, //catch rate
        199, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        30, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_3, //egg groups
        WASSERTEMPO, PANZERHAUT, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TENTACLES, //form
    },

    //POKEMON_KABUTO
    {
        30, 80, 90, 55, 55, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_WATER, //types
        45, //catch rate
        119, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        30, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_3, //egg groups
        WASSERTEMPO, KAMPFPANZER, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_KABUTOPS
    {
        60, 115, 105, 80, 65, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_WATER, //types
        45, //catch rate
        201, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        30, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_3, //egg groups
        WASSERTEMPO, KAMPFPANZER, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_AERODACTYL
    {
        80, 105, 65, 130, 60, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_FLYING, //types
        45, //catch rate
        202, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        35, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        STEINHAUPT, ERZWINGER, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_RELAXO
    {
        160, 110, 65, 30, 65, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        25, //catch rate
        154, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_MARONBEERE, ITEM_MARONBEERE, //common, rare item
        31, //gender
        40, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        IMMUNITAET, SPECKSCHICHT, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_ARKTOS
    {
        90, 85, 100, 85, 95, 125, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_FLYING, //types
        3, //catch rate
        215, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        80, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_ZAPDOS
    {
        90, 90, 85, 100, 125, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_FLYING, //types
        3, //catch rate
        216, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        80, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_LAVADOS
    {
        90, 100, 90, 90, 125, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FLYING, //types
        3, //catch rate
        217, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        80, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_DRATINI
    {
        41, 64, 45, 50, 50, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_DRAGON, //types
        45, //catch rate
        67, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_DRAGON, //egg groups
        EXPIDERMIS, ABILITY_NONE, //abilities
        100, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_DRAGONIR
    {
        61, 84, 65, 70, 70, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_DRAGON, //types
        45, //catch rate
        144, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_DRACHENZAHN, //common, rare item
        127, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_DRAGON, //egg groups
        EXPIDERMIS, ABILITY_NONE, //abilities
        125, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_DRAGORAN
    {
        91, 134, 95, 80, 100, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_FLYING, //types
        45, //catch rate
        218, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_DRACHENZAHN, //common, rare item
        127, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_DRAGON, //egg groups
        KONZENTRATOR, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MEWTU
    {
        106, 110, 90, 130, 154, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        3, //catch rate
        220, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MEW
    {
        100, 100, 100, 100, 100, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        45, //catch rate
        64, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        100, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        SYNCHRO, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_ENDIVIE
    {
        45, 49, 65, 45, 49, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        45, //catch rate
        64, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_PRUNUSBEERE, ITEM_PRUNUSBEERE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_GRASS, //egg groups
        NOTDUENGER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_LORBLATT
    {
        60, 62, 80, 60, 63, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        45, //catch rate
        141, //exp yield
        {0, 0, 1, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_GRASS, //egg groups
        NOTDUENGER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_MEGANIE
    {
        80, 82, 100, 80, 83, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        45, //catch rate
        208, //exp yield
        {0, 0, 1, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_GRASS, //egg groups
        NOTDUENGER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_FEURIGEL
    {
        39, 52, 43, 65, 60, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        45, //catch rate
        65, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        GROSSBRAND, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_IGELAVAR
    {
        58, 64, 58, 80, 80, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        45, //catch rate
        142, //exp yield
        {0, 0, 0, 1, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        GROSSBRAND, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_TORNUPTO
    {
        78, 84, 78, 100, 109, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        45, //catch rate
        209, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        GROSSBRAND, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_KARNIMANI
    {
        50, 65, 64, 43, 44, 48, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        45, //catch rate
        66, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        STURZBACH, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_TYRACROC
    {
        65, 80, 80, 58, 59, 63, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        45, //catch rate
        143, //exp yield
        {0, 1, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        STURZBACH, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_IMPERGATOR
    {
        85, 105, 100, 78, 79, 83, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        45, //catch rate
        210, //exp yield
        {0, 2, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        STURZBACH, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_IGNIVOR
    {
        55, 85, 55, 60, 50, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_FIRE, //types
        45, //catch rate
        108, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        40, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        FLAMMKOERPER, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_RAMOTH
    {
        85, 60, 65, 100, 135, 105, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_FIRE, //types
        30, //catch rate
        195, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        40, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        FLAMMKOERPER, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_GLAZIOLA
    {
        65, 60, 110, 65, 130, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_ICE, //types
        45, //catch rate
        197, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        32, //egg cycles
        35, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        HAGELALARM, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_RESLADERO
    {
        78, 92, 75, 118, 74, 63, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FLYING, //types
        128, //catch rate
        160, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_KING_STEIN, //common, rare item
        127, //gender
        19, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        FLEXIBILITAET, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_LEDYBA
    {
        40, 20, 30, 55, 40, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_FLYING, //types
        255, //catch rate
        54, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        HEXAPLAGA, FRUEHWECKER, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_LEDIAN
    {
        55, 35, 50, 85, 55, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_FLYING, //types
        90, //catch rate
        134, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        HEXAPLAGA, FRUEHWECKER, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_WEBARAK
    {
        40, 60, 40, 30, 40, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_POISON, //types
        255, //catch rate
        54, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        HEXAPLAGA, INSOMNIA, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_ARIADOS
    {
        70, 90, 70, 40, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_POISON, //types
        90, //catch rate
        134, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        HEXAPLAGA, INSOMNIA, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_IKSBAT
    {
        85, 90, 80, 130, 70, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_FLYING, //types
        90, //catch rate
        204, //exp yield
        {0, 0, 0, 3, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        KONZENTRATOR, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_LAMPI
    {
        75, 38, 38, 67, 56, 56, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_ELECTRIC, //types
        190, //catch rate
        90, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GELBSTUECK, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_WATER_2, //egg groups
        VOLTABSORBER, ERLEUCHTUNG, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_LANTURN
    {
        125, 58, 58, 67, 76, 76, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_ELECTRIC, //types
        75, //catch rate
        156, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GELBSTUECK, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_WATER_2, //egg groups
        VOLTABSORBER, ERLEUCHTUNG, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_MAGNEZONE
    {
        70, 70, 115, 60, 130, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_STEEL, //types
        190, //catch rate
        42, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        10, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        STATIK, STATIK, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_TOGEKISS
    {
        85, 50, 95, 80, 120, 115, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        150, //catch rate
        37, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_MONDSTEIN, //common, rare item
        191, //gender
        10, //egg cycles
        140, //base friendship
        4, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        EDELMUT, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_FLABEBE
    {
        44, 38, 39, 42, 61, 79, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FAIRY, TYPE_FAIRY, //types
        170, //catch rate
        70, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        254, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_FAIRY, //egg groups
        LERNFAEHIG, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_TOGEPI
    {
        35, 20, 65, 20, 40, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FAIRY, TYPE_FAIRY, //types
        190, //catch rate
        74, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        10, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        UEBEREIFER, EDELMUT, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_TOGETIC
    {
        55, 40, 85, 40, 80, 105, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FAIRY, TYPE_FLYING, //types
        75, //catch rate
        114, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        10, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FAIRY, //egg groups
        UEBEREIFER, EDELMUT, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_NATU
    {
        40, 50, 45, 70, 70, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_FLYING, //types
        190, //catch rate
        73, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        SYNCHRO, FRUEHWECKER, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_XATU
    {
        65, 75, 70, 95, 95, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_FLYING, //types
        75, //catch rate
        171, //exp yield
        {0, 0, 0, 1, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        SYNCHRO, FRUEHWECKER, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_VOLTILAMM
    {
        55, 40, 40, 35, 65, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        235, //catch rate
        59, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        STATIK, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_WAATY
    {
        70, 55, 55, 45, 80, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        120, //catch rate
        117, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        STATIK, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_AMPHAROS
    {
        90, 75, 75, 55, 115, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        45, //catch rate
        194, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        STATIK, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_BLUBELLA
    {
        75, 80, 85, 50, 90, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        45, //catch rate
        184, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_MARILL
    {
        70, 20, 50, 40, 20, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_FAIRY, //types
        190, //catch rate
        58, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        10, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FAIRY, //egg groups
        SPECKSCHICHT, KRAFTKOLOSS, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_AZUMARILL
    {
        100, 50, 80, 50, 50, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_FAIRY, //types
        75, //catch rate
        153, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        10, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FAIRY, //egg groups
        SPECKSCHICHT, KRAFTKOLOSS, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MOGELBAUM
    {
        70, 100, 115, 30, 30, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_ROCK, //types
        65, //catch rate
        135, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        ROBUSTHEIT, STEINHAUPT, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_CLAVION
    {
        57, 80, 91, 75, 80, 87, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_FAIRY, //types
        80, //catch rate
        125, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        STROLCH, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_LICHTEL
    {
        50, 30, 55, 20, 65, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_FIRE, //types
        135, //catch rate
        74, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        FEUERFAENGER, FLAMMKOERPER, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_LATERNECTO
    {
        60, 40, 60, 55, 95, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_FIRE, //types
        70, //catch rate
        157, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        FEUERFAENGER, FLAMMKOERPER, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_SKLELABRA
    {
        60, 55, 90, 80, 145, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_FIRE, //types
        45, //catch rate
        217, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        FEUERFAENGER, FLAMMKOERPER, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_GRIFFEL
    {
        55, 70, 55, 85, 40, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        94, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ANGSTHASE, MITNAHME, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SHNEBEDECK
    {
        60, 62, 50, 40, 62, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_ICE, //types
        235, //catch rate
        52, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        LAERMSCHUTZ, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_REXBLISAR
    {
        90, 92, 75, 60, 92, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_ICE, //types
        120, //catch rate
        52, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_GRASS, //egg groups
        LAERMSCHUTZ, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_AMBIDIFFEL
    {
        65, 65, 45, 95, 75, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        75, //catch rate
        147, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        MITNAHME, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_FELINO
    {
        55, 45, 45, 15, 25, 25, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_GROUND, //types
        255, //catch rate
        52, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        FEUCHTIGKEIT, H2O_ABSORBER, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_MORLORD
    {
        95, 85, 85, 35, 65, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_GROUND, //types
        90, //catch rate
        137, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        FEUCHTIGKEIT, H2O_ABSORBER, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_PSIANA
    {
        65, 65, 60, 110, 130, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        45, //catch rate
        197, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        35, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SYNCHRO, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_NACHTARA
    {
        95, 65, 110, 65, 60, 130, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_DARK, //types
        45, //catch rate
        197, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        35, //egg cycles
        35, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SYNCHRO, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_KRAMURX
    {
        60, 85, 42, 91, 85, 42, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_FLYING, //types
        30, //catch rate
        107, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        3, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        INSOMNIA, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_LASCHOKING
    {
        95, 75, 80, 30, 100, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_PSYCHIC, //types
        70, //catch rate
        164, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_KING_STEIN, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_WATER_1, //egg groups
        DOESIGKEIT, TEMPOMACHER, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_KRAMSHEF
    {
        100, 125, 52, 71, 105, 52, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_FLYING, //types
        30, //catch rate
        147, //exp yield
        {0, 0, 0, 0, 1, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        3, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        INSOMNIA, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_ICOGNITO
    {
        48, 72, 48, 48, 72, 48, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        225, //catch rate
        61, //exp yield
        {0, 1, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        40, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_FROSDEDJE
    {
        70, 80, 70, 110, 80, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_GHOST, //types
        45, //catch rate
        255, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        19, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_MINERAL, //egg groups
        HAGELALARM, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_SKORGRO
    {
        75, 95, 125, 95, 45, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_FLYING, //types
        30, //catch rate
        149, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_PERSIMBEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SCHERENMACHT, SANDSCHLEIER, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_TANNZA
    {
        50, 65, 90, 15, 35, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_BUG, //types
        190, //catch rate
        60, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        ROBUSTHEIT, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_FORSTELLKA
    {
        75, 90, 140, 40, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_STEEL, //types
        75, //catch rate
        118, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        ROBUSTHEIT, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_ELEVOLTEK
    {
        75, 123, 67, 95, 95, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        190, //catch rate
        120, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        VOLTABSORBER, VOLTABSORBER, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SKORGLA
    {
        65, 75, 105, 85, 35, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_FLYING, //types
        60, //catch rate
        108, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        SCHERENMACHT, SANDSCHLEIER, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_STAHLOS
    {
        75, 85, 200, 30, 55, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_GROUND, //types
        25, //catch rate
        196, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_METALLMANTEL, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        STEINHAUPT, ROBUSTHEIT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_SNUBBULL
    {
        60, 80, 50, 30, 40, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FAIRY, TYPE_FAIRY, //types
        190, //catch rate
        63, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        191, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FAIRY, //egg groups
        BEDROHER, ANGSTHASE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_GRANBULL
    {
        90, 120, 75, 45, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FAIRY, TYPE_FAIRY, //types
        75, //catch rate
        178, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        191, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FAIRY, //egg groups
        BEDROHER, BEDROHER, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MAMUTEL
    {
        110, 130, 80, 80, 70, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_GROUND, //types
        50, //catch rate
        216, //exp yield
        {1, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        19, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        DOESIGKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_SCHEROX
    {
        70, 130, 100, 65, 55, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_STEEL, //types
        25, //catch rate
        200, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        HEXAPLAGA, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_POTTROTT
    {
        20, 10, 230, 5, 10, 230, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_ROCK, //types
        190, //catch rate
        80, //exp yield
        {0, 0, 1, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_BEERENSAFT, ITEM_BEERENSAFT, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        ROBUSTHEIT, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_SKARABORN
    {
        80, 125, 75, 85, 40, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_FIGHTING, //types
        45, //catch rate
        200, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        HEXAPLAGA, ADRENALIN, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KRYPPUK
    {
        50, 92, 108, 35, 92, 108, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_DARK, //types
        60, //catch rate
        132, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ERZWINGER, ERZWINGER, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_TEDDIURSA
    {
        60, 80, 50, 40, 50, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        120, //catch rate
        124, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_SINELBEERE, ITEM_TSITRUBEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        MITNAHME, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_URSARING
    {
        90, 130, 75, 55, 75, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        60, //catch rate
        189, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_SINELBEERE, ITEM_TSITRUBEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ADRENALIN, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SCHNECKMAG
    {
        40, 40, 40, 20, 70, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        190, //catch rate
        78, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        MAGMAPANZER, FLAMMKOERPER, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_MAGCARGO
    {
        50, 50, 120, 30, 80, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_ROCK, //types
        75, //catch rate
        154, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        MAGMAPANZER, FLAMMKOERPER, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_QUIEKEL
    {
        50, 50, 40, 50, 30, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_GROUND, //types
        225, //catch rate
        78, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_WILBIRBEERE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        DOESIGKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_KEIFEL
    {
        100, 100, 80, 50, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_GROUND, //types
        75, //catch rate
        160, //exp yield
        {1, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_WILBIRBEERE, ITEM_EWIGES_EIS, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        DOESIGKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_CORASONN
    {
        55, 55, 85, 35, 65, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_ROCK, //types
        60, //catch rate
        113, //exp yield
        {0, 0, 1, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_PURPURSTUECK, //common, rare item
        191, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_3, //egg groups
        UEBEREIFER, INNERE_KRAFT, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_REMORAID
    {
        35, 65, 35, 65, 65, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        190, //catch rate
        78, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_2, //egg groups
        UEBEREIFER, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_OCTILLERY
    {
        75, 105, 75, 45, 105, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        75, //catch rate
        164, //exp yield
        {0, 1, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_2, //egg groups
        SAUGNAPF, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TENTACLES, //form
    },

    //POKEMON_BOTOGEL
    {
        45, 55, 45, 75, 65, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_FLYING, //types
        45, //catch rate
        183, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        MUNTERKEIT, UEBEREIFER, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_SCHLURPLEK
    {
        110, 85, 95, 50, 80, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        30, //catch rate
        190, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        TEMPOMACHER, DOESIGKEIT, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_PANZAERON
    {
        65, 80, 140, 70, 40, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_FLYING, //types
        25, //catch rate
        168, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_HACKATTACK, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        ADLERAUGE, ROBUSTHEIT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_HUNDUSTER
    {
        45, 60, 30, 65, 80, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_FIRE, //types
        120, //catch rate
        114, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        FRUEHWECKER, FEUERFAENGER, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_HUNDEMON
    {
        75, 90, 50, 95, 110, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_FIRE, //types
        45, //catch rate
        204, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        FRUEHWECKER, FEUERFAENGER, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_SEEDRAKING
    {
        75, 95, 95, 85, 95, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_DRAGON, //types
        45, //catch rate
        207, //exp yield
        {0, 1, 0, 0, 1, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_DRACHENHAUT, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_DRAGON, //egg groups
        WASSERTEMPO, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_PHANPY
    {
        90, 60, 60, 40, 40, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        120, //catch rate
        124, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        MITNAHME, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_DONPHAN
    {
        90, 120, 120, 50, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        60, //catch rate
        189, //exp yield
        {0, 1, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ROBUSTHEIT, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_PORYGON2
    {
        85, 80, 90, 60, 105, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        180, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_UP_GRADE, ITEM_UP_GRADE, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        FAEHRTE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_VOLUMINAS
    {
        60, 55, 145, 40, 75, 150, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_STEEL, //types
        45, //catch rate
        189, //exp yield
        {0, 0, 1, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GRANITSTEIN, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        ROBUSTHEIT, MAGNETFALLE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_MULTI, //form
    },

    //POKEMON_TRAUNMAGIL
    {
        60, 60, 60, 105, 105, 105, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_GHOST, //types
        45, //catch rate
        174, //exp yield
        {0, 0, 0, 3, 2, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_BANNSTICKER, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        4, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_RABAUZ
    {
        35, 35, 35, 35, 35, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        75, //catch rate
        91, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ADRENALIN, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KAPOERA
    {
        50, 95, 95, 70, 35, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        45, //catch rate
        138, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        BEDROHER, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_KUSSILLA
    {
        45, 30, 15, 65, 85, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_PSYCHIC, //types
        45, //catch rate
        87, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        254, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        DOESIGKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_ELEKID
    {
        45, 63, 37, 95, 65, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        45, //catch rate
        106, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        63, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        STATIK, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_MAGBY
    {
        45, 75, 37, 83, 70, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        45, //catch rate
        117, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        63, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        FLAMMKOERPER, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MILTANK
    {
        95, 80, 105, 100, 40, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        200, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_KUHMUH_MILCH, ITEM_KUHMUH_MILCH, //common, rare item
        254, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SPECKSCHICHT, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        CURATOR, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_HEITEIRA
    {
        255, 10, 10, 55, 75, 135, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        30, //catch rate
        255, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GLUECKS_EI, //common, rare item
        254, //gender
        40, //egg cycles
        140, //base friendship
        4, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_FAIRY, //egg groups
        INNERE_KRAFT, EDELMUT, //abilities
        0, //safari rate
        9, //flip and color
        CURATOR, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_RAIKOU
    {
        90, 85, 75, 115, 115, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        3, //catch rate
        216, //exp yield
        {0, 0, 0, 2, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        80, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_ENTEI
    {
        115, 115, 85, 100, 90, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        3, //catch rate
        217, //exp yield
        {1, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        80, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_SUICUNE
    {
        100, 75, 115, 85, 90, 115, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        3, //catch rate
        215, //exp yield
        {0, 0, 1, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        80, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_LARVITAR
    {
        50, 64, 50, 41, 45, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_GROUND, //types
        45, //catch rate
        67, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        ADRENALIN, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_PUPITAR
    {
        70, 84, 70, 51, 65, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_GROUND, //types
        45, //catch rate
        144, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        EXPIDERMIS, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_DESPOTAR
    {
        100, 134, 110, 61, 95, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_DARK, //types
        45, //catch rate
        218, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        SANDSTURM, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_LUGIA
    {
        106, 90, 130, 110, 90, 154, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_FLYING, //types
        3, //catch rate
        220, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_HO_OH
    {
        106, 130, 90, 90, 110, 154, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FLYING, //types
        3, //catch rate
        220, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_CELEBI
    {
        100, 100, 100, 100, 100, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_GRASS, //types
        45, //catch rate
        64, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_PRUNUSBEERE, ITEM_PRUNUSBEERE, //common, rare item
        255, //gender
        120, //egg cycles
        100, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        INNERE_KRAFT, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_BISAFLORM
    {
        80, 100, 123, 80, 122, 120, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_POISON, //types
        3, //catch rate
        255, //exp yield
        {2, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        120, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        SPECKSCHICHT, SPECKSCHICHT, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_GLURAKM
    {
        78, 145, 111, 100, 130, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_DRAGON, //types
        3, //catch rate
        255, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        120, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        SCHWEBE, SCHWEBE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },
 
    //POKEMON_AQUANAM
    {
        130, 65, 95, 80, 125, 115, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_ICE, //types
        3, //catch rate
        140, //exp yield
        {0, 0, 0, 0, 1, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        120, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        REGENGENUSS, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_BLITZAM
    {
        65, 65, 60, 145, 135, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_FAIRY, //types
        45, //catch rate
        255, //exp yield
        {0, 0, 0, 2, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        35, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        TEMPOSCHUB, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_FLAMARM
    {
        65, 145, 100, 90, 95, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_STEEL, //types
        45, //catch rate
        240, //exp yield
        {0, 2, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        35, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        MAGNETFALLE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_DURENGARDA
    {
        60, 150, 50, 60, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_GHOST, //types
        35, //catch rate
        244, //exp yield
        {0, 2, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        TAKTIKWECHS, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_IN
    {
        90, 135, 70, 110, 135, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_DARK, //types
        45, //catch rate
        240, //exp yield
        {0, 2, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        FEUERFAENGER, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_GAME
    {
        75, 95, 70, 155, 140, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_DRAGON, //types
        45, //catch rate
        240, //exp yield
        {0, 0, 0, 3, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        0, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        EXPIDERMIS, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_TURTOKM
    {
        79, 103, 120, 78, 135, 115, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        45, //catch rate
        240, //exp yield
        {0, 0, 3, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        NOTSCHUTZ, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_AMPHARAOSM
    {
        90, 95, 105, 45, 165, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_DRAGON, //types
        45, //catch rate
        240, //exp yield
        {0, 0, 0, 0, 2, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        NOTSCHUTZ, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_GENGARM
    {
        60, 65, 80, 130, 170, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_POISON, //types
        45, //catch rate
        240, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        120, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        WEGSPERRE, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_BIBORM
    {
        65, 160, 95, 140, 45, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_POISON, //types
        45, //catch rate
        240, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        120, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ALTARIAM
    {
        75, 70, 125, 100, 125, 155, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_ELECTRIC, //types
        45, //catch rate
        240, //exp yield
        {0, 0, 0, 0, 1, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        120, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_GEOWAZM
    {
        80, 175, 185, 35, 55, 125, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_FIRE, //types
        45, //catch rate
        240, //exp yield
        {0, 1, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        FEUERFAENGER, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_SENGOM
    {
        73, 145, 80, 135, 60, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        90, //catch rate
        240, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        TEMPOSCHUB, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_VIPITISM
    {
        73, 140, 100, 100, 115, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        90, //catch rate
        240, //exp yield
        {0, 2, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        TEMPOSCHUB, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ZOBIRISM
    {
        50, 100, 110, 50, 65, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_ROCK, //types
        45, //catch rate
        180, //exp yield
        {0, 1, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        3, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_10d
    {
        50, 150, 50, 150, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        3, //catch rate
        1, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_10e
    {
        50, 150, 50, 150, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        3, //catch rate
        1, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_10f
    {
        50, 150, 50, 150, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        3, //catch rate
        1, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_110
    {
        50, 150, 50, 150, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        3, //catch rate
        1, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_111
    {
        50, 150, 50, 150, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        3, //catch rate
        1, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_112
    {
        50, 150, 50, 150, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        3, //catch rate
        1, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_113
    {
        50, 150, 50, 150, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        3, //catch rate
        1, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_114
    {
        50, 150, 50, 150, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        3, //catch rate
        1, //exp yield
        {2, 2, 2, 2, 2, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_LOCKSCHAL
    {
        50, 56, 65, 53, 40, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        45, //catch rate
        65, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_HUMAN, //egg groups
        NOTDUENGER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_STICHSCHAL
    {
        70, 90, 90, 70, 65, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        45, //catch rate
        141, //exp yield
        {0, 1, 1, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_HUMAN, //egg groups
        NOTDUENGER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_STAHLSTICH
    {
        95, 115, 115, 95, 65, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_STEEL, //types
        45, //catch rate
        208, //exp yield
        {0, 2, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_HUMAN, //egg groups
        NOTDUENGER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_WELUNO
    {
        45, 59, 40, 45, 65, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        45, //catch rate
        65, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_MONSTER, //egg groups
        GROSSBRAND, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_ORTHODOS
    {
        75, 85, 60, 65, 85, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_DARK, //types
        45, //catch rate
        142, //exp yield
        {0, 1, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_MONSTER, //egg groups
        GROSSBRAND, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_ZERBERTRES
    {
        80, 125, 62, 90, 120, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_DARK, //types
        45, //catch rate
        209, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_MONSTER, //egg groups
        GROSSBRAND, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_SEEKID
    {
        45, 57, 45, 75, 57, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        45, //catch rate
        65, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_DRAGON, EGG_GROUP_WATER_1, //egg groups
        STURZBACH, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_SEESKULL
    {
        55, 85, 65, 95, 85, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        45, //catch rate
        143, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_DRAGON, EGG_GROUP_WATER_1, //egg groups
        STURZBACH, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_SKULLYDRA
    {
        75, 95, 70, 135, 125, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_DRAGON, //types
        45, //catch rate
        210, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_DRAGON, EGG_GROUP_WATER_1, //egg groups
        STURZBACH, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_FIFFYEN
    {
        35, 55, 35, 35, 30, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_DARK, //types
        255, //catch rate
        55, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_PIRSIFBEERE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ANGSTHASE, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_MAGNAYEN
    {
        70, 90, 70, 70, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_DARK, //types
        127, //catch rate
        128, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_PIRSIFBEERE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        BEDROHER, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_ZIGZACHS
    {
        38, 30, 41, 60, 30, 41, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        255, //catch rate
        60, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_SINELBEERE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        MITNAHME, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_GERADAKS
    {
        78, 70, 61, 100, 50, 61, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        90, //catch rate
        128, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_SINELBEERE, ITEM_TSITRUBEERE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        MITNAHME, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_WAUMPEL
    {
        45, 45, 35, 20, 20, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_BUG, //types
        255, //catch rate
        54, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        PUDERABWEHR, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_SCHALOKO
    {
        50, 35, 55, 15, 25, 25, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_BUG, //types
        120, //catch rate
        71, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        EXPIDERMIS, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_PAPINELLA
    {
        60, 70, 50, 65, 90, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_FLYING, //types
        45, //catch rate
        161, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_SILBERSTAUB, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        HEXAPLAGA, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_PANEKON
    {
        50, 35, 55, 15, 25, 25, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_BUG, //types
        120, //catch rate
        72, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        EXPIDERMIS, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_PUDOX
    {
        60, 50, 70, 65, 50, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_POISON, //types
        45, //catch rate
        160, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_SILBERSTAUB, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        PUDERABWEHR, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_LOTURZEL
    {
        40, 30, 30, 30, 40, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_GRASS, //types
        255, //catch rate
        74, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_GRASS, //egg groups
        WASSERTEMPO, REGENGENUSS, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_LOMBRERO
    {
        60, 50, 50, 50, 60, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_GRASS, //types
        120, //catch rate
        141, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_GRASS, //egg groups
        WASSERTEMPO, REGENGENUSS, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KAPPALORES
    {
        80, 70, 70, 70, 90, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_GRASS, //types
        45, //catch rate
        181, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_GRASS, //egg groups
        WASSERTEMPO, REGENGENUSS, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_SAMURZEL
    {
        40, 40, 50, 30, 30, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        255, //catch rate
        74, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, FRUEHWECKER, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_BLANAS
    {
        70, 70, 40, 60, 60, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_DARK, //types
        120, //catch rate
        141, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, FRUEHWECKER, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_TENGULIST
    {
        90, 100, 60, 80, 90, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_DARK, //types
        45, //catch rate
        181, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, FRUEHWECKER, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_NINCADA
    {
        31, 45, 90, 40, 30, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_GROUND, //types
        255, //catch rate
        65, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        FACETTENAUGE, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_NINJASK
    {
        61, 90, 45, 160, 50, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_FLYING, //types
        120, //catch rate
        155, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        TEMPOSCHUB, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_NINJATOM
    {
        1, 90, 45, 40, 30, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_GHOST, //types
        45, //catch rate
        95, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        15, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        WUNDERWACHE, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_SCHWALBINI
    {
        40, 55, 30, 85, 30, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        200, //catch rate
        59, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        ADRENALIN, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_SCHWALBOSS
    {
        60, 85, 60, 125, 50, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        45, //catch rate
        162, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_FLYING, //egg groups
        ADRENALIN, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_KNILZ
    {
        60, 40, 60, 35, 40, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        255, //catch rate
        65, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_GRASS, //egg groups
        SPORENWIRT, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_KAPILZ
    {
        60, 130, 80, 70, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_FIGHTING, //types
        90, //catch rate
        165, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_GRASS, //egg groups
        SPORENWIRT, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_PANDIR
    {
        60, 60, 60, 60, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        255, //catch rate
        85, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_MARONBEERE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_HUMAN, //egg groups
        TEMPOMACHER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_WINGULL
    {
        40, 30, 30, 85, 55, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_FLYING, //types
        190, //catch rate
        64, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FLYING, //egg groups
        ADLERAUGE, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_PELIPPER
    {
        60, 50, 100, 65, 85, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_FLYING, //types
        45, //catch rate
        164, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FLYING, //egg groups
        ADLERAUGE, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_GEHWEIHER
    {
        40, 30, 32, 65, 50, 52, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_WATER, //types
        200, //catch rate
        63, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_BUG, //egg groups
        WASSERTEMPO, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_MASKEREGEN
    {
        70, 60, 62, 60, 80, 82, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_FLYING, //types
        75, //catch rate
        128, //exp yield
        {0, 0, 0, 0, 1, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_SILBERSTAUB, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_BUG, //egg groups
        BEDROHER, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_WAILMER
    {
        130, 70, 35, 60, 70, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        125, //catch rate
        137, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        40, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_WATER_2, //egg groups
        AQUAHUELLE, DOESIGKEIT, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_WAILORD
    {
        170, 90, 45, 60, 90, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        60, //catch rate
        206, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        40, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_WATER_2, //egg groups
        AQUAHUELLE, DOESIGKEIT, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_ENECO
    {
        50, 45, 45, 50, 35, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        255, //catch rate
        65, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_JONAGOBEERE, //common, rare item
        191, //gender
        15, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FAIRY, //egg groups
        CHARMEBOLZEN, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_ENEKORO
    {
        70, 65, 65, 70, 55, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        60, //catch rate
        138, //exp yield
        {1, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_JONAGOBEERE, //common, rare item
        191, //gender
        15, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FAIRY, //egg groups
        CHARMEBOLZEN, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_KECLEON
    {
        60, 90, 70, 40, 60, 120, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        200, //catch rate
        132, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_PERSIMBEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        FARBWECHSEL, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_PUPPANCE
    {
        40, 40, 55, 55, 40, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_PSYCHIC, //types
        255, //catch rate
        58, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_LEPUMENTAS
    {
        60, 70, 105, 75, 70, 120, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_PSYCHIC, //types
        90, //catch rate
        189, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_NASGNET
    {
        30, 45, 135, 30, 45, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_ROCK, //types
        255, //catch rate
        108, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        ROBUSTHEIT, MAGNETFALLE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_MAGBRANT
    {
        75, 95, 67, 83, 125, 95, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_FIRE, //types
        90, //catch rate
        161, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        FLAMMKOERPER, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_ZWIRRFINST
    {
        45, 100, 135, 45, 65, 135, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_GHOST, //types
        45, //catch rate
        98, //exp yield
        {0, 1, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        3, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_SCHMERBE
    {
        50, 48, 43, 60, 46, 41, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_GROUND, //types
        190, //catch rate
        92, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_WATER_2, //egg groups
        DOESIGKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_WELSAR
    {
        110, 78, 73, 60, 76, 71, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_GROUND, //types
        75, //catch rate
        158, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_WATER_2, //egg groups
        DOESIGKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_LIEBISKUS
    {
        43, 30, 55, 97, 40, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        225, //catch rate
        110, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_HERZSCHUPPE, ITEM_NONE, //common, rare item
        191, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_WATER_2, //egg groups
        WASSERTEMPO, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_KREBSCORPS
    {
        43, 80, 65, 35, 50, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        205, //catch rate
        111, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_3, //egg groups
        SCHERENMACHT, PANZERHAUT, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_KREBUTACK
    {
        63, 120, 85, 55, 90, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_DARK, //types
        155, //catch rate
        161, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_3, //egg groups
        SCHERENMACHT, PANZERHAUT, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_BARSCHWA
    {
        20, 15, 20, 80, 10, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        255, //catch rate
        61, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_DRAGON, //egg groups
        WASSERTEMPO, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_MILOTIC
    {
        95, 60, 79, 81, 100, 125, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        60, //catch rate
        213, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_DRAGON, //egg groups
        NOTSCHUTZ, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_KANIVANHA
    {
        45, 90, 20, 65, 65, 20, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_DARK, //types
        225, //catch rate
        88, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_WATER_2, //egg groups
        RAUHAUT, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_TOHAIDO
    {
        70, 120, 40, 95, 95, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_DARK, //types
        60, //catch rate
        175, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_2, EGG_GROUP_WATER_2, //egg groups
        RAUHAUT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_KNACKLION
    {
        45, 100, 45, 10, 45, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        255, //catch rate
        73, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_PUDERSAND, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        SCHERENMACHT, AUSWEGSLOS, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_VIBRAVA
    {
        50, 70, 50, 70, 50, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_DRAGON, //types
        120, //catch rate
        126, //exp yield
        {0, 1, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        SCHWEBE, SCHWEBE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED_INSECT, //form
    },

    //POKEMON_LIBELLDRA
    {
        80, 100, 80, 100, 80, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_DRAGON, //types
        45, //catch rate
        197, //exp yield
        {0, 1, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_BUG, //egg groups
        SCHWEBE, SCHWEBE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_RIOLU
    {
        72, 60, 30, 25, 20, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_FIGHTING, //types
        180, //catch rate
        160, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        KONZENTRATOR, KONZENTRATOR, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_LUCARIO
    {
        70, 110, 70, 90, 115, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_STEEL, //types
        200, //catch rate
        210, //exp yield
        {2, 3, 1, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_KING_STEIN, //common, rare item
        63, //gender
        20, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        KONZENTRATOR, KONZENTRATOR, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_FRIZELBLIZ
    {
        40, 45, 40, 65, 65, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        120, //catch rate
        104, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        STATIK, BLITZFAENGER, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_VOLTENSO
    {
        70, 75, 60, 105, 105, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        45, //catch rate
        168, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        STATIK, BLITZFAENGER, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_CAMAUB
    {
        60, 60, 40, 35, 65, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_GROUND, //types
        255, //catch rate
        88, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_FRAGIABEERE, ITEM_FRAGIABEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        DOESIGKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_CAMERUPT
    {
        70, 100, 70, 40, 105, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIRE, TYPE_GROUND, //types
        150, //catch rate
        175, //exp yield
        {0, 1, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_FRAGIABEERE, ITEM_FRAGIABEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        MAGMAPANZER, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_SEEMOPS
    {
        70, 40, 50, 25, 55, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_WATER, //types
        255, //catch rate
        75, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        SPECKSCHICHT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_SEEJONG
    {
        90, 60, 70, 45, 75, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_WATER, //types
        120, //catch rate
        128, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        SPECKSCHICHT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_WALRAISA
    {
        110, 80, 90, 65, 95, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_WATER, //types
        45, //catch rate
        192, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_FIELD, //egg groups
        SPECKSCHICHT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_TUSKA
    {
        50, 85, 40, 35, 85, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_GRASS, //types
        190, //catch rate
        97, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GIFTSTICH, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_HUMAN, //egg groups
        SANDSCHLEIER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_NOKTUSKA
    {
        70, 115, 60, 55, 115, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_DARK, //types
        60, //catch rate
        177, //exp yield
        {0, 1, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GIFTSTICH, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        3, //lvl up curve
        EGG_GROUP_GRASS, EGG_GROUP_HUMAN, //egg groups
        SANDSCHLEIER, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_SCHNEPPKE
    {
        50, 50, 50, 50, 50, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_ICE, //types
        190, //catch rate
        74, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_MINERAL, //egg groups
        KONZENTRATOR, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_FIRNONTOR
    {
        80, 80, 80, 80, 80, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_ICE, //types
        75, //catch rate
        187, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_EWIGES_EIS, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_MINERAL, //egg groups
        KONZENTRATOR, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_LUNASTEIN
    {
        70, 55, 65, 70, 95, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_PSYCHIC, //types
        45, //catch rate
        150, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_MONDSTEIN, //common, rare item
        255, //gender
        25, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_SONNFEL
    {
        70, 95, 85, 70, 55, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_PSYCHIC, //types
        45, //catch rate
        150, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_SONNENSTEIN, //common, rare item
        255, //gender
        25, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_AZURILL
    {
        50, 20, 40, 20, 20, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        150, //catch rate
        33, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        191, //gender
        10, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        SPECKSCHICHT, KRAFTKOLOSS, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_SPOINK
    {
        60, 25, 35, 60, 70, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        255, //catch rate
        89, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SPECKSCHICHT, TEMPOMACHER, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_GROINK
    {
        80, 45, 65, 80, 90, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        60, //catch rate
        164, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SPECKSCHICHT, TEMPOMACHER, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_PLUSLE
    {
        60, 50, 40, 95, 85, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        200, //catch rate
        120, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_FAIRY, //egg groups
        PLUS, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_MINUN
    {
        60, 40, 50, 95, 75, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ELECTRIC, TYPE_ELECTRIC, //types
        200, //catch rate
        120, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_FAIRY, //egg groups
        MINUS, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_FLUNKIFER
    {
        50, 85, 85, 50, 55, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_FAIRY, //types
        45, //catch rate
        98, //exp yield
        {0, 1, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FAIRY, //egg groups
        SCHERENMACHT, BEDROHER, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_MEDITIE
    {
        30, 40, 55, 60, 40, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_PSYCHIC, //types
        180, //catch rate
        91, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        MENTALKRAFT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_MEDITALIS
    {
        60, 60, 75, 80, 60, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_FIGHTING, TYPE_PSYCHIC, //types
        90, //catch rate
        153, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_HUMAN, EGG_GROUP_HUMAN, //egg groups
        MENTALKRAFT, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_WABLU
    {
        45, 40, 60, 50, 40, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_FLYING, //types
        255, //catch rate
        74, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_DRAGON, //egg groups
        INNERE_KRAFT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_ALTARIA
    {
        75, 70, 90, 80, 70, 105, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_FLYING, //types
        45, //catch rate
        188, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_FLYING, EGG_GROUP_DRAGON, //egg groups
        INNERE_KRAFT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_ISSO
    {
        95, 23, 48, 23, 23, 48, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        125, //catch rate
        44, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        WEGSPERRE, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_ZWIRRLICHT
    {
        20, 40, 90, 25, 30, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_GHOST, //types
        190, //catch rate
        97, //exp yield
        {0, 0, 1, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_BANNSTICKER, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        4, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_ZWIRRKLOP
    {
        40, 70, 130, 25, 60, 130, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_GHOST, //types
        90, //catch rate
        179, //exp yield
        {0, 0, 1, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_BANNSTICKER, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        4, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_PORYGON_Z
    {
        85, 80, 70, 90, 135, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        30, //catch rate
        210, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_DUBIOSDISK, ITEM_DUBIOSDISK, //common, rare item
        255, //gender
        20, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        ANPASSUNG, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_LEGS, //form
    },

    //POKEMON_BUMMELZ
    {
        60, 60, 60, 30, 35, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        255, //catch rate
        83, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SCHNARCHNASE, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_MUNTIER
    {
        80, 80, 80, 90, 55, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        120, //catch rate
        126, //exp yield
        {0, 0, 0, 2, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        MUNTERKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_LETARKING
    {
        150, 160, 100, 100, 95, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        210, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        15, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        SCHNARCHNASE, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_SCHLUPPUCK
    {
        70, 43, 53, 40, 43, 53, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        225, //catch rate
        75, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_RIESENPERLE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        KLOAKENSOSSE, WERTEHALTER, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_SCHLUKWECH
    {
        100, 73, 83, 55, 73, 83, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        75, //catch rate
        168, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_RIESENPERLE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        KLOAKENSOSSE, WERTEHALTER, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_TROPIUS
    {
        99, 68, 83, 51, 72, 87, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GRASS, TYPE_FLYING, //types
        200, //catch rate
        169, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_GRASS, //egg groups
        CHLOROPHYLL, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_KAUMALAT
    {
        58, 70, 45, 42, 40, 45, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_GROUND, //types
        190, //catch rate
        68, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_MARONBEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        SANDSCHLEIER, SANDSCHLEIER, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_KNARKSEL
    {
        68, 90, 65, 82, 50, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_GROUND, //types
        120, //catch rate
        126, //exp yield
        {2, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_MARONBEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        SANDSCHLEIER, SANDSCHLEIER, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_KNAKRACK
    {
        108, 130, 95, 102, 80, 85, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_GROUND, //types
        45, //catch rate
        184, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_MARONBEERE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        3, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_FIELD, //egg groups
        SANDSCHLEIER, SANDSCHLEIER, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_PERLU
    {
        35, 64, 85, 32, 74, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        255, //catch rate
        142, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_INDIGOSTUECK, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        PANZERHAUT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_AALABYSS
    {
        55, 104, 105, 52, 94, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        60, //catch rate
        178, //exp yield
        {0, 1, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        WASSERTEMPO, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_SAGANABYSS
    {
        55, 84, 105, 52, 114, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        60, //catch rate
        178, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        WASSERTEMPO, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_ABSOL
    {
        65, 130, 60, 75, 75, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DARK, TYPE_DARK, //types
        30, //catch rate
        174, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        3, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        9, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_SHUPPET
    {
        44, 75, 35, 45, 63, 33, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_GHOST, //types
        225, //catch rate
        97, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_BANNSTICKER, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        4, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        INSOMNIA, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_BANETTE
    {
        64, 115, 65, 65, 83, 63, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GHOST, TYPE_GHOST, //types
        45, //catch rate
        179, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_BANNSTICKER, //common, rare item
        127, //gender
        25, //egg cycles
        35, //base friendship
        4, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        INSOMNIA, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_VIPITIS
    {
        73, 100, 60, 65, 100, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_POISON, TYPE_POISON, //types
        90, //catch rate
        165, //exp yield
        {0, 1, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_DRAGON, //egg groups
        EXPIDERMIS, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_SENGO
    {
        73, 115, 60, 90, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        90, //catch rate
        165, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_FIELD, EGG_GROUP_FIELD, //egg groups
        IMMUNITAET, ABILITY_NONE, //abilities
        0, //safari rate
        4, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_RELICANTH
    {
        100, 90, 130, 55, 45, 65, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_ROCK, //types
        25, //catch rate
        198, //exp yield
        {1, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GRUENSTUECK, //common, rare item
        31, //gender
        40, //egg cycles
        70, //base friendship
        5, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_2, //egg groups
        WASSERTEMPO, STEINHAUPT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_STOLLUNIOR
    {
        50, 70, 100, 30, 40, 40, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_ROCK, //types
        180, //catch rate
        96, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GRANITSTEIN, //common, rare item
        127, //gender
        35, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        ROBUSTHEIT, STEINHAUPT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_STOLLRAK
    {
        60, 90, 140, 40, 50, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_ROCK, //types
        90, //catch rate
        152, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GRANITSTEIN, //common, rare item
        127, //gender
        35, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        ROBUSTHEIT, STEINHAUPT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_STOLLOSS
    {
        70, 110, 180, 50, 60, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_ROCK, //types
        45, //catch rate
        205, //exp yield
        {0, 0, 3, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_GRANITSTEIN, //common, rare item
        127, //gender
        35, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_MONSTER, EGG_GROUP_MONSTER, //egg groups
        ROBUSTHEIT, STEINHAUPT, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_FORMEO
    {
        70, 70, 70, 70, 70, 70, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        45, //catch rate
        145, //exp yield
        {1, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_ZAUBERWASSER, ITEM_ZAUBERWASSER, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        0, //lvl up curve
        EGG_GROUP_FAIRY, EGG_GROUP_AMORPHUS, //egg groups
        PROGNOSE, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_BALL, //form
    },

    //POKEMON_VOLBEAT
    {
        65, 73, 55, 85, 47, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_BUG, //types
        150, //catch rate
        146, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        15, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_HUMAN, //egg groups
        ERLEUCHTUNG, HEXAPLAGA, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_ILLUMISE
    {
        65, 47, 55, 85, 73, 75, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_BUG, TYPE_BUG, //types
        150, //catch rate
        146, //exp yield
        {0, 0, 0, 1, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        254, //gender
        15, //egg cycles
        70, //base friendship
        2, //lvl up curve
        EGG_GROUP_BUG, EGG_GROUP_HUMAN, //egg groups
        DOESIGKEIT, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_LILIEP
    {
        66, 41, 77, 23, 61, 87, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_GRASS, //types
        45, //catch rate
        121, //exp yield
        {0, 0, 0, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        30, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        SAUGNAPF, ABILITY_NONE, //abilities
        0, //safari rate
        6, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_WIELIE
    {
        86, 81, 97, 43, 81, 107, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_GRASS, //types
        45, //catch rate
        201, //exp yield
        {0, 0, 0, 0, 0, 2, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        30, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        SAUGNAPF, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_ANORITH
    {
        45, 95, 50, 75, 40, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_BUG, //types
        45, //catch rate
        119, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        30, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        KAMPFPANZER, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_INSECT, //form
    },

    //POKEMON_ARMALDO
    {
        75, 125, 100, 45, 70, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_BUG, //types
        45, //catch rate
        200, //exp yield
        {0, 2, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        31, //gender
        30, //egg cycles
        70, //base friendship
        1, //lvl up curve
        EGG_GROUP_WATER_3, EGG_GROUP_WATER_3, //egg groups
        KAMPFPANZER, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_TRASLA
    {
        28, 25, 25, 40, 45, 35, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_FAIRY, //types
        235, //catch rate
        70, //exp yield
        {0, 0, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SYNCHRO, FAEHRTE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KIRLIA
    {
        38, 35, 35, 50, 65, 55, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_FAIRY, //types
        120, //catch rate
        140, //exp yield
        {0, 0, 0, 0, 2, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SYNCHRO, FAEHRTE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_GUARDEVOIR
    {
        68, 65, 65, 80, 125, 115, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_FAIRY, //types
        45, //catch rate
        208, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        20, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SYNCHRO, FAEHRTE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KINDWURM
    {
        45, 75, 60, 50, 40, 30, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_DRAGON, //types
        45, //catch rate
        89, //exp yield
        {0, 1, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_DRACHENHAUT, //common, rare item
        127, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_DRAGON, EGG_GROUP_DRAGON, //egg groups
        STEINHAUPT, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_DRASCHEL
    {
        65, 95, 100, 50, 60, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_DRAGON, //types
        45, //catch rate
        144, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_DRACHENHAUT, //common, rare item
        127, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_DRAGON, EGG_GROUP_DRAGON, //egg groups
        STEINHAUPT, ABILITY_NONE, //abilities
        0, //safari rate
        8, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_BRUTALANDA
    {
        95, 135, 80, 100, 110, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_FLYING, //types
        45, //catch rate
        218, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_DRACHENHAUT, //common, rare item
        127, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_DRAGON, EGG_GROUP_DRAGON, //egg groups
        BEDROHER, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ANIMAL, //form
    },

    //POKEMON_TANHEL
    {
        40, 55, 80, 30, 35, 60, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_PSYCHIC, //types
        3, //catch rate
        103, //exp yield
        {0, 0, 1, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_METALLMANTEL, //common, rare item
        255, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        NEUTRALTORSO, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HEAD, //form
    },

    //POKEMON_METANG
    {
        60, 75, 100, 50, 55, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_PSYCHIC, //types
        3, //catch rate
        153, //exp yield
        {0, 0, 2, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_METALLMANTEL, //common, rare item
        255, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        NEUTRALTORSO, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_METAGROSS
    {
        80, 135, 130, 70, 95, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_PSYCHIC, //types
        3, //catch rate
        210, //exp yield
        {0, 0, 3, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_METALLMANTEL, //common, rare item
        255, //gender
        40, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_MINERAL, EGG_GROUP_MINERAL, //egg groups
        NEUTRALTORSO, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_MULTI, //form
    },

    //POKEMON_REGIROCK
    {
        80, 100, 200, 50, 50, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ROCK, TYPE_ROCK, //types
        3, //catch rate
        217, //exp yield
        {0, 0, 3, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        80, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        NEUTRALTORSO, ABILITY_NONE, //abilities
        0, //safari rate
        5, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_REGICE
    {
        80, 50, 100, 50, 100, 200, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_ICE, TYPE_ICE, //types
        3, //catch rate
        216, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        80, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        NEUTRALTORSO, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_REGISTEEL
    {
        80, 75, 150, 50, 75, 150, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_STEEL, //types
        3, //catch rate
        215, //exp yield
        {0, 0, 2, 0, 0, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        80, //egg cycles
        35, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        NEUTRALTORSO, ABILITY_NONE, //abilities
        0, //safari rate
        7, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_KYOGRE
    {
        100, 100, 90, 90, 150, 140, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_WATER, TYPE_WATER, //types
        5, //catch rate
        218, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        NIESEL, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_FISH, //form
    },

    //POKEMON_GROUDON
    {
        100, 150, 140, 90, 100, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_GROUND, //types
        5, //catch rate
        218, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        WANDLUNGSK, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    },

    //POKEMON_RAYQUAZA
    {
        105, 150, 90, 95, 150, 90, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_FLYING, //types
        3, //catch rate
        220, //exp yield
        {0, 2, 0, 0, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        KLIMASCHUTZ, ABILITY_NONE, //abilities
        0, //safari rate
        3, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_SNAKE, //form
    },

    //POKEMON_LATIAS
    {
        80, 80, 90, 110, 110, 130, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_PSYCHIC, //types
        3, //catch rate
        211, //exp yield
        {0, 0, 0, 0, 0, 3, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        254, //gender
        120, //egg cycles
        90, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_LATIOS
    {
        80, 90, 80, 110, 130, 110, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_DRAGON, TYPE_PSYCHIC, //types
        3, //catch rate
        211, //exp yield
        {0, 0, 0, 0, 3, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        120, //egg cycles
        90, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_WINGED, //form
    },

    //POKEMON_JIRACHI
    {
        100, 100, 100, 100, 100, 100, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_STEEL, TYPE_PSYCHIC, //types
        3, //catch rate
        215, //exp yield
        {3, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_STERNENSTUECK, ITEM_STERNENSTUECK, //common, rare item
        255, //gender
        120, //egg cycles
        100, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        EDELMUT, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_DEOXYS
    {
        50, 150, 50, 150, 150, 50, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        3, //catch rate
        215, //exp yield
        {0, 1, 0, 1, 1, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        ERZWINGER, ABILITY_NONE, //abilities
        0, //safari rate
        2, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_HUMANOID, //form
    },

    //POKEMON_PALIMPALIM
    {
        65, 50, 70, 65, 95, 80, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_PSYCHIC, TYPE_PSYCHIC, //types
        45, //catch rate
        147, //exp yield
        {0, 0, 0, 0, 1, 1, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        127, //gender
        25, //egg cycles
        70, //base friendship
        4, //lvl up curve
        EGG_GROUP_AMORPHUS, EGG_GROUP_AMORPHUS, //egg groups
        SCHWEBE, ABILITY_NONE, //abilities
        0, //safari rate
        1, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_ARMS, //form
    },

    //POKEMON_EGG
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_B
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_C
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_D
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_E
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_F
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_G
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_H
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_I
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_J
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_K
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_L
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_M
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_N
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_O
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_P
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_Q
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_R
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_S
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_T
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_U
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_V
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_W
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_X
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_Y
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_Z
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_EXCLAMATION
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },

    //POKEMON_ICOGNITO_QUESTION
    {
        0, 0, 0, 0, 0, 0, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_NORMAL, TYPE_NORMAL, //types
        0, //catch rate
        0, //exp yield
        {0, 0, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        0, //gender
        0, //egg cycles
        0, //base friendship
        0, //lvl up curve
        EGG_GROUP_WATER_1, EGG_GROUP_WATER_1, //egg groups
        ABILITY_NONE, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        0, //form
    },
    //POKEMON_GROUDON_REGENT
    {
        100, 195, 150, 95, 125, 105, //basestat values (hp, att, def, spe, satk, sdef)
        TYPE_GROUND, TYPE_FIRE, //types
        5, //catch rate
        255, //exp yield
        {0, 3, 0, 0, 0, 0, 0}, //ev yield (hp, atk, def, spe, satk, sdef)
        ITEM_NONE, ITEM_NONE, //common, rare item
        255, //gender
        120, //egg cycles
        0, //base friendship
        5, //lvl up curve
        EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED, //egg groups
        R_KAISERAURA, ABILITY_NONE, //abilities
        0, //safari rate
        0, //flip and color
        ABILITY_NONE, //hidden ability
        SHAPE_TAIL, //form
    }


};