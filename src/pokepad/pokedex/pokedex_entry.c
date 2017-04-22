#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "pokepad.h"
#include "pokedex.h"
#include "oams.h"
#include "callbacks.h"
#include "save.h"
#include "utils.h"
#include "bg.h"
#include "gfx.h"
#include "text.h"
#include "mega.h"
#include "pokemon.h"
#include "basestats.h"
#include "color.h"
#include "superstate.h"
#include "utils.h"
#include "transparency.h"

extern const unsigned short gfx_pokedex_formsTiles[];
extern const unsigned short gfx_pokedex_entry_uiMap[];
extern const unsigned short gfx_pokedex_bottom_1Map[];
extern const unsigned short gfx_pokedex_bottom_1Tiles[];
extern const unsigned short gfx_pokedex_entry_uiTiles[];
extern const unsigned short gfx_pokedex_entry_uiPal[];
extern const unsigned short gfx_pokedex_bottom_1Pal[];
extern const unsigned short gfx_pokedex_formsPal[];


u8 pokedex_entry_title_fontcolmap[] = {0, 1, 2, 0};

bg_config pokedex_bg_entry_configs [] = {
    {0, 2, 31, 0, 0, 0},
    {1, 0, 30, 0, 0, 1},
    {2, 1, 29, 0, 0, 2},
    {3, 3, 28, 0, 0, 2}
};

tboxdata pokedex_entry_tboxes [] = {
    {0, 9, 1, 19, 2, 14, 1},
    {0, 0, 5, 15, 6, 15, 45},
    {2, 0, 12, 30, 12, 15, 1},
    {0, 20, 1, 8, 2, 3, 135},
    {0, 0, 18, 30, 2, 15, 151},
    {0xFF, 0, 0, 0, 0, 0, 0}
};

sprite pokedex_form_sprite = {
    0, 0x8000, 0, 0
};

sprite pokedex_pokepic_sprite = {
    0, 0xC000, 0, 0
};

oam_template pokedex_form_template = {
    0xA00C,
    0xA00C,
    &pokedex_form_sprite,
    GFX_ANIM_TABLE_NULL,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};

oam_template pokedex_pokepic_template = {
    0xA00A,
    0xA00A,
    &pokedex_pokepic_sprite,
    GFX_ANIM_TABLE_NULL,
    NULL,
    ROTSCALE_TABLE_NULL,
    oam_null_callback
};

void pokedex_entry_load_strings() {
    tbox_flush(0, 0); //0 is the name header
    pokedex_tbox_draw_num(0, 0, fmem->dex_mem->current_species, 0, 0);
    tbox_tilemap_draw(0);
    tbox_print_string(0, 2, 30, 0, 0, 0, pokedex_entry_title_fontcolmap, 0, pokemon_names[fmem->dex_mem->current_species]);
    u16 dex_id = pokedex_get_id(fmem->dex_mem->current_species);

    tbox_flush(1, 0);
    tbox_tilemap_draw(1);
    tbox_print_string(1, 2, 96, 0, 0, 0, pokedex_fontcolmap, 0, str_pokepad_pokedex_form);
    tbox_print_string(1, 2, 4, 15, 0, 0, pokedex_fontcolmap, 0, str_pokepad_pokedex_data);

    tbox_flush(2, 0);
    tbox_tilemap_draw(2);


    tbox_flush(3, 0);
    tbox_tilemap_draw(3);

    tbox_flush(4, 0);
    tbox_tilemap_draw(4);

    bool has_habitat = checkflag(POKEDEX_FLAG_HABITAT);

    u8 *buf = strbuf;
    *buf = 0xFF;
    u8 str_space[] = {0, 0, 0, 0, 0, 0, 0, 0xFF};
    buf = str_append(buf, has_habitat ? str_pokepad_pokedex_habitat : str_space);
    strcpy(buf, str_pokepad_pokedex_std_buttons);
    tbox_print_string(4, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, strbuf);

    bool is_caught = fmem->dex_mem->list[fmem->dex_mem->current_list_index].caught;

    u8 str_none[1] = {0xFF};

    tbox_print_string(1, 2, 8, 0, 0, 0, pokedex_fontcolmap, 0, is_caught ? pokedex_get_data(dex_id)->category : str_pokepad_pokedex_qmark);
    u32 height_upper = pokedex_get_data(dex_id)->height / 10;
    u32 height_lower = __aeabi_uidivmod(pokedex_get_data(dex_id)->height, 10);
    value_to_str(str_append(value_to_str(strbuf, height_upper, 0, 3), str_pokepad_pokedex_comma), height_lower, 0, 1);
    tbox_print_string(1, 2, 38, 15, 0, 0, pokedex_fontcolmap, 0, is_caught ? strbuf : str_pokepad_pokedex_qmark);
    if (is_caught)
        tbox_print_string(1, 2, 70, 15, 0, 0, pokedex_fontcolmap, 0, str_pokepad_pokedex_m);
    u32 weight_upper = pokedex_get_data(dex_id)->weight / 10;
    u32 weight_lower = __aeabi_uidivmod(pokedex_get_data(dex_id)->weight, 10);
    if (is_caught)
        tbox_print_string(1, 2, 70, 30, 0, 0, pokedex_fontcolmap, 0, str_pokepad_pokedex_kg);
    value_to_str(str_append(value_to_str(strbuf, weight_upper, 0, 3), str_pokepad_pokedex_comma), weight_lower, 0, 1);
    tbox_print_string(1, 2, 38, 30, 0, 0, pokedex_fontcolmap, 0, is_caught ? strbuf : str_pokepad_pokedex_qmark);
    tbox_print_string(2, 2, 0, 0, 0, 1, pokedex_fontcolmap, 0, is_caught ? pokedex_get_data(dex_id)->page0 : str_pokepad_pokedex_qmark);
    if (is_caught) {
        u8 type1 = (u8) (basestats[fmem->dex_mem->current_species].type1 + 1);
        u8 type2 = (u8) (basestats[fmem->dex_mem->current_species].type2 + 1);
        tbox_draw_type_icon_by_type_p1(3, type1, 0, 0);
        if (type1 != type2)
            tbox_draw_type_icon_by_type_p1(3, type2, 0x20, 0);
    }
    tbox_print_string(3, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_none);


    bg_virtual_sync(0);
    bg_virtual_sync(2);
}

void pokedex_entry_load_pokepic() {
    if (fmem->dex_mem->entry_skip_cry) {
        fmem->dex_mem->entry_skip_cry = false;
    } else {
        cry(fmem->dex_mem->current_species, 0);
    }
    if (fmem->dex_mem->tile_pokepic == 0xFFFF) {
        //allocate obj vram
        fmem->dex_mem->tile_pokepic = obj_vram_allocate(64);
        obj_vram_add_tile_tag_to_allocation_table(0xA00A, fmem->dex_mem->tile_pokepic, 64);
    }
    if (fmem->dex_mem->pal_pokepic == 0xFF) {
        fmem->dex_mem->pal_pokepic = allocate_obj_pal(0xA00A);
    }
    pal_load_comp(pokemon_pals[fmem->dex_mem->current_species].pal, (u16) (256 + fmem->dex_mem->pal_pokepic * 16), 32);
    pal_set_all_to_black();

    void *offset = (void*) (0x06010000 + 32 * fmem->dex_mem->tile_pokepic);
    lz77uncompvram(pokemon_frontsprites[fmem->dex_mem->current_species].sprite, offset);

    //load form
    offset = (void*) (0x06010000 + 32 * fmem->dex_mem->tile_form);
    u8 form = basestats[fmem->dex_mem->current_species].form;
    cpuset(&gfx_pokedex_formsTiles[form * 256], offset, 256);
}

void pokedex_callback_init_entry() {
    cb1handling();
    if (!is_fading()) {

        //disable window
        set_io(0, (u16) (get_io(0) &~0x6000));

        fmem->dex_mem->tile_pokepic = 0xFFFF;
        fmem->dex_mem->pal_pokepic = 0xFF;

        pokedex_free_maps();

        oam_reset();
        bg_reset(0);
        oam_reset();
        remove_all_big_callbacks();
        pal_fade_cntrl_reset();
        pal_allocation_reset();
        free_all_tboxes();
        set_callback3(NULL);
        bg_reset(0);
        bg_setup(0, pokedex_bg_entry_configs, 4);

        void *bg0map = cmalloc(0x800);
        void *bg1map = malloc(0x800);
        void *bg2map = cmalloc(0x800);
        void *bg3map = malloc(0x800);
        bg_set_tilemap(0, bg0map);
        bg_set_tilemap(1, bg1map);
        bg_set_tilemap(2, bg2map);
        bg_set_tilemap(3, bg3map);

        lz77uncompwram(gfx_pokedex_entry_uiMap, bg1map);
        lz77uncompwram(gfx_pokedex_bottom_1Map, bg3map);
        lz77uncompvram(gfx_pokedex_bottom_1Tiles, (void*) 0x06004000);
        lz77uncompvram(gfx_pokedex_bottom_1Tiles, (void*) 0x06008000);
        lz77uncompvram(gfx_pokedex_bottom_1Tiles, (void*) 0x0600c000);
        lz77uncompvram(gfx_pokedex_entry_uiTiles, (void*) 0x06000000);

        set_io(0x18, (u16) (-4));

        tbox_sync_with_virtual_bg_and_init_all(pokedex_entry_tboxes);
        pokedex_entry_load_strings();

        //oam
        fmem->dex_mem->pal_form = (u8) (allocate_obj_pal(0xA00C) + 0x10);
        fmem->dex_mem->tile_form = obj_vram_allocate(16);
        obj_vram_add_tile_tag_to_allocation_table(0xA00C, fmem->dex_mem->tile_form, 16);
        pokedex_entry_load_pokepic();
        fmem->dex_mem->oam_pokepic = generate_oam_forward_search(&pokedex_pokepic_template, 192, 64, 0);
        fmem->dex_mem->oam_form = generate_oam_forward_search(&pokedex_form_template, 108, 72, 0);

        pal_load_comp(gfx_pokedex_entry_uiPal, 0, 32);
        pal_load_comp(gfx_pokedex_bottom_1Pal, 16, 32);
        pal_load_comp(gfx_pokedex_formsPal, (u16) (fmem->dex_mem->pal_form * 16), 32);
        pal_load_uncomp((void*) 0x08E95DDC, 3 * 16, 32);
        pal_load_uncomp((void*) 0x08E95DBC, 4 * 16, 32);
        pal_set_all_to_black();

        init_fadescreen(0, 0);
        set_callback1(pokedex_callback_entry_idle);

        bg_virtual_sync(1);
        bg_virtual_sync(2);
        bg_virtual_sync(3);

        bg_sync_display_and_show(0);
        bg_sync_display_and_show(1);
        bg_sync_display_and_show(2);
        bg_sync_display_and_show(3);
        bg_display_sync();
    }
}

void pokedex_callback_entry_back() {
    cb1handling();
    if (!is_fading()) {
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free(bg_get_tilemap(2));
        free(bg_get_tilemap(3));
        free_all_tboxes();
        pokedex_init_components();
        pokedex_update_list();
        set_io(0x50, 0);
        set_io(0x52, 0);
        set_io(0x54, 0);
        bic_io(0, 0x6000);
    }
}

void pokedex_entry_update() {
    cb1handling();
    if (!is_fading()) {
        fmem->dex_mem->current_species = fmem->dex_mem->list[fmem->dex_mem->current_list_index].species;
        pokedex_entry_load_strings();
        pokedex_entry_load_pokepic();
        set_io(0x1A, 0);
        init_fadescreen(0, 0);
        set_callback1(pokedex_callback_entry_idle);
        //test(pokedex_get_data(0),00);
    }
}

void pokedex_callback_entry_idle() {
    cb1handling();
    if (!is_fading()) {

        if (super->keys_new.keys.B) {
            sound(5);
            init_fadescreen(1, 0);
            set_callback1(pokedex_callback_entry_back);
        } else if (super->keys_new.keys.start) {
            cry(fmem->dex_mem->current_species, 0);
        } else if (super->keys_new.keys.up && fmem->dex_mem->current_list_index > pokedex_get_first_seen()) {
            do {
                fmem->dex_mem->current_list_index--;
            } while (!fmem->dex_mem->list[fmem->dex_mem->current_list_index].seen);
            set_callback1(pokedex_entry_update);
            init_fadescreen(1, 0);
        } else if (super->keys_new.keys.down && fmem->dex_mem->current_list_index < pokedex_get_last_seen()) {
            do {
                fmem->dex_mem->current_list_index++;
            } while (!fmem->dex_mem->list[fmem->dex_mem->current_list_index].seen);
            set_callback1(pokedex_entry_update);
            init_fadescreen(1, 0);
        } else if (super->keys.keys.left) {
            u16 x = get_io(0x1A);
            if (x)
                x = (u16) (x - 4);
            set_io(0x1A, x);

        } else if (super->keys.keys.right) {
            //first we count the lines in page1
            pokedex_data *data = pokedex_get_data(fmem->dex_mem->list[fmem->dex_mem->current_list_index].dex_id);
            //we count the lines
            int i;
            int line_cnt = 1;
            for (i = 1; data->page0[i] != 0xFF && fmem->dex_mem->list[fmem->dex_mem->current_list_index].caught; i++) {
                if (data->page0[i] == 0xFE)
                    line_cnt++;
            }

            u16 bg2hscroll = get_io(0x1A);
            if (bg2hscroll < 16 * (line_cnt - 3)) {
                set_io(0x1A, (u16) (bg2hscroll + 4));
            }

        } else if (super->keys_new.keys.A && checkflag(POKEDEX_FLAG_HABITAT)) {
            sound(5);
            init_fadescreen(1, 0);
            set_callback1(pokedex_init_habitat);



        }


    }
}


