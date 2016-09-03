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

npc *npcs = (npc*)0x02036E38;
u8 *player_npc = (u8*)0x02037078;

u8 npc_is_tile_blocked(npc *n, s16 x, s16 y, u8 direction);
u8 npc_sees_player(npc *n);

#endif	/* NPC_H */

