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

static bg_config crafting_ui_bg_configs[4] = {
    {.bg_id = 0, .char_base = 0, .map_base = 28, .size = 0, .color_mode = 0, .priority = 0},
    {.bg_id = 1, .char_base = 1, .map_base = 29, .size = 0, .color_mode = 0, .priority = 1},
    {.bg_id = 2, .char_base = 2, .map_base = 30, .size = 0, .color_mode = 0, .priority = 2},
    {.bg_id = 3, .char_base = 3, .map_base = 31, .size = 0, .color_mode = 0, .priority = 3},
};

static u8 str_category[CRAFTING_TYPE_CNT][11] = {
    [CRAFTING_HEALING] = LANGDEP(PSTRING("Medizin"), PSTRING("Medicine")),
    [CRAFTING_POKEBALLS] = LANGDEP(PSTRING("Pokébälle"), PSTRING("Pokéballs")),
    [CRAFTING_JEWELS] = LANGDEP(PSTRING("Juwelen"), PSTRING("Jewels")),
    [CRAFTING_EVOLUTION] = LANGDEP(PSTRING("Evolution"), PSTRING("Evolution")),
    [CRAFTING_MINTS] = LANGDEP(PSTRING("Minze"), PSTRING("Mints")),
    [CRAFTING_NUTRIENTS] = LANGDEP(PSTRING("Vitamine"), PSTRING("Nutrients")),
};

static u8 str_recipe[] = LANGDEP(PSTRING("Rezept"), PSTRING("Recipe"));

static u8 str_textcolor_red[] = PSTRING("TEXT_SET_FG\x04TEXT_SET_SHADOW\x05");
static u8 str_textcolor_black[] = PSTRING("TEXT_SET_FG\x02TEXT_SET_SHADOW\x03");

enum {TBOX_TYPE, TBOX_RECIPE, TBOX_DESCRIPTION, TBOX_INGREDIENTS, TBOX_LIST_MENU, TBOX_CNT,};

static tboxdata ui_tboxes[] = {
    [TBOX_TYPE] = {.bg_id = 1, .x = 0, .y = 0, .w = 13, .h = 2, .pal = 15, .start_tile = 1},
    [TBOX_RECIPE] = {.bg_id = 1, .x = 19, .y = 0, .w = 5, .h = 2, .pal = 15, .start_tile = 1 + (2 * 13)},
    [TBOX_DESCRIPTION] = {.bg_id = 1, .x = 5, .y = 14, .w = 24, .h = 6, .pal = 15, .start_tile = 1 + (2 * 13) + (5 * 2)},
    [TBOX_INGREDIENTS] = {.bg_id = 1, .x = 16, .y = 2, .w = 14, .h = 3 * MAX_NUM_INGREDIENTS, .pal = 14,
        .start_tile = 1 + (2 * 13) + (5 * 2) + (6 * 24)},
    [TBOX_LIST_MENU] = {.bg_id = 1, .x = 1, .y = 3, .w = 11, .h = 11, .pal = 14, 
        .start_tile = 1 + (2 * 13) + (5 * 2) + (6 * 24) + (14 * 3 * MAX_NUM_INGREDIENTS)},
    [TBOX_CNT] = {.bg_id = 0xFF},
};

static tbox_font_colormap fontcolmap_white_letters = {0, 1, 2, 3};
static tbox_font_colormap fontcolmap_black_letters = {0, 2, 3, 1};

static crafting_recipe *crafting_ui_get_current_recipe() {
    u8 type = CRAFTING_UI_STATE->type;
    u8 idx = CRAFTING_UI_STATE->current_recipe_idx[type];
    if (idx == 0xFF || idx >= CRAFTING_UI_STATE->num_crafting_recipies[type])
        return NULL;
    else
        return CRAFTING_UI_STATE->recipies[type] + idx;
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
    u8 *str = str_category[CRAFTING_UI_STATE->type];
    u16 x = (u16)((8 * ui_tboxes[TBOX_TYPE].w - string_get_width(2, str, 0)) / 2);
    tbox_print_string(TBOX_TYPE, 2, x, 1, 0, 0, &fontcolmap_white_letters, 0, str);
}

static u8 str_exit_description[] = LANGDEP(PSTRING("Verlasse die Maschine."), PSTRING("Exit the machine."));

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
    u8 *gfx = item_get_resource(item_new, false);
    lz77uncompwram(gfx, gp_tmp_buf);
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cpuset(gp_tmp_buf + (3 * y + x) * GRAPHIC_SIZE_4BPP(8, 8), (u8*)OAMCHARBASE(tile) + (4 * y + x) * GRAPHIC_SIZE_4BPP(8, 8),
                CPUSET_COPY | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8) | CPUSET_HALFWORD));
        }
    }
    u8 pal_idx = (oam->final_oam.attr2 >> 12) & 0xF;
    u8 *pal = item_get_resource(item_new, true);
    pal_decompress(pal, (u16)(256 + 16 * pal_idx), sizeof(color_t) * 16);
}

static void crafting_ui_update_item_oams() {
    // Oams should be invisible when doing this...
    crafting_recipe *recipe = crafting_ui_get_current_recipe();
    if (recipe) {
        for (size_t i = 0; i < ARRAY_COUNT(CRAFTING_UI_STATE->oams_ingredients); i++) {
            if (recipe->ingredients[i].count > 0) {
                // Reload palette and tile
                u16 item;
                if (recipe->ingredients[i].type == CRAFTING_INGREDIENT_ASH) {
                    item = ITEM_ASCHETASCHE;
                } else {
                    item = recipe->ingredients[i].item;
                }
                crafting_ui_update_item_oam(oams + CRAFTING_UI_STATE->oams_ingredients[i], item);
            }
        }
        crafting_ui_update_item_oam(oams + CRAFTING_UI_STATE->oam_item, recipe->item);
    }
}

static void crafting_ui_show_oams() {
    // All oams are assumed to be invisible
    crafting_recipe *recipe = crafting_ui_get_current_recipe();
    if (recipe) {
        for (size_t i = 0; i < ARRAY_COUNT(CRAFTING_UI_STATE->oams_ingredients); i++) {
            if (recipe->ingredients[i].count > 0) {
                oams[CRAFTING_UI_STATE->oams_ingredients[i]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
            }
        }
        oams[CRAFTING_UI_STATE->oam_item].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    }
}

static void crafting_ui_hide_oams() {
    for (u8 i = 0; i < ARRAY_COUNT(CRAFTING_UI_STATE->oams_ingredients); i++) {
        oams[CRAFTING_UI_STATE->oams_ingredients[i]].flags |= OAM_FLAG_INVISIBLE;
    }
    oams[CRAFTING_UI_STATE->oam_item].flags |= OAM_FLAG_INVISIBLE;
}

static u8 str_ash[] = LANGDEP(PSTRING("Asche"), PSTRING("Ash"));

static void crafting_ui_update_ingredient_texts() {
    tbox_flush_set(TBOX_INGREDIENTS, 0);
    crafting_recipe *recipe = crafting_ui_get_current_recipe();
    if (recipe) {
        for (size_t i = 0; i < MAX_NUM_INGREDIENTS; i++) {
            if (recipe->ingredients[i].count > 0) {
                bool requirements_fulfilled = ingredient_requirements_fulfilled(recipe->ingredients + i);
                u16 y = (u16)(5 + 24 * i);
                u8 *name;
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
                dprintf("X is %d\n", x);
                tbox_print_string(TBOX_INGREDIENTS, 2, x, y, 0, 0, &fontcolmap_black_letters, 0, strbuf);
            }
        }
    } else {
        tbox_copy_to_vram(TBOX_INGREDIENTS, TBOX_COPY_TILESET);
    }
}

static u8 str_exit[] = LANGDEP(PSTRING("Beenden"), PSTRING("Exit"));

static void crafting_ui_setup_recipies_and_list_menu_items() {
    for (u8 type = 0; type < CRAFTING_TYPE_CNT; type++) {
        crafting_recipe *recipies = crafting_recipies_get_by_type(type);
        size_t recipe_cnt = crafting_get_num_recipies_by_type(type);
        CRAFTING_UI_STATE->recipies[type] = malloc_and_clear(sizeof(crafting_recipe) * recipe_cnt);
        CRAFTING_UI_STATE->list_menu_items[type] = malloc_and_clear(sizeof(list_menu_item) * (recipe_cnt + 1));
        for (u8 idx = 0; idx < recipe_cnt; idx++) {
            if (recipies[idx].flag == 0 || recipies[idx].flag == 0xFFFF || checkflag(recipies[idx].flag)) {
                u8 recipe_idx = CRAFTING_UI_STATE->num_crafting_recipies[type]++;
                CRAFTING_UI_STATE->recipies[type][recipe_idx] = recipies[idx];
                CRAFTING_UI_STATE->list_menu_items[type][recipe_idx].text = item_get_name(CRAFTING_UI_STATE->recipies[type][recipe_idx].item);
                CRAFTING_UI_STATE->list_menu_items[type][recipe_idx].idx = (recipe_idx + 1);
            }
        }
        // Add the "exit" option for all lists
        int exit_idx = CRAFTING_UI_STATE->num_crafting_recipies[type];
        CRAFTING_UI_STATE->list_menu_items[type][exit_idx].text = str_exit;
        CRAFTING_UI_STATE->list_menu_items[type][exit_idx].idx = (exit_idx + 1);
        dprintf("Set up %d recipies for category %d\n", CRAFTING_UI_STATE->num_crafting_recipies[type], type);
    }
}

static void list_menu_print_callback_null(u8 tbox_idx, int idx, u8 y) {
    (void)tbox_idx; (void)idx; (void)y;
}

static list_menu_template recipe_selection_list_menu_template = {
    .items = NULL,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = list_menu_print_callback_null,
    .item_cnt = 255, .max_items_showed = 5, .tbox_idx = TBOX_LIST_MENU,
    .header_x = 0, .item_x = 8, .cursor_x = 0, .up_text_y = 2, .cursor_pal = 2, .fill_value = 0,
    .cursor_shadow_color = 3, .letter_spacing = 1, .item_vertical_padding = 2, .scroll_multiple = 0,
    .font = 2
};

static void crafting_ui_update_recipe_callback1() {
    oam_anim_proceed();
    oam_proceed();
    if (dma3_busy(-1))
        return;
    switch (CRAFTING_UI_STATE->setup_state) {
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
            // Redraw the tilemaps and show them
            tbox_tilemap_draw(TBOX_INGREDIENTS);
            tbox_tilemap_draw(TBOX_DESCRIPTION);
            crafting_ui_update_ingredient_boxes();
            bg_virtual_sync(ui_tboxes[TBOX_INGREDIENTS].bg_id);
            bg_virtual_sync(2);
            break;
        }
        case 3: {
            // Also update the oams, probably we don't need an extra frame for this, but w/e
            crafting_ui_update_item_oams();
            break;
        }
        case 4: {
            crafting_ui_show_oams();
            callback1_set(generic_callback1);
            return;
        }
    }
    CRAFTING_UI_STATE->setup_state++;
}

static void crafting_ui_update_visible_recipe_if_necessary() {
    if (CRAFTING_UI_STATE->recipe_selection_list_menu_callback == 0xFF)
        return; // No list menu available...
    u8 type = CRAFTING_UI_STATE->type;
    u16 cursor = 0, items_above = 0;
    list_menu_get_scroll_and_row(CRAFTING_UI_STATE->recipe_selection_list_menu_callback, &cursor, &items_above);
    int idx = CRAFTING_UI_STATE->list_menu_items[type][cursor + items_above].idx - 1; // We defined those indices to be 1-based
    if (idx != CRAFTING_UI_STATE->current_recipe_idx[type]) {
        CRAFTING_UI_STATE->current_recipe_idx[type] = (u8) idx;
        CRAFTING_UI_STATE->setup_state = 0;
        // Update everything
        callback1_set(crafting_ui_update_recipe_callback1);
    }
}

static void crafting_ui_idle(u8 self) {
    (void)self;
    if (fading_is_active() || dma3_busy(-1))
        return;
    crafting_ui_update_visible_recipe_if_necessary();
    list_menu_process_input(CRAFTING_UI_STATE->recipe_selection_list_menu_callback);
}

static void crafting_ui_setup_list_menu() {
    CRAFTING_UI_STATE->recipe_selection_list_menu_template = recipe_selection_list_menu_template;
    u8 type = CRAFTING_UI_STATE->type;
    CRAFTING_UI_STATE->recipe_selection_list_menu_template.item_cnt = (u16)(CRAFTING_UI_STATE->num_crafting_recipies[type] + 1); 
    CRAFTING_UI_STATE->recipe_selection_list_menu_template.items = CRAFTING_UI_STATE->list_menu_items[type];
    CRAFTING_UI_STATE->recipe_selection_list_menu_callback = list_menu_new(&CRAFTING_UI_STATE->recipe_selection_list_menu_template, 0, 0);
    if (!big_callback_is_active(crafting_ui_idle)) {
        big_callback_new(crafting_ui_idle, 0);
    }
}

void crafting_ui_free() {
    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    free(bg_get_tilemap(3));
    for (u8 type = 0; type < CRAFTING_TYPE_CNT; type++) {
        free(CRAFTING_UI_STATE->recipies[type]);
    }
    free(CRAFTING_UI_STATE);
}

static void crafting_ui_setup() {
    // big_callback_proceed(); Don't proceed callbacks, as we proceed the list menu while we in fact are still setting stuff up
    fading_proceed();
    tbox_proceed();
    oam_anim_proceed();
    oam_proceed();
    *(u16*)0x02038604 = 0; //no idea why to do this, but needs to be done for some reason
    if (fading_is_active() || dma3_busy(-1))
        return;
    // dprintf("Ui setup in state %d\n", CRAFTING_UI_STATE->setup_state);
    switch (CRAFTING_UI_STATE->setup_state) {
        case 0: {
            crafting_ui_setup_recipies_and_list_menu_items();
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
        case 1: {
            overworld_free();
            big_callback_delete_all();
            oam_reset();
            oam_palette_allocation_reset();
            dma0_reset_callback();
            tbox_free_all();
            CRAFTING_UI_STATE->setup_state++;
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
            CRAFTING_UI_STATE->setup_state++;
            break; 
        }
        case 3: {
            memset(CHARBASE(0), 0, 32);
            memset(CHARBASE(1), 0, 32);
            lz77uncompvram(gfx_crafting_menu_bg3Tiles, CHARBASE(3));
            lz77uncompvram(gfx_crafting_menu_bg2Tiles, CHARBASE(2));
            lz77uncompwram(gfx_crafting_menu_bg3Map, bg_get_tilemap(3));
            bg_fill_map_with_rectangle(2, gfx_crafting_menu_bg2Map[ARRAY_COUNT(gfx_crafting_menu_bg2Map) - 1][0], 0, 0, 32, 32, 1);
            CRAFTING_UI_STATE->setup_state++;
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
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
        case 5: {
            crafting_ui_setup_list_menu();
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
        case 6: {
            // The current visible recipe was initialized with 0xFF, so we have to update depending on the cursor 0 position
            crafting_ui_update_ingredient_texts();
            crafting_ui_update_description();
            crafting_ui_update_ingredient_boxes(); // Now that we have a cursor we can start updating stuff
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
        case 7: {
            pal_decompress(gfx_crafting_menu_bg3Pal, 0, sizeof(color_t) * 16);
            pal_decompress(gfx_crafting_menu_bg2Pal, 16, sizeof(color_t) * 16);
            tbox_message_init(TBOX_TYPE, 480, 15 * 16);
            // pal_copy(tbox_palette_transparent, 14 * 16, 32);
            pal_set_all_to_black();
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
        case 8: {
            bg_virtual_sync(0);
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            bg_virtual_sync(3);
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
        case 9: {
            for (size_t i = 0; i < ARRAY_COUNT(CRAFTING_UI_STATE->oams_ingredients) + 1; i++) {
                u16 tag = (u16)(0x1534 + i);
                u8 oam_idx = item_oam_new(tag, tag, ITEM_POKEBALL);
                // oams[oam_idx].flags &= (u16)(~OAM_FLAG_CENTERED);
                if (i < ARRAY_COUNT(CRAFTING_UI_STATE->oams_ingredients)) {
                    CRAFTING_UI_STATE->oams_ingredients[i] = oam_idx;
                    oams[oam_idx].x = 13 * 8 + 17;
                    oams[oam_idx].y = (s16)(2 * 8 + (24 * i) + 17);
                } else {
                    CRAFTING_UI_STATE->oam_item = oam_idx;
                    oams[oam_idx].x = 8 + 16;
                    oams[oam_idx].y = 15 * 8 + 4 + 18;
                }
            }
            crafting_ui_hide_oams();
            crafting_ui_update_item_oams();
            pal_set_all_to_black();
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
        case 10: {
            crafting_ui_show_oams();
            bg_sync_display_and_show(0);
            bg_sync_display_and_show(1);
            bg_sync_display_and_show(2);
            bg_sync_display_and_show(3);
            bg_display_sync();
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
        case 11: {
            fadescreen_all(0, 0);
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
        case 12: {
            // Only now also big callbacks may start, i.e. the list menu
            callback1_set(generic_callback1);
            CRAFTING_UI_STATE->setup_state++;
            break;
        }
    }
}



void crafting_ui_initialize() {
    fmem.gp_state = malloc_and_clear(sizeof(crafting_ui_state));
    CRAFTING_UI_STATE->recipe_selection_list_menu_callback = 0xFF;
    for (u8 i = 0; i < ARRAY_COUNT(CRAFTING_UI_STATE->current_recipe_idx); i++)
        CRAFTING_UI_STATE->current_recipe_idx[i] = 0;
    callback1_set(crafting_ui_setup);
    vblank_handler_set(generic_vblank_handler);

}