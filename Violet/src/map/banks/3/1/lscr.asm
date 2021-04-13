.include "overworld_script.s"
.include "ordinals.s"
.include "flags.s"
.include "levelscript_types.s"
.include "difficulties.s"
.include "vars.s"


.global map_meriana_city_levelscripts

map_meriana_city_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word worldmapflag_script
	.byte 0x0

worldmapflag_script:
	setworldmapflag WM_MERIANA_CITY
	checkflag FRBADGE_3
    gotoif EQUAL dont_reset_trainerflags
	setvar VAR_BLUETENBACH_GYM_ROTATION 0 // Resets the puzzle
    compare DIFFICULTY DIFFICULTY_NORMAL
    gotoif LESS dont_reset_trainerflags 
    settrainerflag 0x80
    settrainerflag 0x81
    settrainerflag 0x82
    settrainerflag 0x83
    settrainerflag 0x1cd
    settrainerflag 0x1ce
    settrainerflag 0x1cf
    settrainerflag 0x1d0
	dont_reset_trainerflags:
	end

solve_gym_puzzle:
	setvar VAR_BLUETENBACH_GYM_ROTATION 2 // This "solves" the puzzle
	goto dont_reset_trainerflags