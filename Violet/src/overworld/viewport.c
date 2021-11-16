#include "types.h"
#include "overworld/npc.h"
#include "map/event.h"
#include "save.h"
#include "debug.h"
#include "overworld/map_control.h"
#include "vars.h"

#define BENCHMARK 0
#if BENCHMARK
    #define BENCHMARK_WRAP(x) x
#else
    #define BENCHMARK_WRAP(x) ;
#endif

void overworld_viewport_set_position(s16 x, s16 y) {
    overworld_viewport_move_and_update_all(
        (s16)(x - save1->x_cam_orig),
        (s16)(y - save1->y_cam_orig)
    );
}

void special_overworld_viewport_set_position() {
    overworld_viewport_set_position((s16)(*var_access(0x8004)), (s16)(*var_access(0x8005)));
}

void overworld_viewport_set_position_to_player() {
    npc *player = npcs + player_state.npc_idx;
    overworld_viewport_set_position((s16)(player->dest_x - 7), (s16)(player->dest_y - 7));
}
