#include "types.h"
#include "vars.h"
#include "callbacks.h"
#include "constants/items.h"
#include "debug.h"

void repel_use(){
    switch(*var_access(0x800E)){
        case ITEM_SCHUTZ:
            *var_access(0x4020) = 100;
            break;
        case ITEM_SUPERSCHUTZ:
            *var_access(0x4020) = 200;
            break;
        case ITEM_TOP_SCHUTZ:
            *var_access(0x4020) = 250;
            break;
        default:
            ERROR("No repel item %d\n", *var_access(0x800E));
            break;
    }
}
