/*
 * map_control.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_MAP_CONTROL_H_
#define INCLUDE_C_OVERWORLD_MAP_CONTROL_H_


typedef struct{
    u8 x_start_pixel;
    u8 y_start_pixel;
    u8 x_start;
    u8 y_start;
} stru_map_displ_cntrl;

extern stru_map_displ_cntrl map_displ_cntrl;

/**
 * Returns the state of an overworld flag (0 or != 0)
 * This is done by accessing 0x02037078 and masking the byte with the flag
 * Known flags:
 * 8 (=1 << 3) : If not set wildbattles in water are not triggered
 */
int overworld_flag_get(u8 flag);

/**
 * Reloads the map state
 */
void map_reload();

/**
 * Reloads the map state without fadings (small mapreaload)
 */
void map_reload_no_fading();

/**
 * Sets up the data for warping the player
 * @param bank the target map bank
 * @param map the target map id
 * @param exit the target warp
 * @param x the target x coordiante (if exit == 0xFF)
 * @param y the target y coordiante (if exit == 0xFF)
 */
void warp_setup(u8 bank, u8 map, u8 exit, s16 x, s16 y);

/**
 * Performs warp setup based on an event on a map.
 * @param bank the bank the warp targets
 * @param map the map inside the bank the warp targets
 * @param warp_idx the idx of the warp targeted by the triggering warp

 */
void warp_setup_by_event (u8 target_bank, u8 target_map, u8 warp_idx);

/**
 * Sets up callbacks to execute the warping process setup by warp_setup
 */
void warp_setup_callbacks();

/**
 * Gets the weather currently present
 * @return the current weather
 */
u8 map_get_current_weather();

/**
 * Plays the fadeout sound for rain
 */
void map_play_sound_rain_fadeout();

/**
 * Sets up the warp teleport callback
 */
void warp_setup_teleport_callback();

/**
 * Sets up the warp muted teleport callback
 */
void warp_setup_muted_callback();

/**
 * Enables the warp flags
 */
void warp_enable_flags();

/**
 * Sets the warp history (last used warp)
 * @param unused not used
 * @param bank target map bank
 * @param map target map id
 * @param exit target warp
 * @param x x coordiante if exit == 0xFF
 * @param y y coordinate if exit == 0xFF
 */
void warp_last_map_set(int unused, u8 bank, u8 map, u8 exit, s16 x, s16 y);

/**
 * Sets the last map to a map and the current player coordinates.
 * @param bank the bank to set
 * @param map the map to set
 * @param warp_idx the warp index to set
 */
void warp_last_map_set_on_current_position(u8 bank, u8 map, s8 warp_idx);

/**
 * Updates the last outdoor map to the current map if and only if the current map is an outdoor
 * map and the target map is not an outdoor map.
 * @param x position on the current map (+7 because of borders)
 * @param y position on the current map (+7 because of borders)
 */
void warp_update_last_outdoor_map (s16 x, s16 y);

/**
 * Sets a map and position to the last outdoor map visited by the player.
 * @param bank the bank of the last outdoor map
 * @param map the map index of the last outdoor map
 * @param exit the warp index on the last outdoor map (or -1)
 * @param x the x coordinate on the last outdoor map (or -1)
 * @param y the y coordinate on the last outdoor map (or -1)
 */
void warp_set_last_outdoor_map (u8 bank, u8 map, s8 exit, s16 x, s16 y);

/**
 * Frees all components of the overworld (i.e. virtual maps)
 */
void overworld_free();

/**
 * Callback1 that triggers a mapreload. Used if the overworld interface was not visible previously.
 **/
void overworld_return_to();

#endif /* INCLUDE_C_OVERWORLD_MAP_CONTROL_H_ */
