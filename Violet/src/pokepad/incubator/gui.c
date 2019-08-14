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
#include "pokemon/sprites.h"
#include "language.h"
#include "pokemon/virtual.h"
#include "constants/pokemon_attributes.h"
#include "pokemon/basestat.h"
#include "music.h"
#include "vars.h"
#include "overworld/pokemon_party_menu.h"
#include "data_structures.h"
#include "math.h"
#include "constants/vars.h"

sprite oam_sprite_incubator_egg = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_64_64,
    .attr2 = ATTR2_PRIO(2)};

sprite oam_sprite_incubator_progress_bar = {.attr0 = ATTR0_SHAPE_HORIZONTAL,
    .attr1 = ATTR1_SIZE_32_8, .attr2 = ATTR2_PRIO(2)};

sprite oam_sprite_incubator_egg_icon = {.attr0 = ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE,
    .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(1)
};

sprite oam_sprite_incubator_selection = {.attr0 = ATTR0_SHAPE_HORIZONTAL,
    .attr1 = ATTR1_SIZE_32_64, .attr2 = ATTR2_PRIO(1)};

graphic graphic_incubator_progress_bar = {.size = (32 * 8 / 2),
    .tag = INCUBATOR_EGG_PROGRESS_TAG, .sprite = gfx_incubator_progress_barTiles
};

graphic graphic_incubator_selection = {.size = (64 * 64 / 2),
    .tag = INCUBATOR_SELECTION_TAG_LEFT, .sprite = gfx_incubator_selectionTiles
};

gfx_frame gfx_animation_incubator_egg_icon[] = {
    {.data = 0, .duration = 16}, {.data = 16, .duration = 16},
    {.data = GFX_ANIM_JUMP, .duration = 0}
};

gfx_frame *gfx_animation_table_incubator_egg_icon[] = {
    gfx_animation_incubator_egg_icon
};

gfx_frame gfx_animation_incubator_selection_right[] = {
    {.data = 32, .duration = 0}, {.data = GFX_ANIM_END}
};

gfx_frame *gfx_animation_table_incubator_selection_right[] = {
    gfx_animation_incubator_selection_right
};

rotscale_frame rotscale_animation_incubator_egg_icon_none[] = {
    {.affine = {.affine_x_value = 0x100, .affine_y_value = 0x100, .duration = 0}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

rotscale_frame rotscale_animation_incubator_egg_icon_shrink[] = {
    {.affine = {.affine_x_value = 0x100, .affine_y_value = 0x100, .duration = 0}},
    {.affine = {.affine_x_value = -4, .affine_y_value = -4, .duration = 63}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

rotscale_frame rotscale_animation_incubator_egg_icon_expand[] = {
    {.affine = {.affine_x_value = 4, .affine_y_value = 4, .duration = 0}},
    {.affine = {.affine_x_value = 4, .affine_y_value = 4, .duration = 63}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

rotscale_frame *rotscale_animation_table_incubator_egg_icon[] = {
    rotscale_animation_incubator_egg_icon_none,
    rotscale_animation_incubator_egg_icon_shrink,
    rotscale_animation_incubator_egg_icon_expand
};

void incubator_oam_egg_callback(oam_object *self) {
  int frame = (self->private[0]++) << 10;
  int dy = 2 * FIXED_SIN(frame);
  self->y2 = (s16)(FIXED_TO_INT(dy));
}

oam_template oam_template_incubator_egg = {
    .oam = &oam_sprite_incubator_egg, .tiles_tag = INCUBATOR_EGG_TAG, .pal_tag = INCUBATOR_EGG_TAG,
    .callback = incubator_oam_egg_callback, .graphics = NULL, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null
};

oam_template oam_template_incubator_progress_bar = {
    .oam = &oam_sprite_incubator_progress_bar, .tiles_tag = INCUBATOR_EGG_PROGRESS_TAG,
    .pal_tag = INCUBATOR_EGG_PROGRESS_TAG,
    .callback = oam_null_callback, .graphics = NULL, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null
};

oam_template oam_template_incubator_egg_icon = {
    .oam = &oam_sprite_incubator_egg_icon, .tiles_tag = INCUBATOR_EGG_ICON_TAG,
    .pal_tag = INCUBATOR_EGG_ICON_TAG,
    .callback = oam_null_callback, .graphics = NULL,
    .animation = gfx_animation_table_incubator_egg_icon,
    .rotscale = rotscale_animation_table_incubator_egg_icon
};

oam_template oam_template_incubator_selection_left = {
    .oam = &oam_sprite_incubator_selection, .tiles_tag = INCUBATOR_SELECTION_TAG_LEFT,
    .pal_tag = INCUBATOR_SELECTION_TAG_LEFT, .callback = oam_null_callback, .graphics = NULL,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null
};

oam_template oam_template_incubator_selection_right = {
    .oam = &oam_sprite_incubator_selection, .tiles_tag = INCUBATOR_SELECTION_TAG_LEFT,
    .pal_tag = INCUBATOR_SELECTION_TAG_LEFT, .callback = oam_null_callback, .graphics = NULL,
    .animation = gfx_animation_table_incubator_selection_right,
    .rotscale = oam_rotscale_anim_table_null
};

bg_config incubator_bg_configs[4] = {
    {.bg_id = 0, .char_base = 2, .map_base = 29, .color_mode = 0, .priority = 0, .size = 0},
    {.bg_id = 1, .char_base = 1, .map_base = 30, .color_mode = 0, .priority = 1, .size = 0},
    {.bg_id = 2, .char_base = 0, .map_base = 31, .color_mode = 0, .priority = 2, .size = 0},
    {.bg_id = 3, .char_base = 3, .map_base = 28, .color_mode = 0, .priority = 3, .size = 0},
};

tbox_font_colormap incubator_font_colormap_std_light = {
    0, 1, 2, 3
};

list_menu_template incubator_context_menu_template = {
    .items = NULL,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = incubator_context_menu_item_print_callback,
    .item_cnt = 255, .max_items_showed = 255, .tbox_idx = 255,
    .header_x = 0, .item_x = 8, .cursor_x = 0, .up_text_x = 0, .cursor_pal = 2, .fill_value = 1,
    .cursor_shadow_color = 3, .letter_spacing = 1, .item_vertical_padding = 2, .scroll_multiple = 0,
    .font = 2
};

void incubator_context_menu_item_print_callback(u8 tbox_idx, int idx, u8 y) {
  (void)(tbox_idx);
  (void)(idx);
  (void)y;
}

void incubator_load_temperature() {
  u16 pixels = (u16)(((1000 - *var_access(HATCHING_BOOST_STEPS)) * INCUBATOR_TEMPERATURE_PIXELS)
      / 1000);
  io_set(IO_BGVOFS(3), (u16)(-pixels));
}

void incubator_load_selection() {
  for (int i = 0; i < 2; i++) {
    oams[fmem.incubator_state->oam_selection[i]].y = (s16)(8 *
        (6 + 4 * fmem.incubator_state->cursor_idx) + 12);
  }
}

void incubator_load_current_egg() {
  tbox_flush_set(INCUBATOR_TBOX_EGG, 0);
  tbox_tilemap_draw(INCUBATOR_TBOX_EGG);
  tbox_flush_set(INCUBATOR_TBOX_TYPES, 0);
  tbox_tilemap_draw(INCUBATOR_TBOX_TYPES);
  // Show name, types and oam only if there is an egg in this slot
  box_pokemon *current_pokemon = &cmem.incubator_slots[fmem.incubator_state->cursor_idx];
  int species = box_pokemon_get_attribute(current_pokemon, ATTRIBUTE_SPECIES, 0);
  if (species) {
    box_pokemon_get_attribute(current_pokemon, ATTRIBUTE_NICKNAME, strbuf);
    u8 str_egg_width = string_get_width(2, strbuf, 0);
    tbox_print_string(INCUBATOR_TBOX_EGG, 2,
        (u8)((incubator_tboxes[INCUBATOR_TBOX_EGG].w * 8 - str_egg_width) / 2), 2, 0, 0,
        &incubator_font_colormap_std_light, 0, strbuf);
    tbox_draw_type_icon_by_type_p1(INCUBATOR_TBOX_TYPES, (u8) (basestats[species].type1 + 1), 0, 3);
    if (basestats[species].type1 != basestats[species].type2) {
      tbox_draw_type_icon_by_type_p1(INCUBATOR_TBOX_TYPES, (u8) (basestats[species].type2 + 1),
          32, 3);
    }
    oams[fmem.incubator_state->oam_egg_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
  } else {
    oams[fmem.incubator_state->oam_egg_idx].flags |= OAM_FLAG_INVISIBLE;
    u8 str_none[] = PSTRING("");
    tbox_print_string(INCUBATOR_TBOX_EGG, 2, 0, 0, 0, 0,
        &incubator_font_colormap_std_light, 0, str_none);
  }
  u8 str_none[] = PSTRING("");
  tbox_print_string(INCUBATOR_TBOX_TYPES, 2, 0, 0, 0, 0,
      &incubator_font_colormap_std_light, 0, str_none);
}

void incubator_redraw_progress_bar(int slot) {
  // Edit the progress bars
  int egg_progress = incubator_egg_get_progress(&cmem.incubator_slots[slot]);
  for (int j = 0; j < 2; j++) {
    oams[fmem.incubator_state->oam_egg_progress_bars_idx[slot][j]].flags &=
        (u16)(~OAM_FLAG_INVISIBLE);
    // Draw grey veritcal lines onto the vram according to process
    u16 base_tile = oam_vram_get_tile((u16)(INCUBATOR_EGG_PROGRESS_TAG + 2 * slot + j));
    for (int k = 0; k < 4; k++) {
      int progress = MIN(8, MAX(0, egg_progress - j * 32 - 8 * k));
      // Keep only the first 8 - progress rows (i.e. bits in a tile line)
      u32 mask = (u32)(0xFFFFFFFF) >> (4 * (8 - progress));
      u32 over = (u32)(0x11111111) << (4 * progress);
      for (int l = 0; l < 8; l++) {
        // Clear vertical line l
        OAMCHARBASE(base_tile + k)[l] &= mask;
        OAMCHARBASE(base_tile + k)[l] |= over;
      }
    }
  }
}

void incubator_load_eggs() {
  // Clear background 1
  bg_text_tile *bg1_tilemap = (bg_text_tile*)bg_get_tilemap(1);
  lz77uncompwram(gfx_incubator_ui_glassMap, bg1_tilemap);
  // Buffer boxes
  bg_text_tile *box_tilemap = malloc(sizeof(bg_text_tile) * 14 * 3);
  lz77uncompwram(gfx_incubator_ui_boxMap, box_tilemap);
  for (int i = 0; i < 3; i++) {
    bool is_egg = box_pokemon_get_attribute(&cmem.incubator_slots[i], ATTRIBUTE_SPECIES, 0);
    if (i < incubator_available_slots()) {
      // Spawn the box for a potential egg
      for (int yy = 0; yy < 3; yy++) {
        for (int xx = 0; xx < 14; xx++) {
          bg_text_tile *tile = &bg1_tilemap[32 * (6 + 4 * i + yy) + xx + 10];
          *tile = box_tilemap[14 * yy + xx];
          tile->tile_number = (u16)((tile->tile_number + 64) & 0x3FF);
          if (!is_egg)
            tile->palette = 3;
        }
      }
      incubator_redraw_progress_bar(i);
    } else {
      // Hide progress bars
      for (int j = 0; j < 2; j++) {
        oams[fmem.incubator_state->oam_egg_progress_bars_idx[i][j]].flags |= OAM_FLAG_INVISIBLE;
      }
    }
    if (is_egg) {
      if (!(fmem.incubator_state->hide_current_egg_icon && fmem.incubator_state->cursor_idx == i))
        oams[fmem.incubator_state->oam_egg_icons_idx[i]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    } else {
      oams[fmem.incubator_state->oam_egg_icons_idx[i]].flags |= OAM_FLAG_INVISIBLE;
    }
  }
  bg_virtual_sync(1);
  free(box_tilemap);
}

void incubator_free_components() {
  tbox_free_all();
  free(bg_get_tilemap(0));
  free(bg_get_tilemap(1));
  free(bg_get_tilemap(2));
  free(bg_get_tilemap(3));
  free(fmem.incubator_state);

}

void incubator_callback1_return() {
    generic_callback1();
    if (!fading_is_active()) {
      if (fmem.incubator_state->from_outdoor) {
          callback1_set(map_reload);
      } else {
          callback1_set(pokepad_callback_init);
      }
      incubator_free_components();
    }
}

u8 str_incubator_into_party[] = LANGDEP(PSTRING("Ins Team"), PSTRING("Into Party"));
u8 str_incubator_into_box[] = LANGDEP(PSTRING("Auf Box"), PSTRING("To Box"));
u8 str_incubator_return[] = LANGDEP(PSTRING("Zurück"), PSTRING("Return"));
u8 str_incubator_from_party[] = LANGDEP(PSTRING("Vom Team"), PSTRING("From Party"));

list_menu_item incubator_context_menu_items_egg[3] = {
    {str_incubator_into_party, 1},
    {str_incubator_into_box, 2},
    {str_incubator_return, 3}
};

list_menu_item incubator_context_menu_items_empty[2] = {
    {str_incubator_from_party, 1},
    {str_incubator_return, 2},
};

void incubator_callback_delete_message_and_reload_egg(u8 self) {
  // Restore the text for the types
  tbox_remove_dialog(INCUBATOR_TBOX_MESSAGE, true);
  incubator_load_current_egg();
  big_callback_delete(self);
  callback1_set(incubator_callback1_idle);
}


void incubator_callback_delete_message_and_reload_egg_after_egg_icon_animation(u8 self) {
  if (!big_callback_is_active(incubator_callback_wait_for_egg_icon_animation))
    big_callbacks[self].function = incubator_callback_delete_message_and_reload_egg;
}

void incubator_callback_wait_for_egg_icon_animation(u8 self) {
  if (--big_callbacks[self].params[0] == 0) {
    u16 slot = big_callbacks[self].params[1];
    if (big_callbacks[self].params[2]) {
      oams[fmem.incubator_state->oam_egg_icons_idx[slot]].flags |=
          OAM_FLAG_INVISIBLE;
    }
    // Reset to no scaling
    oam_rotscale_anim_init(&oams[fmem.incubator_state->oam_egg_icons_idx[slot]], 0);
    big_callback_delete(self);
  }
}

void incubator_remove_egg_from_ui(int slot) {
  oam_rotscale_anim_init(&oams[fmem.incubator_state->oam_egg_icons_idx[slot]], 1);
  incubator_load_eggs();
  // Make the egg icon re-appear for its animation
  oams[fmem.incubator_state->oam_egg_icons_idx[slot]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
  if (fmem.incubator_state->cursor_idx == slot)
    oams[fmem.incubator_state->oam_egg_idx].flags |= OAM_FLAG_INVISIBLE;
  u8 callback_idx = big_callback_new(incubator_callback_wait_for_egg_icon_animation, 0);
  big_callbacks[callback_idx].params[0] = 64;
  big_callbacks[callback_idx].params[1] = (u16)(slot);
  big_callbacks[callback_idx].params[2] = true;
}

void incubator_callback_context_menu_egg(u8 self) {
  int item = list_menu_process_input(fmem.incubator_state->context_menu_callback_idx);
  if (item == LIST_MENU_NOTHING_CHOSEN) return;
  if (item == LIST_MENU_B_PRESSED || item == 3) {
    play_sound(5);
    list_menu_remove(fmem.incubator_state->context_menu_callback_idx, NULL, NULL);
    tbox_flush_set(INCUBATOR_TBOX_CONTEXT_MENU_EGG, 0);
    tbox_border_flush(INCUBATOR_TBOX_CONTEXT_MENU_EGG);
    bg_virtual_sync(0);
    callback1_set(incubator_callback1_idle);
    big_callback_delete(self);
  } else if (item == 1) {
    // Try to push it to the team
    list_menu_remove(fmem.incubator_state->context_menu_callback_idx, NULL, NULL);
    tbox_flush_set(INCUBATOR_TBOX_CONTEXT_MENU_EGG, 0);
    tbox_border_flush(INCUBATOR_TBOX_CONTEXT_MENU_EGG);
    box_pokemon *egg = &cmem.incubator_slots[fmem.incubator_state->cursor_idx];
    box_pokemon_get_attribute(egg, ATTRIBUTE_NICKNAME, buffer0);
    if (player_pokemon_cnt < 6) {
      pokemon *target = &player_pokemon[player_pokemon_cnt];
      incubator_remove_egg(fmem.incubator_state->cursor_idx, &target->box);
      pokemon_calculate_stats(target);
      player_pokemon_recount_pokemon();
      u8 str_sent_to_team[] = LANGDEP(
          PSTRING("BUFFER_1 wurde deinem\nTeam hinzugefügt.PAUSE_UNTIL_PRESS"),
          PSTRING("BUFFER_1 was added\nto your party.PAUSE_UNTIL_PRESS"));
      tbox_print_string_and_continue(self, INCUBATOR_TBOX_MESSAGE,
          1 + TBOX_CONTEXT_BORDER_NUM_TILES, 14, 2, tbox_get_set_speed(),
          str_sent_to_team,
          incubator_callback_delete_message_and_reload_egg_after_egg_icon_animation);
      incubator_remove_egg_from_ui(fmem.incubator_state->cursor_idx);
    } else {
      u8 str_no_space[] = LANGDEP(
          PSTRING("In deinem Team ist kein Platz\nfür BUFFER_1.PAUSE_UNTIL_PRESS"),
          PSTRING("There is no room for\nBUFFER_1 in your party.PAUSE_UNTIL_PRESS"));
      tbox_print_string_and_continue(self, INCUBATOR_TBOX_MESSAGE,
          1 + TBOX_CONTEXT_BORDER_NUM_TILES, 14, 2, tbox_get_set_speed(),
          str_no_space, incubator_callback_delete_message_and_reload_egg);
    }
  } else if (item == 2) {
    // Try to push it to a box
    list_menu_remove(fmem.incubator_state->context_menu_callback_idx, NULL, NULL);
    tbox_flush_set(INCUBATOR_TBOX_CONTEXT_MENU_EGG, 0);
    tbox_border_flush(INCUBATOR_TBOX_CONTEXT_MENU_EGG);
    box_pokemon *egg = &cmem.incubator_slots[fmem.incubator_state->cursor_idx];
    box_pokemon_get_attribute(egg, ATTRIBUTE_NICKNAME, buffer0);
    pokemon *tmp = malloc(sizeof(pokemon));
    memcpy(tmp, egg, sizeof(box_pokemon));
    pokemon_calculate_stats(tmp);
    int result = pokemon_to_box(tmp);
    if (result == 1) { // Success
      incubator_remove_egg(fmem.incubator_state->cursor_idx, NULL);
      u8 box_idx = (u8)(*var_access(0x8010));
      strcpy(buffer1, box_get_name(box_idx));
      u8 str_sent_to_box[] = LANGDEP(
          PSTRING("BUFFER_1 wurde an den\nPc gesendet.\pEs wurde in BUFFER_2 platziert."
              "PAUSE_UNTIL_PRESS"),
          PSTRING("BUFFER_1 was sent\nto the Pc.\pIt was placed in box BUFFER_2."
              "PAUSE_UNTIL_PRESS"));
      tbox_print_string_and_continue(self, INCUBATOR_TBOX_MESSAGE,
          1 + TBOX_CONTEXT_BORDER_NUM_TILES, 14, 2, tbox_get_set_speed(),
          str_sent_to_box,
          incubator_callback_delete_message_and_reload_egg_after_egg_icon_animation);
      incubator_remove_egg_from_ui(fmem.incubator_state->cursor_idx);
    } else {
      u8 str_no_space[] = LANGDEP(
          PSTRING("Auf dem Pc ist kein Platz\nfür BUFFER_1.PAUSE_UNTIL_PRESS"),
          PSTRING("There is no room for\nBUFFER_1 on your Pc.PAUSE_UNTIL_PRESS"));
      tbox_print_string_and_continue(self, INCUBATOR_TBOX_MESSAGE,
          1 + TBOX_CONTEXT_BORDER_NUM_TILES, 14, 2, tbox_get_set_speed(),
          str_no_space, incubator_callback_delete_message_and_reload_egg);
    }
    free(tmp);

  }
}

void incubator_callback_initialize_party_menu() {
  generic_callback1();
  if (!fading_is_active()) {
    gp_stack_push(fmem.incubator_state->from_outdoor);
    gp_stack_push(fmem.incubator_state->cursor_idx);
    incubator_free_components();
    pokemon_party_menu_init(3, 0, 0xB, 0, 0, sub_811FB5C,
        incubator_callback1_party_menu_continuation);
  }
}

void incubator_callback_context_menu_empty(u8 self) {
  int item = list_menu_process_input(fmem.incubator_state->context_menu_callback_idx);
  if (item == LIST_MENU_NOTHING_CHOSEN) return;
  if (item == LIST_MENU_B_PRESSED || item == 2) {
    play_sound(5);
    list_menu_remove(fmem.incubator_state->context_menu_callback_idx, NULL, NULL);
    tbox_flush_set(INCUBATOR_TBOX_CONTEXT_MENU_EMPTY, 0);
    tbox_border_flush(INCUBATOR_TBOX_CONTEXT_MENU_EMPTY);
    bg_virtual_sync(0);
    callback1_set(incubator_callback1_idle);
    big_callback_delete(self);
  } else if (item == 1) {
    list_menu_remove(fmem.incubator_state->context_menu_callback_idx, NULL, NULL);
    tbox_flush_set(INCUBATOR_TBOX_CONTEXT_MENU_EMPTY, 0);
    tbox_border_flush(INCUBATOR_TBOX_CONTEXT_MENU_EMPTY);
    fadescreen_all(1, 0);
    callback1_set(incubator_callback_initialize_party_menu);
  }
}

void incubator_callback1_party_menu_continuation() {
  fmem.incubator_state = malloc_and_clear(sizeof(incubator_state_stru));
  fmem.incubator_state->cursor_idx = (u8) gp_stack_pop();
  fmem.incubator_state->from_outdoor = (u8) gp_stack_pop();
  fmem.incubator_state->idle_callback = generic_callback1;
  box_pokemon *target = &cmem.incubator_slots[fmem.incubator_state->cursor_idx];
  u16 party_idx = *var_access(0x8004);
  dprintf("Selected party idx %d\n", party_idx);
  fmem.incubator_state->imported_party_idx = (u8) party_idx;
  if (party_idx < 6 && pokemon_get_attribute(&player_pokemon[party_idx],
      ATTRIBUTE_SANITY_HAS_SPECIES, 0) && !pokemon_get_attribute(&player_pokemon[party_idx],
      ATTRIBUTE_SANITY_IS_BAD_EGG, 0) && pokemon_get_attribute(&player_pokemon[party_idx],
      ATTRIBUTE_SANITY_IS_EGG, 0) && pokemon_get_attribute(&player_pokemon[party_idx],
      ATTRIBUTE_IS_EGG, 0) && box_pokemon_get_attribute(target, ATTRIBUTE_SPECIES, 0) == 0) {
    // Import the pokemon
    memcpy(target, &player_pokemon[party_idx], sizeof(box_pokemon));
    pokemon_clear(&player_pokemon[party_idx]);
    player_pokemon_compact();
    player_pokemon_recount_pokemon();
    fmem.incubator_state->hide_current_egg_icon = true;
  } else if (party_idx != 6 && party_idx != 7) {
    // Tried to import an invalid pokemon
    fmem.incubator_state->imported_party_idx = 255;
  }
  incubator_initialize_ui();
  big_callback_new(incubator_callback_pokemon_imported, 0);
}

void incubator_callback_pokemon_imported(u8 self) {
  if (!fading_is_active()) {
    if (fmem.incubator_state->imported_party_idx < 6) {
      u8 slot = fmem.incubator_state->cursor_idx;
      box_pokemon *egg = &cmem.incubator_slots[slot];
      box_pokemon_get_attribute(egg, ATTRIBUTE_NICKNAME, buffer0);
      oam_rotscale_anim_init(&oams[fmem.incubator_state->oam_egg_icons_idx[slot]], 2);
      oams[fmem.incubator_state->oam_egg_icons_idx[slot]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
      u8 str_placed_in_incubator[] = LANGDEP(
          PSTRING("BUFFER_1 wurde im Inkubator platizert.PAUSE_UNTIL_PRESS"),
          PSTRING("BUFFER_1 was placed in the incubator.PAUSE_UNTIL_PRESS"));
      tbox_print_string_and_continue(self, INCUBATOR_TBOX_MESSAGE,
          1 + TBOX_CONTEXT_BORDER_NUM_TILES, 14, 2, tbox_get_set_speed(),
          str_placed_in_incubator,
          incubator_callback_delete_message_and_reload_egg_after_egg_icon_animation);
      u8 callback_idx = big_callback_new(incubator_callback_wait_for_egg_icon_animation, 0);
      big_callbacks[callback_idx].params[0] = 64;
      big_callbacks[callback_idx].params[1] = (u16)(slot);
      big_callbacks[callback_idx].params[2] = false;
      fmem.incubator_state->hide_current_egg_icon = false;
    } else if (fmem.incubator_state->imported_party_idx == 255) {
      u8 str_only_eggs_can_be_placed[] = LANGDEP(
          PSTRING("Es können nur Eier im Inkubator\nplatziert werden.PAUSE_UNTIL_PRESS"),
          PSTRING("Only eggs can be placed in the\nincubator.PAUSE_UNTIL_PRESS"));
      tbox_print_string_and_continue(self, INCUBATOR_TBOX_MESSAGE,
          1 + TBOX_CONTEXT_BORDER_NUM_TILES, 14, 2, tbox_get_set_speed(),
          str_only_eggs_can_be_placed, incubator_callback_delete_message_and_reload_egg);
    } else {
      callback1_set(incubator_callback1_idle);
      big_callback_delete(self);
    }
  }
}

void incubator_callback1_idle() {
  generic_callback1();
  if (!fading_is_active()) {
    if (super.keys_new.keys.down &&
        fmem.incubator_state->cursor_idx < incubator_available_slots() - 1) {
      fmem.incubator_state->cursor_idx++;
      play_sound(5);
      incubator_load_current_egg();
      incubator_load_selection();
    } else if (super.keys_new.keys.up && fmem.incubator_state->cursor_idx > 0) {
      fmem.incubator_state->cursor_idx--;
      play_sound(5);
      incubator_load_current_egg();
      incubator_load_selection();
    } else if (super.keys_new.keys.B) {
      fadescreen_all(1, 0);
      play_sound(5);
      callback1_set(incubator_callback1_return);
    } else if (super.keys_new.keys.A) {
      // Trigger context menus
      gp_list_menu_template = incubator_context_menu_template;
      play_sound(5);
      if (box_pokemon_get_attribute(&cmem.incubator_slots[fmem.incubator_state->cursor_idx],
          ATTRIBUTE_SPECIES, 0)) {
        gp_list_menu_template.item_cnt = 3;
        gp_list_menu_template.max_items_showed = 3;
        gp_list_menu_template.tbox_idx = INCUBATOR_TBOX_CONTEXT_MENU_EGG;
        gp_list_menu_template.items = incubator_context_menu_items_egg;
        tbox_tilemap_draw(INCUBATOR_TBOX_CONTEXT_MENU_EGG);
        tbox_border_draw(INCUBATOR_TBOX_CONTEXT_MENU_EGG, 1, 13);
        fmem.incubator_state->context_menu_callback_idx = list_menu_new(&gp_list_menu_template,
            0, 0);
        bg_virtual_sync(0);
        big_callback_new(incubator_callback_context_menu_egg, 0);
        callback1_set(generic_callback1);
      } else {
        gp_list_menu_template.item_cnt = 2;
        gp_list_menu_template.max_items_showed = 2;
        gp_list_menu_template.tbox_idx = INCUBATOR_TBOX_CONTEXT_MENU_EMPTY;
        gp_list_menu_template.items = incubator_context_menu_items_empty;
        tbox_tilemap_draw(INCUBATOR_TBOX_CONTEXT_MENU_EMPTY);
        tbox_border_draw(INCUBATOR_TBOX_CONTEXT_MENU_EMPTY, 1, 13);
        fmem.incubator_state->context_menu_callback_idx = list_menu_new(&gp_list_menu_template,
            0, 0);
        bg_virtual_sync(0);
        big_callback_new(incubator_callback_context_menu_empty, 0);
        callback1_set(generic_callback1);
      }
    }
  }
}

void incubator_callback1_show() {
  incubator_load_eggs();
  bg_sync_display_and_show(0);
  bg_sync_display_and_show(1);
  bg_sync_display_and_show(2);
  bg_sync_display_and_show(3);
  bg_display_sync();
  fadescreen_all(0, 0);
  io_set(IO_WIN0H, IO_WINH(0, 80));
  io_set(IO_WIN1H, IO_WINH(0, 255));
  io_set(IO_WIN0V, IO_WINV(0, 255));
  io_set(IO_WIN1V, IO_WINV(0, 255));
  // Window 1 contains every layer except fx, Window 0 contians every layer and fx
  io_set(IO_WININ, IO_WININOUT_OBJ(0) |
      IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) | IO_WININOUT_BG(0, 3) |
      IO_WININOUT_BG(1, 0) | IO_WININOUT_BG(1, 1) | IO_WININOUT_BG(1, 2) | IO_WININOUT_BG(1, 3) |
      IO_WININOUT_OBJ(1) | IO_WININOUT_FX(0));
  io_set(IO_WINOUT, IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(1, 0));
  io_set(IO_BLDCNT, IO_BLDCNT_ALPHA_BLENDING | IO_BLDCNT_BG1_FIRST | IO_BLDCNT_OBJ_SECOND |
      IO_BLDCNT_BG0_SECOND | IO_BLDCNT_BG1_SECOND | IO_BLDCNT_BG2_SECOND | IO_BLDCNT_BG3_SECOND);
  io_set(IO_BLDALPHA, IO_BLDALPHA_EVA(7) | IO_BLDALPHA_EVB(11));
  callback1_set(fmem.incubator_state->idle_callback);
}

void incubator_initialize_ui() {
  oam_reset();
  big_callback_delete_all();
  fading_cntrl_reset();
  oam_palette_allocation_reset();
  dma0_reset_callback();
  vblank_handler_set(NULL);
  bg_reset(0);
  io_set(IO_DISPCNT, IO_DISPCNT_H_BANK_INTERVAL_OBJ_PROCESSING |
      IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL | IO_DISPCNT_BG(0) | IO_DISPCNT_BG(1) |
      IO_DISPCNT_BG(2) | IO_DISPCNT_BG(3) | IO_DISPCNT_OBJ | IO_DISPCNT_WIN0 | IO_DISPCNT_WIN1);
  io_set(IO_BGHOFS(0), 0);
  io_set(IO_BGVOFS(0), 0);
  io_set(IO_BGHOFS(1), 0);
  io_set(IO_BGVOFS(1), 0);
  io_set(IO_BGHOFS(2), 0);
  io_set(IO_BGVOFS(2), 0);
  io_set(IO_BGHOFS(3), 0);
  incubator_load_temperature();
  bg_setup(0, incubator_bg_configs, 4);
  bg_set_tilemap(0, malloc_and_clear(0x800));
  bg_set_tilemap(1, malloc_and_clear(0x800));
  bg_set_tilemap(2, malloc_and_clear(0x800));
  bg_set_tilemap(3, malloc_and_clear(0x800));

  tbox_sync_with_virtual_bg_and_init_all(incubator_tboxes);
  tbox_context_init_border_set_style(INCUBATOR_TBOX_MESSAGE, 1, 13 * 16);
  tbox_message_init(INCUBATOR_TBOX_MESSAGE, 1 + TBOX_CONTEXT_BORDER_NUM_TILES, 14 * 16);
  tbox_flush_set(INCUBATOR_TBOX_TITLE, 0);
  tbox_tilemap_draw(INCUBATOR_TBOX_TITLE);
  u8 str_title[] = LANGDEP(PSTRING("Inkubator"), PSTRING("Incubator"));
  u8 str_title_width = string_get_width(2, str_title, 0);
  tbox_print_string(INCUBATOR_TBOX_TITLE, 2,
      (u16)(incubator_tboxes[INCUBATOR_TBOX_TITLE].w * 8 - str_title_width) / 2, 4, 0, 0,
      &incubator_font_colormap_std_light, 0, str_title);

  lz77uncompwram(gfx_incubator_ui_0Map, bg_get_tilemap(2));
  lz77uncompwram(gfx_incubator_ui_1Map, bg_get_tilemap(3));
  lz77uncompvram(gfx_incubator_ui_0Tiles, CHARBASE(0));
  lz77uncompvram(gfx_incubator_ui_1Tiles, CHARBASE(3));
  lz77uncompvram(gfx_incubator_ui_glassTiles, CHARBASE(1));
  lz77uncompvram(gfx_incubator_ui_boxTiles, &CHARBASE(1)[8 * 64]); // 64 Tiles displacement for the box
  oam_load_graphic(&pokemon_frontsprites[POKEMON_EGG]);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      graphic g = graphic_incubator_progress_bar;
      g.tag = (u16)(INCUBATOR_EGG_PROGRESS_TAG + 2 * i + j);
      oam_load_graphic(&g);
    }
  }
  u16 oam_egg_icon_tile = oam_vram_alloc(32);
  oam_vram_allocation_table_add(INCUBATOR_EGG_ICON_TAG, oam_egg_icon_tile, 32);
  cpuset(pokemon_icons[POKEMON_EGG], OAMCHARBASE(oam_egg_icon_tile),
      CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(0x400));
  oam_load_graphic(&graphic_incubator_selection);

  // Load palettes
  pal_decompress(pokemon_pals[POKEMON_EGG].pal,
      (u16)(16 * (16 + oam_allocate_palette(INCUBATOR_EGG_TAG))), 32);
  for (int i = 0; i < 3; i++) {
    pal_decompress(gfx_incubator_progress_barPal,
        (u16)(16 * (16 + oam_allocate_palette((u16)(INCUBATOR_EGG_PROGRESS_TAG + i)))), 32);
  }
  pal_copy(icon_pals[pokemon_icon_usage[POKEMON_EGG]],
      (u16)(16 * (16 + oam_allocate_palette(INCUBATOR_EGG_ICON_TAG))), 32);
  pal_decompress(gfx_incubator_selectionPal,
      (u16)(16 * (16 + oam_allocate_palette(INCUBATOR_SELECTION_TAG_LEFT))), 32);
  pal_decompress(gfx_incubator_ui_0Pal, 0, 32);
  pal_decompress(gfx_incubator_ui_1Pal, 16, 32);
  pal_decompress(gfx_incubator_ui_boxPal, 32, 32);
  pal_decompress(gfx_incubator_ui_box_greyPal, 48, 32);
  pal_decompress(gfx_incubator_ui_glassPal, 64, 32);
  pal_copy(typechart_icon_pal, 12 * 16, 32);
  pal_set_all_to_black();

  fmem.incubator_state->oam_egg_idx = oam_new_forward_search(&oam_template_incubator_egg,
      5 * 8, 12 * 8 + 4, 0);
  oams[fmem.incubator_state->oam_egg_idx].flags |= OAM_FLAG_INVISIBLE;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      oam_template tmpl = oam_template_incubator_progress_bar;
      tmpl.pal_tag = (u16)(INCUBATOR_EGG_PROGRESS_TAG + i);
      tmpl.tiles_tag = (u16)(INCUBATOR_EGG_PROGRESS_TAG + 2 * i + j);
      fmem.incubator_state->oam_egg_progress_bars_idx[i][j] = oam_new_forward_search(
          &tmpl, (s16)(128 + j * 32), (s16)(60 + i * 32), 0);
      oams[fmem.incubator_state->oam_egg_progress_bars_idx[i][j]].flags |= OAM_FLAG_INVISIBLE;
    }
    fmem.incubator_state->oam_egg_icons_idx[i] = oam_new_forward_search(
        &oam_template_incubator_egg_icon, 96, (s16)(56 + i * 32), 0);
    oam_gfx_anim_init(&oams[fmem.incubator_state->oam_egg_icons_idx[i]], 0);
    oams[fmem.incubator_state->oam_egg_icons_idx[i]].flags |= OAM_FLAG_INVISIBLE;
  }
  fmem.incubator_state->oam_selection[0] = oam_new_forward_search(
      &oam_template_incubator_selection_left, 112, 0, 0);
  fmem.incubator_state->oam_selection[1] = oam_new_forward_search(
      &oam_template_incubator_selection_right, 112 + 64, 0, 0);
  incubator_load_selection();

  incubator_load_current_egg();
  callback1_set(incubator_callback1_show);
  vblank_handler_set(generic_vblank_handler);

  bg_virtual_sync(0);
  bg_virtual_sync(1);
  bg_virtual_sync(2);
  bg_virtual_sync(3);
}

void incubator_callback1_initialize() {
  generic_callback1();
  if (!fading_is_active()) {
    if (fmem.dex_mem->from_outdoor) {
        overworld_free();
    } else {
        pokepad_free_components();
    }
    incubator_initialize_ui();
    fmem.incubator_state->idle_callback = incubator_callback1_idle;
  }
}

void incubator_initialize(bool from_outdoor) {
  fmem.incubator_state = malloc_and_clear(sizeof(incubator_state_stru));
  fmem.incubator_state->from_outdoor = from_outdoor;
  fadescreen_all(1, 0);
  callback1_set(incubator_callback1_initialize);
}

tboxdata incubator_tboxes[INCUBATOR_TBOX_CNT + 1] = {
  [INCUBATOR_TBOX_TITLE] = {.bg_id = 0, .x = 11, .y = 0, .w = 8, .h = 2, .pal = 14,
      .start_tile = INCUBATOR_TBOX_START_TILE},
  [INCUBATOR_TBOX_EGG] = {.bg_id = 0, .x = 3, .y = 3, .w = 4, .h = 2, .pal = 14,
      .start_tile = INCUBATOR_TBOX_START_TILE + 16},
  [INCUBATOR_TBOX_TYPES] = {.bg_id = 0, .x = 12, .y = 3, .w = 8, .h = 2, .pal = 12,
      .start_tile = INCUBATOR_TBOX_START_TILE + 24},
  [INCUBATOR_TBOX_CONTEXT_MENU_EGG] = {.bg_id = 0, .x = 20, .y = 13, .w = 9, .h = 6, .pal = 14,
      .start_tile = INCUBATOR_TBOX_START_TILE + 40},
  [INCUBATOR_TBOX_CONTEXT_MENU_EMPTY] = {.bg_id = 0, .x = 20, .y = 15, .w = 9, .h = 4, .pal = 14,
      .start_tile = INCUBATOR_TBOX_START_TILE + 40},
  [INCUBATOR_TBOX_MESSAGE] = {.bg_id = 0, .x = 2, .y = 15, .w = 26, .h = 4, .pal = 14,
      .start_tile = INCUBATOR_TBOX_START_TILE + 94},
  [INCUBATOR_TBOX_CNT] = {.bg_id = 255},
};

