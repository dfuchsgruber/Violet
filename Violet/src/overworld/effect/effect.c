#include "types.h"
#include "oam.h"
#include "overworld/sprite.h"
#include "overworld/effect.h"
#include "vars.h"

/**
graphic overworld_effect_explosion_graphic = {
    .sprite = gfx_overworld_explosionTiles, .tag = GFX_TAG_OVERWORLD_EFFECT_EXPLOSION, .size = GRAPHIC_SIZE_4BPP(32, 32),
};
**/

static graphic overworld_effect_explosion_graphics[] = {
    [0] = {.sprite = gfx_overworld_explosionTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0xFFFF},
    [1] = {.sprite = gfx_overworld_explosionTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0xFFFF},
    [2] = {.sprite = gfx_overworld_explosionTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0xFFFF},
    [3] = {.sprite = gfx_overworld_explosionTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = 0xFFFF},
};

palette overworld_effect_explosion_palette = {
    .pal = gfx_overworld_explosionPal, .tag = GFX_TAG_OVERWORLD_EFFECT_EXPLOSION,
};

static sprite overworld_effect_explosion_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(1),
};

static gfx_frame overworld_effect_explosion_gfx_animation[] = {
    {.data = 0, .duration = 0}, {.data = 0, .duration = 5}, {.data = 1, .duration = 5}, {.data = 2, .duration = 5}, 
    {.data = 3, .duration = 5}, {.data = GFX_ANIM_END}, 
};

static gfx_frame *overworld_effect_explosion_gfx_animations[] = {overworld_effect_explosion_gfx_animation};

static void overworld_effect_explosion_oam_callback(oam_object *self) {
    if (self->flags & OAM_FLAG_GFX_ANIM_END) {
        overworld_effect_delete(self, OVERWORLD_EFFECT_EXPLOSION);
    }
}

static oam_template overworld_effect_explosion_oam_template = {
    .tiles_tag = 0xFFFF, .pal_tag = GFX_TAG_OVERWORLD_EFFECT_EXPLOSION,
    .graphics = overworld_effect_explosion_graphics,
    .oam = &overworld_effect_explosion_sprite, .animation = overworld_effect_explosion_gfx_animations,
    .rotscale = oam_rotscale_anim_table_null, .callback = overworld_effect_explosion_oam_callback,
};

void overworld_effect_explosion() {
    s16 x = (s16)(overworld_effect_state.x + 7);
    s16 y = (s16)(overworld_effect_state.y + 5);
    overworld_effect_ow_coordinates_to_screen_coordinates(&x, &y, 8, 0);
    u8 oam_idx = oam_new_backward_search(&overworld_effect_explosion_oam_template, x, y , 0);
    oam_gfx_anim_start(oams + oam_idx, 0);
}

void special_overworld_effect_explosion() {
    overworld_effect_state.x = *var_access(0x8004);
    overworld_effect_state.y = *var_access(0x8005);
    overworld_effect_new(OVERWORLD_EFFECT_EXPLOSION);
}

const u8 *overworld_effects[NUM_OVERWORLD_EFFECTS] = {
    [OVERWORLD_EFFECT_EXCLAMATION_MARK_ICON] = overworld_effect_script_exclamation_mark_icon,
    [OVERWORLD_EFFECT_USE_CUT_ON_GRASS] = overworld_effect_script_use_cut_on_grass,
    [OVERWORLD_EFFECT_USE_CUT_ON_TREE] = overworld_effect_script_use_cut_on_tree,
    [OVERWORLD_EFFECT_SHADOW] = overworld_effect_script_shadow,
    [OVERWORLD_EFFECT_TALL_GRASS] = overworld_effect_script_tall_grass,
    [OVERWORLD_EFFECT_RIPPLE] = overworld_effect_script_ripple,
    [OVERWORLD_EFFECT_FIELD_MOVE_SHOW_MON] = overworld_effect_script_field_move_show_mon,
    [OVERWORLD_EFFECT_ASH] = overworld_effect_script_ash,
    [OVERWORLD_EFFECT_SURF_BLOB] = overworld_effect_script_surf_blob,
    [OVERWORLD_EFFECT_USE_SURF] = overworld_effect_script_use_surf,
    [OVERWORLD_EFFECT_DUST] = overworld_effect_script_dust,
    [OVERWORLD_EFFECT_USE_SECRET_POWER_CAVE] = overworld_effect_script_use_secret_power_cave,
    [OVERWORLD_EFFECT_JUMP_TALL_GRASS] = overworld_effect_script_jump_tall_grass,
    [OVERWORLD_EFFECT_SAND_FOOTPRINTS] = overworld_effect_script_sand_footprints,
    [OVERWORLD_EFFECT_JUMP_BIG_SPLASH] = overworld_effect_script_jump_big_splash,
    [OVERWORLD_EFFECT_SPLASH] = overworld_effect_script_splash,
    [OVERWORLD_EFFECT_JUMP_SMALL_SPLASH] = overworld_effect_script_jump_small_splash,
    [OVERWORLD_EFFECT_LONG_GRASS] = overworld_effect_script_long_grass,
    [OVERWORLD_EFFECT_JUMP_LONG_GRASS] = overworld_effect_script_jump_long_grass,
    [OVERWORLD_EFFECT_UNKNOWN_19] = overworld_effect_script_unknown_19,
    [OVERWORLD_EFFECT_UNKNOWN_20] = overworld_effect_script_unknown_20,
    [OVERWORLD_EFFECT_UNKNOWN_21] = overworld_effect_script_unknown_21,
    [OVERWORLD_EFFECT_UNKNOWN_22] = overworld_effect_script_unknown_22,
    [OVERWORLD_EFFECT_BERRY_TREE_GROWTH_SPARKLE] = overworld_effect_script_berry_tree_growth_sparkle,
    [OVERWORLD_EFFECT_DEEP_SAND_FOOTPRINTS] = overworld_effect_script_deep_sand_footprints,
    [OVERWORLD_EFFECT_POKECENTER_HEAL] = overworld_effect_script_pokecenter_heal,
    [OVERWORLD_EFFECT_USE_SECRET_POWER_TREE] = overworld_effect_script_use_secret_power_tree,
    [OVERWORLD_EFFECT_USE_SECRET_POWER_SHRUB] = overworld_effect_script_use_secret_power_shrub,
    [OVERWORLD_EFFECT_TREE_DISGUISE] = overworld_effect_script_tree_disguise,
    [OVERWORLD_EFFECT_MOUNTAIN_DISGUISE] = overworld_effect_script_mountain_disguise,
    [OVERWORLD_EFFECT_NPCFLY_OUT] = overworld_effect_script_npcfly_out,
    [OVERWORLD_EFFECT_USE_FLY] = overworld_effect_script_use_fly,
    [OVERWORLD_EFFECT_FLY_IN] = overworld_effect_script_fly_in,
    [OVERWORLD_EFFECT_QUESTION_MARK_ICON] = overworld_effect_script_question_mark_icon,
    [OVERWORLD_EFFECT_FEET_IN_FLOWING_WATER] = overworld_effect_script_feet_in_flowing_water,
    [OVERWORLD_EFFECT_BIKE_TIRE_TRACKS] = overworld_effect_script_bike_tire_tracks,
    [OVERWORLD_EFFECT_SAND_DISGUISE] = overworld_effect_script_sand_disguise,
    [OVERWORLD_EFFECT_USE_ROCK_SMASH] = overworld_effect_script_use_rock_smash,
    [OVERWORLD_EFFECT_USE_DIG] = overworld_effect_script_use_dig,
    [OVERWORLD_EFFECT_SAND_PILE] = overworld_effect_script_sand_pile,
    [OVERWORLD_EFFECT_USE_STRENGTH] = overworld_effect_script_use_strength,
    [OVERWORLD_EFFECT_SHORT_GRASS] = overworld_effect_script_short_grass,
    [OVERWORLD_EFFECT_HOT_SPRINGS_WATER] = overworld_effect_script_hot_springs_water,
    [OVERWORLD_EFFECT_USE_WATERFALL] = overworld_effect_script_use_waterfall,
    [OVERWORLD_EFFECT_USE_DIVE] = overworld_effect_script_use_dive,
    [OVERWORLD_EFFECT_POKEBALL] = overworld_effect_script_pokeball,
    [OVERWORLD_EFFECT_X_ICON] = overworld_effect_script_x_icon,
    [OVERWORLD_EFFECT_NOP_47] = overworld_effect_script_nop_47,
    [OVERWORLD_EFFECT_NOP_48] = overworld_effect_script_nop_48,
    [OVERWORLD_EFFECT_POP_OUT_OF_ASH] = overworld_effect_script_pop_out_of_ash,
    [OVERWORLD_EFFECT_LAVARIDGE_GYM_WARP] = overworld_effect_script_lavaridge_gym_warp,
    [OVERWORLD_EFFECT_SWEET_SCENT] = overworld_effect_script_sweet_scent,
    [OVERWORLD_EFFECT_SAND_PILLAR] = overworld_effect_script_sand_pillar,
    [OVERWORLD_EFFECT_BUBBLES] = overworld_effect_script_bubbles,
    [OVERWORLD_EFFECT_SPARKLE] = overworld_effect_script_sparkle,
    [OVERWORLD_EFFECT_SECRET_POWER_CAVE] = overworld_effect_script_secret_power_cave,
    [OVERWORLD_EFFECT_SECRET_POWER_TREE] = overworld_effect_script_secret_power_tree,
    [OVERWORLD_EFFECT_SECRET_POWER_SHRUB] = overworld_effect_script_secret_power_shrub,
    [OVERWORLD_EFFECT_CUT_GRASS] = overworld_effect_script_cut_grass,
    [OVERWORLD_EFFECT_FIELD_MOVE_SHOW_MON_INIT] = overworld_effect_script_field_move_show_mon_init,
    [OVERWORLD_EFFECT_USE_FLY_ANCIENT_TOMB] = overworld_effect_script_use_fly_ancient_tomb,
    [OVERWORLD_EFFECT_PCTURN_ON] = overworld_effect_script_pcturn_on,
    [OVERWORLD_EFFECT_HALL_OF_FAME_RECORD] = overworld_effect_script_hall_of_fame_record,
    [OVERWORLD_EFFECT_USE_TELEPORT] = overworld_effect_script_use_teleport,
    [OVERWORLD_EFFECT_SMILEY_FACE_ICON] = overworld_effect_script_smiley_face_icon,
    [OVERWORLD_EFFECT_USE_VS_SEEKER] = overworld_effect_script_use_vs_seeker,
    [OVERWORLD_EFFECT_DOUBLE_EXCL_MARK_ICON] = overworld_effect_script_double_excl_mark_icon,
    [OVERWORLD_EFFECT_MOVE_DEOXYS_ROCK] = overworld_effect_script_move_deoxys_rock,
    [OVERWORLD_EFFECT_UNK_44] = overworld_effect_script_unk_44,
    [OVERWORLD_EFFECT_UNK_45] = overworld_effect_script_unk_45,
    [OVERWORLD_EFFECT_EXPLOSION] = overworld_effect_script_explosion,
};