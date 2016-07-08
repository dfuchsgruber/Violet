/* 
 * File:   overworld.h
 * Author: Domi
 *
 * Created on 6. Juli 2016, 22:47
 */

#ifndef OVERWORLD_H
#define	OVERWORLD_H

void move_npc_to(u8 ow_id, bool horizontal_first, s16 dest_x, s16 dest_y);

int move_npc_to_player_movegen(s16 from, s16 to, u8 *tar, bool horizontal, int start_at);

void move_npc_to_player_free_callback(u8 self);
    
void special_move_npc_to_player();

#endif	/* OVERWORLD_H */

