#include "types.h"
#include "pokemon/breeding.h"
#include "pokemon/basestat.h"
#include "attack.h"
#include "debug.h"
#include "save.h"
#include "constants/species.h"
#include "constants/pokemon_attributes.h"
#include "constants/languages.h"
#include "constants/items.h"
#include "constants/flags.h"
#include "prng.h"
#include "math.h"
#include "flags.h"
#include "pokemon/evolution.h"

void _pokemon_get_egg_moves_stub(){
    derrf("Rom called old invalid stub for pokemon_get_egg_moves!\n");
}

u16 *pokemon_get_egg_moves(u16 species, int *size){
    *size = 0;
    u16 *egg_moves = pokemon_egg_moves[species];
    if (egg_moves) {
		while(egg_moves[*size] != 0xFFFF) {
			(*size)++;
		}
    }
    return egg_moves;
}

void breeding_alter_egg_species(u16 *species, daycare_stru *daycare) {
	u16 mother_item = (u16) box_pokemon_get_attribute(&(daycare->pokemon[0].pokemon),
			ATTRIBUTE_ITEM, 0);
	u16 father_item = (u16) box_pokemon_get_attribute(&(daycare->pokemon[1].pokemon),
			ATTRIBUTE_ITEM, 0);
	switch (*species) {
	case POKEMON_AZURILL:
		if (mother_item != ITEM_SEERAUCH && father_item != ITEM_SEERAUCH) {
			*species = POKEMON_MARILL; // Can't breed Azurill without sea incense
		}
		break;
	case POKEMON_MAMPFAXO:
		if (mother_item != ITEM_LAHMRAUCH && father_item != ITEM_LAHMRAUCH) {
			*species = POKEMON_RELAXO; // Can't breed Munchlax without lax incense
		}
		break;
	} // Wobuffet and Wynaut have been removed from the dex (who likes them anyway?)
}

void breeding_inherit_ivs(pokemon *egg, daycare_stru *daycare) {
	// Inherit the best iv from parents and a randomly generated
	for (int i = 0; i < 6; i++) {
		// Randomly generate an iv
		int iv_rnd = rnd16() % 32;
		// Random iv can be amplified by up to 2.0 hatching eggs
		iv_rnd *= (100 + MIN(100, save_get_key(SAVE_KEY_EGGS_HATCHED))) / 100;
		iv_rnd = MIN(31, iv_rnd);
		int iv_mother = box_pokemon_get_attribute(&daycare->pokemon[0].pokemon, ATTRIBUTE_HP_IV + i,
				0);
		int iv_father = box_pokemon_get_attribute(&daycare->pokemon[1].pokemon, ATTRIBUTE_HP_IV + i,
				0);
		int iv = MAX(iv_rnd, MAX(iv_father, iv_mother));
		pokemon_set_attribute(egg, ATTRIBUTE_HP_IV + i, &iv);
	}
}

void breeding_pokemon_new(pokemon *p, u16 species, daycare_stru *daycare) {
	(void)(daycare);
	pokemon_new(p, species, 5, 32, true, cmem.daycare_offspring_pid, false, 0);
	u8 ball = ITEM_POKEBALL;
	pokemon_set_attribute(p, ATTRIBUTE_CATCH_INFO, &ball);
	pokemon_set_attribute(p, ATTRIBUTE_NICKNAME, str_egg);
	pokemon_set_attribute(p, ATTRIBUTE_HAPPINESS, &basestats[species].egg_cycles);
	u8 level_met = 5;
	pokemon_set_attribute(p, ATTRIBUTE_CATCH_LEVEL, &level_met);
	u8 language = LANGUAGE_GERMAN;
	pokemon_set_attribute(p, ATTRIBUTE_LANGUAGE, &language);
}

bool breeding_inherit_hidden_ability(daycare_stru *daycare) {
	for (int i = 0; i < 2; i++) {
		// Inherit hidden ability from each parent with 50% chance
		if (pokemon_has_hidden_ability(&daycare->pokemon[i].pokemon)) {
			return true;
		}
	}
	return false;
}

pid_t breeding_new_pid(daycare_stru *daycare) {
	pid_t pid = pokemon_new_pid();
	cmem.daycare_offspring_has_hidden_ability = 0;
	// Inherit nature from parent with everstone
	for (int i = 0; i < 2; i++) {
		u16 parent_item = (u16) box_pokemon_get_attribute(&daycare->pokemon[i].pokemon,
				ATTRIBUTE_ITEM, 0);
		if (parent_item == ITEM_EWIGSTEIN) {
			pid_t parent_pid = {
					.value = (u32) box_pokemon_get_attribute(&daycare->pokemon[i].pokemon,
							ATTRIBUTE_PID, 0)};
			pid.fields.nature = parent_pid.fields.nature;
		}
	}
	return pid;
}

u16 breeding_get_egg_species_and_parents(daycare_stru* daycare, u8 *parents) {
	u16 species[2];
	for (u8 i = 0; i < 2; i++) {
		species[i] = (u16) box_pokemon_get_attribute(&daycare->pokemon[i].pokemon,
				ATTRIBUTE_SPECIES, 0);
		if (species[i] == POKEMON_DITTO) {
			parents[0] = i^1;
			parents[1] = i;
		} else if (pokemon_get_gender(&daycare->pokemon[i].pokemon) == GENDER_FEMALE) {
			parents[0] = i;
			parents[1] = i^1;
		}
	}
	u16 egg_species = pokemon_get_basis_stage(species[parents[0]]);
	// Change the species gender for Nidoran (Ilumise has been removed)
	if (egg_species == POKEMON_NIDORANW && cmem.daycare_offspring_male)
		egg_species = POKEMON_NIDORANM;
	// If Ditto mates with a male /genderless pokemon, it is set to the mother
	if (species[parents[1]] == POKEMON_DITTO &&
			pokemon_get_gender(&daycare->pokemon[parents[0]].pokemon) != GENDER_FEMALE) {
		u8 tmp = parents[1];
		parents[1] = parents[0];
		parents[0] = tmp;
	}
	return egg_species;
}

void breeding_spawn_egg(daycare_stru *daycare) {
	cmem.daycare_offspring_pid = breeding_new_pid(daycare);
	cmem.daycare_offspring_male = (rnd16() & 1) > 0;
	cmem.daycare_offspring_has_hidden_ability = breeding_inherit_hidden_ability(daycare);
	setflag(FLAG_DAYCARE_EGG_SPAWNED);
}

void breeding_spawn_male_egg(daycare_stru *daycare) {
	cmem.daycare_offspring_pid = breeding_new_pid(daycare);
	cmem.daycare_offspring_male = true;
	cmem.daycare_offspring_has_hidden_ability = breeding_inherit_hidden_ability(daycare);
	setflag(FLAG_DAYCARE_EGG_SPAWNED);
}
