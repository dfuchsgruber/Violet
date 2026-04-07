#include "pokepad/wondertrade.h"
#include "agbmemory.h"
#include "bg.h"
#include "bios.h"
#include "callbacks.h"
#include "color.h"
#include "constants/flags.h"
#include "constants/pokemon_attributes.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "data_structures.h"
#include "debug.h"
#include "dma.h"
#include "fading.h"
#include "flags.h"
#include "io.h"
#include "language.h"
#include "music.h"
#include "oam.h"
#include "overworld/map_control.h"
#include "overworld/pokemon_party_menu.h"
#include "overworld/script.h"
#include "pc.h"
#include "pokepad/pokedex/operator.h"
#include "pokepad/pokepad2.h"
#include "prng.h"
#include "save.h"
#include "stdbool.h"
#include "superstate.h"
#include "text.h"
#include "transparency.h"
#include "types.h"
#include "vars.h"

EWRAM wondertrade_memory_t *wondertrade_memory = NULL;

extern const unsigned short gfx_wondertrade_bg_upperTiles[];
extern const unsigned short gfx_wondertrade_bg_upperMap[];
extern const unsigned short gfx_wondertrade_bg_lowerTiles[];
extern const unsigned short gfx_wondertrade_bg_lowerMap[];
extern const unsigned short gfx_wondertrade_badgesTiles[];
extern const unsigned short gfx_wondertrade_badgesPal[];
extern const unsigned short gfx_wondertrade_bg_upperPal[];
extern const unsigned short gfx_wondertrade_bg_lowerPal[];
extern const LZ77COMPRESSED gfx_wondertrade_progress_barTiles;
extern const LZ77COMPRESSED gfx_wondertrade_progress_barPal;

const graphic graphic_wondertrade_badges = {
    (void *)gfx_wondertrade_badgesTiles,
    0x80 * 4,
    POKEPAD_WONDERTRADE_GFX_TAG_BADGE};

const graphic graphic_wondertrade_progress_bar = {
    (void *)gfx_wondertrade_progress_barTiles,
    0x80 * 4,
    POKEPAD_WONDERTRADE_GFX_TAG_PROGRESS_BAR};

const sprite sprite_wondertrade_badges = {
    0, 0x4000, 0, 0};

const oam_template oam_template_wondertrade_badges = {
    POKEPAD_WONDERTRADE_GFX_TAG_BADGE, POKEPAD_WONDERTRADE_GFX_TAG_BADGE,
    &sprite_wondertrade_badges,
    oam_gfx_anim_table_null,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback};

const sprite sprite_wondertrade_progress_bar = {
    ATTR0_SHAPE_HORIZONTAL, ATTR1_SIZE_32_16, ATTR2_PRIO(2), 0};

const oam_template oam_template_wondertrade_progress_bar = {
    POKEPAD_WONDERTRADE_GFX_TAG_PROGRESS_BAR, POKEPAD_WONDERTRADE_GFX_TAG_PROGRESS_BAR,
    &sprite_wondertrade_progress_bar,
    oam_gfx_anim_table_null,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback};

const tbox_font_colormap wondertrade_fontcolmap = {0, 2, 1, 0};

const tboxdata wondertrade_tboxes[POKEPAD_WONDERTRADE_NUM_TBOXES + 1] = {
    [POKEPAD_WONDERTRADE_TBOX_TITLE] = {0, 10, 1, 10, 2, 15, 1},                                                    // Wondertrade Title
    [POKEPAD_WONDERTRADE_TBOX_LEVEL] = {0, 1, 4, 7, 4, 15, 1 + 10 * 2},                                             // Wondertrade Level Title
    [POKEPAD_WONDERTRADE_TBOX_CNT] = {0, 11, 4, 7, 4, 15, 1 + 10 * 2 + 7 * 4},                                      // Wondertrade Cnt Title
    [POKEPAD_WONDERTRADE_TBOX_NEXT] = {0, 20, 4, 9, 4, 15, 1 + 10 * 2 + 7 * 4 + 7 * 4},                             // Wondertrade Next Title
    [POKEPAD_WONDERTRADE_TBOX_RENDERER] = {0, 1, 16, 28, 4, 13, 1 + 10 * 2 + 7 * 4 + 7 * 4 + 9 * 4},                // Wondertrade print text for renderer
    [POKEPAD_WONDERTRADE_TBOX_TRADE] = {0, 5, 17, 10, 2, 13, 1 + 10 * 2 + 7 * 4 + 7 * 4 + 9 * 4 + 28 * 4},          // Wondertrade Trade
    [POKEPAD_WONDERTRADE_TBOX_BACK] = {0, 19, 17, 10, 2, 14, 1 + 10 * 2 + 7 * 4 + 7 * 4 + 9 * 4 + 28 * 4 + 10 * 2}, // Wondertrade Back
    {0xFF, 0, 0, 0, 0, 0, 0}};

const u16 wondertrade_pokemon_bronze[] = {
    POKEMON_DARTIRI, POKEMON_HORNLIU, POKEMON_STARALILI, POKEMON_SANDAN,
    POKEMON_NIDORANM, POKEMON_NIDORANW, POKEMON_PUMMELUFF, POKEMON_ZUBAT,
    POKEMON_MYRAPLA, POKEMON_DIGDA, POKEMON_ENTON, POKEMON_MAGNETILO,
    POKEMON_TRAUMATO, POKEMON_LEDYBA, POKEMON_WEBARAK, POKEMON_FLABEBE,
    POKEMON_NATU, POKEMON_SNUBBULL, POKEMON_TEDDIURSA, POKEMON_SCHNECKMAG,
    POKEMON_FIFFYEN, POKEMON_ZIGZACHS, POKEMON_WAUMPEL, POKEMON_LOTURZEL,
    POKEMON_SAMURZEL, POKEMON_FRIZELBLIZ, POKEMON_MEDITIE, POKEMON_MOLUNK,
    POKEMON_ENECO, POKEMON_LAMPI, POKEMON_OWEI, 0xFFFF};

const u16 wondertrade_pokemon_silver[] = {
    POKEMON_PIKACHU, POKEMON_VULPIX, POKEMON_KASTADUR, POKEMON_FUKANO,
    POKEMON_ABRA, POKEMON_PORENTA, POKEMON_SLEIMA, POKEMON_SMOGON,
    POKEMON_NEBULAK, POKEMON_SEEPER, POKEMON_MAGBY, POKEMON_TRAGOSSO,
    POKEMON_ELEKID, POKEMON_MARILL, POKEMON_GRIFFEL,
    POKEMON_SHNEBEDECK, POKEMON_NASGNET, POKEMON_WABLU,
    POKEMON_STOLLUNIOR, POKEMON_STERNDU, 0xFFFF};

const u16 wondertrade_pokemon_gold[] = {
    POKEMON_BISASAM, POKEMON_GLUMANDA, POKEMON_SCHIGGY,
    POKEMON_TOGEPI, POKEMON_CLAVION,
    POKEMON_PANZAERON, POKEMON_SICHLOR, POKEMON_ABSOL, POKEMON_VIPITIS,
    POKEMON_GRAMOKLES,
    POKEMON_KECLEON, 0xFFFF};

const u16 wondertrade_pokemon_platinum[] = {
    POKEMON_CHANEIRA, POKEMON_IGNIVOR, POKEMON_EVOLI, POKEMON_LAPRAS,
    POKEMON_BARSCHWA, POKEMON_DRATINI,
    POKEMON_KAUMALAT, POKEMON_KINDWURM, POKEMON_LARVITAR, POKEMON_TANHEL,
    0xFFFF};

const u16 *const wondertrade_pokemon[] = {
    wondertrade_pokemon_bronze,
    wondertrade_pokemon_silver,
    wondertrade_pokemon_gold,
    wondertrade_pokemon_platinum};

const u16 wondertrade_level_requirements[NUM_WONDERTRADE_LEVELS] = {
    [WONDERTRADE_LEVEL_BRONZE] = 0,
    [WONDERTRADE_LEVEL_SILVER] = 5,
    [WONDERTRADE_LEVEL_GOLD] = 25,
    [WONDERTRADE_LEVEL_PLATINUM] = 100};

void wondertrade_color_callback(u8 self) {
    if (wondertrade_memory->error_m || !wondertrade_memory->usable)
        return;
    if (!fading_is_active()) {
        // first we adjust the mode
        if (!big_callbacks[self].params[0]) {
            if (++big_callbacks[self].params[1] == 16) {
                big_callbacks[self].params[0] = 1;
            }
        } else {
            if (!--big_callbacks[self].params[1]) {
                big_callbacks[self].params[0] = 0;
            }
        }

        // Now we do the fading process
        int i;
        color_t overlay = {0x3FFF};
        for (i = 0; i < 32; i++) {
            if ((i & 0xF) == 2 || (i & 0xF) == 4 || (i & 0xF) == 8) {
                if ((wondertrade_memory->cursor == 1 && i >= 16) || (!wondertrade_memory->cursor && i < 16)) {
                    color_t new = color_alpha_blend(pal_restore[i + 13 * 16], overlay, (u8)big_callbacks[self].params[1]);
                    pals[i + 13 * 16] = new;
                } else {
                    pals[i + 13 * 16] = pal_restore[i + 13 * 16];
                }
            }
        }
    }
}

u8 wondertrade_get_level() {
    u16 cnt = *var_access(WONDERTRADE_CNT);
    u8 level = ARRAY_COUNT(wondertrade_level_requirements) - 1;
    while (true) {
        if (cnt >= wondertrade_level_requirements[level])
            break;
        level--;
    }
    return level;
}

u16 wondertrade_get_trades_needed_for_next_level() {
    u8 level = wondertrade_get_level();
    if (level == NUM_WONDERTRADE_LEVELS)
        return 0;
    u16 cnt = *var_access(WONDERTRADE_CNT);
    DEBUG("Level %d, cnt %d, requirement %d\n", level, cnt, wondertrade_level_requirements[level + 1]);
    return (u16)(wondertrade_level_requirements[level + 1] - cnt);
}

void wondertrade_bg_scroll_callback(u8 self) {
    u16 scroll = big_callbacks[self].params[0]--;
    io_set(0x18, scroll);
}

u16 wondertrade_select_pokemon() {
    u8 table = 0; // bronze standard table
    u8 r = (u8)rnd16();
    u8 wondertrade_level = wondertrade_get_level();
    if (wondertrade_level == WONDERTRADE_LEVEL_PLATINUM && !checkflag(WONDERTRADE_MEW_RECEIVED)) {
        setflag(WONDERTRADE_MEW_RECEIVED);
        return POKEMON_MEW;
    }
    switch (wondertrade_level) {
    case WONDERTRADE_LEVEL_PLATINUM:
        if (r < 16)
            table++;
        FALL_THROUGH;
    case WONDERTRADE_LEVEL_GOLD:
        if (r < 64)
            table++;
        FALL_THROUGH;
    case WONDERTRADE_LEVEL_SILVER:
        if (r < 128)
            table++;
        break;
    }
    u32 table_size = 0;
    while (wondertrade_pokemon[table][table_size] != 0xFFFF)
        table_size++;
    int *probabilities = malloc_and_clear(table_size * sizeof(int));
    for (u32 i = 0; i < table_size; i++) {
        if (!pokedex_operator(wondertrade_pokemon[table][i], POKEDEX_CAUGHT, true))
            probabilities[i] += wondertrade_level;
        if (!pokedex_operator(wondertrade_pokemon[table][i], POKEDEX_SEEN, true))
            probabilities[i] += wondertrade_level;
    }
    u32 idx = softmax_choice(probabilities, table_size, 0, NUM_WONDERTRADE_LEVELS - 1, rnd16);
    return wondertrade_pokemon[table][idx];
}

u16 wondertrade_next_seed() {
    return (u16)((rnd16() & 511) / (wondertrade_get_level() + 1));
}

u32 tid_by_ot_name(const u8 *ot_name) {
    u32 tid = 1;
    int i = 0;
    while (ot_name[i] != 0xFF) {
        tid *= ot_name[i++];
    }
    return tid;
}

static const u8 str_wodka[] = PSTRING("Wodka");

void wondertrade_spawn_pokemon() {
    u16 species = wondertrade_select_pokemon();
    bool female_ot = rnd16() % 1;
    const u8 *ot_name = species == POKEMON_MEW ? str_wodka : person_names[female_ot][rnd16() % 128];
    DEBUG("Spawned wondertrade mon %d with OT @ 0x%x\n", species, ot_name);
    u32 tid = tid_by_ot_name(ot_name);
    pid_t p = {.value = 0};
    pokemon_spawn_by_seed_algorithm(&opponent_pokemon[0], species, 5, 32, false, p,
                                    true, tid, wondertrade_next_seed, NULL);
    pokemon_set_attribute(&opponent_pokemon[0], ATTRIBUTE_OT_NAME, ot_name);
    pokemon_set_attribute(opponent_pokemon + 0, ATTRIBUTE_OT_GENDER, &female_ot);
}

bool wondertrade_can_pokemon_be_sent() {
    box_pokemon *p = pokemon_get_by_box(*var_access(0x8004), *var_access(0x8005));
    if (box_pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0)) {
        return false;
    }
    return !pokemon_knows_hm(p);
}

static void wondertrade_continuation_after_trade() {
    // Reswap the player's first pokemon with the one on the box
    memcpy(pokemon_get_by_box(*var_access(0x8000), *var_access(0x8001)), player_pokemon, sizeof(box_pokemon));
    memcpy(player_pokemon, opponent_pokemon + 1, sizeof(pokemon));
    map_reload_continuation_resume_script();
}

void wondertrade_callback_after_selection() {
    int from_outdoor = gp_stack_pop();
    if (*var_access(0x8006) == false) {
        if (from_outdoor) {
            callback1_set(map_reload);
        } else {
            callback1_set(pokepad2_callback_initialize);
        }
    } else {
        if (wondertrade_can_pokemon_be_sent()) {
            wondertrade_spawn_pokemon();
            if (*var_access(WONDERTRADE_CNT < 9999)) {
                (*var_access(WONDERTRADE_CNT))++;
            }
            *var_access(WONDERTRADE_STEPS_TO_ENABLE) = 0;
            *var_access(0x8000) = *var_access(0x8004);
            *var_access(0x8001) = *var_access(0x8005);
            *var_access(0x8004) = 0;
            *var_access(0x8005) = 0;
            // Temporarily swap out the first mon of the players party, as this will be traded away
            memcpy(opponent_pokemon + 1, player_pokemon, sizeof(pokemon));
            // Fetch the selected pokemon from the box
            memcpy(player_pokemon, pokemon_get_by_box(*var_access(0x8000), *var_access(0x8001)), sizeof(box_pokemon));
            pokemon_calculate_stats(player_pokemon);
            map_reload_continuation = wondertrade_continuation_after_trade;
            callback1_set(ingame_trade_init_callback);

        } else {
            wondertrade_memory = (wondertrade_memory_t *)malloc(sizeof(wondertrade_memory_t));
            wondertrade_memory->from_outdoor = from_outdoor;
            wondertrade_memory->error_m = true;
            wondertrade_memory->usable = true;
            wondertrade_memory->cursor = 0;
            wondertrade_init_components();
            wondertrade_memory->color_cb = big_callback_new(wondertrade_color_callback, 0);
            io_set(0x50, 0);
            io_set(0x52, 0);
            io_set(0x54, 0);
            io_bic(0, 0x6000);
            callback1_set(wondertrade_show_components);
            vblank_handler_set(generic_vblank_handler);
        }
        // now we need to spawn a pokemon for the wondertrade
    }
}

void wondertrade_callback_init_selection() {
    generic_callback1();
    if (!fading_is_active()) {
        fading_control.buffer_transfer_disabled = true;
        gp_stack_push(wondertrade_memory->from_outdoor);
        wondertrade_free_components();
        pc_initialize(PC_MODE_SELECT);
        *var_access(0x8006) = 0;
        pc_selection_context = PC_SELECTION_CONTEXT_CHOOSE_WONDERTRADE;
    }
}

void wondertrade_callback_idle() {
    generic_callback1();
    if (!fading_is_active()) {
        if (wondertrade_memory->usable && !wondertrade_memory->error_m) {
            if (super.keys_new.keys.right || super.keys_new.keys.left) {
                play_sound(5);
                wondertrade_memory->cursor ^= 1;
            } else if (super.keys_new.keys.B) {
                play_sound(5);
                callback1_set(wondertrade_callback_free_components_and_return);
                fadescreen_all(1, 0);
            } else if (super.keys_new.keys.A) {
                if (wondertrade_memory->cursor) {
                    callback1_set(wondertrade_callback_free_components_and_return);
                } else {
                    callback1_set(wondertrade_callback_init_selection);
                }
                play_sound(5);
                fadescreen_all(1, 0);
            }
        } else {
            if (super.keys_new.keys.A || super.keys_new.keys.B) {
                // return to pokepad
                play_sound(5);
                callback1_set(wondertrade_callback_free_components_and_return);
                fadescreen_all(1, 0);
            }
        }
    }
}

void wondertrade_show_components() {
    bg_sync_display_and_show(0);
    bg_sync_display_and_show(1);
    bg_sync_display_and_show(2);
    bg_display_sync();
    if (wondertrade_memory->usable)
        wondertrade_memory->scroll_cb = big_callback_new(wondertrade_bg_scroll_callback, 10);
    fadescreen_all(0, 0);
    callback1_set(wondertrade_callback_idle);
}

const bg_config wondertrade_bg_cnfgs[] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 29, 0, 0, 1},
    {2, 1, 27, 0, 0, 2}};

void wondertrade_free_components() {

    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    oam_free(&oams[wondertrade_memory->oam_badge]);
    tbox_free_all();
    free(wondertrade_memory);
}

void wondertrade_callback_free_components_and_return() {
    generic_callback1();
    if (!fading_is_active()) {
        if (!wondertrade_memory->from_outdoor) {
            callback1_set(pokepad2_callback_initialize);
        } else {
            callback1_set(map_reload);
        }
        wondertrade_free_components();
    }
}

void wondertrade_init_components() {
    oam_reset();
    big_callback_delete_all();
    fading_cntrl_reset();
    oam_palette_allocation_reset();
    dma0_reset_callback();
    vblank_handler_set(generic_vblank_handler);
    bg_reset(0);
    bg_setup(0, wondertrade_bg_cnfgs, 3);

    // now we init the tilesets
    void *bg1map = (void *)malloc(0x800);
    void *bg2map = (void *)malloc(0x800);
    void *bg0map = (void *)malloc_and_clear(0x800);
    bg_set_tilemap(0, bg0map);
    bg_set_tilemap(1, bg1map);
    bg_set_tilemap(2, bg2map);

    tbox_sync_with_virtual_bg_and_init_all(wondertrade_tboxes);

    lz77uncompvram(gfx_wondertrade_bg_upperTiles, (void *)0x06000000);
    lz77uncompwram(gfx_wondertrade_bg_upperMap, bg1map);
    lz77uncompvram(gfx_wondertrade_bg_lowerTiles, (void *)0x06004000);
    lz77uncompwram(gfx_wondertrade_bg_lowerMap, bg2map);

    // Now we init the texts
    u8 str_wondertrade[] = LANGDEP(PSTRING("Wundertausch"), PSTRING("Wondertrade"));
    tbox_flush_set(POKEPAD_WONDERTRADE_TBOX_TITLE, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_TITLE);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_TITLE, 2, 0, 0, 0, 0, &wondertrade_fontcolmap, 0x0, str_wondertrade); // str_pokepad_wondertrade_ref

    // Now we spawn the level
    u8 str_level[] = LANGDEP(PSTRING("Level"), PSTRING("Level"));
    tbox_flush_set(POKEPAD_WONDERTRADE_TBOX_LEVEL, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_LEVEL);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_LEVEL, 2, 6, 0, 0, 0, &wondertrade_fontcolmap, 0x0, str_level);

    u8 *wondertrade_lv_string;
    u8 str_bronze[] = LANGDEP(PSTRING("Bronze"), PSTRING("Bronze"));
    u8 str_silver[] = LANGDEP(PSTRING("Silber"), PSTRING("Silver"));
    u8 str_gold[] = LANGDEP(PSTRING("Gold"), PSTRING("Gold"));
    u8 str_platinum[] = LANGDEP(PSTRING("Platin"), PSTRING("Platinum"));
    u8 lvl = wondertrade_get_level();
    switch (lvl) {
    case 0:
        wondertrade_lv_string = str_bronze;
        break;
    case 1:
        wondertrade_lv_string = str_silver;
        break;
    case 2:
        wondertrade_lv_string = str_gold;
        break;
    default:
        wondertrade_lv_string = str_platinum;
        break;
    }
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_LEVEL, 2, 6, 14, 0, 0, &wondertrade_fontcolmap, 0x0, wondertrade_lv_string);

    // Anzahl
    u8 str_anzahl[] = LANGDEP(PSTRING("Getauscht"), PSTRING("Traded"));
    tbox_flush_set(POKEPAD_WONDERTRADE_TBOX_CNT, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_CNT);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_CNT, 2, 4, 0, 0, 0, &wondertrade_fontcolmap, 0x0, str_anzahl);

    u16 cnt = *var_access(WONDERTRADE_CNT);
    itoa(strbuf, cnt, ITOA_PAD_SPACES, 3);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_CNT, 2, 38, 16, 0, 0, &wondertrade_fontcolmap, 0x0, strbuf);

    // Neachster Lv.
    u8 str_next[] = LANGDEP(PSTRING("Nächstes Lv."), PSTRING("Next Level"));
    tbox_flush_set(POKEPAD_WONDERTRADE_TBOX_NEXT, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_NEXT);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_NEXT, 2, 4, 0, 0, 0, &wondertrade_fontcolmap, 0x0, str_next);

    u8 *strbuf2 = strbuf + 10; // We use the same strbuf since we know the number will not exceed 9 chars
    cnt = wondertrade_get_trades_needed_for_next_level();
    u8 str_none[] = PSTRING("---");
    if (cnt > 0)
        itoa(strbuf2, cnt, 0, 3);
    else
        strcpy(strbuf2, str_none);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_NEXT, 2, 4, 16, 0, 0, &wondertrade_fontcolmap, 0x0, strbuf2);

    // now we spawn the oam for the badges
    oam_load_graphic(&graphic_wondertrade_badges);
    oam_load_graphic(&graphic_wondertrade_progress_bar);
    pal_decompress(gfx_wondertrade_badgesPal, (u16)((16 + oam_allocate_palette(POKEPAD_WONDERTRADE_GFX_TAG_BADGE)) * 16), 32);
    pal_decompress(gfx_wondertrade_progress_barPal, (u16)((16 + oam_allocate_palette(POKEPAD_WONDERTRADE_GFX_TAG_PROGRESS_BAR)) * 16), 32);
    wondertrade_memory->oam_badge = oam_new_forward_search(&oam_template_wondertrade_badges, 66, 51, 0);
    // now we change to the proper graphic
    int displacement = 0;
    switch (lvl) {
    case 3:
        displacement += 4;
        FALL_THROUGH;
    case 2:
        displacement += 4;
        FALL_THROUGH;
    case 1:
        displacement += 4;
        break;
    }
    u16 attr2 = oams[wondertrade_memory->oam_badge].final_oam.attr2;
    u16 base = (u16)((attr2 & 0x3FF) + displacement);
    attr2 = (u16)((attr2 & (~0x3FF)) | base);
    oams[wondertrade_memory->oam_badge].final_oam.attr2 = attr2;

    s16 progress_bar_dx;
    if (lvl == NUM_WONDERTRADE_LEVELS)
        progress_bar_dx = -32;
    else {
        int remaining = wondertrade_level_requirements[lvl + 1] - wondertrade_level_requirements[lvl];
        int current = *var_access(WONDERTRADE_CNT) - wondertrade_level_requirements[lvl];
        progress_bar_dx = (s16)(current * 32 / remaining);
    }

    wondertrade_memory->oam_idx_progress_bar = oam_new_forward_search(
        &oam_template_wondertrade_progress_bar, (s16)220 - 32 + progress_bar_dx, 53, 1);

    // Now we spawn either the not possible text or the two selections
    if (wondertrade_memory->usable) {
        if (wondertrade_memory->error_m) {
            u8 str_error[] = LANGDEP(PSTRING("Diese Pokémon kennt eine\nVm oder ist ein Ei."),
                                     PSTRING("This Pokémon knows a hm\nor is an egg."));
            tbox_flush_set(POKEPAD_WONDERTRADE_TBOX_RENDERER, 0);
            tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_RENDERER);
            tbox_print_string(POKEPAD_WONDERTRADE_TBOX_RENDERER, 2, 0, 0, 0, 0, &wondertrade_fontcolmap, 0x0, str_error);
        } else {
            // We spawn the two options
            u8 str_do[] = LANGDEP(PSTRING("Tauschen"), PSTRING("Trade"));
            tbox_flush_set(POKEPAD_WONDERTRADE_TBOX_TRADE, 0);
            tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_TRADE);
            tbox_print_string(POKEPAD_WONDERTRADE_TBOX_TRADE, 2, 0, 0, 0, 0, &wondertrade_fontcolmap, 0x0, str_do);

            u8 str_back[] = LANGDEP(PSTRING("Zurück"), PSTRING("Back"));
            tbox_flush_set(POKEPAD_WONDERTRADE_TBOX_BACK, 0);
            tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_BACK);
            tbox_print_string(POKEPAD_WONDERTRADE_TBOX_BACK, 2, 0, 0, 0, 0, &wondertrade_fontcolmap, 0x0, str_back);
        }
    } else {
        // spawn the not possible text
        wondertrade_buffer_steps();
        string_decrypt(strbuf, str_wondertrade_not_possible_script);
        tbox_flush_set(POKEPAD_WONDERTRADE_TBOX_RENDERER, 0);
        tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_RENDERER);
        tbox_print_string(POKEPAD_WONDERTRADE_TBOX_RENDERER, 2, 0, 0, 0, 0, &wondertrade_fontcolmap, 0x0, strbuf);
    }

    // scroll
    bg_virtual_map_displace(0, 0, 0);
    bg_virtual_set_displace(0, 0, 0);
    bg_virtual_map_displace(1, 0, 0);
    bg_virtual_set_displace(1, 0, 0);
    bg_virtual_map_displace(2, 0, 0);
    bg_virtual_set_displace(2, 0, 0);

    // pal
    pal_decompress(gfx_wondertrade_bg_upperPal, 0, 32);
    pal_decompress(gfx_wondertrade_bg_lowerPal, 1 * 16, 32);
    pal_copy(tbox_palette_transparent, 15 * 16, 32);
    if (!wondertrade_memory->usable) {
        // greyscale all pals
        int i;
        color_t black = {0};
        for (i = 0; i < 512; i++) {
            color_t n = color_to_grayscale(pal_restore[i]);
            n = color_alpha_blend(n, black, 11);
            pal_restore[i] = n;
        }
    }
    pal_copy(tbox_palette_transparent, 13 * 16, 32);
    pal_copy(tbox_palette_transparent, 14 * 16, 32);

    pal_set_all_to_black();

    bg_virtual_sync(0);
    bg_virtual_sync(1);
    bg_virtual_sync(2);
}

void wondertrade_init_callback() {
    generic_callback1();
    if (!fading_is_active()) {
        if (wondertrade_memory->from_outdoor) {
            overworld_free();
        } else {
            pokepad2_free();
        }
        // Now we initilize the graphic components
        wondertrade_init_components();
        wondertrade_memory->color_cb = big_callback_new(wondertrade_color_callback, 0);
        io_set(0x50, 0);
        io_set(0x52, 0);
        io_set(0x54, 0);
        io_bic(0, 0x6000);
        callback1_set(wondertrade_show_components);
    }
}

void wondertrade_buffer_steps() {
    u8 *buffer0 = (u8 *)0x02021CD0;
    itoa(buffer0, *var_access(WONDERTRADE_STEPS_TO_ENABLE), 0, 3);
}

void wondertrade_init(bool is_outdoor) {
    bool is_usable = *var_access(WONDERTRADE_STEPS_TO_ENABLE) >= 250;
    if (is_outdoor && !is_usable) {
        wondertrade_buffer_steps();
        overworld_script_init(script_wondertrade_failure);
        return;
    }
    overworld_rain_sound_fade_out();
    fadescreen_all(1, 0);
    wondertrade_memory = (wondertrade_memory_t *)malloc(sizeof(wondertrade_memory_t));
    wondertrade_memory->from_outdoor = is_outdoor;
    wondertrade_memory->error_m = false;
    wondertrade_memory->usable = is_usable;
    wondertrade_memory->cursor = 0;
    callback1_set(wondertrade_init_callback);
}
