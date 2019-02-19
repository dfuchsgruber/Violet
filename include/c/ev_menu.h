/*
 * ev_menu.h
 *
 *  Created on: Feb 17, 2019
 *      Author: dominik
 */

#ifndef INCLUDE_C_EV_MENU_H_
#define INCLUDE_C_EV_MENU_H_

#include "pokemon/virtual.h"
#include "oam.h"
#include "bg.h"
#include "text.h"

typedef struct {
	u8 party_idx;
	u8 cursor_position;
	u8 oam_idx;
	u8 delay;
	u16 oam_tile;
	u8 oam_palette;
	void *pokemon_sprite;
} ev_menu_state_stru;


/**
 * Initializes the ev menu from the party selection.
 * @param self idx of the callback that triggered the ev menu
 */
void ev_menu_init(u8 self);

/**
 * Callback1 for the idle state of the ev menu
 */
void ev_menu_callback_idle();

/**
 * Callback1 to show the components of the ev menu after setup.
 */
void ev_menu_callback_show();

/**
 * Callback1 to setup the components of the ev menu.
 */
void ev_menu_callback_setup();

bg_config ev_menu_bg_configs[2];

#define EV_MENU_TBOX_COUNT 14
tboxdata ev_menu_tboxes[EV_MENU_TBOX_COUNT];

extern u16 gfx_ev_menu_bgTiles[];
extern u16 gfx_ev_menu_bgMap[];
extern u16 gfx_ev_menu_bgPal[];

#endif /* INCLUDE_C_EV_MENU_H_ */
