/*
 * pokedex_get_pid.c
 *
 *  Created on: Oct 1, 2018
 *      Author: dominik
 */
#include "constants/species.h"
#include "pokemon/virtual.h"
#include "save.h"
#include "types.h"

pid_t pokedex_get_pid(u16 species) {
    pid_t p = {.value = 0};
    if (species == POKEMON_ICOGNITO) {
        p = save2->icognito_pid;
    } else if (species == POKEMON_PANDIR) {
        p = save2->pandir_pid;
    }
    p.fields.is_shiny = 0;
    return p;
}
