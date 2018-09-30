/*
 * cave.c
 *
 *  Created on: Jun 3, 2018
 *      Author: dominik
 */

#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon/dungeon2.h"
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
#include "constants/vars.h"
#include "vars.h"
#include "pokemon/basestat.h"
#include "constants/person_behaviours.h"
#include "tile/block.h"
#include "data_structures.h"
#include "constants/map_types.h"

extern tileset maptileset0;
extern tileset maptileset15;

u16 dungeon2_cave_borders[4] = {0x291, 0x291, 0x291, 0x291};

map_block dungeon2_cave_map_empty[DG2_CAVE_WIDTH * DG2_CAVE_HEIGHT] = {0};

extern u8 ow_script_dungeon_encounter[];
extern u8 ow_script_dungeon_item[];

mapheader *dungeon2_init_header_cave(dungeon_generator2 *dg2) {

    //save1->flash_circle_size = 1;
    dprintf("D2 header init\n");
    fmem.dmap_header_initialized = 1;
    fmem.dmapheader.levelscripts = dungeon2_lscr;
    fmem.dmapheader.connections = &dungeon2_connections;
    fmem.dmapheader.music = 0x14b;
    fmem.dmapheader.map_index = 0x1c1; //test index
    fmem.dmapheader.flash = 0;
    fmem.dmapheader.weather = MAP_WEATHER_INSIDE;
    fmem.dmapheader.type = MAP_TYPE_INSIDE;
    fmem.dmapheader.show_name = 0;
    fmem.dmapheader.battle_style = 0;
    fmem.dmapheader.events = dungeon2_init_events_cave(dg2);
    return &(fmem.dmapheader);
}

mapfooter *dungeon2_init_footer_cave(dungeon_generator2 *dg2){
    dprintf("D2 footer init\n");
    fmem.dmapfooter.width = (u32)dg2->width;
    fmem.dmapfooter.height = (u32)dg2->height;
    fmem.dmapfooter.tileset1 = &maptileset0;
    fmem.dmapfooter.tileset2 = &maptileset15;
    fmem.dmapfooter.border_blocks = dungeon2_cave_borders;
    fmem.dmapfooter.border_width = 2;
    fmem.dmapfooter.border_height = 2;
    fmem.dmapfooter.map = dungeon2_cave_map_empty;
    return &(fmem.dmapfooter);
}

map_events *dungeon2_init_events_cave(dungeon_generator2 *dg2){
    dprintf("D2 event init, dg2 seed %d, num nodes %d\n", dg2->initial_seed, dg2->nodes);
    (void)dg2;

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
        CPUSET_SIZE(sizeof(map_event_person) >> 2));
    fmem.dpersons[0].x = (s16)(nodes[1][0]);
    fmem.dpersons[0].y = (s16)(nodes[1][1]);
    u16 species = *var_access(DUNGEON_OVERWORLD_SPECIES);
    fmem.dpersons[0].overworld_index = (u8)(154 + basestats[species].form);
    fmem.dpersons[0].behavior = BEHAVIOUR_HERUMGEHEN;
    fmem.dpersons[0].target_index = 1;
    fmem.dpersons[0].script = ow_script_dungeon_encounter;
    fmem.dpersons[0].flag = 0x12;

    // Determine how many items there will be
    int num_items = (dungeon2_rnd_16(dg2) % (dg2->nodes - 2)) + 1;

    for (int i = 0; i < num_items; i++) {
      int person_idx = i + 1;
      int node_idx = i + 2;
      cpuset(&zero, &(fmem.dpersons[person_idx]), CPUSET_FILL | CPUSET_HALFWORD |
          CPUSET_SIZE(sizeof(map_event_person) >> 2));

      fmem.dpersons[person_idx].x = (s16)(nodes[node_idx][0]);
      fmem.dpersons[person_idx].y = (s16)(nodes[node_idx][1]);
      dprintf("Person at (%d, %d)\n", nodes[node_idx][0], nodes[node_idx][1]);
      fmem.dpersons[person_idx].target_index = (u8)(person_idx + 1);
      fmem.dpersons[person_idx].overworld_index = 92;
      fmem.dpersons[person_idx].flag = (u16)(0x13 + i);
      fmem.dpersons[person_idx].private = dungeon_cave_pick_item(dg2);
      fmem.dpersons[person_idx].script = ow_script_dungeon_item;
    }

    fmem.dmapevents.person_cnt = (u8)(1 + num_items);
    return &(fmem.dmapevents);
}


void dungeon2_compute_cave(){
    if (fmem.dmap_blocks_initialized) {
      dprintf("D2 already computed...\n");
      return;
    }
    dprintf("D2 compute...\n");

    fmem.dmap_blocks_initialized = 1;

    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_cave_init_state(dg2);

    u8 *map = dungeon2_create_connected_layout(dg2, false);

    // temporarily double the number of nodes
    dg2->nodes = (u8)(dg2->nodes * 3);
    u8 *over = dungeon2_create_connected_layout(dg2, true);
    dg2->nodes = (u8)(dg2->nodes / 3);
    dungeon2_compute_blocks_cave(map, over, dg2);
    free(map);
    free(over);

    mapheader_virtual.footer = &(fmem.dmapfooter);
}

void dungeon2_cave_init_state(dungeon_generator2 *dg2) {
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
}

void dungeon2_init_cave(){
    if (fmem.dmap_header_initialized) {
      dprintf("D2 header already initialized...\n");
      return;
    }

    fmem.dmap_header_initialized = 1;

    dungeon_generator2 *dg2 = &(cmem.dg2);
    dungeon2_cave_init_state(dg2);

    dungeon2_init_wild_pokemon_cave(dg2); // Initialize before events since persons depend
    dungeon2_init_header_cave(dg2);
    dungeon2_init_events_cave(dg2);
    dungeon2_init_footer_cave(dg2);
}


void dungeon2_enter_cave() {
  // Get the warp node (first node in the cave)
  dungeon_generator2 *dg2 = &(cmem.dg2);
  dungeon2_cave_init_state(dg2);
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
