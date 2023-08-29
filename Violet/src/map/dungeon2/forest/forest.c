#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon/dungeon2.h"
#include "dungeon/callback.h"
#include "dungeon/forest.h"
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
#include "dungeon/forest.h"
#include "flags.h"
#include "constants/person_script_stds.h"
#include "constants/map_weathers.h"
#include "constants/wild_pokemon_densities.h"
#include "callbacks.h"
#include "overworld/script.h"

extern map_footer_t map_footer_dungeon_forest_normal;
extern map_footer_t map_footer_dungeon_forest_apple_tree;
extern map_footer_t map_footer_dungeon_forest_berry_spot;
extern map_footer_t map_footer_dungeon_forest_nest;
extern map_footer_t map_footer_dungeon_forest_mushrooms;
extern map_footer_t map_footer_dungeon_forest_dusk;
extern map_footer_t map_footer_dungeon_forest_tent_and_campfire;

u16 dungeon2_forest_borders[4] = {0x26, 0x27, 0x2c, 0x2d};

map_block dungeon2_forest_map_empty[DG2_FOREST_WIDTH * DG2_FOREST_HEIGHT] = {0};

extern u8 ow_script_dungeon_encounter[];
extern u8 ow_script_dungeon_item[];

static u32 dungeon2_forest_type_rates[NUM_DUNGEON_FOREST_TYPES] = {
    [DUNGEON_FOREST_TYPE_NORMAL] = 3,
    [DUNGEON_FOREST_TYPE_APPLE_FOREST] = 2,
    [DUNGEON_FOREST_TYPE_BERRY_FOREST] = 2,
    [DUNGEON_FOREST_TYPE_EGG_FOREST] = 2,
    [DUNGEON_FOREST_TYPE_MUSHROOM_FOREST] = 3,
    [DUNGEON_FOREST_TYPE_DUSK_FOREST] = 1,
    [DUNGEON_FOREST_TYPE_TENT_FOREST] = 2,
};

u8 dungeon2_get_forest_type(dungeon_generator2 *dg2) {
    gp_rng_seed(dungeon2_seeded_rnd16(dg2, DG2_RANDOM_SEED_DUNGEON_TYPE));
    return (u8)choice(dungeon2_forest_type_rates, NUM_DUNGEON_FOREST_TYPES, gp_rnd16);
}

static map_footer_t *dungeon2_get_forest_type_pattern(dungeon_generator2 *dg2) {
    return dungeon_forest_types[dungeon2_get_forest_type(dg2)].footer;
}

static int dungeon2_get_forest_num_patterns(dungeon_generator2 *dg2) {
    dungeon_forest_t *type = dungeon_forest_types + dungeon2_get_forest_type(dg2);
    gp_rng_seed(dungeon2_seeded_rnd16(dg2, DG2_RANDOM_SEED_NUM_PATTERNS));
    return MIN(DG2_MAX_NUM_PATTERNS, type->min_num_patterns + (gp_rnd16() % (type->max_num_patterns - type->min_num_patterns + 1)));
}

map_footer_t *dungeon2_init_footer_forest(dungeon_generator2 *dg2){
    map_footer_t *footer = dungeon2_get_forest_type_pattern(dg2);
    fmem.dmapfooter.width = (u32)dg2->width;
    fmem.dmapfooter.height = (u32)dg2->height;
    fmem.dmapfooter.tileset1 = footer->tileset1;
    fmem.dmapfooter.tileset2 = footer->tileset2;
    fmem.dmapfooter.border_blocks = footer->border_blocks;
    fmem.dmapfooter.border_width = footer->border_width;
    fmem.dmapfooter.border_height = footer->border_height;
    fmem.dmapfooter.map = dungeon2_forest_map_empty;
    return &(fmem.dmapfooter);
}

static s16 dungeon_forest_apple_displacements[][2] = {
    {-1, 0}, {-1, 1}, {1, 0}, {1, 1}
};

u32 dungeon_forest_berries[] = {
    [ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PIRSIFBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MARONBEERE)] = 4,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_FRAGIABEERE)] = 4,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WILBIRBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SINELBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TSITRUBEERE)] = 3,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_JONAGOBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PRUNUSBEERE)] = 1,
    [11] = 0xFFFF,
};

u16 dungeon_forest_eggs[] = {
    POKEMON_TOGEPI, POKEMON_MAEHIKEL, POKEMON_PIKACHU, POKEMON_FLABEBE, POKEMON_MYRAPLA, POKEMON_WATTZAPF,
    POKEMON_TRAUMATO, POKEMON_KANGAMA, POKEMON_PINSIR, POKEMON_SICHLOR,
    POKEMON_MOBAI, POKEMON_TANNZA, POKEMON_TEDDIURSA, POKEMON_MAMPFAXO, POKEMON_SAMURZEL,
    POKEMON_KNILZ, POKEMON_BUMMELZ, POKEMON_VIPITIS, POKEMON_SENGO, 0xFFFF,
};

static void dungeon_pattern_fill_with_1x1_border_without_corners(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2) {
    dungeon2_fill_rectangle(map, x, y, w, h, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x - 1, y, 1, h, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x + w, y, 1, h, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x, y - 1, w, 1, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x, y + h, w, 1, DG2_SPACE, dg2);
}

static void dungeon_pattern_fill_berry_forest(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2) {
    dungeon_pattern_fill_with_1x1_border_without_corners(map, x, y, w, h, dg2);
    // The three tiles above a berry tree should be solid...
    dungeon2_fill_rectangle(map, x + 1, y - 1, 3, 1, DG2_WALL, dg2);
}

static void dungeon_pattern_fill_egg_forest(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2) {
    dungeon2_fill_rectangle(map, x, y, w, h, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x - 1, y, 1, h, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x + w, y, 1, h, DG2_SPACE, dg2);
    dungeon2_fill_rectangle(map, x, y + h, w, 1, DG2_SPACE, dg2);
}

static void dungeon_pattern_fill_dusk_forest(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2) {
    dungeon_pattern_fill_with_1x1_border_without_corners(map, x, y, w, h, dg2);
    dungeon2_fill_rectangle(map, x + 2, y, w - 6, 2, DG2_WALL | DG2_ALTERNATIVE_TILE_PROHIBITED, dg2);
    dungeon2_fill_rectangle(map, x + 6, y, 2, 2, DG2_WALL | DG2_ALTERNATIVE_TILE, dg2);
}

static void dungeon_pattern_fill_none(u8 *map, int x, int y, int w, int h, dungeon_generator2 *dg2) {
    (void)map; (void)x; (void)y; (void)w; (void)h; (void)dg2;
}

static void dungeon_forest_normal_initialize_events(dungeon_generator2 *dg2) {
    (void)dg2;
}

static void dungeon_forest_apple_forest_initialize_events(dungeon_generator2 *dg2){
    u8 num_persons = fmem.dmapevents.person_cnt;
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);
    bool create_golden_apple = (dungeon2_rnd_16(dg2) % 4) == 0; // 1/4 of apple forests hold a golden apple
    // Up to 4 apples are under an apple tree
    size_t idxs_shuffled[4] = {0, 1, 2, 3};
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns); j++) {
        gp_rng_seed(dungeon2_seeded_rnd16(dg2, DG2_RANDOM_SEED_PATTERN_PARAMETER));
        shuffle(idxs_shuffled, ARRAY_COUNT(idxs_shuffled), gp_rnd16);
        for (int i = 0; i < 4 && num_persons < ARRAY_COUNT(fmem.dpersons); i++) {
            if (dungeon2_rnd_16(dg2) % 2) {
                fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
                fmem.dpersons[num_persons].overworld_index = 92;
                fmem.dpersons[num_persons].script_std = PERSON_ITEM;
                if (create_golden_apple) {
                    fmem.dpersons[num_persons].value = ITEM_GOLDAPFEL;
                    create_golden_apple = false;
                } else {
                    fmem.dpersons[num_persons].value = (dungeon2_rnd_16(dg2) % 4) > 0 ? ITEM_APFEL : ITEM_RIESENAPFEL;
                }
                fmem.dpersons[num_persons].flag = (u16)(DG2_FLAG_PATTERN + 4 * j + i);
                fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0] + dungeon_forest_apple_displacements[idxs_shuffled[i]][0]);
                fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] + dungeon_forest_apple_displacements[idxs_shuffled[i]][1]);
                num_persons++;
            }
        }
    }
    fmem.dmapevents.person_cnt = num_persons;
}

static void dungeon_forest_berry_forest_initialize_events(dungeon_generator2 *dg2){
    u8 num_persons = fmem.dmapevents.person_cnt;
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);
    gp_rng_seed(dungeon2_seeded_rnd16(dg2, DG2_RANDOM_SEED_PATTERN_PARAMETER));
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns); j++) {
        for (int i = 0; i < 3 && num_persons < ARRAY_COUNT(fmem.dpersons); i++) {
            fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
            fmem.dpersons[num_persons].overworld_index = OVERWORLD_SPRITE_BERRY;
            fmem.dpersons[num_persons].script_std = PERSON_STATIC_BERRY_TREE;
            u16 item = (u16)BERRY_IDX_TO_ITEM_IDX(choice(dungeon_forest_berries, ARRAY_COUNT(dungeon_forest_berries) - 1, gp_rnd16));
            berry *b = berry_get((u8)ITEM_IDX_TO_BERRY_IDX(item));
            fmem.dpersons[num_persons].value = item;
            fmem.dpersons[num_persons].argument = b->min_yield;
            fmem.dpersons[num_persons].flag = (u16)(DG2_FLAG_PATTERN + 3 * j + i);
            fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0] + i - 1);
            fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] - 1);
            num_persons++;
        }
    }
    fmem.dmapevents.person_cnt = num_persons;
}

static void dungeon_forest_egg_forest_initialize_events(dungeon_generator2 *dg2){
    u8 num_persons = fmem.dmapevents.person_cnt;
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);
    gp_rng_seed(cmem.dg2.seed);
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns) && num_persons < ARRAY_COUNT(fmem.dpersons); j++) {
        fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
        fmem.dpersons[num_persons].overworld_index = 101;
        fmem.dpersons[num_persons].script_std = PERSON_EGG;
        fmem.dpersons[num_persons].value = dungeon_forest_eggs[dungeon2_rnd_16(dg2) % (ARRAY_COUNT(dungeon_forest_eggs) - 1)];
        fmem.dpersons[num_persons].flag = (u16)(DG2_FLAG_PATTERN + j);
        fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0]);
        fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] - 1);
        num_persons++;
    }
    fmem.dmapevents.person_cnt = num_persons;
}

static s16 dungeon_forest_mushroom_displacements[][3] = {
    {0, -2}, {-1, 0}, {1, 0},
};

static void dungeon_mushroom_forest_initialize_events(dungeon_generator2 *dg2) {
    u8 num_persons = fmem.dmapevents.person_cnt;
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);
    size_t idxs_shuffled[3] = {0, 1, 2};
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns); j++) {
        int num_mushrooms = 1 + dungeon2_rnd_16(dg2) % 3;
        fmem.gp_rng = dg2->seed;
        shuffle(idxs_shuffled, ARRAY_COUNT(idxs_shuffled), gp_rnd16);
        for (int i = 0; i < num_mushrooms && num_persons < ARRAY_COUNT(fmem.dpersons); i++) {
            fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
            fmem.dpersons[num_persons].overworld_index = OVERWORLD_SPRITE_MISC;
            fmem.dpersons[num_persons].script_std = PERSON_MUSHROOM;
            fmem.dpersons[num_persons].value = (u16)(DUNGEON_MISC_IDX_START + 3 * j + i);
            fmem.dpersons[num_persons].flag = (u16)(DG2_FLAG_PATTERN + j);
            fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0] + dungeon_forest_mushroom_displacements[idxs_shuffled[i]][0]);
            fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] + dungeon_forest_mushroom_displacements[idxs_shuffled[i]][1]);
            num_persons++;
        }
    }
    fmem.dmapevents.person_cnt = num_persons;
}

static void dungeon_dusk_forest_initialize_events(dungeon_generator2 *dg2) {
    u8 num_warps = fmem.dmapevents.warp_cnt;
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns) && num_warps <= ARRAY_COUNT(fmem.dwarps); j++) {
        fmem.dwarps[num_warps].x = (s16)(nodes[DG2_NODE_PATTERN + j][0] - 1);
        fmem.dwarps[num_warps].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] + 1);
        fmem.dwarps[num_warps].target_warp_id = 0;
        fmem.dwarps[num_warps].target_map = DG2_DUSK_FOREST_CABIN_MAP;
        fmem.dwarps[num_warps].target_bank = DG2_BANK;
        num_warps++;
    }
    fmem.dmapevents.warp_cnt = num_warps;
}

static void dungeon_tent_forest_initialize_events(dungeon_generator2 *dg2) {
    u8 num_warps = fmem.dmapevents.warp_cnt;
    int (*nodes)[2] = save1->dungeon_nodes;
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns) && num_warps <= ARRAY_COUNT(fmem.dwarps); j++) {
        fmem.dwarps[num_warps].x = (s16)(nodes[DG2_NODE_PATTERN + j][0]);
        fmem.dwarps[num_warps].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] + 1);
        fmem.dwarps[num_warps].target_warp_id = 0;
        fmem.dwarps[num_warps].target_map = DG2_DUSK_FOREST_TENT_MAP;
        fmem.dwarps[num_warps].target_bank = DG2_BANK;
        num_warps++;
    }
    fmem.dmapevents.warp_cnt = num_warps;
}

dungeon_forest_t dungeon_forest_types[NUM_DUNGEON_FOREST_TYPES] = {
    [DUNGEON_FOREST_TYPE_NORMAL] = {
        .footer = &map_footer_dungeon_forest_normal,
        .min_num_patterns = 0,
        .max_num_patterns = 0,
        .deco_rate = 0,
        .alternative_tree_rate = 0,
        .event_init = dungeon_forest_normal_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_none,
        .has_alternative_trees = false,
        .map_weather = MAP_WEATHER_CLOUDY,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_PARA_HEILER, ITEM_GEGENGIFT, ITEM_AUFWECKER, ITEM_AETHER,
        },
        .items_rare = {
            ITEM_GRUENSTUECK, ITEM_TOP_SCHUTZ, ITEM_AP_PLUS, ITEM_ELIXIER,
        },
        .species_common = {
            POKEMON_PIKACHU, POKEMON_MYRAPLA, POKEMON_KNOFENSA, POKEMON_SAMURZEL,
            POKEMON_WAUMPEL, POKEMON_HORNLIU, POKEMON_LEDYBA, POKEMON_WATTZAPF,
        },
        .species_rare = {
            POKEMON_DUFLOR, POKEMON_ULTRIGARIA, POKEMON_SCHALOKO, POKEMON_PANEKON,
        },
        .species_static_encounter = {
            POKEMON_GIFLOR, POKEMON_SARZENIA, POKEMON_PAPINELLA, POKEMON_PUDOX,
        },
    },
    [DUNGEON_FOREST_TYPE_APPLE_FOREST] = {
        .footer = &map_footer_dungeon_forest_apple_tree,
        .min_num_patterns = 1,
        .max_num_patterns = 2,
        .deco_rate = 32,
        .alternative_tree_rate = 64,
        .event_init = dungeon_forest_apple_forest_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_with_1x1_border_without_corners,
        .has_alternative_trees = true,
        .map_weather = MAP_WEATHER_OUTSIDE,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_PARA_HEILER, ITEM_GEGENGIFT, ITEM_APFEL, ITEM_APFEL,
        },
        .items_rare = {
            ITEM_GRUENSTUECK, ITEM_TOP_SCHUTZ, ITEM_RIESENAPFEL, ITEM_ELIXIER,
        },
        .species_common = {
            POKEMON_TEDDIURSA, POKEMON_MOBAI, POKEMON_KNOFENSA, POKEMON_SAMURZEL,
            POKEMON_WAUMPEL, POKEMON_HORNLIU, POKEMON_LEDYBA, POKEMON_FLABEBE,
        },
        .species_rare = {
            POKEMON_DUFLOR, POKEMON_MOGELBAUM, POKEMON_LEDIAN, POKEMON_FLOETTE,
        },
        .species_static_encounter = {
            POKEMON_GIFLOR, POKEMON_URSARING, POKEMON_FLORGES, POKEMON_SARZENIA,
        },
    },
    [DUNGEON_FOREST_TYPE_BERRY_FOREST] = {
        .footer = &map_footer_dungeon_forest_berry_spot,
        .min_num_patterns = 1,
        .max_num_patterns = 3,
        .deco_rate = 16,
        .alternative_tree_rate = 64,
        .event_init = dungeon_forest_berry_forest_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_berry_forest,
        .has_alternative_trees = true,
        .x_consistent_decoration = true,
        .map_weather = MAP_WEATHER_OUTSIDE,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_PARA_HEILER, ITEM_GEGENGIFT, ITEM_BEERENSAFT, ITEM_AETHER,
        },
        .items_rare = {
            ITEM_GRUENSTUECK, ITEM_TOP_SCHUTZ, ITEM_TOP_AETHER, ITEM_ELIXIER,
        },
        .species_common = {
            POKEMON_TEDDIURSA, POKEMON_WATTZAPF, POKEMON_KNOFENSA, POKEMON_SAMURZEL,
            POKEMON_BUMMELZ, POKEMON_MYRAPLA, POKEMON_LEDYBA, POKEMON_FLABEBE,
        },
        .species_rare = {
            POKEMON_DUFLOR, POKEMON_FLOETTE, POKEMON_BLANAS, POKEMON_MUNTIER,
        },
        .species_static_encounter = {
            POKEMON_GIFLOR, POKEMON_URSARING, POKEMON_TENGULIST, POKEMON_LETARKING,
        },
    },
    [DUNGEON_FOREST_TYPE_EGG_FOREST] = {
        .footer = &map_footer_dungeon_forest_nest,
        .min_num_patterns = 1,
        .max_num_patterns = 2,
        .deco_rate = 32,
        .alternative_tree_rate = 8,
        .event_init = dungeon_forest_egg_forest_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_egg_forest,
        .has_alternative_trees = true,
        .x_consistent_decoration = true,
        .map_weather = MAP_WEATHER_OUTSIDE,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_PARA_HEILER, ITEM_GEGENGIFT, ITEM_BEERENSAFT, ITEM_AETHER,
        },
        .items_rare = {
            ITEM_GEWITTER_EI, ITEM_WUESTEN_EI, ITEM_TUNDRA_EI, ITEM_SONNEN_EI,
        },
        .species_common = {
            POKEMON_TOGEPI, POKEMON_TANNZA, POKEMON_KNOFENSA, POKEMON_SAMURZEL,
            POKEMON_KASTADUR, POKEMON_MYRAPLA, POKEMON_PIKACHU, POKEMON_FLABEBE,
        },
        .species_rare = {
            POKEMON_ULTRIGARIA, POKEMON_DUFLOR, POKEMON_BLANAS, POKEMON_FLOETTE,
        },
        .species_static_encounter = {
            POKEMON_GIFLOR, POKEMON_TOGETIC, POKEMON_RAICHU, POKEMON_CHANEIRA,
        },
    },
    [DUNGEON_FOREST_TYPE_MUSHROOM_FOREST] = {
        .footer = &map_footer_dungeon_forest_mushrooms,
        .min_num_patterns = 1,
        .max_num_patterns = 3,
        .deco_rate = 80,
        .alternative_tree_rate = 24,
        .event_init = dungeon_mushroom_forest_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_with_1x1_border_without_corners,
        .has_alternative_trees = true,
        .map_weather = MAP_WEATHER_CLOUDY,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_PARA_HEILER, ITEM_GEGENGIFT, ITEM_AUFWECKER, ITEM_AETHER,
        },
        .items_rare = {
            ITEM_MINIPILZ, ITEM_GRUENSTUECK, ITEM_HYPERTRANK, ITEM_TOP_SCHUTZ,
        },
        .species_common = {
            POKEMON_KNILZ, POKEMON_TRAUMATO, POKEMON_KNOFENSA, POKEMON_SAMURZEL,
            POKEMON_KASTADUR, POKEMON_MYRAPLA, POKEMON_WAUMPEL, POKEMON_KRAMURX,
        },
        .species_rare = {
            POKEMON_SCHALOKO, POKEMON_PANEKON, POKEMON_BLANAS, POKEMON_ULTRIGARIA,
        },
        .species_static_encounter = {
            POKEMON_KAPILZ, POKEMON_HYPNO, POKEMON_PAPINELLA, POKEMON_PUDOX,
        },
    },
    [DUNGEON_FOREST_TYPE_DUSK_FOREST] = {
        .footer = &map_footer_dungeon_forest_dusk,
        .min_num_patterns = 1,
        .max_num_patterns = 1,
        .deco_rate = 80,
        .alternative_tree_rate = 32,
        .event_init = dungeon_dusk_forest_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_dusk_forest,
        .has_alternative_trees = true,
        .x_consistent_decoration = true,
        .y_consistent_decoration = true,
        .map_weather = MAP_WEATHER_CLOUDY,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_PARA_HEILER, ITEM_GEGENGIFT, ITEM_AUFWECKER, ITEM_AETHER,
        },
        .items_rare = {
            ITEM_DUESTERSTUECK, ITEM_BELEBER, ITEM_HYPERTRANK, ITEM_TOP_SCHUTZ,
        },
        .species_common = {
            POKEMON_PARAGONI, POKEMON_TRAUMATO, POKEMON_WEBARAK, POKEMON_SAMURZEL,
            POKEMON_WATTZAPF, POKEMON_MYRAPLA, POKEMON_WAUMPEL, POKEMON_KRAMURX,
        },
        .species_rare = {
            POKEMON_SCHALOKO, POKEMON_PANEKON, POKEMON_BLANAS, POKEMON_ARIADOS,
        },
        .species_static_encounter = {
            POKEMON_KAPILZ, POKEMON_HYPNO, POKEMON_TROMBORK, POKEMON_KRAMSHEF,
        },
    },
    [DUNGEON_FOREST_TYPE_TENT_FOREST] = {
        .footer = &map_footer_dungeon_forest_tent_and_campfire,
        .min_num_patterns = 1,
        .max_num_patterns = 1,
        .deco_rate = 0,
        .alternative_tree_rate = 0,
        .event_init = dungeon_tent_forest_initialize_events,
        .fill_pattern_in_map = dungeon_pattern_fill_with_1x1_border_without_corners,
        .map_weather = MAP_WEATHER_CLOUDY,
        .items_common = {
            ITEM_SUPERBALL, ITEM_SUPERTRANK, ITEM_SUPERSCHUTZ, ITEM_FLUCHTSEIL,
            ITEM_PARA_HEILER, ITEM_GEGENGIFT, ITEM_AUFWECKER, ITEM_AETHER,
        },
        .items_rare = {
            ITEM_GRUENSTUECK, ITEM_TOP_SCHUTZ, ITEM_AP_PLUS, ITEM_ELIXIER,
        },
        .species_common = {
            POKEMON_PIKACHU, POKEMON_MYRAPLA, POKEMON_KNOFENSA, POKEMON_SAMURZEL,
            POKEMON_WAUMPEL, POKEMON_TANNZA, POKEMON_LEDYBA, POKEMON_WATTZAPF,
        },
        .species_rare = {
            POKEMON_DUFLOR, POKEMON_KOKUNA, POKEMON_SCHALOKO, POKEMON_PANEKON,
        },
        .species_static_encounter = {
            POKEMON_GIFLOR, POKEMON_BIBOR, POKEMON_PAPINELLA, POKEMON_PUDOX,
        },
    },
};

u16 dungeon_forest_pick_item(dungeon_generator2 *dg2) {
    if ((dungeon2_rnd_16(dg2) % 10) < 3) {
        return dungeon_forest_types[dungeon2_get_forest_type(dg2)].items_rare[dungeon2_rnd_16(dg2) % DUNGEON_FOREST_NUM_ITEMS_RARE];
    } else {
        return dungeon_forest_types[dungeon2_get_forest_type(dg2)].items_common[dungeon2_rnd_16(dg2) % DUNGEON_FOREST_NUM_ITEMS_COMMON];
    }
}

void dungeon2_init_wild_pokemon_forest(dungeon_generator2 *dg2) {

    dungeon_forest_t *forest_type = dungeon_forest_types + dungeon2_get_forest_type(dg2);

    u16 common_pokemon[4];
    u16 rare_pokemon[2];
    u16 super_rare_pokemon[1];

    dungeon2_pick_wild_pokemon(common_pokemon, ARRAY_COUNT(common_pokemon), forest_type->species_common, DUNGEON_FOREST_NUM_POKEMON_COMMON, dg2);
    dungeon2_pick_wild_pokemon(rare_pokemon, ARRAY_COUNT(rare_pokemon), forest_type->species_rare, DUNGEON_FOREST_NUM_POKEMON_RARE, dg2);
    dungeon2_pick_wild_pokemon(super_rare_pokemon, ARRAY_COUNT(super_rare_pokemon), forest_type->species_static_encounter, DUNGEON_FOREST_NUM_POKEMON_STATIC, dg2);

    *var_access(DUNGEON_OVERWORLD_SPECIES) = super_rare_pokemon[0];

    fmem.dwild_pokemon.grass = &(fmem.dwild_habitat_grass);
    fmem.dwild_pokemon.water = NULL;
    fmem.dwild_pokemon.other = NULL;
    fmem.dwild_pokemon.rod = NULL;
    fmem.dwild_habitat_grass.frequency = DUNGEON_TYPE_FOREST_WILD_POKEMON_FREQUENCY;
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

void dungeon2_set_encounter_forest() {
  dungeon_generator2 *dg2 = &(cmem.dg2);
  dungeon2_forest_initialize_state(dg2);
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

map_header_t *dungeon2_init_header_forest(dungeon_generator2 *dg2) {
    DEBUG("D2 header init\n");
    fmem.dmap_header_initialized = 1;
    fmem.dmapheader.levelscripts = dungeon2_lscr;
    fmem.dmapheader.connections = &dungeon2_connections;
    fmem.dmapheader.music = 0x14b;
    fmem.dmapheader.map_namespace = mapheader_virtual.map_namespace;
    fmem.dmapheader.flash_type = 0;
    fmem.dmapheader.weather = dungeon_forest_types[dungeon2_get_forest_type(dg2)].map_weather;
    fmem.dmapheader.type = MAP_TYPE_INSIDE;
    fmem.dmapheader.show_name = 0;
    fmem.dmapheader.battle_style = 0;
    fmem.dmapheader.events = dungeon2_init_events_forest(dg2);
    fmem.dmapheader.footer = dungeon2_init_footer_forest(dg2);
    fmem.dmapheader.footer_idx = DG2_FOOTER_IDX;
    return &(fmem.dmapheader);
}

map_event_header_t *dungeon2_init_events_forest(dungeon_generator2 *dg2){
    dungeon2_initialize_std_events(dg2, dungeon_forest_pick_item);
    dungeon_forest_types[dungeon2_get_forest_type(dg2)].event_init(dg2);
    return &(fmem.dmapevents);
}

static u16 blocks_alternative_tree[NUM_NBS][5][2][2] = { // [block_type_below][decoration_idx][y][x]
    [NB_GRASS] = {
        [0] = {{0x2b8 | BLOCK_SOLID, 0x2b9 | BLOCK_SOLID}, {0x2c0 | BLOCK_SOLID, 0x2c1 | BLOCK_SOLID}},
        [1] = {{0x2e8 | BLOCK_SOLID, 0x2e9 | BLOCK_SOLID}, {0x2f0 | BLOCK_SOLID, 0x2f1 | BLOCK_SOLID}},
        [2] = {{0x2ea | BLOCK_SOLID, 0x2eb | BLOCK_SOLID}, {0x2f2 | BLOCK_SOLID, 0x2f3 | BLOCK_SOLID}},
        [3] = {{0x2ec | BLOCK_SOLID, 0x2ed | BLOCK_SOLID}, {0x2f4 | BLOCK_SOLID, 0x2f5 | BLOCK_SOLID}},
        [4] = {{0x2ee | BLOCK_SOLID, 0x2ef | BLOCK_SOLID}, {0x2f6 | BLOCK_SOLID, 0x2f7 | BLOCK_SOLID}},
    },
    [NB_1x1_TREE] = {
        [0] = {{0x2b8 | BLOCK_SOLID, 0x2b9 | BLOCK_SOLID}, {0x2a4 | BLOCK_SOLID, 0x2a5 | BLOCK_SOLID}},
        [1] = {{0x2e8 | BLOCK_SOLID, 0x2e9 | BLOCK_SOLID}, {0x320 | BLOCK_SOLID, 0x321 | BLOCK_SOLID}},
        [2] = {{0x2ea | BLOCK_SOLID, 0x2eb | BLOCK_SOLID}, {0x322 | BLOCK_SOLID, 0x323 | BLOCK_SOLID}},
        [3] = {{0x2ec | BLOCK_SOLID, 0x2ed | BLOCK_SOLID}, {0x324 | BLOCK_SOLID, 0x325 | BLOCK_SOLID}},
        [4] = {{0x2ee | BLOCK_SOLID, 0x2ef | BLOCK_SOLID}, {0x326 | BLOCK_SOLID, 0x327 | BLOCK_SOLID}},
    },
    [NB_2x2_TREE] = {
        [0] = {{0x2b8 | BLOCK_SOLID, 0x2b9 | BLOCK_SOLID}, {0x2ae | BLOCK_SOLID, 0x2af | BLOCK_SOLID}},
        [1] = {{0x2e8 | BLOCK_SOLID, 0x2e9 | BLOCK_SOLID}, {0x308 | BLOCK_SOLID, 0x309 | BLOCK_SOLID}},
        [2] = {{0x2ea | BLOCK_SOLID, 0x2eb | BLOCK_SOLID}, {0x30a | BLOCK_SOLID, 0x30b | BLOCK_SOLID}},
        [3] = {{0x2ec | BLOCK_SOLID, 0x2ed | BLOCK_SOLID}, {0x30c | BLOCK_SOLID, 0x30d | BLOCK_SOLID}},
        [4] = {{0x2ee | BLOCK_SOLID, 0x2ef | BLOCK_SOLID}, {0x30e | BLOCK_SOLID, 0x30f | BLOCK_SOLID}},
    },
    [NB_2x2_TREE_ALT] = {
        [0] = {{0x2b8 | BLOCK_SOLID, 0x2b9 | BLOCK_SOLID}, {0x2c8 | BLOCK_SOLID, 0x2c9 | BLOCK_SOLID}},
        [1] = {{0x2e8 | BLOCK_SOLID, 0x2e9 | BLOCK_SOLID}, {0x338 | BLOCK_SOLID, 0x339 | BLOCK_SOLID}},
        [2] = {{0x2ea | BLOCK_SOLID, 0x2eb | BLOCK_SOLID}, {0x33a | BLOCK_SOLID, 0x33b | BLOCK_SOLID}},
        [3] = {{0x2ec | BLOCK_SOLID, 0x2ed | BLOCK_SOLID}, {0x33c | BLOCK_SOLID, 0x33d | BLOCK_SOLID}},
        [4] = {{0x2ee | BLOCK_SOLID, 0x2ef | BLOCK_SOLID}, {0x33e | BLOCK_SOLID, 0x33f | BLOCK_SOLID}},
    },
};

static u16 blocks_1x1_tree[NUM_NBS][5][2][2] = { // [block_type_below][decoration_idx][y][x]
    [NB_GRASS] = {
        [0] = {{0x29a | BLOCK_SOLID, 0x29a | BLOCK_SOLID}, {0x29a | BLOCK_SOLID, 0x29a | BLOCK_SOLID}},
        [1] = {{0x2e0 | BLOCK_SOLID, 0x2e0 | BLOCK_SOLID}, {0x2e0 | BLOCK_SOLID, 0x2e0 | BLOCK_SOLID}},
        [2] = {{0x2e1 | BLOCK_SOLID, 0x2e1 | BLOCK_SOLID}, {0x2e1 | BLOCK_SOLID, 0x2e1 | BLOCK_SOLID}},
        [3] = {{0x2e2 | BLOCK_SOLID, 0x2e2 | BLOCK_SOLID}, {0x2e2 | BLOCK_SOLID, 0x2e2 | BLOCK_SOLID}},
        [4] = {{0x2e3 | BLOCK_SOLID, 0x2e3 | BLOCK_SOLID}, {0x2e3 | BLOCK_SOLID, 0x2e3 | BLOCK_SOLID}},
    },
    [NB_1x1_TREE] = {
        [0] = {{0x29b | BLOCK_SOLID, 0x29b | BLOCK_SOLID}, {0x29b | BLOCK_SOLID, 0x29b | BLOCK_SOLID}},
        [1] = {{0x318 | BLOCK_SOLID, 0x319 | BLOCK_SOLID}, {0x318 | BLOCK_SOLID, 0x319 | BLOCK_SOLID}},
        [2] = {{0x31a | BLOCK_SOLID, 0x31b | BLOCK_SOLID}, {0x31a | BLOCK_SOLID, 0x31b | BLOCK_SOLID}},
        [3] = {{0x31c | BLOCK_SOLID, 0x31d | BLOCK_SOLID}, {0x31c | BLOCK_SOLID, 0x31d | BLOCK_SOLID}},
        [4] = {{0x31e | BLOCK_SOLID, 0x31f | BLOCK_SOLID}, {0x31e | BLOCK_SOLID, 0x31f | BLOCK_SOLID}},
    },
    [NB_2x2_TREE] = {
        [0] = {{0x2aa | BLOCK_SOLID, 0x2ab | BLOCK_SOLID}, {0x2aa | BLOCK_SOLID, 0x2ab | BLOCK_SOLID}},
        [1] = {{0x300 | BLOCK_SOLID, 0x301 | BLOCK_SOLID}, {0x300 | BLOCK_SOLID, 0x301 | BLOCK_SOLID}},
        [2] = {{0x302 | BLOCK_SOLID, 0x303 | BLOCK_SOLID}, {0x302 | BLOCK_SOLID, 0x303 | BLOCK_SOLID}},
        [3] = {{0x304 | BLOCK_SOLID, 0x305 | BLOCK_SOLID}, {0x304 | BLOCK_SOLID, 0x305 | BLOCK_SOLID}},
        [4] = {{0x306 | BLOCK_SOLID, 0x307 | BLOCK_SOLID}, {0x306 | BLOCK_SOLID, 0x307 | BLOCK_SOLID}},
    },
    [NB_2x2_TREE_ALT] = {
        [0] = {{0x2ca | BLOCK_SOLID, 0x2cb | BLOCK_SOLID}, {0x2ca | BLOCK_SOLID, 0x2cb | BLOCK_SOLID}},
        [1] = {{0x330 | BLOCK_SOLID, 0x331 | BLOCK_SOLID}, {0x330 | BLOCK_SOLID, 0x331 | BLOCK_SOLID}},
        [2] = {{0x332 | BLOCK_SOLID, 0x333 | BLOCK_SOLID}, {0x332 | BLOCK_SOLID, 0x333 | BLOCK_SOLID}},
        [3] = {{0x334 | BLOCK_SOLID, 0x335 | BLOCK_SOLID}, {0x334 | BLOCK_SOLID, 0x335 | BLOCK_SOLID}},
        [4] = {{0x336 | BLOCK_SOLID, 0x337 | BLOCK_SOLID}, {0x336 | BLOCK_SOLID, 0x337 | BLOCK_SOLID}},
    }
};

static u16 blocks_grass[NUM_NBS][5][2][2] = { // [block_type_below][decoration_idx][y][x]
    [NB_GRASS] = { // Grass is decorated by a separate function
        [0] = {{0xFFFF, 0xFFFF}, {0xFFFF, 0xFFFF}},
        [1] = {{0xFFFF, 0xFFFF}, {0xFFFF, 0xFFFF}},
        [2] = {{0xFFFF, 0xFFFF}, {0xFFFF, 0xFFFF}},
        [3] = {{0xFFFF, 0xFFFF}, {0xFFFF, 0xFFFF}},
        [4] = {{0xFFFF, 0xFFFF}, {0xFFFF, 0xFFFF}},
    },
    [NB_1x1_TREE] = {
        [0] = {{0x292, 0x292}, {0x292, 0x292}},
        [1] = {{0x2e4, 0x2e4}, {0x2e4, 0x2e4}},
        [2] = {{0x2e5, 0x2e5}, {0x2e5, 0x2e5}},
        [3] = {{0x2e6, 0x2e6}, {0x2e6, 0x2e6}},
        [4] = {{0x2e7, 0x2e7}, {0x2e7, 0x2e7}},
    },
    [NB_2x2_TREE] = {
        [0] = {{0x290, 0x291}, {0x290, 0x291}},
        [1] = {{0x2b2, 0x2b3}, {0x2b2, 0x2b3}},
        [2] = {{0x2b4, 0x2b5}, {0x2b4, 0x2b5}},
        [3] = {{0x2b6, 0x2b7}, {0x2b6, 0x2b7}},
        [4] = {{0x2ba, 0x2bb}, {0x2ba, 0x2bb}},
    },
    [NB_2x2_TREE_ALT] = {
        [0] = {{0x2b0, 0x2b1}, {0x2b0, 0x2b1}},
        [1] = {{0x2bc, 0x2bd}, {0x2bc, 0x2bd}},
        [2] = {{0x2be, 0x2bf}, {0x2be, 0x2bf}},
        [3] = {{0x2c2, 0x2c3}, {0x2c2, 0x2c3}},
        [4] = {{0x2c4, 0x2c5}, {0x2c4, 0x2c5}},
    },
};

static u16 blocks_high_grass[NUM_NBS][5][2][2] = { // [block_type_below][decoration_idx][y][x]
    [NB_GRASS] = {
        [0] = {{0x285, 0x285}, {0x285, 0x285}},
        [1] = {{0x285, 0x285}, {0x285, 0x285}},
        [2] = {{0x285, 0x285}, {0x285, 0x285}},
        [3] = {{0x285, 0x285}, {0x285, 0x285}},
        [4] = {{0x285, 0x285}, {0x285, 0x285}},
    },
    [NB_1x1_TREE] = {
        [0] = {{0x293, 0x293}, {0x293, 0x293}},
        [1] = {{0x293, 0x293}, {0x293, 0x293}},
        [2] = {{0x293, 0x293}, {0x293, 0x293}},
        [3] = {{0x293, 0x293}, {0x293, 0x293}},
        [4] = {{0x293, 0x293}, {0x293, 0x293}},
    },
    [NB_2x2_TREE] = {
        [0] = {{0x2ac, 0x2ad}, {0x2ac, 0x2ad}},
        [1] = {{0x2ac, 0x2ad}, {0x2ac, 0x2ad}},
        [2] = {{0x2ac, 0x2ad}, {0x2ac, 0x2ad}},
        [3] = {{0x2ac, 0x2ad}, {0x2ac, 0x2ad}},
        [4] = {{0x2ac, 0x2ad}, {0x2ac, 0x2ad}},
    },
    [NB_2x2_TREE_ALT] = {
        [0] = {{0x2cc, 0x2cd}, {0x2cc, 0x2cd}},
        [1] = {{0x2cc, 0x2cd}, {0x2cc, 0x2cd}},
        [2] = {{0x2cc, 0x2cd}, {0x2cc, 0x2cd}},
        [3] = {{0x2cc, 0x2cd}, {0x2cc, 0x2cd}},
        [4] = {{0x2cc, 0x2cd}, {0x2cc, 0x2cd}},
    },
};

static u16 blocks_2x2_tree[NUM_NBS][5][2][2] = { // [block_type_below][decoration_idx][y][x]
    [NB_GRASS] = {
        [0] = {{0x298 | BLOCK_SOLID, 0x299 | BLOCK_SOLID}, {0x2a0 | BLOCK_SOLID, 0x2a1 | BLOCK_SOLID}},
        [1] = {{0x2d0 | BLOCK_SOLID, 0x2d1 | BLOCK_SOLID}, {0x2d8 | BLOCK_SOLID, 0x2d9 | BLOCK_SOLID}},
        [2] = {{0x2d2 | BLOCK_SOLID, 0x2d3 | BLOCK_SOLID}, {0x2da | BLOCK_SOLID, 0x2db | BLOCK_SOLID}},
        [3] = {{0x2d4 | BLOCK_SOLID, 0x2d5 | BLOCK_SOLID}, {0x2dc | BLOCK_SOLID, 0x2dd | BLOCK_SOLID}},
        [4] = {{0x2d6 | BLOCK_SOLID, 0x2d7 | BLOCK_SOLID}, {0x2de | BLOCK_SOLID, 0x2df | BLOCK_SOLID}},
    },
    [NB_1x1_TREE] = {
        [0] = {{0x298 | BLOCK_SOLID, 0x299 | BLOCK_SOLID}, {0x2a2 | BLOCK_SOLID, 0x2a3 | BLOCK_SOLID}},
        [1] = {{0x2d0 | BLOCK_SOLID, 0x2d1 | BLOCK_SOLID}, {0x310 | BLOCK_SOLID, 0x311 | BLOCK_SOLID}},
        [2] = {{0x2d2 | BLOCK_SOLID, 0x2d3 | BLOCK_SOLID}, {0x312 | BLOCK_SOLID, 0x313 | BLOCK_SOLID}},
        [3] = {{0x2d4 | BLOCK_SOLID, 0x2d5 | BLOCK_SOLID}, {0x314 | BLOCK_SOLID, 0x315 | BLOCK_SOLID}},
        [4] = {{0x2d6 | BLOCK_SOLID, 0x2d7 | BLOCK_SOLID}, {0x316 | BLOCK_SOLID, 0x317 | BLOCK_SOLID}},
    },
    [NB_2x2_TREE] = {
        [0] = {{0x298 | BLOCK_SOLID, 0x299 | BLOCK_SOLID}, {0x2a8 | BLOCK_SOLID, 0x2a9 | BLOCK_SOLID}},
        [1] = {{0x2d0 | BLOCK_SOLID, 0x2d1 | BLOCK_SOLID}, {0x2f8 | BLOCK_SOLID, 0x2f9 | BLOCK_SOLID}},
        [2] = {{0x2d2 | BLOCK_SOLID, 0x2d3 | BLOCK_SOLID}, {0x2fa | BLOCK_SOLID, 0x2fb | BLOCK_SOLID}},
        [3] = {{0x2d4 | BLOCK_SOLID, 0x2d5 | BLOCK_SOLID}, {0x2fc | BLOCK_SOLID, 0x2fd | BLOCK_SOLID}},
        [4] = {{0x2d6 | BLOCK_SOLID, 0x2d7 | BLOCK_SOLID}, {0x2fe | BLOCK_SOLID, 0x2ff | BLOCK_SOLID}},
    },
    [NB_2x2_TREE_ALT] = {
        [0] = {{0x298 | BLOCK_SOLID, 0x299 | BLOCK_SOLID}, {0x2ce | BLOCK_SOLID, 0x2cf | BLOCK_SOLID}},
        [1] = {{0x2d0 | BLOCK_SOLID, 0x2d1 | BLOCK_SOLID}, {0x328 | BLOCK_SOLID, 0x329 | BLOCK_SOLID}},
        [2] = {{0x2d2 | BLOCK_SOLID, 0x2d3 | BLOCK_SOLID}, {0x32a | BLOCK_SOLID, 0x32b | BLOCK_SOLID}},
        [3] = {{0x2d4 | BLOCK_SOLID, 0x2d5 | BLOCK_SOLID}, {0x32c | BLOCK_SOLID, 0x32d | BLOCK_SOLID}},
        [4] = {{0x2d6 | BLOCK_SOLID, 0x2d7 | BLOCK_SOLID}, {0x32e | BLOCK_SOLID, 0x32f | BLOCK_SOLID}},
    },
};

static u16 dungeon2_forest_branches[] = {0x288, 0x289};
static u16 dungeon2_forest_decoratives[] = {0x28a, 0x28b, 0x28c, 0x28d, 0x28e, 0x28f};
static u16 dungeon2_forest_tiny_grasses[] = {0x281, 0x282, 0x283};

static inline u16 dungeon2_get_grass_decoration(u8 *map, u8 *over, int x, int y, dungeon_generator2 *dg2) {
    (void) over;
    // Count grass, wall neighbours
    int grass_neighbours = 0;
    int wall_neighbours = 0;
    for(int k = 0; k < 4; k++){
        int i = dg2_cross_neighbourhood[k][0];
        int j = dg2_cross_neighbourhood[k][1];
        if(x + i >= 0 && x + i < dg2->width &&
                y + j >= 0 && y + j < dg2->height){
            if(over[(y + j) * dg2->height + x + i] == DG2_SPACE &&
                map[(y + j) * dg2->height + x + i] == DG2_SPACE)
                grass_neighbours++;
            else if(map[(y + j) * dg2->height + x + i] == DG2_WALL)
                wall_neighbours++;
        }
    }
    if(dungeon2_rnd_16(dg2) < grass_neighbours * 0x4000){
        return 0x287; //Cut grass
    } else if (wall_neighbours >= 2 && (dungeon2_rnd_16(dg2) % 100) < 35) {
        return dungeon2_forest_branches[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_forest_branches)];
    } else if (dungeon2_rnd_16(dg2) < wall_neighbours * 0x1000) {
        return dungeon2_forest_decoratives[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_forest_decoratives)];
    } else if (dungeon2_rnd_16(dg2) < 0x1000) {
        return dungeon2_forest_tiny_grasses[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_forest_tiny_grasses)];
    } else {
        return 0x280;
    }
}

static void dungeon2_set_blocks_forest(u8 *map, u8 *over, dungeon_generator2 *dg2) {
    dungeon_forest_t *forest_type = dungeon_forest_types + dungeon2_get_forest_type(dg2);
    // To be able to have consistent decorations, we store them for each row
    u8 *decoration_idxs = malloc(sizeof(u8) * (size_t)dg2->width);
    for (int y = 0; y < dg2->height; y++) {
        if ((y % 2) == 0 || !forest_type->y_consistent_decoration) { // Update decorations for entire row
            u8 decoration_idx = 0;
            for (int x = 0; x < dg2->width; x++) {
                if ((x % 2) == 0 || !forest_type->x_consistent_decoration) {
                    if ((dungeon2_rnd_16(dg2) % 256) < forest_type->deco_rate)
                        decoration_idx = (u8)(1 + (dungeon2_rnd_16(dg2) % 4));
                    else
                        decoration_idx = 0;
                }
                decoration_idxs[x] = decoration_idx;
            }
        }
        for (int x = 0; x < dg2->width; x++) {
            int type = map[y * dg2->width + x];
            u8 type_below;
            if ((y < dg2->height - 1) && ((map[(y + 1) * dg2->width + x] & (DG2_ALTERNATIVE_TILE | DG2_2x2_TREE)) == (DG2_ALTERNATIVE_TILE | DG2_2x2_TREE))) {
                type_below = NB_2x2_TREE_ALT;
            } else if ((y == dg2->height - 1) || (map[(y + 1) * dg2->width + x] & DG2_2x2_TREE)) {
                type_below = NB_2x2_TREE;
            } else if ((y != dg2->height - 1) && (map[(y + 1) * dg2->width + x] & DG2_WALL)) {
                type_below = NB_1x1_TREE;
            } else {
                type_below = NB_GRASS;
            }
            u8 decoration_idx = decoration_idxs[x];
            u16 block = 0;
            if (type & DG2_SPACE && over[y * dg2->width + x] & DG2_SPACE)
                block = blocks_high_grass[type_below][decoration_idx][y % 2][x % 2];
            else if (type & DG2_SPACE) {
                block = blocks_grass[type_below][decoration_idx][y % 2][x % 2];
                if (block == 0xFFFF) 
                    block = dungeon2_get_grass_decoration(map, over, x, y, dg2);
            } else if ((type & (DG2_2x2_TREE | DG2_ALTERNATIVE_TILE)) == (DG2_2x2_TREE | DG2_ALTERNATIVE_TILE)) {
                block = blocks_alternative_tree[type_below][decoration_idx][y % 2][x % 2];
            } else if (type & DG2_2x2_TREE)
                block = blocks_2x2_tree[type_below][decoration_idx][y % 2][x % 2];
            else if (type & DG2_WALL)
                block = blocks_1x1_tree[type_below][decoration_idx][y % 2][x % 2];
            save1->dungeon_blocks[y * dg2->width + x] = block;
        }
    }
    free(decoration_idxs);
}

static void dungeon2_compute_blocks_forest(u8 *map, u8 *over, dungeon_generator2 *dg2){
    int (*nodes)[2] = save1->dungeon_nodes;
    dungeon_forest_t *forest_type = dungeon_forest_types + dungeon2_get_forest_type(dg2);
    map_footer_t *pattern = dungeon2_get_forest_type_pattern(dg2);
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);

    // Fill map to fit the pattern
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns); j++) {
        int w = (int)pattern->width;
        int h = (int)pattern->height;
        int x = nodes[DG2_NODE_PATTERN + j][0] - (w / 2);
        int y = nodes[DG2_NODE_PATTERN + j][1] - (h / 2);
        forest_type->fill_pattern_in_map(map, x, y, w, h, dg2);
    }

    // Fill map to fill items
    for (int j = DG2_NODE_TRAINER_OR_ITEM; j < dg2->nodes && j < DG2_NODE_TRAINER_OR_ITEM + DG2_MAX_NUM_TRAINER_OR_ITEM_NODES; j++) {
        if (dungeon2_node_trainer_or_item_get_type(dg2, j) == DG2_NODE_TRAINER_OR_ITEM_TYPE_ITEM) {
            int x = nodes[j][0];
            int y = nodes[j][1];
            dungeon2_fill_rectangle(map, nodes[j][0] - 1, nodes[j][1] - 1, 3, 3, DG2_SPACE, dg2);
            over[dg2->width * y + x] = DG2_WALL;
        }
    }

    // Construct 2x2 and alternative 2x2 trees
    for (int y = 0; y < dg2->height - 1; y += 2) {
        for (int x = 0; x < dg2->width - 1; x += 2) {
            // Always compute 2x2 patches for tree placement
            if (map[y * dg2->width + x] & DG2_WALL && map[y * dg2->width + x + 1] & DG2_WALL &&
                map[(y + 1) * dg2->width + x] & DG2_WALL && map[(y + 1) * dg2->width + x + 1] & DG2_WALL) {
                u8 mask = ((dungeon2_rnd_16(dg2) % 256) < forest_type->alternative_tree_rate) && forest_type->has_alternative_trees &&
                    !(map[y * dg2->width + x] & DG2_ALTERNATIVE_TILE_PROHIBITED || map[y * dg2->width + x + 1] & DG2_ALTERNATIVE_TILE_PROHIBITED
                    || map[(y + 1) * dg2->width + x] & DG2_ALTERNATIVE_TILE_PROHIBITED || map[(y + 1) * dg2->width + x + 1] & DG2_ALTERNATIVE_TILE_PROHIBITED)? 
                    DG2_2x2_TREE | DG2_ALTERNATIVE_TILE : DG2_2x2_TREE;
                map[y * dg2->width + x] |= mask;
                map[y * dg2->width + x + 1] |= mask;
                map[(y + 1) * dg2->width + x] |= mask;
                map[(y + 1) * dg2->width + x + 1] |= mask;
            }
        }
    }

    // Compute the actual blocks
    dungeon2_set_blocks_forest(map, over, dg2);
    if (pattern) {
        for (int i = 0; i < MIN(num_patterns, DG2_MAX_NUM_PATTERNS); i++) {
            dungeon2_place_pattern(nodes[DG2_NODE_PATTERN + i][0], nodes[DG2_NODE_PATTERN + i][1], pattern, dg2);
        } 
    }
}

void dungeon2_forest_initialize_state(dungeon_generator2 *dg2) {
  dg2->seed = dg2->initial_seed;
  dg2->width = DG2_FOREST_WIDTH;
  dg2->height = DG2_FOREST_HEIGHT;
  dg2->path_randomness = DG2_FOREST_PATH_RANDOMNESS;
  dg2->init_randomness = DG2_FOREST_INIT_RANDOMNESS;
  dg2->nodes = DG2_FOREST_NODES;
  dg2->margin = DG2_FOREST_MARGIN;
  dg2->node_metric_lambda_l2 = DG2_FOREST_NODE_METRIC_LAMBDA_MEAN;
  dg2->node_metric_lambda_min = DG2_FOREST_NODE_METRIC_LAMBDA_MIN;
  dg2->node_samples = DG2_FOREST_NODE_SAMPLES;
  map_footer_t *pattern = dungeon2_get_forest_type_pattern(dg2);
  dg2->pattern_margin = (u8)(((MAX(pattern->width, pattern->height) + 1) / 2) & 0xF);
}

void dungeon2_initialize_forest(){
    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_forest_initialize_state(dg2);
    dungeon2_init_wild_pokemon_forest(dg2); // Initialize before events since persons depend
    dungeon2_init_header_forest(dg2);
    fmem.dmap_header_initialized = 1;
}

void dungeon2_compute_layout_forest_callback(u8 self) {
    dungeon_generator2 *dg2 = (dungeon_generator2*) big_callback_get_int(self, 2);
    u8 *map = (u8*)big_callback_get_int(self, 4);
    u8 *over = (u8*)big_callback_get_int(self, 8);
    u16 *vars = big_callbacks[self].params;
    // DEBUG("Forest callback superstate %d\n", vars[0]);
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
        case 5: {
            int num_patterns = dungeon2_get_forest_num_patterns(dg2);
            int excluded_nodes_mask = 0;
            for (int i = DG2_NODE_PATTERN; i < DG2_NODE_PATTERN + num_patterns; i++)
                excluded_nodes_mask |= 1 << i;
            // DEBUG("Excluded vertices mask 0x%x\n", excluded_nodes_mask);
            vars[1] = dungeon2_create_patch_layout_with_callback(dg2, save1->dungeon_nodes, over, excluded_nodes_mask);
            vars[0]++;
            break;
        }
        case 6: {
            if (dungeon2_create_patch_layout_with_callback_finished((u8)vars[1]))
                vars[0]++;
            break;
        }
        case 7: {
            dungeon2_compute_blocks_forest(map, over, dg2);
            free(map);
            free(over);
            big_callback_delete(self);
        }
    }
}


void dungeon2_compute_layout_forest() {
    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_forest_initialize_state(dg2);
    u8 cb_idx = big_callback_new(dungeon2_compute_layout_forest_callback, 0);
    big_callback_set_int(cb_idx, 2, (int)dg2);
    big_callbacks[cb_idx].params[0] = 0;
}

void dungeon2_compute_layout_forest_continue_overworld_script_if_finished_callback(u8 self) {
    if (!big_callback_is_active(dungeon2_compute_layout_forest_callback)) {
        overworld_script_resume();
        big_callback_delete(self);
    }
}
void dungeon2_compute_layout_forest_continue_overworld_script_if_finished() {
    big_callback_new(dungeon2_compute_layout_forest_continue_overworld_script_if_finished_callback, 1);
}

void dungeon2_enter_forest() {

    *var_access(DUNGEON_TYPE) = DUNGEON_TYPE_FOREST;
    *var_access(DUNGEON_STEPS) = 0;
    dungeon2_reset_flags();

    // Get the warp node (first node in the forest)
    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_forest_initialize_state(dg2);
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
