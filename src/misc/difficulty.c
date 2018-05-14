#include "types.h"
#include "item/item.h"
#include "constants/items.h"

void remove_potion_from_pc(){
    item_remove_from_pc(ITEM_TRANK, 1);
}
