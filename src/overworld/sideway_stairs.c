#include "types.h"
#include "npc.h"
#include "romfuncs.h"
#include "overworld.h"
#include "tile.h"
#include "superstate.h"

/**
 * This enables sideway stairs: The following patterns show how the behaviorbytes must be alinged
 * 
 * Pattern A: Northwest / Southeast
 * 
 * [  ][\ ][  ]
 * [  ][||][  ]        
 * [  ][||][  ]
 * [  ][\ ][  ]
 * 
 * Behaviorbyte arrangement: ([ ] is dont care, x means the block should be solid)
 * 
 * [  ][xA][  ]
 * [  ][A ][  ]
 * [  ][A ][  ]
 * [  ][xA][  ]
 * 
 * The paths to walk over this stair is
 * 
 * [  ][  ][  ]
 * [ 2][ 2][  ]
 * [ 1][ 1][ 2]
 * [  ][  ][ 1]
 * 
 * Pattern B: Southwest / Northeast
 *  * [  ][ /][  ]
 * [  ][||][  ]        
 * [  ][||][  ]
 * [  ][ /][  ]
 * 
 * Dehaviorbyte arrangement: ([ ] is dont care, x means the block should be solid)
 * 
 * [  ][ B][  ]
 * [  ][xB][  ]
 * [  ][xB][  ]
 * [  ][ B][  ]
 * 
 * The paths to walk over this stair is
 * 
 * [  ][  ][  ]
 * [  ][ 2][ 2]
 * [ 2][ 1][ 1]
 * [ 1][  ][  ]
 
 **/

bool npc_side_stairway_init_if_possible(u8 diag) {
    if (diag >= 0x80) {
        u8 movements[4] = {0xAA, 0xAB, 0xAC, 0xAD};
        //TODO running shoes
        player_npc_set_state_and_behavior_tile_anim(movements[diag - 0x80], 2);
        return true;
    }
    return false;
}

/**
 * This function is crucial. It checks if the walking onto the tile would enable a diagonal move
 * @param n
 * @param x_to_origin
 * @param y_to_origin
 * @param direction
 * @param behaviour
 * @return the diagonal move to do (0 if none)
 */
u8 npc_is_tile_diag_enabling(npc *n, s16 x_to_origin, s16 y_to_origin, u8 direction, u8 role_to) {

    //first we create a dummy npc we can mess with
    npc ncpy;

    u16 role_current = get_block_info_behaviour(n->from_x, n->from_y);
    u8 result = npc_is_tile_blocked(n, x_to_origin, y_to_origin, direction);

    if (direction == 3) { //direction left
        if (role_current == BEHAVIOR_SIDE_STAIR_EAST) { //Southwest descending check
            //In order to check for southwest descend we have to move the ncpy one step down (y++)
            memcpy(&ncpy, n, sizeof (npc));
            ncpy.from_y++;
            ncpy.dest_y++;
            result = npc_is_tile_blocked(&ncpy, x_to_origin, (s16) (y_to_origin + 1), direction);
            if (!result) {
                result = DIAG_SW;
            }

        } else if (role_to == BEHAVIOR_SIDE_STAIR_WEST) { //Northwest ascending check
            if (get_block_info_behaviour(x_to_origin, (s16) (y_to_origin - 1)) != BEHAVIOR_SIDE_STAIR_WEST) {
                return 3;
            } else {
                //In order to check for northwest ascend we have to move the ncpy one step up (y--)
                memcpy(&ncpy, n, sizeof (npc));
                ncpy.from_y--;
                ncpy.dest_y--;
                result = npc_is_tile_blocked(&ncpy, x_to_origin, (s16) (y_to_origin - 1), direction);
                if (!result) {
                    result = DIAG_NW;
                }
            }
        }

    } else if (direction == 4) {//direction right
        if (role_current == BEHAVIOR_SIDE_STAIR_WEST) { //Southwest descending check
            //In order to check for southwest descend we have to move the ncpy one step down (y++)
            memcpy(&ncpy, n, sizeof (npc));
            ncpy.from_y++;
            ncpy.dest_y++;
            result = npc_is_tile_blocked(&ncpy, x_to_origin, (s16) (y_to_origin + 1), direction);
            if (!result) {
                result = DIAG_SO;
            }

        } else if (role_to == BEHAVIOR_SIDE_STAIR_EAST) { //Northwest ascending check
            if (get_block_info_behaviour(x_to_origin, (s16) (y_to_origin - 1)) != BEHAVIOR_SIDE_STAIR_EAST) {
                return 3;
            } else {
                //In order to check for northwest ascend we have to move the ncpy one step up (y--)
                memcpy(&ncpy, n, sizeof (npc));
                ncpy.from_y--;
                ncpy.dest_y--;
                result = npc_is_tile_blocked(&ncpy, x_to_origin, (s16) (y_to_origin - 1), direction);
                if (!result) {
                    result = DIAG_NO;
                }
            }
        }
    }


    return result;
}