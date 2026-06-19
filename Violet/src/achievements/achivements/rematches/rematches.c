#include "achievements.h"
#include "language.h"
#include "constants/flags.h"
#include "vars.h"

extern const u8 ow_script_achievement_rematches_10_reward[];
extern const u8 ow_script_achievement_rematches_50_reward[];
extern const u8 ow_script_achievement_rematches_100_reward[];

u16 achievement_rematches_get_progress() { return *var_access(VAR_TRAINERBATTLE_REMATCHES_FOUGHT); }

bool rematches_10_is_achieved(void) { return achievement_rematches_get_progress() >= 10; }
bool rematches_50_is_achieved(void) { return achievement_rematches_get_progress() >= 50; }
bool rematches_100_is_achieved(void) { return achievement_rematches_get_progress() >= 100; }

const achievement_t achievements_rematches[NUM_REMATCHES_ACHIEVEMENTS] = {
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Bestreite 10 Rückkämpfe mit der Kampffahnder-App."), 
            PSTRING("Complete 10 trainer rematches with the VS Seeker app!")
        ),
        .is_achieved = rematches_10_is_achieved,
        .max_progress = 10,
        .get_progress = achievement_rematches_get_progress,
        .flag_achieved = FLAG_REMATCHES_ACHIEVEMENT_10_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_REMATCHES_ACHIEVEMENT_10_REWARD,
            .script = ow_script_achievement_rematches_10_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Trainer sind\nhäufiger\nbereit für\nRückkampf."), 
                PSTRING("Trainers are\nmore likely to\nwant a\nrematch.")
            ),
        },
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Bestreite 50 Rückkämpfe mit der Kampffahnder-App."), 
            PSTRING("Complete 50 trainer rematches with the VS Seeker app!")
        ),
        .is_achieved = rematches_50_is_achieved,
        .max_progress = 50,
        .get_progress = achievement_rematches_get_progress,
        .flag_achieved = FLAG_REMATCHES_ACHIEVEMENT_50_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_SILVER,
        .reward = {
            .flag = FLAG_REMATCHES_ACHIEVEMENT_50_REWARD,
            .script = ow_script_achievement_rematches_50_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Trainer zeigen\nBereitschaft\nfür Rückkampf\nautomatisch."), 
                PSTRING("Trainers automatically\nshow willingness\nfor rematches.")
            ),
        },
     },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Bestreite 100 Rückkämpfe mit der Kampffahnder-App."), 
            PSTRING("Complete 100 trainer rematches with the VS Seeker app!")
        ),
        .is_achieved = rematches_100_is_achieved,
        .max_progress = 100,
        .get_progress = achievement_rematches_get_progress,
        .flag_achieved = FLAG_REMATCHES_ACHIEVEMENT_100_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = FLAG_REMATCHES_ACHIEVEMENT_100_REWARD,
            .script = ow_script_achievement_rematches_100_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Rückkämpfe\ngeben mehr\nEP und Fleiß-\nPunkte."), 
                PSTRING("Rematches\ngive more\nExp. and Effort\nValues.")
            ),
        },
    },
    
};
    