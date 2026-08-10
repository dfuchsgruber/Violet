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

.global ow_script_kranzerbg_clouds_gear_trigger_0

ow_script_kranzerbg_clouds_gear_trigger_0:
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
    trainerbattlenointrotext 0x213 0 str_after
    setvar VAR_KRANZERBG_CLOUDS_GEAR_SCRIPT 1
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
    .autostring 34 2 "Fremder!\nVerlasse diesen Ort augenblicklich!"
str_1:
    .autostring 34 2 "Zurücktreten?"
str_2:
    .autostring 34 2 "Ich habe dieses Siegel zu beschützen bis ans Ende aller Zeiten.\pWenn das dunkle Königreich je zurückkehren sollte, wird die Welt erneut untergehen.\pWidersetzt du dich dem, wirst du vernichtet."
str_after:
    .autostring 34 2 "Das Siegel ist gebrochenDOTS"
str_question:
    .string "???"  
.elseif LANG_EN
.endif
