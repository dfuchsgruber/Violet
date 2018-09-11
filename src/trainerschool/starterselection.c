#include "types.h"
#include "save.h"
#include "callbacks.h"
#include "trainerschool_test.h"
#include "bg.h"
#include "text.h"
#include "superstate.h"
#include "oam.h"
#include "debug.h"
#include "data_structures.h"
#include "pokemon/basestat.h"
#include "pokemon/names.h"
#include "transparency.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "fading.h"
#include "language.h"
#include "io.h"
#include "agbmemory.h"
#include "vars.h"
#include "bios.h"
#include "flags.h"
#include "pokemon/cry.h"
#include "overworld/map_control.h"
#include "music.h"

    typedef struct {
        u16 hscroll;
        u8 hscroll_delay;
        u8 cursor;
        u8 pokeball_oams[3];
        bool selected;
    } trainerschool_selection_memory;

#define TSS_MEM ((trainerschool_selection_memory*)gp_stack_peek())

bg_config trainerschool_selection_bg_configs[4] = {
    {0, 2, 31, 0, 0, 0}, //text on bg0
    {1, 3, 30, 0, 0, 1},
    {2, 1, 29, 0, 0, 2},
    {3, 0, 28, 0, 0, 3}
};


tboxdata trainerschool_selection_tboxes [] = {
    {0, 0, 0, 30, 2, 15, 1}, //0 := text
    {0, 2, 17, 8, 2, 15, 61}, //x + 1 := name
    {0, 11, 18, 8, 2, 15, 77},
    {0, 20, 17, 8, 2, 15, 93}
};

extern const u16 gfx_trainerschool_selection_frontTiles[];
extern const u16 gfx_trainerschool_selection_frontMap[];
extern const u16 gfx_trainerschool_selection_frontPal[];
extern const u16 gfx_trainerschool_selection_middleTiles[];
extern const u16 gfx_trainerschool_selection_middleMap[];
extern const u16 gfx_trainerschool_selection_backTiles[];
extern const u16 gfx_trainerschool_selection_backMap[];



palette *palette_trainerschool_selection_pokeball = (palette*)0x082604F0;
graphic *graphic_trainerschool_selection_pokeball = (graphic*)0x08260490;

extern u16 gfx_trainerschool_lockschalTiles[];
extern u16 gfx_trainerschool_lockschalPal[];
graphic graphic_trainerschool_selection_lockschal = {
    gfx_trainerschool_lockschalTiles, 0x1000, 0xA440
};

extern u16 gfx_trainerschool_welunoTiles[];
extern u16 gfx_trainerschool_welunoPal[];
graphic graphic_trainerschool_selection_weluno = {
    gfx_trainerschool_welunoTiles, 0x1000, 0xA441
};

extern u16 gfx_trainerschool_seekidTiles[];
extern u16 gfx_trainerschool_seekidPal[];
graphic graphic_trainerschool_selection_seekid = {
    gfx_trainerschool_seekidTiles, 0x1000, 0xA442
};

sprite sprite_trainerschool_starter = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_64_64, ATTR2_PRIO(0), 0
};

gfx_frame gfx_anim_trainerschool_starter[] = {
    {0, 0}, {0, 32}, {64, 32}, {GFX_ANIM_JUMP, 0}
};

gfx_frame *gfx_anim_table_trainerschool_starter[] = {
    gfx_anim_trainerschool_starter
};

oam_template oam_template_trainerschool_lockschal = {
    0xA440, 0xA440,
    &sprite_trainerschool_starter,
    gfx_anim_table_trainerschool_starter,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

oam_template oam_template_trainerschool_weluno = {
    0xA441, 0xA441,
    &sprite_trainerschool_starter,
    gfx_anim_table_trainerschool_starter,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

oam_template oam_template_trainerschool_seekid = {
    0xA442, 0xA442,
    &sprite_trainerschool_starter,
    gfx_anim_table_trainerschool_starter,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

sprite sprite_trainerschool_pokeball = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_16_16, 0, 0
};

gfx_frame gfx_frame_trainerschool_ball_anim_ball_0[] = {
    {0, 0}, {GFX_ANIM_END, 0}
};

gfx_frame gfx_frame_trainerschool_ball_anim_ball_1[] = {
    {4, 0}, {GFX_ANIM_END, 0}
};

gfx_frame *gfx_anim_table_trainerschool_pokeball[] = {
    gfx_frame_trainerschool_ball_anim_ball_0,
    gfx_frame_trainerschool_ball_anim_ball_1
};

void oam_callback_trainerschool_pokeball(oam_object *o){
    if(++(o->private[0]) < 6) return;
    o->private[0] = 0;
    
    if(o->private[1]){
        if(--(o->y2) == 0) o->private[1] ^= 1;
    }else{
        //Moving down
        if(!o->private[2]) return; //Do not move becase pokeball is inactive
        if(++(o->y2) == 4) o->private[1] ^= 1;
    }
}

oam_template oam_template_trainerschool_pokeball = {
    0xD6D8, 0xD6D8,
    &sprite_trainerschool_pokeball,
    gfx_anim_table_trainerschool_pokeball,
    NULL,
    oam_rotscale_anim_table_null,
    oam_callback_trainerschool_pokeball
};

u16 trainerschool_selection_species[] = {POKEMON_LOCKSCHAL, POKEMON_WELUNO, POKEMON_SEEKID};

void trainerschool_selection_show_species_text(){
    u8 box_id = (u8)(TSS_MEM->cursor + 1);
    tbox_flush_set(box_id, 0x11);
    tbox_tilemap_draw(box_id);
    tbox_font_colormap fontcolmap = {1, 2, 1, 3};
    u8 *name = pokemon_names[trainerschool_selection_species[TSS_MEM->cursor]];
    int name_width_pixels = string_get_width(2, name, 0);
    int x_distance = (64 - name_width_pixels) >> 1;
    tbox_print_string(box_id, 2, (u8)x_distance, 0, 0, 0, &fontcolmap, 0,
        pokemon_names[trainerschool_selection_species[TSS_MEM->cursor]]);
    
}

void trainerschool_selection_delete_species_text(){
    u8 box_id = (u8)(TSS_MEM->cursor + 1);
    dprintf("Delete text with boxid %d\n", box_id);
    tbox_flush_set(box_id, 0);
    tbox_sync(box_id, TBOX_SYNC_MAP_AND_SET);
    tbox_flush_map(0);
}

u8 str_trainerschool_selection_text[] = LANGDEP(
    PSTRING("  KEY_A  Bestätigen              KEY_B  Abbruch"),
    PSTRING("  KEY_A  Confirm                 KEY_B  Abort"));

void trainerschool_selection_select(){
    //Open the current pokeball
    oams[TSS_MEM->pokeball_oams[TSS_MEM->cursor]].anim_number = 1;
    oam_gfx_anim_init(&oams[TSS_MEM->pokeball_oams[TSS_MEM->cursor]], 0);
    pokemon_play_cry(trainerschool_selection_species[TSS_MEM->cursor], 0);
    //Draw text
    tbox_flush_set(0, 0x11);
    tbox_tilemap_draw(0);
    tbox_sync(0, TBOX_SYNC_MAP_AND_SET);
    tbox_font_colormap fontcolmap = {1, 2, 1, 3};
    tbox_print_string(0, 2, 0, 0, 0, 0, &fontcolmap, 0, str_trainerschool_selection_text);
    TSS_MEM->selected = true;
    
}


void trainerschool_selection_done(){
    generic_callback1();
    if(!fading_is_active()){
        clearflag(MAP_BGN_AUTO_ALIGN_OFF);   
        *((bool*) 0x03000EA8) = false;
        callback1_set(map_reload);
    }
}

void trainerschool_selection_idle(){
    generic_callback1();
    if(!TSS_MEM->hscroll_delay){
        io_set(0x1C, (TSS_MEM->hscroll)--);
        TSS_MEM->hscroll_delay = 8;
    }else{
        TSS_MEM->hscroll_delay--;
    }
    if(!fading_is_active()){
        if(TSS_MEM->selected){
            //One pokeball is already opened and you selected a starter, only handle A;B for confirmation or abort
            if(super.keys_new.keys.B){
                //Return to normal selection
                play_sound(5);
                tbox_flush_set(0, 0);
                tbox_flush_map(0);
                tbox_sync(0, TBOX_SYNC_MAP_AND_SET);
                oams[TSS_MEM->pokeball_oams[TSS_MEM->cursor]].anim_number = 0;
                oam_gfx_anim_init(&oams[TSS_MEM->pokeball_oams[TSS_MEM->cursor]], 0);
                TSS_MEM->selected = false;
            }else if(super.keys_new.keys.A){
                *var_access(STARTER_SELECTED) = TSS_MEM->cursor;
                *var_access(0x800D) = trainerschool_selection_species[TSS_MEM->cursor];
                play_sound(5);
                fadescreen_all(1, 0);
                callback1_set(trainerschool_selection_done);
            }
        }else{
            //Handle A;direction keys for opening and switching
            if(super.keys_new.keys.right){
                play_sound(5);
                trainerschool_selection_delete_species_text();
                oams[TSS_MEM->pokeball_oams[TSS_MEM->cursor]].private[2] = 0;
                TSS_MEM->cursor++;
                if(TSS_MEM->cursor == 3) TSS_MEM->cursor = 0;
                trainerschool_selection_show_species_text();
                oams[TSS_MEM->pokeball_oams[TSS_MEM->cursor]].private[2] = 1;
                
            }else if(super.keys_new.keys.left){
                play_sound(5);
                trainerschool_selection_delete_species_text();
                oams[TSS_MEM->pokeball_oams[TSS_MEM->cursor]].private[2] = 0;
                TSS_MEM->cursor--;
                if(TSS_MEM->cursor == 0xFF) TSS_MEM->cursor = 2;
                trainerschool_selection_show_species_text();
                oams[TSS_MEM->pokeball_oams[TSS_MEM->cursor]].private[2] = 1;
            }else if(super.keys_new.keys.A){
                trainerschool_selection_select();
            }
        }
    }
    
}

void trainerschool_selection_init_components(){
    generic_callback1();
    if(!fading_is_active()){
        //init gfx and stuff
        
        big_callback_delete_all();
        oam_reset();
        oam_palette_allocation_reset();
        bg_reset(0);
        bg_setup(0, trainerschool_selection_bg_configs, 4);
        
        bg_sync_display_and_show(0);
        bg_sync_display_and_show(1);
        bg_sync_display_and_show(2);
        bg_sync_display_and_show(3);
        bg_display_sync();
        bg_virtual_map_displace(0, 0, 0);
        bg_virtual_set_displace(0, 0, 0);
        bg_virtual_map_displace(1, 0, 0);
        bg_virtual_set_displace(1, 0, 0);
        bg_virtual_map_displace(2, 0, 0);
        bg_virtual_set_displace(2, 0, 0);
        bg_virtual_map_displace(3, 0, 0);
        bg_virtual_set_displace(3, 0, 0);
        io_set(0x10, 0);
        io_set(0x12, 0);
        io_set(0x14, 0);
        io_set(0x16, 0);
        io_set(0x18, 0);
        io_set(0x1A, 0);
        io_set(0x1C, 0);
        io_set(0x1E, 0);
        
        void *bg0map = malloc_and_clear(0x800);
        void *bg1map = malloc_and_clear(0x800);
        void *bg2map = malloc_and_clear(0x800);
        void *bg3map = malloc_and_clear(0x800);
        
        bg_set_tilemap(0, bg0map);
        bg_set_tilemap(1, bg1map);
        bg_set_tilemap(2, bg2map);
        bg_set_tilemap(3, bg3map);
        
        
        lz77uncompvram(gfx_trainerschool_selection_frontTiles, (void*) 0x0600C000);
        lz77uncompwram(gfx_trainerschool_selection_frontMap, bg1map);
        lz77uncompvram(gfx_trainerschool_selection_middleTiles, (void*) 0x06004000);
        lz77uncompwram(gfx_trainerschool_selection_middleMap, bg2map);
        lz77uncompvram(gfx_trainerschool_selection_backTiles, (void*) 0x06000000);
        lz77uncompwram(gfx_trainerschool_selection_backMap, bg3map);
        
        
        bg_copy_vram(0, bg0map, 0x800, 0, 2);
        bg_copy_vram(1, bg1map, 0x800, 0, 2);
        bg_copy_vram(2, bg2map, 0x800, 0, 2);
        bg_copy_vram(3, bg3map, 0x800, 0, 2);
        

        tbox_sync_with_virtual_bg_and_init_all(trainerschool_selection_tboxes);
        
        oam_load_graphic(graphic_trainerschool_selection_pokeball);
        oam_load_graphic(&graphic_trainerschool_selection_lockschal);
        oam_load_graphic(&graphic_trainerschool_selection_weluno);
        oam_load_graphic(&graphic_trainerschool_selection_seekid);
        
        u8 pal_id;
        pal_id = oam_allocate_palette(0xA440);
        pal_decompress(gfx_trainerschool_lockschalPal, (u16)(256 + pal_id * 16), 32);
        pal_id = oam_allocate_palette(0xA441);
        pal_decompress(gfx_trainerschool_welunoPal, (u16)(256 + pal_id * 16), 32);
        pal_id = oam_allocate_palette(0xA442);
        pal_decompress(gfx_trainerschool_seekidPal, (u16)(256 + pal_id * 16), 32);
        pal_id = oam_allocate_palette(palette_trainerschool_selection_pokeball->tag);
        pal_decompress(palette_trainerschool_selection_pokeball->pal, (u16)(256 + pal_id * 16), 32);
        pal_decompress(gfx_trainerschool_selection_frontPal, 0, 32);
        pal_set_all_to_black(); //we avoid the 1frame show of a pal
        
        oam_new_forward_search(&oam_template_trainerschool_lockschal, 52, 108, 0);
        oam_new_forward_search(&oam_template_trainerschool_weluno, 120, 114, 0);
        oam_new_forward_search(&oam_template_trainerschool_seekid, 188, 108, 0);
        s16 coords[3] = {52, 120, 188};
        int i;
        for(i = 0; i < 3; i++)
            TSS_MEM->pokeball_oams[i] = oam_new_forward_search(&oam_template_trainerschool_pokeball, coords[i], 72, 0);
        
        oams[TSS_MEM->pokeball_oams[TSS_MEM->cursor]].private[2] = 1;
        trainerschool_selection_show_species_text();
        
        fadescreen_all(0, 0);
        callback1_set(trainerschool_selection_idle);

        bg_virtual_sync(0);
        bg_virtual_sync(1);
        bg_virtual_sync(2);
        bg_virtual_sync(3);
        
        io_set(0x48, 0x1F3F);
        io_set(0x50, 0x3F41);
        io_set(0x52, 0x060F);
        
        
    }
}

void trainerschool_selection_init(){
    generic_callback1();
    gp_stack_push((int)malloc_and_clear(sizeof(trainerschool_selection_memory)));
    TSS_MEM->cursor = 1;
    fadescreen_all(1, 0);
    callback1_set(trainerschool_selection_init_components);
    setflag(MAP_BGN_AUTO_ALIGN_OFF);
}
