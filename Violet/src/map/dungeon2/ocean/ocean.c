/*
 * ocean.c
 *
 *  Created on: Aug 20, 2018
 *      Author: dominik
 */

#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon/dungeon2.h"
#include "dungeon/ocean.h"
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
#include "overworld/sprite.h"

extern const tileset maptileset0;
extern const tileset maptileset_cave;

const u16 dungeon2_ocean_borders[4] = {0x1cd, 0x1cd, 0x1cd, 0x1cd};

const map_block dungeon2_ocean_map_empty[DG2_OCEAN_WIDTH * DG2_OCEAN_HEIGHT] = {0};

extern const u8 ow_script_dungeon_encounter[];
extern const u8 ow_script_dungeon_item[];

map_header_t *dungeon2_init_header_ocean(dungeon_generator2 *dg2) {

    //save1->flash_circle_size = 1;
    DEBUG("D2 header init\n");
    dmap_flags.header_initialized = 1;
    dynamic_map_header.levelscripts = dungeon2_lscr;
    dynamic_map_header.connections = &dungeon2_connections;
    dynamic_map_header.music = 0x14b;
    dynamic_map_header.map_namespace = mapheader_virtual.map_namespace;
    dynamic_map_header.flash_type = 0;
    dynamic_map_header.weather = MAP_WEATHER_INSIDE;
    dynamic_map_header.type = MAP_TYPE_INSIDE;
    dynamic_map_header.show_name = 0;
    dynamic_map_header.battle_style = 0;
    dynamic_map_header.events = dungeon2_init_events_ocean(dg2);
    return &(dynamic_map_header);
}

map_footer_t *dungeon2_init_footer_ocean(dungeon_generator2 *dg2){
    DEBUG("D2 footer init\n");
    dynamic_map_footer.width = (u32)dg2->width;
    dynamic_map_footer.height = (u32)dg2->height;
    dynamic_map_footer.tileset1 = &maptileset0;
    dynamic_map_footer.tileset2 = &maptileset_cave;
    dynamic_map_footer.border_blocks = dungeon2_ocean_borders;
    dynamic_map_footer.border_width = 2;
    dynamic_map_footer.border_height = 2;
    dynamic_map_footer.map = dungeon2_ocean_map_empty;
    return &(dynamic_map_footer);
}

map_event_header_t *dungeon2_init_events_ocean(dungeon_generator2 *dg2){
    DEBUG("D2 event init, dg2 seed %d, num nodes %d\n", dg2->initial_seed, dg2->nodes);
    (void)dg2;

    dynamic_map_event_header.warp_cnt = 0;
    dynamic_map_event_header.script_cnt = 0;
    dynamic_map_event_header.signpost_cnt = 0;
    dynamic_map_event_header.persons = dynamic_persons;

    // Get the nodes of the dungeon
    int nodes[dg2->nodes][2];
    dungeon2_get_nodes(nodes, dg2->nodes, dg2, false);

    int zero = 0;

    // Place the super rare pokemon at the second node
    cpuset(&zero, &(dynamic_persons[0]), CPUSET_FILL | CPUSET_HALFWORD |
        CPUSET_HALFWORD_SIZE(sizeof(map_event_person)));
    dynamic_persons[0].x = (s16)(nodes[1][0]);
    dynamic_persons[0].y = (s16)(nodes[1][1]);
    u16 species = *var_access(DUNGEON_OVERWORLD_SPECIES);
    dynamic_persons[0].overworld_index = overworld_get_sprite_idx_by_species(species);
    dynamic_persons[0].value = species;
    dynamic_persons[0].behavior = BEHAVIOUR_WANDER_AROUND;
    dynamic_persons[0].target_index = 1;
    dynamic_persons[0].script = ow_script_dungeon_encounter;
    dynamic_persons[0].flag = 0x12;
    dynamic_persons[0].level = 1; // Surf

    // Determine how many items there will be
    int num_items = (dungeon2_rnd_16(dg2) % (dg2->nodes / 1 - 2)) + 1;

    for (int i = 0; i < num_items; i++) {
      int person_idx = i + 1;
      int node_idx = i + 2;
      cpuset(&zero, &(dynamic_persons[person_idx]), CPUSET_FILL | CPUSET_HALFWORD |
          CPUSET_HALFWORD_SIZE(sizeof(map_event_person)));

      dynamic_persons[person_idx].x = (s16)(nodes[node_idx][0]);
      dynamic_persons[person_idx].y = (s16)(nodes[node_idx][1]);
      DEBUG("Person at (%d, %d)\n", nodes[node_idx][0], nodes[node_idx][1]);
      dynamic_persons[person_idx].target_index = (u8)(person_idx + 1);
      dynamic_persons[person_idx].overworld_index = 92;
      dynamic_persons[person_idx].flag = (u16)(0x13 + i);
      dynamic_persons[person_idx].value = dungeon_ocean_pick_item(dg2);
      dynamic_persons[person_idx].script = ow_script_dungeon_item;
    }

    dynamic_map_event_header.person_cnt = (u8)(1 + num_items);
    return &(dynamic_map_event_header);
}


void dungeon2_compute_ocean(){
    if (dmap_flags.blocks_initialized) {
      DEBUG("D2 already computed...\n");
      return;
    }
    DEBUG("D2 compute...\n");

    dmap_flags.blocks_initialized = 1;

    dungeon_generator2 *dg2 = &(csave.dg2);
    dungeon2_ocean_init_state(dg2);

    u8 *map = dungeon2_create_connected_layout(dg2, false);

    // Further enlarge the dungeon

    u8 *map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
    dungeon2_enlarge(map, map2, dg2);
    //dungeon2_enlarge(map2, map, dg2);


    // temporarily double the number of nodes
    // dg2->nodes = (u8)(dg2->nodes * 2);
    u8 *over = dungeon2_create_isolated_layout(dg2, 3, 3, false, 1);
    // dg2->nodes = (u8)(dg2->nodes / 2);
    dungeon2_compute_blocks_ocean(map, over, dg2);
    free(map);
    free(map2);
    free(over);

    mapheader_virtual.footer = &(dynamic_map_footer);
}

void dungeon2_ocean_init_state(dungeon_generator2 *dg2) {
  dg2->seed = dg2->initial_seed;
  dg2->width = DG2_OCEAN_WIDTH;
  dg2->height = DG2_OCEAN_HEIGHT;
  dg2->path_randomness = DG2_OCEAN_PATH_RANDOMNESS;
  dg2->init_randomness = DG2_OCEAN_INIT_RANDOMNESS;
  dg2->nodes = DG2_OCEAN_NODES;
  dg2->margin = DG2_OCEAN_MARGIN;
  dg2->node_metric_lambda_l2 = DG2_OCEAN_NODE_METRIC_LAMBDA_MEAN;
  dg2->node_metric_lambda_min = DG2_OCEAN_NODE_METRIC_LAMBDA_MIN;
  dg2->node_samples = DG2_OCEAN_NODE_SAMPLES;
}

void dungeon2_init_ocean(){
    if (dmap_flags.header_initialized) {
      DEBUG("D2 header already initialized...\n");
      return;
    }

    dmap_flags.header_initialized = 1;

    dungeon_generator2 *dg2 = &(csave.dg2);
    dungeon2_ocean_init_state(dg2);

    dungeon2_init_wild_pokemon_ocean(dg2); // Initialize before events since persons depend
    dungeon2_init_header_ocean(dg2);
    dungeon2_init_events_ocean(dg2);
    dungeon2_init_footer_ocean(dg2);
}


void dungeon2_enter_ocean() {
  // Get the warp node (first node in the ocean)
  dungeon_generator2 *dg2 = &(csave.dg2);
  // dg2->initial_seed = 521151070;
  dungeon2_ocean_init_state(dg2);
  int nodes[dg2->nodes][2];
  dungeon2_get_nodes(nodes, dg2->nodes, dg2, false);
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

  transparency_off();

}



