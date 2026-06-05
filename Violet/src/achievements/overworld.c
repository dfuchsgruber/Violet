#include "achievements.h"
#include "overworld/script.h"
#include "vars.h"
#include "debug.h"
#include "flags.h"
#include "text.h"
#include "transparency.h"
#include "oam.h"

#define ACHIEVEMENT_NAME_ICON_TAG 0xA006
#define ACHIEVEMENT_NAME_ICON_RESERVED_PIXELS 40
#define ACHIEVEMENT_NAME_TEXT_X 40

static EWRAM u8 achievements_unlocked_message_issued_flags[8]; // 8 * 8 flags for achievements
static EWRAM u8 achievement_name_tbox_idx = 0;
static EWRAM u8 achievement_name_tbox_active = 0;
static EWRAM u8 achievement_name_oam_idx = NUM_OAMS;
static EWRAM u8 achievement_name_oam_gfx_loaded = 0;
static EWRAM u8 achievement_name_oam_pal_loaded = 0;

static const graphic achievement_name_icon_graphic = {
    .sprite = &gfx_achievements_level_iconsTiles,
    .size = GRAPHIC_SIZE_4BPP(32, 128),
    .tag = ACHIEVEMENT_NAME_ICON_TAG,
};

static const palette achievement_name_icon_palette = {
    .pal = &gfx_achievements_level_iconsPal,
    .tag = ACHIEVEMENT_NAME_ICON_TAG,
};

static const sprite achievement_name_icon_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE,
    .attr1 = ATTR1_SIZE_32_32,
    .attr2 = ATTR2_PRIO(0),
};

static const gfx_frame achievement_name_icon_anim_bronze[] = {
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 0},
    {.data = GFX_ANIM_END},
};

static const gfx_frame achievement_name_icon_anim_silver[] = {
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 0},
    {.data = GFX_ANIM_END},
};

static const gfx_frame achievement_name_icon_anim_gold[] = {
    {.data = 2 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 0},
    {.data = GFX_ANIM_END},
};

static const gfx_frame achievement_name_icon_anim_platinum[] = {
    {.data = 3 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 0},
    {.data = GFX_ANIM_END},
};

static const gfx_frame *const achievement_name_icon_anims[] = {
    [ACHIEVEMENT_LEVEL_BRONZE] = achievement_name_icon_anim_bronze,
    [ACHIEVEMENT_LEVEL_SILVER] = achievement_name_icon_anim_silver,
    [ACHIEVEMENT_LEVEL_GOLD] = achievement_name_icon_anim_gold,
    [ACHIEVEMENT_LEVEL_PLATINUM] = achievement_name_icon_anim_platinum,
};

static const oam_template achievement_name_icon_template = {
    .tiles_tag = ACHIEVEMENT_NAME_ICON_TAG,
    .pal_tag = ACHIEVEMENT_NAME_ICON_TAG,
    .oam = &achievement_name_icon_sprite,
    .animation = achievement_name_icon_anims,
    .graphics = NULL,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static const achievement_t *achievement_from_vars(void) {
    u16 group_idx = *var_access(0x8004);
    u16 achievement_idx = *var_access(0x8005);
    if (group_idx >= NUM_ACHIEVEMENT_GROUPS) {
        return NULL;
    }

    const achievement_group_t *group = achievement_groups + group_idx;
    if (achievement_idx >= group->num_achievements) {
        return NULL;
    }
    return group->achievements + achievement_idx;
}

static void achievements_delete_name_icon(void) {
    if (achievement_name_oam_idx < NUM_OAMS) {
        oams[achievement_name_oam_idx].flags |= OAM_FLAG_INVISIBLE;
        oam_free(oams + achievement_name_oam_idx);
        achievement_name_oam_idx = NUM_OAMS;
    }
    if (achievement_name_oam_gfx_loaded) {
        oam_free_vram_by_tag(ACHIEVEMENT_NAME_ICON_TAG);
        achievement_name_oam_gfx_loaded = 0;
    }
    if (achievement_name_oam_pal_loaded) {
        oam_palette_free(ACHIEVEMENT_NAME_ICON_TAG);
        achievement_name_oam_pal_loaded = 0;
    }
}

static void achievements_create_name_icon(const achievement_t *achievement, u8 box_x, u8 box_y) {
    if (oam_vram_get_tile(ACHIEVEMENT_NAME_ICON_TAG) == 0xFFFF) {
        achievement_name_oam_gfx_loaded = oam_load_graphic_using_heap(&achievement_name_icon_graphic);
    }
    if (oam_palette_get_index(ACHIEVEMENT_NAME_ICON_TAG) == 0xFF) {
        achievement_name_oam_pal_loaded = oam_load_palette_using_heap(&achievement_name_icon_palette);
    }

    s16 x = (s16)(box_x * 8 + ACHIEVEMENT_NAME_ICON_RESERVED_PIXELS / 2 - 4);
    s16 y = (s16)(box_y * 8 + 8);
    achievement_name_oam_idx = oam_new_forward_search(&achievement_name_icon_template, x, y, 0);
    if (achievement_name_oam_idx < NUM_OAMS) {
        u8 level = MIN(ACHIEVEMENT_LEVEL_PLATINUM, achievement->level);
        oam_gfx_anim_start(oams + achievement_name_oam_idx, level);
    }
}

void achievements_delete_name_tbox(void) {
    if (!achievement_name_tbox_active) {
        achievements_delete_name_icon();
        return;
    }

    achievements_delete_name_icon();
    u8 tb_id = achievement_name_tbox_idx;
    tbox_flush_set(tb_id, 0);
    tbox_flush_map(tb_id);
    tbox_sync(tb_id, TBOX_SYNC_MAP_AND_SET);
    if (!transparency_is_on()) {
        tbox_flush_map_and_frame(tb_id);
    }
    tbox_free(tb_id);
    achievement_name_tbox_active = 0;
}

void achievements_create_name_tbox(void) {
    u16 group_idx = *var_access(0x8004);
    achievements_delete_name_tbox();

    const achievement_t *achievement = achievement_from_vars();
    if (achievement == NULL) {
        return;
    }

    const u8 *name = achievement_groups[group_idx].name;
    string_decrypt(strbuf, name);
    u16 width = string_get_width(2, strbuf, 0);

    if (transparency_is_on()) {
        u8 box_width = (u8)MIN(30, (width + ACHIEVEMENT_NAME_ICON_RESERVED_PIXELS) / 8 + 3);
        u8 x = 0;
        tboxdata tbdata = {0, x, 12, box_width, 2, 15, 0xE8};
        u8 box_id = tbox_new(&tbdata);
        tbox_flush_set(box_id, 0x11);
        tbox_tilemap_draw(box_id);
        tbox_clear_bottom_line(box_id);
        tbox_font_colormap fontcolmap = {1, 2, 1, 3};
        tbox_print_string(box_id, 2, ACHIEVEMENT_NAME_TEXT_X, 0, 0, 0, &fontcolmap, 0, strbuf);
        achievement_name_tbox_idx = box_id;
        achievements_create_name_icon(achievement, x, 12);
    } else {
        u8 box_width = (u8)MIN(29, (width + ACHIEVEMENT_NAME_ICON_RESERVED_PIXELS) / 8 + 3);
        u8 x = 1;
        tboxdata tbdata = {0, x, 11, box_width, 2, 15, 0xE8};
        u8 box_id = tbox_new(&tbdata);
        tbox_flush_set(box_id, 0x11);
        tbox_tilemap_draw(box_id);
        tbox_init_frame_set_style(box_id, 1, 13 * 16);
        tbox_frame_draw_outer(box_id, 1, 13);
        tbox_font_colormap fontcolmap = {1, 2, 1, 3};
        tbox_print_string(box_id, 2, ACHIEVEMENT_NAME_TEXT_X, 0, 0, 0, &fontcolmap, 0, strbuf);
        achievement_name_tbox_idx = box_id;
        achievements_create_name_icon(achievement, x, 11);
    }
    achievement_name_tbox_active = 1;
}

bool achievements_get_issued_unlocked_message_group_idx(u8 *group_idx_dst, u8 *achievement_idx_dst) {
    for (size_t i = 0; i < ARRAY_COUNT(achievements_unlocked_message_issued_flags); i++) {
        u8 flags = achievements_unlocked_message_issued_flags[i];
        if (flags) {
            for (u8 bit = 0; bit < 8; bit++) {
                if (flags & (1 << bit)) {
                    u8 group_idx = (u8)(i * 8 + bit);
                    const achievement_group_t *group = achievement_groups + group_idx;
                    if (group->is_unlocked()) {
                        for (u8 achievement_idx = 0; achievement_idx < group->num_achievements; achievement_idx++) {
                            const achievement_t *achievement = group->achievements + achievement_idx;
                            if (achievement->is_achieved() && !checkflag(achievement->flag_achieved)) {
                                *group_idx_dst = group_idx;
                                *achievement_idx_dst = achievement_idx;
                                return true;
                            }
                        }
                    }
                }
            }
            // If reached here, this was wrongly marked, should not happen
            achievements_unlocked_message_issued_flags[i] = 0;
        }
    }
    return false;
}

void achievements_get_issued_unlocked_message_group_idx_to_vars() {
    u8 group_idx, achievement_idx;
    if (achievements_get_issued_unlocked_message_group_idx(&group_idx, &achievement_idx)) {
        *var_access(0x8004) = group_idx;
        *var_access(0x8005) = achievement_idx;
        lastresult = 1;
    } else {
        lastresult = 0;
    }
}

void achievements_set_flag_achieved() {
    int group_idx = *var_access(0x8004);
    int achievement_idx = *var_access(0x8005);
    if (group_idx < NUM_ACHIEVEMENT_GROUPS) {
        const achievement_group_t *group = achievement_groups + group_idx;
        if (achievement_idx < group->num_achievements) {
            const achievement_t *achievement = group->achievements + achievement_idx;
            setflag(achievement->flag_achieved);
        }
    }
}

void achievements_compute_unlocked_message_issued() {
    for (size_t i = 0; i < ARRAY_COUNT(achievements_unlocked_message_issued_flags); i++) {
        achievements_unlocked_message_issued_flags[i] = 0;
    }
    for (u8 group_idx = 0; group_idx < NUM_ACHIEVEMENT_GROUPS; group_idx++) {
        const achievement_group_t *group = achievement_groups + group_idx;
        if (group->is_unlocked()) {
            for (u8 achievement_idx = 0; achievement_idx < group->num_achievements; achievement_idx++) {
                const achievement_t *achievement = group->achievements + achievement_idx;
                // DEBUG("Checking achievement group %d achievement %d: achieved=%d flag_achieved=%d\n", group_idx, achievement_idx, achievement->is_achieved(), checkflag(achievement->flag_achieved));
                if (achievement->is_achieved() && !checkflag(achievement->flag_achieved)){
                    int flag_idx = group_idx / 8;
                    int bit_idx = group_idx % 8;
                    achievements_unlocked_message_issued_flags[flag_idx] |= (1 << bit_idx);
                    // DEBUG("Achievement unlocked message issued for group %d achievement %d\n", group_idx, achievement_idx);
                    break;
                    
                }
            }
        }
    }
    DEBUG("Finished computing unlocked message issued\n");
}

void achievements_load_achieved_text() {
    const achievement_t *achievement = achievement_from_vars();
    if (achievement != NULL) {
        overworld_script_state.pointer_banks[0] = achievement->description;
    }
}

void achievements_load_reward_script() {
    const achievement_t *achievement = achievement_from_vars();
    DEBUG("Loading reward script for achievement 0x%x, has reward: %d, reward taken: %d\n", achievement, ACHIEVEMENT_HAS_REWARD(achievement), ACHIEVEMENT_REWARD_TAKEN(achievement));
    if (achievement != NULL && ACHIEVEMENT_HAS_REWARD(achievement) && !ACHIEVEMENT_REWARD_TAKEN(achievement)) {
        overworld_script_virtual_ptr = achievement->reward.script;
        lastresult = 1;
    } else {
        lastresult = 0;
    }
}

void achievements_is_reward_obtained() {
    const achievement_t *achievement = achievement_from_vars();
    if (achievement != NULL && ACHIEVEMENT_HAS_REWARD(achievement) && ACHIEVEMENT_REWARD_TAKEN(achievement)) {
        lastresult = 1;
    } else {
        lastresult = 0;
    }
}