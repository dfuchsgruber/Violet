.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8e1841
ow_script_movs_0x8e1841:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8e1745
ow_script_movs_0x8e1745:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8e1742
ow_script_movs_0x8e1742:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8e162b
ow_script_movs_0x8e162b:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8e1521
ow_script_movs_0x8e1521:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8e146d
ow_script_movs_0x8e146d:
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8e0815
ow_script_0x8e0815:
lockall
applymovement 0xff ow_script_movs_0x8e1841
waitmovement 0x0

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e17bd
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_revo
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e1748
callstd MSG_KEEPOPEN
special 0xF

applymovement 0x2b ow_script_movs_0x8e1745
applymovement 0x29 ow_script_movs_0x8e1742
waitmovement 0x0

loadpointer 0 str_revo
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e1702
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_revo
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e167c
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_revo
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e162e
callstd MSG_KEEPOPEN
special 0xF

applymovement 0x2b ow_script_movs_0x8e162b
applymovement 0x29 ow_script_movs_0x8e162b
waitmovement 0x0

loadpointer 0 str_revo
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e15cc
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0 str_police_laughs
callstd MSG_KEEPOPEN
special 0xF

sound 0x15
applymovement 0x2a ow_script_movs_0x8e162b
waitmovement 0x0
applymovement 0x29 ow_script_movs_0x8e1521
applymovement 0x2a ow_script_movs_0x8e1521
applymovement 0x2b ow_script_movs_0x8e1521
waitmovement 0x0

loadpointer 0 str_revo
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e14fb
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e148e
callstd MSG_KEEPOPEN
special 0xF

getplayerpos 0x8000 0x8001
compare 0x8001 0x1e
callif EQUAL ow_script_0x8e1470
compare 0x8001 0x20
callif EQUAL ow_script_0x8e147c
applymovement 0x2a ow_script_movs_0x8e146d
waitmovement 0x0

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e12f8
callstd MSG_KEEPOPEN
special 0xF

applymovement 0x2a ow_script_movs_0x8e1841
waitmovement 0x0

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e11b9
callstd MSG_KEEPOPEN
special 0xF

applymovement 0x2a ow_script_movs_0x8e162b

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e0f79
callstd MSG_KEEPOPEN
special 0xF
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 meriana_revo_choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8e22eb


call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8e0cdc
callstd MSG_KEEPOPEN
special 0x7

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
trainerbattlecont 0x1 0x2c 0x0 str_0x8e0c9c str_0x8e0c71 ow_script_0x8e09cc

.align 4
meriana_revo_choice:
    .word str_meriana_revo_choice_0, 0
    .word str_meriana_revo_choice_1, 0



.global ow_script_movs_0x8e0c56
ow_script_movs_0x8e0c56:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8e09cc
ow_script_0x8e09cc:

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e0c5e
callstd MSG_KEEPOPEN
special 0xF

showsprite 0x2c
showsprite 0x2d
applymovement 0x2c ow_script_movs_0x8e0c56
applymovement 0x2d ow_script_movs_0x8e0c56
waitmovement 0x0
applymovement 0x2a ow_script_movs_0x8e162b
waitmovement 0x0
sound 0x15
applymovement 0x29 ow_script_movs_0x8e1521
applymovement 0x2a ow_script_movs_0x8e1521
applymovement 0x2b ow_script_movs_0x8e1521
applymovement 0xff ow_script_movs_0x8e1521
waitmovement 0x0

loadpointer 0 str_polizist
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e0b99
callstd MSG_KEEPOPEN
special 0xF

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e0b24
callstd MSG
special 0xF

fadescreen 0x1
hidesprite 0x29
hidesprite 0x2a
hidesprite 0x2b
hidesprite 0x2d
fadescreen 0x0
applymovement 0xff ow_script_movs_0x8e1d9e
waitmovement 0x0
applymovement 0x2c ow_script_movs_0x8e0b21
waitmovement 0x0

loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e0aa8
callstd MSG
special 0xF

fadescreen 0x1
hidesprite 0x2c
fadescreen 0x0
setvar MERIANA_CITY_REVOLUTIONARY 3
setflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
setvar 0x8000 0x8
special2 0x8000 0xc
releaseall
end


.global ow_script_movs_0x8e1d9e
ow_script_movs_0x8e1d9e:
.byte LOOK_RIGHT
.byte STOP




.global ow_script_movs_0x8e0b21
ow_script_movs_0x8e0b21:
.byte STEP_LEFT
.byte STOP





.global ow_script_0x8e22eb
ow_script_0x8e22eb:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8e0f0b
callstd MSG_KEEPOPEN
special 0x7

loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8e0ef0
callstd MSG
special 0xF

pause 64

loadpointer 0 str_polizist
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e0e4f
callstd MSG
special 0xF

fadescreen 0x1
hidesprite 0x2a
fadescreen 0x0
applymovement 0x2b ow_script_movs_0x8e1745
applymovement 0x29 ow_script_movs_0x8e1742
waitmovement 0x0

loadpointer 0 str_revo
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8e0e17
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x2b
hidesprite 0x29
fadescreen 0x0
setvar MERIANA_CITY_REVOLUTIONARY 0x4
setflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
setvar 0x8000 0xfff2
special2 0x8000 0xc
releaseall
end


.global ow_script_movs_0x8e148b
ow_script_movs_0x8e148b:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8e147c
ow_script_0x8e147c:
applymovement 0x2a ow_script_movs_0x8e148b
waitmovement 0x0
return


.global ow_script_movs_0x8e1488
ow_script_movs_0x8e1488:
.byte STEP_UP
.byte STOP


.global ow_script_0x8e1470
ow_script_0x8e1470:
applymovement 0x2a ow_script_movs_0x8e1488
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x8e17bd

str_polizist:
	.string "Polizist"

str_revo:
	.string "Revolutionär"

str_bewohner:
	.string "Bewohner"

str_0x8e17bd:
	.autostring 35 2 "Revolutionsbewegung, was?\pDass ihr mir in die Arme lauft, ist wirklich Glück!\pIch werde euch festnehmen und hinter Gitter bringen!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEs sei denn, natürlich, wir können uns auf anderen Wegen einig werdenDOTS"
        
        
.global str_0x8e1748

str_0x8e1748:
	.autostring 35 2 "Bestechung?\nNiemals!\pWir sind Teil der Revolutionsbewegung und würden niemals unsere Ideale für Geld verkaufen!\pEher wandern wir ins Gefängnis, als selbst Teil dieser korrupten Welt zu werden!"
        
.global str_0x8e1702

str_0x8e1702:
	.autostring 35 2 "Moment, Moment!\nIst das dein Ernst?\pWillst du wirklich ins Gefängnis gehen?\pWas würde deine Familie denken?"
        
        
.global str_0x8e167c

str_0x8e167c:
	.autostring 35 2 "NunjaDOTS DOTS DOTS\pAber treten wir nicht für eine gerechtere Welt ein?\pWollen wir das alles aufgeben, um uns selbst zu retten?"
        
        
.global str_0x8e162e

str_0x8e162e:
    .autostring 35 2 "Wir sind normale Bürger, keine HeldenDOTS\pSoll jemand anderes sein Leben irgendwelchen Idealen opfernDOTS\pIch will nicht den Rest meines Lebens eingesperrt verbringen."
        
        
.global str_0x8e15cc

str_0x8e15cc:
    .autostring 35 2 "In Ordnung, Polizist!\nWir nehmen dein Angebot an.\pWenn du uns laufen lässt, werden wir dich dafür entlohnen!"

str_police_laughs:
	.autostring 35 2 "Haha! So weit ist es also her mit euren noblen Zielen.\pWer kann es euch verübeln?\pDas ist, wie die Welt funktioniertDOTS DOTS DOTS"
        
        
.global str_0x8e14fb

str_0x8e14fb:
    .autostring 35 2 "He! Da belauscht uns jemand!"
        
        
.global str_0x8e148e

str_0x8e148e:
    .autostring 35 2 "Oh je! Ein Zeuge!\nDOTS DOTS DOTS\pWas mache ich nun bloß mit dir?"
        
        
.global str_0x8e12f8

str_0x8e12f8:
	.autostring 35 2 "Du bist noch ein Kind, also lass mich dir begreiflch machen, wie unsere Welt eigentlich funktioniert.\pGanz oben stehen die Mächte, die Top Vier und ihr Champion.\pGemeinsam herrschen sie über Theto, wie immer es ihnen beliebt.\pUnd wir, die Polizei, bieten den Menschen im Gegenzug für diese Macht unseren Schutz.\pIst das nicht auch eine Form von Gerechtigkeit?\pSelbstverständlich, ist nicht alles in diesem System perfekt.\pSicherlich gibt es Ungerechtigkeiten hier und da."

.global str_0x8e11b9

str_0x8e11b9:
    .autostring 35 2 "Allerdings, wie sähe eine Welt aus, wie diese beiden Revolutionskämpfer sie sich wünschen?\pJeder dürfte tun und lassen, was immer er möchte.\pNiemand wäre mehr sicher.\nDOTS DOTS DOTS\pAnarchie und Chaos würden über unsere Welt hereinbrechen."


str_0x8e0f79:
	.autostring 35 2 "Und jetzt sag mir ehrlich, ob Menschen wie ich wirklich das Übel in dieser Welt sind oder nicht ein viel größeres Übel verhindern.\pWas sagst du, Kind?"
        
        
.global str_meriana_revo_choice_0

str_meriana_revo_choice_0:
    .string "Zustimmen"
        
        
.global str_meriana_revo_choice_1

str_meriana_revo_choice_1:
    .string "Widersprechen"
        
        
.global str_0x8e0cdc

str_0x8e0cdc:
    .autostring 35 2 "Sie haben Unrecht!\nSich einfach hilflos dem System auszuliefern, ist keine Lösung.\pJeder muss selbst daran arbeiten, die Welt zu einem besseren Ort zu machen.\pIch werde Sie nicht mit ihren korrupten Geschäften durchkommen lassen!"
        
        
.global str_0x8e0c9c

str_0x8e0c9c:
    .autostring 35 2 "Verdammtes Gör!\nDu bist eben doch nur ein naives Kind!\pAlso muss ich doch wohl oder übel bekämpfen!"
        
        
.global str_0x8e0c71

str_0x8e0c71:
    .autostring 35 2 "Verflucht! DOTS DOTS DOTS"
        
        
.global str_0x8e0c5e

str_0x8e0c5e:
    .autostring 35 2 "Du einfältiges Kind!\pDenkst du, dass es klug ist, sich mit der Polizei anzulegen!"
        
        
.global str_0x8e0b99

str_0x8e0b99:
	.autostring 35 2 "Wachtmeister!\pIch wurde über Ihre korrupten Aktivitäten unterrichtet und wollte es nicht fassen.\pJetzt muss ich es jedoch mit eigenen Augen sehen!\pUngeheuerlich!\pSie sind verhaftet, alle drei!"
        
.global str_0x8e0b24

str_0x8e0b24:
    .autostring 35 2 "Verlogener Kerl!\pAls hättest du nicht selbst genauso viel Dreck am Stecken!\pAber ich werde keinen Widerstand leisten.\pSoll doch jemand anders sich um diese Welt kümmern DOTS DOTS DOTS"
        
.global str_0x8e0aa8

str_0x8e0aa8:
    .autostring 35 2 "Danke dir tausend Mal!\pEndlich hat jemand diesen korrupten Wachtmeister zur Strecke gebracht.\pWenn es auch ein kleiner Beitrag war, hast du diese Stadt zu einem besseren Ort gemacht.\pWir Bewohner stehen alle in deiner Schuld."
        
        
.global str_0x8e0f0b

str_0x8e0f0b:
    .autostring 35 2 "Vermutlich haben Sie RechtDOTS\pLassen Sie wenigstens die Revolutionäre laufen, wenn Sie selbst nicht den Schneid aufbringen können, etwas zum Besseren wenden zu wollen."
        
        
.global str_0x8e0ef0

str_0x8e0ef0:
    .autostring 35 2 "Du bist nicht dumm, Kind.\pDu wirst sicher auch irgendwann merken, dass es nicht immer leicht ist, etwas zum Besseren zu wenden."
        
.global str_0x8e0e4f

str_0x8e0e4f:
    .autostring 35 2 "Ganz im VertrauenDOTS\pEs ist nicht ratsam, sich mit den Top Vier oder denen, die ihnen unterstellt sind, anzulegen.\pSei klug genug, meinen Rat zu beherzigenDOTS DOTS DOTS"
        
.global str_0x8e0e17

str_0x8e0e17:
    .autostring 35 2 "Schnell, machen wir nuns aus dem Staub!"
        
        
.elseif LANG_EN

.endif
