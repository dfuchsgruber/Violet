

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

static void trigger_callback_animation(oam_object *self) {
    u8 clk = (u8)((self->private[2]++) & 63); // Period of 64
    u8 battler_idx = (u8)(self->private[1]);
    u8 alpha, animation_idx;
    if (MEGA_STATE.marked_for_mega_evolution[battler_idx]) {
        animation_idx = 1;
        if (clk <= 32) {
            alpha = clk;
        } else {
            alpha = (u8)(64 - clk);
        }
    } else {
        animation_idx = 0;
        alpha = 0;
    }
    if (self->anim_number != animation_idx && self->private[0] == MEGA_TRIGGER_IDLE) {
        self->anim_number = animation_idx;
        oam_gfx_anim_init(self, 0);
    }
    
    u8 pal_idx = (u8)((self->final_oam.attr2 >> 12) & 15);
    color_t white = {.rgb = {.red = 31, .blue = 31, .green = 31}};
    pal_blend((u16)(256 + 16 * pal_idx + 5), 12, (u8)MIN(15, alpha / 3), white);
}

static void mega_trigger_oam_callback(oam_object *self) {
    trigger_callback_animation(self);
    u16 *state = self->private;
    u8 battler_idx = (u8)(self->private[1]);
    if(!battler_get_available_mega_evolution(battler_idx)) {
        *state = MEGA_TRIGGER_HIDE; // Whenever the active battler is not eligible to mega evolve, hide the trigger
    }
    switch (*state) {
        case MEGA_TRIGGER_SHOW: { // Show the trigger, i.e. move it upwards
            if (self->y2 <= -32) {
                *state = MEGA_TRIGGER_IDLE;
            } else {
                self->y2 = (s16) MAX(-32, self->y2 - 4);
            }
            break;
        }
        case MEGA_TRIGGER_HIDE: { // Hide the trigger, i.e. move it downwards
            if (self->y2 >= 0) {
                *state = MEGA_TRIGGER_IDLE;
                oam_free(self);
            } else {
                self->y2 = (s16) MIN(0, self->y2 + 4);
            }
            return;
        }
    }
    // Check if the battle controller callback is suitable to show a mega icon
    if (battle_controllers[battler_idx] != battle_controller_player_choose_move &&
        battle_controllers[battler_idx] != battle_controller_player_choose_move_after_dma3 &&
        battle_controllers[battler_idx] != battle_controller_player_initialize_choose_move &&
        battle_controllers[battler_idx] != battle_controller_player_switch_moves) {
        *state = MEGA_TRIGGER_HIDE;
    }
}

static gfx_frame trigger_gfx_anims[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 64, .duration = 0}, {.data = GFX_ANIM_END},
};

static gfx_frame *trigger_gfx_anim_table[] = {
    trigger_gfx_anims + 0,
    trigger_gfx_anims + 2,
};

static sprite trigger_sprite = {ATTR0_MODE_SEMI_TRANSPARENT, ATTR1_SIZE_64_64, ATTR2_PRIO(1), 0};

static graphic trigger_graphics[] = {
    [MEGA_EVOLUTION] = {gfx_mega_triggerTiles, 0x1000, MEGA_TRIGGER_TAG},
    [REGENT_EVOLUTION] = {gfx_regent_triggerTiles, 0x1000, REGENT_TRIGGER_TAG},
};

static oam_template trigger_templates[] = {
    [MEGA_EVOLUTION] = {
        MEGA_TRIGGER_TAG,
        MEGA_TRIGGER_TAG,
        &trigger_sprite,
        trigger_gfx_anim_table,
        NULL,
        oam_rotscale_anim_table_null,
        mega_trigger_oam_callback
    },
    [REGENT_EVOLUTION] = {
        REGENT_TRIGGER_TAG,
        REGENT_TRIGGER_TAG,
        &trigger_sprite,
        trigger_gfx_anim_table,
        NULL,
        oam_rotscale_anim_table_null,
        mega_trigger_oam_callback
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


u8 mega_trigger_oam_idx_get(u8 battler_idx) {
    for (u8 i = 0; i < 0x40; i++) {
        if (oams[i].callback == mega_trigger_oam_callback && 
        (battler_idx = 4 || oams[i].private[1] == battler_idx)) {
            return i;
        }
    }
    return 0x40;
}

void mega_trigger_new(u8 battler_idx) {
    DEBUG("Attempt spawning mega trigger for battler %d\n", battler_idx);
    if (battle_flags & (BATTLE_SAFARI | BATTLE_TUTORIAL))
        return;
    // Check if the battler can perform mega evolution
    mega_evolution_t *mega_evolution = battler_get_available_mega_evolution(battler_idx);
    if (mega_evolution || MEGA_STATE.marked_for_mega_evolution[battler_idx]) {
        u8 mega_trigger_oam = mega_trigger_oam_idx_get(battler_idx);
        if (mega_trigger_oam >= 0x40) {
            // Create a new mega trigger
            u16 tag = trigger_tags[mega_evolution->type];
            if (oam_palette_get_index(tag) == 0xFF) {
                u8 pal_idx = oam_allocate_palette(tag);
                pal_decompress(trigger_pals[mega_evolution->type], (u16)(256 + 16 * pal_idx), 32);
            }
            if (oam_vram_get_tile(tag) == 0xFFFF) {
                oam_load_graphic(trigger_graphics + mega_evolution->type);
            }
            mega_trigger_oam = oam_new_forward_search(trigger_templates + mega_evolution->type, 0x4C, 0x70, 0);
        }
        oams[mega_trigger_oam].private[0] = MEGA_TRIGGER_SHOW;
        oams[mega_trigger_oam].private[1] = battler_idx;
    }
}

void mega_trigger_new_for_active_battler() {
    mega_trigger_new(active_battler);
}

void _battle_controller_player_choose_move_hook(); // This function recovers the original functionality of the handler

// Wraps the original handler. Don't change label to "battle_controller_player_choose_move", as the symbol is referrenced multiple times
void _battle_controller_player_choose_move() {
    mega_evolution_t *mega_evolution = battler_get_available_mega_evolution(active_battler);
    if (super.keys_remapped.keys.B) {
        // Unmark the battler for mega evolution
        MEGA_STATE.marked_for_mega_evolution[active_battler] = 0;
    } else if (mega_evolution && (super.keys_new.keys.l || super.keys_new.keys.r) && super.keys.keys.l && super.keys.keys.r) {
        // Toggle marking
        if (MEGA_STATE.marked_for_mega_evolution[active_battler]) {
            MEGA_STATE.marked_for_mega_evolution[active_battler] = 0;
            play_sound(3);
        } else {
            MEGA_STATE.marked_for_mega_evolution[active_battler] = (u8) mega_evolution->type;
            play_sound(2);
        }
    }
    _battle_controller_player_choose_move_hook();
}

void battle_controller_player_choose_target_wrap() {
    if (super.keys_remapped.keys.B) {
        // When target selection is canceled, try spawning a new mega trigger
        mega_trigger_new(active_battler);
    }
    battle_controller_player_choose_target();
}