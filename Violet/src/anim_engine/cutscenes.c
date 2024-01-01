#include "types.h"
#include "anim_engine.h"

extern const u8 cutscene_script_elite_four_founders[];
extern const u8 cutscene_script_darkqueen_fade_to[];
extern const u8 cutscene_script_darkqueen_fade_from[];
extern const u8 cutscene_script_mistral_yin_yang[];
extern const u8 cutscene_script_future[];
extern const u8 cutscene_script_groudon_diserakt[];
extern const u8 cutscene_script_groudon[];
extern const u8 cutscene_script_groudon_fade[];
extern const u8 cutscene_script_groudon_red[];
extern const u8 cutscene_script_groudon_grey[];
extern const u8 cutscene_script_arc_scrim[];
extern const u8 cutscene_script_difficulty_setting[];
extern const u8 cutscene_script_difficulty_setting_fade_to_dark[];
extern const u8 cutscene_script_intro[];
extern const u8 cutscene_script_staraptor_to[];
extern const u8 cutscene_script_staraptor_from[];
extern const u8 cutscene_script_aktania_meteor[];
extern const u8 cutscene_script_aktania_beam[];
extern const u8 cutscene_script_aktania_sky[];
extern const u8 cutscene_script_ardeal_tower[];
extern const u8 cutscene_script_unown_shrine[];

const u8 *const cutscene_scripts[NUM_CUTSCENES] = {
    [CUTSCENE_ELITE_FOUR_FOUNDERS] = cutscene_script_elite_four_founders,
    [CUTSCENE_DARK_QUEEN_FADE_TO_DARK] = cutscene_script_darkqueen_fade_to,
    [CUTSCENE_DARK_QUEEN_FADE_FROM_DARK] = cutscene_script_darkqueen_fade_from,
    [CUTSCENE_MISTRAL_YING_YANG] = cutscene_script_mistral_yin_yang,
    [CUTSCENE_FUTURE_LANDSCAPE] = cutscene_script_future,
    [CUTSCENE_GROUDON_TESERAKT] = cutscene_script_groudon_diserakt,
    [CUTSCENE_GROUDON] = cutscene_script_groudon,
    [CUTSCENE_GROUDON_FADE_TO_DARK] = cutscene_script_groudon_fade,
    [CUTSCENE_GROUDON_FADE_TO_RED] = cutscene_script_groudon_red,
    [CUTSCENE_GROUDON_FADE_TO_GREY] = cutscene_script_groudon_grey,
    [CUTSCENE_ARC_SCRIM] = cutscene_script_arc_scrim,
    [CUTSCENE_DIFFICULTY_SETTING] = cutscene_script_difficulty_setting,
    [CUTSCENE_DIFFICULTY_SETTING_FADE_TO_DARK] = cutscene_script_difficulty_setting_fade_to_dark,
    [CUTSCENE_PROLOUGE] = cutscene_script_intro,
    [CUTSCENE_STARAPTOR_FLY_TO] = cutscene_script_staraptor_to,
    [CUTSCENE_STARAPTOR_FLY_FROM] = cutscene_script_staraptor_from,
    [CUTSCENE_AKTANIA_METEORITE] = cutscene_script_aktania_meteor,
    [CUTSCENE_AKTANIA_BEAM] = cutscene_script_aktania_beam,
    [CUTSCENE_AKTANIA_SKY] = cutscene_script_aktania_sky,
    [CUTSCENE_ARDEAL_TOWER] = cutscene_script_ardeal_tower,
    [CUTSCENE_UNOWN_SHRINE] = cutscene_script_unown_shrine,
};