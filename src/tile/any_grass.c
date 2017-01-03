#include "types.h"
#include "romfuncs.h"
#include "callbacks.h"
#include "save.h"
#include "tile.h"
#include "gfx.h"
#include "debug.h"


/*
 * Per each map on each bank we get an additional gras animation by this routine (a table determines which one)
 * Other extensions would be kind of inappropriate concerning the effort to put into
 * A table states which grass animation is on which map-bank combination
 */


graphic any_grass_graphics[] = {
    {&gfx_grass_ashTiles[0x0], 0x80, 0},
    {&gfx_grass_ashTiles[0x20], 0x80, 0},
    {&gfx_grass_ashTiles[0x40], 0x80, 0},
    {&gfx_grass_ashTiles[0x60], 0x80, 0},
    {NULL, 0x80, 0}
};

palette any_grass_pals[] = {
    {gfx_grass_ashPal, 0x1080, 0}
};

oam_template any_grass_templates[] = {
    {0xFFFF, 0x1080, (sprite*)0x83A35B4, (gfx_frame**)0x83A52E0,
    any_grass_graphics, (rotscale_frame**)ROTSCALE_TABLE_NULL, (void (*)(oam_object *))0x80DB611}
};



any_grass tile_any_grasses[] = {
    {0, 0, 2, true, (oam_template *)0x083A52E4, NULL, nullsub}, //Normal Grass, behavior 2 triggered by any map
    {0, 0, 3, true, (oam_template *)0x083A5800, NULL, nullsub},
    {3, 24, 0xBb, false, &any_grass_templates[0], &any_grass_pals[0], ash_grass_step},
    {18, 3, 0xBb, false, &any_grass_templates[0], &any_grass_pals[0], ash_grass_step},
    {1, 30, 0xBb, false, &any_grass_templates[0], &any_grass_pals[0], ash_grass_step},
    {0, 12, 0xBb, false, &any_grass_templates[0], &any_grass_pals[0], ash_grass_step},
    {0xFF, 0xFF, 0xFF, false, NULL, NULL, nullsub} 
};

bool tile_is_any_grass(u8 behavior){
    return behavior == 0x3; //we abuse "tall grass" byte for any grass
}

bool tile_is_high_grass(u8 behavior){
    return behavior == 2 || behavior == 0xD1 || behavior == 0xBb;
}


void ash_grass_step(){
    u16 *collected = vardecrypt(VAR_ASH);
    if(checkflag(FLAG_ASHBAG) && *collected < 50000){
        (*collected)++;
    }
}

/**
 * Initializes any grass instead of tall grass(takes x, y to spawn oam), if none can be initialized it returns 64 (:= none)
 * @param pos
 * @return 
 */
u8 tile_any_grass_init(coordinate *pos){
    int i;
    int *overworld_effect_state = (int*)0x020386E0;
    s16 x = (s16)overworld_effect_state[0];
    s16 y = (s16)overworld_effect_state[1];
    u8 behavior = (u8)get_block_info_behaviour(x, y);
    for(i = 0; tile_any_grasses[i].bank != 0xFF || tile_any_grasses[i].map != 0xFF; i++){
        if(tile_any_grasses[i].triggered_by_behavior == behavior &&(
                ((*save1)->bank == tile_any_grasses[i].bank && 
                (*save1)->map == tile_any_grasses[i].map )|| tile_any_grasses[i].apply_to_every_map)){
            
            if(tile_any_grasses[i].init_func)
                tile_any_grasses[i].init_func();
            
            //Load appropriate palette if present
            if(tile_any_grasses[i].pal){
                u8 pal_id = get_obj_pal_by_tag(tile_any_grasses[i].pal->tag);
                if(pal_id == 0xFF)
                    pal_id = allocate_obj_pal(tile_any_grasses[i].pal->tag);
                pal_load_uncomp(tile_any_grasses[i].pal->pal, (u16)(pal_id*16 + 256), 32);
                pal_apply_shader_by_overworld_pal(pal_id);
                pal_ow_fading_state_sync(pal_id);
            }
            
            //Instanciate appropriate template
            return generate_oam_backward_search(tile_any_grasses[i].temp, pos->x, pos->y, 0);
        }
        
    }
    debug1(behavior);
    err(ERR_UNKOWN_GRASS_ANIMATION);
    return 64;
}
