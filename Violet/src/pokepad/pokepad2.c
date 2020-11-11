#include "types.h"
#include "pokepad/pokepad2.h"
#include "pokepad/pokedex/gui.h"
#include "pokepad/pokeradar.h"
#include "pokepad/wondertrade.h"
#include "pokepad/incubator.h"
#include "save.h"
#include "bg.h"
#include "color.h"
#include "callbacks.h"
#include "transparency.h"
#include "oam.h"
#include "superstate.h"
#include "text.h"
#include "fading.h"
#include "constants/vars.h"
#include "language.h"
#include "vars.h"
#include "io.h"
#include "agbmemory.h"
#include "music.h"
#include "overworld/start_menu.h"
#include "overworld/map_control.h"
#include "dma.h"
#include "bios.h"
#include "flags.h"
#include "math.h"
#include "debug.h"
#include "list_menu.h"
#include "menu_indicators.h"

u8 str_pokepad_description[] = LANGDEP(
    PSTRING("Benutze verschiedene Apps, die auf dem\nPoképad installiert sind."),
    PSTRING("Use different apps installed on the\nPoképad.")
);

static pokepad_wallpaper pokepad_wallpapers[POKEPAD_NUM_WALLPAPERS] = {
    {
        .tileset = gfx_pokepad_wallpaper_startersTiles, .tilemap = gfx_pokepad_wallpaper_startersMap,
        .palette = gfx_pokepad_wallpaper_startersPal, .flag = 0,
        .name = LANGDEP(PSTRING("Starter"), PSTRING("Starters")),
    },
};

static u8 wondertrade_name[] = LANGDEP(PSTRING("Wundert."), PSTRING("Wondert."));
static u8 pokedex_name[] = LANGDEP(PSTRING("Pokédex"), PSTRING("Pokédex"));
static u8 pokeradar_name[] = LANGDEP(PSTRING("Pokéradar"), PSTRING("Pokéradar"));
static u8 incubator_name[] = LANGDEP(PSTRING("Inkubator"), PSTRING("Incubator"));

static u8 wondertrade_description[] = LANGDEP(
    PSTRING("Tausche Pokémon mit Trainern aus aller\nWelt."),
    PSTRING("Trade Pokémon with trainers all over\nthe world.")
);
static u8 pokedex_description[] = LANGDEP(
    PSTRING("Betrachte Aufzeichnungen zu gefangenen\nund gesehenen Pokémon."),
    PSTRING("View records of caught and seen Pokémon.")
);
static u8 pokeradar_description[] = LANGDEP(
    PSTRING("Spüre seltene Pokémon in der Nähe auf."),
    PSTRING("Identify rare Pokémon nearby.")
);
static u8 incubator_description[] = LANGDEP(
    PSTRING("Brüte Eier aus und überprüfe deren\nStatus."),
    PSTRING("Hatch eggs and check on their status.")
);

static pokepad2_item pokepad2_items[] = {
    [POKEPAD_ITEM_WONDERTRADE] = {
        .name = wondertrade_name,
        .description = wondertrade_description,
        .flag = WONDERTRADE,
        .initialize = wondertrade_init,
        .icon_graphic = {
            .sprite = gfx_pokepad_icon_wondertradeTiles, .size = GRAPHIC_SIZE_4BPP(32, 32), 
            .tag = POKEPAD_ITEM_ICON_BASE_TAG + POKEPAD_ITEM_WONDERTRADE,
        },
        .icon_palette = {
            .pal = gfx_pokepad_icon_wondertradePal, .tag = POKEPAD_ITEM_ICON_BASE_TAG + POKEPAD_ITEM_WONDERTRADE,
        },
    }, 
    [POKEPAD_ITEM_POKEDEX] = {
        .name = pokedex_name,
        .description = pokedex_description,
        .flag = POKEDEX,
        .initialize = pokedex_init,
        .icon_graphic = {
            .sprite = gfx_pokepad_icon_pokedexTiles, .size = GRAPHIC_SIZE_4BPP(32, 32), 
            .tag = POKEPAD_ITEM_ICON_BASE_TAG + POKEPAD_ITEM_POKEDEX,
        },
        .icon_palette = {
            .pal = gfx_pokepad_icon_pokedexPal, .tag = POKEPAD_ITEM_ICON_BASE_TAG + POKEPAD_ITEM_POKEDEX,
        },
    }, 
    [POKEPAD_ITEM_POKERADAR] = {
        .name = pokeradar_name,
        .description = pokeradar_description,
        .flag = POKERADAR,
        .initialize = pokeradar_init,
        .icon_graphic = {
            .sprite = gfx_pokepad_icon_pokeradarTiles, .size = GRAPHIC_SIZE_4BPP(32, 32), 
            .tag = POKEPAD_ITEM_ICON_BASE_TAG + POKEPAD_ITEM_POKERADAR,
        },
        .icon_palette = {
            .pal = gfx_pokepad_icon_pokeradarPal, .tag = POKEPAD_ITEM_ICON_BASE_TAG + POKEPAD_ITEM_POKERADAR,
        },
    }, 
    [POKEPAD_ITEM_INCUBATOR] = {
        .name = incubator_name,
        .description = incubator_description,
        .flag = FLAG_INCUBATOR,
        .initialize = incubator_initialize,
        .icon_graphic = {
            .sprite = gfx_pokepad_icon_incubatorTiles, .size = GRAPHIC_SIZE_4BPP(32, 32), 
            .tag = POKEPAD_ITEM_ICON_BASE_TAG + POKEPAD_ITEM_INCUBATOR,
        },
        .icon_palette = {
            .pal = gfx_pokepad_icon_incubatorPal, .tag = POKEPAD_ITEM_ICON_BASE_TAG + POKEPAD_ITEM_INCUBATOR,
        },
    }
};

enum {
    PRIORITY_INDICATORS = 0,
    PRIORITY_APP_ICONS,
    PRIORITY_CURSOR,
};

static graphic cursor_graphic = {
    .sprite = gfx_pokepad_cursorTiles, .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = POKEPAD_CURSOR_TAG,
};

static palette cursor_palette = {
    .pal = gfx_pokepad_cursorPal, .tag = POKEPAD_CURSOR_TAG,
};

static sprite cursor_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(1),
};

static void cursor_callback(oam_object *self) {
    if (!fading_is_active()) {
        u8 pal_idx = oam_palette_get_index(POKEPAD_CURSOR_TAG);
        FIXED t = INT_TO_FIXED((self->private[0])++);
        FIXED alpha = FIXED_MUL(INT_TO_FIXED(8), FIXED_COS(FIXED_DIV(t, INT_TO_FIXED(64))));
        // dprintf("Alpha cursor %d\n", FIXED_TO_INT(alpha));
        color_t white = {.rgb = {31, 31, 31}};
        pal_alpha_blending((u16)(256 + 16 * pal_idx), 16, (u8)(8 - FIXED_TO_INT(alpha)), white);
    }
}

static graphic left_indicator_graphic = {
    .sprite = gfx_pokepad_indicator_leftTiles, .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = POKEPAD_LEFT_INDICATOR_TAG,
};

static graphic right_indicator_graphic = {
    .sprite = gfx_pokepad_indicator_rightTiles, .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = POKEPAD_RIGHT_INDICATOR_TAG,
};

static palette lr_indicator_palette = {
    .pal = gfx_pokepad_indicator_leftPal, .tag = POKEPAD_LEFT_INDICATOR_TAG,
};

static oam_template cursor_template = {
    .tiles_tag = POKEPAD_CURSOR_TAG, .pal_tag = POKEPAD_CURSOR_TAG,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .graphics = NULL, .oam = &cursor_sprite, .callback = cursor_callback,
};

static oam_template indicator_left_template = {
    .tiles_tag = POKEPAD_LEFT_INDICATOR_TAG, .pal_tag = POKEPAD_LEFT_INDICATOR_TAG,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .graphics = NULL, .oam = &cursor_sprite, .callback = oam_null_callback,
};

static oam_template indicator_right_template = {
    .tiles_tag = POKEPAD_RIGHT_INDICATOR_TAG, .pal_tag = POKEPAD_LEFT_INDICATOR_TAG,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .graphics = NULL, .oam = &cursor_sprite, .callback = oam_null_callback,
};

static void oam_64_64_locate(oam_object *oam, u8 position) {
    int col = position % 4;
    int row = position / 4;
    oam->x = (s16)(30 + 60 * col);
    oam->y = (s16)(32 + 48 * row + 6);
}

static u8 *registered_items_get() {
    return (u8*) var_access(POKEPAD_SHORTCUTS);
}

static u8 pokepad_item_get_idx(u8 item) {
    for (u8 idx = 0; idx < POKEPAD_STATE->num_items; idx++) {
        if (POKEPAD_STATE->items[idx] == item)
            return idx;
    }
    return 0xFF;
}

static void lr_indicators_locate() {
    u8 *registered = registered_items_get();
    u8 left_position = pokepad_item_get_idx(registered[0]);
    if (left_position != 0xFF) {
        oam_64_64_locate(oams + POKEPAD_STATE->left_oam, left_position);
        oams[POKEPAD_STATE->left_oam].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    } else {
        oams[POKEPAD_STATE->left_oam].flags |= OAM_FLAG_INVISIBLE;
    }
    u8 right_position = pokepad_item_get_idx(registered[1]);
    if (right_position != 0xFF) {
        oam_64_64_locate(oams + POKEPAD_STATE->right_oam, right_position);
        oams[POKEPAD_STATE->right_oam].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    } else {
        oams[POKEPAD_STATE->right_oam].flags |= OAM_FLAG_INVISIBLE;
    }
}

static void cursor_loacte() {
    oam_64_64_locate(oams + POKEPAD_STATE->cursor_oam, POKEPAD_STATE->cursor_idx);
}

static void cursor_stop_fading() {
    u8 pal_idx = oam_palette_get_index(POKEPAD_CURSOR_TAG);
    cpuset(pals + 256 + 16 * pal_idx, pal_restore + 256 + 16 * pal_idx, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
    oams[POKEPAD_STATE->cursor_oam].callback = oam_null_callback;
}

enum {
    TBOX_DESCRIPTION = 0,
    TBOX_APP_UPPER,
    TBOX_APP_LOWER,
    TBOX_HEADER,
};

static tboxdata pokepad_tboxes[] = {
    [TBOX_DESCRIPTION] = {
        .bg_id = 0, .x = 0, .y = 15, .w = 30, .h = 5, .pal = 15, .start_tile = 1,
    },
    [TBOX_APP_UPPER] = {
        .bg_id = 0, .x = 0 * 60, .y = 6 , .w = 30, .h = 3, .pal = 15, .start_tile = 1 + 30 * 5
    },
    [TBOX_APP_LOWER] = {
        .bg_id = 0, .x = 0 * 60, .y = 12 , .w = 30, .h = 3, .pal = 15, .start_tile = 1 + 30 * 5 + 30 * 3
    },
    [TBOX_HEADER] = {
        .bg_id = 0, .x = 0, .y = 0 , .w = 30, .h = 2, .pal = 15, .start_tile = 1 + 30 * 5 + 30 * 3 + 30 * 3
    },
};

static list_menu_template motive_list_menu = {
    .items = NULL,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = incubator_context_menu_item_print_callback,
    .item_cnt = 0, .max_items_showed = 0, .tbox_idx = 0xFF,
    .header_x = 0, .item_x = 8, .cursor_x = 0, .up_text_y = 0, .cursor_pal = 2, .fill_value = 1,
    .cursor_shadow_color = 3, .letter_spacing = 1, .item_vertical_padding = 2, .scroll_multiple = 0,
    .font = 2
};

static bg_config bg_configs[] = {
    {.bg_id = 0, .char_base = 2, .map_base = 31, .size = 0, .color_mode = 0, .priority = 1},
    {.bg_id = 1, .char_base = 0, .map_base = 29, .size = 0, .color_mode = 1, .priority = 2},
    {.bg_id = 2, .char_base = 3, .map_base = 30, .size = 0, .color_mode = 0, .priority = 0},
};

static pokepad_wallpaper *pokepad_get_wallpaper() {
    return pokepad_wallpapers + *var_access(VAR_POKEPAD_WALLPAPER);
}

void pokepad2_free() {
    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    for (int i = 0; i < POKEPAD_STATE->num_app_oams; i++) {
        oam_free(oams + POKEPAD_STATE->app_oams[i]);
    }
    oam_free(oams + POKEPAD_STATE->cursor_oam);
    tbox_free_all();
    free(fmem.pad_mem);
}

static void callback1_free() {
    generic_callback1();
    if (!fading_is_active()) {
        pokepad2_free();
        callback1_set(map_reload);
    }
}

static tbox_font_colormap description_fontcolmap = {
    .background = 1, .body = 2, .edge = 1,
};

static void pokepad2_update_description() {
    pokepad2_item *item = pokepad2_items + POKEPAD_STATE->items[POKEPAD_STATE->cursor_idx];
    tbox_flush_set(TBOX_DESCRIPTION, 0x11);
    tbox_print_string(TBOX_DESCRIPTION, 2, 8, 6, 0, 0, &description_fontcolmap, 0, item->description);
}

static u8 str_key_l[] = PSTRING("KEY_L");

static u8 str_key_r[] = PSTRING("KEY_R");

static u8 str_registered[] = LANGDEP(
    PSTRING("Die BUFFER_1-App wurde auf der\nBUFFER_2 Taste registriert.PAUSE_UNTIL_PRESS"),
    PSTRING("The BUFFER_1-App was registered\non the BUFFER_2 key.PAUSE_UNTIL_PRESS")
);

static u8 str_deregistered[] = LANGDEP(
    PSTRING("Die BUFFER_1-App ist nicht länger auf\nder BUFFER_2 Taste registriert.PAUSE_UNTIL_PRESS"),
    PSTRING("The BUFFER_1-App is no longer registered\non the BUFFER_2 key.PAUSE_UNTIL_PRESS")
);

static void pokepad2_idle(u8 self);

static void pokepad2_tbox_description_run_printer_and_continue(u8 self) {
    if (!tbox_printer_proceed_and_is_active(TBOX_DESCRIPTION)) {
        pokepad2_update_description();
        big_callbacks[self].function = pokepad2_idle;
    }
}

static void pokepad2_tbox_description_print_message(u8 callback_idx, u8 *text) {
    string_decrypt(strbuf, text);
    tbox_flush_set(TBOX_DESCRIPTION, 0x11);
    tbox_printer_flags.can_a_b_speed_up_printing = true;
    tbox_print_string(TBOX_DESCRIPTION, 2, 8, 6, 0, 0, &description_fontcolmap, tbox_get_set_speed(), strbuf);
    big_callbacks[callback_idx].function = pokepad2_tbox_description_run_printer_and_continue;
}

static u16 pokepad2_build_wallpaper_list() {
    u16 list_size = 0;
    for (int i = 0; i < POKEPAD_NUM_WALLPAPERS; i++) {
        if (pokepad_wallpapers[i].flag == 0 || checkflag(pokepad_wallpapers[i].flag)) {
            POKEPAD_STATE->wallpaper_list[list_size].idx = i + 1;
            POKEPAD_STATE->wallpaper_list[list_size].text = pokepad_wallpapers[i].name;
            list_size++;
        }
    }
    return list_size;
}

static void pokepad2_update_wallpaper_palette() {
    pokepad_wallpaper *wallpaper = pokepad_get_wallpaper();
    pal_decompress(wallpaper->palette, 0, 10 * 16 * sizeof(color_t)); // Probably a bit too much...
    color_t black = {.rgb={0, 0, 0}};
    pal_gamma_shift_with_blend(0, 10, 3, 4, black);
    cpuset(pals, pal_restore, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(10 * 16 * sizeof(color_t)));  
}

static void pokepad2_update_wallpaper_bg() {
    pokepad_wallpaper *wallpaper = pokepad_get_wallpaper();
    lz77uncompwram(wallpaper->tilemap, bg_get_tilemap(1));
    lz77uncompvram(wallpaper->tileset, CHARBASE(0));
}

static void pokepad2_context_menu(u8 self);

static void pokepad2_update_wallpaper(u8 self) {
    color_t white = {.rgb = {0, 0, 0}};
    if (!fading_is_active()) {
        switch (big_callbacks[self].params[0]) {
            case 0 : {
                bg_hide(1);
                ++big_callbacks[self].params[0];
                break;
            }
            case 1 : {
                pokepad2_update_wallpaper_bg();
                pokepad2_update_wallpaper_palette();
                cpuset(&white, pals, CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(10 * 16 * sizeof(color_t)));
                fadescreen(0x3FF, 1, 16, 0, white.value);
                ++big_callbacks[self].params[0];
                break;
            }
            case 2 : {
                bg_sync_display_and_show(1);
                big_callbacks[self].function = pokepad2_context_menu;
            }
        }
        
    }
}

static void pokepad2_context_menu_setup_scroll_indicators() {
    scroll_indicator_template indicator_template = {
        .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 25 * 8, .arrow0_y = (u8)((14 - 2 * POKEPAD_STATE->context_menu_num_items_shown) * 8),
        .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 25 * 8, .arrow1_y = 14 * 8,
        .arrow0_threshold = 0, 
        .arrow1_threshold = (u16) MAX(0, (POKEPAD_STATE->context_menu_list_size - POKEPAD_STATE->context_menu_num_items_shown)),
        .tiles_tag = 111,
        .pal_tag = 111,
    };
    POKEPAD_STATE->scroll_indicator_callback_idx = scroll_indicator_new(&indicator_template,
        &POKEPAD_STATE->context_menu_cursor_position);
    scroll_indicator_set_oam_priority(POKEPAD_STATE->scroll_indicator_callback_idx, 0, 0);
}

static void pokepad2_context_menu(u8 self) {
    if (fading_is_active())
        return;
    list_menu_get_scroll_and_row(POKEPAD_STATE->callback_idx_context_menu, &POKEPAD_STATE->context_menu_cursor_position, &POKEPAD_STATE->context_menu_num_items_above);
    int item = list_menu_process_input(POKEPAD_STATE->callback_idx_context_menu);
    if (item == LIST_MENU_NOTHING_CHOSEN) return;
    if (item == LIST_MENU_B_PRESSED) {
        play_sound(5);
        list_menu_remove(POKEPAD_STATE->callback_idx_context_menu, NULL, NULL);
        tbox_flush_set(POKEPAD_STATE->tbox_idx_context_menu, 0);
        tbox_flush_map(POKEPAD_STATE->tbox_idx_context_menu);
        tbox_free(POKEPAD_STATE->tbox_idx_context_menu);
        scroll_indicator_delete(POKEPAD_STATE->scroll_indicator_callback_idx);
        bg_virtual_sync(2);
        pokepad2_update_description();
        big_callbacks[self].function = pokepad2_idle;
    } else if (item >= 1) {
        play_sound(5);
        *var_access(VAR_POKEPAD_WALLPAPER) = (u16)(item - 1);
        color_t white = {.rgb = {0, 0, 0}};
        fadescreen(0x3FF, 1, 0, 16, white.value);
        big_callbacks[self].function = pokepad2_update_wallpaper;
        big_callbacks[self].params[0] = 0;
    }
}

static u8 str_select_motive[] = LANGDEP(
    PSTRING("Wähle ein Hintergrundmotiv aus."),
    PSTRING("Choose a background motive.")
);

static void pokepad2_idle(u8 self) {
    if (!fading_is_active()) {
        if (super.keys_new.keys.down && POKEPAD_STATE->cursor_idx < 4 && POKEPAD_STATE->num_items >= 4) {
            POKEPAD_STATE->cursor_idx = (u8)MIN(POKEPAD_STATE->num_items - 1, POKEPAD_STATE->cursor_idx + 4);
            play_sound(5);
            *var_access(POKEPAD_LAST_USED) = POKEPAD_STATE->cursor_idx;
            cursor_loacte();
            pokepad2_update_description();
            return;
        } else if (super.keys_new.keys.up && POKEPAD_STATE->cursor_idx >= 4) {
            POKEPAD_STATE->cursor_idx = (u8)(POKEPAD_STATE->cursor_idx - 4);
            play_sound(5);
            *var_access(POKEPAD_LAST_USED) = POKEPAD_STATE->cursor_idx;
            cursor_loacte();
            pokepad2_update_description();
            return;
        } else if (super.keys_new.keys.left && (POKEPAD_STATE->cursor_idx % 4) > 0) {
            POKEPAD_STATE->cursor_idx = (u8)(POKEPAD_STATE->cursor_idx - 1);
            play_sound(5);
            *var_access(POKEPAD_LAST_USED) = POKEPAD_STATE->cursor_idx;
            cursor_loacte();
            pokepad2_update_description();
            return;
        } else if (super.keys_new.keys.right && ((POKEPAD_STATE->cursor_idx % 4) < 3) && (POKEPAD_STATE->cursor_idx + 1) < POKEPAD_STATE->num_items) {
            POKEPAD_STATE->cursor_idx = (u8)(POKEPAD_STATE->cursor_idx + 1);
            play_sound(5);
            *var_access(POKEPAD_LAST_USED) = POKEPAD_STATE->cursor_idx;
            cursor_loacte();
            pokepad2_update_description();
            return;
        } else if (super.keys_new.keys.B) {
            cursor_stop_fading();
            fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
            callback1_set(callback1_free);
            big_callback_delete(self);
        } else if (super.keys_new.keys.A) {
            int item = POKEPAD_STATE->items[POKEPAD_STATE->cursor_idx];
            if (pokepad2_items[item].initialize) {
                play_sound(5);
                pokepad2_items[item].initialize(false);
                big_callback_delete(self);
            }
        } else if (super.keys_new.keys.l) {
            u8 current_item = POKEPAD_STATE->items[POKEPAD_STATE->cursor_idx];
            u8 *left = registered_items_get();
            strcpy(buffer0, pokepad2_items[current_item].name);
            strcpy(buffer1, str_key_l);
            tbox_flush_set(TBOX_DESCRIPTION, 0x11);
            if (*left != current_item) {
                *left = current_item;
                lr_indicators_locate();
                play_sound(2);
                pokepad2_tbox_description_print_message(self, str_registered);
            } else {
                *left = 0xFF; // de-registering
                lr_indicators_locate();
                play_sound(3);
                pokepad2_tbox_description_print_message(self, str_deregistered);
            }
        } else if (super.keys_new.keys.r) {
            u8 current_item = POKEPAD_STATE->items[POKEPAD_STATE->cursor_idx];
            u8 *right = registered_items_get() + 1;
            strcpy(buffer0, pokepad2_items[current_item].name);
            strcpy(buffer1, str_key_r);
            tbox_flush_set(TBOX_DESCRIPTION, 0x11);
            if (*right != current_item) {
                *right = current_item;
                lr_indicators_locate();
                play_sound(2);
                pokepad2_tbox_description_print_message(self, str_registered);
            } else {
                *right = 0xFF; // de-registering
                lr_indicators_locate();
                play_sound(3);
                pokepad2_tbox_description_print_message(self, str_deregistered);
            }
        } else if (super.keys_new.keys.start) {
            u16 list_size = pokepad2_build_wallpaper_list();
            POKEPAD_STATE->context_menu_list_size = list_size;
            u16 context_menu_height = MIN(4, list_size);
            POKEPAD_STATE->context_menu_num_items_shown = context_menu_height;
            // Print instructions in the description box
            tbox_flush_set(TBOX_DESCRIPTION, 0x11);
            tbox_print_string(TBOX_DESCRIPTION, 2, 8, 6, 0, 0, &description_fontcolmap, 0, str_select_motive);
            // Create context menu textbox
            tboxdata boxdata = {
                .bg_id = 2, .x = 20, .y = (u8)(14 - 2 * context_menu_height), .w = 10, 
                .h = (u8)(2 * context_menu_height), .pal = 15, .start_tile = 1,
            };
            POKEPAD_STATE->tbox_idx_context_menu = tbox_new(&boxdata);
            tbox_tilemap_draw(POKEPAD_STATE->tbox_idx_context_menu);
            gp_list_menu_template = motive_list_menu;
            gp_list_menu_template.item_cnt = list_size;
            gp_list_menu_template.items = POKEPAD_STATE->wallpaper_list;
            gp_list_menu_template.tbox_idx = POKEPAD_STATE->tbox_idx_context_menu;
            gp_list_menu_template.max_items_showed = (u8)context_menu_height;
            POKEPAD_STATE->callback_idx_context_menu = list_menu_new(&gp_list_menu_template, 0, 0);
            pokepad2_context_menu_setup_scroll_indicators();
            play_sound(5);
            bg_virtual_sync(boxdata.bg_id);
            big_callbacks[self].function = pokepad2_context_menu;
        }
    }
}

static sprite app_icon_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(1),
};

static tbox_font_colormap app_name_fontcolmap = {
    .background = 0, .body = 2, .edge = 0,
};

static bool pokepad2_initialize_app_oams(int num_to_initialize) {
    while (POKEPAD_STATE->num_app_oams < POKEPAD_STATE->num_items) {
        if (num_to_initialize <= 0)
            return false;
        pokepad2_item *item = pokepad2_items + POKEPAD_STATE->num_app_oams;
        oam_load_graphic(&item->icon_graphic);
        oam_palette_load_if_not_present(&item->icon_palette);
        int row = POKEPAD_STATE->num_app_oams / 4;
        int col = POKEPAD_STATE->num_app_oams % 4;
        oam_template template = {
            .tiles_tag = item->icon_graphic.tag, .pal_tag = item->icon_palette.tag,
            .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
            .graphics = NULL, .oam = &app_icon_sprite, .callback = oam_null_callback,
        };
        int string_width = string_get_width(2, item->name, 0);
        tbox_print_string(row > 0 ? TBOX_APP_LOWER : TBOX_APP_UPPER, 2, (u16)((60 - string_width) / 2 + 60 * col), 6, 0, 0, &app_name_fontcolmap, 0, item->name);
        POKEPAD_STATE->app_oams[POKEPAD_STATE->num_app_oams] = oam_new_forward_search(&template, (s16)(30 + 60 * col), (s16)(32 + 48 * row + 6), PRIORITY_APP_ICONS);
        ++POKEPAD_STATE->num_app_oams;
        num_to_initialize--;
    }
    return true;
}
enum {
    RESET,
    BG_SETUP,
    GFX_LOAD,
    TBOX_SETUP,
    DATA_SETUP,
    APP_SETUP,
    PAL_SETUP,
    CURSOR_SETUP,
    BG_COPY,
    FADE_TO_IDLE,
};

static void pokepad2_initialize() {
    switch(POKEPAD_STATE->initialization_state) {
        case RESET: {
            dma0_reset_callback();
            oam_reset();
            big_callback_delete_all();
            fading_cntrl_reset();
            oam_palette_allocation_reset();
            vblank_handler_set(NULL);
            bg_reset(0);
            bg_setup(0, bg_configs, ARRAY_COUNT(bg_configs));
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case BG_SETUP: {
            bg_set_tilemap(0, malloc_and_clear(0x800));
            bg_set_tilemap(1, malloc_and_clear(0x800));
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
            io_set(0x48, 0x1F3F);
            io_set(0x50, 0x3e45);
            io_set(0x52, 0x0a0F);
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case GFX_LOAD: {
            int zero = 0;
            cpuset(&zero, CHARBASE(bg_configs[0].char_base), CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(32) | CPUSET_FILL);
            cpuset(&zero, CHARBASE(bg_configs[2].char_base), CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(32) | CPUSET_FILL);
            pokepad2_update_wallpaper_bg();
            oam_load_graphic(&cursor_graphic);
            oam_load_graphic(&left_indicator_graphic);
            oam_load_graphic(&right_indicator_graphic);
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case DATA_SETUP: {
            POKEPAD_STATE->num_items = 0;
            POKEPAD_STATE->num_app_oams = 0;
            POKEPAD_STATE->cursor_idx = (u8)*var_access(POKEPAD_LAST_USED);
            for (u8 i = 0; i < ARRAY_COUNT(pokepad2_items); i++) {
                if (checkflag(pokepad2_items[i].flag)) {
                    POKEPAD_STATE->items[(POKEPAD_STATE->num_items)++] = i;
                }
            }
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case APP_SETUP: {
            if (pokepad2_initialize_app_oams(2))
                ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case PAL_SETUP: {
            pokepad2_update_wallpaper_palette();
            pal_copy(tbox_palette_transparent, 15 * 16, 16 * sizeof(color_t));
            oam_palette_load_if_not_present(&cursor_palette);
            oam_palette_load_if_not_present(&lr_indicator_palette);
            pal_set_all_to_black();
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case TBOX_SETUP: {
            tbox_sync_with_virtual_bg_and_init_all(pokepad_tboxes);
            tbox_tilemap_draw(TBOX_DESCRIPTION);
            tbox_tilemap_draw(TBOX_APP_UPPER);
            tbox_tilemap_draw(TBOX_APP_LOWER);
            tbox_tilemap_draw(TBOX_HEADER);
            tbox_flush_set(TBOX_DESCRIPTION, 0x11);
            tbox_flush_set(TBOX_HEADER, 0x11);
            tbox_flush_set(TBOX_APP_UPPER, 0x0);
            tbox_flush_set(TBOX_APP_LOWER, 0x0);
            u8 str_header[] = LANGDEP(
                PSTRING("KEY_LKEY_R Registrieren  KEY_START Motiv  KEY_B Zur."),
                PSTRING("KEY_LKEY_R Register  KEY_START Motive  KEY_B Back")
            );
            tbox_print_string(TBOX_HEADER, 2, 8, 0, 0, 0, &description_fontcolmap, 0, str_header);
            tbox_sync(TBOX_APP_UPPER, TBOX_SYNC_SET);
            tbox_sync(TBOX_APP_LOWER, TBOX_SYNC_SET);
            pokepad2_update_description();
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case CURSOR_SETUP: {
            POKEPAD_STATE->cursor_oam = oam_new_forward_search(&cursor_template, 0, 0, PRIORITY_CURSOR);
            cursor_loacte();
            POKEPAD_STATE->left_oam = oam_new_forward_search(&indicator_left_template, 0, 0, PRIORITY_INDICATORS);
            POKEPAD_STATE->right_oam = oam_new_forward_search(&indicator_right_template, 0, 0, PRIORITY_INDICATORS);
            lr_indicators_locate();
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case BG_COPY: {
            bg_virtual_sync(0);
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case FADE_TO_IDLE: {
            callback1_set(generic_callback1);
            vblank_handler_set(generic_vblank_handler);
            fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
            // fadescreen_all(FADE_FROM_BLACK, 0);
            POKEPAD_STATE->callback_idx = big_callback_new(pokepad2_idle, 0);
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
    }
}

void pokepad2_callback_initialize() {
    fmem.pad_mem = malloc_and_clear(sizeof(pokepad_memory2));
    POKEPAD_STATE->initialization_state = 0;
    callback1_set(pokepad2_initialize);
    io_bic(0, 0x6000);
}

bool start_menu_pokepad_initialize() {
    if (!fading_is_active()) {
        save_increment_key(0x29);
        start_menu_close();
        overworld_free();
        tbox_free_all();
        callback1_set(pokepad2_callback_initialize);
        return true;
    }
    return false;
}

bool pokepad_initialize_registered_item() {
    if (!checkflag(POKEDEX)) 
        return false;
    u8 *registered = registered_items_get();
    if (super.keys_new.keys.l && registered[0] != 0xFF) {
        if (pokepad2_items[registered[0]].initialize) {
            pokepad2_items[registered[0]].initialize(true);
            return true;
        }
    } else if (super.keys_new.keys.r && registered[1] != 0xFF) {
        if (pokepad2_items[registered[1]].initialize) {
            pokepad2_items[registered[1]].initialize(true);
            return true;
        }
    }
    return false;
}