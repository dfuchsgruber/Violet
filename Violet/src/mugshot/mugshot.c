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
#include "bg.h"

sprite mugshot_sprite = {0, 0xC000,  ATTR2_PRIO(1), 0};
sprite mugshot_sprite_prio0 = {0, 0xC000, ATTR2_PRIO(0), 0};

mugshot mugshots[] = {
    [MUGSHOT_RIN] = {{
			[MUGSHOT_NORMAL] = gfx_mug_rinTiles,
			[MUGSHOT_SHOCKED] = gfx_mug_rin_shockedTiles, 
			[MUGSHOT_ANGRY] = gfx_mug_rin_angryTiles, 
		}, gfx_mug_rinPal, str_mug_rin},
    [MUGSHOT_MISTRAL] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_mistralTiles,
			[MUGSHOT_ANGRY] = gfx_mug_mistral_angryTiles,
			[MUGSHOT_GOOD] = gfx_mug_mistral_goodTiles,
			[MUGSHOT_HAPPY] = gfx_mug_mistral_happyTiles,
			[MUGSHOT_SAD] = gfx_mug_mistral_sadTiles,
			[MUGSHOT_SCARED] = gfx_mug_mistral_scaredTiles,
			[MUGSHOT_SHOCKED] = gfx_mug_mistral_shockedTiles,
			[MUGSHOT_RUMINATIVE] = gfx_mug_mistral_thoughtfulTiles,
			}, 
		gfx_mug_mistralPal, str_mug_mistral},
    [MUGSHOT_RIVAL] = {
			{
				[MUGSHOT_NORMAL] = gfx_mug_rivalTiles,
				[MUGSHOT_HAPPY] = gfx_mug_rival_happyTiles,
				[MUGSHOT_SAD] = gfx_mug_rival_sadTiles,
				[MUGSHOT_SCARED] = gfx_mug_rival_scaredTiles,
				[MUGSHOT_ANGRY] = gfx_mug_rival_angryTiles,
				[MUGSHOT_SHOCKED] = gfx_mug_rival_shockedTiles,
				[MUGSHOT_RUMINATIVE] = gfx_mug_rival_thoughtfulTiles,
				[MUGSHOT_ANNOYED] = gfx_mug_rival_annoyedTiles,
				[MUGSHOT_BEATEN] = gfx_mug_rival_beatenTiles,
			}, 
		gfx_mug_rivalPal, str_mug_rival},
    [MUGSHOT_BRIX] = {
		{[MUGSHOT_NORMAL] = gfx_mug_brixTiles},
		gfx_mug_brixPal, str_mug_brix},
    [MUGSHOT_MAY] = {
			{
					[MUGSHOT_NORMAL] = gfx_mug_mayTiles,
					[MUGSHOT_HAPPY] = gfx_mug_may_happyTiles,
					[MUGSHOT_SAD] = gfx_mug_may_sadTiles,
					[MUGSHOT_SCARED] = gfx_mug_may_scaredTiles,
					[MUGSHOT_ANGRY] = gfx_mug_may_angryTiles,
					[MUGSHOT_SHOCKED] = gfx_mug_may_shockedTiles,
					[MUGSHOT_RUMINATIVE] = gfx_mug_may_thoughtfulTiles,
					[MUGSHOT_EVIL] = gfx_mug_may_evilTiles,
					[MUGSHOT_ANNOYED] = gfx_mug_may_annoyedTiles,
					[MUGSHOT_SERIOUS] = gfx_mug_may_seriousTiles,
				},
			gfx_mug_mayPal, str_mug_may},
    [MUGSHOT_FELIX] = {
			{
				[MUGSHOT_NORMAL] = gfx_mug_felixTiles,
				[MUGSHOT_HAPPY] = gfx_mug_felix_happyTiles,
				[MUGSHOT_SAD] = gfx_mug_felix_sadTiles,
				[MUGSHOT_SCARED] = gfx_mug_felix_scaredTiles,
				[MUGSHOT_ANGRY] = gfx_mug_felix_angryTiles,
				[MUGSHOT_SHOCKED] = gfx_mug_felix_shockedTiles,
				[MUGSHOT_RUMINATIVE] = gfx_mug_felix_thoughtfulTiles,
				[MUGSHOT_ANNOYED] = gfx_mug_felix_annoyedTiles,
			},  
		gfx_mug_felixPal, str_mug_felix},
    [MUGSHOT_BLAISE] = {
			{
				[MUGSHOT_NORMAL] = gfx_mug_blaiseTiles,
				[MUGSHOT_HAPPY] = gfx_mug_blaise_happyTiles,
				[MUGSHOT_SAD] = gfx_mug_blaise_sadTiles,
				[MUGSHOT_SCARED] = gfx_mug_blaise_scaredTiles,
				[MUGSHOT_ANGRY] = gfx_mug_blaise_angryTiles,
				[MUGSHOT_SHOCKED] = gfx_mug_blaise_shockedTiles,
				[MUGSHOT_RUMINATIVE] = gfx_mug_blaise_thoughtfulTiles,
				[MUGSHOT_ANNOYED] = gfx_mug_blaise_annoyedTiles,
			},  
		gfx_mug_blaisePal, str_mug_blaise},
    [MUGSHOT_TANN] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_tannTiles,
			[MUGSHOT_SCARED] = gfx_mug_tann_scaredTiles,
			[MUGSHOT_HAPPY] = gfx_mug_tann_happyTiles,
			[MUGSHOT_RUMINATIVE] = gfx_mug_tann_thoughtfulTiles,
			[MUGSHOT_ANNOYED] = gfx_mug_tann_annoyedTiles,
			[MUGSHOT_ANGRY] = gfx_mug_tann_angryTiles,
			[MUGSHOT_SHOCKED] = gfx_mug_tann_shockedTiles,
		}, 
		gfx_mug_tannPal, str_mug_tann},
    [MUGSHOT_HIRO] = {
			{
				[MUGSHOT_NORMAL] = gfx_mug_hiroTiles,
				[MUGSHOT_HAPPY] = gfx_mug_hiro_happyTiles,
				[MUGSHOT_SAD] = gfx_mug_hiro_sadTiles,
				[MUGSHOT_SCARED] = gfx_mug_hiro_scaredTiles,
				[MUGSHOT_ANGRY] = gfx_mug_hiro_angryTiles,
				[MUGSHOT_SHOCKED] = gfx_mug_hiro_shockedTiles,
				[MUGSHOT_RUMINATIVE] = gfx_mug_hiro_thoughtfulTiles,
				[MUGSHOT_ANNOYED] = gfx_mug_hiro_annoyedTiles,
			},
			gfx_mug_hiroPal, str_mug_hiro
		},
    [MUGSHOT_LESTER] = {
		{[MUGSHOT_NORMAL] = gfx_mug_lesterTiles}, 
		gfx_mug_lesterPal, str_mug_lester},
    [MUGSHOT_FAUN] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_faunTiles,
			[MUGSHOT_ANGRY] = gfx_mug_faun_angryTiles,
			[MUGSHOT_SERIOUS] = gfx_mug_faun_seriousTiles,
			[MUGSHOT_SHOCKED] = gfx_mug_faun_shockedTiles,
			}, 
		gfx_mug_faunPal, str_mug_faun},
    [MUGSHOT_ELISE] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_eliseTiles,
			[MUGSHOT_SHOCKED] = gfx_mug_elise_shockedTiles,
			[MUGSHOT_ANGRY] = gfx_mug_elise_angryTiles,
			[MUGSHOT_SCARED] = gfx_mug_elise_scaredTiles,
			[MUGSHOT_SAD] = gfx_mug_elise_sadTiles,
			[MUGSHOT_ANNOYED] = gfx_mug_elise_annoyedTiles,
			[MUGSHOT_RUMINATIVE] = gfx_mug_elise_thoughtfulTiles,
			}, 
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
		{
			[MUGSHOT_NORMAL] = gfx_mug_albusTiles, 
			[MUGSHOT_SAD] = gfx_mug_albus_sadTiles,
			[MUGSHOT_SHOCKED] = gfx_mug_albus_shockedTiles,
		}, 
		gfx_mug_albusPal, str_mug_albus},
    [MUGSHOT_FAUN_YOUNG] = {
		{[MUGSHOT_NORMAL] = gfx_mug_faun_youngTiles}, 
		gfx_mug_faun_youngPal, str_mug_faun},
    [MUGSHOT_CELEBI] = {
		{[MUGSHOT_NORMAL] = gfx_pokemon_celebi_frontspriteTiles}, 
		gfx_pokemon_celebi_frontspritePal, str_mug_celebi},
    [MUGSHOT_LARISSA] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_larissaTiles,
			[MUGSHOT_HAPPY] = gfx_mug_larissa_happyTiles,
			[MUGSHOT_ANGRY] = gfx_mug_larissa_angryTiles,
			[MUGSHOT_RUMINATIVE] = gfx_mug_larissa_thoughtfulTiles,
			}, 
		gfx_mug_larissaPal, str_mug_larissa},
    [MUGSHOT_PRIMUS] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_primusTiles,
			[MUGSHOT_SCARED] = gfx_mug_primus_scaredTiles,
			[MUGSHOT_RUMINATIVE] = gfx_mug_primus_thoughtfulTiles,
		}, 
		gfx_mug_primusPal, str_mug_primus},
    [MUGSHOT_IGVA] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_igvaTiles,
			[MUGSHOT_SAD] = gfx_mug_igva_sadTiles,
			[MUGSHOT_HAPPY] = gfx_mug_igva_happyTiles,
			[MUGSHOT_SCARED] = gfx_mug_igva_scaredTiles,
			[MUGSHOT_SHOCKED] = gfx_mug_igva_shockedTiles,
			[MUGSHOT_RUMINATIVE] = gfx_mug_igva_thoughtfulTiles,
			[MUGSHOT_ANNOYED] = gfx_mug_igva_annoyedTiles,
		}, 
		gfx_mug_igvaPal, str_mug_igva},
    [MUGSHOT_BLACKBEARD] = {
		{[MUGSHOT_NORMAL] = gfx_mug_blackbeardTiles,
		[MUGSHOT_SHOCKED] = gfx_mug_blackbeard_shockedTiles,
		[MUGSHOT_ANGRY] = gfx_mug_blackbeard_angryTiles,
		[MUGSHOT_HAPPY] = gfx_mug_blackbeard_happyTiles}, 
		gfx_mug_blackbeardPal, str_mug_blackbeard},
    [MUGSHOT_HIROINE] = {
			{
				[MUGSHOT_NORMAL] = gfx_mug_hiroineTiles,
				[MUGSHOT_HAPPY] = gfx_mug_hiroine_happyTiles,
				[MUGSHOT_SAD] = gfx_mug_hiroine_sadTiles,
				[MUGSHOT_SCARED] = gfx_mug_hiroine_scaredTiles,
				[MUGSHOT_ANGRY] = gfx_mug_hiroine_angryTiles,
				[MUGSHOT_SHOCKED] = gfx_mug_hiroine_shockedTiles,
				[MUGSHOT_RUMINATIVE] = gfx_mug_hiroine_thoughtfulTiles,
				[MUGSHOT_ANNOYED] = gfx_mug_hiroine_annoyedTiles,
			},
			gfx_mug_hiroinePal, str_mug_hiro
		},
	[MUGSHOT_TEAH] = {
		{[MUGSHOT_NORMAL] = gfx_mug_teahTiles}, 
		gfx_mug_teahPal, str_mug_teah},
	[MUGSHOT_NARCISSA] = {
		{[MUGSHOT_NORMAL] = gfx_mug_narcissaTiles}, 
		gfx_mug_narcissaPal, str_mug_narcissa},
	[MUGSHOT_LUCIUS] = {
		{[MUGSHOT_NORMAL] = gfx_mug_luciusTiles}, gfx_mug_luciusPal, str_mug_lucius},
	[MUGSHOT_LUCKY] = {
		{[MUGSHOT_NORMAL] = gfx_mug_luckyTiles,
		[MUGSHOT_SCARED] = gfx_mug_lucky_scaredTiles,
		[MUGSHOT_SHOCKED] = gfx_mug_lucky_shockedTiles}, gfx_mug_luckyPal, str_mug_lucky},
	[MUGSHOT_LESTER_YOUNG] = {
		{[MUGSHOT_NORMAL] = gfx_mug_lester_youngTiles,
		[MUGSHOT_SHOCKED] = gfx_mug_lester_young_shockedTiles,
		[MUGSHOT_SAD] = gfx_mug_lester_young_sadTiles,
		}, gfx_mug_lester_youngPal, str_mug_lester
	},
	[MUGSHOT_ROMAN] = {
		{[MUGSHOT_NORMAL] = gfx_mug_romanTiles,
		[MUGSHOT_HAPPY] = gfx_mug_roman_happyTiles
		}, gfx_mug_romanPal, str_mug_roman
	},
	[MUGSHOT_ROSALIE] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_rosalieTiles,
			[MUGSHOT_ANGRY] = gfx_mug_rosalie_angryTiles,
			[MUGSHOT_SAD] = gfx_mug_rosalie_sadTiles,
			[MUGSHOT_SCARED] = gfx_mug_rosalie_scaredTiles,
			[MUGSHOT_SHOCKED] = gfx_mug_rosalie_shockedTiles,
		},
		gfx_mug_rosaliePal,
		str_mug_rosalie,
	},
	[MUGSHOT_MANUS] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_manusTiles,
			[MUGSHOT_ANGRY] = gfx_mug_manus_angryTiles,
			[MUGSHOT_SAD] = gfx_mug_manus_happyTiles,
		},
		gfx_mug_manusPal,
		str_mug_manus,
	},
	[MUGSHOT_ICARUS] = {
		{
			[MUGSHOT_NORMAL] = gfx_mug_icarusTiles,
			[MUGSHOT_HAPPY] = gfx_mug_icarus_happyTiles,
			[MUGSHOT_SAD] = gfx_mug_icarus_sadTiles,
			[MUGSHOT_SCARED] = gfx_mug_icarus_scaredTiles,
			[MUGSHOT_ANGRY] = gfx_mug_icarus_angryTiles,
			[MUGSHOT_SHOCKED] = gfx_mug_icarus_shockedTiles,
			[MUGSHOT_RUMINATIVE] = gfx_mug_icarus_thoughtfulTiles,
			[MUGSHOT_ANNOYED] = gfx_mug_icarus_annoyedTiles,
		},
		gfx_mug_icarusPal,
		str_mug_icarus,
	}
	
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
		DEBUG("Allocated new mugshot vram\n");
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
	fmem.mugshot_oam_id = oam_new_forward_search(mugshot_template, (s16) (32 + (side > 0) * 176), 80, 0);
	fmem.mugshot_active = 1;
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
		tbox_init_frame_message(box_id, 1, 15 * 16);
		tbox_frame_draw_outer(box_id, 1, 0xF);
		tbox_font_colormap fontcolmap = {1, 2, 1, 3};
		tbox_print_string(box_id, 2, 16, 0, 0, 0, &fontcolmap, 0, strbuf);
		fmem.mugshot_tb_id = box_id;
	}
}

void mugshot_update() {
	if (fmem.mugshot_active) {
		u16 tag = oams[fmem.mugshot_oam_id].oam_template->tiles_tag;
		int mugshot_idx = tag - MUGSHOT_BASE_TAG;
		int emotion = *var_access(0x8000);
		const u8 *gfx = mugshot_get_emotion_gfx(mugshot_idx, emotion);
		u16 base_tile = oams[fmem.mugshot_oam_id].base_tile;
		lz77uncompvram(gfx, OAMCHARBASE(base_tile));
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
			fmem.mugshot_active = 0;
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
				tbox_flush_map_and_frame(tb_id);
			tbox_free(tb_id);
			++*state;
			break;
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


