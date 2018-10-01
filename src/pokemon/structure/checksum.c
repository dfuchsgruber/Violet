#include "types.h"
#include "oam.h"
#include "stdbool.h"
#include "pokemon/virtual.h"
#include "pokemon/sprites.h"
#include "prng.h"
#include "save.h"
#include "vars.h"
#include "constants/vars.h"
#include "math.h"
#include "debug.h"

pid_t pokemon_new_pid() {
	pid_t p;
	p.fields.ability = (u8)(rnd16() & 1);
	p.fields.form = 0;
	p.fields.gender_partial = (u8)(rnd16() & 127);
	p.fields.nature = (u8)((rnd16() % 25) & 31);

	// Use slash count to increase the shiny rate
	int splash_cnt = min(99, save_get_key(0x1A));

	if (rnd16() % 1000 <= splash_cnt / 10) {
		// Shiny rate of exactly 0.1% + (#Splash used) * 0.01% and maximum at 1%
		p.fields.is_shiny = 1;
	} else {
		p.fields.is_shiny = 0;
	}

	// Force shinyness via variable
	u16 *next_shiny_pokemon = var_access(NEXT_POKEMON_SHINY);
	dprintf("Next shinies %d\n", *next_shiny_pokemon);
	if(*next_shiny_pokemon > 0){
		p.fields.is_shiny = 1;
		(*next_shiny_pokemon)--;
	}
	return p;
}


pid_t pokemon_new_pid_with_nature(int nature) {
	pid_t p = pokemon_new_pid();
	p.fields.nature = (u8)(nature & 31);
	return p;
}

u16 pokemon_calculate_checksum(pokemon *p){
    //We automatically return the value the checksum is later compared with,
    //This way we do not need any checksums
    return p->checksum;
}

u8 pokemon_nature_by_pid(pid_t p){
    u8 nat = (u8)p.fields.nature;
    if(nat > 24) {
    	dprintf("Nature value too high! %d\n", nat);
    	nat /= 2;
    }
    return nat;
}

u8 pokemon_get_nature(pokemon *p){
    return pokemon_nature_by_pid(p->pid);
}

bool pokemon_is_shiny(u32 tid, pid_t p){
    (void)tid;
    return p.fields.is_shiny > 0;
}

palette *pokemon_get_pal_struct(u16 species, u32 tid, pid_t p){
    //dprintf("Pokemon get pal struct for species %d, pid %x, tid %x\n", species, p.fields.shinyness, tid);
    if(pokemon_is_shiny(tid, p))
        return &pokemon_shiny_pals[species];
    else
        return &pokemon_pals[species];
    
}

const void *pokemon_get_pal(u16 species, u32 tid, pid_t p){
    return pokemon_get_pal_struct(species, tid, p)->pal;
}
