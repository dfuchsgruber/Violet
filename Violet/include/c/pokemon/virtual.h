/*
 * virtual.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_VIRTUAL_H_
#define INCLUDE_C_POKEMON_VIRTUAL_H_

#include "types.h"
#include "constants/pokemon_attributes.h"
#include "constants/species.h"

typedef struct marking {
    u8 circle : 1;
    u8 square : 1;
    u8 triangle : 1;
    u8 heart : 1;
    u8 padding : 4;
} marking;

typedef union {
    u32 value;

    struct {
        u32 ability : 1;
        u32 gender_partial : 7;
        u32 is_shiny : 1;
        u32 hidden_power_type : 5;
        u32 hidden_power_strength : 3;
		u32 unown_letter : 5;
        u32 unused : 2;
        u32 nature : 5;
        u32 form : 3;
    } fields;
} pid_t;

#define STATUS_CONDITION_NONE 0
#define STATUS_CONDITION_SLEEP 7
#define STATUS_CONDITION_POISON 8
#define STATUS_CONDITION_BURN 16
#define STATUS_CONDITION_FREEZE 32
#define STATUS_CONDITION_PARALYSIS 64
#define STATUS_CONDITION_BAD_POISON 128
#define STATUS_CONDITION_BAD_POISON_COUNTER 0xF00
#define STATUS_CONDITION_POISON_ANY (STATUS_CONDITION_POISON | STATUS_CONDITION_BAD_POISON)
#define STATUS_CONDITION_ANY (STATUS_CONDITION_SLEEP | STATUS_CONDITION_POISON | STATUS_CONDITION_BURN | STATUS_CONDITION_FREEZE | STATUS_CONDITION_PARALYSIS | STATUS_CONDITION_BAD_POISON)

#define POKEMON_IS_VIABLE(p) ((\
	pokemon_get_attribute(p, ATTRIBUTE_CURRENT_HP, 0) != 0 && \
	pokemon_get_attribute(p, ATTRIBUTE_SPECIES2, 0) != 0 && \
	pokemon_get_attribute(p, ATTRIBUTE_SPECIES2, 0) != POKEMON_EGG && \
	!pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, 0)) \
)

typedef struct {
	u16 species;
	u16 item;
	u32 exp;
	u8 pp_up;
	u8 friendship;
} pokemon_substructure_section_A;

typedef struct {
	u16 moves[4];
	u8 pp[4];
} pokemon_substructure_section_B;

typedef struct {
	u8 evs[6];
	u8 contest_stats[6];
} pokemon_substructure_section_C;

typedef struct {
	u8 pokerus;
	u8 catch_location;

	u16 catch_level:7;
	u16 catch_game:3;
	u16 pokeball:5;
	u16 ot_gender:1;

	u32 hp_iv:5;
	u32 attack_iv:5;
	u32 defense_iv:5;
	u32 speed_iv:5;
	u32 special_attack_iv:5;
	u32 special_defense_iv:5;
	u32 is_egg:1;
	u32 ability:1;

	u32 coolness_ribbons:3;
	u32 beatuy_ribbons:3;
	u32 cuteness_ribbons:3;
	u32 smartness_ribbons:3;
	u32 toughness_ribbons:3;
	u32 champion_ribbon:1;
	u32 winning_ribbon:1;
	u32 victory_ribbon:1;
	u32 artist_ribbon:1;
	u32 effort_ribbon:1;
	u32 gift_ribbon_1:1;
	u32 gift_ribbon_2:1;
	u32 gift_ribbon_3:1;
	u32 gift_ribbon_4:1;
	u32 gift_ribbon_5:1;
	u32 gift_ribbon_6:1;
	u32 gift_ribbon_7:1;
	u32 fateful_encounter:4;
	u32 obedient:1;
} pokemon_substructure_section_D;

#define CATCH_LOCATION_FATEFUL_ENCOUNTER 255
#define CATCH_LOCATION_OVERWORLD_EGG 252
#define CATCH_LOCATION_SPECIAL_EGG 253
#define CATCH_LOCATION_INGAME_TRADE 254

typedef union {
	pokemon_substructure_section_A section_A;
	pokemon_substructure_section_B section_B;
	pokemon_substructure_section_C section_C;
	pokemon_substructure_section_D section_D;
	u16 values[6];
} pokemon_substructure_section;

typedef struct {
	pid_t pid;
	u32 tid;
	u8 nickname[10];
	u8 language;
	u8 is_bad_egg : 1;
	u8 has_species : 1;
	u8 is_egg : 1;
	u8 unused : 5;
	u8 ot_name[7];
	marking markings;
	u16 checksum;
	u16 padding;
	pokemon_substructure_section encrypted_substructure[4];
} box_pokemon;

typedef struct pokemon {
    box_pokemon box;
    u32 status_condition;
    u8 level;
    u8 pokerus_remaining_byte;
    u16 current_hp;
    u16 total_hp;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 special_attack;
    u16 special_defense;
} pokemon;

extern u8 player_party_selected_idxs[3]; // Idxs selected by special 0x29

extern pokemon player_pokemon[];
extern u8 player_pokemon_cnt;
extern pokemon opponent_pokemon[];

/** 
 * Transfers the entire player party to the save block.
 **/
void player_save_party();

/**
 * Loads the entire player party from the save block.
 **/
void player_restore_party();

/**
 * Reduces the player party to the (up to) three selected pokemon in the selected order.
 **/
void player_party_reduce_to_selection();

/**
 * Compactifies the player party, i.e. fills empty slots upwards. One should also update the
 * pokemon count after removing a pokemon using player_party_recount_pokemon.
 * @returns the first slot thats was previosly emptied but due to compactifing was filled with a
 * succeeding party pokemon, or -1 instead.
 */
s16 player_pokemon_compact();

/**
 * Updates player_pokemon_cnt by counting pokemon with a non zero species.
 * @return the number of pokemon in the player party
 */
u8 player_pokemon_recount_pokemon();

/**
 * @brief Gets the hp, attack, defense, speed, sp. attack and sp. defense of a pokemon
 * 
 * @param p pokemon the pokemon to get
 * @param dst where to put the stats
 */
void pokemon_get_stats(pokemon *p, u16 *dst);

/**
 * Gets the attribute of a virtual pokemon
 * @param p The offset of the virtual pokemon
 * @param requested_attribute Id of the attribute to get
 * @param result Storage for the result if it is no scalar type (pass 0 otherwise)
 */
int pokemon_get_attribute(pokemon* p, int requested_attribute, void *result);

/**
 * Gets the attribute of a virtual pokemon's substructre
 * @param p The offset of the virtual pokemon
 * @param requested_attribute idx of the attribute to get
 * @param result Storage for the result if it is no scalar type (pass 0 otherwise)
 */
int box_pokemon_get_attribute(box_pokemon *p, int requested_attribute, void *result);

/**
 * Sets the attribute of a virtual pokemon
 * @param p The offset of the virutal pokemon
 * @param requested_attribute Id of the attribute to set
 * @param value Pointer to the value to apply
 */
void pokemon_set_attribute(pokemon* p, int requested_attribute, void* value);

/**
 * Sets the attribute of a virtual pokemon's substructure
 * @param p The offset of the virutal pokemon
 * @param requested_attribute idx of the attribute to set
 * @param value Pointer to the value to apply
 */
void box_pokemon_set_attribute(box_pokemon* p, int requested_attribute, void* value);

/**
 * Calculates the stats of a pokemon.
 * @param p Pokemon to calculate the stats of
 */
void pokemon_calculate_stats(pokemon *p);

/**
 * Returns a pokemon that is placed on the boxes. Note that this pokemon is in compressed format,
 * i.e. it only contains of substructure and thus substructure getters and setters have to be used.
 * @param box_idx the index of the box of the pokemon
 * @param idx the index of the pokemon inside the given box
 * @return the pokemon instance (substructure only)
 */
box_pokemon *pokemon_get_by_box(int box_idx, int idx);

/**
 * Gets the number of pokemon in the player's party
 * @return The number of pokemon in the player's party
 */
u8 pokemon_get_number_in_party();

void pokemon_load_name_as_string(pokemon *pokemon, u8 *buffer);

#define POKEMON_NEW_RANDOM_IVS 32

/**
 * Creates a new pokemon
 * @param space where to create the pokemon
 * @param species the species to create
 * @param level the level of the pokemon to create
 * @param fixed_ivs if < 32 all ivs are set to this value, otherwise random ivs
 * @param pid_determined if true, the pokemon will gain a fixed pid
 * @param pid if pid_determined true the pid the pokemon will gain
 * @param tid_determined if true, the pokemon will gain a fixed tid
 * @param tid if tid_determined true the tid the pokemon will gain
 */
void pokemon_new(pokemon *space, u16 species, u8 level, u8 fixed_ivs,
        bool pid_determined, pid_t pid, bool tid_determined, u32 tid);

/**
 * Creates a new pokemon egg data (without actually setting the is_egg attribute).
 * @param dst target adress to create the pokemon at
 * @param species species to create an egg of
 * @param set_special_catch_location if set, the catch location is set to CATCH_LOCATION_SPECIAL_EGG
 */
void pokemon_new_egg(pokemon *dst, u16 species, bool set_special_catch_location);

/**
 * Tries to add the pokemon to the player's party. If this fails, it tries to add it to any box.
 * Also OT-Name, TID and OT-Gender attributes of the pokemon are set.
 * @param dst the pokemon to be added to the player's collection.
 * @return 0 if added to the party, 1 if added to the box, 2 if everything failed
 */
u8 pokemon_give(pokemon *dst);

/**
 * Tries to add the pokemon to the player's party. If this fails, it tries to add it to any box.
 * Also OT-Name, TID and OT-Gender attributes of the pokemon are kept and not set to the player's.
 * @param dst the pokemon to be added to the player's collection.
 * @return 0 if added to the party, 1 if added to the box, 2 if everything failed
 */
int pokemon_give_with_player_not_ot(pokemon *p);

/**
 * Tries to put a pokemon on the box system.
 * @param dst the pokemon to put.
 * @return 1 on success, 2 on failure
 */
int pokemon_to_box(pokemon *dst);

/**
 * Checks if there is room in any box
 * @return if there is room in any box
 **/
bool box_has_empty_slot();

/**
 * Gets the name of a box
 * @param box_idx the index of the box to get the name of
 * @return the name of the box
 */
u8 *box_get_name(u8 box_idx);

/**
 * Enables the hidden ability on a pokemon.
 * @param p the pokemon to enable its hidden ability on
 */
void pokemon_set_hidden_ability(box_pokemon *p);


u16 pokemon_append_attack(pokemon *p, u16 attack);
void pokemon_rotate_and_push_attack(pokemon *p, u16 attack);
/**
 * Creates a new pokemon using the "seed algorithm". Features are added to the given pokemon
 * with some probability, where values are drawn from a generator and expected to be
 * uniformly distributed in [0; 512). Lower values mean that features will be appended, so
 * the chance of getting "features" is increased when the rnd_generator provides numbers that
 * range only from [0; x) with x < 512.
 * @param p the pokemon to instanciate
 * @param species desired species
 * @param level desired level
 * @param ev_spread desired ev spread
 * @param pid_determined if the pid is already determined and given (shinyness might be changed)
 * @param pid the pid to apply if pid_determined is set to true
 * @param tid_determined if the tid is already determined and given
 * @param tid the tid to apply if tid_determined is set to true
 * @param feature_generator function that provides values in [0; x) with x < 512 to
 * instaciate features (lower values mean more features)
 * @param rng arbitrary rng to determine the pokemon entirely. If null the standard rng
 * is used.
 */
void pokemon_spawn_by_seed_algorithm(pokemon *p, u16 species, u8 level, u8 ev_spread,
    bool pid_determined, pid_t pid, bool tid_determined, u32 tid, u16(*feature_generator)(),
	u16(*rng)());

/**
 * Generates tid based on a ot_name.
 * @param ot_name the original trainer name
 * @return the tid as product of all characters
 */
u32 tid_by_ot_name(u8 *ot_name);

/**
 * Creates a new pokemon and sets its ivs.
 * @param dst where to create the new pokemon
 * @param species the species of the pokemon to create
 * @param level the level of the pokemon to create
 * @param ivs the ivs of the pokemon to create
 * @param pid the pid of the pokemon to create
 **/
void pokemon_new_and_set_ivs(pokemon *dst, u16 species, u8 level, u32 ivs, pid_t pid);

/**
 * Checks if a pokemon has its hidden ability.
 * @param p the pokemon to load the hidden ability from
 * @return if the pokemon has its hidden ability
 */
bool pokemon_has_hidden_ability(box_pokemon *p);
u8 pokemon_get_ability(pokemon *poke);
u8 battler_load_ability_as_defender(pokemon *poke);
/**
 * Special that heals the players party pokemon located at index stored in variable 0x8004
 */
void special_player_party_heal_index();
void pokemon_team_remove();
void pokemon_team_knows_hm();
bool pokemon_knows_hm(box_pokemon *p);

/**
 * Heals all pokemon in the player's party
 */
void pokemon_heal_player_party();

#define GENDER_MALE 0
#define GENDER_FEMALE 254
#define GENDER_NONE 255
/**
 *
 * @param p the pokemon to get the gender of
 * @return 0 := male, 0xFE := female i guess? 0xFF := no gender at all
 */
u8 pokemon_get_gender(box_pokemon *p);

u8 pokemon_get_nature(pokemon *target);

/**
 * Clears a pokemon entry
 */
void pokemon_clear(pokemon *p);

/**
 * Clears the entire party of the opponent
 */
void pokemon_clear_opponent_party();

/**
 * Creates a valid pid for a pokemon.
 * @return the pid
 */
pid_t pokemon_new_pid();

/**
 * Creates a valid pid for a pokemon using a certain prng.
 * @param rnd prng function that yields random 16-bit values
 * @return the pid
 */
pid_t pokemon_new_pid_by_prng(u16 (*rnd)());

/**
 * Sets the effective evs of a pokemon (in multiples of 4).
 * @param p the pokemon
 * @param stat the stat index to set the ev of
 * @param ev the ev value in multiples of 4
 */
void pokemon_set_effective_ev(pokemon *p, int stat, u8 ev);

/**
 * Returns the effective ev of a pokemon.
 * @param p the pokemon
 * @param stat the stat index to get the ev of
 * @return the ev value in multiples of 4
 */
u8 pokemon_get_effective_ev(pokemon *p, int stat);

/**
 * Sets the potential ev of a pokemon.
 * @param p the pokemon
 * @param stat the stat index to get the ev of
 * @ev the potential ev value
 */
void pokemon_set_potential_ev(pokemon *p, int stat, u8 ev);

/**
 * Returns the potential ev of a pokemon.
 * @param p the pokemon
 * @param stat the stat index to set the ev of
 * @return ev the potential ev value
 */
u8 pokemon_get_potential_ev(pokemon *p, int stat);

/**
 * Calculates how many pp a move has in total given its pp up values.
 * @param attack the move to check the total pp of
 * @param pp_ups the bitfield indicating the pp ups used
 * @param index the index of the move on the pokemon
 * @returns the maximal pp of the move
 **/
u8 attack_get_pp(u16 attack, u8 pp_ups, u8 index);

// Masks for isolating the pp ups of a certain move
extern u8 pokemon_pp_up_set_masks[4];
extern u8 pokemon_pp_up_clear_masks[4];
extern u8 pokemon_pp_up_add_masks[4];

/**
 * Restores hp, pp and status of a pokemon.
 * @param dst the pokemon to heal
 **/
void pokemon_heal(pokemon *dst);

/**
 * Checks if a pokémon is at its full health (hp, pp, status)
 * @return if a pokémon has max hp, pp and no primary status condition
 **/
bool pokemon_is_healed(pokemon *dst);

/**
 * Checks if a party pokemon has a certain status condition.
 * @param p the pokemon to check
 * @param party_idx which index the pokemon has in the party
 * @param status_mask the conditions to check for
 * @return if the pokemon has the status condition
 **/ 
bool pokemon_has_status_condition(pokemon *p, int party_idx, u32 status_mask);

/**
 * Checks if a party pokemon has a certain status condition and if so, removes it.
 * @param p the pokemon to check
 * @param party_idx which index the pokemon has in the party
 * @param status_mask the conditions to check for
 * @param battler_idx the idx of the battler associated with the pokemon. If no battler is associated, pass the value 4.
 * @return if the pokemon has the status condition
 **/ 
bool pokemon_remove_status_condition(pokemon *p, int party_idx, u32 status_mask, u8 battler_idx);

/**
 * Returns the letter index of a pokemon's pid.
 * @param p the pid of the pokemon
 * @return which kind of letter the pid resembles
 **/
int pokemon_unown_get_letter(pid_t p);

/**
 * Generates a pid that resembles a unown letter.
 * @param letter the letter (< 28) to generate.
 * @return a random pid with that letter.
 **/
pid_t pokemon_unown_generate_letter_pid(u32 letter);

/**
 * Clears a pokemon on the box.
 * @param the box of the pokemon to clear
 * @param slot the slot in the box to clear
 **/
void box_pokemon_clear_by_box_idx_and_slot(u8 box_idx, u8 slot);

/**
 * Copies the data of a pokemon on the box.
 * @param box_idx the box of the pokemon to copy
 * @param slot the slot in the box
 * @param dst where to put the data
 **/
void box_pokemon_copy(u8 box_idx, u8 slot, box_pokemon *dst);

/**
 * Check if the player party and all boxes are full
 * @return if the player party and all boxes are full
 **/
bool player_party_and_boxes_full();

/**
 * Adds the level of the first num pokemon's level in the player party.
 * @param num how many viable pokemon to consider
 * @return the sum of their level
 **/
u16 player_pokemon_get_total_level(u8 num);

/**
 * Copies the nickname of a pokemon (basically strcpy for 10 bytes)
 * @param dst where to put the nickname
 * @param src from where to read the nickname
 * @return offset of the last char that was copied
 **/
u8 *pokemon_copy_nickname(u8 *dst, const u8 *src);

/**
 * Clears the pp up bonuses in a certain slot
 * @param p which pokemon to clear the pp ups of
 * @param slot in which slot to clear the pp ups
 **/
void pokemon_clear_pp_ups(pokemon *p, u8 slot);

/**
 * Sets the move of a pokemon
 * @param p which pokemon to set a move of
 * @param move which move to set
 * @param slot in which slot to set the move
 */
void pokemon_set_move(pokemon *p, u16 move, u8 slot);

/**
 * Adds friendship to a pokemon
 * @param p which pokemon to add friendship to
 * @param value how much friendship to add
 **/
void pokemon_add_friendship(pokemon *p, s8 value);

#define POKERUS_GET_SINGLE_POKEMON 0

/**
 * Gets the pokerus state of a pokemon / party
 * @param p the pokemon / party to get the pokerus state of
 * @param mask mask for all party idxs requested for the pokerus check, if POKERUS_GET_SINGLE_POKEMON is passed, a simple bool value for p is returned
 * @return pokerus_state the requested pokerus state
 **/
u8 pokemon_get_pokerus(pokemon *p, u8 mask);

#endif /* INCLUDE_C_POKEMON_VIRTUAL_H_ */
