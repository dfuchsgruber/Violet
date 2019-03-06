.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8a820e
ow_script_movs_0x8a820e:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a8214
ow_script_movs_0x8a8214:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x80358f
ow_script_movs_0x80358f:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a7f34
ow_script_movs_0x8a7f34:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8a7f2b
ow_script_movs_0x8a7f2b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a794f
ow_script_movs_0x8a794f:
.byte SAY_QUESTION
.byte STOP


.global ow_script_movs_0x8a792d
ow_script_movs_0x8a792d:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a78ed
ow_script_movs_0x8a78ed:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8a7586
ow_script_0x8a7586:
applymovement 0x3 ow_script_movs_0x8a820e
applymovement 0xff ow_script_movs_0x8a8214
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a7f97
callstd MSG
special 0x7
sound 0x15
applymovement 0x2 ow_script_movs_0x80358f
waitmovement 0x0
checksound
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7f3d
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8a7f34
waitmovement 0x0
sound 0x7
checksound
applymovement 0x2 ow_script_movs_0x8a7f2b
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a7e8d
callstd MSG
special 0x7
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7dbf
callstd MSG
special 0x7
sound 0x15
applymovement 0xff ow_script_movs_0x8a794f
applymovement 0x3 ow_script_movs_0x8a794f
waitmovement 0x0
checksound
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7930
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8a792d
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a78f1
callstd MSG
special 0x7
sound 0x15
applymovement 0x2 ow_script_movs_0x8a78ed
waitmovement 0x0
checksound
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7830
callstd MSG
special 0x7
call ow_script_0x8a91d4
loadpointer 0x0 str_0x8a77ae
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a7789
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a776a
callstd MSG_FACE
special 0x7
goto ow_script_0x8a934f


.global ow_script_movs_0x8a7761
ow_script_movs_0x8a7761:
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_IN_PLACE_LEFT
.byte STEP_IN_PLACE_LEFT
.byte STOP


.global ow_script_movs_0x8a76e4
ow_script_movs_0x8a76e4:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a774a
ow_script_movs_0x8a774a:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x803489
ow_script_movs_0x803489:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8aa36d
ow_script_movs_0x8aa36d:
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP


.global ow_script_movs_0x8aa1b5
ow_script_movs_0x8aa1b5:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8aa181
ow_script_movs_0x8aa181:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8a9a49
ow_script_movs_0x8a9a49:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8a934f
ow_script_0x8a934f:
fanfare 0x13e
loadpointer 0x0 str_0x8aa319
callstd MSG_KEEPOPEN
setflag POKEDEX
closeonkeypress
waitfanfare
applymovement 0x2 ow_script_movs_0x8a7761
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x8a76e4
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a7751
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8a774a
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x803489
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a76ee
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8aabee
callstd MSG
special 0x7
nop
nop
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8aa57d
callstd MSG
special 0x7
call ow_script_0x8a7095
loadpointer 0x0 str_0x8aa381
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8aa36d
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8aa372
callstd MSG
special 0x7
fanfare 0x13e
applymovement 0x2 ow_script_movs_0x8aa36d
loadpointer 0x0 str_0x8aa338
callstd MSG_KEEPOPEN
waitmovement 0x0
waitfanfare
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8aa305
callstd MSG
special 0x7
call ow_script_0x8a7095
loadpointer 0x0 str_0x8aa27f
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8aa22a
callstd MSG
special 0x7
sound 0x15
applymovement 0x2 ow_script_movs_0x8a78ed
waitmovement 0x0
checksound
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8aa1b8
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8aa1b5
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8aa184
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8aa181
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a9f82
callstd MSG
special 0x7
applymovement 0x1 ow_script_movs_0x8aa36d
waitmovement 0x0
sound 0x7
checksound
loadpointer 0x0 str_0x8a9c83
callstd MSG
applymovement 0x2 ow_script_movs_0x8aa36d
call ow_script_0x8ab100
waitmovement 0x0
call ow_script_0x8a7095
loadpointer 0x0 str_0x8a9a4c
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8a9a49
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a99f1
callstd MSG
special 0x7
call ow_script_0x89ba6e
loadpointer 0x0 str_0x8a9950
callstd MSG_FACE
special 0x7
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 str_0x8a992f
callstd MSG
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a9640
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a9771
callstd MSG
special 0x7
setvar 0x8000 0xfe
goto ow_script_0x8aac32


.align 4
choice:
    .word str_route_2_lab_choice_0, 0
    .word str_route_2_lab_choice_1, 0

.global ow_script_movs_0x8ab040
ow_script_movs_0x8ab040:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8aafce
ow_script_movs_0x8aafce:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x8aac32
ow_script_0x8aac32:
special2 0x8000 0xc
call ow_script_0x8a7095
loadpointer 0x0 str_0x8ab043
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8ab040
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8aafd4
callstd MSG
special 0x7
applymovement 0x2 ow_script_movs_0x8aafce
waitmovement 0x0
goto ow_script_0x8ad21f


.global ow_script_0x8ad21f
ow_script_0x8ad21f:
setflag ROUTE_2_RIVAL_INSIDE_LAB
setvar STORY_PROGRESS 0xf
end


.global ow_script_0x8a9640
ow_script_0x8a9640:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a965b
callstd MSG
special 0x7
setvar 0x8000 0x2
goto ow_script_0x8aac32


.global ow_script_0x8ab100
ow_script_0x8ab100:
fanfare 0x13e
additem ITEM_POKEBALL 0x5
loadpointer 0x0 str_0x8ad201
callstd MSG_KEEPOPEN
closeonkeypress
waitfanfare
return


.global ow_script_movs_0x8037d2
ow_script_movs_0x8037d2:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x8a91d4
ow_script_0x8a91d4:
applymovement 0x1 ow_script_movs_0x8037d2
waitmovement 0x0
call ow_script_0x8a7095
return


.ifdef LANG_GER
.global str_0x8a7f97

str_0x8a7f97:
	.autostring 35 2 "PLAYER und mein eigener Sohn!\pZwei frisch gebackene Trainer!\pUnd schon stark genug, diesen alten Herren aus einer misslichen Lage zu befreien.\pDiese Team Violet Rüpel werden zu einem echten Problem in Theto.\pIn letzter Zeit gehen sie immer agressiver gegen die Bürger vor.\pUnd was dieser Wirbel um einen Zeitstein bedeuten soll, kann ich mir auch nicht recht erklären.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWie dem auch sei.\nDa ihr nun endlich die Trainerschule und den alten Faun hinter euch gelassen habt, will ich euch auf dem Weg, den ihr nun bestreitet, unterstützen.\pElise, würdest du bitteDOTS"

.global str_0x8a7f3d

str_0x8a7f3d:
    .autostring 35 2 "Natürlich, Professor Tann.\pIch bin schon unterwegsDOTS"
        
        
.global str_0x8a7e8d

str_0x8a7e8d:
	.autostring 35 2 "Darf ich vorstellen?\nMeine Assistentin Elise.\pSie ist die Tochte eines befreundeten Professors und selbst ein wahres Forschungass.\pSie forscht in der Laz.Corp an der Virtualisierung von Pokémon-Daten.\pScheinbar sind dazu auch die Ergebnisse meiner Forschung relevant.\pDOTS DOTS DOTS"
        
.global str_0x8a7dbf

str_0x8a7dbf:
	.autostring 35 2 "Freut mich außerordentlich!\pIch sammle allerlei Daten, die für die Entwicklung des Poképads relevant sein könnten."
        
        
.global str_0x8a7930

str_0x8a7930:
    .string "Ihr kennt das Poképad nicht?"
        
        
.global str_0x8a78f1

str_0x8a78f1:
    .autostring 35 2 "Deswegen habe ich sie ja herbestellt."
        
        
.global str_0x8a7830

str_0x8a7830:
	.autostring 35 2 "Ach natürlich! Wie dumm von mir.\pDas Poképad ist der Höhepunkt unserer Technologie.\pEin Muss für jeden Trainer!\pMit einer Vielzahl an Apps, die man für das Poképad installieren kann, wird eine Trainerkarriere ohne es bald nicht mehr denkbar sein!"

.global str_0x8a77ae

str_0x8a77ae:
    .autostring 35 2 "Ganz genau!\pUnd als Starthilfe will ich euch beiden jeweils eines dieser Geräte schenken."
        
        
.global str_0x8a7789

str_0x8a7789:
    .autostring 35 2 "Wirklich? Fantastisch, Papi!\nJuhu!"
        
        
.global str_0x8a776a

str_0x8a776a:
    .autostring 35 2 "Vielen Dank, Professor Tann."
        
        
.global str_0x8aa319

str_0x8aa319:
    .autostring 35 2 "PLAYER hat das Poképad erhalten!"
        
        
.global str_0x8a7751

str_0x8a7751:
    .autostring 35 2 "Danke, Elise!"
        
        
.global str_0x8a76ee

str_0x8a76ee:
    .autostring 35 2 "Das ganze ist allerdings mit einer Bitte verbunden."
        
        
.global str_0x8aabee

str_0x8aabee:
    .autostring 35 2 "Och, du bist ein immer so ein Spielverderber, Papi!"
        
        
.global str_0x8aa57d

str_0x8aa57d:
    .autostring 35 2 "Ich darf doch bitten!\pDein Vater macht dir ein Geschenk, also könntest du ruhig etwas mehr Dankbarkeit zeigen!"
        
        
.global str_0x8aa381

str_0x8aa381:
	.autostring 35 2 "Haha!\pMein Sohn meint es doch gar nicht so, er ist nur immer etwas hitzköpfig.\pGanz genauso, wie ich es früher war.\pBei der Bitte handelt es sich um Folgendes:\pEin anderer Kollege von mir namens Eich sammelt Daten über die Pokémon auf unserer Welt.\pDazu entwickelte er den Pokédex, welcher Informationen über gesehene Pokémon aufzeichnet.\pNun hat die Laz.Corp die Funktionalität dieses Pokédex aber bereits Digitalisiert und eine App für das Poképad entwickelt, die Aufzeichnungen über gesehene Pokémon anfertigt.\pIch würde diese App gerne auf euren Poképads installieren und euch darum bitten, möglichst viele verschiedene Pokémonarten einzufangen und so Daten zu sammeln."

        
.global str_0x8aa372

str_0x8aa372:
    .autostring 35 2 "Geht in Ordnung!\nDanke Papi!"
        
        
.global str_0x8aa338

str_0x8aa338:
    .autostring 35 2 "Die Pokedex-App wurde auf dem Poképad installiert!"
        
        
.global str_0x8aa305

str_0x8aa305:
    .autostring 35 2 "Dankesehr, Elise."
        
        
.global str_0x8aa27f

str_0x8aa27f:
	.autostring 35 2 "Sehr schön!\pIch wusste, dass ich mich auf euch verlassen kann.\pIch nehme an, ihr beiden habt in der Trainerschule gelernt, wie man Pokémon fängt?"
        
.global str_0x8aa22a

str_0x8aa22a:
    .autostring 35 2 "Natürlich Papi!\pHerr Faun hat uns alles beigebracht, was ein Trainer wissen muss!"
        
        
.global str_0x8aa1b8

str_0x8aa1b8:
    .autostring 35 2 "Sprecht ihr von dem Faun?\pDem großen Trainer, der in der VergangenheitDOTS"
        
        
.global str_0x8aa184

str_0x8aa184:
    .autostring 35 2 "Kennst du etwa noch einen anderen Faun?"
        
        
.global str_0x8a9f82

str_0x8a9f82:
	.autostring 35 2 "Ihr müsst wissen, dass Faun eine wahre Trainerlegende ist.\pAber irgendwann im Leben kommt einmal der Punkt, an dem man etwas an die nächste Generation weitergeben will.\pDeswegen hat Faun seine Schule eröffnet, denke ich.\pUm aber wieder aufs Thema zurückzukommen.\pBitte versucht, viele verschiedene Pokémon einzufangen und so wertvolle Daten zu sammeln.\pDafür benötigt ihr natürlich Pokébälle und großzügig, wie ich bin, werde ich euch auch diese schenken."
        
.global str_0x8a9c83

str_0x8a9c83:
    .autostring 35 2 "RIVAL hat 5 Pokebälle erhalten!"
        
        
.global str_0x8a9a4c

str_0x8a9a4c:
    .autostring 35 2 "Hach, da werde ich wirklich nostalgisch, wenn ich euch beide ansehe.\pIch erinnere mich noch an meine Jugend!\pDas waren Zeiten, als die Top Vier das Land gerade eroberten.\pIch frage mich, wie eure Generation diese Welt bewegen wird!"
        
        
.global str_0x8a99f1

str_0x8a99f1:
    .autostring 35 2 "Ich bin mir sicher, dass man von den beiden noch viel hören wird!"
        
        
.global str_0x8a9950

str_0x8a9950:
    .autostring 35 2 "Und wie man von mir hören wird!\pEs würde mich nicht überraschen, wenn ich eines Tages als Champion an der Spitze dieser Region stehe!"

        
.global str_0x8a992f

str_0x8a992f:
    .autostring 35 2 "(Was antwortest du?)"
        
        
.global str_0x8a9771

str_0x8a9771:
	.autostring 35 2 "Auch ich werde mir in der Trainerwelt einen Namen machen.\pEines Tages werde ich auch die Top Vier selbst herausfordern!"
        
.global str_0x8ab043

str_0x8ab043:
    .autostring 35 2 "Das sind großartige Ziele, die ihr euch da gesetzt habt!\pIch bin mir sicher, dass ihr erreichen werdet, wovon ihr träumt!\pUnd nun will ich euch nicht weiter aufhalten."
        
.global str_0x8aafd4

str_0x8aafd4:
	.autostring 35 2 "Ich bin auch überzeugt, dass ihr das Zeug zu großen Trainer habt!"
        
        
.global str_0x8a965b

str_0x8a965b:
    .autostring 35 2 "Mein oberstes Ziel ist es, den Menschen und Pokémon in dieser Region zu helfen.\pDaran werde ich alles setzten."
        
.global str_0x8ad201

str_0x8ad201:
    .string "PLAYER hat 5 Pokebälle\nerhalten!"
        
        
.global str_route_2_lab_choice_0

str_route_2_lab_choice_0:
    .string "Den Menschen helfen"
        
        
.global str_route_2_lab_choice_1

str_route_2_lab_choice_1:
    .string "Ruhm erringen"
        
        
.elseif LANG_EN

.endif
