#include "types.h"
#include "tile/coordinate.h"
#include "constants/map_namespaces.h"
#include "worldmap.h"
#include "map/header.h"
#include "constants/map_types.h"
#include "constants/map_connections.h"
#include "debug.h"
#include "math.h"
#include "save.h"
#include "fading.h"
#include "io.h"
#include "bios.h"
#include "callbacks.h"
#include "dma.h"
#include "agbmemory.h"
#include "overworld/map_control.h"
#include "flags.h"
#include "transparency.h"
#include "text.h"
#include "pokemon/names.h"
#include "language.h"
#include "pokemon/sprites.h"
#include "pokepad/pokedex/operator.h"
#include "map/namespace.h"
#include "dma.h"
#include "io.h"
#include "music.h"

EWRAM worldmap_ui_state_t *worldmap_ui_state = NULL;

extern const LZ77COMPRESSED gfx_worldmap_ui_habitat_frameTiles;
extern const LZ77COMPRESSED gfx_worldmap_ui_habitat_frameMap;
extern const color_t gfx_worldmap_ui_habitat_framePal[16];

extern const LZ77COMPRESSED gfx_worldmap_icon_grassTiles;
extern const color_t gfx_worldmap_icon_grassPal[16];
extern const LZ77COMPRESSED gfx_worldmap_icon_waterTiles;
extern const color_t gfx_worldmap_icon_waterPal[16];
extern const LZ77COMPRESSED gfx_worldmap_icon_rodTiles;
extern const color_t gfx_worldmap_icon_rodPal[16];
extern const LZ77COMPRESSED gfx_worldmap_icon_radarTiles;
extern const color_t gfx_worldmap_icon_radarPal[16];
extern const LZ77COMPRESSED gfx_worldmap_icon_rod_typesTiles;
extern const color_t gfx_worldmap_icon_rod_typesPal[16];
extern const LZ77COMPRESSED gfx_worldmap_icon_ball_caughtTiles;
extern const color_t gfx_worldmap_icon_ball_caughtPal[16];
extern const u8 gfx_worldmap_icon_percentageTiles[GRAPHIC_SIZE_4BPP(16, 16 * WORLDMAP_UI_HABITAT_NUM_PERCENTAGES)];
extern const color_t gfx_worldmap_icon_percentagePal[16];

static void worldmap_ui_handle_inputs_habitat(u8 self);
static void worldmap_ui_habitat_update_red_should_be_active();
static void worldmap_ui_habitat_update_red_overlay();
static void worldmap_ui_habitat_draw_red_switch_tiles();
static void worldmap_ui_habitat_free();

static const graphic graphic_icon_grass = {
    .sprite = gfx_worldmap_icon_grassTiles, .tag = WORLDMAP_UI_GFX_TAG_ICON_GRASS,
    .size = GRAPHIC_SIZE_4BPP(16, 64)
};

static const graphic graphic_icon_water = {
    .sprite = gfx_worldmap_icon_waterTiles, .tag = WORLDMAP_UI_GFX_TAG_ICON_WATER,
    .size = GRAPHIC_SIZE_4BPP(16, 96)
};

static const graphic graphic_icon_radar = {
    .sprite = gfx_worldmap_icon_radarTiles, .tag = WORLDMAP_UI_GFX_TAG_ICON_RADAR,
    .size = GRAPHIC_SIZE_4BPP(16, 128)
};

static const graphic graphic_icon_rod = {
    .sprite = gfx_worldmap_icon_rodTiles, .tag = WORLDMAP_UI_GFX_TAG_ICON_ROD,
    .size = GRAPHIC_SIZE_4BPP(16, 48)
};

static const graphic graphic_icon_rod_types = {
    .sprite = gfx_worldmap_icon_rod_typesTiles, .tag = WORLDMAP_UI_GFX_TAG_ICON_ROD_TYPES,
    .size = GRAPHIC_SIZE_4BPP(8, 24)
};

static const graphic graphic_icon_ball_caught = {
    .sprite = gfx_worldmap_icon_ball_caughtTiles, .tag = WORLDMAP_UI_GFX_TAG_ICON_BALL_CAUGHT,
    .size = GRAPHIC_SIZE_4BPP(8, 8)
};

static const palette palette_icon_grass = {
    .pal = gfx_worldmap_icon_grassPal, .tag = WORLDMAP_UI_GFX_TAG_ICON_GRASS
};

static const palette palette_icon_water = {
    .pal = gfx_worldmap_icon_waterPal, .tag = WORLDMAP_UI_GFX_TAG_ICON_WATER
};

static const palette palette_icon_radar = {
    .pal = gfx_worldmap_icon_radarPal, .tag = WORLDMAP_UI_GFX_TAG_ICON_RADAR
};

static const palette palette_icon_rod = {
    .pal = gfx_worldmap_icon_rodPal, .tag = WORLDMAP_UI_GFX_TAG_ICON_ROD
};

static const palette palette_icon_rod_types = {
    .pal = gfx_worldmap_icon_rod_typesPal, .tag = WORLDMAP_UI_GFX_TAG_ICON_ROD_TYPES
};

static const palette palette_icon_ball_caught = {
    .pal = gfx_worldmap_icon_ball_caughtPal, .tag = WORLDMAP_UI_GFX_TAG_ICON_BALL_CAUGHT
};

static const palette palette_percentages = {
    .pal = gfx_worldmap_icon_percentagePal, .tag = WORLDMAP_UI_GFX_TAG_PERCENTAGE
};

static const sprite oam_icon = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0),
};

static const sprite oam_icon_rod_types = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_8_8, .attr2 = ATTR2_PRIO(0),
};

static const sprite oam_icon_species = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0),
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

static const gfx_frame gfx_animation_icon_rod_type_old_rod[] = {{.data = 0, .duration = 0}, {.data = GFX_ANIM_END}};
static const gfx_frame gfx_animation_icon_rod_type_good_rod[] = {{.data = 1, .duration = 0}, {.data = GFX_ANIM_END}};
static const gfx_frame gfx_animation_icon_rod_type_super_rod[] = {{.data = 2, .duration = 0}, {.data = GFX_ANIM_END}};

static const gfx_frame *const gfx_animations_icon_rod_types[] = {
    gfx_animation_icon_rod_type_old_rod, gfx_animation_icon_rod_type_good_rod,
    gfx_animation_icon_rod_type_super_rod,
};

static const gfx_frame gfx_animations_icon_species_idle[] = {{.data = 0, .duration = 0}, {.data = GFX_ANIM_END, .duration = 0}};
static const gfx_frame gfx_animations_icon_species_active[] = {
    {.data = 0, .duration = 0},
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 16},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 16},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const gfx_animations_icon_species[] = {
    gfx_animations_icon_species_idle, gfx_animations_icon_species_active
};

static const gfx_frame gfx_animation_icon_ball_caught_idle[] = {{.data = 0, .duration = 0}, {.data = GFX_ANIM_END, .duration = 0}};
static const gfx_frame *const gfx_animations_icon_ball_caught[] = {
    gfx_animation_icon_ball_caught_idle,
};

static const graphic gfx_table_percentages[WORLDMAP_UI_HABITAT_NUM_PERCENTAGES] = {
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_0, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_1, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_5, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_10, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_15, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_20, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_25, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_30, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_35, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_40, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_45, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_50, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_55, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_60, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_65, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_70, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_75, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_80, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_85, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_90, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_95, gfx_worldmap_icon_percentageTiles, 16, 16),
    GRAPHIC_ARRAY_4BPP(WORLDMAP_UI_PERCENTAGE_100, gfx_worldmap_icon_percentageTiles, 16, 16),
};

#define GFX_ANIMATION_PERCENTAGE(num) [(num)] = {{.data = (num), .duration = 0}, {.data = GFX_ANIM_END}}
#define GFX_ANIMATION_POINTER(num, array) [(num)] = array[(num)]

static const gfx_frame gfx_animation_icon_percentage[WORLDMAP_UI_HABITAT_NUM_PERCENTAGES][2] = {
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_0),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_1),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_5),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_10),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_15),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_20),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_25),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_30),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_35),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_40),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_45),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_50),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_55),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_60),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_65),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_70),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_75),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_80),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_85),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_90),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_95),
    GFX_ANIMATION_PERCENTAGE(WORLDMAP_UI_PERCENTAGE_100),
};

static const gfx_frame *const gfx_animations_percentage[WORLDMAP_UI_HABITAT_NUM_PERCENTAGES] = {
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_0, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_1, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_5, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_10, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_15, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_20, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_25, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_30, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_35, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_40, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_45, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_50, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_55, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_60, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_65, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_70, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_75, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_80, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_85, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_90, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_95, gfx_animation_icon_percentage),
    GFX_ANIMATION_POINTER(WORLDMAP_UI_PERCENTAGE_100, gfx_animation_icon_percentage),
};

static const u8 oam_animation_idx_to_percentage[WORLDMAP_UI_HABITAT_NUM_PERCENTAGES] = {
    [WORLDMAP_UI_PERCENTAGE_0] = 0,
    [WORLDMAP_UI_PERCENTAGE_1] = 1,
    [WORLDMAP_UI_PERCENTAGE_5] = 5,
    [WORLDMAP_UI_PERCENTAGE_10] = 10,
    [WORLDMAP_UI_PERCENTAGE_15] = 15,
    [WORLDMAP_UI_PERCENTAGE_20] = 20,
    [WORLDMAP_UI_PERCENTAGE_25] = 25,
    [WORLDMAP_UI_PERCENTAGE_30] = 30,
    [WORLDMAP_UI_PERCENTAGE_35] = 35,
    [WORLDMAP_UI_PERCENTAGE_40] = 40,
    [WORLDMAP_UI_PERCENTAGE_45] = 45,
    [WORLDMAP_UI_PERCENTAGE_50] = 50,
    [WORLDMAP_UI_PERCENTAGE_55] = 55,
    [WORLDMAP_UI_PERCENTAGE_60] = 60,
    [WORLDMAP_UI_PERCENTAGE_65] = 65,
    [WORLDMAP_UI_PERCENTAGE_70] = 70,
    [WORLDMAP_UI_PERCENTAGE_75] = 75,
    [WORLDMAP_UI_PERCENTAGE_80] = 80,
    [WORLDMAP_UI_PERCENTAGE_85] = 85,
    [WORLDMAP_UI_PERCENTAGE_90] = 90,
    [WORLDMAP_UI_PERCENTAGE_95] = 95,
    [WORLDMAP_UI_PERCENTAGE_100] = 100,
};

static const oam_template oam_template_icon_grass = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_ICON_GRASS, .pal_tag = WORLDMAP_UI_GFX_TAG_ICON_GRASS,
    .oam = &oam_icon, .animation = gfx_animations_icon_grass, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static const oam_template oam_template_icon_water = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_ICON_WATER, .pal_tag = WORLDMAP_UI_GFX_TAG_ICON_WATER,
    .oam = &oam_icon, .animation = gfx_animations_icon_water, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static const oam_template oam_template_icon_radar = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_ICON_RADAR, .pal_tag = WORLDMAP_UI_GFX_TAG_ICON_RADAR,
    .oam = &oam_icon, .animation = gfx_animations_icon_radar, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static const oam_template oam_template_icon_rod = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_ICON_ROD, .pal_tag = WORLDMAP_UI_GFX_TAG_ICON_ROD,
    .oam = &oam_icon, .animation = gfx_animations_icon_rod, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static const oam_template oam_template_icon_rod_types = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_ICON_ROD_TYPES, .pal_tag = WORLDMAP_UI_GFX_TAG_ICON_ROD_TYPES,
    .oam = &oam_icon_rod_types, .animation = gfx_animations_icon_rod_types,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static const oam_template oam_template_icon_species = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_ICON_SPECIES, .pal_tag = WORLDMAP_UI_GFX_TAG_ICON_SPECIES,
    .oam = &oam_icon_species, .animation = gfx_animations_icon_species,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static const oam_template oam_template_icon_ball_caught = {
    .tiles_tag = WORLDMAP_UI_GFX_TAG_ICON_BALL_CAUGHT, .pal_tag = WORLDMAP_UI_GFX_TAG_ICON_BALL_CAUGHT,
    .oam = &oam_icon_rod_types, .animation = gfx_animations_icon_ball_caught,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static const oam_template oam_template_icon_percentage = {
    .tiles_tag = 0xFFFF, .pal_tag = WORLDMAP_UI_GFX_TAG_PERCENTAGE,
    .oam = &oam_icon, .animation = gfx_animations_percentage,
    .graphics = gfx_table_percentages,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};


static const bg_config worldmap_ui_bg_configs[] = {
    [0] = { // Text layer on UI
        .bg_id = 0, .char_base = 0, .map_base = 28, .priority = 0, .size = 0,
    },
    [1] = { // Frame layer
        .bg_id = 1, .char_base = 2, .map_base = 29, .priority = 1, .size = 0,
    },
    [2] = { // Text layer for namespace label and habitat over
        .bg_id = 2, .char_base = 0, .map_base = 30, .priority = 2, .size = 0,
    },
    [3] = { // Worldmap layer
        .bg_id = 3, .char_base = 1, .map_base = 31, .priority = 3, .size = 0, .color_mode = 1,

    },
};

enum {
    WORLDMAP_UI_HABITAT_TBOX_HEADER = WORLDMAP_UI_NUM_TBOXES,
    WORLDMAP_UI_HABITAT_TBOX_FOOTER,
    WORLDMAP_UI_HABITAT_TBOX_HABITAT_NAMES,
    WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES = WORLDMAP_UI_HABITAT_TBOX_HABITAT_NAMES + NUM_HABITAT_TYPES - 2,
    WORLDMAP_UI_HABITAT_TBOX_HABITAT_NO_HABITAT = WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + NUM_HABITAT_TYPES,
    NUM_WORLDMAP_UI_HABITAT_TBOXES,
} worldmap_ui_habitat_tbox;

static const tbox_font_colormap font_colormap_transparent = {.background = 0, .body = 2, .edge = 0};
static const tbox_font_colormap font_colormap_non_transparent = {.background = 1, .body = 2, .edge = 0};
static const tbox_font_colormap font_colormap_transparent_on_ui = {.background = 0, .body = 1, .edge = 2};
static const tbox_font_colormap font_colormap_transparent_footer = {.background = 0, .body = 1, .edge = 0};

static const u8 str_header[] = LANGDEP(
    PSTRING("Fundorte v. BUFFER_1"),
    PSTRING("Habitats of BUFFER_1")
);

static const u8 str_footer_key_select[] = PSTRING("KEY_SELECT");
static const u8 str_footer_key_dpad[] = PSTRING("KEY_DPAD");
static const u8 str_footer_key_b[] = PSTRING("KEY_B");

static const u8 str_footer_switch_map[] = LANGDEP(
    PSTRING("Wechseln"),
    PSTRING("Switch")
);

static const u8 str_footer_move[] = LANGDEP(
    PSTRING("Bewegen"),
    PSTRING("Move")
);

static const u8 str_footer_back[] = LANGDEP(
    PSTRING("Zurück"),
    PSTRING("Back")
);

static const u8 str_no_habitats[] = LANGDEP(
    PSTRING("Keine Gebiete bekannt"),
    PSTRING("No habitats known")
);

static const u8 str_grass[] = LANGDEP(PSTRING("Natur"), PSTRING("Nature"));
static const u8 str_water[] = LANGDEP(PSTRING("Wasser"), PSTRING("Water"));
static const u8 str_radar[] = LANGDEP(PSTRING("Radar"), PSTRING("Radar"));
static const u8 str_rod[] = LANGDEP(PSTRING("Angel"), PSTRING("Rod"));

static const u8 *const habitat_names[] = {
    [HABITAT_TYPE_GRASS] = str_grass,
    [HABITAT_TYPE_WATER] = str_water,
    [HABITAT_TYPE_RADAR] = str_radar,
    [HABITAT_TYPE_OLD_ROD] = str_rod,
};

static const tboxdata worldmap_ui_habitat_tboxes[NUM_WORLDMAP_UI_HABITAT_TBOXES + 1] = {
    [WORLDMAP_UI_HABITAT_TBOX_HEADER] = {.bg_id = 0, .x = 7, .y = 0, .w = 18, .h = 2, .pal = 15, .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_TBOX_IDX_NAMESPACE] = {.bg_id = 2, .x = 7, .y = 2, .w = 18, .h = 2, .pal = 15, .start_tile = 2 + 2 * 18 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_NAMES + HABITAT_TYPE_GRASS] = {.bg_id = 0, .x = 2, .y = 0, .w = 5, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 0 * 2 * 5 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_NAMES + HABITAT_TYPE_WATER] = {.bg_id = 0, .x = 2, .y = 4, .w = 5, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 1 * 2 * 5 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_NAMES + HABITAT_TYPE_RADAR] = {.bg_id = 0, .x = 2, .y = 8, .w = 5, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 2 * 2 * 5 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_NAMES + HABITAT_TYPE_OLD_ROD] = {.bg_id = 0, .x = 2, .y = 12, .w = 5, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 3 * 3 * 5 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + HABITAT_TYPE_GRASS] = {.bg_id = 0, .x = 4, .y = 2, .w = 3, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 4 * 3 * 5 + 0 * 3 * 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + HABITAT_TYPE_WATER] = {.bg_id = 0, .x = 4, .y = 6, .w = 3, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 4 * 3 * 5 + 1 * 3 * 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + HABITAT_TYPE_RADAR] = {.bg_id = 0, .x = 4, .y = 10, .w = 3, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 4 * 3 * 5 + 2 * 3 * 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + HABITAT_TYPE_OLD_ROD] = {.bg_id = 0, .x = 4, .y = 14, .w = 3, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 4 * 3 * 5 + 3 * 3 * 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + HABITAT_TYPE_GOOD_ROD] = {.bg_id = 0, .x = 4, .y = 16, .w = 3, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 4 * 3 * 5 + 4 * 3 * 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + HABITAT_TYPE_SUPER_ROD] = {.bg_id = 0, .x = 4, .y = 18, .w = 3, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 4 * 3 * 5 + 5 * 3 * 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_HABITAT_NO_HABITAT] = {.bg_id = 2, .x = 10, .y = 9, .w = 17, .h = 2, .pal = 15, .start_tile = 2 + 2 * 18 + 18 * 2 + 4 * 3 * 5 + 6 * 3 * 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_HABITAT_TBOX_FOOTER] = {.bg_id = 0, .x = 7, .y = 18, .w = 27, .h = 2, .pal = 14, .start_tile = 2 + 2 * 18 + 18 * 2 + 4 * 3 * 5 + 6 * 3 * 2 + 17 * 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE] = {.bg_id = 0, .x = WORLDMAP_SWITCH_MAPS_DIALOGE_X_HABITAT, .y = WORLDMAP_SWITCH_MAPS_DIALOGE_Y_HABITAT, .w = WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH, .h = WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT, .pal = 13, .start_tile = 2 + 2 * 18 + 18 * 2 + 4 * 3 * 5 + 6 * 3 * 2 + 17 * 2 + 27 * 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [NUM_WORLDMAP_UI_HABITAT_TBOXES] = {.bg_id = 0xFF},
};

static const u8 str_namespace_switch_maps[] = LANGDEP(
    PSTRING("Karte wechseln"),
    PSTRING("Switch maps")
);

static void worldmap_ui_habitat_update_namespace_by_cursor_position(bool print_if_namespace_not_changed) {
    const u8 *str = NULL;
    if (worldmap_ui_state->cursor.x == worldmap_ui_state->icon_switch_maps_x &&
        worldmap_ui_state->cursor.y == worldmap_ui_state->icon_switch_maps_y) {
        str = str_namespace_switch_maps;
    } else {
        u8 namespace_idx = worldmap_get_namespace_by_pos(worldmap_ui_state->cursor.idx, worldmap_ui_state->cursor.layer,
            worldmap_ui_state->cursor.x, worldmap_ui_state->cursor.y);
        if ((namespace_idx != worldmap_ui_state->current_namespace || print_if_namespace_not_changed) 
                && namespace_idx != MAP_NAMESPACE_NONE) {
            worldmap_ui_state->current_namespace = namespace_idx;
            str = map_namespaces[MAP_NAMESPACE_TO_IDX(namespace_idx)];
        }
    }
    if (str) {
        tbox_flush_set(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 0x11);
        tbox_print_string(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 2, 4, 0, 0, 0, &font_colormap_non_transparent, 0, str);
    } else {
        tbox_flush_set(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 0x00);
        tbox_sync(WORLDMAP_UI_TBOX_IDX_NAMESPACE, TBOX_SYNC_SET);
    }
}

static u8 worldmap_ui_habitat_get_oam_animation_idx_by_probability(u8 probability) {
    int animation_idx;
    for (animation_idx = WORLDMAP_UI_HABITAT_NUM_PERCENTAGES - 1; animation_idx >= 0; animation_idx--) {
        if (probability >= oam_animation_idx_to_percentage[animation_idx])
            break;
    }
    return (u8)animation_idx;
}

static const u8 str_percent[] = PSTRING("%");
static const u8 str_no_percent[] = PSTRING(" ---");

static void worldmap_ui_habitat_update_habitat_info_by_cursor() {
    u8 probabilities[NUM_HABITAT_TYPES] = {0};
    for (size_t i = 0; i < worldmap_ui_state->habitats->num_elements; i++) {
        pokedex_habitat_pair *entry = worldmap_ui_state->habitats->list + i;
        if (entry->worldmap_x == worldmap_ui_state->cursor.x && 
            entry->worldmap_y == worldmap_ui_state->cursor.y &&
            entry->worldmap_idx == worldmap_ui_state->cursor.idx &&
            entry->layer == worldmap_ui_state->cursor.layer) {
            probabilities[entry->habitat_type] = entry->probability;
        }
    }
    for (size_t i = 0; i < NUM_HABITAT_TYPES; i++) {
        oam_gfx_anim_start(oams + worldmap_ui_state->oam_idx_percentages[i], 
            worldmap_ui_habitat_get_oam_animation_idx_by_probability(probabilities[i]));
        if (probabilities[i] > 0) {
            itoa(strbuf, probabilities[i], ITOA_PAD_SPACES, 3);
            strcat(strbuf, str_percent);
        } else {
            strcpy(strbuf, str_no_percent);
        }
        tbox_flush_set((u8)(WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + i), 0x00);
        tbox_print_string((u8)(WORLDMAP_UI_HABITAT_TBOX_HABITAT_PERCENTAGES + i), 0, 0, 0, 0, 0, 
            &font_colormap_transparent_on_ui, 0, strbuf);
    }
    

}

static void worldmap_ui_habitat_cursor_moved(__attribute__ ((unused)) u8 self) {
    worldmap_ui_habitat_update_namespace_by_cursor_position(false);
    worldmap_ui_habitat_update_habitat_info_by_cursor();
}

static void worldmap_ui_habitat_cursor_starts_moving(u8 self) {
    (void)self;
}

static u32 worldmap_blending_get_affected_palettes_mask() {
    return (u32) (0b0011111 | (1 << (16 + oam_palette_get_index(WORLDMAP_UI_GFX_TAG_PLAYER_HEAD))) \
            | (1 << (16 + oam_palette_get_index(WORLDMAP_UI_GFX_TAG_CURSOR))));
}

static void worldmap_ui_update_worldmap(u8 self) {
    if (fading_control.active)
        return;
    worldmap_ui_state->cursor = worldmap_ui_state->cursor_switch_maps;
    worldmap_ui_habitat_update_red_should_be_active();
    worldmap_ui_habitat_update_namespace_by_cursor_position(true);
    worldmap_ui_habitat_update_red_overlay();
    worldmap_ui_habitat_update_habitat_info_by_cursor();
    worldmap_ui_update_worldmap_gfx(worldmap_ui_state->cursor.idx, 
                worldmap_ui_state->cursor.layer, worldmap_ui_state->worldmap_tile_x, worldmap_ui_state->worldmap_tile_y);
    worldmap_ui_habitat_draw_red_switch_tiles();
    pal_copy(gfx_worldmap_ui_habitat_framePal + 1, 0, sizeof(color_t));
    worldmap_ui_update_player_head_oam();
        fadescreen(worldmap_blending_get_affected_palettes_mask(), 0, 16, 0, 0);
    bg_virtual_sync_reqeust_push(2);
    bg_virtual_sync_reqeust_push(3);
    big_callbacks[self].function = worldmap_ui_handle_inputs_habitat;
}

static void worldmap_ui_handle_inputs_switch_maps_habitat(u8 self) {
    if (worldmap_ui_switch_maps_dialoge_process_input(self))
        return;
    else if (super.keys_new.keys.B || (super.keys_new.keys.A && worldmap_ui_state->cursor_switch_maps.idx == worldmap_ui_state->cursor.idx &&
            worldmap_ui_state->cursor_switch_maps.layer == worldmap_ui_state->cursor.layer)) {
        play_sound(5);
        worldmap_ui_switch_maps_dialoge_delete();
        big_callbacks[self].function = worldmap_ui_handle_inputs_habitat;
    } else if (super.keys_new.keys.A) {
        play_sound(5);
        worldmap_ui_switch_maps_dialoge_delete();
        tbox_flush_set(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 0x00);
        tbox_sync(WORLDMAP_UI_TBOX_IDX_NAMESPACE, TBOX_SYNC_SET);
        fadescreen(worldmap_blending_get_affected_palettes_mask(), 0, 0, 16, 0);
        big_callbacks[self].function = worldmap_ui_update_worldmap;
    }
}


static void worldmap_ui_exit(u8 self) {
    if (!fading_control.active) {
        callback1_set(worldmap_ui_state->continuation);
        worldmap_ui_habitat_free();
        big_callback_delete(self);
    }
}

static void worldmap_ui_handle_inputs_habitat(u8 self) {
    if (dma3_busy(-1) || fading_control.active)
        return;
    if (worldmap_ui_handle_inputs_move_cursor(self))
        return;
    else if (super.keys_new.keys.select ||
        (super.keys_new.keys.A && worldmap_ui_state->cursor.x == worldmap_ui_state->icon_switch_maps_x &&
            worldmap_ui_state->cursor.y == worldmap_ui_state->icon_switch_maps_y)) {
        play_sound(5);
        worldmap_ui_switch_maps_dialoge_new(self, worldmap_ui_handle_inputs_switch_maps_habitat);
        return;
    } else if (super.keys_new.keys.B) {
        play_sound(5);
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = worldmap_ui_exit;
    }
    // TODO: handle other DPAD presses
}

static void worldmap_ui_habitat_update_red_overlay() {
    bg_tile zero = {0};
    bg_tile *bg2_map = (bg_tile*) worldmap_ui_state->bg2_map;
    cpuset(&zero, bg2_map, CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(sizeof(bg_tile) * 32 * 20));
    for (size_t i = 0; i < worldmap_ui_state->habitats->num_elements; i++) {
        pokedex_habitat_pair *entry = worldmap_ui_state->habitats->list + i;
        if (entry->worldmap_idx == worldmap_ui_state->cursor.idx && 
            entry->layer == worldmap_ui_state->cursor.layer) {
            bg2_map[32 * (entry->worldmap_y + worldmap_ui_state->worldmap_tile_y + WORLDMAP_Y_MARGIN) +
                entry->worldmap_x + worldmap_ui_state->worldmap_tile_x + WORLDMAP_X_MARGIN].text.tile_number = 1;
            bg2_map[32 * (entry->worldmap_y + worldmap_ui_state->worldmap_tile_y + WORLDMAP_Y_MARGIN) +
                entry->worldmap_x + worldmap_ui_state->worldmap_tile_x + WORLDMAP_X_MARGIN].text.palette = 6;
        }
    }
    if (worldmap_ui_state->other_red_should_be_active) {
        // Overlay to the additional switch maps icon
        bg2_map[32 * (worldmap_ui_state->worldmap_tile_y + worldmap_ui_state->icon_switch_maps_y + WORLDMAP_Y_MARGIN) + 
            worldmap_ui_state->worldmap_tile_x + worldmap_ui_state->icon_switch_maps_x + WORLDMAP_X_MARGIN].text.tile_number = 1;
        bg2_map[32 * (worldmap_ui_state->worldmap_tile_y + worldmap_ui_state->icon_switch_maps_y + WORLDMAP_Y_MARGIN) + 
            worldmap_ui_state->worldmap_tile_x + worldmap_ui_state->icon_switch_maps_x + WORLDMAP_X_MARGIN].text.palette = 6;
    }
    for (size_t y = 18; y < 20; y++) {
        for (size_t x = 7; x < 20; x++) {
            bg2_map[32 * y + x].text.tile_number = 1;
            bg2_map[32 * y + x].text.palette = 6;  
        }
    }
}

void worldmap_ui_habitat_update_scanline(u16 colev_worldmap, u16 colev_switch_maps, u16 colev_switch_maps_button) {
	// Initialize the scanline
	for (int i = 0; i < 32; i++) {
		dma0_scanline_frames[0][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(10);
		dma0_scanline_frames[1][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(10);
	}
	for (int i = 32; i < 160 - 24; i++) {
		dma0_scanline_frames[0][i] = colev_worldmap;
		dma0_scanline_frames[1][i] = colev_worldmap;
	}
    for (int i = 160 - 24; i < 160 - 16; i++) {
		dma0_scanline_frames[0][i] = colev_switch_maps_button;
		dma0_scanline_frames[1][i] = colev_switch_maps_button;
    }
    for (int i = 160 - 16; i < 240; i++) {
		dma0_scanline_frames[0][i] = colev_switch_maps;
		dma0_scanline_frames[1][i] = colev_switch_maps;
    }
	dma0_scanline_flipflop_t flipflop = {.bytes = {.flipflop_cntrl = 1, .defaults_field_16_17 = 0}};
	dma0_init_scanline((void*)(IO_ADDRESS + IO_BLDALPHA),
			DMA_ENABLE | DMA_TIMING_HBLANK | DMA_REPEAT | DMA_SRC_INCREMENT | DMA_DST_RELOAD |
			DMA_SIZE(1),
			flipflop);
}

static void worldmap_ui_habitat_apply_red_overlay(u16 intensity_worldmap, u16 intensity_switch_maps) {
    int ea_worldmap = intensity_worldmap;
    int eb_worldmap = 16 - ea_worldmap;
    u16 colev_worldmap = (u16)((eb_worldmap << 8) | ea_worldmap);
    int ea_switch_maps = 2 * intensity_switch_maps;
    int eb_switch_maps = 16 - ea_switch_maps;
    u16 colev_switch_maps = (u16)((eb_switch_maps << 8) | ea_switch_maps);
    int ea_switch_maps_button = intensity_switch_maps;
    int eb_switch_maps_button = 16 - ea_switch_maps_button;
    u16 colev_switch_maps_button = (u16)((eb_switch_maps_button << 8) | ea_switch_maps_button);
    worldmap_ui_habitat_update_scanline(colev_worldmap, colev_switch_maps, colev_switch_maps_button);
}

#define delay params[0]
#define decreasing params[1]
#define intensity params[2]
#define worldmap_alpha_blending_active params[3]

static void worldmap_ui_habitat_red_overlay_task(u8 self_idx) {
    // Update the intensity of the red overlay
    big_callback *self = big_callbacks + self_idx;
    if (self->delay > 0) {
        self->delay--;
    } else {
        if (self->decreasing) { // decrease
            self->intensity--;
            if (self->intensity == 0)
                self->decreasing ^= 1;
        } else { // increase
            self->intensity++;
            if (self->intensity == 8)
                self->decreasing ^= 1;
        }
        self->delay = 2;
    }
    u16 intensity_worldmap = worldmap_ui_state->red_overlay_is_active ? self->intensity : 0;
    u16 intensity_switch_maps = worldmap_ui_state->other_red_is_active ? self->intensity : 0;
    worldmap_ui_state->red_overlay_intensity = (u8)(self->intensity);
    if (self->intensity == 0) {
        // In this frame, the red fading effects can be resynchronized
        worldmap_ui_state->red_overlay_is_active = worldmap_ui_state->red_overlay_should_be_active;
        worldmap_ui_state->other_red_is_active = worldmap_ui_state->other_red_should_be_active;
    }
    worldmap_ui_habitat_apply_red_overlay(intensity_worldmap, intensity_switch_maps);
}

#undef delay
#undef decreasing
#undef intensity

static void worldmap_ui_habitat_update_red_should_be_active() {
    // Does the current worldmap (where the cursor is at) have any red overaly (habitats)
    worldmap_ui_state->red_overlay_should_be_active = 0;
    worldmap_ui_state->other_red_should_be_active = 0;
    for (size_t idx = 0; idx < NUM_WORLDMAPS; idx++) {
        for (size_t layer = 0; layer < NUM_WORLDMAP_LAYERS; layer++) {
            if (worldmap_ui_state->red_overlay_should_be_active_on_worldmap[idx][layer]) {
                if (worldmap_ui_state->cursor.idx == idx && worldmap_ui_state->cursor.layer == layer)
                    worldmap_ui_state->red_overlay_should_be_active = 1;
                else  
                    worldmap_ui_state->other_red_should_be_active = 1;
            }
            DEBUG("Should be active on %d,%d: %d\n", idx, layer, worldmap_ui_state->red_overlay_should_be_active_on_worldmap[idx][layer]);
        }
    }

    // For debugging
    // worldmap_ui_state->red_overlay_should_be_active = 1;
    // worldmap_ui_state->other_red_should_be_active = 1;

    DEBUG("Red overlay should be active %d, other red overlay should be active %d\n",
        worldmap_ui_state->red_overlay_should_be_active, worldmap_ui_state->other_red_should_be_active);
}

static void worldmap_ui_habitat_draw_red_switch_tiles() {
    int gfx_worldmap_red_switch_mapTiles[2] = {0};
    cpuset(gfx_worldmap_red_switch_mapTiles, CHARBASE_PLUS_OFFSET_8BPP(1, 
        WORLDMAP_TOTAL_WIDTH * WORLDMAP_TOTAL_HEIGHT + 1), CPUSET_FILL | CPUSET_HALFWORD |
            CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_8BPP(8, 8)));
    for (size_t y = 18; y < 20; y++) {
        for (size_t x = 7; x < 20; x++) {
            bg_tile *bg3_map = (bg_tile*)worldmap_ui_state->bg3_map;
            bg3_map[y * 32 + x].text.tile_number = WORLDMAP_TOTAL_WIDTH * WORLDMAP_TOTAL_HEIGHT + 1;
        }
    }
}

static void worldmap_ui_callback_initialize_habitat() {
    if (!worldmap_ui_callback_initialize_base())
        return;
    switch (worldmap_ui_state->initialization_state) {
        case WORLDMAP_UI_INITIALIZATION_STATE_DATA_SETUP: {
            worldmap_ui_state->initialization_state++;
            worldmap_ui_state->habitats = pokedex_habitat_list_new(WORLDMAP_POKEDEX_HABITAT_INITIAL_LIST_SIZE, 
                POKEDEX_HABITAT_LIST_MAX_SIZE);
            pokedex_habitat_list_compute_by_species(worldmap_ui_state->habitats, worldmap_ui_state->species);
            worldmap_ui_state->callback_cursor_moved = worldmap_ui_habitat_cursor_moved;
            worldmap_ui_state->callback_cursor_starts_moving = worldmap_ui_habitat_cursor_starts_moving;
            worldmap_ui_state->worldmap_tile_x = WORLDMAP_X_OFFSET_HABITAT;
            worldmap_ui_state->worldmap_tile_y = WORLDMAP_Y_OFFSET_HABITAT;
            worldmap_ui_state->icon_switch_maps_x = WORLDMAP_BUTTON_SWITCH_MAPS_HABITAT_X;
            worldmap_ui_state->icon_switch_maps_y = WORLDMAP_BUTTON_SWITCH_MAPS_HABITAT_Y;
            worldmap_ui_state->switch_map_dialoge_x = WORLDMAP_SWITCH_MAPS_DIALOGE_X_HABITAT;
            worldmap_ui_state->switch_map_dialoge_y = WORLDMAP_SWITCH_MAPS_DIALOGE_Y_HABITAT;
            for (size_t i = 0; i < worldmap_ui_state->habitats->num_elements; i++) {
                pokedex_habitat_pair *entry = worldmap_ui_state->habitats->list + i;
                worldmap_ui_state->red_overlay_should_be_active_on_worldmap[entry->worldmap_idx][entry->layer] = 1;
            }
            worldmap_ui_habitat_update_red_should_be_active();
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_RESET: {
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_BGS: {
            bg_reset(0);
            bg_reset_control_and_displacement();
            bg_setup(0, worldmap_ui_bg_configs, ARRAY_COUNT(worldmap_ui_bg_configs));
            worldmap_ui_state->bg0_map = malloc_and_clear(0x800);
            bg_set_tilemap(0, worldmap_ui_state->bg0_map);
            worldmap_ui_state->bg1_map = malloc_and_clear(0x800);
            bg_set_tilemap(1, worldmap_ui_state->bg1_map);
            worldmap_ui_state->bg2_map = malloc_and_clear(0x800);
            bg_set_tilemap(2, worldmap_ui_state->bg2_map);
            worldmap_ui_state->bg3_map = malloc_and_clear(0x800);
            bg_set_tilemap(3, worldmap_ui_state->bg3_map);
            bg_display_sync();
            bg_virtual_sync(0);
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            bg_virtual_sync(3);
            io_set(IO_WININ, IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) | IO_WININOUT_BG(0, 3) |
                IO_WININOUT_BG(1, 0) | IO_WININOUT_BG(1, 1) | IO_WININOUT_BG(1, 2) | IO_WININOUT_BG(1, 3) | IO_WININOUT_FX(0) |
                IO_WININOUT_FX(1) | IO_WININOUT_OBJ(0) | IO_WININOUT_OBJ(1));
            io_set(IO_DISPCNT, IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL | IO_DISPCNT_OBJ | IO_DISPCNT_WIN0);
            io_set(IO_BLDCNT, IO_BLDCNT_NONE);
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_SCANLINE: {
            dma0_reset_callback();
            io_set(IO_BLDCNT, IO_BLDCNT_BG2_FIRST | IO_BLDCNT_ALPHA_BLENDING | IO_BLDCNT_BG0_SECOND |
                    IO_BLDCNT_BG1_SECOND | IO_BLDCNT_BG2_SECOND | IO_BLDCNT_BG3_SECOND | IO_BLDCNT_OBJ_SECOND |
                    IO_BLDCNT_BACKDROP_SECOND); 
            worldmap_ui_habitat_apply_red_overlay(0, 0);
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_TBOXES: {
            tbox_free_all();
            tbox_sync_with_virtual_bg_and_init_all(worldmap_ui_habitat_tboxes);
            tbox_init_frame_set_style(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, 2, 13 * 16);
            for (u8 i = 0; worldmap_ui_habitat_tboxes[i].bg_id != 0xFF; i++) {
                tbox_flush_set(i, 0x00);
                tbox_flush_map(i);
                tbox_tilemap_draw(i);
                bg_virtual_sync_reqeust_push(worldmap_ui_habitat_tboxes[i].bg_id);
            }
            strcpy(buffer0, pokemon_names[worldmap_ui_state->species]);
            string_decrypt(strbuf, str_header);
            worldmap_ui_state->header_pokemon_name_string_width = string_get_width(2, strbuf, 0);
            tbox_print_string(WORLDMAP_UI_HABITAT_TBOX_HEADER, 2, 2, 1, 0, 0, &font_colormap_transparent, 0, strbuf);
            for (size_t i = 0; i < ARRAY_COUNT(habitat_names); i++) {
                tbox_print_string((u8)(WORLDMAP_UI_HABITAT_TBOX_HABITAT_NAMES + i), 2, 3, 0, 0, 0, &font_colormap_transparent_on_ui, 0, habitat_names[i]);
            }
            if (worldmap_ui_state->habitats->num_elements == 0) {
                tbox_flush_set(WORLDMAP_UI_HABITAT_TBOX_HABITAT_NO_HABITAT, 0x11);
                int width = string_get_width(2, str_no_habitats, 0);
                tbox_print_string(WORLDMAP_UI_HABITAT_TBOX_HABITAT_NO_HABITAT, 2, 
                    (u16)((worldmap_ui_habitat_tboxes[WORLDMAP_UI_HABITAT_TBOX_HABITAT_NO_HABITAT].w * 8 - width) / 2), 0, 0, 0,
                    &font_colormap_non_transparent, 0, str_no_habitats);
            } else {
                tbox_sync(WORLDMAP_UI_HABITAT_TBOX_HABITAT_NO_HABITAT, TBOX_SYNC_SET);
            }
            tbox_sync(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, TBOX_SYNC_SET);
            tbox_print_string(WORLDMAP_UI_HABITAT_TBOX_FOOTER, 2, 2, 1, 0, 0, &font_colormap_transparent, 0, str_footer_key_select);
            tbox_print_string(WORLDMAP_UI_HABITAT_TBOX_FOOTER, 2, 28, 1, 0, 0, &font_colormap_transparent_footer, 0, str_footer_switch_map);
            tbox_print_string(WORLDMAP_UI_HABITAT_TBOX_FOOTER, 2, 82, 1, 0, 0, &font_colormap_transparent, 0, str_footer_key_dpad);
            tbox_print_string(WORLDMAP_UI_HABITAT_TBOX_FOOTER, 2, 92, 1, 0, 0, &font_colormap_transparent_footer, 0, str_footer_move);
            tbox_print_string(WORLDMAP_UI_HABITAT_TBOX_FOOTER, 2, 138, 1, 0, 0, &font_colormap_transparent, 0, str_footer_key_b);
            tbox_print_string(WORLDMAP_UI_HABITAT_TBOX_FOOTER, 2, 148, 1, 0, 0, &font_colormap_transparent_footer, 0, str_footer_back);

            u8 namespace_idx = worldmap_get_namespace_by_pos(worldmap_ui_state->cursor.idx, worldmap_ui_state->cursor.layer,
                worldmap_ui_state->cursor.x, worldmap_ui_state->cursor.y);
            worldmap_ui_habitat_update_namespace_by_cursor_position(true);
            worldmap_ui_habitat_update_habitat_info_by_cursor();
            worldmap_ui_state->current_namespace = namespace_idx;
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_BG_GFX: {
            pal_copy(gfx_worldmap_ui_habitat_framePal, 80, sizeof(gfx_worldmap_ui_habitat_framePal));
            color_t red = {.rgb = {.red = 31, .blue = 0,  .green = 0}};
            pal_copy(&red, 96 + 1, sizeof(color_t));
            pal_copy(gfx_worldmap_ui_habitat_framePal + 1, 0, sizeof(color_t));
            lz77uncompvram(gfx_worldmap_ui_habitat_frameTiles, CHARBASE(2));
            int gfx_worldmap_red_overlayTiles = 0x11111111;
            cpuset(&gfx_worldmap_red_overlayTiles, CHARBASE_PLUS_OFFSET_4BPP(0, 1), CPUSET_FILL | CPUSET_HALFWORD |
                 CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(8, 8)));
            lz77uncompwram(gfx_worldmap_ui_habitat_frameMap, worldmap_ui_state->bg1_map);
            worldmap_ui_habitat_draw_red_switch_tiles();
            worldmap_ui_habitat_update_red_overlay();
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_OAM_GFX: {
            oam_palette_load_if_not_present(&palette_icon_grass);
            oam_palette_load_if_not_present(&palette_icon_water);
            oam_palette_load_if_not_present(&palette_icon_radar);
            oam_palette_load_if_not_present(&palette_icon_rod);
            oam_palette_load_if_not_present(&palette_icon_rod_types);
            oam_palette_load_if_not_present(&palette_icon_ball_caught);
            oam_palette_load_if_not_present(&palette_percentages);
            oam_load_graphic(&graphic_icon_grass);
            oam_load_graphic(&graphic_icon_water);
            oam_load_graphic(&graphic_icon_radar);
            oam_load_graphic(&graphic_icon_rod);
            oam_load_graphic(&graphic_icon_rod_types);
            oam_load_graphic(&graphic_icon_ball_caught);
            u8 oam_idx_icon_grass = oam_new_forward_search(&oam_template_icon_grass, 8, 16, 0);
            u8 oam_idx_icon_water = oam_new_forward_search(&oam_template_icon_water, 8, 48, 0);
            u8 oam_idx_icon_radar = oam_new_forward_search(&oam_template_icon_radar, 8, 80, 0);
            u8 oam_idx_icon_rod = oam_new_forward_search(&oam_template_icon_rod, 8, 104, 0);
            oam_gfx_anim_start(oams + oam_idx_icon_grass, 0);
            oam_gfx_anim_start(oams + oam_idx_icon_water, 0);
            oam_gfx_anim_start(oams + oam_idx_icon_radar, 0);
            oam_gfx_anim_start(oams + oam_idx_icon_rod, 0);
            for (u8 i = 0; i < 3; i++) {
                u8 oam_idx_rod_type = oam_new_forward_search(&oam_template_icon_rod_types, 8, 
                (s16)(121 + 16 * i), 0);
                oam_gfx_anim_start(oams + oam_idx_rod_type, i);
            }
            u8 oam_idx_icon_ball_caught = oam_new_forward_search(&oam_template_icon_ball_caught, 
                (s16)(worldmap_ui_state->header_pokemon_name_string_width + 62), 10, 0);
            u16 base_tile_species_icon = oam_vram_alloc(32);
            oam_vram_allocation_table_add(WORLDMAP_UI_GFX_TAG_ICON_SPECIES, base_tile_species_icon, 32);
            cpuset(pokemon_icons[worldmap_ui_state->species], (void*)(OAMCHARBASE(base_tile_species_icon)), 
                    CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(32, 64)));
            u8 pal_idx_species_icon = oam_allocate_palette(WORLDMAP_UI_GFX_TAG_ICON_SPECIES);
            bool species_is_caught = pokedex_operator(worldmap_ui_state->species, POKEDEX_GET | POKEDEX_CAUGHT, 1);
            if (species_is_caught) {
                pal_copy(icon_pals + pokemon_icon_usage[worldmap_ui_state->species], (u16)(256 + 16 * pal_idx_species_icon), 16 * sizeof(color_t));
            } else {
                color_t pal_black[16] = {0};
                pal_copy(pal_black, (u16)(256 + 16 * pal_idx_species_icon), 16 * sizeof(color_t));
                oams[oam_idx_icon_ball_caught].flags |= OAM_FLAG_INVISIBLE;
            }
            u8 oam_idx_species_icon = oam_new_forward_search(&oam_template_icon_species, 240 - 16, 11, 0);
            oam_gfx_anim_start(oams + oam_idx_species_icon, species_is_caught ? 1 : 0);
            s16 oams_percentage_ys[NUM_HABITAT_TYPES] = {23 + 0 * 32, 22 + 1 * 32, 22 + 2 * 32, 25 + 3 * 32 + 0 * 16, 25 + 3 * 32 + 1 * 16, 25 + 3 * 32 + 2 * 16};
            for (size_t i = 0; i < NUM_HABITAT_TYPES; i++) {
                worldmap_ui_state->oam_idx_percentages[i] = oam_new_forward_search(&oam_template_icon_percentage, 26, oams_percentage_ys[i], 0);
            }
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SHOW: {
            worldmap_ui_state->initialization_state++;
            break;
        }
        default: {
            fading_control.buffer_transfer_disabled = false;
            worldmap_ui_state->cb_idx_handle_inputs = big_callback_new(worldmap_ui_handle_inputs_habitat, 10);
            big_callback_new(worldmap_ui_habitat_red_overlay_task, 11);
            callback1_set(worldmap_ui_cb1);
            vblank_handler_set(worldmap_ui_vblank_callback);
            fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
            // big_callback_new(treasure_map_idle_callbacks[TREASURE_MAP_STATE->context], 0);
            break;
        }
    }
}


static void worldmap_ui_habitat_wait_for_fadescreen_and_initialize_ui(u8 self) {
    if (!fading_control.active) {
        big_callback_delete(self);
        overworld_free();
        callback1_set(worldmap_ui_callback_initialize_habitat);
    }
}


void worldmap_ui_habitat_new(u16 species, void (*continuation)()) {
    worldmap_ui_state = malloc_and_clear(sizeof(worldmap_ui_state_t));
    worldmap_ui_state->species = species;
    worldmap_ui_state->continuation = continuation;
    callback1_set(worldmap_ui_cb1);
    big_callback_new(worldmap_ui_habitat_wait_for_fadescreen_and_initialize_ui, 0);
}

static void worldmap_ui_habitat_free() {
    pokedex_habitat_list_delete(worldmap_ui_state->habitats);
    worldmap_ui_free_base();
}