.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "person_behaviours.s"
.include "movements.s"

.global lscr_0x8f5100
.global ow_script_0x8d3195
.global ow_script_0x92eadc
.global ow_script_0x8de677
.global ow_script_0x8caf33
.global ow_script_0x8112fd
.global lscr_0x719b77

lscr_0x8f5100:
	.byte 0x3
.word ow_script_0x8112fd
	.byte 0x2
.word lscr_0x719b77
	.byte 0x0

.align 4

lscr_0x719b77:
	.hword STORY_PROGRESS, 0x14 
	.word ow_script_0x8d3195
	.hword 0x0


ow_script_0x8112fd:
checkflag FRBADGE_1
callif EQUAL ow_script_0x8caf33
end


ow_script_0x8caf33:
checkflag AKTANIA_FLASHBACK_DONE
gotoif NOT_EQUAL dont_move_woman
compare STORY_PROGRESS 0x14
gotoif NOT_EQUAL dont_move_woman
movesprite2 39 0x2e 0x2d
spritebehave 39 BEHAVIOUR_FACE_UP
dont_move_woman:
movesprite2 0x6 0x1c 0x31
spritebehave 0x6 BEHAVIOUR_LOOK_AROUND
movesprite2 25 0x23 0x2b
movesprite2 26 0x27 0x29
movesprite2 27 0x2c 0x26
movesprite2 28 0x34 0x29
movesprite2 29 0x36 0x2e
movesprite2 30 0x35 0x32
movesprite2 31 0x38 0x34
movesprite2 32 0x1f 0x2e
movesprite2 33 0x34 0x27
movesprite2 38 0x26 0x28
return


ow_script_0x8d3195:
checkflag AKTANIA_FLASHBACK_DONE
gotoif EQUAL ow_script_0x8de677
goto ow_script_0x92eadc


ow_script_0x92eadc:
lockall
fadesong 0
loadpointer 0x0 str_0x92ec17
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
fadescreen 0x1
sound 0x64
checksound
callasm cmdx2D_force_pals_to_black
setvar STORY_PROGRESS 0x15
// writebytetooffset 0x2 0x2036e28
warpmuted 0x3 0x49 0xff 0x8 0x24
waitstate
end


ow_script_0x8de677:
pause 64
loadpointer 0 str_0
callstd MSG
loadpointer 0x0 str_1
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
loadpointer 0 str_2
callstd MSG
loadpointer 0x0 str_3
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
loadpointer 0 str_4
callstd MSG
loadpointer 0x0 str_5
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_HAPPY
pause 32
loadpointer 0 str_6
callstd MSG
applymovement 39 mov_6d
waitmovement 0
spritebehave 39 BEHAVIOUR_WANDER_AROUND
movesprite 39 0x30 0x30
movesprite2 39 0x30 0x30
pause 16
loadpointer 0x0 str_7
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_RUMINATIVE
addvar STORY_PROGRESS 0x2
releaseall
end

mov_6d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP

.ifdef LANG_GER
str_0:
	.autostring 34 2 "Hey, ist bei dir alles in Ordnung?"
str_0x92ec17:
	.autostring 34 2 "Mir ist auf einmal so schwindeligDOTS\pWas geschieht hierDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIchDOTS\nDOTSkannDOTS DOTS DOTS"
str_1:
	.autostring 34 2 "W-Was ist passiert?"
str_2:
	.autostring 34 2 "Du bist gerade einfach so umgekippt.\pDu hast bestimmt einige Minuten bewusstlos auf dem Boden gelegen."
str_3:
	.autostring 34 2 "I-Ich war bewusstlos?\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_4:
	.autostring 34 2 "Ja, das warst du.\pDu bist auch ganz schön blassDOTS\pSoll ich dir Hilfe holen?"
str_5:
	.autostring 34 2 "N-Nein, ist schon in Ordnung.\pIch fühle mich schon viel besser!"
str_6:
	.autostring 34 2 "Na gut, wie du meinst.\pAber pass in Zukunft gut auf dich auf, ja?"
str_7:
	.autostring 34 2 "SeltsamDOTS\pWas ich da gesehen habe, während ich ohnmächtig warDOTS\pHat es irgendetwas mit meinem Traum letztens zu tun?\pDOTS DOTS DOTS\pIst das, was ich gesehen habe, wirklich passiert?\pWurde so Bruchfels zerstört?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch kann mir auf all das keinen Reim machenDOTS\pAber irgendetwas haben meine Träume zu bedeuten.\pDa bin ich mir ganz sicher.\pIch muss Antworten auf diese ganzen Fragen finden."
.elseif LANG_EN

.endif