#ifndef H_ABILITIES
#define H_ABILITIES

#include "types.h"
#include "constants/ability_contexts.h"
#include "constants/abilities.h"

/**
 * Changes the species of a battler (used for change stance)
 * @param target the battler to target
 * @param species the species to change the battler into
 */
void stance_change_change_species(u8 target, u16 species);

/**
 * Gets the ability of a species
 * @param species the species to retrieve the ability from
 * @param fields merged ability bit and hidden ability bit
 * @return the ability of the species
 */
u8 ability_get(u16 species, u8 fields);

/**
 * Executes the abilities for a certain battle state
 * @param state the battle state
 * @param attacker attacking battler
 * @param ability the ability to count / check for
 * @param defender_ability the ability of the defending battler
 * @param active_attack the currently used attack
 * @return whether an ability was triggered in the current state
 */
u8 ability_execute(u8 state, u8 attacker, u8 attacker_ability, u8
    defender_ability, u16 active_attack);

/**
 * Executes battle abilities before an attack.
 * @return if any ability, i.e. battlescript, was triggered
 **/
bool battle_abilities_before_attack();

/**
 * Executes battle abilities after an attack triggered by the attacker, new abilities.
 * @param if any ability, i.e. battlescript, was triggered.
 **/
bool battle_abilities_attack_done_attacker_new();

/**
 * Executes battle abilities after an attack triggered by the defender, new abilities.
 * @param if any ability, i.e. battlescript, was triggered.
 **/
bool battle_abilities_attack_done_defender_new();

#define ABILITY_ON_TARGET_SIDE(battler_idx, ability)(ability_execute(ABILITY_CONTEXT_CHECK_TARGET_SIDE, battler_idx, ability, 0, 0))
#define ABILITY_PRESENT(ability)(ability_execute(ABILITY_CONTEXT_CHECK_PRESENT, 0, ability, 0, 0))
#define ABILITY_PRESENT2(ability)(ability_execute(ABILITY_CONTEXT_FIELD_SPORT, 0, ability, 0, 0))

extern const u8 ability_names[NUM_ABILITIES][13];
extern const u8 *ability_descriptions[NUM_ABILITIES];

#endif
