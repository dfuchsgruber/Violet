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

#define EV_MENU_OAM_POKEPIC_TAG 0xA000
#define EV_MENU_OAM_IV_HEXAGON_TAG 0xA001
#define EV_MENU_OAM_EV_HEXAGON_TAG 0xA002

// Do not display zero iv's / ev's as zero but use a small threshold to make the chart more
// appealing
#define EV_MENU_IV_CHART_MIN_VALUE 3
#define EV_MENU_EV_CHART_MIN_VALUE 7

typedef struct {
	u8 party_idx;
	u8 stat_idx;
	u8 oam_pokepic_idx;
	u8 delay;
	u16 oam_pokepic_tile;
	u16 oam_iv_hexagon_tile;
	u16 oam_ev_hexagon_tile;
	u8 oam_iv_hexagon_idx;
	u8 oam_ev_hexagon_idx;
	int *pokemon_sprite;
	int *iv_hexagon_sprite;
	int *ev_hexagon_sprite;
	// Picture and color the currently rendered polygon uses
	int *render_sprite;
	u8 render_color;
} ev_menu_state_stru;

/**
 * Callback to animate the jump of a pokemon.
 * @param self index of the callback
 */
void ev_menu_big_callback_jump(u8 self);

/**
 * Sets a pixel on the graphic selected by the ev menu state to the corresponding selected color.
 */
void ev_menu_set_pixel(int x, int y);

/**
 * Reloads the currently selected stat in the ev menu.
 */
void ev_menu_load_stat();

/**
 * Redraws the iv spider chart for the current pokemon displayed in the ev menu.
 */
void ev_menu_load_iv_chart();

/**
 * Redraws the ev spider chart for the current pokemon displayed in the ev menu.
 */
void ev_menu_load_ev_chart();

/**
 * Updates the current pokemon displayed in the ev menu.
 */
void ev_menu_load_pokemon();

/**
 * Initializes the ev menu from the party selection.
 * @param self idx of the callback that triggered the ev menu
 */
void ev_menu_init(u8 self);

/**
 * Big callback that first hides, updates and shows the pokemon.
 */
void ev_menu_big_callback_update_pokemon(u8 self);

/**
 * Loads all elements related to the evs and ivs of a pokemon, i.e. stat display, charts, total evs
 */
void ev_menu_load_evs_and_ivs();

/**
 * Updates the total effective ev for the currently selected pokemon.
 */
void ev_menu_load_effective_ev_total();

/**
 * Tries to increase the effective evs for the currently selected stat.
 * @return if the effective evs for the currently selected stat could be increased
 */
bool ev_menu_increase_effective_ev();

/**
 * Callback1 for the idle state of the ev menu
 */
void ev_menu_callback_idle();

/**
 * Callback1 to show the components of the ev menu after setup.
 */
void ev_menu_callback_show();

/**
 * Callback1 to return to the party menu.
 */
void ev_menu_callback_return();

/**
 * Callback1 to setup the components of the ev menu.
 */
void ev_menu_callback_setup();

#define EV_MENU_BG_COUNT 3
bg_config ev_menu_bg_configs[EV_MENU_BG_COUNT];


#define EV_MENU_TBOX_COUNT 13
#define EV_MENU_TBOX_NAME 0
#define EV_MENU_TBOX_HEADER 1
#define EV_MENU_TBOX_HIDDEN_POWER 2
#define EV_MENU_TBOX_HIDDEN_POWER_TYPE 3
#define EV_MENU_TBOX_HIDDEN_POWER_STRENGTH 4
#define EV_MENU_TBOX_CHART_STATS 5
#define EV_MENU_TBOX_IV_CHART_HEADER 6
#define EV_MENU_TBOX_EV_CHART_HEADER 7
#define EV_MENU_TBOX_TOTAL_EV 8
#define EV_MENU_TBOX_CURRENT_STAT_HEADER 9
#define EV_MENU_TBOX_CURRENT_IV 10
#define EV_MENU_TBOX_CURRENT_EV 11
#define EV_MENU_TBOX_HIDDEN_POWER_HEADER 12

tboxdata ev_menu_tboxes[EV_MENU_TBOX_COUNT + 1];

extern u16 gfx_ev_menu_bgTiles[];
extern u16 gfx_ev_menu_bgMap[];
extern u16 gfx_ev_menu_bgPal[];
extern u16 gfx_ev_menu_hexagonPal[];

#endif /* INCLUDE_C_EV_MENU_H_ */
