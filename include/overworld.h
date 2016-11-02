/* 
 * File:   overworld.h
 * Author: Domi
 *
 * Created on 6. Juli 2016, 22:47
 */

#ifndef OVERWORLD_H
#define	OVERWORLD_H

void move_npc_to(u8 ow_id, s16 dest_x, s16 dest_y);

void move_npc_to_player_free_callback(u8 self);

void special_move_npc_to_player();

void special_move_npc_to();



#endif	/* OVERWORLD_H */

