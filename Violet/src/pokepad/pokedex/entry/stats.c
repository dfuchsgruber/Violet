#include "types.h"
#include "fading.h"
#include "pokepad/pokedex/entry.h"
#include "pokepad/pokedex/pages/stats.h"
#include "pokemon/moves.h"
#include "agbmemory.h"
#include "language.h"
#include "attack.h"
#include "bios.h"
#include "music.h"
#include "dma.h"
#include "debug.h"
#include "gpu.h"
#include "menu_indicators.h"
#include "pokepad/pokedex/operator.h"
#include "pokemon/basestat.h"
#include "constants/pokemon_stat_names.h"
#include "mega.h"
#include "pokemon/names.h"

extern const LZ77COMPRESSED gfx_pokedex_entry_page_stats_hexagonPal;

static void pokedex_entry_page_stats_setup_bg_shift_map(u8 layer) {
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 30; x++) {
            bg_tile tile = pokedex_entry_state->bg_maps[2 + layer][y][x];
            tile.text.tile_number = (u16)((tile.text.tile_number + layer * POKEDEX_ENTRY_PAGE_NUM_TILES) & 0x3FF);
            tile.text.palette = (u16)((2 + layer * POKEDEX_ENTRY_PAGE_NUM_PALS) & 0xF);
            pokedex_entry_state->bg_maps[2 + layer][y][x] = tile;
        }
    }
}

void pokedex_entry_page_stats_setup_bg(u8 layer) {
    lz77uncompvram(gfx_pokedex_entry_page_stats_uiTiles, CHARBASE_PLUS_OFFSET_4BPP(1, 1 + layer * POKEDEX_ENTRY_PAGE_NUM_TILES));
    lz77uncompwram(gfx_pokedex_entry_page_stats_uiMap, pokedex_entry_state->bg_maps[2 + layer]);
    pal_decompress(gfx_pokedex_entry_page_stats_uiPal, (u16)(16 * (2 + POKEDEX_ENTRY_PAGE_NUM_PALS * layer)), 16 * sizeof(color_t));
    pokedex_entry_page_stats_setup_bg_shift_map(layer);
}


static const tboxdata pokedex_entry_page_stats_tboxes[NUM_POKEDEX_ENTRY_PAGE_STATS_TBOXES + 1] = {
    // [POKEDEX_ENTRY_PAGE_stats_TBOX_METHOD] = {.bg_id = 0, .x = 22, .y = 13, .w = 8, .h = 7, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 11 * 10 + 14 * 7 + 6 * 10 + 6 * 10},
    [POKEDEX_ENTRY_PAGE_STATS_TBOX_STAT_BASE + STAT_HP] = {.bg_id = 0, .x = 15, .w = 8, .y = 3, .h = 4, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 0 * 9 * 4},
    [POKEDEX_ENTRY_PAGE_STATS_TBOX_STAT_BASE  + STAT_ATTACK] = {.bg_id = 0, .x = 25, .w = 5, .y = 7, .h = 4, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 1 * 9 * 4},
    [POKEDEX_ENTRY_PAGE_STATS_TBOX_STAT_BASE + STAT_DEFENSE] = {.bg_id = 0, .x = 25, .w = 5, .y = 14, .h = 4, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 2 * 9 * 4},
    [POKEDEX_ENTRY_PAGE_STATS_TBOX_STAT_BASE + STAT_SPEED] = {.bg_id = 0, .x = 15, .w = 8, .y = 17, .h = 3, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 3 * 9 * 4},
    [POKEDEX_ENTRY_PAGE_STATS_TBOX_STAT_BASE + STAT_SPECIAL_ATTACK] = {.bg_id = 0, .x = 9, .w = 5, .y = 7, .h = 4, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 4 * 9 * 4},
    [POKEDEX_ENTRY_PAGE_STATS_TBOX_STAT_BASE + STAT_SPECIAL_DEFENSE] = {.bg_id = 0, .x = 9, .w = 5, .y = 14, .h = 4, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 5 * 9 * 4},
    [NUM_POKEDEX_ENTRY_PAGE_STATS_TBOXES] = {.bg_id = 0xFF},
};

static inline void pokedex_entry_stats_sprite_basestats_set_pixel_to_color(int x, int y, u8 color) {
	x += POKEDEX_ENTRY_PAGE_STATS_HEXAGON_SIZE / 2; y += POKEDEX_ENTRY_PAGE_STATS_HEXAGON_SIZE / 2;
    int i = x / 64, j = y / 64;
    if (i < 0 || i >= 2 || j < 0 || j >= 2) {
        DEBUG("Attempt to set pixel outside the stat chart (%d, %d)\n", x ,y);
        return;
    }
    x %= 64; y %= 64;
    int *sprite = (int*)pokedex_entry_state->basestats_sprites[i][j];
	int tile_x = x >> 3, tile_y = y >> 3;
	int pixel_x = x & 7, pixel_y = y & 7;
	int tile_idx = 8 * tile_y + tile_x;
	int *pixel = &sprite[8 * tile_idx + pixel_y]; // Each integer describes a row of a character
	int pixel_shift = pixel_x << 2;
	int pixel_mask = 15 << pixel_shift;
	*pixel = (*pixel & ~pixel_mask) | (color << pixel_shift);
}

static void pokedex_entry_stats_sprite_basestats_set_pixel(int x, int y) {
    pokedex_entry_stats_sprite_basestats_set_pixel_to_color(x, y, 1);
}

static void pokedex_entry_stats_sprite_basestats_set_pixel_mega(int x, int y) {
    pokedex_entry_stats_sprite_basestats_set_pixel_to_color(x, y, 2);
}

static const sprite sprite_hexagon = {
    .attr0 = ATTR0_SHAPE_SQUARE | ATTR0_MODE_SEMI_TRANSPARENT,
    .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(1)};


// static const rotscale_frame rotscale_anim_double_size[] = {
//     {.affine = {0x200, 0x200, 0, 0, 0}},
//     {.command = {ROTSCALE_ANIM_END, 0, 0, 0}}
// };

// static const rotscale_frame *const rotscale_anim_table_double_size[] = {
//     rotscale_anim_double_size
// };

static const oam_template oam_template_basestats_hexagon[2][2] = {
    {
        {
            .tiles_tag = POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS + 0, .pal_tag = POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS,
            .oam = &sprite_hexagon, .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
            .callback = oam_null_callback,
        },
        {
            .tiles_tag = POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS + 1, .pal_tag = POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS,
            .oam = &sprite_hexagon, .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
            .callback = oam_null_callback,
        },
    },{
        {
            .tiles_tag = POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS + 2, .pal_tag = POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS,
            .oam = &sprite_hexagon, .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
            .callback = oam_null_callback,
        },
        {
            .tiles_tag = POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS + 3, .pal_tag = POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS,
            .oam = &sprite_hexagon, .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
            .callback = oam_null_callback,
        },
    },
};

static const tbox_font_colormap font_colormap_white = {.background = 0, .body = 1, .edge = 2};
static const u8 str_stat[] = PSTRING("BUFFER_1");
static const u8 str_stat_with_increase[] = PSTRING("BUFFER_1+BUFFER_2");

static const u16 stat_xs[6] = {
    [STAT_HP] = 3,
    [STAT_SPEED] = 3,
    [STAT_SPECIAL_ATTACK] = 0,
    [STAT_SPECIAL_DEFENSE] = 0,
    [STAT_ATTACK] = 4,
    [STAT_DEFENSE] = 4,
};

static const u16 stat_ys[6] = {
    [STAT_HP] = 2,
    [STAT_SPEED] = 6,
};

static const u16 stat_ws[6] = {
    [STAT_HP] = 62,
    [STAT_SPEED] = 62,
    [STAT_SPECIAL_ATTACK] = 33,
    [STAT_SPECIAL_DEFENSE] = 33,
    [STAT_ATTACK] = 33,
    [STAT_DEFENSE] = 33,
};

static const u8 stat_single_line[6] = {[STAT_HP] = true, [STAT_SPEED] = true};

bool pokedex_entry_page_stats_setup() {
    bool caught = pokedex_operator(pokedex_entry_state->species, POKEDEX_CAUGHT, true);
    switch (pokedex_entry_state->page_initialization_state) {
        case POKEDEX_ENTRY_PAGE_STATS_INITIALIZATION_STATE_DATA_SETUP: {
            for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->basestats_sprites); i++) {
                for (size_t j = 0; j < ARRAY_COUNT(pokedex_entry_state->basestats_sprites[i]); j++) {
                    int zero = 0;
                    CPUSETFILL16(&zero, pokedex_entry_state->basestats_sprites[i][j], GRAPHIC_SIZE_4BPP(64, 64));
                }
            }
            if (caught) {
                const basestat *basestats_species = basestats + pokedex_entry_state->species;
                int stats[6] = {
                    [STAT_HP] = basestats_species->stats[STAT_HP],
                    [STAT_ATTACK] = basestats_species->stats[STAT_ATTACK],
                    [STAT_DEFENSE] = basestats_species->stats[STAT_DEFENSE],
                    [STAT_SPEED] = basestats_species->stats[STAT_SPEED],
                    [STAT_SPECIAL_ATTACK] = basestats_species->stats[STAT_SPECIAL_ATTACK],
                    [STAT_SPECIAL_DEFENSE] = basestats_species->stats[STAT_SPECIAL_DEFENSE],
                };
                int max_stat = 0;
                for (size_t i = 0; i < ARRAY_COUNT(stats); i++) {
                    if (stats[i] > max_stat)
                        max_stat = stats[i];
                }
                const mega_evolution_t *mega = mega_evolution_get_by_species(pokedex_entry_state->species);
                if (mega) {
                    int stats_mega[6] = {
                        [STAT_HP] = basestats[mega->mega_species].stats[STAT_HP],
                        [STAT_ATTACK] = basestats[mega->mega_species].stats[STAT_ATTACK],
                        [STAT_DEFENSE] = basestats[mega->mega_species].stats[STAT_DEFENSE],
                        [STAT_SPEED] = basestats[mega->mega_species].stats[STAT_SPEED],
                        [STAT_SPECIAL_ATTACK] = basestats[mega->mega_species].stats[STAT_SPECIAL_ATTACK],
                        [STAT_SPECIAL_DEFENSE] = basestats[mega->mega_species].stats[STAT_SPECIAL_DEFENSE],
                    };
                    for (size_t i = 0; i < ARRAY_COUNT(stats_mega); i++) {
                        if (stats_mega[i] > max_stat)
                            max_stat = stats_mega[i];
                    }
                    FIXED ratios_mega[6] = {
                        [STAT_HP] = FIXED_DIV(INT_TO_FIXED(stats_mega[STAT_HP]), INT_TO_FIXED(max_stat)),
                        [STAT_ATTACK] =  FIXED_DIV(INT_TO_FIXED(stats_mega[STAT_ATTACK]), INT_TO_FIXED(max_stat)),
                        [STAT_DEFENSE] = FIXED_DIV(INT_TO_FIXED(stats_mega[STAT_DEFENSE]), INT_TO_FIXED(max_stat)),
                        [STAT_SPEED] = FIXED_DIV(INT_TO_FIXED(stats_mega[STAT_SPEED]), INT_TO_FIXED(max_stat)),
                        [STAT_SPECIAL_ATTACK] = FIXED_DIV(INT_TO_FIXED(stats_mega[STAT_SPECIAL_ATTACK]), INT_TO_FIXED(max_stat)),
                        [STAT_SPECIAL_DEFENSE] = FIXED_DIV(INT_TO_FIXED(stats_mega[STAT_SPECIAL_DEFENSE]), INT_TO_FIXED(max_stat)),
                    };
                    gpu_render_polygon_by_radius(ratios_mega, 6, (POKEDEX_ENTRY_PAGE_STATS_HEXAGON_SIZE / 2) - 1, pokedex_entry_stats_sprite_basestats_set_pixel_mega);
                }
                max_stat = MAX(max_stat, 160);
                FIXED ratios[6] = {
                    [STAT_HP] = FIXED_DIV(INT_TO_FIXED(stats[STAT_HP]), INT_TO_FIXED(max_stat)),
                    [STAT_ATTACK] =  FIXED_DIV(INT_TO_FIXED(stats[STAT_ATTACK]), INT_TO_FIXED(max_stat)),
                    [STAT_DEFENSE] = FIXED_DIV(INT_TO_FIXED(stats[STAT_DEFENSE]), INT_TO_FIXED(max_stat)),
                    [STAT_SPEED] = FIXED_DIV(INT_TO_FIXED(stats[STAT_SPEED]), INT_TO_FIXED(max_stat)),
                    [STAT_SPECIAL_ATTACK] = FIXED_DIV(INT_TO_FIXED(stats[STAT_SPECIAL_ATTACK]), INT_TO_FIXED(max_stat)),
                    [STAT_SPECIAL_DEFENSE] = FIXED_DIV(INT_TO_FIXED(stats[STAT_SPECIAL_DEFENSE]), INT_TO_FIXED(max_stat)),
                };
                gpu_render_polygon_by_radius(ratios, 6, (POKEDEX_ENTRY_PAGE_STATS_HEXAGON_SIZE / 2) - 1, pokedex_entry_stats_sprite_basestats_set_pixel);
                io_set(IO_BLDCNT, IO_BLDCNT_BG3_SECOND | IO_BLDCNT_BG2_SECOND | IO_BLDCNT_BG1_SECOND |
                    IO_BLDCNT_BG0_SECOND | IO_BLDCNT_ALPHA_BLENDING);
                io_set(IO_BLDALPHA, IO_BLDALPHA_EVA(7) | IO_BLDALPHA_EVB(11));
            }
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_PAGE_STATS_INITIALIZATION_STATE_SETUP_TBOXES: {
            pokedex_entry_page_initialize_tboxes(pokedex_entry_page_stats_tboxes);
            const basestat *basestats_species = basestats + pokedex_entry_state->species;
            const mega_evolution_t *mega = mega_evolution_get_by_species(pokedex_entry_state->species);
            for (int i = 0; i <= STAT_SPECIAL_DEFENSE; i++) {
                u8 tbox_idx = pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_STATS_TBOX_STAT_BASE + i];
                tbox_flush_set(tbox_idx, 0x00);
                tbox_tilemap_draw(tbox_idx);
                if (caught) {
                    const u8 *str_name = pokemon_stat_names_abbreviated[i];
                    itoa(buffer0, basestats_species->stats[i], ITOA_NO_PADDING, 3);
                    bool with_increase = false;
                    if (mega) {
                        int delta = basestats[mega->mega_species].stats[i] - basestats_species->stats[i];
                        itoa(buffer1, delta, ITOA_NO_PADDING, 3);
                        with_increase = delta > 0;
                    }
                    string_decrypt(strbuf, with_increase ? str_stat_with_increase : str_stat);
                    if (stat_single_line[i]) {
                        u16 width_total = (u16)(string_get_width(0, str_name, 0) + string_get_width(0, strbuf, 0)) + 4;
                        u16 x = (u16)(stat_xs[i] + (stat_ws[i] - width_total) / 2);
                        tbox_print_string(tbox_idx, 0, x, stat_ys[i]
                        , 0, 0, &font_colormap_white, 0xFF, str_name);
                        tbox_print_string(tbox_idx, 0,
                            (u16)(x + string_get_width(0, str_name, 0) + 4), 
                            stat_ys[i], 0, 0, &font_colormap_white, 0, strbuf);
                    } else {
                        tbox_print_string(tbox_idx, 0, 
                            (u16)(stat_xs[i] + (stat_ws[i] - string_get_width(0, str_name, 0)) / 2), 
                            stat_ys[i], 0, 0, &font_colormap_white, 0xFF, str_name);
                        tbox_print_string(tbox_idx, 0,
                            (u16)(stat_xs[i] + (stat_ws[i] - string_get_width(0, strbuf, 0)) / 2), 
                            (u16)(10 + stat_ys[i]), 0, 0, &font_colormap_white, 0, strbuf);
                    }
                } else {
                    tbox_sync(tbox_idx, TBOX_SYNC_SET);
                }
            }


            pokedex_entry_state->page_initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_PAGE_STATS_INITIALIZATION_STATE_SETUP_OAM: {
            u8 hexagon_pal = oam_allocate_palette(POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS);
            pal_decompress(gfx_pokedex_entry_page_stats_hexagonPal, (u16)(256 + 16 * hexagon_pal), 16 * sizeof(color_t));
            for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->basestats_sprites); i++) {
                for (size_t j = 0; j < ARRAY_COUNT(pokedex_entry_state->basestats_sprites[i]); j++) {
                    u16 oam_hexagon_tile = oam_vram_alloc(GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
                    oam_vram_allocation_table_add((u16)(POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS + 
                        (i * ARRAY_COUNT(pokedex_entry_state->basestats_sprites[i]) + j)), oam_hexagon_tile,
                        GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
                    CPUSETCOPY16(pokedex_entry_state->basestats_sprites[i][j], OAMCHARBASE(oam_hexagon_tile), GRAPHIC_SIZE_4BPP(64, 64));
                    pokedex_entry_state->basestats_sprite_oam_idxs[i][j] = oam_new_forward_search(&oam_template_basestats_hexagon[i][j], 
                        (s16)(POKEDEX_ENTRY_PAGE_STATS_HEXAGON_X + 64 * i),
                        (s16)(POKEDEX_ENTRY_PAGE_STATS_HEXAGON_Y + 64 * j), 0);
                }
            }
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        default:
            return false;
    }
    return true;
}

void pokedex_entry_page_stats_destroy() {
    pokedex_entry_page_free_tboxes();
    for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->basestats_sprites); i++)
        for (size_t j = 0; j < ARRAY_COUNT(pokedex_entry_state->basestats_sprites[i]); j++) 
            oam_free(oams + pokedex_entry_state->basestats_sprite_oam_idxs[i][j]);
}


bool pokedex_entry_page_stats_handle_inputs(UNUSED u8 self) {
    if (fading_control.active || dma3_busy(-1)) {
        return false;
    }
    return false;
}
