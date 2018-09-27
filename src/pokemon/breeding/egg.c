/*
 * egg.c
 *
 *  Created on: Sep 26, 2018
 *      Author: dominik
 */
#include "types.h"
#include "constants/pokemon_attributes.h"
#include "pokemon/virtual.h"
#include "agbmemory.h"
#include "text.h"
#include "pokemon/basestat.h"
#include "vars.h"
#include "language.h"

int overworld_script_giveegg (u16 species) {
	pokemon *p = malloc(sizeof(pokemon));
	pokemon_new_egg(p, species, true);
	// Apply 31-ivs
	u8 iv = 31;
	for (int i = 0; i < 6; i++) {
		pokemon_set_attribute(p, (u8)(ATTRIBUTE_HP_EV + i), &iv);
	}
	// Apply is_egg
	bool is_egg = true;
	pokemon_set_attribute(p, ATTRIBUTE_IS_EGG, &is_egg);
	// Apply hidden ability
	u8 coolness = (u8) pokemon_get_attribute(p, ATTRIBUTE_COOLNESS, NULL);
	coolness |= 0x80;
	pokemon_set_attribute(p, ATTRIBUTE_COOLNESS, &coolness);
	int result = pokemon_give(p);
	free(p);
	return result;
}

void overworld_script_egg_buffer_type() {
	u16 species = *var_access(0x8000);
	u8 *dst = buffer0;
	// Buffer the first type
	dst = typetoa_long(dst, basestats[species].type1);
	if (basestats[species].type1 != basestats[species].type2) {
		// Buffer the second type as well
		u8 str_dash[] = PSTRING("-");
		dst = strcpy(dst, str_dash);
		typetoa_long(dst, basestats[species].type2);
	}
}
