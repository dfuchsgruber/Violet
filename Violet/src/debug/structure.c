#include "types.h"
#include "debug.h"
#include "save.h"

void debug_structure() {
    DEBUG("Offset of persons 0x%x", (int)&save1->persons - (int)save1);
}