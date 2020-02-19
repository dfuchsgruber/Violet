

#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "mega.h"
#include "color.h"
#include "bios.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "battle/controller.h"
#include "constants/battle/battle_actions.h"
#include "superstate.h"
#include "music.h"
#include "math.h"
#include "debug.h"
#include "fading.h"
#include "save.h"
#include "callbacks.h"

extern const unsigned gfx_mega_triggerTiles[];
extern const unsigned gfx_mega_triggerPal[];
extern const unsigned gfx_regent_triggerTiles[];
extern const unsigned gfx_regent_triggerPal[];

static void trigger_oam_remove() {
    fmem.mega_state.trigger_oam_removing = 1;
    oams[fmem.mega_state.trigger_oam].private[0] = 1;
}

static void trigger_callback(oam_object *self) {
    u16 *state = self->private;
    switch (*state) {
        case 0: { // Show the trigger, i.e. move it upwards
            if (self->y2 <= -32) {
                *state = 2; // Idle state
            } else {
                self->y2 = (s16) MAX(-32, self->y2 - 4);
            }
            break;
        }
        case 1: { // Hide the trigger, i.e. move it downwards
            if (self->y2 >= 0) {
                fmem.mega_state.trigger_oam_removing = 0; // This oam has finished removing
                oam_free(self);
            } else {
                fmem.mega_state.trigger_oam_removing = 1; // This oam is currently removing
                self->y2 = (s16) MIN(0, self->y2 + 4);
            }
            break;
        }
    }
    u8 clk = (u8)((self->private[1]++) & 63); // Period of 64
    if (!fading_control.active) {
        u8 alpha;
        if (clk <= 32) {
            alpha = clk;
        } else {
            alpha = (u8)(64 - clk);
        }
        u8 pal_idx = (u8)((self->final_oam.attr2 >> 12) & 15);
        color_t white = {.rgb = {.red = 31, .blue = 31, .green = 31}};
        pal_blend((u16)(256 + 16 * pal_idx), 7, (u8)MIN(15, alpha / 2), white);
    }
}

static void callback_marked_animation(u8 self) {
    u8 clk = (u8)((big_callbacks[self].params[0]++) & 63); // Period of 64
    for (u8 battler_idx = 0; battler_idx < battler_cnt; battler_idx++) {
        u8 alpha = 0;
        if (fmem.mega_state.marked_for_mega_evolution & (1 << battler_idx)) {
            if (clk <= 32) {
                alpha = clk;
            } else {
                alpha = (u8)(64 - clk);
            }
        }
        // This overrides fading control, maybe there is a better way to indicate a mon is marked for mega evo?
        u8 pal_idx = (u8)((oams[battler_oams[battler_idx]].final_oam.attr2 >> 12) & 15);
        dprintf("Alpha for battler %d with pal_idx %d is %d\n", battler_idx, pal_idx, alpha);
        color_t white = {.rgb = {.red = 31, .blue = 31, .green = 31}};
        pal_blend((u16)(256 + 16 * pal_idx), 16, (u8)MIN(15, alpha / 2), white);
    }
}

static sprite trigger_sprite = {ATTR0_MODE_SEMI_TRANSPARENT, ATTR1_SIZE_64_64, ATTR2_PRIO(1), 0};

static graphic trigger_graphics[] = {
    [MEGA_EVOLUTION] = {gfx_mega_triggerTiles, 0x800, MEGA_TRIGGER_TAG},
    [REGENT_EVOLUTION] = {gfx_regent_triggerTiles, 0x800, REGENT_TRIGGER_TAG},
};

static oam_template trigger_templates[] = {
    [MEGA_EVOLUTION] = {
        MEGA_TRIGGER_TAG,
        MEGA_TRIGGER_TAG,
        &trigger_sprite,
        oam_gfx_anim_table_null,
        NULL,
        oam_rotscale_anim_table_null,
        trigger_callback
    },
    [REGENT_EVOLUTION] = {
        REGENT_TRIGGER_TAG,
        REGENT_TRIGGER_TAG,
        &trigger_sprite,
        oam_gfx_anim_table_null,
        NULL,
        oam_rotscale_anim_table_null,
        trigger_callback
    },
};

static const void *trigger_pals[] = {
    [MEGA_EVOLUTION] = gfx_mega_triggerPal,
    [REGENT_EVOLUTION] = gfx_regent_triggerPal,
};

static u16 trigger_tags[] = {
    [MEGA_EVOLUTION] = MEGA_TRIGGER_TAG,
    [REGENT_EVOLUTION] = REGENT_TRIGGER_TAG,
};

// Wrapper for choosing an action. If the action is to use a move, show the mega trigger icon.
void _battle_controller_player_choose_action() {
    if (super.keys_remapped.keys.A && battle_selected_action[active_battler] == 0) {
        mega_evolution_t *mega_evolution = battler_get_available_mega_evolution(active_battler);
        if (mega_evolution) {
            // Check if a trigger is currently being removed
            if (fmem.mega_state.trigger_oam_removing) {
                oams[fmem.mega_state.trigger_oam].private[0] = 0; // Change its state to appearing
                fmem.mega_state.trigger_oam_removing = 0;
            } else {
                u16 tag = trigger_tags[mega_evolution->type];
                if (oam_palette_get_index(tag) == 0xFF) {
                    u8 pal_idx = oam_allocate_palette(tag);
                    pal_decompress(trigger_pals[mega_evolution->type], (u16)(256 + 16 * pal_idx), 32);
                }
                if (oam_vram_get_tile(tag) == 0xFFFF) {
                    oam_load_graphic(trigger_graphics + mega_evolution->type);
                }
                fmem.mega_state.trigger_oam = oam_new_forward_search(trigger_templates + mega_evolution->type, 0x4C, 0x70, 0);
            }
        }
    }
    battle_controller_player_choose_action();
}

// Wrapper for choosing a move. If B is pressed, the trigger is deleted. If L & R are pressed, the pokemon is marked for mega evolution.
void _battle_controller_player_choose_move() {
    if (battler_get_available_mega_evolution(active_battler)) {
        if (super.keys_remapped.keys.B) {
            if (fmem.mega_state.marked_for_mega_evolution & (1 << active_battler)) { // Unmark the battler for mega evolution 
                fmem.mega_state.marked_for_mega_evolution = (u8)(
                    (fmem.mega_state.marked_for_mega_evolution & ~(1 << active_battler)) & 15
                );
                u8 animation_cb_idx = big_callback_get_id(callback_marked_animation);
                if (animation_cb_idx != 0xFF)
                    big_callback_delete(animation_cb_idx);
            } else { // Battler was not marked, thus remove the trigger only
                trigger_oam_remove();
            }
        } else if (super.keys.keys.l && super.keys.keys.r &&
                    !(fmem.mega_state.marked_for_mega_evolution & (1 << active_battler))) {
            // Mark the battler for mega evolution and remove the trigger
            fmem.mega_state.marked_for_mega_evolution = (u8)(
                (fmem.mega_state.marked_for_mega_evolution | (1 << active_battler)) & 15
            );
            big_callback_new(callback_marked_animation, 31);
            trigger_oam_remove();
            play_sound(184);
        }
        // dprintf("Markings for mega 0x%x\n", fmem.mega_state.marked_for_mega_evolution);
    }
    battle_controller_player_choose_move();
}
