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
#include "constants/vars.h"
#include "vars.h"
#include "pokemon/basestat.h"
#include "constants/person_behaviours.h"
#include "tile/block.h"
#include "constants/map_types.h"
#include "overworld/sprite.h"

extern tileset maptileset0;
extern tileset maptileset_power_plant;

u16 dungeon2_forest_borders[4] = {0x26, 0x27, 0x2c, 0x2d};

map_block dungeon2_forest_map_empty[DG2_FOREST_WIDTH * DG2_FOREST_HEIGHT] = {0};

extern u8 ow_script_dungeon_encounter[];
extern u8 ow_script_dungeon_item[];

map_header_t *dungeon2_init_header_forest(dungeon_generator2 *dg2) {

    //save1->flash_circle_size = 1;
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
    fmem.dmapfooter.tileset2 = &maptileset_power_plant;
    fmem.dmapfooter.border_blocks = dungeon2_forest_borders;
    fmem.dmapfooter.border_width = 2;
    fmem.dmapfooter.border_height = 2;
    fmem.dmapfooter.map = dungeon2_forest_map_empty;
    return &(fmem.dmapfooter);
}

extern u8 ow_script_dungeon_trainer_0[];
extern u8 ow_script_dungeon_trainer_1[];
extern u8 ow_script_dungeon_trainer_2[];
extern u8 ow_script_dungeon_trainer_3[];

static u8 *dungeon2_trainer_scripts[4] = {
    ow_script_dungeon_trainer_0, ow_script_dungeon_trainer_1, ow_script_dungeon_trainer_2, ow_script_dungeon_trainer_3
};

map_event_header_t *dungeon2_init_events_forest(dungeon_generator2 *dg2){
    dprintf("D2 event init, dg2 seed %d, num nodes %d\n", dg2->initial_seed, dg2->nodes);

    fmem.dmapevents.person_cnt = (u8)(dg2->nodes - 1);
    fmem.dmapevents.warp_cnt = 0;
    fmem.dmapevents.script_cnt = 0;
    fmem.dmapevents.signpost_cnt = 0;
    fmem.dmapevents.persons = fmem.dpersons;

    // Get the nodes of the dungeon
    int nodes[dg2->nodes][2];
    dungeon2_get_nodes(nodes, dg2->nodes, dg2, false);

    int zero = 0;

    // Place the super rare pokemon at the second node
    cpuset(&zero, &(fmem.dpersons[0]), CPUSET_FILL | CPUSET_HALFWORD |
        CPUSET_HALFWORD_SIZE(sizeof(map_event_person)));
    fmem.dpersons[0].x = (s16)(nodes[1][0]);
    fmem.dpersons[0].y = (s16)(nodes[1][1]);
    u16 species = *var_access(DUNGEON_OVERWORLD_SPECIES);
    fmem.dpersons[0].overworld_index = overworld_get_sprite_idx_by_species(species);
    fmem.dpersons[0].value = species;
    fmem.dpersons[0].behavior = BEHAVIOUR_WANDER_AROUND;
    fmem.dpersons[0].target_index = 1;
    fmem.dpersons[0].script = ow_script_dungeon_encounter;
    fmem.dpersons[0].flag = 0x12;

    // Determine how many items / trainers there will be
    int num_events = MIN(DMAP_PERSONS - 1, (dungeon2_rnd_16(dg2) % (dg2->nodes - 2)) + 1); // First two nodes are entry / overworld-mon
    int num_trainers = 0;

    for (int i = 0; i < num_events; i++) {
      int person_idx = i + 1;
      int node_idx = i + 2;
      cpuset(&zero, &(fmem.dpersons[person_idx]), CPUSET_FILL | CPUSET_HALFWORD |
          CPUSET_HALFWORD_SIZE(sizeof(map_event_person)));
        fmem.dpersons[person_idx].x = (s16)(nodes[node_idx][0]);
        fmem.dpersons[person_idx].y = (s16)(nodes[node_idx][1]);
        fmem.dpersons[person_idx].target_index = (u8)(person_idx + 1);
        if (num_trainers < 4 && ((dungeon2_rnd_16(dg2) % 4) == 0)) {
            fmem.dpersons[person_idx].overworld_index = (u8)(41 + (num_trainers & 1));
            fmem.dpersons[person_idx].trainer_type_and_strength_flag = 1;
            fmem.dpersons[person_idx].alert_radius = 4;
            fmem.dpersons[person_idx].script = dungeon2_trainer_scripts[num_trainers];
            fmem.dpersons[person_idx].behavior = BEHAVIOUR_LOOK_AROUND;
            dprintf("Dynamic trainer %d has picture idx %d\n", num_trainers, fmem.dpersons[person_idx].overworld_index);
            num_trainers++;
        } else {
            fmem.dpersons[person_idx].overworld_index = 92;
            fmem.dpersons[person_idx].flag = (u16)(0x13 + i);
            fmem.dpersons[person_idx].value = dungeon_forest_pick_item(dg2);
            fmem.dpersons[person_idx].script = ow_script_dungeon_item;
        }
    }
    fmem.dmapevents.person_cnt = (u8)(1 + num_events);
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
}

static inline u16 dungeon2_compute_1x1_tree_block_forest(u8 *map, u8 *over, int x, int y, dungeon_generator2 *dg2) {
    (void) over;
    bool tree_2x2_below = (y == dg2->height - 1) || map[(y + 1) * dg2->width + x] == DG2_2x2_TREE;
    bool tree_1x1_below = (y != dg2->height - 1) && map[(y + 1) * dg2->width + x] == DG2_WALL;
    if (tree_2x2_below) {
        return (u16)((0x24 + (x % 2)) | BLOCK_SOLID);
    } else if (tree_1x1_below) {
        return 0x5E | BLOCK_SOLID;
    } else {
        return 0x67 | BLOCK_SOLID;
    }
}

void dungeon2_compute_blocks_forest(u8 *map, u8 *over, dungeon_generator2 *dg2){
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

    u8 *over = dungeon2_create_patch_layout(dg2, false);
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
      dprintf("D2 header already initialized...\n");
      return;
    }

    fmem.dmap_header_initialized = 1;

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
