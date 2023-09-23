#include "types.h"
#include "pokemon/virtual.h"
#include "oam.h"
#include "pokemon/sprites.h"
#include "constants/species.h"
#include "bios.h"
#include "save.h"

#include "data/pokemon/frontsprites.h"
#include "data/pokemon/backsprites.h"
#include "data/pokemon/pals.h"
#include "data/pokemon/shiny_pals.h"
#include "data/pokemon/icons.h"
#include "data/pokemon/icon_pals.h"
#include "data/pokemon/player_y.h"
#include "data/pokemon/opponent_y.h"
#include "data/pokemon/altitude.h"

void pokemon_get_frontsprite(const graphic *g, void *dst, u16 species, pid_t p, u8 load_frontsprite) {
    (void) g;
    g = (const graphic*)(hook_tmp);
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