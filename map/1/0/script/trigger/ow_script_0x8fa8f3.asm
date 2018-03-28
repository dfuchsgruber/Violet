.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


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
playsong MUS_ROCKET_HQ_AND_AZURIA_HOHLE_AND_TOP_4_BRUNO 0x0
setvar SONG_OVERRIDE MUS_ROCKET_HQ_AND_AZURIA_HOHLE_AND_TOP_4_BRUNO
special 0x113
applymovement 0x7f ow_script_movs_0x8f4d2c
waitmovement 0x0
special 0x114
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f4c85
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f4c4b
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f4b7b
callstd MSG
special 0x7
applymovement 0x1e ow_script_movs_0x8f4b78
waitmovement 0x0
pause 0x38
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f4aee
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f4ab8
callstd MSG
special 0x7
applymovement 0x1e ow_script_movs_0x8f4ab5
waitmovement 0x0
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f49f3
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f49c5
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f48ca
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f4823
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f4755
callstd MSG
special 0x7
call ow_script_0x8f4d18
goto ow_script_0x8fbc5c


.global ow_script_0x8fbc5c
ow_script_0x8fbc5c:
loadpointer 0x0 str_0x8f46fc
callstd MSG
special 0x7
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
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f5a63
callstd MSG
waitmovement 0x0
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f59e8
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x8f505f
waitmovement 0x0
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f59cf
callstd MSG
applymovement 0x5 ow_script_movs_0x8f5140
loadpointer 0x0 str_0x8f56b8
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f5628
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f5514
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f5425
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f52c9
callstd MSG
special 0x7
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
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f5eb8
callstd MSG
special 0x7
applymovement 0x20 ow_script_movs_0x8f5eb0
applymovement 0x1f ow_script_movs_0x8f5eb4
waitmovement 0x0
applymovement 0x5 ow_script_movs_0x8f5eac
waitmovement 0x0
pause 0x20
call ow_script_0x8f4d18
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
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8fa9e7
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x8f6d16
waitmovement 0x0
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f6cfb
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x5
hidesprite 0x1f
hidesprite 0x20
hidesprite 0xd
hidesprite 0x9
hidesprite 0x6
fadescreen 0x0
playsong VERTANIA_WALD_AND_BEERENFORST_AND_MUSTERBUSCHWALD_AND_DIGDAS_HOHLE_AND_SEESCHAUMINSELN 0
applymovement 0x1e ow_script_movs_0x8f6cf5
waitmovement 0x0
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f6c09
callstd MSG
special 0x7
clearflag PKMNMENU
showsprite 0x24
applymovement 0x24 ow_script_movs_0x8f6c01
waitmovement 0x0
sound 0x15
applymovement 0x24 ow_script_movs_0x8f6bfe
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f6be9
callstd MSG
special 0x7
applymovement 0x1e ow_script_movs_0x8f6be5
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8f6a5d
waitmovement 0x0
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f6bb4
callstd MSG
special 0x7
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f6b22
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f6ae5
callstd MSG
applymovement 0x1e ow_script_movs_0x8f6ae2
waitmovement 0x0
loadpointer 0x0 str_0x8f6a60
callstd MSG
special 0x7
applymovement 0x24 ow_script_movs_0x8f6ae2
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f68d7
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f68a8
callstd MSG_KEEPOPEN
sound 0x15
applymovement 0x24 ow_script_movs_0x8f68a4
applymovement 0xff ow_script_movs_0x8f68a4
waitmovement 0x0
loadpointer 0x0 str_0x8f6749
callstd MSG
special 0x7
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f6725
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f6626
callstd MSG_KEEPOPEN
special 0x7
fadescreen 0x1
hidesprite 0x1e
fadescreen 0x0
applymovement 0x24 ow_script_movs_0x8f6ae2
applymovement 0xff ow_script_movs_0x8f6a5d
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f65b0
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f64bc
callstd MSG
special 0x7
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f6465
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x24
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8f4d04
ow_script_0x8f4d04:
setvar 0x8000 0x0
setvar 0x8001 0x18
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8f4d18
ow_script_0x8f4d18:
setvar 0x8000 0x1
setvar 0x8001 0x0
setvar 0x8002 0xe
special 0x6
return


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
    .string "Wir werden die Informationen\nohnehin bekommen, Professor.\lSie ersparen sich eine Menge\lSchmerzen, wenn sie kooperieren."
        
        
.global str_0x8f4c4b

str_0x8f4c4b:
    .string "In Ordnung, in Ordnung.\nTun Sie mir nichts, bitte!"
        
        
.global str_0x8f4b7b

str_0x8f4b7b:
    .string "Gut, Professor Primus, eine\nweise Entscheidung.\lWir verlangen nicht viel von\lIhnen. Sehen Sie sich die Runen\lan, die dort in den Schrein\lgraviert sind und übersetzten Sie\ldie antiken Icognito-Zeichen."
        
        
.global str_0x8f4aee

str_0x8f4aee:
    .string "... ... ...\p.... .... ....\pEs ist eine sehr alte Sprache ...\lwie ... interessant ...\p....\p.....\pOh ja, höchst interessant ..."
        
        
.global str_0x8f4ab8

str_0x8f4ab8:
    .string "Also, was ist nun? Was steht\ndort geschrieben?"
        
        
.global str_0x8f49f3

str_0x8f49f3:
    .string "... Offenbar sind es im\nGrunde zwei Texte. Ein alter Text,\lder vom Stein der Zeit, dem\lDiserakt, erzählt. Und ein neuer\lText, nur ein paar Jahre alt, der\lebenfalls von dem Stein handelt."
        
        
.global str_0x8f49c5

str_0x8f49c5:
    .string "Und was besagen sie, die\nbeiden Texte?"
        
        
.global str_0x8f48ca

str_0x8f48ca:
    .string "Hmm... Diese alte Inschrift\nhandelt von der Erschaffung der\lZeit durch Dialga. Dieses soll das\lHerz der Zeit in einem Stein\lversiegelt haben. Aus diesem Stein\list das zeitreisende Pokémon\lCelebi entstanden, welches den\lDiserakt bewachen sollte."
        
        
.global str_0x8f4823

str_0x8f4823:
    .string "Oh ja, das wissen wir bereits.\nCelebi, das Zeitpokemon, dem\ldieser Schrein gewidmet ist.\lDer neue Text, der interessiert\lmich. Welche Enthüllungen hält er\lbereit?"
        
        
.global str_0x8f4755

str_0x8f4755:
    .string "Die neuerlich hinzugefügte Inschrift\nist an jene Menschen adressiert,\ldie den Stein mit reinem Herzen\lsuchen. Er besagt, dass Celebi den\lStein fortgebracht und ihn den\lgroßen Wächtern der Welt\lanvertraut hat."
        
        
.global str_0x8f46fc

str_0x8f46fc:
    .string "... ... ...\p... ... ... ...\pDen ... Wächtern ...\p... meint es damit .... etwa ..."
        
        
.global str_0x8f5a63

str_0x8f5a63:
    .string "Hey, ihr da! Lasst den Mann in\nFrieden!"
        
        
.global str_0x8f59e8

str_0x8f59e8:
    .string "Ein Trainer!\nArceus sei Dank! Hilf mir, diese\lSchergen von Team Violet haben\lmich als Geisel genommen!"
        
        
.global str_0x8f59cf

str_0x8f59cf:
    .string "Schweig, du Narr!"
        
        
.global str_0x8f56b8

str_0x8f56b8:
    .string "Was haben wir denn da?\nEinen kleinen Jungen, der sich in\lAngelegenheiten einmischt, die ihn\lnichts angehen.\pErlaube mir mich vorzustellen. Ich\nbin Rin, Anführer der zweiten\lDivision von Team Violet und\lMitglied des Vorstands.\pWir sind eine Organisation des\nFriedens. Seit je her war es die\lFreiheit, die der Menschheit den\lKrieg gebracht hat. Es liegt in\lder Natur des Menschen, zu\lkämpfen. Wir werden diesem\lKreislauf ein Ende bereiten, indem\lwir eine Waffe konstruieren,\lwelche uns zu den Herrschern der\lWelt machen wird. Dann werden wir\ldie Menschheit zum Frieden\lzwingen!\pDas Problem ist die Energie, die\nfür eine derartige Waffe benötigt\lwird. Da kommt der Stein der Zeit,\lder Diserakt, ins Spiel. Mit der\lEssenz der Zeit angetrieben,\lkönnen wir dank ihm die Maschine\lbetreiben."
        
        
.global str_0x8f5628

str_0x8f5628:
    .string "Und für diesen Frieden werden\nMenschenleben geopfert? Für diesen\lunechten Frieden wird die Freiheit\laufgegeben? Das werde ich nicht\lzulassen!"
        
        
.global str_0x8f5514

str_0x8f5514:
    .string "Du begreifst es nicht, Junge.\nDie Mächte, mit denen du dich\lanlegst, übersteigen deine\lFähigkeiten bei Weitem. Unser Plan\list in vollem Gange und kann nicht\lmehr aufgehalten werden.\lSchließlich wird man uns noch\ldanken, für das, was wir der\lMenschheit geschenkt haben."
        
        
.global str_0x8f5425

str_0x8f5425:
    .string "Niemand wird euch danken, denn was\nihr versprecht ist Frieden, aber\lwas ihr bringt, ist eine Waffe.\lIch werde euch aufhalten, euch von\lTeam Violet, die ihr hilflose\lMenschen wie Professor Primus\lentführt und für eure Zwecke\lmissbraucht."
        
        
.global str_0x8f52c9

str_0x8f52c9:
    .string "Du bist ein einfältiger\nIdealist. Solange die Menschen\lfrei sind, werden sie immer Kriege\lführen, werden sie immer kämpfen.\lEine Nation muss unterdrückt\lwerden, um in Frieden existieren\lzu können. Der Krieg ist das\leinzige, das wahren Frieden\lbringen kann. Ich werde es dir\lbeweisen. Los, meine Untergebenen,\lschaltet diesen Ignoranten aus."
        
        
.global str_0x8f523b

str_0x8f523b:
    .string "Du wirst Rin in ihrer\nMission nicht aufhalten, Bengel!"
        
        
.global str_0x8f527b

str_0x8f527b:
    .string "Du kannst nicht gewinnen,\negal, ob ich nun verloren habe."
        
        
.global str_0x8f5f96

str_0x8f5f96:
    .string "Mist... Wie konnte ich nur gegen\ndiesen Jungen verlieren?"
        
        
.global str_0x8f5f21

str_0x8f5f21:
    .string "Mit mir wirst du es nicht so\nleicht haben, Bursche!"
        
        
.global str_0x8f5f57

str_0x8f5f57:
    .string "Du bist stark ... aber mit Rin\nkannst du es nicht aufnehmen."
        
        
.global str_0x8f5edb

str_0x8f5edb:
    .string "Argh! Dieser Rotzlöffel ist stark!\nIch konnte ihn nicht besiegen..."
        
        
.global str_0x8f5eb8

str_0x8f5eb8:
    .string "Beiseite, ihr Schwächlinge."
        
        
.global str_0x8f5d92

str_0x8f5d92:
    .string "Du hast eine Menge Mut, dich\nmit uns anzulegen. Aber du musst\lbegreifen, dass unsere Ideale kein\ldummes Kinderspiel sind. Wir\lkämpfen für eine bessere Welt. Und\lich bin bereit, jeden Preis zu\lzahlen, der von mir gefordert\lwird. Auch wenn es bedeutet, ein\lKind zu vernichten."
        
        
.global str_0x8f5d31

str_0x8f5d31:
    .string "Unmöglich! Das ist unmöglich!\nWie kann ein Kind sich dem großen\lPlan widersetzen und bestehen?"
        
        
.global str_0x8fa9e7

str_0x8fa9e7:
    .string "DOTS\nDu bist DOTS DOTS\lein ernstzunehmender Gegner. Ich\lwar unvorsichtig und habe mich\lüberrumpeln lassen.\pSei\s drum, ich habe bereits\nerfahren, was ich wissen wollte.\pUnsere Friedensmission wird\nforgesetzt und du solltest dich\llieber von uns fern halten, Kind.\lAnderenfalls werden dir die Dinge\lschnell über den Kopf wachsen."
        
        
.global str_0x8f6cfb

str_0x8f6cfb:
    .string "Wir ziehen ab, los!"
        
        
.global str_0x8f6c09

str_0x8f6c09:
    .string "Oh beim großen Arceus, ich\ndanke dir, tausend Mal danke ich\ldir, dass du mich von diesen\lschrecklichen Schurken befreit\lhast. Bereits seit einer Woche\lhalten sie mich gefangen und\lzwingen mich dazu, antike Texte zu\lübersetzten."
        
        
.global str_0x8f6be9

str_0x8f6be9:
    .string "Papa! Papa!"
        
        
.global str_0x8f6bb4

str_0x8f6bb4:
    .string "Elise! Was tust du denn hier?"
        
        
.global str_0x8f6b22

str_0x8f6b22:
    .string "Ich habe mir solche Sorgen\num dich gemacht, Papa. Als ich\lgehört habe, dass Team Violet dich\lentführt hat, bin ich fast\ldurchgedreht..."
        
        
.global str_0x8f6ae5

str_0x8f6ae5:
    .string "Sei unbesorgt, ich bin wohlauf."
        
        
.global str_0x8f6a60

str_0x8f6a60:
    .string "Und das alles dank meinem Retter,\nPLAYER. Er hat Rin, die\lAnführerin der zweiten Division\lvon Team Violet in die Flucht\lgeschlagen!"
        
        
.global str_0x8f68d7

str_0x8f68d7:
    .string "Wirklich, PLAYER?\nDu bist ohne Zweifel fantastisch!\pAls ich dich das erste Mal gesehen\nhabe, wusste ich, dass du ein\ltalentierter Trainer bist, aber\ldass du sogar ein so hohes Tier in\lder Hirarchie Team Violets\lbesiegen kannst...\pFantastisch! Du hast mir meinen\nlieben Vater zurückgebracht,\lPLAYER! Ich wüsste nicht, was\lich ohne deine Hilfe getan hätte.\pDanke, danke, und nochmals danke!"
        
        
.global str_0x8f68a8

str_0x8f68a8:
    .string "Ungeachtet\ndessen aber ..."
        
        
.global str_0x8f6749

str_0x8f6749:
    .string "... haben wir ein ernsthaftes\nProblem. Team Violet weiß nun,\ldass der Stein der Zeit, der\lDiserakt, nicht hier verborgen\lliegt.\lDiese schurkische Organisation\lwill die Energie des Diserakts\lnutzen, um eine höllische Waffe zu\lbetreiben. Mittels dieser Macht\lkönnten sie ihre Pläne\lverwirklichen und die Herrschaft\lüber diese Welt an sich reißen."
        
        
.global str_0x8f6725

str_0x8f6725:
    .string "Das klingt ja schrecklich!"
        
        
.global str_0x8f6626

str_0x8f6626:
    .string "Ja. Das ist in der\nTat beunruhigend. Alarmierend\lsogar...\lTeam Violet darf unter keinen\lUmständen in den Besitz des\lDiserakts gelangen. Ich werde mich\lunverzüglich auf den Weg machen,\ldie Top Vier von der Situation in\lKenntnis zu setzten."
        
        
.global str_0x8f65b0

str_0x8f65b0:
    .string "PLAYER, was wirst du\nnun tun? Verfolgst du Team Violet\lweiterhin, um unsere Welt vor der\lUnterwerfung zu retten?"
        
        
.global str_0x8f64bc

str_0x8f64bc:
    .string "Ja... Ich befürchte, dass hinter\nall dem weitaus mehr steckt, als\lauf den ersten Blick sichtbar ist.\lTeam Violet und ich, wir sind DOTS\lauf eine seltsame Art und Weise\lverbunden. Es ist, als sei es mein\lSchicksal, diese Verbrecher zu\lbekämpfen."
        
        
.global str_0x8f6465

str_0x8f6465:
    .string "Du bist wahrlich ein großer\nMensch, PLAYER. Wenn uns jemand\lretten kann, dann du."
        
        
.elseif LANG_EN

.endif
