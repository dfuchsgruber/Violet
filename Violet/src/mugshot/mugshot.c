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
    {&gfx_mug_rinTiles, &gfx_mug_rinPal, str_mug_rin},
    {NULL, NULL, NULL},
    {&gfx_mug_mistralTiles, &gfx_mug_mistralPal, str_mug_mistral},
    {NULL, NULL, NULL},
    
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {&gfx_mug_rivalTiles, &gfx_mug_rivalPal, str_mug_rival},
    {&gfx_mug_brixTiles, &gfx_mug_brixPal, str_mug_brix},
    
    {&gfx_mug_mayTiles, &gfx_mug_mayPal, str_mug_may},
    {&gfx_mug_felixTiles, &gfx_mug_felixPal, str_mug_felix},
    {&gfx_mug_blaiseTiles, &gfx_mug_blaisePal, str_mug_blaise},
    {&gfx_mug_tannTiles, &gfx_mug_tannPal, str_mug_tann},
    
    {&gfx_mug_hiroTiles, &gfx_mug_hiroPal, str_mug_hiro},
    {&gfx_mug_lesterTiles, &gfx_mug_lesterPal, str_mug_lester},
    {&gfx_mug_faunTiles, &gfx_mug_faunPal, str_mug_faun},
    {&gfx_mug_eliseTiles, &gfx_mug_elisePal, str_mug_elise},
    
    {&gfx_mug_emerysTiles, &gfx_mug_emerysPal, str_mug_emerys},
    {&gfx_mug_rubysTiles, &gfx_mug_rubysPal, str_mug_rubys},
    {&gfx_mug_saphiraTiles, &gfx_mug_saphiraPal, str_mug_saphira},
    {&gfx_mug_harrenfeldTiles, &gfx_mug_harrenfeldPal, str_mug_harrenfeld},
    
    {&gfx_mug_albusTiles, &gfx_mug_albusPal, str_mug_albus},
    {&gfx_mug_faun_youngTiles, &gfx_mug_faun_youngPal, str_mug_faun},
    {&gfx_pkmn_species_251_pokemon_celebi_frontspriteTiles, &gfx_pkmn_species_251_pokemon_celebi_frontspritePal, str_mug_celebi},
    {&gfx_mug_larissaTiles, &gfx_mug_larissaPal, str_mug_larissa},
    
    {&gfx_mug_primusTiles, &gfx_mug_primusPal, str_mug_primus},
    {&gfx_mug_igvaTiles, &gfx_mug_igvaPal, str_mug_igva},
    {&gfx_mug_blackbeardTiles, &gfx_mug_blackbeardPal, str_mug_blackbeard},
    {&gfx_mug_hiroineTiles, &gfx_mug_hiroinePal, str_mug_hiro}
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


void mugshot_create_oam(int side, int idx) {
    u16 tag = (u16) (MUGSHOT_BASE_TAG + idx);
    // Create the graphic
    graphic *mugshot_tmp_graphic = (graphic*) malloc(sizeof (graphic));
	mugshot_tmp_graphic->sprite = mugshots[idx].gfx;
	mugshot_tmp_graphic->size = 0x800;
	mugshot_tmp_graphic->tag = tag;

	// Load palette
	u8 pal = oam_allocate_palette(tag);
	u16 *pal_buf = (u16*) malloc(40);
	lz77uncompwram(mugshots[idx].pal, pal_buf);
	u8 weather = map_get_current_weather();
	pal_copy(pal_buf, (u16) (0x100 + 16 * pal), 32);
	if (weather == MAP_WEATHER_CLOUDY || weather == MAP_WEATHER_EXTREME_THUNDER ||
			weather == MAP_WEATHER_THUNDER || weather == MAP_WEATHER_RAIN) {
		//fade
		u16 *dma3s = (u16*) 0x020375F8;
		int i;
		for (i = 0; i < 16; i++) {
			u16 original = dma3s[i + (pal + 0x10)*0x10];
			color_t co = {original};
			color_t over = {0}; //black
			color_t n = color_alpha_blend(co, over, 3);
			dma3s[i + (pal + 0x10)*0x10] = n.value;
		}
	}
	free(pal_buf);

	// Allocate vram for the mugshot
	if (oam_vram_allocation_table_get_index(tag) == 0xFF) {
		oam_load_graphic(mugshot_tmp_graphic);
	}

	// Create a template
	oam_template *mugshot_template = malloc(sizeof (oam_template));
	mugshot_template->tiles_tag = tag;
	mugshot_template->pal_tag = tag;
	if(!checkflag(0x806) && get_mapheader(save1->bank, save1->map)->flash_type){
		mugshot_template->oam = &mugshot_sprite_prio0;
	}else{
		mugshot_template->oam = &mugshot_sprite;
	}
	mugshot_template->graphics = NULL;
	mugshot_template->animation = (gfx_frame**) 0x08231Bc0;
	mugshot_template->rotscale = (rotscale_frame**) 0x08231Bcc;
	mugshot_template->callback = oam_null_callback;

	// Spawn the mugshot
	s16 x = (s16) (0x20 + side * 0xB0);
	fmem.mugshot_oam_id = oam_new_forward_search(mugshot_template, x, 0x50, 0);
}

void mugshot_create_text(int side, u8 *text) {
	dprintf("Create text %x\n", text);
	// Decrypt buffers
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
  if (idx == MUGSHOT_PLAYER) {
    idx = save2->player_is_female ? MUGSHOT_HIROINE : MUGSHOT_HIRO;
  }
	int is_known = *var_access(0x8002);
	u8 unknown_name[] = PSTRING("???");
    mugshot_create_oam(side, idx);
	mugshot_create_text(side, is_known ? mugshots[idx].name : unknown_name);
}

void special_mugshot_delete() {
	// Delete the oam
	u16 oam_id = fmem.mugshot_oam_id;
	u8 delete_oam_cb_id = big_callback_new(mugshot_delete_oam, 0);
	big_callbacks[delete_oam_cb_id].params[0] = oam_id;
	// Move the oam offscreen meanwhile
	oams[oam_id].x2 = -64;

	// Delete the text
	u8 delete_tb_cb_id = big_callback_new(mugshot_delete_text, 0);
	big_callbacks[delete_tb_cb_id].params[0] = fmem.mugshot_tb_id;
}

void mugshot_delete_oam(u8 self) {
    u8 oam_id = (u8)big_callbacks[self].params[0];
    free(oams[oam_id].oam_template->graphics);
    free(oams[oam_id].oam_template);
    oam_free(&oams[oam_id]);
    big_callback_delete(self);

}

void mugshot_delete_text(u8 self) {
    u8 tb_id = (u8)big_callbacks[self].params[0];
    tbox_flush_set(tb_id, 0);
    tbox_flush_map(tb_id);
    tbox_sync(tb_id, TBOX_SYNC_MAP_AND_SET);
    if(!transparency_is_on()) tbox_border_flush(tb_id);
    tbox_free(tb_id);
    big_callback_delete(self);
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
}


