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
#include "overworld/map_control.h"
#include "overworld/start_menu.h"
#include "superstate.h"
#include "text.h"
#include "transparency.h"
#include "types.h"

EWRAM achievements_ui_state_t *achievements_ui_state = NULL;

void achievements_update_rewards(u8 self);

void achievements_process_input(u8 self) {
    (void)self;
    int input = list_menu_process_input(achievements_ui_state->list_menu_callback_idx);
    switch (input) {
    case LIST_MENU_B_PRESSED:
    case LIST_MENU_NOTHING_CHOSEN:
        break;
    default: {
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
    CURSOR_SETUP,
    BG_COPY,
    FADE_TO_IDLE,
};

static const bg_config bg_configs[] = {
    {.bg_id = 0, .char_base = 0, .map_base = 31, .size = 0, .color_mode = 0, .priority = 1},
    {.bg_id = 1, .char_base = 2, .map_base = 29, .size = 0, .color_mode = 0, .priority = 2},
    {.bg_id = 2, .char_base = 3, .map_base = 30, .size = 0, .color_mode = 0, .priority = 0},
};

static inline int achievement_to_key(u8 achievement_group) {
    const achievement_group_t *group = achievement_groups + achievement_group;
    const achievement_t *tail = group->achievements + achievement_group_get_tail_idx(group);
    if (group->is_unlocked()) {
        if (!tail->is_achieved())
            return (1 * 256) + achievement_group;
        else
            return 0 + achievement_group;
    } else {
        return (2 * 256) + achievement_group;
    }
}

void sort_achievements() {
    for (u8 i = 0; i < NUM_ACHIEVEMENT_GROUPS - 1; i++) {
        for (u8 j = 0; j < NUM_ACHIEVEMENT_GROUPS - i - 1; j++) {
            if (achievement_to_key(achievements_ui_state->achievements[j]) > achievement_to_key(achievements_ui_state->achievements[j + 1])) {
                u8 temp = achievements_ui_state->achievements[j];
                achievements_ui_state->achievements[j] = achievements_ui_state->achievements[j + 1];
                achievements_ui_state->achievements[j + 1] = temp;
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
#define HEADER_WIDTH 30
#define LIST_MENU_HEIGHT 16
#define LIST_MENU_WIDTH 15
#define DESCRIPTION_WIDTH 30
#define DESCRIPTION_HEIGHT 2
#define REWARDS_WIDTH (30 - LIST_MENU_WIDTH - 3)
#define REWARDS_HEIGHT LIST_MENU_HEIGHT

static const tboxdata ui_tboxes[TBOX_CNT + 1] = {
    [TBOX_HEADER] = {.bg_id = 0, .x = 0, .y = 0, .w = HEADER_WIDTH, .h = HEADER_HEIGHT, .pal = 14, .start_tile = 1},
    [TBOX_DESCRIPTION] = {.bg_id = 0, .x = 0, .y = 18, .w = DESCRIPTION_WIDTH, .h = DESCRIPTION_HEIGHT, .pal = 15, .start_tile = 1 + (HEADER_WIDTH * HEADER_HEIGHT)},
    [TBOX_LIST_MENU] = {.bg_id = 0, .x = 3, .y = 2, .w = LIST_MENU_WIDTH, .h = LIST_MENU_HEIGHT, .pal = 14, .start_tile = 1 + (HEADER_WIDTH * HEADER_HEIGHT) + (DESCRIPTION_WIDTH * DESCRIPTION_HEIGHT)},
    [TBOX_REWARD] = {.bg_id = 0, .x = 3 + LIST_MENU_WIDTH, .y = 2, .w = REWARDS_WIDTH, .h = REWARDS_HEIGHT, .pal = 14, .start_tile = 1 + (HEADER_WIDTH * HEADER_HEIGHT) + (DESCRIPTION_WIDTH * DESCRIPTION_HEIGHT) + (LIST_MENU_WIDTH * LIST_MENU_HEIGHT)},
    [TBOX_CNT] = {.bg_id = 0xFF},
};

static void list_menu_print_callback_null(UNUSED u8 tbox_idx, UNUSED int idx, UNUSED u8 y) {
}

static void list_menu_cursor_moved_callback(int idx, u8 is_on_initialization, list_menu *list) {
    list_menu_generic_cursor_callback(idx, is_on_initialization, list);
    big_callbacks[achievements_ui_state->process_input_callback_idx].function = achievements_update_rewards;
    }

static const list_menu_template achievements_list_menu_template = {
    .items = NULL,
    .cursor_moved_callback = list_menu_cursor_moved_callback,
    .item_print_callback = list_menu_print_callback_null,
    .item_cnt = NUM_ACHIEVEMENT_GROUPS,
    .max_items_showed = REWARDS_UI_NUM_ITEMS_SHOWN,
    .tbox_idx = TBOX_LIST_MENU,
    .header_x = 0,
    .item_x = 12,
    .cursor_x = 4,
    .up_text_y = 2, // vertical padding of the menu relative to box rectangle
    .cursor_pal = 2,
    .fill_value = 0,
    .cursor_shadow_color = 3,
    .letter_spacing = 1,
    .item_vertical_padding = 7,
    .scroll_multiple = 0,
    .font = 2};

void achievements_update_reward_and_description() {
    u16 scroll_offset, row;
    list_menu_get_scroll_and_row(achievements_ui_state->list_menu_callback_idx, &scroll_offset, &row);
    tbox_flush_set(TBOX_REWARD, 0x00);
    u8 tail_idx = achievement_group_get_tail_idx(achievement_groups + achievements_ui_state->achievements[scroll_offset + row]);
    const achievement_t *tail = achievement_groups[achievements_ui_state->achievements[scroll_offset + row]].achievements + tail_idx;
    if (ACHIEVEMENT_HAS_REWARD(tail) && (
        !tail->is_achieved() || (tail->is_achieved() && !ACHIEVEMENT_REWARD_TAKEN(tail))
    )) {  
        tbox_print_string(TBOX_REWARD, 1, 0, 0, 0, 0,
                        &((const tbox_font_colormap){0, 1, 2, 3}), 0,
                        tail->reward.description);
    }
    tbox_flush_set(TBOX_DESCRIPTION, 0x00);
    tbox_print_string(TBOX_DESCRIPTION, 1, 4, 0, 0, 0,
                        &((const tbox_font_colormap){0, 1, 2, 3}), 0,
                        tail->description);

    bg_virtual_sync_reqeust_push(ui_tboxes[TBOX_REWARD].bg_id);
    bg_virtual_sync_reqeust_push(ui_tboxes[TBOX_DESCRIPTION].bg_id);
}

void achievements_update_rewards(u8 self) {
    achievements_update_reward_and_description();
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
        for (u8 i = 0; i < NUM_ACHIEVEMENT_GROUPS; i++) {
            achievements_ui_state->achievements[i] = i;
        }
        sort_achievements();
        DEBUG("Sorted achievements:\n");
        for (u8 i = 0; i < NUM_ACHIEVEMENT_GROUPS; i++) {
            DEBUG("Achievement group %d, name 0x%x, unlocked %d\n", achievements_ui_state->achievements[i], achievement_groups[achievements_ui_state->achievements[i]].name, achievement_groups[achievements_ui_state->achievements[i]].is_unlocked());
        }
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case BUILD_LIST_MENU: {
        achievements_ui_state->list_menu_template = achievements_list_menu_template;
        for (u8 i = 0; i < NUM_ACHIEVEMENT_GROUPS; i++) {
            u8 *dst = achievements_ui_state->achievements_item_strings[i];
            strcpy(dst, achievement_groups[achievements_ui_state->achievements[i]].name);
            achievements_ui_state->list_menu_items[i].text = dst;
            achievements_ui_state->list_menu_items[i].idx = i;
            }
        achievements_ui_state->list_menu_template.items = achievements_ui_state->list_menu_items;
        achievements_ui_state->list_menu_template.item_cnt = NUM_ACHIEVEMENT_GROUPS;
        achievements_ui_state->list_menu_callback_idx = list_menu_new(&achievements_ui_state->list_menu_template, 0, 0);
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case PAL_SETUP: {
        pal_copy(tbox_palette_transparent, 15 * 16, 16 * sizeof(color_t));
        pal_decompress(gfx_achievements_ui_bgPal, 0, 16 * sizeof(color_t));
        CPUSETCOPY16(pals, pal_restore, 16);
        pal_set_all_to_black();
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case TBOX_SETUP: {
        tbox_sync_with_virtual_bg_and_init_all(ui_tboxes);
        for (u8 i = 0; i < TBOX_CNT; i++) {
            tbox_tilemap_draw(i);
        }
        tbox_flush_set(TBOX_HEADER, 0);
        tbox_print_string(TBOX_HEADER, 2, 4, 1, 0, 0,
                          &((const tbox_font_colormap){0, 1, 2, 3}), 0,
                          (const u8[])LANGDEP(PSTRING("Erfolge"), PSTRING("Achievements")));
        tbox_print_string(TBOX_HEADER, 2, 140, 1, 0, 0,
                          &((const tbox_font_colormap){0, 1, 2, 3}), 0,
                          (const u8[])LANGDEP(PSTRING("Belohnung"), PSTRING("Rewards")));
        achievements_update_reward_and_description();
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case CURSOR_SETUP: {
        ++(achievements_ui_state->initialization_state);
        break;
    }
    case BG_COPY: {
        bg_virtual_sync(0);
        bg_virtual_sync(1);
        bg_virtual_sync(2);
        ++(achievements_ui_state->initialization_state);
        break;
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

bool start_menu_achievements_initialize() {
    if (!fading_control.active) {
        overworld_rain_sound_fade_out();
        start_menu_delete_safari();
        overworld_free();
        callback1_set(achievements_allocate_and_initialize);
        return true;
    }
    return false;
}