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
#include "save.h"
#include "pokepad/incubator.h"

u8 str_egg[] = LANGDEP(PSTRING("Ei"), PSTRING("Egg"));

void overworld_egg_new(u16 species, int catch_location, pokemon *dst) {
  pokemon_new_egg(dst, species, true);
  // Apply 31-ivs
  u8 iv = 31;
  for (int i = 0; i < 6; i++) {
    pokemon_set_attribute(dst, (u8)(ATTRIBUTE_HP_IV + i), &iv);
  }
  // Apply is_egg
  bool is_egg = true;
  pokemon_set_attribute(dst, ATTRIBUTE_IS_EGG, &is_egg);
  // Apply hidden ability
  pokemon_set_hidden_ability(&dst->box);
  pokemon_set_attribute(dst, ATTRIBUTE_CATCH_LOCATION, &catch_location);
}

int overworld_script_egg_with_custom_catch_location(u16 species, int catch_location) {
	pokemon *p = malloc(sizeof(pokemon));
	overworld_egg_new(species, catch_location, p);
	int result = pokemon_give(p);
	free(p);
	return result;
}

int overworld_script_give_egg (u16 species) {
	return overworld_script_egg_with_custom_catch_location(species, CATCH_LOCATION_SPECIAL_EGG);
}

int special_overworld_script_give_egg() {
	return overworld_script_egg_with_custom_catch_location(*var_access(0x8000),
			CATCH_LOCATION_OVERWORLD_EGG);
}

int special_overworld_script_give_egg_into_incubator_slots() {
  for (int i = 0; i < incubator_available_slots(); i++) {
    if (box_pokemon_get_attribute(&cmem.incubator_slots[i], ATTRIBUTE_SPECIES, 0) == 0) {
      pokemon *tmp = malloc(sizeof(pokemon));
      overworld_egg_new(*var_access(0x8000), CATCH_LOCATION_SPECIAL_EGG, tmp);
      memcpy(&cmem.incubator_slots[i], tmp, sizeof(box_pokemon));
      cmem.incubator_ready |= (u8)(~(1 << i));
      free(tmp);
      return i;
    }
  }
  return 255;
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

void egg_hatched_pokemon_new(pokemon *egg, pokemon *target) {
	pid_t pid = {.value = (u32) pokemon_get_attribute(egg, ATTRIBUTE_PID, 0)};
	u16 species = (u16) pokemon_get_attribute(egg, ATTRIBUTE_SPECIES, 0);
	u16 moves[4];
	for (int i = 0; i < 4; i++) {
		moves[i] = (u16) pokemon_get_attribute(egg, ATTRIBUTE_ATTACK1 + i, 0);
	}
	int ivs[6];
	for (int i = 0; i < 6; i++) {
		ivs[i] = pokemon_get_attribute(egg, ATTRIBUTE_HP_IV + i, 0);
	}
	int language = pokemon_get_attribute(egg, ATTRIBUTE_LANGUAGE, 0);
	int catch_game = pokemon_get_attribute(egg, ATTRIBUTE_CATCH_GAME, 0);
	int markings = pokemon_get_attribute(egg, ATTRIBUTE_MARKINGS, 0);
	int pokerus = pokemon_get_attribute(egg, ATTRIBUTE_POKERUS, 0);
	int obedience = pokemon_get_attribute(egg, ATTRIBUTE_OBEDIENCE, 0);
	bool has_hidden_ability = pokemon_has_hidden_ability(&egg->box);

	pokemon_new(target, species, 5, 32, true, pid, 0, 0);
	for (int i = 0; i < 4; i++) {
		pokemon_set_attribute(target, ATTRIBUTE_ATTACK1 + i, &moves[i]);
	}
	for (int i = 0; i < 6; i++) {
		pokemon_set_attribute(target, ATTRIBUTE_HP_IV + i, &ivs[i]);
	}
	pokemon_set_attribute(target, ATTRIBUTE_LANGUAGE, &language);
	pokemon_set_attribute(target, ATTRIBUTE_CATCH_GAME, &catch_game);
	pokemon_set_attribute(target, ATTRIBUTE_MARKINGS, &markings);
	pokemon_set_attribute(target, ATTRIBUTE_POKERUS, &pokerus);
	pokemon_set_attribute(target, ATTRIBUTE_OBEDIENCE, &obedience);
	if (has_hidden_ability)
		pokemon_set_hidden_ability(&target->box);
	int friendship = 120;
	pokemon_set_attribute(target, ATTRIBUTE_HAPPINESS, &friendship);
	*egg = *target;
}
