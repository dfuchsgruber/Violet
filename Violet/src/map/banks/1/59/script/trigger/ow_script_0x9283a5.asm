.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x92d0b8
ow_script_movs_0x92d0b8:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x928a7c
ow_script_movs_0x928a7c:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x928a0e
ow_script_movs_0x928a0e:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x9288c3
ow_script_movs_0x9288c3:
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x9288bf
ow_script_movs_0x9288bf:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x9288ba
ow_script_movs_0x9288ba:
.byte STEP_UP
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x9286d6
ow_script_movs_0x9286d6:
.byte STEP_RIGHT
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x9312ac
ow_script_movs_0x9312ac:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x92e56b
ow_script_movs_0x92e56b:
.byte STEP_UP
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x9283a5
ow_script_0x9283a5:
lockall
playsong MUS_REVOLUTION 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x92d0b8
waitmovement 0x0
special 0x114
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92d01d
callstd MSG
special 0x7
call ow_script_0x8e63f4
loadpointer 0x0 str_0x92cf46
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92ce82
callstd MSG
special 0x7
call ow_script_0x8e63f4
loadpointer 0x0 str_0x928b41
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x928a7f
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x928a7c
waitmovement 0x0
applymovement 0xb ow_script_movs_0x92d0b8
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x928a11
callstd MSG
special 0x7
applymovement 0xb ow_script_movs_0x928a0e
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x9288c7
callstd MSG
special 0x7
applymovement 0xb ow_script_movs_0x9288c3
waitmovement 0x0
sound 0x15
applymovement 0xb ow_script_movs_0x9288bf
applymovement 0xc ow_script_movs_0x9288bf
waitmovement 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x9288c3
applymovement 0xb ow_script_movs_0x9288ba
waitmovement 0x0
special 0x114
call ow_script_0x8e63f4
loadpointer 0x0 str_0x9286da
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x9286d6
waitmovement 0x0
applymovement 0xb ow_script_movs_0x9312ac
pause 0x40
call ow_script_0x89c5ee
loadpointer 0x0 str_0x9286b8
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x92e56b
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x928594
callstd MSG
goto ow_script_0x92d67a


.global ow_script_movs_0x92dc7e
ow_script_movs_0x92dc7e:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x92dc7a
ow_script_movs_0x92dc7a:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x92db7c
ow_script_movs_0x92db7c:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x92da68
ow_script_movs_0x92da68:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x92da70
ow_script_movs_0x92da70:
.byte STEP_LEFT
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x92da6b
ow_script_movs_0x92da6b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x92d849
ow_script_movs_0x92d849:
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x92d7a5
ow_script_movs_0x92d7a5:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x93a4d4
ow_script_movs_0x93a4d4:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x92d7b6
ow_script_movs_0x92d7b6:
.byte STEP_DOWN
.byte FACE_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x92d67a
ow_script_0x92d67a:
special 0x7
showsprite 0xd
applymovement 0xd ow_script_movs_0x92dc7e
waitmovement 0x0
sound 0x15
applymovement 0xc ow_script_movs_0x92dc7a
applymovement 0xff ow_script_movs_0x92dc7a
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92dc49
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92dbcf
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92db7f
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92db7c
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92db39
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92da68
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92db05
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x935f18
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x92da70
waitmovement 0x0
applymovement 0xd ow_script_movs_0x92da6b
waitmovement 0x0
applymovement 0xff ow_script_movs_0x92da68
applymovement 0xc ow_script_movs_0x92da68
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92d98d
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x936ef3
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x92d849
waitmovement 0x0
applymovement 0xd ow_script_movs_0x92db7c
applymovement 0xff ow_script_movs_0x92db7c
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x92d7c0
callstd MSG
special 0x7
applymovement 0xc ow_script_movs_0x92d7a5
waitmovement 0x0
applymovement 0xff ow_script_movs_0x93a4d4
applymovement 0xd ow_script_movs_0x92d7b6
waitmovement 0x0
goto ow_script_0x92dc84


.global ow_script_movs_0x92e6ec
ow_script_movs_0x92e6ec:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x92e6ef
ow_script_movs_0x92e6ef:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x92dc84
ow_script_0x92dc84:
pause 0x40
call ow_script_0x89e1fc
loadpointer 0x0 str_0x93a4de
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92e6ec
applymovement 0xff ow_script_movs_0x92e6ef
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e6d7
callstd MSG_YES_NO
special 0x7
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x93a667
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x92e662
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e5ea
callstd MSG
goto ow_script_0x92df8a


.global ow_script_movs_0x92e21e
ow_script_movs_0x92e21e:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x92e021
ow_script_movs_0x92e021:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x93c1e9
ow_script_movs_0x93c1e9:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x92df8a
ow_script_0x92df8a:
loadpointer 0x0 str_0x92e221
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92e21e
applymovement 0xff ow_script_movs_0x92e21e
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e138
callstd MSG
special 0x7
applymovement 0xd ow_script_movs_0x92e6ec
applymovement 0xff ow_script_movs_0x92e6ef
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e024
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x92e021
waitmovement 0x0
applymovement 0xd ow_script_movs_0x93c1e9
waitmovement 0x0
hidesprite 0x1
hidesprite 0x2
hidesprite 0x3
hidesprite 0x4
hidesprite 0x5
hidesprite 0x6
hidesprite 0x7
hidesprite 0x8
hidesprite 0x9
hidesprite 0xa
hidesprite 0xb
hidesprite 0xc
hidesprite 0xd
goto ow_script_0x941cae


.global ow_script_0x941cae
ow_script_0x941cae:
fadescreen 0x1
showsprite 0xe
showsprite 0x10
showsprite 0x11
showsprite 0x12
showsprite 0x13
showsprite 0x14
showsprite 0x15
clearflag KASKADA_IGVA
clearflag KASKADA_FELIX_DONE
fadescreen 0x0
fadesong MUS_ROUTE_24_25
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x93a667
ow_script_0x93a667:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x92e4e6
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x92e56f
callstd MSG_KEEPOPEN
goto ow_script_0x92df8a


.ifdef LANG_GER
.global str_0x92d01d

str_0x92d01d:
	.autostring 35 2 "DOTS DOTS DOTS\pAlbus!\nDOTS DOTS DOTS\pDass wir uns nach all der Zeit unter solchen Umständen wieder begegnen DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS"

        
        
.global str_0x92cf46

str_0x92cf46:
	.autostring 35 2 "Faun, mein alter Freund.\pEs tut mir wirklich im Herzen weh, dass wir uns hier als Feinde gegenüberstehen.\pAber du weißt so gut wie ich, dass das System, das wir selbst einst erschaffen haben, uns längst schon entglitten ist."

        
        
.global str_0x92ce82

str_0x92ce82:
	.autostring 35 2 "Entglitten?\nDas ist eine sehr bequeme Ausrede, sich vor der Aufgabe zu drücken, einen Kontinent zu regieren.\pErinnerst du dich nicht an früher?\pSollte die Pokémon-Liga nicht unser Vermächtnis sein?"

.global str_0x928b41

str_0x928b41:
	.autostring 35 2 "Es ist keine Ausrede, Faun.\pIch habe so lange für die Pokémon-Liga gekämpft, wie ich es mit meinem Gewissen vereinbaren konnte.\pAber Korruption und Machtsucht haben unsere Ideale von damals infiziert DOTS\pErkennst du es nicht?\nDiese Regierung ist nicht mehr zu retten.\pEs ist heute wie damals unsere Pflicht, diese Welt zu verändern.\pUnd für die Veränderung zum Besseren werden wir kämpfen.\pDu, Faun, solltest an meiner Seite dafür eintreten DOTS"
        
.global str_0x928a7f

str_0x928a7f:
	.autostring 35 2 "Du irrst dich, Albus.\pIch kann verstehen, warum du dich gegen Thetos Regierung auflehnst.\pIch kann es wirklich sehr gut verstehen.\pAber du bringst den Menschen einen Krieg, in dem es keine Gewinner gibt.\pSelbst, wenn dein Vorhaben gelingen sollte DOTS\pWas kommt danach?\pWer sagt dir, dass nicht eben das gleiche System wieder entsteht?\pWir haben Verantwortung für das Land, das wir damals erobert haben.\pDiese Verantwortung jetzt einfach aufzugeben DOTS DOTS DOTS\pIst feige!"

        
.global str_0x928a11

str_0x928a11:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pVielleicht ist es das, Faun DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
        
        
.global str_0x9288c7

str_0x9288c7:
	.autostring 35 2 "Faun.\nWir du bist für mich wie ein Bruder.\pAuch, wenn wir in diesem Krieg nicht auf der selben Seite stehen DOTS\pIch werde niemals gegen dich kämpfen.\pAber ich werde mein Vorhaben auch nicht einfach aufgeben.\pIch weiß, dass ich im Recht bin.\pDu bist ein gutherziger Mensch, Faun.\pVielleicht siehst du auch eines Tages ein, dass die Revolution notwendig ist DOTS"
        
.global str_0x9286da

str_0x9286da:
	.autostring 35 2 "Hu?\nDu bist doch das Kind, dem ich auf Route 2 begegnet bin?\pDu bist also ein Schüler von Faun?\pIch hoffe, dass du nicht mit der Absicht gekommen bist, dich unserer Sache in den Weg zu stellen.\pWie du sicherlich inzwischen bemerkt hast, bin ich der Anführer der Revolutionsbewegung.\pVielleicht kommst du ja, anders als dein Lehrer, zur Erkenntnis, dass das System der Top Vier gestürzt werden muss.\pEines Tages wirst du dich entscheiden müssen, auf wessen Seite du stehst.\pDOTS DOTS DOTS\nAber ich will dich nicht überrumpeln.\pLeb wohl, junger Trainer."
        
        
.global str_0x9286b8

str_0x9286b8:
    .autostring 35 2 "Albus, warte DOTS DOTS"
        
        
.global str_0x928594

str_0x928594:
	.autostring 35 2 "PLAYER.\nDer Mann, dem du eben begegnet bist, ist Albus, der Anführer der Revolutionsbewegung.\pEr ist DOTS\nDOTS DOTS DOTS\pDOTS er war ein enger Freund von mir, aber das liegt eine Ewigkeit zurück.\pGemeinsam waren wir an der Gründung der Pokémon-Liga beteiligt.\pAber jetzt stellt Albus sich gegen das System, das er selbst mitaufgebaut hat DOTS"
        
.global str_0x92dc49

str_0x92dc49:
    .autostring 35 2 "Felix?\nDu bist auch hier?"
        
        
.global str_0x92dbcf

str_0x92dbcf:
	.autostring 35 2 "Aber sicher doch, Opi!\pIch bin gekommen, um dir im Kampf gegen die Revolutionäre zu helfen!"
        
        
.global str_0x92db7f

str_0x92db7f:
    .autostring 35 2 "He!\nDa bist zu spät dran, Junge.\pIhr Anführer ist mir eben durch die Lappen gegangen."
        
        
.global str_0x92db39

str_0x92db39:
    .autostring 35 2 "Was?\nIhr Anführer?\pSag mir nicht, dass das der Mann in Grün war, der eben auf dem Berg an mir vorbeigegangen ist!"
        
        
.global str_0x92db05

str_0x92db05:
    .autostring 35 2 "Mist!\nIch hätte ihn überwältigen sollen!"
        
        
.global str_0x935f18

str_0x935f18:
	.autostring 35 2 "Hahaha!\nRede doch keinen Unfug, Bursche!\pAlbus Fertigkeiten sind deinen weit voraus.\pEr hätte dich im Handumdrehen erledigt."
        
.global str_0x92d98d

str_0x92d98d:
	.autostring 35 2 "Du unterschätzt mich ja immer noch Opi!\pIch habe schon zwei Arena-Orden errungen!\pUnd du denkst immer noch, dass ihr Erwachsenen uns überlegen sind?\pDu hast doch gar keine Vorstellung davon, wie stark ich inzwischen geworden bin!\pPLAYER hier hat es sogar geschafft, einen Kommandanten von Team Violet zu besiegen!"
        
.global str_0x936ef3

str_0x936ef3:
	.autostring 35 2 "Hahaha!\nHahaa DOTS\pNun mach mal halblang, du Rotzlöffel.\pIhr beide seid sicherlich auf einem guten Weg, starke Trainer zu werden, aber Leuten wie Albus oder mir könnt ihr noch lange nicht das Wasser reichen."
        
.global str_0x92d7c0

str_0x92d7c0:
	.autostring 35 2 "Bis der Tag kommt, an dem ihr in der Lage seid, solche Kaliber herauszufordern, müsst ihr noch einiges leisten!\pAber ich bin sicher, dass ihr das Zeug dazu habt!"
        
.global str_0x93a4de

str_0x93a4de:
	.autostring 35 2 "Es ist unfair, dass Opi uns immer noch wie kleine Kinder behandelt DOTS\pWir sind mittlerweile ernstzunehmende Trainer geworden, meinst du nicht?\pDOTS DOTS DOTS\pAber wenn wir ihm das nicht zeigen, werden wir seinen Respekt nie verdienen!\pWir müssen einfach noch stärker werden, PLAYER.\pUnd dann werden wir eines Tages selbst den Champion herausfordern!"
        
.global str_0x92e6d7

str_0x92e6d7:
    .autostring 35 2 "Was sagst du dazu?"
        
        
.global str_0x92e662

str_0x92e662:
	.autostring 35 2 "Wir werden auf jeden Fall die großen Trainer unserer Zeit übertreffen.\pDaran führt kein Weg vorbei!"
        
        
.global str_0x92e5ea

str_0x92e5ea:
    .autostring 35 2 "Das ist die richtige Einstellung!\pIn ein paar Jahren wird man sich von uns Geschichten erzählen, wie man sie von Opi kennt!"
        
        
.global str_0x92e221

str_0x92e221:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pÜbrigens PLAYER,\nhast du je etwas von einer Technik namens Mega-Evolution gehört?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDas dachte ich mir bereits.\pOpi hat uns in der Schule nichts darüber beigebracht.\pDoch wenn man dem, was ich gehört habe, Glauben schenkt, handelt es sich um eine Möglichkeit, durch die enge Freundschaft zwischen Trainer und Pokémon im Kampf dessen verstecktes Potenzial zum Vorschein zu bringen.\pDOTS DOTS DOTS\pWas meinst du, wie stark wir erst werden, wenn wir diese Technik beherrschen?"
        
.global str_0x92e138

str_0x92e138:
	.autostring 35 2 "Es gibt noch so viel, dass wir nicht über die Welt der Pokémon wissen.\pUnd genau das macht das Abenteuer so unglaublich spannend!"

        
.global str_0x92e024

str_0x92e024:
	.autostring 35 2 "Aber lass uns die eigentlichen Probleme nicht aus den Augen verlieren, PLAYER!\pWir sollten uns gegen diese Revolutionsbewegung kämpfen!\pAm besten suchen wir in Kaskada nach Albus, ihrem Anführer.\pWenn wir ihn gemeinsam besiegen könnten, wäre Opi sicherlich schwer beeindruckt!"
        
.global str_0x92e4e6

str_0x92e4e6:
    .autostring 35 2 "Und du meinst, wir sind stark genug, es mit dem Anführer der Revolutionsbewegung aufzunehmen?"
        
        
.global str_0x92e56f

str_0x92e56f:
    .autostring 35 2 "Willst du damit sagen, dass du denkst, wir wären zu schwach für so ein Vorhaben?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDas können wir nur herausfinden, wenn wir es versuchen!"
        
        
.elseif LANG_EN

.endif
