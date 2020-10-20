.include "overworld_script.s"
.include "callstds.s"
.include "movements.s"
.include "vars.s"

.global ow_script_forest_cemetery_teahs_house_person_0

ow_script_forest_cemetery_teahs_house_person_0:
    lock
    loadpointer 0 str_0
    callstd MSG
    applymovement LASTTALKED mov_ghost
    waitmovement 0
    loadpointer 0 str_1
    callstd MSG
    applymovement LASTTALKED mov_away
    waitmovement 0
    hidesprite LASTTALKED
    end

mov_ghost:
    .byte HIDE_SPRITE, PAUSE_4, SHOW_SPRITE, PAUSE_4, HIDE_SPRITE, PAUSE_4, SHOW_SPRITE, PAUSE_4, HIDE_SPRITE, PAUSE_4, SHOW_SPRITE, PAUSE_4, PAUSE_16, PAUSE_16, PAUSE_16, STOP
    
mov_away:
    .byte STEP_DOWN_VERY_SLOW, HIDE_SPRITE, PAUSE_4, SHOW_SPRITE, HIDE_SPRITE, PAUSE_4, SHOW_SPRITE, STEP_DOWN_VERY_SLOW, HIDE_SPRITE, PAUSE_4, SHOW_SPRITE, STEP_DOWN_VERY_SLOW, HIDE_SPRITE, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich warte hier jeden Abend darauf, das meine Schwester Teah zurückkommt.\pSie ist sehr verschlossen, aber gutherzig.\pSie sorgt sich um die Toten ebensosehr als um die Lebenden.\pNicht viele Menschen sind so emphatisch wie sieDOTS"
str_1:
    .autostring 34 2 "IchDOTS DOTS DOTS\nDOTSmuss jetzt gehen.\pMeine Schwester wird jeden Moment zurück kommenDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Every evening I wait for my sister Teah to return here.\pShe is somewhat introverted but has a warm heart.\pShe cares about the dead as much as about the living.\pNot many people are that emphatic."
str_1:
    .autostring 34 2 "IDOTS DOTS DOTS\nDOTShave to go now.\pMy sister will return any moment nowDOTS"

.endif