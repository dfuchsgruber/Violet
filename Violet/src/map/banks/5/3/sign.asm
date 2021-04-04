.include "overworld_script.s"
.include "callstds.s"
.include "specials.s"

.global ow_script_meriana_city_gym_gong


ow_script_meriana_city_gym_gong:
    lockall
    callasm bluetenbach_gym_rotate_walls
    special SPECIAL_MAP_UPDATE_BLOCKS
    releaseall
    end
