#include "types.h"
#include "item/item.h"
#include "save.h"
#include "superstate.h"
#include "overworld/pokemon_party_menu.h"
#include "callbacks.h"
#include "music.h"
#include "item/item_effect.h"
#include "debug.h"
#include "oam.h"
#include "agbmemory.h"
#include "bios.h"
#include "data_structures.h"
#include "gpu.h"
#include "pokemon/basestat.h"

EWRAM item_candy_state_t item_candy_state = {0};

static void rare_candy_reset() {
    item_candy_state.rare_candy_exp_remaining = 0;
    item_candy_state.rare_candy_levels_remaining = 0;
    item_candy_state.rare_candy_item_removed = false;
}

void item_callback_rare_candy(u8 self, void (*exit_continuation)(u8)) {
    u8 party_idx = pokemon_party_menu_current_index;
    bool no_effect = true;
    if (pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_LEVEL, NULL) < 100) {
        no_effect = !item_effect(player_pokemon + party_idx, item_activated, party_idx, 0, false, true);
    }
    play_sound(5);
    if (no_effect) {
        pokemon_party_menu_use_return_callback = false;
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, self);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = exit_continuation;
    } else {
        if (!item_candy_state.rare_candy_item_removed) {
            item_remove(item_activated, 1);
            item_candy_state.rare_candy_item_removed = true;
        }
        item_callback_after_pokemon_selected = item_callback_rare_candy_step;
        pokemon_party_menu_do_item_use_animation(self);
    }
}

#define OAM_TAG_PARTY_MENU_EXP_BAR 5117

extern const u8 gfx_pokemon_party_menu_exp_barTiles[];
extern const u8 gfx_pokemon_party_menu_exp_barPal[];

static const graphic graphic_exp_bar = {
    .sprite = gfx_pokemon_party_menu_exp_barTiles, .size = GRAPHIC_SIZE_4BPP(64, 16), .tag = OAM_TAG_PARTY_MENU_EXP_BAR,
};

static const palette palette_exp_bar = {
    .pal = gfx_pokemon_party_menu_exp_barPal, .tag = OAM_TAG_PARTY_MENU_EXP_BAR,
};

static const sprite sprite_exp_bar = {
    .attr0 = ATTR0_SHAPE_HORIZONTAL, .attr1 = ATTR1_SIZE_32_16, .attr2 = ATTR2_PRIO(1),
};

static const gfx_frame gfx_anim_exp_bar_left[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END}
};

static const gfx_frame gfx_anim_exp_bar_right[] = {
    {.data = 8, .duration = 0}, {.data = GFX_ANIM_END}
};

static const gfx_frame *const gfx_anims_exp_bar[] = {
    gfx_anim_exp_bar_left, gfx_anim_exp_bar_right
};

static const oam_template template_exp_bar = {
    .tiles_tag = OAM_TAG_PARTY_MENU_EXP_BAR, .pal_tag = OAM_TAG_PARTY_MENU_EXP_BAR,
    .oam = &sprite_exp_bar, .animation = gfx_anims_exp_bar,
    .graphics = NULL, .rotscale = oam_rotscale_anim_table_null, 
    .callback = oam_null_callback,
};

#define EXP_BAR_PAD 2
#define EXP_BAR_WIDTH (64 - 2 * EXP_BAR_PAD)
#define EXP_BAR_RESOLUTION 64
#define EXP_BAR_STEP 1

static void exp_candy_fill_rectangle(void *sprite, int fraction) {

    u16 tile_num = oam_vram_get_tile(OAM_TAG_PARTY_MENU_EXP_BAR);
    if (tile_num != 0xFFFF) {

        int width = (EXP_BAR_WIDTH * fraction) / EXP_BAR_RESOLUTION;
        int x0 = EXP_BAR_PAD;
        int x1 = x0 + width;
        if (2 + x1 > 32) {
            gpu_fill_rectangle_4bpp(item_candy_state.sprite_rectangle, x0, 4, 32, 10, 1, 32);
            gpu_fill_rectangle_4bpp((u8*)item_candy_state.sprite_rectangle + GRAPHIC_SIZE_4BPP(32, 16), 0, 4, x1 - 32, 10, 1, 32);
        } else {
            gpu_fill_rectangle_4bpp(item_candy_state.sprite_rectangle, x0, 4, x1, 10, 1, 32);
        }

        cpuset(sprite, OAMCHARBASE(tile_num), CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(graphic_exp_bar.size));
    }
}

static void exp_candy_fill_exp_bar(u8 self) {
    // In EXP_BAR_RESOLUTION-ths
    u32 r0 = (u32)big_callback_get_int(self, 1);
    u32 r1 = (u32)big_callback_get_int(self, 3);
    u16 frame = big_callbacks[self].params[0]++;
    u32 r = r0 + (u32)(frame * EXP_BAR_STEP);
    bool finished = false;
    if (r1 <= r) {
        r = r1;
        finished = true;
    }
    // DEBUG("Fill exp bar from %d to %d, current %d\n", r0, r1, r);
    exp_candy_fill_rectangle(item_candy_state.sprite_rectangle, (int)r);
    if (finished) {
        mplay_stop_song(27);
        big_callback_delete(self);
    }
}

extern const u8 str_pokemon_reached_level[];

static void exp_candy_delete_bar_and_free(bool delete_oams) {
    // Delete the boxes
    if (delete_oams) {
        s16 *data = pokemon_party_menu_state.options_state->data;
        oam_delete(oams + data[14]);
        oam_delete(oams + data[15]);
    }
    free(item_candy_state.sprite_rectangle);
}

static void exp_candy_wait_level_up_fanfare(u8 self) {
    if (!big_callback_is_active(fanfare_callback_wait)) {
        exp_candy_delete_bar_and_free(true);
        big_callbacks[self].function = pokemon_party_menu_rare_candy_display_page_0;
    }
}

static void exp_candy_wait_keypress_and_close_pokemon_party_menu(u8 self) {
    if (super.keys_new.keys.A || super.keys_new.keys.B) {
        exp_candy_delete_bar_and_free(false);
        DEBUG("Use return callback %d, is @0x%x\n", pokemon_party_menu_use_return_callback, pokemon_party_menu_state.callback);
        if (!pokemon_party_menu_use_return_callback)
            pokemon_party_menu_state.callback = NULL;
        pokemon_party_menu_return_and_execute_callback(self);

    }
    // if (!pokemon_party_menu_is_text_printer_active()) {
    //     exp_candy_delete_bar_and_free();
    //     if (!pokemon_party_menu_use_return_callback)
    //         pokemon_party_menu_state.callback = NULL;
    //     pokemon_party_menu_return_and_execute_callback(self);
    // }
}

static void exp_candy_step(u8 self) {
    (void)self;
    if (!big_callback_is_active(exp_candy_fill_exp_bar)) {
        pokemon_party_menu_use_return_callback = true;
        if (item_candy_state.rare_candy_exp_leveled_up) {
            u8 party_idx = pokemon_party_menu_current_index;
            pokemon *p = player_pokemon + party_idx;
            DEBUG("Leveled up.\n");
            fanfare_by_fanfare_idx(0);
            fanfare_callback_wait_new();
            pokemon_party_menu_update_slot_display(party_idx, p);
            pokemon_load_name_as_string(p, buffer0);
            u8 level = (u8)pokemon_get_attribute(p, ATTRIBUTE_LEVEL, NULL);
            itoa(buffer1, level, ITOA_NO_PADDING, 3);
            string_decrypt(strbuf, str_pokemon_reached_level);
            pokemon_party_menu_init_text_rendering(strbuf, true);
            bg_virtual_sync_reqeust_push(2);
            big_callbacks[self].function = exp_candy_wait_level_up_fanfare;
            //item_callback_rare_candy_step(self, pokemon_party_menu_wait_for_text_and_close);
        } else {
            DEBUG("Not leveled up.\n");
            big_callbacks[self].function = exp_candy_wait_keypress_and_close_pokemon_party_menu;
        }
    }
}



static void item_callback_exp_candy_setup(u8 self, void (*exit_contuation)(u8)) {
    (void)exit_contuation;
    // DEBUG("Exp candy setup.\n");
    s16 *data = pokemon_party_menu_state.options_state->data;
    u8 party_idx = pokemon_party_menu_current_index;

    // Distribute exp points
    pokemon *p = player_pokemon + party_idx;
    u16 species = (u16)pokemon_get_attribute(p, ATTRIBUTE_SPECIES, NULL);
    int experience_group = basestats[species].level_up_type;
    u8 level = (u8)pokemon_get_attribute(p, ATTRIBUTE_LEVEL, NULL);
    u32 exp_current = (u32)pokemon_get_attribute(p, ATTRIBUTE_EXP, NULL);
    u32 exp_level_difference = pokemon_experience_tables[experience_group][level + 1] - pokemon_experience_tables[experience_group][level];
    u32 to_distribute = MIN(pokemon_experience_tables[experience_group][level + 1] - exp_current, item_candy_state.rare_candy_exp_remaining);
    item_candy_state.rare_candy_exp_remaining = (u32)(item_candy_state.rare_candy_exp_remaining - to_distribute);
    u32 exp_new = (u32)(exp_current + to_distribute);

    pokemon_get_stats(p, (u16*)(data + 0));
    pokemon_set_attribute(p, ATTRIBUTE_EXP, &exp_new);
    pokemon_calculate_stats(p);
    pokemon_get_stats(p, (u16*)(data + 6));
    u8 level_new = (u8)pokemon_get_attribute(p, ATTRIBUTE_LEVEL, NULL);
    item_candy_state.rare_candy_exp_leveled_up = level_new > level;
    if (item_candy_state.rare_candy_exp_leveled_up) {
        pokemon_party_menu_use_return_callback = true;
    }

    // Allocate resources
    if (oam_vram_get_tile(graphic_exp_bar.tag) == 0xFFFF) {
        u16 num_tiles = (u16)(graphic_exp_bar.size / GRAPHIC_SIZE_4BPP(8, 8));
        u16 tile = oam_vram_alloc(num_tiles);
        oam_vram_allocation_table_add(graphic_exp_bar.tag, tile, num_tiles);
    }
    void *sprite = malloc(graphic_exp_bar.size);
    lz77uncompwram(graphic_exp_bar.sprite, sprite);
    item_candy_state.sprite_rectangle = sprite;

    oam_palette_load_if_not_present(&palette_exp_bar);
    big_callbacks[self].function = exp_candy_step;

    // Calculate the position of the bar
    s16 x, y;
    if (party_idx == 0) {
        x = 33;
        y = 69;
    } else {
        x = 186;
        y = (s16)(28 + 8 * 3 * (party_idx - 1));
    }

    u8 oam_idx_left = oam_new_backward_search(&template_exp_bar, x, y, 48);
    oam_gfx_anim_start(oams + oam_idx_left, 0);
    u8 oam_idx_right = oam_new_backward_search(&template_exp_bar, (s16)(x + 32), y, 48);
    oam_gfx_anim_start(oams + oam_idx_right, 1);
    data[14] = oam_idx_left;
    data[15] = oam_idx_right;

    // Draw the first frame of the exp bar
    u8 cb_idx = big_callback_new(exp_candy_fill_exp_bar, 10);

    u32 r0 = EXP_BAR_RESOLUTION * (exp_current - pokemon_experience_tables[experience_group][level]) / (exp_level_difference);
    u32 r1 = EXP_BAR_RESOLUTION * (exp_new - pokemon_experience_tables[experience_group][level]) / (exp_level_difference);
    // DEBUG("Exp remaining %d, total %d\n", pokemon_experience_tables[experience_group][level + 1] - exp_current, exp_level_difference);

    big_callback_set_int(cb_idx, 1, (int)r0);
    big_callback_set_int(cb_idx, 3, (int)r1);
    big_callbacks[cb_idx].params[0] = 0; // Frame
    big_callbacks[cb_idx].function(cb_idx);
    play_sound(27);

}


void item_callback_exp_candy(u8 self, void (*exit_continuation)(u8)) {
    u8 party_idx = pokemon_party_menu_current_index;
    bool no_effect = true;
    if (pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_LEVEL, NULL) < 100) {
        no_effect = false;
    }
    play_sound(5);
    if (no_effect) {
        pokemon_party_menu_use_return_callback = false;
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, self);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = exit_continuation;
    } else {
        if (!item_candy_state.rare_candy_item_removed) {
            item_remove(item_activated, 1);
            item_candy_state.rare_candy_item_removed = true;
        }
        item_callback_after_pokemon_selected = item_callback_exp_candy_setup;
        pokemon_party_menu_do_item_use_animation(self);
    }
}

bool item_rare_candy_is_issued() {
    u8 party_idx = pokemon_party_menu_current_index;
    if (item_activated == ITEM_SONDERBONBON || item_activated == ITEM_GOLDBONBON) {
        return item_candy_state.rare_candy_levels_remaining > 0 && 
            pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_LEVEL, NULL) < 100 &&
            item_effect(player_pokemon + party_idx, item_activated, party_idx, 0, false, true);
    } else if (item_activated == ITEM_EP_BONBON_S || item_activated == ITEM_EP_BONBON_M 
                    || item_activated == ITEM_EP_BONBON_L || item_activated == ITEM_EP_BONBON_XL) {
        return item_candy_state.rare_candy_exp_remaining > 0 && pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_LEVEL, NULL) < 100;
    }
    return false;
}

void item_callback_do_rare_candy_if_issued(u8 self) {
    // DEBUG("check if candy is issued\n");
    if (item_rare_candy_is_issued()) {
        if (item_candy_state.rare_candy_levels_remaining > 0) {
            item_candy_state.rare_candy_levels_remaining--;
            item_callback_rare_candy(self, pokemon_party_menu_wait_for_text_and_close);
            return;
        } else if (item_candy_state.rare_candy_exp_leveled_up > 0) {
            // TODO
            item_callback_exp_candy(self, pokemon_party_menu_wait_for_text_and_close);
            return;
        }
    }
    // Default: Nothing is issued anymore
    big_callbacks[self].function = pokemon_party_menu_wait_for_text_and_close;
}

static void item_callback_do_rare_candy(u8 self) {
    // When giving N levels, at the first time we do not want to check if a level-up is
    // possible as we want the potential error message
    item_candy_state.rare_candy_levels_remaining--;
    item_callback_rare_candy(self, pokemon_party_menu_wait_for_text_and_close);
}

static void item_callback_any_rare_candy(u8 self, void (*exit_continuation)(u8)) {
    (void)exit_continuation; // It is always `pokemon_party_menu_wait_for_text_and_close`
    big_callbacks[self].function = item_callback_do_rare_candy;
}

void item_gold_candy_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_any_rare_candy;
    rare_candy_reset();
    item_candy_state.rare_candy_levels_remaining = 5;
    item_field_fade_to_scene_and_execute_callback(self);
}

void item_rare_candy_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_any_rare_candy;
    rare_candy_reset();
    item_candy_state.rare_candy_levels_remaining = 1;
    item_field_fade_to_scene_and_execute_callback(self);
}

void item_exp_candy_s_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_exp_candy;
    rare_candy_reset();
    item_candy_state.rare_candy_exp_remaining = 500;//500;
    item_field_fade_to_scene_and_execute_callback(self);
}

void item_exp_candy_m_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_exp_candy;
    rare_candy_reset();
    item_candy_state.rare_candy_exp_remaining = 3000;
    item_field_fade_to_scene_and_execute_callback(self);
}

void item_exp_candy_l_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_exp_candy;
    rare_candy_reset();
    item_candy_state.rare_candy_exp_remaining = 10000;
    item_field_fade_to_scene_and_execute_callback(self);
}

void item_exp_candy_xl_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_exp_candy;
    rare_candy_reset();
    item_candy_state.rare_candy_exp_remaining = 30000;
    item_field_fade_to_scene_and_execute_callback(self);
}