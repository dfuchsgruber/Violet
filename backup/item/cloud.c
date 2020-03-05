#include "types.h"
#include "overworld/npc.h"
#include "flags.h"
#include "constants/flags.h"
#include "map/header.h"
#include "constants/map_types.h"

void cloud_force() {
    if (player_state.state & 1)
        npc_player_set_bike_state(2);
}

bool map_is_cloud(){
	return mapheader_virtual.type == MAP_TYPE_CLOUD;
}
