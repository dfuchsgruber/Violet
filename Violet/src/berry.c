#include "types.h"
#include "save.h"
#include "berry.h"
#include "debug.h"
#include "agbmemory.h"

u8 berry_tree_get_berry(u8 berry_tree_idx) {
    return cmem.berry_trees[berry_tree_idx].berry;
}
 

static u8 berry_tree_initial_items[] = {
    [0] = ITEM_IDX_TO_BERRY_IDX(ITEM_LYDZIBEERE),
    [1] = ITEM_IDX_TO_BERRY_IDX(ITEM_PIRSIFBEERE),
};


void berry_trees_initialize() {
    memset(cmem.berry_trees, 0, sizeof(cmem.berry_trees));
    for (size_t i = 0; i < ARRAY_COUNT(berry_tree_initial_items); i++) {
        cmem.berry_trees[i].berry = berry_tree_initial_items[i];
        cmem.berry_trees[i].stage = BERRY_STAGE_BERRIES;
        cmem.berry_trees[i].yield = 3; // TODO
    }
}