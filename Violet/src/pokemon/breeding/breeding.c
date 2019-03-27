#include "types.h"
#include "pokemon/breeding.h"
#include "pokemon/basestat.h"
#include "pokemon/moves.h"
#include "attack.h"
#include "debug.h"
#include "save.h"
#include "constants/species.h"
#include "constants/pokemon_attributes.h"
#include "constants/languages.h"
#include "constants/items.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "vars.h"
#include "prng.h"
#include "math.h"
#include "flags.h"
#include "pokemon/evolution.h"
#include "constants/abilities.h"
#include "pokepad/incubator.h"
#include "agbmemory.h"

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
	daycare->offspring_present = 1;
	setflag(FLAG_DAYCARE_EGG_SPAWNED);
}

void breeding_spawn_male_egg(daycare_stru *daycare) {
	cmem.daycare_offspring_pid = breeding_new_pid(daycare);
	cmem.daycare_offspring_male = true;
	cmem.daycare_offspring_has_hidden_ability = breeding_inherit_hidden_ability(daycare);
	daycare->offspring_present = 1;
	setflag(FLAG_DAYCARE_EGG_SPAWNED);
}

void breeding_egg_new_into_incubator(daycare_stru *daycare) {
  pokemon tmp;
  u8 parents[2];
  u16 species = breeding_get_egg_species_and_parents(daycare, parents);
  breeding_alter_egg_species(&species, daycare);
  breeding_pokemon_new(&tmp, species, daycare);
  breeding_inherit_ivs(&tmp, daycare);
  breeding_egg_create_moves(&tmp, &daycare->pokemon[parents[1]].pokemon, &daycare->pokemon[parents[0]].pokemon);
  u8 is_egg = 1;
  pokemon_set_attribute(&tmp, ATTRIBUTE_IS_EGG, &is_egg);
	for (int i = 0; i < incubator_available_slots(); i++) {
    if (box_pokemon_get_attribute(&cmem.incubator_slots[i], ATTRIBUTE_SPECIES, 0) == 0) {
      memcpy(&cmem.incubator_slots[i], &tmp, sizeof(box_pokemon));
			daycare_remove_egg(daycare);
  		return;
		}
	}
}

void breeding_egg_add_move_if_known_by_parent(pokemon *egg, box_pokemon *father, box_pokemon *mother, u16 move) {
	for (int j = 0; j < 4; j++) {
		if (box_pokemon_get_attribute(father, ATTRIBUTE_ATTACK1 + j, 0) == move ||
				box_pokemon_get_attribute(mother, ATTRIBUTE_ATTACK1 + j, 0) == move) {
			if (pokemon_append_attack(egg, move) == 0xFFFF) {
				pokemon_rotate_and_push_attack(egg, move);
			}
			return;
		}
	}
}

void breeding_egg_create_moves(pokemon *egg, box_pokemon *father, box_pokemon *mother) {
	u16 species = (u16) pokemon_get_attribute(egg, ATTRIBUTE_SPECIES, 0);

	// Scan if any parent has any of its levelup moves
	for(int i = 0; pokemon_moves[species][i].move_id != 511; i++) {
		breeding_egg_add_move_if_known_by_parent(egg, father, mother, pokemon_moves[species][i].move_id);
	}
	
	// Scan for move tutor moves that can be inherited from both parents
	for (u8 i = 0; i < 32; i++) {
		if (pokemon_move_tutor_compatibility[species] & (u32)(1 << i)) {
			breeding_egg_add_move_if_known_by_parent(egg, father, mother, move_tutor_get_attack(i));
		}
	}

	// Scan for egg moves that can be inherited from both parents
	int num_egg_moves = 0;
	u16 *egg_moves = pokemon_get_egg_moves(species, &num_egg_moves);
	for (int i = 0; i < num_egg_moves; i++) {
		breeding_egg_add_move_if_known_by_parent(egg, father, mother, egg_moves[i]);
	}
}

bool daycare_egg_spawned(daycare_stru *daycare) {
	return daycare->offspring_present;
}

void special_daycare_egg_new_into_incubator() {
	breeding_egg_new_into_incubator(&save1->daycare);
}

bool pokemon_party_has_flamebody(){
    for(int i = 0; i < player_pokemon_cnt; i++){
        if(pokemon_get_ability(&player_pokemon[i]) == FLAMMKOERPER)
            return true;
    }
    return false;
}

u8 breeding_get_cycle_steps() {
  int cycle = 255;
  int hot_spring_boost = *var_access(HATCHING_BOOST_STEPS) + 1000;
  cycle *= 1000;
  cycle /= hot_spring_boost;
  if (pokemon_party_has_flamebody())
    cycle /= 2;
  return (u8)(MAX(1, MIN(255, cycle)));
}

bool box_pokemon_hatching_proceed(box_pokemon *egg, bool consider_zero_cycles,
    bool consider_immediate_hatching, u8 proceed_cycles) {
  if (!box_pokemon_get_attribute(egg, ATTRIBUTE_IS_EGG, 0)) return false;
  if (box_pokemon_get_attribute(egg, ATTRIBUTE_SANITY_IS_BAD_EGG, 0)) return false;
  int cycles = box_pokemon_get_attribute(egg, ATTRIBUTE_HAPPINESS, 0);
  dprintf("Proceed egg @%x with %d cycles\n", egg, cycles);
  if ((cycles == BREEDING_CYCLES_HATCH_IMMEDIATLEY && consider_immediate_hatching) ||
      (consider_zero_cycles && cycles == 0)) return true;
  if (cycles != BREEDING_CYCLES_HATCH_IMMEDIATLEY) cycles = MAX(0, cycles - proceed_cycles);
  box_pokemon_set_attribute(egg, ATTRIBUTE_HAPPINESS, &cycles);
  return false;
}

u8 daycare_proceed(daycare_stru *daycare) {
  int pokemon_in_daycare = 0;
  for (int i = 0; i < 2; i++) {
    if (box_pokemon_get_attribute(&daycare->pokemon[i].pokemon, ATTRIBUTE_SANITY_HAS_SPECIES, 0)) {
      daycare->pokemon[i].step_counter++;
      pokemon_in_daycare++;
    }
  }
  // Breed the pokemon in daycare
  if (!daycare->offspring_present && pokemon_in_daycare == 2 &&
      (daycare->pokemon[1].step_counter & 0xFF) == 0xFF) {
    u8 score = daycare_get_compatibility_score(daycare);
    if (score > (rnd16() * 100u) / 0xFFFF) {
      _daycare_spawn_egg();
    }
  }
  // Check the entire party for immediate hatches, do not proceed cycles
  for (u16 i = 0; i < player_pokemon_cnt; i++) {
    if (box_pokemon_hatching_proceed(&player_pokemon[i].box, false, true, 0)) {
      // Hatch this pokemon as it was marked as immediate
      *var_access(0x8004) = i;
      return true;
    }
  }
  // Hatch eggs
  if (++daycare->step_counter >= breeding_get_cycle_steps()) {
    daycare->step_counter = 0;
    for (u16 i = 0; i < player_pokemon_cnt; i++) {
      if (box_pokemon_hatching_proceed(&player_pokemon[i].box, true, true, 1)) {
        // Hatch this pokemon
        *var_access(0x8004) = i;
        return true;
      }
    }
    // Proceed incubator
    for (int i = 0; i < incubator_available_slots(); i++) {
      if (box_pokemon_hatching_proceed(&cmem.incubator_slots[i], true, false, 2)){
        // Mark the pokemon to hatch immediatley
        int cycles = BREEDING_CYCLES_HATCH_IMMEDIATLEY;
        box_pokemon_set_attribute(&cmem.incubator_slots[i], ATTRIBUTE_HAPPINESS, &cycles);
        *var_access(0x8004) = (u16)(i + 6);
        return true;
      }
    }
  }
  return false;
}
