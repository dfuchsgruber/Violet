#include "types.h"
#include "pokepad/pokedex/habitat.h"
#include "map/header.h"
#include "map/wild_pokemon.h"
#include "pokemon/roamer.h"
#include "save.h"
#include "constants/map_namespaces.h"
#include "worldmap.h"
#include "debug.h"

void pokedex_habitats_add_position(int x, int y, pokedex_habitat_pair *dst, int *size, int probability, int habitat_type) {
    for (int i = 0; i < *size; i++) {
        if (dst[i].worldmap_x == x && dst[i].worldmap_y == y && dst[i].type == habitat_type) {
            dst[i].probability = (u8)MAX(dst[i].probability, probability);
            return;
        }
    }
    dst[*size].worldmap_x = (u8)x;
    dst[*size].worldmap_y = (u8)y;
    dst[*size].probability = (u8)probability;
    dst[*size].type = (u8)habitat_type;
    (*size)++;
    dprintf("Left marking (%d, %d), type %d, prob %d\n", x, y, habitat_type, probability);
}


void pokedex_habitats_add(u8 bank, u8 map_idx, pokedex_habitat_pair *dst, int *size, int probability, int habitat_type) {
    dprintf("Size of habitats %d\n", *size);
    dprintf("Found species at %d.%d with type %d and probability of %d percent.\n", bank, map_idx, habitat_type, probability);
    u8 shape_idx = worldmap_get_shape_idx(bank, map_idx);
    u8 namespace = get_mapheader(bank, map_idx)->map_namespace;
	worldmap_shape_t *shape = worldmap0_namespace_patterns[namespace - MAP_AMONIA][shape_idx];
    for (int i = 0; i < shape->width; i++) {
        for (int j = 0; j < shape->height; j++) {
            pokedex_habitats_add_position(worldmap0_namespace_position_assoc[namespace - MAP_AMONIA].x + shape->x + i,
                worldmap0_namespace_position_assoc[namespace - MAP_AMONIA].y + shape->y + j, dst, size, probability, habitat_type);
        }
    }
}

int pokedex_get_habitats_of_species(pokedex_habitat_pair *dst, u16 species) {
    int cnt = 0;
    for (int i = 0; wild_pokemon[i].bank != 0xFF; i++) {
        // Check grass habitats
        if (wild_pokemon[i].grass) {
            int probability = 0;
            for (int j = 0; j < 12; j++) {
                if (wild_pokemon[i].grass->data[j].species == species) {
                    probability += wild_pokemon_grass_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_GRASS);
        }
        if (wild_pokemon[i].water) {
            int probability = 0;
            for (int j = 0; j < 5; j++) {
                if (wild_pokemon[i].water->data[j].species == species) {
                    probability += wild_pokemon_water_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_WASSER);
        }
        if (wild_pokemon[i].other) {
            int probability = 0;
            for (int j = 0; j < 5; j++) {
                if (wild_pokemon[i].other->data[j].species == species) {
                    probability += wild_pokemon_other_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_RADAR);
        }
        if (wild_pokemon[i].rod) {
            int probability = 0;
            for (int j = 0; j < 2; j++) {
                if (wild_pokemon[i].rod->data[j].species == species) {
                    probability += wild_pokemon_rod_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_ROD);
            probability = 0;
            for (int j = 0; j < 3; j++) {
                if (wild_pokemon[i].rod->data[2 + j].species == species) {
                    probability += wild_pokemon_good_rod_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_GOOD_ROD);
            probability = 0;
            for (int j = 0; j < 5; j++) {
                if (wild_pokemon[i].rod->data[2 + 3 + j].species == species) {
                    probability += wild_pokemon_super_rod_pdf[j];
                }
            }
            if (probability > 0) pokedex_habitats_add(wild_pokemon[i].bank, wild_pokemon[i].map, dst, &cnt, probability, HABITAT_TYPE_GOOD_ROD);
        }
    }
    int roamer_idx = species_to_roamer_idx(species);
    if (roamer_idx != -1 && cmem.roamers[roamer_idx].is_present) {
        pokedex_habitats_add(cmem.roamer_locations[roamer_idx].bank, cmem.roamer_locations[roamer_idx].map_idx, dst, &cnt, 50, HABITAT_TYPE_GRASS);
        pokedex_habitats_add(cmem.roamer_locations[roamer_idx].bank, cmem.roamer_locations[roamer_idx].map_idx, dst, &cnt, 50, HABITAT_TYPE_WASSER);
    }
    dprintf("Number of habitats is %d @%x\n", cnt, dst);
    return cnt;
}

