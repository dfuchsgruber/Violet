#include "types.h"
#include "item/item.h"
#include "pokemon/virtual.h"
#include "language.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "debug.h"

extern u8 str_pokeball_unusable_because_no_space[];

u8 str_pokeball_unusable_cant_aim_at_two[] = LANGDEP(
    PSTRING("Du kannst nicht auf zwei Pokémon\ngleichzeitig zielen!PAUSE_UNTIL_PRESS"),
    PSTRING("You can't aim at two Pokémon at\nthe same time!PAUSE_UNTIL_PRESS")
);

void item_pokeball_battle(u8 self) {
    if (player_party_and_boxes_full()) {
        bag_print_string(self, 2, str_pokeball_unusable_because_no_space, bag_return_from_context_menu);
    } else if ((battle_flags & BATTLE_DOUBLE) && battlers[BATTLE_POSITION_OPPONENT_LEFT].current_hp > 0 && battlers[BATTLE_POSITION_OPPONENT_RIGHT].current_hp > 0) {
        bag_print_string(self, 2, str_pokeball_unusable_cant_aim_at_two, bag_return_from_context_menu);
    } else {
        item_remove(item_activated, 1);
        bag_initialize_close_animation();
        item_menu_fade_and_continue(self);
    }
}