#include "types.h"
#include "pokemon/virtual.h"
#include "constants/species.h"

void test_tollwut() {
    pid_t pid = {0};
    pokemon_new(player_pokemon, POKEMON_TAUROS, 25, POKEMON_NEW_RANDOM_IVS, false, pid, false, 0);
    pokemon_set_hidden_ability(&player_pokemon->box);
}