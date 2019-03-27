/*
 * flag.c
 *
 *  Created on: 22.03.2019
 *      Author: dominik
 */

#include "types.h"
#include "constants/map_namespaces.h"
#include "worldmap.h"
#include "flags.h"
#include "constants/flags.h"

u8 worldmap_lower_layer_check(u8 namespace) {
	u16 flag;
	switch (namespace) {
	case MAP_AMONIA:
		flag = WM_AMONIA; break;
	case MAP_MERIANA_CITY:
		flag = WM_MERIANA_CITY; break;
	case MAP_AKTANIA:
		flag = WM_AKTANIA; break;
	case MAP_SILVANIA:
		flag = WM_SILVANIA; break;
	case MAP_KASKADA:
		flag = WM_KASKADA; break;
	case MAP_ORINA_CITY:
		flag = WM_ORINA_CITY; break;
	case MAP_INFERIOR:
		flag = WM_INFERIOR; break;
	case MAP_LAUBDORF:
		flag = WM_LAUBDORF; break;
	case 0xC5:
		return WORLDMAP_FLAG_CHECK_INVALID;
	default: return WORLDMAP_FLAG_CHECK_NO_FLAG;
	}
	if (checkflag(flag)) {
		return WORLDMAP_FLAG_CHECK_SET;
	} else {
		return WORLDMAP_FLAG_CHECK_UNSET;
	}
}

u8 worldmap_upper_layer_check(u8 namespace) {
	u16 flag;
	switch (namespace) {
		case MAP_SILVANIA_WALD:
			flag = WM_SILVANIA_FOREST; break;
		case MAP_ASCHHAIN:
			flag = WM_ASCHHAIN; break;
		case MAP_KUESTENBERG:
			flag = WM_KUSTENBERG; break;
	case 0xC5:
		return WORLDMAP_FLAG_CHECK_INVALID;
	default: return WORLDMAP_FLAG_CHECK_NO_FLAG;
	}
	if (checkflag(flag)) {
		return WORLDMAP_FLAG_CHECK_SET;
	} else {
		return WORLDMAP_FLAG_CHECK_UNSET;
	}
}
