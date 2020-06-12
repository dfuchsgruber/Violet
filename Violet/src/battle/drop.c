#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "item/item.h"
#include "constants/items.h"
#include "battle/battlescript.h"
#include "battle/battle_string.h"
#include "debug.h"
#include "callbacks.h"
#include "oam.h"
#include "battle/attack.h"
#include "music.h"
#include "text.h"
#include "battle/bg.h"
#include "bg.h"
#include "dma.h"
#include "superstate.h"
#include "language.h"

bool battler_drop_item(u8 battler_idx, u16 *item, u8 *quantity) {

    // TODO
    switch (BATTLE_STATE2->num_items_dropped[battler_idx]) {
        case 0:
            *item = ITEM_WUNDERSTAUB;
            *quantity = 2;
            return true;
        case 1:
            *item = ITEM_POKEBALL;
            *quantity = 3;
            return true;
        case 3:
            *item = ITEM_TRANK;
            *quantity = 4;
            return true;
        case 2:
            *item = ITEM_AMRENABEERE;
            *quantity = 1;
            return true;
        default: 
            return false;
    }
}

static void battle_item_drop_compact(u8 battler_idx) {
    for (int i = 0; i < BATTLE_STATE2->num_items_dropped[battler_idx]; i++) {
        u16 item = BATTLE_STATE2->items_dropped[battler_idx][i];
        for (int j = i + 1; j < BATTLE_STATE2->num_items_dropped[battler_idx]; j++) {
            if (BATTLE_STATE2->items_dropped[battler_idx][j] == item) {
                // Aggregate the same items
                BATTLE_STATE2->items_dropped_cnt[battler_idx][i] = (u8) (BATTLE_STATE2->items_dropped_cnt[battler_idx][i] + 
                    BATTLE_STATE2->items_dropped_cnt[battler_idx][j]);
                // Remove the aggregated item by swapping with the last one and reducing the list length
                BATTLE_STATE2->items_dropped[battler_idx][j] = BATTLE_STATE2->items_dropped[battler_idx][--BATTLE_STATE2->num_items_dropped[battler_idx]];
            }
        }
    }
}

extern u8 battlescript_itemdrop[];
extern u8 battlescript_print_payday_money[];
extern u8 battlescript_itemdrop_picked_up[];
extern u8 battlescript_itemdrop_picked_up_no_space[];

enum {
    DROPPING_PAYDAY = 0,
    DROPPING_INIT,
    DROP_ITEM,
    DROPPING_DONE,
    SUMMARY_INIT,
    SUMMARY_DRAW_TEXT,
    SUMMARY_WAIT_FOR_DMA3,
    SUMMARY_WAIT_FOR_INPUT,
    SUMMARY_CLEAR,
    SUMMARY_DONE,
};

static tbox_font_colormap item_drop_summary_fontcolmap = { .background = 0xE, .body = 0xD, .edge = 0xF};

static u8 battle_item_drop_summary_tbox_new() {
    int height = 2 * BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler] + 2;
    tboxdata template = {0};
    tbox_data_new(&template, 1, 14, 9, 15, (u8)height, 5, 0x100); // Basically re-uses all the tiles of the "standard" gp battle tbox, which is too small
    return tbox_new(&template);
}

static void battle_item_drop_draw_summary_text() {
    // TODO
    u8 title[] = LANGDEP(PSTRING("Items erhalten:"), PSTRING("Items received"));
    tbox_print_string(BATTLE_STATE2->item_dropping_summary_tbox_idx, 2, 0, 0, 0, 0, &item_drop_summary_fontcolmap, 0xFF, title);
    for (int i = 0; i < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]; i++) {
        u16 item = BATTLE_STATE2->items_dropped[BATTLE_STATE2->item_dropping_battler][i];
        u8 cnt = BATTLE_STATE2->items_dropped_cnt[BATTLE_STATE2->item_dropping_battler][i];
        tbox_print_string(BATTLE_STATE2->item_dropping_summary_tbox_idx, 2, 8, (u16)(16 + (16 * i)), 0, 0, 
            &item_drop_summary_fontcolmap, 0xFF, item_get_name(item));
        if (item_has_room(item, cnt)) {
            itoa(strbuf, cnt, ITOA_PAD_SPACES, 2);
            u8 str_cnt[] = PSTRING("x");
            strcat(strbuf, str_cnt);
        } else {
            u8 str_full[] = LANGDEP(PSTRING("voll"), PSTRING("full"));
            strcpy(strbuf, str_full);
        }
        tbox_print_string(BATTLE_STATE2->item_dropping_summary_tbox_idx, 2, 96, (u16)(16 + (16 * i)), 0, 0, 
            &item_drop_summary_fontcolmap, 0xFF, strbuf);
    }
}

/**
static void item_drop_summary_battle_gp_tbox_draw(u8 mode) {
    battle_gp_tbox_draw(18, 7, 29, (u8)(2 * BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler] + 2 + 9), mode);
}
**/

void bsc_cmd_itemdrop_and_payday() {
    // dprintf("Payday in state %d\n", BATTLE_STATE2->item_dropping_state);
    switch (BATTLE_STATE2->item_dropping_state) {
        case DROPPING_PAYDAY: {
            BATTLE_STATE2->item_dropping_state++;
            if (!(battle_flags & BATTLE_LINK) && battle_payday_money > 0) {
                u32 amount =(u32)(battle_payday_money * battle_state->money_multiplier);
                money_add(&save1->money, amount);
                BSC_BUFFER_HWORD(bsc_string_buffer0, 5, amount);
                battlescript_callstack_push_next_command();
                bsc_offset = battlescript_print_payday_money;
                return;
            }
            break;
        }
        case DROPPING_INIT:  {
            BATTLE_STATE2->item_dropping_battler = 0;
            for (int i = 0; i < MAX_ITEMS_DROPPED_PER_BATTLER; i++)
                BATTLE_STATE2->items_dropped_oams[i] = 0xFF;

            for (u8 i = 0; i < battler_cnt; i++) {
                if (battler_is_opponent(i)) {
                    u16 item = 0;
                    u8 cnt = 0;
                    do {
                        if (battler_drop_item(i, &item, &cnt)) {
                            BATTLE_STATE2->items_dropped[i][BATTLE_STATE2->num_items_dropped[i]] = item;
                            BATTLE_STATE2->items_dropped_cnt[i][BATTLE_STATE2->num_items_dropped[i]] = cnt;
                            BATTLE_STATE2->num_items_dropped[i]++;
                            dprintf("Battler %d dropped item %d (cnt=%d)\n", i, item, cnt);
                        } else {
                            break;
                        }
                    } while (item != 0 && BATTLE_STATE2->num_items_dropped[i] < MAX_ITEMS_DROPPED_PER_BATTLER);
                    battle_item_drop_compact(i);
                    /**
                    // Try to add the items to the player's inventory and remove non-addable items (i.e. bag full)
                    for (int j = 0; j < BATTLE_STATE2->num_items_dropped[i]; j++) {
                        item = BATTLE_STATE2->items_dropped[i][j];
                        if (!item_has_room(item, 1)) { // This item can't be dropped, remove it from the list, i.e. swap it with the last element and shrink the list's size
                            BATTLE_STATE2->items_dropped[i][j] = BATTLE_STATE2->items_dropped[i][BATTLE_STATE2->num_items_dropped[i] - 1];
                            BATTLE_STATE2->num_items_dropped[i]--;
                        }
                    }
                    **/
                    // Debugging:
                    for (int j = 0; j < BATTLE_STATE2->num_items_dropped[i]; j++) {
                        dprintf("Player obtained item %d %d-times from battler %d\n", BATTLE_STATE2->items_dropped[i][j], BATTLE_STATE2->items_dropped_cnt[i][j], j);
                    }
                } else {
                    BATTLE_STATE2->num_items_dropped[i] = 0; // Only opponents can drop items
                }
            }
            BATTLE_STATE2->item_dropping_state++;
        }
        FALL_THROUGH;
        case DROP_ITEM: {
            for(; BATTLE_STATE2->item_dropping_battler < battler_cnt; BATTLE_STATE2->item_dropping_battler++) {
                if (!(BATTLE_STATE2->items_dropped_done & int_bitmasks[BATTLE_STATE2->item_dropping_battler])) {
                    BATTLE_STATE2->items_dropped_done = (u8)(BATTLE_STATE2->items_dropped_done | int_bitmasks[BATTLE_STATE2->item_dropping_battler]);
                    if (BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler] > 0) {
                        // Add the items
                        for (int i = 0; i < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]; i++) {
                            u16 item = BATTLE_STATE2->items_dropped[BATTLE_STATE2->item_dropping_battler][i];
                            u8 cnt = BATTLE_STATE2->items_dropped_cnt[BATTLE_STATE2->item_dropping_battler][i];
                            if (item_has_room(item, cnt))
                                item_add(item, cnt);
                        }
                        battle_scripting.battler_idx = BATTLE_STATE2->item_dropping_battler;
                        battlescript_callstack_push_next_command();
                        bsc_offset = battlescript_itemdrop;
                        BATTLE_STATE2->item_to_pickup = 0;
                        BATTLE_STATE2->item_dropping_state = SUMMARY_INIT;
                        return;
                    }
                }
            }
            BATTLE_STATE2->item_dropping_state++;
        }
        FALL_THROUGH;
        case DROPPING_DONE: {
            bsc_offset++;
            return;
        }
        case SUMMARY_INIT: {
            fanfare(257);
            battle_bg1_x = 0;
            battle_bg1_y = 256;
            bg_set_attribute(0, BG_ATTR_PRIORITY, 1);
            bg_set_attribute(1, BG_ATTR_PRIORITY, 0);
            bg_sync_display_and_show(0);
            bg_sync_display_and_show(1);
            BATTLE_STATE2->item_dropping_summary_tbox_idx = battle_item_drop_summary_tbox_new();
            tbox_border_draw(BATTLE_STATE2->item_dropping_summary_tbox_idx, 34, 1);
            // item_drop_summary_battle_gp_tbox_draw(BATTLE_GP_TBOX_BG_1 | BATTLE_GP_TBOX_DRAW);
            BATTLE_STATE2->item_dropping_state++;
            break;
        }
        case SUMMARY_DRAW_TEXT: {
            tbox_flush_set(BATTLE_STATE2->item_dropping_summary_tbox_idx, 0xEE);
            battle_item_drop_draw_summary_text();
            tbox_tilemap_draw(BATTLE_STATE2->item_dropping_summary_tbox_idx);
            tbox_copy_to_vram(BATTLE_STATE2->item_dropping_summary_tbox_idx, TBOX_COPY_TILEMAP | TBOX_COPY_TILESET);
            BATTLE_STATE2->item_dropping_state++;
            break;
        }
        case SUMMARY_WAIT_FOR_DMA3: {
            if (!dma3_busy())
                battle_bg1_y = 0;
                BATTLE_STATE2->item_dropping_state++;
            break;
        }
        case SUMMARY_WAIT_FOR_INPUT: {
            if (super.keys_new.value) { // Any key press is ok...
                play_sound(5);
                tbox_flush_all(BATTLE_STATE2->item_dropping_summary_tbox_idx, 0);
                // item_drop_summary_battle_gp_tbox_draw(BATTLE_GP_TBOX_BG_1 | BATTLE_GP_TBOX_CLEAR);
                BATTLE_STATE2->item_dropping_state++;
            }
            break;
        }
        case SUMMARY_CLEAR: {
            if (!big_callback_is_active(fanfare_callback_wait)) {
                tbox_flush_map(BATTLE_STATE2->item_dropping_summary_tbox_idx);
                tbox_copy_to_vram(BATTLE_STATE2->item_dropping_summary_tbox_idx, TBOX_COPY_TILEMAP);
                BATTLE_STATE2->item_dropping_state++;
                break; 
            }
        }
        case SUMMARY_DONE: {
            if (!dma3_busy()) {
                tbox_free(BATTLE_STATE2->item_dropping_summary_tbox_idx);
                bg_set_attribute(0, BG_ATTR_PRIORITY, 0);
                bg_set_attribute(1, BG_ATTR_PRIORITY, 1);
                bg_sync_display_and_show(0);
                bg_sync_display_and_show(1);
                BATTLE_STATE2->item_dropping_state = DROP_ITEM;
            }
            break;
        }
        /**
        case DROPPING_COLLECT_ITEM: {
            if (BATTLE_STATE2->item_to_pickup < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]) {
                bsc_last_used_item = BATTLE_STATE2->items_dropped[BATTLE_STATE2->item_dropping_battler][BATTLE_STATE2->item_to_pickup];
                oam_free(oams + BATTLE_STATE2->items_dropped_oams[BATTLE_STATE2->item_to_pickup]);
                if (item_has_room(bsc_last_used_item, 1)) {
                    battlescript_callstack_push_next_command();
                    bsc_offset = battlescript_itemdrop_picked_up;
                    play_sound(88);
                    item_add(bsc_last_used_item, 1);
                } else {
                    battlescript_callstack_push_next_command();
                    bsc_offset = battlescript_itemdrop_picked_up_no_space;
                }
                BATTLE_STATE2->item_to_pickup++;
                return;
            } else {
                BATTLE_STATE2->item_dropping_state = DROP_ITEM;
            }
            break;
        }
        **/
    }
}

static coordinate_t item_dropping_animation_offsets[MAX_ITEMS_DROPPED_PER_BATTLER] = {
    {.x = 4, .y = 0}, {.x = 20, .y = -4}, {.x = -20, .y = 0}, {.x = -8, .y = -2},
};


enum {
    ITEM_DROPPING_CALLBACK_STATE = 0,
    ITEM_DROPPING_CALLBACK_DELAY,
    ITEM_DROPPING_CALLBACK_NUM_OAMS_TO_WAIT_FOR,
};

enum {
    ITEM_DROPPING_OAM_STATE_SHOW = 0,
    ITEM_DROPPING_OAM_STATE_FALL,
    ITEM_DROPPING_OAM_STATE_REBOUNCE,
    ITEM_DROPPING_OAM_STATE_IDLE,
    ITEM_DROPPING_OAM_STATE_DELETE,
};

enum {
    ITEM_DROPPING_OAM_CALLBACK_IDX = 0,
    ITEM_DROPPING_OAM_DELAY,
    ITEM_DROPPING_OAM_FRAME,
    ITEM_DROPPING_OAM_STATE
};

#define DROPPING_DY 32
#define DROPPING_DT 16

static void item_dropping_oam_callback(oam_object *self) {
    u16 *callback_idx = self->private + ITEM_DROPPING_OAM_CALLBACK_IDX;
    u16 *delay = self->private + ITEM_DROPPING_OAM_DELAY;
    u16 *frame = self->private + ITEM_DROPPING_OAM_FRAME;
    u16 *state = self->private + ITEM_DROPPING_OAM_STATE;
    if (*delay > 0) {
        --*delay;
        return;
    }

    FIXED dt = INT_TO_FIXED(DROPPING_DT); // in frames
    FIXED dy = INT_TO_FIXED(DROPPING_DY); // Fallin 32 px
    FIXED a = FIXED_DIV(dy, FIXED_MUL(dt, dt));
    switch(*state) {
        case ITEM_DROPPING_OAM_STATE_SHOW: {
            self->flags = (u16)(self->flags &(~OAM_FLAG_INVISIBLE));
            *state = ITEM_DROPPING_OAM_STATE_FALL;
            FALL_THROUGH;
        }
        case ITEM_DROPPING_OAM_STATE_FALL: {
            FIXED t = INT_TO_FIXED(*frame);
            FIXED y = FIXED_MUL(a, FIXED_MUL(t, t));
            self->y2 = (s16)(FIXED_TO_INT(y));
            if (*frame >= DROPPING_DT) {
                play_sound(23);
                *state = ITEM_DROPPING_OAM_STATE_REBOUNCE;
                *frame = 0;
            } else {
                ++*frame;
            }
            break;
        }
        case ITEM_DROPPING_OAM_STATE_REBOUNCE: {
            // Re-bounce, use a parabola for the y direction as well, but now with a initial velocity given by a * dt / const = dy / dt / const
            FIXED t = INT_TO_FIXED(*frame);
            FIXED v0 = FIXED_DIV(FIXED_MUL(FIXED_DIV(dy, dt), INT_TO_FIXED(2)), INT_TO_FIXED(3));
            FIXED y = FIXED_SUB(FIXED_MUL(a, FIXED_MUL(t, t)), FIXED_MUL(v0, t));
            if (y > 0) {
                y = 0;
                big_callbacks[*callback_idx].params[ITEM_DROPPING_CALLBACK_NUM_OAMS_TO_WAIT_FOR]--; // Wait for one oam less
                *state = ITEM_DROPPING_OAM_STATE_IDLE;
            }
            self->y2 = (s16)(FIXED_TO_INT(FIXED_ADD(dy, y)));
            ++*frame;
            break;
        }
        case ITEM_DROPPING_OAM_STATE_IDLE: {
            break; // Do nothing, wait for removal basically
        }
        case ITEM_DROPPING_OAM_STATE_DELETE: {
            // play_sound(88);
            big_callbacks[*callback_idx].params[ITEM_DROPPING_CALLBACK_NUM_OAMS_TO_WAIT_FOR]--; // Wait for one oam less
            oam_free(self); // This state is set externally, when picking stuff up
            break;
        }
    }
}

void battle_animation_callback_create_item_sprite(u8 self) {
    u16 *state = big_callbacks[self].params + ITEM_DROPPING_CALLBACK_STATE;
    u16 *delay = big_callbacks[self].params + ITEM_DROPPING_CALLBACK_DELAY;
    u16 *num_oams_to_wait_for = big_callbacks[self].params + ITEM_DROPPING_CALLBACK_NUM_OAMS_TO_WAIT_FOR;
    if (*delay > 0) {
        --*delay;
        return;
    }
    switch (*state) {
        case 0: { // Allocate resources
            for (u8 i = 0; i < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]; i++) {
                u8 oam_idx = item_oam_new((u16)(0x56A0 + i), (u16)(0x56A0 + i), BATTLE_STATE2->items_dropped[BATTLE_STATE2->item_dropping_battler][i]);
                BATTLE_STATE2->items_dropped_oams[i] = oam_idx;
                oams[oam_idx].x = (s16)(battler_get_coordinate(battle_scripting.battler_idx, BATTLER_COORD_X_2) + item_dropping_animation_offsets[i].x);
                oams[oam_idx].y = (s16)(battler_get_coordinate(battle_scripting.battler_idx, BATTLER_COORD_Y) - 8 + item_dropping_animation_offsets[i].y);
                oams[oam_idx].priority_on_layer = (u8)(battler_oam_get_relative_priority(BATTLE_STATE2->item_dropping_battler) + i);
                oams[oam_idx].flags |= OAM_FLAG_INVISIBLE;
                oams[oam_idx].private[0] = self;
                oams[oam_idx].private[1] = (u16)(i * 16); // delay
                oams[oam_idx].callback = item_dropping_oam_callback;
                ++*num_oams_to_wait_for;
            }
            ++*state;
            break;
        }
        case 1: {
            if (*num_oams_to_wait_for > 0) 
                return;
            *delay = 32;
            ++*state;
            break;
        }
        case 2: {
            for (u8 i = 0; i < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]; i++) {
                u8 oam_idx = BATTLE_STATE2->items_dropped_oams[i];
                oams[oam_idx].private[ITEM_DROPPING_OAM_DELAY] = (u16)(i * 8); // delay
                oams[oam_idx].private[ITEM_DROPPING_OAM_STATE] = ITEM_DROPPING_OAM_STATE_DELETE; // state
                ++*num_oams_to_wait_for;
            }
            ++*state;
            break;
        }
        case 3: {
            if (*num_oams_to_wait_for > 0) 
                return;
            battle_animation_big_callback_delete(self);
            break;
        }

    }


}