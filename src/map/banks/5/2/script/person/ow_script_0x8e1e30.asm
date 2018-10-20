.include "flags.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8e07eb
ow_script_movs_0x8e07eb:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8e1e30
ow_script_0x8e1e30:
checkflag MERIANA_CITY_REVOLUTIONARIES
gotoif LESS ow_script_0x8de301
checkflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
gotoif EQUAL ow_script_0x8de4b5
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e07ee
callstd MSG_KEEPOPEN
special 0xF
sound 0x15
faceplayer
applymovement 0x800f ow_script_movs_0x8e07eb
waitmovement 0x0
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e066f
callstd MSG_KEEPOPEN
special 0xF
clearflag MERIANA_CITY_REVOLUTIONARIES
addvar MERIANA_CITY_REVOLUTIONARY 0x1
closeonkeypress
end


.global ow_script_0x8de4b5
ow_script_0x8de4b5:
compare MERIANA_CITY_REVOLUTIONARY 4
gotoif EQUAL ow_script_0x8de66e
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8de630
callstd MSG_FACE
special 0xF
end


.global ow_script_0x8de66e
ow_script_0x8de66e:
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e1de2
callstd MSG_FACE
special 0xF
end


.global ow_script_0x8de301
ow_script_0x8de301:
checkflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
gotoif EQUAL ow_script_0x8de4b5
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8de430
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER
.global str_0x8e07ee

str_bewohner:
	.string "Bewohner"

str_0x8e07ee:
	.autostring 36 2 "DOTSDiese verdammte korrupte Polizei\pDOTS DOTS DOTS"
        
        
.global str_0x8e066f

str_0x8e066f:
	.autostring 36 2 "Nanu? Wer bist du denn?\pDOTS DOTS DOTS\pDu hast den Streit zwischen mir und dem Polizisten mitgehört?\pWeißt du, die Polizei in Theto ist bis auf\s Mark korrupt.\pSie nutzen schamlos ihre Macht aus, um den Bewohnern ihre Willkür aufzuzwingen.\pUnd obwohl sie den Top Vier unterstehen, haben die Polizisten nichts zu befürchten.\pSelbst, wenn man sie auf frischer Tat ertappen würdeDOTS"

.global str_0x8de630

str_0x8de630:
    .autostring 36 2 "Du hast wirklich einen gewissen Heldenmut, dich mit der Polizei anzulegen.\pHast du je darüber nachgedacht, dich der Revolutionsbewegung anzuschließen?"
        
        
.global str_0x8e1de2

str_0x8e1de2:
    .autostring 36 2 "Das System, in dem wir leben, ist von Grund auf marode.\pDie Korruption reicht sogar bis zu den Top Vier selbstDOTS"
        
        
.global str_0x8de430

str_0x8de430:
	.autostring 36 2 "Selbst, wenn man einen der Übeltäter bei der Polizei bloßstellen könnte, würde man nichts erreichen.\pDie Polizei hat durch die Top Vier so gut wie jede BefugnisDOTS"
        
.elseif LANG_EN

.endif
