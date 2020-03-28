.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "movements.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "vars.s"
.include "levelscript_types.s"
.include "difficulties.s"
.include "ordinals.s"

.global str_aktania_gym_referee
.global levelscripts_aktania_gym

levelscripts_aktania_gym:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
.word lscr_referee
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word lscr_reset_trainerflags
	.byte 0

lscr_referee:
	.hword VAR_GYM_TIPPS, 0x0
	.word referee
	.hword 0x0

referee:
    lockall
    applymovement 3 mov_1lfd
    waitmovement 0
    loadpointer 0 str_aktania_gym_referee
    callstd MSG
    applymovement 3 mov_1rfd
    waitmovement 0
    addvar VAR_GYM_TIPPS 1
    releaseall
    end

mov_1lfd:
    .byte STEP_LEFT, LOOK_DOWN, STOP
mov_1rfd:
    .byte STEP_RIGHT, LOOK_DOWN, STOP

lscr_reset_trainerflags:
    checkflag FRBADGE_1
    gotoif EQUAL dont_reset_trainerflags
    compare DIFFICULTY DIFFICULTY_NORMAL
    gotoif LESS dont_reset_trainerflags 
    settrainerflag 0x12
dont_reset_trainerflags:
    end

.ifdef LANG_GER
str_aktania_gym_referee:
    .autostring 34 2 "Hey! Du siehst aus, als wärst du noch nicht lange ein Trainer.\pDeswegen will ich dir ein paar Ratschläge erteilen, damit du auf das, was dich hier erwartet, vorbereitet bist.\pIn dieser Arena wird mit Gestein-Pokémon gekämpft.\pDie können ordentlich einstecken, sind aber gegen einige Typen sehr anfällig.\pDeswegen hat der Arenaleiter Manus Maßnahmen ergriffen, sich gegen effektive Angriffe zu wappnen!\pViel Glück!"
.elseif LANG_EN
.endif