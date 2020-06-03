#include "types.h"
#include "save.h"
#include "berry.h"
#include "debug.h"

void debug_berries() {
    dprintf("Offset of berry trees in saveblock 0x%x\n", (int)(save1->berry_trees) - (int)(save1));
    dprintf("Sizeof berry trees %d\n", sizeof(save1->berry_trees));

    for (size_t i = 0; i < ARRAY_COUNT(save1->berry_trees); i++) {
        dprintf("Berry %d: Type = %d, stage = %d\n", i, save1->berry_trees[i].berry, save1->berry_trees[i].stage);
    }
}