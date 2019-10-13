.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "battle_results.s"
.include "specials.s"
.include "flags.s"

.global map_3_8_route_3_levelscripts

map_3_8_route_3_levelscripts:
	.byte 0x3
	.word ow_script_move_drampa
	.byte 0x5
	.word ow_script_hide_drampa
	.byte 0x0

ow_script_move_drampa:
compare SEN_LONG_TRIGGER 1
callif EQUAL move_drampa
end

move_drampa:
movesprite2 0x1 0x15 0x6
// If Drampa was fled or teleported, it reappears on the next map entering
checkflag SEN_LONG_CAUGHT
gotoif EQUAL dramp_not_reappearing
clearflag (SEN_LONG_VISIBLE | 0x8000)
dramp_not_reappearing:
return

ow_script_hide_drampa:
checkflag FLAG_IN_BATTLE
callif 1 hide_drampa_overworld
end

hide_drampa_overworld:
special2 LASTRESULT SPECIAL_GET_BATTLE_RESULT
compare LASTRESULT BATTLE_RESULT_CAUGHT
gotoif NOT_EQUAL no_hiding
hidesprite LASTTALKED
no_hiding:
return


