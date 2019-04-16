#include "types.h"
#include "tile/coordinate.h"
#include "constants/map_namespaces.h"
#include "worldmap.h"
#include "map/header.h"
#include "constants/map_types.h"
#include "debug.h"
#include "math.h"
#include "save.h"

u8 worldmap0_position_data [] = {
    //   [0]   [1]   [2]  [3]   [4]   [5]   [6]   [7]   [8]   [9]    [A]  [B]   [C]   [D]   [E]    [F]  [10]  [11]  [12]  [13]  [14]
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x6d, 0x6d, 0x6d, 0x5a, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x6d, ____, ____, 0x6e, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x60, ____, ____, 0x6e, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x6c, ____, ____, 0x6e,

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x7e, ____, ____, 0x87,

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x8a, ____, 0x81, ____, ____, ____, 0x66, 0x5b, 0x67, 0x67, 0x5c,

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x5e, 0x6a, 0x6a, 0x6a, 0x5d, 0x69, 0x7a, ____, ____, ____, 0x68,

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x7a, ____, ____, ____, 0x68,

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x7a, 0x7a, 0x7a, 0x7a, 0x59,

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x6f, ____, ____, ____, 0x65,

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x6f, ____, ____, 0xa2, 0x65,

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 0x58,

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 


        //Upper layer

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 

        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, 


};

// Standard shapes
worldmap_shape_t worldmap_shape_1x1_no_displacement = {0, 0, 1, 1};

worldmap_shape_t worldmap_shape_1x2_no_displacement = {0, 0, 1, 2};

worldmap_shape_t worldmap_shape_2x1_no_displacement = {0, 0, 2, 1};

worldmap_shape_t worldmap_shape_route_2_vertical = {0, 0, 1, 3};

worldmap_shape_t worldmap_shape_route_2_horizontal = {1, 2, 3, 1};

worldmap_shape_t worldmap_shape_route_2_clockmaker = {3, 2, 1, 1};

worldmap_shape_t worldmap_shape_route_9_vertical = {.x = 0, .y = 0, .width = 1, .height = 2};

worldmap_shape_t worldmap_shape_route_9_horizontal = {.x = 1, .y = 0, .width = 2, .height = 1};

worldmap_shape_t worldmap_shape_route_10_vertical = {.x = 0, .y = 0, .width = 1, .height = 3};

worldmap_shape_t *worldmap_pattern_1x1[1] = {
	&worldmap_shape_1x1_no_displacement
};

worldmap_shape_t *worldmap_pattern_route_2[3] = {
	&worldmap_shape_route_2_vertical, &worldmap_shape_route_2_horizontal,
	&worldmap_shape_route_2_clockmaker
};

worldmap_shape_t worldmap_shape_feslige_oednis_east = {1, 0, 1, 1};

worldmap_shape_t *worldmap_pattern_felige_oednis[2] = {
	&worldmap_shape_1x1_no_displacement, &worldmap_shape_feslige_oednis_east
};

worldmap_shape_t worldmap_shape_route_6_east = {2, 0, 1, 1};

worldmap_shape_t *worldmap_pattern_route_6[2] = {
	&worldmap_shape_2x1_no_displacement, &worldmap_shape_route_6_east
};

worldmap_shape_t *worldmap_pattern_route_1[1] = {
	&worldmap_shape_1x2_no_displacement
};

worldmap_shape_t *worldmap_pattern_route_9[2] = {
	&worldmap_shape_route_9_vertical, &worldmap_shape_route_9_horizontal
};

worldmap_shape_t *worldmap_pattern_route_10[1] = {
	&worldmap_shape_route_10_vertical
};

worldmap_shape_t *worldmap_pattern_route_11[1] = {
	&worldmap_shape_1x2_no_displacement
};

worldmap_shape_t **worldmap0_namespace_patterns[] = {
	worldmap_pattern_1x1, // MAP_AMONIA
	worldmap_pattern_1x1, // MAP_MERIANA_CITY
	worldmap_pattern_1x1, // MAP_AKTANIA
	worldmap_pattern_1x1, // MAP_SILVANIA
	worldmap_pattern_1x1, // MAP_KASKADA
	worldmap_pattern_1x1, // MAP_ORINA_CITY
	worldmap_pattern_1x1, // MAP_INFERIOR
	worldmap_pattern_1x1, // MAP_CEOMETRIA
	worldmap_pattern_1x1, // MAP_LAUBDORF
	worldmap_pattern_1x1, // MAP_INDIGO_PLATEAU
	worldmap_pattern_1x1, // MAP_SAFFRONIA_CITY
	worldmap_pattern_1x1, // MAP_NAMESPACE_99
	worldmap_pattern_1x1, // MAP_NAMESPACE_100
	worldmap_pattern_route_1, // MAP_ROUTE_1
	worldmap_pattern_1x1, // MAP_ROUTE_3
	worldmap_pattern_felige_oednis, // MAP_FELSIGE_OEDNIS
	worldmap_pattern_route_1, // MAP_ROUTE_4
	worldmap_pattern_1x1, // MAP_ROUTE_5
	worldmap_pattern_route_6, // MAP_ROUTE_6
	worldmap_pattern_1x1, // MAP_ROUTE_7
	worldmap_pattern_1x1, // MAP_ROUTE_8
	worldmap_pattern_route_9, // MAP_ROUTE_9
	worldmap_pattern_route_10, // MAP_ROUTE_10
	worldmap_pattern_route_11, // MAP_ROUTE_11
	worldmap_pattern_1x1, // MAP_ROUTE_12
	worldmap_pattern_1x1, // MAP_ROUTE_13
	worldmap_pattern_1x1, // MAP_ROUTE_14
	worldmap_pattern_1x1, // MAP_ROUTE_15
	worldmap_pattern_1x1, // MAP_ROUTE_16
	worldmap_pattern_1x1, // MAP_ROUTE_17
	worldmap_pattern_1x1, // MAP_ROUTE_18
	worldmap_pattern_1x1, // MAP_ROUTE_19
	worldmap_pattern_1x1, // MAP_ROUTE_20
	worldmap_pattern_1x1, // MAP_ROUTE_21
	worldmap_pattern_route_2, // MAP_ROUTE_2
	worldmap_pattern_1x1, // MAP_ROUTE_23
	worldmap_pattern_1x1, // MAP_ROUTE_24
	worldmap_pattern_1x1, // MAP_ROUTE_25
	worldmap_pattern_1x1, // MAP_SILVANIA_WALD
	worldmap_pattern_1x1, // MAP_PKMN_FRIEDHOF
	worldmap_pattern_1x1, // MAP_NAMESPACE_128
	worldmap_pattern_1x1, // MAP_ASCHHAIN
	worldmap_pattern_1x1, // MAP_TUNNELPFAD
	worldmap_pattern_1x1, // MAP_WASSERPFAD
	worldmap_pattern_1x1, // MAP_SIEGESSTRASSE
	worldmap_pattern_1x1, // MAP_ROCKET_HQ
	worldmap_pattern_1x1, // MAP_NAMESPACE_134
	worldmap_pattern_1x1, // MAP_KUESTENBERG
	worldmap_pattern_1x1, // MAP_SAFARI_ZONE
	worldmap_pattern_1x1, // MAP_POKEMON_LIGA
	worldmap_pattern_1x1, // MAP_VULCANO
	worldmap_pattern_1x1, // MAP_SEESCHAUMINSELN
	worldmap_pattern_1x1, // MAP_POKEMON_TURM
	worldmap_pattern_1x1, // MAP_AZURIA_HOEHLE
	worldmap_pattern_1x1, // MAP_KRAFTWERK
	worldmap_pattern_1x1, // MAP_EILAND_EINS
	worldmap_pattern_1x1, // MAP_EILAND_ZWEI
	worldmap_pattern_1x1, // MAP_EILAND_DREI
	worldmap_pattern_1x1, // MAP_EILAND_VIER
	worldmap_pattern_1x1, // MAP_EILAND_FUENF
	worldmap_pattern_1x1, // MAP_EILAND_SIEBEN
	worldmap_pattern_1x1, // MAP_EILAND_SECHS
	worldmap_pattern_1x1, // MAP_GLUEHWEG
	worldmap_pattern_1x1, // MAP_SCHATZGESTADE
	worldmap_pattern_1x1, // MAP_KAP_KANTE
	worldmap_pattern_1x1, // MAP_BUNDBRUECKE
	worldmap_pattern_1x1, // MAP_TRI_EILAND_HAFEN
	worldmap_pattern_1x1, // MAP_SEVII_EILAND_6
	worldmap_pattern_1x1, // MAP_SEVII_EILAND_7
	worldmap_pattern_1x1, // MAP_SEVII_EILAND_8
	worldmap_pattern_1x1, // MAP_SEVII_EILAND_9
	worldmap_pattern_1x1, // MAP_FERIENPARADIES
	worldmap_pattern_1x1, // MAP_WASSERIRRGARTEN
	worldmap_pattern_1x1, // MAP_EILAND_5_WEIDE
	worldmap_pattern_1x1, // MAP_TRAINERSCHULE
	worldmap_pattern_1x1, // MAP_FERN_EILAND
	worldmap_pattern_1x1, // MAP_GRUENER_PFAD
	worldmap_pattern_1x1, // MAP_WASSERWEG
	worldmap_pattern_1x1, // MAP_RUINENTAL
	worldmap_pattern_1x1, // MAP_NAMESPACE_167
	worldmap_pattern_1x1, // MAP_SCHLUCHTEINGANG
	worldmap_pattern_1x1, // MAP_7_SCHATZSCHLUCHT
	worldmap_pattern_1x1, // MAP_TANIBO_RUINEN
	worldmap_pattern_1x1, // MAP_SEVII_EILAND_22
	worldmap_pattern_1x1, // MAP_SEVII_EILAND_23
	worldmap_pattern_1x1, // MAP_SEVII_EILAND_24
	worldmap_pattern_1x1, // MAP_NABELFELS
	worldmap_pattern_1x1, // MAP_GLUTBERG
	worldmap_pattern_1x1, // MAP_BEERENFORST
	worldmap_pattern_1x1, // MAP_EISKASKADENHOEHLE
	worldmap_pattern_1x1, // MAP_ROCKET_LAGER
	worldmap_pattern_1x1, // MAP_TRAINERTURM
	worldmap_pattern_1x1, // MAP_PUNKTLOCH
	worldmap_pattern_1x1, // MAP_VERLORENE_HOEHLE
	worldmap_pattern_1x1, // MAP_MUSTERBUSCHWALD
	worldmap_pattern_1x1, // MAP_WANDELHOEHLE
	worldmap_pattern_1x1, // MAP_TANIBO_KAMMER
	worldmap_pattern_1x1, // MAP_TRI_EILAND_PFAD
	worldmap_pattern_1x1, // MAP_TANIBO_SCHLUESSEL
	worldmap_pattern_1x1, // MAP_ENTSTEHUNGSINSEL
	worldmap_pattern_1x1, // MAP_WUESTENKAMMER
	worldmap_pattern_1x1, // MAP_PEZWULP_KAMMER
	worldmap_pattern_1x1, // MAP_DREICKE_KAMMER
	worldmap_pattern_1x1, // MAP_VIERZISSE_KAMMER
	worldmap_pattern_1x1, // MAP_FUENIBISKU_KAMMER
	worldmap_pattern_1x1, // MAP_LILECHS_KAMMER
	worldmap_pattern_1x1, // MAP_ARC_SCRIM
	worldmap_pattern_1x1, // MAP_GLUTTHERME
	worldmap_pattern_1x1, // MAP_PRISMANIA_EINK
};

coordinate_t worldmap0_namespace_position_assoc[] = {
	{0x15, 0xb}, // MAP_AMONIA
	{0x15, 0x8}, // MAP_MERIANA_CITY
	{0x15, 0x0}, // MAP_AKTANIA
	{0x12, 0x5}, // MAP_SILVANIA
	{0x15, 0x5}, // MAP_KASKADA
	{0xF, 0x6}, // MAP_ORINA_CITY
	{0xB, 0x6}, // MAP_INFERIOR
	{0x0, 0x0}, // MAP_CEOMETRIA
	{0x12, 0x2}, // MAP_LAUBDORF
	{0x0, 0x0}, // MAP_INDIGO_PLATEAU
	{0x0, 0x0}, // MAP_SAFFRONIA_CITY
	{0x0, 0x0}, // MAP_NAMESPACE_99
	{0x0, 0x0}, // MAP_NAMESPACE_100
	{0x15, 0x9}, // MAP_ROUTE_1
	{0x11, 0x5}, // MAP_ROUTE_3
	{0x13, 0x5}, // MAP_FELSIGE_OEDNIS
	{0x15, 0x6}, // MAP_ROUTE_4
	{0x10, 0x6}, // MAP_ROUTE_5
	{0xC, 0x6}, // MAP_ROUTE_6
	{0x0, 0x0}, // MAP_ROUTE_7
	{0x12, 0x3}, // MAP_ROUTE_8
	{0x12, 0x0}, // MAP_ROUTE_9
	{0x15, 0x1}, // MAP_ROUTE_10
	{0x11, 0xA}, // MAP_ROUTE_11
	{0x0, 0x0}, // MAP_ROUTE_12
	{0x0, 0x0}, // MAP_ROUTE_13
	{0x0, 0x0}, // MAP_ROUTE_14
	{0x0, 0x0}, // MAP_ROUTE_15
	{0x0, 0x0}, // MAP_ROUTE_16
	{0x0, 0x0}, // MAP_ROUTE_17
	{0x0, 0x0}, // MAP_ROUTE_18
	{0x0, 0x0}, // MAP_ROUTE_19
	{0x0, 0x0}, // MAP_ROUTE_20
	{0x0, 0x0}, // MAP_ROUTE_21
	{0x11, 0x6}, // MAP_ROUTE_2
	{0x0, 0x0}, // MAP_ROUTE_23
	{0x0, 0x0}, // MAP_ROUTE_24
	{0x0, 0x0}, // MAP_ROUTE_25
	{0x12, 0x4}, // MAP_SILVANIA_WALD
	{0x0, 0x0}, // MAP_PKMN_FRIEDHOF
	{0x0, 0x0}, // MAP_NAMESPACE_128
	{0xD, 0x5}, // MAP_ASCHHAIN
	{0x0, 0x0}, // MAP_TUNNELPFAD
	{0x0, 0x0}, // MAP_WASSERPFAD
	{0x0, 0x0}, // MAP_SIEGESSTRASSE
	{0x0, 0x0}, // MAP_ROCKET_HQ
	{0x0, 0x0}, // MAP_NAMESPACE_134
	{0x15, 0x4}, // MAP_KUESTENBERG
	{0x0, 0x0}, // MAP_SAFARI_ZONE
	{0x0, 0x0}, // MAP_POKEMON_LIGA
	{0x0, 0x0}, // MAP_VULCANO
	{0x0, 0x0}, // MAP_SEESCHAUMINSELN
	{0x0, 0x0}, // MAP_POKEMON_TURM
	{0x0, 0x0}, // MAP_AZURIA_HOEHLE
	{0x0, 0x0}, // MAP_KRAFTWERK
	{0x0, 0x0}, // MAP_EILAND_EINS
	{0x0, 0x0}, // MAP_EILAND_ZWEI
	{0x0, 0x0}, // MAP_EILAND_DREI
	{0x0, 0x0}, // MAP_EILAND_VIER
	{0x0, 0x0}, // MAP_EILAND_FUENF
	{0x0, 0x0}, // MAP_EILAND_SIEBEN
	{0x0, 0x0}, // MAP_EILAND_SECHS
	{0x0, 0x0}, // MAP_GLUEHWEG
	{0x0, 0x0}, // MAP_SCHATZGESTADE
	{0x0, 0x0}, // MAP_KAP_KANTE
	{0xd, 0xc}, // MAP_BUNDBRUECKE
	{0x0, 0x0}, // MAP_TRI_EILAND_HAFEN
	{0x0, 0x0}, // MAP_SEVII_EILAND_6
	{0x0, 0x0}, // MAP_SEVII_EILAND_7
	{0x0, 0x0}, // MAP_SEVII_EILAND_8
	{0x0, 0x0}, // MAP_SEVII_EILAND_9
	{0x0, 0x0}, // MAP_FERIENPARADIES
	{0x0, 0x0}, // MAP_WASSERIRRGARTEN
	{0x0, 0x0}, // MAP_EILAND_5_WEIDE
	{0x14, 0xA}, // MAP_TRAINERSCHULE
	{0x0, 0x0}, // MAP_FERN_EILAND
	{0x0, 0x0}, // MAP_GRUENER_PFAD
	{0x0, 0x0}, // MAP_WASSERWEG
	{0x0, 0x0}, // MAP_RUINENTAL
	{0x0, 0x0}, // MAP_NAMESPACE_167
	{0x0, 0x0}, // MAP_SCHLUCHTEINGANG
	{0x0, 0x0}, // MAP_7_SCHATZSCHLUCHT
	{0x0, 0x0}, // MAP_TANIBO_RUINEN
	{0x0, 0x0}, // MAP_SEVII_EILAND_22
	{0x0, 0x0}, // MAP_SEVII_EILAND_23
	{0x0, 0x0}, // MAP_SEVII_EILAND_24
	{0x0, 0x0}, // MAP_NABELFELS
	{0x0, 0x0}, // MAP_GLUTBERG
	{0x0, 0x0}, // MAP_BEERENFORST
	{0x0, 0x0}, // MAP_EISKASKADENHOEHLE
	{0x0, 0x0}, // MAP_ROCKET_LAGER
	{0x0, 0x0}, // MAP_TRAINERTURM
	{0x0, 0x0}, // MAP_PUNKTLOCH
	{0x0, 0x0}, // MAP_VERLORENE_HOEHLE
	{0x0, 0x0}, // MAP_MUSTERBUSCHWALD
	{0x0, 0x0}, // MAP_WANDELHOEHLE
	{0x0, 0x0}, // MAP_TANIBO_KAMMER
	{0x0, 0x0}, // MAP_TRI_EILAND_PFAD
	{0x0, 0x0}, // MAP_TANIBO_SCHLUESSEL
	{0x0, 0x0}, // MAP_ENTSTEHUNGSINSEL
	{0x0, 0x0}, // MAP_WUESTENKAMMER
	{0x0, 0x0}, // MAP_PEZWULP_KAMMER
	{0x0, 0x0}, // MAP_DREICKE_KAMMER
	{0x0, 0x0}, // MAP_VIERZISSE_KAMMER
	{0x0, 0x0}, // MAP_FUENIBISKU_KAMMER
	{0x0, 0x0}, // MAP_LILECHS_KAMMER
	{0x0, 0x0}, // MAP_ARC_SCRIM
	{0x0, 0x0}, // MAP_GLUTTHERME
	{0x0, 0x0}, // MAP_PRISMANIA_EINK
};

#define MAP_TYPE_STD 0x0
#define MAP_TYPE_VILLAGE 0x1
#define MAP_TYPE_CITY 0x2
#define MAP_TYPE_ROUTE 0x3
#define MAP_TYPE_BASEMENT 0x4
#define MAP_TYPE_UNDERWATER 0x5
#define MAP_TYPE_TYPE_06 0x6
#define MAP_TYPE_TYPE_07 0x7
#define MAP_TYPE_INSIDE 0x8
#define MAP_TYPE_SECRET_BASE 0x9

 worldmap_shape_association_t worldmap_shape_associations[NUM_WORLDMAP_SHAPE_ASSOCIATIONS] = {
	 {.bank = 3, .map_idx = 21, .shape_idx = 1},
	 {.bank = 3, .map_idx = 24, .shape_idx = 1},
	 {.bank = 3, .map_idx = 7, .shape_idx = 1},
	 {.bank = 11, .map_idx = 1, .shape_idx = 1},
	 {.bank = 13, .map_idx = 0, .shape_idx = 1}
 };


u8 worldmap_get_shape_idx(u8 bank, u8 map_idx) {
	for (int i = 0; i < NUM_WORLDMAP_SHAPE_ASSOCIATIONS; i++) {
		if (worldmap_shape_associations[i].bank == bank && worldmap_shape_associations[i].map_idx == map_idx) {
			return worldmap_shape_associations[i].shape_idx;
		}
	}
	return 0;
}

void worldmap_locate_player() {
	u8 bank = save1->bank;
	u8 map = save1->map;
	s16 x, y;
	switch (get_mapheader(bank, map)->type) {
	case MAP_TYPE_STD:
	case MAP_TYPE_VILLAGE:
	case MAP_TYPE_CITY:
	case MAP_TYPE_ROUTE:
	case MAP_TYPE_TYPE_06:
		// x, y from save
		x = save1->x_cam_orig;
		y = save1->y_cam_orig;
		worldmap_state->player_namespace = mapheader_virtual.map_namespace;
		break;
	case MAP_TYPE_BASEMENT:
	case MAP_TYPE_TYPE_07:
	case MAP_TYPE_INSIDE:
	case MAP_TYPE_UNDERWATER:
		// Load everything from last outdoor map
		bank = save1->last_outdoor_map.bank;
		map = save1->last_outdoor_map.map;
		x = save1->last_outdoor_map.x;
		y = save1->last_outdoor_map.y;
		worldmap_state->player_namespace = get_mapheader(bank, map)->map_namespace;
		break;
	case MAP_TYPE_SECRET_BASE:
		// Load everything from last_map
		bank = save1->last_map.bank;
		map = save1->last_map.map;
		x = save1->last_map.x;
		y = save1->last_map.y;
		worldmap_state->player_namespace = get_mapheader(bank, map)->map_namespace;
		break;
	default:
		derrf("Unkown map type %d\n", get_mapheader(bank, map)->type);
		return;
	}
	map_header_t *header = get_mapheader(bank, map);
	dprintf("Locating player on %d.%d at coordinates %d, %d\n", bank, map, x, y);
	int map_width = (int)header->footer->width;
	int map_height = (int)header->footer->height;
	// Find the shape in the pattern of namespace
	u8 shape_idx = worldmap_get_shape_idx(bank, map);
	worldmap_shape_t *shape = worldmap0_namespace_patterns[worldmap_state->player_namespace - 0x58]
										 [shape_idx];

	int segment_width = MAX(1, map_width / shape->width);
	int segment_height = MAX(1, map_height / shape->height);
	int segment_x = x / segment_width;
	int segment_y = y / segment_height;
	dprintf("Map width %d, height %d\n", map_width, map_height);
	dprintf("Segment width %d, height %d\n", segment_width, segment_height);
	dprintf("Segment x %d, y %d\n", segment_x, segment_y);
	worldmap_state->cursor_x = (u16)(
			worldmap0_namespace_position_assoc[worldmap_state->player_namespace - 0x58].x +
			segment_x + shape->x);
	worldmap_state->cursor_y = (u16)(
			worldmap0_namespace_position_assoc[worldmap_state->player_namespace - 0x58].y +
			segment_y + shape->y);
}
