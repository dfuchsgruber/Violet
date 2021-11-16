#include "types.h"
#include "item/item_effect.h"
#include "constants/item_effect_types.h"
#include "language.h"
#include "text.h"
#include "pokemon/names.h"
#include "constants/pokemon_stat_names.h"
#include "debug.h"

static u8 str_item_effect_result_heal_status[] = LANGDEP(
    PSTRING("Die BUFFER_2 von BUFFER_1\nwurde geheilt.PAUSE_UNTIL_PRESS"),
    PSTRING("The BUFFER_2 of BUFFER_1\nwas cured.PAUSE_UNTIL_PRESS"));

static u8 str_item_effect_result_heal_sleep[] = LANGDEP(
    PSTRING("BUFFER_1 ist aufgewacht.PAUSE_UNTIL_PRESS"), PSTRING("BUFFER_2 woke up.PAUSE_UNTIL_PRESS")
);

static u8 str_item_effect_result_full_heal[] = LANGDEP(
    PSTRING("BUFFER_1 erholte sich.PAUSE_UNTIL_PRESS"), PSTRING("BUFFER_2 recovered.PAUSE_UNTIL_PRESS")
);

static u8 str_item_effect_result_ev[] = LANGDEP(
    PSTRING("BUFFER_2 Fleiß-Punkte von\nBUFFER_1 wurden angehoben.PAUSE_UNTIL_PRESS"), PSTRING("BUFFER_1's BUFFER_2\neffort values were raised.PAUSE_UNTIL_PRESS")
);

static u8 str_item_effect_result_increase_pp[] = LANGDEP(
    PSTRING("Ap von BUFFER_1\nwurden angehoben.PAUSE_UNTIL_PRESS"), PSTRING("PP of BUFFER_2\nwere raised.PAUSE_UNTIL_PRESS")
);

static u8 str_item_effect_result_heal_pp[] = LANGDEP(
    PSTRING("Ap wurden aufgefüllt.PAUSE_UNTIL_PRESS"), PSTRING("PP were recovered.PAUSE_UNTIL_PRESS")
);

static u8 str_item_effect_result_none[] = LANGDEP(
    PSTRING("Es wird keine Wirkung haben.PAUSE_UNTIL_PRESS"), PSTRING("It has no effect.PAUSE_UNTIL_PRESS")
);

static u8 str_item_effect_result_friendship[] = LANGDEP(
    PSTRING("BUFFER_1 wurde\nzutraulicher.PAUSE_UNTIL_PRESS"), PSTRING("BUFFER_1 became\nmore friendly.PAUSE_UNTIL_PRESS")
);

static u8 *item_effect_result_strings[] = {
    [ITEM_EFFECT_HEAL_POISON] = str_item_effect_result_heal_status,
    [ITEM_EFFECT_HEAL_CONFUSION] = str_item_effect_result_heal_status,
    [ITEM_EFFECT_HEAL_FREEZE] = str_item_effect_result_heal_status,
    [ITEM_EFFECT_HEAL_INFATUATION] = str_item_effect_result_heal_status,
    [ITEM_EFFECT_HEAL_PARALYSIS] = str_item_effect_result_heal_status,
    [ITEM_EFFECT_HEAL_BURN] = str_item_effect_result_heal_status,
    [ITEM_EFFECT_HEAL_SLEEP] = str_item_effect_result_heal_sleep,
    [ITEM_EFFECT_HEAL_ALL_STATUS] = str_item_effect_result_full_heal,
    [ITEM_EFFECT_EV_HP] = str_item_effect_result_ev,
    [ITEM_EFFECT_EV_ATTACK] = str_item_effect_result_ev,
    [ITEM_EFFECT_EV_DEFENSE] = str_item_effect_result_ev,
    [ITEM_EFFECT_EV_SPEED] = str_item_effect_result_ev,
    [ITEM_EFFECT_EV_SPECIAL_ATTACK] = str_item_effect_result_ev,
    [ITEM_EFFECT_EV_SPECIAL_DEFENSE] = str_item_effect_result_ev,
    [ITEM_EFFECT_PP_UP] = str_item_effect_result_increase_pp,
    [ITEM_EFFECT_PP_MAX] = str_item_effect_result_increase_pp,
    [ITEM_EFFECT_HEAL_PP] = str_item_effect_result_heal_pp,
    [ITEM_EFFECT_NONE] = str_item_effect_result_none,
    [ITEM_EFFECT_FRIENDSHIP] = str_item_effect_result_friendship,
};

void item_effect_print_result(u16 item) {
    u8 item_effect_type = item_get_effect_type(item);
    DEBUG("Item %d has effect type %d\n", item, item_effect_type);
    switch (item_effect_type) {
        case ITEM_EFFECT_HEAL_BURN: {
            u8 s[] = LANGDEP(PSTRING("Verbrennung"), PSTRING("burn"));
            strcpy(buffer1, s);
            break;
        }
        case ITEM_EFFECT_HEAL_CONFUSION: {
            u8 s[] = LANGDEP(PSTRING("Verwirrung"), PSTRING("confusion"));
            strcpy(buffer1, s);
            break;
        }
        case ITEM_EFFECT_HEAL_FREEZE: {
            u8 s[] = LANGDEP(PSTRING("Vereisung"), PSTRING("freezing"));
            strcpy(buffer1, s);
            break;
        }
        case ITEM_EFFECT_HEAL_INFATUATION:  {
            u8 s[] = LANGDEP(PSTRING("Vernarrtheit"), PSTRING("infatuation"));
            strcpy(buffer1, s);
            break;
        }
        case ITEM_EFFECT_HEAL_PARALYSIS:  {
            u8 s[] = LANGDEP(PSTRING("Paralyse"), PSTRING("paralysis"));
            strcpy(buffer1, s);
            break;
        }
        case ITEM_EFFECT_HEAL_POISON: {
            u8 s[] = LANGDEP(PSTRING("Vergiftung"), PSTRING("poisoning"));
            strcpy(buffer1, s);
            break;
        }
        case ITEM_EFFECT_EV_HP:
            strcpy(buffer1, pokemon_stat_names[POKEMON_STAT_NAME_HP]);
            break;
        case ITEM_EFFECT_EV_ATTACK:
            strcpy(buffer1, pokemon_stat_names[POKEMON_STAT_NAME_ATTACK]);
            break;
        case ITEM_EFFECT_EV_DEFENSE:
            strcpy(buffer1, pokemon_stat_names[POKEMON_STAT_NAME_DEFENSE]);
            break;
        case ITEM_EFFECT_EV_SPEED:
            strcpy(buffer1, pokemon_stat_names[POKEMON_STAT_NAME_SPEED]);
            break;
        case ITEM_EFFECT_EV_SPECIAL_ATTACK:
            strcpy(buffer1, pokemon_stat_names[POKEMON_STAT_NAME_SPECIAL_ATTACK]);
            break;
        case ITEM_EFFECT_EV_SPECIAL_DEFENSE:
            strcpy(buffer1, pokemon_stat_names[POKEMON_STAT_NAME_SPECIAL_DEFENSE]);
            break;
    }
    string_decrypt(strbuf, item_effect_result_strings[item_effect_type]);
}