#include "types.h"
#include "bg.h"
#include "io.h"

void bg_reset_scroll() {
    for (int i = 0; i < 4; i++) {
        io_set((u16)IO_BGHOFS(i), 0);
        io_set((u16)IO_BGVOFS(i), 0);
    }
}