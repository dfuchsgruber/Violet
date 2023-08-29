#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon/dungeon2.h"
#include "dungeon/callback.h"
#include "dungeon/cave.h"
#include "debug.h"
#include "constants/map_weathers.h"
#include "map/footer.h"
#include "agbmemory.h"
#include "prng.h"
#include "vars.h"
#include "bios.h"
#include "transparency.h"
#include "overworld/map_control.h"
#include "berry.h"
#include "constants/vars.h"
#include "vars.h"
#include "pokemon/basestat.h"
#include "constants/person_behaviours.h"
#include "tile/block.h"
#include "constants/map_types.h"
#include "overworld/sprite.h"
#include "dungeon/cave.h"
#include "flags.h"
#include "constants/person_script_stds.h"
#include "constants/map_weathers.h"
#include "constants/wild_pokemon_densities.h"
#include "callbacks.h"
#include "overworld/script.h"

extern map_footer_t map_footer_dungeon_cave_normal;
extern map_footer_t map_footer_dungeon_cave_tent_and_campfire;
extern map_footer_t map_footer_dungeon_ice_cave;
extern map_footer_t map_footer_dungeon_sand_cave;
extern map_footer_t map_footer_dungeon_dragon_cave;
extern map_footer_t map_footer_dungeon_steel_cave;
extern map_footer_t map_footer_dungeon_fossil_cave;

u16 dungeon2_cave_borders[4] = {0x281, 0x281, 0x281, 0x281};

map_block dungeon2_cave_map_empty[DG2_CAVE_WIDTH * DG2_CAVE_HEIGHT] = {0};

extern u8 ow_script_dungeon_encounter[];
extern u8 ow_script_dungeon_item[];

static u32 dungeon2_cave_type_rates[NUM_DUNGEON_CAVE_TYPES] = {
    [DUNGEON_CAVE_TYPE_NORMAL] = 6,
    [DUNGEON_CAVE_TYPE_TENT] = 1,
    [DUNGEON_CAVE_TYPE_ICE] = 2,
    [DUNGEON_CAVE_TYPE_SAND] = 1,
    [DUNGEON_CAVE_TYPE_DRAGON] = 1,
    [DUNGEON_CAVE_TYPE_STEEL] = 4,
    [DUNGEON_CAVE_TYPE_FOSSIL] = 1,
};

u8 dungeon2_get_cave_type(dungeon_generator2 *dg2) {
    gp_rng_seed(dungeon2_seeded_rnd16(dg2, DG2_RANDOM_SEED_DUNGEON_TYPE));
    return (u8)choice(dungeon2_cave_type_rates, NUM_DUNGEON_CAVE_TYPES, gp_rnd16);
}

static map_footer_t *dungeon2_get_cave_type_pattern(dungeon_generator2 *dg2) {
    return dungeon_cave_types[dungeon2_get_cave_type(dg2)].footer;
}

static int dungeon2_get_cave_num_patterns(dungeon_generator2 *dg2) {
    dungeon_cave_t *type = dungeon_cave_types + dungeon2_get_cave_type(dg2);
    gp_rng_seed(dungeon2_seeded_rnd16(dg2, DG2_RANDOM_SEED_NUM_PATTERNS));
    return MIN(DG2_MAX_NUM_PATTERNS, type->min_num_patterns + (gp_rnd16() % (type->max_num_patterns - type->min_num_patterns + 1)));
}

map_footer_t *dungeon2_init_footer_cave(dungeon_generator2 *dg2){
    map_footer_t *footer = dungeon2_get_cave_type_pattern(dg2);
    fmem.dmapfooter.width = (u32)dg2->width;
    fmem.dmapfooter.height = (u32)dg2->height;
    fmem.dmapfooter.tileset1 = footer->tileset1;
    fmem.dmapfooter.tileset2 = footer->tileset2;
    fmem.dmapfooter.border_blocks = footer->border_blocks;
    fmem.dmapfooter.border_width = footer->border_width;
    fmem.dmapfooter.border_height = footer->border_height;
    fmem.dmapfooter.map = dungeon2_cave_map_empty;
    return &(fmem.dmapfooter);
}

static void dungeon_cave_tent_initialize_events(dungeon_generator2 *dg2) {
    u8 num_warps = fmem.dmapevents.warp_cnt;
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_cave_num_patterns(dg2);
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns) && num_warps <= ARRAY_COUNT(fmem.dwarps); j++) {
        fmem.dwarps[num_warps].x = (s16)(nodes[DG2_NODE_PATTERN + j][0]);
        fmem.dwarps[num_warps].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] + 1);
        fmem.dwarps[num_warps].target_warp_id = 0;
        fmem.dwarps[num_warps].target_map = DG2_CAVE_TENT_MAP;
        fmem.dwarps[num_warps].target_bank = DG2_BANK;
        num_warps++;
    }
    fmem.dmapevents.warp_cnt = num_warps;
}

static void dungeon_ice_cave_initialize_events(dungeon_generator2 *dg2) {
    (void)dg2;
}

static void dungeon_sand_cave_initialize_events(dungeon_generator2 *dg2) {
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_cave_num_patterns(dg2);
    u8 num_persons = fmem.dmapevents.person_cnt;
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns) && num_persons <= ARRAY_COUNT(fmem.dpersons); j++) {
        fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0]);
        fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1]);
        fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
        fmem.dpersons[num_persons].overworld_index = 101;
        fmem.dpersons[num_persons].script_std = PERSON_EGG;
        fmem.dpersons[num_persons].value = POKEMON_LARVITAR;
        fmem.dpersons[num_persons].flag = (u16)(FLAG_DUNGEON_GP + j);
        num_persons++;
    }
    fmem.dmapevents.person_cnt = num_persons;
}

static void dungeon_dragon_cave_initialize_events(dungeon_generator2 *dg2) {
    u8 num_warps = fmem.dmapevents.warp_cnt;
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_cave_num_patterns(dg2);
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns) && num_warps <= ARRAY_COUNT(fmem.dwarps); j++) {
        fmem.dwarps[num_warps].x = (s16)(nodes[DG2_NODE_PATTERN + j][0]);
        fmem.dwarps[num_warps].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] + 3);
        fmem.dwarps[num_warps].target_warp_id = 0;
        fmem.dwarps[num_warps].target_map = DG2_CAVE_DRAGON_CAVE_MAP;
        fmem.dwarps[num_warps].target_bank = DG2_BANK;
        num_warps++;
    }
    fmem.dmapevents.warp_cnt = num_warps;
}

u16 dungeon_steel_cave_special_items[] = {
    ITEM_METALLMANTEL, ITEM_NUGGET, ITEM_TOP_BELEBER,
};

static s16 dungeon_steel_cave_special_item_positions[3][2] = {
    {-1, 1}, {1, 1}, {1, -1}
};

static void dungeon_steel_cave_initialize_events(dungeon_generator2 *dg2) {
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_cave_num_patterns(dg2);
    u8 num_persons = fmem.dmapevents.person_cnt;
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns) && num_persons <= ARRAY_COUNT(fmem.dpersons); j++) {
        int pos_idx = dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon_steel_cave_special_item_positions);
        fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0] + dungeon_steel_cave_special_item_positions[pos_idx][0]);
        fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] + dungeon_steel_cave_special_item_positions[pos_idx][1]);
        fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
        fmem.dpersons[num_persons].overworld_index = 92;
        fmem.dpersons[num_persons].script_std = PERSON_ITEM;
        fmem.dpersons[num_persons].value = dungeon_steel_cave_special_items[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon_steel_cave_special_items)];
        fmem.dpersons[num_persons].flag = (u16)(FLAG_DUNGEON_GP + j);
        num_persons++;
    }
    fmem.dmapevents.person_cnt = num_persons;
}

u16 dungeon_fossil_cave_fossils[] = {
    ITEM_DOMFOSSIL, ITEM_HELIXFOSSIL, ITEM_WURZELFOSSIL, ITEM_KLAUENFOSSIL,
};

static void dungeon_fossil_cave_initialize_events(dungeon_generator2 *dg2) {
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_cave_num_patterns(dg2);
    u8 num_persons = fmem.dmapevents.person_cnt;
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns) && num_persons <= ARRAY_COUNT(fmem.dpersons); j++) {
        fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0] + 0);
        fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] - 3);
        fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
        fmem.dpersons[num_persons].overworld_index = 98;
        fmem.dpersons[num_persons].script_std = PERSON_ITEM;
        fmem.dpersons[num_persons].value = dungeon_fossil_cave_fossils[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon_fossil_cave_fossils)];
        fmem.dpersons[num_persons].flag = (u16)(FLAG_DUNGEON_GP + j);
        num_persons++;
    }
    fmem.dmapevents.person_cnt = num_persons;
}

static void dungeon_pattern_fill_none(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2) {
    (void)map; (void)x; (void)y; (void)w; (void)h; (void)dg2;
}

static void dungeon_pattern_fill_with_1x1_border_without_corners(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2) {
    dungeon2_fill_rectangle(map, x, y, w, h, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x - 1, y, 1, h, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x + w, y, 1, h, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x, y - 1, w, 1, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x, y + h, w, 1, DG2_SPACE, dg2);
}

static void dungeon_pattern_fill_with_1x1_border_without_corners_walls(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2) {
    dungeon2_fill_rectangle(map, x, y, w, h, DG2_WALL, dg2);
    dungeon2_fill_rectangle(map, x - 1, y, 1, h, DG2_WALL, dg2);
    dungeon2_fill_rectangle(map, x + w, y, 1, h, DG2_WALL, dg2);
    dungeon2_fill_rectangle(map, x, y - 1, w, 1, DG2_WALL, dg2);
    dungeon2_fill_rectangle(map, x, y + h, w, 1, DG2_WALL, dg2);
}

static void dungeon_cave_normal_initialize_events(dungeon_generator2 *dg2) {
    (void)dg2;
}

dungeon_cave_t dungeon_cave_types[NUM_DUNGEON_CAVE_TYPES] = {
    [DUNGEON_CAVE_TYPE_NORMAL] = {
        .footer = &map_footer_dungeon_cave_normal,
        .min_num_patterns = 0,
        .max_num_patterns = 0,
        .deco_rate = 0,
        .event_init = dungeon_cave_normal_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_none,
        .fill_pattern_in_over = dungeon_pattern_fill_none,
        .map_weather = MAP_WEATHER_CLOUDY,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_PARA_HEILER, ITEM_GEGENGIFT, ITEM_AUFWECKER, ITEM_AETHER,
        },
        .items_rare = {
            ITEM_STERNENSTAUB, ITEM_TOP_SCHUTZ, ITEM_AP_PLUS, ITEM_ELIXIER,
        },
        .species_common = {
            POKEMON_ZUBAT, POKEMON_KLEINSTEIN, POKEMON_PUMMELUFF, POKEMON_BRONZEL,
            POKEMON_MACHOLLO, POKEMON_ONIX, POKEMON_NASGNET, POKEMON_ABRA,
        },
        .species_rare = {
            POKEMON_GOLBAT, POKEMON_GEOROK, POKEMON_MASCHOCK, POKEMON_KADABRA,
        },
        .species_static_encounter = {
            POKEMON_GEOWAZ, POKEMON_BRONZONG, POKEMON_KNUDDELUFF, POKEMON_VOLUMINAS,
        },
    },
    [DUNGEON_CAVE_TYPE_TENT] = {
        .footer = &map_footer_dungeon_cave_tent_and_campfire,
        .min_num_patterns = 1,
        .max_num_patterns = 1,
        .deco_rate = 0,
        .event_init = dungeon_cave_tent_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_with_1x1_border_without_corners,
        .fill_pattern_in_over = dungeon_pattern_fill_with_1x1_border_without_corners_walls,
        .map_weather = MAP_WEATHER_CLOUDY,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_PARA_HEILER, ITEM_GEGENGIFT, ITEM_AUFWECKER, ITEM_AETHER,
        },
        .items_rare = {
            ITEM_STERNENSTUECK, ITEM_BELEBER, ITEM_AP_PLUS, ITEM_ELIXIER,
        },
        .species_common = {
            POKEMON_ZUBAT, POKEMON_KLEINSTEIN, POKEMON_RIOLU, POKEMON_BRONZEL,
            POKEMON_MACHOLLO, POKEMON_ONIX, POKEMON_NASGNET, POKEMON_ABRA,
        },
        .species_rare = {
            POKEMON_GOLBAT, POKEMON_GEOROK, POKEMON_MASCHOCK, POKEMON_KADABRA,
        },
        .species_static_encounter = {
            POKEMON_GEOWAZ, POKEMON_BRONZONG, POKEMON_ZOBIRIS, POKEMON_VOLUMINAS,
        },
    },
    [DUNGEON_CAVE_TYPE_ICE] = {
        .footer = &map_footer_dungeon_ice_cave,
        .min_num_patterns = 1,
        .max_num_patterns = 3,
        .deco_rate = 0,
        .event_init = dungeon_ice_cave_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_with_1x1_border_without_corners,
        .fill_pattern_in_over = dungeon_pattern_fill_with_1x1_border_without_corners_walls,
        .map_weather = MAP_WEATHER_COLD_BLUE,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_INDIGOSTUECK, ITEM_EISHEILER, ITEM_INDIGOSTUECK, ITEM_AETHER,
        },
        .items_rare = {
            ITEM_EWIGES_EIS, ITEM_BELEBER, ITEM_EISJUWEL, ITEM_ELIXIER,
        },
        .species_common = {
            POKEMON_ZUBAT, POKEMON_QUIEKEL, POKEMON_SCHNEPPKE, POKEMON_SCHNEPPKE,
            POKEMON_MACHOLLO, POKEMON_ONIX, POKEMON_MARILL, POKEMON_ZUBAT,
        },
        .species_rare = {
            POKEMON_GOLBAT, POKEMON_FIRNONTOR, POKEMON_KEIFEL, POKEMON_GOLBAT,
        },
        .species_static_encounter = {
            POKEMON_CRYSTAL_ONIX, POKEMON_CRYSTAL_ONIX, POKEMON_CRYSTAL_ONIX, POKEMON_CRYSTAL_ONIX,
        },
    },
    [DUNGEON_CAVE_TYPE_SAND] = {
        .footer = &map_footer_dungeon_sand_cave,
        .min_num_patterns = 1,
        .max_num_patterns = 1,
        .deco_rate = 0,
        .event_init = dungeon_sand_cave_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_with_1x1_border_without_corners,
        .fill_pattern_in_over = dungeon_pattern_fill_with_1x1_border_without_corners_walls,
        .map_weather = MAP_WEATHER_INSIDE,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_GELBSTUECK, ITEM_PURPURSTUECK, ITEM_SOLARSTUECK, ITEM_LUNARSTUECK,
        },
        .items_rare = {
            ITEM_PUDERSAND, ITEM_BELEBER, ITEM_BODENJUWEL, ITEM_ELIXIER,
        },
        .species_common = {
            POKEMON_ZUBAT, POKEMON_SANDAN, POKEMON_DIGDA, POKEMON_PUPPANCE,
            POKEMON_MACHOLLO, POKEMON_ONIX, POKEMON_NASGNET, POKEMON_ZUBAT,
        },
        .species_rare = {
            POKEMON_GOLBAT, POKEMON_MASCHOCK, POKEMON_SKORGLA, POKEMON_SANDAMER,
        },
        .species_static_encounter = {
            POKEMON_SANDAMER, POKEMON_DIGDRI, POKEMON_LEPUMENTAS, POKEMON_SKORGRO,
        },
    },
    [DUNGEON_CAVE_TYPE_DRAGON] = {
        .footer = &map_footer_dungeon_dragon_cave,
        .min_num_patterns = 1,
        .max_num_patterns = 1,
        .deco_rate = 0,
        .event_init = dungeon_dragon_cave_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_with_1x1_border_without_corners,
        .fill_pattern_in_over = dungeon_pattern_fill_with_1x1_border_without_corners_walls,
        .map_weather = MAP_WEATHER_INSIDE,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_X_ANGRIFF, ITEM_FEUERHEILER, ITEM_PARA_HEILER, ITEM_X_SPEZIAL,
        },
        .items_rare = {
            ITEM_DRACHENHAUT, ITEM_DRACHENZAHN, ITEM_SCHARFZAHN, ITEM_DRACOJUWEL,
        },
        .species_common = {
            POKEMON_KLEINSTEIN, POKEMON_ONIX, POKEMON_PUPPANCE, POKEMON_KNACKLION,
            POKEMON_KLEINSTEIN, POKEMON_ONIX, POKEMON_ZUBAT, POKEMON_ZUBAT,
        },
        .species_rare = {
            POKEMON_GOLBAT, POKEMON_GEOROK, POKEMON_ONIX, POKEMON_GEOROK,
        },
        .species_static_encounter = {
            POKEMON_VIBRAVA, POKEMON_LEPUMENTAS, POKEMON_VIBRAVA, POKEMON_LEPUMENTAS,
        },
    },
    [DUNGEON_CAVE_TYPE_STEEL] = {
        .footer = &map_footer_dungeon_steel_cave,
        .min_num_patterns = 1,
        .max_num_patterns = 3,
        .deco_rate = 0,
        .event_init = dungeon_steel_cave_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_with_1x1_border_without_corners,
        .fill_pattern_in_over = dungeon_pattern_fill_with_1x1_border_without_corners_walls,
        .map_weather = MAP_WEATHER_INSIDE,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_X_ABWEHR, ITEM_STERNENSTAUB, ITEM_LUNARSTUECK, ITEM_SOLARSTUECK,
        },
        .items_rare = {
            ITEM_METALLMANTEL, ITEM_UNLICHTJUWEL, ITEM_STAHLJUWEL, ITEM_BELEBER,
        },
        .species_common = {
            POKEMON_KLEINSTEIN, POKEMON_STOLLUNIOR, POKEMON_BRONZEL, POKEMON_ZUBAT,
            POKEMON_STOLLUNIOR, POKEMON_ONIX, POKEMON_BRONZEL, POKEMON_STOLLUNIOR,
        },
        .species_rare = {
            POKEMON_STOLLRAK, POKEMON_GEOROK, POKEMON_GOLBAT, POKEMON_BRONZONG,
        },
        .species_static_encounter = {
            POKEMON_STOLLOSS, POKEMON_SONNFEL, POKEMON_STAHLOS, POKEMON_LUNASTEIN,
        },
    },
    [DUNGEON_CAVE_TYPE_FOSSIL] = {
        .footer = &map_footer_dungeon_fossil_cave,
        .min_num_patterns = 1,
        .max_num_patterns = 1,
        .deco_rate = 0,
        .event_init = dungeon_fossil_cave_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_with_1x1_border_without_corners,
        .fill_pattern_in_over = dungeon_pattern_fill_with_1x1_border_without_corners_walls,
        .map_weather = MAP_WEATHER_INSIDE,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_X_TREFFER, ITEM_STERNENSTAUB, ITEM_GLITZERSTUECK, ITEM_LUNARSTUECK,
        },
        .items_rare = {
            ITEM_ELIXIER, ITEM_EWIGSTEIN, ITEM_STERNENSTUECK, ITEM_BELEBER,
        },
        .species_common = {
            POKEMON_KLEINSTEIN, POKEMON_ABRA, POKEMON_MEDITIE, POKEMON_ZUBAT,
            POKEMON_NASGNET, POKEMON_PUMMELUFF, POKEMON_BRONZEL, POKEMON_MACHOLLO,
        },
        .species_rare = {
            POKEMON_KADABRA, POKEMON_GEOROK, POKEMON_GOLBAT, POKEMON_BRONZONG,
        },
        .species_static_encounter = {
            POKEMON_MEDITALIS, POKEMON_VOLUMINAS, POKEMON_BRONZONG, POKEMON_KNUDDELUFF,
        },
    },
};

u16 dungeon_cave_pick_item(dungeon_generator2 *dg2) {
    u16 item;
    if ((dungeon2_rnd_16(dg2) % 10) < 3) {
        item = dungeon_cave_types[dungeon2_get_cave_type(dg2)].items_rare[dungeon2_rnd_16(dg2) % DUNGEON_CAVE_NUM_ITEMS_RARE];
    } else {
        item = dungeon_cave_types[dungeon2_get_cave_type(dg2)].items_common[dungeon2_rnd_16(dg2) % DUNGEON_CAVE_NUM_ITEMS_COMMON];
    }
    return item;
}

void dungeon2_init_wild_pokemon_cave(dungeon_generator2 *dg2) {

    dungeon_cave_t *cave_type = dungeon_cave_types + dungeon2_get_cave_type(dg2);

    u16 common_pokemon[4];
    u16 rare_pokemon[2];
    u16 super_rare_pokemon[1];

    dungeon2_pick_wild_pokemon(common_pokemon, ARRAY_COUNT(common_pokemon), cave_type->species_common, DUNGEON_CAVE_NUM_POKEMON_COMMON, dg2);
    dungeon2_pick_wild_pokemon(rare_pokemon, ARRAY_COUNT(rare_pokemon), cave_type->species_rare, DUNGEON_CAVE_NUM_POKEMON_RARE, dg2);
    dungeon2_pick_wild_pokemon(super_rare_pokemon, ARRAY_COUNT(super_rare_pokemon), cave_type->species_static_encounter, DUNGEON_CAVE_NUM_POKEMON_STATIC, dg2);

    *var_access(DUNGEON_OVERWORLD_SPECIES) = super_rare_pokemon[0];

    fmem.dwild_pokemon.grass = &(fmem.dwild_habitat_grass);
    fmem.dwild_pokemon.water = NULL;
    fmem.dwild_pokemon.other = NULL;
    fmem.dwild_pokemon.rod = NULL;
    fmem.dwild_habitat_grass.frequency = DUNGEON_TYPE_CAVE_WILD_POKEMON_FREQUENCY;
    fmem.dwild_habitat_grass.data = fmem.dwild_data_grass;

    // Each of the common pokemon has a 20% probability
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT].species = common_pokemon[0];
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT].species = common_pokemon[1];
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT].species = common_pokemon[2];
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT].species = common_pokemon[2];
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT].species = common_pokemon[3];
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT].species = common_pokemon[3];

    // The first rare pokemon has a 14% probability
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT].species = rare_pokemon[0];
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT].species = rare_pokemon[0];
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT].species = rare_pokemon[0];

    // The other rare pokemon has a 6% probability
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT].species = rare_pokemon[1];
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT].species = rare_pokemon[1];
    fmem.dwild_data_grass[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT].species = rare_pokemon[1];

    u8 mean = 0;
    u8 std_deviation = 0;
    u8 level_min = 0;
    u8 level_max = 0;
    dungeon2_get_wild_pokemon_level_distribution(&mean, &std_deviation);

    for(int i = 0; i < 12; i++) {
        dungeon2_wild_pokemon_sample_level_boundaries(&level_min, &level_max,
            (i < 6) ? mean : (u8)(mean + std_deviation), std_deviation, dg2);
        fmem.dwild_data_grass[i].level_min = level_min;
        fmem.dwild_data_grass[i].level_max = level_max;
    }
}

void dungeon2_set_encounter_cave() {
  dungeon_generator2 *dg2 = &(cmem.dg2);
  dungeon2_cave_initialize_state(dg2);
  pokemon_clear_opponent_party();

  u16 species = *var_access(DUNGEON_OVERWORLD_SPECIES);
  u8 mean = 0, std_deviation = 0;
  dungeon2_get_wild_pokemon_level_distribution(&mean, &std_deviation);
  mean = (u8)(mean + std_deviation + std_deviation / 2); // High level for this pokemon

  int level = FIXED_TO_INT(FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(INT_TO_FIXED(std_deviation),
        dungeon2_rnd_normal(dg2))));
  level = MAX(MIN(level, 100), 2);

  pid_t p = {dungeon2_rnd(dg2)};

  pokemon_spawn_by_seed_algorithm(&opponent_pokemon[0], species, (u8)level, 32, true, p, false, 0,
      dungeon2_encounter_rnd_generator, dungeon2_encounter_rnd_generator);
}

map_header_t *dungeon2_init_header_cave(dungeon_generator2 *dg2) {
    DEBUG("D2 header init\n");
    fmem.dmap_header_initialized = 1;
    fmem.dmapheader.levelscripts = dungeon2_lscr;
    fmem.dmapheader.connections = &dungeon2_connections;
    fmem.dmapheader.music = 0x14b;
    fmem.dmapheader.map_namespace = mapheader_virtual.map_namespace;
    fmem.dmapheader.flash_type = 0;
    fmem.dmapheader.weather = dungeon_cave_types[dungeon2_get_cave_type(dg2)].map_weather;
    fmem.dmapheader.type = MAP_TYPE_BASEMENT;
    fmem.dmapheader.show_name = 0;
    fmem.dmapheader.battle_style = 0;
    fmem.dmapheader.events = dungeon2_init_events_cave(dg2);
    fmem.dmapheader.footer = dungeon2_init_footer_cave(dg2);
    fmem.dmapheader.footer_idx = DG2_FOOTER_IDX;
    return &(fmem.dmapheader);
}

map_event_header_t *dungeon2_init_events_cave(dungeon_generator2 *dg2){
    dungeon2_initialize_std_events(dg2, dungeon_cave_pick_item);
    dungeon_cave_types[dungeon2_get_cave_type(dg2)].event_init(dg2);
    return &(fmem.dmapevents);
}

static void dungeon2_compute_blocks_cave(u8 *map, u8 *over, dungeon_generator2 *dg2){
    int (*nodes)[2] = save1->dungeon_nodes;
    dungeon_cave_t *cave_type = dungeon_cave_types + dungeon2_get_cave_type(dg2);
    map_footer_t *pattern = dungeon2_get_cave_type_pattern(dg2);
    int num_patterns = dungeon2_get_cave_num_patterns(dg2);

    // Fill map to fit the pattern
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns); j++) {
        int w = (int)pattern->width;
        int h = (int)pattern->height;
        int x = nodes[DG2_NODE_PATTERN + j][0] - (w / 2);
        int y = nodes[DG2_NODE_PATTERN + j][1] - (h / 2);
        cave_type->fill_pattern_in_map(map, x, y, w, h, dg2);
        cave_type->fill_pattern_in_over(over, x, y, w, h, dg2);
    }
    // Compute the actual blocks
    dungeon2_set_blocks_cave(map, over, dg2);
    if (pattern) {
        for (int i = 0; i < MIN(num_patterns, DG2_MAX_NUM_PATTERNS); i++) {
            dungeon2_place_pattern(nodes[DG2_NODE_PATTERN + i][0], nodes[DG2_NODE_PATTERN + i][1], pattern, dg2);
        } 
    }
}

void dungeon2_cave_initialize_state(dungeon_generator2 *dg2) {
  dg2->seed = dg2->initial_seed;
  dg2->width = DG2_CAVE_WIDTH;
  dg2->height = DG2_CAVE_HEIGHT;
  dg2->path_randomness = DG2_CAVE_PATH_RANDOMNESS;
  dg2->init_randomness = DG2_CAVE_INIT_RANDOMNESS;
  dg2->nodes = DG2_CAVE_NODES;
  dg2->margin = DG2_CAVE_MARGIN;
  dg2->node_metric_lambda_l2 = DG2_CAVE_NODE_METRIC_LAMBDA_MEAN;
  dg2->node_metric_lambda_min = DG2_CAVE_NODE_METRIC_LAMBDA_MIN;
  dg2->node_samples = DG2_CAVE_NODE_SAMPLES;
  map_footer_t *pattern = dungeon2_get_cave_type_pattern(dg2);
  dg2->pattern_margin = (u8)(((MAX(pattern->width, pattern->height) + 1) / 2) & 0xF);
}

void dungeon2_initialize_cave(){
    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_cave_initialize_state(dg2);
    dungeon2_init_wild_pokemon_cave(dg2); // Initialize before events since persons depend
    dungeon2_init_header_cave(dg2);
    fmem.dmap_header_initialized = 1;
}

void dungeon2_compute_layout_cave_callback(u8 self) {
    dungeon_generator2 *dg2 = (dungeon_generator2*) big_callback_get_int(self, 2);
    u8 *map = (u8*)big_callback_get_int(self, 4);
    u8 *over = (u8*)big_callback_get_int(self, 8);
    u16 *vars = big_callbacks[self].params;
    // DEBUG("cave callback superstate %d\n", vars[0]);
    switch (vars[0]) {
        case 0: {
            big_callback_set_int(self, 4, (int)malloc(sizeof(u8) * (size_t)dg2->width * (size_t)dg2->height));
            big_callback_set_int(self, 8, (int)malloc(sizeof(u8) * (size_t)dg2->width * (size_t)dg2->height));
            vars[0]++;
            FALL_THROUGH;
        }
        case 1: { // Sample nodes
            int (*nodes_tmp)[2] = malloc(sizeof(save1->dungeon_nodes));
            big_callback_set_int(self, 6, (int)nodes_tmp);
            vars[1] = dungeon2_get_nodes_with_callback(nodes_tmp, dg2->nodes, dg2);
            vars[0]++;
            break;
        }
        case 2: {
            if (dungeon2_get_nodes_with_callback_finished((u8)vars[1])) {
                int (*nodes_tmp)[2] = (int (*)[2])big_callback_get_int(self, 6);
                memcpy(save1->dungeon_nodes, nodes_tmp, sizeof(save1->dungeon_nodes));
                free(nodes_tmp);
                vars[0]++;
            }
            break;
        }
        case 3: {
            vars[1] = dungeon2_create_connected_layout_with_callback(dg2, save1->dungeon_nodes, map, 0);
            vars[0]++;
            break;
        }
        case 4: {
            if (dungeon2_create_connected_layout_with_callback_finished((u8)vars[1]))
                vars[0]++;
            break;
        }
        case 5: { // Sample nodes for over layout
            dg2->nodes = (u8)(dg2->nodes * 3); // More nodes for the over layout
            int (*nodes_tmp)[2] = malloc(2 * sizeof(int) * dg2->nodes);
            big_callback_set_int(self, 6, (int)nodes_tmp);
            vars[1] = dungeon2_get_nodes_with_callback(nodes_tmp, dg2->nodes, dg2);
            vars[0]++;
            break;
        }
        case 6: {
            if (dungeon2_get_nodes_with_callback_finished((u8)vars[1])) {
                vars[0]++;
            }
            break;
        }
        case 7: {
            int (*nodes_tmp)[2] = (int (*)[2])big_callback_get_int(self, 6);
            int num_patterns = dungeon2_get_cave_num_patterns(dg2);
            int excluded_nodes_mask = 0;
            for (int i = DG2_NODE_PATTERN; i < DG2_NODE_PATTERN + num_patterns; i++)
                excluded_nodes_mask |= 1 << i;
            vars[1] = dungeon2_create_connected_layout_with_callback(dg2, nodes_tmp, over, excluded_nodes_mask);
            vars[0]++;
            break;
        }
        case 8: {
            if (dungeon2_create_connected_layout_with_callback_finished((u8)vars[1]))
                vars[0]++;
            break;
        }
        case 9: {
            dg2->nodes = (u8)(dg2->nodes / 3);
            dungeon2_compute_blocks_cave(map, over, dg2);
            int (*nodes_tmp)[2] = (int (*)[2])big_callback_get_int(self, 6);
            free(nodes_tmp);
            free(map);
            free(over);
            big_callback_delete(self);
        }
    }
}


void dungeon2_compute_layout_cave() {
    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_cave_initialize_state(dg2);
    u8 cb_idx = big_callback_new(dungeon2_compute_layout_cave_callback, 0);
    big_callback_set_int(cb_idx, 2, (int)dg2);
    big_callbacks[cb_idx].params[0] = 0;
}

void dungeon2_compute_layout_cave_continue_overworld_script_if_finished_callback(u8 self) {
    if (!big_callback_is_active(dungeon2_compute_layout_cave_callback)) {
        overworld_script_resume();
        big_callback_delete(self);
    }
}
void dungeon2_compute_layout_cave_continue_overworld_script_if_finished() {
    big_callback_new(dungeon2_compute_layout_cave_continue_overworld_script_if_finished_callback, 1);
}

void dungeon2_enter_cave() {

    *var_access(DUNGEON_TYPE) = DUNGEON_TYPE_CAVE;
    *var_access(DUNGEON_STEPS) = 0;
    dungeon2_reset_flags();

    // Get the warp node (first node in the cave)
    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_cave_initialize_state(dg2);
    int (*nodes)[2] = save1->dungeon_nodes;
    s16 x = (s16)(nodes[0][0]);
    s16 y = (s16)(nodes[0][1]); 

    warp_setup(DG2_BANK, DG2_MAP, 0xFF, x, y);
    warp_update_last_outdoor_map(save1->x_cam_orig, save1->y_cam_orig);
    warp_last_map_set(0, save1->bank, save1->map, 0xFF, (s16)(save1->x_cam_orig - 7),
            (s16)(save1->y_cam_orig - 7));
    warp_setup_callbacks();
    warp_reset_initial_player_state();

    // Setup warpback
    player_get_coordinates(&(dg2->previous_position.x), &(dg2->previous_position.y));
    dg2->previous_position.x = (s16)(dg2->previous_position.x - 7);
    dg2->previous_position.y = (s16)(dg2->previous_position.y - 7);
    dg2->previous_bank = save1->bank;
    dg2->previous_map = save1->map;
    DEBUG("Saved player @ (%d, %d) on %d.%d\n", dg2->previous_position.x, dg2->previous_position.y,
        dg2->previous_bank, dg2->previous_map);
}
