

#include "types.h"
#include "stdbool.h"
#include "pokepad/pokepad2.h"
#include "pokepad/pokedex/gui.h"
#include "pokepad/pokedex/operator.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "mega.h"
#include "pokemon/basestat.h"
#include "color.h"
#include "superstate.h"
#include "transparency.h"
#include "fading.h"
#include "debug.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "language.h"
#include "io.h"
#include "flags.h"
#include "vars.h"
#include "music.h"
#include "bios.h"
#include "agbmemory.h"
#include "overworld/map_control.h"
#include "pokepad/pokedex/state.h"
#include "dma.h"
#include "menu_indicators.h"
#include "pokemon/names.h"
#include "pokepad/pokedex/pages/flavor_text.h"
#include "pokepad/pokedex/pages/evolution.h"
#include "pokepad/pokedex/pages/move_list.h"
#include "pokepad/pokedex/pages/stats.h"
#include "pokemon/cry.h"
#include "battle/state.h"
#include "worldmap.h"

EWRAM pokedex_entry_state_t *pokedex_entry_state = NULL;

static void pokedex_entry_callback_initialize_state_machine();

extern const LZ77COMPRESSED gfx_pokedex_entry_ui2Tiles;
extern const LZ77COMPRESSED gfx_pokedex_entry_ui2Map;
extern const LZ77COMPRESSED gfx_pokedex_entry_ui2Pal;
extern const LZ77COMPRESSED gfx_pokedex_entry_ui_scrollingTiles;
extern const bg_tile gfx_pokedex_entry_ui_scrollingMap[3][6];

static const u8 str_pokedex_entry_page_flavor_text[] = LANGDEP(PSTRING("Allgemeines"), PSTRING("General"));
static const u8 str_pokedex_entry_page_evolution[] = LANGDEP(PSTRING("Evolution"),PSTRING("Evolution"));
static const u8 str_pokedex_entry_page_move_list[] = LANGDEP(PSTRING("Attacken"), PSTRING("Moves"));
static const u8 str_pokedex_entry_page_extra_move_list[] = LANGDEP(PSTRING("Extra-Attacken"), PSTRING("Extra Moves"));
static const u8 str_pokedex_entry_page_stats[] = LANGDEP(PSTRING("Basiswerte"), PSTRING("Base Stats"));

static const pokedex_entry_page_t pokedex_entry_pages[NUM_POKEDEX_ENTRY_PAGES] = {
    [POKEDEX_ENTRY_PAGE_FLAVOR_TEXT] = {
        .title = str_pokedex_entry_page_flavor_text,
        .setup = pokedex_entry_page_flavor_text_setup,
        .destroy = pokedex_entry_page_flavor_text_destroy,
        .handle_inputs = pokedex_entry_page_flavor_text_handle_inputs,
        .setup_bg = pokedex_entry_page_flavor_text_setup_bg,
        },
    [POKEDEX_ENTRY_PAGE_EVOLUTION] = {
        .title = str_pokedex_entry_page_evolution,
        .setup = pokedex_entry_page_evolution_setup,
        .destroy = pokedex_entry_page_evolution_destroy,
        .handle_inputs = pokedex_entry_page_evolution_handle_inputs,
        .setup_bg = pokedex_entry_page_evolution_setup_bg,
        },
    [POKEDEX_ENTRY_PAGE_MOVE_LIST] = {
        .title = str_pokedex_entry_page_move_list,
        .setup = pokedex_entry_page_move_list_level_up_setup,
        .destroy = pokedex_entry_page_move_list_level_up_destroy,
        .handle_inputs = pokedex_entry_page_move_list_level_up_handle_inputs,
        .setup_bg = pokedex_entry_page_move_list_setup_bg,
    },
    [POKEDEX_ENTRY_PAGE_EXTRA_MOVE_LIST] = {
        .title = str_pokedex_entry_page_extra_move_list,
        .setup = pokedex_entry_page_move_list_extra_setup,
        .destroy = pokedex_entry_page_move_list_extra_destroy,
        .handle_inputs = pokedex_entry_page_move_list_extra_handle_inputs,
        .setup_bg = pokedex_entry_page_move_list_extra_setup_bg,
    },
    [POKEDEX_ENTRY_PAGE_STATS] = {
        .title = str_pokedex_entry_page_stats,
        .setup = pokedex_entry_page_stats_setup,
        .destroy = pokedex_entry_page_stats_destroy,
        .handle_inputs = pokedex_entry_page_stats_handle_inputs,
        .setup_bg = pokedex_entry_page_stats_setup_bg,
    }
};

static const bg_config pokedex_entry_bg_configs[] = {
    {.bg_id = 0, .char_base = 2, .map_base = 31, .priority = 0, .size = BG_TEXT_SIZE_256x256},
    {.bg_id = 1, .char_base = 0, .map_base = 30, .priority = 1, .size = BG_TEXT_SIZE_256x256},
    {.bg_id = 2, .char_base = 1, .map_base = 28, .priority = 2, .size = BG_TEXT_SIZE_512x256},
    {.bg_id = 3, .char_base = 1, .map_base = 26, .priority = 3, .size = BG_TEXT_SIZE_512x256},
};

static const tboxdata pokedex_entry_tboxes[NUM_POKEDEX_ENTRY_TBOXES + 1] = {
    [POKEDEX_ENTRY_TBOX_PAGE_TITLE] = {.bg_id = 0, .x = 10, .y = 0, .w = 11, .h = 3, .pal = 13, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [POKEDEX_ENTRY_TBOX_TITLE] = {.bg_id = 0, .x = 0, .y = 0, .w = 10, .h = 3, .pal = 13, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES  + 11 * 3},
    [POKEDEX_ENTRY_TBOX_CAUGHT_ICON] = {.bg_id = 0, .x = 3, .y = 12, .w = 2, .h = 2, .pal = 12, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES  + 11 * 3 + 10 * 3},
    [POKEDEX_ENTRY_TBOX_TYPES] = {.bg_id = 0, .x = 0, .y = 16, .w = 9, .h = 2, .pal = 11, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES  + 11 * 3 + 10 * 3 + 2 * 3},
    [POKEDEX_ENTRY_TBOX_CATEGORY] = {.bg_id = 0, .x = 0, .y = 14, .w = 8, .h = 2, .pal = 13, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES  + 11 * 3 + 10 * 3 + 2 * 3 + 2 * 9},
    [POKEDEX_ENTRY_TBOX_HABITAT] = {.bg_id = 0, .x = 0, .y = 18, .w = 8, .h = 2, .pal = 13, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES  + 11 * 3 + 10 * 3 + 2 * 3 + 2 * 9 + 2 * 8},
    [NUM_POKEDEX_ENTRY_TBOXES] = {.bg_id = 0xFF},
};

static const sprite sprite_pokemon = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(0),
};

static const oam_template oam_template_pokemon = {
    .tiles_tag = POKEDEX_ENTRY_GFX_TAG_SPECIES, .pal_tag = POKEDEX_ENTRY_GFX_TAG_SPECIES,
    .oam = &sprite_pokemon, .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};


static const tbox_font_colormap tbox_fontcolmap_white = {.background = 0, .body = 1, .edge = 2};

static void pokedex_entry_update_page_header() {
    for (int i = 0; i < NUM_POKEDEX_ENTRY_PAGES; i++) {
        int x = 30 - (NUM_POKEDEX_ENTRY_PAGES - i) * 2;
        int src_x;
        if (i < pokedex_entry_state->page) {
            src_x = 0;
        } else if (i == pokedex_entry_state->page) {
            src_x = 2;
        } else {
            src_x = 4;
        }
        pokedex_entry_state->bg_maps[1][0][x] = gfx_pokedex_entry_ui_scrollingMap[0][src_x];
        pokedex_entry_state->bg_maps[1][1][x] = gfx_pokedex_entry_ui_scrollingMap[1][src_x];
        pokedex_entry_state->bg_maps[1][2][x] = gfx_pokedex_entry_ui_scrollingMap[2][src_x];
        pokedex_entry_state->bg_maps[1][0][x + 1] = gfx_pokedex_entry_ui_scrollingMap[0][src_x + 1];
        pokedex_entry_state->bg_maps[1][1][x + 1] = gfx_pokedex_entry_ui_scrollingMap[1][src_x + 1];
        pokedex_entry_state->bg_maps[1][2][x + 1] = gfx_pokedex_entry_ui_scrollingMap[2][src_x + 1];
    }
    tbox_flush_set(POKEDEX_ENTRY_TBOX_PAGE_TITLE, 0x00);
    tbox_print_string(POKEDEX_ENTRY_TBOX_PAGE_TITLE, 2, 4, 4, 0, 0, &tbox_fontcolmap_white, 0, 
        pokedex_entry_pages[pokedex_entry_state->page].title);
    bg_virtual_sync_reqeust_push(1);
}

static void pokedex_entry_update_page_all() {
    pokedex_entry_state->page_initialization_state = 0;
    while (true) {
        if (!pokedex_entry_pages[pokedex_entry_state->page].setup()) {
            break;
        }
    }
}

static void pokedex_entry_switch_pages_callback(u8 self) {
    u16 *state = big_callbacks[self].params;
    bool fading_in = big_callbacks[self].params[1];
    bool setup_proceeding = false;
    if (*state == 2 || *state == 3) 
        setup_proceeding = pokedex_entry_pages[pokedex_entry_state->page].setup();
    switch (*state) {
        case 0: {
            pokedex_entry_update_page_header();
            pokedex_entry_pages[pokedex_entry_state->page].setup_bg(pokedex_entry_state->page_layer);
            bg_set_attribute((u8)(2 + (pokedex_entry_state->page_layer ^ fading_in ^ 1)), BG_ATTR_PRIORITY, 2);
            bg_set_attribute((u8)(2 + (pokedex_entry_state->page_layer ^ fading_in)), BG_ATTR_PRIORITY, 3);
            bg_update_and_show(2);
            bg_update_and_show(3);
            bg_virtual_sync_reqeust_push(0);
            bg_virtual_sync_reqeust_push(2);
            bg_virtual_sync_reqeust_push(3);
            (*state)++;
            FALL_THROUGH;
        }
        case 1: {
            pokedex_entry_state->bg_x_offset[2 + pokedex_entry_state->page_layer] = fading_in ? 256 : 0;
            pokedex_entry_state->bg_x_offset[2 + (pokedex_entry_state->page_layer ^ 1)] = 0;
            (*state)++;
            break;
        }
        case 2: {
            if (fading_in) {
                pokedex_entry_state->bg_x_offset[2 + pokedex_entry_state->page_layer] = (u16)(
                    pokedex_entry_state->bg_x_offset[2 + pokedex_entry_state->page_layer] - 64);
                if (pokedex_entry_state->bg_x_offset[2 + pokedex_entry_state->page_layer] > 0)
                    break;
            } else {
                pokedex_entry_state->bg_x_offset[2 + (pokedex_entry_state->page_layer ^ 1)] = (u16)(
                    pokedex_entry_state->bg_x_offset[2 + (pokedex_entry_state->page_layer ^ 1)] + 64);
                
                if (pokedex_entry_state->bg_x_offset[2 + (pokedex_entry_state->page_layer ^ 1)] < 256)
                    break;
            }
            (*state)++;
            FALL_THROUGH;
        }
        case 3: {
            if (setup_proceeding)
                return;
            bg_virtual_sync_reqeust_push(0);
            io_bic(IO_DISPCNT, IO_DISPCNT_WIN0);
            FALL_THROUGH;
        }
        default:
            big_callback_set_function_to_continuation(self);
            DEBUG("Big callback set function co tinuation %d\n", big_callbacks[self].function);
            break;
    }
}

static void pokedex_entry_switch_pages(u8 self, u8 fading_in, u8 to_page) {
    // DEBUG("Switch fading %d, to %d\n", fading_in, to_page);
    pokedex_entry_pages[pokedex_entry_state->page].destroy();
    pokedex_entry_state->page = to_page;
    pokedex_entry_state->page_layer ^= 1;
    big_callbacks[self].params[0] = 0;
    big_callbacks[self].params[1] = fading_in;
    // Exclude everything but BG2 and BG3 from the area where the page is loaded using the WIN feature
    io_set(IO_DISPCNT, (u16)(io_get(IO_DISPCNT) | IO_DISPCNT_WIN0));
    io_set(IO_WININ, IO_WININOUT_BG(0, 2) | IO_WININOUT_BG(0, 3));
    io_set(IO_WINOUT, IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) |
        IO_WININOUT_BG(0, 3) | IO_WININOUT_OBJ(0) | IO_WININOUT_FX(0));
    io_set(IO_WIN0H, IO_WINH(70, 255));
    io_set(IO_WIN0V, IO_WINV(24, 255));
    pokedex_entry_state->page_initialization_state = 0;
    big_callback_set_function_and_continuation(self, pokedex_entry_switch_pages_callback, big_callbacks[self].function);
    big_callbacks[self].function(self);
}


static void pokedex_entry_update(u16 species) {
    DEBUG("Species: %d\n", species);
    tbox_flush_set(POKEDEX_ENTRY_TBOX_TITLE, 0x00);
    const u8 *str = pokemon_names[species];
    tbox_print_string(POKEDEX_ENTRY_TBOX_TITLE, 2, 
        (u16)((8 * pokedex_entry_tboxes[POKEDEX_ENTRY_TBOX_TITLE].w - string_get_width(2, str, 0)) / 2),
        4, 0, 0, &tbox_fontcolmap_white, 0, str);
    tbox_flush_set(POKEDEX_ENTRY_TBOX_CAUGHT_ICON, 0x00);
    tbox_flush_set(POKEDEX_ENTRY_TBOX_TYPES, 0x00);
    tbox_flush_set(POKEDEX_ENTRY_TBOX_CATEGORY, 0x00);

    // Print additional information if the pokemon is caught
    if (pokedex_operator(species, POKEDEX_GET | POKEDEX_CAUGHT, true)) {
        tbox_blit_move_info_icon(POKEDEX_ENTRY_TBOX_CAUGHT_ICON, 0, 4, 4);
        u8 type1 = (u8) (basestats[species].type1 + 1);
        u8 type2 = (u8) (basestats[species].type2 + 1);
        if (type1 == type2) {
            tbox_blit_move_info_icon(POKEDEX_ENTRY_TBOX_TYPES, type1, 16 + 2, 0);
        } else {
            tbox_blit_move_info_icon(POKEDEX_ENTRY_TBOX_TYPES, type1, 0 + 2, 0);
            tbox_blit_move_info_icon(POKEDEX_ENTRY_TBOX_TYPES, type2, 32 + 2, 0);
        }   
        const u8 *category = pokedex_entries[pokedex_get_id(species)].category;
        tbox_print_string(POKEDEX_ENTRY_TBOX_CATEGORY, 0, 
            (u16)((4 + 8 * pokedex_entry_tboxes[POKEDEX_ENTRY_TBOX_CATEGORY].w - string_get_width(0, category, 0)) / 2), 
            0, 0, 0, &tbox_fontcolmap_white, 0, category);
    }
    tbox_sync(POKEDEX_ENTRY_TBOX_CAUGHT_ICON, TBOX_SYNC_SET);
    tbox_sync(POKEDEX_ENTRY_TBOX_TYPES, TBOX_SYNC_SET);
    tbox_sync(POKEDEX_ENTRY_TBOX_CATEGORY, TBOX_SYNC_SET);

    // Load the speices picture
    lz77uncompvram(pokemon_frontsprites[species].sprite, OAMCHARBASE(pokedex_entry_state->base_tile_pokemon));
    pal_decompress(pokemon_pals[species].pal, (u16) (256 + pokedex_entry_state->pal_idx_pokemon * 16), 16 * sizeof(color_t));

}

static void pokedex_entry_free() {
    tbox_free_all();
    for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->bg_maps); i++) {
        u8 bg_idx = pokedex_entry_bg_configs[i].bg_id;
        free(pokedex_entry_state->bg_maps[bg_idx]);
    }
    pokedex_entry_pages[pokedex_entry_state->page].destroy();
}

static void pokedex_entry_callback_return(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    callback1_set(pokedex_entry_state->continuation);
    pokedex_entry_free();
    big_callback_delete(self);
    if (pokedex_entry_state->context == POKEDEX_ENTRY_PAGE_CONTEXT_CATCHING)
        big_callback_delete(pokedex_entry_state->catching_cb_idx);
    free(pokedex_entry_state);
}

static void pokedex_entry_reinitialize_from_habitat() {
    pokedex_entry_state->play_cry = false;
    pokedex_entry_state->initialization_state = 0;
    pokedex_entry_state->color_to_fade_from = (color_t){0};
    callback1_set(pokedex_entry_callback_initialize_state_machine);
}

static void pokedex_entry_callback_habitat(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    pokedex_entry_free();
    // Do not free `pokedex_entry_state` here, it is used by the worldmap UI
    big_callback_delete(self);
    if (pokedex_entry_state->context == POKEDEX_ENTRY_PAGE_CONTEXT_CATCHING)
        big_callback_delete(pokedex_entry_state->catching_cb_idx);
    worldmap_ui_habitat_new(pokedex_entry_state->species, pokedex_entry_reinitialize_from_habitat);
}

static bool pokedex_entry_handle_inputs_switch_pages(u8 self) {
    if (super.keys_new.keys.right && pokedex_entry_state->page < NUM_POKEDEX_ENTRY_PAGES - 1) {
        play_sound(5);
        pokedex_entry_switch_pages(self, true, (u8)(pokedex_entry_state->page + 1));
        return true;
    } else if (super.keys_new.keys.left && pokedex_entry_state->page > 0) {
        play_sound(5);
        pokedex_entry_switch_pages(self, false, (u8)(pokedex_entry_state->page - 1));
        return true;
    }
    return false;
}

static void pokedex_entry_handle_inputs_context_pokedex(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    if (super.keys_new.keys.B) {
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = pokedex_entry_callback_return;
    } else if (super.keys_new.keys.A) {
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = pokedex_entry_callback_habitat;
    } else {
        if (pokedex_entry_pages[pokedex_entry_state->page].handle_inputs(self))
            return;
        if (pokedex_entry_handle_inputs_switch_pages(self))
            return;
    }
}

static void pokedex_entry_handle_input_context_catching(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    if (super.keys_new.keys.B || super.keys_new.keys.A) {
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = pokedex_entry_callback_return;
    } else {
        if (pokedex_entry_pages[pokedex_entry_state->page].handle_inputs(self))
            return;
        if (pokedex_entry_handle_inputs_switch_pages(self))
            return;
    }    
}


static void (*pokedex_entry_handle_inputs_by_context[POKEDEX_ENTRY_PAGE_NUM_CONTEXTS])(u8) = {
    [POKEDEX_ENTRY_PAGE_CONTEXT_POKEDEX] = pokedex_entry_handle_inputs_context_pokedex,
    [POKEDEX_ENTRY_PAGE_CONTEXT_CATCHING] = pokedex_entry_handle_input_context_catching,
};


static void pokedex_entry_handle_inputs(u8 self) {
    if (pokedex_entry_state->handle_inputs_delay > 0) {
        pokedex_entry_state->handle_inputs_delay--;
        return;
    }
    pokedex_entry_handle_inputs_by_context[pokedex_entry_state->context](self);
}


static void pokedex_entry_wait_for_cry_and_continue_handle_inputs(u8 self) {
    if (fading_control.active || dma3_busy(-1)) //  || !cry_has_finished())
        return;
    big_callbacks[self].function = pokedex_entry_handle_inputs;
}


static void pokedex_entry_play_cry_and_continue_handle_inputs(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    if (pokedex_entry_state->play_cry) {
        pokemon_play_cry(pokedex_entry_state->species, 0);
        big_callbacks[self].function = pokedex_entry_wait_for_cry_and_continue_handle_inputs;
    } else {
        big_callbacks[self].function = pokedex_entry_handle_inputs;
    }
}


static const u8 str_habitat[] = LANGDEP(
    PSTRING("KEY_ASKIP\x02Gebiete"),
    PSTRING("KEY_ASKIP\x02Habitats")
);

static const u8 str_continue[] = LANGDEP(
    PSTRING("KEY_AWeiter"),
    PSTRING("KEY_AWeiter")
);

static void pokedex_entry_cb1() {
    generic_callback1();
    bg_virtual_sync_reqeust_proceed();
    for (size_t i = 0; i < 4; i++) {
        io_set((u16)IO_BGHOFS(i), pokedex_entry_state->bg_x_offset[i]);
        io_set((u16)IO_BGVOFS(i), pokedex_entry_state->bg_y_offset[i]);
    }
}

static size_t pokedex_entry_bg_sizes[4] = {
    [0] = 32 * 32 * sizeof(bg_tile), [1] = 32 * 32 * sizeof(bg_tile), [2] = 32 * 64 * sizeof(bg_tile), [3] = 32 * 64 * sizeof(bg_tile),
};

static void pokedex_entry_initialize_state_machine() {
    switch (pokedex_entry_state->initialization_state) {
        case POKEDEX_ENTRY_INITIALIZATION_STATE_DATA_SETUP: {
            pokedex_entry_state->page = POKEDEX_ENTRY_PAGE_FLAVOR_TEXT;
            pokedex_entry_state->initialization_state++;
            FALL_THROUGH;
        }
        case POKEDEX_ENTRY_INITIALIZATION_STATE_STATE_RESET: {
            oam_reset();
            if (pokedex_entry_state->context != POKEDEX_ENTRY_PAGE_CONTEXT_CATCHING)
                big_callback_delete_all();
            fading_cntrl_reset(); 
            fading_control.buffer_transfer_disabled = true;
            oam_palette_allocation_reset();
            dma0_reset_callback();
            reset_hblank_and_vblank_callbacks();
            pokedex_entry_state->initialization_state++;
            FALL_THROUGH;
        }
        case POKEDEX_ENTRY_INITIALIZATION_STATE_SETUP_BGS: {
            bg_reset(0);
            bg_setup(0, pokedex_entry_bg_configs, 4);
            bg_display_sync();
            for (size_t i = 0; i < 4; i++) {
                u8 bg_idx = pokedex_entry_bg_configs[i].bg_id;
                pokedex_entry_state->bg_maps[bg_idx] = malloc_and_clear(pokedex_entry_bg_sizes[bg_idx]);
                bg_set_tilemap(bg_idx, pokedex_entry_state->bg_maps[bg_idx]);
                bg_virtual_map_displace(bg_idx, 0, 0);
                bg_virtual_set_displace(bg_idx, 0, 0);
                bg_virtual_sync(bg_idx);
            }
            io_set(IO_DISPCNT, IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL | IO_DISPCNT_OBJ | IO_DISPCNT_WIN0);
            io_set(IO_BLDCNT, IO_BLDCNT_NONE);
            pokedex_entry_state->initialization_state++;
            FALL_THROUGH;
        }
        case POKEDEX_ENTRY_INITIALIZATION_STATE_SETUP_TBOXES:
            tbox_free_all(); {
            tbox_sync_with_virtual_bg_and_init_all(pokedex_entry_tboxes);
            tbox_init_frame_set_style(POKEDEX_ENTRY_TBOX_PAGE_TITLE, 1, 13 * 16);
            tbox_tilemap_draw(POKEDEX_ENTRY_TBOX_PAGE_TITLE);
            tbox_tilemap_draw(POKEDEX_ENTRY_TBOX_TITLE);
            tbox_tilemap_draw(POKEDEX_ENTRY_TBOX_CAUGHT_ICON);
            tbox_tilemap_draw(POKEDEX_ENTRY_TBOX_TYPES);
            tbox_tilemap_draw(POKEDEX_ENTRY_TBOX_CATEGORY);
            tbox_tilemap_draw(POKEDEX_ENTRY_TBOX_HABITAT);
            tbox_flush_set(POKEDEX_ENTRY_TBOX_HABITAT, 0x00);
            const u8 *str = NULL;
            if (pokedex_entry_state->context == POKEDEX_ENTRY_PAGE_CONTEXT_POKEDEX) {
                str = str_habitat;
            } else if (pokedex_entry_state->context == POKEDEX_ENTRY_PAGE_CONTEXT_CATCHING) {
                str = str_continue;
            }
            if (str)
                tbox_print_string(POKEDEX_ENTRY_TBOX_HABITAT, 2, 
                (u16)((pokedex_entry_tboxes[POKEDEX_ENTRY_TBOX_HABITAT].w * 8 - string_get_width(2, str, 0)) / 2),
                1, 0, 0, &tbox_fontcolmap_white, 0, str);
            else
                tbox_sync(POKEDEX_ENTRY_TBOX_HABITAT, TBOX_SYNC_SET);

            pokedex_entry_state->initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_INITIALIZATION_STATE_LOAD_GFX: {
            int zero = 0;
            cpufastset(&zero, CHARBASE_PLUS_OFFSET_4BPP(1, 0), CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8)));
            lz77uncompwram(gfx_pokedex_entry_ui2Map, pokedex_entry_state->bg_maps[1]);
            lz77uncompvram(gfx_pokedex_entry_ui2Tiles, CHARBASE(0));
            pal_decompress(gfx_pokedex_entry_ui2Pal, 0, 16 * sizeof(color_t));
            lz77uncompvram(gfx_pokedex_entry_ui_scrollingTiles, CHARBASE_PLUS_OFFSET_4BPP(0, 128));
            pal_copy(typechart_icon_pal, 11 * 16, 16 * sizeof(color_t));
            pal_copy(tbox_pokeball_pal, 12 * 16, 16 * sizeof(color_t));
            pokedex_entry_state->initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_INITIALIZATION_STATE_SETUP_OAM: {
            pokedex_entry_state->pal_idx_pokemon = oam_allocate_palette(POKEDEX_ENTRY_GFX_TAG_SPECIES);
            pokedex_entry_state->base_tile_pokemon = oam_vram_alloc(GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
            oam_vram_allocation_table_add(POKEDEX_ENTRY_GFX_TAG_SPECIES, pokedex_entry_state->base_tile_pokemon, GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
            pokedex_entry_state->oam_idx_pokemon = oam_new_forward_search(&oam_template_pokemon, 34, 68, 0);
            pokedex_entry_state->initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_INITIALIZATION_STATE_LOAD_PAGE: {
            pokedex_entry_update_page_header();
            pokedex_entry_update_page_all();
            pokedex_entry_pages[pokedex_entry_state->page].setup_bg(pokedex_entry_state->page_layer);
            pokedex_entry_update(pokedex_entry_state->species);
            pokedex_entry_state->initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_INITIALIZATION_STATE_SETUP_SHOW: {
            for (size_t i = 0; i < 512; i++)
                pals[i] = pokedex_entry_state->color_to_fade_from;
            fading_control.buffer_transfer_disabled = false;   
            for (size_t i = 0; i < 4; i++)
                bg_virtual_sync_reqeust_push(pokedex_entry_bg_configs[i].bg_id);
            pokedex_entry_state->initialization_state++;
            break;
        }
        default: {
            for (size_t i = 0; i < 4; i++)
                bg_sync_display_and_show(pokedex_entry_bg_configs[i].bg_id);
            bg_display_sync();
            io_set(IO_BLDCNT, 0);
            io_set(IO_BLDALPHA, 0);
            io_set(IO_BLDY, 0);
            io_bic(IO_DISPCNT, IO_DISPCNT_WIN0 | IO_DISPCNT_WIN1);
            fadescreen(0xFFFFFFFF, 0, 16, 0, pokedex_entry_state->color_to_fade_from.value);
            callback1_set(pokedex_entry_cb1);
            vblank_handler_set(generic_vblank_handler);
            big_callback_new(pokedex_entry_play_cry_and_continue_handle_inputs, 0);
            break;
        }
    }

}

static void pokedex_entry_callback_initialize_state_machine() {
    DEBUG("Pokedex entry initialization state %d\n", pokedex_entry_state->initialization_state);
    pokedex_cb1();
    if (fading_control.active || dma3_busy(-1))
        return;
    pokedex_entry_initialize_state_machine();
}
    

void pokedex_entry_initialize(u16 species, u8 context, void (*continuation_cb1)(), bool play_cry,
        color_t color_to_fade_from) {
    pokedex_entry_state = malloc_and_clear(sizeof(pokedex_entry_state_t));
    pokedex_entry_state->initialization_state = 0;
    pokedex_entry_state->species = species;
    pokedex_entry_state->context = context;
    pokedex_entry_state->continuation = continuation_cb1;
    pokedex_entry_state->play_cry = (u8)(play_cry & 1);
    pokedex_entry_state->color_to_fade_from = color_to_fade_from;
    callback1_set(pokedex_entry_callback_initialize_state_machine);
}

void pokedex_entry_page_initialize_tboxes(const tboxdata *boxes) {
    pokedex_entry_state->page_num_tboxes = 0;
    for (size_t i = 0; boxes[i].bg_id != 0xFF; i++) {
        pokedex_entry_state->page_tbox_idxs[i] = tbox_new(boxes + i);
        pokedex_entry_state->page_num_tboxes++;
    }
}

void pokedex_entry_page_free_tboxes() {
    for (size_t i = 0; i < pokedex_entry_state->page_num_tboxes; i++) {
        tbox_flush_set(pokedex_entry_state->page_tbox_idxs[i], 0x00);
        tbox_flush_map(pokedex_entry_state->page_tbox_idxs[i]);
        tbox_copy_to_vram(pokedex_entry_state->page_tbox_idxs[i], TBOX_COPY_TILESET | TBOX_COPY_TILEMAP);
        tbox_free(pokedex_entry_state->page_tbox_idxs[i]);
    }
    pokedex_entry_state->page_num_tboxes = 0;
}

void pokedex_entry_page_load_gfx(u8 layer, const void *tiles, const void *map, const void *pal) {
    lz77uncompvram(tiles, CHARBASE_PLUS_OFFSET_4BPP(1, 1 + layer * POKEDEX_ENTRY_PAGE_NUM_TILES));
    lz77uncompwram(map, pokedex_entry_state->bg_maps[2 + layer]);
    pal_decompress(pal, (u16)(16 * (2 + POKEDEX_ENTRY_PAGE_NUM_PALS * layer)), 16 * sizeof(color_t));
    // Shift the palette and tile indices of the map
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 30; x++) {
            bg_tile tile = pokedex_entry_state->bg_maps[2 + layer][y][x];
            tile.text.tile_number = (u16)((tile.text.tile_number + layer * POKEDEX_ENTRY_PAGE_NUM_TILES) & 0x3FF);
            tile.text.palette = (u16)((2 + layer * POKEDEX_ENTRY_PAGE_NUM_PALS) & 0xF);
            pokedex_entry_state->bg_maps[2 + layer][y][x] = tile;
        }
    }
}

u8 pokedex_entry_initialize_from_battle(u16 species) {
    color_t white = {.rgb = {.red = 31, .green = 31, .blue = 31}};
    pokedex_entry_initialize(species, POKEDEX_ENTRY_PAGE_CONTEXT_CATCHING, battle_callback1, true, white);
    pokedex_entry_state->handle_inputs_delay = 120;
    pokedex_entry_state->catching_cb_idx = big_callback_new((void(*)(u8))nullsub, 0);
    return pokedex_entry_state->catching_cb_idx;
}