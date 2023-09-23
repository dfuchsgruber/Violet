#include "types.h"
#include "crafting.h"
#include "item/item.h"
#include "bg.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "ev_menu.h"
#include "field_move.h"
#include "pokemon/basestat.h"
#include "pokemon/sprites.h"
#include "pokemon/names.h"
#include "pokemon/cry.h"
#include "color.h"
#include "superstate.h"
#include "constants/pokemon_attributes.h"
#include "language.h"
#include "agbmemory.h"
#include "io.h"
#include "bios.h"
#include "music.h"
#include "overworld/map_control.h"
#include "overworld/script.h"
#include "overworld/pokemon_party_menu.h"
#include "fading.h"
#include "text.h"
#include "agbmemory.h"
#include "math.h"
#include "debug.h"
#include "attack.h"
#include "gpu.h"
#include "vram.h"
#include "constants/species.h"
#include "transparency.h"
#include "dma.h"
#include "list_menu.h"
#include "vars.h"
#include "flags.h"
#include "menu_indicators.h"
#include "menu_util.h"

EWRAM crafting_ui_state_t *crafting_ui_state = NULL;

static void crafting_ui_switch_type_callback1();
static void crafting_ui_free();
static void crafting_ui_process_list_menu(u8 self);
static void crafting_ui_setup_list_menu();

static const bg_config crafting_ui_bg_configs[4] = {
    {.bg_id = 0, .char_base = 0, .map_base = 28, .size = 0, .color_mode = 0, .priority = 0},
    {.bg_id = 1, .char_base = 1, .map_base = 29, .size = 0, .color_mode = 0, .priority = 1},
    {.bg_id = 2, .char_base = 2, .map_base = 30, .size = 0, .color_mode = 0, .priority = 2},
    {.bg_id = 3, .char_base = 3, .map_base = 31, .size = 0, .color_mode = 0, .priority = 3},
};

static const u8 str_category[CRAFTING_TYPE_CNT][11] = {
    [CRAFTING_HEALING] = LANGDEP(PSTRING("Medizin"), PSTRING("Medicine")),
    [CRAFTING_POKEBALLS] = LANGDEP(PSTRING("Pokébälle"), PSTRING("Pokéballs")),
    [CRAFTING_JEWELS] = LANGDEP(PSTRING("Wertvolles"), PSTRING("Valuables")),
    [CRAFTING_EVOLUTION] = LANGDEP(PSTRING("Evolution"), PSTRING("Evolution")),
    [CRAFTING_MINTS] = LANGDEP(PSTRING("Minze"), PSTRING("Mints")),
    [CRAFTING_NUTRIENTS] = LANGDEP(PSTRING("Vitamine"), PSTRING("Nutrients")),
    [CRAFTING_BATTLE] = LANGDEP(PSTRING("Kampf"), PSTRING("Battle")),
};

static const u8 str_recipe[] = LANGDEP(PSTRING("Rezept"), PSTRING("Recipe"));

static const u8 str_textcolor_red[] = PSTRING("TEXT_SET_FG\x04TEXT_SET_SHADOW\x05");
static const u8 str_textcolor_black[] = PSTRING("TEXT_SET_FG\x02TEXT_SET_SHADOW\x03");

enum {TBOX_MESSAGE, TBOX_TYPE, TBOX_RECIPE, TBOX_DESCRIPTION, TBOX_INGREDIENTS, TBOX_LIST_MENU, TBOX_POSSESION, TBOX_CRAFTING_CNT, TBOX_CNT,};

static const tboxdata ui_tboxes[] = {
    [TBOX_MESSAGE] = {.bg_id = 0, .x = 2, .y = 15, .w = 26, .h = 4, .pal = 14, .start_tile = 1},
    [TBOX_TYPE] = {.bg_id = 1, .x = 2, .y = 0, .w = 8, .h = 2, .pal = 15, .start_tile = 1},
    [TBOX_RECIPE] = {.bg_id = 1, .x = 19, .y = 0, .w = 5, .h = 2, .pal = 15, .start_tile = 1 + (2 * 13)},
    [TBOX_DESCRIPTION] = {.bg_id = 1, .x = 5, .y = 14, .w = 24, .h = 6, .pal = 15, .start_tile = 1 + (2 * 13) + (5 * 2)},
    [TBOX_INGREDIENTS] = {.bg_id = 1, .x = 16, .y = 2, .w = 14, .h = 3 * MAX_NUM_INGREDIENTS, .pal = 14,
        .start_tile = 1 + (2 * 13) + (5 * 2) + (6 * 24)},
    [TBOX_LIST_MENU] = {.bg_id = 1, .x = 0, .y = 3, .w = 12, .h = 11, .pal = 14, 
        .start_tile = 1 + (2 * 13) + (5 * 2) + (6 * 24) + (14 * 3 * MAX_NUM_INGREDIENTS)},
    [TBOX_CRAFTING_CNT] = {.bg_id = 0, .x = 24, .y = 9, .w = 5, .h = 4, .pal = 14, .start_tile = 1 + 26 * 4,},
    [TBOX_POSSESION] = {.bg_id = 0, .x = 1, .y = 11, .w = 8, .h = 2, .pal = 14, .start_tile = 1 + 26 * 4 + 5 * 4,},
    [TBOX_CNT] = {.bg_id = 0xFF},
};

static const tboxdata ui_yes_no_box = {
    .bg_id = 0, .x = 21, .y = 9, .w = 6, .h = 4, .pal = 14, .start_tile = 1 + 15 * 26,
};

static const tbox_font_colormap fontcolmap_white_letters = {0, 1, 2, 3};
static const tbox_font_colormap fontcolmap_black_letters = {0, 2, 3, 1};

static crafting_recipe *crafting_ui_get_current_recipe() {
    u16 type = crafting_ui_state->type;
    u8 idx = crafting_ui_state->current_recipe_idx;
    if (idx == 0xFF || idx >= crafting_ui_state->num_crafting_recipies[type])
        return NULL;
    else
        return crafting_ui_state->recipies[type] + idx;
}

static void crafting_ui_update_ingredient_boxes() {
    crafting_recipe *recipe = crafting_ui_get_current_recipe();
    if (recipe) {
        for (size_t i = 0; i < MAX_NUM_INGREDIENTS; i++) {
            if (recipe->ingredients[i].count > 0) {
                bg_copy_rectangle(2, gfx_crafting_menu_bg2Map[0], 13, (u8)(2 + 3 * i), 17, 3);
            } else {
                bg_copy_rectangle(2, gfx_crafting_menu_bg2Map[3], 13, (u8)(2 + 3 * i), 17, 3);
            }
        }
    } else {
        for (size_t i = 0; i < MAX_NUM_INGREDIENTS; i++) {
            bg_copy_rectangle(2, gfx_crafting_menu_bg2Map[3], 13, (u8)(2 + 3 * i), 17, 3);
        }
    }
}

static void crafting_ui_update_tbox_type() {
    tbox_flush_set(TBOX_TYPE, 0);
    const u8 *str = str_category[crafting_ui_state->type];
    u16 x = (u16)((8 * ui_tboxes[TBOX_TYPE].w - string_get_width(2, str, 0)) / 2);
    tbox_print_string(TBOX_TYPE, 2, x, 1, 0, 0, &fontcolmap_white_letters, 0, str);
}

static const u8 str_exit_description[] = LANGDEP(PSTRING("Verlasse die Maschine."), PSTRING("Exit the machine."));

static void crafting_ui_update_description() {
    tbox_flush_set(TBOX_DESCRIPTION, 0);
    crafting_recipe *recipe = crafting_ui_get_current_recipe();
    if (recipe)
        tbox_print_string(TBOX_DESCRIPTION, 2, 0, 4, 0, 0, &fontcolmap_white_letters, 0, item_get_description(recipe->item));
    else
        tbox_print_string(TBOX_DESCRIPTION, 2, 0, 4, 0, 0, &fontcolmap_white_letters, 0, str_exit_description);
}

static void crafting_ui_update_item_oam(oam_object *oam, u16 item_new) {
    int tile = oam->final_oam.attr2 & 1023;
    const u8 *gfx = item_get_resource(item_new, false);
    lz77uncompwram(gfx, gp_tmp_buf);
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cpuset(gp_tmp_buf + (3 * y + x) * GRAPHIC_SIZE_4BPP(8, 8), (u8*)OAMCHARBASE(tile) + (4 * y + x) * GRAPHIC_SIZE_4BPP(8, 8),
                CPUSET_COPY | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8) | CPUSET_HALFWORD));
        }
    }
    u8 pal_idx = (oam->final_oam.attr2 >> 12) & 0xF;
    const u8 *pal = item_get_resource(item_new, true);
    pal_decompress(pal, (u16)(256 + 16 * pal_idx), sizeof(color_t) * 16);
}

static void crafting_ui_update_item_oams() {
    // Oams should be invisible when doing this...
    crafting_recipe *recipe = crafting_ui_get_current_recipe();
    if (recipe) {
        for (size_t i = 0; i < ARRAY_COUNT(crafting_ui_state->oams_ingredients); i++) {
            if (recipe->ingredients[i].count > 0) {
                // Reload palette and tile
                u16 item;
                if (recipe->ingredients[i].type == CRAFTING_INGREDIENT_ASH) {
                    item = ITEM_ASCHETASCHE;
                } else {
                    item = recipe->ingredients[i].item;
                }
                crafting_ui_update_item_oam(oams + crafting_ui_state->oams_ingredients[i], item);
            }
        }
        crafting_ui_update_item_oam(oams + crafting_ui_state->oam_item, recipe->item);
    } else {
        crafting_ui_update_item_oam(oams + crafting_ui_state->oam_item, ITEM_NA);
    }
}

static void crafting_ui_show_oams() {
    // All oams are assumed to be invisible
    crafting_recipe *recipe = crafting_ui_get_current_recipe();
    if (recipe) {
        for (size_t i = 0; i < ARRAY_COUNT(crafting_ui_state->oams_ingredients); i++) {
            if (recipe->ingredients[i].count > 0) {
                oams[crafting_ui_state->oams_ingredients[i]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
            }
        }
    }
    oams[crafting_ui_state->oam_item].flags &= (u16)(~OAM_FLAG_INVISIBLE);
}

static void crafting_ui_hide_oams() {
    for (u8 i = 0; i < ARRAY_COUNT(crafting_ui_state->oams_ingredients); i++) {
        oams[crafting_ui_state->oams_ingredients[i]].flags |= OAM_FLAG_INVISIBLE;
    }
    oams[crafting_ui_state->oam_item].flags |= OAM_FLAG_INVISIBLE;
}

static const u8 str_ash[] = LANGDEP(PSTRING("Asche"), PSTRING("Ash"));

static void crafting_ui_update_ingredient_texts() {
    tbox_flush_set(TBOX_INGREDIENTS, 0);
    crafting_recipe *recipe = crafting_ui_get_current_recipe();
    if (recipe) {
        for (size_t i = 0; i < MAX_NUM_INGREDIENTS; i++) {
            if (recipe->ingredients[i].count > 0) {
                bool requirements_fulfilled = ingredient_requirements_fulfilled(recipe->ingredients + i, 1);
                u16 y = (u16)(5 + 24 * i);
                const u8 *name;
                int required, posessed;
                if (recipe->ingredients[i].type == CRAFTING_INGREDIENT_ASH) {
                    name = str_ash;
                    required = recipe->ingredients[i].count * CRAFTING_INGREDIENT_ASH_MULTIPLIER;
                    posessed = *var_access(ASH);
                } else {
                    name = item_get_name(recipe->ingredients[i].item);
                    required = recipe->ingredients[i].count;
                    posessed = item_get_count(recipe->ingredients[i].item);
                }
                tbox_print_string(TBOX_INGREDIENTS, 2, 3, y, 0, 0, &fontcolmap_black_letters, 0xFF, name);
                u8 str_number[8];
                itoa(str_number, posessed, 0, 6);
                *strbuf = 0xFF;
                if (!requirements_fulfilled) {
                    strcat(strbuf, str_textcolor_red);
                    strcat(strbuf, str_number);
                    strcat(strbuf, str_textcolor_black);
                } else {
                    strcat(strbuf, str_number);
                }
                u8 str_slash[] = PSTRING("/");
                strcat(strbuf, str_slash);
                itoa(str_number, required, 0, 6);
                strcat(strbuf, str_number);
                u16 x = (u16)((8 * ui_tboxes[TBOX_INGREDIENTS].w) - string_get_width(2, strbuf, 0) - 6);
                tbox_print_string(TBOX_INGREDIENTS, 2, x, y, 0, 0, &fontcolmap_black_letters, 0, strbuf);
            }
        }
    } else {
        tbox_copy_to_vram(TBOX_INGREDIENTS, TBOX_COPY_TILESET);
    }
}

static const u8 str_exit[] = LANGDEP(PSTRING("Beenden"), PSTRING("Exit"));

static void crafting_ui_setup_recipies_and_list_menu_items() {
    for (u16 type = 0; type < CRAFTING_TYPE_CNT; type++) {
        const crafting_recipe *recipies = crafting_recipies_get_by_type(type);
        size_t recipe_cnt = crafting_get_num_recipies_by_type(type);
        crafting_ui_state->recipies[type] = malloc_and_clear(sizeof(crafting_recipe) * recipe_cnt);
        crafting_ui_state->list_menu_items[type] = malloc_and_clear(sizeof(list_menu_item) * (recipe_cnt + 1));
        crafting_ui_state->list_menu_item_strings[type] = malloc_and_clear(sizeof(u8*) * recipe_cnt);

        DEBUG("Allocated recipies @%x, list_menu_items @%x\n", crafting_ui_state->recipies[type], crafting_ui_state->list_menu_items[type]);

        for (u8 idx = 0; idx < recipe_cnt; idx++) {
            if (recipies[idx].flag == 0 || recipies[idx].flag == 0xFFFF || checkflag(recipies[idx].flag)) {
                u8 recipe_idx = crafting_ui_state->num_crafting_recipies[type]++;
                crafting_ui_state->recipies[type][recipe_idx] = recipies[idx];
                u8 *line_str = malloc(32);
                crafting_ui_state->list_menu_item_strings[type][recipe_idx] = line_str;
                #define STYLE_NAME_COUNT
                #ifdef STYLE_COUNT_NAME
                    u8 str_fontsize_small_x[] = PSTRING("FONT_SIZE_SMALL");
                    u8 str_times[] = PSTRING("× ");
                    line_str[0] = 0xFF;
                    line_str = strcat(line_str, str_fontsize_small_x);
                    itoa(line_str, crafting_ui_state->recipies[type][recipe_idx].count, ITOA_NO_PADDING, 1);
                    strcat(line_str, str_times);
                    strcat(line_str, item_get_name(crafting_ui_state->recipies[type][recipe_idx].item));
                #else
                    u8 font_size_small[] = PSTRING("FONT_SIZE_SMALL");
                    strcpy(line_str, font_size_small);
                    strcat(line_str, item_get_name(crafting_ui_state->recipies[type][recipe_idx].item));
                    u8 str_clear_to[] = PSTRING("SKIP\x42×");
                    // u8 str_clear_to[] = PSTRING("SKIP");
                    line_str = strcat(line_str, str_clear_to);
                    itoa(line_str, crafting_ui_state->recipies[type][recipe_idx].count, ITOA_NO_PADDING, 1);
                #endif
                DEBUG("Allocated recipe target name @0x%x, char 3 0x%x item name 0x%x\n\n", line_str, line_str[3], item_get_name(crafting_ui_state->recipies[type][recipe_idx].item));
                crafting_ui_state->list_menu_items[type][recipe_idx].text = crafting_ui_state->list_menu_item_strings[type][recipe_idx];
                crafting_ui_state->list_menu_items[type][recipe_idx].idx = (recipe_idx + 1);
            }
        }
        // Add the "exit" option for all lists
        int exit_idx = crafting_ui_state->num_crafting_recipies[type];
        crafting_ui_state->list_menu_items[type][exit_idx].text = str_exit;
        crafting_ui_state->list_menu_items[type][exit_idx].idx = (exit_idx + 1);
        DEBUG("Set up %d recipies for category %d\n", crafting_ui_state->num_crafting_recipies[type], type);
    }
}

static void list_menu_print_callback_null(u8 tbox_idx, int idx, u8 y) {
    (void)tbox_idx; (void)idx; (void)y;
} 

static const list_menu_template recipe_selection_list_menu_template = {
    .items = NULL,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = list_menu_print_callback_null,
    .item_cnt = 255, .max_items_showed = 5, .tbox_idx = TBOX_LIST_MENU,
    .header_x = 0, .item_x = 12, .cursor_x = 4, .up_text_y = 2, .cursor_pal = 2, .fill_value = 0,
    .cursor_shadow_color = 3, .letter_spacing = 1, .item_vertical_padding = 2, .scroll_multiple = 0,
    .font = 2
};

static void crafting_ui_setup_scroll_indicators() {
    scroll_indicator_template crafting_ui_scroll_indicator_template_up_down = {
        .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 6 * 8, .arrow0_y = 20,
        .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 6 * 8, .arrow1_y = 16 + 12 * 8,
        .arrow0_threshold = 0, 
        .arrow1_threshold = (u16) MAX(0, (crafting_ui_state->num_crafting_recipies[crafting_ui_state->type] + 1 - 
            recipe_selection_list_menu_template.max_items_showed)),
        .tiles_tag = 111,
        .pal_tag = 111,
    };
    crafting_ui_state->callback_scroll_indicators_up_down = scroll_indicator_new(&crafting_ui_scroll_indicator_template_up_down,
        crafting_ui_state->list_menu_cursor_positions + crafting_ui_state->type);
    scroll_indicator_set_oam_priority(crafting_ui_state->callback_scroll_indicators_up_down, 1, 1);
}

static void crafting_ui_setup_scroll_indicators_left_right() {
    scroll_indicator_template crafting_ui_scroll_indicator_template_left_right = {
        .arrow0_type = SCROLL_ARROW_LEFT, .arrow0_x = 12, .arrow0_y = 8,
        .arrow1_type = SCROLL_ARROW_RIGHT, .arrow1_x = 84, .arrow1_y = 8,
        .arrow0_threshold = 0, 
        .arrow1_threshold = CRAFTING_TYPE_CNT - 1,
        .tiles_tag = 112,
        .pal_tag = 112,
    };
    crafting_ui_state->callback_scroll_indicators_left_right = scroll_indicator_new(&crafting_ui_scroll_indicator_template_left_right,
    &crafting_ui_state->type);
    scroll_indicator_set_oam_priority(crafting_ui_state->callback_scroll_indicators_left_right, 1, 1);
}

static void crafting_ui_setup_quantity_selection_scroll_indicators() {
    scroll_indicator_template crafting_ui_scroll_indicator_template_up_down = {
        .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 27 * 8 - 4, .arrow0_y = 8 * 9,
        .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 27 * 8 - 4, .arrow1_y = 8 * 13,
        .arrow0_threshold = 0xFFFF, 
        .arrow1_threshold = (u16) (crafting_ui_state->max_quantity + 2),
        .tiles_tag = 111,
        .pal_tag = 111,
    };
    crafting_ui_state->callback_scroll_indicators_up_down = scroll_indicator_new(&crafting_ui_scroll_indicator_template_up_down,
        &crafting_ui_state->quantity);
    scroll_indicator_set_oam_priority(crafting_ui_state->callback_scroll_indicators_up_down, 0, 0);
}

static void crafting_ui_remove_scroll_indicators() {
    if (crafting_ui_state->callback_scroll_indicators_up_down == 0xFF)
        return;
    scroll_indicator_delete(crafting_ui_state->callback_scroll_indicators_up_down);
    crafting_ui_state->callback_scroll_indicators_up_down = 0xFF;
}

static void crafting_ui_remove_scroll_indicators_left_right() {
    if (crafting_ui_state->callback_scroll_indicators_left_right == 0xFF)
        return;
    scroll_indicator_delete(crafting_ui_state->callback_scroll_indicators_left_right);
    crafting_ui_state->callback_scroll_indicators_left_right = 0xFF;
}

static void crafting_ui_free_and_return_to_overworld() {
    crafting_ui_free();
    map_reload();
    overworld_script_resume();
}

static void crafting_ui_exit_and_continue_callback1() {
    fading_proceed();
    if (!fading_is_active()) {
        crafting_ui_state->exit_continuation();
    }
}

static void crafting_ui_exit_and_return_to_overworld() {
    crafting_ui_state->exit_continuation = crafting_ui_free_and_return_to_overworld;
    fadescreen_all(1, 0);
    callback1_set(crafting_ui_exit_and_continue_callback1);
}

static void crafting_ui_update_recipe_callback1() {
    oam_animations_proceed();
    oam_proceed();
    if (dma3_busy(-1))
        return;
    switch (crafting_ui_state->setup_state) {
        case 0: {
            crafting_ui_hide_oams();
            // Clear the tilemap of the ingredient texts as well as the description
            tbox_flush_map(TBOX_INGREDIENTS);
            tbox_flush_map(TBOX_DESCRIPTION);
            bg_virtual_sync(ui_tboxes[TBOX_INGREDIENTS].bg_id);
            break;
        }
        case 1 : {
            // Tilemaps are invisible, update the texts
            crafting_ui_update_ingredient_texts();
            crafting_ui_update_description();
            break;
        }
        case 2: {
            crafting_ui_update_item_oams();
            // Redraw the tilemaps and show them
            tbox_tilemap_draw(TBOX_INGREDIENTS);
            tbox_tilemap_draw(TBOX_DESCRIPTION);
            crafting_ui_update_ingredient_boxes();
            bg_virtual_sync(ui_tboxes[TBOX_INGREDIENTS].bg_id);
            bg_virtual_sync(2);
            break;
        }
        case 3: {
            crafting_ui_show_oams();
            callback1_set(generic_callback1);
            return;
        }
    }
    crafting_ui_state->setup_state++;
}

static void crafting_ui_synchronize_current_recipe_with_list_menu_cursor() {
    if (crafting_ui_state->recipe_selection_list_menu_callback == 0xFF)
        return; // No list menu available...
    u16 type = crafting_ui_state->type;
    int idx = crafting_ui_state->list_menu_items[type][
        crafting_ui_state->list_menu_cursor_positions[type] + crafting_ui_state->list_menu_cursor_above[type]].idx - 1; 
    crafting_ui_state->current_recipe_idx = (u8) idx;
}

static void crafting_ui_update_visible_recipe_if_necessary() {
    if (crafting_ui_state->recipe_selection_list_menu_callback == 0xFF)
        return; // No list menu available...
    u16 type = crafting_ui_state->type;
    list_menu_get_scroll_and_row(crafting_ui_state->recipe_selection_list_menu_callback, 
        crafting_ui_state->list_menu_cursor_positions + type, crafting_ui_state->list_menu_cursor_above + type);
    // We defined those indices to be 1-based
    int idx = crafting_ui_state->list_menu_items[type][
        crafting_ui_state->list_menu_cursor_positions[type] + crafting_ui_state->list_menu_cursor_above[type]].idx - 1; 
    if (idx != crafting_ui_state->current_recipe_idx) {
        crafting_ui_synchronize_current_recipe_with_list_menu_cursor();
        crafting_ui_state->setup_state = 0;
        // Update everything
        callback1_set(crafting_ui_update_recipe_callback1);
    }
}

static void crafting_ui_message_big_callback1() {
    generic_callback1();
    return; // Test this out
    tbox_proceed();
    oam_proceed();
    // Suspends bascially everything but the message callback
    if (fading_is_active() || dma3_busy(-1))
        return;
    u8 cb_idx = crafting_ui_state->message_callback;
    big_callbacks[cb_idx].function(cb_idx);
}

static void crafting_ui_list_menu_remove() {
    if (crafting_ui_state->recipe_selection_list_menu_callback != 0xFF) {
        list_menu_remove(crafting_ui_state->recipe_selection_list_menu_callback, 
            crafting_ui_state->list_menu_cursor_positions + crafting_ui_state->type, crafting_ui_state->list_menu_cursor_above + crafting_ui_state->type);
        crafting_ui_state->recipe_selection_list_menu_callback = 0xFF;
    }
    while (big_callback_is_active(crafting_ui_process_list_menu))
        big_callback_delete(big_callback_get_id(crafting_ui_process_list_menu));
}

static void crafting_ui_print_message(u8 callback_idx, const u8 *message, void (*continuation)(u8)) {
    tbox_flush_set(TBOX_MESSAGE, 0);
    tbox_tilemap_draw(TBOX_MESSAGE);
    tbox_print_string_and_continue(callback_idx, TBOX_MESSAGE, 256, 15, 2, tbox_get_set_speed(), message, continuation);
    callback1_set(crafting_ui_message_big_callback1);
    crafting_ui_list_menu_remove();
}

static void crafting_ui_message_continuation_delete_message_and_return_to_selection(u8 self) {
    // Wait for a key-press
    if (super.keys_new.value) {
        tbox_clear_message(TBOX_MESSAGE, true);
        // bg_virtual_sync(ui_tboxes[TBOX_MESSAGE].bg_id);
        callback1_set(generic_callback1);
        big_callback_delete(self);
        crafting_ui_setup_list_menu();
    }
}

static void crafting_ui_initialize_cauldron_scene() {
    crafting_recipe recipe = *crafting_ui_get_current_recipe();
    crafting_ui_state_t tmp = *crafting_ui_state;
    crafting_ui_free();
    cauldron_scene_initialize(&recipe, &tmp);
}

static void crafting_ui_process_yes_no_start_crafting(u8 self) {
    int idx = gp_list_menu_process_input_and_close_on_selection();
    switch (idx) {
        case 0: // Recipe will be crafted
            crafting_ui_state->quantity = 1; 
            crafting_ui_state->exit_continuation = crafting_ui_initialize_cauldron_scene;
            fadescreen_all(1, 0);
            callback1_set(crafting_ui_exit_and_continue_callback1);
            big_callback_delete(self);
            break;
        case -1: // Why is that not the standard values for the list menu input??
        case 1:
            callback1_set(generic_callback1);
            tbox_clear_message(TBOX_MESSAGE, true);
            big_callback_delete(self);
            crafting_ui_setup_scroll_indicators();
            crafting_ui_setup_scroll_indicators_left_right();
            crafting_ui_setup_list_menu();
            break;
        case -2:
            return;
    }
}

static void crafting_ui_message_continuation_yes_no_box(u8 self) {
    gp_list_menu_yes_no_new(&ui_yes_no_box, 2, 0, 2, 256 + 20, 14, 1);
    big_callbacks[self].function = crafting_ui_process_yes_no_start_crafting;
}

static void crafting_ui_print_quantity_to_craft() {
    tbox_flush_set(TBOX_CRAFTING_CNT, 0x11);
    u8 str_cross[] = PSTRING("x");
    strcpy(strbuf, str_cross);
    u8 str_number[4] = {0xFF};
    itoa(str_number, crafting_ui_state->quantity, ITOA_PAD_ZEROS, 2);
    strcat(strbuf, str_number);
    tbox_print_string(TBOX_CRAFTING_CNT, 1, 
        (u16) ((ui_tboxes[TBOX_CRAFTING_CNT].w * 8 - string_get_width(1, strbuf, 0)) / 2), 
        8, 0, 0, &fontcolmap_black_letters, 0, strbuf);
}

static const u8 str_possesion[] = LANGDEP(
    PSTRING("Besitz: "),
    PSTRING("Posession:")
);

static void crafting_ui_handle_count_selection(u8 self) {
    if (quantity_adjust_by_key_input(&crafting_ui_state->quantity, crafting_ui_state->max_quantity)) {
        crafting_ui_print_quantity_to_craft();
        bg_virtual_sync(0);
    }
    if (super.keys_new.keys.A) {
        crafting_ui_state->exit_continuation = crafting_ui_initialize_cauldron_scene;
        fadescreen_all(1, 0);
        callback1_set(crafting_ui_exit_and_continue_callback1);
        big_callback_delete(self);
    } else if (super.keys_new.keys.B) {
        callback1_set(generic_callback1);
        crafting_ui_remove_scroll_indicators();
        crafting_ui_setup_scroll_indicators();
        crafting_ui_setup_scroll_indicators_left_right();
        tbox_flush_map(TBOX_CRAFTING_CNT);
        tbox_flush_map(TBOX_POSSESION);
        tbox_flush_map_and_frame(TBOX_CRAFTING_CNT);
        tbox_flush_map_and_frame(TBOX_POSSESION);
        bg_virtual_sync(0);
        tbox_clear_message(TBOX_MESSAGE, true);
        big_callback_delete(self);
        crafting_ui_setup_list_menu();
    }
}

static void crafting_ui_message_continuation_prompt_count(u8 self) {
    tbox_flush_set(TBOX_POSSESION, 0x11);
    crafting_ui_state->max_quantity = (u8)MIN(99, recipe_max_count_with_requirements_fulfilled(crafting_ui_get_current_recipe()));
    crafting_ui_state->quantity = 1;
    crafting_ui_print_quantity_to_craft();
    tbox_print_string(TBOX_POSSESION, 2, 0, 0, 0, 0, &fontcolmap_black_letters, 0xFF, str_possesion);
    itoa(strbuf, item_get_count(crafting_ui_get_current_recipe()->item), ITOA_PAD_SPACES, 3);
    tbox_print_string(TBOX_POSSESION, 1, 40, 0, 0, 0, &fontcolmap_black_letters, 0, strbuf);
    tbox_frame_draw_outer(TBOX_CRAFTING_CNT, CRAFTING_BASE_TILE_FRAME_STD, CRAFTING_PAL_IDX_FRAME_STD);
    tbox_frame_draw_outer(TBOX_POSSESION, CRAFTING_BASE_TILE_FRAME_STD, CRAFTING_PAL_IDX_FRAME_STD);
    tbox_tilemap_draw(TBOX_CRAFTING_CNT);
    tbox_tilemap_draw(TBOX_POSSESION);
    if (crafting_ui_state->max_quantity > 1) {
        crafting_ui_setup_quantity_selection_scroll_indicators();
    }
    bg_virtual_sync(0);
    big_callbacks[self].function = crafting_ui_handle_count_selection;
}

static const u8 str_cant_craft[] = LANGDEP(
    PSTRING("Du hast nicht die nötigen Zutaten,\num dieses Item herzustellen."),
    PSTRING("You can't craft this item, because you\ndont posess all ingredients.")
);

static const u8 str_no_room[] = LANGDEP(
    PSTRING("Du hast nicht den nötigen Platz\nim Beutel dafür!"),
    PSTRING("Your bag doesn't have the necessary\nspace for that!")
);

static const u8 str_ask_crafting[] = LANGDEP(
    PSTRING("Möchtest du BUFFER_1\nherstellen?"),
    PSTRING("Do you want to craft\nBUFFER_1?")
); 

static const u8 str_ask_crafting_cnt[] = LANGDEP(
    PSTRING("Wie oft willst du das Rezept\nfür BUFFER_1 anwenden?"),
    PSTRING("How many times do you want to\nuse the recipe for BUFFER_1?")
);

static void crafting_ui_process_list_menu(u8 self) {
    (void)self;
    if (fading_is_active() || dma3_busy(-1))
        return;
    crafting_ui_update_visible_recipe_if_necessary();
    if (super.keys_new.keys.right && crafting_ui_state->type < (CRAFTING_TYPE_CNT - 1)) {
        play_sound(5);
        crafting_ui_state->type_to_switch_to = (u16) (crafting_ui_state->type + 1);
        crafting_ui_state->setup_state = 0;
        callback1_set(crafting_ui_switch_type_callback1);
        return;
    } else if (super.keys_new.keys.left && crafting_ui_state->type > 0) {
        play_sound(5);
        crafting_ui_state->type_to_switch_to = (u16) (crafting_ui_state->type -1);
        crafting_ui_state->setup_state = 0;
        callback1_set(crafting_ui_switch_type_callback1);
        return;
    }

    int idx = list_menu_process_input(crafting_ui_state->recipe_selection_list_menu_callback);
    if (idx == LIST_MENU_B_PRESSED || idx > crafting_ui_state->num_crafting_recipies[crafting_ui_state->type]) {
        crafting_ui_exit_and_return_to_overworld();
    } else if (idx != LIST_MENU_NOTHING_CHOSEN) { // A recipe was selected
        crafting_recipe *recipe = crafting_ui_get_current_recipe();
        if (recipe) {
            if (!recipe_requirements_fulfilled(recipe, 1)) {
                play_sound(5);
                // Print the string that the player doesn't have all ingredients. Suspend all callbacks other than that
                crafting_ui_print_message(self, str_cant_craft, crafting_ui_message_continuation_delete_message_and_return_to_selection);
            } else if (!item_has_room(recipe->item, recipe->count)) {
                crafting_ui_print_message(self, str_no_room, crafting_ui_message_continuation_delete_message_and_return_to_selection);
            } else if (recipe_max_count_with_requirements_fulfilled(crafting_ui_get_current_recipe()) > 1){
                crafting_ui_remove_scroll_indicators();
                crafting_ui_remove_scroll_indicators_left_right();
                strcpy(buffer0, item_get_name(recipe->item));
                crafting_ui_print_message(self, str_ask_crafting_cnt, crafting_ui_message_continuation_prompt_count);
            } else {
                crafting_ui_remove_scroll_indicators();
                crafting_ui_remove_scroll_indicators_left_right();
                strcpy(buffer0, item_get_name(recipe->item));
                crafting_ui_print_message(self, str_ask_crafting, crafting_ui_message_continuation_yes_no_box);
            }
        }
    }
}

static void crafting_ui_setup_list_menu() {
    crafting_ui_state->recipe_selection_list_menu_template = recipe_selection_list_menu_template;
    u16 type = crafting_ui_state->type;
    crafting_ui_state->recipe_selection_list_menu_template.item_cnt = (u16)(crafting_ui_state->num_crafting_recipies[type] + 1); 
    crafting_ui_state->recipe_selection_list_menu_template.items = crafting_ui_state->list_menu_items[type];
    DEBUG("Set up list menu for type %d with cursor @%d and %d above.\n", type, crafting_ui_state->list_menu_cursor_positions[type], crafting_ui_state->list_menu_cursor_above[type]);
    crafting_ui_state->recipe_selection_list_menu_callback = list_menu_new(&crafting_ui_state->recipe_selection_list_menu_template, 
        crafting_ui_state->list_menu_cursor_positions[type], crafting_ui_state->list_menu_cursor_above[type]);
    crafting_ui_synchronize_current_recipe_with_list_menu_cursor();
    if (!big_callback_is_active(crafting_ui_process_list_menu)) {
        big_callback_new(crafting_ui_process_list_menu, 0);
    }
}

static void crafting_ui_switch_type_callback1() {
    oam_animations_proceed();
    oam_proceed();
    fading_proceed();
    if (fading_is_active() || dma3_busy(-1))
        return;
    // DEBUG("Updating in state %d\n", crafting_ui_state->setup_state);
    switch (crafting_ui_state->setup_state) {
        case 0: {
            bg_hide(ui_tboxes[TBOX_INGREDIENTS].bg_id); // Hides the bg
            bg_display_sync();
            crafting_ui_hide_oams();
            crafting_ui_remove_scroll_indicators();
            break;
        }
        case 1: {
            crafting_ui_list_menu_remove();
            break;
        }
        case 2: {
            crafting_ui_state->type = crafting_ui_state->type_to_switch_to;
            crafting_ui_setup_list_menu();
            break;
        }
        case 3: {
            crafting_ui_update_tbox_type();
            crafting_ui_update_ingredient_texts();
            crafting_ui_update_description();
            break;
        }
        case 4: {
            crafting_ui_update_item_oams();
            crafting_ui_setup_scroll_indicators();
            crafting_ui_update_ingredient_boxes();
            bg_virtual_sync(2);
            break;
        }
        case 5: {
            crafting_ui_show_oams();
            bg_update_and_show(ui_tboxes[TBOX_INGREDIENTS].bg_id);
            bg_display_sync();
            callback1_set(generic_callback1);
            return;
        }
    }
    crafting_ui_state->setup_state++;
}

static void crafting_ui_free() {
    if (crafting_ui_state->callback_scroll_indicators_left_right != 0xFF)
        scroll_indicator_delete(crafting_ui_state->callback_scroll_indicators_left_right);
    if (crafting_ui_state->callback_scroll_indicators_up_down != 0xFF)
        scroll_indicator_delete(crafting_ui_state->callback_scroll_indicators_up_down);
    crafting_ui_list_menu_remove();
    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    free(bg_get_tilemap(3));
    for (u16 type = 0; type < CRAFTING_TYPE_CNT; type++) {
        for (int i = 0; i < crafting_ui_state->num_crafting_recipies[type]; i++)
            free(crafting_ui_state->list_menu_item_strings[type][i]);
        free(crafting_ui_state->recipies[type]);
        free(crafting_ui_state->list_menu_items[type]);
    }
    free(crafting_ui_state);
}


static void crafting_ui_setup() {
    // big_callback_proceed(); Don't proceed callbacks, as we proceed the list menu while we in fact are still setting stuff up
    fading_proceed();
    tbox_proceed();
    oam_animations_proceed();
    oam_proceed();
    *(u16*)0x02038604 = 0; //no idea why to do this, but needs to be done for some reason
    if (fading_is_active() || dma3_busy(-1))
        return;
    // DEBUG("Ui setup in state %d\n", crafting_ui_state->setup_state);
    switch (crafting_ui_state->setup_state) {
        case 0: {
            crafting_ui_setup_recipies_and_list_menu_items();
            crafting_ui_state->setup_state++;
            break;
        }
        case 1: {
            if (crafting_ui_state->initialized_from_overworld)
                overworld_free();
            else
                tbox_free_all();
            big_callback_delete_all();
            oam_reset();
            oam_palette_allocation_reset();
            dma0_reset_callback();
            crafting_ui_state->setup_state++;
            break;
        }
        case 2: {
            bg_reset(0); 
            bg_setup(0, crafting_ui_bg_configs, ARRAY_COUNT(crafting_ui_bg_configs));
            bg_virtual_map_displace(0, 0, 0);
            bg_virtual_set_displace(0, 0, 0);
            bg_virtual_map_displace(1, 0, 0);
            bg_virtual_set_displace(1, 0, 0);
            bg_virtual_map_displace(2, 0, 0);
            bg_virtual_set_displace(2, 0, 0);
            bg_virtual_map_displace(3, 0, 0);
            bg_virtual_set_displace(3, 0, 0);
            io_set(IO_BGHOFS(0), 0);
            io_set(IO_BGVOFS(0), 0);
            io_set(IO_BGHOFS(1), 0);
            io_set(IO_BGVOFS(1), 0);
            io_set(IO_BGHOFS(2), 0);
            io_set(IO_BGVOFS(2), 0);
            io_set(IO_BGHOFS(3), 0);
            io_set(IO_BGVOFS(3), 0);
            bg_set_tilemap(0, malloc_and_clear(0x800));
            bg_set_tilemap(1, malloc_and_clear(0x800));
            bg_set_tilemap(2, malloc_and_clear(0x800));
            bg_set_tilemap(3, malloc_and_clear(0x800));
            crafting_ui_state->setup_state++;
            break; 
        }
        case 3: {
            memset(CHARBASE(0), 0, 32);
            memset(CHARBASE(1), 0, 32);
            lz77uncompvram(gfx_crafting_menu_bg3Tiles, CHARBASE(3));
            lz77uncompvram(gfx_crafting_menu_bg2Tiles, CHARBASE(2));
            lz77uncompwram(gfx_crafting_menu_bg3Map, bg_get_tilemap(3));
            bg_fill_map_with_rectangle(2, gfx_crafting_menu_bg2Map[ARRAY_COUNT(gfx_crafting_menu_bg2Map) - 1][0], 0, 0, 32, 32, 1);
            crafting_ui_state->setup_state++;
            break;
        }
        case 4: {
            tbox_sync_with_virtual_bg_and_init_all(ui_tboxes);
            tbox_tilemap_draw(TBOX_TYPE);
            tbox_tilemap_draw(TBOX_RECIPE);
            tbox_tilemap_draw(TBOX_DESCRIPTION);
            tbox_tilemap_draw(TBOX_INGREDIENTS);
            tbox_tilemap_draw(TBOX_LIST_MENU);
            tbox_flush_set(TBOX_RECIPE, 0);
            tbox_print_string(TBOX_RECIPE, 2, 0, 1, 0, 0, &fontcolmap_white_letters, 0, str_recipe);
            crafting_ui_update_tbox_type();
            crafting_ui_state->setup_state++;
            break;
        }
        case 5: {
            crafting_ui_setup_list_menu();
            crafting_ui_state->setup_state++;
            break;
        }
        case 6: {
            // The current visible recipe was initialized with 0xFF, so we have to update depending on the cursor 0 position
            crafting_ui_update_ingredient_texts();
            crafting_ui_update_description();
            crafting_ui_update_ingredient_boxes(); // Now that we have a cursor we can start updating stuff
            crafting_ui_state->setup_state++;
            break;
        }
        case 7: {
            pal_decompress(gfx_crafting_menu_bg3Pal, 0, sizeof(color_t) * 16);
            pal_decompress(gfx_crafting_menu_bg2Pal, 16, sizeof(color_t) * 16);
            tbox_init_frame_message(TBOX_MESSAGE, 256, 15 * 16);
            tbox_init_frame_set_style(TBOX_MESSAGE, CRAFTING_BASE_TILE_FRAME_STD, CRAFTING_PAL_IDX_FRAME_STD * 16);
            // pal_copy(tbox_palette_transparent, 14 * 16, 32);
            pal_set_all_to_black();
            crafting_ui_state->setup_state++;
            break;
        }
        case 8: {
            bg_virtual_sync(0);
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            bg_virtual_sync(3);
            crafting_ui_state->setup_state++;
            break;
        }
        case 9: {
            crafting_ui_setup_scroll_indicators();
            crafting_ui_setup_scroll_indicators_left_right();
            crafting_ui_state->setup_state++;
            break;
        }
        case 10: {
            for (size_t i = 0; i < ARRAY_COUNT(crafting_ui_state->oams_ingredients) + 1; i++) {
                u16 tag = (u16)(0x1534 + i);
                u8 oam_idx = item_oam_new(tag, tag, ITEM_POKEBALL);
                // oams[oam_idx].flags &= (u16)(~OAM_FLAG_CENTERED);
                if (i < ARRAY_COUNT(crafting_ui_state->oams_ingredients)) {
                    crafting_ui_state->oams_ingredients[i] = oam_idx;
                    oams[oam_idx].x = 13 * 8 + 17;
                    oams[oam_idx].y = (s16)(2 * 8 + (24 * i) + 17);
                } else {
                    crafting_ui_state->oam_item = oam_idx;
                    oams[oam_idx].x = 8 + 16;
                    oams[oam_idx].y = 15 * 8 + 4 + 18;
                }
            }
            crafting_ui_hide_oams();
            crafting_ui_update_item_oams();
            pal_set_all_to_black();
            crafting_ui_state->setup_state++;
            break;
        }
        case 11: {
            crafting_ui_show_oams();
            bg_sync_display_and_show(0);
            bg_sync_display_and_show(1);
            bg_sync_display_and_show(2);
            bg_sync_display_and_show(3);
            bg_display_sync();
            crafting_ui_state->setup_state++;
            break;
        }
        case 12: {
            fadescreen_all(0, 0);
            crafting_ui_state->setup_state++;
            break;
        }
        case 13: {
            // Only now also big callbacks may start, i.e. the list menu
            callback1_set(generic_callback1);
            crafting_ui_state->setup_state++;
            break;
        }
    }
}

void crafting_ui_initialize() {
    crafting_ui_state = (crafting_ui_state_t*) malloc_and_clear(sizeof(crafting_ui_state_t));
    crafting_ui_state->recipe_selection_list_menu_callback = 0xFF;
    crafting_ui_state->callback_scroll_indicators_left_right = 0xFF;
    crafting_ui_state->callback_scroll_indicators_up_down = 0xFF;
    crafting_ui_state->current_recipe_idx = 0;
    crafting_ui_state->initialized_from_overworld = true;
    callback1_set(crafting_ui_setup);
    vblank_handler_set(generic_vblank_handler);
    io_bic(0, 0x6000);
}

void crafting_ui_reinitialize(u16 type, u16 list_menu_cursor_positions[CRAFTING_TYPE_CNT], u16 list_menu_cursor_above[CRAFTING_TYPE_CNT]) {
    crafting_ui_initialize();
    crafting_ui_state->initialized_from_overworld = false;
    (void) list_menu_cursor_positions;
    (void) list_menu_cursor_above;
    (void) type;
    return;
    crafting_ui_state->type = type;
    memcpy(crafting_ui_state->list_menu_cursor_positions, list_menu_cursor_positions, 0);//sizeof(crafting_ui_state->list_menu_cursor_positions));
    memcpy(crafting_ui_state->list_menu_cursor_above, list_menu_cursor_above, 0);// sizeof(crafting_ui_state->list_menu_cursor_above));
}