#include "types.h"
#include "romfuncs.h"
#include "constants/items.h"

void remove_potion_from_pc(){
    remove_pc_item(ITEM_TRANK, 1);
}
