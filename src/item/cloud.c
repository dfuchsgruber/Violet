#include "types.h"
#include "overworld/npc.h"

void cloud_force() {
    if (player_state->state & 1)
        npc_player_set_bike_state(2);
}
