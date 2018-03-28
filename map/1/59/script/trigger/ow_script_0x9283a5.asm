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
    .string "... ... ...\pDir nach all der Zeit\ngegenüberzutreten ...\p...\pSo viel hat sich verändert, so\nviel ist geschehen ...\pWieso, Albus? Wieso tust du das?"
        
        
.global str_0x92cf46

str_0x92cf46:
    .string "Alter Freund, es tut mir\nweh, dass wir unter diesen\lUmständen zusammenkommen.\pAber wir beide wissen, dass das\nSystem, dem wir gedient haben, das\lSystem, das wir selbst erschaffen\lhaben, uns entglitten ist."
        
        
.global str_0x92ce82

str_0x92ce82:
    .string "Entglitten? Du hast dich von\nunserem Lebenswerk abgewendet.\lErinnerst du dich? Die Top Vier,\ldie Pokemon Liga. All das. Sie\lwaren unser Werk, unser\lVermächtnis.\pUnd nun trittst du es mit Füßen!"
        
        
.global str_0x928b41

str_0x928b41:
    .string "Du tust mir unrecht. Ich habe so\nlange daran festgehalten, wie ich\les nur irgendwie verantworten\lkonnte.\pAber Korruption und Machtsucht\nhaben unsere Ideale infiziert und\leine kranke Regierung\lhervorgebracht.\pErkennst du es nicht? Siehst du\nnicht, was aus dieser Welt\lgeworden ist?\pDein eigener Schüler Devin ist der\nKönig des Untergrunds, die Polizei\lkümmert sich nicht um das Gesetz\lsondern bloß um einen gefüllten\lGeldbeutel.\pDie Feinde der Freiheit sind unter\neuch, Faun. Sie sind an deiner\lSeite. Der neue Champion, der\lLucius vertrieben hat...\pEr wird diese Welt nicht retten\nkönnen.\pVerstehst du nicht? Wir müssen\ndiese Aufgabe selbst in die Hand\lnehmen, wie wir es vor all den\lJahren getan haben."
        
        
.global str_0x928a7f

str_0x928a7f:
    .string "Du irrst dich, Albus. Du irrst\ndich.\pDeine Motive sind edel, aber eine\nneue Revolution wird nichts\lbewirken. Hunderte Menschen werden\lunter dem Krieg, den du diesem\lKontinent bringst, leiden."
        
        
.global str_0x928a11

str_0x928a11:
    .string "... ...\nDas Meer ...\lEs hat mich schon immer\lfasziniert...\l...\lEs ist voller Frieden und\lHarmonie...\l..."
        
        
.global str_0x9288c7

str_0x9288c7:
    .string "Ich kenne dich, Faun.\pDu bist mein Freund.\pWir sind wie Brüder füreinander.\pDu wirst mich nicht bekämpfen und\nich werde dich nicht bekämpfen.\pJedoch werde ich mein Vorhaben\nnicht aufgeben, denn ich weiß,\ldass ich das Richtige tue.\lDu bist ein guter Mensch, Faun.\pAuch du wirst begreifen, dass ich\nim Recht liege.\pIrgendwann."
        
        
.global str_0x9286da

str_0x9286da:
    .string "Bist du nicht der Junge, der mir\nauf Route 2 begegnet ist?\l...\lDu bist ein Schüler Fauns?\lDie Welt ist wahrlich klein. Ich\lhoffe, du bist nicht gekommen,\ldich unserer Sache in den Weg zu\lstellen.\lJa, ich bin der Kopf der\lRevolutionsbewegung, Albus.\lIm Kampf für Freiheit und\lGerechtigkeit bin ich unermüdlich.\lMöglicherweise kannst du, anders\lals dein Lehrer, zur Einsicht\lfinden und dich meiner Sache\lanschließen.\lEines steht aber fest:\lUnsere Wege werden sich wieder\lkreuzen."
        
        
.global str_0x9286b8

str_0x9286b8:
    .string "Albus, warte..."
        
        
.global str_0x928594

str_0x928594:
    .string "Hallo, PLAYER.\pDu bist Albus also bereits\nbegegnet.\pEr ist der Anführer der\nRevolutionsbewegung und mein\p...\pFreund...\pEr war es zumindest. Früher\neroberten wir gemeinsam den\lKontinent und gründeten die Top\lVier, musst du wissen.\pJetzt aber hat er sich gegen sein\neigenes System verschworen..."
        
        
.global str_0x92dc49

str_0x92dc49:
    .string "Felix! Was verschlägt dich\ndenn hierher?"
        
        
.global str_0x92dbcf

str_0x92dbcf:
    .string "Hallo Opi, hallo PLAYER!\pIch bin gekommen, um dich im Kampf\ngegen die Revolutionäre zu\lunterstützen, Opi, was sonst?"
        
        
.global str_0x92db7f

str_0x92db7f:
    .string "Nun, da bist du zu spät, ihr\nAnführer ist mir eben durch die\lFinger gegangen."
        
        
.global str_0x92db39

str_0x92db39:
    .string "War das der grün vermummte Mann,\ndem ich dort oben begegnet bin?"
        
        
.global str_0x92db05

str_0x92db05:
    .string "Wie ungünstig! Ich hätte ihn\nüberwältigen sollen."
        
        
.global str_0x935f18

str_0x935f18:
    .string "Rede keinen Unfug, Felix.\nAlbus\ Fertigkeiten im Kampf sind\ldeinen um Lichtjahre voraus.\lImmerhin waren wir einst Partner,\lwir sind ebenbürtig."
        
        
.global str_0x92d98d

str_0x92d98d:
    .string "Du unterschätzt uns immer noch,\nOpi! Wir sind deine Schüler!\pWer sagt, dass wir nicht längst\nüber deine Generation\lhinausgewachsen sind?\pWer sagt, dass die Ära, die du uns\nvorausgesagt hast, nicht schon\lgekommen ist?"
        
        
.global str_0x936ef3

str_0x936ef3:
    .string "Gjahaha! Gjahahap\nDu erinnerst mich an meine Jugend,\lFelix. Unverbesserlich\loptimistisch und naiv!\pNein, ihr zwei seid noch nicht\nso weit uns Veteranen\lherauszufordern.\pAber der Tag wird kommen, da ihr\nglänzen könnt und Menschen wie\lAlbus oder mich ablösen werdet."
        
        
.global str_0x92d7c0

str_0x92d7c0:
    .string "Bis dahin aber müsst ihr noch\neiniges leisten, euch beweisen.\lKämpft mit Herz und lasst euch von\leuren Entscheidungen nicht\labbringen."
        
        
.global str_0x93a4de

str_0x93a4de:
    .string "Ich finde es unfair, dass Opi uns\nimmer noch wie Kinder behandelt...\lSieht er nicht, dass wir\linzwischen unseren eigenen Weg\lgehen?\lWir werden ihm wohl beweisen\lmüssen, dass wir zu etwas taugen.\lIch werde meinen Plan, Arenaleiter\lzu werden, über den Haufen werfen.\lPLAYER, lass uns keine kleinen Ziele\lfassen.\lLass uns direkt nach den Sternen\lgreifen.\lLass uns den Titel des Champions\lanstreben!"
        
        
.global str_0x92e6d7

str_0x92e6d7:
    .string "Was sagst du dazu?"
        
        
.global str_0x92e662

str_0x92e662:
    .string "Nur, wenn man seine\nTräume hoch ansetzt, kann man\lGröße erlangen.\pWir werden die Welt erobern, auf\nunsere Art!"
        
        
.global str_0x92e5ea

str_0x92e5ea:
    .string "Das ist die richtige Einstellung!\pWie einst Opi und seine beiden\nGefährten, werden wir uns diese\lWelt zu Füßen legen!"
        
        
.global str_0x92e221

str_0x92e221:
    .string "Übrigens, ich bin auf dem Weg\nhierher unserem alten\lKlassenkameraden Blaise begegnet.\pEr scheint sich ebenfalls gut zu\nmachen, hat sogar einige\lArenaorden errungen. Nur seine\lhasszerfressene Art ist er noch\lnicht los geworden.\pHat aber etwas sehr interessantes\nerzählt, über eine Kampftechnik,\ldie sich Mega-Evolution nennt.\p... ...\p... ...\pIch dachte mir bereits, dass du\nauch nicht viel darüber weißt. Es\lscheint sich um eine Art der\lEvolution zu handlen, welche von\leinem Trainer nur ausgelöst werden\lkann, wenn sein Pokémon und er\leine enge Bindung zueinander\lhaben.\pWarum Faun uns dieses Geheimnis\nwohl vorenthalten hat?\pWir werden wohl auf eigene Faust\nherausfinden müssen, was es damit\lauf sich hat."
        
        
.global str_0x92e138

str_0x92e138:
    .string "Weißt du...\nManchmal starre ich stundenlang in\lden Himmel und frage mich, was es\ljenseits unserer Welt gibt...\lIst dort draußen noch Leben?\lWerden wir ihm begegnen?\lDie Welt ist so riesig, größer\lnoch als unsere Träume.\l...\l..."
        
        
.global str_0x92e024

str_0x92e024:
    .string "Weißt du, für den Anfang wäre es\nsicherlich hilfreich, wenn wir Opi\lim Kampf gegen die Revolutionäre\lunterstützen könnten.\pLass uns in Kaskada nach dem in\ngrün vermummten Mann, Albus,\lsuchen und ihn stellen.\pOpi wird sicherlich beeindruckt\nsein, wenn wir ihn fassen können."
        
        
.global str_0x92e4e6

str_0x92e4e6:
    .string "Vielleicht ist es doch\nsinnvoller, sich auf kleine Ziele\lzu berufen. Niemand kann unendlich\lgroße Stufen erklimmen."
        
        
.global str_0x92e56f

str_0x92e56f:
    .string "Vermutlich hast du du Recht. Opi\nund seine beiden Gefährten haben\lsich ihren Ruhm auch über viele\lJahre hinweg erkämpft."
        
        
.elseif LANG_EN

.endif
