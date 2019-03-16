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
#include "pokemon/names.h"
#include "debug.h"
#include "list_menu.h"
#include "multichoice.h"
#include "music.h"
#include "math.h"

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

graphic graphic_river_puzzle_cursor = {
    .sprite = gfx_river_puzzle_cursorTiles, .tag = RIVER_PUZZLE_CURSOR_TAG, .size = 16 * 16 / 2
};

graphic graphic_river_puzzle_pokemons[] = {
    [RIVER_PUZZLE_WIGGLYTUFF] = {.sprite = &gfx_river_puzzle_wigglytuff_lineTiles[0], .tag = 0,
        .size = 0x200},
    [RIVER_PUZZLE_IGGLYTUFF] = {.sprite = &gfx_river_puzzle_wigglytuff_lineTiles[128], .tag = 0,
        .size = 0x200},
    [RIVER_PUZZLE_ELECTRIVIRE] = {.sprite = &gfx_river_puzzle_electrivire_lineTiles[0], .tag = 0,
        .size = 0x200},
    [RIVER_PUZZLE_ELEKID] = {.sprite = &gfx_river_puzzle_electrivire_lineTiles[128], .tag = 0,
        .size = 0x200},
    [RIVER_PUZZLE_MAGMORTAR] = {.sprite = &gfx_river_puzzle_magmortar_lineTiles[0], .tag = 0,
        .size = 0x200},
    [RIVER_PUZZLE_MAGBY] = {.sprite = &gfx_river_puzzle_magmortar_lineTiles[128], .tag = 0,
        .size = 0x200},
};

sprite sprite_river_puzzle_boat = {
    .attr0 = ATTR0_SHAPE_HORIZONTAL, .attr1 = ATTR1_SIZE_64_32, .attr2 = ATTR2_PRIO(1)
};

sprite sprite_river_puzzle_pokemon = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(1)
};

sprite sprite_river_puzzle_cursor = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(1)
};

gfx_frame gfx_anim_river_puzzle_pokemon[] = {{.data = 0, .duration = 0}, {.data = GFX_ANIM_END}};
gfx_frame *gfx_anim_table_river_puzzle_pokemon[] = {
    gfx_anim_river_puzzle_pokemon
};

oam_template oam_template_river_puzzle_boat = {
    .tiles_tag = RIVER_PUZZLE_BOAT_TAG, .pal_tag = RIVER_PUZZLE_BOAT_TAG, .graphics = NULL,
    .oam = &sprite_river_puzzle_boat, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

oam_template oam_template_river_puzzle_pokemons[] = {
    [RIVER_PUZZLE_WIGGLYTUFF] = {
        .tiles_tag = 0xFFFF, .pal_tag = RIVER_PUZZLE_POKEMON_TAG + RIVER_PUZZLE_WIGGLYTUFF_LINE,
        .graphics = &graphic_river_puzzle_pokemons[RIVER_PUZZLE_WIGGLYTUFF],
        .oam = &sprite_river_puzzle_pokemon, .animation = gfx_anim_table_river_puzzle_pokemon,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
    }, [RIVER_PUZZLE_IGGLYTUFF] = {
        .tiles_tag = 0xFFFF, .pal_tag = RIVER_PUZZLE_POKEMON_TAG + RIVER_PUZZLE_WIGGLYTUFF_LINE,
        .graphics = &graphic_river_puzzle_pokemons[RIVER_PUZZLE_IGGLYTUFF],
        .oam = &sprite_river_puzzle_pokemon, .animation = gfx_anim_table_river_puzzle_pokemon,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
    }, [RIVER_PUZZLE_ELECTRIVIRE] = {
        .tiles_tag = 0xFFFF, .pal_tag = RIVER_PUZZLE_POKEMON_TAG + RIVER_PUZZLE_ELECTRIVIRE_LINE,
        .graphics = &graphic_river_puzzle_pokemons[RIVER_PUZZLE_ELECTRIVIRE],
        .oam = &sprite_river_puzzle_pokemon, .animation = gfx_anim_table_river_puzzle_pokemon,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
    }, [RIVER_PUZZLE_ELEKID] = {
        .tiles_tag = 0xFFFF, .pal_tag = RIVER_PUZZLE_POKEMON_TAG + RIVER_PUZZLE_ELECTRIVIRE_LINE,
        .graphics = &graphic_river_puzzle_pokemons[RIVER_PUZZLE_ELEKID],
        .oam = &sprite_river_puzzle_pokemon, .animation = gfx_anim_table_river_puzzle_pokemon,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
    }, [RIVER_PUZZLE_MAGMORTAR] = {
        .tiles_tag = 0xFFFF, .pal_tag = RIVER_PUZZLE_POKEMON_TAG + RIVER_PUZZLE_MAGMORTAR_LINE,
        .graphics = &graphic_river_puzzle_pokemons[RIVER_PUZZLE_MAGMORTAR],
        .oam = &sprite_river_puzzle_pokemon, .animation = gfx_anim_table_river_puzzle_pokemon,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
    }, [RIVER_PUZZLE_MAGBY] = {
        .tiles_tag = 0xFFFF, .pal_tag = RIVER_PUZZLE_POKEMON_TAG + RIVER_PUZZLE_MAGMORTAR_LINE,
        .graphics = &graphic_river_puzzle_pokemons[RIVER_PUZZLE_MAGBY],
        .oam = &sprite_river_puzzle_pokemon, .animation = gfx_anim_table_river_puzzle_pokemon,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
    }
};

void river_puzzle_cursor_callback(oam_object *self) {
  int frame = (self->private[0]++) << 11;
  int dy = 2 * FIXED_SIN(frame);
  self->y2 = (s16)(FIXED_TO_INT(dy));
}

oam_template oam_template_river_puzzle_cursor = {
    .tiles_tag = RIVER_PUZZLE_CURSOR_TAG, .pal_tag = RIVER_PUZZLE_CURSOR_TAG, .graphics = NULL,
    .oam = &sprite_river_puzzle_cursor, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = river_puzzle_cursor_callback
};

u8 river_puzzle_str_yes[] = LANGDEP(PSTRING("Ja"), PSTRING("Yes"));
u8 river_puzzle_str_no[] = LANGDEP(PSTRING("Nein"), PSTRING("No"));

list_menu_item river_puzzle_list_items_yes_no[] = {
    {.idx = 1, .text = river_puzzle_str_yes},
    {.idx = 2, .text = river_puzzle_str_no}
};

list_menu_template river_puzzle_list_template_yes_no = {
    .items = river_puzzle_list_items_yes_no,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = incubator_context_menu_item_print_callback,
    .item_cnt = 2, .max_items_showed = 2, .tbox_idx = RIVER_PUZZLE_TBOX_LIST,
    .header_x = 0, .item_x = 8, .cursor_x = 0, .up_text_x = 0, .cursor_pal = 2, .fill_value = 1,
    .cursor_shadow_color = 3, .letter_spacing = 1, .item_vertical_padding = 2, .scroll_multiple = 0,
    .font = 2
};

u16 river_puzzle_species[6] = {
    POKEMON_KNUDDELUFF, POKEMON_FLUFFELUFF, POKEMON_ELEVOLTEK, POKEMON_ELEKTEK, POKEMON_MAGBRANT,
    POKEMON_MAGMAR
};

void river_puzzle_locate(int side, int idx, s16 *x, s16 *y) {
  if (idx < 6) {
    // Land
    int x_offset = 24 + 16 * (idx & RIVER_PUZZLE_BABY_POKEMON);
    *x = (s16)((side == RIVER_PUZZLE_WEST) ? x_offset : 240 - x_offset);
    *y = (s16)(48 + 24 * (idx / 2));
  } else {
    // Boat
    int x_offset = 68 + 22 * (idx - 6);
    *x = (s16)((side == RIVER_PUZZLE_WEST) ? x_offset : 240 - x_offset);
    *y = 60;
  }
}

void river_puzzle_locate_cursor() {
  oam_object *cursor_oam = &oams[RIVER_PUZZLE_STATE->cursor_oam];
  river_puzzle_locate(RIVER_PUZZLE_STATE->cursor_side, RIVER_PUZZLE_STATE->cursor, &(cursor_oam->x),
      &(cursor_oam->y));
  cursor_oam->y = (s16)(cursor_oam->y - 20);
}

void river_puzzle_callback_exit(u8 self) {
  if (!fading_is_active()) {
    tbox_free_all();
    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    free(bg_get_tilemap(3));
    free(fmem.gp_state);
    callback1_set(map_reload);
    big_callback_delete(self);
  }
}

void river_puzzle_callback_confirm_exit_handle_list(u8 self) {
  int item = list_menu_process_input(RIVER_PUZZLE_STATE->callback_idx_list);
  if (item == LIST_MENU_NOTHING_CHOSEN) return;
  if (item == LIST_MENU_B_PRESSED || item == 1 || item == 2) {
    play_sound(5);
    list_menu_remove(RIVER_PUZZLE_STATE->callback_idx_list, NULL, NULL);
    tbox_flush_set(RIVER_PUZZLE_TBOX_LIST, 0);
    tbox_border_flush(RIVER_PUZZLE_TBOX_LIST);
    tbox_remove_dialog(RIVER_PUZZLE_TBOX_MESSAGE, false);
    bg_virtual_sync(0);
    if (item == 1) {
      fadescreen_all(1, 0);
      big_callbacks[self].function = river_puzzle_callback_exit;
    } else {
      big_callbacks[self].function = river_puzzle_callback_idle;
    }
  }
}

void river_puzzle_callback_confirm_exit(u8 self) {
  gp_list_menu_template = river_puzzle_list_template_yes_no;
  tbox_tilemap_draw(RIVER_PUZZLE_TBOX_LIST);
  tbox_border_draw(RIVER_PUZZLE_TBOX_LIST, RIVER_PUZZLE_UI_NUM_TILES, 14);
  RIVER_PUZZLE_STATE->callback_idx_list = list_menu_new(&gp_list_menu_template,
      0, 0);
  bg_virtual_sync(0);
  big_callbacks[self].function = river_puzzle_callback_confirm_exit_handle_list;
}

void river_puzzle_callback_remove_dialog_and_return_to_idle(u8 self) {
  tbox_remove_dialog(RIVER_PUZZLE_TBOX_MESSAGE, true);
  big_callbacks[self].function = river_puzzle_callback_idle;
}

int river_puzzle_pokemon_in_boat() {
  int pokemon_in_boat = 0;
  for (int i = 0; i < 6; i++) {
    if (RIVER_PUZZLE_STATE->pokemon[i] == RIVER_PUZZLE_BOAT_WEST ||
        RIVER_PUZZLE_STATE->pokemon[i] == RIVER_PUZZLE_BOAT_EAST) pokemon_in_boat++;
  }
  return pokemon_in_boat;
}

bool river_puzzle_pokemon_on_same_side(u8 i, u8 j) {
  if (RIVER_PUZZLE_STATE->pokemon[i] == RIVER_PUZZLE_BOAT_WEST ||
      RIVER_PUZZLE_STATE->pokemon[i] == RIVER_PUZZLE_BOAT_EAST) {
    return RIVER_PUZZLE_STATE->pokemon[j] == RIVER_PUZZLE_BOAT_WEST ||
        RIVER_PUZZLE_STATE->pokemon[j] == RIVER_PUZZLE_BOAT_EAST;
  }
  return RIVER_PUZZLE_STATE->pokemon[i] == RIVER_PUZZLE_STATE->pokemon[j];
}

bool river_puzzle_configuration_valid(u8 *invalid_baby, u8 *cause) {
  // For all babies check if they are afraid
  for (u8 i = 0; i < 6; i++) {
    if (i & RIVER_PUZZLE_BABY_POKEMON) {
      u8 parent = 255;
      u8 hostile_adult = 255;
      for (u8 j = 0; j < 6; j++) {
        // Check if any of the other pokemon on the same side
        if (river_puzzle_pokemon_on_same_side(i, j)) {
          if (!(j & RIVER_PUZZLE_BABY_POKEMON)) {
            if (i / 2 == j / 2)
              parent = j;
            else if (hostile_adult == 255)
              hostile_adult = j;
          }
        }
      }
      if (parent == 255 || hostile_adult != 255) {
        *invalid_baby = i;
        *cause = hostile_adult;
        return false;
      }
    }
  }
  return true;
}

void river_puzzle_draw_context_information() {
  tbox_flush_set(RIVER_PUZZLE_TBOX_CONTEXT, 0x44);
  tbox_tilemap_draw(RIVER_PUZZLE_TBOX_CONTEXT);
  u8 str_into_boat[] = LANGDEP(PSTRING("KEY_AIns Boot  "), PSTRING("KEY_AInto Boat  "));
  u8 str_general_context[] = LANGDEP(PSTRING("KEY_BAbbrechen  KEY_STARTHilfe"),
      PSTRING("KEY_BAbort  KEY_STARTHelp"));
  u8 str_from_boat[] = LANGDEP(PSTRING("KEY_AVom Boot  "), PSTRING("KEY_AFrom Boat  "));
  u8 str_departure[] = LANGDEP(PSTRING("KEY_SELECTAbfahrt  "), PSTRING("KEY_SELECTDeparture  "));
  u8 str_none[] = PSTRING("");
  strcpy(strbuf, str_none);
  if (RIVER_PUZZLE_STATE->cursor < 6) {
    // Selected pokemon on land
    if (river_puzzle_pokemon_in_boat() < 2) strcat(strbuf, str_into_boat);
  } else {
    // Selected pokemon in boat
    if (river_puzzle_pokemon_in_boat() > 0) strcat(strbuf, str_departure);
    for (int i = 0; i < 6; i++) {
      if (RIVER_PUZZLE_STATE->pokemon[i] == RIVER_PUZZLE_STATE->cursor)
        strcat(strbuf, str_from_boat);
    }
  }
  strcat(strbuf, str_general_context);
  tbox_print_string(RIVER_PUZZLE_TBOX_CONTEXT, 2, 0, 0, 0, 0,
      &river_puzzle_font_colmap_std, 0, strbuf);
}

void river_puzzle_cursor_move_right() {
  if (RIVER_PUZZLE_STATE->cursor < 7) {
    if (RIVER_PUZZLE_STATE->cursor < 6 &&
        (RIVER_PUZZLE_STATE->cursor & RIVER_PUZZLE_BABY_POKEMON)) {
      RIVER_PUZZLE_STATE->cursor = 6;
      river_puzzle_draw_context_information();
    } else {
      RIVER_PUZZLE_STATE->cursor++;
    }
    river_puzzle_locate_cursor();
    play_sound(5);
  }
}

void river_puzzle_cursor_move_left() {
  if (RIVER_PUZZLE_STATE->cursor > 0) {
    if (RIVER_PUZZLE_STATE->cursor == 6) {
      RIVER_PUZZLE_STATE->cursor = 3;
      river_puzzle_draw_context_information();
    } else if (RIVER_PUZZLE_STATE->cursor > 6 ||
        (RIVER_PUZZLE_STATE->cursor & RIVER_PUZZLE_BABY_POKEMON)) {
      RIVER_PUZZLE_STATE->cursor--;
    }
    river_puzzle_locate_cursor();
    play_sound(5);
  }
}

void river_puzzle_callback_idle(u8 self) {
  if (big_callbacks[self].params[0]) {
    big_callbacks[self].params[0]--;
    return;
  }
  if (!fading_is_active()) {
    // Process keys
    if (super.keys_new.keys.start) {
      // Print help
      tbox_print_string_and_continue(self, RIVER_PUZZLE_TBOX_MESSAGE,
          RIVER_PUZZLE_UI_NUM_TILES + TBOX_CONTEXT_BORDER_NUM_TILES, 15, 2, tbox_get_set_speed(),
          str_river_puzzle_help, river_puzzle_callback_remove_dialog_and_return_to_idle);
    } else if (super.keys_new.keys.B) {
      // Print exit message and ask for confirmation
      tbox_print_string_and_continue(self, RIVER_PUZZLE_TBOX_MESSAGE,
          RIVER_PUZZLE_UI_NUM_TILES + TBOX_CONTEXT_BORDER_NUM_TILES, 15, 2, tbox_get_set_speed(),
          str_river_puzzle_confirm_exit, river_puzzle_callback_confirm_exit);
    } else if (super.keys_new.keys.down && RIVER_PUZZLE_STATE->cursor / 2 < 2) {
      RIVER_PUZZLE_STATE->cursor = (u8)(RIVER_PUZZLE_STATE->cursor + 2);
      river_puzzle_locate_cursor();
      play_sound(5);
    } else if (super.keys_new.keys.up && RIVER_PUZZLE_STATE->cursor / 2 < 3 &&
        RIVER_PUZZLE_STATE->cursor / 2 > 0) {
      RIVER_PUZZLE_STATE->cursor = (u8)(RIVER_PUZZLE_STATE->cursor - 2);
      river_puzzle_locate_cursor();
      play_sound(5);
    } else if (super.keys_new.keys.left) {
      if (RIVER_PUZZLE_STATE->cursor_side == RIVER_PUZZLE_WEST) {
        river_puzzle_cursor_move_left();
      } else {
        river_puzzle_cursor_move_right();
      }
    } else if (super.keys_new.keys.right) {
      if (RIVER_PUZZLE_STATE->cursor_side == RIVER_PUZZLE_WEST) {
        river_puzzle_cursor_move_right();
      } else {
        river_puzzle_cursor_move_left();
      }
    } else if (super.keys_new.keys.A) {
      if (RIVER_PUZZLE_STATE->cursor < 6 && river_puzzle_pokemon_in_boat() < 2) {
        // Try a configuration where the current pokemon is in the boat
        u8 side_old = RIVER_PUZZLE_STATE->pokemon[RIVER_PUZZLE_STATE->cursor];
        u8 side_new = RIVER_PUZZLE_BOAT_WEST;
        for (u8 i = 0; i < 6; i++) {
          if (RIVER_PUZZLE_STATE->pokemon[i] == RIVER_PUZZLE_BOAT_WEST)
            side_new = RIVER_PUZZLE_BOAT_EAST;
        }
        RIVER_PUZZLE_STATE->pokemon[RIVER_PUZZLE_STATE->cursor] = side_new;
        u8 invalid_baby = 0, cause = 0;
        if (!river_puzzle_configuration_valid(&invalid_baby, &cause)) {
          RIVER_PUZZLE_STATE->pokemon[RIVER_PUZZLE_STATE->cursor] = side_old;
          // Print error string
          strcpy(buffer0, pokemon_names[river_puzzle_species[invalid_baby]]);
          strcpy(buffer1, pokemon_names[river_puzzle_species[cause]]);
          tbox_print_string_and_continue(self, RIVER_PUZZLE_TBOX_MESSAGE,
              RIVER_PUZZLE_UI_NUM_TILES + TBOX_CONTEXT_BORDER_NUM_TILES, 15, 2,
              tbox_get_set_speed(), str_river_puzzle_invalid_configuration,
              river_puzzle_callback_remove_dialog_and_return_to_idle);
        }
        play_sound(5);

      }
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
  u8 callback_idx = big_callback_new(river_puzzle_callback_idle, 0);
  big_callbacks[callback_idx].params[0] = 0; // Delay
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
  generic_callback1();
  if (!fading_is_active()) {
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
    oam_load_graphic(&graphic_river_puzzle_cursor);

    // Load palettes
    pal_decompress(gfx_river_puzzle_uiPal, 13 * 16, 32);
    pal_copy(map_footer_22_river_puzzle.tileset1->colors, 0, 7 * 16);
    pal_decompress(gfx_river_puzzle_boatPal,
        (u16)(16 * (16 + oam_allocate_palette(RIVER_PUZZLE_BOAT_TAG))), 32);
    pal_set_all_to_black();
    pal_decompress(gfx_river_puzzle_wigglytuff_linePal,
        (u16)(16 * (16 + oam_allocate_palette(
            RIVER_PUZZLE_POKEMON_TAG + RIVER_PUZZLE_WIGGLYTUFF_LINE))), 32);
    pal_decompress(gfx_river_puzzle_electrivire_linePal,
        (u16)(16 * (16 + oam_allocate_palette(
            RIVER_PUZZLE_POKEMON_TAG + RIVER_PUZZLE_ELECTRIVIRE_LINE))), 32);
    pal_decompress(gfx_river_puzzle_magmortar_linePal,
        (u16)(16 * (16 + oam_allocate_palette(
            RIVER_PUZZLE_POKEMON_TAG + RIVER_PUZZLE_MAGMORTAR_LINE))), 32);
    pal_decompress(gfx_river_puzzle_cursorPal, (u16)(16 * (16 + oam_allocate_palette(
            RIVER_PUZZLE_CURSOR_TAG))), 32);
    pal_set_all_to_black();


    RIVER_PUZZLE_STATE->boat_oam = oam_new_forward_search(&oam_template_river_puzzle_boat,
        80, 80, 7);
    for (int i = 0; i < 6; i++) {
      RIVER_PUZZLE_STATE->pokemon_oams[i] = oam_new_forward_search(
          &oam_template_river_puzzle_pokemons[i], 0, 0, (u8)(7 - i - 1));
      oam_object *pokemon_oam = &oams[RIVER_PUZZLE_STATE->pokemon_oams[i]];
      river_puzzle_locate(RIVER_PUZZLE_STATE->cursor_side, i, &pokemon_oam->x, &pokemon_oam->y);
    }
    RIVER_PUZZLE_STATE->cursor_oam = oam_new_forward_search(&oam_template_river_puzzle_cursor,
        0, 0, 0);
    river_puzzle_locate_cursor();

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
}

void river_puzzle_initialize() {
  fmem.gp_state = malloc_and_clear(sizeof(river_puzzle_state_t));
  RIVER_PUZZLE_STATE->cursor = 0;
  RIVER_PUZZLE_STATE->cursor_side = RIVER_PUZZLE_WEST;
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
    [RIVER_PUZZLE_TBOX_LIST] = {.bg_id = 0, .x = 20, .y = 9, .w = 8, .h = 4, .pal = 14,
        .start_tile = RIVER_PUZZLE_TBOX_START_TILE + 36 + 56 + 26 * 4},
    {.bg_id = 255},
};
