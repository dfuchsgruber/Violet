#include "types.h"
#include "item/item.h"
#include "item/bag.h"
#include "debug.h"
#include "save.h"

#define MAX_SLOT_CAPACITY 999

static bool pocket_has_singleton_stacks[NUM_POCKETS] = {
    [POCKET_TM_HM] = true,
    [POCKET_BERRIES] = true,
};

bool item_check(u16 item, u16 quantity) {
    u8 pocket = item_get_pocket(item);
    if (pocket == 0 || pocket >= NUM_POCKETS)
        return false;
    
    for (int i = 0; i < bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].capacity && quantity > 0; i++) {
        bag_item_t *slot = bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].items + i;
        if (slot->item_idx == item) {
            u16 in_slot = item_slot_get_quantity(&slot->quantity);
            quantity = (u16)(MAX(0, quantity - in_slot));
            if (pocket_has_singleton_stacks[pocket])
                break; // Only check a single slot
        }
    }
    return quantity <= 0;
}

bool item_has_room(u16 item, u16 quantity) {
    u8 pocket = item_get_pocket(item);
    if (pocket == 0 || pocket >= NUM_POCKETS)
        return false;
    for (int i = 0; i < bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].capacity && quantity > 0; i++) {
        bag_item_t *slot = bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].items + i;
        if (slot->item_idx == item) {
            u16 in_slot = item_slot_get_quantity(&slot->quantity);
            // DEBUG("Looking for item in %d x %d in slot with quantity %d\n", item, quantity, in_slot);
            quantity = (u16)MAX(0, quantity - (MAX_SLOT_CAPACITY - in_slot));
            if (pocket_has_singleton_stacks[pocket])
                break; // Only check a single slot
        } else if (slot->item_idx == ITEM_NONE) {
            // Empty slot can hold MAX_SLOT_CAPACITY exemplars
            // DEBUG("Looking for item in empty slot\n");
            quantity = (u16)(MAX(0, quantity - MAX_SLOT_CAPACITY));
            if (pocket_has_singleton_stacks[pocket])
                break; // Only check a single slot
        }
    }
    // DEBUG("Reamining to check %d\n", quantity);
    return quantity == 0;
}

bool item_add(u16 item_idx, u16 quantity) {
    // DEBUG("Key at offset %d\n", (int)(&save2->encryption_key) - (int)save2);
    // DEBUG("Item add %d x %d, key 0x%x\n", item_idx, quantity, save2->encryption_key);
    if (!item_has_room(item_idx, quantity))
        return false;
    // DEBUG("Item has room\n");
    u8 pocket = item_get_pocket(item_idx);
    if (pocket == 0 || pocket >= NUM_POCKETS)
        return false;
    // DEBUG("Pocket valid\n");
    for (int i = 0; i < bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].capacity && quantity > 0; i++) {
        bag_item_t *slot = bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].items + i;
        if (slot->item_idx == item_idx) {
            u16 in_slot = item_slot_get_quantity(&slot->quantity);
            int to_add = MAX(0, MIN(quantity, MAX_SLOT_CAPACITY - in_slot));
            in_slot = (u16)(in_slot + to_add);
            quantity = (u16)(quantity - to_add);
            item_slot_set_quantity(&slot->quantity, in_slot);
            // DEBUG("Set in slot to %d (= %d)\n", in_slot, item_slot_get_quantity(&slot->quantity));
            if (pocket_has_singleton_stacks[pocket])
                break; // Only check a single slot
        } else if (slot->item_idx == ITEM_NONE) {
            u16 to_add = (u16)MIN(quantity, MAX_SLOT_CAPACITY);
            quantity = (u16)(quantity - to_add);
            slot->item_idx = item_idx;
            item_slot_set_quantity(&slot->quantity, to_add);
            // DEBUG("Set in empty slot to %d (= %d)\n", to_add, item_slot_get_quantity(&slot->quantity));
            if (pocket_has_singleton_stacks[pocket])
                break; // Only check a single slot
        }
    }
    if (quantity > 0) {
        ERROR("Item adding failed for %d after room was found, there must be a bug in your code.\n", item_idx);
    }
    // DEBUG("Item added, remining %d\n", quantity);
    return quantity <= 0;
}

bool item_remove(u16 item_idx, u16 quantity) {
    if (!item_check(item_idx, quantity))
        return false;
    u8 pocket = item_get_pocket(item_idx);
    if (pocket == 0 || pocket >= NUM_POCKETS)
        return false;
    bool needs_compacting = false;
    for (int i = 0; i < bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].capacity && quantity > 0; i++) {
        bag_item_t *slot = bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].items + i;
        if (slot->item_idx == item_idx) {
            u16 in_slot = item_slot_get_quantity(&slot->quantity);
            int to_remove = MIN(in_slot, quantity);
            in_slot = (u16)(in_slot - to_remove);
            quantity = (u16)(quantity - to_remove);
            item_slot_set_quantity(&slot->quantity, in_slot);
            DEBUG("Set quantity at slot 0x%x to %d\n", &slot->quantity, in_slot);
            if (in_slot == 0) {
                slot->item_idx = ITEM_NONE;
                needs_compacting = true;
            }
            if (pocket_has_singleton_stacks[pocket])
                break; // Only check a single slot
        }
    }
    if (needs_compacting)
        bag_pocket_compact(bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].items, bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket)].capacity);
    if (quantity > 0) {
        ERROR("Item removing failed for %d after enough exemplars have been found, there must be a bug in your code.\n", item_idx);
    }
    return quantity <= 0;
}

void bag_apply_new_encryption(u32 key) {
    for (int i = 0; i < NUM_POCKETS - 1; i++) {
        for (int j = 0; j < bag_pockets[i].capacity; j++) {
            bag_item_apply_new_encryption_key(&bag_pockets[i].items[j].quantity, key);
        }
    }
}

void item_remove_tm_case_and_berry_pouch() {
    item_remove(ITEM_VMTM_BOX, 1);
    item_remove(ITEM_BEERENTUETE, 1);
}

// void item_clear_pokeballs() {
//     bag_clear_slots(bag_pockets[POCKET_TO_BAG_POCKETS_IDX(POCKET_POKEBALLS)].items, bag_pockets[POCKET_TO_BAG_POCKETS_IDX(POCKET_POKEBALLS)].capacity);
// }