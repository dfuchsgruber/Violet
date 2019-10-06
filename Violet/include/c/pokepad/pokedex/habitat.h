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
#define HABITAT_TYPE_GOOD_ROD 4
#define HABITAT_TYPE_SUPER_ROD 5

#define HABITAT_OUTSIDE 0
#define HABITAT_CAVE 1
#define HABITAT_CLOUD 2

typedef struct {
        u16 *data;
        int page_size;
    } pokedex_page;

    typedef struct {
        pokedex_page *pages;
        int page_cnt;
    } pokedex_habitat;

    typedef struct {
        u8 worldmap_x;
        u8 worldmap_y;
        u8 probability;
        u8 type; //0 grass, 1 water, 2 rod, 3 radar
    } pokedex_habitat_pair;

    void pokedex_habitat_callback_idle();
    void pokedex_habitat_callback_init_entry();
    void pokedex_habitats_load_for_species(u16 *bg0map);

    /**
     * Builds a list of all habitats of a species, i.e. all positions on the worldmap for a possible encounter type.
     * @param dst the list to build
     * @param species the habitat list to build
     **/
    int pokedex_get_habitats_of_species(pokedex_habitat_pair *dst, u16 species);

    /** Adds a certain map (i.e. all positions on the worlmap associated with it) to the habitat list.
     * @param bank the bank of the map to add
     * @param map_idx the map index of the map to add
     * @param dst the map list where to add the habitat to
     * @param size pointer to the number of elements in the habitat lsit
     * @param probability the probability (in %) of the pokemon to appear
     * @param habitat_type which kind of encounter the species appears in
     **/
    void pokedex_habitats_add(u8 bank, u8 map_idx, pokedex_habitat_pair *dst, int *size, int probability, int habitat_type);

    /** Adds a certain position to the habitat list.
     * @param x the x coordinate to add
     * @param y the y coordinate to add
     * @param dst the map list where to add the habitat to
     * @param size pointer to the number of elements in the habitat lsit
     * @param probability the probability (in %) of the pokemon to appear
     * @param habitat_type which kind of encounter the species appears in
     **/
    void pokedex_habitats_add_position(int x, int y, pokedex_habitat_pair *dst, int *size, int probability, int habitat_type);

    int pokedex_get_namespace_of_species_add_pair_if_not_present(pokedex_habitat_pair *dst, int cnt, u8 namespace, u8 propability, u8 type);

#endif /* INCLUDE_C_POKEPAD_POKEDEX_HABITAT_H_ */
