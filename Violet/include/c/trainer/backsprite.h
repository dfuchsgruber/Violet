#ifndef H_TRAINER_BACKSPRITE
#define H_TRAINER_BACKSPRITE

#include "types.h"
#include "oam.h"
#include "constants/trainer_backsprites.h"

palette trainer_backsprite_palettes[TRAINER_BACKSPRITE_CNT];
sprite_coordinates_t trainer_backsprite_coordinates[TRAINER_BACKSPRITE_CNT];

extern sprite trainer_backsprite_sprite;
extern rotscale_frame *trainer_backsprite_rotscale_anim_table[];

/**
 * Oam callback for a trainer backsprite oam.
 * @param self self-reference
 **/
void trainer_backsprite_callback(oam_object *self);


extern const u8 gfx_trainer_backsprite_hiroTiles[];
extern const u8 gfx_trainer_backsprite_hiroineTiles[];
extern const u8 gfx_trainer_backsprite_brendanTiles[];
extern const u8 gfx_trainer_backsprite_mayTiles[];
extern const u8 gfx_trainer_backsprite_pokedudeTiles[];
extern const u8 gfx_trainer_backsprite_old_manTiles[];
extern const u8 gfx_trainer_backsprite_rivalTiles[];

extern const u8 gfx_trainer_backsprite_hiroPal[];
extern const u8 gfx_trainer_backsprite_hiroinePal[];
extern const u8 gfx_trainer_backsprite_brendanPal[];
extern const u8 gfx_trainer_backsprite_mayPal[];
extern const u8 gfx_trainer_backsprite_pokedudePal[];
extern const u8 gfx_trainer_backsprite_old_manPal[];
extern const u8 gfx_trainer_backsprite_rivalPal[];

#endif