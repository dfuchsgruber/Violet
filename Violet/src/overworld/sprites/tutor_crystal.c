#include "types.h"
#include "overworld/sprite.h"
#include "overworld/script.h"
#include "color.h"
#include "constants/items.h"
#include "save.h"
#include "debug.h"
#include "flags.h"
#include "vars.h"
#include "agbmemory.h"
#include "prng.h"
#include "overworld/misc.h"
#include "math.h"
#include "music.h"
#include "constants/pokemon_types.h"

static palette overworld_tutor_crystal_pals[] = {
    [TYPE_NORMAL] = {.pal = gfx_tutor_crystal_normalPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_NORMAL},
    [TYPE_KAMPF] = {.pal = gfx_tutor_crystal_fightingPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_KAMPF},
    [TYPE_FLUG] = {.pal = gfx_tutor_crystal_flyingPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_FLUG},
    [TYPE_GIFT] = {.pal = gfx_tutor_crystal_poisonPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_GIFT},
    [TYPE_BODEN] = {.pal = gfx_tutor_crystal_groundPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_BODEN},
    [TYPE_GESTEIN] = {.pal = gfx_tutor_crystal_rockPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_GESTEIN},
    [TYPE_KAEFER] = {.pal = gfx_tutor_crystal_bugPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_KAEFER},
    [TYPE_GEIST] = {.pal = gfx_tutor_crystal_ghostPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_GEIST},
    [TYPE_STAHL] = {.pal = gfx_tutor_crystal_steelPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_STAHL},
    [TYPE_FEE] = {.pal = gfx_tutor_crystal_fairyPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_FEE},
    [TYPE_FEUER] = {.pal = gfx_tutor_crystal_firePal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_FEUER},
    [TYPE_WASSER] = {.pal = gfx_tutor_crystal_waterPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_WASSER},
    [TYPE_PFLANZE] = {.pal = gfx_tutor_crystal_grassPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_PFLANZE},
    [TYPE_ELEKTRO] = {.pal = gfx_tutor_crystal_electricPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_ELEKTRO},
    [TYPE_PSYCHO] = {.pal = gfx_tutor_crystal_psychicPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_PSYCHO},
    [TYPE_EIS] = {.pal = gfx_tutor_crystal_icePal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_EIS},
    [TYPE_DRACHE] = {.pal = gfx_tutor_crystal_dragonPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_DRACHE},
    [TYPE_UNLICHT] = {.pal = gfx_tutor_crystal_darkPal, .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_UNLICHT},
};

palette *overworld_palette_tutor_crystal_get_by_tag(u16 tag) {
    return overworld_tutor_crystal_pals + tag - OW_PAL_TAG_TUTOR_CRYSTAL_BASE;
};

static graphic overworld_tutor_crystal_graphics[] = {
    [0] = {.sprite = gfx_tutor_crystal_bugTiles + 0 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE},
    [1] = {.sprite = gfx_tutor_crystal_bugTiles + 1 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE},
    [2] = {.sprite = gfx_tutor_crystal_bugTiles + 2 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE},
    [3] = {.sprite = gfx_tutor_crystal_bugTiles + 3 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE},
    [4] = {.sprite = gfx_tutor_crystal_bugTiles + 4 * GRAPHIC_SIZE_4BPP(32, 32), .size = GRAPHIC_SIZE_4BPP(32, 32), .tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE},
};

static gfx_frame gfx_animation_tutor_crystal[] = {
	{.data = 0, .duration = 0}, {.data = 0, .duration = 12}, {.data = 1, .duration = 12}, 
    {.data = 2, .duration = 12}, {.data = 3, .duration = 12}, {.data = 4, .duration = 12},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame *gfx_animations_tutor_crystal[1] = {gfx_animation_tutor_crystal};

static overworld_sprite ow_tutor_crystals[] = {
	[TYPE_NORMAL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_NORMAL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_KAMPF] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_KAMPF,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_FLUG] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_FLUG,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_GIFT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_GIFT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_BODEN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_BODEN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_GESTEIN] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_GESTEIN,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_KAEFER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_KAEFER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_GEIST] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_GEIST,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_STAHL] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_STAHL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_FEE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_FEE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_FEUER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_FEUER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_WASSER] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_WASSER,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_PFLANZE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_PFLANZE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_ELEKTRO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_ELEKTRO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_PSYCHO] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_PSYCHO,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_EIS] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_EIS,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_DRACHE] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_DRACHE,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
    [TYPE_UNLICHT] = {
        .tiles_tag = 0xFFFF, .pal_tag = OW_PAL_TAG_TUTOR_CRYSTAL_BASE + TYPE_UNLICHT,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(32, 32), .width = 32, .height = 32,
        .final_oam = &ow_final_oam_32_32, .subsprite_table = &ow_formation_32_32, .gfx_animation = gfx_animations_tutor_crystal,
        .graphics = overworld_tutor_crystal_graphics, .rotscale_animation = oam_rotscale_anim_table_null,
    },
};

overworld_sprite ow_mega_stone;

overworld_sprite *overworld_sprite_get_by_tutor_crystal_type(u16 type) {
    DEBUG("Getting ow sprite of crystal type %d\n", type);
    return ow_tutor_crystals + type;
}