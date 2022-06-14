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
#include "gpu.h"
#include "vram.h"
#include "constants/species.h"
#include "transparency.h"
#include "item/item.h"
#include "data_structures.h"

tbox_font_colormap ev_menu_font_colormap_std_dark = {
    0, 2, 1, 3
};

tbox_font_colormap ev_menu_font_colormap_std_light = {
    0, 1, 2, 3
};

tbox_font_colormap ev_menu_font_colormap_std_transparent = {
    1, 2, 1, 1
};

tbox_font_colormap ev_menu_font_colormap_plus = {
    0, 1, 6, 3
};

tbox_font_colormap ev_menu_font_colormap_minus = {
    0, 1, 4, 3
};

sprite ev_menu_oam_sprite = {.attr1 = ATTR1_SIZE_64_64};

sprite ev_menu_oam_sprite_semi_transparent = {
		.attr0 = ATTR0_ROTSCALE | ATTR0_MODE_SEMI_TRANSPARENT, .attr1 = ATTR1_SIZE_64_64,
		.attr2 = ATTR2_PRIO(1)};


oam_template ev_menu_oam_template_pokemon = {
    EV_MENU_OAM_POKEPIC_TAG,
	EV_MENU_OAM_POKEPIC_TAG,
    &ev_menu_oam_sprite,
    oam_gfx_anim_table_null,
    NULL,
    oam_rotscale_anim_table_null,
	oam_null_callback
};

oam_template ev_menu_oam_template_iv_hexagon = {
	EV_MENU_OAM_IV_HEXAGON_TAG,
	EV_MENU_OAM_IV_HEXAGON_TAG,
    &ev_menu_oam_sprite_semi_transparent,
    oam_gfx_anim_table_null,
    NULL,
    oam_rotscale_anim_table_null,
	oam_null_callback
};

oam_template ev_menu_oam_template_ev_hexagon = {
	EV_MENU_OAM_EV_HEXAGON_TAG,
	EV_MENU_OAM_EV_HEXAGON_TAG,
    &ev_menu_oam_sprite_semi_transparent,
    oam_gfx_anim_table_null,
    NULL,
    oam_rotscale_anim_table_null,
	oam_null_callback
};

void ev_menu_set_pixel(int x, int y) {
	x += 32; y += 32; // Shift to the center
	if (x < 0 || x >= 64 || y < 0 || y >= 64) {
		DEBUG("Attempt to set pixel outside the stat chart (%d, %d)\n", x ,y);
		return;
	}
	int *sprite = fmem.ev_menu_state->render_sprite;
	u8 color = fmem.ev_menu_state->render_color;
	int tile_x = x >> 3, tile_y = y >> 3;
	int pixel_x = x & 7, pixel_y = y & 7;
	int tile_idx = 8 * tile_y + tile_x;
	int *pixel = &sprite[8 * tile_idx + pixel_y]; // Each integer describes a row of a character
	int pixel_shift = pixel_x << 2;
	int pixel_mask = 15 << pixel_shift;
	*pixel = (*pixel & ~pixel_mask) | (color << pixel_shift);
}

static void ev_menu_load_stat_header() {
	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
	bool is_egg = pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0);
    tbox_flush_set(EV_MENU_TBOX_CURRENT_STAT_HEADER, 0);
	tbox_tilemap_draw(EV_MENU_TBOX_CURRENT_STAT_HEADER);
	tbox_font_colormap *stat_name_colormap = &ev_menu_font_colormap_std_light;
	strcpy(strbuf, pokemon_get_stat_name(fmem.ev_menu_state->stat_idx));
	u8 str_stat_name_width = string_get_width(2, strbuf, 0);
	if (!is_egg) {
		u8 nature = pokemon_get_nature(p);
		int stat_increased = nature / 5 + 1, stat_decreased = nature % 5 + 1;
		if (stat_increased == fmem.ev_menu_state->stat_idx && stat_increased != stat_decreased){
			stat_name_colormap = &ev_menu_font_colormap_plus;
			u8 str_up[] = PSTRING("UP_ARROW");
			strcat(strbuf, str_up);
		} else if (stat_decreased == fmem.ev_menu_state->stat_idx
				&& stat_increased != stat_decreased) {
			stat_name_colormap = &ev_menu_font_colormap_minus;
			u8 str_down[] = PSTRING("DOWN_ARROW");
			strcat(strbuf, str_down);
		}
	}
	// Center the stat name
	u16 x_offset = (u16)((8 * ev_menu_tboxes[EV_MENU_TBOX_CURRENT_STAT_HEADER].w -
			str_stat_name_width) / 2);
	tbox_print_string(EV_MENU_TBOX_CURRENT_STAT_HEADER, 2, x_offset, 0, 0, 0, stat_name_colormap, 0,
			strbuf);
}

void ev_menu_load_stat() {
	ev_menu_load_stat_header();
	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
	bool is_egg = pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0);

	int iv = pokemon_get_attribute(p, (u8)(ATTRIBUTE_HP_IV + fmem.ev_menu_state->stat_idx), 0);
	int effective_ev = pokemon_get_effective_ev(p, fmem.ev_menu_state->stat_idx) * 4;
	int potential_ev = MIN(252, pokemon_get_potential_ev(p, fmem.ev_menu_state->stat_idx) & ~3);
	tbox_flush_set(EV_MENU_TBOX_CURRENT_IV, 0);
	tbox_tilemap_draw(EV_MENU_TBOX_CURRENT_IV);
	if (!is_egg) {
		itoa(strbuf, iv, ITOA_PAD_SPACES, 2);
		tbox_print_string(EV_MENU_TBOX_CURRENT_IV, 2, 0, 6, 0, 0, &ev_menu_font_colormap_std_dark, 0,
				strbuf);
	} else {
		tbox_sync(EV_MENU_TBOX_CURRENT_IV, TBOX_SYNC_SET);
	}
	tbox_flush_set(EV_MENU_TBOX_CURRENT_EV, 0);
	tbox_tilemap_draw(EV_MENU_TBOX_CURRENT_EV);
	if (!is_egg) {
		itoa(strbuf, effective_ev, ITOA_NO_PADDING, 3);
		tbox_print_string(EV_MENU_TBOX_CURRENT_EV, 2, 2, 6, 0, 0, &ev_menu_font_colormap_std_dark, 0,
				strbuf);
		u8 str_delimiter[] = PSTRING("/");
		strcpy(strbuf, str_delimiter);
		itoa(strbuf + 1, potential_ev, ITOA_PAD_SPACES, 3);
		tbox_print_string(EV_MENU_TBOX_CURRENT_EV, 2, 20, 6, 0, 0, &ev_menu_font_colormap_std_dark, 0,
					strbuf);
	} else {
		tbox_sync(EV_MENU_TBOX_CURRENT_EV, TBOX_SYNC_SET);
	}
}


void ev_menu_load_iv_chart() {
	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
	FIXED iv_ratios[6] = {0};
	bool is_egg = pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0);
	for (int i = 0; i < 6; i++) {
		FIXED iv = INT_TO_FIXED(
				(is_egg ? 0 : pokemon_get_attribute(p, (u8)(ATTRIBUTE_HP_IV + i), 0)) +
				EV_MENU_IV_CHART_MIN_VALUE);
		iv_ratios[i] = FIXED_DIV(iv, INT_TO_FIXED(31 + EV_MENU_IV_CHART_MIN_VALUE));
	}
	fmem.ev_menu_state->render_sprite = fmem.ev_menu_state->iv_hexagon_sprite;
	fmem.ev_menu_state->render_color = 1;
	memset(fmem.ev_menu_state->render_sprite, 0, 0x800);
	gpu_render_polygon_by_radius(iv_ratios, 6, 31, ev_menu_set_pixel);
	memcpy(OAMCHARBASE(fmem.ev_menu_state->oam_iv_hexagon_tile),
			fmem.ev_menu_state->iv_hexagon_sprite, 0x800);
    oams[fmem.ev_menu_state->oam_iv_hexagon_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
}

void ev_menu_load_ev_chart() {
	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
	FIXED ev_ratios[6] = {0};
	bool is_egg = pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0);
	for (int i = 0; i < 6; i++) {
		FIXED ev = INT_TO_FIXED(
				(is_egg ? 0 : pokemon_get_effective_ev(p, i)) + EV_MENU_EV_CHART_MIN_VALUE);
		ev_ratios[i] = FIXED_DIV(ev, INT_TO_FIXED(63 + EV_MENU_EV_CHART_MIN_VALUE));
	}
	fmem.ev_menu_state->render_sprite = fmem.ev_menu_state->ev_hexagon_sprite;
	fmem.ev_menu_state->render_color = 1;
	memset(fmem.ev_menu_state->render_sprite, 0, 0x800);
	gpu_render_polygon_by_radius(ev_ratios, 6, 31, ev_menu_set_pixel);
	memcpy(OAMCHARBASE(fmem.ev_menu_state->oam_ev_hexagon_tile),
			fmem.ev_menu_state->ev_hexagon_sprite, 0x800);
    oams[fmem.ev_menu_state->oam_ev_hexagon_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
}

void ev_menu_load_effective_ev_total() {
	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
	// Print the sum of effective evs
	tbox_flush_set(EV_MENU_TBOX_TOTAL_EV, 0);
	tbox_tilemap_draw(EV_MENU_TBOX_TOTAL_EV);
	if (!pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0)) {
		int effective_evs_sum = 0;
		for (u8 i = 0; i < 6; i++) {
			effective_evs_sum += pokemon_get_effective_ev(p, i) * 4;
		}
		itoa(strbuf, effective_evs_sum, ITOA_NO_PADDING, 3);
		tbox_print_string(EV_MENU_TBOX_TOTAL_EV, 2, 2, 0, 0, 0, &ev_menu_font_colormap_std_light, 0,
				strbuf);
		u8 str_delim[] = PSTRING("/512");
		tbox_print_string(EV_MENU_TBOX_TOTAL_EV, 2, 20, 0, 0, 0, &ev_menu_font_colormap_std_light,
				0, str_delim);
	} else {
		tbox_sync(EV_MENU_TBOX_TOTAL_EV, TBOX_SYNC_SET);
	}
}

void ev_menu_load_evs_and_ivs() {
	ev_menu_load_effective_ev_total();
	ev_menu_load_stat();
	ev_menu_load_iv_chart();
	ev_menu_load_ev_chart();
}

static u16 stat_coordinates[6][2] = {{34, 0}, {58, 12}, {58, 52}, {32, 64}, {2, 52}, {2, 12}};

static void ev_menu_draw_print_stat_names() {
	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
	bool is_egg = pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0);
	int stat_increased, stat_decreased;
	if (!is_egg) {
		u8 nature = pokemon_get_nature(p);
		stat_increased = nature / 5 + 1;
		stat_decreased = nature % 5 + 1;
	} else {
		stat_increased = -1;
		stat_decreased = -1;
	}
	if (stat_increased == stat_decreased) {
		stat_increased = -1;
		stat_decreased = -1;
	}
	for (u8 stat = 0; stat < 6; stat++) {
		tbox_font_colormap *colmap;
		if (stat == stat_increased)
			colmap = &ev_menu_font_colormap_plus;
		else if (stat == stat_decreased) 
			colmap = &ev_menu_font_colormap_minus;
		else
			colmap = &ev_menu_font_colormap_std_light;

		u8 *str_stat_name = pokemon_stat_names_abbreviated[stat];
		tbox_print_string(EV_MENU_TBOX_CHART_STATS, 0,
				stat_coordinates[stat][0], stat_coordinates[stat][1], 0, 0,
				colmap, 0, str_stat_name);
		tbox_print_string(EV_MENU_TBOX_CHART_STATS, 0,
				(u16)(stat_coordinates[stat][0] + 80), stat_coordinates[stat][1], 0, 0,
				colmap, 0, str_stat_name);
	}
}

void ev_menu_load_pokemon() {

	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
	pid_t pid = {.value = (u32) pokemon_get_attribute(p,ATTRIBUTE_PID, 0)};
	bool is_egg = pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0);
	u16 species;
	if (is_egg) species = POKEMON_EGG;
	else species = (u16) pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
	pokemon_load_gfx_by_graphic(&pokemon_frontsprites[species], fmem.ev_menu_state->pokemon_sprite,
			species, pid);
	oams[fmem.ev_menu_state->oam_pokepic_idx].flags |= OAM_FLAG_INVISIBLE;
	memcpy(OAMCHARBASE(fmem.ev_menu_state->oam_pokepic_tile), fmem.ev_menu_state->pokemon_sprite,
			0x800);
	palette *pal = pokemon_get_palette(&player_pokemon[fmem.ev_menu_state->party_idx]);
	pal_decompress(pal, (u16)(256 + 16 * oam_palette_get_index(EV_MENU_OAM_POKEPIC_TAG)), 32);
    pokemon_get_attribute(p, ATTRIBUTE_NICKNAME, strbuf);
    tbox_flush_set(EV_MENU_TBOX_NAME, 0);
	tbox_tilemap_draw(EV_MENU_TBOX_NAME);
	// Center the name
	u8 str_name_width = string_get_width(2, strbuf, 0);
	u16 x_offset = (u16)((8 * ev_menu_tboxes[EV_MENU_TBOX_NAME].w - str_name_width) / 2);
	tbox_print_string(EV_MENU_TBOX_NAME, 2, x_offset, 0, 0, 0, &ev_menu_font_colormap_std_dark, 0, strbuf);
	tbox_flush_set(EV_MENU_TBOX_HIDDEN_POWER_TYPE, 0);
	tbox_tilemap_draw(EV_MENU_TBOX_HIDDEN_POWER_TYPE);
	if (!is_egg) {
		tbox_blit_move_info_icon(EV_MENU_TBOX_HIDDEN_POWER_TYPE,
				(u8) (hidden_power_get_type(pid) + 1), 0, 0);
		u8 str_none[] = PSTRING("");
		tbox_print_string(EV_MENU_TBOX_HIDDEN_POWER_TYPE, 2, 40, 0, 0, 0,
				&ev_menu_font_colormap_std_dark, 0, str_none);
	} else {
		tbox_sync(EV_MENU_TBOX_HIDDEN_POWER_TYPE, TBOX_SYNC_SET);
	}
	tbox_flush_set(EV_MENU_TBOX_HIDDEN_POWER_STRENGTH, 0);
	tbox_tilemap_draw(EV_MENU_TBOX_HIDDEN_POWER_STRENGTH);
	if (!is_egg) {
		itoa(strbuf, hidden_power_get_base_power(pid), ITOA_NO_PADDING, 2);
		tbox_print_string(EV_MENU_TBOX_HIDDEN_POWER_STRENGTH, 2, 2, 0, 0, 0,
				&ev_menu_font_colormap_std_light,0, strbuf);
	} else {
		tbox_sync(EV_MENU_TBOX_HIDDEN_POWER_STRENGTH, TBOX_SYNC_SET);
	}


	if (!is_egg) {
		u8 callback_idx = big_callback_new(ev_menu_big_callback_jump, 0);
		big_callback_set_int(callback_idx, 0, 0); // Set the time value to zero
	    pokemon_play_cry(species, 0);
	}
	ev_menu_draw_print_stat_names();
	ev_menu_load_evs_and_ivs();
}

void ev_menu_big_callback_update_pokemon(u8 self) {
	switch(big_callbacks[self].params[0]++) {
	case 0:
		// Hide the pokemon, wait 1 frame (hiding is after palette updating...)
		oams[fmem.ev_menu_state->oam_pokepic_idx].flags |= OAM_FLAG_INVISIBLE;
		break;
	case 2:
		// Reload the pokemon sprite
		ev_menu_load_pokemon();
		break;
	case 3:
		// Show the pokemon
		oams[fmem.ev_menu_state->oam_pokepic_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
		big_callback_delete(self);
		break;
	}
}

bool ev_menu_increase_effective_ev() {
	pokemon *p = &player_pokemon[fmem.ev_menu_state->party_idx];
	if (pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0)) return false;
	int effective_ev = pokemon_get_effective_ev(p, fmem.ev_menu_state->stat_idx);
	int potential_ev = pokemon_get_potential_ev(p, fmem.ev_menu_state->stat_idx) / 4;
	if (effective_ev >= potential_ev) return false;
	// Check if the total 512 sum would be exceeded
	int effective_ev_total = 0;
	for (u8 stat = 0; stat < 6; stat++) {
		effective_ev_total += pokemon_get_effective_ev(p, stat);
	}
	if (effective_ev_total >= 128) return false;
	// Increase the total effective ev
	pokemon_set_effective_ev(p, fmem.ev_menu_state->stat_idx, (u8)(effective_ev + 1));
	pokemon_calculate_stats(p);
	return true;
}

void ev_menu_callback_return() {
    if (!fading_is_active() && cry_has_finished()) {
    	pokemon_party_menu_current_index2 = fmem.ev_menu_state->party_idx;
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free(bg_get_tilemap(2));
        free(fmem.ev_menu_state->pokemon_sprite);
        free(fmem.ev_menu_state->iv_hexagon_sprite);
        free(fmem.ev_menu_state->ev_hexagon_sprite);
        free(fmem.ev_menu_state);
        tbox_free_all();
        callback1_set(fmem.ev_menu_state->continuation); 
    }
    generic_callback1();
}

void ev_menu_big_callback_jump(u8 self) {
	FIXED t = big_callback_get_int(self, 0);
	if (t >= INT_TO_FIXED(1)){
		big_callback_delete(self);
	} else {
		FIXED dy = ABS(8 * FIXED_SIN(t));
		oams[fmem.ev_menu_state->oam_pokepic_idx].y2 = (s16)(-FIXED_TO_INT(dy));
		t = FIXED_ADD(t, INT_TO_FIXED(1) >> 4); // t += 1/16
		big_callback_set_int(self, 0, t);
	}
}

void ev_menu_callback_idle() {
    generic_callback1();
    if (!fading_is_active() && !big_callback_is_active(ev_menu_big_callback_jump) &&
    		!big_callback_is_active(ev_menu_big_callback_update_pokemon)) {
    	if (!fmem.ev_menu_state->delay) {
    		if (super.keys_new.keys.B) {
    			// Return
    			play_sound(5);
                callback1_set(ev_menu_callback_return);
                fadescreen_all(1, 0);
    		} else if (super.keys_new.keys.left) {
    			play_sound(5);
    			fmem.ev_menu_state->stat_idx = (u8)((fmem.ev_menu_state->stat_idx + 5) % 6);
    			ev_menu_load_stat();
    		} else if (super.keys_new.keys.right) {
    			play_sound(5);
    			fmem.ev_menu_state->stat_idx = (u8)((fmem.ev_menu_state->stat_idx + 1) % 6);
    			ev_menu_load_stat();
    		} else if (super.keys_new.keys.down) {
    			fmem.ev_menu_state->party_idx = (u8)((fmem.ev_menu_state->party_idx + 1) %
    					pokemon_get_number_in_party());
    			big_callbacks[big_callback_new(
    					ev_menu_big_callback_update_pokemon, 1)].params[0] = 0;
    		} else if (super.keys_new.keys.up) {
    			fmem.ev_menu_state->party_idx = (u8)(
    					(fmem.ev_menu_state->party_idx + pokemon_get_number_in_party() - 1) %
    					pokemon_get_number_in_party());
    			big_callbacks[big_callback_new(
    					ev_menu_big_callback_update_pokemon, 1)].params[0] = 0;
    		} else if (super.keys_new.keys.A) {
    			// Try to increase the stat of this pokemon
    			if (ev_menu_increase_effective_ev()) {
    				ev_menu_load_evs_and_ivs();
                    play_sound(84);
    			} else {
                    play_sound(26);
    			}
    		}
    	} else fmem.ev_menu_state->delay--;
    }
}


static u8 str_nature_stone[] = LANGDEP(
    PSTRING("BUFFER_1 hat jetzt\ndas Wesen BUFFER_2.PAUSE_UNTIL_PRESS"),
    PSTRING("BUFFER_1\'s nature has\nchanged to BUFFER_2.PAUSE_UNTIL_PRESS")
);

static u8 str_used_nature_stone[] = LANGDEP(
	PSTRING("BUFFER_2 wird\nbei BUFFER_1 eingesetzt.PAUSE_UNTIL_PRESS"),
	PSTRING("BUFFER_2 is\nused on BUFFER_1.PAUSE_UNTIL_PRESS")
);

static void ev_menu_change_nature_step_finish(u8 self) {
	callback1_set(ev_menu_callback_return);
	fadescreen_all(1, 0);
	big_callback_delete(self);
}

static void ev_menu_change_nature_step_has_changed(u8 self) {
	if (sound_is_playing())
		return;
	ev_menu_load_stat_header();
	ev_menu_draw_print_stat_names();
	string_decrypt(strbuf, str_nature_stone);
	tbox_print_string_and_continue(self, EV_MENU_TBOX_MESSAGE, EV_MENU_MESSAGE_FRAME_START_TILE, 13, 2, tbox_get_set_speed(), 
		strbuf, ev_menu_change_nature_step_finish);
}

static void ev_menu_change_nature_step_sound(u8 self) {
	if (sound_is_playing())
		return;
	pokemon *p = player_pokemon + fmem.ev_menu_state->party_idx;
	pid_t pid = {.value = (u32)pokemon_get_attribute(p, ATTRIBUTE_PID, NULL)};
	u32 new_nature = item_nature_stone_modify_nature((u8)pid.fields.nature, item_activated);
	pid.fields.nature = new_nature & 0x1F;
	pokemon_set_attribute(p, ATTRIBUTE_PID, &pid);
	pokemon_calculate_stats(p);
	pokemon_load_name_as_string(p, buffer0);
	strcpy(buffer1, pokemon_nature_strings[new_nature]);
	play_sound(240);
	big_callbacks[self].function = ev_menu_change_nature_step_has_changed;
}

static void ev_menu_change_nature_step_is_used(u8 self) {
	pokemon *p = player_pokemon + fmem.ev_menu_state->party_idx;
	pokemon_load_name_as_string(p, buffer0);
	strcpy(buffer1, item_get_name(item_activated));
	string_decrypt(strbuf, str_used_nature_stone);
	tbox_draw_frame_message_and_flush_set(EV_MENU_TBOX_MESSAGE, true, EV_MENU_MESSAGE_FRAME_START_TILE, 13);
	tbox_print_string_and_continue(self, EV_MENU_TBOX_MESSAGE, EV_MENU_MESSAGE_FRAME_START_TILE, 13, 2, tbox_get_set_speed(), 
			strbuf, ev_menu_change_nature_step_sound);
}


static void ev_menu_change_nature_callback() {
    generic_callback1();
	if (!fading_is_active()) {
		big_callback_new(ev_menu_change_nature_step_is_used, 0);
		callback1_set(generic_callback1);
	}

}

void ev_menu_callback_show() {
    generic_callback1();
    if (!fading_is_active()) {
    	// Show the pokepic oam
    	oams[fmem.ev_menu_state->oam_pokepic_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);

    	fadescreen_all(0, 0);

        // Make semi-transparent oams transparent (only after fadescreen)
        io_set(IO_BLDCNT, IO_BLDCNT_BG3_SECOND | IO_BLDCNT_BG2_SECOND | IO_BLDCNT_BG1_SECOND |
        		IO_BLDCNT_BG0_SECOND | IO_BLDCNT_ALPHA_BLENDING);
        io_set(IO_BLDALPHA, IO_BLDALPHA_EVA(7) | IO_BLDALPHA_EVB(11));
        callback1_set(fmem.ev_menu_state->idle_callback);
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
        bg_setup(0, ev_menu_bg_configs, EV_MENU_BG_COUNT);
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
        io_set(0x10, 0);
        io_set(0x12, 0);
        io_set(0x14, 0);
        io_set(0x16, 0);
        io_set(0x18, 0);
        io_set(0x1A, 0);

        // Drop old bgs and allocate new backgrounds
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free(bg_get_tilemap(2));
        void *bg0map = malloc_and_clear(0x800);
        void *bg1map = malloc_and_clear(0x800);
        void *bg2map = malloc_and_clear(0x800);
        bg_set_tilemap(0, bg0map);
        bg_set_tilemap(1, bg1map);
        bg_set_tilemap(2, bg2map);
        lz77uncompwram(gfx_ev_menu_bgMap, bg1map);
        lz77uncompvram(gfx_ev_menu_bgTiles, CHARBASE(0));

        // Setup textboxes
        tbox_sync_with_virtual_bg_and_init_all(ev_menu_tboxes);
        u8 str_header[] = LANGDEP(
        		PSTRING("KEY_A Erhöhen KEY_LEFT_RIGHT Statuswert KEY_UP_DOWN Pokémon "),
				PSTRING("KEY_A Raise KEY_LEFT_RIGHT Stat KEY_UP_DOWN Pokémon"));
        tbox_flush_set(EV_MENU_TBOX_HEADER, 0);
		tbox_tilemap_draw(EV_MENU_TBOX_HEADER);
		tbox_print_string(EV_MENU_TBOX_HEADER, 2, 0, 0, 0, 0, &ev_menu_font_colormap_std_light, 0,
				str_header);
		u8 str_hidden_power[] = LANGDEP(PSTRING("Kraftreserve"), PSTRING("Hidden Power"));
        tbox_flush_set(EV_MENU_TBOX_HIDDEN_POWER, 0);
		tbox_tilemap_draw(EV_MENU_TBOX_HIDDEN_POWER);
		tbox_print_string(EV_MENU_TBOX_HIDDEN_POWER, 2, 0, 0, 0, 0,
				&ev_menu_font_colormap_std_light, 0, str_hidden_power);
		u8 str_header_iv_chart[] = LANGDEP(PSTRING("Veranlagung"), PSTRING("Genes"));
		tbox_flush_set(EV_MENU_TBOX_IV_CHART_HEADER, 0);
		tbox_tilemap_draw(EV_MENU_TBOX_IV_CHART_HEADER);
		tbox_print_string(EV_MENU_TBOX_IV_CHART_HEADER, 2, 0, 1, 0, 0,
				&ev_menu_font_colormap_std_light, 0, str_header_iv_chart);
		u8 str_header_ev_chart[] = LANGDEP(PSTRING("Fleiß-Punkte"), PSTRING("Effort Values"));
		tbox_flush_set(EV_MENU_TBOX_EV_CHART_HEADER, 0);
		tbox_tilemap_draw(EV_MENU_TBOX_EV_CHART_HEADER);
		tbox_print_string(EV_MENU_TBOX_EV_CHART_HEADER, 2, 0, 1, 0, 0,
				&ev_menu_font_colormap_std_light, 0, str_header_ev_chart);

		u8 str_header_hidden_power[] = LANGDEP(PSTRING(" Typ  Stärke"), PSTRING(" Type Power"));
		tbox_flush_set(EV_MENU_TBOX_HIDDEN_POWER_HEADER, 0);
		tbox_tilemap_draw(EV_MENU_TBOX_HIDDEN_POWER_HEADER);
		tbox_print_string(EV_MENU_TBOX_HIDDEN_POWER_HEADER, 0, 2, 0, 0, 0,
				&ev_menu_font_colormap_std_light, 0, str_header_hidden_power);

		// Textboxes for the charts
		tbox_flush_set(EV_MENU_TBOX_CHART_STATS, 0);
		tbox_tilemap_draw(EV_MENU_TBOX_CHART_STATS);
		

        // Initialize oams
		u16 oam_pokepic_tile = oam_vram_alloc(64);
        oam_vram_allocation_table_add(EV_MENU_OAM_POKEPIC_TAG, oam_pokepic_tile, 64);
        oam_allocate_palette(EV_MENU_OAM_POKEPIC_TAG);
        fmem.ev_menu_state->oam_pokepic_tile = oam_pokepic_tile;
        fmem.ev_menu_state->oam_pokepic_idx = oam_new_forward_search(
        		&ev_menu_oam_template_pokemon, 5 * 8, 9 * 8, 0);
        oams[fmem.ev_menu_state->oam_pokepic_idx].flags |= OAM_FLAG_INVISIBLE;

		u16 oam_iv_hexagon_tile = oam_vram_alloc(64);
        oam_vram_allocation_table_add(EV_MENU_OAM_IV_HEXAGON_TAG, oam_iv_hexagon_tile, 64);
        u8 iv_hexagon_pal = oam_allocate_palette(EV_MENU_OAM_IV_HEXAGON_TAG);
        fmem.ev_menu_state->oam_iv_hexagon_tile = oam_iv_hexagon_tile;
        fmem.ev_menu_state->oam_iv_hexagon_idx = oam_new_forward_search(
        		&ev_menu_oam_template_iv_hexagon, 15 * 8, 9 * 8, 0);
        oams[fmem.ev_menu_state->oam_iv_hexagon_idx].flags |= OAM_FLAG_INVISIBLE;

		u16 oam_ev_hexagon_tile = oam_vram_alloc(64);
        oam_vram_allocation_table_add(EV_MENU_OAM_EV_HEXAGON_TAG, oam_ev_hexagon_tile, 64);
        u8 ev_hexagon_pal = oam_allocate_palette(EV_MENU_OAM_EV_HEXAGON_TAG);
        fmem.ev_menu_state->oam_ev_hexagon_tile = oam_ev_hexagon_tile;
        fmem.ev_menu_state->oam_ev_hexagon_idx = oam_new_forward_search(
        		&ev_menu_oam_template_ev_hexagon, 25 * 8, 9 * 8, 0);
        oams[fmem.ev_menu_state->oam_ev_hexagon_idx].flags |= OAM_FLAG_INVISIBLE;
        ev_menu_load_pokemon();

        // Load palettes
        pal_decompress(gfx_ev_menu_bgPal, 0, 32);
        pal_copy(typechart_icon_pal, 16, 32);
        pal_decompress(gfx_ev_menu_hexagonPal, (u16)(256 + 16 * iv_hexagon_pal), 32);
        pal_decompress(gfx_ev_menu_hexagonPal, (u16)(256 + 16 * ev_hexagon_pal), 32);
        pal_copy(tbox_palette_transparent, 14 * 16, 32);
        tbox_init_frame_message(EV_MENU_TBOX_MESSAGE, EV_MENU_MESSAGE_FRAME_START_TILE, 13 * 16);
		pal_set_all_to_black();
	
        bg_virtual_sync(0);
        bg_virtual_sync(1);
        bg_virtual_sync(2);

        callback1_set(ev_menu_callback_show);
        vblank_handler_set(generic_vblank_handler);
    }
}

static void ev_menu_initialize_internal(u8 party_idx, u8 stat_idx, void (*idle_callback)(), void (*continuation)()) {
    fmem.ev_menu_state = (ev_menu_state_stru*) malloc_and_clear(sizeof (ev_menu_state_stru));
    fmem.ev_menu_state->party_idx = party_idx;
    fmem.ev_menu_state->stat_idx = stat_idx;
    fmem.ev_menu_state->pokemon_sprite = malloc_and_clear(0x800);
    fmem.ev_menu_state->iv_hexagon_sprite = malloc_and_clear(0x800);
    fmem.ev_menu_state->ev_hexagon_sprite = malloc_and_clear(0x800);
	fmem.ev_menu_state->idle_callback = idle_callback;
	fmem.ev_menu_state->continuation = continuation;
    callback1_set(ev_menu_callback_setup);
}

void ev_menu_initialize_from_party_menu(u8 self) {
	ev_menu_initialize_internal(pokemon_party_menu_current_index, 0, ev_menu_callback_idle, pokemon_party_menu_return_callback);
    fadescreen_all(1, 0);
	big_callback_delete(self);
}

void ev_menu_initialize_change_nature() {
	ev_menu_initialize_internal(pokemon_party_menu_current_index, 0, ev_menu_change_nature_callback, party_menu_continuation_return_to_bag);
}

bg_config ev_menu_bg_configs[EV_MENU_BG_COUNT] = {
	{.bg_id = 0, .char_base = 2, .map_base = 31, .priority = 1, .size = 0, .color_mode = 0},
	{.bg_id = 1, .char_base = 0, .map_base = 30, .priority = 2, .size = 0, .color_mode = 0},
	{.bg_id = 2, .char_base = 1, .map_base = 29, .priority = 0, .size = 0, .color_mode = 0},
};

tboxdata ev_menu_tboxes[EV_MENU_TBOX_COUNT + 1] = {
	[EV_MENU_TBOX_NAME] = {.bg_id = 0, .x = 1, .y = 3, .w = 8, .h = 2, .start_tile = 1, .pal = 15},
	[EV_MENU_TBOX_HEADER] = {.bg_id = 0, .x = 1, .y = 0, .w = 28, .h = 2, .pal = 15,
			.start_tile = 17},
	[EV_MENU_TBOX_HIDDEN_POWER] = {.bg_id = 0, .x = 1, .y = 14, .w = 9, .h = 2, .pal = 15,
			.start_tile = 73},
	[EV_MENU_TBOX_HIDDEN_POWER_TYPE] = {.bg_id = 0, .x = 1, .y = 18, .w = 4, .h = 2, .pal = 1,
			.start_tile = 91},
	[EV_MENU_TBOX_HIDDEN_POWER_STRENGTH] = {.bg_id = 0, .x = 6, .y = 18, .w = 4, .h = 2, .pal = 15,
			.start_tile = 99},
	[EV_MENU_TBOX_CHART_STATS] = {.bg_id = 2, .x = 10, .y = 4, .w = 20, .h = 10,
			.pal = 15, .start_tile = 107 },
	[EV_MENU_TBOX_IV_CHART_HEADER] = {.bg_id = 0, .x = 11, .y = 2, .w = 8, .h = 2, .pal = 15,
			.start_tile = 307},
	[EV_MENU_TBOX_EV_CHART_HEADER] = {.bg_id = 0, .x = 21, .y = 2, .w = 9, .h = 2, .pal = 15,
			.start_tile = 323},
	[EV_MENU_TBOX_TOTAL_EV] = {.bg_id = 0, .x = 23, .y = 15, .w = 6, .h = 2, .pal = 15,
			.start_tile = 341},
	[EV_MENU_TBOX_CURRENT_STAT_HEADER] = {.bg_id = 0, .x = 10, .y = 15, .w = 10, .h = 2, .pal = 15,
			.start_tile = 361},
	[EV_MENU_TBOX_CURRENT_IV] = {.bg_id = 0, .x = 14, .y = 17, .w = 2, .h = 3, .pal = 15,
			.start_tile = 381},
	[EV_MENU_TBOX_CURRENT_EV] = {.bg_id = 0, .x = 23, .y = 17, .w = 10, .h = 3, .pal = 15,
				.start_tile = 387},
	[EV_MENU_TBOX_HIDDEN_POWER_HEADER] = {.bg_id = 0, .x = 1, .y = 16, .w = 8, .h = 2, .pal = 15,
				.start_tile = 424},
	[EV_MENU_TBOX_MESSAGE] = {.bg_id = 0, .x = 2, .y = 15, .w = 26, .h = 4, .pal = 13, .start_tile = 424 + 16 * 8},
	[EV_MENU_TBOX_COUNT] = {.bg_id = 255},
};
