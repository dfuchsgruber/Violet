/*
 * gui.c
 *
 *  Created on: Mar 7, 2019
 *      Author: dominik
 */

#include "types.h"
#include "text.h"
#include "save.h"
#include "callbacks.h"
#include "list_menu.h"
#include "language.h"
#include "superstate.h"
#include "debug.h"
#include "pokepad/incubator.h"
#include "agbmemory.h"
#include "fading.h"
#include "pokepad/gui.h"
#include "io.h"
#include "oam.h"
#include "dma.h"
#include "bg.h"
#include "bios.h"
#include "overworld/map_control.h"

bg_config incubator_bg_configs[3] = {
    {.bg_id = 0, .char_base = 2, .map_base = 29, .color_mode = 0, .priority = 0, .size = 0},
    {.bg_id = 1, .char_base = 1, .map_base = 30, .color_mode = 0, .priority = 1, .size = 0},
    {.bg_id = 2, .char_base = 0, .map_base = 31, .color_mode = 0, .priority = 2, .size = 0}
};

void incubator_callback1_idle() {
  generic_callback1();
}

void incubator_callback1_show() {
  bg_sync_display_and_show(0);
  bg_sync_display_and_show(1);
  bg_sync_display_and_show(2);
  bg_sync_display_and_show(3);
  bg_display_sync();
  callback1_set(incubator_callback1_idle);
}

void incubator_callback1_initialize() {
  generic_callback1();
  if (!fading_is_active()) {
    if (fmem.dex_mem->from_outdoor) {
        overworld_free();
    } else {
        pokepad_free_components();
    }
    io_set(IO_BLDCNT, 0);
    oam_reset();
    big_callback_delete_all();
    fading_cntrl_reset();
    oam_palette_allocation_reset();
    dma0_reset_callback();
    vblank_handler_set(NULL);
    bg_reset(0);
    bg_setup(0, incubator_bg_configs, 3);
    bg_set_tilemap(0, malloc_and_clear(0x800));
    bg_set_tilemap(1, malloc_and_clear(0x800));
    bg_set_tilemap(2, malloc_and_clear(0x800));

    lz77uncompwram(gfx_incubator_ui_0Map, bg_get_tilemap(2));
    lz77uncompvram(gfx_incubator_ui_0Tiles, CHARBASE(2));

    // Load palettes
    pal_decompress(gfx_incubator_ui_0Pal, 0, 32);
    pal_set_all_to_black();

    fadescreen_all(0, 0);
    callback1_set(incubator_callback1_show);
    vblank_handler_set(generic_vblank_handler);

    bg_virtual_sync(0);
    bg_virtual_sync(1);
    bg_virtual_sync(2);
  }
}

void incubator_initialize(bool from_outdoor) {
  fmem.incubator_state = malloc_and_clear(sizeof(incubator_state_stru));
  fmem.incubator_state->from_outdoor = from_outdoor;
  fadescreen_all(1, 0);
  callback1_set(incubator_callback1_initialize);
}

/**
u8 str_inc_test1[] = PSTRING("ASDF");
u8 str_inc_test2[] = PSTRING("xD");
u8 str_inc_test3[] = PSTRING("DOTS");

list_menu_item incubator_context_menu_items[3] = {
    {str_inc_test1, 0},
    {str_inc_test2, 1},
    {str_inc_test3, 2},
};

void incubator_context_menu_item_print_callback(u8 tbox_idx, int idx, u8 y) {
  (void)(tbox_idx);
  (void)(idx);
  (void)y;
}

list_menu_template incubator_context_menu_template = {
    .items = incubator_context_menu_items,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = incubator_context_menu_item_print_callback,
    .item_cnt = 3, .max_items_showed = 3, .tbox_idx = 255,
    .header_x = 0, .item_x = 8, .cursor_x = 0, .up_text_x = 0, .cursor_pal = 2, .fill_value = 1,
    .cursor_shadow_color = 3, .letter_spacing = 1, .item_vertical_padding = 0, .scroll_multiple = 0,
    .font = 2
};

void incubator_callback_test() {
  generic_callback1();
  int item = list_menu_process_input(cmem.unused[0]);
  if (item == LIST_MENU_NOTHING_CHOSEN) return;
  dprintf("Received item %d\n", item);
}

void incubator_initialize() {
  // Test
  // spawn a textbox
  tboxdata boxdata = {.bg_id = 0, .pal = 15, .w = 5, .h = 6, .x = 5, .y = 5,
      .start_tile = 1 + TBOX_CONTEXT_BORDER_NUM_TILES + TBOX_MESSAGE_NUM_TILES};
  u8 box_idx = tbox_new(&boxdata);
  tbox_context_init_border_set_style(box_idx, 1, 13 * 16);
  tbox_message_init(box_idx, 1 + TBOX_CONTEXT_BORDER_NUM_TILES, 14 * 16);
  // tbox_message_init_border(box_idx, 1 + 10, 15 * 16);

  tbox_tilemap_draw(box_idx);
  tbox_border_draw(box_idx, 1, 13);
  gp_list_menu_template = incubator_context_menu_template;
  gp_list_menu_template.tbox_idx = box_idx;
  cmem.unused[0] = list_menu_new(&gp_list_menu_template, 0, 0);
  bg_virtual_sync(0);
  callback1_set(incubator_callback_test);
}
**/
