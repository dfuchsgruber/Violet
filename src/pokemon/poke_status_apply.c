#include "types.h"
#include "basestats.h"
#include "types.h"
#include "pokemon.h"
#include "romfuncs.h"

void special_heal_team_index() {
    pokemon *p = (pokemon*) malloc(sizeof (pokemon) * 6);
    memcopy(p, player_pokemon, sizeof (pokemon) * 6);
    pokemon_heal_all();
    u16 team_index = *vardecrypt(0x8004);
    u16 i;
    for (i = 0; i < 6; i++) {
        if (i != team_index) {
            memcopy(&player_pokemon[i], &p[i], sizeof (pokemon));
        }
    }
    free(p);
}
