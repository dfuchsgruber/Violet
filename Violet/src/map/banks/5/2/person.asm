.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"

.global ow_script_0x8de301
.global ow_script_map_5_2_person_0
.global ow_script_map_5_2_person_2
.global ow_script_map_5_2_person_1
.global ow_script_0x8de4b5
.global ow_script_0x8de66e

ow_script_map_5_2_person_0:
loadpointer 0x0 str_0x8a3b23
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a3b23:
    .string "Hier in Meriana City bekommen wir\nsauberes Wasser aus den Quellen\lvon Kaskada, südlich von hier."


.elseif LANG_EN

.endif


ow_script_map_5_2_person_1:
loadpointer 0x0 str_0x8a3b8f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a3b8f:
    .string "Magst du Gedichte? Ich finde\nThomas Dylan fantastisch. Do not\lgo gentle into that good nightDOTS\lEin Meisterwerk, oder?"


.elseif LANG_EN

.endif


ow_script_movs_0x8e07eb:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_5_2_person_2:
	loadpointer 0 str_0
	callstd MSG_FACE
	end

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


ow_script_0x8de66e:
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e1de2
callstd MSG_FACE
special 0xF
end


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

str_bewohner:
	.string "Bewohner"

str_0x8e07ee:
	.autostring 35 2 "DOTSDiese verdammte korrupte Polizei\pDOTS DOTS DOTS"



str_0x8e066f:
	.autostring 35 2 "Nanu? Wer bist du denn?\pDOTS DOTS DOTS\pDu hast den Streit zwischen mir und dem Polizisten mitgehört?\pWeißt du, die Polizei in Theto ist bis auf\'s Mark korrupt.\pSie nutzen schamlos ihre Macht aus, um den Bewohnern ihre Willkür aufzuzwingen.\pUnd obwohl sie den Top Vier unterstehen, haben die Polizisten nichts zu befürchten.\pSelbst, wenn man sie auf frischer Tat ertappen würdeDOTS"


str_0x8de630:
    .autostring 35 2 "Du hast wirklich einen gewissen Heldenmut, dich mit der Polizei anzulegen.\pHast du je darüber nachgedacht, dich der Revolutionsbewegung anzuschließen?"



str_0x8e1de2:
    .autostring 35 2 "Das System, in dem wir leben, ist von Grund auf marode.\pDie Korruption reicht sogar bis zu den Top Vier selbstDOTS"



str_0x8de430:
	.autostring 35 2 "Selbst, wenn man einen der Übeltäter bei der Polizei bloßstellen könnte, würde man nichts erreichen.\pDie Polizei hat durch die Top Vier so gut wie jede BefugnisDOTS"

str_0:
	.autostring 34 2 "Über kurz oder lang, wird die Region von Anarchisten überrannt werden.\pDas System der Top Vier ist durch und durch korrupt.\pEs darf nicht überleben!"
.elseif LANG_EN


str_0:
	.autostring 34 2 "Sooner or later this region will be overwhelmed by anarchists of all kind.\pThis system of the Elite Four is corrupted to its core.\pIt must not survive!"

.endif