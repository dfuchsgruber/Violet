.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "story_states.s"

.global ow_script_0x8fa888
.global ow_script_map_1_0_trigger_0
.global ow_script_0x8f5aa3
.global ow_script_0x8f5a94
.global ow_script_0x8f5cdf
.global ow_script_0x8fab2c
.global ow_script_0x8f5143
ow_script_movs_0x8037d4:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x8f4d2c:
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8f4b78:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8f4ab5:
.byte LOOK_LEFT
.byte STOP


ow_script_map_1_0_trigger_0:
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


ow_script_movs_0x8f5a91:
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8f5a8d:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8f505f:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x8f5140:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8f52c0:
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8f52c4:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_LEFT
.byte STOP


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
special SPECIAL_CANT_DOUBLE_BATTLE
compare LASTRESULT 0
gotoif NOT_EQUAL cant_double_battle
// Can double battle
setvar LASTTALKED 0
trainerbattletwotrainers 0x4a 0x4b 0 str_0x8f523b str_0x8f527b str_0x8f5f57 ow_script_0x8fa888
end

cant_double_battle:
setvar LASTTALKED 31
trainerbattlecont 0x1 0x4a 0x0 str_0x8f523b str_0x8f527b ow_script_0x8f5cdf


ow_script_0x8f5cdf:
loadpointer 0x0 str_0x8f5f96
callstd MSG
setvar LASTTALKED 30
trainerbattlecont 0x1 0x4b 0x0 str_0x8f5f21 str_0x8f5f57 ow_script_0x8fa888


ow_script_movs_0x8f5eb0:
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8f5eb4:
.byte LOOK_UP
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8f5eac:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STOP


ow_script_0x8fa888:
loadpointer 0x0 str_0x8f5edb
callstd MSG

after_two_grunts:
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
setvar LASTTALKED 5
trainerbattlecont 0x1 0x4c 0x0 str_0x8f5d92 str_0x8f5d31 ow_script_0x8fab2c


ow_script_movs_0x8f6d19:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x8f6d16:
.byte LOOK_UP_DELAYED
.byte LOOK_DOWN_DELAYED
.byte STOP


ow_script_movs_0x8f6cf5:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_movs_0x8f6c01:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT_FAST
.byte STOP


ow_script_movs_0x8f6bfe:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8f6be5:
.byte STEP_UP_FAST
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8f6a5d:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8f6ae2:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8f68a4:
.byte LOOK_RIGHT
.byte SAY_QUESTION
.byte STOP


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


ow_script_movs_0x8f5aaf:
.byte STEP_UP
.byte STOP


ow_script_0x8f5aa3:
applymovement 0xff ow_script_movs_0x8f5aaf
waitmovement 0x0
return


ow_script_movs_0x8f5aa0:
.byte STEP_DOWN
.byte STOP


ow_script_0x8f5a94:
applymovement 0xff ow_script_movs_0x8f5aa0
waitmovement 0x0
return


.ifdef LANG_GER

str_0x8f4c85:
	.autostring 34 2 "Wir werden sowieso aus Ihnen herausbekommen, was wir wissen wollen, Professor.\pErsparen Sie sich alberene Ausreden und kooperieren Sie lieber gleich!"



str_0x8f4c4b:
	.autostring 34 2 "In Ordnung!\pDOTS DOTS DOTS\pIn Ordnung DOTS\nAber tun Sie mir bitte nichts DOTS"



str_0x8f4b7b:
	.autostring 34 2 "Haha!\nSie haben absolut kein Rückgrat, Primus!\pHaha!\pSo gefällt mir das!\nNun sagen Sie mir, was es mit dem Zeitstein und diesem seltsamen Schrein hier auf sich hat!"



str_0x8f4aee:
    .autostring 34 2 "Ich muss ehrlich sagen, dass ich ein Physiker bin, kein Historiker.\pDieser SchreinDOTS\pDOTSist uralt, ebenso wie seine Inschriften.\pIch kann sie nicht entziffernDOTS"



str_0x8f4ab8:
    .autostring 34 2 "Sie fangen nun also doch mit Ausflüchten an?\pHabe ich mich nicht klar genug ausgedrückt?\pDenken Sie, dass ich nicht bereit wäre, Sie aus dem Weg zu räumen?"



str_0x8f49f3:
    .autostring 34 2 "Nein!\pHalt, warten Sie, bitte!\pEs gibt noch eine zweite Inschrift, die nachträglich hinzugefügt wurde.\pSie ist in Icognito Zeichen geschrieben undDOTS\pIch müsste sie entziffern könnenDOTS"



str_0x8f49c5:
    .autostring 34 2 "Na also!\pIch wusste doch, dass Sie von Nutzen sein können.\pWie lautet diese Inschrift?"



str_0x8f48ca:
	.autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDer Text handelt von einem Pokémon namens Celebi.\pEs war einst der Wächter des Zeitsteins, welcher das Zeitgefüge zusammenhält.\pDOTS DOTS DOTS\nDOTS DOTS DOTS"


str_0x8f4823:
    .autostring 34 2 "Sehr gut, sehr gut!\pLesen Sie weiter!"


str_0x8f4755:
    .autostring 34 2 "Um einer drohenden Gefahr zu entgehen entschloss sich Celebi, den Zeitstein in drei Teile zu spaltenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pUnd jeden des der Fragmente von einem mächtigen antiken Pokémon bewachen zu lassenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch denke, das ist allesDOTS"


str_0x8f46fc:
	.autostring 34 2 "Gespalten?\nSind Sie sich da sicher?\pWenn Ihre Informationen sich als unwahr entpuppen solltenDOTS\pIch muss Ihnen Ihre Lage nicht ein weiteres Mal erklären, oder?"



str_0x8f5a63:
    .autostring 34 2 "Hey!\nLasst den Professor in Frieden!"



str_0x8f59e8:
    .autostring 34 2 "Arceus sei Dank!\nEin Trainer!\pBitte, hilf mir!\nDiese Frau DOTS\lDOTS ist eine Kommandantin von Team Violet.\pSie ist gefährlich!\pHilf mir!"



str_0x8f59cf:
    .autostring 34 2 "Halt den Rand, Primus!"



str_0x8f56b8:
	.autostring 34 2 "Was haben wir denn da?\pEin Kind, das sich in die Angelegenheiten von Team Violet einmischt.\pMein Name ist Rin und ich bin Kommandantin der zweiten Division von Team Violet.\pBist du dir sicher, dass du dich mit mir anlegen möchtest?\pHast du etwa noch nicht von mir und meinen Taten gehört?"


str_0x8f5628:
	.autostring 34 2 "Mir ist völlig gleichgültig, wer Sie sind oder was Sie im Schilde führen.\pIch werde Team Violet aufhalten!"


str_0x8f5514:
    .autostring 34 2 "Mut hast du ja, Rotznase!\pAber du weißt nicht, was gut für dich ist.\pUnser Plan ist in vollem Gange.\pIn naher Zukunft werden wir im Besitz einer so schrecklichen Waffe sein, dass jeder Mensch auf diesem Kontinent sich Team Violet zu fügen hat.\pEin Kind wie du, wird da nichts ausrichten können."


str_0x8f5425:
    .autostring 34 2 "Ich lasse mich nicht einschüchtern!"


str_0x8f52c9:
    .autostring 34 2 "Genug jetzt!\pDummes Kind!\pIhr da, erledigt das Balg, und zwar pronto!"


str_0x8f523b:
    .autostring 34 2 "Du kannst mir schon fast leid tun.\pSich mit Rin anzulegen ist nie eine gute Idee!"



str_0x8f527b:
    .autostring 34 2 "Na und?\nDann habe ich eben verloren.\pGegen Rin wirst du ohnehin nicht gewinnen, du naives Balg!"



str_0x8f5f96:
    .autostring 34 2 "Ich DOTS DOTS\nDOTS es tut mir leid, Rin DOTS"



str_0x8f5f21:
    .autostring 34 2 "Eines Tages werden wir über die Welt herrschen!\pUnd dafür werde ich bis zum bitteren Ende kämpfen!"



str_0x8f5f57:
    .autostring 34 2 "Du hast mehr auf dem Kasten, als es scheint.\pAber Rin ist eine Nummer zu groß für dich!"



str_0x8f5edb:
    .autostring 34 2 "Das Kind DOTS DOTS DOTS\nDOTS ist kein Anfänger DOTS"



str_0x8f5eb8:
    .autostring 34 2 "Ihr seid erbärmliche Gestalten!\pIch sollte euch in Mistrals Division verweisen.\pBeiseite, ihr Pappnasen!"



str_0x8f5d92:
	.autostring 34 2 "Vielleicht bist du doch ein interessanter Gegner.\pAber du musst wissen, dass ich auch gegen ein Kind ohne Skrupel kämpfen werde.\pDu hättest diese Dinge den Erwachsenen überlassen sollen.\pJetzt bezahlst du den Preis für deinen Heldenmut!"


str_0x8f5d31:
    .autostring 34 2 "Ich DOTS DOTS DOTS\nDOTS wurde von einem Kind besiegt?"



str_0x8fa9e7:
	.autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pIch habe dich wohl unterschätzt.\pDu bist ein ernstzunehmender Gegner.\pBeim unserem nächsten Aufeinandertreffen, werde ich mich nicht so überrumpeln lassen.\pWir haben ohnehin erfahren, was wir wissen wollten."


str_0x8f6cfb:
    .autostring 34 2 "Wir ziehen ab, los!"



str_0x8f6c09:
	.autostring 34 2 "Oh bei Arceus, ich danke dir!\pTausend Mal danke danke danke!\pIch bin gerettet.\pBereits seit Tagen halten mich diese Rüpel fest und schikanieren mich.\pIch dachte, es wäre aus mit mir."



str_0x8f6be9:
    .autostring 34 2 "Papa! Papa!"



str_0x8f6bb4:
    .autostring 34 2 "Elise!\nWas tust du denn hier?"



str_0x8f6b22:
	.autostring 34 2 "Ich habe mir solche Sorgen um dich gemacht.\pAls mir Professor Tann von deinem Verschwinden erzählt hat DOTS\pDOTS ich DOTS\nDOTS DOTS DOTS\pDOTS wäre vor Sorge fast umgekommen!"


str_0x8f6ae5:
    .autostring 34 2 "Keine Sorge, ich bin jetzt wohlauf, mein Schatz!"



str_0x8f6a60:
    .autostring 34 2 "Und das alles dank meinem Retter hier.\pDieses Kind hat einen Kommandanten von Team Violet geschlagen!\pWie lautet eigentlich dein Name?"



str_0x8f68d7:
    .autostring 34 2 "Wirklich PLAYER?\nDas ist fantastisch!\pSich mit solchen Menschen anzulegen, erfordert Mut!\pDu verblüffst mich aufs Neue!\pDanke dir, PLAYER!\nVon ganzem Herzen danke, dass du meinen Vater gerettet hast!"


str_0x8f68a8:
    .autostring 34 2 "DOTS DOTS DOTS\nAllerdings DOTS"



str_0x8f6749:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pHaben diese Leute von Team Violet es auf den Diserakt abgesehen."


str_0x8f6725:
    .autostring 34 2 "Diserakt?\nWas ist das?"



str_0x8f6626:
    .autostring 34 2 "Der Legende nach wird das Zeitgefüge vom Diserakt zusammengehalten.\pDie Leute haben ihn deshalb auch Zeitstein genannt.\pSolte er tatsächlich existierenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDie Energie, die er beinhaltet, wäre imens.\pDamit könnte man allerlei gefährliche Dinge anstellen."



str_0x8f65b0:
    .autostring 34 2 "PLAYER DOTS\nWirst du Team Violet weiter verfolgen?"



str_0x8f64bc:
    .autostring 34 2 "Team Violet will die Energie des Diserakts vermutlich als Waffe benutzen.\pDas werde ich nicht zulassen!"


str_0x8f6465:
    .autostring 34 2 "Das hatte ich mir gedachtDOTS\pDu solltest dir deinen Sieg nicht zu Kopf steigen lassen, ja?\pSchließlich haben wir die Top Vier und die Polizei, um sich mit solchen verbrecherischen Organisationen zu befassen.\pSich mit solchen Leuten anzulegen, kann leicht ins Auge gehen.\pPass auf dich auf, PLAYER!"

.elseif LANG_EN

.endif