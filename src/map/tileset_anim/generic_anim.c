#include "types.h"
#include "romfuncs.h"
#include "save.h"
#include "tileset_anim.h"
#include "map.h"
#include "debug.h"
#include "utils.h"

u16 generic_tileset_anim_get_clk(tileset_animation_header *anim_header){
    if(anim_header->cnt == 0) return 640;
    int clk_cycle = anim_header->animations[0].cycle * anim_header->animations[0].speed;
    int i;
    for(i = 0; i < anim_header->cnt; i++)
        clk_cycle = kgv(clk_cycle, anim_header->animations[i].cycle *
                anim_header->animations[i].speed);
    if(clk_cycle > 0xFFFF){
        dprintf("Tileset animation init failed: no common clk cycle found: %d\n", clk_cycle);
        clk_cycle = 640; //has a lot of common divisors
    }
    return (u16)clk_cycle;
}

void generic_tileset_anim_proceed(tileset_animation *anim, u16 clk){
    if(!__aeabi_uidivmod(clk, anim->speed)){
        //Copy frame
        void *dst = (void*)(0x06000000 + anim->start_tile * 32);
        int frame = (int)__aeabi_uidivmod(clk / anim->speed, anim->cycle);
        int source_offset = 32 * anim->num_tiles * frame;
        void *src = (void*)((int)anim->gfx + source_offset);
        dma3_add_request(src, dst, (u16)(anim->num_tiles * 32));
        
    }
}

void generic_tileset_anim_proceed_all(tileset_animation_header *anim_header,
        u16 clk){
    int i;
    for(i = 0; i < anim_header->cnt; i++)
        generic_tileset_anim_proceed(&anim_header->animations[i], clk);
    
}

