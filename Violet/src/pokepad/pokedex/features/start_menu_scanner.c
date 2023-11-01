#include "types.h"
#include "pokepad/pokedex/scanner.h"
#include "agbmemory.h"

#define PAL_TAG_GFX_MENU_SCANNER 0xC29B

void start_menu_print_scanner() {
    pokedex_scanner_data_t *data = malloc(sizeof(pokedex_scanner_data_t));
    pokedex_scanner_unique_species_list_t *list = malloc(sizeof(pokedex_scanner_unique_species_list_t));
    if (data && list) {
        pokedex_feature_scanner_build_all_entries(&pokedex_scanner_state->data, map_wild_pokemon_get_current());
        pokedex_scanner_build_unique_species(list, &pokedex_scanner_state->data);


    }
    free(data);
    free(list);    
}