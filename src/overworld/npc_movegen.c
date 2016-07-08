/* 
 * File:   npc_movegen.c
 * Author: Domi
 *
 * Created on 6. Juli 2016, 22:46
 */
#include "types.h"
#include "stdbool.h"
#include "utils.h"
#include "npc.h"
#include "save.h"
#include "romfuncs.h"
#include "overworld.h"
#include "callbacks.h"

void special_move_npc_to_player(){
    s16 pos[2];
    get_current_tile_position(&pos[0], &pos[1]);
    u8 target = (u8)*vardecrypt(0x8004);
    move_npc_to(target, (bool)vardecrypt(0x8005), pos[0], pos[1]);
}

void move_npc_to(u8 ow_id, bool horizontal_first, s16 dest_x, s16 dest_y){
    
    u8 npc_id;
    if (get_npc_id_by_overworld(ow_id, (*save1)->map, (*save1)->bank, &npc_id))
        return;
    
    s16 x_from = npcs[npc_id].dest_x;
    s16 y_from = npcs[npc_id].dest_y;
    
    int total_tiles = abs(dest_x-x_from) + abs(dest_y-y_from);
    u8 *dyn_move = (u8*)malloc(total_tiles + 1); //dynamic space for movement list
    
    
    //Now we generate a move list
    int processed = 0;
    processed += move_npc_to_player_movegen(horizontal_first ? x_from : y_from, horizontal_first ? dest_x : dest_y, dyn_move, horizontal_first, processed);
    processed += move_npc_to_player_movegen(horizontal_first ? y_from : x_from, horizontal_first ? dest_y : dest_x, dyn_move, !horizontal_first, processed);
    dyn_move[processed] = 0xFE; //end if movements
    
    npc_applymovement(ow_id, (*save1)->map, (*save1)->bank, dyn_move);
    /*
    u8 cb = spawn_big_callback(move_npc_to_player_free_callback, 10);
    big_callback_set_int(cb, 0, (int)dyn_move);
    big_callbacks[cb].params[2] = ow_id;
    big_callbacks[cb].params[3] = (u16)dest_x;
    big_callbacks[cb].params[4] = (u16)dest_y;
     */
    
    *((u16*)0x20370B0) = ow_id;
}

int move_npc_to_player_movegen(s16 from, s16 to, u8 *tar, bool horizontal, int start_at){
    int processed = 0;
    while(from != to){
        u8 move;
        if (from < to){
            move = horizontal ? 0x13 : 0x10;
            from++;
        }else{
            move = horizontal ? 0x12 : 0x11;
            from--;
        }
        tar[start_at+processed] = move;
        processed++;
    }
    return processed;
}

void move_npc_to_player_free_callback(u8 self){
    big_callbacks[self].params[5]++;
    u8 npc_id;
    if (get_npc_id_by_overworld((u8)big_callbacks[self].params[2], (*save1)->map, (*save1)->bank, &npc_id))
        return;
    
    if (npcs[npc_id].dest_x == (s16)(big_callbacks[self].params[3]) &&
            npcs[npc_id].dest_y == (s16)(big_callbacks[self].params[4])){
        //free((void*)big_callback_get_int(self, 0));
        remove_big_callback(self);
    }
}

