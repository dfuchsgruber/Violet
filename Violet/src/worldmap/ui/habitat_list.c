#include "types.h"
#include "pokepad/pokedex/habitat.h"
#include "map/header.h"
#include "map/wild_pokemon.h"
#include "pokemon/roamer.h"
#include "save.h"
#include "constants/map_namespaces.h"
#include "worldmap.h"
#include "debug.h"
#include "constants/map_types.h"
#include "agbmemory.h"

pokedex_habitat_list_t *pokedex_habitat_list_new(size_t initial_array_size, size_t max_array_size) {
    pokedex_habitat_list_t *list = malloc(sizeof(pokedex_habitat_list_t));
    list->list = malloc(sizeof(pokedex_habitat_pair) * initial_array_size);
    list->num_elements = 0;
    list->array_size = initial_array_size;
    list->max_array_size = max_array_size;
    return list;
}

void pokedex_habitat_list_delete(pokedex_habitat_list_t *list) {
    if (list) {
        if (list->list)
            free(list->list);
        free(list);
    }
}

static void pokedex_habitat_list_reallocate(pokedex_habitat_list_t *list, size_t new_array_size) {
    if (new_array_size > list->max_array_size)
        ERROR("Trying to allocate a habitat array of size %d which exceeds the maximum %d\n", new_array_size, list->max_array_size);
    pokedex_habitat_pair *new_array = malloc(sizeof(pokedex_habitat_pair) * new_array_size);
    for (size_t i = 0; i < list->num_elements; i++)
        new_array[i] = list->list[i];
    free(list->list);
    list->list = new_array;
    list->array_size = new_array_size;
}


static void pokedex_habitat_list_add_position(pokedex_habitat_list_t *list, int x, int y, int worldmap_idx,
    int layer, int probability, int habitat_type, int map_type) {
    for (size_t i = 0; i < list->num_elements; i++) {
        if (list->list[i].worldmap_x == x && list->list[i].worldmap_y == y && list->list[i].habitat_type == habitat_type 
            //&& dst[i].map_type == map_type // for now, we do not separate map types in the current UI
            ) {
            list->list[i].probability = (u8)MAX(list->list[i].probability, probability);
            return;
        }
    }
    // Add a new entry to the list
    if (list->num_elements == list->array_size)
        pokedex_habitat_list_reallocate(list, 2 * list->array_size);
    DEBUG("Add habitat position (%d, %d)\n", x, y);
    list->list[list->num_elements].worldmap_x = (u8)x;
    list->list[list->num_elements].worldmap_y = (u8)y;
    list->list[list->num_elements].worldmap_idx = (u8)worldmap_idx;
    list->list[list->num_elements].layer = (u8)layer;
    list->list[list->num_elements].probability = (u8)probability;
    list->list[list->num_elements].habitat_type = (u8)habitat_type;
    list->list[list->num_elements].map_type = (u8)map_type; // currently we do not care about this
    list->num_elements++;
}

static void pokedex_habitats_add_map(pokedex_habitat_list_t *list, u8 bank, u8 map_idx, int probability, int habitat_type, int map_type) {
    DEBUG("Found species at %d.%d with m_type %d, h_type %d and probability of %d percent.\n", bank, map_idx, map_type, habitat_type, probability);
    for (int i = 0; i < worldmap_positions[bank][map_idx].width; i++) {
        for (int j = 0; j < worldmap_positions[bank][map_idx].height; j++) {
            pokedex_habitat_list_add_position(list, 
                worldmap_positions[bank][map_idx].x + i,
                worldmap_positions[bank][map_idx].y + j, 
                worldmap_positions[bank][map_idx].worldmap_idx, 
                worldmap_positions[bank][map_idx].layer,
                probability, habitat_type, map_type);
        }
    }
}

static u8 pokdex_map_type_to_habitat_map_type[] = {
    [MAP_TYPE_STD] = HABITAT_MAP_TYPE_OUTSIDE,
    [MAP_TYPE_VILLAGE] = HABITAT_MAP_TYPE_OUTSIDE,
    [MAP_TYPE_CITY] = HABITAT_MAP_TYPE_OUTSIDE,
    [MAP_TYPE_ROUTE] = HABITAT_MAP_TYPE_OUTSIDE,
    [MAP_TYPE_BASEMENT] = HABITAT_MAP_TYPE_CAVE,
    [MAP_TYPE_CLOUD] = HABITAT_MAP_TYPE_CAVE,
    [MAP_TYPE_TYPE_06] = HABITAT_MAP_TYPE_OUTSIDE,
    [MAP_TYPE_TYPE_07] = HABITAT_MAP_TYPE_OUTSIDE,
    [MAP_TYPE_INSIDE] = HABITAT_MAP_TYPE_CAVE,
    [MAP_TYPE_SECRET_BASE] = HABITAT_MAP_TYPE_CAVE,
};

void pokedex_habitat_list_compute_by_species(pokedex_habitat_list_t *list, u16 species) {
    for (int i = 0; wild_pokemon[i].bank != 0xFF; i++) {
        // Check grass habitats
        int map_type = pokdex_map_type_to_habitat_map_type[get_mapheader(wild_pokemon[i].bank, wild_pokemon[i].map)->type];
        if (wild_pokemon[i].grass) {
            int probability = 0;
            for (int j = 0; j < WILD_POKEMON_NUM_ENTRIES_GRASS; j++) {
                if (wild_pokemon[i].grass->data[j].species == species) {
                    probability += wild_pokemon_grass_pdf[j];
                }
            }
            if (probability > 0) 
                pokedex_habitats_add_map(list, wild_pokemon[i].bank, wild_pokemon[i].map, probability, HABITAT_TYPE_GRASS, map_type);
        }
        if (wild_pokemon[i].water) {
            int probability = 0;
            for (int j = 0; j < WILD_POKEMON_NUM_ENTRIES_WATER; j++) {
                if (wild_pokemon[i].water->data[j].species == species) {
                    probability += wild_pokemon_water_pdf[j];
                }
            }
            if (probability > 0)
                pokedex_habitats_add_map(list, wild_pokemon[i].bank, wild_pokemon[i].map, probability, 
                    HABITAT_TYPE_WATER, map_type);
        }
        if (wild_pokemon[i].other) {
            int probability = 0;
            for (int j = 0; j < WILD_POKEMON_NUM_ENTRIES_OTHER; j++) {
                if (wild_pokemon[i].other->data[j].species == species) {
                    probability += wild_pokemon_other_pdf[j];
                }
            }
            if (probability > 0) 
                pokedex_habitats_add_map(list, wild_pokemon[i].bank, wild_pokemon[i].map, 
                    probability, HABITAT_TYPE_RADAR, map_type);
        }
        if (wild_pokemon[i].rod) {
            int probability = 0;
            for (int j = 0; j < WILD_POKEMON_NUM_ENTRIES_ROD; j++) {
                if (wild_pokemon[i].rod->data[j].species == species) {
                    probability += wild_pokemon_rod_pdf[j];
                }
            }
            if (probability > 0) 
                pokedex_habitats_add_map(list, wild_pokemon[i].bank, wild_pokemon[i].map, probability, 
                    HABITAT_TYPE_OLD_ROD, map_type);
            probability = 0;
            for (int j = 0; j < WILD_POKEMON_NUM_ENTRIES_GOOD_ROD; j++) {
                if (wild_pokemon[i].rod->data[WILD_POKEMON_NUM_ENTRIES_ROD + j].species == species) {
                    probability += wild_pokemon_good_rod_pdf[j];
                }
            }
            if (probability > 0) 
                pokedex_habitats_add_map(list, wild_pokemon[i].bank, wild_pokemon[i].map, probability, 
                    HABITAT_TYPE_GOOD_ROD, map_type);
            probability = 0;
            for (int j = 0; j < WILD_POKEMON_NUM_ENTRIES_SUPER_ROD; j++) {
                if (wild_pokemon[i].rod->data[WILD_POKEMON_NUM_ENTRIES_ROD + WILD_POKEMON_NUM_ENTRIES_GOOD_ROD + j].species == species) {
                    probability += wild_pokemon_super_rod_pdf[j];
                }
            }
            if (probability > 0) 
                pokedex_habitats_add_map(list, wild_pokemon[i].bank, wild_pokemon[i].map, probability, 
                    HABITAT_TYPE_GOOD_ROD, map_type);
        }
    }
    int roamer_idx = species_to_roamer_idx(species);
    if (roamer_idx != -1 && csave.roamers[roamer_idx].is_present) {
        u8 bank = csave.roamer_locations[roamer_idx].bank;
        u8 map_idx = csave.roamer_locations[roamer_idx].map_idx;
        int map_type = pokdex_map_type_to_habitat_map_type[get_mapheader(bank, map_idx)->type];
        pokedex_habitats_add_map(list, bank, map_idx, 50, HABITAT_TYPE_GRASS, map_type);
        pokedex_habitats_add_map(list, bank, map_idx, 50, HABITAT_TYPE_WATER, map_type);
    }
}

