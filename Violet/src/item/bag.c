#include "item/item.h"
#include "item/bag.h"
#include "callbacks.h"
#include "language.h"
#include "save.h"

static u8 str_cant_write_mail_here[] = LANGDEP(
    PSTRING("Du kannst jetzt keinen Brief\nschreiben!"),
    PSTRING("You can't write a mail now!")
);

static u8 str_cant_give_a_tm[] = LANGDEP(
    PSTRING("Tms und Vms können nicht gegeben\nwerden!"),
    PSTRING("Tms and Hms can't be held!")
);

void bag_item_selected_give_from_overworld_or_pc(u8 self, bool from_pc) {
    u16 *data = big_callbacks[self].params;
    u16 item_idx = item_get_idx_by_pocket_position((u16)(bag_state.pocket + 1), data[1]);
    if (!item_is_mail_and_can_be_written(item_idx)) {
        bag_print_string_with_continuation(self, 2, str_cant_write_mail_here, bag_wait_for_a_press_and_close_context_menu);
    } else if (item_idx == ITEM_VMTM_BOX) {
        bag_print_string_with_continuation(self, 2, str_cant_give_a_tm, bag_wait_for_a_press_and_close_context_menu);
    } else if (item_idx == ITEM_BEERENTUETE) {
        bag_set_continuation(from_pc ? bag_initialize_berry_pouch_with_context_give_item_from_pc : bag_initialize_berry_pouch_with_context_give_item);
        bag_fade_out_and_continuation(self);
    } else if (bag_state.pocket != POCKET_KEY_ITEMS - 1 && !item_get_importance(item_idx)) {
        bag_close_with_win0_animation();
        big_callbacks[self].function = bag_fade_out_and_continuation;
    } else {
        bag_print_string_item_cant_be_held(self);
    }
}

void bag_item_selected_give(u8 self) {
    bag_item_selected_give_from_overworld_or_pc(self, false);
}

void bag_item_selected_give_from_pc(u8 self) {
    bag_item_selected_give_from_overworld_or_pc(self, true);
}

void bag_set_pocket_pointers() {
    bag_pockets[POCKET_ITEMS - 1].items = save1->bag_pocket_items;
    bag_pockets[POCKET_ITEMS - 1].capacity = MAX_NUM_BAG_ITEMS;
    bag_pockets[POCKET_KEY_ITEMS - 1].items = save1->bag_pocket_key_items;
    bag_pockets[POCKET_KEY_ITEMS - 1].capacity = MAX_NUM_BAG_KEY_ITEMS;
    bag_pockets[POCKET_POKEBALLS - 1].items = save1->bag_pocket_pokeballs;
    bag_pockets[POCKET_POKEBALLS - 1].capacity = MAX_NUM_BAG_POKEBALLS;
    bag_pockets[POCKET_TM_HM - 1].items = save1->bag_pocket_tm_hms;
    bag_pockets[POCKET_TM_HM - 1].capacity = MAX_NUM_BAG_TM_HMS;
    bag_pockets[POCKET_BERRIES - 1].items = save1->bag_pocket_berries;
    bag_pockets[POCKET_BERRIES - 1].capacity = MAX_NUM_BAG_BERRIES;
    bag_pockets[POCKET_BAIT - 1].items = save1->bag_pocket_bait;
    bag_pockets[POCKET_BAIT - 1].capacity = MAX_NUM_BAG_BAIT;
}

void bag_clear() {
    for (int i = 0; i < NUM_POCKETS; i++)
        bag_clear_slots(bag_pockets[i].items, bag_pockets[i].capacity);
}