#include "types.h"
#include "overworld/sprite.h"
#include "overworld/script.h"
#include "color.h"
#include "save.h"
#include "debug.h"
#include "flags.h"
#include "vars.h"
#include "agbmemory.h"
#include "prng.h"
#include "overworld/misc.h"
#include "math.h"
#include "music.h"
#include "constants/species.h"
#include "constants/overworld/misc.h"
#include "callbacks.h"
#include "io.h"
#include "music.h"

#define NUM_UNOWNS 5

static s16 unowns_positions[NUM_UNOWNS][2] = {
    {0x1C, 0xA},
    {0x1E, 0xA},
    {0x1D, 0x8},
    {0x1C, 0x9},
    {0x1D, 0xA},
};

static u16 unown_species[NUM_UNOWNS] = {
    POKEMON_ICOGNITO_W,
    POKEMON_ICOGNITO_O,
    POKEMON_ICOGNITO_D,
    POKEMON_ICOGNITO_K,
    POKEMON_ICOGNITO,
};

static u16 unown_delays[NUM_UNOWNS + 1] = {
    0,
    20,
    40,
    70,
    80,
    100, // state-switch
};

typedef struct {
    u8 state;
    u8 oams[NUM_UNOWNS];
    u16 clk;
} unowns_state_t;

#define FLOATING_PERIOD 64

static void unown_oam_callback_float (oam_object *self) {
    u16 frame = self->private[7]++;
    FIXED y = FIXED_SIN(FIXED_DIV(INT_TO_FIXED(frame), INT_TO_FIXED(FLOATING_PERIOD)));
    y = FIXED_MUL(y, INT_TO_FIXED(2));
    self->y2 = (s16)(FIXED_TO_INT(y));
}

#define FADING_DURATION 16

static void unown_oam_callback_transparent_fade_in_and_float(oam_object *self) {
    u16 *frame = self->private + 6;
    unown_oam_callback_float(self);
    int to = 0;
    int from = 31;
    FIXED dx = INT_TO_FIXED(FADING_DURATION);
    FIXED dy = INT_TO_FIXED(to - from);
    FIXED m = FIXED_DIV(dy, dx);
    int y = FIXED_TO_INT(FIXED_ADD(INT_TO_FIXED(from), FIXED_MUL(m, INT_TO_FIXED(*frame))));
    io_set(IO_BLDALPHA, (u16)(IO_BLDALPHA_EVA(31 - y) | IO_BLDALPHA_EVB(y)));
    if (31 <= y) {
        self->flags |= OAM_FLAG_INVISIBLE;
    } else {
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    }
    ++*frame;
    if (y == 0) {
        self->callback = unown_oam_callback_float;
        self->final_oam.attr0 &= (u16)~(ATTR0_MODE_SEMI_TRANSPARENT);
    }
}

static void unown_oam_callback_fly_away(oam_object *self) {
    if (self->private[5]++ < 12) {
        self->y2 = (s16)(self->y2 - 8);
    }
}

static void callback_create_unowns(u8 self) {
    unowns_state_t *state = (unowns_state_t*)big_callback_get_int(self, 0);
    switch (state->state) {
        case 0: {
            map_event_person person = {0};
            for (int i = 0; i < NUM_UNOWNS; i++) {
                u16 species = unown_species[i];
                person.overworld_index = overworld_get_sprite_idx_by_species(species);
                person.value = species;
                u8 oam_idx = overworld_create_oam_by_person(&person, 0, unowns_positions[i][0], unowns_positions[i][1], 4, DIR_DOWN);
                oams[oam_idx].callback = oam_null_callback;
                oams[oam_idx].flags = (u16)(oams[oam_idx].flags | OAM_FLAG_INVISIBLE);
                oams[oam_idx].final_oam.attr0 |= ATTR0_MODE_SEMI_TRANSPARENT;
                state->oams[i] = oam_idx;
            }
            state->clk = 0;
            state->state++;
            io_set(IO_BLDCNT, IO_BLDCNT_ALPHA_BLENDING | IO_BLDCNT_BG0_SECOND | IO_BLDCNT_BG1_SECOND | 
                IO_BLDCNT_BG2_SECOND | IO_BLDCNT_BG3_SECOND | IO_BLDCNT_BACKDROP_SECOND | 
                IO_BLDCNT_OBJ_FIRST);
            io_set(IO_BLDALPHA, (u16)(IO_BLDALPHA_EVA(31) | IO_BLDALPHA_EVB(0)));

            break;
        }
        case 1: {
            u16 clk = state->clk++;
            for (int i = 0; i <= NUM_UNOWNS; i++) {
                if (unown_delays[i] == clk) {
                    if (i == NUM_UNOWNS) { // state-switch
                        state->state++;
                        return;
                    } else {
                        u8 oam_idx = state->oams[i];
                        oams[oam_idx].callback = unown_oam_callback_transparent_fade_in_and_float;
                        play_sound(107);
                    }
                }
            }
            break;
        }
        case 2: {
            overworld_script_resume();
            state->clk = 0;
            state->state++;
            break;
        }
        case 3: {
            // Idle, wait for the script to continue
            break;
        }
        case 4: {
            u16 clk = state->clk++;
            for (int i = 0; i <= NUM_UNOWNS; i++) {
                if (unown_delays[i] == clk) {
                    if (i == NUM_UNOWNS) { // state-switch
                        state->state++;
                        return;
                    } else {
                        u8 oam_idx = state->oams[i];
                        oams[oam_idx].callback = unown_oam_callback_fly_away;
                        play_sound(128);
                    }
                }
            }
            break;
        }
        case 5: {
            for (int i = 0; i < NUM_UNOWNS; i++)
                oam_free(oams + state->oams[i]);
            free(state);
            big_callback_delete(self);
            overworld_script_resume();
        }
    }
}

void map_sonnaufeld_clouds_create_unowns() {
    u8 cb_idx = big_callback_new(callback_create_unowns, 0xA);
    unowns_state_t *state = malloc_and_clear(sizeof(unowns_state_t));
    state->state = 0;
    big_callback_set_int(cb_idx, 0, (int)state);
}

void map_sonnaufeld_clouds_unowns_fly() {
    u8 cb_idx = big_callback_get_id(callback_create_unowns);
    if (cb_idx != 0xFF) {
        unowns_state_t *state = (unowns_state_t*)big_callback_get_int(cb_idx, 0);
        state->state++;
    }
}