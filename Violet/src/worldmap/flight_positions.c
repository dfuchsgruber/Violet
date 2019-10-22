#include "types.h"
#include "worldmap.h"
#include "constants/map_namespaces.h"

// *DO NOT* change the position of any flight position, as it is associated with a worldmapflag
stru_flight_position flight_positions[NUM_FLIGHT_POSITONS] = {
    // bank, map, x, y, d
    {3, 0, 14, 26, 0}, // Amonia
    {3, 1, 72, 29, 0}, // Meriana City
    {3, 2, 24, 21, 0}, // Aktania
    {3, 3, 20, 13, 0}, // Silvania
    {3, 4, 31, 51, 0}, // Kaskada
    {3, 5, 31, 26, 0}, // Orina City
    {3, 6, 28, 17, 0}, // Inferior
    {3, 13, 0x13, 0x12, 0}, // Ceometria
    {3, 9, 0x12, 0x2b, 0}, // Laubdorf
    {3, 17, 0x1e, 0x15, 0}, // Haweiland
    {3, 10, 24, 39, 0},
    {15, 0, 47, 44, 0},
    {3, 28, 13, 21, 0},
    {3, 12, 14, 6, 0},
    {3, 13, 21, 8, 0},
    {3, 14, 14, 28, 0},
    {3, 15, 18, 21, 0},
    {3, 16, 18, 7, 0},
    {3, 17, 12, 4, 0},
    {3, 18, 11, 12, 0},
    {0xFF, 0xFF, 0, 0, 0}
};

flight_position_association_t flight_position_associations[MAP_NAMESPACE_NONE - MAP_AMONIA] = {
    [MAP_AMONIA - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 1},
    [MAP_MERIANA_CITY - MAP_AMONIA] = {.bank = 3, .map_idx = 1, .flight_position_idx = 2},
    [MAP_AKTANIA - MAP_AMONIA] = {.bank = 3, .map_idx = 2, .flight_position_idx = 3},
    [MAP_SILVANIA - MAP_AMONIA] = {.bank = 3, .map_idx = 3, .flight_position_idx = 4},
    [MAP_KASKADA - MAP_AMONIA] = {.bank = 3, .map_idx = 4, .flight_position_idx = 5},
    [MAP_ORINA_CITY - MAP_AMONIA] = {.bank = 3, .map_idx = 5, .flight_position_idx = 6},
    [MAP_INFERIOR - MAP_AMONIA] = {.bank = 3, .map_idx = 6, .flight_position_idx = 7},
    [MAP_CEOMETRIA - MAP_AMONIA] = {.bank = 3, .map_idx = 7, .flight_position_idx = 8},
    [MAP_LAUBDORF - MAP_AMONIA] = {.bank = 3, .map_idx = 8, .flight_position_idx = 9},
    [MAP_INDIGO_PLATEAU - MAP_AMONIA] = {.bank = 3, .map_idx = 9, .flight_position_idx = 10},
    [MAP_HAWEILAND - MAP_AMONIA] = {.bank = 3, .map_idx = 10, .flight_position_idx = 10},
    [MAP_NAMESPACE_99 - MAP_AMONIA] = {.bank = 3, .map_idx = 22, .flight_position_idx = 12},
    [MAP_NAMESPACE_100 - MAP_AMONIA] = {.bank = 3, .map_idx = 28, .flight_position_idx = 13},
    [MAP_ROUTE_1 - MAP_AMONIA] = {.bank = 3, .map_idx = 19, .flight_position_idx = 0},
    [MAP_ROUTE_3 - MAP_AMONIA] = {.bank = 3, .map_idx = 20, .flight_position_idx = 0},
    [MAP_FELSIGE_OEDNIS - MAP_AMONIA] = {.bank = 3, .map_idx = 21, .flight_position_idx = 0},
    [MAP_ROUTE_4 - MAP_AMONIA] = {.bank = 3, .map_idx = 22, .flight_position_idx = 0},
    [MAP_ROUTE_5 - MAP_AMONIA] = {.bank = 3, .map_idx = 23, .flight_position_idx = 0},
    [MAP_ROUTE_6 - MAP_AMONIA] = {.bank = 3, .map_idx = 24, .flight_position_idx = 0},
    [MAP_ROUTE_7 - MAP_AMONIA] = {.bank = 3, .map_idx = 25, .flight_position_idx = 0},
    [MAP_ROUTE_8 - MAP_AMONIA] = {.bank = 3, .map_idx = 26, .flight_position_idx = 0},
    [MAP_ROUTE_9 - MAP_AMONIA] = {.bank = 3, .map_idx = 27, .flight_position_idx = 0},
    [MAP_ROUTE_10 - MAP_AMONIA] = {.bank = 3, .map_idx = 28, .flight_position_idx = 0},
    [MAP_ROUTE_11 - MAP_AMONIA] = {.bank = 3, .map_idx = 29, .flight_position_idx = 0},
    [MAP_ROUTE_12 - MAP_AMONIA] = {.bank = 3, .map_idx = 30, .flight_position_idx = 0},
    [MAP_ROUTE_13 - MAP_AMONIA] = {.bank = 3, .map_idx = 31, .flight_position_idx = 0},
    [MAP_ROUTE_14 - MAP_AMONIA] = {.bank = 3, .map_idx = 32, .flight_position_idx = 0},
    [MAP_ROUTE_15 - MAP_AMONIA] = {.bank = 3, .map_idx = 33, .flight_position_idx = 0},
    [MAP_ROUTE_16 - MAP_AMONIA] = {.bank = 3, .map_idx = 34, .flight_position_idx = 0},
    [MAP_ROUTE_17 - MAP_AMONIA] = {.bank = 3, .map_idx = 35, .flight_position_idx = 0},
    [MAP_ROUTE_18 - MAP_AMONIA] = {.bank = 3, .map_idx = 36, .flight_position_idx = 0},
    [MAP_ROUTE_19 - MAP_AMONIA] = {.bank = 3, .map_idx = 37, .flight_position_idx = 0},
    [MAP_ROUTE_20 - MAP_AMONIA] = {.bank = 3, .map_idx = 38, .flight_position_idx = 0},
    [MAP_ROUTE_21 - MAP_AMONIA] = {.bank = 3, .map_idx = 39, .flight_position_idx = 0},
    [MAP_ROUTE_2 - MAP_AMONIA] = {.bank = 3, .map_idx = 41, .flight_position_idx = 0},
    [MAP_ROUTE_23 - MAP_AMONIA] = {.bank = 3, .map_idx = 42, .flight_position_idx = 0},
    [MAP_ROUTE_24 - MAP_AMONIA] = {.bank = 3, .map_idx = 43, .flight_position_idx = 0},
    [MAP_ROUTE_25 - MAP_AMONIA] = {.bank = 3, .map_idx = 44, .flight_position_idx = 0},
    [MAP_SILVANIA_WALD - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_WALDFRIEDHOF - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_NAMESPACE_128 - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_ASCHHAIN - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_ANTIKE_RUINE - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_WASSERPFAD - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_SIEGESSTRASSE - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_ROCKET_HQ - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_NAMESPACE_134 - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_KUESTENBERG - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_SAFARI_ZONE - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_POKEMON_LIGA - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_VULCANO - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_SEESCHAUMINSELN - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_POKEMON_TURM - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_AZURIA_HOEHLE - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_KRAFTWERK - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_EILAND_EINS - MAP_AMONIA] = {.bank = 3, .map_idx = 12, .flight_position_idx = 14},
    [MAP_EILAND_ZWEI - MAP_AMONIA] = {.bank = 3, .map_idx = 13, .flight_position_idx = 15},
    [MAP_EILAND_DREI - MAP_AMONIA] = {.bank = 3, .map_idx = 14, .flight_position_idx = 16},
    [MAP_EILAND_VIER - MAP_AMONIA] = {.bank = 3, .map_idx = 15, .flight_position_idx = 17},
    [MAP_EILAND_FUENF - MAP_AMONIA] = {.bank = 3, .map_idx = 16, .flight_position_idx = 18},
    [MAP_EILAND_SIEBEN - MAP_AMONIA] = {.bank = 3, .map_idx = 17, .flight_position_idx = 19},
    [MAP_EILAND_SECHS - MAP_AMONIA] = {.bank = 3, .map_idx = 18, .flight_position_idx = 20},
    [MAP_GLUEHWEG - MAP_AMONIA] = {.bank = 3, .map_idx = 45, .flight_position_idx = 0},
    [MAP_SCHATZGESTADE - MAP_AMONIA] = {.bank = 3, .map_idx = 46, .flight_position_idx = 0},
    [MAP_KAP_KANTE - MAP_AMONIA] = {.bank = 3, .map_idx = 47, .flight_position_idx = 0},
    [MAP_BUNDBRUECKE - MAP_AMONIA] = {.bank = 3, .map_idx = 48, .flight_position_idx = 0},
    [MAP_TRI_EILAND_HAFEN - MAP_AMONIA] = {.bank = 3, .map_idx = 49, .flight_position_idx = 0},
    [MAP_SEVII_EILAND_6 - MAP_AMONIA] = {.bank = 3, .map_idx = 50, .flight_position_idx = 0},
    [MAP_SEVII_EILAND_7 - MAP_AMONIA] = {.bank = 3, .map_idx = 51, .flight_position_idx = 0},
    [MAP_SEVII_EILAND_8 - MAP_AMONIA] = {.bank = 3, .map_idx = 52, .flight_position_idx = 0},
    [MAP_SEVII_EILAND_9 - MAP_AMONIA] = {.bank = 3, .map_idx = 53, .flight_position_idx = 0},
    [MAP_FERIENPARADIES - MAP_AMONIA] = {.bank = 3, .map_idx = 54, .flight_position_idx = 0},
    [MAP_WASSERIRRGARTEN - MAP_AMONIA] = {.bank = 3, .map_idx = 55, .flight_position_idx = 0},
    [MAP_EILAND_5_WEIDE - MAP_AMONIA] = {.bank = 3, .map_idx = 56, .flight_position_idx = 0},
    [MAP_TRAINERSCHULE - MAP_AMONIA] = {.bank = 3, .map_idx = 57, .flight_position_idx = 0},
    [MAP_FERN_EILAND - MAP_AMONIA] = {.bank = 3, .map_idx = 58, .flight_position_idx = 0},
    [MAP_GRUENER_PFAD - MAP_AMONIA] = {.bank = 3, .map_idx = 59, .flight_position_idx = 0},
    [MAP_WASSERWEG - MAP_AMONIA] = {.bank = 3, .map_idx = 60, .flight_position_idx = 0},
    [MAP_RUINENTAL - MAP_AMONIA] = {.bank = 3, .map_idx = 61, .flight_position_idx = 0},
    [MAP_NAMESPACE_167 - MAP_AMONIA] = {.bank = 3, .map_idx = 62, .flight_position_idx = 0},
    [MAP_SCHLUCHTEINGANG - MAP_AMONIA] = {.bank = 3, .map_idx = 63, .flight_position_idx = 0},
    [MAP_7_SCHATZSCHLUCHT - MAP_AMONIA] = {.bank = 3, .map_idx = 64, .flight_position_idx = 0},
    [MAP_TANIBO_RUINEN - MAP_AMONIA] = {.bank = 3, .map_idx = 65, .flight_position_idx = 0},
    [MAP_SEVII_EILAND_22 - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_SEVII_EILAND_23 - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_SEVII_EILAND_24 - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_NABELFELS - MAP_AMONIA] = {.bank = 2, .map_idx = 0, .flight_position_idx = 0},
    [MAP_GLUTBERG - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_BEERENFORST - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_EISKASKADENHOEHLE - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_ROCKET_LAGER - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_TRAINERTURM - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_PUNKTLOCH - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_VERLORENE_HOEHLE - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_MUSTERBUSCHWALD - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_WANDELHOEHLE - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_TANIBO_KAMMER - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_TRI_EILAND_PFAD - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_TANIBO_SCHLUESSEL - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_ENTSTEHUNGSINSEL - MAP_AMONIA] = {.bank = 2, .map_idx = 56, .flight_position_idx = 0},
    [MAP_WUESTENKAMMER - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_PEZWULP_KAMMER - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_DREICKE_KAMMER - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_VIERZISSE_KAMMER - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_FUENIBISKU_KAMMER - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_LILECHS_KAMMER - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_ARC_SCRIM - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
    [MAP_GLUTTHERME - MAP_AMONIA] = {.bank = 3, .map_idx = 0, .flight_position_idx = 0},
};

int map_get_flightposition(u8 bank, u8 map){
    for(int i = 0; flight_positions[i].bank != 0xFF 
            || flight_positions[i].map != 0xFF; i++){
        if(flight_positions[i].bank == bank
                && flight_positions[i].map == map)
            return i + 1;
    }
    return 0;
}

stru_flight_position *flightposition_by_id(int id){
    if(!id) return 0;
    return &flight_positions[id - 1];
}
