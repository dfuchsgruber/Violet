.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "story_states.s"
.include "mugshot.s"


.global ow_script_movs_0x8037d4
ow_script_movs_0x8037d4:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8f4d2c
ow_script_movs_0x8f4d2c:
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8f4b78
ow_script_movs_0x8f4b78:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8f4ab5
ow_script_movs_0x8f4ab5:
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x8fa8f3
ow_script_0x8fa8f3:
lockall
applymovement 0xff ow_script_movs_0x8037d4
waitmovement 0x0
settrainerflag 0x4a
settrainerflag 0x4b
settrainerflag 0x4c
lockall
playsong MUS_VIOLET_ENCOUNTER 0x0
setvar SONG_OVERRIDE MUS_VIOLET_ENCOUNTER
special 0x113
applymovement 0x7f ow_script_movs_0x8f4d2c
waitmovement 0x0
special 0x114
loadpointer 0x0 str_0x8f4c85
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8f4c4b
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
loadpointer 0x0 str_0x8f4b7b
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
applymovement 0x1e ow_script_movs_0x8f4b78
waitmovement 0x0
pause 0x38
loadpointer 0x0 str_0x8f4aee
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
loadpointer 0x0 str_0x8f4ab8
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
applymovement 0x1e ow_script_movs_0x8f4ab5
waitmovement 0x0
loadpointer 0x0 str_0x8f49f3
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
loadpointer 0x0 str_0x8f49c5
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8f48ca
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
loadpointer 0x0 str_0x8f4823
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8f4755
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
loadpointer 0x0 str_0x8f46fc
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
goto ow_script_0x8f5143


.global ow_script_movs_0x8f5a91
ow_script_movs_0x8f5a91:
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8f5a8d
ow_script_movs_0x8f5a8d:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8f505f
ow_script_movs_0x8f505f:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8f5140
ow_script_movs_0x8f5140:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8f52c0
ow_script_movs_0x8f52c0:
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8f52c4
ow_script_movs_0x8f52c4:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8f5143
ow_script_0x8f5143:
getplayerpos 0x8000 0x8001
compare 0x8001 0x12
callif EQUAL ow_script_0x8f5a94
compare 0x8001 0x14
callif EQUAL ow_script_0x8f5aa3
applymovement 0xff ow_script_movs_0x8f5a91
waitmovement 0x0
sound 0x15
applymovement 0x1e ow_script_movs_0x8f5a8d
applymovement 0x1f ow_script_movs_0x8f5a8d
applymovement 0x20 ow_script_movs_0x8f5a8d
applymovement 0x5 ow_script_movs_0x8f5a8d
draw_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8f5a63
callstd MSG
waitmovement 0x0
hide_mugshot
loadpointer 0x0 str_0x8f59e8
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
applymovement 0x5 ow_script_movs_0x8f505f
waitmovement 0x0
draw_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8f59cf
callstd MSG
applymovement 0x5 ow_script_movs_0x8f5140
loadpointer 0x0 str_0x8f56b8
callstd MSG
hide_mugshot
loadpointer 0x0 str_0x8f5628
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8f5514
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8f5425
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8f52c9
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
applymovement 0x20 ow_script_movs_0x8f52c0
applymovement 0x1f ow_script_movs_0x8f52c4
waitmovement 0x0
trainerbattlecont 0x1 0x4a 0x0 str_0x8f523b str_0x8f527b ow_script_0x8f5cdf


.global ow_script_0x8f5cdf
ow_script_0x8f5cdf:
loadpointer 0x0 str_0x8f5f96
callstd MSG
trainerbattlecont 0x1 0x4b 0x0 str_0x8f5f21 str_0x8f5f57 ow_script_0x8fa888


.global ow_script_movs_0x8f5eb0
ow_script_movs_0x8f5eb0:
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8f5eb4
ow_script_movs_0x8f5eb4:
.byte LOOK_UP
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8f5eac
ow_script_movs_0x8f5eac:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8fa888
ow_script_0x8fa888:
loadpointer 0x0 str_0x8f5edb
callstd MSG
loadpointer 0x0 str_0x8f5eb8
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
applymovement 0x20 ow_script_movs_0x8f5eb0
applymovement 0x1f ow_script_movs_0x8f5eb4
waitmovement 0x0
applymovement 0x5 ow_script_movs_0x8f5eac
waitmovement 0x0
pause 0x20
draw_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
setvar BATTLE_SONG_OVERRIDE MUS_KAMPF_GEGEN_ARENALEITER_HOENN
trainerbattlecont 0x1 0x4c 0x0 str_0x8f5d92 str_0x8f5d31 ow_script_0x8fab2c


.global ow_script_movs_0x8f6d19
ow_script_movs_0x8f6d19:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8f6d16
ow_script_movs_0x8f6d16:
.byte LOOK_UP_DELAYED
.byte LOOK_DOWN_DELAYED
.byte STOP


.global ow_script_movs_0x8f6cf5
ow_script_movs_0x8f6cf5:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8f6c01
ow_script_movs_0x8f6c01:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT_FAST
.byte STOP


.global ow_script_movs_0x8f6bfe
ow_script_movs_0x8f6bfe:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8f6be5
ow_script_movs_0x8f6be5:
.byte STEP_UP_FAST
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8f6a5d
ow_script_movs_0x8f6a5d:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8f6ae2
ow_script_movs_0x8f6ae2:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8f68a4
ow_script_movs_0x8f68a4:
.byte LOOK_RIGHT
.byte SAY_QUESTION
.byte STOP


.global ow_script_0x8fab2c
ow_script_0x8fab2c:
setvar SONG_OVERRIDE 0
applymovement 0xff ow_script_movs_0x8f6d19
waitmovement 0x0
clearflag TRANS_DISABLE
loadpointer 0x0 str_0x8fa9e7
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
applymovement 0x5 ow_script_movs_0x8f6d16
waitmovement 0x0
loadpointer 0x0 str_0x8f6cfb
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
fadescreen 0x1
hidesprite 0x5
hidesprite 0x1f
hidesprite 0x20
hidesprite 0xd
hidesprite 0x9
hidesprite 0x6
hidesprite 0xf
fadescreen 0x0
playsong VERTANIA_WALD_AND_BEERENFORST_AND_MUSTERBUSCHWALD_AND_DIGDAS_HOHLE_AND_SEESCHAUMINSELN 0
applymovement 0x1e ow_script_movs_0x8f6cf5
waitmovement 0x0
loadpointer 0x0 str_0x8f6c09
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
clearflag PKMNMENU
showsprite 0x24
applymovement 0x24 ow_script_movs_0x8f6c01
waitmovement 0x0
sound 0x15
applymovement 0x24 ow_script_movs_0x8f6bfe
waitmovement 0x0
loadpointer 0x0 str_0x8f6be9
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
applymovement 0x1e ow_script_movs_0x8f6be5
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8f6a5d
waitmovement 0x0
loadpointer 0x0 str_0x8f6bb4
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
loadpointer 0x0 str_0x8f6b22
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
draw_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
loadpointer 0x0 str_0x8f6ae5
callstd MSG
applymovement 0x1e ow_script_movs_0x8f6ae2
waitmovement 0x0
loadpointer 0x0 str_0x8f6a60
callstd MSG
hide_mugshot
applymovement 0x24 ow_script_movs_0x8f6ae2
waitmovement 0x0
loadpointer 0x0 str_0x8f68d7
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
draw_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
loadpointer 0x0 str_0x8f68a8
callstd MSG_KEEPOPEN
sound 0x15
applymovement 0x24 ow_script_movs_0x8f68a4
applymovement 0xff ow_script_movs_0x8f68a4
waitmovement 0x0
loadpointer 0x0 str_0x8f6749
callstd MSG
hide_mugshot
loadpointer 0x0 str_0x8f6725
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x8f6626
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT MSG_KEEPOPEN
applymovement 0x24 ow_script_movs_0x8f6ae2
applymovement 0xff ow_script_movs_0x8f6a5d
waitmovement 0x0
loadpointer 0x0 str_0x8f65b0
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x8f64bc
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8f6465
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
fadescreen 0x1
hidesprite 0x24
hidesprite 0x1e
fadescreen 0x0
addvar STORY_PROGRESS 0x1
setvar STORY_STATE STORY_STATE_SILVANIA_FOREST_CLEAR
releaseall
end


.global ow_script_movs_0x8f5aaf
ow_script_movs_0x8f5aaf:
.byte STEP_UP
.byte STOP


.global ow_script_0x8f5aa3
ow_script_0x8f5aa3:
applymovement 0xff ow_script_movs_0x8f5aaf
waitmovement 0x0
return


.global ow_script_movs_0x8f5aa0
ow_script_movs_0x8f5aa0:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8f5a94
ow_script_0x8f5a94:
applymovement 0xff ow_script_movs_0x8f5aa0
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x8f4c85

str_0x8f4c85:
	.autostring 35 2 "Wir werden sowieso aus Ihnen herausbekommen, was wir wissen wollen, Professor.\pErsparen Sie sich das und kooperieren Sie!"
        
        
.global str_0x8f4c4b

str_0x8f4c4b:
	.autostring 35 2 "In Ordnung!\pDOTS DOTS DOTS\pIn Ordnung DOTS\nAber tun Sie mir bitte nichts DOTS"
        
        
.global str_0x8f4b7b

str_0x8f4b7b:
	.autostring 35 2 "Sie haben kein Rückgrat, Professor Primus!\pHahaha!\pBrav von Ihnen!\nNun sagen Sie mir, was es mit dem Zeitstein und diesem seltsamen Schrein hier auf sich hat!"
        
        
.global str_0x8f4aee

str_0x8f4aee:
	.autostring 35 2 "Ich DOTS weiß nicht viel DOTS\pDer Zeitstein enthält das Herz der Zeit.\pDurch seine Energie bleibt der Fluss der Zeit erhalten DOTS"
        
        
.global str_0x8f4ab8

str_0x8f4ab8:
    .autostring 35 2 "Überaus spannend, Ihre Mythologiestunde, Professorchen!\pMich interessiert, wo ich diesen Zeitstein finden kann.\pDas wissen Sie doch auch, nicht?\pDie Inschriften auf dem Schrein DOTS DOTS DOTS\pJemand wie Sie müsste die Icognito-Zeichen doch lesen können!"
        
        
.global str_0x8f49f3

str_0x8f49f3:
    .autostring 35 2 "Ja schon DOTS DOTS DOTS\pAber ich habe seit dem Studium nichts mehr in dieser Sprache gelesen DOTS"
        
        
.global str_0x8f49c5

str_0x8f49c5:
    .autostring 35 2 "Ich denke nicht, dass ich Ihnen klar machen muss, was für Sie auf dem Spiel steht!\pSagen Sie mir, was auf dem Schrein geschrieben steht und zwar flott!"
        
        
.global str_0x8f48ca

str_0x8f48ca:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDer Text handelt von einem Pokémon namens Celebi.\pEs hatte ursprünglich die Aufgabe, den Zeitstein zu bewachen.\pAber DOTS DOTS DOTS\pDOTS DOTS DOTS\nDOTS da ist noch ein zweiter Text DOTS"

.global str_0x8f4823

str_0x8f4823:
    .autostring 35 2 "Ein zweiter Text?\nWie spannend!\pNa dann raus mit der Sprache, Professorchen!"
        
.global str_0x8f4755

str_0x8f4755:
    .autostring 35 2 "Die Zeichen scheinen erst vor einiger Zeit geschrieben worden zu sein DOTS\pLaut der Inschrift bewacht Celebi den Zeitstein nicht länger DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pStattdessen wurde der Zeitstein gespalten und den drei Wächtern Thetos anvertraut DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDas ist DOTS\nalles, denke ich DOTS"
        
.global str_0x8f46fc

str_0x8f46fc:
	.autostring 35 2 "Verdammt noch eins!\nDass die Dinge immer kompliziert werden müssen.\pNicht nur, dass der Stein gespalten wurde DOTS\pDOTS sondern er wird auch noch bewacht DOTS"
        
        
.global str_0x8f5a63

str_0x8f5a63:
    .autostring 35 2 "Ihr da!\nLasst den Professor in Frieden!"
        
        
.global str_0x8f59e8

str_0x8f59e8:
    .autostring 35 2 "Arceus sei Dank!\nEin Trainer!\pBitte, hilf mir!\nDiese Frau DOTS\lDOTS ist eine Kommandantin von Team Violet.\pSie ist gefährlich!\pHilf mir!"
        
        
.global str_0x8f59cf

str_0x8f59cf:
    .autostring 35 2 "Halt den Rand, Professorchen!"
        
        
.global str_0x8f56b8

str_0x8f56b8:
	.autostring 35 2 "Was haben wir denn da?\pEin Kind, das sich in die Angelegenheiten von Team Violet einmischt.\pMein Name ist Rin und ich bin Kommandantin der zweiten Division von Team Violet.\pBist du dir sicher, dass du dich mit mir anlegen möchtest?\pWenn wir die Energie des Zeitsteins nutzbar gemacht haben, werden wir eine unendlich todbringende Waffe besitzen, um den Kontinent zu unterwerfen.\pSich unserer Organisation in den Weg zu stellen, kann übel ausgehen, Kindchen!"
        
.global str_0x8f5628

str_0x8f5628:
	.autostring 35 2 "Mir ist völlig gleichgültig, wer Sie sind, oder was sie vorhaben.\pWenn Sie Menschen wie den Professor bedrängen, werde ich mich euch in den Weg stellen!"
        
.global str_0x8f5514

str_0x8f5514:
	.autostring 35 2 "Du hast Mum, Rotznase!\pAber du weißt nicht, was gut für dich ist.\pUnser Plan ist in vollem Gange.\pWir sind nicht aufzuhalten.\pJemand wie du ist meine Aufmerksamkeit nicht wert."
        
.global str_0x8f5425

str_0x8f5425:
    .autostring 35 2 "Ich werde jeden von euch besiegen!\pUnd auch dir werde ich das Handwerk legen!"

.global str_0x8f52c9

str_0x8f52c9:
    .autostring 35 2 "Genug jetzt!\pDummes Kind!\pIhr da, macht die Rotznase fertig!"
        
.global str_0x8f523b

str_0x8f523b:
    .autostring 35 2 "Du kannst mir schon fast leid tun.\pSich mit Rin anzulegen ist nie eine gute Idee!"
        
        
.global str_0x8f527b

str_0x8f527b:
    .autostring 35 2 "Na und?\nDann habe ich eben verloren.\pGegen Rin wirst du ohnehin nicht gewinnen, du naives Balg!"
        
        
.global str_0x8f5f96

str_0x8f5f96:
    .autostring 35 2 "Ich DOTS DOTS\nDOTS es tut mir leid, Rin DOTS"
        
        
.global str_0x8f5f21

str_0x8f5f21:
    .autostring 35 2 "Eines Tages werden wir über die Welt herrschen!\pUnd dafür werde ich bis zum bitteren Ende kämpfen!"
        
        
.global str_0x8f5f57

str_0x8f5f57:
    .autostring 35 2 "Du hast mehr auf dem Kasten, als es scheint.\pAber Rin ist eine Nummer zu groß für dich!"
        
        
.global str_0x8f5edb

str_0x8f5edb:
    .autostring 35 2 "Das Kind DOTS DOTS DOTS\nDOTS ist kein Anfänger DOTS"
        
        
.global str_0x8f5eb8

str_0x8f5eb8:
    .autostring 35 2 "Ihr seid erbärmliche Gestalten!\pIch sollte euch in Mistrals Division verweisen.\pBeiseite, ihr Pappnasen!"
        
        
.global str_0x8f5d92

str_0x8f5d92:
	.autostring 35 2 "Vielleicht bist du doch ein interessanter Gegner.\pAber du musst wissen, dass ich auch gegen ein Kind ohne Skrupel kämpfen werde.\pDu hättest diese Dinge den Erwachsenen überlassen sollen.\pJetzt bezahlst du den Preis für deinen Heldenmut!"
        
.global str_0x8f5d31

str_0x8f5d31:
    .autostring 35 2 "Ich DOTS DOTS DOTS\nDOTS wurde von einem Kind besiegt?"
        
        
.global str_0x8fa9e7

str_0x8fa9e7:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pIch habe dich wohl unterschätzt.\pDu bist ein ernstzunehmender Gegner.\pBeim unserem nächsten Aufeinandertreffen, werde ich mich nicht so überrumpeln lassen.\pWir haben ohnehin erfahren, was wir wissen wollten."
        
.global str_0x8f6cfb

str_0x8f6cfb:
    .autostring 35 2 "Wir ziehen ab, los!"
        
        
.global str_0x8f6c09

str_0x8f6c09:
	.autostring 35 2 "Oh bei Arceus, ich danke dir!\pTausend Mal danke danke danke!\pIch bin gerettet.\pBereits seit Tagen halten mich diese Rüpel fest und schikanieren mich.\pIch dachte, es wäre aus mit mir."
        
        
.global str_0x8f6be9

str_0x8f6be9:
    .autostring 35 2 "Papa! Papa!"
        
        
.global str_0x8f6bb4

str_0x8f6bb4:
    .autostring 35 2 "Elise!\nWas tust du denn hier?"
        
        
.global str_0x8f6b22

str_0x8f6b22:
	.autostring 35 2 "Ich habe mir solche Sorgen um dich gemacht.\pAls mir Professor Tann von deinem Verschwinden erzählt hat DOTS\pDOTS ich DOTS\nDOTS DOTS DOTS\pDOTS wäre vor Sorge fast umgekommen!"
        
.global str_0x8f6ae5

str_0x8f6ae5:
    .autostring 35 2 "Keine Sorge, ich bin jetzt wohlauf, mein Schatz!"
        
        
.global str_0x8f6a60

str_0x8f6a60:
    .autostring 35 2 "Und das alles dank meinem Retter hier.\pDieses Kind hat einen Kommandanten von Team Violet geschlagen!\pWie lautet eigentlich dein Name?"
        
        
.global str_0x8f68d7

str_0x8f68d7:
    .autostring 35 2 "Wirklich PLAYER?\nDas ist fantastisch!\pSich mit solchen Menschen anzulegen, erfordert Mut!\pDu verblüffst mich aufs Neue!\pDanke dir, PLAYER!\nVon ganzem Herzen danke, dass du meinen Vater gerettet hast!"
        
.global str_0x8f68a8

str_0x8f68a8:
    .autostring 35 2 "DOTS DOTS DOTS\nAllerdings DOTS"
        
        
.global str_0x8f6749

str_0x8f6749:
    .autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS scheinen diese Verbrecher es auf den Diserakt, auch Zeitstein genannt, abgesehen zu haben."
        
.global str_0x8f6725

str_0x8f6725:
    .autostring 35 2 "Diserakt?\nWas ist das?"
        
        
.global str_0x8f6626

str_0x8f6626:
    .autostring 35 2 "Der Diserakt ist ein Stein, von dem ich bislang geglaub habe, dass er nur in Legenden existiert.\pDas Herz der Zeit soll in ihm schlagen.\pUnd er beinhaltet eine imense Energiemenge, für den, der ihn nutzbar machen kann.\pUnd darauf scheint es Team Violet abgesehen zu haben."


.global str_0x8f65b0

str_0x8f65b0:
    .autostring 35 2 "PLAYER DOTS\nWirst du Team Violet weiter verfolgen?"
        
        
.global str_0x8f64bc

str_0x8f64bc:
    .autostring 35 2 "Rin hat gedroht, mit der Energie des Zeitsteins eine zerstörerische Waffe zu erschaffen.\pWenn ihr das gelingt, wird Team Violet vielleicht die Herrschaft über Theto erlangen.\pDas werde ich nicht zulassen!"
        
.global str_0x8f6465

str_0x8f6465:
    .autostring 35 2 "Das hatte ich mir gedacht DOTS\pAber lass dir deinen Sieg über Rin nicht zu Kopf wachsen.\pDie Top Vier sollen sich dieser Bedrohung stellen, das ist ihre Aufgabe!\pIch habe zwar Vertrauen in deine Fähigkeiten, aber sei vorsichtig!\pEs scheint, als wäre mit Team Violet nicht zu spaßen DOTS"

.elseif LANG_EN

.endif
