#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_forest_cemetery_grass_entries[12] = {
  [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_NEBULAK},
  [WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_PARAGONI},
  [WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_ZWIRRLICHT},
  [WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_SHUPPET},
  [WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_NEBULAK},
  [WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_PARAGONI},
  [WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_TRAGOSSO},
  [WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_TRAGOSSO},
  [WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] =
    {.level_min = 37, .level_max = 39, .species = POKEMON_ALPOLLO},
  [WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] =
    {.level_min = 37, .level_max = 40, .species = POKEMON_TRAGOSSO},
  [WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] =
    {.level_min = 38, .level_max = 40, .species = POKEMON_SHUPPET},
  [WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] =
    {.level_min = 39, .level_max = 42, .species = POKEMON_TROMBORK},
};

wild_pokemon_habitat wild_pokemon_forest_cemetery_grass = {
  .frequency = 30, .data = wild_pokemon_forest_cemetery_grass_entries
};

wild_pokemon_entry wild_pokemon_forest_cemetery_other_entries[5] = {
  [WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_PALIMPALIM},
  [WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] =
    {.level_min = 35, .level_max = 31, .species = POKEMON_TRAUNFUGIL},
  [WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] =
    {.level_min = 35, .level_max = 30, .species = POKEMON_WEBARAK},
  [WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] =
    {.level_min = 35, .level_max = 32, .species = POKEMON_WEBARAK},
  [WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] =
    {.level_min = 38, .level_max = 42, .species = POKEMON_ZWIRRKLOP},
};

wild_pokemon_habitat wild_pokemon_forest_cemetery_other = {
  .frequency = 128, .data = wild_pokemon_forest_cemetery_other_entries
};
