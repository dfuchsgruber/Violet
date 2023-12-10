#include "types.h"
#include "fading.h"
#include "pokepad/pokedex/entry.h"
#include "pokepad/pokedex/pages/move_list.h"
#include "pokemon/moves.h"
#include "agbmemory.h"
#include "language.h"
#include "attack.h"
#include "bios.h"
#include "music.h"
#include "dma.h"
#include "debug.h"
#include "constants/attack_categories.h"
#include "menu_indicators.h"
#include "pokepad/pokedex/operator.h"
#include "pokemon/breeding.h"
#include "pokemon/evolution.h"
#include "pokemon/moves.h"
#include "item/item.h"
#include "item/tm_hm.h"
#include "pokemon/sprites.h"
#include "pokemon/basestat.h"
#include "overworld/sprite.h"
#include "pokemon/move_relearner.h"

static void pokedex_entry_page_move_list_setup_bg_shift_map(u8 layer) {
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 30; x++) {
            bg_tile tile = pokedex_entry_state->bg_maps[2 + layer][y][x];
            tile.text.tile_number = (u16)((tile.text.tile_number + layer * POKEDEX_ENTRY_PAGE_NUM_TILES) & 0x3FF);
            tile.text.palette = (u16)((2 + layer * POKEDEX_ENTRY_PAGE_NUM_PALS) & 0xF);
            pokedex_entry_state->bg_maps[2 + layer][y][x] = tile;
        }
    }
}

void pokedex_entry_page_move_list_setup_bg(u8 layer) {
    lz77uncompvram(gfx_pokedex_entry_page_move_list_uiTiles, CHARBASE_PLUS_OFFSET_4BPP(1, 1 + layer * POKEDEX_ENTRY_PAGE_NUM_TILES));
    lz77uncompwram(gfx_pokedex_entry_page_move_list_uiMap, pokedex_entry_state->bg_maps[2 + layer]);
    pal_decompress(gfx_pokedex_entry_page_move_list_uiPal, (u16)(16 * (2 + POKEDEX_ENTRY_PAGE_NUM_PALS * layer)), 16 * sizeof(color_t));
    pokedex_entry_page_move_list_setup_bg_shift_map(layer);
}

void pokedex_entry_page_move_list_extra_setup_bg(u8 layer) {
    lz77uncompvram(gfx_pokedex_entry_page_move_list_extra_uiTiles, CHARBASE_PLUS_OFFSET_4BPP(1, 1 + layer * POKEDEX_ENTRY_PAGE_NUM_TILES));
    lz77uncompwram(gfx_pokedex_entry_page_move_list_extra_uiMap, pokedex_entry_state->bg_maps[2 + layer]);
    pal_decompress(gfx_pokedex_entry_page_move_list_extra_uiPal, (u16)(16 * (2 + POKEDEX_ENTRY_PAGE_NUM_PALS * layer)), 16 * sizeof(color_t));
    pokedex_entry_page_move_list_setup_bg_shift_map(layer);
}


static const tboxdata pokedex_entry_page_move_list_tboxes[NUM_POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOXES + 1] = {
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_LIST] = {.bg_id = 0, .x = 19, .y = 3, .w = 11, .h = 10, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE},
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION] = {.bg_id = 0, .x = 9, .y = 13, .h = 7, .w = 14, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 11 * 10},
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES] = {.bg_id = 0, .x = 9, .y = 3, .h = 10, .w = 5, .pal = 11, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 11 * 10 + 14 * 7},
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES] = {.bg_id = 0, .x = 14, .y = 3, .h = 10, .w = 5, .pal = 11, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 11 * 10 + 14 * 7 + 6 * 10},
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_METHOD] = {.bg_id = 0, .x = 22, .y = 13, .w = 8, .h = 7, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 11 * 10 + 14 * 7 + 6 * 10 + 6 * 10},
    [NUM_POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOXES] = {.bg_id = 0xFF},
};

static void pokedex_entry_page_move_list_setup_tboxes(UNUSED u8 which) {
    pokedex_entry_page_initialize_tboxes(pokedex_entry_page_move_list_tboxes);
    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION], 0x00);
    tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION]);
    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 0x00);
    tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES]);
    tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES]);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
        MOVE_INFO_POWER, 2, 0 * 13 + 2);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
        MOVE_INFO_TYPE, 2, 1 * 13 + 2);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
        MOVE_INFO_CATEGORY, 2, 2 * 13 + 2);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
        MOVE_INFO_ACCURACY, 2, 3 * 13 + 2);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
        MOVE_INFO_PP, 2, 4 * 13 + 2);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], 
        MOVE_INFO_EFFECT, 2, 5 * 13 + 2);
    tbox_sync(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES], TBOX_SYNC_SET);
    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 0x00);

    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_METHOD], 0x00);
    tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_METHOD]); 
    tbox_sync(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_METHOD], TBOX_SYNC_SET);    
}

static void pokedex_entry_page_move_list_setup_scroll_indicators(u16 *cursor_position) {
    bool caught = pokedex_operator(pokedex_entry_state->species, POKEDEX_CAUGHT, true);
    if (caught) {
        scroll_indicator_template crafting_ui_scroll_indicator_template_up_down = {
            .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 25 * 8, .arrow0_y = 24,
            .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 25 * 8, .arrow1_y = 24 + 8 * 10,
            .arrow0_threshold = 0, 
            .arrow1_threshold = (u16) MAX(0, (pokedex_entry_state->move_list_size - 
                POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_SHOWN)),
            .tiles_tag = 111,
            .pal_tag = 111,
        };
        pokedex_entry_state->move_list_scroll_indicators_cb_idx = scroll_indicator_new(&crafting_ui_scroll_indicator_template_up_down, 
            cursor_position);
    } else {
        pokedex_entry_state->move_list_scroll_indicators_cb_idx = 0xFF;
    }
}

static void pokedex_entry_page_move_list_print_item_callback(u8 tbox_idx, int idx, u8 y) {
    (void)tbox_idx; (void)idx; (void)y;
}

static const tbox_font_colormap font_colormap_std = {.background = 0, .body = 2, .edge = 3};
static const tbox_font_colormap font_colormap_white = {.background = 0, .body = 1, .edge = 2};
static const tbox_font_colormap font_colormap_typechart_pal = {.background = 0, .body = 15, .edge = 14};

static const u8 str_move_no_power[] = PSTRING("---");

static void pokedex_entry_page_move_list_update(int idx) {
    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION], 0x00);
    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION], 
        0, 0, 0, 0, 0, &font_colormap_std, 0, attack_descriptions[idx - 1]);
    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 0x00);
    if (attacks[idx].base_power <= 1 || attacks[idx].category == CATEGORY_STATUS) {
        strcpy(strbuf, str_move_no_power);
    } else {
        itoa(strbuf, attacks[idx].base_power, ITOA_NO_PADDING, 3);
    }
    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
        2, 4, 2, 0, 0, &font_colormap_typechart_pal, 0xFF, strbuf);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
        (u8)(MOVE_INFO_TYPE_BASE + attacks[idx].type), 4, 1 * 13 + 2);
    tbox_blit_move_info_icon(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
        (u8)(MOVE_INFO_PHYSICAL + attacks[idx].category), 2, 2 * 13 + 2);
    if (attacks[idx].accuracy == 0) {
        strcpy(strbuf, str_move_no_power);
    } else {
        itoa(strbuf, attacks[idx].accuracy, ITOA_NO_PADDING, 3);
    }
    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
            2, 4, 2 + 3 * 13, 0, 0, &font_colormap_typechart_pal, 0xFF, strbuf);
    itoa(strbuf, attacks[idx].pp, ITOA_NO_PADDING, 3);
    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], 
            2, 4, 2 + 4 * 13, 0, 0, &font_colormap_typechart_pal, 0xFF, strbuf);
    tbox_sync(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES], TBOX_SYNC_SET);
}

static void pokedex_entry_page_move_list_cursor_move_callback(int idx, u8 on_initialize, UNUSED list_menu *list) {
    if (!on_initialize)
        play_sound(5);
    pokedex_entry_page_move_list_update(idx);
}

static void pokedex_entry_page_move_list_extra_delete_icon_if_present() {
    if (pokedex_entry_state->move_list_extra_oam_idx < NUM_OAMS) {
        oam_free_graphic(&oams[pokedex_entry_state->move_list_extra_oam_idx]);
        oam_delete(&oams[pokedex_entry_state->move_list_extra_oam_idx]);
        pokedex_entry_state->move_list_extra_oam_idx = NUM_OAMS;
    }
}

static const sprite sprite_egg = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0)};

extern const u8 gfx_pkmn_species_412_pokemon_egg_iconTiles[2][GRAPHIC_SIZE_4BPP(32, 32)];

static const graphic graphics_egg[] = {
    {.sprite = gfx_pkmn_species_412_pokemon_egg_iconTiles[0], .size = GRAPHIC_SIZE_4BPP(32, 32)},
    {.sprite = gfx_pkmn_species_412_pokemon_egg_iconTiles[1], .size = GRAPHIC_SIZE_4BPP(32, 32)},
};

static const gfx_frame animation_egg[] = {
    {.data = 0, .duration = 0}, {.data = 0, .duration = 32}, {.data = 1, .duration = 32}, {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const animation_egg_frames[] = {
    animation_egg,
};

static const oam_template templates_icon_egg[] = {
    {
        .tiles_tag = 0xFFFF, .pal_tag = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON, .oam = &sprite_egg, 
        .animation = animation_egg_frames, .graphics = graphics_egg, .rotscale = oam_rotscale_anim_table_null, 
        .callback = oam_null_callback,
    },{
        .tiles_tag = 0xFFFF, .pal_tag = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON + 1, .oam = &sprite_egg, 
        .animation = animation_egg_frames, .graphics = graphics_egg, .rotscale = oam_rotscale_anim_table_null, 
        .callback = oam_null_callback,
    },
};

static const oam_template templates_icons_tm_hm[] = {
    {
        .tiles_tag = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON, 
        .pal_tag = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON, .oam = &sprite_egg, 
        .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null, 
        .callback = oam_null_callback,
    },{
        .tiles_tag = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON + 1, 
        .pal_tag = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON + 1, .oam = &sprite_egg, 
        .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null, 
        .callback = oam_null_callback,
    },
};

static const oam_template templates_icon_crystal = {
    .tiles_tag = 0xFFFF, .oam = &sprite_egg,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};


static const u8 str_egg_move[] = LANGDEP(PSTRING("Durch Zucht."), PSTRING("By breeding."));
static const u8 str_tm[] = LANGDEP(PSTRING("TM"), PSTRING("TM"));
static const u8 str_hm[] = LANGDEP(PSTRING("VM"), PSTRING("HM"));
static const u8 str_tm_hm_move[] = LANGDEP(PSTRING("Durch BUFFER_1BUFFER_2"), PSTRING("By BUFFER_1BUFFER_2"));
static const u8 str_crystal_move[] = LANGDEP(PSTRING("Kristall"), PSTRING("Crystal"));
static const u8 str_tutor_move[] = LANGDEP(PSTRING("Durch Tutor"), PSTRING("By tutor"));

static void pokedex_entry_page_move_list_extra_cursor_move_callback(int idx, u8 on_initialize, UNUSED list_menu *list) {
    if (!on_initialize)
        play_sound(5);
    pokedex_entry_page_move_list_extra_item_t item = {.value = idx};
    pokedex_entry_page_move_list_update(item.fields.move);
    u8 oam_idx_new_icon = NUM_OAMS;
    u16 tag_new = (u16)(POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON + pokedex_entry_state->move_list_extra_oam_setup_flip_flop);
    DEBUG("Tag for new oam is %d\n", tag_new);
    const u8 *str = NULL;
    switch (item.fields.type) {
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_EGG: {
            u8 pal_idx = pokedex_entry_state->move_list_extra_icon_pal_idxs[pokedex_entry_state->move_list_extra_oam_setup_flip_flop];
            pal_copy(icon_pals[1], (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
            oam_idx_new_icon = oam_new_forward_search(templates_icon_egg + 
                pokedex_entry_state->move_list_extra_oam_setup_flip_flop, 206, 122, 0);
            oam_gfx_anim_start_if_not_current(&oams[oam_idx_new_icon], 0);
            str = str_egg_move;
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_TM_HM: {
            u8 pal_idx = pokedex_entry_state->move_list_extra_icon_pal_idxs[pokedex_entry_state->move_list_extra_oam_setup_flip_flop];
            u16 tile = oam_vram_alloc(GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32));
            oam_vram_allocation_table_add(tag_new, tile, GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32));
            pal_decompress(item_get_resource((u16)TM_IDX_TO_ITEM_IDX(item.fields.argument), true),
                (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
            const u8 *gfx = item_get_resource((u16)TM_IDX_TO_ITEM_IDX(item.fields.argument), false);
            lz77uncompwram(gfx, gp_tmp_buf);
            int zero = 0;
            cpuset(&zero, (u8*)OAMCHARBASE(tile), CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(32, 32)));
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    cpuset(gp_tmp_buf + (3 * y + x) * GRAPHIC_SIZE_4BPP(8, 8), (u8*)OAMCHARBASE(tile) + (4 * y + x) * GRAPHIC_SIZE_4BPP(8, 8),
                        CPUSET_COPY | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8) | CPUSET_HALFWORD));
                }
            }
            oam_idx_new_icon = oam_new_forward_search(templates_icons_tm_hm + 
                pokedex_entry_state->move_list_extra_oam_setup_flip_flop, 211, 129, 0);
            oam_gfx_anim_start_if_not_current(&oams[oam_idx_new_icon], 0);
            if (IS_TM(item.fields.argument)) {
                strcpy(buffer0, str_tm);
                itoa(buffer1, item.fields.argument + 1, ITOA_PAD_ZEROS, 2);
            } else {
                strcpy(buffer0, str_hm);
                itoa(buffer1, TM_HM_IDX_TO_HM_IDX(item.fields.argument) + 1, ITOA_PAD_ZEROS, 2);
            }
            string_decrypt(strbuf, str_tm_hm_move);
            str = strbuf;
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_TUTOR: {
            u8 move_tutor_idx = item.fields.argument;
            DEBUG("Move tutor idx %d, bank %d, map_idx %d, person_idx %d\n", move_tutor_idx,
                move_tutors[move_tutor_idx].bank, move_tutors[move_tutor_idx].map_idx, move_tutors[move_tutor_idx].person_idx);
            if (move_tutors[move_tutor_idx].bank != 0xFF) {
                const map_event_person *person = map_get_person(
                    move_tutors[move_tutor_idx].person_idx, move_tutors[move_tutor_idx].map_idx,
                    move_tutors[move_tutor_idx].bank);
                if (person) {
                    const overworld_sprite *sprite = overworld_get(person->overworld_index);
                    if (sprite) {
                        DEBUG("Sprite %d, person %d, bank 0x%x, map 0x%x\n", person->overworld_index, 
                            move_tutors[move_tutor_idx].person_idx, move_tutors[move_tutor_idx].bank, move_tutors[move_tutor_idx].map_idx);
                        u8 pal_idx = pokedex_entry_state->move_list_extra_icon_pal_idxs[pokedex_entry_state->move_list_extra_oam_setup_flip_flop];
                        const palette *pal = overworld_npc_palette_get_by_tag(sprite->pal_tag);
                        pal_copy(pal->pal, (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
                        pokedex_entry_state->move_list_extra_icon_template = templates_icon_crystal;
                        pokedex_entry_state->move_list_extra_icon_template.pal_tag = tag_new;
                        pokedex_entry_state->move_list_extra_icon_template.graphics = sprite->graphics;
                        pokedex_entry_state->move_list_extra_icon_template.animation = sprite->gfx_animation;
                        pokedex_entry_state->move_list_extra_icon_template.oam = sprite->final_oam;
                        oam_idx_new_icon = oam_new_forward_search(&pokedex_entry_state->move_list_extra_icon_template, 208, 120, 0);
                        oam_gfx_anim_start_if_not_current(&oams[oam_idx_new_icon], 4);
                    }
                }
            }
            string_decrypt(strbuf, str_tutor_move);
            str = strbuf;
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_CRYSTAL: {
            u8 pal_idx = pokedex_entry_state->move_list_extra_icon_pal_idxs[pokedex_entry_state->move_list_extra_oam_setup_flip_flop];
            const overworld_sprite *sprite = overworld_sprite_get_by_tutor_crystal_type(attacks[item.fields.move].type);
            const palette *pal = overworld_palette_tutor_crystal_get_by_tag(sprite->pal_tag);
            pal_copy(pal->pal, (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
            pokedex_entry_state->move_list_extra_icon_template = templates_icon_crystal;
            pokedex_entry_state->move_list_extra_icon_template.pal_tag = tag_new;
            pokedex_entry_state->move_list_extra_icon_template.graphics = sprite->graphics;
            pokedex_entry_state->move_list_extra_icon_template.animation = sprite->gfx_animation;
            oam_idx_new_icon = oam_new_forward_search(&pokedex_entry_state->move_list_extra_icon_template, 208, 124, 0);
            oam_gfx_anim_start_if_not_current(&oams[oam_idx_new_icon], 0);
            strcpy(buffer0, str_pokemon_type_names[attacks[item.fields.move].type]);
            string_decrypt(strbuf, str_crystal_move);
            str = strbuf;
            break;
        }
    }
    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_METHOD], 0x00);
    if (str) {
        tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_METHOD], 
            0, (u16)((8 * pokedex_entry_page_move_list_tboxes[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_METHOD].w - 
                string_get_width(0, str, 0)) / 2), 36, 0, 0, &font_colormap_white, 0, str);
    } else {
        tbox_sync(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_METHOD], TBOX_SYNC_SET);
    }
    pokedex_entry_state->move_list_extra_oam_setup_flip_flop ^= 1;
    pokedex_entry_page_move_list_extra_delete_icon_if_present();
    if (oam_idx_new_icon < NUM_OAMS) {
        pokedex_entry_state->move_list_extra_oam_idx = oam_idx_new_icon;
    }
}

static const list_menu_template move_list_list_menu_templates[] = {
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_LEVEL_UP] = {
        .header_x = 0, .item_x = 9, .cursor_x = 1, .font = 0,
        .max_items_showed = POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_SHOWN,
        .cursor_pal = 2, .cursor_shadow_color = 3,
        .cursor_moved_callback = pokedex_entry_page_move_list_cursor_move_callback,
        .item_print_callback = pokedex_entry_page_move_list_print_item_callback,
    },
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA] = {
        .header_x = 0, .item_x = 9, .cursor_x = 1, .font = 0,
        .max_items_showed = POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_SHOWN,
        .cursor_pal = 2, .cursor_shadow_color = 3,
        .cursor_moved_callback = pokedex_entry_page_move_list_extra_cursor_move_callback,
        .item_print_callback = pokedex_entry_page_move_list_print_item_callback,
    },
};

static const u8 str_move_move_list_level[] = LANGDEP(PSTRING("BUFFER_1CLEAR_TO\x10BUFFER_2"), PSTRING("BUFFER_1CLEAR_TO\x10BUFFER_2"));
static const u8 str_move_move_list_evolution[] = LANGDEP(PSTRING("EvoCLEAR_TO\x10BUFFER_2"), PSTRING("EvoCLEAR_TO\x10BUFFER_2"));
// static const u8 str_move_list_header[] = LANGDEP(PSTRING("LvCLEAR_TO\x0CName"), PSTRING("LvlCLEAR_TO\x0CName"));


static void pokedex_entry_page_move_list_setup_level_up_moves() {
    u16 num_moves = 0;
    const pokemon_move *moves = pokemon_moves[pokedex_entry_state->species];
    while(moves[num_moves].move_id != 511) {
        num_moves++;
    }
    pokedex_entry_state->move_list_size = num_moves;
    pokedex_entry_state->move_list_items = malloc(sizeof(list_menu_item) * (num_moves));
    pokedex_entry_state->move_list_strs = malloc(sizeof(u8) * (num_moves * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS));
    for (size_t i = 0; i < num_moves; i++) {
        itoa(buffer0, moves[i].level,
            ITOA_PAD_SPACES, 2);
        strcpy(buffer1, attack_names[moves[i].move_id]);
        string_decrypt(pokedex_entry_state->move_list_strs + i * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS, 
            moves[i].level == 0 ? str_move_move_list_evolution : str_move_move_list_level);
        pokedex_entry_state->move_list_items[i] = (list_menu_item) {
            .idx = moves[i].move_id,
            .text = pokedex_entry_state->move_list_strs + i * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS,
        };
    }
}

static const u8 str_move_list_egg[] = LANGDEP(PSTRING("EiCLEAR_TO\x10BUFFER_1"), PSTRING("EggCLEAR_TO\x10BUFFER_1"));
static const u8 str_move_list_tm_hm[] = LANGDEP(PSTRING("BUFFER_2CLEAR_TO\x10BUFFER_1"), PSTRING("BUFFER_2CLEAR_TO\x10BUFFER_1"));
static const u8 str_move_tutor[] = LANGDEP(PSTRING("Tu"), PSTRING("Tu"));
static const u8 str_move_accessible[] = LANGDEP(PSTRING("KrCLEAR_TO\x10BUFFER_1"), PSTRING("CrCLEAR_TO\x10BUFFER_1"));

static void pokedex_entry_page_move_list_setup_extra_moves() {
    u16 num_egg_moves = 0;
    const u16 *egg_moves = pokemon_egg_moves[pokemon_get_basis_stage(pokedex_entry_state->species)];
    if (egg_moves) {
        while(egg_moves[num_egg_moves] != 0xFFFF) {
            num_egg_moves++;
        }
    }
    u16 num_tm_hm_moves = 0;
    for (int i = 0; i < NUM_TMS + NUM_HMS; i++) {
        if (pokemon_tm_compatibility[pokedex_entry_state->species][i / 8] & (1 << (i % 8))) {
            num_tm_hm_moves++;
        }
    }
    u16 num_move_tutor_moves = 0;
    for (int i = 0; i < NUM_MOVE_TUTORS; i++) {
        if (pokemon_move_tutor_compatibility[pokedex_entry_state->species] & (1 << i)) {
            num_move_tutor_moves++;
        }
    }
    u16 num_accessible_moves = 0;
    const u16 *accessible_moves = pokemon_accessible_moves[pokedex_entry_state->species];
    if (accessible_moves) {
        while(accessible_moves[num_accessible_moves] != 0xFFFF) {
            num_accessible_moves++;
        }
    }
    u16 num_moves = (u16)(num_egg_moves + num_tm_hm_moves + num_move_tutor_moves + num_accessible_moves);
    pokedex_entry_state->move_list_size = num_moves;
    pokedex_entry_state->move_list_items = malloc(sizeof(list_menu_item) * (num_moves));
    pokedex_entry_state->move_list_strs = malloc(sizeof(u8) * (num_moves * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS));
    size_t idx = 0;
    if (egg_moves) {
        for (size_t i = 0; i < num_egg_moves; i++) {
            strcpy(buffer0, attack_names[egg_moves[i]]);
            string_decrypt(pokedex_entry_state->move_list_strs + idx * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS, 
                str_move_list_egg);
            pokedex_entry_state->move_list_items[idx] = (list_menu_item) {
                .idx = (pokedex_entry_page_move_list_extra_item_t){
                    .fields = {
                        .type = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_EGG,
                        .move = egg_moves[i],
                    }}.value,
                .text = pokedex_entry_state->move_list_strs + idx * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS,
            };
            idx++;
        }
    }
    for (int i = 0; i < NUM_TMS + NUM_HMS; i++) {
        if (pokemon_tm_compatibility[pokedex_entry_state->species][i / 8] & (1 << (i % 8))) {
            u16 attack = tm_hm_to_attack[i];
            strcpy(buffer0, attack_names[attack]);
            strcpy(buffer1, IS_TM(i) ? str_tm : str_hm);
            string_decrypt(pokedex_entry_state->move_list_strs + idx * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS, 
                str_move_list_tm_hm);
            pokedex_entry_state->move_list_items[idx] = (list_menu_item) {
                .idx = (pokedex_entry_page_move_list_extra_item_t){
                    .fields = {
                        .type = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_TM_HM,
                        .argument = (u8)i,
                        .move = attack,
                    }}.value,
                .text = pokedex_entry_state->move_list_strs + idx * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS,
            };
            idx++;
        }
    }
    for (u8 i = 0; i < NUM_MOVE_TUTORS; i++) {
        if (pokemon_move_tutor_compatibility[pokedex_entry_state->species] & (1 << i)) {
            u16 attack = move_tutor_get_attack(i);
            strcpy(buffer0, attack_names[attack]);
            strcpy(buffer1, str_move_tutor);
            string_decrypt(pokedex_entry_state->move_list_strs + idx * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS, 
                str_move_list_tm_hm);
            pokedex_entry_state->move_list_items[idx] = (list_menu_item) {
                .idx = (pokedex_entry_page_move_list_extra_item_t){
                    .fields = {
                        .type = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_TUTOR,
                        .move = attack,
                        .argument = i,
                    }}.value,
                .text = pokedex_entry_state->move_list_strs + idx * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS,
            };
            idx++;
        }
    }
    if (accessible_moves) {
        for (size_t i = 0; i < num_accessible_moves; i++) {
            strcpy(buffer0, attack_names[accessible_moves[i]]);
            string_decrypt(pokedex_entry_state->move_list_strs + idx * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS, 
                str_move_accessible);
            pokedex_entry_state->move_list_items[idx] = (list_menu_item) {
                .idx = (pokedex_entry_page_move_list_extra_item_t){
                    .fields = {
                        .type = POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_CRYSTAL,
                        .move = accessible_moves[i],
                    }}.value,
                .text = pokedex_entry_state->move_list_strs + idx * POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS,
            };
            idx++;
        }
    }
}

static void (*const pokedex_entry_page_move_list_setup_data[])() = {
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_LEVEL_UP] = pokedex_entry_page_move_list_setup_level_up_moves,
    [POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA] = pokedex_entry_page_move_list_setup_extra_moves,
};

bool pokedex_entry_page_move_list_setup_any(u8 which, u16 *cursor_position, u16 *items_above) {
    bool caught = pokedex_operator(pokedex_entry_state->species, POKEDEX_CAUGHT, true);
    switch (pokedex_entry_state->page_initialization_state) {
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_DATA_SETUP: {
            pokedex_entry_state->move_list_extra_icon_base_tile = 0xFFFF;
            pokedex_entry_state->move_list_extra_pal_idx = 0xFF;
            pokedex_entry_state->move_list_extra_oam_idx = NUM_OAMS;
            pokedex_entry_state->move_list_extra_oam_setup_flip_flop = 0;
            for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->move_list_extra_icon_pal_idxs); i++) {
                pokedex_entry_state->move_list_extra_icon_pal_idxs[i] = oam_allocate_palette((u16)(POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON + i));
                DEBUG("Allocated palette %d for icon %d with tag %d\n", pokedex_entry_state->move_list_extra_icon_pal_idxs[i], i, 
                    (u16)(POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON + i));
            }
            pokedex_entry_page_move_list_setup_data[which]();
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_TBOXES: {
            pokedex_entry_page_move_list_setup_tboxes(which);
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_LIST: {
            if (caught) {
                // Set up the level-up move list of a pokemon
                gp_list_menu_template = move_list_list_menu_templates[which];
                gp_list_menu_template.items = pokedex_entry_state->move_list_items;
                gp_list_menu_template.item_cnt = pokedex_entry_state->move_list_size;
                gp_list_menu_template.tbox_idx = pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_LIST];
                pokedex_entry_state->list_menu_move_list_cb_idx = list_menu_new(&gp_list_menu_template, 
                    *cursor_position, *items_above);
            } else {
                pokedex_entry_state->list_menu_move_list_cb_idx = 0xFF;
            }
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        case POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS: {
            pokedex_entry_page_move_list_setup_scroll_indicators(cursor_position);
            pokedex_entry_state->page_initialization_state++;
            FALL_THROUGH;
        }
        default:
            return false;
    }
    return true;
}

bool pokedex_entry_page_move_list_level_up_setup() {
    return pokedex_entry_page_move_list_setup_any(POKEDEX_ENTRY_PAGE_MOVE_LIST_LEVEL_UP,
        &pokedex_entry_state->cursor_position_move_list_level_up, 
        &pokedex_entry_state->items_above_move_list_level_up);
}

bool pokedex_entry_page_move_list_extra_setup() {
    return pokedex_entry_page_move_list_setup_any(POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA,
        &pokedex_entry_state->cursor_position_move_list_extra, 
        &pokedex_entry_state->items_above_move_list_extra);
}

static void pokedex_entry_page_move_list_destroy_any(u16 *cursor_position, u16 *items_above) {
    pokedex_entry_page_free_tboxes();
    if (pokedex_entry_state->move_list_scroll_indicators_cb_idx != 0xFF) {
        free(pokedex_entry_state->move_list_items);
        free(pokedex_entry_state->move_list_strs);
        scroll_indicator_delete(pokedex_entry_state->move_list_scroll_indicators_cb_idx);
        pokedex_entry_state->move_list_scroll_indicators_cb_idx = 0xFF;
    }
    if (pokedex_entry_state->list_menu_move_list_cb_idx) {
        list_menu_remove(pokedex_entry_state->list_menu_move_list_cb_idx, 
            cursor_position, items_above);
        pokedex_entry_state->list_menu_move_list_cb_idx = 0xFF;
    }
    for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->move_list_extra_icon_pal_idxs); i++) {
        if (pokedex_entry_state->move_list_extra_icon_pal_idxs[i] < 16) {
            oam_palette_free((u16)(POKEDEX_ENTRY_PAGE_MOVE_LIST_EXTRA_GFX_TAG_ICON + i));
            pokedex_entry_state->move_list_extra_icon_pal_idxs[i] = 0xFF;
        }
    }
    pokedex_entry_page_move_list_extra_delete_icon_if_present();
}

void pokedex_entry_page_move_list_level_up_destroy() {
    pokedex_entry_page_move_list_destroy_any(&pokedex_entry_state->cursor_position_move_list_level_up, 
        &pokedex_entry_state->items_above_move_list_level_up);
}

void pokedex_entry_page_move_list_extra_destroy() {
    pokedex_entry_page_move_list_destroy_any(&pokedex_entry_state->cursor_position_move_list_extra, 
        &pokedex_entry_state->items_above_move_list_extra);
}

static bool pokedex_entry_page_move_list_handle_inputs_any(u16 *cursor_position, u16 *items_above) {
    if (fading_control.active || dma3_busy(-1)) {
        return false;
    }
    if (pokedex_entry_state->list_menu_move_list_cb_idx == 0xFF) {
        return false;
    } else {
        int input = list_menu_process_input(pokedex_entry_state->list_menu_move_list_cb_idx);
        list_menu_get_scroll_and_row(pokedex_entry_state->list_menu_move_list_cb_idx, 
            cursor_position, items_above); 
        switch (input) {
            case -2:
            case -1:
                return false;
            default:
                return true;
        }
    }
}

bool pokedex_entry_page_move_list_level_up_handle_inputs(UNUSED u8 self) {
    return pokedex_entry_page_move_list_handle_inputs_any(&pokedex_entry_state->cursor_position_move_list_level_up, 
        &pokedex_entry_state->items_above_move_list_level_up);
}

bool pokedex_entry_page_move_list_extra_handle_inputs(UNUSED u8 self) {
    return pokedex_entry_page_move_list_handle_inputs_any(&pokedex_entry_state->cursor_position_move_list_extra, 
        &pokedex_entry_state->items_above_move_list_extra);
}