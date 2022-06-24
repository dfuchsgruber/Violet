#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon/dungeon2.h"
#include "dungeon/forest.h"
#include "dungeon/cave.h"
#include "dungeon/ocean.h"
#include "debug.h"
#include "constants/vars.h"
#include "vars.h"
#include "overworld/script.h"
#include "overworld/map_control.h"
#include "transparency.h"


extern u8 ow_script_dungeon_forest_collapsing[];
extern u8 ow_script_dungeon_cave_collapsing[];
extern u8 ow_script_dungeon_ocean_collapsing[];

bool dungeon2_step_is_collapsing(){
    u16 *steps = var_access(DUNGEON_STEPS);
    switch (dungeon_get_type()) {
      case DTYPE_FOREST: {
        if (++(*steps) >= ((DG2_FOREST_WIDTH * DG2_FOREST_HEIGHT) / 6)) {
          // Collapse
          overworld_script_init(ow_script_dungeon_forest_collapsing);
          overworld_script_set_active();
          return true;
        }
        break;
      }
      case DTYPE_CAVE: {
        if (++(*steps) >= ((DG2_CAVE_WIDTH * DG2_CAVE_HEIGHT) / 6)) {
          // Collapse
          overworld_script_init(ow_script_dungeon_cave_collapsing);
          overworld_script_set_active();
          return true;
        }
        break;
      }
      case DTYPE_OCEAN: {
          if (++(*steps) >= ((DG2_OCEAN_WIDTH * DG2_OCEAN_HEIGHT) / 6)) {
            // Collapse
            overworld_script_init(ow_script_dungeon_ocean_collapsing);
            overworld_script_set_active();
            return true;
          }
          break;

      }
    }
    return false;
}

void dungeon2_exit() {
  dungeon_generator2 *dg2 = &(cmem.dg2);
  warp_setup(dg2->previous_bank, dg2->previous_map, 0xFF, dg2->previous_position.x,
      dg2->previous_position.y);
  warp_setup_callbacks();
  warp_reset_initial_player_state();
  fmem.dmap_header_initialized = false;
  fmem.dmap_blocks_initialized = false;
  transparency_off();
}
