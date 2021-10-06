#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "debug.h"
#include "color.h"
#include "math.h"
#include "io.h"
#include "bios.h"
#include "anim_engine.h"
#include "music.h"

#define LIGHTNING_TAG 0x1AAB

extern const u8 gfx_cutscene_unown_shrine_lightningTiles[];
extern const u8 gfx_cutscene_unown_shrine_lightningPal[];

static sprite lightning_sprite = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_64_64, ATTR2_PRIO(2), 0
};

static graphic unown_shrine_lightning_graphic[] = {
    [0] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 0 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [1] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 1 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [2] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 2 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [3] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 3 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [4] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 4 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [5] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 5 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [6] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 6 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [7] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 7 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [8] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 8 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [9] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 9 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [10] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 10 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [11] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 11 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [12] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 12 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [13] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 13 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [14] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 14 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [15] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 15 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [16] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 16 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [17] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 17 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [18] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 18 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
    [19] = {.sprite = gfx_cutscene_unown_shrine_lightningTiles + 19 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64), .tag = LIGHTNING_TAG},
};

#define LIGHTNING_FRAME_DURATION 4
#define LIGHTNING_EMPTY 19

static gfx_frame lightning_anim_idle[] = {
    {.data = LIGHTNING_EMPTY, .duration = 0}, {.data = GFX_ANIM_END}
};

static gfx_frame lightning_anim_upper[] = {
    {.data = LIGHTNING_EMPTY, .duration = 0},
    {.data = 0 * 2, .duration = LIGHTNING_FRAME_DURATION},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION}, // empty
    {.data = 1 * 2, .duration = LIGHTNING_FRAME_DURATION},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION}, // empty
    {.data = 2 * 2, .duration = LIGHTNING_FRAME_DURATION}, 
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION}, // empty
    {.data = 1 * 2, .duration = LIGHTNING_FRAME_DURATION},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION}, // empty & whole screen to white
    {.data = 3 * 2, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 4 * 2, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 5 * 2, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 6 * 2, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 7 * 2, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 8 * 2, .duration = LIGHTNING_FRAME_DURATION},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = GFX_ANIM_JUMP, .duration = 0}, 
};

static gfx_frame lightning_anim_lower[] = {
    {.data = LIGHTNING_EMPTY, .duration = 0},
    {.data = 0 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION}, // empty
    {.data = 1 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION}, // empty
    {.data = 2 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION}, 
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION}, // empty
    {.data = 1 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION}, // empty & whole screen to white
    {.data = 3 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 4 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 5 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 6 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 7 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION},
    {.data = 8 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = GFX_ANIM_JUMP, .duration = 0}, 
};


static gfx_frame lightning_anim_upper_flipped[] = {
    {.data = LIGHTNING_EMPTY, .duration = 0},
    {.data = 0 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, // empty
    {.data = 1 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, // empty
    {.data = 2 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, 
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, // empty
    {.data = 1 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, // empty & whole screen to white
    {.data = 3 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 4 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 5 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 6 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 7 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 8 * 2, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = GFX_ANIM_JUMP, .duration = 0}, 
};

static gfx_frame lightning_anim_lower_flipped[] = {
    {.data = LIGHTNING_EMPTY, .duration = 0},
    {.data = 0 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, // empty
    {.data = 1 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, // empty
    {.data = 2 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, 
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, // empty
    {.data = 1 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = LIGHTNING_EMPTY, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP}, // empty & whole screen to white
    {.data = 3 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 4 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 5 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 6 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 7 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = 8 * 2 + 1, .duration = LIGHTNING_FRAME_DURATION | GFX_ANIM_HFLIP},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = LIGHTNING_EMPTY, .duration = 32},
    {.data = GFX_ANIM_JUMP, .duration = 0}, 
};


static gfx_frame *lightning_anims[] = {
    [0] = lightning_anim_idle,
    [2] = lightning_anim_lower,
    [1] = lightning_anim_upper,
    [3] = lightning_anim_upper_flipped,
    [4] = lightning_anim_lower_flipped,
};

static u8 lightnings_anim_idxs[2][2] = {
    {1, 2},
    {3, 4},
};

static void lightning_sound_callback (oam_object *self) {
    int period = 14 * LIGHTNING_FRAME_DURATION + 3 * 32;
    if (self->anim_number != 0) {
        u16 frame = self->private[7]++;
        if (self->private[7] >= period)
            self->private[7] = 0;
        if (frame == 0) {
            // play_sound(111); // interferes with the earthquake sound
        }
    }
}

static oam_template lightning_template = {
    .tiles_tag = 0xFFFF, .pal_tag = LIGHTNING_TAG,
    .oam = &lightning_sprite, .animation = lightning_anims,
    .graphics = unown_shrine_lightning_graphic, .rotscale = oam_rotscale_anim_table_null,
    .callback = lightning_sound_callback,
};

#define NUM_LIGHTNINGS 4

static s16 lightning_coordinates[NUM_LIGHTNINGS][2] = {
    {40, 64}, 
    {240 - 32, 64},
    {80, 72},
    {240 - 112, 69},
};

static u16 lightning_delays[NUM_LIGHTNINGS] = {
    0, 82, 104, 40,
};

static u8 lightning_flipped[NUM_LIGHTNINGS] = {false, true, true, false};

typedef struct {
    u8 state;
    u8 screen_white;
    u16 setup_clk;
    u8 lightnings[NUM_LIGHTNINGS][2];
} lightning_state_t;

static inline int earthquake_displacement(int frame, int period, int amplitude, FIXED cushion) {
    FIXED sin_arg = FIXED_DIV(INT_TO_FIXED(frame), INT_TO_FIXED(period));
    FIXED trig_applied = FIXED_MUL(FIXED_SIN(sin_arg), INT_TO_FIXED(amplitude));
    // Apply decay function
    int decay = hwt(frame/period, FIXED_TO_INT(FIXED_DIV(INT_TO_FIXED(period), cushion)), 0x10000);
    return (FIXED_TO_INT(trig_applied) * decay) / 0x10000;
}

void unown_shrine_animation_lightning_callback(anim_engine_task *self) {
    lightning_state_t *state = (lightning_state_t*)self->vars;
    switch (state->state) {
        case 0: {
            for (int i = 0; i < NUM_LIGHTNINGS; i++) {
                for (int j = 0; j < 2; j++) {
                    state->lightnings[i][j] = oam_new_forward_search(&lightning_template, lightning_coordinates[i][0], (s16)(lightning_coordinates[i][1] + 64 * j), 0);
                    oam_gfx_anim_start(oams + state->lightnings[i][j], 0);
                }
            }
            state->setup_clk = 0;
            state->state++;
            break;
        }
        case 1: {
            u16 clk = state->setup_clk++;
            // process the earthquacke
            int displacement = earthquake_displacement(clk, 8, 7, FIXED_DIV(INT_TO_FIXED(12), INT_TO_FIXED(10)));
            int lightning_displacement = earthquake_displacement(clk + 1, 8, 7, FIXED_DIV(INT_TO_FIXED(11), INT_TO_FIXED(10)));
            int temple_displacement = MIN(0, 80 * clk / (3 * 80) - 64);
            io_set(IO_BGVOFS(1), (u16)(temple_displacement));
            io_set(IO_BGHOFS(0), (u16)(displacement + 8));
            io_set(IO_BGHOFS(1), (u16)(displacement + 8));
            io_set(IO_BGHOFS(2), (u16)(displacement + 8));
            for (int i = 0; i < NUM_LIGHTNINGS; i++) {
                if (clk == lightning_delays[i]) {
                    u8 flipped = lightning_flipped[i];
                    for (int j = 0; j < 2; j++) {
                        oam_gfx_anim_start(oams + state->lightnings[i][j], lightnings_anim_idxs[flipped][j]);
                    }
                }
                for (int j = 0; j < 2; j++) {
                    oams[state->lightnings[i][j]].x2 = (s16)(-lightning_displacement);
                }
            }
            if (clk >= 216) {
                state->state++;
            }
            break;
        }
        case 2: {
            for (int i = 0; i < NUM_LIGHTNINGS; i++) {
                for (int j = 0; j < 2; j++)
                    oam_gfx_anim_start(oams + state->lightnings[i][j], 0);
            }
            anim_engine_task_delete(self);
            state->state++;
            break;
        }
    }
}


