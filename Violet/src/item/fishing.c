#include "item/fishing.h"
#include "agbmemory.h"
#include "callbacks.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/pokemon_attributes.h"
#include "constants/sav_keys.h"
#include "constants/vars.h"
#include "data_structures.h"
#include "debug.h"
#include "flags.h"
#include "item/item.h"
#include "language.h"
#include "list_menu.h"
#include "map/wild_pokemon.h"
#include "overworld/script.h"
#include "pokemon/virtual.h"
#include "prng.h"
#include "save.h"
#include "types.h"
#include "vars.h"

static u16 fishing_rng_no_bait() {
    u32 state = (u32)gp_stack_pop();
    u16 r = (u16)_prng_xorshift(&state);
    dprintf("No bait r 0x%x\n", r);
    gp_stack_push((int)state);
    return (u16)(r % (512 - MIN(save_get_key(SAV_KEY_FISHING_ENCOUNTERS), 256)));
}

static u16 fishing_rng_bait() {
    u32 state = (u32)gp_stack_pop();
    u16 r = (u16)_prng_xorshift(&state);
    gp_stack_push((int)state);
    return (u16)(r % (256 - MIN(save_get_key(SAV_KEY_FISHING_ENCOUNTERS), 128)));
}

static u16 fishing_rng_golden_bait() {
    u32 state = (u32)gp_stack_pop();
    u16 r = (u16)_prng_xorshift(&state);
    gp_stack_push((int)state);
    return (u16)(r % (64 - MIN(save_get_key(SAV_KEY_FISHING_ENCOUNTERS), 32)));
}

static u16 fishing_rng_shining_bait() {
    u32 state = (u32)gp_stack_pop();
    u16 r = (u16)_prng_xorshift(&state);
    gp_stack_push((int)state);
    return (u16)(r % (16 - MIN(save_get_key(SAV_KEY_FISHING_ENCOUNTERS), 8)));
}

u16 fishing_create_pokemon(wild_pokemon_habitat *habitat, u8 rod_type) {
    int idx = wildbattle_sample_from_rod_pdf(rod_type);
    u8 level = wildbattle_sample_level(habitat->data + idx);
    u16 species = habitat->data[idx].species;
    pid_t pid = {.value = 0};
    // Seed the fishing feature rng
    u32 seed = (u32)((rnd16() << 16) | rnd16());
    dprintf("Gp stack has size %d\n", fmem.gp_stack_size);
    gp_stack_push((int)seed);
    if (checkflag(FLAG_FISHING_SHINING_BAIT_USED)) {
        pokemon_spawn_by_seed_algorithm(opponent_pokemon, species, (u8)(MIN(level + 8, 100)),
                                        32, false, pid, false, 0, fishing_rng_shining_bait, NULL);
        pid_t pid = {.value = (u32)pokemon_get_attribute(opponent_pokemon, ATTRIBUTE_PID, 0)};
        pid.fields.is_shiny = 1;
        pokemon_set_attribute(opponent_pokemon, ATTRIBUTE_PID, &pid);
        clearflag(FLAG_FISHING_SHINING_BAIT_USED);
        item_remove(ITEM_LEUCHTKOEDER, 1);
        dprintf("Spawned fishing pokemon with shining bait\n");
    } else if (checkflag(FLAG_FISHING_GOLDEN_BAIT_USED)) {
        pokemon_spawn_by_seed_algorithm(opponent_pokemon, species, (u8)(MIN(level + 5, 100)),
                                        POKEMON_NEW_RANDOM_IVS, false, pid, false, 0, fishing_rng_golden_bait, NULL);
        clearflag(FLAG_FISHING_GOLDEN_BAIT_USED);
        item_remove(ITEM_GOLDKOEDER, 1);
        dprintf("Spawned fishing pokemon with golden bait\n");
    } else if (checkflag(FLAG_FISHING_BAIT_USED)) {
        pokemon_spawn_by_seed_algorithm(opponent_pokemon, species, (u8)(MIN(level + 2, 100)),
                                        POKEMON_NEW_RANDOM_IVS, false, pid, false, 0, fishing_rng_bait, NULL);
        clearflag(FLAG_FISHING_BAIT_USED);
        item_remove(ITEM_KOEDER, 1);
        dprintf("Spawned fishing pokemon with bait\n");
    } else {
        pokemon_spawn_by_seed_algorithm(opponent_pokemon, species, level,
                                        POKEMON_NEW_RANDOM_IVS, false, pid, false, 0, fishing_rng_no_bait, NULL);
        dprintf("Spawned fishing pokemon without bait\n");
    }
    gp_stack_pop();
    return species;
}

static void fishing_big_callback_wait_bait_selection(u8 self) {
    (void)self;
}

void fishing_start_after_bait_selection() {
    u8 idx = big_callback_get_id(fishing_big_callback_wait_bait_selection);
    if (idx == 0xFF)
        derrf("No fishing in progress, can't start it after bait selection...\n");
    big_callbacks[idx].function = fishing_big_callback;
}

void fishing_big_callback_bait(u8 self) {
    overworld_script_init(ow_script_fishing);
    big_callbacks[self].function = fishing_big_callback_wait_bait_selection;
}

static u8 str_no_bait[] = LANGDEP(PSTRING("Kein Köder"), LANGDEP("No bait"));

static u16 fishing_build_selection_list(list_menu_item *list) {
    u16 num_displayed = 0;
    if (item_check(ITEM_KOEDER, 1)) {
        list[num_displayed].text = items[ITEM_KOEDER].name;
        list[num_displayed].idx = FLAG_FISHING_BAIT_USED;
        num_displayed++;
    }
    if (item_check(ITEM_GOLDKOEDER, 1)) {
        list[num_displayed].text = items[ITEM_GOLDKOEDER].name;
        list[num_displayed].idx = FLAG_FISHING_GOLDEN_BAIT_USED;
        num_displayed++;
    }
    if (item_check(ITEM_LEUCHTKOEDER, 1)) {
        list[num_displayed].text = items[ITEM_LEUCHTKOEDER].name;
        list[num_displayed].idx = FLAG_FISHING_SHINING_BAIT_USED;
        num_displayed++;
    }
    list[num_displayed].text = str_no_bait;
    list[num_displayed].idx = 0;
    num_displayed++;
    return num_displayed;
}

void fishing_print_bait_selection() {
    list_menu_item *list = malloc_and_clear(sizeof(list_menu_item) * 4);
    u16 num_displayed = fishing_build_selection_list(list);
    *var_access(DYN_MULTICHOICE_ITEM_CNT) = num_displayed;
    overworld_script_state.pointer_banks[0] = (u8 *)list;
    if (multichoice(0, 0, 0, true)) {
        overworld_script_halt();
    }
    dprintf("Select %d options\n", num_displayed);
    fmem.gp_state = list;
}

void fishing_execute_bait_selection() {
    list_menu_item *list = (list_menu_item *)fmem.gp_state;
    fishing_build_selection_list(list);
    u16 idx = *var_access(LASTRESULT);
    u16 flag = (u16)list[idx].idx;
    if (flag) {
        setflag(flag);
        *var_access(LASTRESULT) = 1;
    } else {
        clearflag(FLAG_FISHING_BAIT_USED);
        clearflag(FLAG_FISHING_GOLDEN_BAIT_USED);
        clearflag(FLAG_FISHING_SHINING_BAIT_USED);
        *var_access(LASTRESULT) = 0;
    }
    *var_access(DYN_MULTICHOICE_ITEM_CNT) = 0;
    free(fmem.gp_state);
}
