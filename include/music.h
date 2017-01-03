/* 
 * File:   music.h
 * Author: Domi
 *
 * Created on 9. Juni 2016, 11:57
 */

#ifndef MUSIC_H
#define	MUSIC_H


#include "types.h"
#include "anim_engine.h"

#define VAR_BATTLE_MUSIC 0x50DC
#define VAR_MAP_MUSIC_FORCE 0x50D9

#define MUS_VIOLET_ENCOUNTER 274
#define MUS_GYMLEADER_BATTLE 0x128
#define MUS_TRAINER_BATTLE 0x129
#define MUS_WILDBATTLE 0x12A
#define MUS_VIOLET_BATTLE 0x15B
#define MUS_RIVAL_BATTLE 0x15F
#define MUS_REVOLUTIONARY_BATTLE 353
#define MUS_REVOLUTIONARY_ENCOUNTER 355

u16 get_encounter_music_by_trainer_id(u16 trainer_id);
u16 battle_get_music();
u16 current_map_get_song();


#endif	/* MUSIC_H */

