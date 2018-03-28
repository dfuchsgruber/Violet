.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8eca2a
ow_script_movs_0x8eca2a:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8eca0e
ow_script_movs_0x8eca0e:
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8ec91e
ow_script_movs_0x8ec91e:
.byte SAY_QUESTION
.byte STOP


.global ow_script_0x81c406
ow_script_0x81c406:
checkflag SILVANIA_FOREST_FLASHBACK_DONE
gotoif EQUAL ow_script_0x8f7200
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8eca2e
callstd MSG
special 0x7
sound 0x15
applymovement 0x2 ow_script_movs_0x8eca2a
applymovement 0x1 ow_script_movs_0x8eca2a
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8eca11
callstd MSG
special 0x7
applymovement 0xff ow_script_movs_0x8eca0e
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ec9d0
callstd MSG
special 0x7
loadpointer 0x0 str_0x8ec921
callstd MSG
sound 0x15
applymovement 0xff ow_script_movs_0x8ec91e
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8ec8fc
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ec8ab
callstd MSG
special 0x7
loadpointer 0x0 str_0x8ec84d
callstd MSG
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ec7d7
callstd MSG
special 0x7
loadpointer 0x0 str_0x8ec6df
callstd MSG
call ow_script_0x89c5ee
loadpointer 0x0 str_0x87e807
callstd MSG
special 0x7
goto ow_script_0x8ecac3


.global ow_script_0x8ecac3
ow_script_0x8ecac3:
goto ow_script_0x8fbc6c


.global ow_script_0x8fbc6c
ow_script_0x8fbc6c:
writebytetooffset 0x2 0x2036e28
warpmuted 0x1 0x0 0x8 0x0 0x0
addvar STORY_PROGRESS 0x1
waitstate
end


.global ow_script_movs_0x8f28b5
ow_script_movs_0x8f28b5:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8f28b2
ow_script_movs_0x8f28b2:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8f27c8
ow_script_movs_0x8f27c8:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8f26b0
ow_script_movs_0x8f26b0:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8f0a0b
ow_script_movs_0x8f0a0b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8f0981
ow_script_movs_0x8f0981:
.byte LOOK_UP
.byte STOP


.global ow_script_0x8f7200
ow_script_0x8f7200:
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f28b9
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8f28b5
waitmovement 0x0
loadpointer 0x0 str_0x8f3668
callstd MSG
applymovement 0x1 ow_script_movs_0x8f28b2
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f27cb
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8f27c8
applymovement 0x2 ow_script_movs_0x8f27c8
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f276d
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f26b3
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8f26b0
waitmovement 0x0
loadpointer 0x0 str_0x8f2607
callstd MSG
sound 0x63
showsprite 0x3
checksound
sound 0x15
applymovement 0x1 ow_script_movs_0x8eca2a
applymovement 0x2 ow_script_movs_0x8eca2a
applymovement 0xff ow_script_movs_0x8eca2a
waitmovement 0x0
loadpointer 0x0 str_0x8f257b
callstd MSG
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f0b3b
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8f28b2
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f0ad6
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8f27c8
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8f0a28
callstd MSG
special 0x7
loadpointer 0x0 str_0x8f0a11
callstd MSG
applymovement 0x3 ow_script_movs_0x8f27c8
waitmovement 0x0
sound 0x9
hidesprite 0x3
checksound
applymovement 0x1 ow_script_movs_0x8f0a0b
waitmovement 0x0
sound 0x9
hidesprite 0x1
checksound
applymovement 0xff ow_script_movs_0x8f0981
waitmovement 0x0
goto ow_script_0x8c7d62


.global ow_script_0x8c7d62
ow_script_0x8c7d62:
loadpointer 0x0 str_0x8f0984
callstd MSG_KEEPOPEN
fanfare 0x13e
loadpointer 0x0 str_0x8c7f7a
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
additem ITEM_VM01 0x1
loadpointer 0x0 str_0x8c7f9a
callstd MSG
fadescreen 0x1
hidesprite 0x2
fadescreen 0x0
addvar STORY_PROGRESS 0x2
releaseall
end


.ifdef LANG_GER
.global str_0x8eca2e

str_0x8eca2e:
    .string "Mit Team Violet und der\nRevolutionsarmee als Gegnern\lkönnen wir nicht standhalten.\lSelbst wir, von den Top Vier, sind\ldazu nicht im Stande..."
        
        
.global str_0x8eca11

str_0x8eca11:
    .string "Oh, PLAYER!\nDa bist du ja!"
        
        
.global str_0x8ec9d0

str_0x8ec9d0:
    .string "Darf ich dir Mia vorstellen, die\nArenaleiterin Silvanias?"
        
        
.global str_0x8ec921

str_0x8ec921:
    .string "Sehr erfreut! Danke, dass du uns\nim Kampf gegen Team Violet\lunterstützt.\pAls ich erfahren habe, dass Faun\nvon den Top Vier uns hilft, ist\lmir ein Stein vom Herzen gefallen."
        
        
.global str_0x8ec8fc

str_0x8ec8fc:
    .string "Sie sind Mitglied der Top Vier?"
        
        
.global str_0x8ec8ab

str_0x8ec8ab:
    .string "Oh, äh, ja! Ich bin zuständig für\ndie Regierung des östlichen Teils\lvon Theto."
        
        
.global str_0x8ec84d

str_0x8ec84d:
    .string "Faun ist ein berühmter\nTrainer. Viele sahen ihn sogar den\lPosten des Champs erklimmen."
        
        
.global str_0x8ec7d7

str_0x8ec7d7:
    .string "Nein, ich war diesbezüglich nie\nambitioniert.\pAber das tut auch nicht zur Sache,\nwir haben ein ernsthaftes Problem."
        
        
.global str_0x8ec6df

str_0x8ec6df:
    .string "Ja, in der Tat. Augenzeugen\nberichten, beobachtet zu haben,\lwie Team Violet in den Zeitwald\leingefallen ist. Einige geben auch\lan, Professor Primus gesehen zu\lhaben. Wir müssen also davon\lausgehen, dass Team Violet eine\lGeisel genommen hat."
        
        
.global str_0x87e807

str_0x87e807:
    .string "Im Zeitwald lebt ein\nPokémon, welches in der Lage ist,\ldie Zeit selbst zu beugen. In\lmeiner Jugend bin ich ihm sogar\lbegegnet..."
        
        
.global str_0x8f28b9

str_0x8f28b9:
    .string "Meine Begegnung mit Celebi war\nbezeichnend. Noch heute träume ich\lvon diesem Moment...\pEs hat mich vor etwas gewarnt, vor\neiner Bedrohung. Wenn das Pokémon\ldamit Team Violet gemeint hat,\lsind wir in ernsthaften\lSchwierigkeiten. Celebi kennt die\lZeit besser als jedes andere\lWesen, es kennt die Vergangenheit,\ldie Gegenwart und auch ...\p...\p...\pdie Zukunft."
        
        
.global str_0x8f3668

str_0x8f3668:
    .string "Soll das heißen, dass Team\nViolet Celebi Schaden zufügen\lwill?"
        
        
.global str_0x8f27cb

str_0x8f27cb:
    .string "Ich fürchte, dass es weitaus\nschlimmer sein könnte. Wenn Celebi\lmich damals vor Team Violet\lgewarnt hat, dann hat ihr Handeln\lAuswirkungen von unvorstellbarem\lAusmaß, so weitreichend, dass\lselbst die Zeit nicht verschont\lbleibt."
        
        
.global str_0x8f276d

str_0x8f276d:
    .string "Ich habe Team Violet\nüber den Zeitstein reden hören.\lVermutlich sind sie darauf aus!"
        
        
.global str_0x8f26b3

str_0x8f26b3:
    .string "Der Zeitstein? Das ergibt Sinn.\nSeit dem Verhängnis von Aktania\lwidmet sich Professor Primus der\lErforschung der Zeitstruktur.\lDeswegen wird Team Violet ihn als\lGeisel genommen haben."
        
        
.global str_0x8f2607

str_0x8f2607:
    .string "Das ist schrecklich! Aber ich\nkann die Arena nicht noch länger\lunbeaufsichtigt lassen. Gut, dass\lsich nun ein Mitglied der Top Vier\lum die Angelegenheit kümmert."
        
        
.global str_0x8f257b

str_0x8f257b:
    .string "Polizist: Lord Faun!\nEntschuldigen Sie, dass ich so\lhereinplatze, aber der Anführer\lder Revolutionsbewegung wurde nahe\lKaskada gesichtet."
        
        
.global str_0x8f0b3b

str_0x8f0b3b:
    .string "In Kaskada? Ich muss ihn\ntreffen... Vielleicht kann ich ihn\lvon seinem Vorhaben abbringen..."
        
        
.global str_0x8f0ad6

str_0x8f0ad6:
    .string "Entschuldige bitte, Mia, aber als\nTop Vier Mitglied muss ich der\lRevolutionsarmee gegenübertreten."
        
        
.global str_0x8f0a28

str_0x8f0a28:
    .string "Außerdem habe ich vollstes\nVertrauen, dass PLAYER diese\lSituation in den Griff bekommt.\lEr ist ein vorzüglicher Trainer,\lund ich muss es wissen, denn ich\lhabe ihn ausgebildet."
        
        
.global str_0x8f0a11

str_0x8f0a11:
    .string "Polizist: Gehen wir!"
        
        
.global str_0x8f0984

str_0x8f0984:
    .string "Wenn sich Faun auf dich\nverlässt, werde ich das auch tun.\lIch vertraue dir die Angelegenheit\lan."
        
        
.global str_0x8c7f7a

str_0x8c7f7a:
    .string "Mia übergibt PLAYER\nZerschneider!"
        
        
.global str_0x8c7f9a

str_0x8c7f9a:
    .string "Diese Versteckte Maschine nennt\nsich Zerschneider und kann\lGestrüpp und Pflanzen entfernen.\lIm Kampf gegen Team Violet sollte\lsie dir nützlich sein.\lIch werde zur Arena zurückkehren,\lwo du mich herausfordern kannst.\lErst nach einem Sieg über mich,\lwirst du in der Lage sein, die\lMaschine zu verwenden."
        
        
.elseif LANG_EN

.endif
