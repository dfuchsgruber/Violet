#include "types.h"
#include "item/item_effect.h"
#include "constants/pokemon_stat_names.h"
#include "constants/items.h"

item_effect_t item_effect_potion = {.heal_hp = true, .hp = 20};

item_effect_t item_effect_berry_juice = {.heal_hp = true, .hp = 75};

item_effect_t item_effect_antidote = {.heal_poison = true};

item_effect_t item_effect_burn_heal = {.heal_burn = true};

item_effect_t item_effect_ice_heal = {.heal_freeze = true};

item_effect_t item_effect_awakening = {.heal_sleep = true};

item_effect_t item_effect_paralyze_heal = {.heal_paralysis = true};

item_effect_t item_effect_full_restore = {
    .heal_poison = true, .heal_burn = true, .heal_freeze = true, .heal_sleep = true,
    .heal_paralysis = true, .heal_confusion = true, .heal_infatuation = true,
    .heal_hp = true, .hp = ITEM_EFFECT_HEAL_HP_ALL,
};

item_effect_t item_effect_max_potion = {.heal_hp = true, .hp = ITEM_EFFECT_HEAL_HP_ALL};

item_effect_t item_effect_hyper_potion = {.heal_hp = true, .hp = 200};

item_effect_t item_effect_super_potion = {.heal_hp = true, .hp = 50};

item_effect_t item_effect_full_heal = {
    .heal_poison = true, .heal_burn = true, .heal_freeze = true, .heal_sleep = true,
    .heal_paralysis = true, .heal_confusion = true, .heal_infatuation = true,
};

item_effect_t item_effect_revive = {.revives = true, .heal_hp = true, .hp = ITEM_EFFECT_HEAL_HP_HALF};

item_effect_t item_effect_max_revive = {.revives = true, .heal_hp = true, .hp = ITEM_EFFECT_HEAL_HP_ALL};

item_effect_t item_effect_fresh_water = {.heal_hp = true, .hp = ITEM_EFFECT_HEAL_HP_HALF};

item_effect_t item_effect_soda_pop = {.heal_pp = true, .heal_pp_one_move = true, .pp = 5};

item_effect_t item_effect_lemonade = {.heal_hp = true, .hp = 225};

item_effect_t item_effect_moomoo_milk = {.heal_hp = true, .hp = 100};

item_effect_t item_effect_energy_powder = {
    .heal_hp = true, .hp = 50, .increase_friendship_low = true, .friendship_low = -5,
    .increase_friendship_mid = true, .friendship_mid = -5, .increase_friendship_high = true,
    .friendship_high = -10, 
};

item_effect_t item_effect_energy_root = {
    .heal_hp = true, .hp = 200, .increase_friendship_low = true, .friendship_low = -10,
    .increase_friendship_mid = true, .friendship_mid = -10, .increase_friendship_high = true,
    .friendship_high = -15, 
};

item_effect_t item_effect_heal_powder = {
    .heal_poison = true, .heal_burn = true, .heal_freeze = true, .heal_sleep = true,
    .heal_paralysis = true, .heal_confusion = true, .heal_infatuation = true,
    .increase_friendship_low = true, .friendship_low = -5,
    .increase_friendship_mid = true, .friendship_mid = -5, .increase_friendship_high = true,
    .friendship_high = -10, 
};

item_effect_t item_effect_revival_herb = {
    .heal_hp = true, .revives = true, .hp = ITEM_EFFECT_HEAL_HP_ALL,
    .increase_friendship_low = true, .friendship_low = -15,
    .increase_friendship_mid = true, .friendship_mid = -15, .increase_friendship_high = true,
    .friendship_high = -20, 
};

item_effect_t item_effect_ether = {
    .heal_pp = true, .heal_pp_one_move = true, .pp = 10
};

item_effect_t item_effect_max_ether = {
    .heal_pp = true, .heal_pp_one_move = true, .pp = ITEM_EFFECT_PP_ALL
};

item_effect_t item_effect_elixir = {
    .heal_pp = true, .heal_pp_one_move = false, .pp = 10
};

item_effect_t item_effect_max_elixir = {
    .heal_pp = true, .heal_pp_one_move = false, .pp = ITEM_EFFECT_PP_ALL
};

item_effect_t item_effect_yellow_flute = {.heal_confusion = true};

item_effect_t item_effect_red_flute = {.heal_infatuation = true};

item_effect_t item_effect_sacred_ash = {.sacred_ash = true, .heal_hp = true, .revives = true, .hp = ITEM_EFFECT_HEAL_HP_ALL};

item_effect_t item_effect_hp_up = {
    .increase_ev_hp = true, .evs = {[STAT_HP] = 12}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
};

item_effect_t item_effect_protein = {
    .increase_ev_attack = true, .evs = {[STAT_ATTACK] = 12}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
};

item_effect_t item_effect_iron = {
    .increase_ev_defense = true, .evs = {[STAT_DEFENSE] = 12}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
};

item_effect_t item_effect_calcium = {
    .increase_ev_special_attack = true, .evs = {[STAT_SPECIAL_ATTACK] = 12}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
};

item_effect_t item_effect_carbos = {
    .increase_ev_speed = true, .evs = {[STAT_SPEED] = 12}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
};

item_effect_t item_effect_rare_candy = {
    .increase_level = true, .revives = true, .heal_hp = true,
    .hp = ITEM_EFFECT_HEAL_HP_DYANMIC, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
    .level = 1,
};

item_effect_t item_effect_pp_up = {
    .pp_up = true, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
};

item_effect_t item_effect_zinc = {
    .increase_ev_special_defense = true, .evs = {[STAT_SPECIAL_DEFENSE] = 12}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
};

item_effect_t item_effect_pp_max = {
    .pp_max = true, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
};

item_effect_t item_effect_guard_spec = {
    .creates_mist = true, .increase_friendship_low = true, .increase_friendship_mid = true,
    .friendship_low = 1, .friendship_mid = 1,
};

item_effect_t item_effect_dire_hit = {
    .increase_critical_ratio = true, .increase_friendship_low = true, .increase_friendship_mid = true,
    .friendship_low = 1, .friendship_mid = 1,
};

item_effect_t item_effect_x_attack = {
    .x_attack = 1, .increase_friendship_low = true, .increase_friendship_mid = true,
    .friendship_low = 1, .friendship_mid = 1,
};

item_effect_t item_effect_x_defend = {
    .x_defense = 1, .increase_friendship_low = true, .increase_friendship_mid = true,
    .friendship_low = 1, .friendship_mid = 1,
};

item_effect_t item_effect_x_speed = {
    .x_speed = 1, .increase_friendship_low = true, .increase_friendship_mid = true,
    .friendship_low = 1, .friendship_mid = 1,
};

item_effect_t item_effect_x_accuracy = {
    .x_accuracy = 1, .increase_friendship_low = true, .increase_friendship_mid = true,
    .friendship_low = 1, .friendship_mid = 1,
};

item_effect_t item_effect_x_special = {
    .x_special_attack = 1, .increase_friendship_low = true, .increase_friendship_mid = true,
    .friendship_low = 1, .friendship_mid = 1,
};

item_effect_t item_effect_evolution_stone = {.trigger_evolution = true};

item_effect_t item_effect_oran_berry = {.heal_hp = true, .hp = 10};

item_effect_t item_effect_sitrus_berry = {.heal_hp = true, .hp = 30};

item_effect_t item_effect_pomeg_berry = {
    .increase_ev_hp = true, .evs = {[STAT_HP] = -10}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 10, .friendship_mid = 5, .friendship_high = 2,
};

item_effect_t item_effect_kelpsy_berry = {
    .increase_ev_attack = true, .evs = {[STAT_ATTACK] = -10}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 10, .friendship_mid = 5, .friendship_high = 2,
};

item_effect_t item_effect_qualot_berry = {
    .increase_ev_defense = true, .evs = {[STAT_DEFENSE] = -10}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 10, .friendship_mid = 5, .friendship_high = 2,
};

item_effect_t item_effect_hondrew_berry = {
    .increase_ev_special_attack = true, .evs = {[STAT_SPECIAL_ATTACK] = -10}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 10, .friendship_mid = 5, .friendship_high = 2,
};

item_effect_t item_effect_grepy_berry = {
    .increase_ev_special_defense = true, .evs = {[STAT_SPECIAL_DEFENSE] = -10}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 10, .friendship_mid = 5, .friendship_high = 2,
};

item_effect_t item_effect_tomato_berry = {
    .increase_ev_speed = true, .evs = {[STAT_SPEED] = -10}, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 10, .friendship_mid = 5, .friendship_high = 2,
};

item_effect_t item_effect_gold_candy = {
    .increase_level = true, .revives = true, .heal_hp = true,
    .hp = ITEM_EFFECT_HEAL_HP_DYANMIC, .increase_friendship_low = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
    .level = 3,
};

item_effect_t item_effect_sweet_candy = {
    .increase_friendship_low = true, .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 25, .friendship_mid = 15, .friendship_high = 5,
};

static item_effect_t item_effect_null_syrup = {
    .increase_ev_hp = true, .increase_ev_attack = true, .increase_ev_defense = true,
    .increase_ev_speed = true, .increase_ev_special_defense = true, .increase_ev_special_attack = true,
    .increase_friendship_mid = true, .increase_friendship_high = true,
    .friendship_low = 5, .friendship_mid = 3, .friendship_high = 2,
    .evs = {
        [STAT_HP] = EFFECT_RESET_EVS, [STAT_ATTACK] = EFFECT_RESET_EVS, [STAT_DEFENSE] = EFFECT_RESET_EVS,
        [STAT_SPEED] = EFFECT_RESET_EVS, [STAT_SPECIAL_ATTACK] = EFFECT_RESET_EVS, [STAT_SPECIAL_DEFENSE] = EFFECT_RESET_EVS,
    }
};

item_effect_t *item_effects[] = {
    [ITEM_TRANK- ITEM_TRANK] = &item_effect_potion,
    [ITEM_GEGENGIFT- ITEM_TRANK] = &item_effect_antidote,
    [ITEM_FEUERHEILER- ITEM_TRANK] = &item_effect_burn_heal,
    [ITEM_EISHEILER- ITEM_TRANK] = &item_effect_ice_heal,
    [ITEM_AUFWECKER- ITEM_TRANK] = &item_effect_awakening,
    [ITEM_PARA_HEILER- ITEM_TRANK] = &item_effect_paralyze_heal,
    [ITEM_TOP_GENESUNG- ITEM_TRANK] = &item_effect_full_restore,
    [ITEM_TOP_TRANK- ITEM_TRANK] = &item_effect_max_potion,
    [ITEM_HYPERTRANK- ITEM_TRANK] = &item_effect_hyper_potion,
    [ITEM_SUPERTRANK- ITEM_TRANK] = &item_effect_super_potion,
    [ITEM_HYPERHEILER- ITEM_TRANK] = &item_effect_full_heal,
    [ITEM_BELEBER- ITEM_TRANK] = &item_effect_revive,
    [ITEM_TOP_BELEBER- ITEM_TRANK] = &item_effect_max_revive,
    [ITEM_CO_MIX- ITEM_TRANK] = &item_effect_fresh_water,
    [ITEM_C_SAFT- ITEM_TRANK] = &item_effect_soda_pop,
    [ITEM_C_SERUM- ITEM_TRANK] = &item_effect_lemonade,
    [ITEM_KUHMUH_MILCH- ITEM_TRANK] = &item_effect_moomoo_milk,
    [ITEM_ENERGIESTAUB- ITEM_TRANK] = &item_effect_energy_powder,
    [ITEM_KRAFTWURZEL- ITEM_TRANK] = &item_effect_energy_root,
    [ITEM_HEILPUDER- ITEM_TRANK] = &item_effect_heal_powder,
    [ITEM_VITALKRAUT- ITEM_TRANK] = &item_effect_revival_herb,
    [ITEM_AETHER- ITEM_TRANK] = &item_effect_ether,
    [ITEM_TOP_AETHER- ITEM_TRANK] = &item_effect_max_ether,
    [ITEM_ELIXIER- ITEM_TRANK] = &item_effect_elixir,
    [ITEM_TOP_ELIXIER- ITEM_TRANK] = &item_effect_max_elixir,
    [ITEM_LAVAKEKS- ITEM_TRANK] = &item_effect_full_heal,
    [ITEM_BLAUE_FLOETE- ITEM_TRANK] = &item_effect_awakening,
    [ITEM_GELBE_FLOETE- ITEM_TRANK] = &item_effect_yellow_flute,
    [ITEM_ROTE_FLOETE- ITEM_TRANK] = &item_effect_red_flute,
    [ITEM_BEERENSAFT- ITEM_TRANK] = &item_effect_berry_juice,
    [ITEM_ZAUBERASCHE- ITEM_TRANK] = &item_effect_sacred_ash,
    [ITEM_KP_PLUS- ITEM_TRANK] = &item_effect_hp_up,
    [ITEM_PROTEIN- ITEM_TRANK] = &item_effect_protein,
    [ITEM_EISEN- ITEM_TRANK] = &item_effect_iron,
    [ITEM_CARBON- ITEM_TRANK] = &item_effect_carbos,
    [ITEM_KALZIUM- ITEM_TRANK] = &item_effect_calcium,
    [ITEM_SONDERBONBON- ITEM_TRANK] = &item_effect_rare_candy,
    [ITEM_AP_PLUS- ITEM_TRANK] = &item_effect_pp_up,
    [ITEM_ZINK- ITEM_TRANK] = &item_effect_zinc,
    [ITEM_AP_TOP- ITEM_TRANK] = &item_effect_pp_max,
    [ITEM_GOLDBONBON- ITEM_TRANK] = &item_effect_gold_candy,
    [ITEM_MEGABLOCK- ITEM_TRANK] = &item_effect_guard_spec,
    [ITEM_ANGRIFFPLUS- ITEM_TRANK] = &item_effect_dire_hit,
    [ITEM_X_ANGRIFF- ITEM_TRANK] = &item_effect_x_attack,
    [ITEM_X_ABWEHR- ITEM_TRANK] = &item_effect_x_defend,
    [ITEM_X_TEMPO- ITEM_TRANK] = &item_effect_x_speed,
    [ITEM_X_TREFFER- ITEM_TRANK] = &item_effect_x_accuracy,
    [ITEM_X_SPEZIAL- ITEM_TRANK] = &item_effect_x_special,
    [ITEM_SUESSBONBON- ITEM_TRANK] = &item_effect_sweet_candy,
    [ITEM_SONNENSTEIN- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_MONDSTEIN- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_FEUERSTEIN- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_DONNERSTEIN- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_WASSERSTEIN- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_BLATTSTEIN- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_LINKKABEL- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_FINSTERSTEIN- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_LEUCHTSTEIN- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_FUNKELSTEIN- ITEM_TRANK] = &item_effect_evolution_stone,
    [ITEM_NULLSAFT - ITEM_TRANK] = &item_effect_null_syrup,
    [ITEM_SINELBEERE- ITEM_TRANK] = &item_effect_oran_berry,
    [ITEM_TSITRUBEERE- ITEM_TRANK] = &item_effect_sitrus_berry,
    [ITEM_AMRENABEERE- ITEM_TRANK] = &item_effect_paralyze_heal,
    [ITEM_MARONBEERE- ITEM_TRANK] = &item_effect_awakening,
    [ITEM_PIRSIFBEERE- ITEM_TRANK] = &item_effect_antidote,
    [ITEM_FRAGIABEERE- ITEM_TRANK] = &item_effect_burn_heal,
    [ITEM_WILBIRBEERE- ITEM_TRANK] = &item_effect_ice_heal,
    [ITEM_JONAGOBEERE- ITEM_TRANK] = &item_effect_ether,
    [ITEM_PERSIMBEERE- ITEM_TRANK] = &item_effect_yellow_flute,
    [ITEM_PRUNUSBEERE- ITEM_TRANK] = &item_effect_full_heal,
    [ITEM_GRANABEERE- ITEM_TRANK] = &item_effect_pomeg_berry,
    [ITEM_SETANGBEERE- ITEM_TRANK] = &item_effect_kelpsy_berry,
    [ITEM_QUALOTBEERE- ITEM_TRANK] = &item_effect_qualot_berry,
    [ITEM_HONMELBEERE- ITEM_TRANK] = &item_effect_hondrew_berry,
    [ITEM_LABRUSBEERE- ITEM_TRANK] = &item_effect_grepy_berry,
    [ITEM_TAMOTBEERE- ITEM_TRANK] = &item_effect_tomato_berry,
};
