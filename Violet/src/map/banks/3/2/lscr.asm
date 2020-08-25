


.include "overworld_script.s"
.include "ordinals.s"
.include "flags.s"
.include "levelscript_types.s"
.include "difficulties.s"
.include "vars.s"

.global lscr_0x718de8

lscr_0x718de8:
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word lscr_reset_gym_trainerflag
	.byte 0x0

lscr_reset_gym_trainerflag:
	setworldmapflag WM_AKTANIA
    checkflag FRBADGE_1
    gotoif EQUAL dont_reset_trainerflags
    compare DIFFICULTY DIFFICULTY_NORMAL
    gotoif LESS dont_reset_trainerflags 
    settrainerflag 0x12
    settrainerflag 0x19f
    settrainerflag 0x1a0
	dont_reset_trainerflags:
	end


