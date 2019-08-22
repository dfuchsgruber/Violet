.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"
.include "specials.s"
.include "movements.s"

.global ow_script_ceometria_trigger_0

ow_script_ceometria_trigger_0:
    setvar 0x8004 12
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0x0
    applymovement 12 mov_face_left
    waitmovement 0
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

.elseif LANG_EN
str_block:
    .autostring 34 2 "You want to visit the Forest Cemetery, right?\pI am afraid but Teah, the gym leader of Ceometria, is currently speaking her prayers there.\pShe really dislikes being interrupted.\pWhy don't you come back later?"

.endif
