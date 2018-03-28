.include "overworld_script.s"

.include "std.s"

.global ow_script_0x886913
ow_script_0x886913:
goto ow_script_0x8fad58


.global ow_script_0x8fad58
ow_script_0x8fad58:
lockall
goto ow_script_0x88c7d7


.global ow_script_movs_0x886b4b
ow_script_movs_0x886b4b:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a1332
ow_script_movs_0x8a1332:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x8a1307
ow_script_movs_0x8a1307:
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x886b48
ow_script_movs_0x886b48:
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x886b1b
ow_script_movs_0x886b1b:
.byte STEP_UP
.byte STOP


.global ow_script_0x88c7d7
ow_script_0x88c7d7:
sound 0x15
applymovement 0x1 ow_script_movs_0x886b4b
waitmovement 0x0
checksound
playsong MUS_KOMMT_MIT_SPIELER_WIRD_HERUMGEFUHRT 0x0
call ow_script_0x8a1311
applymovement 0x1 ow_script_movs_0x8a1332
waitmovement 0x0
loadpointer 0x0 str_0x8869ab
callstd MSG
call ow_script_0x8a1251
applymovement 0x1 ow_script_movs_0x8a1307
applymovement 0xff ow_script_movs_0x8a1307
waitmovement 0x0
loadpointer 0x0 str_0x886a80
callstd MSG
setdooropened 0x48 0x1c
doorchange
applymovement 0x1 ow_script_movs_0x886b48
waitmovement 0x0
hidesprite 0x1
applymovement 0xff ow_script_movs_0x886b1b
waitmovement 0x0
applymovement 0xff ow_script_movs_0x886b48
waitmovement 0x0
clearflag PKMNMENU
setvar STORY_PROGRESS 0x9
warp 0x5 0x4 0x0 0x0 0x0
end


.global ow_script_0x8a1251
ow_script_0x8a1251:
getplayerpos 0x8000 0x8001
compare 0x8000 0x42
callif EQUAL ow_script_0x8a12f1
return


.global ow_script_movs_0x8a1304
ow_script_movs_0x8a1304:
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a12f1
ow_script_0x8a12f1:
applymovement 0x1 ow_script_movs_0x8a1304
applymovement 0xff ow_script_movs_0x8a1304
waitmovement 0x0
return


.global ow_script_0x8a1311
ow_script_0x8a1311:
getplayerpos 0x8000 0x8001
compare 0x8000 0x42
callif EQUAL ow_script_0x8a1323
return


.global ow_script_movs_0x8a132f
ow_script_movs_0x8a132f:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8a1323
ow_script_0x8a1323:
applymovement 0x1 ow_script_movs_0x8a132f
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x8869ab

str_0x8869ab:
    .string "Hallo! Du siehst mir aus wie ein\nTrainer, bist aber offensichtlich\lnoch grün hinter den Ohren. Keine\lSorge, mit etwas Übung wird das\lschon. Komm mit, ich erkläre dir\ldie Welt, die sich dir als Trainer\leröffnet."
        
        
.global str_0x886a80

str_0x886a80:
    .string "Diesen Ort nennt man Pokestop.\nJeder Trainer hat sozusagen die\lPflicht dort vorbeizuschauen,\lsobald er eine neue Stadt\lerreicht. Komm, gehen wir hinein."
        
        
.elseif LANG_EN

.endif
