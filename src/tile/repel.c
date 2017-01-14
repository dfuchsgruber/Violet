#include "types.h"
#include "romfuncs.h"
#include "callbacks.h"
#include "item.h"
#include "debug.h"

void repel_use(){
    switch(*vardecrypt(0x800E)){
        case ITEM_SCHUTZ:
            *vardecrypt(0x4020) = 100;
            break;
        case ITEM_SUPERSCHUTZ:
            *vardecrypt(0x4020) = 200;
            break;
        case ITEM_TOP_SCHUTZ:
            *vardecrypt(0x4020) = 250;
            break;
        default:
            err2(ERR_NO_REPEL_ITEM, *vardecrypt(0x800E));
            break;
    }
}
