.include "vars.s"

.global lscr_0x81c4d9

lscr_0x81c4d9:
	.byte 0x4
.word lscr_0x83074b
	.byte 0x2
.word lscr_0x81c541
	.byte 0x0


.align 4
.global lscr_0x83074b

lscr_0x83074b:
	.hword STORY_PROGRESS, 0x1a
	.word ow_script_0x81c512
	.hword 0x0


.align 4
.global lscr_0x81c541

lscr_0x81c541:
	.hword STORY_PROGRESS, 0x1a
	.word ow_script_0x81c406
	.hword 0x0
.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x8ecac3
.global ow_script_0x81c406
.global ow_script_0x81c51d
.global ow_script_0x8f7200
.global ow_script_0x8c7d62
.global ow_script_0x81c512
.global ow_script_0x8fbc6c

ow_script_movs_0x8eca2a:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8eca0e:
.byte STEP_UP
.byte STOP


ow_script_movs_0x8ec91e:
.byte SAY_QUESTION
.byte STOP


ow_script_0x81c406:
checkflag SILVANIA_FOREST_FLASHBACK_DONE
gotoif EQUAL ow_script_0x8f7200
loadpointer 0x0 str_0x8eca2e
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
sound 0x15
applymovement 0x2 ow_script_movs_0x8eca2a
applymovement 0x1 ow_script_movs_0x8eca2a
waitmovement 0x0
loadpointer 0x0 str_0x8eca11
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0xff ow_script_movs_0x8eca0e
waitmovement 0x0
loadpointer 0x0 str_0x8ec9d0
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT

loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8ec921
callstd MSG
special 0xF

sound 0x15
applymovement 0xff ow_script_movs_0x8ec91e
waitmovement 0x0
loadpointer 0x0 str_0x8ec8fc
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8ec8ab
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT

loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8ec84d
callstd MSG
special 0xF

loadpointer 0x0 str_0x8ec7d7
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT

loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8ec6df
callstd MSG
special 0xF

loadpointer 0x0 str_0x87e807
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
goto ow_script_0x8ecac3


ow_script_0x8ecac3:
goto ow_script_0x8fbc6c


ow_script_0x8fbc6c:
writebytetooffset 0x2 0x2036e28
warpmuted 0x1 0x1 0x0 0x0 0x0
addvar STORY_PROGRESS 0x1
waitstate
end


ow_script_movs_0x8f28b5:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8f28b2:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x8f27c8:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8f26b0:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8f0a0b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8f0981:
.byte LOOK_UP
.byte STOP


ow_script_0x8f7200:
loadpointer 0x0 str_0x8f28b9
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x2 ow_script_movs_0x8f28b5
waitmovement 0x0

loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8f3668
callstd MSG
special 0xF

applymovement 0x1 ow_script_movs_0x8f28b2
waitmovement 0x0
loadpointer 0x0 str_0x8f27cb
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x1 ow_script_movs_0x8f27c8
applymovement 0x2 ow_script_movs_0x8f27c8
waitmovement 0x0
loadpointer 0x0 str_0x8f276d
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8f26b3
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x2 ow_script_movs_0x8f26b0
waitmovement 0x0

loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8f2607
callstd MSG
special 0xF

sound 0x63
showsprite 0x3
checksound
sound 0x15
applymovement 0x1 ow_script_movs_0x8eca2a
applymovement 0x2 ow_script_movs_0x8eca2a
applymovement 0xff ow_script_movs_0x8eca2a
waitmovement 0x0

loadpointer 0x0 str_0x8f257b
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT

loadpointer 0x0 str_0x8f0b3b
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x1 ow_script_movs_0x8f28b2
waitmovement 0x0
loadpointer 0x0 str_0x8f0ad6
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x1 ow_script_movs_0x8f27c8
waitmovement 0x0
loadpointer 0x0 str_0x8f0a28
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT



loadpointer 0x0 str_0x8f0a11
show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG

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


ow_script_0x8c7d62:
loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8f0984
callstd MSG_KEEPOPEN
special 0xF

fanfare 0x13e
loadpointer 0x0 str_0x8c7f7a
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
additem ITEM_VM01 0x1
loadpointer 0 str_mia
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8c7f9a
callstd MSG
special 0xF

fadescreen 0x1
hidesprite 0x2
fadescreen 0x0
addvar STORY_PROGRESS 0x2
releaseall
end


.ifdef LANG_GER

str_mia:
	.string "Rosalie"


str_0x8eca2e:
	.autostring 35 2 "Team Violet und die Revolutionsarmee gleichzeitig zu bekämpfen kann auch ich nicht bewerkstelligen DOTS"



str_0x8eca11:
    .autostring 35 2 "Oh, PLAYER!\nDa bist du ja!"



str_0x8ec9d0:
	.autostring 35 2 "Das ist Rosalie, die Arenaleiterin von Kranzdorf."



str_0x8ec921:
	.autostring 35 2 "Freut mich!\nIch danke dir, dass du uns im Kampf gegen Team Violet unterstützen willst.\pDOTS DOTS DOTS\pIch muss ehrlich sagen, als ich erfahren habe, dass uns Faun von den Top Vier unterstützt, ist mir ein Stein vom Herzen gefallen DOTS"


str_0x8ec8fc:
    .autostring 35 2 "Herr Faun, Sie sind ein Mitglied der Top Vier?"



str_0x8ec8ab:
	.autostring 35 2 "Ja, das bin ich!\pDenkst du, ich würde mir anmaßen, euch Rotzlöffeln etwas beizubringen, wenn ich nicht selbst etwas vorzuweisen hätte?"



str_0x8ec84d:
    .autostring 35 2 "Faun ist einer der Begründer der Top Vier.\pViele haben sich ihn sogar als Champion gewünscht!"



str_0x8ec7d7:
    .autostring 35 2 "Ach, der Posten des Champions wäre nichts für mich gewesen.\pWir alle standen schon immer im Schatten von Lucius DOTS\pAber das tut jetzt nichts zur Sache.\pWir haben einige gewaltige Probleme, die die es zu lösen gilt!"


str_0x8ec6df:
	.autostring 35 2 "Augenzeugen berichten, dass Team Violet den renomierten Physiker Professor Primus als Geisel genommen hat.\pSollte das zutreffen, wird die ganze Sache weitaus heikler DOTS"



str_0x87e807:
	.autostring 35 2 "Ist Primus nicht für seine Forschung bezüglich der Raumzeit bekannt?\pDOTS DOTS DOTS\pDas würde zumindest einen Sinn ergeben.\pIm Kranzdorf-Wald lebt ein Pokémon, das in der Lage ist, die Zeit zu manipulieren DOTS\pIch bin ihm in meinen jungen Tagen selbst einmal begegnet DOTS"


str_0x8f28b9:
	.autostring 35 2 "Wenn ich an meine Begegnung mit Celebi zurückdenke DOTS\pIch erinnere mich! DOTS\pEs hat mich vor einer Bedrohung gewarnt, die Thetos Zukunft gefährden würde.\pWenn es sich dabei auf Team Violet bezogen hat, stehen wir vor womöglich gravierenden Schwierigkeiten."


str_0x8f3668:
    .autostring 35 2 "Sie meinen doch nicht etwa, dass Team Violet dem Pokémon Celebi Schaden zufügen will, Lord Faun?"



str_0x8f27cb:
    .autostring 35 2 "Schlimmer noch.\pCelebi hat ein Gespür für die Zukunft.\pWomöglich ist es die Organisation Team Violet selbst, die das Fortbestehen der Region gefährdet."


str_0x8f276d:
    .autostring 35 2 "Ich habe einige Team Violet Rüpel über einen seltsamen Zeistein reden hören.\pSie haben Professor Tann in Bredouille gebracht, dass er ihnen etwas über diesen Stein verrät DOTS"



str_0x8f26b3:
	.autostring 35 2 "Der Zeitstein ist ein legendäres Artefakt, in dem laut der Erzählung das Herz der Zeit selbst schlagen soll.\pDOTS DOTS DOTS\pWenn Team Violet es auf dieses Objekt abgesehen hat, würde es auch Sinn ergeben, warum sie Professor Primus als Geisel genommen haben."



str_0x8f2607:
    .autostring 35 2 "Sind diese Legenden denn wahr?\pDOTS DOTS DOTS\pIch bin wirklich froh, dass ein Mitglied der Top Vier sich darum kümmert DOTS DOTS DOTS"


str_0x8f257b:
	.autostring 35 2 "Lord Faun!\pEntschuldigen Sie die Störung, aber der Anführer der Revolutionsbewegung wurde in Kaskada gewichtet!"



str_0x8f0b3b:
    .autostring 35 2 "In Kaskada?\pVielleicht hole ich ihn noch ein.\pWenn ich Albus überzeugen kann, von seiner irrsinnigen Idee abzulassen DOTS\pDOTS DOTS DOTS"



str_0x8f0ad6:
    .autostring 35 2 "Es tut mir leid, Rosalie DOTS\pAber um den Revolutionsanführer aufzuhalten, bedarf es eines Top Vier Mitglieds.\pUnd ich hoffe, die Sache friedlich lösen zu können.\pIch vertraue dir und PLAYER die Lage an."



str_0x8f0a28:
    .autostring 35 2 "Ich habe vertrauen, dass ihr die Sache in den Griff kriegt.\pImmerhin habe ich euch beide ausgebildet!"



str_0x8f0a11:
    .autostring 35 2 "Machen wir uns auf den Weg, Lord Faun!"



str_0x8f0984:
	.autostring 35 2 "Das ist gar nicht gut.\pEin Kommandant von Team Violet DOTS\pDas sind gefährliche Leute!\pDOTS DOTS DOTS\pAber wir haben wohl keine Wahl, was?\pWenn du im Kranzdorf-Wald zurecht kommen willst, wirst du das hier benötigen."


str_0x8c7f7a:
    .autostring 35 2 "Rosalie übergibt PLAYER\nZerschneider!"



str_0x8c7f9a:
	.autostring 35 2 "Leider kannst du diese Versteckte Maschine erst benutzen, wenn du den Waldorden im Kampf gegen mich errungen hast.\pWir sollten diese Formalität also schnell über die Bühne bringen.\pAußerdem kann ich mir so ein Bild von deinen Fähigkeiten machen.\pWir werden jedes Bisschen Glück brauchen, dass wir kriegen können.\pIch werde in die Arena zurückkehren.\pWir sollten keine Zeit verlieren DOTS"

.elseif LANG_EN

.endif


ow_script_0x81c512:
checkflag SILVANIA_FOREST_FLASHBACK_DONE
gotoif EQUAL ow_script_0x81c51d
end


ow_script_0x81c51d:
spriteface 0xff 0x2
spriteface 0x1 0x0
spriteface 0x2 0x0
end