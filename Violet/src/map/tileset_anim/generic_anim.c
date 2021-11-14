#include "types.h"
#include "math.h"
#include "save.h"
#include "map/tileset.h"
#include "debug.h"
#include "constants/flags.h"
#include "flags.h"
#include "dma.h"
#include "map/cloud.h"

u16 generic_tileset_anim_get_clk(tileset_animation_header *anim_header){
    if(anim_header->cnt == 0) return 640 * 9;
    int clk_cycle = anim_header->animations[0].cycle * anim_header->animations[0].speed;
    for(size_t i = 0; i < anim_header->cnt; i++)
        clk_cycle = kgv(clk_cycle, anim_header->animations[i].cycle *
                anim_header->animations[i].speed);
    if(clk_cycle > 0xFFFF){
        dprintf("Tileset animation init failed: no common clk cycle found: %d\n", clk_cycle);
        clk_cycle = 640 * 9; //has a lot of common divisors
    }
    return (u16)clk_cycle;
}

void generic_tileset_anim_proceed(tileset_animation *anim, u16 clk){
    if(checkflag(TILESET_ANIM_DISABLE)) return;
    if(!(clk % anim->speed)){
        //Copy frame
        void *dst = (void*)(0x06000000 + anim->start_tile * 32);
        int frame = (clk / anim->speed) % anim->cycle;
        int source_offset = 32 * anim->num_tiles * frame;
        void *src = (void*)((int)anim->gfx + source_offset);
        dma3_queue_add(src, dst, (u16)(anim->num_tiles * 32));
        
    }
}

void generic_tileset_anim_proceed_all(tileset_animation_header *anim_header,
        u16 clk){
    for(size_t i = 0; i < anim_header->cnt; i++)
        generic_tileset_anim_proceed(&anim_header->animations[i], clk);
    
}

void tileset_secondary_animation_initialize_() {
    // map_cloud_upstream_new();
    tileset_anim_clk1 = 0;
    tileset_anim_clk1_cycle = 0;
    tileset_anim_1 = NULL;
    if (mapheader_virtual.footer->tileset2 && mapheader_virtual.footer->tileset2->animation_init)
        mapheader_virtual.footer->tileset2->animation_init();
}

