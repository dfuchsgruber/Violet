/*
 * forest.c
 *
 *  Created on: Jun 3, 2018
 *      Author: dominik
 */

#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon/dungeon2.h"
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

extern tileset maptileset0;
extern tileset maptileset_dungeon_forest;
extern map_footer_t map_footer_dungeon_forest_apple_tree;
extern map_footer_t map_footer_dungeon_forest_berry_spot;
extern map_footer_t map_footer_dungeon_forest_nest;

u16 dungeon2_forest_borders[4] = {0x26, 0x27, 0x2c, 0x2d};

map_block dungeon2_forest_map_empty[DG2_FOREST_WIDTH * DG2_FOREST_HEIGHT] = {0};

extern u8 ow_script_dungeon_encounter[];
extern u8 ow_script_dungeon_item[];

static u32 dungeon2_forest_type_rates[NUM_DUNGEON_FOREST_TYPES] = {
    [DUNGEON_FOREST_TYPE_NORMAL] = 5,
    [DUNGEON_FOREST_TYPE_APPLE_FOREST] = 3,
    [DUNGEON_FOREST_TYPE_BERRY_FOREST] = 2,
    [DUNGEON_FOREST_TYPE_EGG_FOREST] = 2000,
};

u8 dungeon2_get_forest_type(dungeon_generator2 *dg2) {
    fmem.gp_rng = dg2->initial_seed;
    return (u8)choice(dungeon2_forest_type_rates, NUM_DUNGEON_FOREST_TYPES, gp_rnd16);
}

static map_footer_t *dungeon2_get_forest_type_pattern(dungeon_generator2 *dg2) {
    switch (dungeon2_get_forest_type(dg2)) {
        case DUNGEON_FOREST_TYPE_APPLE_FOREST:
            return &map_footer_dungeon_forest_apple_tree;
        case DUNGEON_FOREST_TYPE_BERRY_FOREST:
            return &map_footer_dungeon_forest_berry_spot;
        case DUNGEON_FOREST_TYPE_EGG_FOREST:
            return &map_footer_dungeon_forest_nest;
        default:
            return NULL;
    }
}

static int dungeon2_get_forest_num_patterns(dungeon_generator2 *dg2) {
    switch (dungeon2_get_forest_type(dg2)) {
        case DUNGEON_FOREST_TYPE_APPLE_FOREST:
            return MIN(DG2_MAX_NUM_PATTERNS, 1 + (dungeon2_rnd_16(dg2) % 3));
        case DUNGEON_FOREST_TYPE_BERRY_FOREST:
            return MIN(DG2_MAX_NUM_PATTERNS, 1 + (dungeon2_rnd_16(dg2) % 3));
        case DUNGEON_FOREST_TYPE_EGG_FOREST:
            // return MIN(DG2_MAX_NUM_PATTERNS, 1 + (dungeon2_rnd_16(dg2) % 2));
            return 3;
    }
    return 0;
}

map_header_t *dungeon2_init_header_forest(dungeon_generator2 *dg2) {
    dprintf("D2 header init\n");
    fmem.dmap_header_initialized = 1;
    fmem.dmapheader.levelscripts = dungeon2_lscr;
    fmem.dmapheader.connections = &dungeon2_connections;
    fmem.dmapheader.music = 0x14b;
    fmem.dmapheader.map_namespace = mapheader_virtual.map_namespace;
    fmem.dmapheader.flash_type = 0;
    fmem.dmapheader.weather = MAP_WEATHER_INSIDE;
    fmem.dmapheader.type = MAP_TYPE_INSIDE;
    fmem.dmapheader.show_name = 0;
    fmem.dmapheader.battle_style = 0;
    fmem.dmapheader.events = dungeon2_init_events_forest(dg2);
    return &(fmem.dmapheader);
}

map_footer_t *dungeon2_init_footer_forest(dungeon_generator2 *dg2){
    dprintf("D2 footer init\n");
    fmem.dmapfooter.width = (u32)dg2->width;
    fmem.dmapfooter.height = (u32)dg2->height;
    fmem.dmapfooter.tileset1 = &maptileset0;
    fmem.dmapfooter.tileset2 = &maptileset_dungeon_forest;
    fmem.dmapfooter.border_blocks = dungeon2_forest_borders;
    fmem.dmapfooter.border_width = 2;
    fmem.dmapfooter.border_height = 2;
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
};

u16 dungeon_forest_eggs[] = {
    POKEMON_TOGEPI, POKEMON_MAEHIKEL, POKEMON_PIKACHU, POKEMON_FLABEBE, POKEMON_MYRAPLA, POKEMON_WATTZAPF,
    POKEMON_TRAUMATO, POKEMON_KANGAMA, POKEMON_PINSIR, POKEMON_SICHLOR,
    POKEMON_MOBAI, POKEMON_TANNZA, POKEMON_TEDDIURSA, POKEMON_MAMPFAXO, POKEMON_SAMURZEL,
    POKEMON_KNILZ, POKEMON_BUMMELZ, POKEMON_VIPITIS, POKEMON_SENGO, 0xFFFF,
};

map_event_header_t *dungeon2_init_events_forest(dungeon_generator2 *dg2){
    dungeon2_initialize_std_events(dg2, dungeon_forest_pick_item);
    u8 num_persons = fmem.dmapevents.person_cnt;
    int nodes[dg2->nodes][2];
    dungeon2_get_nodes(nodes, dg2->nodes, dg2, false);
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);
    switch (dungeon2_get_forest_type(dg2)) {
        case DUNGEON_FOREST_TYPE_APPLE_FOREST: { // Place up to 4 apples
            for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns); j++) {
                for (int i = 0; i < 4 && num_persons < ARRAY_COUNT(fmem.dpersons); i++) {
                    if (dungeon2_rnd_16(dg2) % 2) {
                        fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
                        fmem.dpersons[num_persons].overworld_index = 184;
                        fmem.dpersons[num_persons].script_std = PERSON_ITEM;
                        fmem.dpersons[num_persons].value = (dungeon2_rnd_16(dg2) % 8) > 0 ? ITEM_APFEL : ITEM_RIESENAPFEL;
                        fmem.dpersons[num_persons].flag = (u16)(DG2_FLAG_PATTERN + 4 * j + i);
                        fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0] + dungeon_forest_apple_displacements[i][0]);
                        fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] + dungeon_forest_apple_displacements[i][1]);
                        num_persons++;
                    }
                }
            }
            break;
        }
        case DUNGEON_FOREST_TYPE_BERRY_FOREST: {
            gp_rng_seed(cmem.dg2.seed);
            for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns); j++) {
                for (int i = 0; i < 3 && num_persons < ARRAY_COUNT(fmem.dpersons); i++) {
                    fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
                    fmem.dpersons[num_persons].overworld_index = OVERWORLD_SPRITE_BERRY;
                    fmem.dpersons[num_persons].script_std = PERSON_STATIC_BERRY_TREE;
                    u16 item = (u16)BERRY_IDX_TO_ITEM_IDX(choice(dungeon_forest_berries, ARRAY_COUNT(dungeon_forest_berries), gp_rnd16));
                    berry *b = berry_get((u8)ITEM_IDX_TO_BERRY_IDX(item));
                    fmem.dpersons[num_persons].value = item;
                    fmem.dpersons[num_persons].argument = b->min_yield;
                    fmem.dpersons[num_persons].flag = (u16)(DG2_FLAG_PATTERN + 3 * j + i);
                    fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0] + i - 1);
                    fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] - 1);
                    num_persons++;
                }
            }
            break;
        }
        case DUNGEON_FOREST_TYPE_EGG_FOREST: {
            gp_rng_seed(cmem.dg2.seed);
            for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns); j++) {
                fmem.dpersons[num_persons].target_index = (u8)(num_persons + 1);
                fmem.dpersons[num_persons].overworld_index = 101;
                fmem.dpersons[num_persons].script_std = PERSON_EGG;
                fmem.dpersons[num_persons].value = dungeon_forest_eggs[dungeon2_rnd_16(dg2) % (ARRAY_COUNT(dungeon_forest_eggs) - 1)];
                fmem.dpersons[num_persons].flag = (u16)(DG2_FLAG_PATTERN + j);
                fmem.dpersons[num_persons].x = (s16)(nodes[DG2_NODE_PATTERN + j][0]);
                fmem.dpersons[num_persons].y = (s16)(nodes[DG2_NODE_PATTERN + j][1] - 1);
                num_persons++;
            }
            break;
        }
    }
    fmem.dmapevents.person_cnt = num_persons;
    return &(fmem.dmapevents);
}

#define DG2_2x2_TREE 16

static u16 dungeon2_forest_branches[] = {0xa, 0xb};
static u16 dungeon2_forest_decoratives[] = {0x18, 0x20, 0x28, 0x19, 0x21, 0x29};
static u16 dungeon2_forest_tiny_grasses[] = {0x8, 0x9, 0xc};

static inline u16 dungeon2_compute_space_block_forest(u8 *map, u8 *over, int x, int y, dungeon_generator2 *dg2) {
    bool tree_2x2_below = (y == dg2->height - 1) || map[(y + 1) * dg2->width + x] == DG2_2x2_TREE;
    bool tree_1x1_below = (y != dg2->height - 1) && map[(y + 1) * dg2->width + x] == DG2_WALL;
    if (tree_2x2_below) {
        if (over[y * dg2->width + x] == DG2_SPACE) {
            return (u16)(0x1A + (x % 2));
        } else {
            return (u16)(0x1E + (x % 2));
        }
    } else if (tree_1x1_below) {
        if (over[y * dg2->width + x] == DG2_SPACE) {
            return 0x5C;
        } else {
            return 0x5F;
        }
    } else {
        if (over[y * dg2->width + x] == DG2_SPACE) 
            return 0x10; //High grass
        else {
            //Count grass, wall neighbours
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
                return 0x11; //Cut grass
            } else if (wall_neighbours >= 2 && (dungeon2_rnd_16(dg2) % 100) < 35) {
                return dungeon2_forest_branches[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_forest_branches)];
            } else if (dungeon2_rnd_16(dg2) < wall_neighbours * 0x1000) {
                return dungeon2_forest_decoratives[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_forest_decoratives)];
            } else if (dungeon2_rnd_16(dg2) < 0x1000) {
                return dungeon2_forest_tiny_grasses[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_forest_tiny_grasses)];
            } else {
                return 1;
            }
        }
    }
}

static inline u16 dungeon2_compute_2x2_tree_block_forest(u8 *map, u8 *over, int x, int y, dungeon_generator2 *dg2) {
    (void) over;
    // bool tree_2x2_above = (y == 0) || map[(y - 1) * dg2->width + x] == DG2_2x2_TREE;
    bool tree_2x2_below = (y == dg2->height - 1) || map[(y + 1) * dg2->width + x] == DG2_2x2_TREE;
    // bool tree_1x1_above = (y != 0) && map[(y - 1) * dg2->width + x] == DG2_WALL;
    bool tree_1x1_below = (y != dg2->height - 1) && map[(y + 1) * dg2->width + x] == DG2_WALL;
    switch (dungeon2_get_forest_type(dg2)) {
        case DUNGEON_FOREST_TYPE_APPLE_FOREST: {
            if (y % 2) {
                if (tree_2x2_below)
                    return (u16)((0x2C + (x % 2)) | BLOCK_SOLID);
                else if (tree_1x1_below)
                    return (u16)((0x64 + (x % 2)) | BLOCK_SOLID);
                else
                    return (u16)((0x2E + (x % 2)) | BLOCK_SOLID);
            } else {
                if (dungeon2_rnd_16(dg2) % 10 == 0) {
                    return (u16)((0x285 + (8 * (dungeon2_rnd_16(dg2) % 4)) + (x % 2)) | BLOCK_SOLID);
                } else {
                    return (u16)((0x26 + (x % 2)) | BLOCK_SOLID);
                }
            }
            break;
        }
        case DUNGEON_FOREST_TYPE_BERRY_FOREST: {
            if (y % 2) {
                if (tree_2x2_below)
                    return (u16)((0x2C + (x % 2)) | BLOCK_SOLID);
                else if (tree_1x1_below)
                    return (u16)((0x64 + (x % 2)) | BLOCK_SOLID);
                else
                    return (u16)((0x2E + (x % 2)) | BLOCK_SOLID);
            } else {
                if (dungeon2_rnd_16(dg2) % 10 == 0) {
                    return (u16)((0x2a8 + (8 * (dungeon2_rnd_16(dg2) % 4)) + (x % 2)) | BLOCK_SOLID);
                } else {
                    return (u16)((0x26 + (x % 2)) | BLOCK_SOLID);
                }
            }
            break;
        }
        case DUNGEON_FOREST_TYPE_EGG_FOREST: {
            if (y % 2) {
                if (tree_2x2_below)
                    return (u16)((0x2C + (x % 2)) | BLOCK_SOLID);
                else if (tree_1x1_below)
                    return (u16)((0x64 + (x % 2)) | BLOCK_SOLID);
                else
                    return (u16)((0x2E + (x % 2)) | BLOCK_SOLID);
            } else {
                if (dungeon2_rnd_16(dg2) % 32 == 0) {
                    return (u16)((0x2a4 + (8 * (dungeon2_rnd_16(dg2) % 2)) + (x % 2)) | BLOCK_SOLID);
                } else {
                    return (u16)((0x26 + (x % 2)) | BLOCK_SOLID);
                }
            }
            break;
        }
        default: {
            if (y % 2) {
                if (tree_2x2_below)
                    return (u16)((0x2C + (x % 2)) | BLOCK_SOLID);
                else if (tree_1x1_below)
                    return (u16)((0x64 + (x % 2)) | BLOCK_SOLID);
                else
                    return (u16)((0x2E + (x % 2)) | BLOCK_SOLID);
            } else {
                return (u16)((0x26 + (x % 2)) | BLOCK_SOLID);
            }
            break;
        }
    }
}

static inline u16 dungeon2_compute_1x1_tree_block_forest(u8 *map, u8 *over, int x, int y, dungeon_generator2 *dg2) {
    (void) over;
    bool tree_2x2_below = (y == dg2->height - 1) || map[(y + 1) * dg2->width + x] == DG2_2x2_TREE;
    bool tree_1x1_below = (y != dg2->height - 1) && map[(y + 1) * dg2->width + x] == DG2_WALL;

    switch (dungeon2_get_forest_type(dg2)) {
        case DUNGEON_FOREST_TYPE_BERRY_FOREST: {
            if (tree_2x2_below) {
                return (u16)((0x24 + (x % 2)) | BLOCK_SOLID);
            } else if (tree_1x1_below) {
                return 0x5E | BLOCK_SOLID;
            } else {
                if (dungeon2_rnd_16(dg2) % 2 == 0)
                    return (u16)((0x2aa + 8 * (dungeon2_rnd_16(dg2) % 4) + (dungeon2_rnd_16(dg2) % 2)) | BLOCK_SOLID);
                else
                    return 0x67 | BLOCK_SOLID;
            }
        }
        default: {
            if (tree_2x2_below) {
                return (u16)((0x24 + (x % 2)) | BLOCK_SOLID);
            } else if (tree_1x1_below) {
                return 0x5E | BLOCK_SOLID;
            } else {
                return 0x67 | BLOCK_SOLID;
            }
        }
    }
    
}

void dungeon2_compute_blocks_forest(u8 *map, u8 *over, dungeon_generator2 *dg2){
    int nodes[dg2->nodes][2];
    dungeon2_get_nodes(nodes, dg2->nodes, dg2, false);
    map_footer_t *pattern = dungeon2_get_forest_type_pattern(dg2);
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);
    for (int j = 0; j < MIN(DG2_MAX_NUM_PATTERNS, num_patterns); j++) {
        int w = (int)pattern->width;
        int h = (int)pattern->height;
        int x = nodes[DG2_NODE_PATTERN + j][0] - (w / 2);
        int y = nodes[DG2_NODE_PATTERN + j][1] - (h / 2);
        switch (dungeon2_get_forest_type(dg2)) {
            case DUNGEON_FOREST_TYPE_APPLE_FOREST: {
                dungeon2_fill_rectangle(map, x, y, w, h, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x - 1, y, 1, h, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x + w, y, 1, h, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x, y - 1, w, 1, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x, y + h, w, 1, DG2_SPACE, dg2);
                break;
            }
            case DUNGEON_FOREST_TYPE_BERRY_FOREST: {
                dungeon2_fill_rectangle(map, x, y, w, h, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x - 1, y, 1, h, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x + w, y, 1, h, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x, y - 1, w, 1, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x, y + h, w, 1, DG2_SPACE, dg2);
                // The three tiles above a berry tree should be solid...
                dungeon2_fill_rectangle(map, x + 1, y - 1, 3, 1, DG2_WALL, dg2);
                break;
            }
            case DUNGEON_FOREST_TYPE_EGG_FOREST: {
                dungeon2_fill_rectangle(map, x, y, w, h, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x - 1, y, 1, h, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x + w, y, 1, h, DG2_SPACE, dg2);
                dungeon2_fill_rectangle(map, x, y + h, w, 1, DG2_SPACE, dg2);
                break;
            }
        }
    }
    // First we identify all the 2x2 trees
    for (int y = 0; y < dg2->height - 1; y += 2) {
        for (int x = 0; x < dg2->width - 1; x += 2) {
            // Always compute 2x2 patches for tree placement
            if (map[y * dg2->width + x] == DG2_WALL && map[y * dg2->width + x + 1] == DG2_WALL &&
                map[(y + 1) * dg2->width + x] == DG2_WALL && map[(y + 1) * dg2->width + x + 1] == DG2_WALL) {
                map[y * dg2->width + x] = DG2_2x2_TREE;
                map[y * dg2->width + x + 1] = DG2_2x2_TREE;
                map[(y + 1) * dg2->width + x] = DG2_2x2_TREE;
                map[(y + 1) * dg2->width + x + 1] = DG2_2x2_TREE;
            }
        }
    }
    for (int y = 0; y < dg2->height; y++) {
        for (int x = 0; x < dg2->width; x++) {
            int type = map[y * dg2->width + x];
            u16 block = 0;
            if (type == DG2_SPACE)
                block = dungeon2_compute_space_block_forest(map, over, x, y, dg2);
            else if (type == DG2_2x2_TREE)
                block = dungeon2_compute_2x2_tree_block_forest(map, over, x, y, dg2);
            else if (type == DG2_WALL)
                block = dungeon2_compute_1x1_tree_block_forest(map, over, x, y, dg2);
            block_set_by_pos((s16)(x + 7), (s16)(y + 7), block);
        }
    }
    if (pattern) {
        for (int i = 0; i < MIN(num_patterns, DG2_MAX_NUM_PATTERNS); i++) {
            dungeon2_place_pattern(nodes[DG2_NODE_PATTERN + i][0], nodes[DG2_NODE_PATTERN + i][1], pattern);
        } 
    }
}

void dungeon2_compute_forest(){
    if (fmem.dmap_blocks_initialized) {
      dprintf("D2 already computed...\n");
      return;
    }
    dprintf("D2 compute...\n");

    fmem.dmap_blocks_initialized = 1;

    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_forest_init_state(dg2);

    u8 *map = dungeon2_create_connected_layout(dg2, false);
    int num_patterns = dungeon2_get_forest_num_patterns(dg2);
    int excluded_nodes_mask = 0;
    for (int i = DG2_NODE_PATTERN; i < DG2_NODE_PATTERN + num_patterns; i++)
        excluded_nodes_mask |= 1 << i;
    u8 *over = dungeon2_create_patch_layout(dg2, false, excluded_nodes_mask);
    dungeon2_compute_blocks_forest(map, over, dg2);
    free(map);
    free(over);

    mapheader_virtual.footer = &(fmem.dmapfooter);
}

void dungeon2_forest_init_state(dungeon_generator2 *dg2) {
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
}

void dungeon2_init_forest(){
    if (fmem.dmap_header_initialized) {
      return;
    }

    fmem.dmap_header_initialized = 1;
    dungeon2_reset_flags();

    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_forest_init_state(dg2);

    dungeon2_init_wild_pokemon_forest(dg2); // Initialize before events since persons depend
    dungeon2_init_header_forest(dg2);
    dungeon2_init_events_forest(dg2);
    dungeon2_init_footer_forest(dg2);
}

void dungeon2_enter_forest() {
  // Get the warp node (first node in the forest)
  dungeon_generator2 *dg2 = &(cmem.dg2);
  dungeon2_forest_init_state(dg2);
  int nodes[dg2->nodes][2];
  dungeon2_get_nodes(nodes, dg2->nodes, dg2, false);
  s16 x = (s16)(nodes[0][0]);
  s16 y = (s16)(nodes[0][1]); 


  warp_setup(DG2_BANK, DG2_MAP, 0xFF, x, y);
  warp_update_last_outdoor_map(save1->x_cam_orig, save1->y_cam_orig);
  warp_last_map_set(0, save1->bank, save1->map, 0xFF, (s16)(save1->x_cam_orig - 7),
		  (s16)(save1->y_cam_orig - 7));
  warp_setup_callbacks();
  warp_enable_flags();

  // Setup warpback
  player_get_coordinates(&(dg2->previous_position.x), &(dg2->previous_position.y));
  dg2->previous_position.x = (s16)(dg2->previous_position.x - 7);
  dg2->previous_position.y = (s16)(dg2->previous_position.y - 7);
  dg2->previous_bank = save1->bank;
  dg2->previous_map = save1->map;
  dprintf("Saved player @ (%d, %d) on %d.%d\n", dg2->previous_position.x, dg2->previous_position.y,
      dg2->previous_bank, dg2->previous_map);

  transparency_off();

}
