#include "types.h"
#include "map/wild_pokemon.h"
#include "overworld/map_control.h"
#include "save.h"
#include "tile/block.h"
#include "debug.h"
#include "prng.h"
#include "dungeon/dungeon2.h"

u16 map_wild_pokemon_get_current_table_id(){
    u16 i = 0;
    while(wild_pokemon[i].bank != 0xFF){
        if(wild_pokemon[i].bank == (*save1)->bank &&
                wild_pokemon[i].map == (*save1)->map)
            return i;
        i++;
    }
    return 0xFFFF;
}

wild_pokemon_data *map_wild_pokemon_get_current() {
  if(dungeon_get_type()) {
    return &(fmem->dwild_pokemon);
  } else {
    u16 idx = map_wild_pokemon_get_current_table_id();
    if (idx == 0xFFFF) return NULL;
    return &(wild_pokemon[idx]);
  }
}

u8 map_wildbattle_init_seed(u32 triggers_wildbattle) {
  wild_pokemon_data *header = map_wild_pokemon_get_current();
  u8 frequency;
  switch(triggers_wildbattle) {
    case TRIGGERS_WILDBATTLE_GRASS:
      frequency = header->grass->frequency;
      break;
    case TRIGGERS_WILDBATTLE_WATER:
      frequency = header->water->frequency;
      break;
    default:
      return 0xFF;
  }
  if(!frequency) return 0xFF;
  if(frequency >= 80) return 0;
  if(frequency <= 9) return 8;
  u8 result = (u8)(8 - (frequency / 10));
  dprintf("Result is %d\n", result);
  return result;
}

int map_wildbattle_init(bdata current, u16 behaviour_previous_tile) {
  u8 *byte_20386DC = (u8*)0x20386DC;
  if(*byte_20386DC == 1) return 0; // TODO: investigate
  wild_pokemon_data *wild_pokemon_header = map_wild_pokemon_get_current();
  u8 pdf_type;
  u32 triggers_wildbattle = block_get_field(current, BDATA_TRIGGERS_WILDBATTLE);
  wild_pokemon_habitat *habitat = NULL;
  switch(triggers_wildbattle) {
    case TRIGGERS_WILDBATTLE_GRASS: {
      habitat = wild_pokemon_header->grass;
      pdf_type = 0;
      break;
    }
    case TRIGGERS_WILDBATTLE_WATER: {
      if(!overworld_flag_get(8)) return 0;
      habitat = wild_pokemon_header->water;
      pdf_type = 1;
      break;
    }
    default:
      return 0;
  }

  if(!habitat) return 0;
  u32 behaviour = block_get_field(current, BDATA_BEHAVIOUR);
  // With 40% entering a new "patch" does not provide an encounter
  if(behaviour != behaviour_previous_tile && (rnd16() % 100) >= 60) return 0;
  if(!wildbattle_does_pokemon_appear_by_frequency(habitat->frequency, 0)) {
    wildbattle_increase_chance(habitat->frequency);
    return 0;
  }
  if(!wildbattle_initialize_by_habitat(habitat, pdf_type, 1)) {
    wildbattle_increase_chance(habitat->frequency);
    return 0;
  }
  wildbattle_start();
  return 1;
}
