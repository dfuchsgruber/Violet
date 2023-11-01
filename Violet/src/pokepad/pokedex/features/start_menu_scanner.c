#include "types.h"
#include "pokepad/pokedex/scanner.h"
#include "agbmemory.h"
#include "pokemon/sprites.h"
#include "debug.h"
#include "bios.h"

#define PAL_TAG_GFX_MENU_SCANNER 0xC29B

EWRAM u8 start_menu_scanner_oam_idxs[POKEDEX_SCANNER_MAX_NUM_UNIQUE_SPECIES] = {0};
EWRAM u8 start_menu_scanner_num_oams = 0;

static const palette palette_greyscale = {
    .pal = gfx_pokemon_icon_greyPal, .tag = PAL_TAG_GFX_MENU_SCANNER,
};

static const sprite sprite_icon = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0),
};

static const oam_template oam_template_icon = {
    .pal_tag = PAL_TAG_GFX_MENU_SCANNER, .oam = &sprite_icon, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

void start_menu_print_scanner() {
    pokedex_scanner_data_t *data = malloc(sizeof(pokedex_scanner_data_t));
    pokedex_scanner_unique_species_list_t *list = malloc(sizeof(pokedex_scanner_unique_species_list_t));
    if (data && list) {
        pokedex_feature_scanner_build_all_entries(data, map_wild_pokemon_get_current());
        pokedex_scanner_build_unique_species(list, data);
        oam_palette_load_if_not_present(&palette_greyscale);
        DEBUG("List size: %d\n", list->size);
        for (start_menu_scanner_num_oams = 0; start_menu_scanner_num_oams < list->size; start_menu_scanner_num_oams++) {
            u16 species = list->list[start_menu_scanner_num_oams];
            DEBUG("Species: %d, idx: %d\n", species, start_menu_scanner_num_oams);
            u16 tag = (u16)(species + PAL_TAG_GFX_MENU_SCANNER);
            if (oam_vram_get_tile(tag) == 0xFFFF) {
                u16 base_tile = oam_vram_alloc(GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 64));
                oam_vram_allocation_table_add(tag, base_tile, GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 64));
                cpuset(pokemon_icons_greyscale[species], OAMCHARBASE(base_tile), CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(32, 64)));
            }
            oam_template template = oam_template_icon;
            template.tiles_tag = tag;
            start_menu_scanner_oam_idxs[start_menu_scanner_num_oams] = oam_new_forward_search(&template,
                (s16)(64 + 32 * (start_menu_scanner_num_oams % START_MENU_SCANNER_ICONS_PER_LINE)),
                (s16)(16 + (start_menu_scanner_num_oams / START_MENU_SCANNER_ICONS_PER_LINE) * 32),
                start_menu_scanner_num_oams
            );
        }
    }
    free(data);
    free(list);    
}

void start_menu_clear_scanner() {
    for (u8 i = 0; i < start_menu_scanner_num_oams; i++) {
        oam_free(&oams[start_menu_scanner_oam_idxs[i]]);
    }
}