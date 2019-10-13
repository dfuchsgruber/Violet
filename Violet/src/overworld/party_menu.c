#include "types.h"
#include "pokemon/virtual.h"
#include "field_move.h"
#include "overworld/pokemon_party_menu.h"
#include "constants/pokemon_attributes.h"

void pokemon_party_menu_options_build(pokemon *base, u8 index) {
    pokemon_party_menu_options_state_t *options_state = pokemon_party_menu_state.options_state;
    options_state->number_options = 0;
    pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 0); //Adding summary
    //adding field moves
    int i;
    for (i = 0; i < 4; i++) {
        u16 attack = (u16) pokemon_get_attribute(&base[index], ATTRIBUTE_ATTACK1 + i, NULL);
        int j;
        for (j = 0; field_moves[j] != 0xFFFF; j++) {
            if (attack == field_moves[j]) {
                pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, (u8) (j + 0x12));
            }
        }
    }
    //adding switch
    if (pokemon_get_attribute(&base[1], ATTRIBUTE_SPECIES, NULL)) {
        //at least two pokemon are present
        pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 1); //Adding switch
    }
    //Adding back button and items
    pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 3);
    //Adding ev menu
    if (!pokemon_get_attribute(&base[index], ATTRIBUTE_IS_EGG, NULL) && options_state->number_options < 7) {
        pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 6);
    }
    pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 2);
}