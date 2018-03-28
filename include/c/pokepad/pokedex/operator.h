/*
 * operator.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_OPERATOR_H_
#define INCLUDE_C_POKEPAD_POKEDEX_OPERATOR_H_

#define POKEDEX_GET 0
#define POKEDEX_SET 2
#define POKEDEX_SEEN 0
#define POKEDEX_CAUGHT 1


bool pokedex_operator(u16 val, u8 op, bool is_species_id);
u8* pokedex_flag_access(u16 flag, bool seen);
u16 pokedex_get_number_seen_or_caught(bool caught);

u16 pokedex_get_id(u16 species);
bool pokedex_operator_by_dex_id(u16 dex_id, u8 op);
bool national_dex_is_achieved();
u16 pokemon_get_display_number(u16 species);
u16 pokedex_get_species_by_dex_id(u16 dex_id);

#endif /* INCLUDE_C_POKEPAD_POKEDEX_OPERATOR_H_ */
