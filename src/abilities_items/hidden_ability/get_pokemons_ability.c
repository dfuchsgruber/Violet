#include "types.h"
#include "romfuncs.h"
#include "oams.h"
#include "callbacks.h"
#include "battle.h"
#include "basestats.h"
#include "trainer.h"
#include "item.h"
#include "save.h"
#include <stdbool.h>
#include "unaligned_types.h"
#include "pokemon.h"


u8 get_pokemons_ability (pokemon *poke){
	
	bool ability_bit = get_pokemons_attribute(poke, ATTRIBUTE_ABILITY, 0);
	bool hidden_ability_bit = get_pokemons_attribute(poke, ATTRIBUTE_COOLNESS, 0) & 0x80;
	
	u16 species = (u16)get_pokemons_attribute(poke, ATTRIBUTE_SPECIES, 0);
	
	if (hidden_ability_bit && bstats[species].hidden_ability){
		
		return bstats[species].hidden_ability;
		
	}
	
	if (ability_bit && bstats[species].ability2){
		
		return bstats[species].ability2;
		
	}
	
	return bstats[species].ability1;
	
	
}


u8 write_ability_into_dbuf (pokemon *poke){
	
	u8 ability = get_pokemons_ability(poke);
	*((u8*)0x02023D6A) = ability;
	return ability;
	
}

