.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x89ba89
ow_script_movs_0x89ba89:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x89bd3d
ow_script_movs_0x89bd3d:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_movs_0x89adc0
ow_script_movs_0x89adc0:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STOP


.global ow_script_movs_0x89adbd
ow_script_movs_0x89adbd:
.byte SAY_QUESTION
.byte STOP


.global ow_script_movs_0x89adba
ow_script_movs_0x89adba:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8401ea
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


.global ow_script_0x89bb77
ow_script_0x89bb77:
lockall
setvar 0x8000 0x0
loadpointer 0x0 str_0x89ba8d
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
call ow_script_0x89ba6e
loadpointer 0x0 str_0x947c6c
callstd MSG
special 0x7
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
loadpointer 0x0 str_0x89ba8d
special 0xe
loadpointer 0x0 str_0x89ad96
callstd MSG
special 0xf
applymovement 0x1 ow_script_movs_0x89adba
waitmovement 0x0
setvar 0x8000 0x0
loadpointer 0x0 str_0x89ba8d
special 0xe
loadpointer 0x0 str_0x89ad05
callstd MSG
special 0xf
applymovement 0x1 ow_script_movs_0x8401ea
waitmovement 0x0
setvar STORY_PROGRESS 0x2
releaseall
end

.global str_0x89ba8d

str_0x89ba8d:
    .string "Mutter:"
        
        
.global str_0x89ba97

str_0x89ba97:
    .string "Guten Morgen PLAYER.\pDu hast wieder einmal verschlafen!\pUnd ausgerechnet heute, wo doch\ndeine Abschlussprüfung in der\lTrainerschule ansteht.\pBeeil dich lieber, RIVAL\nwird jeden Moment -"
        
        
.global str_0x947c6c

str_0x947c6c:
    .string "PLAYER, du Schlafmütze!\pDie Prüfung beginnt gleich\nund du bist noch gar nicht\lrichtig aus den Federn gekommen!\pWenn wir zu spät\nkommen, wird uns Faun eine\lordentliche Standpauke halten und\lwir wissen ja, wie er sein kann...\pAlso los! Komm in die Gänge!\pIch gebe dir eine halbe Minute!"
        
        
.global str_0x89ad96

str_0x89ad96:
    .string "Was für ein Auftritt..."
        
        
.global str_0x89ad05

str_0x89ad05:
    .string "RIVAL hatte schon immer etwas von\neinem Hitzkopf an sich...\pDu solltest ihn lieber nicht\nwarten lassen, befürchte ich.\pUnd natürlich viel\nGlück bei deiner Prüfung, Liebling!"
        
        