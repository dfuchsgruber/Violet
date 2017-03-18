#include "types.h"
#include "pokemon.h"
#include "romfuncs.h"
#include "basestats.h"

u16 pokemon_calculate_checksum(pokemon *p){
    //We automatically return the value the checksum is later compared with,
    //This way we do not need any checksums
    return p->checksum;
}

u8 pokemon_nature_by_pid(pid p){
    u8 nat = (u8)p.fields.nature;
    if(nat > 24) nat /= 2;
    return nat;
}

u8 pokemon_get_nature(pokemon *p){
    return pokemon_nature_by_pid(p->pid);
}

bool pokemon_is_shiny(u32 tid, pid p){
    (void)tid;
    return p.fields.shinyness <= 512;
}

palette *pokemon_get_pal_struct(u16 species, u32 tid, pid p){
    if(pokemon_is_shiny(tid, p))
        return &pokemon_shiny_pals[species];
    else
        return &pokemon_pals[species];
    
}

const void *pokemon_get_pal(u16 species, u32 tid, pid p){
    return pokemon_get_pal_struct(species, tid, p)->pal;
}