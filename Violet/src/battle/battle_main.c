#include "types.h"
#include "battle/state.h"
#include "save.h"
#include "mega.h"
#include "agbmemory.h"

// TODO hooks

void battle_allocate_new() {
    fmem.mega_state = malloc_and_clear(sizeof(mega_state_t));
}

void battle_free_new() {
    if (fmem.mega_state) {
        battle_alternative_forms_revert(); // It's whack to have it here, but w/e
        free(fmem.mega_state);
        fmem.mega_state = NULL;
    }
}