/*
 * item.c
 *
 *  Created on: Aug 20, 2018
 *      Author: dominik
 */

#include "item/item.h"
#include "constants/items.h"
#include "constants/species.h"
#include "debug.h"
#include "dungeon/dungeon2.h"
#include "math.h"
#include "prng.h"
#include "save.h"
#include "types.h"

u16 dungeon_ocean_items_common[] = {
    ITEM_POKEBALL,
    ITEM_SUPERBALL,
    ITEM_TRANK,
    ITEM_SUPERTRANK,
    ITEM_AETHER,
    ITEM_SCHUTZ,
    ITEM_FLUCHTSEIL,
    ITEM_PARA_HEILER,
    ITEM_GEGENGIFT,
    ITEM_SUPERSCHUTZ,
    ITEM_PERLE,
    0xFFFF};

u16 dungeon_ocean_items_rare[] = {
    ITEM_ABYSSPLATTE,
    ITEM_SONDERBONBON,
    ITEM_RIESENPERLE,
    ITEM_AP_PLUS,
    ITEM_ELIXIER,
    ITEM_TOP_SCHUTZ,
    ITEM_ABYSSZAHN,
    0xFFFF};

u16 dungeon_ocean_pick_item(dungeon_generator2 *dg2) {
    u16 *items;
    if (dungeon2_rnd_16(dg2) < 0x3000) {
        // 3/16 chance
        items = dungeon_ocean_items_rare;
    } else {
        items = dungeon_ocean_items_common;
    }
    int size = 0;
    while (items[size] != 0xFFFF)
        size++;
    return items[dungeon2_rnd_16(dg2) % size];
}
