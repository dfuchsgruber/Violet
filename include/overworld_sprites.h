/* 
 * File:   overworld_sprites.h
 * Author: Domi
 *
 * Created on 16. Juni 2016, 11:14
 */

#ifndef OVERWORLD_SPRITES_H
#define	OVERWORLD_SPRITES_H


#include "types.h"
#include "oams.h"
    

//We define the constant offsets for things we know
#define OW_ANIM_STANDARD_NPC (void*)0x083A322C

#define OW_FORMATION_16_32 (void*)0x083A3660
#define OW_FORMATION_128_64 (void*)0x083A3914
#define OW_FORMATION_32_32 (void*)0x083A36B4

#define OW_FINAL_OAM_16_32 (sprite*)0x083A35D4
#define OW_FINAL_OAM_128_64 (sprite*)0x083A35A4
#define OW_FINAL_OAM_32_32 (sprite*)0x083A35DC

typedef struct overworld_sprite{
    
    u16 tiles_tag; //Tiles tag
    u16 pal_tag; //0x1100 + PalID
    u16 unkown; //usually 0x11FF
    u16 size; //in bytes, e.g. for 32x16 := 0x100
    u16 width;
    u16 height;
    u8 mirror_pal;
    u8 field_D;
    u8 field_E;
    u8 field_F;
    sprite *final_oam; //NSE := Pointer 1
    void *formation; //NSE := Pointer 2
    void *animation; //NSE := Anim Pointer
    graphic *graphics; //NSE := equals Pointer 3
    rotscale_frame **rotscales; //No NSE equal
    
    
    
    //TODO
    
}overworld_sprite;
    
 

#endif	/* OVERWORLD_SPRITES_H */

