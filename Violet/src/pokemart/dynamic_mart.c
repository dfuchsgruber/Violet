#include "constants/flags.h"
#include "constants/items.h"
#include "debug.h"
#include "flags.h"
#include "item/mart.h"
#include "overworld/script.h"
#include "save.h"
#include "types.h"

static mart_item mart_items_pokeball[] = {
    {POKEDEX, ITEM_POKEBALL},
    {0xFFFF, 0}};

static mart_item mart_items_ball_std[] = {
    {FRBADGE_5, ITEM_HYPERBALL},
    {FRBADGE_2, ITEM_SUPERBALL},
    {0xFFFF, 0}};

static mart_item mart_item_potion_std[] = {
    {FRBADGE_7, ITEM_TOP_TRANK},
    {FRBADGE_5, ITEM_HYPERTRANK},
    {FRBADGE_2, ITEM_SUPERTRANK},
    {0, ITEM_TRANK},
    {0xFFFF, 0}};

static mart_item mart_item_full_restore[] = {
    {FRBADGE_8, ITEM_TOP_GENESUNG},
    {0xFFFF, 0}};

static mart_item mart_item_feuerheiler[] = {
    {FRBADGE_4, ITEM_HYPERHEILER},
    {0, ITEM_FEUERHEILER},
    {0xFFFF, 0}};

static mart_item mart_item_eisheiler[] = {
    {FRBADGE_4, ITEM_HYPERHEILER},
    {0, ITEM_EISHEILER},
    {0xFFFF, 0}};

static mart_item mart_item_para_heiler[] = {
    {FRBADGE_4, ITEM_HYPERHEILER},
    {0, ITEM_PARA_HEILER},
    {0xFFFF, 0}};

static mart_item mart_item_aufwecker[] = {
    {FRBADGE_4, ITEM_HYPERHEILER},
    {0, ITEM_AUFWECKER},
    {0xFFFF, 0}};

static mart_item mart_item_gegengift[] = {
    {FRBADGE_4, ITEM_HYPERHEILER},
    {0, ITEM_GEGENGIFT},
    {0xFFFF, 0}};

static mart_item mart_item_repel_std[] = {
    {FRBADGE_4, ITEM_TOP_SCHUTZ},
    {FRBADGE_2, ITEM_SUPERSCHUTZ},
    {0, ITEM_SCHUTZ},
    {0xFFFF, 0}};

static mart_item mart_item_fluchtseil[] = {
    {0, ITEM_FLUCHTSEIL},
    {0xFFFF, 0}};

static mart_item mart_item_beleber[] = {
    {FRBADGE_4, ITEM_BELEBER},
    {0xFFFF, 0}};

static mart_item mart_item_ether[] = {
    {MART_SELLS_ETHER, ITEM_AETHER},
    {0xFFFF, 0}};

static mart_item mart_item_elixier[] = {
    {MART_SELLS_ELIXIR, ITEM_ELIXIER},
    {0xFFFF, 0}};

static mart_item mart_item_abra_doll[] = {
    {FLAG_MART_SELLS_ABRA_DOLL, ITEM_ABRA_PUPPE},
    {0xFFFF, 0}};

static mart_item *mart_items[] = {
    mart_items_pokeball,
    mart_items_ball_std,
    mart_item_full_restore,
    mart_item_potion_std,
    mart_item_gegengift,
    mart_item_aufwecker,
    mart_item_para_heiler,
    mart_item_feuerheiler,
    mart_item_eisheiler,
    mart_item_repel_std,
    mart_item_fluchtseil,
    mart_item_abra_doll,
    mart_item_beleber,
    mart_item_ether,
    mart_item_elixier,
    NULL};

void pokemart_add_item(u16 item, size_t *item_cnt) {
    if (*item_cnt >= ARRAY_COUNT(fmem.dmart))
        return;
    for (size_t i = 0; i < *item_cnt; i++) {
        if (fmem.dmart[i] == item)
            return;
    }
    fmem.dmart[(*item_cnt)++] = item;
}

bool script_cmd_x88_pokemart3(overworld_script_state_t *script_state) {
    u8 *items = (u8 *)overworld_script_read_word(script_state);
    bool default_mart = *(script_state->script++);
    size_t item_cnt = 0;
    if (default_mart) {
        for (int i = 0; mart_items[i] && item_cnt < ARRAY_COUNT(fmem.dmart); i++) {
            for (int j = 0; mart_items[i][j].item; j++) {
                if (!mart_items[i][j].flag || checkflag(mart_items[i][j].flag)) {
                    pokemart_add_item(mart_items[i][j].item, &item_cnt);
                    break; // Add only the best item of each "category" to the default mart
                }
            }
        }
    }
    for (size_t i = 0; UNALIGNED_16_GET(items + 2 * i) && item_cnt < ARRAY_COUNT(fmem.dmart); i++) {
        dprintf("Reading additional item %d\n", UNALIGNED_16_GET(items + 2 * i));
        pokemart_add_item(UNALIGNED_16_GET(items + 2 * i), &item_cnt);
    }

    pokemart(fmem.dmart);
    mart_state.end_callback = overworld_script_resume;
    overworld_script_halt();
    return true;
}
