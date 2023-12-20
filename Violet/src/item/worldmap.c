#include "types.h"
#include "item/item.h"
#include "callbacks.h"
#include "overworld/pokemon_party_menu.h"
#include "overworld/map_control.h"
#include "overworld/npc.h"
#include "tile/coordinate.h"
#include "berry.h"
#include "constants/person_script_stds.h"
#include "map/event.h"
#include "map/header.h"
#include "save.h"
#include "debug.h"
#include "vars.h"
#include "language.h"
#include "overworld/script.h"
#include "item/bag.h"
#include "fading.h"
#include "worldmap.h"

static void town_map_from_overworld(u8 self) {
    if (!fading_control.active) {
        overworld_free();
        overworld_callback2_set_to_use_item();
        worldmap_ui_info_new(map_reload);
        big_callback_delete(self);
    }
}

static void town_map_from_bag() {
    worldmap_ui_info_new(bag_initialize_from_start_menu);
}

void item_effect_town_map(u8 self) {
    bool from_overworld = (bool)big_callbacks[self].params[3];
    if (from_overworld) {
        overworld_pokemon_league_stop_lighting_effect();
        fadescreen_all(FADE_TO_BLACK, 0);
        big_callbacks[self].function = town_map_from_overworld;
    } else {
        bag_set_continuation(town_map_from_bag);
        bag_fade_out_and_continuation(self);
    }
}