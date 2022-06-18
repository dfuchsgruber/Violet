#include "types.h"
#include "item/item.h"
#include "callbacks.h"
#include "save.h"
#include "item/fishing.h"
#include "debug.h"
#include "overworld/script.h"
#include "overworld/npc.h"
#include "tile/block.h"
#include "oam.h"
#include "agbmemory.h"
#include "music.h"
#include "math.h"
#include "gpu.h"
#include "bios.h"
#include "bg.h"
#include "prng.h"
#include "text.h"
#include "language.h"
#include "overworld/effect.h"
#include "constants/sav_keys.h"

extern LZ77COMPRESSED gfx_fishing_throw_barTiles;
extern LZ77COMPRESSED gfx_fishing_throw_barPal;
extern LZ77COMPRESSED gfx_fishing_starTiles;
extern LZ77COMPRESSED gfx_fishing_catching_fishTiles;
extern LZ77COMPRESSED gfx_fishing_catching_barTiles;
extern LZ77COMPRESSED gfx_fishing_catching_frameTiles;

static graphic graphic_throw_bar = {.sprite = gfx_fishing_throw_barTiles, .tag = FISHING_OAM_TAG_THROW, .size = 2 * GRAPHIC_SIZE_4BPP(32, 16) + 2 * GRAPHIC_SIZE_4BPP(32, 8)};
static graphic graphic_star = {.sprite = gfx_fishing_starTiles, .tag = FISHING_OAM_TAG_STAR, .size = 5 * GRAPHIC_SIZE_4BPP(16, 16)};
static graphic graphic_catching_frame = {.sprite = gfx_fishing_catching_frameTiles, .tag = FISHING_OAM_TAG_CATCHING_FRAME, .size = GRAPHIC_SIZE_4BPP(32, 96)};
static graphic graphic_catching_bar = {.sprite = gfx_fishing_catching_barTiles, .tag = FISHING_OAM_TAG_CATCHING_BAR, .size = GRAPHIC_SIZE_4BPP(16, 32)};
static graphic graphic_catching_fish = {.sprite = gfx_fishing_catching_fishTiles, .tag = FISHING_OAM_TAG_CATCHING_FISH, .size = GRAPHIC_SIZE_4BPP(32, 32)};
static palette palette_throw_bar = {.pal = gfx_fishing_throw_barPal, .tag = FISHING_OAM_TAG_THROW,};

static subsprite subsprites_throw_bar[] = {
    {.x = -32, .y = 0, .shape = ATTR0_SHAPE_HORIZONTAL >> 14, .size = ATTR1_SIZE_32_16 >> 14, .tile_offset = 0},
    {.x = 0, .y = 0, .shape = ATTR0_SHAPE_HORIZONTAL >> 14, .size = ATTR1_SIZE_32_16 >> 14, .tile_offset = GRAPHIC_SIZE_4BPP(32, 16) / GRAPHIC_SIZE_4BPP(8, 8)},
};

static subsprite_table subsprite_table_throw_bar = {
    .num_subsprites = ARRAY_COUNT(subsprites_throw_bar), .subsprites = subsprites_throw_bar,
};

static subsprite subsprites_throw_bar_progress[] = {
    {.x = -32, .y = 0, .shape = ATTR0_SHAPE_HORIZONTAL >> 14, .size = ATTR1_SIZE_32_8 >> 14, .tile_offset = GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8)},
    {.x = 0, .y = 0, .shape = ATTR0_SHAPE_HORIZONTAL >> 14, .size = ATTR1_SIZE_32_8 >> 14, .tile_offset = GRAPHIC_SIZE_4BPP(32, 40) / GRAPHIC_SIZE_4BPP(8, 8)},
};

static subsprite_table subsprite_table_throw_bar_progress = {
    .num_subsprites = ARRAY_COUNT(subsprites_throw_bar_progress), .subsprites = subsprites_throw_bar_progress,
};

static sprite sprite_throw_bar = {.attr0 = ATTR0_SHAPE_HORIZONTAL, .attr1 = ATTR1_SIZE_32_16, .attr2 = ATTR2_PRIO(1)};

static void fishing_free(fishing_state_t *state) {
    free(state->sprite_throw_bar_progress);
    oam_free_vram_by_tag(FISHING_OAM_TAG_STAR);
    oam_free_vram_by_tag(FISHING_OAM_TAG_THROW);
    oam_palette_free(FISHING_OAM_TAG_THROW);
    free(state);
}

static u8 fishing_get_throw_rating(u8 throw_bar_value) {
    if (throw_bar_value < 70)
        return 0;
    else if (throw_bar_value < 90)
        return 1;
    else if (throw_bar_value < 100)
        return 2;
    else
        return 3;
}

static u8 fishing_get_catching_bonus() {
    return 5; // TODO, for testing
}

static void oam_callback_throw_bar_shake(oam_object *self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int((u8)(self->private[0]), 0);
    if (state->state == FISHING_STATE_THROWING) {
        u16 *frame = self->private + 1;
        *frame = (u16)((*frame + 1) % 4);
        int amplitude = fishing_get_throw_rating(state->throw_bar_value);
        FIXED sine = FIXED_SIN(FIXED_DIV(INT_TO_FIXED(*frame), INT_TO_FIXED(4)));
        self->x2 = (s16)FIXED_TO_INT(FIXED_MUL(INT_TO_FIXED(amplitude), sine));
    } else {
        self->x2 = 0;
    }
}

static oam_template oam_template_throw_bar = {
    .tiles_tag = FISHING_OAM_TAG_THROW, .pal_tag = FISHING_OAM_TAG_THROW,
    .graphics = NULL, .oam = &sprite_throw_bar, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_callback_throw_bar_shake,
};

static sprite sprite_throw_bar_progress = {.attr0 = ATTR0_SHAPE_HORIZONTAL, .attr1 = ATTR1_SIZE_32_8, .attr2 = ATTR2_PRIO(1)};

static oam_template oam_template_throw_bar_progress = {
    .tiles_tag = FISHING_OAM_TAG_THROW, .pal_tag = FISHING_OAM_TAG_THROW,
    .graphics = NULL, .oam = &sprite_throw_bar_progress, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_callback_throw_bar_shake,
};

static sprite sprite_star = {.attr0 = ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0)};

static gfx_frame animation_star_empty[] = {{.data = 1 * GRAPHIC_SIZE_4BPP(16, 16) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame animation_star_1[] = {{.data = 2 * GRAPHIC_SIZE_4BPP(16, 16) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame animation_star_2[] = {{.data = 3 * GRAPHIC_SIZE_4BPP(16, 16) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame animation_star_3[] = {{.data = 4 * GRAPHIC_SIZE_4BPP(16, 16) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame animation_star_full[] = {{.data = 0 * GRAPHIC_SIZE_4BPP(16, 16) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};

static gfx_frame *animations_star[] = {
    [FISHING_STAR_EMPTY] = animation_star_empty,
    [FISHING_STAR_1] = animation_star_1,
    [FISHING_STAR_2] = animation_star_2,
    [FISHING_STAR_3] = animation_star_3,
    [FISHING_STAR_FULL] = animation_star_full,
};

static rotscale_frame rs_star_none[] = {
    {.affine = {.affine_x_value = 0x100, .affine_y_value = 0x100, .duration = 0}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

static rotscale_frame rs_star_appear[] = {
    {.affine = {.affine_x_value = 8, .affine_y_value = 8, .duration = 0}},
    {.affine = {.affine_x_value = 8, .affine_y_value = 8, .duration = 31}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

static rotscale_frame rs_star_disappear[] = {
    {.affine = {.affine_x_value = 0x100, .affine_y_value = 0x100, .duration = 0}},
    {.affine = {.affine_x_value = -8, .affine_y_value = -8, .duration = 31}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

static rotscale_frame rs_star_collect[] = {
    {.affine = {.affine_x_value = 0x100, .affine_y_value = 0x100, .duration = 0}},
    {.affine = {.affine_x_value = 8, .affine_y_value = 8, .duration = 15}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

static rotscale_frame *rs_anims_star[] = {
    [FISHING_STAR_RS_NONE] = rs_star_none,
    [FISHING_STAR_RS_APPEAR] = rs_star_appear,
    [FISHING_STAR_RS_DISAPPEAR] = rs_star_disappear,
    [FISHING_STAR_RS_COLLECT] = rs_star_collect,
};

static oam_template oam_template_star = {
    .tiles_tag = FISHING_OAM_TAG_STAR, .pal_tag = FISHING_OAM_TAG_THROW,
    .graphics = NULL, .oam = &sprite_star, .animation = animations_star,
    .rotscale = rs_anims_star, .callback = oam_null_callback,
};

static int fishing_get_bite_bonus() {
    return 0; // TODO
}

static bool fishing_state_lock(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    player_state.is_locked = true;
    overworld_script_set_active();
    state->state++;
    return true;
}

static void oam_callback_vibrate(oam_object *self) {
    self->private[1]++;
    if (self->private[0] && self->x2 == 0 && (self->private[1] & 3) == 0) {
        self->x2 = 1;
    } else {
        self->x2 = 0;
    }
}

static u8 fishing_reach_back_animations[] = {
    [DIR_DOWN] = 12,
    [DIR_UP] = 13,
    [DIR_LEFT] = 14,
    [DIR_RIGHT] = 15,
};

static bool fishing_state_reach_back(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    npc *n = npcs + player_state.npc_idx;
    state->backup_overworld_idx = n->overworld_id;
    npc_clear_held_movement_if_active(n);
    n->flags.animation_enabled = true;
    player_transition(PLAYER_TRANSITION_FISH);
    state->state++;
    oam_gfx_anim_start(oams + n->oam_id, fishing_reach_back_animations[player_get_facing()]);
    return false;
}

static bool fishing_state_initialize_throwing(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    state->progress_tile_idx = oam_load_graphic(&graphic_throw_bar);
    oam_load_palette_using_heap(&palette_throw_bar);
    state->oam_idx_throw_bar = oam_new_forward_search(&oam_template_throw_bar, 120, 40, 0);
    oam_set_subsprite_table(oams + state->oam_idx_throw_bar, &subsprite_table_throw_bar);
    oams[state->oam_idx_throw_bar].private[0] = self;
    state->oam_idx_throw_bar_progress = oam_new_forward_search(&oam_template_throw_bar_progress, 120, 45, 0);
    oam_set_subsprite_table(oams + state->oam_idx_throw_bar_progress, &subsprite_table_throw_bar_progress);
    oams[state->oam_idx_throw_bar_progress].private[0] = self;
    state->sprite_throw_bar_progress = malloc_and_clear(GRAPHIC_SIZE_4BPP(64, 8));
    state->state++;
    return false;
}

static bool fishing_state_wait_for_a_to_start_throwing(u8 self) {
    if (super.keys_new.keys.A) {
        play_sound(5);
        fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
        state->throw_bar_value = 0;
        state->state++;
        return true;
    }
    return false;
}

#define THROWING_PERFECT_FRAME_EXTRA_MARGIN 1
#define THROWING_SPEED 3

static bool fishing_state_throwing(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    if (state->throw_bar_decreasing) {
        state->throw_bar_value = (u8)MAX(0, state->throw_bar_value - THROWING_SPEED);
        if (state->throw_bar_value <= 0)
            state->throw_bar_decreasing = false;
    } else {
        state->throw_bar_value = (u8)MIN(100 + THROWING_PERFECT_FRAME_EXTRA_MARGIN * THROWING_SPEED, state->throw_bar_value + THROWING_SPEED);
        if (state->throw_bar_value >= 100 + THROWING_PERFECT_FRAME_EXTRA_MARGIN * THROWING_SPEED)
            state->throw_bar_decreasing = true;
    }
    int width = MIN(100, state->throw_bar_value) * FISHING_THROW_PROGRESS_TOTAL_WIDTH / 100;
    u32 color = (state->throw_bar_value * 5u) / 100u;
    gpu_fill_rectangle_4bpp(state->sprite_throw_bar_progress, FISHING_THROW_PROGRESS_MARGIN, 0, FISHING_THROW_PROGRESS_MARGIN + width, 6, 7 + color, 64);
    gpu_fill_rectangle_4bpp(state->sprite_throw_bar_progress, FISHING_THROW_PROGRESS_MARGIN + width, 0, 64 - FISHING_THROW_PROGRESS_MARGIN, 6, 0, 64);
    cpuset(state->sprite_throw_bar_progress, OAMCHARBASE(state->progress_tile_idx + 
        (GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8))
    ), CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(64, 8)));
    // DEBUG("Width %d, color %d, frame %d, throw_bar_val %d\n", width, color, state->throw_bar_progress, state->throw_bar_value);
    if (!super.keys.keys.A) {
        state->state++;
    }
    return false;
}

static void star_animation_disappear(oam_object *self) {
    u16 *vars = self->private;
    if (vars[0] > 0) {
        vars[0]--;
        self->flags |= OAM_FLAG_INVISIBLE;
    } else {
        if (vars[2] > 0) {
            vars[2]--;
            return;
        } else {
            vars[2] = 1;
        }
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
        if (self->y2 > 0) {
            self->y2--;
            FIXED sin = FIXED_SIN(FIXED_DIV(INT_TO_FIXED(vars[1]++), INT_TO_FIXED(8)));
            FIXED x2 = FIXED_MUL(INT_TO_FIXED(2), sin);
            self->x2 = (s16)(FIXED_TO_INT(x2));
        } else {
            self->flags |= OAM_FLAG_INVISIBLE;
            self->callback = oam_null_callback;
        }
    }
}

static s16 star_x_anchors[3] = {120, 110, 130};

static void fishing_create_stars(fishing_state_t *state, u8 num_stars) {
    for (size_t i = 0; i < num_stars; i++) {
        // s16 x = (s16)(star_x_anchors[i] + (rnd16() % 8));
        // s16 y = (s16)(30 - (rnd16() % 10));
        s16 x = star_x_anchors[i];
        s16 y = 24;
        state->oam_idx_star[i] = oam_new_forward_search(&oam_template_star, x, y, 1);
        oam_object *o = oams + state->oam_idx_star[i];
        o->y2 = 20;
        // o->private[0] = (u16)(rnd16() % 16);
        o->private[0] = (u16)(i * 10);
        oam_gfx_anim_start(o, FISHING_STAR_FULL);
        o->callback = star_animation_disappear;
        o->callback(o);
    }
    state->num_star_sounds = num_stars;
}

static bool fishing_wait_for_stars(fishing_state_t *state, u8 num_stars) {
    bool finished = true;
    for (int i = 0; i < num_stars; i++) {
        if (oams[state->oam_idx_star[i]].callback == star_animation_disappear) {
            finished = false;
        }
    }
    if (state->num_star_sounds > 0) {
        if (state->delay > 0) {
            state->delay--;
        } else {
            // star sound
            play_sound(188);
            state->delay = 8;
            state->num_star_sounds--;
        }
        finished = false;
    }
    if (finished) {
        for (int i = 0; i < num_stars; i++) {
            oam_delete(oams + state->oam_idx_star[i]);
        }
        return true;
    }
    return false;
}

static bool fishing_state_thrown(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    u8 num_stars = fishing_get_throw_rating(state->throw_bar_value);
    state->delay = 0;
    oam_load_graphic(&graphic_star);
    fishing_create_stars(state, num_stars);
    state->state++;
    return true;
}

static bool fishing_state_wait_throw_stars(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    u8 num_stars = fishing_get_throw_rating(state->throw_bar_value);
    if (fishing_wait_for_stars(state, num_stars))
        state->state++;
    return false;
}

static bool fishing_player_throw_animation(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    player_transition(PLAYER_TRANSITION_FISH);
    play_sound(153);
    state->delay = 24;
    state->state++;
    return true;
}

static bool fishing_player_wait(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    if (state->delay > 0) {
        state->delay--;
    } else {
        state->state++;
    }
    return false;
}

static bool fishing_player_hide_throwing(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    oam_delete(oams + state->oam_idx_throw_bar);
    oam_delete(oams + state->oam_idx_throw_bar_progress);
    // play_sound(117);
    state->delay = 44;
    state->state++;
    return false;
}

static bool fishing_initialize_wait_for_bite(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    state->delay = 60; // Duration of one round
    state->state++;
    return true;
}

static bool fishing_wait_for_bite(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    if (state->delay > 0) {
        if (super.keys_new.keys.A) { // can't pull out too early
            state->state = FISHING_STATE_NOT_EVEN_A_NIBBLE;
            return true;
        }
        state->delay--;
        int p = MAX(1, 4 + fishing_get_bite_bonus()); // Base change is 4 / 256 = 1 / 64
        if (map_current_has_wild_habitat_rod() && ((rnd16() % 256) < p || true)) { // something bites
            // oam_gfx_anim_start(oams + player_state.oam_idx, fishing_get_bite_animation_idx_by_facing_direction());
            state->state = FISHING_STATE_BITE_EXCLAMATION_MARK;
            oam_gfx_anim_start(oams + player_state.oam_idx, fishing_get_bite_animation_idx_by_facing_direction(player_get_facing()));
            return true;
        }
    } else {
        if (map_current_has_wild_habitat_rod() && (rnd16() & 1)) { // go to next round
            state->state = FISHING_STATE_INITIALIZE_WAIT_FOR_BITE;
        } else {
            state->state = FISHING_STATE_NOT_EVEN_A_NIBBLE;
        }
        return true;
    }
    return false;
}

static u8 str_not_even_a_nibble[] = LANGDEP(
    PSTRING("Nicht einmal ein kleines KnabbernDOTSPAUSE_UNTIL_PRESS"), 
    PSTRING("Not even a nibbleDOTSPAUSE_UNTIL_PRESS")
);

// static tbox_font_colormap fishing_fontcolmap = {.background = 1, .body = 2, .shadow = 3};

static bool fishing_not_even_a_nibble(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    oam_gfx_anim_start(oams + player_state.oam_idx, fishing_get_no_bite_animation_idx_by_facing_direction(player_get_facing()));
    tbox_init_frame_message_and_draw_tilemap(0, true);
    tbox_flush_set(0, 0x11);
    tbox_print_string_set_font_colors_and_spacing_1(0, 2, str_not_even_a_nibble, tbox_get_set_speed(), NULL, 2, 1, 3);
    state->state = FISHING_STATE_WAIT_FRAME_TO_PRINT_TEXT;
    return true;
}

static bool fishing_wait_frame_to_print_text(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    state->state = FISHING_STATE_RESET_PLAYER_STATE_AND_PRINT_TEXT;
    return false;
}

static void fishing_reset_player_state(fishing_state_t *state) {
    oam_object *o = oams + player_state.oam_idx; 
    npc *n = npcs + player_state.npc_idx;
    npc_update_picture(n, state->backup_overworld_idx);
    npc_set_facing(n, n->direction.movement);
    if (player_state.state & PLAYER_STATE_SURFING) {
        player_npc_set_surf_blob_offset(n->oam_surf, false, 0);
    }
    o->x2 = 0;
    o->y2 = 0;
}

static bool fishing_reset_player_state_and_print_text(u8 self) {
    oam_object *o = oams + player_state.oam_idx; 
    fishing_proceed_and_align_oams(o);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    if (o->flags & OAM_FLAG_GFX_ANIM_END) {
        fishing_reset_player_state(state);
        if (state->catching_succesfull)
            state->state = FISHING_STATE_PRINT_TEXT_AND_START_ENCOUNTER;
        else
            state->state = FISHING_STATE_PRINT_TEXT_AND_RELEASE;
    }
    return false;
}

static bool fishing_wait_print_text_and_release(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    tbox_proceed();
    if (!tbox_printer_is_active(0)) {
        player_state.is_locked = false;
        overworld_script_set_inactive();
        npc_update_oam_delay_all();
        tbox_clear_message(0, true);
        fishing_free(state);
        big_callback_delete(self);
    }
    return false;
}

static bool fishing_wait_print_text_and_start_encounter(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    tbox_proceed();
    if (!tbox_printer_is_active(0)) {
        fishing_reset_player_state(state);
        tbox_clear_message(0, true);
        state->state = FISHING_STATE_START_ENCOUNTER;
    }
    return false;
}

static void fishing_pokemon_new(fishing_state_t *state) {
    (void)state;
    pid_t pid = {0};
    pokemon_clear_opponent_party();
    pokemon_new(opponent_pokemon, 5, 5, POKEMON_NEW_RANDOM_IVS, false, pid, false, 0);
    
}

static bool fishing_start_encounter(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    save_increment_key(SAV_KEY_FISHING_ENCOUNTERS);
    overworld_script_set_inactive();
    fishing_pokemon_new(state);
    wildbattle_start();
    player_state.is_locked = false;
    fishing_free(state);
    big_callback_delete(self);
    return false;
}

static bool fishing_exclamation_mark(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    npc *n = npcs + player_state.npc_idx;
    overworld_effect_state.x = 0xFF;
    overworld_effect_state.y = n->map;
    overworld_effect_state.height = n->bank;
    overworld_effect_new(OVERWORLD_EFFECT_EXCLAMATION_MARK_ICON);
    play_sound(21);
    state->delay = (u8)(30 + (rnd16() % 16));
    state->state = FISHING_STATE_BITE_REACT_TO_EXCLAMATION_MARK;
    return false;
}

static bool fishing_react_to_exclamation_mark(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    if (state->delay > 0) {
        state->delay--;
        if (super.keys_new.keys.A) {
            state->substate = 0;
            state->state = FISHING_STATE_INTIALIZE_CATCHING;
        }
    } else {
        state->state = FISHING_STATE_IT_GOT_AWAY;
    }
    return false;
}


static void fishing_initialize_catching_bar() {
    // Manually decompress and manipulate the catching bar according to the bonus
    u32 *src = malloc(graphic_catching_bar.size);
    lz77uncompwram(graphic_catching_bar.sprite, src);
    int bonus = fishing_get_catching_bonus();
    int height = FISHING_CATCHING_BAR_HEIGHT + 2 * bonus;
    int margin = (32 - height) / 2;
    gpu_fill_rectangle_4bpp(gp_tmp_buf, 0, 0, 16, margin, 0, 16);
    gpu_fill_rectangle_4bpp(gp_tmp_buf, 0, 32 - margin, 16, 32, 0, 16);
    u32 *dst = (u32*)gp_tmp_buf;
    // Assembling this bar is a bit hacky, we draw it line-wise, but lines are split over 2 tiles (width = 16)
    for (int i = 0; i < height; i++) {
        int y_src;
        if (i == 0)
            y_src = CATCHING_BAR_Y_TOP;
        else if (i == 2)
            y_src = CATCHING_BAR_Y_TOP_SHINE;
        else if (i == height - 2)
            y_src = CATCHING_BAR_Y_BOTTOM_SHADOW;
        else if (i == height - 1)
            y_src = CATCHING_BAR_Y_BOTTOM;
        else
            y_src = CATCHING_BAR_Y_DEFAULT;
        int y_dst = margin + i;
        dst[8 * 2 * (y_dst / 8) + (y_dst % 8)] = src[8 * 2 * (y_src / 8) + (y_src % 8)];
        dst[8 * 2 * (y_dst / 8) + (y_dst % 8) + 8] = src[8 * 2 * (y_src / 8) + (y_src % 8) + 8];
    }

    // u32 color = 4;
    // if (bonus > 0) {
    //     gpu_fill_rectangle_4bpp(gp_tmp_buf, 1, 24, 15, 24 + bonus, color, 16);
    //     gpu_fill_rectangle_4bpp(gp_tmp_buf, 1, 8 - bonus, 15, 8, color, 16);
    // }
    u16 num_tiles = (u16)(graphic_catching_bar.size / GRAPHIC_SIZE_4BPP(8, 8));
    u16 tile_idx = oam_vram_alloc(num_tiles);
    oam_vram_allocation_table_add(FISHING_OAM_TAG_CATCHING_BAR, tile_idx, num_tiles);
    cpuset(gp_tmp_buf, OAMCHARBASE(tile_idx), CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(graphic_catching_bar.size));
    free(src);
}

static void fishing_update_catching_progress(fishing_state_t *state) {
    int progress = state->catching_progress * FISHING_CATCHING_PROGRESS_BAR_TOTAL_HEIGHT / CATCHING_DURATION;
    u32 color = (u32)(7 + state->catching_progress * 5 / CATCHING_DURATION);
    int y = 96 - progress;
    gpu_fill_rectangle_4bpp(state->sprite_catching_progress_bar, 0, 0, 8, y, 0, 8);
    gpu_fill_rectangle_4bpp(state->sprite_catching_progress_bar, 0, y, 8, 96, color, 8);
    // DEBUG("Catching progress bar at 0x%x, progress %d, y%d, color %d\n", state->sprite_catching_progress_bar, progress, y);
    cpuset(state->sprite_catching_progress_bar, OAMCHARBASE(state->progress_tile_idx), CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 96)));
}

static void fishing_initialize_catching_progress(fishing_state_t *state) {
    u16 num_tiles = GRAPHIC_SIZE_4BPP(8, 96) / GRAPHIC_SIZE_4BPP(8, 8);
    u16 tile_idx = oam_vram_alloc(num_tiles);
    oam_vram_allocation_table_add(FISHING_OAM_TAG_CATCHING_PROGRESS, tile_idx, num_tiles);
    state->progress_tile_idx = tile_idx;
    state->sprite_catching_progress_bar = malloc(GRAPHIC_SIZE_4BPP(8, 96));
    fishing_update_catching_progress(state);
}

static sprite sprite_catching_frame = {.attr0 = ATTR0_SHAPE_VERTICAL, .attr1 = ATTR1_SIZE_32_64, .attr2 = ATTR2_PRIO(0)};

static oam_template oam_template_catching_frame = {
    .tiles_tag = FISHING_OAM_TAG_CATCHING_FRAME, .pal_tag = FISHING_OAM_TAG_THROW,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback, .oam = &sprite_catching_frame,
};

static subsprite subsprites_catching_frame[] = {
    {.x = 0, .y = -64, .shape = ATTR0_SHAPE_VERTICAL >> 14, .size = ATTR1_SIZE_32_64 >> 14, .tile_offset = 0},
    {.x = 0, .y = 0, .shape = ATTR0_SHAPE_SQUARE >> 14, .size = ATTR1_SIZE_32_32 >> 14, .tile_offset = GRAPHIC_SIZE_4BPP(32, 64) / GRAPHIC_SIZE_4BPP(8, 8)},
};

static subsprite_table subsprite_table_catching_frame = {.subsprites = subsprites_catching_frame, .num_subsprites = ARRAY_COUNT(subsprites_catching_frame)};

static sprite sprite_catching_progress_bar = {.attr0 = ATTR0_SHAPE_VERTICAL, .attr1 = ATTR1_SIZE_8_32, .attr2 = ATTR2_PRIO(0)};

static oam_template oam_template_catching_progress_bar = {
    .tiles_tag = FISHING_OAM_TAG_CATCHING_PROGRESS, .pal_tag = FISHING_OAM_TAG_THROW,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback, .oam = &sprite_catching_progress_bar,
};

static subsprite subsprites_catching_progress_bar[] = {
    {.x = 0, .y = -64, .shape = ATTR0_SHAPE_VERTICAL >> 14, .size = ATTR1_SIZE_8_32 >> 14, .tile_offset = 0 * GRAPHIC_SIZE_4BPP(8, 32) / GRAPHIC_SIZE_4BPP(8, 8)},
    {.x = 0, .y = -32, .shape = ATTR0_SHAPE_VERTICAL >> 14, .size = ATTR1_SIZE_8_32 >> 14, .tile_offset = 1 * GRAPHIC_SIZE_4BPP(8, 32) / GRAPHIC_SIZE_4BPP(8, 8)},
    {.x = 0, .y = 0, .shape = ATTR0_SHAPE_VERTICAL >> 14, .size = ATTR1_SIZE_8_32 >> 14, .tile_offset = 2 * GRAPHIC_SIZE_4BPP(8, 32) / GRAPHIC_SIZE_4BPP(8, 8)},
};

static subsprite_table subsprite_table_catching_progress_bar = {.subsprites = subsprites_catching_progress_bar, .num_subsprites = ARRAY_COUNT(subsprites_catching_progress_bar)};

static sprite sprite_catching_bar = {.attr0 = ATTR0_SHAPE_VERTICAL, .attr1 = ATTR1_SIZE_16_32, .attr2 = ATTR2_PRIO(0)};

static oam_template oam_template_catching_bar = {
    .tiles_tag = FISHING_OAM_TAG_CATCHING_BAR, .pal_tag = FISHING_OAM_TAG_THROW,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback, .oam = &sprite_catching_bar,
};

static sprite sprite_catching_fish = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0)};

static oam_template oam_template_catching_fish = {
    .tiles_tag = FISHING_OAM_TAG_CATCHING_FISH, .pal_tag = FISHING_OAM_TAG_THROW,
    .animation = oam_gfx_anim_table_null, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_callback_vibrate, .oam = &sprite_catching_fish,
};

static void fishing_catching_get_anchor_position(s16 *x, s16 *y) {
    *y = 160 - (96 / 2) - 20;
    if (player_get_facing() == DIR_RIGHT)
        *x = 120 - 32;
    else
        *x = 120 + 16;
}

static bool fishing_initialize_catching(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    switch (state->substate) {
        case 0:
            state->catching_progress = CATCHING_DURATION / 4;
            state->substate++;
            FALL_THROUGH;
        case 1:
            oam_load_graphic(&graphic_catching_frame);
            oam_load_graphic(&graphic_catching_fish);
            state->substate++;
            return false;
        case 2:
            fishing_initialize_catching_bar();
            fishing_initialize_catching_progress(state);
            state->substate++;
            return false;
        default: {
            s16 anchor_x, anchor_y;
            fishing_catching_get_anchor_position(&anchor_x, &anchor_y);
            state->oam_idx_catching_frame = oam_new_forward_search(&oam_template_catching_frame, anchor_x, anchor_y, 31);
            oam_set_subsprite_table(oams + state->oam_idx_catching_frame, &subsprite_table_catching_frame);
            state->oam_idx_catching_progress_bar = oam_new_forward_search(&oam_template_catching_progress_bar, anchor_x, anchor_y, 0);
            oam_set_subsprite_table(oams + state->oam_idx_catching_progress_bar, &subsprite_table_catching_progress_bar);
            oams[state->oam_idx_catching_progress_bar].x2 = 21;
            oams[state->oam_idx_catching_progress_bar].y2 = -FISHING_CATCHING_PROGRESS_BAR_MARGIN;
            state->oam_idx_catching_bar = oam_new_forward_search(&oam_template_catching_bar, (s16)(anchor_x + 11), (s16)(anchor_y + 21), 2);
            state->oam_idx_catching_fish = oam_new_forward_search(&oam_template_catching_fish, (s16)(anchor_x + 11), (s16)(anchor_y + 24), 1);
            state->state = FISHING_STATE_CATCHING;
            return true;
        }
    }   
}

static void fishing_catching_bar_proceed(fishing_state_t *state) {
    FIXED pos = FIXED_ADD(state->catching_bar_position, state->catching_bar_velocity);
    FIXED pmax = INT_TO_FIXED(FISHING_CATCHING_FRAME_TOTAL_HEIGHT - 2 * fishing_get_catching_bonus() - (FISHING_CATCHING_BAR_HEIGHT / 1));
    if (pos < 0) {
        // pos = FIXED_SUB(pmin, pos); // Reflect
        pos = 0;
        state->catching_bar_velocity = FIXED_SUB(-state->catching_bar_velocity, FISHING_CATCHING_BAR_VELOCITY_LOSS);
    } else if (pos > pmax) { // Reflect
        pos = FIXED_SUB(pmax,FIXED_SUB(pos, pmax));
        // pos = pmax;
        state->catching_bar_velocity = FIXED_ADD(-state->catching_bar_velocity, FISHING_CATCHING_BAR_VELOCITY_LOSS);
    }
    // Proceed the velocity
    oams[state->oam_idx_catching_bar].y2 = (s16)(-FIXED_TO_INT(pos) - fishing_get_catching_bonus());
    state->catching_bar_position = pos;
    state->catching_bar_velocity = MAX(-FISHING_CATCHING_BAR_MAX_VELOCITY, FIXED_SUB(state->catching_bar_velocity, FISHING_CATCHING_BAR_G));
}

static void fishing_catching_fish_proceed(fishing_state_t *state) {
    // FIXED pmin = 0;
    // FIXED pmax = INT_TO_FIXED(FISHING_CATCHING_FRAME_TOTAL_HEIGHT - FISHING_CATCHING_FISH_HEIGHT);
    FIXED pos = 0;
    oams[state->oam_idx_catching_fish].y2 = (s16)(-FIXED_TO_INT(pos));
    state->catching_fish_position = pos;
}

static inline bool intervals_overlap(FIXED a1, FIXED a2, FIXED b1, FIXED b2) {
    return a1 <= b2 && b1 <= a2;
}


static void fishing_catching_new_star(fishing_state_t *state) {
    for (int i = 0; i < CATCHING_NEW_STAR_MAX_ATTEMPTS; i++) {
        state->catching_star_position = INT_TO_FIXED(rnd16() % (FISHING_CATCHING_FRAME_TOTAL_HEIGHT - FISHING_CATCHING_STAR_HEIGHT));
        FIXED y0_bar = state->catching_bar_position;
        FIXED y1_bar = FIXED_ADD(y0_bar, INT_TO_FIXED(FISHING_CATCHING_BAR_HEIGHT + 2 * fishing_get_catching_bonus()));
        FIXED y0_fish = state->catching_fish_position;
        FIXED y1_fish = FIXED_ADD(y0_fish, INT_TO_FIXED(FISHING_CATCHING_FISH_HEIGHT));
        FIXED y0_star = state->catching_star_position;
        FIXED y1_star = FIXED_ADD(y0_star, INT_TO_FIXED(FISHING_CATCHING_STAR_HEIGHT));
        if (!intervals_overlap(y0_bar, y1_bar, y0_star, y1_star) && 
            !intervals_overlap(y0_fish, y1_fish, y0_star, y1_star)) {

            DEBUG("New star at [%d, %d], bar at [%d, %d], fish at [%d, %d]\n", 
                FIXED_TO_INT(y0_star), FIXED_TO_INT(y1_star), FIXED_TO_INT(y0_bar), 
                FIXED_TO_INT(y1_bar), FIXED_TO_INT(y0_fish), FIXED_TO_INT(y1_fish));
            break;
        }
    }
}

static void fishing_catching_new_star_proceed(fishing_state_t *state) {
    if (!state->catching_star_is_present && state->num_stars_collected < CATCHING_MAX_NUM_STARS && 
            (rnd16() % 512) == 0) {
        // Find a position that does not overlap the bar and the fish (if possible)
        fishing_catching_new_star(state);
        s16 anchor_x, anchor_y;
        fishing_catching_get_anchor_position(&anchor_x, &anchor_y);
        state->oam_idx_catching_star = oam_new_forward_search(&oam_template_star, 
            (s16)(anchor_x + 11), (s16)(anchor_y + 23), 1);
        oam_rotscale_anim_init(oams + state->oam_idx_catching_star, FISHING_STAR_RS_APPEAR);
        oams[state->oam_idx_catching_star].y2 = (s16)(-FIXED_TO_INT(state->catching_star_position));
        oams[state->oam_idx_catching_star].callback = oam_callback_vibrate;
        state->star_progress = 0;
        state->catching_star_is_present = true;
    }
}

static void fishing_star_progress_proceed(fishing_state_t *state) {
    oam_object *o = oams + state->oam_idx_catching_star;
    switch(state->star_state) {
        case FISHING_STAR_STATE_PROGRESS: {
            if (state->catching_star_is_present) {
                FIXED y0_box = state->catching_bar_position;
                FIXED y1_box = FIXED_ADD(y0_box, INT_TO_FIXED(FISHING_CATCHING_BAR_HEIGHT + 2 * fishing_get_catching_bonus()));
                FIXED y0_star = state->catching_star_position;
                FIXED y1_star = FIXED_ADD(y0_star, INT_TO_FIXED(FISHING_CATCHING_STAR_HEIGHT));
                if (intervals_overlap(y0_box, y1_box, y0_star, y1_star)) {
                    state->star_progress = (u16)MIN(CATCHING_STAR_DURATION, state->star_progress + 1);
                    o->private[0] = true;
                } else {
                    state->star_progress = (u16)MAX(0, state->star_progress - 1);
                    o->private[0] = false;
                }
                u8 anim_idx = (u8)((NUM_FISHING_STAR_ANIMATIONS - 1) * state->star_progress / CATCHING_STAR_DURATION);
                oam_gfx_anim_start(o, anim_idx);
                if (state->star_progress == CATCHING_STAR_DURATION) {
                    play_sound(244);
                    state->star_state = FISHING_STAR_STATE_COLLECT;
                    state->num_stars_collected++;
                }
            }
            break;
        }
        case FISHING_STAR_STATE_COLLECT: {
            oam_rotscale_anim_init(o, FISHING_STAR_RS_COLLECT);
            state->star_state = FISHING_STAR_STATE_WAIT_COLLECTING;
            FALL_THROUGH;
        }
        case FISHING_STAR_STATE_WAIT_COLLECTING: {
            if (o->flags & OAM_FLAG_ROTSCALE_ANIM_END) {
                oam_delete(o);
                state->catching_star_is_present = false;
                state->star_state = FISHING_STAR_STATE_PROGRESS;
            }
            break;
        }
    }
    
}

static void fishing_catching_progress_proceed(fishing_state_t *state) {
    // Check if the intervals defined by the fish and the box intersect
    FIXED y0_box = state->catching_bar_position;
    FIXED y1_box = FIXED_ADD(y0_box, INT_TO_FIXED(FISHING_CATCHING_BAR_HEIGHT + 2 * fishing_get_catching_bonus()));
    FIXED y0_fish = state->catching_fish_position;
    FIXED y1_fish = FIXED_ADD(y0_fish, INT_TO_FIXED(FISHING_CATCHING_FISH_HEIGHT));
    if (intervals_overlap(y0_box, y1_box, y0_fish, y1_fish)) {
        state->catching_progress = (u16)MIN(CATCHING_DURATION, state->catching_progress + 1);
        oams[state->oam_idx_catching_fish].private[0] = true;
    } else {
        state->catching_progress = (u16)MAX(0, state->catching_progress - 2);
        oams[state->oam_idx_catching_fish].private[0] = false;
    }
    fishing_update_catching_progress(state);
}

static bool fishing_catching(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    if (super.keys_new.keys.A) { // Burst
        state->catching_bar_velocity = MIN(FISHING_CATCHING_BAR_MAX_VELOCITY, 
            MAX(FISHING_CATCHING_BAR_BOOST, 
            FIXED_ADD(state->catching_bar_velocity, FISHING_CATCHING_BAR_BOOST))
        );
        // state->catching_bar_velocity = FISHING_CATCHING_BAR_BOOST;
    }
    // DEBUG("Pos 0x%x, veclocity 0x%x\n", state->catching_bar_position, state->catching_bar_velocity);
    fishing_catching_bar_proceed(state);
    fishing_catching_fish_proceed(state);
    fishing_catching_new_star_proceed(state);
    fishing_star_progress_proceed(state);
    fishing_catching_progress_proceed(state);
    if (super.keys_new.keys.B || state->catching_progress == 0) {
        state->state = FISHING_STATE_DELETE_CATCHING_AND_DO_CONTINUATION_STATE;
        state->continuation_state = FISHING_STATE_IT_GOT_AWAY;
        fanfare(271);
    } else if  (state->catching_progress == CATCHING_DURATION) {
        oams[state->oam_idx_catching_fish].private[0] = false; // Stop vibration
        if (state->catching_star_is_present)
            oams[state->oam_idx_catching_star].private[0] = false; // Stop vibration
        fishing_create_stars(state, state->num_stars_collected);
        state->catching_succesfull = true;
        state->state = FISHING_STATE_WAIT_CAUGHT_STARS;
    }
    return false;
}
static bool fishing_wait_caught_stars(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    if (fishing_wait_for_stars(state, state->num_stars_collected)) {
        state->state = FISHING_STATE_DELETE_CATCHING_AND_DO_CONTINUATION_STATE;
        state->continuation_state = FISHING_STATE_CAUGHT;
    }
    return false;
}

static u8 str_got_one_on_hook[] = LANGDEP(
    PSTRING("Du hast ein Pokémon am Haken!PAUSE_UNTIL_PRESS"), 
    PSTRING("You got a Pokémon on the hook!PAUSE_UNTIL_PRESS")
);

static bool fishing_caught(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    (void)str_got_one_on_hook;
    oam_gfx_anim_start(oams + player_state.oam_idx, fishing_get_no_bite_animation_idx_by_facing_direction(player_get_facing()));
    tbox_init_frame_message_and_draw_tilemap(0, true);
    tbox_flush_set(0, 0x11);
    tbox_print_string_set_font_colors_and_spacing_1(0, 2, str_got_one_on_hook, tbox_get_set_speed(), NULL, 2, 1, 3);
    state->state = FISHING_STATE_WAIT_FRAME_TO_PRINT_TEXT;
    return true;
}

static bool fishing_delete_catching_and_do_continuation_state(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    if (state->delay) {
        state->delay--;
        return false;
    }
    if (big_callback_is_active(fanfare_callback_wait))
        return false;
    oam_delete(oams + state->oam_idx_catching_progress_bar);
    oam_delete(oams + state->oam_idx_catching_bar);
    oam_delete(oams + state->oam_idx_catching_fish);
    oam_delete(oams + state->oam_idx_catching_frame);
    if (state->catching_star_is_present)
        oam_delete(oams + state->oam_idx_catching_star);
    oam_free_vram_by_tag(FISHING_OAM_TAG_CATCHING_FRAME);
    oam_free_vram_by_tag(FISHING_OAM_TAG_CATCHING_BAR);
    oam_free_vram_by_tag(FISHING_OAM_TAG_CATCHING_FISH);
    oam_free_vram_by_tag(FISHING_OAM_TAG_CATCHING_PROGRESS);
    state->state = state->continuation_state;
    return false;
}

static u8 str_it_got_away[] = LANGDEP(
    PSTRING("Es ist entkommenDOTSPAUSE_UNTIL_PRESS"), 
    PSTRING("It got awayDOTSPAUSE_UNTIL_PRESS")
);

static bool fishing_it_got_away(u8 self) {
    fishing_proceed_and_align_oams(oams + player_state.oam_idx);
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    oam_gfx_anim_start(oams + player_state.oam_idx, fishing_get_no_bite_animation_idx_by_facing_direction(player_get_facing()));
    tbox_init_frame_message_and_draw_tilemap(0, true);
    tbox_flush_set(0, 0x11);
    tbox_print_string_set_font_colors_and_spacing_1(0, 2, str_it_got_away, tbox_get_set_speed(), NULL, 2, 1, 3);
    state->state = FISHING_STATE_WAIT_FRAME_TO_PRINT_TEXT;
    return true;
}

bool (*fishing_callbacks[NUM_FISHING_STATES])(u8) = {
    [FISHING_STATE_LOCK_PLAYER] = fishing_state_lock,
    [FISHING_STATE_REACH_BACK] = fishing_state_reach_back,
    [FISHING_STATE_INITIALIZE_THROWING] = fishing_state_initialize_throwing,
    [FISHING_STATE_WAIT_FOR_A_TO_START_THROWING] = fishing_state_wait_for_a_to_start_throwing,
    [FISHING_STATE_THROWING] = fishing_state_throwing,
    [FISHING_STATE_THROWN] = fishing_state_thrown,
    [FISHING_STATE_WAIT_THROW_STARS] = fishing_state_wait_throw_stars,
    [FISHING_STATE_PLAYER_THROW_ANIMATION_START] = fishing_player_throw_animation,
    [FISHING_STATE_PLAYER_THROW_ANIMATION_WAIT] = fishing_player_wait,
    [FISHING_STATE_HIDE_THROWING] = fishing_player_hide_throwing,
    [FISHING_STATE_PLAYER_THROW_ANIMATION_WAIT_2] = fishing_player_wait,
    [FISHING_STATE_INITIALIZE_WAIT_FOR_BITE] = fishing_initialize_wait_for_bite,
    [FISHING_STATE_WAIT_FOR_BITE] = fishing_wait_for_bite,
    [FISHING_STATE_NOT_EVEN_A_NIBBLE] = fishing_not_even_a_nibble,
    [FISHING_STATE_WAIT_FRAME_TO_PRINT_TEXT] = fishing_wait_frame_to_print_text,
    [FISHING_STATE_PRINT_TEXT_AND_RELEASE] = fishing_wait_print_text_and_release,
    [FISHING_STATE_RESET_PLAYER_STATE_AND_PRINT_TEXT] = fishing_reset_player_state_and_print_text,
    [FISHING_STATE_BITE_EXCLAMATION_MARK] = fishing_exclamation_mark,
    [FISHING_STATE_BITE_REACT_TO_EXCLAMATION_MARK] = fishing_react_to_exclamation_mark,
    [FISHING_STATE_IT_GOT_AWAY] = fishing_it_got_away,
    [FISHING_STATE_INTIALIZE_CATCHING] = fishing_initialize_catching,
    [FISHING_STATE_CATCHING] = fishing_catching,
    [FISHING_STATE_DELETE_CATCHING_AND_DO_CONTINUATION_STATE] = fishing_delete_catching_and_do_continuation_state,
    [FISHING_STATE_WAIT_CAUGHT_STARS] = fishing_wait_caught_stars,
    [FISHING_STATE_CAUGHT] = fishing_caught,
    [FISHING_STATE_PRINT_TEXT_AND_START_ENCOUNTER] = fishing_wait_print_text_and_start_encounter,
    [FISHING_STATE_START_ENCOUNTER] = fishing_start_encounter,
};

static void fishing_big_callback_do(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callback_get_int(self, 0);
    if (state->state >= ARRAY_COUNT(fishing_callbacks))
        return;
    DEBUG("Fishing state %d\n", state->state);
    while (fishing_callbacks[state->state](self)) {}
}

void fishing_big_callback(u8 self) {
    fishing_state_t *state = malloc_and_clear(sizeof(fishing_state_t));
    big_callback_set_int(self, 0, (int)state);
    big_callbacks[self].function = fishing_big_callback_do;
    big_callbacks[self].function(self);
}

