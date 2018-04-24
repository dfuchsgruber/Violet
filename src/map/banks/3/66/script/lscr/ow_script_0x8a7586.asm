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
multichoice 0x0 0x0 0x0 0x0
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
    .string "Mein Sohn und PLAYER.\nDa seid ihr, zwei frisch gebackene\lTrainer und schon stark genug, es\lmit den Schergen von Team Violet\laufzunehmen. Keiner weiß so recht,\lwas diese Gruppe eigentlich im\lSchilde führt, aber scheinbar sind\lsie hinter einem Objekt namens\lZeitstein her. Ich als Archeologe\lmuss zugeben, bereits von diesem\lominösen Stein gehört zu haben. Er\lwird in vielen Legenden erwähnt\lund soll den Fluss der Zeit\laufrecht erhalten... Wo er liegt\lweiß aber keiner!\l...\l...\lNun aber genug dazu. Ich wollte\leuch ohnehin aus einem anderem\lGrund sehen: Auch ich wollte euch\lbeide auf eurem neuen Weg\lunterstützen.\pElise, würdest du?"
        
        
.global str_0x8a7f3d

str_0x8a7f3d:
    .string "Oh ja, sofort, Professor\nTann! Ich bin schon auf dem Weg!"
        
        
.global str_0x8a7e8d

str_0x8a7e8d:
    .string "Darf ich vorstellen? Meine\nAssistentin Elise. Sie ist die\lTochter eines Kollegen von mir und\lhilft mir, beim Digitalisieren\lmeiner archeologischen Studien."
        
        
.global str_0x8a7dbf

str_0x8a7dbf:
    .string "In der Tat, ich bin die\nTochter von Professor Primus,\leinem angesehenen Physiker der\lThetoregion. Als Angestellte der\lLaZ. Cooperation bin ich\lmaßgeblich an der Entwicklung des\lPokepads beteiligt."
        
        
.global str_0x8a7930

str_0x8a7930:
    .string "Ihr kennt das Pokepad nicht?"
        
        
.global str_0x8a78f1

str_0x8a78f1:
    .string "Das ist der Grund, wieso ich sie\nherbestellt habe, Elise."
        
        
.global str_0x8a7830

str_0x8a7830:
    .string "Natürlich! Ich Dummerchen. Das\nPokepad ist ein Gadget, auf dem\lman die verschiedensten Apps\linstallieren kann. Schon bald wird\lein Trainerdasein ohne das Pokepad\lnicht mehr denkbar sein."
        
        
.global str_0x8a77ae

str_0x8a77ae:
    .string "Ganz genau. Und als Starthilfe\ngewissermaßen will ich euch beiden\ljeweils eines dieser Geräte\lschenken."
        
        
.global str_0x8a7789

str_0x8a7789:
    .string "Wirklich? Fantastisch, Papi!\nJuhu!"
        
        
.global str_0x8a776a

str_0x8a776a:
    .string "Vielen Dank, Professor Tann."
        
        
.global str_0x8aa319

str_0x8aa319:
    .string "PLAYER hat das Pokepad\nerhalten!"
        
        
.global str_0x8a7751

str_0x8a7751:
    .string "Danke, Elise!"
        
        
.global str_0x8a76ee

str_0x8a76ee:
    .string "Aber das soll noch nicht alles\nsein. Mein nächtes Geschenk ist\lmit einer Bitte verbunden."
        
        
.global str_0x8aabee

str_0x8aabee:
    .string "Einer Bitte? Du bist schon\nwieder so ein Spielverderber,\lPapi!"
        
        
.global str_0x8aa57d

str_0x8aa57d:
    .string "Ich darf doch bitten! Der\nProfessor macht dir ein Geschenk,\ldu könntest ruhig mal etwas\lDankbarkeit zeigen..."
        
        
.global str_0x8aa381

str_0x8aa381:
    .string "Ach, das macht gar nichts, Elise.\nIch kenne meinen Sohn gut genug,\lum zu wissen, dass er nur Späße\lmacht...\lWie dem auch sei - vor vielen\lJahren entwickelte ein genialer\lKopf namens Professor Eich den\lPokedex, ein Gerät, welches Daten\lüber gesehene und gefangene\lPokémon aufzeichnet. Mit der\lEntwicklung des Pokepads sah man\lden Pokedex immer seltener, bis\ldieser schließlich digitalisiert\lund ins Pokepad integriert wurde.\lWenn ihr erlaubt, würde ich gerne\ldie Pokedex-App auf eurem Pokepad\linstallieren."
        
        
.global str_0x8aa372

str_0x8aa372:
    .string "Danke, Papi!"
        
        
.global str_0x8aa338

str_0x8aa338:
    .string "Die Pokedex-App wurde auf dem\nPokepad installiert!"
        
        
.global str_0x8aa305

str_0x8aa305:
    .string "Dankesehr, Elise."
        
        
.global str_0x8aa27f

str_0x8aa27f:
    .string "Gut, gut. Hätten wir das also auch\nabgehakt. Ich nehme an, ihr beiden\lhabt in der Trainerschule gelernt,\lwie man ein Pokémon fängt?"
        
        
.global str_0x8aa22a

str_0x8aa22a:
    .string "Natürlich, Papi! Herr Faun hat uns\nalles beigebracht, was ein Trainer\lkönnen muss!"
        
        
.global str_0x8aa1b8

str_0x8aa1b8:
    .string "Sprecht ihr etwa von dem Faun? Dem\nruhmreichen Trainer vergangener\lTage? Den, den sie die \rosa\lFaust\ nannten?"
        
        
.global str_0x8aa184

str_0x8aa184:
    .string "Kennst du etwa noch einen anderen\nFaun, Elise?"
        
        
.global str_0x8a9f82

str_0x8a9f82:
    .string "Faun war früher ein mal ein großer\nTrainer, eine Berühmtheit, wenn\lman so will. Doch irgendwann im\lLeben kommt der Punkt, da man\letwas an kommende Generationen\lweitergeben will und so hat Faun\leine Trainerschule eröffnet, um\langehenden Trainern sein Wissen\lmitzugeben.\lUm aber aufs Thema zurückzukommen:\lDer Pokedex registriert Daten,\lwenn ihr einem Pokémon begegnet.\lFangt ihr es, so speichert er noch\lmehr Informationen darüber ab.\lNatürlich braucht ihr, um Pokémon\lfangen zu können, erst einmal\lPokebälle."
        
        
.global str_0x8a9c83

str_0x8a9c83:
    .string "RIVAL hat 5 Pokebälle erhalten!"
        
        
.global str_0x8a9a4c

str_0x8a9a4c:
    .string "Ich kann es noch immer nicht\nfassen - ich habe euch beide schon\lgekannt, da habt ihr noch im\lKindbett gelegen und jetzt zieht\lihr hinaus in die weite Welt, auf\lder Suche nach Ruhm und Stärke.\lWenn ich euch einen Rat auf den\lWeg mitgeben will, dann diesen:\lKämpft nicht für Macht, kämpft\lnicht für Achtung, kämpft nicht\lohne Herz. Pokémon sind Lebewesen\lwie wir Menschen, gleichgestellt.\lWir messen einander im Kampf des\lSpaßes halber, nicht um zu\lvernichten. Nur, wer ein starkes\lBand zwischen sich und seinen\lPokémon spannt, kann in dieser\lWelt erfolgreich sein."
        
        
.global str_0x8a99f1

str_0x8a99f1:
    .string "Das war eine schöne Ansprache,\nProfessor. Wirklich fesselnd und\lnur allzu zutreffend."
        
        
.global str_0x8a9950

str_0x8a9950:
    .string "Du warst schon immer einer, der\nviel redet, Papi! Immer diese öden\lAnsprachen. Es ist doch\lselbstverständlich, dass Trainer\lund Pokémon Freunde werden müssen!"
        
        
.global str_0x8a992f

str_0x8a992f:
    .string "(Was antwortest du?)"
        
        
.global str_0x8a9771

str_0x8a9771:
    .string "Ich danke Ihnen vielmals,\nProfessor, auch wenn es sehr naiv\list, zu glauben, dass Freundschaft\lund Liebe allein in dieser Welt\lbestehen können. Nur wer ehrgeizig\lsein Ziel nicht aus den Augen\lverliert, kann auch erfolgreich\lsein. Natürlich enstehen auch\ldabei Freunschaften. Ihre Worte\lsind hoffnungsvoll, und voller\lHoffnung werde ich mich dieser\lWelt stellen."
        
        
.global str_0x8ab043

str_0x8ab043:
    .string "Es freut mich, wenn auch meine\nIdeale in der kommenden Generation\lweiterleben. Die Hoffnung, die ich\leuch beiden auf den Weg gebe, wird\lder Grundstein für eine neue Zeit\lsein, eure Zeit."
        
        
.global str_0x8aafd4

str_0x8aafd4:
    .string "Auch ich wünsche euch beiden viel\nGlück auf eurem Weg. Bei Fragen\lstehe ich euch gerne mit Rat zur\lSeite."
        
        
.global str_0x8a965b

str_0x8a965b:
    .string "Ich danke Ihnen vielmals,\nProfessor. In Ihren Worten steckt\lnichts als die Wahrheit. Wahre\lKraft findet man nur in dem Band,\ldas Mensch und Pokémon\lgleichermaßen vereint. Ihre Worte\lsind voller Hoffnung, und diese\lHoffnung werde ich hinaustragen in\ldieser weite Welt! "
        
        
.global str_0x8ad201

str_0x8ad201:
    .string "PLAYER hat 5 Pokebälle\nerhalten!"
        
        
.global str_route_2_lab_choice_0

str_route_2_lab_choice_0:
    .string "Zustimmen"
        
        
.global str_route_2_lab_choice_1

str_route_2_lab_choice_1:
    .string "Widersprechen"
        
        
.elseif LANG_EN

.endif
