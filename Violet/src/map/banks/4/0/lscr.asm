
.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"

.global str_mother

.global lscr_0x719248

lscr_0x719248:
	.byte 0x2
.word lscr_0x719056
	.byte 0x3
.word ow_script_0x83ff26
	.byte 0x0


.align 4
.global lscr_0x719056

lscr_0x719056:
	.hword STORY_PROGRESS, 0x1
	.word ow_script_0x89bb77
	.hword 0x0



.global ow_script_0x8400be
.global ow_script_0x83ff26
.global ow_script_0x89bb77

ow_script_0x83ff26:
compare STORY_PROGRESS 0x1
gotoif EQUAL ow_script_0x8400be
end


ow_script_0x8400be:
movesprite2 0x1 0x6 0x6
spritebehave 0x1 0x7
end


ow_script_movs_0x89ba89:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x89bd3d:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


ow_script_movs_0x89adc0:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STOP


ow_script_movs_0x89adbd:
.byte SAY_QUESTION
.byte STOP


ow_script_movs_0x89adba:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8401ea:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


ow_script_0x89bb77:
lockall
setvar 0x8000 0x0
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_0x89ba97
callstd MSG
special 0xf
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
clearflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
showsprite 0x2
sound 0x9
checksound
sound 0x15
applymovement 0xff ow_script_movs_0x89ba89
applymovement 0x1 ow_script_movs_0x89ba89
waitmovement 0x0
applymovement 0x2 ow_script_movs_0x89bd3d
waitmovement 0x0
loadpointer 0x0 str_0x947c6c
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x2 ow_script_movs_0x89adc0
waitmovement 0x0
sound 0x9
hidesprite 0x2
setflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
fadesong MUS_ALABASTIA
checksound
pause 0x1c
sound 0x15
applymovement 0xff ow_script_movs_0x89adbd
applymovement 0x1 ow_script_movs_0x89adbd
waitmovement 0x0
checksound
setvar 0x8000 0x0
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_0x89ad96
callstd MSG
special 0xf
applymovement 0x1 ow_script_movs_0x89adba
waitmovement 0x0
setvar 0x8000 0x0
loadpointer 0x0 str_mother
setvar 0x8000 0
special 0xe
loadpointer 0x0 str_0x89ad05
callstd MSG
special 0xf
applymovement 0x1 ow_script_movs_0x8401ea
waitmovement 0x0
setvar STORY_PROGRESS 0x2
releaseall
end


.ifdef LANG_GER

str_mother:
    .string "Mutter"



str_0x89ba97:
    .string "Guten Morgen PLAYER.\pDu hast wieder einmal verschlafen!\pUnd ausgerechnet heute, wo doch\ndeine Abschlussprüfung in der\lTrainerschule ansteht.\pBeeil dich lieber, RIVAL\nwird jeden Moment -"



str_0x947c6c:
    .string "PLAYER, du Schlafmütze!\pDie Prüfung beginnt gleich\nund du bist noch gar nicht\lrichtig aus den Federn gekommen!\pWenn wir zu spät\nkommen, wird uns Faun eine\lordentliche Standpauke halten und\lwir wissen ja, wie er sein kannDOTS\pAlso los! Komm in die Gänge!\pIch gebe dir eine halbe Minute!"



str_0x89ad96:
    .string "Was für ein AuftrittDOTS"



str_0x89ad05:
    .string "RIVAL hatte schon immer etwas von\neinem Hitzkopf an sichDOTS\pDu solltest ihn lieber nicht\nwarten lassen, befürchte ich.\pUnd natürlich viel\nGlück bei deiner Prüfung, Liebling!"


.elseif LANG_EN

.endif