/*
 * sprites.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_SPRITES_H_
#define INCLUDE_C_POKEMON_SPRITES_H_

#include "pokemon/virtual.h"
#include "pokemon/count.h"
#include "oam.h"

extern sprite_coordinates_t trainer_sprite_coordinates[];

/**
 * Loads the gfx of a trainer (graphic and palette) into the pokemon buffer of a battler's position.
 * @param sprite_idx the trainer sprite to load
 * @param battler_idx sprite will be loaded into the buffer of this battler's position
 **/
void trainer_gfx_load(u16 sprite_idx, u8 battler_idx);

/**
 * Loads the gfx of a pokemon.
 * @param g the graphic to load, should match the is_frontsprite parameter
 * @param dst memory to place the gfx in
 * @param species the species to load
 * @param pid the pid of the pokemon (for Unown, Spinda)
 */
void pokemon_load_gfx_by_graphic(graphic *g, void *dst, u16 species, pid_t pid);


/**
 * Draws the spinda pattern on a sprite.
 * @param species the species of the pokemon to draw
 * @param pid the pid of the pokemon (used for pattern drawing)
 * @param dst where the gfx is located (uncompressed)
 * @param load_frontsprite if a frontsprite is loaded
 **/
void pokemon_spinda_draw_pattern(u16 species,pid_t pid, void *dst,bool load_frontsprite);

/**
 * Creates an oam with the sprite of a pokemon.
 * @param species the species
 * @param x horizontal position
 * @param y vertical position
 * @return the oam idx created
 **/
u8 pokemon_oam_new(u16 species, s16 x, s16 y);

/**
 * Returns the palette that matches a pokemon.
 * @param p the pokemon to retrieve the palette of
 * @return pointer to the palette structure
 */
palette *pokemon_get_palette(pokemon *p);

// Make this thing round correctly, therefore add 8 / 2 = 4
#define POKEMON_COORDINATE_SIZE(x) (((x) + 4) >> 3)

typedef struct {
    u8 width : 4;
    u8 height : 4;
    u8 y_offset;
    u8 field2;
    u8 field3;
} pokemon_coordinate_t;

graphic pokemon_frontsprites[POKEMON_CNT];
graphic pokemon_backsprites[POKEMON_CNT];
palette pokemon_pals[POKEMON_CNT];
palette pokemon_shiny_pals[POKEMON_CNT];
u8 pokemon_icon_usage[POKEMON_CNT];
const void *pokemon_icons[POKEMON_CNT];

pokemon_coordinate_t pokemon_player_y[POKEMON_CNT];
pokemon_coordinate_t pokemon_enemy_y[POKEMON_CNT];
u8 pokemon_altitude[POKEMON_CNT];
u16 icon_pals[3][16];

#endif /* INCLUDE_C_POKEMON_SPRITES_H_ */
