/*
 * buffer.c
 *
 *  Created on: Sep 26, 2018
 *      Author: dominik
 */

#include "types.h"
#include "text.h"
#include "constants/pokemon_types.h"
#include "language.h"

u8 *typetoa(u8 *dst, u8 type) {
	return strcpy(dst, str_types[type]);
}

u8 *typetoa_long(u8 *dst, u8 type) {
	return strcpy(dst, str_types_long[type]);
}


const u8 str_types[][7] = {
	LANGDEP(PSTRING("Normal"), PSTRING("Normal")),
	LANGDEP(PSTRING("Kampf"), PSTRING("Fight.")),
	LANGDEP(PSTRING("Flug"), PSTRING("Flying")),
	LANGDEP(PSTRING("Gift"), PSTRING("Poison")),
	LANGDEP(PSTRING("Boden"), PSTRING("Ground")),
	LANGDEP(PSTRING("Gest."), PSTRING("Rock")),
	LANGDEP(PSTRING("Käfer"), PSTRING("Bug")),
	LANGDEP(PSTRING("Geist"), PSTRING("Ghost")),
	LANGDEP(PSTRING("Stahl"), PSTRING("Steel")),
	LANGDEP(PSTRING("Fee"), PSTRING("Fairy")),
	LANGDEP(PSTRING("Feuer"), PSTRING("Fire")),
	LANGDEP(PSTRING("Wasser"), PSTRING("Water")),
	LANGDEP(PSTRING("Pfl."), PSTRING("Grass")),
	LANGDEP(PSTRING("Elek."), PSTRING("Elec.")),
	LANGDEP(PSTRING("Psycho"), PSTRING("Psy.")),
	LANGDEP(PSTRING("Eis"), PSTRING("Ice")),
	LANGDEP(PSTRING("Drache"), PSTRING("Dragon")),
	LANGDEP(PSTRING("Unl."), PSTRING("Dark"))
};

const u8 str_types_long[][8] = {
	LANGDEP(PSTRING("Normal"), PSTRING("Normal")),
	LANGDEP(PSTRING("Kampf"), PSTRING("Fighting")),
	LANGDEP(PSTRING("Flug"), PSTRING("Flying")),
	LANGDEP(PSTRING("Gift"), PSTRING("Poison")),
	LANGDEP(PSTRING("Boden"), PSTRING("Ground")),
	LANGDEP(PSTRING("Gestein"), PSTRING("Rock")),
	LANGDEP(PSTRING("Käfer"), PSTRING("Bug")),
	LANGDEP(PSTRING("Geist"), PSTRING("Ghost")),
	LANGDEP(PSTRING("Stahl"), PSTRING("Steel")),
	LANGDEP(PSTRING("Fee"), PSTRING("Fairy")),
	LANGDEP(PSTRING("Feuer"), PSTRING("Fire")),
	LANGDEP(PSTRING("Wasser"), PSTRING("Water")),
	LANGDEP(PSTRING("Pflanze"), PSTRING("Grass")),
	LANGDEP(PSTRING("Elektro"), PSTRING("Electric")),
	LANGDEP(PSTRING("Psycho"), PSTRING("Psychic")),
	LANGDEP(PSTRING("Eis"), PSTRING("Ice")),
	LANGDEP(PSTRING("Drache"), PSTRING("Dragon")),
	LANGDEP(PSTRING("Unlicht"), PSTRING("Dark"))
};
