#include "battle/battler.h"
#include "callbacks.h"
#include "constants/pokemon_attributes.h"
#include "mega.h"
#include "oam.h"
#include "pokemon/basestat.h"
#include "save.h"
#include "types.h"

bool pokemon_has_hidden_ability(box_pokemon *p) {
    return (box_pokemon_get_attribute(p, ATTRIBUTE_COOLNESS, 0) & 0x80) > 0;
}

u8 pokemon_get_ability(pokemon *poke) {

    bool ability_bit = pokemon_get_attribute(poke, ATTRIBUTE_ABILITY, 0);
    bool hidden_ability_bit = pokemon_has_hidden_ability(&poke->box);
    u16 species = (u16)pokemon_get_attribute(poke, ATTRIBUTE_SPECIES, 0);
    if (hidden_ability_bit && basestats[species].hidden_ability) {
        return basestats[species].hidden_ability;
    }
    if (ability_bit && basestats[species].ability2) {
        return basestats[species].ability2;
    }
    return basestats[species].ability1;
}

u8 battler_load_ability_as_defender(pokemon *poke) {
    defending_battler_ability = pokemon_get_ability(poke);
    return defending_battler_ability;
}

u8 battler_load_ability_as_defender_by_slot(u8 battler_slot) {
    pokemon *p = (battler_is_opponent(battler_slot) ? opponent_pokemon : player_pokemon) + battler_idx_to_party_idx(battler_slot);
    return battler_load_ability_as_defender(p);
}
