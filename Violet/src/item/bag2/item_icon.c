#include "types.h"
#include "oam.h"
#include "item/bag2.h"
#include "bios.h"
#include "item/item.h"

static void bag_oam_item_callback_update(oam_object *self) {
    switch (self->private[1]) {
        case 0: {
            const u8 *pal = item_get_resource(self->private[0], true);
            pal_decompress(pal, (u16)(256 + 16 * BAG2_STATE->pal_idx_item), 16 * sizeof(color_t));
            break;
        }
        case 1: {
            u16 tile = BAG2_STATE->oam_item_base_tile;
            const u8 *gfx = item_get_resource(self->private[0], false);
            lz77uncompwram(gfx, gp_tmp_buf);
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    cpuset(gp_tmp_buf + (3 * y + x) * GRAPHIC_SIZE_4BPP(8, 8), (u8*)OAMCHARBASE(tile) + (4 * y + x) * GRAPHIC_SIZE_4BPP(8, 8),
                        CPUSET_COPY | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8) | CPUSET_HALFWORD));
                }
            }
            break;
        }
        default: {
            self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
            self->callback = oam_null_callback;
            break;
        }
    }
    self->private[1]++;
}

void bag_update_item(u16 slot) {
    u8 pocket = bag_get_current_pocket();
    u16 item_idx;
    if (slot == BAG2_STATE->pocket_size[pocket])
        item_idx = ITEM_NA;
    else
        item_idx = item_get_idx_by_pocket_position(pocket, slot);
    oam_object *o = oams + BAG2_STATE->oam_idx_item;
    o->flags |= OAM_FLAG_INVISIBLE;
    o->private[0] = item_idx;
    o->private[1] = 0;
    o->callback = bag_oam_item_callback_update;
}