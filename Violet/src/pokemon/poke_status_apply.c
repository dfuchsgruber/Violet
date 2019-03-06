#include "types.h"
#include "stdbool.h"
#include "pokemon/virtual.h"
#include "bios.h"
#include "vars.h"
#include "agbmemory.h"

void special_heal_team_index() {
    pokemon *p = (pokemon*) malloc(sizeof (pokemon) * 6);
    memcpy(p, player_pokemon, sizeof (pokemon) * 6);
    pokemon_heal_player_party();
    u16 team_index = *var_access(0x8004);
    u16 i;
    for (i = 0; i < 6; i++) {
        if (i != team_index) {
            memcpy(&player_pokemon[i], &p[i], sizeof (pokemon));
        }
    }
    free(p);
}
