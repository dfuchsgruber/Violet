.include "overworld_script.s"

.include "std.s"

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
loadpointer 0x0 str_0x8e17bd
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e1748
callstd MSG_KEEPOPEN
applymovement 0x2b ow_script_movs_0x8e1745
applymovement 0x29 ow_script_movs_0x8e1742
waitmovement 0x0
loadpointer 0x0 str_0x8e1702
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e167c
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e162e
callstd MSG_KEEPOPEN
applymovement 0x2b ow_script_movs_0x8e162b
applymovement 0x29 ow_script_movs_0x8e162b
waitmovement 0x0
loadpointer 0x0 str_0x8e15cc
callstd MSG_KEEPOPEN
sound 0x15
applymovement 0x2a ow_script_movs_0x8e162b
waitmovement 0x0
applymovement 0x29 ow_script_movs_0x8e1521
applymovement 0x2a ow_script_movs_0x8e1521
applymovement 0x2b ow_script_movs_0x8e1521
waitmovement 0x0
loadpointer 0x0 str_0x8e14fb
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e148e
callstd MSG_KEEPOPEN
getplayerpos 0x8000 0x8001
compare 0x8001 0x1e
callif EQUAL ow_script_0x8e1470
compare 0x8001 0x20
callif EQUAL ow_script_0x8e147c
applymovement 0x2a ow_script_movs_0x8e146d
waitmovement 0x0
loadpointer 0x0 str_0x8e12f8
callstd MSG_KEEPOPEN
applymovement 0x2a ow_script_movs_0x8e1841
waitmovement 0x0
loadpointer 0x0 str_0x8e11b9
callstd MSG_KEEPOPEN
applymovement 0x2a ow_script_movs_0x8e162b
loadpointer 0x0 str_0x8e0f79
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
goto ow_script_0x8f6e54

.align 4
meriana_revo_choice:
    .word str_meriana_revo_choice_0, 0
    .word str_meriana_revo_choice_1, 0
    


.global ow_script_0x8f6e54
ow_script_0x8f6e54:
loadpointer 0x0 meriana_revo_choice
goto ow_script_0x8e1b14


.global ow_script_0x8e1b14
ow_script_0x8e1b14:
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8e22eb
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8e0cdc
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x2c 0x0 str_0x8e0c9c str_0x8e0c71 ow_script_0x8e09cc


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
loadpointer 0x0 str_0x8e0c5e
callstd MSG_KEEPOPEN
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
loadpointer 0x0 str_0x8e0b99
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x8e0b24
callstd MSG
fadescreen 0x1
hidesprite 0x29
hidesprite 0x2a
hidesprite 0x2b
hidesprite 0x2d
fadescreen 0x0
goto ow_script_0x8e1b5e


.global ow_script_movs_0x8e1d9e
ow_script_movs_0x8e1d9e:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8e1b5e
ow_script_0x8e1b5e:
applymovement 0xff ow_script_movs_0x8e1d9e
waitmovement 0x0
goto ow_script_0x8e1da1


.global ow_script_movs_0x8e0b21
ow_script_movs_0x8e0b21:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8e1da1
ow_script_0x8e1da1:
applymovement 0x2c ow_script_movs_0x8e0b21
waitmovement 0x0
loadpointer 0x0 str_0x8e0aa8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_HYPERTRANK
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8e0a79
callstd MSG
fadescreen 0x1
hidesprite 0x2c
fadescreen 0x0
setvar MERIANA_CITY_REVOLUTIONARY 0x80
setflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
setvar 0x8000 0x8
special2 0x8000 0xc
releaseall
end


.global ow_script_0x8e22eb
ow_script_0x8e22eb:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8e0f0b
callstd MSG_KEEPOPEN
special 0x7
loadpointer 0x0 str_0x8e0ef0
callstd MSG_KEEPOPEN
sound 0x41
givemoney 0x5dc 0x0
loadpointer 0x0 str_0x8e0edc
callstd MSG_KEEPOPEN
checksound
loadpointer 0x0 str_0x8e0e4f
callstd MSG
fadescreen 0x1
hidesprite 0x2a
fadescreen 0x0
applymovement 0x2b ow_script_movs_0x8e1745
applymovement 0x29 ow_script_movs_0x8e1742
waitmovement 0x0
loadpointer 0x0 str_0x8e0e17
callstd MSG
fadescreen 0x1
hidesprite 0x2b
hidesprite 0x29
fadescreen 0x0
setvar MERIANA_CITY_REVOLUTIONARY 0x7f
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

.global str_0x8e17bd

str_0x8e17bd:
    .string "Polizist Marq: Gut, ich lasse euch\nlaufen, dieses Mal. Vorausgesetzt,\lihr könnt mich entsprechend\lentlohnen, wie sich versteht..."
        
        
.global str_0x8e1748

str_0x8e1748:
    .string "Mann: Wir sind Revolutionäre. Wir\nverhandeln nicht mit\lEuresgleichen. Wir werden euer\lSystem zum Einsturz bringen!"
        
        
.global str_0x8e1702

str_0x8e1702:
    .string "Mann: Hey, warte mal. Willst du\nwirklich ins Gefängnis gehen?"
        
        
.global str_0x8e167c

str_0x8e167c:
    .string "Mann: Kämpfen wir nicht für\nIdeale? Für eine Welt der\lGerechtigkeit und ohne Korruption?\lWollen wir wirklich unsere Werte\lverraten?"
        
        
.global str_0x8e162e

str_0x8e162e:
    .string "Mann: Mach, was du willst. Ich\nwerde mein Leben nicht einfach so\lwegwerfen."
        
        
.global str_0x8e15cc

str_0x8e15cc:
    .string "Wir nehmen dein Angebot an,\nPolizist. Wir werden dich\lbezahlen, wenn du uns passieren\llässt."
        
        
.global str_0x8e14fb

str_0x8e14fb:
    .string "Mann: Hey, da belauscht uns\njemand!"
        
        
.global str_0x8e148e

str_0x8e148e:
    .string "Marq: Hach, wie unerfreulich, ein\nZeuge.\l...\lNun, was machen wir nun mit dir...\lWas machen wir mit dir... "
        
        
.global str_0x8e12f8

str_0x8e12f8:
    .string "Junge, du musst verstehen, wie\nunsere Welt funktioniert. An der\lSpitze, da sitzt ein einziger\lMann, der Champion, mächtig und\leinflussreich. Unter ihm die Top\lVier, die Herrscher Thetos. Und\ldann, dann kommen wir, die\leinfachen Menschen, die nichts\lhaben außer dem, was sie sich\lerarbeiten. Die Welt ist nicht\lgerecht, denn es ist die\lmenschliche Natur, Macht zu\lsuchen."
        
        
.global str_0x8e11b9

str_0x8e11b9:
    .string "Diese beiden Männer gehören den\nRevolutionären an, die das System\lder Top Vier stürzen wollen, im\lSinne einer gerechten Welt.\pSoll ich sie wirklich fangen? Soll\nich den Top Vier erlauben, ihre\lUnterdrückungsherrschaft\lforzusetzten? Oder ist es nicht\lsinnvoller, sie laufen zu lassen\lund daraus noch Profit zu ziehen?"
        
        
.global str_0x8e0f79

str_0x8e0f79:
    .string "Ich biete dir einen Anteil an.\nVerstehe meinen Standpunkt. Die\lWelt ist korrupt und wer sich der\lWelt nicht beugt, wird zerquetscht\lwie ein Käfer-Pokémon."
        
        
.global str_meriana_revo_choice_0

str_meriana_revo_choice_0:
    .string "Bestechen lassen"
        
        
.global str_meriana_revo_choice_1

str_meriana_revo_choice_1:
    .string "Widersprechen"
        
        
.global str_0x8e0cdc

str_0x8e0cdc:
    .string "Ich kann Sie nicht einfach\ndavonkommen lassen. Sie\lunterdrücken die Menschen dieser\lStadt!"
        
        
.global str_0x8e0c9c

str_0x8e0c9c:
    .string "So sei es dann der Kampf.\nBedauerlich, dass es so enden\lmuss."
        
        
.global str_0x8e0c71

str_0x8e0c71:
    .string "Dummer Junge... Du verstehst gar\nnichts!"
        
        
.global str_0x8e0c5e

str_0x8e0c5e:
    .string "Das ... Nein ..."
        
        
.global str_0x8e0b99

str_0x8e0b99:
    .string "Polizist: Wachtmeister Marq, ich\nhabe bereits von dubiosen\lAktivitäten gehört, und nun muss\lich sie mit eigenen Augen\lmiterleben! Ungeheuerlich!\lHiermit sind Sie festgenommen,\lalle drei!"
        
        
.global str_0x8e0b24

str_0x8e0b24:
    .string "Nah. Hätte ich doch den Top Vier\nmehr gedient, als meinem eigenen\lReichtum, wäre ich nun in einer\lbesseren Lage..."
        
        
.global str_0x8e0aa8

str_0x8e0aa8:
    .string "Danke, vielen Dank! Endlich\nhat jemand diesen Schurken zur\lStrecke gebracht.\lIch will mich dir erkenntlich\lzeigen."
        
        
.global str_0x8e0a79

str_0x8e0a79:
    .string "Ich stehe in deiner Schuld.\pAuf Wiedersehen!"
        
        
.global str_0x8e0f0b

str_0x8e0f0b:
    .string "... Ich werde ... Ihr Geld nehmen.\pLassen Sie die Revolutionäre\nlaufen."
        
        
.global str_0x8e0ef0

str_0x8e0ef0:
    .string "Eine weise Entscheidung."
        
        
.global str_0x8e0edc

str_0x8e0edc:
    .string "PLAYER erhält 1500 POKEDOLLAR."
        
        
.global str_0x8e0e4f

str_0x8e0e4f:
    .string "Du bist ein kluger Junge. Du\nverstehst, wie die Welt\lfunktioniert. Wir brauchen keine\lIdealisten, sondern Pragmatiker.\lWie mich, wie dich."
        
        
.global str_0x8e0e17

str_0x8e0e17:
    .string "Revolutionäre: Schnell, machen wir\nuns aus dem Staub!"
        
        