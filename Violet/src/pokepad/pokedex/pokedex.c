#include "types.h"
#include "save.h"
#include "pokepad/pokedex/operator.h"
#include "pokepad/pokedex/state.h"
#include "mega.h"

u8* pokedex_flag_access(u16 flag, bool seen) {
    if (flag < 416) {
        //std access
        int index = flag / 8;
        return seen ? &(save2->pokedex_seen_flags[index]) : &(save2->pokedex_caught_flags[index]);
    } else {
        int index = (416 - flag) / 8;
        return seen ? &(csave.pokedex_seen_extension[index]) : &(csave.pokedex_caught_extension[index]);
    }
}

bool pokedex_operator(u16 val, u8 op, bool is_species_id) {

    if (is_species_id)
        val = pokedex_get_id(val);
    if (!val)
        return false;
    val--;
    u8 mask = (u8) (1 << (val & 7));
    bool seen = !(op & 1);
    bool apply = op & 2;
    u8 *field = pokedex_flag_access(val, seen);
    if (apply) {
        *field |= mask;
    } else {
        if (*field & mask)
            return true;
    }
    return false;
}

u16 pokedex_get_number_seen_or_caught(bool caught) {

    u16 cnt = 0;
    u16 i;
    for (i = 1; i <= POKEDEX_CNT; i++) {
        if (pokedex_operator_by_dex_id(i, caught ? 1 : 0))
            cnt++;

    }
    return cnt;
}

u16 pokemon_get_display_number(u16 species) {
    const mega_evolution_t *mega_evolution = mega_evolution_get_by_mega_species(species);
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
    for (i = 0; i < POKEMON_CNT; i++) {
        if (pokedex_order[i] == dex_id)
            return (u16)i;
    }
    return 0;
}

u16 pokedex_get_id(u16 species) {
    return pokedex_order[species];
}


pid_t pokedex_get_pid(u16 species) {
	pid_t p = {.value = 0};
	if (species == POKEMON_ICOGNITO) {
		p = save2->icognito_pid;
	} else if (species == POKEMON_PANDIR) {
		p = save2->pandir_pid;
	}
	p.fields.is_shiny = 0;
	return p;
}
