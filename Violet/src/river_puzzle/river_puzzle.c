/*
 * river_puzzle.c
 *
 *  Created on: Mar 14, 2019
 *      Author: dominik
 */
#include "types.h"
#include "river_puzzle.h"
#include "fading.h"
#include "oam.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "language.h"
#include "map/tileset.h"
#include "io.h"
#include "dma.h"
#include "superstate.h"
#include "overworld/map_control.h"
#include "agbmemory.h"
#include "callbacks.h"
#include "bios.h"
#include "constants/species.h"

tbox_font_colormap river_puzzle_font_colmap_std = {
    4, 1, 2, 4
};

bg_config river_puzzle_bg_configs[4] = {
    {.bg_id = 0, .char_base = 2, .map_base = 31, .priority = 0, .size = 0, .color_mode = 0},
    {.bg_id = 1, .char_base = 2, .map_base = 30, .priority = 1, .size = 0, .color_mode = 0},
    {.bg_id = 2, .char_base = 0, .map_base = 29, .priority = 2, .size = 0, .color_mode = 0},
    {.bg_id = 3, .char_base = 0, .map_base = 28, .priority = 3, .size = 0, .color_mode = 0}
};

graphic graphic_river_puzzle_boat = {
    .sprite = gfx_river_puzzle_boatTiles, .tag = RIVER_PUZZLE_BOAT_TAG, .size = 64 * 32 / 2
};

graphic graphic_river_puzzle_wigglytuff[] = {
    {.sprite = &gfx_river_puzzle_wigglytuff_lineTiles[0], .tag = 0, .size = 16 * 32 / 2},
    {.sprite = &gfx_river_puzzle_wigglytuff_lineTiles[16 * 32 / 8], .tag = 0, .size = 16 * 32 / 2},
};

sprite sprite_river_puzzle_boat = {
    .attr0 = ATTR0_SHAPE_HORIZONTAL, .attr1 = ATTR1_SIZE_64_32, .attr2 = ATTR2_PRIO(1)
};

sprite sprite_river_puzzle_pokemon = {
    .attr0 = ATTR0_SHAPE_VERTICAL, .attr1 = ATTR1_SIZE_16_32, .attr2 = ATTR2_PRIO(1)
};

oam_template oam_template_river_puzzle_boat = {
    .tiles_tag = RIVER_PUZZLE_BOAT_TAG, .pal_tag = RIVER_PUZZLE_BOAT_TAG, .graphics = NULL,
    .oam = &sprite_river_puzzle_boat, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

oam_template oam_template_river_puzzle_wigglytuff = {
    .tiles_tag = 0xFFFF, .pal_tag = RIVER_PUZZLE_WIGGLYTUFF_LINE_TAG,
    .graphics = &graphic_river_puzzle_wigglytuff[0],
    .oam = &sprite_river_puzzle_pokemon, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

oam_template oam_template_river_puzzle_igglytuff = {
    .tiles_tag = 0xFFFF, .pal_tag = RIVER_PUZZLE_WIGGLYTUFF_LINE_TAG,
    .graphics = &graphic_river_puzzle_wigglytuff[1],
    .oam = &sprite_river_puzzle_pokemon, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

void river_puzzle_remove_dialog_and_return_to_idle(u8 self) {
  tbox_remove_dialog(RIVER_PUZZLE_TBOX_MESSAGE, true);
  big_callbacks[self].function = river_puzzle_callback_idle;
}

void river_puzzle_draw_context_information() {
  tbox_flush_set(RIVER_PUZZLE_TBOX_CONTEXT, 0x44);
  tbox_tilemap_draw(RIVER_PUZZLE_TBOX_CONTEXT);
  u8 str_context[] = LANGDEP(PSTRING("KEY_AIns Boot  KEY_BAbbrechen  KEY_STARTHilfe"),
      PSTRING("KEY_AInto Boat  KEY_BAbort  KEY_STARTHelp"));
  tbox_print_string(RIVER_PUZZLE_TBOX_CONTEXT, 2, 0, 0, 0, 0,
      &river_puzzle_font_colmap_std, 0, str_context);
}

void river_puzzle_callback_idle(u8 self) {
  (void)(self);
  if (!fading_is_active()) {
    // Process keys
    if (super.keys_new.keys.start) {
      // Print help
      tbox_print_string_and_continue(self, RIVER_PUZZLE_TBOX_MESSAGE,
          RIVER_PUZZLE_UI_NUM_TILES + TBOX_CONTEXT_BORDER_NUM_TILES, 15, 2, tbox_get_set_speed(),
          str_river_puzzle_help,
          river_puzzle_remove_dialog_and_return_to_idle);
    }
  }
}

void river_puzzle_callback1() {
  generic_callback1();
  tileset_anim_proceed();
}


void river_puzzle_callback1_show() {
  lz77uncompvram(map_footer_22_river_puzzle.tileset1->graphic, CHARBASE(0));
  bg_sync_display_and_show(0);
  bg_sync_display_and_show(1);
  bg_sync_display_and_show(2);
  bg_sync_display_and_show(3);
  bg_display_sync();
  fadescreen_all(0, 0);
  big_callback_new(river_puzzle_callback_idle, 0);
  callback1_set(river_puzzle_callback1);
}

void river_puzzle_compute_map() {
  bg_tile *bg3map = bg_get_tilemap(3);
  bg_tile *bg2map = bg_get_tilemap(2);
  int width = (int)map_footer_22_river_puzzle.width;
  int height = (int)map_footer_22_river_puzzle.height;
  bg_tile *blocks = map_footer_22_river_puzzle.tileset1->blocks;
  // Draw the background
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      u16 block_idx = map_footer_22_river_puzzle.map[y * width + x].block_id;
      // Render this block
      for (int i = 0; i < 8; i++) {
        int xx = i % 2;
        int yy = (i % 4) / 2;
        bg_tile *target = i < 4 ? bg3map : bg2map;
        target[32 * (3 + 2 * y + yy) + 2 * x + xx] = blocks[8 * block_idx + i];
      }
    }
  }
}

void river_puzzle_callback1_initialize() {
  overworld_free();
  oam_reset();
  big_callback_delete_all();
  fading_cntrl_reset();
  oam_palette_allocation_reset();
  dma0_reset_callback();
  vblank_handler_set(NULL);
  bg_reset(0);
  io_set(IO_BGHOFS(0), 0);
  io_set(IO_BGVOFS(0), 0);
  io_set(IO_BGHOFS(1), 0);
  io_set(IO_BGVOFS(1), 0);
  io_set(IO_BGHOFS(2), 0);
  io_set(IO_BGVOFS(2), 0);
  io_set(IO_BGHOFS(3), 0);
  io_set(IO_BGVOFS(3), 0);
  bg_setup(0, river_puzzle_bg_configs, 4);
  bg_set_tilemap(0, malloc_and_clear(0x800));
  bg_set_tilemap(1, malloc_and_clear(0x800));
  bg_set_tilemap(2, malloc_and_clear(0x800));
  bg_set_tilemap(3, malloc_and_clear(0x800));

  lz77uncompvram(gfx_river_puzzle_uiTiles, CHARBASE(2));
  lz77uncompwram(gfx_river_puzzle_uiMap, bg_get_tilemap(1));
  river_puzzle_compute_map();

  tbox_sync_with_virtual_bg_and_init_all(river_puzzle_tboxes);
  tbox_context_init_border_set_style(RIVER_PUZZLE_TBOX_MESSAGE, RIVER_PUZZLE_UI_NUM_TILES, 14 * 16);
  tbox_message_init(RIVER_PUZZLE_TBOX_MESSAGE,
      RIVER_PUZZLE_UI_NUM_TILES + TBOX_CONTEXT_BORDER_NUM_TILES, 15 * 16);
  tbox_flush_set(RIVER_PUZZLE_TBOX_TITLE, 0x44);
  tbox_tilemap_draw(RIVER_PUZZLE_TBOX_TITLE);
  u8 str_title[] = LANGDEP(PSTRING("Hilf den Pokémon!"),
      PSTRING("Help the Pokémon!"));
  u8 str_title_width = string_get_width(2, str_title, 0);
  tbox_print_string(RIVER_PUZZLE_TBOX_TITLE, 2,
      (u16)(river_puzzle_tboxes[RIVER_PUZZLE_TBOX_TITLE].w * 8 - str_title_width) / 2, 3, 0, 0,
      &river_puzzle_font_colmap_std, 0, str_title);
  river_puzzle_draw_context_information();

  oam_load_graphic(&graphic_river_puzzle_boat);

  // Load palettes
  pal_decompress(gfx_river_puzzle_uiPal, 13 * 16, 32);
  pal_copy(map_footer_22_river_puzzle.tileset1->colors, 0, 7 * 16);
  pal_decompress(gfx_river_puzzle_boatPal,
      (u16)(16 * (16 + oam_allocate_palette(RIVER_PUZZLE_BOAT_TAG))), 32);
  pal_set_all_to_black();
  pal_decompress(gfx_river_puzzle_wigglytuff_linePal,
      (u16)(16 * (16 + oam_allocate_palette(RIVER_PUZZLE_WIGGLYTUFF_LINE_TAG))), 32);
  pal_set_all_to_black();

  RIVER_PUZZLE_STATE->boat_oam = oam_new_forward_search(&oam_template_river_puzzle_boat,
      80, 80, 0);
  RIVER_PUZZLE_STATE->pokemon_oams[0] = oam_new_forward_search(
      &oam_template_river_puzzle_wigglytuff, 16, 40, 0);
  RIVER_PUZZLE_STATE->pokemon_oams[1] = oam_new_forward_search(&oam_template_river_puzzle_igglytuff,
      48, 40, 0);

  callback1_set(river_puzzle_callback1_show);
  vblank_handler_set(generic_vblank_handler);

  // Reinitialize the animation of only the first tileset
  tileset_anim_0 = NULL;
  tileset_anim_clk0 = 0;
  tileset_anim_clk0_cycle = 0;
  tileset_anim_1 = NULL;
  tileset_anim_clk1 = 0;
  tileset_anim_clk1_cycle = 0;
  map_footer_22_river_puzzle.tileset1->animation_init();

  bg_virtual_sync(0);
  bg_virtual_sync(1);
  bg_virtual_sync(2);
  bg_virtual_sync(3);
}

void river_puzzle_initialize() {
  fmem.gp_state = malloc_and_clear(sizeof(river_puzzle_state_t));
  fadescreen_all(1, 0);
  callback1_set(river_puzzle_callback1_initialize);
}

tboxdata river_puzzle_tboxes[RIVER_PUZZLE_TBOX_CNT + 1] = {
    [RIVER_PUZZLE_TBOX_TITLE] = {.bg_id = 1, .w = 18, .h = 2, .x = 6, .y = 0,
        .start_tile = RIVER_PUZZLE_TBOX_START_TILE , .pal = 13},
    [RIVER_PUZZLE_TBOX_CONTEXT] = {.bg_id = 1, .w = 28, .h = 2, .x = 1, .y = 18,
        .start_tile = RIVER_PUZZLE_TBOX_START_TILE + 36, .pal = 13},
    [RIVER_PUZZLE_TBOX_MESSAGE] = {.bg_id = 0, .x = 2, .y = 15, .w = 26, .h = 4, .pal = 15,
        .start_tile = RIVER_PUZZLE_TBOX_START_TILE + 36 + 56},
    {.bg_id = 255},
};
