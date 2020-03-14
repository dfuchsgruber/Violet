#include "types.h"
#include "oam.h"
#include "trainer/backsprite.h"


graphic gfx_trainer_backsprite_hiro[5] = {
    {.sprite = gfx_trainer_backsprite_hiroTiles + 0 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_hiroTiles + 1 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_hiroTiles + 2 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_hiroTiles + 3 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_hiroTiles + 4 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
};

graphic gfx_trainer_backsprite_hiroine[5] = {
    {.sprite = gfx_trainer_backsprite_hiroineTiles + 0 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_hiroineTiles + 1 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_hiroineTiles + 2 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_hiroineTiles + 3 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_hiroineTiles + 4 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
};

graphic gfx_trainer_backsprite_brendan[4] = {
    {.sprite = gfx_trainer_backsprite_brendanTiles + 0 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_brendanTiles + 1 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_brendanTiles + 2 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_brendanTiles + 3 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
};

graphic gfx_trainer_backsprite_may[4] = {
    {.sprite = gfx_trainer_backsprite_mayTiles + 0 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_mayTiles + 1 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_mayTiles + 2 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_mayTiles + 3 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
};

graphic gfx_trainer_backsprite_pokedude[4] = {
    {.sprite = gfx_trainer_backsprite_pokedudeTiles + 0 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_pokedudeTiles + 1 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_pokedudeTiles + 2 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_pokedudeTiles + 3 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
};

graphic gfx_trainer_backsprite_old_man[4] = {
    {.sprite = gfx_trainer_backsprite_old_manTiles + 0 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_old_manTiles + 1 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_old_manTiles + 2 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_old_manTiles + 3 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
};

graphic gfx_trainer_backsprite_rival[4] = {
    {.sprite = gfx_trainer_backsprite_rivalTiles + 0 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_rivalTiles + 1 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_rivalTiles + 2 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
    {.sprite = gfx_trainer_backsprite_rivalTiles + 3 * GRAPHIC_SIZE_4BPP(64, 64), .size = GRAPHIC_SIZE_4BPP(64, 64)},
};

oam_template trainer_backsprite_templates[TRAINER_BACKSPRITE_CNT] = {
    [TRAINER_BACKSPRITE_HIRO] = {
        .tiles_tag = 0xFFFF,
        .pal_tag = 0,
        .oam = &trainer_backsprite_sprite,
        .animation = NULL,
        .graphics = gfx_trainer_backsprite_hiro,
        .rotscale = trainer_backsprite_rotscale_anim_table,
        .callback = trainer_backsprite_callback
    },
    [TRAINER_BACKSPRITE_HIROINE] = {
        .tiles_tag = 0xFFFF,
        .pal_tag = 0,
        .oam = &trainer_backsprite_sprite,
        .animation = NULL,
        .graphics = gfx_trainer_backsprite_hiroine,
        .rotscale = trainer_backsprite_rotscale_anim_table,
        .callback = trainer_backsprite_callback
    },
    [TRAINER_BACKSPRITE_BRENDAN] = {
        .tiles_tag = 0xFFFF,
        .pal_tag = 0,
        .oam = &trainer_backsprite_sprite,
        .animation = NULL,
        .graphics = gfx_trainer_backsprite_brendan,
        .rotscale = trainer_backsprite_rotscale_anim_table,
        .callback = trainer_backsprite_callback
    },
    [TRAINER_BACKSPRITE_MAY] = {
        .tiles_tag = 0xFFFF,
        .pal_tag = 0,
        .oam = &trainer_backsprite_sprite,
        .animation = NULL,
        .graphics = gfx_trainer_backsprite_may,
        .rotscale = trainer_backsprite_rotscale_anim_table,
        .callback = trainer_backsprite_callback
    },
    [TRAINER_BACKSPRITE_POKEDUDE] = {
        .tiles_tag = 0xFFFF,
        .pal_tag = 0,
        .oam = &trainer_backsprite_sprite,
        .animation = NULL,
        .graphics = gfx_trainer_backsprite_pokedude,
        .rotscale = trainer_backsprite_rotscale_anim_table,
        .callback = trainer_backsprite_callback
    },
    [TRAINER_BACKSPRITE_OLD_MAN] = {
        .tiles_tag = 0xFFFF,
        .pal_tag = 0,
        .oam = &trainer_backsprite_sprite,
        .animation = NULL,
        .graphics = gfx_trainer_backsprite_old_man,
        .rotscale = trainer_backsprite_rotscale_anim_table,
        .callback = trainer_backsprite_callback
    },
    [TRAINER_BACKSPRITE_RIVAL] = {
        .tiles_tag = 0xFFFF,
        .pal_tag = 0,
        .oam = &trainer_backsprite_sprite,
        .animation = NULL,
        .graphics = gfx_trainer_backsprite_rival,
        .rotscale = trainer_backsprite_rotscale_anim_table,
        .callback = trainer_backsprite_callback
    },
};

static gfx_frame trainer_backsprite_animation_frame_0[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END}
};

static gfx_frame trainer_backsprite_animation_frame_3[] = {
    {.data = 3, .duration = 0}, {.data = GFX_ANIM_END}
};

static gfx_frame trainer_backsprite_animation_throw_hiro[] = {
    {.data = 1, .duration = 20},
    {.data = 2, .duration = 6},
    {.data = 3, .duration = 6},
    {.data = 4, .duration = 24},
    {.data = 0, .duration = 1},
    {.data = GFX_ANIM_END}
};

static gfx_frame trainer_backsprite_animation_throw_brendan[] = {
    {.data = 0, .duration = 24},
    {.data = 1, .duration = 9},
    {.data = 2, .duration = 24},
    {.data = 0, .duration = 9},
    {.data = 3, .duration = 50},
    {.data = GFX_ANIM_END}
};

static gfx_frame trainer_backsprite_animation_throw_pokedude[] = {
    {.data = 1, .duration = 24},
    {.data = 2, .duration = 9},
    {.data = 3, .duration = 24},
    {.data = 0, .duration = 9},
    {.data = GFX_ANIM_END}
};

static gfx_frame *trainer_backsprite_animations_hiro[] = {
    trainer_backsprite_animation_frame_0, trainer_backsprite_animation_throw_hiro
};

static gfx_frame *trainer_backsprite_animations_hiroine[] = {
    trainer_backsprite_animation_frame_0, trainer_backsprite_animation_throw_hiro
};

static gfx_frame *trainer_backsprite_animations_brendan[] = {
    trainer_backsprite_animation_frame_3, trainer_backsprite_animation_throw_brendan
};

static gfx_frame *trainer_backsprite_animations_may[] = {
    trainer_backsprite_animation_frame_3, trainer_backsprite_animation_throw_brendan
};

static gfx_frame *trainer_backsprite_animations_pokedude[] = {
    trainer_backsprite_animation_frame_0, trainer_backsprite_animation_throw_pokedude
};

static gfx_frame *trainer_backsprite_animations_old_man[] = {
    trainer_backsprite_animation_frame_0, trainer_backsprite_animation_throw_pokedude
};

static gfx_frame *trainer_backsprite_animations_rival[] = {
    trainer_backsprite_animation_frame_3, trainer_backsprite_animation_throw_brendan
};

palette trainer_backsprite_palettes[TRAINER_BACKSPRITE_CNT] = {
    [TRAINER_BACKSPRITE_HIRO] = {.pal = gfx_trainer_backsprite_hiroPal, .tag = TRAINER_BACKSPRITE_HIRO},
    [TRAINER_BACKSPRITE_HIROINE] = {.pal = gfx_trainer_backsprite_hiroinePal, .tag = TRAINER_BACKSPRITE_HIROINE},
    [TRAINER_BACKSPRITE_BRENDAN] = {.pal = gfx_trainer_backsprite_brendanPal, .tag = TRAINER_BACKSPRITE_BRENDAN},
    [TRAINER_BACKSPRITE_MAY] = {.pal = gfx_trainer_backsprite_mayPal, .tag = TRAINER_BACKSPRITE_MAY},
    [TRAINER_BACKSPRITE_POKEDUDE] = {.pal = gfx_trainer_backsprite_pokedudePal, .tag = TRAINER_BACKSPRITE_POKEDUDE},
    [TRAINER_BACKSPRITE_OLD_MAN] = {.pal = gfx_trainer_backsprite_old_manPal, .tag = TRAINER_BACKSPRITE_OLD_MAN},
    [TRAINER_BACKSPRITE_RIVAL] = {.pal = gfx_trainer_backsprite_rivalPal, .tag = TRAINER_BACKSPRITE_RIVAL},
};

sprite_coordinates_t trainer_backsprite_coordinates[TRAINER_BACKSPRITE_CNT] = {
    [TRAINER_BACKSPRITE_HIRO] = {.y_offset = 8, .frames = 5},
    [TRAINER_BACKSPRITE_HIROINE] = {.y_offset = 8, .frames = 5},
    [TRAINER_BACKSPRITE_BRENDAN] = {.y_offset = 8, .frames = 4},
    [TRAINER_BACKSPRITE_MAY] = {.y_offset = 8, .frames = 4},
    [TRAINER_BACKSPRITE_POKEDUDE] = {.y_offset = 8, .frames = 4},
    [TRAINER_BACKSPRITE_OLD_MAN] = {.y_offset = 8, .frames = 4},
    [TRAINER_BACKSPRITE_RIVAL] = {.y_offset = 8, .frames = 4},
};

gfx_frame **trainer_backsprite_animations[] = {
    [TRAINER_BACKSPRITE_HIRO] = trainer_backsprite_animations_hiro,
    [TRAINER_BACKSPRITE_HIROINE] = trainer_backsprite_animations_hiroine,
    [TRAINER_BACKSPRITE_BRENDAN] = trainer_backsprite_animations_brendan,
    [TRAINER_BACKSPRITE_MAY] = trainer_backsprite_animations_may,
    [TRAINER_BACKSPRITE_POKEDUDE] = trainer_backsprite_animations_pokedude,
    [TRAINER_BACKSPRITE_OLD_MAN] = trainer_backsprite_animations_old_man,
    [TRAINER_BACKSPRITE_RIVAL] = trainer_backsprite_animations_rival,
};