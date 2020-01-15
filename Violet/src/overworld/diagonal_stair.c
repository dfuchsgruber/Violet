#include "types.h"
#include "overworld/npc.h"
#include "tile/block.h"
#include "tile/coordinate.h"
#include "tile/diagonal_stair.h"
#include "superstate.h"
#include "agbmemory.h"
#include "constants/overworld/overworld_collisions.h"

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
 * [  ][ /][  ]
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

/**
 * This function checks if the walking onto the tile would enable a diagonal move
 * @param n
 * @param x_to_origin
 * @param y_to_origin
 * @param direction
 * @param behaviour
 * @return the diagonal move to do (0 if none)
 */
u8 npc_attempt_diagonal_move(npc *n, s16 x_to_origin, s16 y_to_origin, u8 direction) {

    //first we create a dummy npc we can mess with
    npc ncpy = *n;
    u8 role_to = (u8)block_get_behaviour_by_pos(x_to_origin, y_to_origin);

    u16 role_current = block_get_behaviour_by_pos(n->from_x, n->from_y);
    u8 result = npc_get_collision(n, x_to_origin, y_to_origin, direction);

    if (direction == 3) { //direction left
        if (role_current == BEHAVIOR_SIDE_STAIR_EAST) { //Southwest descending check
            //In order to check for southwest descend we have to move the ncpy one step down (y++)
            ncpy.from_y++;
            ncpy.dest_y++;
            result = npc_get_collision(&ncpy, x_to_origin, (s16) (y_to_origin + 1), direction);
            if (!result) {
                result = COLLISION_SIDEWAY_STAIRS;
                npc_player_set_state_and_execute_tile_anim(0xAC, 2);
            }

        } else if (role_to == BEHAVIOR_SIDE_STAIR_WEST) { //Northwest ascending check
            if (block_get_behaviour_by_pos(x_to_origin, (s16) (y_to_origin - 1)) != BEHAVIOR_SIDE_STAIR_WEST) {
                return COLLISION_HEIGHT_MISMATCH;
            } else {
                //In order to check for northwest ascend we have to move the ncpy one step up (y--)
                ncpy.from_y--;
                ncpy.dest_y--;
                result = npc_get_collision(&ncpy, x_to_origin, (s16) (y_to_origin - 1), direction);
                if (!result) {
                    result = COLLISION_SIDEWAY_STAIRS;
                    npc_player_set_state_and_execute_tile_anim(0xAD, 2);
                }
            }
        }

    } else if (direction == 4) {//direction right
        if (role_current == BEHAVIOR_SIDE_STAIR_WEST) { //Southeast descending check
            //In order to check for southwest descend we have to move the ncpy one step down (y++)
            ncpy.from_y++;
            ncpy.dest_y++;
            result = npc_get_collision(&ncpy, x_to_origin, (s16) (y_to_origin + 1), direction);
            if (!result) {
                result = COLLISION_SIDEWAY_STAIRS;
                npc_player_set_state_and_execute_tile_anim(0xAB, 2);
            }

        } else if (role_to == BEHAVIOR_SIDE_STAIR_EAST) { //Northeast ascending check
            if (block_get_behaviour_by_pos(x_to_origin, (s16) (y_to_origin - 1)) != BEHAVIOR_SIDE_STAIR_EAST) {
                return COLLISION_HEIGHT_MISMATCH;
            } else {
                //In order to check for northwest ascend we have to move the ncpy one step up (y--)
                ncpy.from_y--;
                ncpy.dest_y--;
                result = npc_get_collision(&ncpy, x_to_origin, (s16) (y_to_origin - 1), direction);
                if (!result) {
                    result = COLLISION_SIDEWAY_STAIRS;
                    npc_player_set_state_and_execute_tile_anim(0xAA, 2);
                }
            }
        }
    }


    return result;
}
