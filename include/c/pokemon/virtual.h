/*
 * virtual.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_VIRTUAL_H_
#define INCLUDE_C_POKEMON_VIRTUAL_H_

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
        u32 unused : 7;
        u32 nature : 5;
        u32 form : 3;
    } fields;
} pid_t;

#define STATUS_CONDITION_SLEEP 7


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
	u16 catch_game:4;
	u16 pokeball:4;
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


extern pokemon player_pokemon[];
extern u8 player_pokemon_cnt;
extern pokemon opponent_pokemon[];

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
 * @param set_catch_location_to_xFD if set, the catch location is set to 0xFD (whatever this means)
 */
void pokemon_new_egg(pokemon *dst, u16 species, bool set_catch_location_to_xFD);

/**
 * Tries to add the pokemon to the player's party. If this fails, it tries to add it to any box.
 * Also OT-Name, TID and OT-Gender attributes of the pokemon are set.
 * @param dst the pokemon to be added to the player's collection.
 * @return 0 if added to the party, 1 if added to the box, 2 if everything failed
 */
int pokemon_give(pokemon *dst);

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
 * Enables the hidden ability on a pokemon.
 * @param p the pokemon to enable its hidden ability on
 */
void pokemon_set_hidden_ability(pokemon *p);

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
 * Checks if a pokemon has its hidden ability.
 * @param p the pokemon to load the hidden ability from
 * @return if the pokemon has its hidden ability
 */
bool pokemon_has_hidden_ability(box_pokemon *p);
u8 pokemon_get_ability(pokemon *poke);
u8 battler_load_ability_as_defender(pokemon *poke);
void special_heal_team_index();
void pokemon_team_remove();
void pokemon_team_knows_hm();
bool pokemon_knows_hm(pokemon *p);

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

#endif /* INCLUDE_C_POKEMON_VIRTUAL_H_ */
