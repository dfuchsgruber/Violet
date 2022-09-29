#include "types.h"
#include "oam.h"
#include "stdbool.h"
#include "pokemon/virtual.h"
#include "pokemon/sprites.h"
#include "pokemon/basestat.h"
#include "prng.h"
#include "save.h"
#include "vars.h"
#include "constants/vars.h"
#include "math.h"
#include "debug.h"
#include "constants/pokemon_stat_names.h"
#include "constants/pokemon_attributes.h"
#include "item/pokeball.h"

static bool pokemon_new_gender_is_female(u16 species, u16 (*rnd)()) {
	if (rnd == NULL)
		rnd = rnd16;
	switch (basestats[species].gender_value) {
		case POKEMON_GENDER_MALE:
		case POKEMON_GENDER_GENDERLESS:
			return false;
		case POKEMON_GENDER_FEMALE:
			return true;
		default:
			return (rnd() & 0xFF) < basestats[species].gender_value;
	}
}

// static bool pokemon_new_gender_is_female(u16 species, u16 (*rnd)()) {
// 	int male_trials = 0;
// 	for (int i = 0; i < 100; i++) {
// 		if (_pokemon_new_gender_is_female(species, rnd))
// 			male_trials++;
// 	}
// 	DEBUG("New gender for pokemon %d, actual rate %d, empirical %d\n", species, basestats[species].gender_value * 100 / 255, male_trials);
// 	return _pokemon_new_gender_is_female(species, rnd);
// }

pid_t pokemon_new_pid_by_prng(u16 species, u16 (*rnd)()) {
	pid_t p;
	p.fields.ability = (u8)(rnd() & 1);
	p.fields.form = 0;
	p.fields.unown_letter = (u32)(rnd() % 28 & 31);
	p.fields.is_female = (u8)(pokemon_new_gender_is_female(species, rnd) & 1);
	p.fields.nature = (u8)((rnd() % 25) & 31);
	p.fields.hidden_power_type = (u8)((rnd() % 18) & 31);
	p.fields.hidden_power_strength = (u8)(rnd() & 7);

	// Use slash count to increase the shiny rate
	int splash_cnt = MIN(99, save_get_key(SAVE_KEY_SPLASH_USED));

	if (rnd() % 1000 <= splash_cnt / 10) {
		// Shiny rate of exactly 0.1% + (#Splash used) * 0.01% and maximum at 1%
		p.fields.is_shiny = 1;
	} else {
		p.fields.is_shiny = 0;
	}
	return p;
}

pid_t pokemon_new_pid(u16 species) {
	pid_t p = pokemon_new_pid_by_prng(species, rnd16);
	// Force shinyness via variable
	u16 *next_shiny_pokemon = var_access(NEXT_POKEMON_SHINY);
	DEBUG("Next shinies %d\n", *next_shiny_pokemon);
	if(*next_shiny_pokemon > 0){
		p.fields.is_shiny = 1;
		(*next_shiny_pokemon)--;
	}
	return p;
}


pid_t pokemon_new_pid_with_nature(u16 species, int nature) {
	pid_t p = pokemon_new_pid(species);
	p.fields.nature = (u8)(nature & 31);
	return p;
}

u16 pokemon_calculate_checksum(pokemon *p){
    //We automatically return the value the checksum is later compared with,
    //This way we do not need any checksums
    return p->box.checksum;
}

u8 pokemon_nature_by_pid(pid_t p){
    u8 nat = (u8)p.fields.nature;
    if(nat > 24) {
    	DEBUG("Nature value too high! %d\n", nat);
    	nat /= 2;
    }
    return nat;
}

u8 pokemon_get_nature(pokemon *p){
	pid_t pid = {.value = (u32)pokemon_get_attribute(p, ATTRIBUTE_PID, 0)};
    return pokemon_nature_by_pid(pid);
}

bool pokemon_is_shiny(u32 tid, pid_t p){
    (void)tid;
    return p.fields.is_shiny > 0;
}

palette *pokemon_get_pal_struct(u16 species, u32 tid, pid_t p){
    //DEBUG("Pokemon get pal struct for species %d, pid %x, tid %x\n", species, p.fields.shinyness, tid);
    if(pokemon_is_shiny(tid, p))
        return &pokemon_shiny_pals[species];
    else
        return &pokemon_pals[species];
    
}

const void *pokemon_get_pal(u16 species, u32 tid, pid_t p){
    return pokemon_get_pal_struct(species, tid, p)->pal;
}

void box_pokemon_set_pokeball_in_substructure (pokemon_substructure_section_D *subs, u8 pokeball_idx) {
	DEBUG("Set pokeball of 0x%x to %d\n", subs, pokeball_idx);
	subs->pokeball = (u8)(pokeball_idx & 0x1F);
}

void box_pokemon_set_game_in_substructure (pokemon_substructure_section_D *subs, u8 game) {
	subs->catch_game = (u8)(game & 7);
}

int box_pokemon_get_pokeball_in_substructure(pokemon_substructure_section_D *subs) {
	return subs->pokeball;
}

int box_pokemon_get_game_in_substructure(pokemon_substructure_section_D *subs) {
	return subs->catch_game;
}

u8 pokemon_get_gender_by_pid(u16 species, pid_t pid) {
	switch (basestats[species].gender_value) {
		case POKEMON_GENDER_MALE:
		case POKEMON_GENDER_FEMALE:
		case POKEMON_GENDER_GENDERLESS:
			return basestats[species].gender_value;
		default:
			if (pid.fields.is_female)
				return POKEMON_GENDER_FEMALE;
			else
				return POKEMON_GENDER_MALE;
	}
}

u8 box_pokemon_get_gender(box_pokemon *p) {
	pid_t pid = {.value = (u32)box_pokemon_get_attribute(p, ATTRIBUTE_PID, NULL)};
	return pokemon_get_gender_by_pid((u16)box_pokemon_get_attribute(p, ATTRIBUTE_SPECIES, NULL), pid);
}

u8 pokemon_get_gender(pokemon *p) {
	return box_pokemon_get_gender(&p->box);
}