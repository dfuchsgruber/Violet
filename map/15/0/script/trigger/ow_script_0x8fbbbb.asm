.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8fbbbb
ow_script_0x8fbbbb:
lockall
sound 0x15
applymovement 0x48 ow_script_movs_0x8fbc24
waitmovement 0x0
goto ow_script_0x8bf01f


.global ow_script_movs_0x8fbc24
ow_script_movs_0x8fbc24:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8bf01f
ow_script_0x8bf01f:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf724
callstd MSG
special 0x7
setvar 0x8004 0x48
setvar LASTTALKED 0x48
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf610
callstd MSG_KEEPOPEN
multichoice 8 8 0 1
special 0x7
compare LASTRESULT 0x1
callif EQUAL ow_script_0x8bf0a0
goto ow_script_0x8bf0c1


.global ow_script_0x8bf0c1
ow_script_0x8bf0c1:
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x8bf102
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x8bf12d
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bfe09
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x2b 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


.global ow_script_0x8bf158
ow_script_0x8bf158:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf3f9
callstd MSG
special 0x7
additem ITEM_KARTE 0x1
fanfare 0x13e
loadpointer 0x0 str_0x8bf3dc
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf2f0
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x48
fadescreen 0x0
goto ow_script_0x8fb459


.global ow_script_0x8fb459
ow_script_0x8fb459:
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8bf7fb
ow_script_0x8bf7fb:
setvar 0x8000 0x0
setvar 0x8001 0x8
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8bf12d
ow_script_0x8bf12d:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bfe09
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x2a 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


.global ow_script_0x8bf102
ow_script_0x8bf102:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bfe09
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x29 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


.global ow_script_0x8bf0a0
ow_script_0x8bf0a0:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf745
callstd MSG_KEEPOPEN
special 0x7
multichoice 8 8 0 1
compare LASTRESULT 0x1
callif EQUAL ow_script_0x8bf0a0
goto ow_script_0x8bf0c1


.ifdef LANG_GER
.global str_0x8bf724

str_0x8bf724:
    .string "PLAYER!"
        
        
.global str_0x8bf610

str_0x8bf610:
    .string "So ein Zufall, dass wir uns hier\ntreffen? Bist du etwa auch auf den\lWeg nach Aktania, um deinen ersten\lArena Orden zu erringen?\lWie wäre es, wenn du mir zuerst\ldein Können unter Beweis stellst.\lSeit ich die Trainerschule\lverlassen habe, bin ich viel\lstärker geworden."
        
        
.global str_0x8bfe09

str_0x8bfe09:
    .string "Meine Pokémon sind nicht mehr zu\nbremsen!"
        
        
.global str_0x8bf5bc

str_0x8bf5bc:
    .string "Nimm dich in Acht!"
        
        
.global str_0x8bf5d1

str_0x8bf5d1:
    .string "Unglaublich wie stark du geworden\nbist! Einfach unglaublich!"
        
        
.global str_0x8bf3f9

str_0x8bf3f9:
    .string "Scheinbar hast du auch nicht\nauf der faulen Haut herumgelegen!\lDu bist wirklich ganz schön stark\lgeworden. Versuch dich doch in der\lArena von Aktania, du kannst das\lsicherlich schaffen.\lWie du dort hingelangst? Dort oben\lbetreiben zwei nette Herren namens\lNick und Rick eine Farm. Sie\lzüchten auch Vögel, die dich von\lhier nach Aktania bringen können.\lFrag die beiden doch einfach mal!\lUnd bevor ich es vergesse: Ich\lhabe ein Geschenk für dich!"
        
        
.global str_0x8bf3dc

str_0x8bf3dc:
    .string "PLAYER erhält eine Karte."
        
        
.global str_0x8bf2f0

str_0x8bf2f0:
    .string "Die Karte kann oft sehr nützlich\nsein. Wirf ruhig einen Blick\ldarauf.\pDer Kampf hat Spaß gemacht. Wir\nsehen uns, PLAYER!"
        
        
.global str_0x8bf745

str_0x8bf745:
    .string "Ich kann dich doch nicht nach\nAktania gehen lassen, ohne zu\lwissen, ob du die Arena überhaupt\lmeistern kannst.\pWas sagst du? Lass uns kämpfen!"
        
        
.elseif LANG_EN

.endif
