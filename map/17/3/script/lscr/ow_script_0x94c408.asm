.include "overworld_script.s"

.include "std.s"

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
    .string "Ist das erneut eine Vision?\n... ... ...\pDoch was ist das für ein dunkler,\nbeängstigender Ort?\pEs wirkt so, als hätten violette\nKristalle die Welt verschlungen..."
        
        
.global str_0x94d69f

str_0x94d69f:
    .string "Ein trister, lebloser Ort...\nWas hat das nur zu bedeuten?"
        
        
.global str_0x94d65f

str_0x94d65f:
    .string "Sind das etwa Faun und Larissa?\nWarum sind sie an diesem Ort?"
        
        
.global str_0x94d5ec

str_0x94d5ec:
    .string "Faun, ich bin froh, Euch\nhier zu treffen.\pIch hatte fast befürchtet, Ihr\nwürdet nicht kommen."
        
        
.global str_0x94d4e4

str_0x94d4e4:
    .string "Ach Mädchen, ich hätte genug\nGrund gehabt, dich wie die anderen\lzu versetzten.\pAber trotz allem, was passiert\nist, bleibe ich noch immer ein\lMitglied der Top Vier.\pAuch wenn von der Welt, die ich\ngeschworen habe zu beschützen,\lnicht mehr viel übrig ist..."
        
        
.global str_0x94d210

str_0x94d210:
    .string "Ich bedaure zutiefst, was\npassiert ist, und ich gebe zu,\ldass es hätte verhindert werden\lkönnen.\pDoch es war unmöglich, die\nEreignisse zu antizpieren, die\lunsere Welt in diese finstere\lSphäre gestürzt haben..."
        
        
.global str_0x94d09a

str_0x94d09a:
    .string "Das ist nicht länger von\nBedeutung. Was zählt, ist die\lTatsache, dass wir noch immer\lleben.\pDiese Welt mag verloren sein, aber\nwir werden unsere Hoffnung nicht\lverlieren.\pUnsere Freunde und Familien haben\nnicht umsonst ihr Leben gelassen.\pLarissa, es gilt nun, dich zu\nbeweisen. Wir werden uns nicht\lalles nehmen lassen."
        
        
.global str_0x94c54b

str_0x94c54b:
    .string "Unmöglich!\nSie haben uns gefunden!"
        
        
.global str_0x94c524

str_0x94c524:
    .string "Das ist unser Ende..."
        
        
.elseif LANG_EN

.endif
