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

extern LZ77COMPRESSED gfx_fishing_throw_barTiles;
extern LZ77COMPRESSED gfx_fishing_throw_barPal;
extern LZ77COMPRESSED gfx_fishing_starTiles;

static graphic graphic_throw_bar = {.sprite = gfx_fishing_throw_barTiles, .tag = FISHING_OAM_TAG_THROW, .size = 2 * GRAPHIC_SIZE_4BPP(32, 16) + 2 * GRAPHIC_SIZE_4BPP(32, 8)};
static graphic graphic_star = {.sprite = gfx_fishing_starTiles, .tag = FISHING_OAM_TAG_STAR, .size = 5 * GRAPHIC_SIZE_4BPP(16, 16)};
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

static u8 fishing_get_throw_rating(u8 throw_bar_value) {
    if (throw_bar_value < 35)
        return 0;
    else if (throw_bar_value < 80)
        return 1;
    else if (throw_bar_value < 100)
        return 2;
    else
        return 3;
}

static void oam_callback_throw_bar_shake(oam_object *self) {
    fishing_state_t *state = (fishing_state_t*)big_callbacks[self->private[0]].params;
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

static sprite sprite_star = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0)};

static gfx_frame animation_star_empty[] = {{.data = 1 * GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame animation_star_1[] = {{.data = 2 * GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame animation_star_2[] = {{.data = 3 * GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame animation_star_3[] = {{.data = 4 * GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame animation_star_full[] = {{.data = 0 * GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8), .duration = 0}, {.data = GFX_ANIM_END}};

static gfx_frame *animations_star[] = {
    [FISHING_STAR_EMPTY] = animation_star_empty,
    [FISHING_STAR_1] = animation_star_1,
    [FISHING_STAR_2] = animation_star_2,
    [FISHING_STAR_3] = animation_star_3,
    [FISHING_STAR_FULL] = animation_star_full,
};

static oam_template oam_template_star = {
    .tiles_tag = FISHING_OAM_TAG_STAR, .pal_tag = FISHING_OAM_TAG_THROW,
    .graphics = NULL, .oam = &sprite_star, .animation = animations_star,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static bool fishing_state_lock(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callbacks[self].params;
    player_state.is_locked = true;
    overworld_script_set_active();
    state->state++;
    return true;
}

static u8 fishing_reach_back_animations[] = {
    [DIR_DOWN] = 12,
    [DIR_UP] = 13,
    [DIR_LEFT] = 14,
    [DIR_RIGHT] = 15,
};

static bool fishing_state_reach_back(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callbacks[self].params;
    npc *n = npcs + player_state.npc_idx;
    state->backup_overworld_idx = n->overworld_id;
    npc_clear_held_movement_if_active(n);
    n->flags.animation_enabled = true;
    player_transition(PLAYER_TRANSITION_FISH);
    state->state++;
    oam_gfx_anim_start(oams + n->oam_id, fishing_reach_back_animations[n->direction.facing]);
    return false;
}

static bool fishing_state_initialize_throwing(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callbacks[self].params;
    state->throw_bar_progress_tile_idx = oam_load_graphic(&graphic_throw_bar);
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
        fishing_state_t *state = (fishing_state_t*)big_callbacks[self].params;
        state->throw_bar_value = 0;
        state->state++;
        return true;
    }
    return false;
}

#define THROWING_PERFECT_FRAME_EXTRA_MARGIN 1
#define THROWING_SPEED 3

static bool fishing_state_throwing(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callbacks[self].params;
    // state->throw_bar_progress = (u8)((state->throw_bar_progress + 3) & 0xFF);
    // FIXED cos = FIXED_COS(FIXED_DIV(INT_TO_FIXED(state->throw_bar_progress), INT_TO_FIXED(256)));
    // // cos is in [-1, 1], we will shift to [0, 100]
    // // we want it to start at 0, but cos starts at 1
    // // therefore, we use -cos(x), which starts at -1
    // // we offset by +1 (so it starts at 0) and multiply by 0.5
    // cos = FIXED_ADD(INT_TO_FIXED(1), -cos);
    // cos = FIXED_MUL(INT_TO_FIXED(50), cos);
    // state->throw_bar_value = (u8)FIXED_TO_INT(cos);
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
    cpuset(state->sprite_throw_bar_progress, OAMCHARBASE(state->throw_bar_progress_tile_idx + 
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

static bool fishing_state_thrown(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callbacks[self].params;
    u8 num_stars = fishing_get_throw_rating(state->throw_bar_value);
    oam_load_graphic(&graphic_star);
    for (int i = 0; i < num_stars; i++) {
        s16 x = (s16)(star_x_anchors[i] + (rnd16() % 8));
        s16 y = (s16)(30 - (rnd16() % 10));
        state->oam_idx_star[i] = oam_new_forward_search(&oam_template_star, x, y, 1);
        oam_object *o = oams + state->oam_idx_star[i];
        o->y2 = 20;
        o->private[0] = (u16)(rnd16() % 16);
        oam_gfx_anim_start(o, FISHING_STAR_FULL);
        o->callback = star_animation_disappear;
        o->callback(o);
    }
    state->state++;
    return true;
}

static bool fishing_state_wait_throw_stars(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callbacks[self].params;
    u8 num_stars = fishing_get_throw_rating(state->throw_bar_value);
    bool finished = true;
    for (int i = 0; i < num_stars; i++) {
        if (oams[state->oam_idx_star[i]].callback == star_animation_disappear) {
            finished = false;
        }
    }
    if (finished) {
        for (int i = 0; i < num_stars; i++) {
            oam_delete(oams + state->oam_idx_star[i]);
        }
        oam_free_vram_by_tag(FISHING_OAM_TAG_STAR);
        state->state++;
    }
    return false;
}

bool (*fishing_callbacks[NUM_FISHING_STATES])(u8) = {
    [FISHING_STATE_LOCK_PLAYER] = fishing_state_lock,
    [FISHING_STATE_REACH_BACK] = fishing_state_reach_back,
    [FISHING_STATE_INITIALIZE_THROWING] = fishing_state_initialize_throwing,
    [FISHING_STATE_WAIT_FOR_A_TO_START_THROWING] = fishing_state_wait_for_a_to_start_throwing,
    [FISHING_STATE_THROWING] = fishing_state_throwing,
    [FISHING_STATE_THROWN] = fishing_state_thrown,
    [FISHING_STATE_WAIT_THROW_STARS] = fishing_state_wait_throw_stars,
};

void fishing_big_callback(u8 self) {
    fishing_state_t *state = (fishing_state_t*)big_callbacks[self].params;
    if (state->state >= ARRAY_COUNT(fishing_callbacks))
        return;
    while (fishing_callbacks[state->state](self)) {}
}

