#include "types.h"
#include "romfuncs.h"
#include "item.h"
#include "npc.h"

void cloud_force() {
    if (pstate->state & 1)
        npc_player_set_bike_state(2);
}
