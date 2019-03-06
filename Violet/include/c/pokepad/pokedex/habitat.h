/*
 * habitat.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_HABITAT_H_
#define INCLUDE_C_POKEPAD_POKEDEX_HABITAT_H_

#define HABITAT_TYPE_GRASS 0
#define HABITAT_TYPE_WASSER 1
#define HABITAT_TYPE_ROD 2
#define HABITAT_TYPE_RADAR 3

typedef struct {
        u16 *data;
        int page_size;
    } pokedex_page;

    typedef struct {
        pokedex_page *pages;
        int page_cnt;
    } pokedex_habitat;

    typedef struct {
        u8 _namespace;
        u8 probability; //0 rare, 1 medium, 2 common
        u8 type; //0 grass, 1 water, 2 rod, 3 radar
    } pokedex_habitat_pair;

    void pokedex_habitat_callback_idle();
    void pokedex_habitat_callback_init_entry();
    void pokedex_habitats_load_for_species(u16 *bg0map);
    int pokedex_get_namespaces_of_species(pokedex_habitat_pair *dst, u16 species);
    int pokedex_get_namespace_of_species_add_pair_if_not_present(pokedex_habitat_pair *dst, int cnt, u8 namespace, u8 propability, u8 type);

#endif /* INCLUDE_C_POKEPAD_POKEDEX_HABITAT_H_ */
