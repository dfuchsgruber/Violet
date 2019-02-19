/*
 * ev_menu.c
 *
 *  Created on: Feb 17, 2019
 *      Author: dominik
 */
#include "types.h"
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

tbox_font_colormap ev_menu_font_colormap_std = {
    0, 2, 1, 3
};

tbox_font_colormap ev_menu_font_colormap_red = {
    0, 5, 1, 3
};

tbox_font_colormap ev_menu_font_colormap_blue = {
    0, 9, 1, 3
};

sprite ev_menu_oam_pokemon_sprite = {.attr1 = ATTR1_SIZE_64_64};

oam_template ev_menu_oam_template_pokemon = {
    0xA000,
    0xA000,
    &ev_menu_oam_pokemon_sprite,
    oam_gfx_anim_table_null,
    NULL,
    oam_rotscale_anim_table_null,
	oam_null_callback
};

u8 str_ev_menu_total[] = LANGDEP(PSTRING("Total"), PSTRING("Total"));

void ev_menu_update_stat_effective_ev(u8 stat) {

}

void ev_menu_load_stat(u8 stat) {
	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
    u8 nature = pokemon_get_nature(p);
	u8 tbox_id = (u8)(3 + stat);
    tbox_flush_set(tbox_id, 0);
	tbox_tilemap_draw(tbox_id);
	tbox_font_colormap *stat_name_colormap;
	if (nature / 5 + 1 == stat) stat_name_colormap = &ev_menu_font_colormap_red;
	else if (nature % 5 + 1 == stat) stat_name_colormap = &ev_menu_font_colormap_blue;
	else stat_name_colormap = &ev_menu_font_colormap_std;
	int effective_ev, potential_ev, iv;
	if (stat == fmem.ev_menu_state->cursor_position) {
		u8 str_cursor[] = PSTRING("▶");
		tbox_print_string(tbox_id, 2, 0, 0, 0, 0, stat_name_colormap, 0, str_cursor);
	}
	u8 *str_stat_name;
	if (stat < 6) {
		str_stat_name = pokemon_get_state_name(stat);
		iv = pokemon_get_attribute(p, (u8)(ATTRIBUTE_HP_IV + stat), 0);
		effective_ev = pokemon_get_effective_ev(p, stat) * 4;
		potential_ev = min(252, pokemon_get_potential_ev(p, stat) & ~3);
	} else {
		str_stat_name = str_ev_menu_total;
		// Sum over values
		effective_ev = 0;
		potential_ev = 512;
		iv = 0;
		for (u8 i = 0; i < 6; i++) {
			effective_ev +=  pokemon_get_effective_ev(p, i);
			iv += pokemon_get_attribute(p, (u8)(ATTRIBUTE_HP_IV + i), 0);
		}
	}
	tbox_print_string(tbox_id, 4, 8, 0, 0, 0, stat_name_colormap, 0, str_stat_name);
	itoa(strbuf, iv, 0, 3);
	tbox_print_string(tbox_id, 2, 64, 0, 0, 0, &ev_menu_font_colormap_std, 0, strbuf);
	itoa(strbuf, effective_ev, ITOA_NO_PADDING, 3);
	tbox_print_string(tbox_id, 2, 12 * 8, 0, 0, 0, &ev_menu_font_colormap_std, 0, strbuf);
	u8 str_delimiter[] = PSTRING(" / ");
	tbox_print_string(tbox_id, 2, 13 * 8 + 4, 0, 0, 0, &ev_menu_font_colormap_std, 0,
			str_delimiter);
	itoa(strbuf, potential_ev, ITOA_PAD_SPACES, 3);
	tbox_print_string(tbox_id, 2, 15 * 8, 0, 0, 0, &ev_menu_font_colormap_std, 0, strbuf);
}

void ev_menu_update_pokemon() {
	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
	pid_t pid = {.value = (u32) pokemon_get_attribute(p,ATTRIBUTE_PID, 0)};
	u16 species = (u16) pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
	pokemon_load_gfx2(&pokemon_frontsprites[species], fmem.ev_menu_state->pokemon_sprite,
			species, pid, true);
	oams[fmem.ev_menu_state->oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
	memcpy(OAMCHARBASE(fmem.ev_menu_state->oam_tile), fmem.ev_menu_state->pokemon_sprite, 0x800);
	palette *pal = pokemon_get_palette(&player_pokemon[fmem.ev_menu_state->party_idx]);
	pal_decompress(pal, (u16)(256 + 16 * fmem.ev_menu_state->oam_palette), 32);
    pokemon_get_attribute(p, ATTRIBUTE_NICKNAME, strbuf);
    tbox_flush_set(0, 0);
	tbox_tilemap_draw(0);
	tbox_print_string(0, 2, 0, 0, 0, 0, &ev_menu_font_colormap_std, 0, strbuf);
	for (u8 stat = 0; stat < 7; stat++) {
		ev_menu_update_stat(stat);
	}
	tbox_flush_set(11, 0);
	tbox_tilemap_draw(11);
	tbox_draw_type_icon_by_type_p1(11, (u8) (hidden_power_get_type(pid) + 1), 0, 0);
	u8 str_none[] = PSTRING("");
	tbox_print_string(11, 2, 40, 0, 0, 0, &ev_menu_font_colormap_std, 0, str_none);
	itoa(strbuf, hidden_power_get_base_power(pid), ITOA_NO_PADDING, 2);
	tbox_flush_set(12, 0);
	tbox_tilemap_draw(12);
	tbox_print_string(12, 2, 0, 0, 0, 0, &ev_menu_font_colormap_std, 0, strbuf);

}

void ev_menu_callback_idle() {
    generic_callback1();
    if (!fading_is_active()) {
    	if (!fmem.ev_menu_state->delay) {
    		if (super.keys_new.keys.down && fmem.ev_menu_state->cursor_position < 6) {
    			fmem.ev_menu_state->cursor_position++;
    			ev_menu_update_stat((u8)(fmem.ev_menu_state->cursor_position - 1));
    			ev_menu_update_stat(fmem.ev_menu_state->cursor_position);
    			play_sound(5);
    		} else if (super.keys_new.keys.up && fmem.ev_menu_state->cursor_position > 0) {
    			fmem.ev_menu_state->cursor_position--;
    			ev_menu_update_stat((u8)(fmem.ev_menu_state->cursor_position + 1));
    			ev_menu_update_stat(fmem.ev_menu_state->cursor_position);
    			play_sound(5);
    		}


    	} else fmem.ev_menu_state->delay--;
    }
}

void ev_menu_callback_show() {
    generic_callback1();
    if (!fading_is_active()) {
        //oams[fmem.fp_mem->oam_pokepic].y2 = 0;
        fadescreen_all(0, 0);
        callback1_set(ev_menu_callback_idle);
    }
}

void ev_menu_callback_setup() {
    generic_callback1();
    if (!fading_is_active()) {
        big_callback_delete_all();
        pokemon_party_menu_free();
        oam_reset();
        oam_palette_allocation_reset();
        bg_reset(0);
        bg_setup(0, ev_menu_bg_configs, 2);
        bg_sync_display_and_show(0);
        bg_sync_display_and_show(1);
        bg_display_sync();
        bg_virtual_map_displace(0, 0, 0);
        bg_virtual_set_displace(0, 0, 0);
        bg_virtual_map_displace(1, 0, 0);
        bg_virtual_set_displace(1, 0, 0);
        io_set(0x10, 0);
        io_set(0x12, 0);
        io_set(0x14, 0);
        io_set(0x16, 0);

        // Drop old bgs and allocate new backgrounds
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        void *bg0map = malloc_and_clear(0x800);
        void *bg1map = malloc_and_clear(0x800);
        bg_set_tilemap(0, bg0map);
        bg_set_tilemap(1, bg1map);
        lz77uncompwram(gfx_ev_menu_bgMap, bg1map);
        lz77uncompvram(gfx_ev_menu_bgTiles, CHARBASE(0));


        // Setup textboxes
        tbox_sync_with_virtual_bg_and_init_all(ev_menu_tboxes);
        u8 str_header_stat[] = LANGDEP(PSTRING("Statusw."), PSTRING("Stat"));
        u8 str_header_ivs[] = LANGDEP(PSTRING("Gene"), PSTRING("Genes"));
        u8 str_header_evs[] = LANGDEP(PSTRING("Fleiß-P."), PSTRING("Effort V."));
        u8 str_header_raise[] = LANGDEP(PSTRING("KEY_A Erhöhen"), PSTRING("KEY_A Raise"));
        tbox_flush_set(1, 0);
		tbox_tilemap_draw(1);
		tbox_print_string(1, 2, 0, 0, 0, 0, &ev_menu_font_colormap_std, 0, str_header_stat);
		tbox_print_string(1, 2, 7 * 8, 0, 0, 0, &ev_menu_font_colormap_std, 0, str_header_ivs);
		tbox_print_string(1, 2, 12 * 8, 0, 0, 0, &ev_menu_font_colormap_std, 0, str_header_evs);
        tbox_flush_set(2, 0);
		tbox_tilemap_draw(2);
		tbox_print_string(2, 2, 0, 0, 0, 0, &ev_menu_font_colormap_std, 0, str_header_raise);
		u8 str_header_hidden_power[] = LANGDEP(PSTRING("Kraftreserve"), PSTRING("Hidden Power"));
        tbox_flush_set(10, 0);
		tbox_tilemap_draw(10);
		tbox_print_string(10, 2, 0, 0, 0, 0, &ev_menu_font_colormap_std, 0, str_header_hidden_power);


        //init the oams
		u16 oam_pokepic_tile = oam_vram_alloc(64);
        oam_vram_allocation_table_add(0xA000, oam_pokepic_tile, 64);
        fmem.ev_menu_state->oam_tile = oam_pokepic_tile;
        fmem.ev_menu_state->oam_tile = oam_allocate_palette(0xA000);
        fmem.ev_menu_state->oam_idx = oam_new_forward_search(
        		&ev_menu_oam_template_pokemon, 5 * 8, 9 * 8, 0);
        oams[fmem.ev_menu_state->oam_idx].flags |= OAM_FLAG_INVISIBLE;
        ev_menu_update_pokemon();
        /**

        //arrows
        oam_load_graphic(&fp_menu_graphic_arrow_vertical);
        oam_load_graphic(&fp_menu_graphic_arrow_horizontal);
        u8 arrow_pal = oam_allocate_palette(0xA001);
        fmem.fp_mem->oam_arrows[0] = oam_new_forward_search(&fp_menu_oam_arrow_template_down, 16, 32, 0);
        fmem.fp_mem->oam_arrows[1] = oam_new_forward_search(&fp_menu_oam_arrow_template_up, 16, 76, 0);
        fmem.fp_mem->oam_arrows[2] = oam_new_forward_search(&fp_menu_oam_arrow_template_left, 12, 100, 0);
        fmem.fp_mem->oam_arrows[3] = oam_new_forward_search(&fp_menu_oam_arrow_template_right, 124, 100, 0);
        big_callback_new(fp_menu_callback_arrow_anim, 0);

        fp_menu_pokemon_load();
		**/

        //load palettes
        pal_decompress(gfx_ev_menu_bgPal, 0, 32);
        pal_copy(typechart_icon_pal, 16, 32);
        pal_set_all_to_black();

        bg_virtual_sync(0);
        bg_virtual_sync(1);

        callback1_set(ev_menu_callback_show);
        vblank_handler_set(generic_vblank_handler);
    }
}

void ev_menu_init(u8 self) {
    fmem.ev_menu_state = (ev_menu_state_stru*) malloc_and_clear(sizeof (ev_menu_state_stru));
    fmem.ev_menu_state->party_idx = pokemon_party_menu_current_index;
    fmem.ev_menu_state->cursor_position = 0;
    fmem.ev_menu_state->pokemon_sprite = malloc_and_clear(0x800);
    fadescreen_all(1, 0);
    callback1_set(ev_menu_callback_setup);
    big_callback_delete(self);
}

bg_config ev_menu_bg_configs[2] = {
	{.bg_id = 0, .char_base = 2, .map_base = 31, .priority = 0, .size = 0, .color_mode = 0},
	{.bg_id = 1, .char_base = 0, .map_base = 30, .priority = 1, .size = 0, .color_mode = 0},
};

tboxdata ev_menu_tboxes[EV_MENU_TBOX_COUNT] = {
	{.bg_id = 0, .x = 2, .y = 3, .w = 8, .h = 2, .start_tile = 1, .pal = 15}, // Name
	{.bg_id = 0, .x = 12, .y = 0, .w = 18, .h = 2, .pal = 15, .start_tile = 17}, // Header
	{.bg_id = 0, .x = 1, .y = 0, .w = 8, .h = 2, .pal = 15, .start_tile = 53}, // Raise Description
	{.bg_id = 0, .x = 12, .y = 4, .w = 18, .h = 2, .pal = 15, .start_tile = 69}, // HP
	{.bg_id = 0, .x = 12, .y = 6, .w = 18, .h = 2, .pal = 15, .start_tile = 69 + 2 * 36}, // Attack
	{.bg_id = 0, .x = 12, .y = 8, .w = 18, .h = 2, .pal = 15, .start_tile = 69 + 3 * 36}, // Defense
	{.bg_id = 0, .x = 12, .y = 10, .w = 18, .h = 2, .pal = 15, .start_tile = 69 + 4 * 36}, // Speed
	{.bg_id = 0, .x = 12, .y = 12, .w = 18, .h = 2, .pal = 15, .start_tile = 69 + 5 * 36}, // Special Attack
	{.bg_id = 0, .x = 12, .y = 14, .w = 18, .h = 2, .pal = 15, .start_tile = 69 + 6 * 36}, // Special Defense
	{.bg_id = 0, .x = 12, .y = 16, .w = 18, .h = 2, .pal = 15, .start_tile = 69 + 7 * 36}, // Total
	{.bg_id = 0, .x = 1, .y = 14, .w = 9, .h = 2, .pal = 15, .start_tile = 69 + 8 * 36}, // Hidden Power
	{.bg_id = 0, .x = 1, .y = 17, .w = 4, .h = 2, .pal = 1, .start_tile = 69 + 8 * 36 + 18}, // Hidden Power Type
	{.bg_id = 0, .x = 7, .y = 17, .w = 4, .h = 2, .pal = 15, .start_tile = 69 + 8 * 36 + 18 + 8}, // Hidden Power Strength
	{.bg_id = 255},
};
