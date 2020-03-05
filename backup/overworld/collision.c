#include "types.h"
#include "overworld/npc.h"
#include "tile/block.h"
#include "tile/coordinate.h"
#include "tile/diagonal_stair.h"
#include "superstate.h"
#include "agbmemory.h"
#include "constants/sav_keys.h"
#include "constants/overworld/overworld_collisions.h"
#include "save.h"

int npc_player_attempt_step(npc *player, s16 x, s16 y, u8 direction, int param_5) {
    (void) param_5; // unused in fire red
    int collision = npc_attempt_diagonal_move(player, x, y, direction);
    if (collision == COLLISION_HEIGHT_MISMATCH && npc_player_attempt_transition_water_to_land(x, y, direction)) {
        return COLLISION_STOP_SURFING;
    }
    if (block_ledge_triggered(x, y, direction)) {
        // Check if the block "after" the ledge yields no collision on its own
        npc dummy = *player;
        coordinates_apply_direction(direction, &dummy.dest_x, &dummy.dest_y);
        coordinates_apply_direction(direction, &dummy.from_x, &dummy.from_y);
        coordinates_apply_direction(direction, &x, &y);
        collision = npc_get_collision(&dummy, x, y, direction);
        if (collision == COLLISION_NONE) {
            save_increment_key(SAV_KEY_LEDGES_JUMPED);
            return COLLISION_LEDGE;
        } else {
            return COLLISION_IMPASSABLE; // There are no special collision events like boulder pushing along ledges
        }
    }
    if (collision == COLLISION_OTHER_NPC && npc_is_movable_boulder_at(x, y, direction)) {
        return COLLISION_PUSHED_BOULDER;
    }
    return collision;
}
