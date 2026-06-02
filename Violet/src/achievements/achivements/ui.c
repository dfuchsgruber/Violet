#include "achievements.h"
#include "agbmemory.h"
#include "bios.h"
#include "callbacks.h"
#include "debug.h"
#include "dma.h"
#include "fading.h"
#include "io.h"
#include "language.h"
#include "list_menu.h"
#include "menu_indicators.h"
#include "oam.h"
#include "overworld/map_control.h"
#include "overworld/script.h"
#include "overworld/start_menu.h"
#include "superstate.h"
#include "text.h"
#include "transparency.h"
#include "types.h"
#include "vars.h"

EWRAM achievements_ui_state_t *achievements_ui_state = NULL;
EWRAM achievements_ui_cursor_t achievements_ui_cursor = {0};

void achievements_update_selected(u8 self);
static void achievements_update_level_icon_oams(void);
static void achievements_exit(u8 self);
static void achievements_exit_to_script(u8 self);
static const achievement_group_t *achievements_get_selected_group(void);
static u8 achievements_get_selected_group_idx(void);
static const achievement_t *achievements_group_get_first_claimable_reward(const achievement_group_t *group);
static const achievement_t *achievements_group_get_last_achieved(const achievement_group_t *group);
static void achievements_save_cursor(void);
static void achievements_get_initial_cursor(u16 *scroll_offset, u16 *row);

void achievements_process_input(u8 self) {
    if (fading_is_active() || dma3_busy(-1)) {
        return;
    }
    int input = list_menu_process_input(achievements_ui_state->list_menu_callback_idx);
    switch (input) {
    case LIST_MENU_B_PRESSED:
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = achievements_exit;
        break;
    case LIST_MENU_NOTHING_CHOSEN:
        break;
    default: {
        const achievement_group_t *group = achievements_get_selected_group();
        const achievement_t *achievement = achievements_group_get_first_claimable_reward(group);
        if (achievement != NULL && achievement->reward.script != NULL) {
            achievements_ui_state->script_to_execute = achievement->reward.script;
            fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
            big_callbacks[self].function = achievements_exit_to_script;
        }
        break;
    }
    }
}

enum {
    RESET,
    BG_SETUP,
    GFX_LOAD,
    DATA_SETUP,
    TBOX_SETUP,
    BUILD_LIST_MENU,
    PAL_SETUP,
    OAM_SETUP,
    CURSOR_SETUP,
    BG_COPY,
    FADE_TO_IDLE,
};

static const bg_config bg_configs[] = {
    {.bg_id = 0, .char_base = 0, .map_base = 31, .size = 0, .color_mode = 0, .priority = 1},
    {.bg_id = 1, .char_base = 2, .map_base = 29, .size = 0, .color_mode = 0, .priority = 2},
    {.bg_id = 2, .char_base = 3, .map_base = 30, .size = 0, .color_mode = 0, .priority = 0},
};

static inline u8 achievement_to_bucket(u8 achievement_group) {
    const achievement_group_t *group = achievement_groups + achievement_group;
    if (!group->is_unlocked()) {
        return 2;
    }
    const achievement_t *tail = group->achievements + achievement_group_get_tail_idx(group);
    if (tail->is_achieved()) {
        return 1;
    }
    return 0;
}

void sort_achievements() {
    u8 dst = 0;
    for (u8 bucket = 0; bucket < 3; bucket++) {
        for (u8 i = 0; i < NUM_ACHIEVEMENT_GROUPS; i++) {
            if (achievement_to_bucket(i) == bucket) {
                achievements_ui_state->achievements[dst++] = i;
            }
        }
    }
}

enum { TBOX_HEADER,
       TBOX_LIST_MENU,
       TBOX_DESCRIPTION,
       TBOX_REWARD,
       TBOX_CNT };
#define HEADER_HEIGHT 2
#define HEADER_WIDTH 28
#define LIST_MENU_HEIGHT 16
#define LIST_MENU_WIDTH 15
#define DESCRIPTION_WIDTH 30
#define DESCRIPTION_HEIGHT 2
#define REWARDS_WIDTH (30 - LIST_MENU_WIDTH - 3)
#define REWARDS_HEIGHT LIST_MENU_HEIGHT
#define ACHIEVEMENTS_LEVEL_ICON_TAG 0xA006
#define ACHIEVEMENTS_PROGRESS_BAR_TAG 0xA007
#define HEADER_CLAIM_NOTE_X 180
#define HEADER_CLAIM_NOTE_Y 0
#define HEADER_CLAIM_NOTE_WIDTH (HEADER_WIDTH * 8 - HEADER_CLAIM_NOTE_X)
#define HEADER_CLAIM_NOTE_HEIGHT (HEADER_HEIGHT * 8)
#define ACHIEVEMENTS_LIST_ITEM_X 12
#define ACHIEVEMENTS_LIST_FONT 2

static const tboxdata ui_tboxes[TBOX_CNT + 1] = {
    [TBOX_HEADER] = {.bg_id = 0, .x = 2, .y = 0, .w = HEADER_WIDTH, .h = HEADER_HEIGHT, .pal = 14, .start_tile = 1},
    [TBOX_DESCRIPTION] = {.bg_id = 0, .x = 0, .y = 18, .w = DESCRIPTION_WIDTH, .h = DESCRIPTION_HEIGHT, .pal = 14, .start_tile = 1 + (HEADER_WIDTH * HEADER_HEIGHT)},
    [TBOX_LIST_MENU] = {.bg_id = 0, .x = 3, .y = 2, .w = LIST_MENU_WIDTH, .h = LIST_MENU_HEIGHT, .pal = 14, .start_tile = 1 + (HEADER_WIDTH * HEADER_HEIGHT) + (DESCRIPTION_WIDTH * DESCRIPTION_HEIGHT)},
    [TBOX_REWARD] = {.bg_id = 0, .x = 3 + LIST_MENU_WIDTH, .y = 2, .w = REWARDS_WIDTH, .h = REWARDS_HEIGHT, .pal = 14, .start_tile = 1 + (HEADER_WIDTH * HEADER_HEIGHT) + (DESCRIPTION_WIDTH * DESCRIPTION_HEIGHT) + (LIST_MENU_WIDTH * LIST_MENU_HEIGHT)},
    [TBOX_CNT] = {.bg_id = 0xFF},
};

static const graphic achievement_level_icon_graphic = {
    .sprite = &gfx_achievements_level_iconsTiles,
    .size = GRAPHIC_SIZE_4BPP(32, 128),
    .tag = ACHIEVEMENTS_LEVEL_ICON_TAG,
};

static const graphic achievement_progress_bar_graphic = {
    .sprite = &gfx_achievements_progress_barTiles,
    .size = GRAPHIC_SIZE_4BPP(64, 32),
    .tag = ACHIEVEMENTS_PROGRESS_BAR_TAG,
};

static const palette achievement_level_icon_palette = {
    .pal = &gfx_achievements_level_iconsPal,
    .tag = ACHIEVEMENTS_LEVEL_ICON_TAG,
};

static const palette achievement_progress_bar_palette = {
    .pal = &gfx_achievements_progress_barPal,
    .tag = ACHIEVEMENTS_PROGRESS_BAR_TAG,
};

static const sprite achievement_level_icon_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE,
    .attr1 = ATTR1_SIZE_32_32,
    .attr2 = ATTR2_PRIO(0),
};

static const sprite achievement_progress_bar_sprite = {
    .attr0 = ATTR0_SHAPE_HORIZONTAL,
    .attr1 = ATTR1_SIZE_64_32,
    .attr2 = ATTR2_PRIO(3),
};

static const gfx_frame achievement_level_icon_anim_bronze[] = {
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 0},
    {.data = GFX_ANIM_END},
};

static const gfx_frame achievement_level_icon_anim_silver[] = {
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 0},
    {.data = GFX_ANIM_END},
};

static const gfx_frame achievement_level_icon_anim_gold[] = {
    {.data = 2 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 0},
    {.data = GFX_ANIM_END},
};

static const gfx_frame achievement_level_icon_anim_platinum[] = {
    {.data = 3 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 0},
    {.data = GFX_ANIM_END},
};

static const gfx_frame *const achievement_level_icon_anims[] = {
    [ACHIEVEMENT_LEVEL_BRONZE] = achievement_level_icon_anim_bronze,
    [ACHIEVEMENT_LEVEL_SILVER] = achievement_level_icon_anim_silver,
    [ACHIEVEMENT_LEVEL_GOLD] = achievement_level_icon_anim_gold,
    [ACHIEVEMENT_LEVEL_PLATINUM] = achievement_level_icon_anim_platinum,
};

static const oam_template achievement_level_icon_template = {
    .tiles_tag = ACHIEVEMENTS_LEVEL_ICON_TAG,
    .pal_tag = ACHIEVEMENTS_LEVEL_ICON_TAG,
    .oam = &achievement_level_icon_sprite,
    .animation = achievement_level_icon_anims,
    .graphics = NULL,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static const oam_template achievement_progress_bar_template = {
    .tiles_tag = ACHIEVEMENTS_PROGRESS_BAR_TAG,
    .pal_tag = ACHIEVEMENTS_PROGRESS_BAR_TAG,
    .oam = &achievement_progress_bar_sprite,
    .animation = oam_gfx_anim_table_null,
    .graphics = &achievement_progress_bar_graphic,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static const u8 str_achievements_header_title[] = LANGDEP(PSTRING("Erfolge"), PSTRING("Achievements"));
static const u8 str_achievements_header_rewards[] = LANGDEP(PSTRING("Belohnung"), PSTRING("Rewards"));
static const u8 str_achievements_claim[] = LANGDEP(PSTRING("KEY_ANehmen"), PSTRING("KEY_AClaim"));
static const u8 str_achievements_header_count_separator[] = PSTRING("/");
static const u8 str_achievements_progress_separator[] = PSTRING("/");

static void achievements_get_counts(u16 *completed, u16 *unlocked, u16 *total) {
    *completed = 0;
    *unlocked = 0;
    *total = NUM_ACHIEVEMENT_GROUPS;

    for (u8 i = 0; i < NUM_ACHIEVEMENT_GROUPS; i++) {
        const achievement_group_t *group = achievement_groups + i;
        if (!group->is_unlocked()) {
            continue;
        }

        ++(*unlocked);
        u8 tail_idx = achievement_group_get_tail_idx(group);
        const achievement_t *tail = group->achievements + tail_idx;
        if (tail->is_achieved()) {
            ++(*completed);
        }
    }
}


static void achievements_build_header_count_string(u8 *dst) {
    u16 completed, unlocked, total;
    u8 number[4];
    achievements_get_counts(&completed, &unlocked, &total);

    itoa(dst, completed, ITOA_PAD_SPACES, 2);
    itoa(number, unlocked, ITOA_PAD_SPACES, 2);
    strcat(dst, str_achievements_header_count_separator);
    strcat(dst, number);
    itoa(number, total, ITOA_PAD_SPACES, 2);
    strcat(dst, str_achievements_header_count_separator);
    strcat(dst, number);
}

static void list_menu_print_callback_null(u8 tbox_idx, int idx, u8 y) {
    if (idx < 0 || idx >= NUM_ACHIEVEMENT_GROUPS) {
        return;
    }

    const achievement_group_t *group = achievement_groups + achievements_ui_state->achievements[idx];
    const achievement_t *tail = group->achievements + achievement_group_get_tail_idx(group);
    u16 progress = 0;
    if (tail->get_progress != NULL) {
        progress = tail->get_progress();
    }

    itoa(strbuf, progress, ITOA_PAD_SPACES, 3);
    strcat(strbuf, str_achievements_progress_separator);
    itoa(buffer0, tail->max_progress, ITOA_PAD_SPACES, 3);
    strcat(strbuf, buffer0);

    tbox_print_string(tbox_idx, 0, ACHIEVEMENTS_LIST_ITEM_X + 47,
                      (u16)(y + font_get_attribute(ACHIEVEMENTS_LIST_FONT,
                                                   FONT_ATTRIBUTE_MAX_LETTER_HEIGHT) - 5),
                      0, 0, &((const tbox_font_colormap){0, 1, 2, 3}), 0xFF, strbuf);
}

static void list_menu_cursor_moved_callback(int idx, u8 is_on_initialization, list_menu *list) {
    list_menu_generic_cursor_callback(idx, is_on_initialization, list);
    if (is_on_initialization || achievements_ui_state->process_input_callback_idx == 0xFF) {
        return;
    }
    achievements_update_level_icon_oams(); // This is cheap to do
    big_callbacks[achievements_ui_state->process_input_callback_idx].function = achievements_update_selected;
}

static const list_menu_template achievements_list_menu_template = {
    .items = NULL,
    .cursor_moved_callback = list_menu_cursor_moved_callback,
    .item_print_callback = list_menu_print_callback_null,
    .item_cnt = NUM_ACHIEVEMENT_GROUPS,
    .max_items_showed = REWARDS_UI_NUM_ITEMS_SHOWN,
    .tbox_idx = TBOX_LIST_MENU,
    .header_x = 0,
    .item_x = ACHIEVEMENTS_LIST_ITEM_X,
    .cursor_x = 4,
    .up_text_y = 0, // vertical padding of the menu relative to box rectangle
    .cursor_pal = 2,
    .fill_value = 0,
    .cursor_shadow_color = 3,
    .letter_spacing = 1,
    .item_vertical_padding = 7,
    .scroll_multiple = 0,
    .font = ACHIEVEMENTS_LIST_FONT};

static inline s16 achievements_level_icon_x(void) {
    return (s16)(((ui_tboxes[TBOX_LIST_MENU].x) * 8) - 11);
}

static inline s16 achievements_level_icon_y(u8 row) {
    const u8 font_height = font_get_attribute(achievements_list_menu_template.font, FONT_ATTRIBUTE_MAX_LETTER_HEIGHT);
    return (s16)(ui_tboxes[TBOX_LIST_MENU].y * 8 + achievements_list_menu_template.up_text_y +
                 font_height / 2 + row * (font_height + achievements_list_menu_template.item_vertical_padding) + 5);
}

#define PROGRESS_BAR_WIDTH 58

static void achievements_update_level_icon_oams(void) {
    u16 scroll_offset, row;
    (void)row;
    list_menu_get_scroll_and_row(achievements_ui_state->list_menu_callback_idx, &scroll_offset, &row);

    for (u8 i = 0; i < REWARDS_UI_NUM_ITEMS_SHOWN; i++) {
        const u8 oam_idx = achievements_ui_state->oam_idxs[i];
        oam_object *icon = oams + oam_idx;
        oam_object *progress_bar = oams + achievements_ui_state->oam_idxs_progress[i];

        if (scroll_offset + i >= NUM_ACHIEVEMENT_GROUPS) {
            icon->flags |= OAM_FLAG_INVISIBLE;
            progress_bar->flags |= OAM_FLAG_INVISIBLE;
            continue;
        }

        const achievement_group_t *group = achievement_groups + achievements_ui_state->achievements[scroll_offset + i];
        const achievement_t *last_achieved = achievements_group_get_last_achieved(group);
        if (last_achieved == NULL) {
            icon->flags |= OAM_FLAG_INVISIBLE;
            progress_bar->flags |= OAM_FLAG_INVISIBLE;
            continue;
        }

        const achievement_t *tail = group->achievements + achievement_group_get_tail_idx(group);
        icon->x = achievements_level_icon_x();
        icon->y = achievements_level_icon_y(i);
        progress_bar->x = icon->x - 15;

        int progress = MIN(tail->get_progress(), tail->max_progress);
        progress_bar->x = (s16)(icon->x - 15  + ((PROGRESS_BAR_WIDTH * progress) / tail->max_progress));
        progress_bar->y = icon->y + 4;

        u8 level = MIN(ACHIEVEMENT_LEVEL_PLATINUM, last_achieved->level);
        oam_gfx_anim_start(icon, level);
        icon->flags &= (u16)(~OAM_FLAG_INVISIBLE);
        progress_bar->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    }
}

static void achievements_create_level_icon_oams(void) {
    for (u8 i = 0; i < REWARDS_UI_NUM_ITEMS_SHOWN; i++) {
        achievements_ui_state->oam_idxs[i] = oam_new_forward_search(&achievement_level_icon_template,
                                                                     0, 0, 0);
        oams[achievements_ui_state->oam_idxs[i]].flags |= OAM_FLAG_INVISIBLE;
        achievements_ui_state->oam_idxs_progress[i] = oam_new_forward_search(&achievement_progress_bar_template,
                                                                     0, 0, 0);
        oams[achievements_ui_state->oam_idxs_progress[i]].flags |= OAM_FLAG_INVISIBLE;
    }
}

static void achievements_setup_scroll_indicators(void) {
    scroll_indicator_template indicator_template = {
        .arrow0_type = SCROLL_ARROW_UP,
        .arrow0_x = (u8)((ui_tboxes[TBOX_LIST_MENU].x + ui_tboxes[TBOX_LIST_MENU].w / 2) * 8),
        .arrow0_y = (u8)(ui_tboxes[TBOX_LIST_MENU].y * 8 - 4),
        .arrow1_type = SCROLL_ARROW_DOWN,
        .arrow1_x = (u8)((ui_tboxes[TBOX_LIST_MENU].x + ui_tboxes[TBOX_LIST_MENU].w / 2) * 8),
        .arrow1_y = (u8)((ui_tboxes[TBOX_LIST_MENU].y + ui_tboxes[TBOX_LIST_MENU].h) * 8 - 4),
        .arrow0_threshold = 0,
        .arrow1_threshold = (u16)MAX(0, NUM_ACHIEVEMENT_GROUPS - REWARDS_UI_NUM_ITEMS_SHOWN),
        .tiles_tag = 111,
        .pal_tag = 111,
    };
    achievements_ui_state->scroll_indicator_callback_idx = scroll_indicator_new(&indicator_template,
                                                                                &achievements_ui_state->list_menu_scroll_offset);
    scroll_indicator_set_oam_priority(achievements_ui_state->scroll_indicator_callback_idx, 0, 0);
}

static void achievements_free(void) {
    if (achievements_ui_state->scroll_indicator_callback_idx != 0xFF) {
        scroll_indicator_delete(achievements_ui_state->scroll_indicator_callback_idx);
    }
    list_menu_remove(achievements_ui_state->list_menu_callback_idx, NULL, NULL);
    for (u8 i = 0; i < REWARDS_UI_NUM_ITEMS_SHOWN; i++) {
        if (achievements_ui_state->oam_idxs[i] < NUM_OAMS) {
            oam_free(oams + achievements_ui_state->oam_idxs[i]);
        }
    }
    oam_free_vram_by_tag(ACHIEVEMENTS_LEVEL_ICON_TAG);
    oam_palette_free(ACHIEVEMENTS_LEVEL_ICON_TAG);
    tbox_free_all();
    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    free(achievements_ui_state);
    achievements_ui_state = NULL;
}

static void achievements_exit(u8 self) {
    if (fading_is_active() || dma3_busy(-1)) {
        return;
    }
    u8 opened_from_script = achievements_ui_state->opened_from_script;
    achievements_save_cursor();
    achievements_ui_cursor.return_to_achievements = 0;
    achievements_free();
    if (opened_from_script) {
        map_reload();
        overworld_script_resume();
    } else {
        map_reload_continuation = map_reload_continuation_exit_warp;
        callback1_set(super.saved_callback);
    }
    big_callback_delete(self);
}

void achievements_get_return_to_achievements_to_lastresult() {
    lastresult = achievements_ui_cursor.return_to_achievements > 0;
}

static void achievements_exit_to_script(u8 self) {
    if (fading_is_active() || dma3_busy(-1)) {
        return;
    }

    const u8 *script = achievements_ui_state->script_to_execute;
    achievements_save_cursor();
    achievements_ui_cursor.return_to_achievements = 1;
    achievements_free();
    overworld_script_init(script);
    callback1_set(map_reload);
    big_callback_delete(self);
}

static const achievement_group_t *achievements_get_selected_group(void) {
    return achievement_groups + achievements_get_selected_group_idx();
}

static u8 achievements_get_selected_group_idx(void) {
    u16 scroll_offset, row;
    list_menu_get_scroll_and_row(achievements_ui_state->list_menu_callback_idx, &scroll_offset, &row);
    return achievements_ui_state->achievements[scroll_offset + row];
}

static void achievements_save_cursor(void) {
    achievements_ui_cursor.cursor = (u8)(achievements_get_selected_group_idx() & 0x7F);
}

static void achievements_get_initial_cursor(u16 *scroll_offset, u16 *row) {
    u16 sorted_idx = 0;
    u8 cursor = achievements_ui_cursor.cursor;
    if (cursor >= NUM_ACHIEVEMENT_GROUPS) {
        cursor = 0;
    }

    for (u16 i = 0; i < NUM_ACHIEVEMENT_GROUPS; i++) {
        if (achievements_ui_state->achievements[i] == cursor) {
            sorted_idx = i;
            break;
        }
    }

    *row = MIN(sorted_idx, REWARDS_UI_NUM_ITEMS_SHOWN - 1);
    *scroll_offset = (u16)(sorted_idx - *row);
}

static const achievement_t *achievements_group_get_first_claimable_reward(const achievement_group_t *group) {
    u8 tail_idx = achievement_group_get_tail_idx(group);
    for (u8 i = 0; i <= tail_idx; i++) {
        const achievement_t *achievement = group->achievements + i;
        if (ACHIEVEMENT_HAS_REWARD(achievement) && achievement->is_achieved() &&
            !ACHIEVEMENT_REWARD_TAKEN(achievement)) {
            return achievement;
        }
    }
    return NULL;
}

static const achievement_t *achievements_group_get_last_achieved(const achievement_group_t *group) {
    const achievement_t *last_achieved = NULL;
    for (u8 i = 0; i < group->num_achievements; i++) {
        const achievement_t *achievement = group->achievements + i;
        if (achievement->is_achieved()) {
            last_achieved = achievement;
        }
    }
    return last_achieved;
}

static bool achievements_group_has_claimable_reward(const achievement_group_t *group) {
    return achievements_group_get_first_claimable_reward(group) != NULL;
}

static void achievements_print_header_static(void) {
    u8 count_str[12];
    achievements_build_header_count_string(count_str);

    tbox_flush_set(TBOX_HEADER, 0);
    tbox_print_string(TBOX_HEADER, 2, 4, 1, 0, 0,
                      &((const tbox_font_colormap){0, 1, 2, 3}), 0,
                      str_achievements_header_title);
    tbox_print_string(TBOX_HEADER, 2,
                      (u16)(8 + string_get_width(2, str_achievements_header_title, 0)),
                      1, 0, 0, &((const tbox_font_colormap){0, 1, 2, 3}), 0,
                      count_str);
    tbox_print_string(TBOX_HEADER, 2, 124, 1, 0, 0,
                      &((const tbox_font_colormap){0, 1, 2, 3}), 0,
                      str_achievements_header_rewards);
    achievements_ui_state->claim_note_visible = false;
    bg_virtual_sync_reqeust_push(ui_tboxes[TBOX_HEADER].bg_id);
}

static void achievements_update_claim_note(bool show_claim) {
    if (achievements_ui_state->claim_note_visible == show_claim) {
        return;
    }

    tbox_fill_rectangle(TBOX_HEADER, 0, HEADER_CLAIM_NOTE_X, HEADER_CLAIM_NOTE_Y,
                        HEADER_CLAIM_NOTE_WIDTH, HEADER_CLAIM_NOTE_HEIGHT);
    if (show_claim) {
        tbox_print_string(TBOX_HEADER, 2, HEADER_CLAIM_NOTE_X, 1, 0, 0,
                          &((const tbox_font_colormap){0, 4, 5, 3}), 0,
                          str_achievements_claim);
    }
    achievements_ui_state->claim_note_visible = show_claim;
    bg_virtual_sync_reqeust_push(ui_tboxes[TBOX_HEADER].bg_id);
}

void achievements_update_reward_and_description_and_level_icons() {
    u16 scroll_offset, row;
    list_menu_get_scroll_and_row(achievements_ui_state->list_menu_callback_idx, &scroll_offset, &row);
    achievements_ui_state->list_menu_scroll_offset = scroll_offset;
    achievements_ui_state->list_menu_row = row;
    achievements_update_level_icon_oams();
    const achievement_group_t *group = achievement_groups + achievements_ui_state->achievements[scroll_offset + row];
    achievements_update_claim_note(achievements_group_has_claimable_reward(group));
    tbox_flush_set(TBOX_REWARD, 0x00);
    const achievement_t *achievement_with_reward = achievements_group_get_first_claimable_reward(group);
    const achievement_t *tail = group->achievements + achievement_group_get_tail_idx(group);
    const u8 *reward_str = NULL;

    if (achievement_with_reward && ACHIEVEMENT_HAS_REWARD(achievement_with_reward)) {  
        reward_str = achievement_with_reward->reward.description;
    } else if (ACHIEVEMENT_HAS_REWARD(tail) && !ACHIEVEMENT_REWARD_TAKEN(tail)) {
        reward_str = tail->reward.description;
    }
    if (reward_str) {
        tbox_print_string(TBOX_REWARD, 1, 0, 4, 0, 0,
                        &((const tbox_font_colormap){0, 1, 2, 3}), 0,
                        reward_str);
    } else {
        tbox_sync(TBOX_REWARD, TBOX_SYNC_SET);
    }
    tbox_flush_set(TBOX_DESCRIPTION, 0x00);
    tbox_print_string(TBOX_DESCRIPTION, 1, 4, 0, 0, 0,
                        &((const tbox_font_colormap){0, 1, 2, 3}), 0,
                        tail->description);

    bg_virtual_sync_reqeust_push(ui_tboxes[TBOX_REWARD].bg_id);
    bg_virtual_sync_reqeust_push(ui_tboxes[TBOX_DESCRIPTION].bg_id);
}

void achievements_update_selected(u8 self) {
    achievements_update_reward_and_description_and_level_icons();
    big_callbacks[self].function = achievements_process_input;
}

void achievements_initialize_state_machine() {
    DEBUG("Achievements UI initialization state: %d", achievements_ui_state->initialization_state);
    switch (achievements_ui_state->initialization_state) {
    case RESET: {
        dma0_reset_callback();
        oam_reset();
        big_callback_delete_all();
        fading_cntrl_reset();
        oam_palette_allocation_reset();
        vblank_handler_set(NULL);
        bg_reset(0);
        bg_setup(0, bg_configs, ARRAY_COUNT(bg_configs));
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case BG_SETUP: {
        bg_set_tilemap(0, malloc_and_clear(0x800));
        bg_set_tilemap(1, malloc_and_clear(0x1000));
        bg_set_tilemap(2, malloc_and_clear(0x800));
        bg_sync_display_and_show(0);
        bg_sync_display_and_show(1);
        bg_sync_display_and_show(2);
        bg_display_sync();
        bg_virtual_map_displace(0, 0, 0);
        bg_virtual_set_displace(0, 0, 0);
        bg_virtual_map_displace(1, 0, 0);
        bg_virtual_set_displace(1, 0, 0);
        bg_virtual_map_displace(2, 0, 0);
        bg_virtual_set_displace(2, 0, 0);
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case GFX_LOAD: {
        int zero = 0;
        CPUSETFILL16(&zero, CHARBASE(bg_configs[0].char_base), 32);
        CPUSETFILL16(&zero, CHARBASE(bg_configs[2].char_base), 32);
        lz77uncompvram(gfx_achievements_ui_bgTiles, CHARBASE(bg_configs[1].char_base));
        lz77uncompwram(gfx_achievements_ui_bgMap, bg_get_tilemap(1));
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case DATA_SETUP: {
        for (u8 i = 0; i < REWARDS_UI_NUM_ITEMS_SHOWN; i++) {
            achievements_ui_state->oam_idxs[i] = NUM_OAMS;
        }
        achievements_ui_state->scroll_indicator_callback_idx = 0xFF;
        achievements_ui_state->process_input_callback_idx = 0xFF;
        achievements_ui_state->claim_note_visible = false;
        achievements_ui_state->script_to_execute = NULL;
        achievements_ui_state->list_menu_scroll_offset = 0;
        achievements_ui_state->list_menu_row = 0;
        sort_achievements();
        // DEBUG("Sorted achievements:\n");
        // for (u8 i = 0; i < NUM_ACHIEVEMENT_GROUPS; i++) {
        //     DEBUG("Achievement group %d, name 0x%x, unlocked %d\n", achievements_ui_state->achievements[i], achievement_groups[achievements_ui_state->achievements[i]].name, achievement_groups[achievements_ui_state->achievements[i]].is_unlocked());
        // }
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case TBOX_SETUP: {
        tbox_sync_with_virtual_bg_and_init_all(ui_tboxes);
        for (u8 i = 0; i < TBOX_CNT; i++) {
            tbox_tilemap_draw(i);
        }
        achievements_print_header_static();
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case BUILD_LIST_MENU: {
        u16 scroll_offset, row;
        achievements_ui_state->list_menu_template = achievements_list_menu_template;
        for (u8 i = 0; i < NUM_ACHIEVEMENT_GROUPS; i++) {
            u8 *dst = achievements_ui_state->achievements_item_strings[i];
            strcpy(dst, achievement_groups[achievements_ui_state->achievements[i]].name);
            achievements_ui_state->list_menu_items[i].text = dst;
            achievements_ui_state->list_menu_items[i].idx = i;
        }
        achievements_ui_state->list_menu_template.items = achievements_ui_state->list_menu_items;
        achievements_ui_state->list_menu_template.item_cnt = NUM_ACHIEVEMENT_GROUPS;
        achievements_get_initial_cursor(&scroll_offset, &row);
        achievements_ui_state->list_menu_scroll_offset = scroll_offset;
        achievements_ui_state->list_menu_row = row;
        achievements_ui_state->list_menu_callback_idx = list_menu_new(&achievements_ui_state->list_menu_template,
                                                                      scroll_offset, row);
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case PAL_SETUP: {
        pal_copy(tbox_palette_transparent, 15 * 16, 16 * sizeof(color_t));
        pal_decompress(gfx_achievements_ui_bgPal, 0, 16 * sizeof(color_t));
        pal_copy(&((color_t){.rgb = {.red = 31, .green = 31, .blue = 31}}), 0, sizeof(color_t)); // White backdrop
        oam_load_graphic_using_heap(&achievement_level_icon_graphic);
        oam_load_palette_using_heap(&achievement_level_icon_palette);
        oam_load_graphic_using_heap(&achievement_progress_bar_graphic);
        oam_load_palette_using_heap(&achievement_progress_bar_palette);
        CPUSETCOPY16(pals, pal_restore, 16);
        pal_set_all_to_black();
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case OAM_SETUP: {
        achievements_create_level_icon_oams();
        achievements_update_reward_and_description_and_level_icons();
        ++(achievements_ui_state->initialization_state);
        FALL_THROUGH;
    }
    case CURSOR_SETUP: {
        achievements_setup_scroll_indicators();
        ++(achievements_ui_state->initialization_state);
        FALL_THROUGH;
    }
    case BG_COPY: {
        bg_virtual_sync(0);
        bg_virtual_sync(1);
        bg_virtual_sync(2);
        ++(achievements_ui_state->initialization_state);
        FALL_THROUGH;
    }
    case FADE_TO_IDLE: {
        callback1_set(generic_callback1);
        vblank_handler_set(generic_vblank_handler);
        fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
        achievements_ui_state->process_input_callback_idx = big_callback_new(achievements_process_input, 0);
        ++(achievements_ui_state->initialization_state);
        break;
    }
    }
}

void achievements_allocate_and_initialize() {
    achievements_ui_state = malloc_and_clear(sizeof(achievements_ui_state_t));
    achievements_ui_state->initialization_state = RESET;
    callback1_set(achievements_initialize_state_machine);
    io_bic(IO_DISPCNT, 0);
}

static void achievements_ui_initialize_from_overworld_callback(UNUSED u8 self) {
    if (fading_is_active() || dma3_busy(-1)) {
        return;
    }
    overworld_rain_sound_fade_out();
    overworld_free();
    achievements_allocate_and_initialize();
    achievements_ui_state->opened_from_script = true;
}

void achievements_ui_initialize_from_overworld(void) {
    fadescreen_all(FADE_TO_BLACK, 0);
    big_callback_new(achievements_ui_initialize_from_overworld_callback, 0);
}

bool start_menu_achievements_initialize() {
    if (!fading_control.active) {
        overworld_rain_sound_fade_out();
        start_menu_delete_safari();
        overworld_free();
        callback1_set(achievements_allocate_and_initialize);
        super.saved_callback = map_reload_and_open_start_menu;
        return true;
    }
    return false;
}
