#include "types.h"
#include "callbacks.h"
#include "save.h"
#include "tile/any_grass.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "debug.h"
#include "color.h"
#include "music.h"
#include "vars.h"
#include "flags.h"
#include "dns.h"
#include "overworld/weather.h"

/*
 * Per each map on each bank we get an additional gras animation by this routine (a table determines which one)
 * Other extensions would be kind of inappropriate concerning the effort to put into
 * A table states which grass animation is on which map-bank combination
 */

extern const unsigned int gfx_grass_ashTiles[];
extern const unsigned short gfx_grass_ashPal[];
extern unsigned int gfx_rock_climb_animTiles[];
extern unsigned int gfx_rock_climb_animPal[];
extern unsigned int gfx_rock_climb_sky_island_animTiles[];
extern unsigned int gfx_rock_climb_sky_island_animPal[];
extern u32 gfx_shallow_waterTiles[];
extern u32 gfx_graveyard_grassTiles[];
extern color_t gfx_graveyard_grassPal[16];
extern unsigned int gfx_grass_haweilandTiles[];
extern color_t gfx_grass_haweilandPal[16];
extern unsigned int gfx_grass_cloudTiles[];
extern color_t gfx_grass_cloudPal[16];

extern gfx_frame *overworld_effect_gfx_anim_table_grass[];

sprite overworld_effect_grass_sprite = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_16_16, ATTR2_PRIO(3), 0
};

graphic haweiland_grass_graphics[] = {
    {&gfx_grass_haweilandTiles[0x0], 0x80, 0},
    {&gfx_grass_haweilandTiles[0x20], 0x80, 0},
    {&gfx_grass_haweilandTiles[0x40], 0x80, 0},
    {&gfx_grass_haweilandTiles[0x60], 0x80, 0},
    {NULL, 0x80, 0}
};    

graphic ash_grass_graphics[] = {
    {&gfx_grass_ashTiles[0x0], 0x80, 0},
    {&gfx_grass_ashTiles[0x20], 0x80, 0},
    {&gfx_grass_ashTiles[0x40], 0x80, 0},
    {&gfx_grass_ashTiles[0x60], 0x80, 0},
    {NULL, 0x80, 0}
};

graphic graveyard_grass_graphics[] = {
    {&gfx_graveyard_grassTiles[0], 0x80, 0},
    {&gfx_graveyard_grassTiles[0x20], 0x80, 0},
    {&gfx_graveyard_grassTiles[0x40], 0x80, 0},
    {&gfx_graveyard_grassTiles[0x60], 0x80, 0},
    {NULL, 0x80, 0}
};

graphic cloud_grass_graphics[] = {
    {&gfx_grass_cloudTiles[0], 0x80, 0},
    {&gfx_grass_cloudTiles[0x20], 0x80, 0},
    {&gfx_grass_cloudTiles[0x40], 0x80, 0},
    {&gfx_grass_cloudTiles[0x60], 0x80, 0},
    {NULL, 0x80, 0}
};

palette any_grass_pals[] = {
    [ANY_GRASS_ASH] = {gfx_grass_ashPal, 0x1080, 0},
    [ANY_GRASS_GRAVEYARD] = {gfx_graveyard_grassPal, 0x1081, 0},
    [ANY_GRASS_HAWEILAND] = {gfx_grass_haweilandPal, 0x1082, 0},
    [ANY_GRASS_CLOUD] = {gfx_grass_cloudPal, 0x1083, 0},
};

oam_template any_grass_templates[] = {
    [ANY_GRASS_ASH] = {0xFFFF, 0x1080, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    ash_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
    [ANY_GRASS_GRAVEYARD] = {0xFFFF, 0x1081, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    graveyard_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
    [ANY_GRASS_HAWEILAND] = {0xFFFF, 0x1082, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    haweiland_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
    [ANY_GRASS_CLOUD] = {0xFFFF, 0x1083, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    cloud_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
};

gfx_frame rock_climb_gfx_anim[] = {
		{0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {GFX_ANIM_END, 0}
};

gfx_frame *rock_climb_gfx_anim_table[] = {rock_climb_gfx_anim};

graphic rock_climb_graphics[] = {
		{&gfx_rock_climb_animTiles[0 * 16 * 16 / 8], 16 * 16 / 2, 0},
		{&gfx_rock_climb_animTiles[1 * 16 * 16 / 8], 16 * 16 / 2, 0},
		{&gfx_rock_climb_animTiles[2 * 16 * 16 / 8], 16 * 16 / 2, 0},
		{&gfx_rock_climb_animTiles[3 * 16 * 16 / 8], 16 * 16 / 2, 0},
		{&gfx_rock_climb_animTiles[4 * 16 * 16 / 8], 16 * 16 / 2, 0},
	    {NULL, 16 * 16 / 2, 0}
};

sprite rock_climb_sprite = {
		ATTR0_SHAPE_SQUARE, ATTR1_SIZE_16_16, ATTR2_PRIO(1), 0
};

oam_template rock_climb_template = {
		0xFFFF, 0x7731, &rock_climb_sprite, rock_climb_gfx_anim_table, rock_climb_graphics,
		oam_rotscale_anim_table_null, oam_null_callback
};

static graphic rock_climb_sky_island_graphics[] = {
    {&gfx_rock_climb_sky_island_animTiles[0 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {&gfx_rock_climb_sky_island_animTiles[1 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {&gfx_rock_climb_sky_island_animTiles[2 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {&gfx_rock_climb_sky_island_animTiles[3 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {&gfx_rock_climb_sky_island_animTiles[4 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {NULL, 16 * 16 / 2, 0}
};

static oam_template rock_climb_sky_island_template = {
		0xFFFF, 0x7732, &rock_climb_sprite, rock_climb_gfx_anim_table, rock_climb_sky_island_graphics,
		oam_rotscale_anim_table_null, oam_null_callback
};

palette rock_climb_pal = {
		gfx_rock_climb_animPal, 0x7731, 0
};

palette rock_climb_sky_island_pal = {
		gfx_rock_climb_sky_island_animPal, 0x7732, 0
};

graphic shallow_water_graphics[] = {
    {&gfx_shallow_waterTiles[0], 0x80, 0},
    {&gfx_shallow_waterTiles[0x20], 0x80, 0},
    {&gfx_shallow_waterTiles[0x40], 0x80, 0},
    {&gfx_shallow_waterTiles[0x60], 0x80, 0},
    {&gfx_shallow_waterTiles[0x80], 0x80, 0},
};


any_grass any_grasses[] = {
    {&maptileset0, 2, (oam_template *)0x083A52E4, NULL, any_grass_step, any_grass_player_step_null}, //Normal Grass, behavior 2 triggered by any map
    {&maptileset0, 3, (oam_template *)0x083A5800, NULL, any_grass_step, any_grass_player_step_null},
    {&maptileset0, 0xBD, &rock_climb_template, &rock_climb_pal, rock_climb_step, any_grass_player_step_null},
    {&maptileset251828, 0xBB, any_grass_templates + ANY_GRASS_ASH, any_grass_pals + ANY_GRASS_ASH, any_grass_step, ash_grass_player_step},
    {&maptileset_ceometria, 0xBB, any_grass_templates + ANY_GRASS_GRAVEYARD, any_grass_pals + ANY_GRASS_GRAVEYARD, 
        any_grass_step, any_grass_player_step_null},
    {&maptileset_haweiland, 0xBB, any_grass_templates + ANY_GRASS_HAWEILAND, any_grass_pals + ANY_GRASS_HAWEILAND, 
        any_grass_step, any_grass_player_step_null},
    {&maptileset_clouds, 2, any_grass_templates + ANY_GRASS_CLOUD, any_grass_pals + ANY_GRASS_CLOUD, 
        any_grass_step, any_grass_player_step_null},
    {&maptileset_clouds, 0xBD, &rock_climb_sky_island_template, &rock_climb_sky_island_pal, 
        rock_climb_step, any_grass_player_step_null},
};

any_grass *any_grass_get_on_current_map_by_behaviour(u8 behaviour) {
    for (size_t i = 0; i < ARRAY_COUNT(any_grasses); i++) {
        if ((mapheader_virtual.footer->tileset1 == any_grasses[i].tileset || 
            mapheader_virtual.footer->tileset2 == any_grasses[i].tileset)
             && behaviour == any_grasses[i].triggered_by_behavior) 
            return any_grasses + i;
    }
    return NULL;
}

void any_grass_step(){
    play_sound(0x15C);
}

void rock_climb_step(){
	play_sound(0x7C);
}

bool tile_is_any_grass(u8 behavior){
    return behavior == 0x3; //we abuse "tall grass" byte for any grass
}

bool tile_is_high_grass(u8 behavior){
    return behavior == 2 || behavior == 0xD1 || behavior == 0xBb || behavior == 0xBD;
}


u8 *ash_grass_player_step(){
    u16 *collected = var_access(ASH);
    if(checkflag(ASHBAG_RECEIVED) && *collected < 50000){
        (*collected)++;
    }
    return NULL;
}

u8 *any_grass_player_step_null(){
    return NULL;
}

/**
 * Initializes any grass instead of tall grass(takes x, y to spawn oam), if none can be initialized it returns 64 (:= none)
 * @param pos
 * @return 
 */
u8 tile_any_grass_init(coordinate_t *pos){
    s16 x = (s16)overworld_effect_state.x;
    s16 y = (s16)overworld_effect_state.y;
    u8 behavior = (u8)block_get_behaviour_by_pos(x, y);
    any_grass *g = any_grass_get_on_current_map_by_behaviour(behavior);
    if (g) {
        if (g->init_func) g->init_func();
        // Initialize pal
        if (g->pal) {
            u8 pal_idx = oam_palette_get_index(g->pal->tag);
            if(pal_idx == 0xFF) {
                pal_idx = oam_allocate_palette(g->pal->tag);
            }
            u16 color = (u16)(pal_idx * 16 + 256);
            pal_copy(g->pal->pal, color, 32);
            pal_apply_shaders_by_oam_palette_idx(pal_idx);
            pal_oam_apply_fading(pal_idx);
        }
        return oam_new_backward_search(g->temp, pos->x, pos->y, 0);
    }
    dprintf("No grass animation possible for behaviour %d on current map.\n", behavior);
    return 64;
}

