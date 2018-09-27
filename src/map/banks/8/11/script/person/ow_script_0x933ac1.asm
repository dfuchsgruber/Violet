.include "callstds.s"
.include "flags.s"
.include "movements.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x933e11
ow_script_movs_0x933e11:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x933e0d
ow_script_movs_0x933e0d:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x933c58
ow_script_movs_0x933c58:
.byte STEP_UP
.byte STEP_UP
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x933c5d
ow_script_movs_0x933c5d:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x933ac1
ow_script_0x933ac1:
checkflag KASKADA_BLACKMARKET_PRIMUS
gotoif LESS ow_script_0x933fe1
checkflag KASKADA_BLACKMARKET_BLAISE
gotoif LESS ow_script_0x933fe1
checkflag KASKADA_BLACKMARET_BB_SHIP
gotoif LESS ow_script_0x933fe1
lock
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x933f08
callstd MSG
special 0x7
showsprite 0x1d
showsprite 0x1e
showsprite 0x1f
setflag PKMNMENU
applymovement 0x1d ow_script_movs_0x933e11
applymovement 0x1e ow_script_movs_0x933e11
applymovement 0x1f ow_script_movs_0x933e11
waitmovement 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x933e0d
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x933c60
callstd MSG
special 0x7
applymovement 0x1d ow_script_movs_0x933c58
waitmovement 0x0
applymovement 0xff ow_script_movs_0x933c5d
waitmovement 0x0
goto ow_script_0x935a41


.global ow_script_0x935a41
ow_script_0x935a41:
setflag BLACKOUT_BYPASS
loadpointer 0 str_revolutionary
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x933bb4
callstd MSG
trainerbattlelosable 0x9 0x73 0x0 str_0x933c29 str_0x935b22
goto ow_script_0x936ffe


.global ow_script_movs_0x935b64
ow_script_movs_0x935b64:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x935c46
ow_script_movs_0x935c46:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x937090
ow_script_movs_0x937090:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


.global ow_script_0x936ffe
ow_script_0x936ffe:
clearflag BLACKOUT_BYPASS
applymovement 0xff ow_script_movs_0x935b64
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x93661f
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x935c46
waitmovement 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x9365b7
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x935b64
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x9362bd
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x1d
hidesprite 0x1e
hidesprite 0x1f
fadescreen 0x0
applymovement 0xff ow_script_movs_0x935c46
waitmovement 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x9360fc
callstd MSG
special 0x7
applymovement 0x20 ow_script_movs_0x937090
waitmovement 0x0
hidesprite 0x20
releaseall
end


.global ow_script_0x933fe1
ow_script_0x933fe1:
lock
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x9359bb
callstd MSG
special 0x7
release
end


.ifdef LANG_GER

str_revolutionary:
	.string "Revolutionär"

.global str_0x933f08

str_0x933f08:
	.autostring 35 2 "Siehst du, was für ein abgrund hier unterhalb dieser schönen Stadt liegt?\pHier floriert die Krimialität wie nirgends sonst.\pUnd all das wird von den Top Vier tolleriert.\pDieser Markt befindet sich unter der Obhut von Devin, einem Mitglied der Pokémon-Liga."
        
.global str_0x933c60

str_0x933c60:
	.autostring 35 2 "Igva und DOTS\nPLAYER!\pWie klein die Welt doch ist, dass ihr euch iher begegnet.\pAuch wenn ich jemanden wie PLAYER hier nicht erwartet hätte.\pIgva versucht wohl, dich auf unsere Seite zu bringen.\pDu solltest deine Entscheidung aber nicht überstürzen, PLAYER.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu willst mich herausfordern?\pDenkst du denn, dass du es mit mir aufnehmen kannst?\pVersuch dich doch erst einmal an ihm hier, dann werden wir sehen, ob du für einen Kampf gegen mich bereit bist DOTS"

        
.global str_0x933bb4

str_0x933bb4:
	.autostring 35 2 "Ich werde alles tun, was in meiner Macht steht, um diese Welt zu einem besseren Ort zu machen."
        
        
.global str_0x933c29

str_0x933c29:
    .autostring 35 2 "Vergebt mir, Albus DOTS\nIch war zu schwach DOTS"
        
        
.global str_0x935b22

str_0x935b22:
    .string "Lord Albus, ich habe das Kind besiegt!"
        
        
.global str_0x93661f

str_0x93661f:
	.autostring 35 2 "Du kämpfst nicht schlecht, PLAYER.\pAber bis du dich mit jemandem wie mir anlegen kannst, musst du noch viel an dir arbeiten.\pIch will dir einen Ratschlag mitgeben.\pDu solltest nicht leichtfertig Leute herausfordern, die dir offensichtlich überlegen sind.\pSo etwas kann schnell ins Auge gehen und nicht jeder ist dir so freundlich gesinnt, wie ich es bin.\pDOTS DOTS DOTS\pAußerdem DOTS\pWürde ich dich viel lieber in unseren Reihen begrüßen, anstatt mit dir zu kämpfen.\pMein Angebot, dich uns anzuschließen, steht noch immer."
        
.global str_0x9365b7

str_0x9365b7:
    .string "PLAYER! Schließe dich\nunserer Sache an!\pLord Albus wird dich unterweisen,\ndu wirst Großes bewirken!"
        
        
.global str_0x9362bd

str_0x9362bd:
	.autostring 35 2 "Nichts überstürzen, Igva.\pIch will PLAYER nicht zu einer unüberlegten Narrheit zwingen.\pLass dir ruhig Zeit mit deiner Entscheidung.\pWenn es aber darauf ankommt, musst du ohne zu zögern hinter deinem Entschluss stehne können.\pBehalte das im Kopf, PLAYER."

.global str_0x9360fc

str_0x9360fc:
	.autostring 35 2 "PLAYER DOTS\nSiehst du, was für ein großartiger Mensch Albus ist?\pEr hätte dich mit Leichtigkeit besiegen können, doch obwohl du ihn herausgefordert hast, hat er dich verschont.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch werde seinen Worten folge leisten und dich ziehen lassen.\pLass dein Herz dir sagen, auf wessen Seite du in diesem Konflikt stehen willst.\pWenn du noch mehr von der dunklen Seite Thetos sehen willst, solltest du Manus, den Arenaleiter von Meriana City herausfordern.\pAuf Wiedersehen, PLAYER."
        
.global str_0x9359bb

str_0x9359bb:
	.autostring 35 2 "PLAYER, sieh dich doch ruhig etwas um."
        
.elseif LANG_EN

.endif
