#include "types.h"
#include "worldmap.h"
#include "constants/map_namespaces.h"
#include "constants/flags.h"

const flight_position2_t flight_positions2[] = {
    {.bank = 3, .map_idx = 0, .x = 0xE, .y = 0x10, .flag = WM_AMONIA},
    {.bank = 3, .map_idx = 1, .x = 72, .y = 29, .flag = WM_MERIANA_CITY},
    {.bank = 3, .map_idx = 2, .x = 0x1f, .y = 0x28, .flag = WM_AKTANIA},
    {.bank = 3, .map_idx = 3, .x = 0x1c, .y = 0xA, .flag = WM_SILVANIA},
    {.bank = 3, .map_idx = 4, .x = 0x2f, .y = 0x2e, .flag = WM_KASKADA},
    {.bank = 3, .map_idx = 5, .x = 31, .y = 37, .flag = WM_ORINA_CITY},
    {.bank = 3, .map_idx = 6, .x = 28, .y = 17, .flag = WM_SILVANIA},
    {.bank = 3, .map_idx = 13, .x = 0x13, .y = 0x12, .flag = WM_CEOMETRIA},
    {.bank = 3, .map_idx = 9, .x = 0x13, .y = 0x2b, .flag = WM_LAUBDORF},
    {.bank = 3, .map_idx = 17, .x = 0x1E, .y = 0x15, .flag = WM_HAWEILAND},
    {.bank = 3, .map_idx = 25, .x = 0x8, .y = 0x22, .flag = WM_TANNS_LAB},
    {.bank = 3, .map_idx = 26, .x = 0x15, .y = 0x27, .flag = WM_DESERT_VILLAGE},
    {.bank = 0xFF},
};
