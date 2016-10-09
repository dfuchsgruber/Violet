/* 
 * File:   npc.h
 * Author: Domi
 *
 * Created on 9. Juni 2016, 23:33
 */

#ifndef NPC_H
#define	NPC_H

#include "anim_engine.h"
#include "map.h"
#include "oams.h"

typedef struct npc{
    struct{
        u8 active : 1;
        u8 in_motion : 1;
        u8 is_obstacle : 1;
        u8 is_obstacle_2 : 1;
        u8 flag_4 : 1;
        u8 flag_5 : 1;
        u8 flag_6 : 1;
        u8 reset : 1;
    }flags;
    u8 visual_cntrl;
    u8 field_2;
    u8 field_3;
    
    u8 oam_id;
    u8 sprite;
    u8 behavior_type;
    u8 trainer_trigger;
    
    u8 overworld_id;
    u8 map;
    u8 bank;
    struct{
        u8 current : 4;
        u8 previous : 4;
    }height;
    
    s16 origin_x;
    s16 origin_y;
    
    s16 dest_x;
    s16 dest_y;
    
    s16 from_x;
    s16 from_y;
    
    struct npc_facing{
        u8 lower : 4;
        u8 higher : 4;
    }facing;
    struct rectangle{
        u8 x : 4;
        u8 y : 4;
    }rectangle;
    u8 oam_surf;
    u8 oam_bike;
    
    u8 field_1C;
    u8 sight_range;
    u8 behavior_tile_to;
    u8 behavior_tile_current;
    
    u8 field_20;
    u8 step_countdown;
    u8 field_22;
    u8 field_23;
}npc;

typedef struct{
    u8 state;
    u8 bike;
    u8 running2;
    u8 running1;
    u8 std_oam_id;
    u8 player_npc_id;
    u8 is_locked;
    u8 gender;
    u8 mode;
    u8 unkown[3];
}player_state;

npc *npcs = (npc*)0x02036E38;
player_state *pstate = (player_state*)0x02037078;

u8 npc_is_tile_blocked(npc *n, s16 x, s16 y, u8 direction);
u8 npc_sees_player(npc *n);

bool npc_anim_stop (npc *n, oam_object *target);

void npc_anim_init_walk (npc *n, oam_object *target, u8 direction, u8 unkown);
bool npc_anim_walk_is_finished (npc *n, oam_object *target);

bool npc_anim_diag_no_init(npc *n, oam_object *target);
void npc_diag_apply(npc *n, oam_object *target, u8 direction);
u8 npc_is_tile_diag_enabling(npc *n, s16 x_to_origin, s16 y_to_origin, u8 direction, u8 role_to);

#endif	/* NPC_H */

