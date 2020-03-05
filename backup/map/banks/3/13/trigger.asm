.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"
.include "specials.s"
.include "movements.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"

.global ow_script_ceometria_trigger_0

ow_script_ceometria_trigger_0:
    setvar 0x8004 12
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0x0
    applymovement 12 mov_face_left
    waitmovement 0
    compare STORY_PROGRESS 0x3a
    gotoif LESS block
    checkflag (FLAG_HAWEILAND_MAIKE | 0x8000)
    gotoif 0 block
    loadpointer 0 str_let_through
    callstd MSG
    setvar 0x8004 12
    setvar 0x8005 0x36
    setvar 0x8006 0x10
    special SPECIAL_NPC_MOVE_TO
    addvar CEOMETRIA_CAN_ENTER_FOREST_CEMETERY 1
    releaseall
    end


block:
    loadpointer 0 str_block
    callstd MSG
    setvar 0x8004 12
    setvar 0x8005 0x36
    setvar 0x8006 0x10
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0x0
    applymovement 0xFF mov_step_left
    waitmovement 0
    releaseall
    end

mov_face_left:
    .byte LOOK_LEFT, STOP

mov_step_left:
    .byte STEP_LEFT, STOP

.ifdef LANG_GER
str_block:
    .autostring 34 2 "Du willst wohl auf den Waldfriedhof nicht?\pIch bin untröstlich, aber Teah, die Arenaleiterin von Ceometria, spricht dort eben in diesem Moment ihre Gebete.\pSie wird wirklich ungern gestört.\pWieso kommst du nicht später noch einmal vorbei?"
str_let_through:
    .autostring 34 2 "Eigentlich würde ich dich nicht auf den Waldfriedhof lassen, weil Teah, die Arenaleiterin, dort gerade ihre Gebete sprichtDOTS\pAber eben hat mich ein Kommandant von Team Violet überrumpelt, und ich fürchte, dass die Sache ins Auge gehen könnteDOTS\pWürdest du vielleicht nach dem Rechten sehen?"

.elseif LANG_EN
str_block:
    .autostring 34 2 "You want to visit the Forest Cemetery, right?\pI am afraid but Teah, the gym leader of Ceometria, is currently speaking her prayers there.\pShe really dislikes being interrupted.\pWhy don't you come back later?"
str_let_through:
    .autostring 34 2 "Under normal circumstances I wouldn't let you pass to the Forest Cemetery, since Teah, the gym leader, is currently speaking her prayers there.\pBut just now a commandant of Team Violet caught me unaware and I fear that this might not end wellDOTS\pWould you mind to check if everything is fine?"

.endif
