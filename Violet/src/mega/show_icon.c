#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "mega.h"
#include "color.h"
#include "bios.h"

extern const unsigned gfx_mega_triggerTiles[];
extern const unsigned gfx_mega_triggerPal[];
extern const unsigned gfx_regent_triggerTiles[];
extern const unsigned gfx_regent_triggerPal[];

static sprite icon_sprite = {0x400, 0xC000, 0x400, 0};
static graphic icon_graphic = {gfx_mega_triggerTiles, 0x800, MEGA_ICON_TAG};
static graphic regent_graphic = {gfx_regent_triggerTiles, 0x800, MEGA_ICON_TAG + 1};

static oam_template icon_template = {
    MEGA_ICON_TAG,
    MEGA_ICON_TAG,
    &icon_sprite,
    (gfx_frame**) 0x08231Bc0,
    (graphic*) 0,
    (rotscale_frame**) 0x08231Bcc,
    icon_callback
};

static oam_template icon_template_reg = {
    MEGA_ICON_TAG + 1,
    MEGA_ICON_TAG + 1,
    &icon_sprite,
    (gfx_frame**) 0x08231Bc0,
    (graphic*) 0,
    (rotscale_frame**) 0x08231Bcc,
    icon_callback
};

void mega_show_icon() {

    //checking if active pokemon can mega evolve and is not mega evolved yet
    u8 active_poke = *((u8*) 0x02023BC4);

    battler *b = &battlers[active_poke];
    mega_table_entry *mega_entry;
    //check the pp of the poke
    int i, pp_sum = 0;
    for(i = 0; i < 4; i++) pp_sum += b->current_pp[i];

    if ((mega_entry = get_mega_if_can_mega_evolve(b)) && (can_player_trigger_mega() & pp_sum)) { //                                  TODO: player must also be able to perform mega!

        const u32 *palette = (mega_entry->regent == 1) ? gfx_regent_triggerPal : gfx_mega_triggerPal;
        graphic *g = (mega_entry->regent == 1) ? &regent_graphic : &icon_graphic;
        u16 paltag = (mega_entry->regent == 1) ? (u16) (MEGA_ICON_TAG + 1) : MEGA_ICON_TAG;
        oam_template *temp = (mega_entry->regent == 1) ? &icon_template_reg : &icon_template;

        u8 palid = oam_palette_get_index(paltag);
        if (palid == 0xFF) {
            palid = oam_allocate_palette(paltag);
            lz77uncompwram(palette, (u32*) (0x020373F8 + (palid << 5)));
            lz77uncompwram(palette, (u32*) (0x020377F8 + (palid << 5)));
        }

        if (oam_vram_get_tile(g->tag) == 0xFFFF) {
            oam_load_graphic(g);
        }
        u8 oid = oam_new_forward_search(temp, 0x4C, 0x70, 0);
        oam_object* oam = &oams[oid];
        oam->private[2] = palid;

        *((u16*) (0x020370D0)) = (u16) oid;

    }


}

mega_table_entry *get_mega_if_can_mega_evolve(battler *b) {
    
    int i = 0;
    u16 s;
    do {
        s = megas[i].species;
        if (s == b->species) {
            if (megas[i].item == b->item) {
                
                
                return &megas[i];
            }
        }
        i++;
    } while (s != 0xFFFF);
    return (mega_table_entry*) 0;
}

/**
/  Checks if b can mega evolve
/	@b: checks if b can mega evolve
/  @return: returns 0xFFFF if b cannot mega evolve
 **/
u16 can_mega_evolve(battler *b) {
    int i = 0;
    u16 s;
    do {
        s = megas[i].species;
        if (s == b->species) {
            if (megas[i].item == b->item) {
                return megas[i].target;
            }
        }
        i++;
    } while (s != 0xFFFF);
    return 0xFFFF;
}

void icon_callback(oam_object *self) {

    switch (self->private[0]) {
        case 0:
        {

            //Move the oam upwards
            if (self->private[1] >= 32) {
                self->private[0] = 1;
            } else {
                self->private[1] = (u16) (self->private[1] + 4);
                self->y2 = (s16) (self->y2 - 4);
            }
            break;
        }

        case 1:
        {

            //getting the palette
            u16 palid = self->private[2];
            color white = {.value = 0x7FFF};
            pal_blend((u16) (0x100 + palid * 0x10), 0x7, (u8) (self->private[4]) >> 1, white);
            if (!self->private[3]) {
                //we rise the color bits
                if (self->private[4] >= 16) {
                    self->private[3] = 1;
                } else {
                    self->private[4] = (u8) (self->private[4] + 1);
                }

            } else {
                //we lower the color bits
                if (self->private[4] == 0) {
                    self->private[3] = 0;
                } else {
                    self->private[4] = (u8) (self->private[4] - 1);
                }
            }
            break;
        }

        case 2:
        {

            //move the oam downwards
            if (self->private[1] == 0) {
                //delete the oam
                oam_clear(self);
            } else {
                self->private[1] = (u16) (self->private[1] - 4);
                self->y2 = (s16) (self->y2 + 4);
            }
            break;
        }

    }
}
