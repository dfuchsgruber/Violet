#include "types.h"
#include "mugshot.h"
#include "oams.h"
#include "romfuncs.h"
#include "callbacks.h"
#include "utils.h"
#include "color.h"
#include "save.h"
#include "gfx.h"

#define MUGSHOT_BASE_TAG 0x1340

static sprite mugshot_sprite = {0, 0xC000, 0x400, 0};

static mugshot mugshots[] = {
    {(void*) 0x93d6750, (void*) 0x93d6720},
    {(void*) 0x8882bb4, (void*) 0x8883240},
    {&gfx_mug_mistralTiles, &gfx_mug_mistralPal},
    {(void*) 0x8884168, (void*) 0x8884850},
    {(void*) 0x8884bf8, (void*) 0x8885328},
    {(void*) 0x88692e8, (void*) 0x8869a04},
    {(void*) 0x8891f00, (void*) 0x88922b0},
    {(void*) 0x8892388, (void*) 0x88927c8},
    {(void*) 0x9500000, (void*) 0x9500440},
    {(void*) 0x9502350, (void*) 0x95026f0},
    {(void*) 0x88b4000, (void*) 0x9502310},
    {(void*) 0x9502730, (void*) 0x9502d10},
    {&gfx_mug_hiroTiles, &gfx_mug_hiroPal},
    {(void*) 0x9503200, (void*) 0x9503640},
    {(void*) 0x9378bf0, (void*) 0x9378f90},
    {(void*) 0x9379000, (void*) 0x93793a0},
    {(void*) 0x938d800, (void*) 0x93c1300},
    {(void*) 0x93c1330, (void*) 0x93c16c0},
    {(void*) 0x93c1700, (void*) 0x93c1a70},
    {(void*) 0x93c4160, (void*) 0x93c45f0},
    {(void*) 0x93d4c30, (void*) 0x93d4c00},
    {(void*) 0x93d50b0, (void*) 0x93d5080},
    {(void*) 0x9399530, (void*) 0x93997c0},
    {(void*) 0x93d54b0, (void*) 0x93d5480},
    {(void*) 0x93d6350, (void*) 0x93d6320},
    {&gfx_mug_igvaTiles, &gfx_mug_igvaPal},
    {&gfx_mug_blackbeardTiles, &gfx_mug_blackbeardPal}
};

void spawn_mugshot() {

    int side = *vardecrypt(0x8000);
    int index = *vardecrypt(0x8001);
    u16 tag = (u16) (MUGSHOT_BASE_TAG + index);

    graphic *mugshot_tmp_graphic = (graphic*) malloc(sizeof (graphic));
    mugshot_tmp_graphic->sprite = mugshots[index].gfx;
    mugshot_tmp_graphic->size = 0x800;
    mugshot_tmp_graphic->tag = tag;

    u8 pal = allocate_obj_pal(tag);
    u16 *pal_buf = (u16*) malloc(32);
    lz77uncompwram(mugshots[index].pal, pal_buf);
    //apply weather effects to pal
    u8 weather = get_current_weather();

    pal_load_uncomp(pal_buf, (u16) (0x100 + 16 * pal), 32);

    if (weather == WEATHER_CLOUDY || weather == WEATHER_HEAVY_RAIN || weather == WEATHER_RAIN || weather == WEATHER_STORM) {
        //fade
        u16 *dma3s = (u16*) 0x020375F8;
        int i;
        for (i = 0; i < 16; i++) {
            u16 original = dma3s[i + (pal + 0x10)*0x10];
            color co = {original};
            color over = {0}; //black
            color n = alpha_blend(co, over, 3);
            dma3s[i + (pal + 0x10)*0x10] = n.value;
        }
    }

    free(pal_buf);

    //allocating vram for the tiles
    if (get_id_of_vramobj_alloc_list_element(tag) == 0xFF) {
        load_and_alloc_obj_vram_lz77(mugshot_tmp_graphic);
    }
    s16 x = (s16) (0x20 + side * 0xB0);

    //spawn a template obj
    oam_template *mugshot_template = (oam_template*) malloc(sizeof (oam_template));
    mugshot_template->tiles_tag = tag;
    mugshot_template->pal_tag = tag;
    mugshot_template->oam = &mugshot_sprite;
    mugshot_template->graphics = NULL;
    mugshot_template->animation = (gfx_frame**) 0x08231Bc0;
    mugshot_template->rotscale = (rotscale_frame**) 0x08231Bcc;
    mugshot_template->callback = oam_null_callback;
    *vardecrypt(0x8003) = generate_oam_forward_search(mugshot_template, x, 0x50, 0);
}

void mugshot_oam_despawn_cb(u8 self) {
    u16 oam_id = big_callbacks[self].params[0];
    free(oams[oam_id].oam_template->graphics);
    free(oams[oam_id].oam_template);
    oam_despawn(&oams[oam_id]);
    remove_big_callback(self);
}

void clear_mugshot() {
    u16 oam_id = *vardecrypt(0x8003);
    u8 cb_id = spawn_big_callback(mugshot_oam_despawn_cb, 0);
    big_callbacks[cb_id].params[0] = oam_id;
    oams[oam_id].x2 = -64;
}
