#ifndef H_POKEPAD_VS_SEEKER
#define H_POKEPAD_VS_SEEKER

#include "types.h"
#include "constants/flags.h"
#include "overworld/npc.h"
#include "trainer/trainer.h"
#define VS_SEEKER_NUM_FLAGS (96 * 8)

typedef struct {
    const u8 *script;
    u16 trainer_idx;
    u8 person_idx;
    u8 npc_idx;
    s16 x;
    s16 y;
    u8 sprite_idx;
    u8 filler[3];
} vs_seeker_trainer_t;

typedef struct
{
    vs_seeker_trainer_t trainers[NUM_NPCS];
    /*0x100*/ u8 filler_100[0x300];
    /*0x400*/ u16 trainer_idxs[NUM_NPCS];
    /*0x420*/ u8 behaviours[NUM_NPCS];
    /*0x430*/ u8 num_rematchable_trainers;
    /*0x431*/ u8 trainer_has_not_been_fought:1;
    /*0x431*/ u8 trainer_does_not_want_rematch:1;
    /*0x431*/ u8 trainer_wants_rematch:1;
    u8 response_code:5;
} vs_seeker_state_t;

typedef enum {
    VSSEEKER_RESPONSE_NO_VISIBLE_TRAINERS,
    VSSEEKER_RESPONSE_NO_REMATCHES_FOUND,
    VSSEEKER_RESPONSE_UNFOUGHT_TRAINERS,
    VSSEEKER_RESPONSE_FOUND_REMATCHES
} vs_seeker_response;

extern vs_seeker_state_t *vs_seeker_state;

extern u8 ow_script_vs_seeker[];

/**
 * Gets a rematch flag in the save file
 * @param rematch_idx the rematch flag to get
 * @return true if the flag is set, false otherwise
 */
bool vs_seeker_get_rematch_flag(u16 rematch_idx);

/**
 * Sets a rematch flag in the save file
 * @param rematch_idx the rematch flag to set
 */
void vs_seeker_set_rematch_flag(u16 rematch_idx);

/**
 * Clears a rematch flag in the save file
 * @param rematch_idx the rematch flag to clear
 */
void vs_seeker_clear_rematch_flag(u16 rematch_idx);

/**
 * Resets all rematch flags in the save file
 */
void vs_seeker_reset_rematch_flags();

/**
 * Gets the probability in percentage that a rematch flag is set when randomly setting rematch flags.
 * @return the probability in percentage that a rematch flag is set when randomly setting rematch flags.
 */
 int vs_seeker_get_rematch_flag_set_probability_percentage();

/**
 * Randomly sets rematch flags in the save file according to the probability defined by vs_seeker_get_rematch_flag_set_probability_percentage.
 */
void vs_seeker_randomly_set_rematch_flags();

/**
 * Sets all rematch flags in the save file, so that all rematches are available.
 */
void vs_seeker_set_all_rematch_flags();

/**
 * Initializes the VS Seeker.
 * @param is_outdoor whether triggered from the overworld
 */
void vs_seeker_initialize(bool is_outdoor);

/**
    * Initializes the VS Seeker state based on the trainers currently in the map.
    * Should be called when entering a map to update the VS Seeker state according to the current map's trainers.
*/
void vs_seeker_state_initialize_by_persons();

/**
 * Checks if a rematchable trainer is visible.
 * @return whether a rematchable trainer is visible
 */
bool vs_seeker_is_trainer_visible(vs_seeker_trainer_t *trainer);

/**
 * Applies a movement script to a VS Seeker trainer.
 * @param trainer the trainer to apply the movement to
 * @param movements the movement script to apply
 */
void vs_seeker_trainer_applymovement(vs_seeker_trainer_t *trainer, const u8 *movements);

/**
 * Checks if a VS Seeker trainer wants a rematch.
 * @param trainer_idx the trainer index to check
 * @return whether the trainer wants a rematch
 */
bool vs_seeker_trainer_wants_rematch(u16 trainer_idx);


/**
 * For a person on the map, sets the rematch triggered flag, so that interaction triggers a rematch
 * @param person_idx the person index to set the rematch triggered flag for
 */
void vs_seeker_person_set_rematch_triggered(u8 person_idx);

/**
 * For a person on the map, clears the rematch triggered flag
 * @param person_idx the person index to clear the rematch triggered flag for
 */
void vs_seeker_person_clear_rematch_triggered(u8 person_idx);

/**
 * For a person on the map, gets whether the rematch triggered flag is set
 * @param person_idx the person index to get the rematch triggered flag for
 * @return whether the rematch triggered flag is set for the given person index
 */
bool vs_seeker_person_get_rematch_triggered(u8 person_idx);

/**
 * Clears the rematch triggered flag for all persons, so that no rematches can be triggered until the flag is set again for certain persons.
 */
void vs_seeker_person_clear_rematch_triggered_for_all();

/*
 * Checks if there are new rematchable trainers visible and triggers their rematch movements.
    * @return whether there are new rematchable trainers visible
*/
bool vs_seeker_new_rematches_visible();


void vs_seeker_setup_trainer_party(u16 trainer_idx, trainer *trainer_dst, trainer_pokemon *party_dst);
#endif