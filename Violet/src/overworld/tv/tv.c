#include "overworld/tv.h"
#include "flags.h"
#include "prng.h"
#include "constants/species.h"
#include "agbmemory.h"
#include "vars.h"
#include "constants/story_states.h"
#include "constants/flags.h"
#include "text.h"
#include "map/namespace.h"
#include "map/header.h"
#include "constants/species.h"
#include "pokemon/names.h"
#include "overworld/script.h"

extern const u8 tv_show_text_swarm[];
extern const u8 tv_show_text_weather_forecast_sunny[];
extern const u8 tv_show_text_weather_forecast_rainy[];
extern const u8 tv_show_text_weather_forecast_snowy[];
extern const u8 tv_show_text_weather_forecast_unknown[]; // fallback
extern const u8 tv_show_default_text[]; // fallback
extern const u8 tv_show_text_new_champ[];
extern const u8 tv_show_tann_done_text[];
extern const u8 tv_show_bruchfels_done_text[];
extern const u8 tv_show_felsige_oednis_rival_done[];
extern const u8 tv_show_silvania_forest_done[];
extern const u8 tv_show_kuestenberg_done[];
extern const u8 tv_show_bluetenbach_gym_done[];
extern const u8 tv_show_mistral_igva_done[];
extern const u8 tv_show_volcano_done[];

const tv_story_event_t tv_story_events[] = {
    {.story_state = STORY_STATE_NONE, .flag = FLAG_TV_SHOW_NEW_CHAMP, .text = tv_show_text_new_champ},
    {.story_state = STORY_STATE_ROUTE_2_TANN_DONE, .flag = FLAG_TV_SHOW_TANN_DONE, .text = tv_show_tann_done_text},
    {.story_state = STORY_STATE_BRUCHFELS_DONE, .flag = FLAG_TV_SHOW_BRUCHFELS_DONE, .text = tv_show_bruchfels_done_text},
    {.story_state = STORY_STATE_FELSIGE_ODENIS_RIVAL_DONE, .flag = FLAG_TV_SHOW_FELSIGE_OEDNIS_RIVAL_DONE, .text = tv_show_felsige_oednis_rival_done},
    {.story_state = STORY_STATE_SILVANIA_FOREST_DONE, .flag = FLAG_TV_SHOW_SILVANIA_FOREST_DONE, .text = tv_show_silvania_forest_done},
    {.story_state = STORY_STATE_KUESTENBERG_DONE, .flag = FLAG_TV_SHOW_KUESTENBERG_DONE, .text = tv_show_kuestenberg_done},
    {.story_state = STORY_STATE_BLUETENBACH_GYM_DONE, .flag = FLAG_TV_SHOW_BLUETENBACH_GYM_DONE, .text = tv_show_bluetenbach_gym_done},
    {.story_state = STORY_STATE_ROUTE_6_MISTRAL_IGVA_DONE, .flag = FLAG_TV_SHOW_MISTRAL_IGVA_DONE, .text = tv_show_mistral_igva_done},
    {.story_state = STORY_STATE_VULCANO_DONE, .flag = FLAG_TV_SHOW_VOLCANO_DONE, .text = tv_show_volcano_done},
};

const u8 *tv_get_story_event_text() {
    u16 story_progress = *var_access(VAR_STORY_STATE);
    for (int i = (int)(ARRAY_COUNT(tv_story_events) - 1); i >= 0; i--) {
        if (story_progress >= tv_story_events[i].story_state) {
            if (!checkflag(tv_story_events[i].flag)) {
                return tv_story_events[i].text;
            } else {
                // The latest show has already been seen, don't show earlier shows
                return NULL;
            }

        }
    }
    return NULL;
}

static const tv_event_location_t tv_event_locations[] = {
    {.bank = 3, .map_idx = 19}, // Route 1
    {.bank = 3, .map_idx = 7}, // Route 2
    {.bank = 3, .map_idx = 41}, // Route 3
    {.bank = 15, .map_idx = 0}, // Route 4
    {.bank = 3, .map_idx = 74}, // Felsige Oednis
    {.bank = 1, .map_idx = 59}, // Kuestenberg North
    {.bank = 3, .map_idx = 22}, // Route 5
    {.bank = 3, .map_idx = 23}, // Route 6
};

static const size_t tv_event_probabilities[NUM_TV_EVENTS] = {
    [TV_EVENT_SWARM] = 1,
    [TV_EVENT_WEATHER_FORECAST] = 2,
};

static const tv_event_swarm_species_t tv_event_swarm_species[] = {
    {.species = POKEMON_BISASAM, .rate = 1},
    {.species = POKEMON_GLUMANDA, .rate = 1},
    {.species = POKEMON_SCHIGGY, .rate = 1},
    {.species = POKEMON_PIKACHU, .rate = 3},
    {.species = POKEMON_SCHLURP, .rate = 2},
    {.species = POKEMON_CHANEIRA, .rate = 1},
    {.species = POKEMON_SICHLOR, .rate = 2},
    {.species = POKEMON_DITTO, .rate = 2,},
    {.species = POKEMON_EVOLI, .rate = 2},
    {.species = POKEMON_ENDIVIE, .rate = 1},
    {.species = POKEMON_FEURIGEL, .rate = 1},
    {.species = POKEMON_KARNIMANI, .rate = 1},
    {.species = POKEMON_CLAVION, .rate = 2},
    {.species = POKEMON_MAMPFAXO, .rate = 2},
    {.species = POKEMON_PANZAERON, .rate = 2},
    {.species = POKEMON_SEN_LONG, .rate = 1,},
    {.species = POKEMON_LARVITAR, .rate = 1},
    {.species = POKEMON_LOCKSCHAL, .rate = 1},
    {.species = POKEMON_WELUNO, .rate = 1},
    {.species = POKEMON_SEEKID, .rate = 1},
    {.species = POKEMON_FLUNKIFER, .rate = 2},
    {.species = POKEMON_ABSOL, .rate = 1},
    {.species = POKEMON_SENGO, .rate = 2},
    {.species = POKEMON_VIPITIS, .rate = 2},
    {.species = POKEMON_TANHEL, .rate = 1},
};

static const u8 tv_event_weather_events[NUM_TV_WEATHER_EVENTS] = {
    [TV_EVENT_WEATHER_RAINY] = MAP_WEATHER_RAIN,
    [TV_EVENT_WEATHER_SUNNY] = MAP_WEATHER_EXTREME_SUN,
    [TV_EVENT_WEATHER_SNOWY] = MAP_WEATHER_SNOW,
};

static void tv_buffer_namespace_by_location_idx(u8 location_idx, u8 *dst) {
    u8 namespace;
    if (location_idx < ARRAY_COUNT(tv_event_locations)) {
        namespace = mapbanks[tv_event_locations[location_idx].bank][tv_event_locations[location_idx].map_idx]->map_namespace;
    } else {
        namespace = MAP_NAMESPACE_NONE;
    }
    strcpy(dst, map_namespaces[namespace]);
}

static void tv_buffer_species_by_swarm_species_idx(u8 species_idx, u8 *dst) {
    u16 species;
    if (species_idx < ARRAY_COUNT(tv_event_swarm_species)) {
        species = tv_event_swarm_species[species_idx].species;
    } else {
        species = POKEMON_POKEMON_0;
    }
    strcpy(dst, pokemon_names[species]);
}

const u8 *tv_get_text() {
    const u8 *text = tv_get_story_event_text();
    if (text) {
        return text;
    }
    switch (*var_access(VAR_TV_EVENT)) {
        case TV_EVENT_STORY:
            text = tv_get_story_event_text();
            break;
        case TV_EVENT_SWARM:
            text = tv_show_text_swarm;
            tv_event_swarm_t swarm = {.value = *var_access(VAR_TV_EVENT_PARAMETERS)};
            tv_buffer_namespace_by_location_idx(swarm.fields.location_idx, buffer0);
            tv_buffer_species_by_swarm_species_idx(swarm.fields.species_idx, buffer1);
            break;
        case TV_EVENT_WEATHER_FORECAST: {
            tv_event_weather_t weather = {.value = *var_access(VAR_TV_EVENT_PARAMETERS)};
            tv_buffer_namespace_by_location_idx(weather.fields.location_idx, buffer0);
            switch (weather.fields.weather_event) {
                case TV_EVENT_WEATHER_RAINY:
                    text = tv_show_text_weather_forecast_rainy;
                    break;
                case TV_EVENT_WEATHER_SUNNY:
                    text = tv_show_text_weather_forecast_sunny;
                    break;
                case TV_EVENT_WEATHER_SNOWY:
                    text = tv_show_text_weather_forecast_snowy;
                    break;
                default:
                    text = tv_show_text_weather_forecast_unknown;
                    break;
            }
            break;
        }
    }
    if (text) {
        return text;
    } else {
        return tv_show_default_text; // Should not be reached, safety fallback
    }
}

void tv_load_text() {
    overworld_script_state.pointer_banks[0] = tv_get_text();
}

bool tv_broadcast_is_on() {
    if (tv_get_story_event_text()) {
        return true;
    }
    return checkflag(FLAG_TV_DAILY_SHOW_SEEN) == false;
}

void special_get_tv_broadcast_is_on() {
    lastresult = tv_broadcast_is_on();
}

u16 tv_event_swarm_get_species_if_active(u8 bank, u8 map_idx) {
    if (*var_access(VAR_TV_EVENT) != TV_EVENT_SWARM) {
        return 0;
    }
    tv_event_swarm_t swarm = {.value = *var_access(VAR_TV_EVENT_PARAMETERS)};
    tv_event_location_t location = tv_event_locations[swarm.fields.location_idx];
    if (location.bank == bank && location.map_idx == map_idx) {
        return tv_event_swarm_species[swarm.fields.species_idx].species;
    }
    return 0;
}

u8 tv_event_weather_get_if_active(u8 bank, u8 map_idx) {
    if (*var_access(VAR_TV_EVENT) != TV_EVENT_WEATHER_FORECAST) {
        return NUM_MAP_WEATHERS;
    }
    tv_event_weather_t weather = {.value = *var_access(VAR_TV_EVENT_PARAMETERS)};
    tv_event_location_t location = tv_event_locations[weather.fields.location_idx];
    if (location.bank == bank && location.map_idx == map_idx) {
        return tv_event_weather_events[weather.fields.weather_event];
    }
    return NUM_MAP_WEATHERS;
}

void tv_randomize_event() {
    clearflag(FLAG_TV_DAILY_SHOW_SEEN);
    size_t event = choice(tv_event_probabilities, ARRAY_COUNT(tv_event_probabilities), gp_rnd16);
    *var_access(VAR_TV_EVENT) = (u16)event;
    switch (event) {
        case TV_EVENT_SWARM: {
            tv_event_swarm_t swarm;
            u8 location_idx = (u8)(gp_rnd16() % ARRAY_COUNT(tv_event_locations));
            size_t *species_rates = malloc(ARRAY_COUNT(tv_event_swarm_species) * sizeof(size_t));
            for (size_t i = 0; i < ARRAY_COUNT(tv_event_swarm_species); i++) {
                species_rates[i] = tv_event_swarm_species[i].rate;
            }
            u8 species_idx = (u8)(choice(species_rates, ARRAY_COUNT(tv_event_swarm_species), gp_rnd16));
            free(species_rates);
            swarm.fields.location_idx = location_idx;
            swarm.fields.species_idx = species_idx;
            *var_access(VAR_TV_EVENT_PARAMETERS) = swarm.value;
            break;
        }
        case TV_EVENT_WEATHER_FORECAST: {
            tv_event_weather_t weather;
            u8 location_idx = (u8)(gp_rnd16() % ARRAY_COUNT(tv_event_locations));
            u8 weather_event = (u8)(gp_rnd16() % NUM_TV_WEATHER_EVENTS);
            weather.fields.location_idx = location_idx;
            weather.fields.weather_event = weather_event;
            *var_access(VAR_TV_EVENT_PARAMETERS) = weather.value;
            break;
        }
    }
}
