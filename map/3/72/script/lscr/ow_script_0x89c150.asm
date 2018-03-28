.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x89c605
ow_script_movs_0x89c605:
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x89c614
ow_script_movs_0x89c614:
.byte STEP_UP
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
.byte STOP


.global ow_script_movs_0x89c602
ow_script_movs_0x89c602:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x89c5da
ow_script_movs_0x89c5da:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x89c5e4
ow_script_movs_0x89c5e4:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x89c3c1
ow_script_movs_0x89c3c1:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c563
ow_script_movs_0x89c563:
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x89c3c4
ow_script_movs_0x89c3c4:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x89c3b8
ow_script_movs_0x89c3b8:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c3b4
ow_script_movs_0x89c3b4:
.byte STEP_LEFT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c3ad
ow_script_movs_0x89c3ad:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c3a9
ow_script_movs_0x89c3a9:
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x89c3a2
ow_script_movs_0x89c3a2:
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x89c399
ow_script_movs_0x89c399:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte FACE_DOWN
.byte STOP


.global ow_script_0x89c150
ow_script_0x89c150:

call ow_script_0x89ba6e
loadpointer 0x0 str_0x89c626
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x89c605
applymovement 0xff ow_script_movs_0x89c614
waitmovement 0x0
pause 0x18
applymovement 0x9 ow_script_movs_0x89c602
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89c567
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x89c5da
applymovement 0x1 ow_script_movs_0x89c5e4
waitmovement 0x0
applymovement 0x9 ow_script_movs_0x89c3c1
waitmovement 0x0
special 0x113
fadesong MUS_0
applymovement 0x7f ow_script_movs_0x89c563
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89c3c8
callstd MSG
special 0x7
applymovement 0x7f ow_script_movs_0x89c3c4
waitmovement 0x0
special 0x114
applymovement 0x9 ow_script_movs_0x89c3b8
waitmovement 0x0
sound 0x17
setmaptile 0x3 0x21 0x2c6 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3b4
waitmovement 0x0
sound 0x17
setmaptile 0x2 0x21 0x2c5 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3ad
waitmovement 0x0
sound 0x17
setmaptile 0x6 0x21 0x2c5 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3a9
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x21 0x2c6 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3a2
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x23 0x2c6 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c399
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89c29e
callstd MSG
special 0x7
goto ow_script_0x898639


.global ow_script_0x898639
ow_script_0x898639:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
playsong MUS_JEROPARDY 0x0
setvar 0x8000 0x0
goto ow_script_0x89c871


.global ow_script_0x89c871
ow_script_0x89c871:

setvar STORY_PROGRESS 0x6
callasm trainerschool_test_init
waitstate

clearflag TRANS_DISABLE
fadescreen 0x0
goto ow_script_0x89d3db


.global ow_script_movs_0x89d4b7
ow_script_movs_0x89d4b7:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x89d4ba
ow_script_movs_0x89d4ba:
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x89d3db
ow_script_0x89d3db:
fadesong MUS_TRAINERSCHOOL
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89d5d3
callstd MSG
special 0x7
applymovement 0x9 ow_script_movs_0x89c3b8
waitmovement 0x0
sound 0x17
setmaptile 0x3 0x21 0x2b9 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3b4
waitmovement 0x0
sound 0x17
setmaptile 0x2 0x21 0x2b8 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3ad
waitmovement 0x0
sound 0x17
setmaptile 0x6 0x21 0x2b8 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3a9
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x21 0x2b9 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c3a2
waitmovement 0x0
sound 0x17
setmaptile 0x7 0x23 0x2b9 0x1
special 0x8e
checksound
applymovement 0x9 ow_script_movs_0x89c399
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x89d54d
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x89d4b7
applymovement 0x1 ow_script_movs_0x89d4ba
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89d4bd
callstd MSG
special 0x7
goto ow_script_0x8a4b76


.global ow_script_0x8a4b76
ow_script_0x8a4b76:
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
end


.global ow_script_0x89d3d1
ow_script_0x89d3d1:
addvar 0x8000 0x1
return


.ifdef LANG_GER
.global str_0x89c626

str_0x89c626:
    .string "PLAYER! Wir sind viel zu spät!\nUm unsere Unterlagen noch einmal\ldurchzusehen, bleibt wohl keine\lZeit mehr!\pKomm schon, Beeilung! Sonst\nverpassen wir noch die Prüfung!"
        
        
.global str_0x89c567

str_0x89c567:
    .string "Ah ja, RIVAL und PLAYER!\pIch hatte schon befürchtet, ihr\nwürdet nicht auftauchen.\pNehmt bitte Platz, wir\nhaben lange genug auf euch gewartet."
        
        
.global str_0x89c3c8

str_0x89c3c8:
    .string "Nun gut, meine lieben Schüler!\nHeute ist der Tag eurer\lAbschlussprüfung gekommen.\pZunächst werdet ihr in einer\ntheoretischen Prüfung euer Wissen\lum die Welt der Pokémon unter\lBeweis stellen.\pAnschließend liegt eine\npraktische Prüfung, in der euch\ldie Grundfertigkeiten eines\lTrainers abverlangt werden, vor euch.\pIn diesem Sinne werde\nich ohne weitere Umscheife mit dem\ltheoretischen Teil beginnen und\lnun die Fragebögen austeilen.\pIch wünsche absolute Ruhe!"
        
        
.global str_0x89c29e

str_0x89c29e:
    .string "Vor euch findet ihr einen Bogen mit\njeweils zehn Fragen, die ihr\lbeantworten müsst.\pMacht euch keinen zu großen\nKopf, ihr könnt im praktischen\lTeil noch genügend Punkte sammeln,\laber gebt euch trotzdem Mühe!\pIn diesem Sinne wünsche ich\nallen ein gutes Gelingen!"
        
        
.global str_0x89d5d3

str_0x89d5d3:
    .string "Gut, die Bearbeitungszeit ist nun\nvorüber!\pLegt eure Stifte beiseite, ich\nwerde die Bögen einsammeln und\lunverzüglich korrigieren."
        
        
.global str_0x89d54d

str_0x89d54d:
    .string "Findet euch, solange ich mit der\nKorrektur beschäftigt bin, doch\lbitte schon einmal auf dem Hof\lzusammen, damit wir schnell mit\lder praktischen Prüfung beginnen\lkönnen."
        
        
.elseif LANG_EN

.endif
