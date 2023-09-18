#include "types.h"
#include "callbacks.h"
#include "save.h"
#include "overworld/effect.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "debug.h"
#include "color.h"
#include "music.h"
#include "vars.h"
#include "flags.h"
#include "dns.h"
#include "overworld/weather.h"
#include "constants/block_behaviour.h"
#include "bios.h"

/*
 * Per each map on each bank we get an additional gras animation by this routine (a table determines which one)
 * Other extensions would be kind of inappropriate concerning the effort to put into
 * A table states which grass animation is on which map-bank combination
 */

extern const unsigned int gfx_high_grassTiles[];
extern const unsigned int gfx_grass_ashTiles[];
extern const unsigned short gfx_grass_ashPal[];
extern const unsigned int gfx_rock_climb_animTiles[];
extern const unsigned int gfx_rock_climb_animPal[];
extern const unsigned int gfx_rock_climb_sky_island_animTiles[];
extern const unsigned int gfx_rock_climb_sky_island_animPal[];
extern const u32 gfx_shallow_waterTiles[];
extern const u32 gfx_graveyard_grassTiles[];
extern const color_t gfx_graveyard_grassPal[16];
extern const unsigned int gfx_grass_haweilandTiles[];
extern const color_t gfx_grass_haweilandPal[16];
extern const unsigned int gfx_grass_cloudTiles[];
extern const color_t gfx_grass_cloudPal[16];
extern const u8 gfx_grass_cloud_dark_greenTiles[];
extern const color_t gfx_grass_cloud_dark_greenPal[16];
extern const u8 gfx_grass_cloud_blueTiles[];
extern const color_t gfx_grass_cloud_bluePal[16];

extern const gfx_frame *const overworld_effect_gfx_anim_table_grass[];

const sprite overworld_effect_grass_sprite = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_16_16, ATTR2_PRIO(3), 0
};


const graphic high_grass_graphics[5] = {
    {&gfx_high_grassTiles[0x0], 0x80, 0},
    {&gfx_high_grassTiles[0x20], 0x80, 0},
    {&gfx_high_grassTiles[0x40], 0x80, 0},
    {&gfx_high_grassTiles[0x60], 0x80, 0},
    {&gfx_high_grassTiles[0x80], 0x80, 0}
};

const graphic haweiland_grass_graphics[] = {
    {&gfx_grass_haweilandTiles[0x0], 0x80, 0},
    {&gfx_grass_haweilandTiles[0x20], 0x80, 0},
    {&gfx_grass_haweilandTiles[0x40], 0x80, 0},
    {&gfx_grass_haweilandTiles[0x60], 0x80, 0}, 
    {&gfx_grass_haweilandTiles[0x80], 0x80, 0}, 
};    

const graphic ash_grass_graphics[] = {
    {&gfx_grass_ashTiles[0x0], 0x80, 0},
    {&gfx_grass_ashTiles[0x20], 0x80, 0},
    {&gfx_grass_ashTiles[0x40], 0x80, 0},
    {&gfx_grass_ashTiles[0x60], 0x80, 0},
    {&gfx_grass_ashTiles[0x80], 0x80, 0},
};

const graphic graveyard_grass_graphics[] = {
    {&gfx_graveyard_grassTiles[0], 0x80, 0},
    {&gfx_graveyard_grassTiles[0x20], 0x80, 0},
    {&gfx_graveyard_grassTiles[0x40], 0x80, 0},
    {&gfx_graveyard_grassTiles[0x60], 0x80, 0},
    {&gfx_graveyard_grassTiles[0x80], 0x80, 0},
};

const graphic cloud_grass_graphics[] = {
    {&gfx_grass_cloudTiles[0], 0x80, 0},
    {&gfx_grass_cloudTiles[0x20], 0x80, 0},
    {&gfx_grass_cloudTiles[0x40], 0x80, 0},
    {&gfx_grass_cloudTiles[0x60], 0x80, 0},
    {&gfx_grass_cloudTiles[0x80], 0x80, 0},
};

const graphic cloud_dark_green_grass_graphics[] = {
    {&gfx_grass_cloud_dark_greenTiles[0 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
    {&gfx_grass_cloud_dark_greenTiles[1 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
    {&gfx_grass_cloud_dark_greenTiles[2 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
    {&gfx_grass_cloud_dark_greenTiles[3 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
    {&gfx_grass_cloud_dark_greenTiles[4 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
};

const graphic cloud_blue_grass_graphics[] = {
    {&gfx_grass_cloud_blueTiles[0 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
    {&gfx_grass_cloud_blueTiles[1 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
    {&gfx_grass_cloud_blueTiles[2 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
    {&gfx_grass_cloud_blueTiles[3 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
    {&gfx_grass_cloud_blueTiles[4 * GRAPHIC_SIZE_4BPP(16, 16)], GRAPHIC_SIZE_4BPP(16, 16), 0},
};

const palette any_grass_pals[] = {
    [ANY_GRASS_ASH] = {gfx_grass_ashPal, TAG_ANY_GRASS_ASH, 0},
    [ANY_GRASS_GRAVEYARD] = {gfx_graveyard_grassPal, TAG_ANY_GRASS_GRAVEYARD, 0},
    [ANY_GRASS_HAWEILAND] = {gfx_grass_haweilandPal, TAG_ANY_GRASS_HAWEILAND, 0},
    [ANY_GRASS_CLOUD] = {gfx_grass_cloudPal, TAG_ANY_GRASS_CLOUD, 0},
    [ANY_GRASS_CLOUD_DARK_GREEN] = {gfx_grass_cloud_dark_greenPal, TAG_ANY_GRASS_CLOUD_DARK_GREEN, 0},
    [ANY_GRASS_CLOUD_BLUE] = {gfx_grass_cloud_bluePal, TAG_ANY_GRASS_CLOUD_BLUE, 0},
};

const oam_template any_grass_templates[] = {
    [ANY_GRASS_ASH] = {0xFFFF, TAG_ANY_GRASS_ASH, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    ash_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
    [ANY_GRASS_GRAVEYARD] = {0xFFFF, TAG_ANY_GRASS_GRAVEYARD, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    graveyard_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
    [ANY_GRASS_HAWEILAND] = {0xFFFF, TAG_ANY_GRASS_HAWEILAND, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    haweiland_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
    [ANY_GRASS_CLOUD] = {0xFFFF, TAG_ANY_GRASS_CLOUD, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    cloud_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
    [ANY_GRASS_CLOUD_DARK_GREEN] = {0xFFFF, TAG_ANY_GRASS_CLOUD_DARK_GREEN, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    cloud_dark_green_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
    [ANY_GRASS_CLOUD_BLUE] = {0xFFFF, TAG_ANY_GRASS_CLOUD_BLUE, &overworld_effect_grass_sprite, overworld_effect_gfx_anim_table_grass,
    cloud_blue_grass_graphics, oam_rotscale_anim_table_null, overworld_effect_oam_callback_grass},
};

const gfx_frame rock_climb_gfx_anim[] = {
		{0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {GFX_ANIM_END, 0}
};

const gfx_frame *rock_climb_gfx_anim_table[] = {rock_climb_gfx_anim};

const graphic rock_climb_graphics[] = {
		{&gfx_rock_climb_animTiles[0 * 16 * 16 / 8], 16 * 16 / 2, 0},
		{&gfx_rock_climb_animTiles[1 * 16 * 16 / 8], 16 * 16 / 2, 0},
		{&gfx_rock_climb_animTiles[2 * 16 * 16 / 8], 16 * 16 / 2, 0},
		{&gfx_rock_climb_animTiles[3 * 16 * 16 / 8], 16 * 16 / 2, 0},
		{&gfx_rock_climb_animTiles[4 * 16 * 16 / 8], 16 * 16 / 2, 0},
	    {NULL, 16 * 16 / 2, 0}
};

const sprite rock_climb_sprite = {
		ATTR0_SHAPE_SQUARE, ATTR1_SIZE_16_16, ATTR2_PRIO(1), 0
};

const oam_template rock_climb_template = {
		0xFFFF, TAG_ROCK_CLIMB, &rock_climb_sprite, rock_climb_gfx_anim_table, rock_climb_graphics,
		oam_rotscale_anim_table_null, oam_null_callback
};

static const graphic rock_climb_sky_island_graphics[] = {
    {&gfx_rock_climb_sky_island_animTiles[0 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {&gfx_rock_climb_sky_island_animTiles[1 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {&gfx_rock_climb_sky_island_animTiles[2 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {&gfx_rock_climb_sky_island_animTiles[3 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {&gfx_rock_climb_sky_island_animTiles[4 * 16 * 16 / 8], 16 * 16 / 2, 0},
    {NULL, 16 * 16 / 2, 0}
};

static const oam_template rock_climb_sky_island_template = {
		0xFFFF, 0x1084, &rock_climb_sprite, rock_climb_gfx_anim_table, rock_climb_sky_island_graphics,
		oam_rotscale_anim_table_null, oam_null_callback
};

const palette rock_climb_pal = {
		gfx_rock_climb_animPal, TAG_ROCK_CLIMB, 0
};

const palette rock_climb_sky_island_pal = {
		gfx_rock_climb_sky_island_animPal, TAG_ROCK_CLIMB_SKY_ISLANG, 0
};

const graphic shallow_water_graphics[] = {
    {&gfx_shallow_waterTiles[0], 0x80, 0},
    {&gfx_shallow_waterTiles[0x20], 0x80, 0},
    {&gfx_shallow_waterTiles[0x40], 0x80, 0},
    {&gfx_shallow_waterTiles[0x60], 0x80, 0},
    {&gfx_shallow_waterTiles[0x80], 0x80, 0},
};

extern const palette overworld_effect_high_grass_pal;
extern const oam_template overworld_effect_oam_template_high_grass;

static const any_grass any_grasses_default[] = {
    {.triggered_by_behavior = MB_TALL_GRASS, .template = &overworld_effect_oam_template_high_grass, .palette = &overworld_effect_high_grass_pal, 
        .initialize = any_grass_step, .on_player_step = any_grass_player_step_null},
    {.triggered_by_behavior = MB_BD, .template = &rock_climb_template, .palette = &rock_climb_pal, 
        .initialize = rock_climb_step, .on_player_step = any_grass_player_step_null},
    {.triggered_by_behavior = MB_3, .template = (oam_template *)0x083A5800, .palette = NULL, 
        .initialize = rock_climb_step, .on_player_step = any_grass_player_step_null},
};

const any_grass_header_t any_grasses_header_default = {.any_grasses = any_grasses_default, .number_any_grasses = ARRAY_COUNT(any_grasses_default)};

static const any_grass any_grasses_ash[] = {
    {.triggered_by_behavior = MB_TALL_GRASS, .template = any_grass_templates + ANY_GRASS_ASH, .palette = any_grass_pals + ANY_GRASS_ASH, 
        .initialize = any_grass_step, .on_player_step = ash_grass_player_step},
    {.triggered_by_behavior = MB_BD, .template = &rock_climb_template, .palette = &rock_climb_pal, 
        .initialize = rock_climb_step, .on_player_step = any_grass_player_step_null},
};
// maptileset251828
const any_grass_header_t any_grasses_header_ash = {.any_grasses = any_grasses_ash, .number_any_grasses = ARRAY_COUNT(any_grasses_ash)};

static const any_grass any_grasses_graveyard[] = {
    {.triggered_by_behavior = MB_BB, .template = any_grass_templates + ANY_GRASS_GRAVEYARD, .palette = any_grass_pals + ANY_GRASS_GRAVEYARD, 
        .initialize = any_grass_step, .on_player_step = any_grass_player_step_null},
    {.triggered_by_behavior = MB_BD, .template = &rock_climb_template, .palette = &rock_climb_pal, 
        .initialize = rock_climb_step, .on_player_step = any_grass_player_step_null},
};

const any_grass_header_t any_grasses_header_graveyard = {.any_grasses = any_grasses_graveyard, .number_any_grasses = ARRAY_COUNT(any_grasses_graveyard)};

static const any_grass any_grasses_haweiland[] = {
    {.triggered_by_behavior = MB_BB, .template = any_grass_templates + ANY_GRASS_HAWEILAND, .palette = any_grass_pals + ANY_GRASS_HAWEILAND, 
        .initialize = any_grass_step, .on_player_step = any_grass_player_step_null},
    {.triggered_by_behavior = MB_BD, .template = &rock_climb_template, .palette = &rock_climb_pal, 
        .initialize = rock_climb_step, .on_player_step = any_grass_player_step_null},
};

const any_grass_header_t any_grasses_header_haweiland = {.any_grasses = any_grasses_haweiland, .number_any_grasses = ARRAY_COUNT(any_grasses_haweiland)};

static const any_grass any_grasses_clouds[] = {
    {.triggered_by_behavior = 2, .template = any_grass_templates + ANY_GRASS_CLOUD, .palette = any_grass_pals + ANY_GRASS_CLOUD, 
        .initialize = any_grass_step, .on_player_step = any_grass_player_step_null},
    {.triggered_by_behavior = MB_BD, .template = &rock_climb_sky_island_template, .palette = &rock_climb_sky_island_pal, 
        .initialize = rock_climb_step, .on_player_step = any_grass_player_step_null},
};

const any_grass_header_t any_grasses_header_clouds = {.any_grasses = any_grasses_clouds, .number_any_grasses = ARRAY_COUNT(any_grasses_clouds)};

static const any_grass any_grasses_clouds_dark_green[] = {
    {.triggered_by_behavior = 2, .template = any_grass_templates + ANY_GRASS_CLOUD_DARK_GREEN, .palette = any_grass_pals + ANY_GRASS_CLOUD_DARK_GREEN, 
        .initialize = any_grass_step, .on_player_step = any_grass_player_step_null},
    {.triggered_by_behavior = MB_BD, .template = &rock_climb_sky_island_template, .palette = &rock_climb_sky_island_pal, 
        .initialize = rock_climb_step, .on_player_step = any_grass_player_step_null},
};

const any_grass_header_t any_grasses_header_clouds_dark_green = {.any_grasses = any_grasses_clouds_dark_green, .number_any_grasses = ARRAY_COUNT(any_grasses_clouds_dark_green)};

static const any_grass any_grasses_clouds_blue[] = {
    {.triggered_by_behavior = 2, .template = any_grass_templates + ANY_GRASS_CLOUD_BLUE, .palette = any_grass_pals + ANY_GRASS_CLOUD_BLUE, 
        .initialize = any_grass_step, .on_player_step = any_grass_player_step_null},
    {.triggered_by_behavior = MB_BD, .template = &rock_climb_sky_island_template, .palette = &rock_climb_sky_island_pal, 
        .initialize = rock_climb_step, .on_player_step = any_grass_player_step_null},
};

const any_grass_header_t any_grasses_header_clouds_blue = {.any_grasses = any_grasses_clouds_blue, .number_any_grasses = ARRAY_COUNT(any_grasses_clouds_blue)};


static const any_grass *any_grass_get_by_behaviour(u8 behaviour, const tileset *ts) {
    if (ts->any_grasses) {
        for (size_t i = 0; i < ts->any_grasses->number_any_grasses; i++) {
            const any_grass *g = ts->any_grasses->any_grasses + i;
            if (g->triggered_by_behavior == behaviour)
                return g;
        }
    }
    return NULL;
}

const any_grass *any_grass_get_on_current_map_by_behaviour(u8 behaviour) {
    // Secondary tileset any grasses superceed primary tileset ones
    const any_grass *g = any_grass_get_by_behaviour(behaviour, mapheader_virtual.footer->tileset2);
    if (g)
        return g;
    g = any_grass_get_by_behaviour(behaviour, mapheader_virtual.footer->tileset1);
    return g;
}

void any_grass_step(bool reinitialize){
    if (!reinitialize)
        play_sound(0x15C);
}

void rock_climb_step(bool reinitialize){
    if (!reinitialize)
	    play_sound(0x7C);
}

bool tile_is_high_grass(u8 behavior){
    return behavior == MB_TALL_GRASS || behavior == 0xD1 || behavior == MB_BB || behavior == MB_BD;
}


const u8 *ash_grass_player_step(){
    u16 *collected = var_access(ASH);
    if(checkflag(ASHBAG_RECEIVED) && *collected < 50000){
        (*collected)++;
    }
    return NULL;
}

const u8 *any_grass_player_step_null(){
    return NULL;
}

/**
 * Initializes any grass instead of tall grass(takes x, y to spawn oam), if none can be initialized it returns 64 (:= none)
 * @param pos
 * @return 
 */
int tile_any_grass_init(){
    s16 x = (s16)(overworld_effect_state.x), y = (s16)(overworld_effect_state.y);
    u8 behavior = (u8)block_get_behaviour_by_pos((s16)(overworld_effect_state.x), (s16)(overworld_effect_state.y));
    const any_grass *g = any_grass_get_on_current_map_by_behaviour(behavior);
    DEBUG("New any grass init: 0x%x, behaviour %d.\n", g, behavior);
    if (g) {
        if (g->initialize) 
            g->initialize(overworld_effect_state.reinitialize);
        // Initialize pal
        if (g->palette) {
            u8 pal_idx = oam_palette_get_index(g->palette->tag);
            if(pal_idx == 0xFF) {
                pal_idx = oam_allocate_palette(g->palette->tag);
            }
            u16 color = (u16)(pal_idx * 16 + 256);
            pal_copy(g->palette->pal, color, 32);
            pal_apply_shaders_by_oam_palette_idx(pal_idx);
            pal_oam_apply_fading(pal_idx);
        }
        overworld_effect_ow_coordinates_to_screen_coordinates(&x, &y, 8, 8);
        u8 oam_idx = oam_new_backward_search(g->template, x, y, 0);
        if (oam_idx < ARRAY_COUNT(oams)) {
            oam_object *o = oams + oam_idx;
            o->flags |= OAM_FLAG_CENTERED;
            o->final_oam.attr2 = (u16)((o->final_oam.attr2 & (~ATTR2_PRIO(3))) | ATTR2_PRIO(overworld_effect_state.bg_priority));
            o->private[0] = (u16)(overworld_effect_state.height);
            o->private[1] = (u16)(overworld_effect_state.x);
            o->private[2] = (u16)(overworld_effect_state.y);
            o->private[3] = (u16)(overworld_effect_state.target_ow_and_their_map);
            o->private[4] = (u16)(overworld_effect_state.target_ow_bank);
            o->private[5] = (u16)(overworld_effect_state.origin_map_and_bank);
            if (overworld_effect_state.reinitialize) {
                oam_gfx_anim_init(o, 4);
            }
            return 0;
        }   
    }
    DEBUG("No grass animation possible for behaviour %d on current map.\n", behavior);
    return 0;
}

bool tag_is_ground_effect(u16 tag) {
    return tag >= 0x1000 && tag < 0x1100; // If we ever need other ground effect tags, we need to add them here...
}