#include "types.h"
#include "overworld/script.h"
#include "item/item.h"
#include "item/gfx.h"
#include "text.h"
#include "language.h"
#include "vars.h"
#include "debug.h"
#include "transparency.h"
#include "save.h"
#include "callbacks.h"
#include "oam.h"
#include "bios.h"
#include "options.h"
#include "mugshot.h"

EWRAM u8 item_obtain_oam_id = 0;
EWRAM u8 item_obtain_tb_id = 0;
static const u8 str_times[] = PSTRING("FONT_SIZE_SMALL×FONT_SIZE_BIG");

bool overworld_script_command_xd4_bufferitemnameplural(overworld_script_state_t *state) {
    u8 buffer_idx = state->script[0];
    state->script++;
    u16 item_idx =  var_get(overworld_script_read_hword(state));
    u16 cnt = var_get(overworld_script_read_hword(state));
    u8 *dst = ow_script_string_buffers[buffer_idx];
    DEBUG("buffer item name plural for item %d, count %d, buffer %d\n", item_idx, cnt, buffer_idx);
    dst[0] = 0xFF;
    if (cnt > 1) {
        u8 str_cnt[8];
        itoa(str_cnt, cnt, ITOA_NO_PADDING, (u8)((cnt / 10) + 1));
        strcat(dst, str_cnt);
        strcat(dst, str_times);
        strcat(dst, item_get_name(item_idx));
    } else {
        strcpy(dst, item_get_name(item_idx));
    }
    return false;
} 

#define ITEM_OBTAIN_TAG 0xB110
static const sprite sprite_item_obtain = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0)
    };
static const oam_template template_item_obtain = {
    .tiles_tag = ITEM_OBTAIN_TAG, .pal_tag = ITEM_OBTAIN_TAG,
    .oam = &sprite_item_obtain, .graphics = NULL, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static const tboxdata tboxdata_non_tm_hm = {
    .bg_id = 0, .x = 1, .y = 8, .w = 28, .h = 6, .pal = 15, .start_tile = 0xE8
};

static const tboxdata tboxdata_tm_hm = {
    .bg_id = 0, .x = 1, .y = 6, .w = 18, .h = 8, .pal = 15, .start_tile = 0xE8
};


static const tboxdata tboxdata_non_tm_hm_non_transparent = {
    .bg_id = 0, .x = 1, .y = 7, .w = 28, .h = 6, .pal = 15, .start_tile = 0xE8
};

static const tboxdata tboxdata_tm_hm_non_transparent = {
    .bg_id = 0, .x = 1, .y = 5, .w = 18, .h = 8, .pal = 15, .start_tile = 0xE8
};


void special_item_obtain_show() {
	if (item_obtain_should_show_description()) {
		// DEBUG("Item is %d\n", var_get(0x8000));
		u16 item_idx = var_get(0x8004);
		bool is_tm_hm = false; // item_get_pocket(item_idx) == POCKET_TM_HM;
		// DEBUG("Found hm item %d\n", is_tm_hm);
		if (transparency_is_on()) {
			const tboxdata *tbdata = is_tm_hm ? &tboxdata_tm_hm : &tboxdata_non_tm_hm;
			u8 box_id = tbox_new(tbdata);
			tbox_flush_set(box_id, 0x11);
			tbox_tilemap_draw(box_id);
			tbox_clear_bottom_line(box_id);
			tbox_font_colormap fontcolmap = {1, 2, 1, 3};
			tbox_print_string(box_id, 0, 32 + 4, 2, 0, 0, &fontcolmap, 0,
				item_get_description(item_idx));
			item_obtain_tb_id = box_id;
		} else {
			const tboxdata *tbdata = is_tm_hm ? &tboxdata_tm_hm_non_transparent : &tboxdata_non_tm_hm_non_transparent;
			u8 box_id = tbox_new(tbdata);
			tbox_flush_set(box_id, 0x11);
			tbox_tilemap_draw(box_id);
			tbox_init_frame_set_style(box_id, 1, 13 * 16);
			tbox_frame_draw_outer(box_id, 1, 13);
			tbox_font_colormap fontcolmap = {1, 2, 3, 3};
			tbox_print_string(box_id, 0, 32 + 4, 2, 0, 0, &fontcolmap, 0,
				item_get_description(item_idx));
			item_obtain_tb_id = box_id;
		}
		DEBUG("Item description box %d\n", item_obtain_tb_id);

		// Create the oam
		u16 tile = oam_vram_get_tile(ITEM_OBTAIN_TAG);
		if (tile == 0xFFFF) {
			u16 num_tiles = GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8);
			tile = oam_vram_alloc(num_tiles);
			oam_vram_allocation_table_add(ITEM_OBTAIN_TAG, tile, num_tiles);
		}
		const u8 *gfx = item_get_resource(item_idx, false);
		lz77uncompwram(gfx, gp_tmp_buf);
		int zero = 0;
		cpuset(&zero, (u8*)OAMCHARBASE(tile), CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(32, 32)));
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				cpuset(gp_tmp_buf + (3 * y + x) * GRAPHIC_SIZE_4BPP(8, 8), (u8*)OAMCHARBASE(tile) + (4 * y + x) * GRAPHIC_SIZE_4BPP(8, 8),
					CPUSET_COPY | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8) | CPUSET_HALFWORD));
			}
		}
		u8 pal_idx = oam_palette_get_index(ITEM_OBTAIN_TAG);
		if (pal_idx == 0xFF) {
			pal_idx = oam_allocate_palette(ITEM_OBTAIN_TAG);
			const u8 *pal = item_get_resource(item_idx, true);
			pal_decompress(pal, (u16)(256 + 16 * pal_idx), sizeof(color_t) * 16);
		}
		u8 oam_idx = oam_new_forward_search(&template_item_obtain, 24 + 4, 
			is_tm_hm ? 80 + 4 : 88 + 4, 1);
		item_obtain_oam_id = oam_idx;
	} else {
		item_obtain_tb_id = 0x10;
		item_obtain_oam_id = NUM_OAMS;
	}
    
}

static void item_obtain_wait_for_deletion(u8 self);

static void item_obtain_delete_oam(u8 self) {
	u16 *state = big_callbacks[self].params + 1;
	switch(*state) {
		case 0: {
			u8 oam_id = (u8)big_callbacks[self].params[0];
			if (item_obtain_should_show_description() && oam_id < NUM_OAMS) {
				oam_free(&oams[oam_id]);
			}
			++*state;
			break;
		}
		case 1:
			++*state; // I frame delay
			break;
		default: {
			mugshot_flags.active = 0;
			if (!big_callback_is_active(item_obtain_wait_for_deletion)) {
				big_callbacks[self].function = item_obtain_wait_for_deletion;
			} else {
				big_callback_delete(self);
			}
			break;
		}
	}
}

static void item_obtain_delete_text(u8 self) {
    u16 *state = big_callbacks[self].params + 1;
	switch(*state) {
		case 0: {
			u8 tb_id = (u8)big_callbacks[self].params[0];
			if (item_obtain_should_show_description() && tb_id < 16) {
				tbox_flush_set(tb_id, 0);
				tbox_flush_map(tb_id);
				tbox_sync(tb_id, TBOX_SYNC_MAP_AND_SET);
				if(!transparency_is_on()) 
					tbox_flush_map_and_frame(tb_id);
				tbox_free(tb_id);
			}
			++*state;
			break;
		}
		default: {
			if (!big_callback_is_active(item_obtain_wait_for_deletion)) {
				big_callbacks[self].function = item_obtain_wait_for_deletion;
			} else {
				big_callback_delete(self);
			}
			break;
		}
	}
}


static void item_obtain_wait_for_deletion(u8 self) {
	if (big_callback_is_active(item_obtain_delete_text) || big_callback_is_active(item_obtain_delete_oam)) 
        return;
	overworld_script_resume();
	big_callback_delete(self);
}

void special_item_obtain_delete() {
    // Delete the text
	u8 delete_tb_cb_id = big_callback_new(item_obtain_delete_text, 0);
	big_callbacks[delete_tb_cb_id].params[0] = item_obtain_tb_id;
	big_callbacks[delete_tb_cb_id].params[1] = 0;

	// Delete the oam
	u16 oam_id = item_obtain_oam_id;
	u8 delete_oam_cb_id = big_callback_new(item_obtain_delete_oam, 0);
	big_callbacks[delete_oam_cb_id].params[0] = oam_id;
	big_callbacks[delete_oam_cb_id].params[1] = 0;
	// Move the oam offscreen meanwhile
	oams[oam_id].x2 = -32;
}