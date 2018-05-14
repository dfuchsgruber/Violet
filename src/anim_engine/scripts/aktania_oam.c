#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "romfuncs.h"
#include "constants/species.h"

rotscale_frame rs_frames_aktania_sky_regis[] = {
    {0x60, 0x60, 0, 0, 0},
    {ROTSCALE_ANIM_END, 0, 0, 0, 0}
};

rotscale_frame rs_frames_aktania_sky_deoxys[] = {
    {0xC0, 0xC0, 0, 0, 0},
    {ROTSCALE_ANIM_END, 0, 0, 0, 0}
};

rotscale_frame *rs_table_aktania_sky_regis[] = {rs_frames_aktania_sky_regis};
rotscale_frame *rs_table_aktania_sky_deoxys[] = {rs_frames_aktania_sky_deoxys};

sprite sprite_aktania_sky_regis = {
    ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE, ATTR1_SIZE_64_64, ATTR2_PRIO(2), 0
};

sprite sprite_aktania_sky_deoxys = {
    ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE, ATTR1_SIZE_64_64, ATTR2_PRIO(1), 0
};

oam_template oam_template_aktania_sky_deoxys = {
    POKEMON_DEOXYS, POKEMON_DEOXYS,
    &sprite_aktania_sky_deoxys,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    rs_table_aktania_sky_deoxys,
    oam_null_callback
};


oam_template oam_template_aktania_sky_regirock = {
    POKEMON_REGIROCK, POKEMON_REGIROCK,
    &sprite_aktania_sky_regis,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    rs_table_aktania_sky_regis,
    oam_null_callback
};

oam_template oam_template_aktania_sky_regice = {
    POKEMON_REGICE, POKEMON_REGICE,
    &sprite_aktania_sky_regis,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    rs_table_aktania_sky_regis,
    oam_null_callback
};

oam_template oam_template_aktania_sky_registeel = {
    POKEMON_REGISTEEL, POKEMON_REGISTEEL,
    &sprite_aktania_sky_regis,
    OAM_GFX_ANIM_TABLE_NULL,
    NULL,
    rs_table_aktania_sky_regis,
    oam_null_callback
};
