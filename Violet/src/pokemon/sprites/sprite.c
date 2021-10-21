#include "bios.h"
#include "constants/species.h"
#include "oam.h"
#include "pokemon/sprites.h"
#include "pokemon/virtual.h"
#include "save.h"
#include "types.h"

void pokemon_get_frontsprite(graphic *g, void *dst, u16 species, pid_t p, u8 load_frontsprite) {
    (void)g;
    g = (graphic *)(fmem._hook_tmp_);
    if (species == POKEMON_ICOGNITO) {
        int letter_idx = pokemon_unown_get_letter(p);
        if (letter_idx > 0) {
            species = (u16)(POKEMON_ICOGNITO_B - 1 + letter_idx);
        }
        if (load_frontsprite) {
            g = pokemon_frontsprites + species;
        } else {
            g = pokemon_backsprites + species;
        }
    }
    if (species >= POKEMON_CNT) {
        g = pokemon_frontsprites;
    }
    lz77uncompwram(g->sprite, dst);
    pokemon_spinda_draw_pattern(species, p, dst, load_frontsprite);
}
