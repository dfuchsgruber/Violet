.include "overworld_script.s"
.include "specials.s"
.include "callstds.s"
.include "vars.s"
.include "mugshot.s"
.include "ordinals.s"
.include "flags.s"
.include "species.s"
.include "pathfinding.s"
.include "songs.s"

.global ow_script_tafelberg_clouds_gear_trigger_0

ow_script_tafelberg_clouds_gear_trigger_0:
    lockall
	setvar 0x8004 1
	special SPECIAL_CUTSCENE_SHOW
	waitstate
    pause 48
    msgbox_with_name str_0 str_question message_type=MSG_KEEPOPEN
    loadpointer 0 str_1
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL step_back
    msgbox_with_name str_2 str_question message_type=MSG_KEEPOPEN hide_name=0
    trainerbattlenointrotext 0x1ff 0 str_after
    setvar VAR_TAFELBERG_CLOUDS_GEAR_SCRIPT 1
    releaseall
    end

step_back:
    closeonkeypress
	setvar 0x8004 2
	special SPECIAL_CUTSCENE_SHOW
    applymovement 0xFF mov_1d
	waitstate
    waitmovement 0
    releaseall
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wer bist du?\pDieser Ort darf von niemandem betreten werden."
str_1:
    .autostring 34 2 "Zurücktreten?"
str_2:
    .autostring 34 2 "Meine Aufgabe ist es, dieses Siegel zu bewachen.\pDas dunkle Königreich darf niemals widerkehren.\pWer immer sich widersetzt, wird ausgelöscht."
str_after:
    .autostring 34 2 "Ich habe versagtDOTS"
str_question:
    .string "???"  
.elseif LANG_EN
.endif
