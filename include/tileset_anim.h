/* 
 * File:   tileset_anim.h
 * Author: Domi
 *
 * Created on 19. September 2017, 21:09
 */

#ifndef TILESET_ANIM_H
#define	TILESET_ANIM_H

#ifdef	__cplusplus
extern "C" {
#endif


typedef struct {
    u16 cycle;
    u16 speed;
    u16 start_tile;
    u16 num_tiles;
    void *gfx;
} tileset_animation;

typedef struct {
    int cnt;
    tileset_animation *animations;
} tileset_animation_header;


u16 generic_tileset_anim_get_clk(tileset_animation_header *anim_header);

void generic_tileset_anim_proceed(tileset_animation *anim, u16 clk);

void generic_tileset_anim_proceed_all(tileset_animation_header *anim_header,
        u16 clk);

#ifdef	__cplusplus
}
#endif

#endif	/* TILESET_ANIM_H */

