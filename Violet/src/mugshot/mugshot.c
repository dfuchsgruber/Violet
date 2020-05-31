#include "types.h"
#include "mugshot.h"
#include "oam.h"
#include "callbacks.h"
#include "color.h"
#include "save.h"
#include "text.h"
#include "debug.h"
#include "transparency.h"
#include "constants/map_weathers.h"
#include "vars.h"
#include "flags.h"
#include "bios.h"
#include "agbmemory.h"
#include "overworld/map_control.h"
#include "overworld/script.h"
#include "language.h"
#include "constants/mugshot_character.h"

#define MUGSHOT_BASE_TAG 0x1340

sprite mugshot_sprite = {0, 0xC000,  ATTR2_PRIO(1), 0};
sprite mugshot_sprite_prio0 = {0, 0xC000, ATTR2_PRIO(0), 0};


mugshot mugshots[] = {
    [MUGSHOT_RIN] = {
		{[MUGSHOT_NORMAL] = gfx_mug_rinTiles}, 
		gfx_mug_rinPal, str_mug_rin},
    [MUGSHOT_MISTRAL] = {
		{[MUGSHOT_NORMAL] = gfx_mug_mistralTiles}, 
		gfx_mug_mistralPal, str_mug_mistral},
    [MUGSHOT_RIVAL] = {
		{[MUGSHOT_NORMAL] = gfx_mug_rivalTiles}, 
		gfx_mug_rivalPal, str_mug_rival},
    [MUGSHOT_BRIX] = {
		{[MUGSHOT_NORMAL] = gfx_mug_brixTiles},
		gfx_mug_brixPal, str_mug_brix},
    [MUGSHOT_MAY] = {
		{[MUGSHOT_NORMAL] = gfx_mug_mayTiles}, 
		gfx_mug_mayPal, str_mug_may},
    [MUGSHOT_FELIX] = {
		{[MUGSHOT_NORMAL] = gfx_mug_felixTiles}, 
		gfx_mug_felixPal, str_mug_felix},
    [MUGSHOT_BLAISE] = {
		{[MUGSHOT_NORMAL] = gfx_mug_blaiseTiles}, gfx_mug_blaisePal, str_mug_blaise},
    [MUGSHOT_TANN] = {
		{[MUGSHOT_NORMAL] = gfx_mug_tannTiles}, 
		gfx_mug_tannPal, str_mug_tann},
    [MUGSHOT_HIRO] = {
		{[MUGSHOT_NORMAL] = gfx_mug_hiroTiles},
		gfx_mug_hiroPal, str_mug_hiro},
    [MUGSHOT_LESTER] = {
		{[MUGSHOT_NORMAL] = gfx_mug_lesterTiles}, 
		gfx_mug_lesterPal, str_mug_lester},
    [MUGSHOT_FAUN] = {
		{[MUGSHOT_NORMAL] = gfx_mug_faunTiles}, 
		gfx_mug_faunPal, str_mug_faun},
    [MUGSHOT_ELISE] = {
		{[MUGSHOT_NORMAL] = gfx_mug_eliseTiles}, 
		gfx_mug_elisePal, str_mug_elise},
    [MUGSHOT_EMERYS] = {
		{[MUGSHOT_NORMAL] = gfx_mug_emerysTiles}, 
		gfx_mug_emerysPal, str_mug_emerys},
    [MUGSHOT_RUBYS] = {
		{[MUGSHOT_NORMAL] = gfx_mug_rubysTiles}, 
		gfx_mug_rubysPal, str_mug_rubys},
    [MUGSHOT_SAPHIRA] = {
		{[MUGSHOT_NORMAL] = gfx_mug_saphiraTiles}, 
		gfx_mug_saphiraPal, str_mug_saphira},
    [MUGSHOT_HARRENFELD] = {
		{[MUGSHOT_NORMAL] = gfx_mug_harrenfeldTiles}, 
		gfx_mug_harrenfeldPal, str_mug_harrenfeld},
    [MUGSHOT_ALBUS] = {
		{[MUGSHOT_NORMAL] = gfx_mug_albusTiles}, 
		gfx_mug_albusPal, str_mug_albus},
    [MUGSHOT_FAUN_YOUNG] = {
		{[MUGSHOT_NORMAL] = gfx_mug_faun_youngTiles}, 
		gfx_mug_faun_youngPal, str_mug_faun},
    [MUGSHOT_CELEBI] = {
		{[MUGSHOT_NORMAL] = gfx_pkmn_species_251_pokemon_celebi_frontspriteTiles}, 
		gfx_pkmn_species_251_pokemon_celebi_frontspritePal, str_mug_celebi},
    [MUGSHOT_LARISSA] = {
		{[MUGSHOT_NORMAL] = gfx_mug_larissaTiles}, 
		gfx_mug_larissaPal, str_mug_larissa},
    [MUGSHOT_PRIMUS] = {
		{[MUGSHOT_NORMAL] = gfx_mug_primusTiles}, 
		gfx_mug_primusPal, str_mug_primus},
    [MUGSHOT_IGVA] = {
		{[MUGSHOT_NORMAL] = gfx_mug_igvaTiles}, 
		gfx_mug_igvaPal, str_mug_igva},
    [MUGSHOT_BLACKBEARD] = {
		{[MUGSHOT_NORMAL] = gfx_mug_blackbeardTiles}, 
		gfx_mug_blackbeardPal, str_mug_blackbeard},
    [MUGSHOT_HIROINE] = {
		{[MUGSHOT_NORMAL] = gfx_mug_hiroineTiles}, 
		gfx_mug_hiroinePal, str_mug_hiro},
	[MUGSHOT_TEAH] = {
		{[MUGSHOT_NORMAL] = gfx_mug_teahTiles}, 
		gfx_mug_teahPal, str_mug_teah},
	[MUGSHOT_NARCISSA] = {
		{[MUGSHOT_NORMAL] = gfx_mug_narcissaTiles}, 
		gfx_mug_narcissaPal, str_mug_narcissa},
	[MUGSHOT_LUCIUS] = {
		{[MUGSHOT_NORMAL] = gfx_mug_luciusTiles}, gfx_mug_luciusPal, str_mug_lucius},
	[MUGSHOT_LUCKY] = {
		{[MUGSHOT_NORMAL] = gfx_mug_luckyTiles}, gfx_mug_luckyPal, str_mug_lucky},
};

void tbox_clear_bottom_line(u8 box_id) {
    int first_tile = tboxes[box_id].boxdata.w * (tboxes[box_id].boxdata.h - 1);
    int i;
    u16 *vtileset = (tboxes[box_id].virtual_tileset);
    for(i = 0; i < tboxes[box_id].boxdata.w; i++){
        vtileset[(first_tile + i) * 16 + 14] = 0;
        vtileset[(first_tile + i) * 16 + 15] = 0;
    }
}

static const void *mugshot_get_emotion_gfx(int idx, int emotion) {
	if (mugshots[idx].gfx[emotion] == NULL) {
		emotion = MUGSHOT_NORMAL;
	}
	return mugshots[idx].gfx[emotion];
}

void mugshot_create_oam(int side, int idx, int emotion) {
    u16 tag = (u16) (MUGSHOT_BASE_TAG + idx);
	
	// Create an oam template for the mugshot
	oam_template *mugshot_template = malloc(sizeof(oam_template));
	mugshot_template->tiles_tag = tag;
	mugshot_template->pal_tag = tag;
	if (map_flash_usable()){
		mugshot_template->oam = &mugshot_sprite_prio0;
	} else {
		mugshot_template->oam = &mugshot_sprite;
	}
	mugshot_template->animation = oam_gfx_anim_table_null;
	mugshot_template->rotscale = oam_rotscale_anim_table_null;
	mugshot_template->callback = oam_null_callback;

	if (oam_vram_allocation_table_get_index(tag) == 0xFF) {
		// Allocate a graphic, that is released once the mugshot is destroyed
		graphic *g = (graphic*) malloc(sizeof (graphic));
		g->sprite = mugshot_get_emotion_gfx(idx, emotion);
		g->size = GRAPHIC_SIZE_4BPP(64, 64);
		g->tag = tag;	
		oam_load_graphic(g);
		mugshot_template->graphics = g;
	} else {
		mugshot_template->graphics = NULL;
	}

	// Load palette
	if (oam_palette_get_index(tag) == 0xFF) {
		u8 pal = oam_allocate_palette(tag);
		pal_decompress(mugshots[idx].pal, (u16)(16 * (pal + 16)), 16 * sizeof(color_t));
		pal_oam_apply_fading(pal);
	}

	fmem.mugshot_oam_id = oam_new_forward_search(mugshot_template, (s16) (32 + side * 176), 80, 0);
}

void mugshot_create_text(int side, u8 *text) {
	string_decrypt(strbuf, text);
	u8 width = string_get_width(2, strbuf, 0);
	if(transparency_is_on()){
		tboxdata tbdata = {
			0, (side ? 0 : (u8)(30 - width / 8 - 4)), 12, (u8)((width / 8) + 4), 2, 15, 0xE8
		};
		u8 box_id = tbox_new(&tbdata);
		tbox_flush_set(box_id, 0x11);
		tbox_tilemap_draw(box_id);
		tbox_clear_bottom_line(box_id);
		tbox_font_colormap fontcolmap = {1, 2, 1, 3};
		tbox_print_string(box_id, 2, 16, 0, 0, 0, &fontcolmap, 0, strbuf);
		fmem.mugshot_tb_id = box_id;

	}else{
		tboxdata tbdata = {
			0, (side ? 1 : (u8)(30 - width / 8 - 5)), 11, (u8)((width / 8) + 4), 2, 15, 0xE8
		};
		u8 box_id = tbox_new(&tbdata);
		tbox_flush_set(box_id, 0x11);
		tbox_tilemap_draw(box_id);
		tbox_message_init_border(box_id, 1, 15 * 16);
		tbox_border_draw(box_id, 1, 0xF);
		tbox_font_colormap fontcolmap = {1, 2, 1, 3};
		tbox_print_string(box_id, 2, 16, 0, 0, 0, &fontcolmap, 0, strbuf);
		fmem.mugshot_tb_id = box_id;
	}
}

void special_mugshot_show() {
	// If a mugshot_delete_oam callback is already present we have to clear the mugshot in this
	// frame manually before creating a new one
	u8 delete_oam_cb_id = big_callback_get_id(mugshot_delete_oam);
	if (delete_oam_cb_id != 0xFF) {
		mugshot_delete_oam(delete_oam_cb_id);
	}
	// Same goes for the text
	u8 delete_text_cb_id = big_callback_get_id(mugshot_delete_text);
	if (delete_text_cb_id != 0xFF) {
		mugshot_delete_text(delete_text_cb_id);
	}

	// Create the actual mugshot
  int side = *var_access(0x8000);
  int idx = *var_access(0x8001);
  int emotion = *var_access(0x8003);
  if (idx == MUGSHOT_PLAYER) {
    idx = save2->player_is_female ? MUGSHOT_HIROINE : MUGSHOT_HIRO;
  }
	int is_known = *var_access(0x8002);
	u8 unknown_name[] = PSTRING("???");
    mugshot_create_oam(side, idx, emotion);
	mugshot_create_text(side, is_known ? mugshots[idx].name : unknown_name);
}

void special_mugshot_delete() {
	// Delete the oam
	u16 oam_id = fmem.mugshot_oam_id;
	u8 delete_oam_cb_id = big_callback_new(mugshot_delete_oam, 0);
	big_callbacks[delete_oam_cb_id].params[0] = oam_id;
	big_callbacks[delete_oam_cb_id].params[1] = 0;
	// Move the oam offscreen meanwhile
	oams[oam_id].x2 = -64;

	// Delete the text
	u8 delete_tb_cb_id = big_callback_new(mugshot_delete_text, 0);
	big_callbacks[delete_tb_cb_id].params[0] = fmem.mugshot_tb_id;
	big_callbacks[delete_tb_cb_id].params[1] = 0;
}

void mugshot_wait_for_deletion(u8 self) {
	if (big_callback_is_active(mugshot_delete_oam) || big_callback_is_active(mugshot_delete_text)) return;
	overworld_script_resume();
	big_callback_delete(self);
}

void mugshot_delete_oam(u8 self) {
	u16 *state = big_callbacks[self].params + 1;
	switch(*state) {
		case 0: {
			u8 oam_id = (u8)big_callbacks[self].params[0];
			free(oams[oam_id].oam_template->graphics);
			free(oams[oam_id].oam_template);
			oam_free(&oams[oam_id]);
			++*state;
			break;
			}
		case 1:
			++*state; // I frame delay
			break;
		default: {
			if (!big_callback_is_active(mugshot_wait_for_deletion)) {
				big_callbacks[self].function = mugshot_wait_for_deletion;
			} else {
				big_callback_delete(self);
			}
			break;
		}
	}
}

void mugshot_delete_text(u8 self) {
	u16 *state = big_callbacks[self].params + 1;
	switch(*state) {
		case 0: {
			u8 tb_id = (u8)big_callbacks[self].params[0];
			tbox_flush_set(tb_id, 0);
			tbox_flush_map(tb_id);
			tbox_sync(tb_id, TBOX_SYNC_MAP_AND_SET);
			if(!transparency_is_on()) 
				tbox_border_flush(tb_id);
			tbox_free(tb_id);
		}
		default: {
			if (!big_callback_is_active(mugshot_wait_for_deletion)) {
				big_callbacks[self].function = mugshot_wait_for_deletion;
			} else {
				big_callback_delete(self);
			}
			break;
		}
	}
}

void special_show_name() {
	// Delete any text that is currently present
	u8 delete_text_cb_id = big_callback_get_id(mugshot_delete_text);
	if (delete_text_cb_id != 0xFF) {
		mugshot_delete_text(delete_text_cb_id);
	}

	// Show the text
	u8 *text = overworld_script_state.pointer_banks[0];
	int side = *var_access(0x8000);
	mugshot_create_text(side, text);
}

void special_delete_name() {
	// Delete the text
	u8 delete_tb_cb_id = big_callback_new(mugshot_delete_text, 0);
	big_callbacks[delete_tb_cb_id].params[0] = fmem.mugshot_tb_id;
	big_callbacks[delete_tb_cb_id].params[1] = 0;
}


