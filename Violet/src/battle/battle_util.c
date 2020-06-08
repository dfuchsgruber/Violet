#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "debug.h"
#include "overworld/pokemon_party_menu.h"
#include "battle/attack.h"
#include "constants/attacks.h"

pokemon *battler_load_party_range(u8 battler_idx, u8 *first, u8 *last) {
    if (battle_flags & BATTLE_MULTI) {
        *first = link_trainer_is_at_flank(battler_get_multiplayer_idx(battler_idx)) ? 3 : 0;
        *last = (u8)(*first + 3);
    } else {
        // Regular non-link battle
        if (SIDE(battler_idx) == BATTLE_SIDE_OPPONENT && (battle_flags & BATTLE_TWO_TRAINERS)) {
            *first = battler_get_position(battler_idx) == BATTLE_POSITION_OPPONENT_RIGHT ? 3 : 0;
            *last = (u8)(*first + 3);
        } else if (SIDE(battler_idx) == BATTLE_SIDE_PLAYER && (battle_flags & BATTLE_ALLY)) {
            *first = battler_get_position(battler_idx) == BATTLE_POSITION_PLAYER_RIGHT ? 3 : 0;
            *last = (u8)(*first + 3);
        } else {
            *first = 0;
            *last = 6;
        }
    }
    return SIDE(battler_idx) == BATTLE_SIDE_OPPONENT ? opponent_pokemon : player_pokemon;
}


void battler_get_partner_and_foes(u8 battler, u8 *partner, u8 *foe, u8 *foe_partner) {
    if (battle_flags & BATTLE_DOUBLE) {
        if (partner) *partner = PARTNER(battler);
        if (foe) *foe = OPPONENT(battler);
        if (foe_partner) *foe_partner = PARTNER(*foe);
    } else {
        if (partner) *partner = battler;
        if (foe) *foe = OPPONENT(battler);
        if (foe_partner) *foe_partner = *foe;
    }
}

bool battle_is_tag() {
    return (battle_flags & (BATTLE_ALLY | BATTLE_MULTI)) != 0 && (battle_flags & BATTLE_DOUBLE) != 0;
}

bool battle_has_two_opponents() {
    return (battle_flags & (BATTLE_TWO_TRAINERS | BATTLE_MULTI)) != 0 && (battle_flags & BATTLE_DOUBLE) != 0;
}

extern u16 battler_party_idxs[4];

// In retrospective - this function is suuuuper unneccesary...
u8 battler_idx_to_party_idx(u8 battler_idx) {
    return (u8)battler_party_idxs[battler_idx];
}

bool battler_has_no_switching_targets(u8 battler_idx, u8 party_idx, u8 partner_party_idx) {
    if (!(battle_flags & BATTLE_DOUBLE)) return false;
    u8 first = 0, last = 0;
    pokemon *party = battler_load_party_range(battler_idx, &first, &last);
    if (party_idx == 6)
        party_idx = (u8) battler_idx_to_party_idx(battler_idx);
    if (partner_party_idx == 6)
        partner_party_idx = (u8) battler_idx_to_party_idx(PARTNER(battler_idx));
    dprintf("Battler %d has switching target?\nparty_idx %d, partner_party_idx %d\n", battler_idx, party_idx, partner_party_idx);
    for (int i = first; i < last; i++) {
        if (POKEMON_IS_VIABLE(party + i) && i != party_idx && i != partner_party_idx) {
            dprintf("Party idx %d is viable.\n", i);
            return false;
        }
    }
    dprintf("Battler %d has no swichting targets.\n", battler_idx);
    return true;
}

bool battler_is_alive(u8 battler_idx) {
    if (battlers[battler_idx].current_hp <= 0) 
        return false;
    if (battler_idx >= battler_cnt)
        return false;
    if (battlers_absent & int_bitmasks[battler_idx])
        return false;
    return true;
}

bool battle_active_attack_should_do_animation() {
    if (active_attack == ATTACK_DELEGATOR || active_attack == ATTACK_WANDLER) // Even with no animations, these ones are needed for the game to work
        return true;
    if (active_attack == ATTACK_TELEPORT && BATTLE_IS_WILD_DOUBLE && battler_is_opponent(attacking_battler) && battler_is_alive(PARTNER(attacking_battler)))
        return true; // In a double battle against two wilds, the teleport animation is required if both of them are still alive
    return (bsc_status_flags & 0x80) == 0; // 0x80: Animations inactive
}