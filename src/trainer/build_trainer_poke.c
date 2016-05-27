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
#include "map.h"


static u8 ev_finals[6] = {0x16, 0x17, 0x18, 0x21, 0x2F, 0x30};

static build builds [14] = {
	
	{0, {0, 0, 0, 0, 0, 0}, 0}, //None
	{NATURE_HART, {4, 252, 0, 252, 0, 0}, 0}, //physical sweep attack preference
	{NATURE_FROH, {4, 252, 0, 252, 0, 0}, 0}, //physical sweep init preference
	{NATURE_MAESSIG, {4, 0, 252, 252, 0, 0}, 0}, //special sweep sattack preference
	
	{NATURE_SCHEU, {4, 0, 252, 252, 0, 0}, 0}, //special sweep init preference
	{NATURE_KUEHN, {252, 0, 252, 0, 0, 4}, 0}, //physical wall attack minus
	{NATURE_PFIFFIG, {252, 0, 252, 0, 0, 4}, 0}, //physical wall sattack minus
	{NATURE_STILL, {252, 0, 4, 0, 0, 252}, 0}, //special wall attack minus
	
	{NATURE_SACHT, {252, 0, 4, 0, 0, 252}, 0}, //special wall sattack minus
	{NATURE_ROBUST, {40, 40, 40, 40, 40, 40}, 0}, //balanced weak
	{NATURE_ROBUST, {85, 85, 85, 85, 85, 85}, 0}, //balanced strong
	{NATURE_NAIV, {0, 252, 0, 4, 252, 0}, 0},	//mixed sweeper
	
	{NATURE_HART, {252, 252, 0, 4, 0, 0}, 0}, //tanky phyiscal
	{NATURE_MAESSIG, {252, 0, 0, 4, 252, 0}, 0} //tanky special 
	
};



void build_trainer_poke(union union_build_field field, pokemon *poke){
	
	if (field.value != 0x20){
		
		if (!field.value){
			switch (*(vardecrypt(0x50F9))){
				case 0:
				case 1:
				case 2:
				default:
					return;
				case 3:
					//difficult
					field.bitfield.build = 9;
					break;
				case 4:
					//very difficult
					field.bitfield.build = 10;
					break;
			}
			field.bitfield.ability = (u8)(random_change_seed() & 1); //random ability still
		}
		
		
		union u_pid p = {get_pokemons_attribute (poke, 0, 0)};
		p.bitfield.shinyness = field.bitfield.shinyness ? 0 : 0x201;
		p.bitfield.nature = (builds[field.bitfield.build].nature);
		set_pokemons_attribute (poke, 0, &p);
		
		
		u8 ability = field.bitfield.ability & 1;
		set_pokemons_attribute (poke, ATTRIBUTE_ABILITY, &ability);
		
		u8 poke_coolness_field = (u8)( get_pokemons_attribute (poke, 0x16, 0) & 0x7F );
		poke_coolness_field = (u8) (poke_coolness_field | (field.bitfield.hability << 7));
		set_pokemons_attribute(poke, 0x16, &poke_coolness_field);
		
		if (!get_pokemons_attribute(poke, 0xC, 0)){
			set_pokemons_attribute(poke, 0xC, &builds[field.bitfield.build].prefered_item);
		}
		
		int i;
		for (i = 0; i < 6; i++){
			u8 max_iv = 31;
			set_pokemons_attribute(poke, (u16)(ATTRIBUTE_HP_IV+i), &max_iv);
			
			u8 effective_ev = (u8)(builds[field.bitfield.build].evs[i] >> 2);
			effective_ev = (u8)((get_pokemons_attribute(poke, ev_finals[i], 0) & 0xC0) | effective_ev);
			set_pokemons_attribute (poke, ev_finals[i], &effective_ev);
			
		}
		
		recalculate_stats(poke);
	}
}