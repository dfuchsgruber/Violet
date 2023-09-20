#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "io.h"
#include "bios.h"
#include "constants/species.h"

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
