#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "item/item.h"
#include "constants/items.h"
#include "battle/battlescript.h"
#include "battle/battle_string.h"
#include "debug.h"
#include "callbacks.h"
#include "oam.h"
#include "battle/attack.h"
#include "music.h"
#include "text.h"
#include "battle/bg.h"
#include "bg.h"
#include "dma.h"
#include "superstate.h"
#include "language.h"
#include "prng.h"
#include "constants/pokemon_types.h"
#include "pokemon/basestat.h"
#include "constants/pokemon_colors.h"
#include "berry.h"
#include "pokemon/evolution.h"

static u32 standard_item_drop_rates[][2] = {
    {ITEM_BITTERKRAUT, 100},
    {ITEM_QUARZSTAUB, 50},
    {ITEM_WUNDERSTAUB, 75},
    {ITEM_APFEL, 40},
    /**
    {ITEM_POKEBALL, 75},
    {ITEM_SUPERBALL, 30},
    {ITEM_HYPERBALL, 5},
    {ITEM_TRANK, 75},
    {ITEM_FLUCHTSEIL, 50},
    {ITEM_PARA_HEILER, 50},
    {ITEM_GEGENGIFT, 50},
    {ITEM_AUFWECKER, 50},
    {ITEM_FEUERHEILER, 50},
    {ITEM_EISHEILER, 50},
    {ITEM_ENERGIESTAUB, 25},
    {ITEM_KRAFTWURZEL, 10},
    {ITEM_VITALKRAUT, 5},
    {ITEM_HEILPUDER, 15},
    {ITEM_SCHUTZ, 50},
    {ITEM_SUPERSCHUTZ, 40},
    {ITEM_TOP_SCHUTZ, 30},
    **/
};

static u32 standard_item_count_rates[] = {[1] = 19, [2] = 4, [3] = 1};

static bool drop_standard_item(u8 battler_idx, u16 *item, u8 *cnt) {
    u32 p[ARRAY_COUNT(standard_item_drop_rates)];
    // Applying the level of the battler as offset: The higher the offset, the more "equal" all resulting probabilities will get
    // i.e. the more likely rare items will get
    u8 offset = battlers[battler_idx].level;
    for (size_t i = 0; i < ARRAY_COUNT(standard_item_drop_rates); i++) {
        p[i] = (u32)(standard_item_drop_rates[i][1] + offset);
    }
    *item = (u16)(standard_item_drop_rates[choice(p, ARRAY_COUNT(p), NULL)][0]);
    *cnt = (u8) choice(standard_item_count_rates, ARRAY_COUNT(standard_item_count_rates), NULL);
    return true;
}

static u32 standard_item_rare_drop_rates[][2] = {
    {ITEM_MININUGGET, 5},
    {ITEM_RIESENAPFEL, 3},
};

static u32 standard_item_rare_count_rates[] = {[1] = 1};

static bool drop_rare_item(u8 battler_idx, u16 *item, u8 *cnt) {
    u32 p[ARRAY_COUNT(standard_item_rare_drop_rates)];
    // Applying the level of the battler as offset: The higher the offset, the more "equal" all resulting probabilities will get
    // i.e. the more likely rare items will get
    u8 offset = battlers[battler_idx].level;
    for (size_t i = 0; i < ARRAY_COUNT(standard_item_rare_drop_rates); i++) {
        p[i] = (u32)(standard_item_rare_drop_rates[i][1] + offset);
    }
    *item = (u16)(standard_item_rare_drop_rates[choice(p, ARRAY_COUNT(p), NULL)][0]);
    *cnt = (u8) choice(standard_item_rare_count_rates, ARRAY_COUNT(standard_item_rare_count_rates), NULL);
    return true;
}

#define P_ARRAY_ADD_ITEM(p, items, item, prob, p_size) {p[p_size] = prob; items[p_size] = item; p_size++;}

static u32 drop_type_item_count_rates[] = {0, 1};

static bool drop_type_item(u8 battler_idx, u16 *dst_item, u8 *dst_cnt) {
    u32 p[16]; u16 items[16];
    size_t p_size = 0;
    if (battlers[battler_idx].type1 == TYPE_WASSER || battlers[battler_idx].type2 == TYPE_WASSER) {
        P_ARRAY_ADD_ITEM(p, items, ITEM_PERLE, 50, p_size);
        P_ARRAY_ADD_ITEM(p, items, ITEM_HERZSCHUPPE, 25, p_size);
        P_ARRAY_ADD_ITEM(p, items, ITEM_RIESENPERLE, 5, p_size);
    }
    if (battlers[battler_idx].type1 == TYPE_PFLANZE || battlers[battler_idx].type2 == TYPE_PFLANZE ||
        battlers[battler_idx].type1 == TYPE_KAEFER || battlers[battler_idx].type2 == TYPE_KAEFER) {
        P_ARRAY_ADD_ITEM(p, items, ITEM_MINIPILZ, 70, p_size);
        P_ARRAY_ADD_ITEM(p, items, ITEM_RIESENPILZ, 10, p_size);
    }
    if (battlers[battler_idx].type1 == TYPE_GESTEIN || battlers[battler_idx].type2 == TYPE_GESTEIN ||
        battlers[battler_idx].type1 == TYPE_BODEN || battlers[battler_idx].type2 == TYPE_BODEN ||
        battlers[battler_idx].type1 == TYPE_FEE || battlers[battler_idx].type2 == TYPE_FEE) {
        P_ARRAY_ADD_ITEM(p, items, ITEM_STERNENSTAUB, 40, p_size);
        P_ARRAY_ADD_ITEM(p, items, ITEM_STERNENSTUECK, 2, p_size);
    }
    /**
    for (u16 i = ITEM_NORMALJUWEL; i <= ITEM_UNLICHTJUWEL; i++) {
        if (battlers[battler_idx].type1 == item_get_hold_effect_parameter(i) ||
            battlers[battler_idx].type2 == item_get_hold_effect_parameter(i)) {
            P_ARRAY_ADD_ITEM(p, items, i, 1, p_size);
        }
    }
    **/
    if (p_size > 0) {
        *dst_item = items[choice(p, p_size, NULL)];
        *dst_cnt = (u8)choice(drop_type_item_count_rates, ARRAY_COUNT(drop_type_item_count_rates), NULL);
        return true;
    } else {
        return false;
    }
}


static u32 drop_color_item_count_rates[] = {[1] = 1};

static bool drop_color_item(u8 battler_idx, u16 *dst_item, u8 *dst_cnt) {
    int color = basestats[battlers[battler_idx].species].color_flip_field & 0x7F;
    u32 p[16]; u16 items[16];
    size_t p_size = 0;
    switch(color) {
        case POKEMON_COLOR_BLAU:
            P_ARRAY_ADD_ITEM(p, items, ITEM_INDIGOSTUECK, 1, p_size);
            break;
        case POKEMON_COLOR_ROT:
            P_ARRAY_ADD_ITEM(p, items, ITEM_PURPURSTUECK, 1, p_size);
            break;
        case POKEMON_COLOR_GELB:
            P_ARRAY_ADD_ITEM(p, items, ITEM_GELBSTUECK, 1, p_size);
            break;
        case POKEMON_COLOR_GRUEN:
            P_ARRAY_ADD_ITEM(p, items, ITEM_GRUENSTUECK, 1, p_size);
            break;
        case POKEMON_COLOR_SCHWARZ:
            P_ARRAY_ADD_ITEM(p, items, ITEM_DUESTERSTUECK, 1, p_size);
            break;
        case POKEMON_COLOR_WEISS:
            P_ARRAY_ADD_ITEM(p, items, ITEM_LICHTSTUECK, 1, p_size);
            break;
        case POKEMON_COLOR_BRAUN:
            P_ARRAY_ADD_ITEM(p, items, ITEM_SOLARSTUECK, 1, p_size);
            break;
        case POKEMON_COLOR_GRAU:
            P_ARRAY_ADD_ITEM(p, items, ITEM_LUNARSTUECK, 1, p_size);
            break;
        case POKEMON_COLOR_ROSA:
            P_ARRAY_ADD_ITEM(p, items, ITEM_GLITZERSTUECK, 1, p_size);
            break;
    }
    if (p_size > 0) {
        *dst_item = items[choice(p, p_size, NULL)];
        *dst_cnt = (u8)choice(drop_color_item_count_rates, ARRAY_COUNT(drop_color_item_count_rates), NULL);
        return true;
    } else {
        return false;
    }
}

static bool drop_species_item(u8 battler_idx, u16 *dst_item, u8 *dst_cnt) {
    u16 species = battlers[battler_idx].species;
    u32 p[16]; u16 items[16];
    size_t p_size = 0;
    if (basestats[species].common_item) P_ARRAY_ADD_ITEM(p, items, basestats[species].common_item, 50, p_size)
    if (basestats[species].rare_item) P_ARRAY_ADD_ITEM(p, items, basestats[species].rare_item, 5, p_size)
     if (p_size > 0) {
        *dst_item = items[choice(p, p_size, NULL)];
        *dst_cnt = 1;
        return true;
    } else {
        return false;
    }
}

static u32 berry_dropping_probabilities[] = {
    [ITEM_IDX_TO_BERRY_IDX(ITEM_AMRENABEERE)] = 10,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MARONBEERE)] = 10,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PIRSIFBEERE)] = 10,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_FRAGIABEERE)] = 10,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WILBIRBEERE)] = 10,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_JONAGOBEERE)] = 4,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SINELBEERE)] = 10,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PERSIMBEERE)] = 10,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PRUNUSBEERE)] = 1,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TSITRUBEERE)] = 7,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_GIEFEBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WIKIBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_GAUVEBEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_YAPABEERE)] = 5,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_HIMMIHBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MORBBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_NANABBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_NIRBEBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SANANABEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_GRANABEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SETANGBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_QUALOTBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_HONMELBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LABRUSBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TAMOTBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SAIMBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MAGOSTBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_RABUTABEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TRONZIBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_KIWANBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_PALLMBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_WASMELBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_DURINBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_MYRTILBEERE)] = 6,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LYDZIBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LINGANBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_SALKABEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_TAHAYBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_APIKOBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_LANSATBEERE)] = 2,
    [ITEM_IDX_TO_BERRY_IDX(ITEM_KRAMBOBEERE)] = 1,
};


static u32 drop_berry_item_count_rates[] = {[1] = 13, [2] = 4, [3] = 2, [4] = 1};

static bool drop_berry_item(u8 battler_idx, u16 *dst_item, u8 *dst_cnt) {
    (void) battler_idx;
    *dst_item = (u16)(BERRY_IDX_TO_ITEM_IDX(choice(berry_dropping_probabilities, ARRAY_COUNT(berry_dropping_probabilities), NULL)));
    *dst_cnt = (u8)choice(drop_berry_item_count_rates, ARRAY_COUNT(drop_berry_item_count_rates), NULL);
    return true;
}

static bool drop_evolution_item(u8 battler_idx, u16 *dst_item, u8 *dst_cnt) {
    u16 species = battlers[battler_idx].species;
    u16 items[16];
    size_t num_items = pokemon_get_evolution_item_line(species, items, ARRAY_COUNT(items));
    if (num_items == 0)
        return false;
    size_t p[16] = {1};
    *dst_item = items[choice(p, num_items, NULL)];
    *dst_cnt = 1;
    return true;
}


enum {
    DROP_STANDARD_ITEM = 0,
    DROP_RARE_ITEM,
    DROP_TYPE_ITEM,
    DROP_COLOR_ITEM,
    DROP_SPECIES_ITEM,
    DROP_BERRY_ITEM,
    DROP_EVOLUTION_ITEM,
};

static bool (*dropping_functions[])(u8, u16*, u8*) = {
    [DROP_STANDARD_ITEM] = drop_standard_item,
    [DROP_RARE_ITEM] = drop_rare_item,
    [DROP_TYPE_ITEM] = drop_type_item,
    [DROP_COLOR_ITEM] = drop_color_item,
    [DROP_SPECIES_ITEM] = drop_species_item,
    [DROP_BERRY_ITEM] = drop_berry_item,
    [DROP_EVOLUTION_ITEM] = drop_evolution_item,
};

static u32 dropping_type_probabilities[] = {
    [DROP_STANDARD_ITEM] = 30,
    [DROP_RARE_ITEM] = 2,
    [DROP_TYPE_ITEM] = 3,
    [DROP_COLOR_ITEM] = 3,
    [DROP_SPECIES_ITEM] = 2,
    [DROP_BERRY_ITEM] = 0, // For now, we don't drop any berries
    [DROP_EVOLUTION_ITEM] = 1,
};

void battler_drop_item(u8 battler_idx, u16 *dst_item, u8 *dst_cnt) {
    u32 p[ARRAY_COUNT(dropping_type_probabilities)];
    u16 items[ARRAY_COUNT(dropping_type_probabilities)];
    u8 cnts[ARRAY_COUNT(dropping_type_probabilities)];
    size_t p_size = 0;
    for (size_t i = 0; i < ARRAY_COUNT(dropping_type_probabilities); i++) {
        u16 item = 0; u8 cnt = 0; 
        if (dropping_functions[i](battler_idx, &item, &cnt)) {
            DEBUG("Type %d made item %d droppable (absolute mass %d)\n", i, item, dropping_type_probabilities[i]);
            p[p_size] = dropping_type_probabilities[i];
            items[p_size] = item;
            cnts[p_size] = cnt;
            p_size++;
        }
    }
    size_t idx = choice(p, p_size, NULL);

    *dst_item = items[idx];
    *dst_cnt = cnts[idx];
}

bool battler_drop_next_item(u8 battler_idx, u16 *item, u8 *cnt) {
    u32 p[2] = {
        [0] = (u32)(1 + (1 << BATTLE_STATE2->num_items_dropped[battler_idx])),
        [1] = 2,
    };
    if (battle_flags & BATTLE_AGGRESSIVE_WILD)
        p[1]++;
    if (battle_flags & BATTLE_DOUBLE)
        p[1]++;
    if (BATTLE_STATE2->item_dropping_chance_increased_by_item)
        p[1]++;
    if (BATTLE_STATE2->item_dropping_chance_increased_by_ability)
        p[1]++;
    if (choice(p, ARRAY_COUNT(p), NULL) != 0) {
        battler_drop_item(battler_idx, item, cnt);
        return true;
    }
    return false;
}

static void battle_item_drop_compact(u8 battler_idx) {
    for (int i = 0; i < BATTLE_STATE2->num_items_dropped[battler_idx]; i++) {
        u16 item = BATTLE_STATE2->items_dropped[battler_idx][i];
        for (int j = i + 1; j < BATTLE_STATE2->num_items_dropped[battler_idx] && j < MAX_ITEMS_DROPPED_PER_BATTLER; j++) {
            if (BATTLE_STATE2->items_dropped[battler_idx][j] == item) {
                DEBUG("compactifying items at slot %d and %d\n", i, j);
                // Aggregate the same items
                BATTLE_STATE2->items_dropped_cnt[battler_idx][i] = (u8) (BATTLE_STATE2->items_dropped_cnt[battler_idx][i] + 
                    BATTLE_STATE2->items_dropped_cnt[battler_idx][j]);
                // Remove the aggregated item by swapping with the last one and reducing the list length
                BATTLE_STATE2->num_items_dropped[battler_idx]--;
                BATTLE_STATE2->items_dropped[battler_idx][j] = BATTLE_STATE2->items_dropped[battler_idx][BATTLE_STATE2->num_items_dropped[battler_idx]];
            }
        }
    }
}

extern u8 battlescript_itemdrop[];
extern u8 battlescript_print_payday_money[];
extern u8 battlescript_itemdrop_picked_up[];
extern u8 battlescript_itemdrop_picked_up_no_space[];

enum {
    DROPPING_PAYDAY = 0,
    DROPPING_INIT,
    DROP_ITEM,
    DROPPING_DONE,
    SUMMARY_INIT,
    SUMMARY_DRAW_TEXT,
    SUMMARY_WAIT_FOR_DMA3,
    SUMMARY_WAIT_FOR_INPUT,
    SUMMARY_CLEAR,
    SUMMARY_DONE,
};

static tbox_font_colormap item_drop_summary_fontcolmap = { .background = 0xE, .body = 0xD, .edge = 0xF};

static u8 battle_item_drop_summary_tbox_new() {
    int height = 2 * BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler];
    tboxdata template = {0};
    tbox_data_new(&template, 1, 14, (u8)(13 - height), 15, (u8)height, 5, 0x100); // Basically re-uses all the tiles of the "standard" gp battle tbox, which is too small
    return tbox_new(&template);
}

static void battle_item_drop_draw_summary_text() {
    // TODO
    for (int i = 0; i < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]; i++) {
        u16 item = BATTLE_STATE2->items_dropped[BATTLE_STATE2->item_dropping_battler][i];
        u8 cnt = BATTLE_STATE2->items_dropped_cnt[BATTLE_STATE2->item_dropping_battler][i];
        if (!item_has_room(item, cnt))
            cnt = 0;
        itoa(strbuf, cnt, ITOA_NO_PADDING, 1);
        u8 str_x[] = PSTRING("x ");
        strcat(strbuf, str_x);
        strcat(strbuf, item_get_name(item));

        tbox_print_string(BATTLE_STATE2->item_dropping_summary_tbox_idx, 2, 0, (u16)((16 * i)), 0, 0, 
            &item_drop_summary_fontcolmap, 0xFF, strbuf);

        if (!item_has_room(item, cnt)) {
            u8 str_full[] = LANGDEP(PSTRING("voll"), PSTRING("full"));
            strcpy(strbuf, str_full);
            tbox_print_string(BATTLE_STATE2->item_dropping_summary_tbox_idx, 2, 96, (u16)((16 * i)), 0, 0, 
                &item_drop_summary_fontcolmap, 0xFF, strbuf);
        }
    }
}

/**
static void item_drop_summary_battle_gp_tbox_draw(u8 mode) {
    battle_gp_tbox_draw(18, 7, 29, (u8)(2 * BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler] + 2 + 9), mode);
}
**/

void bsc_cmd_itemdrop_and_payday() {
    // DEBUG("Payday in state %d\n", BATTLE_STATE2->item_dropping_state);
    switch (BATTLE_STATE2->item_dropping_state) {
        case DROPPING_PAYDAY: {
            BATTLE_STATE2->item_dropping_state++;
            if (!(battle_flags & BATTLE_LINK) && battle_payday_money > 0) {
                u32 amount =(u32)(battle_payday_money * battle_state->money_multiplier);
                money_add(&save1->money, amount);
                BSC_BUFFER_HWORD(bsc_string_buffer0, 5, amount);
                battlescript_callstack_push_next_command();
                bsc_offset = battlescript_print_payday_money;
            }
            if (battle_flags & BATTLE_TRAINER) {
                BATTLE_STATE2->item_dropping_state = SUMMARY_DONE;
            } else {
                BATTLE_STATE2->item_dropping_state = DROPPING_INIT;
            }
            break;
        }
        case DROPPING_INIT:  {
            BATTLE_STATE2->item_dropping_battler = 0;
            for (int i = 0; i < MAX_ITEMS_DROPPED_PER_BATTLER; i++)
                BATTLE_STATE2->items_dropped_oams[i] = 0xFF;

            for (u8 i = 0; i < battler_cnt; i++) {
                if (battler_is_opponent(i)) {
                    u16 item = 0;
                    u8 cnt = 0;
                    do {
                        if (battler_drop_next_item(i, &item, &cnt)) {
                            BATTLE_STATE2->items_dropped[i][BATTLE_STATE2->num_items_dropped[i]] = item;
                            BATTLE_STATE2->items_dropped_cnt[i][BATTLE_STATE2->num_items_dropped[i]] = cnt;
                            BATTLE_STATE2->num_items_dropped[i]++;
                            DEBUG("Battler %d dropped item %d (cnt=%d)\n", i, item, cnt);
                        } else {
                            break;
                        }
                    } while (item != 0 && BATTLE_STATE2->num_items_dropped[i] < MAX_ITEMS_DROPPED_PER_BATTLER);
                    battle_item_drop_compact(i);
                    /**
                    // Try to add the items to the player's inventory and remove non-addable items (i.e. bag full)
                    for (int j = 0; j < BATTLE_STATE2->num_items_dropped[i]; j++) {
                        item = BATTLE_STATE2->items_dropped[i][j];
                        if (!item_has_room(item, 1)) { // This item can't be dropped, remove it from the list, i.e. swap it with the last element and shrink the list's size
                            BATTLE_STATE2->items_dropped[i][j] = BATTLE_STATE2->items_dropped[i][BATTLE_STATE2->num_items_dropped[i] - 1];
                            BATTLE_STATE2->num_items_dropped[i]--;
                        }
                    }
                    **/
                    // Debugging:
                    for (int j = 0; j < BATTLE_STATE2->num_items_dropped[i]; j++) {
                        DEBUG("Player obtained item %d %d-times from battler %d\n", BATTLE_STATE2->items_dropped[i][j], BATTLE_STATE2->items_dropped_cnt[i][j], j);
                    }
                } else {
                    BATTLE_STATE2->num_items_dropped[i] = 0; // Only opponents can drop items
                }
            }
            BATTLE_STATE2->item_dropping_state++;
        }
        FALL_THROUGH;
        case DROP_ITEM: {
            for(; BATTLE_STATE2->item_dropping_battler < battler_cnt; BATTLE_STATE2->item_dropping_battler++) {
                if (!(BATTLE_STATE2->items_dropped_done & int_bitmasks[BATTLE_STATE2->item_dropping_battler])) {
                    BATTLE_STATE2->items_dropped_done = (u8)(BATTLE_STATE2->items_dropped_done | int_bitmasks[BATTLE_STATE2->item_dropping_battler]);
                    if (BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler] > 0) {
                        // Add the items
                        for (int i = 0; i < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]; i++) {
                            u16 item = BATTLE_STATE2->items_dropped[BATTLE_STATE2->item_dropping_battler][i];
                            u8 cnt = BATTLE_STATE2->items_dropped_cnt[BATTLE_STATE2->item_dropping_battler][i];
                            if (item_has_room(item, cnt))
                                item_add(item, cnt);
                        }
                        battle_scripting.battler_idx = BATTLE_STATE2->item_dropping_battler;
                        battlescript_callstack_push_next_command();
                        bsc_offset = battlescript_itemdrop;
                        BATTLE_STATE2->item_dropping_state = SUMMARY_INIT;
                        return;
                    }
                }
            }
            BATTLE_STATE2->item_dropping_state++;
        }
        FALL_THROUGH;
        case DROPPING_DONE: {
            bsc_offset++;
            return;
        }
        case SUMMARY_INIT: {
            fanfare(257);
            battle_bg1_x = 0;
            battle_bg1_y = 256;
            bg_set_attribute(0, BG_ATTR_PRIORITY, 1);
            bg_set_attribute(1, BG_ATTR_PRIORITY, 0);
            bg_sync_display_and_show(0);
            bg_sync_display_and_show(1);
            BATTLE_STATE2->item_dropping_summary_tbox_idx = battle_item_drop_summary_tbox_new();
            tbox_border_draw(BATTLE_STATE2->item_dropping_summary_tbox_idx, 34, 1);
            // item_drop_summary_battle_gp_tbox_draw(BATTLE_GP_TBOX_BG_1 | BATTLE_GP_TBOX_DRAW);
            BATTLE_STATE2->item_dropping_state++;
            break;
        }
        case SUMMARY_DRAW_TEXT: {
            tbox_flush_set(BATTLE_STATE2->item_dropping_summary_tbox_idx, 0xEE);
            battle_item_drop_draw_summary_text();
            tbox_tilemap_draw(BATTLE_STATE2->item_dropping_summary_tbox_idx);
            tbox_copy_to_vram(BATTLE_STATE2->item_dropping_summary_tbox_idx, TBOX_COPY_TILEMAP | TBOX_COPY_TILESET);
            BATTLE_STATE2->item_dropping_state++;
            break;
        }
        case SUMMARY_WAIT_FOR_DMA3: {
            if (!dma3_busy(-1))
                battle_bg1_y = 0;
                BATTLE_STATE2->item_dropping_state++;
            break;
        }
        case SUMMARY_WAIT_FOR_INPUT: {
            
            if (!big_callback_is_active(fanfare_callback_wait) && super.keys_new.value) { // Any key press is ok...
                play_sound(5);
                tbox_flush_all(BATTLE_STATE2->item_dropping_summary_tbox_idx, 0);
                // item_drop_summary_battle_gp_tbox_draw(BATTLE_GP_TBOX_BG_1 | BATTLE_GP_TBOX_CLEAR);
                BATTLE_STATE2->item_dropping_state++;
            }
            break;
        }
        case SUMMARY_CLEAR: {
            tbox_flush_map(BATTLE_STATE2->item_dropping_summary_tbox_idx);
            tbox_copy_to_vram(BATTLE_STATE2->item_dropping_summary_tbox_idx, TBOX_COPY_TILEMAP);
            BATTLE_STATE2->item_dropping_state++;
            break; 
        }
        case SUMMARY_DONE: {
            if (!dma3_busy(-1)) {
                tbox_free(BATTLE_STATE2->item_dropping_summary_tbox_idx);
                bg_set_attribute(0, BG_ATTR_PRIORITY, 0);
                bg_set_attribute(1, BG_ATTR_PRIORITY, 1);
                bg_sync_display_and_show(0);
                bg_sync_display_and_show(1);
                BATTLE_STATE2->item_dropping_state = DROP_ITEM;
            }
            break;
        }
        /**
        case DROPPING_COLLECT_ITEM: {
            if (BATTLE_STATE2->item_to_pickup < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]) {
                bsc_last_used_item = BATTLE_STATE2->items_dropped[BATTLE_STATE2->item_dropping_battler][BATTLE_STATE2->item_to_pickup];
                oam_free(oams + BATTLE_STATE2->items_dropped_oams[BATTLE_STATE2->item_to_pickup]);
                if (item_has_room(bsc_last_used_item, 1)) {
                    battlescript_callstack_push_next_command();
                    bsc_offset = battlescript_itemdrop_picked_up;
                    play_sound(88);
                    item_add(bsc_last_used_item, 1);
                } else {
                    battlescript_callstack_push_next_command();
                    bsc_offset = battlescript_itemdrop_picked_up_no_space;
                }
                BATTLE_STATE2->item_to_pickup++;
                return;
            } else {
                BATTLE_STATE2->item_dropping_state = DROP_ITEM;
            }
            break;
        }
        **/
    }
}

static coordinate_t item_dropping_animation_offsets[MAX_ITEMS_DROPPED_PER_BATTLER] = {
    {.x = 4, .y = 0}, {.x = 20, .y = -4}, {.x = -20, .y = 0}, {.x = -8, .y = -2},
};


enum {
    ITEM_DROPPING_CALLBACK_STATE = 0,
    ITEM_DROPPING_CALLBACK_DELAY,
    ITEM_DROPPING_CALLBACK_NUM_OAMS_TO_WAIT_FOR,
};

enum {
    ITEM_DROPPING_OAM_STATE_SHOW = 0,
    ITEM_DROPPING_OAM_STATE_FALL,
    ITEM_DROPPING_OAM_STATE_REBOUNCE,
    ITEM_DROPPING_OAM_STATE_IDLE,
    ITEM_DROPPING_OAM_STATE_DELETE,
};

enum {
    ITEM_DROPPING_OAM_CALLBACK_IDX = 0,
    ITEM_DROPPING_OAM_DELAY,
    ITEM_DROPPING_OAM_FRAME,
    ITEM_DROPPING_OAM_STATE
};

#define DROPPING_DY 32
#define DROPPING_DT 16

static void item_dropping_oam_callback(oam_object *self) {
    u16 *callback_idx = self->private + ITEM_DROPPING_OAM_CALLBACK_IDX;
    u16 *delay = self->private + ITEM_DROPPING_OAM_DELAY;
    u16 *frame = self->private + ITEM_DROPPING_OAM_FRAME;
    u16 *state = self->private + ITEM_DROPPING_OAM_STATE;
    if (*delay > 0) {
        --*delay;
        return;
    }

    FIXED dt = INT_TO_FIXED(DROPPING_DT); // in frames
    FIXED dy = INT_TO_FIXED(DROPPING_DY); // Fallin 32 px
    FIXED a = FIXED_DIV(dy, FIXED_MUL(dt, dt));
    switch(*state) {
        case ITEM_DROPPING_OAM_STATE_SHOW: {
            self->flags = (u16)(self->flags &(~OAM_FLAG_INVISIBLE));
            *state = ITEM_DROPPING_OAM_STATE_FALL;
            FALL_THROUGH;
        }
        case ITEM_DROPPING_OAM_STATE_FALL: {
            FIXED t = INT_TO_FIXED(*frame);
            FIXED y = FIXED_MUL(a, FIXED_MUL(t, t));
            self->y2 = (s16)(FIXED_TO_INT(y));
            if (*frame >= DROPPING_DT) {
                play_sound(23);
                *state = ITEM_DROPPING_OAM_STATE_REBOUNCE;
                *frame = 0;
            } else {
                ++*frame;
            }
            break;
        }
        case ITEM_DROPPING_OAM_STATE_REBOUNCE: {
            // Re-bounce, use a parabola for the y direction as well, but now with a initial velocity given by a * dt / const = dy / dt / const
            FIXED t = INT_TO_FIXED(*frame);
            FIXED v0 = FIXED_DIV(FIXED_MUL(FIXED_DIV(dy, dt), INT_TO_FIXED(2)), INT_TO_FIXED(3));
            FIXED y = FIXED_SUB(FIXED_MUL(a, FIXED_MUL(t, t)), FIXED_MUL(v0, t));
            if (y > 0) {
                y = 0;
                big_callbacks[*callback_idx].params[ITEM_DROPPING_CALLBACK_NUM_OAMS_TO_WAIT_FOR]--; // Wait for one oam less
                *state = ITEM_DROPPING_OAM_STATE_IDLE;
            }
            self->y2 = (s16)(FIXED_TO_INT(FIXED_ADD(dy, y)));
            ++*frame;
            break;
        }
        case ITEM_DROPPING_OAM_STATE_IDLE: {
            break; // Do nothing, wait for removal basically
        }
        case ITEM_DROPPING_OAM_STATE_DELETE: {
            // play_sound(88);
            big_callbacks[*callback_idx].params[ITEM_DROPPING_CALLBACK_NUM_OAMS_TO_WAIT_FOR]--; // Wait for one oam less
            oam_free(self); // This state is set externally, when picking stuff up
            break;
        }
    }
}

void battle_animation_callback_create_item_sprite(u8 self) {
    u16 *state = big_callbacks[self].params + ITEM_DROPPING_CALLBACK_STATE;
    u16 *delay = big_callbacks[self].params + ITEM_DROPPING_CALLBACK_DELAY;
    u16 *num_oams_to_wait_for = big_callbacks[self].params + ITEM_DROPPING_CALLBACK_NUM_OAMS_TO_WAIT_FOR;
    if (*delay > 0) {
        --*delay;
        return;
    }
    switch (*state) {
        case 0: { // Allocate resources
            for (u8 i = 0; i < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]; i++) {
                u16 tag = (u16)(0x56A0 + MAX_ITEMS_DROPPED_PER_BATTLER * BATTLE_STATE2->item_dropping_battler + i);
                u8 oam_idx = item_oam_new(tag, tag, BATTLE_STATE2->items_dropped[BATTLE_STATE2->item_dropping_battler][i]);
                BATTLE_STATE2->items_dropped_oams[i] = oam_idx;
                oams[oam_idx].x = (s16)(battler_get_coordinate(battle_scripting.battler_idx, BATTLER_COORD_X_2) + item_dropping_animation_offsets[i].x);
                oams[oam_idx].y = (s16)(battler_get_coordinate(battle_scripting.battler_idx, BATTLER_COORD_Y) - 8 + item_dropping_animation_offsets[i].y);
                oams[oam_idx].priority_on_layer = (u8)(battler_oam_get_relative_priority(BATTLE_STATE2->item_dropping_battler) + i);
                oams[oam_idx].flags |= OAM_FLAG_INVISIBLE;
                oams[oam_idx].private[0] = self;
                oams[oam_idx].private[1] = (u16)(i * 16); // delay
                oams[oam_idx].callback = item_dropping_oam_callback;
                ++*num_oams_to_wait_for;
            }
            ++*state;
            break;
        }
        case 1: {
            if (*num_oams_to_wait_for > 0) 
                return;
            *delay = 32;
            ++*state;
            break;
        }
        case 2: {
            for (u8 i = 0; i < BATTLE_STATE2->num_items_dropped[BATTLE_STATE2->item_dropping_battler]; i++) {
                u8 oam_idx = BATTLE_STATE2->items_dropped_oams[i];
                oams[oam_idx].private[ITEM_DROPPING_OAM_DELAY] = (u16)(i * 8); // delay
                oams[oam_idx].private[ITEM_DROPPING_OAM_STATE] = ITEM_DROPPING_OAM_STATE_DELETE; // state
                ++*num_oams_to_wait_for;
            }
            ++*state;
            break;
        }
        case 3: {
            if (*num_oams_to_wait_for > 0) 
                return;
            battle_animation_big_callback_delete(self);
            break;
        }

    }


}