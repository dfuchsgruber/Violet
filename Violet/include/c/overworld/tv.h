#ifndef H_OVERWORLD_TV
#define H_OVERWORLD_TV

#include "types.h"
#include "constants/map_weathers.h"

enum {
    TV_EVENT_STORY,
    TV_EVENT_SWARM,
    TV_EVENT_WEATHER_FORECAST,
    NUM_TV_EVENTS,
};

enum {
    TV_EVENT_WEATHER_RAINY,
    TV_EVENT_WEATHER_SUNNY,
    TV_EVENT_WEATHER_SNOWY,
    NUM_TV_WEATHER_EVENTS,
};

typedef struct {
    u16 story_state;
    u16 flag;
    const u8 *text;
} tv_story_event_t;

typedef union {
    u16 value;
    struct {
        u8 species_idx;
        u8 location_idx;
    } fields;
} tv_event_swarm_t;

typedef struct {
    u8 bank;
    u8 map_idx;
} tv_event_location_t;


typedef struct {
    u16 species;
    u16 rate;
} tv_event_swarm_species_t;


typedef union {
    u16 value;
    struct {
        u8 weather_event;
        u8 location_idx;
    } fields;
} tv_event_weather_t;

/**
 * Get the species of the swarm event if it is active at the given location.
 * @param bank The bank of the location.
 * @param map_idx The map index of the location.
 * @return The species of the swarm event, or 0 if no swarm event is active at that location.
 */
u16 tv_event_swarm_get_species_if_active(u8 bank, u8 map_idx);

/**
 * Get the weather event if it is active at the given location.
 * @param bank The bank of the location.
 * @param map_idx The map index of the location.
 * @return The map weather, or NUM_MAP_WEATHERS if no weather event is active at that location.
 */
u8 tv_event_weather_get_if_active(u8 bank, u8 map_idx);

/**
 * Randomly select a TV event and set the appropriate variables.
 */
void tv_randomize_event();

/**
 * Check if the TV broadcast is currently on.
 * @return true if the TV broadcast is on, false otherwise.
 */
bool tv_broadcast_is_on();

#endif