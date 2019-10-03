#include "types.h"
#include "map/wild_pokemon.h"
#include "overworld/map_control.h"
#include "save.h"
#include "tile/block.h"
#include "debug.h"
#include "prng.h"
#include "dungeon/dungeon2.h"
#include "vars.h"
#include "constants/vars.h"
#include "overworld/script.h"
#include "pokemon/roamer.h"

extern u8 ow_script_trainerschool_wildbattle[];

u16 map_wild_pokemon_get_current_table_id(){
    u16 i = 0;
    while(wild_pokemon[i].bank != 0xFF){
        if(wild_pokemon[i].bank == save1->bank &&
                wild_pokemon[i].map == save1->map)
            return i;
        i++;
    }
    return 0xFFFF;
}

wild_pokemon_data *map_wild_pokemon_get_current() {
  if(dungeon_get_type() && save1->bank == DG2_BANK && save1->map == DG2_MAP) {
    return &(fmem.dwild_pokemon);
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
  // dprintf("Result is %d\n", result);
  return result;
}

int map_wildbattle_init(bdata current, u16 behaviour_previous_tile) {
  if(wild_pokemon_disabled) return 0;
  if (*var_access(TRAINERSCHOOL_PROGRESS) <= 5) return 0; // Can not encounter until >= 6
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
  // Check if a roamer appears
  if (wild_pokemon_spawn_roamer()) {
    dprintf("Roamer to be spawned, allowed by repel %d\n", wildbattle_is_allowed_by_repel(ROAMER_LEVEL));
    if (wildbattle_is_allowed_by_repel(ROAMER_LEVEL)) {
      battle_initialize_roamer();
      return true;
    }
  }

  if(!wildbattle_initialize_by_habitat(habitat, pdf_type, 1)) {
    wildbattle_increase_chance(habitat->frequency);
    return 0;
  }
  if (*var_access(TRAINERSCHOOL_PROGRESS) <= 6) {
	  // Start a wildbattle script instead
	  dprintf("Started script\n");
	  overworld_script_init(ow_script_trainerschool_wildbattle);
  } else {
	  wildbattle_start();
  }
  return 1;
}

bool wildbattle_initialize_by_habitat(wild_pokemon_habitat *habitat, int pdf_type,
		int icognito_letter) {
	int idx = -1;
	switch(pdf_type) {
		case 0: {
			idx = wildbattle_sample_from_pdf(wild_pokemon_grass_pdf, 12);
			break;
		}
		case 1: {
			idx = wildbattle_sample_from_pdf(wild_pokemon_water_pdf, 5);
			break;
		}
		case 2 : {
			idx = wildbattle_sample_from_pdf(wild_pokemon_other_pdf, 5);
			break;
		}
		default : {
			derrf("Unsupported pdf type %d\n", pdf_type);
			break;
		}
	}
	u8 level = wildbattle_sample_level(&(habitat->data[idx]));
	if (wildbattle_is_allowed_by_repel(level)) {
		if (*var_access(STORY_PROGRESS) < 8) {
			return trainerschool_wildbattle_initialize_secondary_starter();
		}

		wildbattle_initialize_pokemon(habitat->data[idx].species, level, icognito_letter);
		return true;
	}
	return false;
}

int wildbattle_sample_from_pdf(u8 *pdf, int size) {
	int p = rnd16() % 100;
	for (int i = 0; i < size; i++) {
		if (p < pdf[i]) return i;
		p -= pdf[i];
	}
	derrf("Pdf @x, size %d does not sum up to 100\n", pdf, size);
	return -1;
}

u8 wild_pokemon_grass_pdf[12] = { 20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1 };

u8 wild_pokemon_water_pdf[5] = { 35, 25, 20, 15, 5};

u8 wild_pokemon_rod_pdf[2] = { 70, 30 };

u8 wild_pokemon_good_rod_pdf[3] = { 60, 20, 20 };

u8 wild_pokemon_super_rod_pdf[5] = { 40, 40, 15, 4, 1 };

u8 wild_pokemon_other_pdf[5] = { 40, 20, 20, 10, 10 };

wild_pokemon_data wild_pokemon[] = {
  {
		.bank = 3, .map = 0,
		.grass = NULL,
		.water = &wild_pokemon_3_0_water,
		.other = NULL,
		.rod = &wild_pokemon_3_0_rod,
	},
	{
		.bank = 3, .map = 1,
		.grass = NULL,
		.water = &wild_pokemon_3_1_water,
		.other = NULL,
		.rod = &wild_pokemon_3_1_rod,
	},
	{
		.bank = 3, .map = 2,
		.grass = NULL,
		.water = &wild_pokemon_3_2_water,
		.other = NULL,
		.rod = &wild_pokemon_3_2_rod,
	},
	{
		.bank = 6, .map = 2,
		.grass = NULL,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 19,
		.grass = &wild_pokemon_3_19_grass,
		.water = NULL,
		.other = &wild_pokemon_3_19_other,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 76,
		.grass = &wild_pokemon_3_76_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 57,
		.grass = &wild_pokemon_3_57_grass,
		.water = &wild_pokemon_3_57_water,
		.other = &wild_pokemon_3_57_other,
		.rod = &wild_pokemon_3_57_rod,
	},
	{
		.bank = 3, .map = 72,
		.grass = NULL,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 41,
		.grass = &wild_pokemon_3_41_grass,
		.water = &wild_pokemon_3_41_water,
		.other = &wild_pokemon_3_41_other,
		.rod = &wild_pokemon_3_41_rod,
	},
	{
		.bank = 3, .map = 70,
		.grass = &wild_pokemon_3_70_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 15, .map = 0,
		.grass = &wild_pokemon_15_0_grass,
		.water = &wild_pokemon_15_0_water,
		.other = &wild_pokemon_15_0_other,
		.rod = &wild_pokemon_15_0_rod,
	},
	{
		.bank = 15, .map = 4,
		.grass = &wild_pokemon_15_4_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 3,
		.grass = NULL,
		.water = &wild_pokemon_3_3_water,
		.other = NULL,
		.rod = &wild_pokemon_3_3_rod,
	},
	{
		.bank = 1, .map = 0,
		.grass = &wild_pokemon_1_0_grass,
		.water = &wild_pokemon_1_0_water,
		.other = &wild_pokemon_1_0_other,
		.rod = &wild_pokemon_1_0_rod,
	},
	{
		.bank = 0, .map = 5,
		.grass = &wild_pokemon_0_5_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 0, .map = 6,
		.grass = &wild_pokemon_0_6_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 0, .map = 7,
		.grass = &wild_pokemon_0_7_grass,
		.water = &wild_pokemon_0_7_water,
		.other = NULL,
		.rod = &wild_pokemon_0_7_rod,
	},
	{
		.bank = 3, .map = 21,
		.grass = &wild_pokemon_3_21_grass,
		.water = NULL,
		.other = &wild_pokemon_3_21_other,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 67,
		.grass = &wild_pokemon_3_67_grass,
		.water = &wild_pokemon_3_67_water,
		.other = NULL,
		.rod = &wild_pokemon_3_67_rod,
	},
	{
		.bank = 3, .map = 74,
		.grass = &wild_pokemon_3_74_grass,
		.water = NULL,
		.other = &wild_pokemon_3_74_other,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 4,
		.grass = NULL,
		.water = &wild_pokemon_3_4_water,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 8, .map = 11,
		.grass = NULL,
		.water = &wild_pokemon_8_11_water,
		.other = NULL,
		.rod = &wild_pokemon_8_11_rod,
	},
	{
		.bank = 1, .map = 59,
		.grass = &wild_pokemon_1_59_grass,
		.water = &wild_pokemon_1_59_water,
		.other = NULL,
		.rod = &wild_pokemon_1_59_rod,
	},
	{
		.bank = 3, .map = 22,
		.grass = &wild_pokemon_3_22_grass,
		.water = &wild_pokemon_3_22_water,
		.other = &wild_pokemon_3_22_other,
		.rod = &wild_pokemon_3_22_rod,
	},
	{
		.bank = 16, .map = 3,
		.grass = &wild_pokemon_16_3_grass,
		.water = NULL,
		.other = NULL,
		.rod = &wild_pokemon_16_3_rod,
	},
	{
		.bank = 3, .map = 23,
		.grass = &wild_pokemon_3_23_grass,
		.water = NULL,
		.other = &wild_pokemon_3_23_other,
		.rod = NULL,
	},
	{
		.bank = 17, .map = 2,
		.grass = &wild_pokemon_route_5_clouds_grass,
		.water = &wild_pokemon_route_5_clouds_water,
		.other = NULL,
		.rod = &wild_pokemon_route_5_clouds_rod,
	},
	{
		.bank = 3, .map = 5,
		.grass = NULL,
		.water = &wild_pokemon_3_5_water,
		.other = NULL,
		.rod = &wild_pokemon_3_5_rod,
	},
	{
		.bank = 3, .map = 24,
		.grass = NULL,
		.water = &wild_pokemon_3_24_water,
		.other = NULL,
		.rod = &wild_pokemon_3_24_rod,
	},
	{
		.bank = 18, .map = 2,
		.grass = &wild_pokemon_18_2_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 18, .map = 3,
		.grass = &wild_pokemon_18_3_grass,
		.water = NULL,
		.other = &wild_pokemon_18_3_other,
		.rod = NULL,
	},
	{
		.bank = 1, .map = 30,
		.grass = &wild_pokemon_1_30_grass,
		.water = NULL,
		.other = &wild_pokemon_1_30_other,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 6,
		.grass = NULL,
		.water = &wild_pokemon_3_6_water,
		.other = NULL,
		.rod = &wild_pokemon_3_6_rod,
	},
	{
		.bank = 0, .map = 12,
		.grass = &wild_pokemon_0_12_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 1, .map = 81,
		.grass = &wild_pokemon_1_81_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 1, .map = 82,
		.grass = &wild_pokemon_1_82_grass,
		.water = NULL,
		.other = &wild_pokemon_1_82_other,
		.rod = NULL,
	},
	{
		.bank = 1, .map = 126,
		.grass = &wild_pokemon_1_126_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 7,
		.grass = &wild_pokemon_3_7_grass,
		.water = NULL,
		.other = &wild_pokemon_3_7_other,
		.rod = NULL,
	},
	{
		.bank = 11, .map = 2,
		.grass = &wild_pokemon_route_2_clouds_grass,
		.water = &wild_pokemon_route_2_clouds_water,
		.other = &wild_pokemon_route_2_clouds_rod,
	},
	{
		.bank = 11, .map = 3,
		.grass = &wild_pokemon_route_2_clouds_grass,
		.water = &wild_pokemon_route_2_clouds_water,
		.other = &wild_pokemon_route_2_clouds_rod,
	},
	{
	    .bank = 3, .map = 8,
	    .grass = &wild_pokemon_3_8_grass,
	    .water = &wild_pokemon_3_8_water,
	    .other = &wild_pokemon_3_8_other,
	    .rod = &wild_pokemon_3_8_rod,
	},
	{
		.bank = 3, .map = 9,
		.water = &wild_pokemon_laubdorf_water, .rod = &wild_pokemon_laubdorf_rod,
		.grass = NULL, .other = NULL
	},
	{
		.bank = 3, .map = 10,
		.water = &wild_pokemon_route_9_water, .rod = &wild_pokemon_route_9_rod,
		.grass = NULL, .other = NULL

	},
	{
		.bank = 13, .map = 0,
		.water = &wild_pokemon_route_9_water, .rod = &wild_pokemon_route_9_rod,
		.grass = NULL, .other = NULL

	},
	{
		.bank = 3, .map = 11,
		.water = &wild_pokemon_route_10_water, .rod = &wild_pokemon_route_10_rod,
		.grass = NULL, .other = NULL

	},
	{
		.bank = 14, .map = 0,
		.water = NULL, .rod = NULL,
		.grass = &wild_pokemon_route_10_clouds_grass, .other = NULL

	},
	{
		.bank = 3, .map = 12,
		.water = &wild_pokemon_route_11_water, .rod = &wild_pokemon_route_11_rod,
		.grass = NULL, .other = NULL

	},
	{
		.bank = 3, .map = 14,
		.grass = &wild_pokemon_forest_cemetery_grass, .other = &wild_pokemon_forest_cemetery_other,
		.water = NULL, .rod = NULL
	},
	{
		.bank = 3, .map = 15,
		.grass = &wild_pokemon_route_12_east_grass, .other = &wild_pokemon_route_12_east_other,
		.water = &wild_pokemon_route_12_east_water, .rod = &wild_pokemon_route_12_east_rod
	},
	{
		.bank = 9, .map = 0,
		.grass = &wild_pokemon_orina_city_clouds_grass,
		.water = &wild_pokemon_orina_city_clouds_water,
		.rod = &wild_pokemon_orina_city_clouds_rod,
	},
	{
		.bank = 18, .map = 0,
		.grass = &wild_pokemon_route_6_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 10, .map = 2,
		.grass = &wild_pokemon_route_6_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 21, .map = 0,
		.grass = &wild_pokemon_route_6_clouds_grass,
	},
	{
		.bank = 5, .map = 1,
		.grass = &wild_pokemon_meriana_city_clouds_grass,
	},
	{
		.bank = 16, .map = 0,
		.grass = &wild_pokemon_route_4_clouds_grass,
	},
	{
		.bank = 8, .map = 1,
		.grass = &wild_pokemon_kaskada_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 22, .map = 0,
		.grass = &wild_pokemon_felsige_oednis_clouds_grass,
	},
	{
		.bank = 7, .map = 0,
		.grass = &wild_pokemon_silvania_clouds_grass,
	},
	{
		.bank = 15, .map = 2,
		.grass = &wild_pokemon_route_3_clouds_grass,
	},
	{
		.bank = 1, .map = 2,
		.grass = &wild_pokemon_silvania_wald_clouds_grass,
	},
	{
		.bank = 23, .map = 0,
		.grass = &wild_pokemon_route_8_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 12, .map = 5,
		.grass = &wild_pokemon_route_8_clouds_grass,
	},
	{
		.bank = 13, .map = 4,
		.grass = &wild_pokemon_route_9_clouds_grass,
	},
	{
		.bank = 13, .map = 5,
		.grass = &wild_pokemon_route_9_clouds_grass,
	},
	{
		.bank = 6, .map = 6,
		.grass = &wild_pokemon_route_9_clouds_grass,
	},
	{
		.bank = 14, .map = 0,
		.grass = &wild_pokemon_route_10_clouds_grass,
	},
	{
		.bank = 24, .map = 0,
		.grass = &wild_pokemon_kaskada_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 25, .map = 0,
		.grass = &wild_pokemon_route_11_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 19, .map = 9,
		.grass = &wild_pokemon_ceometria_clouds_grass,
	},
	{
		.bank = 26, .map = 0,
		.grass = &wild_pokemon_route_12_clouds_grass,
	},
	{
		.bank = 26, .map = 1,
		.grass = &wild_pokemon_route_12_clouds_grass,
	},
	{
	    .bank = 0xFF, .map = 0xFF, .field_2 = 0xFF, .field_3 = 0xFF,
	    .grass = NULL, .water = NULL, .other = NULL, .rod = NULL
	},
};
