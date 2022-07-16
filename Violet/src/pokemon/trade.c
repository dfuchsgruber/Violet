#include "types.h"
#include "pokemon/trade.h"
#include "language.h"
#include "constants/pokemon_types.h"
#include "constants/natures.h"
#include "constants/items.h"

ingame_trade_t ingame_trades[NUM_INGAME_TRADES] = {
    [INGAME_TRADE_CAMAUB] = {
        .nickname = LANGDEP(PSTRING("Carmella"), PSTRING("Carmella")),
        .species = POKEMON_CAMAUB,
        .ivs = {
            [STAT_HP] = 24,
            [STAT_ATTACK] = 16,
            [STAT_DEFENSE] = 25,
            [STAT_SPEED] = 25,
            [STAT_SPECIAL_ATTACK] = 31,
            [STAT_SPECIAL_DEFENSE] = 22,
        },
        .tid = 69420,
        .pid = {
            .fields = {
                .ability = 0,
                .is_female = true,
                .is_shiny = 0,
                .hidden_power_type = TYPE_KAMPF,
                .hidden_power_strength = 6,
                .nature = NATURE_MAESSIG,
            }
        },
        .item = ITEM_SAIMBEERE,
        .ot_name = LANGDEP(PSTRING("Anthony"), PSTRING("Anthony")),
        .ot_is_female = 0,
        .hidden_ability = 1,
        .requested_species = POKEMON_ABRA,
    },
    [INGAME_TRADE_SEEMOPS] = {
        .nickname = LANGDEP(PSTRING("Robin"), PSTRING("Robin")),
        .species = POKEMON_SCHNEPPKE,
        .ivs = {
            [STAT_HP] = 24,
            [STAT_ATTACK] = 16,
            [STAT_DEFENSE] = 25,
            [STAT_SPEED] = 25,
            [STAT_SPECIAL_ATTACK] = 31,
            [STAT_SPECIAL_DEFENSE] = 22,
        },
        .tid = 1234321,
        .pid = {
            .fields = {
                .ability = 0,
                .is_female = false,
                .is_shiny = 0,
                .hidden_power_type = TYPE_ELEKTRO,
                .hidden_power_strength = 7,
                .nature = NATURE_STILL,
            }
        },
        .item = ITEM_SEEGESANG,
        .ot_name = LANGDEP(PSTRING("Franz"), PSTRING("Franz")),
        .ot_is_female = 0,
        .hidden_ability = 1,
        .requested_species = POKEMON_ONIX,
    },
    [INGAME_TRADE_ZWIRRLICHT] = {
        .nickname = LANGDEP(PSTRING("Düstrich"), PSTRING("Dusky")),
        .species = POKEMON_ZWIRRLICHT,
        .ivs = {
            [STAT_HP] = 24,
            [STAT_ATTACK] = 16,
            [STAT_DEFENSE] = 25,
            [STAT_SPEED] = 25,
            [STAT_SPECIAL_ATTACK] = 31,
            [STAT_SPECIAL_DEFENSE] = 22,
        },
        .tid = 666,
        .pid = {
            .fields = {
                .ability = 0,
                .is_female = true,
                .is_shiny = 0,
                .hidden_power_type = TYPE_FEE,
                .hidden_power_strength = 7,
                .nature = NATURE_HART,
            }
        },
        .item = ITEM_DUESTERUMHANG,
        .ot_name = LANGDEP(PSTRING("Simon"), PSTRING("Simon")),
        .ot_is_female = 0,
        .hidden_ability = 1,
        .requested_species = POKEMON_WABLU,
    },
    [INGAME_TRADE_MOLUNK] = {
        .nickname = LANGDEP(PSTRING("Lizzy"), PSTRING("Lizzy")),
        .species = POKEMON_MOLUNK,
        .ivs = {
            [STAT_HP] = 27,
            [STAT_ATTACK] = 21,
            [STAT_DEFENSE] = 30,
            [STAT_SPEED] = 31,
            [STAT_SPECIAL_ATTACK] = 28,
            [STAT_SPECIAL_DEFENSE] = 19,
        },
        .tid = 133737,
        .pid = {
            .fields = {
                .ability = 0,
                .is_female = true,
                .is_shiny = 0,
                .hidden_power_type = TYPE_WASSER,
                .hidden_power_strength = 7,
                .nature = NATURE_MAESSIG,
            }
        },
        .item = ITEM_GIFTJUWEL,
        .ot_name = LANGDEP(PSTRING("Emilia"), PSTRING("Emilia")),
        .ot_is_female = 1,
        .hidden_ability = 1,
        .requested_species = POKEMON_NIDORANM,
    },
    [INGAME_TRADE_MAGNETON] = {
        .nickname = LANGDEP(PSTRING("Magneto"), PSTRING("Magneto")),
        .species = POKEMON_MAGNETON,
        .ivs = {
            [STAT_HP] = 31,
            [STAT_ATTACK] = 7,
            [STAT_DEFENSE] = 28,
            [STAT_SPEED] = 15,
            [STAT_SPECIAL_ATTACK] = 31,
            [STAT_SPECIAL_DEFENSE] = 31,
        },
        .tid = 987653,
        .pid = {
            .fields = {
                .ability = 0,
                .is_female = false,
                .is_shiny = 0,
                .hidden_power_type = TYPE_FEUER,
                .hidden_power_strength = 7,
                .nature = NATURE_KUEHN,
            }
        },
        .item = ITEM_SANANABEERE,
        .ot_name = LANGDEP(PSTRING("Julia"), PSTRING("Julia")),
        .ot_is_female = 1,
        .hidden_ability = 1,
        .requested_species = POKEMON_GEOROK,
    },
};


void ingame_trade_pokemon_new(u8 party_idx, u8 ingame_trade_idx) { 
    ingame_trade_t *trade = ingame_trades + ingame_trade_idx;
    u8 level = (u8)pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_LEVEL, 0);
    pokemon *p = &opponent_pokemon[0];
    pokemon_new(p, trade->species, level, POKEMON_NEW_RANDOM_IVS, true, trade->pid, true, trade->tid);
    for (int i = 0; i < 6; i++)
        pokemon_set_attribute(p, ATTRIBUTE_HP_IV + i, trade->ivs + i);
    pokemon_set_attribute(p, ATTRIBUTE_NICKNAME, trade->nickname);
    pokemon_set_attribute(p, ATTRIBUTE_OT_NAME, trade->ot_name);
    pokemon_set_attribute(p, ATTRIBUTE_OT_GENDER, &trade->ot_is_female);
    if (trade->hidden_ability)
        pokemon_set_hidden_ability(&p->box);
    pokemon_set_attribute(p, ATTRIBUTE_ITEM, &trade->item);
    int met_location = CATCH_LOCATION_INGAME_TRADE;
    pokemon_set_attribute(p, ATTRIBUTE_CATCH_LOCATION, &met_location);
    pokemon_calculate_stats(p);
    if (trade->has_custom_moves) {
        for (int i = 0; i < 4; i++) {
            pokemon_set_attribute(p, ATTRIBUTE_ATTACK1 + i, trade->moves + i);
        }
    }
}