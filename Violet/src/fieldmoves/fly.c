#include "types.h"
#include "worldmap.h"
#include "field_move.h"

void field_move_fly_init() {
    worldmap_ui_fly_new(field_move_fly_map_reload_and_do_fly);
}