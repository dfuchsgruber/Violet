#include "types.h"
#include "item/item.h"
#include "crafting.h"
#include "vars.h"
#include "debug.h"
#include "bios.h"
#include "agbmemory.h"
#include "transparency.h"
#include "options.h"
#include "language.h"

static bool recipe_get_by_flag(u16 flag, const crafting_recipe **result) {
    bool ambiguos = false;
    *result = NULL;
    for (u16 type = 0; type < CRAFTING_TYPE_CNT; type++) {
        const crafting_recipe *recipies = crafting_recipies_get_by_type(type);
        size_t num_recipies = crafting_get_num_recipies_by_type(type);
        for (u16 idx = 0; idx < num_recipies; idx++) {
            if (recipies[idx].flag == flag) {
                if (*result)
                    ambiguos = true;
                *result = recipies + idx;
            }
        }
    }
    return ambiguos;
}

static u16 recipe_get_item_idx_by_flag(u16 flag) {
    const crafting_recipe *recipe;
    bool ambiguos = recipe_get_by_flag(flag, &recipe);
    if (ambiguos)
        return RECIPE_FLAG_AMBIGUOUS;
    else
        return recipe->item;
}


void overworld_recipe_buffer_name() {
    u16 flag = *var_access(0x8004);
    u16 item_idx = recipe_get_item_idx_by_flag(flag);
    if (item_idx == RECIPE_FLAG_AMBIGUOUS) {
        ERROR("Ambiguous recipe flag %d\n", flag);
    } else if (item_idx == 0) {
        ERROR("No recipe matching with flag %d\n", flag);
    }
    strcpy(buffer0, item_get_name(item_idx));
}

#define RECIPE_ITEM_TAG 0xB111

static const sprite sprite_item_obtain = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0)
    };

static const oam_template template_recipe_item = {
    .tiles_tag = RECIPE_ITEM_TAG, .pal_tag = RECIPE_ITEM_TAG,
    .oam = &sprite_item_obtain, .graphics = NULL, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static const tboxdata tbox_template_recipe_transparent = {
    .bg_id = 0, .x = 1, .y = 1, .w = 28, .h = 13, .pal = 15, .start_tile = 44
};


static const tboxdata tbox_template_recipe_non_transparent = {
    .bg_id = 0, .x = 1, .y = 2, .w = 28, .h = 13, .pal = 15, .start_tile = 44
};

static const u8 str_cross[] = PSTRING("x ");
static const u8 str_ash[] = LANGDEP(PSTRING("Asche"), PSTRING("Ash"));
static const u8 str_recipe_for[] = LANGDEP(PSTRING("Rezept für BUFFER_1:"), PSTRING("Recipe for BUFFER_1:"));

void recipe_obtain_show() {
    const crafting_recipe *recipe;
    bool ambigious = recipe_get_by_flag(*var_access(0x8004), &recipe);
    u8 box_id;
    tbox_font_colormap fontcolmap = {1, 2, 1, 3};
	if (item_obtain_should_show_description() && (!ambigious)) {
		if (transparency_is_on()) {
			const tboxdata *tbdata =  &tbox_template_recipe_transparent;
			box_id = tbox_new(tbdata);
			tbox_flush_set(box_id, 0x11);
			tbox_tilemap_draw(box_id);
			tbox_clear_bottom_line(box_id);
			tbox_print_string(box_id, 0, 32 + 4, 2 + 56, 0, 0, &fontcolmap, 0,
				item_get_description(recipe->item));
			item_obtain_tb_id = box_id;
		} else {
			const tboxdata *tbdata = &tbox_template_recipe_non_transparent;
			box_id = tbox_new(tbdata);
			tbox_flush_set(box_id, 0x11);
			tbox_tilemap_draw(box_id);
			tbox_init_frame_message(box_id, 1, 15 * 16);
			tbox_frame_draw_outer(box_id, 1, 0xF);
			tbox_print_string(box_id, 0, 32 + 4, 2 + 56, 0, 0, &fontcolmap, 0,
				item_get_description(recipe->item));
			item_obtain_tb_id = box_id;
		}
        // Write out the recipe
        for (size_t i = 0; i < MAX_NUM_INGREDIENTS; i++) {
            if (recipe->ingredients[i].count > 0) {
                const u8 *name;
                int count;
                switch (recipe->ingredients[i].type) {
                    case CRAFTING_INGREDIENT_ITEM: {
                        name = item_get_name(recipe->ingredients[i].item);
                        count = recipe->ingredients[i].count;
                        break;
                    }
                    case CRAFTING_INGREDIENT_ASH: {
                        name = str_ash;
                        count = recipe->ingredients[i].count * CRAFTING_INGREDIENT_ASH_MULTIPLIER;
                        break;
                    }
                    default:
                        continue;
                }   
                // tbox_print_string(box_id, 0, 
                //     (u16)(32 + 4 + 28 + 96 * (i / 2)), 
                //     (u16)(4 + 16 * (i % 2)),
                //     0, 0, &fontcolmap, 0xFF, name);
                itoa(strbuf, count, ITOA_NO_PADDING, 4);
                strcat(strbuf, str_cross);
                strcat(strbuf, name);
                tbox_print_string(box_id, 0, 
                    (u16)(32 + 4 + 96 * (i / 2)), 
                    (u16)(4 + 16 + 16 * (i % 2)),
                    0, 0, &fontcolmap, 0xFF, 
                    strbuf); 
            }
        }
        strcpy(buffer0, item_get_name(recipe->item));
        string_decrypt(strbuf, str_recipe_for);
        tbox_print_string(box_id, 0, 4, 0, 0, 0, &fontcolmap, 0, strbuf);

		// Create the oam
		u16 tile = oam_vram_get_tile(RECIPE_ITEM_TAG);
		if (tile == 0xFFFF) {
			u16 num_tiles = GRAPHIC_SIZE_4BPP(32, 32) / GRAPHIC_SIZE_4BPP(8, 8);
			tile = oam_vram_alloc(num_tiles);
			oam_vram_allocation_table_add(RECIPE_ITEM_TAG, tile, num_tiles);
		}
		const u8 *gfx = item_get_resource(recipe->item, false);
		lz77uncompwram(gfx, gp_tmp_buf);
		int zero = 0;
		cpuset(&zero, (u8*)OAMCHARBASE(tile), CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(32, 32)));
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				cpuset(gp_tmp_buf + (3 * y + x) * GRAPHIC_SIZE_4BPP(8, 8), (u8*)OAMCHARBASE(tile) + (4 * y + x) * GRAPHIC_SIZE_4BPP(8, 8),
					CPUSET_COPY | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8) | CPUSET_HALFWORD));
			}
		}
		u8 pal_idx = oam_palette_get_index(RECIPE_ITEM_TAG);
		if (pal_idx == 0xFF) {
			pal_idx = oam_allocate_palette(RECIPE_ITEM_TAG);
			const u8 *pal = item_get_resource(recipe->item, true);
			pal_decompress(pal, (u16)(256 + 16 * pal_idx), sizeof(color_t) * 16);
		}
		u8 oam_idx = oam_new_forward_search(&template_recipe_item, 24 + 4, 
			64 + 4, 1);
		item_obtain_oam_id = oam_idx;
	} else {
		item_obtain_tb_id = 0x10;
		item_obtain_oam_id = NUM_OAMS;
	}
}

