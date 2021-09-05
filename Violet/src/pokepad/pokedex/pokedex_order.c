#include "types.h"
#include <stdbool.h>
#include "pokemon/count.h"
#include "pokepad/pokedex/operator.h"
#include "mega.h"

u16 pokemon_get_display_number(u16 species) {
    mega_evolution_t *mega_evolution = mega_evolution_get_by_mega_species(species);
	if (mega_evolution)
		return mega_evolution->species;
    u16 id = pokedex_get_id(species);
    if (!pokedex_is_national() && id > 151)
        return 0xFFFF;
    return id;

}

u16 pokedex_get_species_by_dex_id(u16 dex_id) {
    if (!dex_id)
        return 0;
    u16 i;
    for (i = 0; i < POKEMON_CNT - 1; i++) {
        if (pokedex_order[i] == dex_id)
            return i;
    }
    return 0;
}
