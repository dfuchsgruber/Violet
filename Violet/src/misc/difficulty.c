#include "constants/items.h"
#include "item/item.h"
#include "types.h"

void remove_potion_from_pc() {
    item_remove_from_pc(ITEM_TRANK, 1);
}
