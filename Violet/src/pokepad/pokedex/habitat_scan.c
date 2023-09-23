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

void pokedex_habitats_add_position(int x, int y, pokedex_habitat_pair *dst, int *size, int probability, int habitat_type, int map_type) {
    for (int i = 0; i < *size; i++) {
        if (dst[i].worldmap_x == x && dst[i].worldmap_y == y && dst[i].habitat_type == habitat_type && dst[i].map_type == map_type) {
            dst[i].probability = (u8)MAX(dst[i].probability, probability);
            return;
        }
    }
    DEBUG("Add habitat position (%d, %d)\n", x, y);
    dst[*size].worldmap_x = (u8)x;
    dst[*size].worldmap_y = (u8)y;
    dst[*size].probability = (u8)probability;
    dst[*size].habitat_type = (u8)habitat_type;
    dst[*size].map_type = (u8)map_type;
    (*size)++;
}


void pokedex_habitats_add(u8 bank, u8 map_idx, pokedex_habitat_pair *dst, int *size, int probability, int habitat_type, int map_type) {
    DEBUG("Size of habitats %d\n", *size);
    DEBUG("Found species at %d.%d with m_type %d, h_type %d and probability of %d percent.\n", bank, map_idx, map_type, habitat_type, probability);
    for (int i = 0; i < worldmap_positions[bank][map_idx].width; i++) {
        for (int j = 0; j < worldmap_positions[bank][map_idx].height; j++) {
            pokedex_habitats_add_position(worldmap_positions[bank][map_idx].x + i,
                worldmap_positions[bank][map_idx].y + j, dst, size, probability, habitat_type, map_type);
        }
    }
}

static const u8 pokdex_map_type_to_habitat_map_type[] = {
    [MAP_TYPE_STD] = HABITAT_OUTSIDE,
    [MAP_TYPE_VILLAGE] = HABITAT_OUTSIDE,
    [MAP_TYPE_CITY] = HABITAT_OUTSIDE,
    [MAP_TYPE_ROUTE] = HABITAT_OUTSIDE,
    [MAP_TYPE_BASEMENT] = HABITAT_CAVE,
    [MAP_TYPE_CLOUD] = HABITAT_CLOUD,
    [MAP_TYPE_TYPE_06] = HABITAT_OUTSIDE,
    [MAP_TYPE_TYPE_07] = HABITAT_OUTSIDE,
    [MAP_TYPE_INSIDE] = HABITAT_CAVE,
    [MAP_TYPE_SECRET_BASE] = HABITAT_CAVE,
};

int pokedex_get_habitats_of_species(pokedex_habitat_pair *dst, u16 species) {
    int cnt = 0;
    for (int i = 0; wild_pokemon[i].bank != 0xFF; i++) {
        // Check grass habitats
        int map_type = pokdex_map_type_to_habitat_map_type[get_mapheader(wild_pokemon[i].bank, wild_pokemon[i].map)->type];
        if (wild_pokemon[i].grass) {
            int probability = 0;
            for (int j = 0; j < 12; j++) {
                if (wild_pokemon[i].grass->data[j].species == species) {
                    probability += wild_pokemon_grass_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_GRASS, map_type);
        }
        if (wild_pokemon[i].water) {
            int probability = 0;
            for (int j = 0; j < 5; j++) {
                if (wild_pokemon[i].water->data[j].species == species) {
                    probability += wild_pokemon_water_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_WASSER, map_type);
        }
        if (wild_pokemon[i].other) {
            int probability = 0;
            for (int j = 0; j < 5; j++) {
                if (wild_pokemon[i].other->data[j].species == species) {
                    probability += wild_pokemon_other_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_RADAR, map_type);
        }
        if (wild_pokemon[i].rod) {
            int probability = 0;
            for (int j = 0; j < 2; j++) {
                if (wild_pokemon[i].rod->data[j].species == species) {
                    probability += wild_pokemon_rod_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_ROD, map_type);
            probability = 0;
            for (int j = 0; j < 3; j++) {
                if (wild_pokemon[i].rod->data[2 + j].species == species) {
                    probability += wild_pokemon_good_rod_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_GOOD_ROD, map_type);
            probability = 0;
            for (int j = 0; j < 5; j++) {
                if (wild_pokemon[i].rod->data[2 + 3 + j].species == species) {
                    probability += wild_pokemon_super_rod_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_GOOD_ROD, map_type);
        }
    }
    int roamer_idx = species_to_roamer_idx(species);
    if (roamer_idx != -1 && csave.roamers[roamer_idx].is_present) {
        u8 bank = csave.roamer_locations[roamer_idx].bank;
        u8 map_idx = csave.roamer_locations[roamer_idx].map_idx;
        int map_type = pokdex_map_type_to_habitat_map_type[get_mapheader(bank, map_idx)->type];
        pokedex_habitats_add(bank, map_idx, dst, &cnt, 50, HABITAT_TYPE_GRASS, map_type);
        pokedex_habitats_add(bank, map_idx, dst, &cnt, 50, HABITAT_TYPE_WASSER, map_type);
    }
    DEBUG("Number of habitats is %d @%x\n", cnt, dst);
    return cnt;
}

