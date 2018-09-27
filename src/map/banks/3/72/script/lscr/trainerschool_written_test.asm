.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "overworld_script.s"

.global ow_script_0x89c150
ow_script_0x89c150:
@ Move rival to his place
lockall
call ow_script_0x89ba6e
loadpointer 0x0 str_rival_to_player
callstd MSG
special 0x7
applymovement 0x1 mov_rival_to_place
waitmovement 0
applymovement 0xFF mov_step_up
waitmovement 0
addvar STORY_PROGRESS 1
releaseall
end

mov_rival_to_place:
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP

mov_step_up:
	.byte STEP_UP, STOP

.global ow_script_trainerschool_faun_call_out

ow_script_trainerschool_faun_call_out:
lockall
applymovement 0x9 mov_look_right
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_faun_to_player
callstd MSG
special 0x7
addvar TRAINERSCHOOL_PROGRESS 1
releaseall
end


mov_look_right:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_trainerschool_written_test

ow_script_trainerschool_written_test:
lockall
@ All npcs (+ player) look up
applymovement 0xff mov_look_up
applymovement 0x1 mov_look_up
applymovement 0x2 mov_look_up
applymovement 0x3 mov_look_up
applymovement 0x4 mov_look_up
applymovement 0x9 mov_look_down
waitmovement 0x0
@ Camera to Faun
special 0x113
fadesong 0
applymovement 0x7f mov_cam_to_faun
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_faun_announce
callstd MSG
special 0x7
applymovement 0x7f mov_cam_back
waitmovement 0x0
special 0x114
@ Faun walks towards Felix
applymovement 0x9 mov_faun_to_felix
waitmovement 0x0
sound 0x17
setmaptile 0x3 0x21 0x2c6 0x1
special 0x8e
checksound
@ Faun walks towards Blaise
applymovement 0x9 mov_faun_to_blaise
waitmovement 0x0
sound 0x17
setmaptile 0x2 0x21 0x2c5 0x1
special 0x8e
checksound
@ Faun walks towards Player
applymovement 0x9 mov_faun_to_player
waitmovement 0x0
sound 0x17
setmaptile 0x6 0x21 0x2c5 0x1
special 0x8e
checksound
@ Faun walks towards Rival
applymovement 0x9 mov_faun_to_rival
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x21 0x2c6 0x1
special 0x8e
checksound
@ Faun walks towards Maike
applymovement 0x9 mov_faun_to_may
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x23 0x2c6 0x1
special 0x8e
checksound
@ Faun walks back
applymovement 0x9 mov_faun_back
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_test_begins
callstd MSG
special 0x7
@ Test begins - start cutscene
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
playsong MUS_JEROPARDY 0x0
setvar 0x8000 0x0
@ setvar STORY_PROGRESS 0x6
callasm trainerschool_test_init
waitstate
clearflag TRANS_DISABLE
fadescreen 0x0
@ Let npcs react to test
sound 0x15
applymovement 3 mov_exclam
waitmovement 0
pause 32
sound 0x15
applymovement 4 mov_x
applymovement 1 mov_x
waitmovement 0
pause 16
sound 0x15
applymovement 2 mov_question
waitmovement 0
pause 128
@ Test is over
fadesong MUS_TRAINERSCHOOL
call ow_script_0x89c5ee
loadpointer 0x0 str_test_over
callstd MSG
special 0x7
@ Faun collects the sheets
applymovement 0x9 mov_faun_to_felix
waitmovement 0x0
sound 0x17
setmaptile 0x3 0x21 0x2b9 0x1
special 0x8e
checksound
applymovement 0x9 mov_faun_to_blaise
waitmovement 0x0
sound 0x17
setmaptile 0x2 0x21 0x2b8 0x1
special 0x8e
checksound
applymovement 0x9 mov_faun_to_player
waitmovement 0x0
sound 0x17
setmaptile 0x6 0x21 0x2b8 0x1
special 0x8e
checksound
applymovement 0x9 mov_faun_to_rival
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x21 0x2b9 0x1
special 0x8e
checksound
applymovement 0x9 mov_faun_to_may
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x23 0x2b9 0x1
special 0x8e
checksound
applymovement 0x9 mov_faun_back
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_after_test
callstd MSG
special 0x7
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
addvar STORY_PROGRESS 1
addvar TRAINERSCHOOL_PROGRESS 1
releaseall
end


mov_look_up:
	.byte LOOK_UP
	.byte STOP

mov_look_down:
	.byte FACE_DOWN
	.byte STOP

mov_cam_to_faun:
	.byte STEP_UP
	.byte STEP_UP
	.byte STOP

mov_cam_back:
	.byte STEP_DOWN
	.byte STEP_DOWN
	.byte STOP

mov_faun_to_felix:
	.byte STEP_LEFT
	.byte STEP_LEFT
	.byte STEP_DOWN
	.byte STEP_DOWN
	.byte STEP_LEFT
	.byte STEP_LEFT
	.byte FACE_DOWN
	.byte STOP

mov_faun_to_blaise:
	.byte STEP_LEFT
	.byte FACE_DOWN
	.byte STOP

mov_faun_to_player:
	.byte STEP_RIGHT
	.byte STEP_RIGHT
	.byte STEP_RIGHT
	.byte STEP_RIGHT
	.byte FACE_DOWN
	.byte STOP

mov_faun_to_rival:
	.byte STEP_RIGHT
	.byte FACE_DOWN
	.byte STOP

mov_faun_to_may:
	.byte STEP_RIGHT
	.byte STEP_DOWN
	.byte STEP_DOWN
	.byte STEP_DOWN
	.byte LOOK_LEFT
	.byte STOP

mov_faun_back:
	.byte STEP_UP
	.byte STEP_UP
	.byte STEP_UP
	.byte STEP_UP
	.byte STEP_UP
	.byte STEP_LEFT
	.byte FACE_DOWN
	.byte STOP

mov_exclam:
	.byte SAY_EXCLAM
	.byte STOP

mov_question:
	.byte SAY_QUESTION
	.byte STOP

mov_x:
	.byte SAY_X
	.byte STOP


.ifdef LANG_GER

str_rival_to_player:
	.autostring 36 2 "PLAYER! Wir sind schon viel zu spät! Wenn ich wegen deiner Trödelei die Abschlussprüfung in den Sand setzte, dannDOTS!\pBeeilung jetzt!"

str_faun_to_player:
	.autostring 36 2 "PLAYER!\pDa bist ja endlich!\nHehe! Ich hatte schon befürchtet, du und RIVAL würdet kneifen!\pNimm PlatzDOTS"

str_faun_announce:
	.autostring 36 2 "So ihr Bälger!\nHeute ist es so weit und ihr werdet nach meiner harten Ausbildung zu echten Trainern!\pZuerst werde ich euer wissen in einer schriftlichen Prüfung abfragen.\pDann geht es nach draußen, wo ihr einen Feldtest bestehen müsst.\pIch bin mir sicher, dass ihr alle das nicht vergeigen werdet!\pIch teile nun die Fragebögen aus.\pKeinen Mucks will ich dabei hören!"
        
str_test_begins:
	.autostring 36 2 "Na dann! Viel Glück\pIhr werdet es brauchenDOTS\nHehe!"
        
str_test_over:
	.autostring 36 2 "Gut, das wars!\nStifte weg!\pDas war ein kleiner Vorgeschmack auf das Trainer-Dasein!\pKeine Bange, der Feldtest macht ein Stück mehr Spaß!"
        
str_after_test:
	.autostring 35 2 "Sehr schön!\nIch werde mir eure Antworten ansehen und ihr könnt erst einmal durchschnaufen.\pWir treffen uns auf dem Hof, wo der Feldtest stattfindet.\pDas wird ein Spaß werden, meint ihr nicht auch?"
        
.elseif LANG_EN

.endif
