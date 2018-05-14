#include "types.h"
#include "mugshot.h"
#include "oam.h"
#include "callbacks.h"
#include "color.h"
#include "save.h"
#include "text.h"
#include "debug.h"
#include "transparency.h"
#include "constants/map_weathers.h"
#include "vars.h"
#include "flags.h"
#include "bios.h"
#include "agbmemory.h"
#include "overworld/map_control.h"

#define MUGSHOT_BASE_TAG 0x1340

static sprite mugshot_sprite = {0, 0xC000,  ATTR2_PRIO(1), 0};
static sprite mugshot_sprite_prio0 = {0, 0xC000, ATTR2_PRIO(0), 0};

extern const unsigned short gfx_mug_mistralTiles[];
extern const unsigned short gfx_mug_mistralPal[];
extern const unsigned short gfx_mug_hiroTiles[];
extern const unsigned short gfx_mug_hiroPal[];
extern const unsigned short gfx_mug_lesterTiles[];
extern const unsigned short gfx_mug_lesterPal[];
extern const unsigned short gfx_mug_igvaTiles[];
extern const unsigned short gfx_mug_igvaPal[];
extern const unsigned short gfx_mug_blackbeardTiles[];
extern const unsigned short gfx_mug_blackbeardPal[];
extern const unsigned short gfx_mug_rinTiles[];
extern const unsigned short gfx_mug_rinPal[];
extern const unsigned short gfx_mug_rivalTiles[];
extern const unsigned short gfx_mug_rivalPal[];
extern const unsigned short gfx_mug_brixTiles[];
extern const unsigned short gfx_mug_brixPal[];
extern const unsigned short gfx_mug_mayTiles[];
extern const unsigned short gfx_mug_mayPal[];
extern const unsigned short gfx_mug_felixTiles[];
extern const unsigned short gfx_mug_felixPal[];
extern const unsigned short gfx_mug_felixTiles[];
extern const unsigned short gfx_mug_felixPal[];
extern const unsigned short gfx_mug_blaiseTiles[];
extern const unsigned short gfx_mug_blaisePal[];
extern const unsigned short gfx_mug_tannTiles[];
extern const unsigned short gfx_mug_tannPal[];
extern const unsigned short gfx_mug_faunTiles[];
extern const unsigned short gfx_mug_faunPal[];
extern const unsigned short gfx_mug_eliseTiles[];
extern const unsigned short gfx_mug_elisePal[];
extern const unsigned short gfx_mug_emerysTiles[];
extern const unsigned short gfx_mug_emerysPal[];
extern const unsigned short gfx_mug_rubysTiles[];
extern const unsigned short gfx_mug_rubysPal[];
extern const unsigned short gfx_mug_saphiraTiles[];
extern const unsigned short gfx_mug_saphiraPal[];
extern const unsigned short gfx_mug_harrenfeldTiles[];
extern const unsigned short gfx_mug_harrenfeldPal[];
extern const unsigned short gfx_mug_albusTiles[];
extern const unsigned short gfx_mug_albusPal[];
extern const unsigned short gfx_mug_faun_youngTiles[];
extern const unsigned short gfx_mug_faun_youngPal[];
extern const unsigned short gfx_pkmn_species_251_pokemon_celebi_frontspriteTiles[];
extern const unsigned short gfx_pkmn_species_251_pokemon_celebi_frontspritePal[];
extern const unsigned short gfx_mug_larissaTiles[];
extern const unsigned short gfx_mug_larissaPal[];
extern const unsigned short gfx_mug_primusTiles[];
extern const unsigned short gfx_mug_primusPal[];
extern const unsigned short gfx_mug_hiroineTiles[];
extern const unsigned short gfx_mug_hiroinePal[];

extern u8 str_mug_mistral[];
extern u8 str_mug_hiro[];
extern u8 str_mug_lester[];
extern u8 str_mug_igva[];
extern u8 str_mug_blackbeard[];
extern u8 str_mug_rin[];
extern u8 str_mug_rival[];
extern u8 str_mug_brix[];
extern u8 str_mug_may[];
extern u8 str_mug_felix[];
extern u8 str_mug_felix[];
extern u8 str_mug_blaise[];
extern u8 str_mug_tann[];
extern u8 str_mug_faun[];
extern u8 str_mug_elise[];
extern u8 str_mug_emerys[];
extern u8 str_mug_rubys[];
extern u8 str_mug_saphira[];
extern u8 str_mug_harrenfeld[];
extern u8 str_mug_albus[];
extern u8 str_mug_larissa[];
extern u8 str_mug_primus[];
extern u8 str_mug_celebi[];


extern u8 str_mugshot_stub[];

static mugshot mugshots[] = {
    {&gfx_mug_rinTiles, &gfx_mug_rinPal, str_mug_rin},
    {NULL, NULL, NULL},
    {&gfx_mug_mistralTiles, &gfx_mug_mistralPal, str_mug_mistral},
    {NULL, NULL, NULL},
    
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {&gfx_mug_rivalTiles, &gfx_mug_rivalPal, str_mug_rival},
    {&gfx_mug_brixTiles, &gfx_mug_brixPal, str_mug_brix},
    
    {&gfx_mug_mayTiles, &gfx_mug_mayPal, str_mug_may},
    {&gfx_mug_felixTiles, &gfx_mug_felixPal, str_mug_felix},
    {&gfx_mug_blaiseTiles, &gfx_mug_blaisePal, str_mug_blaise},
    {&gfx_mug_tannTiles, &gfx_mug_tannPal, str_mug_tann},
    
    {&gfx_mug_hiroTiles, &gfx_mug_hiroPal, str_mug_hiro},
    {&gfx_mug_lesterTiles, &gfx_mug_lesterPal, str_mug_lester},
    {&gfx_mug_faunTiles, &gfx_mug_faunPal, str_mug_faun},
    {&gfx_mug_eliseTiles, &gfx_mug_elisePal, str_mug_elise},
    
    {&gfx_mug_emerysTiles, &gfx_mug_emerysPal, str_mug_emerys},
    {&gfx_mug_rubysTiles, &gfx_mug_rubysPal, str_mug_rubys},
    {&gfx_mug_saphiraTiles, &gfx_mug_saphiraPal, str_mug_saphira},
    {&gfx_mug_harrenfeldTiles, &gfx_mug_harrenfeldPal, str_mug_harrenfeld},
    
    {&gfx_mug_albusTiles, &gfx_mug_albusPal, str_mug_albus},
    {&gfx_mug_faun_youngTiles, &gfx_mug_faun_youngPal, str_mug_faun},
    {&gfx_pkmn_species_251_pokemon_celebi_frontspriteTiles, &gfx_pkmn_species_251_pokemon_celebi_frontspritePal, str_mug_celebi},
    {&gfx_mug_larissaTiles, &gfx_mug_larissaPal, str_mug_larissa},
    
    {&gfx_mug_primusTiles, &gfx_mug_primusPal, str_mug_primus},
    {&gfx_mug_igvaTiles, &gfx_mug_igvaPal, str_mug_igva},
    {&gfx_mug_blackbeardTiles, &gfx_mug_blackbeardPal, str_mug_blackbeard},
    {&gfx_mug_hiroineTiles, &gfx_mug_hiroinePal, str_mug_hiro}
};


/**
 * Clears the bottom line of the tbox (sets tile to color 0)
 * @param box_id
 */
void tbox_clear_bottom_line(u8 box_id){
    int first_tile = tboxes[box_id].boxdata.w * (tboxes[box_id].boxdata.h - 1);
    int i;
    u16 *vtileset = (tboxes[box_id].virtual_tileset);
    for(i = 0; i < tboxes[box_id].boxdata.w; i++){
        vtileset[(first_tile + i) * 16 + 14] = 0;
        vtileset[(first_tile + i) * 16 + 15] = 0;
    }
}


void mugshot_oam_despawn_cb(u8 self);

void spawn_mugshot() {
    
    //If a callback to clear a mugshot is currently active we have to clear first in order to prevent that our content will be swiped away
    u8 clearing_cb = big_callback_get_id(mugshot_oam_despawn_cb);
    if(clearing_cb != 0xFF){
        mugshot_oam_despawn_cb(clearing_cb);
        big_callback_delete(clearing_cb);
    }
    
    int side = *var_access(0x8000);
    int index = *var_access(0x8001);
    u16 tag = (u16) (MUGSHOT_BASE_TAG + index);

    graphic *mugshot_tmp_graphic = (graphic*) malloc(sizeof (graphic));
    mugshot_tmp_graphic->sprite = mugshots[index].gfx;
    mugshot_tmp_graphic->size = 0x800;
    mugshot_tmp_graphic->tag = tag;

    u8 pal = oam_allocate_palette(tag);
    u16 *pal_buf = (u16*) malloc(40);
    
    lz77uncompwram(mugshots[index].pal, pal_buf);
    //apply weather effects to pal
    
    
    u8 weather = map_get_current_weather();
    pal_copy(pal_buf, (u16) (0x100 + 16 * pal), 32);
    if (weather == MAP_WEATHER_CLOUDY || weather == MAP_WEATHER_EXTREME_THUNDER ||
    		weather == MAP_WEATHER_THUNDER || weather == MAP_WEATHER_RAIN) {
        //fade
        u16 *dma3s = (u16*) 0x020375F8;
        int i;
        for (i = 0; i < 16; i++) {
            u16 original = dma3s[i + (pal + 0x10)*0x10];
            color co = {original};
            color over = {0}; //black
            color n = color_alpha_blend(co, over, 3);
            dma3s[i + (pal + 0x10)*0x10] = n.value;
        }
    }

    free(pal_buf);

    //allocating vram for the tiles
    if (oam_vram_allocation_table_get_index(tag) == 0xFF) {
        oam_load_graphic(mugshot_tmp_graphic);
    }
    s16 x = (s16) (0x20 + side * 0xB0);

    //spawn a template obj
    oam_template *mugshot_template = (oam_template*) malloc(sizeof (oam_template));
    mugshot_template->tiles_tag = tag;
    mugshot_template->pal_tag = tag;
    
    if(!checkflag(0x806) && get_mapheader((*save1)->bank, (*save1)->map)->flash){
        mugshot_template->oam = &mugshot_sprite_prio0;
    }else{     
        mugshot_template->oam = &mugshot_sprite;
    }
    mugshot_template->graphics = NULL;
    mugshot_template->animation = (gfx_frame**) 0x08231Bc0;
    mugshot_template->rotscale = (rotscale_frame**) 0x08231Bcc;
    mugshot_template->callback = oam_null_callback;
    fmem->mugshot_oam_id = oam_new_forward_search(mugshot_template, x, 0x50, 0);
    
    //Copy name string
    string_decrypt(strbuf, mugshots[index].name);
    //spawn tbox
    u8 strwidth = string_get_width(2, strbuf, 0);
    if(transparency_is_on()){
        tboxdata tbdata = {
            0, (side ? 0 : (u8)(30 - strwidth / 8 - 4)), 12, (u8)((strwidth / 8) + 4), 2, 15, 0xE8
        };
        u8 box_id = tbox_new(&tbdata);
        tbox_flush_set(box_id, 0x11);
        tbox_tilemap_draw(box_id);
        tbox_clear_bottom_line(box_id);
        tbox_font_colormap fontcolmap = {1, 2, 1, 3};
        tbox_print_string(box_id, 2, 16, 0, 0, 0, &fontcolmap, 0, strbuf);
        fmem->mugshot_tb_id = box_id;
        
    }else{
        tboxdata tbdata = {
            0, (side ? 0 : (u8)(30 - strwidth / 8 - 5)), 11, (u8)((strwidth / 8) + 4), 2, 15, 0xE8
        };
        u8 box_id = tbox_new(&tbdata);
        tbox_flush_set(box_id, 0x11);
        tbox_tilemap_draw(box_id);
        tbox_border_init(box_id, 1, 15 * 16);
        tbox_border_draw(box_id, 1, 0xF);
        tbox_font_colormap fontcolmap = {1, 2, 1, 3};
        tbox_print_string(box_id, 2, 16, 0, 0, 0, &fontcolmap, 0, strbuf);
        fmem->mugshot_tb_id = box_id;
    }
    
    //dprintf("Spawned oam %d, tbid %d\n", fmem->mugshot_oam_id, box_id);
}


void mugshot_oam_despawn_cb(u8 self) {
    u8 oam_id = (u8)big_callbacks[self].params[0];
    u8 tb_id = (u8)big_callbacks[self].params[1];
    free(oams[oam_id].oam_template->graphics);
    free(oams[oam_id].oam_template);
    oam_free(&oams[oam_id]);
    tbox_flush_set(tb_id, 0);
    //tbox_tilemap_draw(fmem->mugshot_tb_id);
    tbox_flush_map(tb_id);
    tbox_sync(tb_id, TBOX_SYNC_MAP_AND_SET);
    if(!transparency_is_on()) tbox_border_flush(tb_id);
    
    tbox_free(tb_id);
    //dprintf("Triggered despawn with oam %d, tbid %d\n", oam_id, tb_id);
    big_callback_delete(self);
}

void clear_mugshot() {
    u16 oam_id = fmem->mugshot_oam_id;
    u8 cb_id = big_callback_new(mugshot_oam_despawn_cb, 0);
    big_callbacks[cb_id].params[0] = oam_id;
    big_callbacks[cb_id].params[1] = fmem->mugshot_tb_id;
    oams[oam_id].x2 = -64;
}
