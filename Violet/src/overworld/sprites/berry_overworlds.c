#include "types.h"
#include "overworld/sprite.h"
#include "color.h"
#include "constants/items.h"
#include "berry.h"
#include "debug.h"

static gfx_frame gfx_animation_berry_idle[] = {
	{.data = 0, .duration = 0}, {.data = 0, .duration = 32}, {.data = 1, .duration = 32}, {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame *gfx_animations_berry_tree[9] = {gfx_animation_berry_idle};

palette ow_berry_pals[NUM_OW_PAL_TAGS_BERRY] = {
    [2] = {.pal = gfx_ow_berry_pal2Pal, .tag = OW_PAL_TAG_BERRY_BASE + 2},
    [3] = {.pal = gfx_ow_berry_pal3Pal, .tag = OW_PAL_TAG_BERRY_BASE + 3},
    [4] = {.pal = gfx_ow_berry_pal4Pal, .tag = OW_PAL_TAG_BERRY_BASE + 4},
    [5] = {.pal = gfx_ow_berry_pal5Pal, .tag = OW_PAL_TAG_BERRY_BASE + 5},
}; 

static graphic overworld_gfxs_cheri_berry[] = {
	[0] = {gfx_ow_berry_cheriTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_cheriTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_cheriTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_cheriTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_cheriTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_cheriTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_chesto_berry[] = {
	[0] = {gfx_ow_berry_chestoTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_chestoTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_chestoTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_chestoTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_chestoTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_chestoTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_pecha_berry[] = {
	[0] = {gfx_ow_berry_pechaTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_pechaTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_pechaTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_pechaTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_pechaTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_pechaTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_rawst_berry[] = {
	[0] = {gfx_ow_berry_rawstTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_rawstTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_rawstTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_rawstTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_rawstTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_rawstTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_aspear_berry[] = {
	[0] = {gfx_ow_berry_aspearTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_aspearTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_aspearTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_aspearTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_aspearTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_aspearTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_leppa_berry[] = {
	[0] = {gfx_ow_berry_leppaTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_leppaTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_leppaTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_leppaTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_leppaTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_leppaTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_oran_berry[] = {
	[0] = {gfx_ow_berry_oranTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_oranTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_oranTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_oranTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_oranTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_oranTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_persim_berry[] = {
	[0] = {gfx_ow_berry_persimTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_persimTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_persimTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_persimTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_persimTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_persimTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_lum_berry[] = {
	[0] = {gfx_ow_berry_lumTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_lumTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_lumTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_lumTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_lumTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_lumTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_sitrus_berry[] = {
	[0] = {gfx_ow_berry_sitrusTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_sitrusTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_sitrusTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_sitrusTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_sitrusTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_sitrusTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_figy_berry[] = {
	[0] = {gfx_ow_berry_figyTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_figyTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_figyTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_figyTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_figyTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_figyTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_wiki_berry[] = {
	[0] = {gfx_ow_berry_wikiTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_wikiTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_wikiTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_wikiTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_wikiTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_wikiTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_mago_berry[] = {
	[0] = {gfx_ow_berry_magoTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_magoTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_magoTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_magoTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_magoTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_magoTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_aguav_berry[] = {
	[0] = {gfx_ow_berry_aguavTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_aguavTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_aguavTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_aguavTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_aguavTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_aguavTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_iapapa_berry[] = {
	[0] = {gfx_ow_berry_iapapaTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_iapapaTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_iapapaTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_iapapaTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_iapapaTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_iapapaTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_razz_berry[] = {
	[0] = {gfx_ow_berry_razzTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_razzTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_razzTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_razzTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_razzTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_razzTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_bluk_berry[] = {
	[0] = {gfx_ow_berry_razzTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_razzTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_razzTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_razzTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_razzTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_razzTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_nanab_berry[] = {
	[0] = {gfx_ow_berry_magoTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_magoTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_magoTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_magoTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_magoTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_magoTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_wepear_berry[] = {
	[0] = {gfx_ow_berry_wepearTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_wepearTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_wepearTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_wepearTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_wepearTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_wepearTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_pinap_berry[] = {
	[0] = {gfx_ow_berry_iapapaTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_iapapaTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_iapapaTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_iapapaTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_iapapaTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_iapapaTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_pomeg_berry[] = {
	[0] = {gfx_ow_berry_pomegTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_pomegTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_pomegTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_pomegTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_pomegTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_pomegTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_kelpsy_berry[] = {
	[0] = {gfx_ow_berry_kelpsyTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_kelpsyTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_kelpsyTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_kelpsyTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_kelpsyTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_kelpsyTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_qualot_berry[] = {
	[0] = {gfx_ow_berry_wepearTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_wepearTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_wepearTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_wepearTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_wepearTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_wepearTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_hondew_berry[] = {
	[0] = {gfx_ow_berry_hondewTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_hondewTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_hondewTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_hondewTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_hondewTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_hondewTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_grepa_berry[] = {
	[0] = {gfx_ow_berry_grepaTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_grepaTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_grepaTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_grepaTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_grepaTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_grepaTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_tamato_berry[] = {
	[0] = {gfx_ow_berry_tamatoTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_tamatoTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_tamatoTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_tamatoTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_tamatoTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_tamatoTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_cornn_berry[] = {
	[0] = {gfx_ow_berry_cornnTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_cornnTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_cornnTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_cornnTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_cornnTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_cornnTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_magost_berry[] = {
	[0] = {gfx_ow_berry_pomegTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_pomegTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_pomegTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_pomegTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_pomegTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_pomegTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_rabuta_berry[] = {
	[0] = {gfx_ow_berry_rabutaTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_rabutaTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_rabutaTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_rabutaTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_rabutaTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_rabutaTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_nomel_berry[] = {
	[0] = {gfx_ow_berry_nomelTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_nomelTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_nomelTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_nomelTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_nomelTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_nomelTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_spelon_berry[] = {
	[0] = {gfx_ow_berry_spelonTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_spelonTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_spelonTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_spelonTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_spelonTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_spelonTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_pamtre_berry[] = {
	[0] = {gfx_ow_berry_pamtreTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_pamtreTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_pamtreTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_pamtreTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_pamtreTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_pamtreTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_watmel_berry[] = {
	[0] = {gfx_ow_berry_rabutaTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_rabutaTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_rabutaTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_rabutaTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_rabutaTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_rabutaTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_durin_berry[] = {
	[0] = {gfx_ow_berry_durinTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_durinTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_durinTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_durinTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_durinTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_durinTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_belue_berry[] = {
	[0] = {gfx_ow_berry_hondewTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_hondewTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_hondewTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_hondewTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_hondewTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_hondewTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_liechi_berry[] = {
	[0] = {gfx_ow_berry_liechiTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_liechiTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_liechiTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_liechiTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_liechiTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_liechiTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_ganlon_berry[] = {
	[0] = {gfx_ow_berry_hondewTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_hondewTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_hondewTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_hondewTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_hondewTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_hondewTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_salac_berry[] = {
	[0] = {gfx_ow_berry_aguavTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_aguavTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_aguavTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_aguavTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_aguavTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_aguavTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_petaya_berry[] = {
	[0] = {gfx_ow_berry_pomegTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_pomegTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_pomegTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_pomegTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_pomegTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_pomegTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_apicot_berry[] = {
	[0] = {gfx_ow_berry_grepaTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_grepaTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_grepaTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_grepaTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_grepaTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_grepaTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_lansat_berry[] = {
	[0] = {gfx_ow_berry_lansatTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_lansatTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_lansatTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_lansatTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_lansatTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_lansatTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_starf_berry[] = {
	[0] = {gfx_ow_berry_cornnTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_cornnTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_cornnTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_cornnTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_cornnTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_cornnTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

static graphic overworld_gfxs_enigma_berry[] = {
	[0] = {gfx_ow_berry_durinTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_berry_durinTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_berry_durinTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_berry_durinTiles + 3 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_berry_durinTiles + 4 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_berry_durinTiles + 5 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};


overworld_sprite overworlds_berry_trees[][3] = {
	[ITEM_AMRENABEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_cheri_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_cheri_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_cheri_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_MARONBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_chesto_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_chesto_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_chesto_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_PIRSIFBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pecha_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pecha_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pecha_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_FRAGIABEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_rawst_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_rawst_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_rawst_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_WILBIRBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_aspear_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_aspear_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_aspear_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_JONAGOBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_leppa_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_leppa_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_leppa_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_SINELBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_oran_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_oran_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_oran_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_PERSIMBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_persim_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_persim_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_persim_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_PRUNUSBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_lum_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_lum_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_lum_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_TSITRUBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_sitrus_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_sitrus_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_sitrus_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_GIEFEBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_figy_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_figy_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_figy_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_WIKIBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_wiki_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_wiki_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_wiki_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_MAGOBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_mago_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_mago_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_mago_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_GAUVEBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_aguav_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_aguav_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_aguav_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_YAPABEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_iapapa_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_iapapa_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_iapapa_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_HIMMIHBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_razz_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_razz_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_razz_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_MORBBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_bluk_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_bluk_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_bluk_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_NANABBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_nanab_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_nanab_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_nanab_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_NIRBEBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_wepear_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_wepear_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_wepear_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_SANANABEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pinap_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pinap_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pinap_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_GRANABEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pomeg_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pomeg_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pomeg_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_SETANGBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_kelpsy_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_kelpsy_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_kelpsy_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_QUALOTBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_qualot_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_qualot_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_qualot_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_HONMELBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 5,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_hondew_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 5,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_hondew_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 5,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_hondew_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_LABRUSBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_grepa_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_grepa_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_grepa_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_TAMOTBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_tamato_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_tamato_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_tamato_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_SAIMBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_cornn_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_cornn_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_cornn_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_MAGOSTBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_magost_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_magost_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_magost_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_RABUTABEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_rabuta_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_rabuta_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_rabuta_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_TRONZIBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_nomel_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_nomel_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_nomel_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_KIWANBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_spelon_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_spelon_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_spelon_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_PALLMBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pamtre_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pamtre_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_pamtre_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_WASMELBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_watmel_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_watmel_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_watmel_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_DURINBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_durin_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_durin_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_durin_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_MYRTILBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 5,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_belue_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 5,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_belue_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 5,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_belue_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_LYDZIBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_liechi_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_liechi_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_liechi_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_LINGANBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 5,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_ganlon_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 5,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_ganlon_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 5,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_ganlon_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_SALKABEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_salac_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_salac_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_salac_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_TAHAYBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_petaya_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_petaya_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_petaya_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_APIKOBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_apicot_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_apicot_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_apicot_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_LANSATBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_lansat_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_lansat_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_lansat_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_KRAMBOBEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_starf_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_starf_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 2,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_starf_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
	[ITEM_ENIGMABEERE - ITEM_FIRST_BERRY] = {
		[BERRY_STAGE_TALLER - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_enigma_berry + 0, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BLOSSOM - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_enigma_berry + 2, .rotscale_animation = oam_rotscale_anim_table_null,
		},
		[BERRY_STAGE_BERRIES - BERRY_STAGE_TALLER] = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
			.unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
			.final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
			.graphics = overworld_gfxs_enigma_berry + 4, .rotscale_animation = oam_rotscale_anim_table_null,
		},
	},
};

static graphic overworld_gfxs_none[] = {
    [0] = {.sprite = gfx_ow_berry_noneTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_berry_noneTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

overworld_sprite overworld_berry_tree_none = {
    .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
    .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
    .final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
    .graphics = overworld_gfxs_none, .rotscale_animation = oam_rotscale_anim_table_null,
	.inanimate = true,
};

static graphic overworld_gfxs_none_fertilized[] = {
    [0] = {.sprite = gfx_ow_berry_none_fertilizedTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_berry_none_fertilizedTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

overworld_sprite overworld_berry_tree_none_fertilized = {
    .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
    .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
    .final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
    .graphics = overworld_gfxs_none_fertilized, .rotscale_animation = oam_rotscale_anim_table_null,
	.inanimate = true,
};

static graphic overworld_gfxs_dirt_pile[] = {
    [0] = {.sprite = gfx_ow_berry_dirt_pileTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_berry_dirt_pileTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

overworld_sprite overworld_berry_tree_dirt_pile = {
    .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 3,
    .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
    .final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
    .graphics = overworld_gfxs_dirt_pile, .rotscale_animation = oam_rotscale_anim_table_null,
	.inanimate = true,
};

static graphic overworld_gfxs_sprout[] = {
    [0] = {.sprite = gfx_ow_berry_sproutTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {.sprite = gfx_ow_berry_sproutTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

overworld_sprite overworld_berry_tree_sprout = {
    .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_BERRY_BASE + 4,
    .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
    .final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_berry_tree,
    .graphics = overworld_gfxs_sprout, .rotscale_animation = oam_rotscale_anim_table_null,
};

overworld_sprite *overworld_sprite_get_by_berry_idx(u8 berry_idx) {
	u8 stage = cmem.berry_trees[berry_idx].stage;
	u8 berry = cmem.berry_trees[berry_idx].berry;
	//dprintf("Requesting ow sprite for berry idx %d, in stage %d with berry %d\n", berry_idx, stage, berry);
	if (stage == BERRY_STAGE_NO_BERRY) {
		if (cmem.berry_trees[berry_idx].fertilized)
			return &overworld_berry_tree_none_fertilized;
		else 
			return &overworld_berry_tree_none;
	} else if (stage == BERRY_STAGE_DIRT_PILE)
        return &overworld_berry_tree_dirt_pile;
	else if (stage == BERRY_STAGE_SPROUT)
		return &overworld_berry_tree_sprout;
    overworld_sprite *r = &overworlds_berry_trees[berry][stage - BERRY_STAGE_TALLER];
	//dprintf("Is @0x%x\n", r);
	return r;
}

palette *overworld_palette_berry_get_by_tag(u16 tag) {
    if (tag >= OW_PAL_TAG_BERRY_BASE && tag < (OW_PAL_TAG_BERRY_BASE + NUM_OW_PAL_TAGS_BERRY)) {
		return ow_berry_pals + (tag - OW_PAL_TAG_BERRY_BASE);
	}
	return ow_berry_pals + 0;
}

palette *overworld_palette_get_by_berry_idx(u8 berry_idx) {
    u16 tag = overworld_sprite_get_by_berry_idx(berry_idx)->pal_tag;
    return overworld_palette_berry_get_by_tag(tag);
}


u8 overworld_get_sprite_idx_by_berry_idx(u8 berry_idx) {
    (void)berry_idx;
	return OVERWORLD_SPRITE_BERRY;
}