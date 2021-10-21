#include "callbacks.h"
#include "item/bag.h"
#include "item/item.h"
#include "map/header.h"
#include "overworld/effect.h"
#include "overworld/map_control.h"
#include "overworld/pokemon_party_menu.h"
#include "overworld/start_menu.h"
#include "types.h"

static void abra_doll_field_continuation(u8 self) {
    overworld_effect_teleport_after_showing_pokemon();
    item_remove(ITEM_ABRA_PUPPE, 1);
    big_callback_delete(self);
}

void item_field_effect_abra_doll(u8 self) {
    if (map_type_enables_fly_or_teleport(mapheader_virtual.type)) {
        item_use_continuation = abra_doll_field_continuation;
        item_close_bag_and_return_to_overworld(self);
    } else {
        item_print_string_can_not_be_used_by_oak(self, (u8)big_callbacks[self].params[3]);
    }
}
