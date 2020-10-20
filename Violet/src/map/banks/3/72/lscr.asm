.include "vars.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"

.global ow_script_trainerschool_faun_call_out
.global ow_script_trainerschool_start_exam

.global lscr_0x719018

lscr_0x719018:
	.byte 0x2
.word lscr_0x71a186
	.byte 0x0


.align 4
.global lscr_0x71a186

lscr_0x71a186:
	.hword STORY_PROGRESS, 0x5
	.word ow_script_0x89c150
	.hword 0x0

.global ow_script_0x89c150
ow_script_0x89c150:
@ Move rival to his place
lockall
loadpointer 0x0 str_rival_to_player
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_ANNOYED
applymovement 0x1 mov_rival_to_place
waitmovement 0
applymovement 0xFF mov_step_up
waitmovement 0
addvar STORY_PROGRESS 1
releaseall
end

mov_rival_to_place:
.byte STEP_UP_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte LOOK_UP
.byte STOP

mov_step_up:
	.byte STEP_UP, STOP


ow_script_trainerschool_faun_call_out:
lockall
applymovement 0x9 mov_look_right
waitmovement 0x0
loadpointer 0x0 str_faun_to_player
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
addvar TRAINERSCHOOL_PROGRESS 1
releaseall
end


mov_look_right:
.byte LOOK_RIGHT
.byte STOP



ow_script_trainerschool_start_exam:
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
loadpointer 0x0 str_faun_announce
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
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
loadpointer 0x0 str_exam_begins
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
@ Exam begins - start cutscene
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
playsong MUS_JEROPARDY 0x0
setvar 0x8000 0x0
@ setvar STORY_PROGRESS 0x6
callasm trainerschool_exam_init
waitstate
clearflag TRANS_DISABLE
fadescreen 0x0
@ Let npcs react to exam
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
@ Exam is over
fadesong MUS_TRAINERSCHOOL
loadpointer 0x0 str_exam_over
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
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
loadpointer 0x0 str_after_exam
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
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
	.autostring 35 2 "PLAYER!\nWir sind schon viel zu spät!\pWenn ich wegen deiner Trödelei die Abschlussprüfung in den Sand setzte, dann setzt's wasDOTS\pBeeilung jetzt!"

str_faun_to_player:
	.autostring 35 2 "PLAYER!\pDa bist du ja endlich!\pIch hatte schon befürchtet, RIVAL und du würden keifen!"

str_faun_announce:
	.autostring 34 2 "So, ihr Rotzlöffel!\pHeute ist hoffentlich euer letzter Tag in dieser Schule.\pJetzt müsst ihr beweisen, dass ihr das Zeug zu Trainern habt.\pZuerst werde ich euer Wissen in einer schriftlichen Prüfung abfragen.\pDanach werdet ihr draußen einen Feldtest bestehen müssen.\pGlaubt ja nicht, dass ich euch in dieser Prüfung irgendetwas schenke!\pIch teile jetzt die Fragebögen aus.\pWer auch nur einen Laut von sich gibt, ist schon durchgefallen!"

str_exam_begins:
	.autostring 35 2 "Viel Glück, ihr Bälger!\pIhr werdet es brauchen, hehe!"

str_exam_over:
	.autostring 34 2 "Gut, das wars!\pStifte weg!\pEin netter kleiner Vorgeschmack auf das Trainer-Dasein, was?\pKeine Bange, der Feldtest macht ein Stückchen mehr Spaß!"

str_after_exam:
	.autostring 35 2 "Sehr gut!\pIch werde mir eure Antworten ansehen.\pIhr könnt erst einmal durchschnaufen.\pWir treffen uns gleich draußen auf dem Hof, verstanden?\pUnd ja nicht trödeln!"

.elseif LANG_EN


str_rival_to_player:
	.autostring 35 2 "PLAYER!\nWe are way too late anyways!\pIf I mess up this exam because of you, I will whip you up!"

str_faun_to_player:
	.autostring 35 2 "PLAYER!\pThere you are!\pI almost thought RIVAL and you would duck out!"

str_faun_announce:
	.autostring 34 2 "Well, brats!\pToday hopefully is your last day in this school.\pNow you will have to prove that you have what makes a trainer.\pFirst I will test your knowledge in a written exam.\pAfterwards we will do a field examination outside.\pDon't you think I will give you anything for free in this test.\pI will now distribute the papers, if anybody makes any noise they will fail immediatly, got that?"

str_exam_begins:
	.autostring 35 2 "Good luck, brats!\pYou will need it, hehe!"

str_exam_over:
	.autostring 34 2 "That's it!\pPut the pens down!\pA little impression of what's to come once you are trainer.\pNo worries, the field exam will make little bit more fun!"

str_after_exam:
	.autostring 35 2 "Great!\pI will now have look at your answers.\pYou can now take a little time to breathe.\pWe will meet outside in a moment, ok?\pAnd don't you dare to stroll!"

.endif