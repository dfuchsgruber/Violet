/*
 * habitat.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_HABITAT_H_
#define INCLUDE_C_POKEPAD_POKEDEX_HABITAT_H_

enum {
    HABITAT_TYPE_GRASS = 0,
    HABITAT_TYPE_WATER,
    HABITAT_TYPE_RADAR,
    HABITAT_TYPE_OLD_ROD,
    HABITAT_TYPE_GOOD_ROD,
    HABITAT_TYPE_SUPER_ROD,
    NUM_HABITAT_TYPES,
};

enum {
    HABITAT_MAP_TYPE_OUTSIDE = 0,
    HABITAT_MAP_TYPE_CAVE,
};

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
        u8 habitat_type;
        u8 worldmap_idx;
        u8 layer;
        u8 map_type;
    } pokedex_habitat_pair;

    #define POKEDEX_HABITAT_LIST_MAX_SIZE 2048

    typedef struct {
        pokedex_habitat_pair *list;
        size_t num_elements;
        size_t array_size;
        size_t max_array_size; // Error is thrown if `array_size` would exceed this
    } pokedex_habitat_list_t;

    /**
     * Creates a new list to collect habitats of a species by worldmap
     * @param initial_array_size the initial array size of the list
     * @param max_array_size how big the array is allowed to grow at max
     * @return the newly created list
    */
    pokedex_habitat_list_t *pokedex_habitat_list_new(size_t initial_array_size, size_t max_array_size);

    /**
     * Deletes (and frees) a habitat list for a species
     * @param list the list to delete
    */
    void pokedex_habitat_list_delete(pokedex_habitat_list_t *list);

    /**
     * Fills the list of habitats of a certain species by worldmap position
     * @param list the list to fill
     * @param species for which species
    */
    void pokedex_habitat_list_compute_by_species(pokedex_habitat_list_t *list, u16 species);

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
     * @param map_type the type of the map the encounter happens on
     **/
    void pokedex_habitats_add(u8 bank, u8 map_idx, pokedex_habitat_pair *dst, int *size, int probability, int habitat_type, int map_type);

    /** Adds a certain position to the habitat list.
     * @param x the x coordinate to add
     * @param y the y coordinate to add
     * @param dst the map list where to add the habitat to
     * @param size pointer to the number of elements in the habitat lsit
     * @param probability the probability (in %) of the pokemon to appear
     * @param habitat_type which kind of encounter the species appears in
     * @param map_type the type of the map the encounter happens on
     **/
    void pokedex_habitats_add_position(int x, int y, pokedex_habitat_pair *dst, int *size, int probability, int habitat_type, int map_type);

#endif /* INCLUDE_C_POKEPAD_POKEDEX_HABITAT_H_ */
