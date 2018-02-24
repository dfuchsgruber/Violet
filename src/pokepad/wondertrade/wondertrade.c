#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "pokepad.h"
#include "save.h"
#include "bg.h"
#include "utils.h"
#include "color.h"
#include "callbacks.h"
#include "transparency.h"
#include "gfx.h"
#include "oams.h"
#include "superstate.h"
#include "utils.h"
#include "text.h"
#include "pokemon.h"
#include "basestats.h"

extern const unsigned short gfx_wondertrade_bg_upperTiles[];
extern const unsigned short gfx_wondertrade_bg_upperMap[];
extern const unsigned short gfx_wondertrade_bg_lowerTiles[];
extern const unsigned short gfx_wondertrade_bg_lowerMap[];
extern const unsigned short gfx_wondertrade_badgesPal[];
extern const unsigned short gfx_wondertrade_bg_upperPal[];
extern const unsigned short gfx_wondertrade_bg_lowerPal[];

u8 wondertrade_fontcolmap[] = {0, 2, 1, 0};

tboxdata wondertrade_tboxes[] = {
    {0, 10, 1, 10, 2, 15, 1}, //Wondertrade Title
    {0, 1, 4, 5, 2, 15, 21}, //Wondertrade Level Title
    {0, 2, 6, 5, 2, 15, 31}, //Wondertrade Level Text
    {0, 11, 4, 5, 2, 15, 41}, //Wondertrade Cnt Title
    {0, 12, 6, 5, 2, 15, 51}, //Wondertrade Cnt Text
    {0, 19, 4, 7, 2, 15, 61}, //Wondertrade Next Title
    {0, 21, 6, 4, 2, 15, 75}, //Wondertrade Next Text
    {0, 1, 16, 28, 4, 13, 95}, //Wondertrade print text for renderer
    {0, 5, 17, 10, 2, 13, 187}, //Wondertrade Trade
    {0, 19, 17, 10, 2, 14, 207}, //Wondertrade Back
    {0xFF, 0, 0, 0, 0, 0, 0}
};


u16 wondertrade_pokemon_bronze[] = {
    POKEMON_DARTIRI, POKEMON_HORNLIU, POKEMON_STARALILI, POKEMON_SANDAN,
    POKEMON_NIDORANM, POKEMON_NIDORANW, POKEMON_PUMMELUFF, POKEMON_ZUBAT,
    POKEMON_MYRAPLA, POKEMON_DIGDA, POKEMON_ENTON, POKEMON_MAGNETILO,
    POKEMON_TRAUMATO, POKEMON_LEDYBA, POKEMON_WEBARAK, POKEMON_FLABEBE,
    POKEMON_NATU, POKEMON_SNUBBULL, POKEMON_TEDDIURSA, POKEMON_SCHNECKMAG,
    POKEMON_FIFFYEN, POKEMON_ZIGZACHS, POKEMON_WAUMPEL, POKEMON_LOTURZEL,
    POKEMON_SAMURZEL, POKEMON_FRIZELBLIZ, POKEMON_MEDITIE, POKEMON_SCHLUPPUCK,
    POKEMON_ENECO, POKEMON_LAMPI, POKEMON_OWEI, 0xFFFF
};

u16 wondertrade_pokemon_silver[] = {
    POKEMON_PIKACHU, POKEMON_VULPIX, POKEMON_KASTADUR, POKEMON_FUKANO,
    POKEMON_ABRA, POKEMON_PORENTA, POKEMON_SLEIMA, POKEMON_SMOGON,
    POKEMON_NEBULAK, POKEMON_SEEPER, POKEMON_MAGBY, POKEMON_TRAGOSSO,
    POKEMON_ELEKID, POKEMON_MARILL, POKEMON_GRIFFEL,
    POKEMON_SHNEBEDECK, POKEMON_NASGNET, POKEMON_WABLU,
    POKEMON_STOLLUNIOR, POKEMON_STERNDU, 0xFFFF
};

u16 wondertrade_pokemon_gold[] = {
    POKEMON_BISASAM, POKEMON_GLUMANDA, POKEMON_SCHIGGY,
    POKEMON_TOGEPI, POKEMON_CLAVION,
    POKEMON_PANZAERON,
    POKEMON_KECLEON, 0xFFFF
};

u16 wondertrade_pokemon_platinum[] = {
    POKEMON_CHANEIRA, POKEMON_IGNIVOR, POKEMON_EVOLI, POKEMON_LAPRAS,
    POKEMON_BARSCHWA, POKEMON_ABSOL, POKEMON_SICHLOR, 0xFFFF
};

u16 *wondertrade_pokemon[] = {
    wondertrade_pokemon_bronze,
    wondertrade_pokemon_silver,
    wondertrade_pokemon_gold,
    wondertrade_pokemon_platinum
};

void wondertrade_color_callback(u8 self) {
    if (fmem->wtrade_mem->error_m || !fmem->wtrade_mem->usable)
        return;
    if (!is_fading()) {
        //first we adjust the mode
        if (!big_callbacks[self].params[0]) {
            if (++big_callbacks[self].params[1] == 16) {
                big_callbacks[self].params[0] = 1;
            }
        } else {
            if (!--big_callbacks[self].params[1]) {
                big_callbacks[self].params[0] = 0;
            }
        }

        //Now we do the fading process
        int i;
        color overlay = {0x3FFF};
        for (i = 0; i < 32; i++) {
            if ((i & 0xF) == 2 || (i & 0xF) == 4 || (i & 0xF) == 8) {
                if ((fmem->wtrade_mem->cursor == 1 && i >= 16) || (!fmem->wtrade_mem->cursor && i < 16)) {
                    color new = alpha_blend(pal_restore[i + 13 * 16], overlay, (u8) big_callbacks[self].params[1]);
                    pals[i + 13 * 16] = new;
                } else {
                    pals[i + 13 * 16] = pal_restore[i + 13 * 16];
                }
            }
        }
    }
}

u8 wondertrade_get_level() {
    u16 cnt = *vardecrypt(VAR_POKEPAD_WONDERTRADE_CNT);
    if (cnt < 10) {
        return 0;
    } else if (cnt < 50) {
        return 1;
    } else if (cnt < 150) {
        return 2;
    } else {
        return 3;
    }
}

void wondertrade_bg_scroll_callback(u8 self) {
    u16 scroll = big_callbacks[self].params[0]--;
    set_io(0x18, scroll);
}

u16 wondertrade_select_pokemon() {
    u8 table = 0; //bronze standard table
    u8 r = (u8) rnd16();
    switch (wondertrade_get_level()) {
        case 3:
            if (r < 16)
                table++;
        case 2:
            if (r < 64)
                table++;
        case 1:
            if (r < 128)
                table++;
            break;
    }
    if (table > 1 && r < 2 && !checkflag(POKEPAD_WONDERTRADE_MEW_FLAG)) {
        setflag(POKEPAD_WONDERTRADE_MEW_FLAG);
        return POKEMON_MEW;
    }
    u32 table_size = 0;
    while (wondertrade_pokemon[table][table_size] != 0xFFFF)
        table_size++;
    return wondertrade_pokemon[table][rnd16() % table_size];
}

u16 wondertrade_next_seed() {
    return (u16) ((rnd16() & 511) / (wondertrade_get_level() + 1));
}

void wondertrade_spawn_pokemon() {
    u16 species = wondertrade_select_pokemon();

    //first we find a OT name
    u8 *ot_name = species == POKEMON_MEW ? str_wondertrade_name0 :
            wondertrade_ot_names[rnd16() % 36];

    u32 tid = 1;
    int i = 0;
    while (ot_name[i] != 0xFF)
        tid *= ot_name[i++];

    pokemon_spawn_by_seed_algorithm(&opponent_pokemon[0], species, 5, 0, true, tid, wondertrade_next_seed);

    //at last we define ot
    set_pokemons_attribute(&opponent_pokemon[0], ATTRIBUTE_OT_NAME, ot_name);
}

bool wondertrade_can_pokemon_be_sent() {
    u16 *result = (u16*) 0x020370C0;
    if (get_pokemons_attribute(&player_pokemon[*result], ATTRIBUTE_IS_EGG, 0)) {
        return false;
    }
    return !pokemon_knows_hm(&player_pokemon[*result]);
}

void wondertrade_callback_after_selection() {
    u16 *result = (u16*) 0x020370C0;
    u16 *tmp_from_outdoor = (u16*) 0x020370C2;
    if (*result >= 6) {
        if (*tmp_from_outdoor) {
            set_callback1(map_reload);
        } else {
            set_callback1(pokepad_callback_init);
        }
    } else {
        if (wondertrade_can_pokemon_be_sent()) {
            wondertrade_spawn_pokemon();
            if (*vardecrypt(VAR_POKEPAD_WONDERTRADE_CNT < 9999)) {
                (*vardecrypt(VAR_POKEPAD_WONDERTRADE_CNT))++;
            }
            *vardecrypt(VAR_POKEPAD_WONDERTRADE_STEP_CNT) = 0;
            *tmp_from_outdoor = *result; //var8005 <- var8004
            //now we initialize the ingame trade
            void **unkown_func_ptr = (void**) 0x3004F70;
            *unkown_func_ptr = unkown_ingame_trade_func;
            set_callback1(ingame_trade_init_callback);

        } else {
            fmem->wtrade_mem = (wondertrade_memory*) malloc(sizeof (wondertrade_memory));
            fmem->wtrade_mem->from_outdoor = (bool) (*tmp_from_outdoor);
            fmem->wtrade_mem->error_m = true;
            fmem->wtrade_mem->usable = true;
            fmem->wtrade_mem->cursor = 0;
            wondertrade_init_components();
            fmem->wtrade_mem->color_cb = spawn_big_callback(wondertrade_color_callback, 0);
            set_io(0x50, 0);
            set_io(0x52, 0);
            set_io(0x54, 0);
            bic_io(0, 0x6000);
            set_callback1(wondertrade_show_components);
        }
        //now we need to spawn a pokemon for the wondertrade
    }
}

void wondertrade_callback_init_selection() {
    cb1handling();
    if (!is_fading()) {
        u8 *flag = (u8*) 0x02037AC0;
        *flag |= 0x80;
        void **launch_func = (void **) 0x03004F74;
        *launch_func = (void**) 0x08128435;
        pokemenu_init(3, 0, 0xB, 0, 0, (void (*)())0x0811FB5D, wondertrade_callback_after_selection); // <---------- This init function is the resume callback from selection
        u16 *tmp_from_outdoor = (u16*) 0x020370C2;
        *tmp_from_outdoor = fmem->wtrade_mem->from_outdoor;
        wondertrade_free_components();
    }
}

void wondertrade_callback_idle() {
    cb1handling();
    if (!is_fading()) {
        if (fmem->wtrade_mem->usable && !fmem->wtrade_mem->error_m) {
            if (super->keys_new.keys.right || super->keys_new.keys.left) {
                sound(5);
                fmem->wtrade_mem->cursor ^= 1;
            } else if (super->keys_new.keys.B) {
                sound(5);
                set_callback1(wondertrade_callback_free_components_and_return);
                init_fadescreen(1, 0);
            } else if (super->keys_new.keys.A) {
                if (fmem->wtrade_mem->cursor) {
                    set_callback1(wondertrade_callback_free_components_and_return);
                } else {
                    set_callback1(wondertrade_callback_init_selection);
                }
                sound(5);
                init_fadescreen(1, 0);
            }
        } else {
            if (super->keys_new.keys.A || super->keys_new.keys.B) {
                //return to pokepad
                sound(5);
                set_callback1(wondertrade_callback_free_components_and_return);
                init_fadescreen(1, 0);
            }
        }
    }
}

void wondertrade_show_components() {
    bg_sync_display_and_show(0);
    bg_sync_display_and_show(1);
    bg_sync_display_and_show(2);
    bg_display_sync();
    if (fmem->wtrade_mem->usable)
        fmem->wtrade_mem->scroll_cb = spawn_big_callback(wondertrade_bg_scroll_callback, 10);
    init_fadescreen(0, 0);
    set_callback1(wondertrade_callback_idle);
}

bg_config wondertrade_bg_cnfgs [] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 29, 0, 0, 1},
    {2, 1, 27, 0, 0, 2}
};

void wondertrade_free_components() {

    free(bg_get_tilemap(0));
    free(bg_get_tilemap(1));
    free(bg_get_tilemap(2));
    oam_despawn(&oams[fmem->wtrade_mem->oam_badge]);
    free_all_tboxes();
    free(fmem->wtrade_mem);
}

void wondertrade_callback_free_components_and_return() {
    cb1handling();
    if (!is_fading()) {
        if (!fmem->wtrade_mem->from_outdoor) {
            set_callback1(pokepad_callback_init);
        } else {
            set_callback1(map_reload);
        }
        wondertrade_free_components();
    }
}

void wondertrade_init_components() {
    oam_reset();
    remove_all_big_callbacks();
    pal_fade_cntrl_reset();
    pal_allocation_reset();
    //dma0_cb_reset();
    set_callback3(NULL);
    bg_reset(0);
    bg_setup(0, wondertrade_bg_cnfgs, 3);

    //now we init the tilesets
    void *bg1map = (void*) malloc(0x800);
    void *bg2map = (void*) malloc(0x800);
    void *bg0map = (void*) cmalloc(0x800);
    bg_set_tilemap(0, bg0map);
    bg_set_tilemap(1, bg1map);
    bg_set_tilemap(2, bg2map);

    tbox_sync_with_virtual_bg_and_init_all(wondertrade_tboxes);

    lz77uncompvram(gfx_wondertrade_bg_upperTiles, (void*) 0x06000000);
    lz77uncompwram(gfx_wondertrade_bg_upperMap, bg1map);
    lz77uncompvram(gfx_wondertrade_bg_lowerTiles, (void*) 0x06004000);
    lz77uncompwram(gfx_wondertrade_bg_lowerMap, bg2map);

    //Now we init the texts
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_TITLE, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_TITLE);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_TITLE, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_pokepad_wondertrade); //str_pokepad_wondertrade_ref

    //Now we spawn the level
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_LEVEL_H, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_LEVEL_H);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_LEVEL_H, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_wondertrade_level);

    tbox_flush(POKEPAD_WONDERTRADE_TBOX_LEVEL_T, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_LEVEL_T);
    u8 *wondertrade_lv_string;
    u8 lvl = wondertrade_get_level();
    switch (lvl) {
        case 0:
            wondertrade_lv_string = str_wondertrade_bronze;
            break;
        case 1:
            wondertrade_lv_string = str_wondertrade_silver;
            break;
        case 2:
            wondertrade_lv_string = str_wondertrade_gold;
            break;
        default:
            wondertrade_lv_string = str_wondertrade_platin;
            break;
    }
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_LEVEL_T, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, wondertrade_lv_string);

    //Anzahl
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_CNT_H, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_CNT_H);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_CNT_H, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_wondertrade_anzahl);

    tbox_flush(POKEPAD_WONDERTRADE_TBOX_CNT_T, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_CNT_T);
    u8 *strbuf = (u8*) 0x02021D18;
    u16 cnt = *vardecrypt(VAR_POKEPAD_WONDERTRADE_CNT);
    itoa(strbuf, cnt, 0, 3);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_CNT_T, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, strbuf);

    //Neachster Lv.
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_NEXT_H, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_NEXT_H);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_NEXT_H, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_wondertrade_next);

    u8 *strbuf2 = (u8*) (0x02021D18 + 10); //We use the same strbuf since we know the number will not exceed 9 chars
    tbox_flush(POKEPAD_WONDERTRADE_TBOX_NEXT_T, 0);
    tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_NEXT_T);
    switch (lvl) {
        case 0:
            cnt = (u16) (10 - cnt);
            break;
        case 1:
            cnt = (u16) (50 - cnt);
            break;
        case 2:
            cnt = (u16) (150 - cnt);
            break;
        default:
            cnt = 0xFFFF;
            break;
    }
    if (cnt != 0xFFFF)
        itoa(strbuf2, cnt, 0, 3);
    else
        strcpy(strbuf2, str_wondertrade_none);
    tbox_print_string(POKEPAD_WONDERTRADE_TBOX_NEXT_T, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, strbuf2);

    //now we spawn the oam for the badges
    load_and_alloc_obj_vram_lz77(&graphic_wondertrade_badges);
    u8 bpal = allocate_obj_pal(0xA004);
    pal_load_comp(gfx_wondertrade_badgesPal, (u16) ((16 + bpal)*16), 32);
    fmem->wtrade_mem->oam_badge = generate_oam_forward_search(&oam_template_wondertrade_badges, 64, 50, 0);
    //now we change to the proper graphic
    int displacement = 0;
    switch (lvl) {
        case 3:
            displacement += 4;
        case 2:
            displacement += 4;
        case 1:
            displacement += 4;
            break;
    }
    u16 attr2 = oams[fmem->wtrade_mem->oam_badge].final_oam.attr2;
    u16 base = (u16) ((attr2 & 0x3FF) + displacement);
    attr2 = (u16) ((attr2 & (~0x3FF)) | base);
    oams[fmem->wtrade_mem->oam_badge].final_oam.attr2 = attr2;

    //Now we spawn either the not possible text or the two selections
    if (fmem->wtrade_mem->usable) {
        if (fmem->wtrade_mem->error_m) {
            tbox_flush(POKEPAD_WONDERTRADE_TBOX_RENDERER, 0);
            tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_RENDERER);
            tbox_print_string(POKEPAD_WONDERTRADE_TBOX_RENDERER, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_wondertrade_error_m);
        } else {
            //We spawn the two options
            tbox_flush(POKEPAD_WONDERTRADE_TBOX_TRADE, 0);
            tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_TRADE);
            tbox_print_string(POKEPAD_WONDERTRADE_TBOX_TRADE, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_wondertrade_do);

            tbox_flush(POKEPAD_WONDERTRADE_TBOX_BACK, 0);
            tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_BACK);
            tbox_print_string(POKEPAD_WONDERTRADE_TBOX_BACK, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, str_wondertrade_back);
        }
    } else {
        //spawn the not possible text
        wondertrade_load_steps_into_buffer();
        string_decrypt(strbuf, str_wondertrade_not_possible_script);
        tbox_flush(POKEPAD_WONDERTRADE_TBOX_RENDERER, 0);
        tbox_tilemap_draw(POKEPAD_WONDERTRADE_TBOX_RENDERER);
        tbox_print_string(POKEPAD_WONDERTRADE_TBOX_RENDERER, 2, 0, 0, 0, 0, wondertrade_fontcolmap, 0x0, strbuf);

    }

    //scroll
    bg_virtual_map_displace(0, 0, 0);
    bg_virtual_set_displace(0, 0, 0);
    bg_virtual_map_displace(1, 0, 0);
    bg_virtual_set_displace(1, 0, 0);
    bg_virtual_map_displace(2, 0, 0);
    bg_virtual_set_displace(2, 0, 0);

    //pal
    pal_load_comp(gfx_wondertrade_bg_upperPal, 0, 32);
    pal_load_comp(gfx_wondertrade_bg_lowerPal, 1 * 16, 32);
    pal_load_uncomp(transparency_black_box_pals, 15 * 16, 32);
    if (!fmem->wtrade_mem->usable) {
        //greyscale all pals
        int i;
        color black = {0};
        for (i = 0; i < 512; i++) {
            color n = greyscale(pal_restore[i]);
            n = alpha_blend(n, black, 11);
            pal_restore[i] = n;
        }
    }
    pal_load_uncomp(transparency_black_box_pals, 13 * 16, 32);
    pal_load_uncomp(transparency_black_box_pals, 14 * 16, 32);

    pal_set_all_to_black();

    bg_virtual_sync(0);
    bg_virtual_sync(1);
    bg_virtual_sync(2);

}

void wondertrade_init_callback() {
    cb1handling();
    if (!is_fading()) {
        if (fmem->wtrade_mem->from_outdoor) {
            overworld_free();
        } else {
            pokepad_free_components();
        }
        //Now we initilize the graphic components
        wondertrade_init_components();
        fmem->wtrade_mem->color_cb = spawn_big_callback(wondertrade_color_callback, 0);
        set_io(0x50, 0);
        set_io(0x52, 0);
        set_io(0x54, 0);
        bic_io(0, 0x6000);
        set_callback1(wondertrade_show_components);
    }
}

void wondertrade_load_steps_into_buffer() {
    u8 *buffer0 = (u8*) 0x02021CD0;
    itoa(buffer0, *vardecrypt(VAR_POKEPAD_WONDERTRADE_STEP_CNT), 0, 3);
}

void wondertrade_init(bool is_outdoor) {
    bool is_usable = *vardecrypt(VAR_POKEPAD_WONDERTRADE_STEP_CNT) >= 250;
    if (is_outdoor && !is_usable) {
        wondertrade_load_steps_into_buffer();
        init_script(script_wondertrade_failure);
        return;
    }

    init_fadescreen(1, 0);
    fmem->wtrade_mem = (wondertrade_memory*) malloc(sizeof (wondertrade_memory));
    fmem->wtrade_mem->from_outdoor = is_outdoor;
    fmem->wtrade_mem->error_m = false;
    fmem->wtrade_mem->usable = is_usable;
    fmem->wtrade_mem->cursor = 0;
    set_callback1(wondertrade_init_callback);

}