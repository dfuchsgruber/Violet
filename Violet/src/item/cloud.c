#include "constants/flags.h"
#include "constants/map_types.h"
#include "debug.h"
#include "flags.h"
#include "map/header.h"
#include "overworld/npc.h"
#include "types.h"

void cloud_force() {
    if ((player_state.state & 1) && cloud_not_dismountable()) {
        npc_player_set_bike_state(2);
        dprintf("Forced to bike.\n");
    }
}

bool map_is_cloud() {
    return mapheader_virtual.type == MAP_TYPE_CLOUD;
}
