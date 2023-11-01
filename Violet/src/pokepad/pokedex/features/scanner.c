#include "types.h"
#include "pokepad/pokedex/gui.h"
#include "pokepad/pokedex/operator.h"
#include "pokepad/pokedex/scanner.h"
#include "map/header.h"
#include "map/wild_pokemon.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "pokemon/sprites.h"
#include "pokemon/names.h"
#include "pokemon/basestat.h"
#include "oam.h"
#include "superstate.h"
#include "math.h"
#include "debug.h"
#include "fading.h"
#include "language.h"
#include "agbmemory.h"
#include "io.h"
#include "bios.h"
#include "music.h"
#include "dma.h"
#include "callbacks.h"
#include "pokepad/pokedex/state.h"
#include "list_menu.h"
#include "constants/items.h"
#include "item/item.h"
#include "menu_indicators.h"

EWRAM pokedex_scanner_state_t *pokedex_scanner_state;

extern const u8 gfx_pokedex_scanner_uiTiles[];
extern const u8 gfx_pokedex_scanner_uiMap[];
extern const u8 gfx_pokedex_scanner_uiPal[];
extern const LZ77COMPRESSED gfx_worldmap_icon_grassTiles;
extern const color_t gfx_worldmap_icon_grassPal[16];
extern const LZ77COMPRESSED gfx_worldmap_icon_waterTiles;
extern const color_t gfx_worldmap_icon_waterPal[16];
extern const LZ77COMPRESSED gfx_worldmap_icon_rodTiles;
extern const color_t gfx_worldmap_icon_rodPal[16];
extern const LZ77COMPRESSED gfx_worldmap_icon_radarTiles;
extern const color_t gfx_worldmap_icon_radarPal[16];
extern const LZ77COMPRESSED gfx_pokedex_scanner_cursorTiles;
extern const color_t gfx_pokedex_scanner_cursorPal[16];
extern const LZ77COMPRESSED gfx_pokedex_scanner_icon_caughtTiles;
extern const color_t gfx_pokedex_scanner_icon_caughtPal[16];

static const color_t pal_black[16] = {0};

static void pokedex_feature_scanner_sort_entries(pokedex_scanner_entry_t *entries, size_t size) {
    // Bubble sort
    for(size_t n = size; n > 1; n--){
        for(size_t i = 0; i < n - 1; i++){
            if(entries[i].percentage < entries[i + 1].percentage) {
                pokedex_scanner_entry_t tmp = entries[i];
                entries[i] = entries[i + 1];
                entries[i + 1] = tmp;
            }
        }
    }
}

static size_t pokedex_feature_scanner_build_entries(const wild_pokemon_entry *wild_entries,
        pokedex_scanner_entry_t *dst, size_t capacity, const u8 pdf[]){
    size_t num_entries = 0;
    for(size_t i = 0; i < capacity; i++){
        u16 key = wild_entries[i].species;
        // Check if this key is already in dst
        size_t in_dst = 0;
        for(size_t j = 0; j < num_entries; j++){
            if(dst[j].species == key){
                dst[j].percentage = (u16)(dst[j].percentage + pdf[i]);
                in_dst = 1;
                break;
            }
        }
        if(!in_dst){
            dst[num_entries].species = key;
            dst[num_entries].percentage = pdf[i];
            num_entries++;
        }
    }
    return num_entries;
}

static void pokedex_feature_scanner_entries_add_roamers() {
    for (int i = 0; i < NUM_ROAMERS; i++) {
        if (csave.roamers[i].is_present && csave.roamer_locations[i].bank == save1->bank && csave.roamer_locations[i].map_idx == save1->map) {
            // 50% probability that the roamer appears, so all percentages must be multiplied by 1/2
            // If multiple roamers were present at this map, only the first roamer appears, so we only list one
            int total_percentage_values = 0;
            for (size_t j = 0; j < pokedex_scanner_state->num_entries[POKEDEX_SCANNER_HABITAT_GRASS]; j++) {
                pokedex_scanner_state->entries_grass[j].percentage = (u16)(MAX(1, pokedex_scanner_state->entries_grass[j].percentage / 2));
                total_percentage_values += pokedex_scanner_state->entries_grass[j].percentage;
            }
            pokedex_scanner_state->entries_grass[pokedex_scanner_state->num_entries[POKEDEX_SCANNER_HABITAT_GRASS]].species = roamer_species[i];
            pokedex_scanner_state->entries_grass[pokedex_scanner_state->num_entries[POKEDEX_SCANNER_HABITAT_GRASS]].percentage = (u8)(100 - total_percentage_values); // Make probabilities sum up to 100 in case of rounding issues
            pokedex_scanner_state->num_entries[POKEDEX_SCANNER_HABITAT_GRASS]++;
        }
    }
}

static inline size_t pokedex_feature_scanner_add_entries_from_wild_pokemon_data(const wild_pokemon_entry *src,
        pokedex_scanner_entry_t *dst, size_t capacity, const u8 pdf[]) {
    size_t num_entries = 0;
    if (src) {
        num_entries = pokedex_feature_scanner_build_entries(src, dst, capacity, pdf);
        pokedex_feature_scanner_sort_entries(dst, num_entries);
    }
    return num_entries;
}

static void pokedex_feature_scanner_build_all_entries(pokedex_scanner_state_t *state){
    const wild_pokemon_data *wild_pokemon_header = map_wild_pokemon_get_current();
    if(!wild_pokemon_header) 
        return;

    if (wild_pokemon_header->grass)
        state->num_entries[POKEDEX_SCANNER_HABITAT_GRASS] = pokedex_feature_scanner_add_entries_from_wild_pokemon_data(
                wild_pokemon_header->grass->data, state->entries_grass, WILD_POKEMON_NUM_ENTRIES_GRASS, wild_pokemon_grass_pdf);
    if (wild_pokemon_header->water)
        state->num_entries[POKEDEX_SCANNER_HABITAT_WATER] = pokedex_feature_scanner_add_entries_from_wild_pokemon_data(
                wild_pokemon_header->water->data, state->entries_water, WILD_POKEMON_NUM_ENTRIES_WATER, wild_pokemon_water_pdf);
    if (wild_pokemon_header->rod)
        state->num_entries[POKEDEX_SCANNER_HABITAT_OTHER] = pokedex_feature_scanner_add_entries_from_wild_pokemon_data(
                wild_pokemon_header->other->data, state->entries_other, WILD_POKEMON_NUM_ENTRIES_OTHER, wild_pokemon_other_pdf);
    if (wild_pokemon_header->rod) {
        // DEBUG("Has rod data\n");
        // Build rod entries with corresponding delimiters
        size_t num_entries_rod = 0;

        // Add rod delimiter and rod entries
        state->entries_rods[num_entries_rod].species = POKEDEX_SCANNER_DELIMITER_ROD;
        state->entries_rods[num_entries_rod].is_delimiter = true;
        num_entries_rod++;
        num_entries_rod += pokedex_feature_scanner_add_entries_from_wild_pokemon_data(
                wild_pokemon_header->rod->data, state->entries_rods + num_entries_rod, WILD_POKEMON_NUM_ENTRIES_ROD, wild_pokemon_rod_pdf);

        // Add good rod delimiter and good rod entries
        state->entries_rods[num_entries_rod].species = POKEDEX_SCANNER_DELIMITER_GOOD_ROD;
        state->entries_rods[num_entries_rod].is_delimiter = true;
        num_entries_rod++;
        num_entries_rod += pokedex_feature_scanner_add_entries_from_wild_pokemon_data(
                wild_pokemon_header->rod->data + WILD_POKEMON_NUM_ENTRIES_ROD, state->entries_rods + num_entries_rod, WILD_POKEMON_NUM_ENTRIES_GOOD_ROD, wild_pokemon_good_rod_pdf);

        // Add super rod delimiter and super rod entries
        state->entries_rods[num_entries_rod].species = POKEDEX_SCANNER_DELIMITER_SUPER_ROD;
        state->entries_rods[num_entries_rod].is_delimiter = true;
        num_entries_rod++;
        num_entries_rod += pokedex_feature_scanner_add_entries_from_wild_pokemon_data(
                wild_pokemon_header->rod->data + WILD_POKEMON_NUM_ENTRIES_ROD + WILD_POKEMON_NUM_ENTRIES_GOOD_ROD, state->entries_rods + num_entries_rod, WILD_POKEMON_NUM_ENTRIES_SUPER_ROD, wild_pokemon_super_rod_pdf);
        state->num_entries[POKEDEX_SCANNER_HABITAT_ROD] = num_entries_rod;
    }
    pokedex_feature_scanner_entries_add_roamers();
}
    
static const graphic graphics_icons[POKEDEX_SCANNER_NUM_HABITATS] = {
    [POKEDEX_SCANNER_HABITAT_GRASS] = {
        .sprite = gfx_worldmap_icon_grassTiles, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_GRASS,
        .size = GRAPHIC_SIZE_4BPP(16, 64)
    },
    [POKEDEX_SCANNER_HABITAT_WATER] = {
        .sprite = gfx_worldmap_icon_waterTiles, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_WATER,
        .size = GRAPHIC_SIZE_4BPP(16, 96)
    },
    [POKEDEX_SCANNER_HABITAT_OTHER] = {
        .sprite = gfx_worldmap_icon_radarTiles, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_OTHER,
        .size = GRAPHIC_SIZE_4BPP(16, 128)
    },
    [POKEDEX_SCANNER_HABITAT_ROD] = {
        .sprite = gfx_worldmap_icon_rodTiles, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_ROD,
        .size = GRAPHIC_SIZE_4BPP(16, 48)
    },
};

static const graphic graphic_cursor = {
    .sprite = gfx_pokedex_scanner_cursorTiles, .tag = POKEDEX_SCANNER_GFX_TAG_CURSOR,
    .size = 2 * GRAPHIC_SIZE_4BPP(32, 32)
};

static const graphic graphic_icon_caught = {
    .sprite = gfx_pokedex_scanner_icon_caughtTiles, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_CAUGHT,
    .size = GRAPHIC_SIZE_4BPP(16, 16)
};

static const palette palettes_icons[POKEDEX_SCANNER_NUM_HABITATS] = {
    [POKEDEX_SCANNER_HABITAT_GRASS] = {
        .pal = gfx_worldmap_icon_grassPal, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_GRASS
    },
    [POKEDEX_SCANNER_HABITAT_WATER] = {
        .pal = gfx_worldmap_icon_waterPal, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_WATER
    },
    [POKEDEX_SCANNER_HABITAT_OTHER] = {
        .pal = gfx_worldmap_icon_radarPal, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_OTHER
    },
    [POKEDEX_SCANNER_HABITAT_ROD] = {
        .pal = gfx_worldmap_icon_rodPal, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_ROD
    },
};

static const palette palette_cursor = {
    .pal = gfx_pokedex_scanner_cursorPal, .tag = POKEDEX_SCANNER_GFX_TAG_CURSOR
};

static const palette palette_icon_caught = {
    .pal = gfx_pokedex_scanner_icon_caughtPal, .tag = POKEDEX_SCANNER_GFX_TAG_ICON_CAUGHT,
};

static const sprite oam_icon = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0),
};

static const sprite oam_icon_cursor = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0),
};

static const sprite oam_pokemon = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(0),
};

static const sprite oam_icon_caught = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0),
};

static const sprite pokedex_feature_scanner_icon_sprite = {
    ATTR0_SHAPE_SQUARE, ATTR1_SIZE_32_32, 0, 0
};

static const gfx_frame gfx_animation_icon_grass[] = {
    {.data = 0, .duration = 0}, 
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 40},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 2 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 3 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const gfx_animations_icon_grass[] = {gfx_animation_icon_grass};

static const gfx_frame gfx_animation_icon_water[] = {
    {.data = 0, .duration = 0}, 
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 24},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 2 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 3 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 4 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 5 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const gfx_animations_icon_water[] = {gfx_animation_icon_water};

static const gfx_frame gfx_animation_icon_radar[] = {
    {.data = 0, .duration = 0}, 
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 2 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 3 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 4 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 5 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 6 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 7 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const gfx_animations_icon_radar[] = {gfx_animation_icon_radar};

static const gfx_frame gfx_animation_icon_rod[] = {
    {.data = 0, .duration = 0}, 
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 48},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 2 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = 2 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16), .duration = 8},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const gfx_animations_icon_rod[] = {gfx_animation_icon_rod};

static const gfx_frame gfx_animation_cursor[] = {
    {.data = 0, .duration = 0},
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 32},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 32},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const gfx_animations_cursor[] = {gfx_animation_cursor};

static const gfx_frame gfx_animation_icon_idle[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END},
};

static const gfx_frame gfx_animation_icon_active[] = {
    {.data = 0, .duration = 0},
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 16},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 16},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const gfx_animations_icon[] = {gfx_animation_icon_idle, gfx_animation_icon_active};

static const oam_template oam_templates_icons[POKEDEX_SCANNER_NUM_HABITATS] = {
    [POKEDEX_SCANNER_HABITAT_GRASS] = {
        .tiles_tag = POKEDEX_SCANNER_GFX_TAG_ICON_GRASS, .pal_tag = POKEDEX_SCANNER_GFX_TAG_ICON_GRASS,
        .oam = &oam_icon, .animation = gfx_animations_icon_grass, .rotscale = oam_rotscale_anim_table_null,
        .callback = oam_null_callback,
    },
    [POKEDEX_SCANNER_HABITAT_WATER] = {
        .tiles_tag = POKEDEX_SCANNER_GFX_TAG_ICON_WATER, .pal_tag = POKEDEX_SCANNER_GFX_TAG_ICON_WATER,
        .oam = &oam_icon, .animation = gfx_animations_icon_water, .rotscale = oam_rotscale_anim_table_null,
        .callback = oam_null_callback,
    },
    [POKEDEX_SCANNER_HABITAT_OTHER] = {
        .tiles_tag = POKEDEX_SCANNER_GFX_TAG_ICON_OTHER, .pal_tag = POKEDEX_SCANNER_GFX_TAG_ICON_OTHER,
        .oam = &oam_icon, .animation = gfx_animations_icon_radar, .rotscale = oam_rotscale_anim_table_null,
        .callback = oam_null_callback,
    },
    [POKEDEX_SCANNER_HABITAT_ROD] = {
        .tiles_tag = POKEDEX_SCANNER_GFX_TAG_ICON_ROD, .pal_tag = POKEDEX_SCANNER_GFX_TAG_ICON_ROD,
        .oam = &oam_icon, .animation = gfx_animations_icon_rod, .rotscale = oam_rotscale_anim_table_null,
        .callback = oam_null_callback,
    },
};

static const oam_template oam_template_pokemon = {
    .tiles_tag = POKEDEX_SCANNER_GFX_TAG_ICON_POKEMON, .pal_tag = POKEDEX_SCANNER_GFX_TAG_ICON_POKEMON,
    .oam = &oam_pokemon, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback
};

static const oam_template oam_template_cursor = {
    .tiles_tag = POKEDEX_SCANNER_GFX_TAG_CURSOR, .pal_tag = POKEDEX_SCANNER_GFX_TAG_CURSOR,
    .oam = &oam_icon_cursor, .animation = gfx_animations_cursor, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static const oam_template oam_template_icon = {
    .tiles_tag = 0, .pal_tag = 0xFFFF, .oam = &pokedex_feature_scanner_icon_sprite, 
    .animation = gfx_animations_icon, .rotscale = oam_rotscale_anim_table_null, 
    .callback = oam_null_callback,
};

static const oam_template oam_template_icon_caught = {
    .tiles_tag = POKEDEX_SCANNER_GFX_TAG_ICON_CAUGHT, .pal_tag = POKEDEX_SCANNER_GFX_TAG_ICON_CAUGHT, 
    .oam = &oam_icon_caught, .animation = gfx_animations_icon, .rotscale = oam_rotscale_anim_table_null, 
    .callback = oam_null_callback,
};

static const bg_config pokedex_feature_scanner_bg_cnfgs[] = {
    {.bg_id = 0, .char_base = 2, .map_base = 31, .priority = 0},
    {.bg_id = 1, .char_base = 0, .map_base = 30, .priority = 1},
};

static const tboxdata pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_NUM_TBOXES + 1] = {
    [POKEDEX_SCANNER_TBOX_TITLE] = {.bg_id = 0, .x = 3, .y = 0, .w = 12, .h = 3, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES, .pal = 13},
    [POKEDEX_SCANNER_TBOX_LIST] = {.bg_id = 0, .x = 1, .y = 3, .w = 19, .h = 17, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES + 12 * 3, .pal = 13},
    [POKEDEX_SCANNER_TBOX_STATS] = {.bg_id = 0, .x = 20, .w = 10, .y = 16, .h = 4, .start_tile = 1 + TBOX_FRAME_SET_STYLE_NUM_TILES + 12 * 3 + 20 * 17, .pal = 13},
    [POKEDEX_SCANNER_TBOX_NUM_TBOXES] = {.bg_id = 0xFF},
};

static const tbox_font_colormap pokedex_feature_scanner_title_fontcolmap = {0, 1, 2, 0};
static const tbox_font_colormap pokedex_feature_scanner_subtitle_fontcolmap = {0, 9, 8, 0};

static void pokedex_feature_scanner_relocate_habitat_cursor() {
    oams[pokedex_scanner_state->oam_idx_habitat_cursor].x = (s16)(156 + 24 * pokedex_scanner_state->habitat);
    oams[pokedex_scanner_state->oam_idx_habitat_cursor].y = 12;
}

void pokedex_feature_scanner_draw_generic_icons(pokedex_scanner_state_t *state,
        u16 entries[][2], int size){
    // Load for each entry the respective icon and draw it
    for(int i = 0; i < size; i++){
        u16 species = entries[i][0];
        u16 tile = oam_vram_get_tile((u16)(0 + i));
        void *dst = (void*)(0x06010000 + 0x20 * tile);
        cpuset(pokemon_icons[species], dst, 
                CPUSET_COPY | CPUSET_HALFWORD | 0x100);
        oams[state->oams[i]].final_oam.attr0 &= (u16)(~ATTR0_OBJDISABLE);
        
        int icon_pal = pokemon_icon_usage[species];
        if(!pokedex_operator(species, POKEDEX_GET | POKEDEX_CAUGHT, 1))
            icon_pal = 3;
        oams[state->oams[i]].final_oam.attr2 &= (u16)(~(0b1111 << 12));
        oams[state->oams[i]].final_oam.attr2 |= (u16)(icon_pal << 12);
    }
}

static u16 rod_delimiter_to_item_idx[POKEDEX_SCANNER_NUM_DELIMITERS] = {
    [POKEDEX_SCANNER_DELIMITER_ROD] = ITEM_ANGEL,
    [POKEDEX_SCANNER_DELIMITER_GOOD_ROD] = ITEM_PROFIANGEL,
    [POKEDEX_SCANNER_DELIMITER_SUPER_ROD] = ITEM_SUPERANGEL,
};

static pokedex_scanner_entry_t *pokedex_scanner_get_entries(u8 habitat) {
    switch (habitat) {
        case POKEDEX_SCANNER_HABITAT_GRASS:
            return pokedex_scanner_state->entries_grass;
        case POKEDEX_SCANNER_HABITAT_WATER:
            return pokedex_scanner_state->entries_water;
        case POKEDEX_SCANNER_HABITAT_OTHER:
            return pokedex_scanner_state->entries_other;
        case POKEDEX_SCANNER_HABITAT_ROD:
            return pokedex_scanner_state->entries_rods;
        default:
            return NULL;
    }
}

static void pokedex_scanner_oam_pokemon_callback_request_update_gfx(__attribute__((unused)) oam_object *self) {
    // this causes a one frame delay to synchronize the hiding of the oam
    lz77uncompvram(pokemon_frontsprites[self->private[0]].sprite, OAMCHARBASE(pokedex_scanner_state->base_tile_pokemon));
    self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    oams[pokedex_state->oam_idx_pokemon].callback = oam_null_callback;
}

static const u8 str_pokedex_feature_scanner_unseen[] = PSTRING("?????");
static const u8 str_pokedex_scanner_none_found[] = LANGDEP(
    PSTRING("Keine Pokémon auffindbar."),
    PSTRING("No Pokémon to find.")
);

void pokedex_scanner_redraw_list(bool scrolling_down) {

    u16 cursor = pokedex_scanner_state->cursor_positions[pokedex_scanner_state->habitat];
    pokedex_scanner_entry_t *list = pokedex_scanner_get_entries(pokedex_scanner_state->habitat);
    // DEBUG("Habitat %d, list at 0x%x\n", pokedex_scanner_state->habitat, list);
    int first_idx = 0;
    int last_idx = (int)(pokedex_scanner_state->num_entries[pokedex_scanner_state->habitat]) - 1;
    tbox_flush_set(POKEDEX_SCANNER_TBOX_LIST, 0x00);
    // Make all icon oams invisible
    for (int i = 0; i < POKEDEX_SCANNER_MAX_NUM_DISPLAYED; i++) {
        oams[pokedex_scanner_state->oams[i]].flags |= OAM_FLAG_INVISIBLE;
        oams[pokedex_scanner_state->oams_icons_caught[i]].flags |= OAM_FLAG_INVISIBLE;
    }
    // Print each line
    if (first_idx < last_idx) {
        int first = MAX(0, cursor - (scrolling_down ? 1 : 0) - (POKEDEX_SCANNER_MAX_NUM_DISPLAYED - 1) / 2);
        int last = MIN(last_idx, first + POKEDEX_SCANNER_MAX_NUM_DISPLAYED - 1);
        first = MAX(first_idx, last - POKEDEX_SCANNER_MAX_NUM_DISPLAYED + 1);
        pokedex_scanner_state->first_idx_displayed = (u8)first;
        pokedex_scanner_state->last_idx_displayed = (u8)last;
        for (int i = first; i <= last; i++) {
            int row_idx = i - first;
            u16 y = (u16)(POKEDEX_SCANNER_LIST_Y +  POKEDEX_SCANNER_LIST_LINE_WIDTH * row_idx);
            if (list[i].is_delimiter) {
                const u8 *str = item_get_name(rod_delimiter_to_item_idx[list[i].species]);
                tbox_print_string(POKEDEX_SCANNER_TBOX_LIST, 2, 
                POKEDEX_SCANNER_LIST_X, y, 0, 0, &pokedex_feature_scanner_subtitle_fontcolmap, 0xFF, str);
            } else {
                u16 species = list[i].species;
                bool caught = pokedex_operator(species, POKEDEX_GET | POKEDEX_CAUGHT, true);
                bool seen = pokedex_operator(species, POKEDEX_GET | POKEDEX_SEEN, true);
                strbuf[0] = 0xFF;
                if (pokedex_scanner_state->cursor_positions[pokedex_scanner_state->habitat] == i) {
                    const u8 str_pokepad_pokedex_cursor[] = PSTRING("▶");
                    strcat(strbuf, str_pokepad_pokedex_cursor);
                }
                if (seen) {
                    strcat(strbuf, pokemon_names[species]);
                } else {
                    strcat(strbuf, str_pokedex_feature_scanner_unseen);
                }
                tbox_print_string(POKEDEX_SCANNER_TBOX_LIST, 2, POKEDEX_SCANNER_LIST_X + 24, y, 0, 0, 
                        &pokedex_feature_scanner_title_fontcolmap, 0xFF, strbuf);
                    
                itoa(strbuf, list[i].percentage, ITOA_PAD_SPACES, 3);
                u8 str_percent[] = PSTRING("%");
                strcat(strbuf, str_percent);
                tbox_print_string(POKEDEX_SCANNER_TBOX_LIST, 2, POKEDEX_SCANNER_LIST_X + 118, y, 0, 0, 
                        &pokedex_feature_scanner_title_fontcolmap, 0xFF, strbuf);

                u16 tag; u8 pal_idx, animation_idx;
                if (seen && caught) {
                    tag = (u16)(POKEDEX_SCANNER_GFX_TAG_ICONS_BASE + species);
                    pal_idx = pokedex_scanner_state->icon_pals[pokemon_icon_usage[species]];
                    animation_idx = 1;
                } else if (seen) {
                    tag = (u16)(POKEDEX_SCANNER_GFX_TAG_ICONS_BASE + species);
                    pal_idx = pokedex_scanner_state->icon_pals[POKEMON_NUM_ICON_PALS];
                    animation_idx = 0;
                } else {
                    tag = POKEDEX_SCANNER_GFX_TAG_ICONS_BASE;
                    pal_idx = pokedex_scanner_state->icon_pals[pokemon_icon_usage[0]];
                    animation_idx = 0;
                }
                oams[pokedex_scanner_state->oams[row_idx]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
                u16 tile = oam_vram_get_tile(tag);
                oam_object *icon = oams + pokedex_scanner_state->oams[row_idx];
                icon->base_tile = tile;
                icon->final_oam.attr2 = (u16)((icon->final_oam.attr2 & (~0x3FF)) | (tile & 0x3FF));
                icon->final_oam.attr2 = (u16)((icon->final_oam.attr2 & (~0xF000)) | ((pal_idx & 0xF) << 12));
                oam_gfx_anim_start_if_not_current(icon, animation_idx);

                if (caught) {
                    oams[pokedex_scanner_state->oams_icons_caught[row_idx]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
                } else {
                    oams[pokedex_scanner_state->oams_icons_caught[row_idx]].flags |= OAM_FLAG_INVISIBLE;
                }
            }
        }
        // Update the pokemon shown
        u16 current_species = list[cursor].species;
        bool caught = pokedex_operator(current_species, POKEDEX_GET | POKEDEX_CAUGHT, true);
        bool seen = pokedex_operator(current_species, POKEDEX_GET | POKEDEX_SEEN, true);
        if (!seen) {
            current_species = 0;
        }
        if (caught || (!caught && !seen)) {
            pal_decompress(pokemon_pals[current_species].pal, (u16) (256 + pokedex_scanner_state->pal_idx_icon_pokemon * 16), 16 * sizeof(color_t));
        } else {
            pal_copy(pal_black, (u16) (256 + pokedex_scanner_state->pal_idx_icon_pokemon * 16), 16 * sizeof(color_t));
        }
        oams[pokedex_state->oam_idx_pokemon].private[0] = current_species;
        oams[pokedex_state->oam_idx_pokemon].callback = pokedex_scanner_oam_pokemon_callback_request_update_gfx; // will update the tiles
        oams[pokedex_state->oam_idx_pokemon].flags |= OAM_FLAG_INVISIBLE;
    } else {
        oams[pokedex_state->oam_idx_pokemon].flags |= OAM_FLAG_INVISIBLE;
        tbox_print_string(POKEDEX_SCANNER_TBOX_LIST, 2, 
            (u16)((8 * pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_LIST].w - string_get_width(2, str_pokedex_scanner_none_found, 0)) / 2),
            (u16)(8 * (pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_LIST].h - 2) / 2), 0, 0, 
                        &pokedex_feature_scanner_title_fontcolmap, 0xFF, str_pokedex_scanner_none_found);
    }
    

    tbox_copy_to_vram(POKEDEX_SCANNER_TBOX_LIST, TBOX_COPY_TILESET | TBOX_COPY_TILEMAP);
}

static void pokedex_scanner_cb1() {
    tbox_proceed();
    oam_animations_proceed();
    oam_proceed();
    big_callback_proceed();
    bg_virtual_sync_reqeust_proceed();
    fading_proceed();
}

static bool pokedex_scanner_try_list_scroll(int offset) {
    int first, last;
    for (first = 0; first < (int)pokedex_scanner_state->num_entries[pokedex_scanner_state->habitat]; first++) {
        if (!pokedex_scanner_get_entries(pokedex_scanner_state->habitat)[first].is_delimiter)
            break;
    }
    for (last = (int)pokedex_scanner_state->num_entries[pokedex_scanner_state->habitat] - 1; last > first; last--) {
        if (!pokedex_scanner_get_entries(pokedex_scanner_state->habitat)[last].is_delimiter)
            break;
    }
    int cursor_new = pokedex_scanner_state->cursor_positions[pokedex_scanner_state->habitat];
    while (cursor_new >= first && cursor_new <= last) {
        cursor_new += offset;
        if (!pokedex_scanner_get_entries(pokedex_scanner_state->habitat)[cursor_new].is_delimiter)
            break;
    }
    if (cursor_new < first || cursor_new > last)
        return false;
    pokedex_scanner_state->cursor_positions[pokedex_scanner_state->habitat] = (u8)cursor_new;
    return true;
}

static void pokedex_scanner_free() {
    tbox_free_all();
    for (int i = 0; i < POKEDEX_SCANNER_NUM_BGS; i++) {
        free(pokedex_scanner_state->bg_maps[i]);
    }
    free(pokedex_scanner_state);
}

static void pokedex_scanner_return(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    pokedex_scanner_free();
    callback1_set(pokedex_callback_initialize);
    big_callback_delete(self);
}

static void pokedex_scanner_scroll_indicator_callback(u8 self) {
    scroll_indicator_state *state = (scroll_indicator_state*)(big_callbacks[self].params);
    if (pokedex_scanner_state->first_idx_displayed > 0) {
        oams[state->arrow0_oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    } else {
       oams[state->arrow0_oam_idx].flags |= OAM_FLAG_INVISIBLE;
    }
    if (pokedex_scanner_state->last_idx_displayed < (int)pokedex_scanner_state->num_entries[pokedex_scanner_state->habitat] - 1) {
        oams[state->arrow1_oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
    } else {
       oams[state->arrow1_oam_idx].flags |= OAM_FLAG_INVISIBLE;
    }
    // DEBUG("First %d, last %d, num_entries %d\n", pokedex_scanner_state->first_idx_displayed, pokedex_scanner_state->last_idx_displayed, pokedex_scanner_state->num_entries[pokedex_scanner_state->habitat]);
}

static void pokedex_scanner_scroll_indicators_new() {
    u8 x = (u8)(8 * pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_LIST].x + (pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_LIST].w * 8 / 2));
    scroll_indicator_template scroll_indicator_template = {
                .arrow0_threshold = 0, 
                .arrow1_threshold = (u16)pokedex_scanner_state->num_entries[pokedex_scanner_state->habitat], 
                .arrow0_type = SCROLL_ARROW_UP, .arrow1_type = SCROLL_ARROW_DOWN,
                .arrow0_x = x, .arrow1_x = x,
                .arrow0_y = 28, .arrow1_y = 152,
                .pal_tag = 112, .tiles_tag = 112,
    };
    pokedex_scanner_state->scroll_indicator_cb_idx = scroll_indicator_new(&scroll_indicator_template,
    pokedex_scanner_state->cursor_positions + pokedex_scanner_state->habitat); 
    big_callbacks[pokedex_scanner_state->scroll_indicator_cb_idx].function = pokedex_scanner_scroll_indicator_callback;        
}

static void pokedex_scanner_handle_inputs(u8 self) {
    int offset = 0;
    bool scrolling_down = false;
    if (fading_control.active || dma3_busy(-1))
        return;
    if (super.keys_new.keys.left && pokedex_scanner_state->habitat > 0) {
        play_sound(5);
        pokedex_scanner_state->habitat--;
        pokedex_feature_scanner_relocate_habitat_cursor();
        pokedex_scanner_redraw_list(true);
        scroll_indicator_delete(pokedex_scanner_state->scroll_indicator_cb_idx);
        pokedex_scanner_scroll_indicators_new();
    } else if (super.keys_new.keys.right && pokedex_scanner_state->habitat < POKEDEX_SCANNER_NUM_HABITATS - 1) {
        play_sound(5);
        pokedex_scanner_state->habitat++;
        pokedex_feature_scanner_relocate_habitat_cursor();
        pokedex_scanner_redraw_list(true);
        scroll_indicator_delete(pokedex_scanner_state->scroll_indicator_cb_idx);
        pokedex_scanner_scroll_indicators_new();
    } else if (super.keys_new_and_repeated.keys.down) {
        offset = 1;
        scrolling_down = true;
    } else if (super.keys_new_and_repeated.keys.up) {
        offset = -1;
    } else if (super.keys_new.keys.B) {
        play_sound(5);
        big_callbacks[self].function = pokedex_scanner_return;
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
    } 
    if (offset != 0 && pokedex_scanner_try_list_scroll(offset)) {
        play_sound(5);
        pokedex_scanner_redraw_list(scrolling_down);
    }
}

static inline void pokedex_scanner_setup_icon_gfx(u16 species) {
    u16 tag = (u16)(POKEDEX_SCANNER_GFX_TAG_ICONS_BASE + species);
    if (oam_vram_get_tile(tag) == 0xFFFF) {
        u16 tile = oam_vram_alloc(GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 64));
        oam_vram_allocation_table_add(tag, tile, GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 64));
        cpuset(pokemon_icons[species], OAMCHARBASE(tile), 
                CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(32, 64)));
    }
}

static const u8 str_seen[] = LANGDEP(PSTRING("Ges."), PSTRING("Seen"));
static const u8 str_caught[] = LANGDEP(PSTRING("Gef."), PSTRING("Caught"));
static const u8 str_num_unique_count[] = PSTRING("BUFFER_2SKIP\x01/SKIP\x01BUFFER_1");

static inline void pokedex_scanner_print_caught_and_total_counts() {
    size_t max_size = 0;
    for (u8 habitat = 0; habitat < POKEDEX_SCANNER_NUM_HABITATS; habitat++)
        max_size += pokedex_scanner_state->num_entries[habitat];

    size_t num_unique_species = 0;
    u16 *unique_species = malloc(sizeof(u16) * max_size);
    for (u8 habitat = 0; habitat < POKEDEX_SCANNER_NUM_HABITATS; habitat++) {
        pokedex_scanner_entry_t *entries = pokedex_scanner_get_entries(habitat);
        if (entries) {
            for (u16 i = 0; i < pokedex_scanner_state->num_entries[habitat]; i++) {
                if (!entries[i].is_delimiter && entries[i].species) {
                    // Add the species of the entry to unique species if is not present already
                    bool found = false;
                    for (u16 j = 0; j < num_unique_species; j++) {
                        if (unique_species[j] == entries[i].species) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        unique_species[num_unique_species++] = entries[i].species;
                    }
                }
            }
        }
    }
    size_t num_unique_species_caught = 0, num_unique_species_seen = 0;
    for (u16 i = 0; i < num_unique_species; i++) {
        if (pokedex_operator(unique_species[i], POKEDEX_GET | POKEDEX_CAUGHT, true))
            num_unique_species_caught++;
        if (pokedex_operator(unique_species[i], POKEDEX_GET | POKEDEX_SEEN, true))
            num_unique_species_seen++;
    }
    itoa(buffer0, (int)num_unique_species, ITOA_PAD_SPACES, 2);
    itoa(buffer1, (int)num_unique_species_seen, ITOA_PAD_SPACES, 2);
    string_decrypt(strbuf, str_num_unique_count);
    tbox_print_string(POKEDEX_SCANNER_TBOX_STATS, 2, 43, 0, 0, 0, &pokedex_feature_scanner_title_fontcolmap, 0, strbuf);
    itoa(buffer1, (int)num_unique_species_caught, ITOA_PAD_SPACES, 2);
    string_decrypt(strbuf, str_num_unique_count);
    tbox_print_string(POKEDEX_SCANNER_TBOX_STATS, 2, 43, 16, 0, 0, &pokedex_feature_scanner_title_fontcolmap, 0, strbuf);

}



void pokedex_callback_initialize_feature_scanner_state_machine() {
    generic_callback1();
    if (fading_control.active || dma3_busy(-1))
        return;
    switch (pokedex_scanner_state->initialization_state) {
        case POKEDEX_SCANNER_SETUP_STATE_DATA_SETUP: {
            keys_repeated_start_delay = 20;
            keys_repeated_continue_delay = 4;
            pokedex_feature_scanner_build_all_entries(pokedex_scanner_state);
            // Initialize all cursors to a non-delimiter entry
            for (u8 habitat = 0; habitat < POKEDEX_SCANNER_NUM_HABITATS; habitat++) {
                pokedex_scanner_entry_t *entries = pokedex_scanner_get_entries(habitat);
                if (entries) {
                    for (pokedex_scanner_state->cursor_positions[habitat] = 0; 
                            entries[pokedex_scanner_state->cursor_positions[habitat]].is_delimiter && \
                            pokedex_scanner_state->cursor_positions[habitat] < pokedex_scanner_state->num_entries[habitat]; 
                            pokedex_scanner_state->cursor_positions[habitat]++);
                }
            }
            pokedex_scanner_state->initialization_state++;
            FALL_THROUGH;
        }
        case POKEDEX_SCANNER_SETUP_STATE_RESET:
            io_set(IO_DISPCNT, (u16)(io_get(IO_DISPCNT) & (~(IO_DISPCNT_WIN0 | IO_DISPCNT_WIN1))));
            oam_reset();
            fading_cntrl_reset();
            oam_palette_allocation_reset();
            fading_control.buffer_transfer_disabled = true;
            dma0_reset_callback();
            big_callback_delete_all();
            reset_hblank_and_vblank_callbacks();
            pokedex_scanner_state->initialization_state++;
            FALL_THROUGH;
        case POKEDEX_SCANNER_SETUP_STATE_SETUP_BGS: {
            bg_reset(0);
            bg_setup(0, pokedex_feature_scanner_bg_cnfgs, 2);
            bg_display_sync();
            for (u8 i = 0; i < POKEDEX_SCANNER_NUM_BGS; i++) {
                pokedex_scanner_state->bg_maps[i] = malloc_and_clear(32 * 32 * sizeof(bg_tile));
                bg_set_tilemap(i, pokedex_scanner_state->bg_maps[i]);
                bg_virtual_map_displace(i, 0, 0);
                bg_virtual_set_displace(i, 0, 0);
                bg_virtual_sync(i);
            }
            pokedex_scanner_state->initialization_state++;
            FALL_THROUGH;
        }
        case POKEDEX_SCANNER_SETUP_STATE_SETUP_TBOXES: {
            tbox_free_all();
            tbox_sync_with_virtual_bg_and_init_all(pokedex_feature_scanner_tboxes);
            tbox_init_frame_set_style(POKEDEX_SCANNER_TBOX_TITLE, 1, 13 * 16);
            u8 str_title[] = LANGDEP(PSTRING("Scanner"), PSTRING("Scanner"));
            tbox_flush_set(POKEDEX_SCANNER_TBOX_TITLE, 0x00);
            tbox_tilemap_draw(POKEDEX_SCANNER_TBOX_TITLE);
            tbox_print_string(POKEDEX_SCANNER_TBOX_TITLE, 2, 
                (u16)(((8 * pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_TITLE].w) - string_get_width(2, str_title, 0)) / 2), 
                4, 0, 0, &pokedex_feature_scanner_title_fontcolmap, 0, str_title);
            tbox_flush_set(POKEDEX_SCANNER_TBOX_LIST, 0x00);
            tbox_tilemap_draw(POKEDEX_SCANNER_TBOX_LIST);
            
            tbox_flush_set(POKEDEX_SCANNER_TBOX_STATS, 0x00);
            tbox_tilemap_draw(POKEDEX_SCANNER_TBOX_STATS);
            tbox_print_string(POKEDEX_SCANNER_TBOX_STATS, 2, 4, 0, 0, 0, &pokedex_feature_scanner_title_fontcolmap, 0, str_seen);
            tbox_print_string(POKEDEX_SCANNER_TBOX_STATS, 2, 4, 16, 0, 0, &pokedex_feature_scanner_title_fontcolmap, 0, str_caught);
            pokedex_scanner_print_caught_and_total_counts();
            pokedex_scanner_state->initialization_state++;
            break;
        }
        case POKEDEX_SCANNER_SETUP_STATE_LOAD_GFX: {
            lz77uncompwram(gfx_pokedex_scanner_uiMap, pokedex_scanner_state->bg_maps[1]);
            lz77uncompvram(gfx_pokedex_scanner_uiTiles, CHARBASE(0));
            pal_decompress(gfx_pokedex_scanner_uiPal, 0, 32);
            pokedex_scanner_state->initialization_state++;
            break;
        }
        case POKEDEX_SCANNER_SETUP_STATE_SETUP_OAM: {
            oam_palette_load_if_not_present(&palette_cursor);
            oam_load_graphic(&graphic_cursor);
            pokedex_scanner_state->oam_idx_habitat_cursor = oam_new_forward_search(&oam_template_cursor, 0, 0, 0);
            oam_gfx_anim_start(oams + pokedex_scanner_state->oam_idx_habitat_cursor, 0);
            pokedex_feature_scanner_relocate_habitat_cursor();
            for (int i = 0; i < POKEDEX_SCANNER_NUM_HABITATS; i++) {
                oam_palette_load_if_not_present(&palettes_icons[i]);
                oam_load_graphic(&graphics_icons[i]);
                pokedex_scanner_state->oam_idxs_icon[i] = oam_new_forward_search(&oam_templates_icons[i], (s16)(156 + i * 24), 12, 0);
                oam_gfx_anim_start(oams + pokedex_scanner_state->oam_idxs_icon[i], 0);
            }
            oam_palette_load_if_not_present(&palette_icon_caught);
            oam_load_graphic(&graphic_icon_caught);
            for (int i = 0; i < POKEDEX_SCANNER_MAX_NUM_DISPLAYED; i++){
                pokedex_scanner_state->oams[i] = oam_new_forward_search(&oam_template_icon,
                        (s16)(POKEDEX_SCANNER_LIST_X + pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_LIST].x * 8 + 8), 
                        (s16)(POKEDEX_SCANNER_LIST_Y + pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_LIST].y * 8 + POKEDEX_SCANNER_LIST_LINE_WIDTH * i), 
                        (u8)i
                        );
                oams[pokedex_scanner_state->oams[i]].flags |= OAM_FLAG_INVISIBLE;
                pokedex_scanner_state->oams_icons_caught[i] = oam_new_forward_search(&oam_template_icon_caught,
                        (s16)(POKEDEX_SCANNER_LIST_X + pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_LIST].x * 8 + 112), 
                        (s16)(POKEDEX_SCANNER_LIST_Y + pokedex_feature_scanner_tboxes[POKEDEX_SCANNER_TBOX_LIST].y * 8 + POKEDEX_SCANNER_LIST_LINE_WIDTH * i + 6), 
                        (u8)i
                        );
                oams[pokedex_scanner_state->oams_icons_caught[i]].flags |= OAM_FLAG_INVISIBLE;
            }
            // Load the palettes for the icons
            for(int i = 0; i < 3; i++){
                pokedex_scanner_state->icon_pals[i] = oam_allocate_palette(
                        (u16)(POKEDEX_SCANNER_GFX_TAG_ICONS_BASE + i));
                pal_copy(icon_pals[i], (u16)(256 + 16 * pokedex_scanner_state->icon_pals[i]), 16 * sizeof(color_t));
            }
            pokedex_scanner_state->icon_pals[3] = oam_allocate_palette(POKEDEX_SCANNER_GFX_TAG_ICONS_BASE + 3);
            pal_copy(pal_black, (u16)(256 + 16 * pokedex_scanner_state->icon_pals[3]), 16 * sizeof(color_t));
            pokedex_scanner_state->pal_idx_icon_pokemon = oam_allocate_palette(POKEDEX_SCANNER_GFX_TAG_ICON_POKEMON);
            pokedex_scanner_state->base_tile_pokemon = oam_vram_alloc(GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
            oam_vram_allocation_table_add(POKEDEX_SCANNER_GFX_TAG_ICON_POKEMON, pokedex_scanner_state->base_tile_pokemon, 
                GRAPHIC_SIZE_4BPP_TO_NUM_TILES(64, 64));
            pokedex_state->oam_idx_pokemon = oam_new_backward_search(&oam_template_pokemon, 200, 76, 0);
            pokedex_scanner_state->initialization_state++;
            break;
        }
        case POKEDEX_SCANNER_SETUP_STATE_SETUP_ICON_OAM: {
            for (u8 habitat = 0; habitat < POKEDEX_SCANNER_NUM_HABITATS; habitat++) {
                pokedex_scanner_entry_t *entries = pokedex_scanner_get_entries(habitat);
                if (entries) {
                    for (u8 i = 0; i < pokedex_scanner_state->num_entries[habitat]; i++) {
                        u16 species = entries[i].species;
                        if (species) {
                            pokedex_scanner_setup_icon_gfx(species);
                        }
                    }
                }
            }
            pokedex_scanner_setup_icon_gfx(0);
            pokedex_scanner_state->initialization_state++;
            break;
        }
        case POKEDEX_SCANNER_SETUP_STATE_UPDATE_LIST: {
            pokedex_scanner_redraw_list(true);
            pokedex_scanner_state->initialization_state++;
            break;
        }
        case POKEDEX_SCANNER_SETUP_SCROLL_INDICATORS: {
            pokedex_scanner_scroll_indicators_new();
            pokedex_scanner_state->initialization_state++;
            break;
        }
        case POKEDEX_SCANNER_SETUP_SHOW: {
            pal_set_all_to_black();
            fading_control.buffer_transfer_disabled = false;   
            // Those requests are picked up by the vblank callback and copies the tilemaps
            for (u8 i = 0; i < ARRAY_COUNT(pokedex_scanner_state->bg_maps); i++)
                bg_virtual_sync_reqeust_push(i);
            pokedex_scanner_state->initialization_state++;
            break;
        }
        default: {
            for (u8 i = 0; i < ARRAY_COUNT(pokedex_scanner_state->bg_maps); i++)
                bg_sync_display_and_show(i);
            bg_display_sync();
            io_set(IO_BLDCNT, 0);
            io_set(IO_BLDALPHA, 0);
            io_set(IO_BLDY, 0);
            io_bic(IO_DISPCNT, IO_DISPCNT_WIN0 | IO_DISPCNT_WIN1);
            fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
            callback1_set(pokedex_scanner_cb1);
            vblank_handler_set(generic_vblank_handler);
            big_callback_new(pokedex_scanner_handle_inputs, 0);
        }
    }
}

void pokedex_callback_initialize_feature_scanner() {
    pokedex_scanner_state = malloc_and_clear(sizeof(pokedex_scanner_state_t));
    callback1_set(pokedex_callback_initialize_feature_scanner_state_machine);
}