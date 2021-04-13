.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"
.include "songs.s"

.global ow_script_meriana_city_gym_gong


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
