.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"
.include "songs.s"

.global ow_script_meriana_city_gym_gong
.global ow_script_meriana_city_gym_statue

ow_script_meriana_city_gym_gong:
    lockall
    fanfare FANFARE_GONG
    special SPECIAL_OVERWORLD_EFFECT_SOUND_WAVE
    pause 12
    special SPECIAL_OVERWORLD_EFFECT_SOUND_WAVE
    pause 24
    callasm bluetenbach_gym_rotate_walls
	special SPECIAL_MAP_UPDATE_BLOCKS
    waitfanfare
    releaseall
    end

ow_script_meriana_city_gym_statue:
    loadpointer 0 str_statue
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_statue:
    .autostring 34 2 "Lotusarena.\nArenaleiter: Manuel.\pEs sind die Namen Larissa und Mara eingeritzt.\pRIVAL hat seinen Namen in Großbuchstaben darüber geschrieben."
.elseif LANG_EN
str_statue:
    .autostring 34 2 "Lotus Gym.\nGym Leader: Manuel.\pThe names Larissa and Mara are engraved.\pRIVAL wrote his name in big capitalized letters over it."
.endif
