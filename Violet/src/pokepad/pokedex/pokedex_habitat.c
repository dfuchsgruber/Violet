#include "types.h"
#include "stdbool.h"
#include "pokepad/pokedex/gui.h"
#include "pokepad/pokedex/habitat.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "mega.h"
#include "pokemon/names.h"
#include "pokemon/basestat.h"
#include "color.h"
#include "superstate.h"
#include "transparency.h"
#include "language.h"
#include "map/namespace.h"
#include "fading.h"
#include "io.h"
#include "agbmemory.h"
#include "bios.h"
#include "worldmap.h"
#include "dma.h"
#include "debug.h"
#include "pokepad/pokedex/state.h"

extern const unsigned short gfx_pokedex_habitat_uiTiles[];
extern const unsigned short gfx_pokedex_habitat_uiMap[];
extern const unsigned short gfx_pokedex_habitat_uiPal[];
extern const unsigned short gfx_pokedex_habitat_maskTiles[];
extern const unsigned short gfx_pokedex_habitat_maskPal[];
extern const unsigned short gfx_pokedex_habitat_type_iconsTiles[];
extern const unsigned short gfx_pokedex_habitat_type_iconsPal[];

extern const unsigned short gfx_hiro_headTiles[];
extern const unsigned short gfx_hiroine_headTiles[];
extern const unsigned short gfx_hiro_headPal[];
extern const unsigned short gfx_hiroine_headPal[];

const bg_config pokedex_bg_habitat_configs [] = {
    {0, 0, 31, 0, 0, 0},
    {1, 0, 30, 0, 0, 2},
    {2, 3, 29, 0, 0, 1},
    {3, 1, 28, 0, 1, 3}
};

const tboxdata pokedex_habitat_tboxes [] = {
    {0, 6, 0, 24, 2, 15, 2}, //Title Line := 0x0
    {0, 1, 0, 5, 2, 15, 50}, //Grass := 0x1
    {0, 1, 4, 5, 2, 15, 60}, //Water := 0x2
    {0, 1, 8, 5, 2, 15, 70}, //Radar := 0x3
    {0, 1, 12, 5, 2, 15, 80}, //Rod := 0x4
    {1, 6, 2, 15, 2, 13, 90}, //Namespace := 0x5 on BG 1
    {1, 9, 10, 20, 2, 13, 120}, //Not found := 0x6 on BG 1
    {0xFF, 0, 0, 0, 0, 0, 0},
};

const graphic pokedex_habitat_cursor_graphic = {
    (void*) 0x083EED38,
    0x100,
    0xA014
};

const graphic pokedex_habitat_male_graphic = {
    gfx_hiro_headTiles,
    0x80,
    0xA015
};

const graphic pokedex_habitat_female_graphic = {
    gfx_hiroine_headTiles,
    0x80,
    0xA015
};

const graphic pokedex_habitat_type_graphic = {
    &gfx_pokedex_habitat_type_iconsTiles,
    0x80 * 9,
    0xA016
};

const sprite pokedex_habitat_cursor_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0)
};

const sprite pokedex_habitat_head_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0)
};

const gfx_frame pokedex_habitat_cursor_gfx_anim[] = {
    {0, 32},
    {4, 32},
    {0xFFFE, 0}
};

const gfx_frame *const pokedex_habitat_cursor_gfx_anim_table[] = {
    pokedex_habitat_cursor_gfx_anim
};

static const gfx_frame pokedex_habitat_type_gfx_frames[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 8, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 12, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 16, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 20, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 24, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 28, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 32, .duration = 0}, {.data = GFX_ANIM_END},
};


static const gfx_frame *const pokedex_habitat_type_gfx_anim_table[] = {
    pokedex_habitat_type_gfx_frames,
    pokedex_habitat_type_gfx_frames + 2,
    pokedex_habitat_type_gfx_frames + 4,
    pokedex_habitat_type_gfx_frames + 6,
    pokedex_habitat_type_gfx_frames + 8,
    pokedex_habitat_type_gfx_frames + 10,
    pokedex_habitat_type_gfx_frames + 12,
    pokedex_habitat_type_gfx_frames + 14,
    pokedex_habitat_type_gfx_frames + 16,
};

const oam_template pokedex_habitat_cursor_template = {
    0xA014,
    0xA014,
    &pokedex_habitat_cursor_sprite,
    pokedex_habitat_cursor_gfx_anim_table,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

const oam_template pokedex_habitat_head_template = {
    0xA015,
    0xA015,
    &pokedex_habitat_head_sprite,
    oam_gfx_anim_table_null,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback
};

static const oam_template pokedex_habitat_type_template = {
    0xA016,
    0xA016,
    &pokedex_habitat_cursor_sprite,
    pokedex_habitat_type_gfx_anim_table,
    NULL,
    oam_rotscale_anim_table_null,
    oam_null_callback
};


const tbox_font_colormap pokedex_fontcolmap_namespace = {3, 2, 1, 0};

const int *const worldmap_tilemaps[4] = {
    (int*) gfx_worldmapMap,
    (int*) 0x083F0354,
    (int*) 0x083F0464,
    (int*) 0x080C0564
};


void pokedex_habitat_draw_scanline(u16 colev) {
	// Initialize the scanline
	for (int i = 0; i < 32; i++) {
		dma0_scanline_frames[0][i] = 0xA0F;
		dma0_scanline_frames[1][i] = 0xA0F;
	}
	for (int i = 32; i < 240; i++) {
		dma0_scanline_frames[0][i] = colev;
		dma0_scanline_frames[1][i] = colev;
	}
	dma0_scanline_flipflop_t flipflop = {.bytes = {.flipflop_cntrl = 1, .defaults_field_16_17 = 0}};
	dma0_init_scanline((void*)0x04000052,
			DMA_ENABLE | DMA_TIMING_HBLANK | DMA_REPEAT | DMA_SRC_INCREMENT | DMA_DST_RELOAD |
			DMA_SIZE(1),
			flipflop);
}

void pokedex_init_habitat() {
    generic_callback1();
    if (!fading_is_active()) {

        //we find the current worldmap
        int i, j;
        pokedex_state->current_worldmap = 0;

        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free(bg_get_tilemap(2));
        free(bg_get_tilemap(3));
        oam_reset();
        bg_reset(0);
        oam_reset();
        big_callback_delete_all();
        fading_cntrl_reset();
        oam_palette_allocation_reset();
        tbox_free_all();
        vblank_handler_set(NULL);
        bg_reset(0);
        bg_setup(0, pokedex_bg_habitat_configs, 4); //we use same configs as we want to use each bg seperatly

        void *bg0map = malloc_and_clear(0x800);
        void *bg1map = malloc_and_clear(0x800);
        void *bg2map = malloc_and_clear(0x800);
        u16 *bg3map = malloc_and_clear(0x800);
        bg_set_tilemap(0, bg0map);
        bg_set_tilemap(1, bg1map);
        bg_set_tilemap(2, bg2map);
        bg_set_tilemap(3, bg3map);

        io_set(0x10, 0);
        io_set(0x12, 0);
        io_set(0x14, 0);
        io_set(0x16, 0);
        io_set(0x18, 0);
        io_set(0x1A, 0);
        io_set(0x1C, (u16) (-24));
        io_set(0x1E, 0);

        dma0_reset_callback();
        pokedex_habitat_draw_scanline(0x1F0F);

        u16 *gp_tmp = (u16*) 0x0201C000;

        lz77uncompvram(gfx_worldmapTiles, (void*) 0x06004000);
        lz77uncompwram(worldmap_tilemaps[pokedex_state->current_worldmap], gp_tmp);
        lz77uncompvram(gfx_pokedex_habitat_uiTiles, (void*) 0x0600C000);
        lz77uncompwram(gfx_pokedex_habitat_uiMap, bg2map);
        lz77uncompvram(gfx_pokedex_habitat_maskTiles, (void*) 0x06000000);


        //unpack the tilemap to 32 width
        for (i = 0; i < 20; i++) {
            //line loop
            for (j = 0; j < 32; j++) {
                //col loop
                bg3map[i * 32 + j] = j < 30 ? gp_tmp[i * 30 + j] : 0;
            }
        }
        pokedex_habitats_load_for_species(bg1map);

        //Tboxes
        tbox_sync_with_virtual_bg_and_init_all(pokedex_habitat_tboxes);

        tbox_flush_set(0, 0);
        tbox_tilemap_draw(0);
        u8 str_title[] = LANGDEP(PSTRING(" Fundorte v. "), PSTRING(" Habitats of "));
        u8 *title = strcpy(strbuf, str_title);
        title = strcat(title, pokemon_names[pokedex_state->current_species]);
        tbox_print_string(0, 2, 0, 0, 0, 0, &pokedex_fontcolmap, 0, strbuf);
        u8 str_back[] = LANGDEP(PSTRING("KEY_B Zur."), PSTRING("KEY_B Back"));
        tbox_print_string(0, 2, 144, 0, 0, 0, &pokedex_fontcolmap, 0, str_back);

        tbox_flush_set(1, 0);
        tbox_tilemap_draw(1);
        u8 str_habitat_grass[] = LANGDEP(PSTRING(" Natur"), PSTRING(" Nature"));
        tbox_print_string(1, 2, 0, 0, 0, 0, &pokedex_fontcolmap, 0, str_habitat_grass);

        tbox_flush_set(2, 0);
        tbox_tilemap_draw(2);
        u8 str_habitat_water[] = LANGDEP(PSTRING(" Wasser"), PSTRING(" Water"));
        tbox_print_string(2, 2, 0, 0, 0, 0, &pokedex_fontcolmap, 0, str_habitat_water);

        tbox_flush_set(3, 0);
        tbox_tilemap_draw(3);
        u8 str_habitat_rod[] = LANGDEP(PSTRING(" Radar"), PSTRING(" Radar"));
        tbox_print_string(3, 2, 0, 0, 0, 0, &pokedex_fontcolmap, 0, str_habitat_rod);

        tbox_flush_set(4, 0);
        tbox_tilemap_draw(4);
        u8 str_habitat_radar[] = LANGDEP(PSTRING(" Angel"), PSTRING(" Rod"));
        tbox_print_string(4, 2, 0, 0, 0, 0, &pokedex_fontcolmap, 0, str_habitat_radar);

        //pal
        pal_copy(gfx_worldmapPal, 0, 4 * 16);
        pal_decompress(gfx_pokedex_habitat_uiPal, 4 * 16, 32);
        pal_decompress(gfx_pokedex_habitat_maskPal, 5 * 16, 32);
        pal_copy((void*) 0x83EEAB2, (u16) ((16 + oam_allocate_palette(0xA014))*16), 30);
        pal_decompress(gfx_pokedex_habitat_type_iconsPal, (u16) ((16 + oam_allocate_palette(0xA016))*16), 32);
        const void *head_pal = save2->player_is_female ? gfx_hiroine_headPal : gfx_hiro_headPal;
        pal_copy(head_pal, (u16) ((16 + oam_allocate_palette(0xA015))*16), 32);
        pal_copy(tbox_palette_transparent, 16 * 13, 32);
        pal_set_all_to_black();

        //oam
        s16 origin_x = (s16) ((pokedex_state->habitat_cursor_x + 7) * 8 + 4);
        s16 origin_y = (s16) ((pokedex_state->habitat_cursor_y + 4) * 8 + 4);
        if (save2->player_is_female) {
            oam_load_graphic(&pokedex_habitat_female_graphic);
        } else {
            oam_load_graphic(&pokedex_habitat_male_graphic);
        }
        pokedex_state->oam_habitat_head = oam_new_forward_search(&pokedex_habitat_head_template, origin_x, origin_y, 1);
        oam_load_graphic(&pokedex_habitat_type_graphic);

        for (i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (i >= HABITAT_TYPE_ROD) {
                    pokedex_state->habitat_oams_rarity[i][j] = oam_new_forward_search(
                        &pokedex_habitat_type_template, (s16) (8 + j * 16), (s16)(120 + (i - HABITAT_TYPE_ROD) * 16), 0);
                } else {
                    pokedex_state->habitat_oams_rarity[i][j] = oam_new_forward_search(
                        &pokedex_habitat_type_template, (s16) (8 + j * 16), (s16) (16 + i * 32 + 6), 0);
                }
                oams[pokedex_state->habitat_oams_rarity[i][j]].flags |= OAM_FLAG_INVISIBLE;
            }
            
        }
        oam_load_graphic(&pokedex_habitat_cursor_graphic);
        pokedex_state->oam_habitat_cursor = oam_new_forward_search(&pokedex_habitat_cursor_template, origin_x, origin_y, 0);

        pokedex_habitats_update();

        callback1_set(pokedex_habitat_callback_idle);
        vblank_handler_set(generic_vblank_handler);
        pokedex_state->habitat_cursor_is_moving = false;
        fadescreen_all(0, 0);

        bg_virtual_sync(0);
        bg_virtual_sync(1);
        bg_virtual_sync(2);
        bg_virtual_sync(3);

        bg_sync_display_and_show(0);
        bg_sync_display_and_show(1);
        bg_sync_display_and_show(2);
        bg_sync_display_and_show(3);

        bg_display_sync();

        io_set(0x50, 0x3F42);
        io_set(0x52, 0xA0F);
    }
}

void pokedex_habitat_big_callback_cursor_movement(u8 self) {
    oam_object *obj = &oams[pokedex_state->oam_habitat_cursor];
    switch (big_callbacks[self].params[0]) {
        case 0: //down
            obj->y2 = (s16) (obj->y2 + 2);
            break;
        case 1:
            obj->y2 = (s16) (obj->y2 - 2);
            break;
        case 2:
            obj->x2 = (s16) (obj->x2 - 2);
            break;
        case 3:
            obj->x2 = (s16) (obj->x2 + 2);
            break;
    }
    if (!--big_callbacks[self].params[1]) {
        pokedex_habitats_update();
        pokedex_state->habitat_cursor_is_moving = false;
        big_callback_delete(self);
    }

}

void pokedex_habitat_callback_idle() {
    generic_callback1();
    if (!fading_is_active() && !pokedex_state->habitat_cursor_is_moving) {
        if (pokedex_state->habitat_fading_countdown) {
            pokedex_state->habitat_fading_countdown--;
        } else {
            //process the habitat fading
            if (pokedex_state->habitat_fading_mode) {
                if (!--pokedex_state->habitat_fading_index)
                    pokedex_state->habitat_fading_mode = 0;
            } else {
                if (++pokedex_state->habitat_fading_index == 8)
                    pokedex_state->habitat_fading_mode = 1;
            }
				if (pokedex_state->habitat_found) {
				int ea = pokedex_state->habitat_fading_index;
				int eb = 16 - ea;
				u16 colev = (u16)((eb << 8) | ea);
				pokedex_habitat_draw_scanline(colev);
            } else {
            	// Standard transparency always
				pokedex_habitat_draw_scanline(0xA0F);
            }
            pokedex_state->habitat_fading_countdown = 2;
        }

        u8 cb_id;
        if (super.keys.keys.down && pokedex_state->habitat_cursor_y < 14) {
            cb_id = big_callback_new(pokedex_habitat_big_callback_cursor_movement, 0);
            big_callbacks[cb_id].params[1] = 4;
            big_callbacks[cb_id].params[0] = 0;
            pokedex_state->habitat_cursor_is_moving = true;
            pokedex_state->habitat_cursor_y++;
        } else if (super.keys.keys.up && pokedex_state->habitat_cursor_y) {
            cb_id = big_callback_new(pokedex_habitat_big_callback_cursor_movement, 0);
            big_callbacks[cb_id].params[1] = 4;
            big_callbacks[cb_id].params[0] = 1;
            pokedex_state->habitat_cursor_is_moving = true;
            pokedex_state->habitat_cursor_y--;
        } else if (super.keys.keys.left && pokedex_state->habitat_cursor_x) {
            cb_id = big_callback_new(pokedex_habitat_big_callback_cursor_movement, 0);
            big_callbacks[cb_id].params[1] = 4;
            big_callbacks[cb_id].params[0] = 2;
            pokedex_state->habitat_cursor_is_moving = true;
            pokedex_state->habitat_cursor_x--;
        } else if (super.keys.keys.right && pokedex_state->habitat_cursor_x < 21) {
            cb_id = big_callback_new(pokedex_habitat_big_callback_cursor_movement, 0);
            big_callbacks[cb_id].params[1] = 4;
            big_callbacks[cb_id].params[0] = 3;
            pokedex_state->habitat_cursor_is_moving = true;
            pokedex_state->habitat_cursor_x++;
        } else if (super.keys.keys.B) {
            fadescreen_all(1, 0);
            free(pokedex_state->habitats);
            pokedex_state->entry_skip_cry = true;
            callback1_set(pokedex_callback_init_entry);
        }
    }
}

void pokedex_habitats_load_for_species(u16 *bg1map) {
    pokedex_habitat_pair *habitats = malloc(sizeof(pokedex_habitat_pair) * 6 * 22 * 15 * 7);
    pokedex_state->habitats = habitats;
    int habitat_size = pokedex_get_habitats_of_species(habitats, pokedex_state->current_species);
    pokedex_state->habitat_size = habitat_size;
    pokedex_state->habitat_found = false;

    // Locate the player on the map (use the old worldmap routine)
    worldmap_state_t *wm_state = malloc(sizeof(worldmap_state));
    worldmap_state = wm_state;
    worldmap_locate_player();

    u8 i, j, k, l;
    for (i = 0; i < 18; i++) {
        for (j = 0; j < 22; j++) {
            for (k = 0; k < 1; k++) {
                u8 namespace = worldmap_get_namespace_by_pos(pokedex_state->current_worldmap, (u8) k, (u16) i, (u16) j);
                if (namespace != MAP_NAMESPACE_NONE) {
                    //Lets check if the namespace is present in our list
                    if (j == worldmap_state->cursor_x && i == worldmap_state->cursor_y) {
                        pokedex_state->habitat_cursor_x = j;
                        pokedex_state->habitat_cursor_y = i;
                    }
                    for (l = 0; l < habitat_size; l++) {
                        if (habitats[l].worldmap_x == j && habitats[l].worldmap_y == i) {
                        	// Set red block
                            bg1map[(i + 4) * 32 + j + 7] = 0x5001;
                            pokedex_state->habitat_found = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    free(wm_state);
}

void pokedex_habitats_load_namespace() {
    u8 str_blank [] = {0, 0, 0xFF};
    u8 namespace = worldmap_get_namespace_by_pos(pokedex_state->current_worldmap, 0, pokedex_state->habitat_cursor_y, pokedex_state->habitat_cursor_x);
    if (namespace != 0xC5) {
        strcat(strcat(strcpy(strbuf, str_blank), map_namespaces[namespace - 0x58]), str_blank);
    } else {
        *strbuf = 0xFF;
    }
    tbox_flush_set(5, 0);
    tbox_tilemap_draw(5);
    tbox_print_string(5, 2, 0, 1, 0, 0, &pokedex_fontcolmap_namespace, 0, strbuf);

    //print the not found string
    if (!pokedex_state->habitat_found) {
        u8 str_habitat_none[] = LANGDEP(PSTRING(" Keine Gebiete bekannt"), PSTRING("No habitats known"));
        strcat(strcat(strcpy(strbuf, str_blank), str_habitat_none), str_blank);
        tbox_flush_set(6, 0);
        tbox_tilemap_draw(6);
        tbox_print_string(6, 2, 0, 0, 0, 0, &pokedex_fontcolmap_namespace, 0, strbuf);
    }
}

void pokedex_habitats_update() {
    pokedex_habitats_load_namespace();
    //update the rarity oams
    pokedex_habitat_pair *habitats = pokedex_state->habitats;
    DEBUG("Habitats @%x\n", habitats);
    int cursor_x = pokedex_state->habitat_cursor_x;
    int cursor_y = pokedex_state->habitat_cursor_y;
    for (int habitat_type = 0; habitat_type < 6; habitat_type++) {
        for (int map_type = 0; map_type < 3; map_type ++) {
            int probability = 0;
            for (int i = 0; i < pokedex_state->habitat_size; i++) {
                if (habitats[i].worldmap_x == cursor_x && habitats[i].worldmap_y == cursor_y && habitats[i].habitat_type == habitat_type &&
                    habitats[i].map_type == map_type) {
                        probability = habitats[i].probability;
                        break;
                }
            }
            if (probability) {
                int animation_idx;
                if (probability >= 50) animation_idx = 2;
                else if (probability >= 10) animation_idx = 1;
                else animation_idx = 0;
                oams[pokedex_state->habitat_oams_rarity[habitat_type][map_type]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
                oams[pokedex_state->habitat_oams_rarity[habitat_type][map_type]].anim_number = (u8)(3 * animation_idx + map_type);
                oam_gfx_anim_init(oams + pokedex_state->habitat_oams_rarity[habitat_type][map_type], 0);
            } else {
                oams[pokedex_state->habitat_oams_rarity[habitat_type][map_type]].flags |= OAM_FLAG_INVISIBLE;
            }
        }
    }
    (void) cursor_x;
    (void) cursor_y;
}

