#include "achievements.h"
#include "language.h"
#include "constants/flags.h"
#include "constants/sav_keys.h"
#include "save.h"

extern const u8 ow_script_achievement_breeding_1_reward[];
extern const u8 ow_script_achievement_breeding_3_reward[];
extern const u8 ow_script_achievement_breeding_10_reward[];
extern const u8 ow_script_achievement_breeding_20_reward[];
extern const u8 ow_script_achievement_breeding_50_reward[];

u16 breeding_get_progress() { return (u16)save_get_key(SAV_KEY_EGGS_HATCHED); }
bool breeding_hatch_1_is_achieved(void) { return save_get_key(SAV_KEY_EGGS_HATCHED) >= 1 && checkflag(POKEDEX); }
bool breeding_hatch_3_is_achieved(void) { return save_get_key(SAV_KEY_EGGS_HATCHED) >= 3 && checkflag(POKEDEX); }
bool breeding_hatch_10_is_achieved(void) { return save_get_key(SAV_KEY_EGGS_HATCHED) >= 10 && checkflag(POKEDEX); }
bool breeding_hatch_20_is_achieved(void) { return save_get_key(SAV_KEY_EGGS_HATCHED) >= 20 && checkflag(POKEDEX); }
bool breeding_hatch_50_is_achieved(void) { return save_get_key(SAV_KEY_EGGS_HATCHED) >= 50 && checkflag(POKEDEX); }

const achievement_t achievements_breeding[NUM_BREEDING_ACHIEVEMENTS] = {
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Brüte ein Ei aus!"), 
            PSTRING("Hatch an egg!")
        ),
        .is_achieved = breeding_hatch_1_is_achieved,
        .max_progress = 1,
        .get_progress = breeding_get_progress,
        .flag_achieved = FLAG_BREEDING_ACHIVEMENT_HATCH_1_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_INCUBATOR,
            .script = ow_script_achievement_breeding_1_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Inkubator-App\nauf dem Poképad."), 
                PSTRING("Incubator app\non the Poképad.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Brüte 3 Eier aus!"), 
            PSTRING("Hatch 3 eggs!")
        ),
        .is_achieved = breeding_hatch_3_is_achieved,
        .max_progress = 3,
        .get_progress = breeding_get_progress,
        .flag_achieved = FLAG_BREEDING_ACHIVEMENT_HATCH_3_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_INCUBATOR_ADDITIONAL_SLOT_1,
            .script = ow_script_achievement_breeding_3_reward, // No script reward for this achievement
            .description = (const u8[]) LANGDEP(
                PSTRING("Extra Platz\nfür Eier in\nInkubator App."), 
                PSTRING("Additional slot\nfor eggs in\nthe incubator\napp.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Brüte 10 Eier aus!"), 
            PSTRING("Hatch 10 eggs!")
        ),
        .is_achieved = breeding_hatch_10_is_achieved,
        .max_progress = 10,
        .get_progress = breeding_get_progress,
        .flag_achieved = FLAG_BREEDING_ACHIVEMENT_HATCH_10_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_SILVER,
        .reward = {
            .flag = FLAG_EGGS_HATCH_FASTER,
            .script = ow_script_achievement_breeding_10_reward, // No script reward for this achievement
            .description = (const u8[]) LANGDEP(
                PSTRING("Eier schlüfen\nschneller."), 
                PSTRING("Eggs hatch\nfaster.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Brüte 20 Eier aus!"), 
            PSTRING("Hatch 20 eggs!")
        ),
        .is_achieved = breeding_hatch_20_is_achieved,
        .max_progress = 20,
        .get_progress = breeding_get_progress,
        .flag_achieved = FLAG_BREEDING_ACHIVEMENT_HATCH_20_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = FLAG_INCUBATOR_ADDITIONAL_SLOT_2,
            .script = ow_script_achievement_breeding_20_reward, // No script reward for this achievement
            .description = (const u8[]) LANGDEP(
                PSTRING("Extra Platz\nfür Eier in\nInkubator App."), 
                PSTRING("Additional slot\nfor eggs in\nthe incubator\napp.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Brüte 50 Eier aus!"), 
            PSTRING("Hatch 50 eggs!")
        ),
        .is_achieved = breeding_hatch_50_is_achieved,
        .max_progress = 50,
        .get_progress = breeding_get_progress,
        .flag_achieved = FLAG_BREEDING_ACHIVEMENT_HATCH_50_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_PLATINUM,
        .reward = {
            .flag = FLAG_EGGS_IMPROVED_FEATURE_GENERATOR,
            .script = ow_script_achievement_breeding_50_reward, // No script reward for this achievement
            .description = (const u8[]) LANGDEP(
                PSTRING("Geschlüpfte\nPokémon sind\nstärker."), 
                PSTRING("Hatched\nPokémon are\nstronger.")
            ),
        }
    }
};