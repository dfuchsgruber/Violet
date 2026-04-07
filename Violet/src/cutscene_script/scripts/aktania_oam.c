#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "io.h"
#include "bios.h"
#include "constants/species.h"

#define GFX_TAG_AKTANIA_BEAM 0x6E00
extern LZ77COMPRESSED gfx_anim_aktania_beamTiles;
extern LZ77COMPRESSED gfx_anim_aktania_beamPal;

static const rotscale_frame rs_frames_aktania_sky_regis[] = {
    {.affine = {0x60, 0x60, 0, 0, 0}},
    {.command = {ROTSCALE_ANIM_END, 0, 0, 0}}
};

static const rotscale_frame rs_frames_aktania_sky_deoxys[] = {
    {.affine = {0xC0, 0xC0, 0, 0, 0}},
    {.command = {ROTSCALE_ANIM_END, 0, 0, 0}}
};

static const rotscale_frame *const rs_table_aktania_sky_regis[] = {rs_frames_aktania_sky_regis};
static const rotscale_frame *const rs_table_aktania_sky_deoxys[] = {rs_frames_aktania_sky_deoxys};

static const sprite sprite_aktania_sky_regis = {
    ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE, ATTR1_SIZE_64_64, ATTR2_PRIO(2), 0
};

static const sprite sprite_aktania_sky_deoxys = {
    ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE, ATTR1_SIZE_64_64, ATTR2_PRIO(1), 0
};

static const sprite sprite_aktania_beam = {
    ATTR0_SHAPE_VERTICAL, ATTR1_SIZE_32_64, ATTR2_PRIO(0), 0
};

const oam_template oam_template_aktania_sky_deoxys = {
    POKEMON_DEOXYS, POKEMON_DEOXYS,
    &sprite_aktania_sky_deoxys,
    oam_gfx_anim_table_null,
    NULL,
    rs_table_aktania_sky_deoxys,
    oam_null_callback
};

const oam_template oam_template_aktania_sky_regirock = {
    POKEMON_REGIROCK, POKEMON_REGIROCK,
    &sprite_aktania_sky_regis,
    oam_gfx_anim_table_null,
    NULL,
    rs_table_aktania_sky_regis,
    oam_null_callback
};

const oam_template oam_template_aktania_sky_regice = {
    POKEMON_REGICE, POKEMON_REGICE,
    &sprite_aktania_sky_regis,
    oam_gfx_anim_table_null,
    NULL,
    rs_table_aktania_sky_regis,
    oam_null_callback
};

const oam_template oam_template_aktania_sky_registeel = {
    POKEMON_REGISTEEL, POKEMON_REGISTEEL,
    &sprite_aktania_sky_regis,
    oam_gfx_anim_table_null,
    NULL,
    rs_table_aktania_sky_regis,
    oam_null_callback
};

const graphic graphic_aktania_beam = {
    .sprite = gfx_anim_aktania_beamTiles,
    .size = GRAPHIC_SIZE_4BPP(32, 4 * 64),
    .tag = GFX_TAG_AKTANIA_BEAM,
};

static const gfx_frame gfx_anim_aktania_beam_frames[] = {
    {.data = 0, .duration = 0},
    {.data = 0, .duration = 8},
    {.data = GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 64) * 1, .duration = 8},
    {.data = GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 64) * 2, .duration = 8},
    {.data = GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 64) * 3, .duration = 8},
    {.data = GFX_ANIM_END, .duration = 0},
};

static const gfx_frame *const gfx_table_aktania_beam[] = {gfx_anim_aktania_beam_frames};

const oam_template oam_template_aktania_beam = {
    .tiles_tag = GFX_TAG_AKTANIA_BEAM, .pal_tag = GFX_TAG_AKTANIA_BEAM,
    .oam = &sprite_aktania_beam,
    .callback = oam_null_callback,
    .rotscale = oam_rotscale_anim_table_null,
    .animation = gfx_table_aktania_beam,
};