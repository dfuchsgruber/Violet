.include "flags.s"
.include "movements.s"
.include "callstds.s"
.include "species.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_movs_0x94d655
ow_script_movs_0x94d655:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x94c547
ow_script_movs_0x94c547:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x94c542
ow_script_movs_0x94c542:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x94c408
ow_script_0x94c408:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x94d6db
callstd MSG
special 0x7
addvar STORY_PROGRESS 0x1
setvar 0x8004 0x4
special 0x19
waitstate
pause 64
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x94d69f
callstd MSG
special 0x7
special 0x113
applymovement 0x7f ow_script_movs_0x94d655
waitmovement 0x0
special 0x114
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x94d65f
callstd MSG
special 0x7
call ow_script_0x8a2791
loadpointer 0x0 str_0x94d5ec
callstd MSG_KEEPOPEN
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x94d4e4
callstd MSG_KEEPOPEN
special 0x7
call ow_script_0x8a2791
loadpointer 0x0 str_0x94d210
callstd MSG_KEEPOPEN
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x94d09a
callstd MSG_KEEPOPEN
special 0x7
call ow_script_0x8d7a10
sound 0x15
applymovement 0x1 ow_script_movs_0x94c547
applymovement 0x2 ow_script_movs_0x94c547
waitmovement 0x0
checksound
cry POKEMON_DEOXYS 0x0
waitcry
call ow_script_0x8a2791
loadpointer 0x0 str_0x94c54b
callstd MSG_KEEPOPEN
special 0x7
cry POKEMON_DEOXYS 0x0
call ow_script_0x8d7a10
cry POKEMON_DEOXYS 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x94c542
waitmovement 0x0
special 0x114
cry POKEMON_DEOXYS 0x0
call ow_script_0x8d7a10
cry POKEMON_DEOXYS 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x94c524
callstd MSG
special 0x7
cry POKEMON_DEOXYS 0x0
call ow_script_0x8d7a10
fadescreen 0x1
sound 0x64
checksound
goto ow_script_0x94d77e


.global ow_script_0x94d77e
ow_script_0x94d77e:
callasm cmdx2D_force_pals_to_black
copyvar 0x8000 0x8008
copyvar 0x8001 0x8009
copyvar 0x8004 0x800a
setvar 0x8002 0x3
setvar 0x8003 0x17
setflag ROUTE_5_FUTURE_SEEN
special 0x2d
waitstate
end


.ifdef LANG_GER
.global str_0x94d6db

str_0x94d6db:
	.autostring 35 2 "Ist das\nDOTS DOTS DOTS\pDOTS wieder eine Vision?\pAber was ist das für ein beängstigender Ort?\pDas alles hier kommt mir überhaupt nicht bekannt vor DOTS"
        
        
.global str_0x94d69f

str_0x94d69f:
    .autostring 35 2 "Überall ist Dunkelheit DOTS"
        
        
.global str_0x94d65f

str_0x94d65f:
    .autostring 35 2 "Sind das etwa Faun und Larissa?\pWarum sind sie an diesem Ort?"
        
        
.global str_0x94d5ec

str_0x94d5ec:
    .autostring 35 2 "Faun, ich bin froh, Sie hier zu treffen.\pIch hatte schon Angst, dass niemand auftauchen würde DOTS"
        
        
.global str_0x94d4e4

str_0x94d4e4:
    .autostring 35 2 "Ich fürchte, dass die anderen Mitglieder der Top Vier inzwischen nicht mehr am Leben sind.\pVielleicht wollen sie sich auch nicht der Gefahr ausetzten, entdeckt zu werden DOTS\pWer weiß DOTS DOTS DOTS"
        
.global str_0x94d210

str_0x94d210:
	.autostring 35 2 "Bedauernswert.\nAber wir haben nicht viel Zeit.\pWenn wir diese Katastrophe doch einfach nur verhindert hätten!\pAber wer hätte ahnen können, dass wir uns einmal in dieser aussichtslosen Lage befinden?"

        
.global str_0x94d09a

str_0x94d09a:
	.autostring 35 2 "Wir haben die Bedrohung durch Team Violet wohl massiv unterschätzt.\pDas schließt mich natürlich ein.\pVielleicht ist unsere Welt wirklich bereits verloren DOTS\pUnd diese dunkle Sphäre ist die Zukunft Thetos DOTS\pAber solange auch nur ein Mensch noch am Leben ist, müssen wir kämpfen.\pLarissa!\nVergiss nicht, wer du bist!\pWenn uns jemand anführen soll, musst du diese Person sein!"

.global str_0x94c54b

str_0x94c54b:
    .autostring 35 2 "Unmöglich!\nSie haben uns gefunden!"
        
        
.global str_0x94c524

str_0x94c524:
    .autostring 35 2 "Das ist unser EndeDOTS"
        
        
.elseif LANG_EN

.endif
