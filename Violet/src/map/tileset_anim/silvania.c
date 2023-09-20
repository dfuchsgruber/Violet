#include "types.h"
#include "map/tileset.h"
#include "overworld/effect.h"
#include "overworld/sprite.h"
#include "oam.h"
#include "save.h"
#include "flags.h"
#include "debug.h"

#define SILVANIA_FOREST_BANK 1
#define SILVANIA_FOREST_MAP 0
#define SILVANIA_FOREST_HYDRO_PUMP_TAG 0x889

extern const u8 gfx_silvania_forest_hydro_pumpsTiles[];
extern const u8 gfx_silvania_forest_hydro_pumpsPal[];

static const graphic hydro_pump_graphic = {
  .sprite = gfx_silvania_forest_hydro_pumpsTiles, .tag = SILVANIA_FOREST_HYDRO_PUMP_TAG, .size = 3 * GRAPHIC_SIZE_4BPP(16, 32),
};

static const gfx_frame hydro_pump_animation[] = {
  {.data = 0, .duration = 0},
  {.data = 0, .duration = 12},
  {.data = 8, .duration = 12},
  {.data = 16, .duration = 12},
  {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const hydro_pump_animations[] = {hydro_pump_animation};

static const s16 hydro_pump_locations[][2] = {
  {0x2d + 7, 0x12 + 7},
  {0x31 + 7, 0x13 + 7},
};

static const u16 hydro_pump_flags[] = {
  FLAG_SILVANIA_FOREST_HYDRO_PUMP_0,
  FLAG_SILVANIA_FOREST_HYDRO_PUMP_1,
};


static const sprite hydro_pump_final_oam = {
    .attr0 = ATTR0_SHAPE_VERTICAL,
    .attr1 = ATTR1_SIZE_16_32,
    .attr2 = ATTR2_PRIO(2),
};

static void hydro_pump_oam_callback(oam_object *self) {
  if (save1->bank != SILVANIA_FOREST_BANK || save1->map != SILVANIA_FOREST_MAP) {
    oam_free(self);
    return;
  }
  u16 idx = self->private[0];
  s16 x = hydro_pump_locations[idx][0];
  s16 y = hydro_pump_locations[idx][1];
  if (!checkflag(hydro_pump_flags[idx]) || overworld_effect_is_oam_outside_camera_view(x, y, 16, 32)) {
    self->flags |= OAM_FLAG_INVISIBLE;
  } else {
      self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
      map_position_to_oam_position(x, y, &self->x, &self->y);
      // Center at block
      self->x = (s16)(self->x + 8);
      self->y = (s16)(self->y - 16);
  }
}

static const oam_template hydro_pump_template = {
    .tiles_tag = SILVANIA_FOREST_HYDRO_PUMP_TAG, .pal_tag = SILVANIA_FOREST_HYDRO_PUMP_TAG,
    .oam = &hydro_pump_final_oam,
    .animation = hydro_pump_animations,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = hydro_pump_oam_callback,
};

static void hydro_pumps_initialize() {
  u8 pal_idx = oam_allocate_palette(SILVANIA_FOREST_HYDRO_PUMP_TAG);
  // DEBUG("Applying shaders to hydro pump sprites\n");
  pal_decompress(gfx_silvania_forest_hydro_pumpsPal, (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
  pal_apply_shaders_by_oam_palette_idx(pal_idx);
  oam_load_graphic(&hydro_pump_graphic);
  for (u8 idx = 0; idx < ARRAY_COUNT(hydro_pump_locations); idx++) {
    u8 oam_idx = oam_new_backward_search(&hydro_pump_template, 0, 0, 255);
    oams[oam_idx].flags |= OAM_FLAG_CENTERED;
    oams[oam_idx].private[0] = idx;
    oams[oam_idx].callback(oams + oam_idx);
  }
}


extern const u8 gfx_maptileset_silvania_animation_sparklesTiles[];
extern const u8 gfx_maptileset_silvania_animation_fireTiles[];

static const tileset_animation tileset_silvania_animations[] = {
    {
		.cycle = 6, .speed = 8, .start_tile = 0x282, .num_tiles = 4 * 3,
		.gfx = gfx_maptileset_silvania_animation_sparklesTiles
    },
    {
		.cycle = 6, .speed = 8, .start_tile = 0x298, .num_tiles = 4,
		.gfx = gfx_maptileset_silvania_animation_fireTiles
    },
};

static const tileset_animation_header tileset_silvania_animations_head = {
    ARRAY_COUNT(tileset_silvania_animations), tileset_silvania_animations
};


void tileset_silvania_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_silvania_animations_head, clk);
}

void tileset_silvania_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_silvania_animations_head);
    tileset_anim_1 = tileset_silvania_anim;
    hydro_pumps_initialize();
}