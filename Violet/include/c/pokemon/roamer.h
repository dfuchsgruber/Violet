#ifndef H_POKEMON_ROAMER
#define H_POKEMON_ROAMER

#include "types.h"
#include "pokemon/virtual.h"

#define NUM_ROAMERS 3
#define ROAMER_LEVEL 35

typedef struct {
    pid_t pid;
    u32 ivs;
    // u16 species;
    u16 hp;
    // u8 level;
    u8 status;
    // *** Some attributes are present in a vanilla game roamer, but excluded from violet due to memory issues ***
    // u8 coolness;
    // u8 beauty;
    // u8 cuteness;
    // u8 smartness;
    // u8 toughness;
    u8 is_present;
    // u8 field_20[8];
    u8 pps[4]; // New field
} roamer_state_t;

typedef struct {
    u8 bank;
    u8 map_idx;
} roamer_history_entry_t;

extern const roamer_history_entry_t cloud_maps[];
extern const u16 roamer_species[NUM_ROAMERS];
extern EWRAM u8 roamer_last_encountered;

/**
 * Gets the index of a random cloud map to spawn a roamer on.
 * @return the index of a random cloud map to access cloud_maps
 */
int roamer_get_random_map();

/**
 * Resets all roamers
 */
void roamer_reset_all();

/**
 * Resets one particular roamer.
 * @param roamer_idx the index of the roamer to reset.
 **/
void roamer_reset(int roamer_idx);

/**
 * Initializes a roamer.
 * @param roamer_idx the index of the roamer to initialize.
 **/
void roamer_initialize(int roamer_idx);

/**
 * Updates the histories of all roamers, i.e. adds their current location to the history.
 **/
void roamer_history_update();

/**
 * Randomizes the position of a roamer to a map_idx it has not been recently.
 * @param roamer_idx the index of the roamer to reloacte
 */
void roamer_randomize_position(int roamer_idx);

/**
 * Randomizes the position of all roamers that are active to map_idxs they have not been recently.
 **/
void roamer_randomize_position_all();

/** 
 * Moves all roamers to adjacent maps or, with a 1/16 probability randomizes their position 
 **/
void roamer_move_all();

/**
 * Creates a new pokemon that corresponds to a roamer.
 * @param roamer_idx the roamer that the pokemon to create should correspond to.
 **/
void pokemon_new_roamer(int roamer_idx);

/**
 * Checks if a roamer is present at a given location.
 * @param bank the map bank of the location
 * @param map_idx the map index of the location
 * @param roamer_idx the index of the roamer to check
 * @return if the roamer is present at the requested location
 **/  
bool roamer_is_present(u8 bank, u8 map_idx, int roamer_idx);

/**
 * Tries to spawn a roamer with a 50% chance if one is present at the current map.
 * @return if a roamer was spawned
 **/
bool wild_pokemon_spawn_roamer();

/**
 * Updates a roamer after it was battled and randomizes its position.
 **/
void roamer_last_encountered_update_and_randomize_position();

/**
 * Deletes the roamer after it was battled (and defeated).
 **/
void roamer_last_encountered_set_not_present();

/**
 * Returns the roamer idx corresponding to a species.
 * @param species the species to find the roamer idx to
 * @return the roamer idx or -1 if no roamer is of this species
 **/
int species_to_roamer_idx(u16 species);

/**
 * Returns the namespace of a roamer if it is present.
 * @param roamer_idx the roamer to get the namespace of its location
 * @return the namespace of its location or MAP_NAMESPACE_NONE if it is not present
 **/
u8 roamer_get_namespace(int roamer_idx);

/**
 * Initializes a battle with roamer flags.
 **/
void battle_initialize_roamer();

#endif