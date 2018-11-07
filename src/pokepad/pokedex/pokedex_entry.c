#include "types.h"
#include "stdbool.h"
#include "pokepad/pokedex/gui.h"
#include "pokepad/pokedex/operator.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "mega.h"
#include "pokemon/basestat.h"
#include "pokemon/names.h"
#include "pokemon/sprites.h"
#include "color.h"
#include "superstate.h"
#include "transparency.h"
#include "constants/flags.h"
#include "language.h"
#include "fading.h"
#include "debug.h"
#include "agbmemory.h"
#include "bios.h"
#include "io.h"
#include "dma.h"
#include "music.h"
#include "pokemon/cry.h"
#include "flags.h"

extern const unsigned short gfx_pokedex_formsTiles[];
extern const unsigned short gfx_pokedex_entry_uiMap[];
extern const unsigned short gfx_pokedex_bottom_1Map[];
extern const unsigned short gfx_pokedex_bottom_1Tiles[];
extern const unsigned short gfx_pokedex_entry_uiTiles[];
extern const unsigned short gfx_pokedex_entry_uiPal[];
extern const unsigned short gfx_pokedex_bottom_1Pal[];
extern const unsigned short gfx_pokedex_formsPal[];


tbox_font_colormap pokedex_entry_title_fontcolmap = {0, 1, 2, 0};

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
    oam_gfx_anim_table_null,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

oam_template pokedex_pokepic_template = {
    0xA00A,
    0xA00A,
    &pokedex_pokepic_sprite,
    oam_gfx_anim_table_null,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

void pokedex_entry_load_strings() {
    tbox_flush_set(0, 0); //0 is the name header
    pokedex_tbox_draw_num(0, 0, fmem.dex_mem->current_species, 0, 0);
    tbox_tilemap_draw(0);
    tbox_print_string(0, 2, 30, 0, 0, 0, &pokedex_entry_title_fontcolmap, 0,
        pokemon_names[fmem.dex_mem->current_species]);
    u16 dex_id = pokedex_get_id(fmem.dex_mem->current_species);

    tbox_flush_set(1, 0);
    tbox_tilemap_draw(1);
    u8 str_form[] = LANGDEP(PSTRING("Form"), PSTRING("Form"));
    tbox_print_string(1, 2, 96, 0, 0, 0, &pokedex_fontcolmap, 0, str_form);
    u8 str_data[] = LANGDEP(PSTRING("Gr.\nGew."), PSTRING("Sz.\nWgt."));
    tbox_print_string(1, 2, 4, 15, 0, 0, &pokedex_fontcolmap, 0, str_data);

    tbox_flush_set(2, 0);
    tbox_tilemap_draw(2);


    tbox_flush_set(3, 0);
    tbox_tilemap_draw(3);

    tbox_flush_set(4, 0);
    tbox_tilemap_draw(4);

    bool has_habitat = checkflag(POKEDEX_FEATURE_HABITAT);

    u8 *buf = strbuf;
    *buf = 0xFF;
    if(fmem.dex_mem->from_battle){
        u8 str_buttons_battle[] = LANGDEP(PSTRING("KEY_START Ruf  KEY_A Weiter"),
            PSTRING("KEY_START Cry  KEY_A Proceed"));
        strcpy(buf, str_buttons_battle);
    }else{
        u8 str_space[] = PSTRING("       ");
        u8 str_buttons[] = LANGDEP(
            PSTRING("KEY_START Ruf  KEY_UP_DOWN Liste  KEY_LEFT_RIGHT Eintr. KEY_B Zur."),
            PSTRING("KEY_START Cry  KEY_UP_DOWN List  KEY_LEFT_RIGHT Rec. KEY_B Back"));
        u8 str_habitat[] = LANGDEP(PSTRING("KEY_A Hab."), PSTRING("KEY_A Hab."));
        buf = strcat(buf, has_habitat ? str_habitat : str_space);
        strcpy(buf, str_buttons);
    }
    tbox_print_string(4, 2, 0, 0, 0, 0, &pokedex_fontcolmap, 0, strbuf);

    bool is_caught = fmem.dex_mem->list[fmem.dex_mem->current_list_index].caught;

    u8 str_none[1] = PSTRING("");
    u8 str_qmark[] = PSTRING("?");

    tbox_print_string(1, 2, 8, 0, 0, 0, &pokedex_fontcolmap, 0, is_caught ?
        pokedex_get_data(dex_id)->category : str_qmark);
    int height_upper = pokedex_get_data(dex_id)->height / 10;
    int height_lower = pokedex_get_data(dex_id)->height % 10;
    u8 str_comma[] = PSTRING(",");
    itoa(strcat(itoa(strbuf, height_upper, 0, 3), str_comma), height_lower, 0, 1);
    tbox_print_string(1, 2, 38, 15, 0, 0, &pokedex_fontcolmap, 0, is_caught ? strbuf : str_qmark);
    u8 str_meter[] = PSTRING("m");
    u8 str_kilogram[] = PSTRING("kg");
    if (is_caught)
        tbox_print_string(1, 2, 70, 15, 0, 0, &pokedex_fontcolmap, 0, str_meter);
    int weight_upper = pokedex_get_data(dex_id)->weight / 10;
    int weight_lower = pokedex_get_data(dex_id)->weight % 10;
    if (is_caught)
        tbox_print_string(1, 2, 70, 30, 0, 0, &pokedex_fontcolmap, 0, str_kilogram);
    itoa(strcat(itoa(strbuf, weight_upper, 0, 3), str_comma), weight_lower, 0, 1);
    tbox_print_string(1, 2, 38, 30, 0, 0, &pokedex_fontcolmap, 0, is_caught ? strbuf : str_qmark);
    tbox_print_string(2, 2, 0, 0, 0, 1, &pokedex_fontcolmap, 0, is_caught ?
        pokedex_get_data(dex_id)->page0 : str_qmark);
    if (is_caught) {
        u8 type1 = (u8) (basestats[fmem.dex_mem->current_species].type1 + 1);
        u8 type2 = (u8) (basestats[fmem.dex_mem->current_species].type2 + 1);
        tbox_draw_type_icon_by_type_p1(3, type1, 0, 0);
        if (type1 != type2)
            tbox_draw_type_icon_by_type_p1(3, type2, 0x20, 0);
    }
    tbox_print_string(3, 2, 0, 0, 0, 0, &pokedex_fontcolmap, 0, str_none);


    bg_virtual_sync(0);
    bg_virtual_sync(2);
}

void pokedex_entry_load_pokepic() {
    if (fmem.dex_mem->entry_skip_cry) {
        fmem.dex_mem->entry_skip_cry = false;
    } else {
        pokemon_play_cry(fmem.dex_mem->current_species, 0);
    }
    if (fmem.dex_mem->tile_pokepic == 0xFFFF) {
        //allocate obj vram
        fmem.dex_mem->tile_pokepic = oam_vram_alloc(64);
        oam_vram_allocation_table_add(0xA00A, fmem.dex_mem->tile_pokepic, 64);
    }
    if (fmem.dex_mem->pal_pokepic == 0xFF) {
        fmem.dex_mem->pal_pokepic = oam_allocate_palette(0xA00A);
    }
    pal_decompress(pokemon_pals[fmem.dex_mem->current_species].pal, (u16) (256 + fmem.dex_mem->pal_pokepic * 16), 32);
    pal_set_all_to_black();

    void *offset = (void*) (0x06010000 + 32 * fmem.dex_mem->tile_pokepic);
    lz77uncompvram(pokemon_frontsprites[fmem.dex_mem->current_species].sprite, offset);

    //load form
    offset = (void*) (0x06010000 + 32 * fmem.dex_mem->tile_form);
    u8 form = basestats[fmem.dex_mem->current_species].form;
    cpuset(&gfx_pokedex_formsTiles[form * 256], offset, 256);
}

u16 pokedex_colors[16];
u16 pokedex_colors_nr[16];

void pokedex_callback_init_entry_load_elements(){
   //disable window
    io_set(0, (u16) (io_get(0) &~0x6000));

    fmem.dex_mem->tile_pokepic = 0xFFFF;
    fmem.dex_mem->pal_pokepic = 0xFF;


    oam_reset();
    bg_reset(0);
    fading_cntrl_reset();
    oam_palette_allocation_reset();
    tbox_free_all();
    vblank_handler_set(NULL);
    dma0_reset_callback();
    bg_reset(0);
    bg_setup(0, pokedex_bg_entry_configs, 4);

    void *bg0map = malloc_and_clear(0x800);
    void *bg1map = malloc(0x800);
    void *bg2map = malloc_and_clear(0x800);
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

    io_set(0x18, (u16) (-4));

    tbox_sync_with_virtual_bg_and_init_all(pokedex_entry_tboxes);
    pokedex_entry_load_strings();

    //oam
    fmem.dex_mem->pal_form = (u8) (oam_allocate_palette(0xA00C) + 0x10);
    fmem.dex_mem->tile_form = oam_vram_alloc(16);
    oam_vram_allocation_table_add(0xA00C, fmem.dex_mem->tile_form, 16);
    pokedex_entry_load_pokepic();
    fmem.dex_mem->oam_pokepic = oam_new_forward_search(&pokedex_pokepic_template, 192, 64, 0);
    fmem.dex_mem->oam_form = oam_new_forward_search(&pokedex_form_template, 108, 72, 0);

    pal_decompress(gfx_pokedex_entry_uiPal, 0, 32);
    pal_decompress(gfx_pokedex_bottom_1Pal, 16, 32);
    pal_decompress(gfx_pokedex_formsPal, (u16) (fmem.dex_mem->pal_form * 16), 32);
    pal_copy((void*) 0x08E95DDC, 3 * 16, 32);
    pal_copy((void*) 0x08E95DBC, 4 * 16, 32);
    pal_copy(pokedex_colors_nr, 14 * 16, 32);
    pal_copy(pokedex_colors, 15 * 16, 16);
    pal_set_all_to_black();

    bg_virtual_sync(1);
    bg_virtual_sync(2);
    bg_virtual_sync(3);

    bg_sync_display_and_show(0);
    bg_sync_display_and_show(1);
    bg_sync_display_and_show(2);
    bg_sync_display_and_show(3);
    bg_display_sync();
    
    dprintf("Loaded pokexdex elements\n");
}

void pokedex_callback_init_entry() {
    generic_callback1();
    if (!fading_is_active()) {
        pokedex_free_maps();
        pokedex_callback_init_entry_load_elements();
        big_callback_delete_all();
        callback1_set(pokedex_callback_entry_idle);
        vblank_handler_set(generic_vblank_handler);
        fadescreen_all(0, 0);
        
    }
}

void pokedex_entry_from_battle_cb(u8 self){
    
    if(!fading_is_active()){
        switch( big_callbacks[self].params[0]){
            case 0: //Countdown
                if(--(big_callbacks[self].params[1])) return;
                big_callbacks[self].params[0]++;
                break;
            case 1:{ //Wait for a press
                if (super.keys.keys.left) {
                    u16 x = io_get(0x1A);
                    if (x)
                        x = (u16) (x - 4);
                    io_set(0x1A, x);

                } else if (super.keys.keys.right) {
                    //first we count the lines in page1
                    u16 dex_id = pokedex_get_id(fmem.dex_mem->current_species);
                    pokedex_entry *data = pokedex_get_data(dex_id);
                    //we count the lines
                    int i;
                    int line_cnt = 1;
                    for (i = 1; data->page0[i] != 0xFF; i++) {
                        if (data->page0[i] == 0xFE)
                            line_cnt++;
                    }

                    u16 bg2hscroll = io_get(0x1A);
                    if (bg2hscroll < 16 * (line_cnt - 3)) {
                        io_set(0x1A, (u16) (bg2hscroll + 4));
                    }
                } else if(super.keys_new.keys.A){
                    fadescreen((u32)-1, 0, 0, 16, 0);
                    big_callbacks[self].params[0]++;
                } else if (super.keys_new.keys.start) {
                     pokemon_play_cry(fmem.dex_mem->current_species, 0);
                }
                break;
            }
            case 2:{ //free all components
                volume_set((void*) 0x030071F0, 0xFFFF, 0x100);
                free(bg_get_tilemap(0));
                free(bg_get_tilemap(1));
                free(bg_get_tilemap(2));
                free(bg_get_tilemap(3));
                tbox_free_all();
                big_callback_delete(self);
                
            }
        }
    }
    
}

u8 pokedex_init_entry_from_battle(u16 species){
    //First allocate dex_mem
    pokedex_memory *dex_mem = (pokedex_memory*)malloc_and_clear(sizeof(pokedex_memory));
    dex_mem->current_species = species;
    dex_mem->from_battle = true;
    fmem.dex_mem = dex_mem;
    pokedex_callback_init_entry_load_elements();
    u8 cb_id = big_callback_new(pokedex_entry_from_battle_cb, 0);
    big_callbacks[cb_id].params[0] = 0;
    big_callbacks[cb_id].params[1] = 120; //countdown
    fading_cntrl.field_8 &= 0x7F;
    fadescreen(0xFFFFFFFF, 0, 16, 0, 0xFFFF);
    
    //Set the pokedex callback3
    void (*pokedex_cb3)() = (void(*)())(0x08102714 | 1);
    vblank_handler_set(pokedex_cb3);
    
    return cb_id;
}


void pokedex_callback_entry_back() {
    generic_callback1();
    if (!fading_is_active()) {
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free(bg_get_tilemap(2));
        free(bg_get_tilemap(3));
        tbox_free_all();
        pokedex_init_components();
        pokedex_update_list();
        io_set(0x50, 0);
        io_set(0x52, 0);
        io_set(0x54, 0);
        io_bic(0, 0x6000);
    }
}

void pokedex_entry_update() {
    generic_callback1();
    if (!fading_is_active()) {
        fmem.dex_mem->current_species = fmem.dex_mem->list[fmem.dex_mem->current_list_index].species;
        pokedex_entry_load_strings();
        pokedex_entry_load_pokepic();
        io_set(0x1A, 0);
        fadescreen_all(0, 0);
        callback1_set(pokedex_callback_entry_idle);
        //test(pokedex_get_data(0),00);
    }
}

void pokedex_callback_entry_idle() {
    generic_callback1();
    if (!fading_is_active()) {

        if (super.keys_new.keys.B) {
            play_sound(5);
            fadescreen_all(1, 0);
            volume_set((void*) 0x030071F0, 0xFFFF, 0x100);
            callback1_set(pokedex_callback_entry_back);
        } else if (super.keys_new.keys.start) {
            pokemon_play_cry(fmem.dex_mem->current_species, 0);
        } else if (super.keys_new.keys.up && fmem.dex_mem->current_list_index > pokedex_get_first_seen()) {
            do {
                fmem.dex_mem->current_list_index--;
            } while (!fmem.dex_mem->list[fmem.dex_mem->current_list_index].seen);
            callback1_set(pokedex_entry_update);
            fadescreen_all(1, 0);
        } else if (super.keys_new.keys.down && fmem.dex_mem->current_list_index < pokedex_get_last_seen()) {
            do {
                fmem.dex_mem->current_list_index++;
            } while (!fmem.dex_mem->list[fmem.dex_mem->current_list_index].seen);
            callback1_set(pokedex_entry_update);
            fadescreen_all(1, 0);
        } else if (super.keys.keys.left) {
            u16 x = io_get(0x1A);
            if (x)
                x = (u16) (x - 4);
            io_set(0x1A, x);

        } else if (super.keys.keys.right) {
            //first we count the lines in page1
            pokedex_entry *data = pokedex_get_data(fmem.dex_mem->list[fmem.dex_mem->current_list_index].dex_id);
            //we count the lines
            int i;
            int line_cnt = 1;
            for (i = 1; data->page0[i] != 0xFF && fmem.dex_mem->list[fmem.dex_mem->current_list_index].caught; i++) {
                if (data->page0[i] == 0xFE)
                    line_cnt++;
            }

            u16 bg2hscroll = io_get(0x1A);
            if (bg2hscroll < 16 * (line_cnt - 3)) {
                io_set(0x1A, (u16) (bg2hscroll + 4));
            }

        } else if (super.keys_new.keys.A && checkflag(POKEDEX_FEATURE_HABITAT)) {
            play_sound(5);
            fadescreen_all(1, 0);
            callback1_set(pokedex_init_habitat);



        }


    }
}


