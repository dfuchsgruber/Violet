#include "types.h"
#include "pokepad/gui.h"
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
#include "pokepad2.h"


static pokepad_wallpaper pokepad_wallpapers[] = {
    {
        .tileset = gfx_pokepad_wallpaper_startersTiles, .tilemap = gfx_pokepad_wallpaper_startersMap,
        .palette = gfx_pokepad_wallpaper_startersPal, .flag = 0,
    },
};

static u8 wondertrade_name[] = LANGDEP(PSTRING("Wundert."), PSTRING("Wondert."));
static u8 pokedex_name[] = LANGDEP(PSTRING("Pokédex"), PSTRING("Pokédex"));
static u8 pokeradar_name[] = LANGDEP(PSTRING("Pokéradar"), PSTRING("Pokéradar"));
static u8 incubator_name[] = LANGDEP(PSTRING("Inkubator"), PSTRING("Incubator"));

static u8 wondertrade_description[] = LANGDEP(
    PSTRING("Tausche Pokémon mit Trainern\naus aller Welt."),
    PSTRING("Trade Pokémon with trainers\nall over the world.")
);
static u8 pokedex_description[] = LANGDEP(
    PSTRING("Betrachte Aufzeichnungen zu gefangenen\nund gesehenen Pokémon."),
    PSTRING("View records of caught and seen\nPokémon.")
);
static u8 pokeradar_description[] = LANGDEP(
    PSTRING("Spüre seltene Pokémon in der\nNähe auf."),
    PSTRING("Identify rare Pokémon nearby.")
);
static u8 incubator_description[] = LANGDEP(
    PSTRING("Brüte Eier aus und überprüfe\nderen Status."),
    PSTRING("Hatch eggs and check on their\nstatus.")
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
    TBOX_DESCRIPTION = 0,
    TBOX_APP_UPPER,
    TBOX_APP_LOWER,
};

static tboxdata pokepad_tboxes[] = {
    [TBOX_DESCRIPTION] = {
        .bg_id = 0, .x = 0, .y = 15, .w = 30, .h = 5, .pal = 15, .start_tile = 1,
    },
    [TBOX_APP_UPPER] = {
        .bg_id = 0, .x = 0 * 60, .y = 8 , .w = 30, .h = 2, .pal = 15, .start_tile = 1 + 30 * 5
    },
    [TBOX_APP_LOWER] = {
        .bg_id = 0, .x = 0 * 60, .y = 13 , .w = 30, .h = 2, .pal = 15, .start_tile = 1 + 30 * 5 + 30 * 2
    },
};

static bg_config bg_configs[] = {
    {.bg_id = 0, .char_base = 2, .map_base = 31, .size = 0, .color_mode = 0, .priority = 0},
    {.bg_id = 1, .char_base = 0, .map_base = 29, .size = 0, .color_mode = 1, .priority = 1},
};

static pokepad_wallpaper *pokepad_get_wallpaper() {
    // TODO
    return pokepad_wallpapers + 0;
}

static void pokepad2_idle(u8 self) {
    (void)self;
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
        tbox_print_string(row > 0 ? TBOX_APP_LOWER : TBOX_APP_UPPER, 2, (u16)((60 - string_width) / 2 + 60 * col), 0, 0, 0, &app_name_fontcolmap, 0, item->name);
        POKEPAD_STATE->app_oams[POKEPAD_STATE->num_app_oams] = oam_new_forward_search(&template, (s16)(30 + 60 * col), (s16)(48 + 48 * row), 0);
        ++POKEPAD_STATE->num_app_oams;
        num_to_initialize--;
    }
    return true;
}

static tbox_font_colormap description_fontcolmap = {
    .background = 1, .body = 2, .edge = 1,
};

static void pokepad2_update_description() {
    pokepad2_item *item = pokepad2_items + POKEPAD_STATE->items[POKEPAD_STATE->cursor_idx];
    tbox_flush_set(TBOX_DESCRIPTION, 0x11);
    tbox_print_string(TBOX_DESCRIPTION, 2, 8, 6, 0, 0, &description_fontcolmap, 0, item->description);
}

enum {
    RESET,
    BG_SETUP,
    GFX_LOAD,
    TBOX_SETUP,
    DATA_SETUP,
    APP_SETUP,
    PAL_SETUP,
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
            bg_sync_display_and_show(0);
            bg_sync_display_and_show(1);
            bg_display_sync();
            bg_virtual_map_displace(0, 0, 0);
            bg_virtual_set_displace(0, 0, 0);
            bg_virtual_map_displace(1, 0, 0);
            bg_virtual_set_displace(1, 0, 0);
            io_set(0x48, 0x1F3F);
            io_set(0x50, 0x3F41);
            io_set(0x52, 0x0a0F);
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case GFX_LOAD: {
            pokepad_wallpaper *wallpaper = pokepad_get_wallpaper();
            lz77uncompwram(wallpaper->tilemap, bg_get_tilemap(1));
            lz77uncompvram(wallpaper->tileset, CHARBASE(0));
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case DATA_SETUP: {
            POKEPAD_STATE->num_items = 0;
            POKEPAD_STATE->num_app_oams = 0;
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
            pokepad_wallpaper *wallpaper = pokepad_get_wallpaper();
            pal_decompress(wallpaper->palette, 0, 10 * 16 * sizeof(color_t)); // Probably a bit too much...
            color_t black = {.rgb={0, 0, 0}};
            pal_gamma_shift_with_blend(0, 10, 3, 4, black);
            cpuset(pals, pal_restore, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(10 * 16 * sizeof(color_t)));
            pal_copy(tbox_palette_transparent, 15 * 16, 16 * sizeof(color_t));
            pal_set_all_to_black();
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case TBOX_SETUP: {
            tbox_sync_with_virtual_bg_and_init_all(pokepad_tboxes);
            tbox_tilemap_draw(TBOX_DESCRIPTION);
            tbox_tilemap_draw(TBOX_APP_UPPER);
            tbox_tilemap_draw(TBOX_APP_LOWER);
            tbox_flush_set(TBOX_DESCRIPTION, 0x11);
            tbox_flush_set(TBOX_APP_UPPER, 0x0);
            tbox_flush_set(TBOX_APP_LOWER, 0x0);
            tbox_sync(TBOX_APP_UPPER, TBOX_SYNC_SET);
            tbox_sync(TBOX_APP_LOWER, TBOX_SYNC_SET);
            pokepad2_update_description();
            ++(POKEPAD_STATE->initialization_state);
            break;
        }
        case BG_COPY: {
            bg_virtual_sync(0);
            bg_virtual_sync(1);
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


static void pokepad2_callback_initialize() {
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