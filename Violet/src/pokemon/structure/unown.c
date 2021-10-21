#include "debug.h"
#include "pokemon/virtual.h"
#include "types.h"

int pokemon_unown_get_letter(pid_t p) {
    return (int)p.fields.unown_letter % 28;
}

pid_t pokemon_unown_generate_letter_pid(u32 letter) {
    if (letter >= 28) {
        derrf("Attempting to generate an unown with letter >= 28 %d\n", letter);
    }
    pid_t p = pokemon_new_pid();
    p.fields.unown_letter = (u32)(letter & 31);
    dprintf("Created unown with letter %d and pid %x\n", letter, p);
    return p;
}
