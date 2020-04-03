.include "vars.s"
.include "map_adjacency_types.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "ordinals.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"
.include "items.s"

.global ow_script_map_3_41_trainer_7
.global ow_script_map_3_41_trainer_20
.global ow_script_map_3_7_route_2_east_trainer_0
.global ow_script_0x8dc94e
.global ow_script_0x880ba0
.global ow_script_0x1aba6e
.global ow_script_map_3_41_trainer_10
.global ow_script_map_3_41_trainer_11
.global ow_script_map_3_41_trainer_1
.global ow_script_0x1abab4
.global ow_script_0x8dce6c
.global ow_script_0x8305a5
.global ow_script_map_3_41_trainer_9
.global ow_script_0x877bed
.global ow_script_0x880be5
.global ow_script_0x1aba89
.global ow_script_0x947e82
.global ow_script_0x1abacd
.global ow_script_map_3_41_trainer_3
.global ow_script_0x8ac1e8
.global ow_script_map_3_41_trainer_19
.global ow_script_0x93d5cd
.global ow_script_map_3_41_trainer_14
.global ow_script_0x8fb0c5
.global ow_script_map_3_41_trainer_15
.global ow_script_map_3_41_trainer_12
.global ow_script_0x8aaf95
.global ow_script_map_3_41_trainer_0
.global ow_script_0x8ac217
.global ow_script_0x87f942
.global ow_script_0x947e76
.global ow_script_0x8304ac
.global ow_script_map_3_41_trainer_2
.global ow_script_map_3_7_route_2_east_trainer_1
.global ow_script_map_3_41_trainer_8
.global ow_script_0x8fb0b2
.global ow_script_0x8448c2
.global ow_script_0x8cb3c8
.global ow_script_0x880bcd
.global ow_script_0x8fb105
.global ow_script_0x880bd9
.global ow_script_map_3_41_trainer_21
.global ow_script_map_3_41_trainer_16
.global ow_script_map_3_41_trainer_22
.global ow_script_0x1abaa2
.global ow_script_0x880b86
.global ow_script_map_3_41_trainer_4
.global ow_script_map_3_41_trainer_18
.global ow_script_map_3_7_route_2_east_trainer_2
.global ow_script_0x931332
.global ow_script_0x8dc43a
.global ow_script_0x8ac33f
.global ow_script_0x8dcb4e
.global ow_script_map_3_41_trainer_6
.global ow_script_0x8305ae
.global ow_script_0x8fb10e
.global ow_script_map_3_41_trainer_13
.global ow_script_0x8fafe1
.global ow_script_map_3_41_trainer_17
.global ow_script_0x8fb076
.global ow_script_map_3_41_trainer_5
.global ow_script_0x830543
.global ow_script_0x8ac281
.global ow_script_0x8c8acf

ow_script_map_3_41_trainer_7:
loadpointer 0x0 str_0x80f654
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x80f654:
    .string "In dem Haus dort oben wohnt\nProfessor Tann. Du solltest ihn\lunbedingt mal besuchen!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_4:
trainerbattlestd 0x0 0x13 0x0 str_0x80f360 str_0x80f391
loadpointer 0x0 str_0x80f391
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x80f360:
    .string "Sieh mal, was ich mir für Käfer\ngefangen habe!"



str_0x80f391:
    .string "Meine Käfer!!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_3:
trainerbattlestd 0x0 0x14 0x0 str_0x80f3b7 str_0x80f40b
loadpointer 0x0 str_0x80f40b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x80f3b7:
    .string "Als Lady lehne ich keine\nHerausforderung ab! Benimm dich\laber gut!"



str_0x80f40b:
    .string "Du hast dich nicht gut\nbenommen!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_9:
trainerbattlestd 0x0 0x17 0x0 str_0x810968 str_0x810989
loadpointer 0x0 str_0x810989
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x810968:
    .string "Ich fühle, was andere fühlenDOTS"



str_0x810989:
    .string "Ich fühleDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_11:
loadpointer 0 str_violet_grunt
special 0xE
loadpointer 0x0 str_0x810ec2
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER

str_violet_grunt:
	.string "Team Violet Rüpel"

str_0x810ec2:
    .string "Hey! Verschwinde du Balg!"


.elseif LANG_EN

.endif


ow_script_0x8304ac:
goto ow_script_0x877bed


ow_script_0x877bed:
lock
faceplayer
loadpointer 0x0 str_0x8305dd
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8305ae
showmoney 0x0 0x0 0x0
loadpointer 0x0 str_0x83069c
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8305a5
countpokemon
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x830543
sound 0x41
paymoney 0xfa 0x0
updatemoney 0x0 0x0 0x0
checksound
fanfare 0x13e
loadpointer 0x0 str_0x8305b9
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
givepokemon POKEMON_NINCADA 0x5 ITEM_NONE 0x0 0x0 0x0
bufferpokemon 0x0 POKEMON_NINCADA
hidemoney 0x0 0x0
loadpointer 0x0 str_0x830520
callstd MSG
release
end


ow_script_0x830543:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x830551
callstd MSG
release
end


ow_script_0x8305a5:
hidemoney 0x0 0x0
goto ow_script_0x8305ae


ow_script_0x8305ae:
loadpointer 0x0 str_0x8306cd
callstd MSG
release
end


.ifdef LANG_GER

str_0x8305dd:
    .string "Hallo und herzlich willkommen!\nIch bin der Käferhändler. Heute\lhabe ich ganz frische Ware\lreinbekommen, Nincada, soweit das\lAuge reicht. Du möchtest nicht\lzufällig eines kaufen?"



str_0x83069c:
    .string "Das Stück kostet 250POKEDOLLAR. Willst du\nzuschlagen?"



str_0x8305b9:
    .string "PLAYER hat ein Nincada erhalten. "



str_0x830520:
    .string "Danke! Viel Spaß mit dem Nincada!"



str_0x830551:
    .string "Sorry, du hast bereits 6 Pokémon in\ndeinem Team. Komm wieder wenn du\lPlatz hast."



str_0x8306cd:
    .string "Das ist eine sehr schlechte\nEntscheidung, aber gut, ich kann\ldich daran nicht hindern."


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_10:
lock
faceplayer
checkflag FLAG_ROUTE_2_QUICKCLAW
gotoif EQUAL ow_script_0x8448c2
loadpointer 0x0 str_0x8448cd
callstd MSG_FACE
copyvarifnotzero 0x8000 ITEM_FLINKKLAUE
copyvarifnotzero 0x8001 1
lock
callstd ITEM_OBTAIN
lock
setflag FLAG_ROUTE_2_QUICKCLAW
loadpointer 0x0 str_0x844937
callstd MSG_FACE
release
end


ow_script_0x8448c2:
loadpointer 0x0 str_0x844937
callstd MSG_FACE
release
end


.ifdef LANG_GER

str_0x8448cd:
    .string "Oh sieh mal, was ich dort auf dem\nBoden gefunden habe! Eine\lmerkwürdige KlaueDOTS Willst du sie\lhaben?"



str_0x844937:
    .string "Sie sieht wirklich ziemlich\nmerkwürdig aus, nicht?"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_16:
setflag TRANS_DISABLE
showpokepic POKEMON_GLUMANDA 0x0 0x0
clearflag TRANS_DISABLE
end


ow_script_movs_0x8f5c79:
.byte SAY_EXCLAM
.byte STOP


ow_script_0x87f942:
lock
faceplayer
loadpointer 0x0 str_0x8f6003
callstd MSG
sound 0x15
applymovement 0x800f ow_script_movs_0x8f5c79
waitmovement 0x0
loadpointer 0x0 str_0x8f5bee
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_BELEBER
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
lock
faceplayer
loadpointer 0x0 str_0x8f5bc3
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.ifdef LANG_GER

str_0x8f6003:
    .string "Oh, du bist doch der liebe Junge,\nder mich vor dieser bösen Frau\lbeschützt hat.\pOhne dich hätte ich mein liebes\nVoltilamm nicht mehr."



str_0x8f5bee:
    .string "Du hast ein Item gefunden, das ich\nverloren habe? Vielen Dank, aber\ldu kannst es gerne behalten, alles\lwas ich will, ist mein Voltilamm."



str_0x8f5bc3:
    .string "Komm Voltilamm, wir gehen spielen!\nHihi!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_13:
loadpointer 0x0 str_0x8a538f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a538f:
    .string "Viele Leute nennen Route 2 auch\ndie Birkenstraße. Ich muss wohl\lnicht erklären, wieso, oder?"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_2:
trainerbattlestd 0x0 0xa 0x0 str_0x8a8910 str_0x8a896a
loadpointer 0x0 str_0x8a896a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a8910:
    .string "Ein Kampf ist im Grunde wie Strom.\nUnd wir Trainer stehen dabei\lgehörig unter Spannung!"



str_0x8a896a:
    .string "Oh je. Ich glaube, da hab ich wohl\neinen Kurzschluss verursachtDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_7_route_2_east_trainer_1:
trainerbattlestd 0x0 0xb 0x0 str_0x8a9536 str_0x8a959f
loadpointer 0x0 str_0x8a959f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a9536:
    .string "Unsere Sitten verkommen, die\nJugend verliert den Respekt. Bist\ldu auch eine solche rüpelhafte\lGestalt?"



str_0x8a959f:
    .string "Ohne Zweifel leben in dir\nSittlichkeit und Anstand weiter.\lPass gut auf dich auf, Bursche."


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_5:
trainerbattlestd 0x0 0xc 0x0 str_0x8a9ca1 str_0x8a95fb
loadpointer 0x0 str_0x8a95fb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a9ca1:
    .string "Was entspannt mehr als ein\nPicknick in der Sonne?\pEin Kampf natürlich!"



str_0x8a95fb:
    .string "Mir bleibt immerhin noch das\nPicknicken!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_1:
trainerbattlestd 0x0 0xd 0x0 str_0x8a9ce9 str_0x8a9d56
loadpointer 0x0 str_0x8a9d56
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a9ce9:
    .string "Ich bin eine Grazie. Meine\nSchönheit kann blenden. Sieh mich\lan und lass mich dein Herz\lergreifen!"



str_0x8a9d56:
    .string "Du kannst meiner Schönheit\nwiderstehen?"


.elseif LANG_EN

.endif


ow_script_map_3_7_route_2_east_trainer_2:
trainerbattlestd 0x0 0xe 0x0 str_0x8aa83e str_0x8aa8fb
loadpointer 0x0 str_0x8aa8fb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8aa83e:
    .string "Ich trainiere sehr hart, um eines\nTages Mitglied in Manus Arena\lwerden zu können. Meine Schläge\lmussen schnell und stark sein,\lmeine Tritte brauchen Wucht!\pIch zeige dir, wie man kämpft!"



str_0x8aa8fb:
    .string "Großartige Kampftechnik! Hast du\nschonmal darüber nachgedacht, dich\lselbst dafür zu bewerben?"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_8:
trainerbattlestd 0x0 0xf 0x0 str_0x8aaad4 str_0x8aab7f
loadpointer 0x0 str_0x8aab7f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8aaad4:
    .string "Als Ranger muss man stets den\nÜberblick behalten. Wir trainieren\ldie verschiedensten Pokémon, um\lfür jede Situation gewappnet zu\lsein. In der Vielfalt liegt die\lStärke!"



str_0x8aab7f:
    .string "Achte darauf, möglichst viele\nverschiedene Typen in deinem\lPokémon-Team unterzubringen."


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_0:
trainerbattlestd 0x0 0x9 0x0 str_0x8a9d7f str_0x8aaf13
loadpointer 0x0 str_0x8aaf13
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a9d7f:
    .string "Was ist berauschender als der\nKlang eines Baches oder der Duft\lvon frischem Laub?"



str_0x8aaf13:
    .string "Natur und Mensch sind keine\nFeinde, sondern brauchen einander.\pMerk dir das. Bitte."


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_6:
trainerbattlestd 0x0 0x11 0x0 str_0x8ab8e2 str_0x8abf92
loadpointer 0x0 str_0x8abf92
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ab8e2:
    .string "Mein Konkurent dort drüben meint,\ner würde es in Manus Arena\lschaffen. Dabei bin ich es, der\ldiesen Posten ergattern wird! Sieh\ldir nur an, wie viel ich trainiert\lhabe!"



str_0x8abf92:
    .string "Dann muss ich wohl noch härter an\nmir und meinen Pokémon arbeiten!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_15:
pause 0x20
goto ow_script_0x8cb3c8


ow_script_0x8cb3c8:
checkflag POKERADAR_POKEMON_SPAWNED
gotoif LESS ow_script_0x8ac1e8
goto ow_script_0x8ac281


ow_script_0x8ac281:
fadescreen 0x1
sound 0x27
checksound
sound 0x27
checksound
sound 0x27
checksound
callasm 0x919a201
compare POKERADAR_EMENY_SPECIES 0xffff
gotoif EQUAL ow_script_0x8ac33f
callasm 0x9199e31
compare 0x8002 0x0
gotoif EQUAL ow_script_0x8ac33f
callasm 0x9199de1
hidesprite 0xfe
showsprite 0xfe
clearflag POKERADAR_POKEMON_SPAWNED
fadescreen 0x0
callasm 0x9199c01
cry 0x8000 0x0
call ow_script_0x8ac217
waitcry
loadpointer 0x0 str_0x8ac2ec
callstd MSG
setvar POKERADAR_ENEMY_STATE 0x0
end


ow_script_0x8ac217:
random 0x4
addvar LASTRESULT 0x52
singlemovement 0xfe 0x800d
waitmovement 0x0
singlemovement 0xfe 0x800d
waitmovement 0x0
singlemovement 0xfe 0x63
waitmovement 0x0
return


ow_script_0x8ac33f:
fadescreen 0x0
loadpointer 0x0 str_0x8ac34b
callstd MSG
end


ow_script_0x8ac1e8:
loadpointer 0x0 str_0x8ac381
callstd MSG
end


.ifdef LANG_GER

str_0x8ac2ec:
    .string "Ein Pokémon scheint hier in der\nNähe zu sein! Lass dich nicht von\lihm erwischen!"



str_0x8ac34b:
    .string "Der Pokeradar konnte keine Pokémon\nausfindig machen."



str_0x8ac381:
    .string "Aber der Pokeradar hat doch schon\nein Pokémon entdeckt!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_22:
loadpointer 0x0 str_0x8de6b0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8de6b0:
    .string "Krieg den Top Vier, Krieg dem\nChampion! Friede dem Volk!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_21:
loadpointer 0x0 str_0x8dea32
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8dea32:
    .string "Wende dich gegen deine\nUnterdrücker, Junge! Sei kein\lSklave der Top Vier!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_20:
loadpointer 0x0 str_0x8de6ea
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8de6ea:
    .string "Jeder korrupte Polizist soll\nbezahlen für seine Taten!"


.elseif LANG_EN

.endif

ow_script_0x8dce6c:
setvar 0x8000 POKEMON_BARSCHWA
goto ow_script_find_egg
end



ow_script_map_3_41_trainer_17:
loadpointer 0x0 str_0x8e6508
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e6508:
    .string "Südlich von hier liegt Ceometria,\ndie Insel der Toten.\pWann immer ein Trainer einen\nVerlust betrauern muss, besucht er\ldiesen OrtDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_7_route_2_east_trainer_0:
trainerbattlestd 0x0 0x37 0x0 str_0x8e658b str_0x8e65f1
loadpointer 0x0 str_0x8e65f1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e658b:
    .string "Was hältst du von der\nRevolutionsbewegung? Ich finde ja,\lsie hat in einigen Punkten\ldurchaus Recht!"



str_0x8e65f1:
    .string "Vielleicht schließe ich mich den\nRevolutionären an!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_18:
loadpointer 0x0 str_0x8e6626
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e6626:
    .string "Manchmal findet man hier einige\nGeist Pokémon, die sich von\lCeometria, der Stadt der Toten,\ldie südlich liegt, hierher verirrt\lhaben."


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_14:
checkflag BIBOR_QUEST_BIBOR_RECEIVED
gotoif EQUAL ow_script_0x8fb105
checkflag BIBOR_QUEST_DONE
gotoif EQUAL ow_script_0x8fb10e
checkflag BIBOR_QUEST_NOT_TRIGGERED
gotoif EQUAL ow_script_0x8fafe1
loadpointer 0x0 str_0x8dcaa4
callstd MSG_FACE
end


ow_script_movs_0x87bf49:
.byte SAY_QUESTION
.byte STOP


ow_script_0x8fafe1:
checktrainerflag 0x28
gotoif LESS ow_script_0x8fb076
lock
faceplayer
loadpointer 0x0 str_0x8dca59
callstd MSG_KEEPOPEN
fanfare 0x13e
loadpointer 0x0 str_0x8dc421
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
setflag BIBOR_QUEST_DONE
lock
faceplayer
applymovement 0x800f ow_script_movs_0x87bf49
waitmovement 0x0
loadpointer 0x0 str_0x8dc9a6
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x8fb0b2
loadpointer 0x0 str_0x8fb02d
callstd MSG_FACE
end


ow_script_0x8fb0b2:
countpokemon
compare LASTRESULT 0x6
gotoif LESS ow_script_0x8fb0c5
goto ow_script_0x8dc43a


ow_script_0x8dc43a:
loadpointer 0x0 str_0x8dc8dd
callstd MSG_FACE
end


ow_script_0x8fb0c5:
fanfare 0x13e
lock
faceplayer
loadpointer 0x0 str_0x87ae8d
callstd MSG_KEEPOPEN
waitfanfare
givepokemon POKEMON_BIBOR 0xc ITEM_BIBORNIT 0x0 0x0 0x0
bufferpokemon 0x0 POKEMON_BIBOR
bufferpokemon 0x1 POKEMON_BIBOR
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
call ow_script_0x947e82
clearflag TRANS_DISABLE
loadpointer 0x0 str_0x8dcd2f
callstd MSG_FACE
setflag BIBOR_QUEST_BIBOR_RECEIVED
end


ow_script_0x947e82:
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x880b86
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x880ba0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x880be5
end


ow_script_0x880be5:
textcolor 0x3
loadpointer 0x0 str_0x1a8bc9
callstd MSG_KEEPOPEN
setvar LASTRESULT 0xff
return


ow_script_0x880ba0:
call ow_script_0x880bd9
loadpointer 0x0 str_set_nickname
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x880bcd
return


ow_script_0x880bcd:
call show_box_nickname_form
call ow_script_0x1aba6e
return


ow_script_0x1aba6e:
bufferboxname 0x0 0x4037
checkflag 0x834
callif LESS ow_script_0x1aba89
checkflag 0x834
callif EQUAL ow_script_0x1abab4
return


ow_script_0x1abab4:
special2 0x800d 0x165
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x1abacd
loadpointer 0x0 str_0x1a8ac7
callstd MSG_KEEPOPEN
return


ow_script_0x1abacd:
special2 0x800d 0x18a
bufferboxname 0x2 0x800d
loadpointer 0x0 str_0x1a8b4b
callstd MSG_KEEPOPEN
return


ow_script_0x1aba89:
special2 0x800d 0x165
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x1abaa2
loadpointer 0x0 str_0x1a8a83
callstd MSG_KEEPOPEN
return


ow_script_0x1abaa2:
special2 0x800d 0x18a
bufferboxname 0x2 0x800d
loadpointer 0x0 str_0x1a8b08
callstd MSG_KEEPOPEN
return


ow_script_0x880bd9:
return


ow_script_0x880b86:
goto ow_script_0x8c8acf


ow_script_0x8c8acf:
loadpointer 0x0 str_set_nickname
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x931332
clearflag TRANS_DISABLE
return


ow_script_0x931332:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
countpokemon
subvar LASTRESULT 0x1
copyvar 0x8004 LASTRESULT
fadescreen 0x1
special 0x9e
waitstate
return


ow_script_0x8fb076:
lock
faceplayer
loadpointer 0x0 str_0x8dcba5
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8dcb4e
loadpointer 0x0 str_0x8dcb0a
callstd MSG
clearflag BIBOR_QUEST_NOT_TRIGGERED
release
end


ow_script_0x8dcb4e:
loadpointer 0x0 str_0x8dcb58
callstd MSG_FACE
end


ow_script_0x8fb10e:
lock
faceplayer
loadpointer 0x0 str_0x8fcddd
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8dc94e
goto ow_script_0x8fb0b2


ow_script_0x8dc94e:
loadpointer 0x0 str_0x8dc958
callstd MSG_FACE
end


ow_script_0x8fb105:
loadpointer 0x0 str_0x8dcd4c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8dcaa4:
    .string "Der Rüpel ist wohl nach Norden\ngerannt, in Richtung Route 3!"



str_0x8dca59:
    .string "Oh, du hast meine Bibor\nzurückgebracht! Vielen, vielen\lDank!"



str_0x8dc421:
    .string "PLAYER übergibt die Bibor!"



str_0x8dc9a6:
    .string "Was ist das? Sieht so aus, als\nwolle eines der Bibor bei dir\lbleiben. Willst du das Bibor in\ldein Team aufnehmen?"



str_0x8fb02d:
    .string "Das ist aber schade! Komm wieder,\nwenn du es dir anders überlegt\lhast."



str_0x8dc8dd:
    .string "Sieht so aus, als hättest du nicht\ngenug Platz in deinem Team.\pKomm wieder, wenn du Platz in\ndeinem Team hast."



str_0x87ae8d:
    .string "PLAYER hat Bibor erhalten!"



str_0x8dcd2f:
    .string "Kümmere dich gut um Bibor!"



@ ToDo: Investigate sentences containing the word "PC"
str_0x1a8bc9:
    .string "Es ist kein Platz mehr für Pokémon\nvorhanden!\pDie Pokémon Boxen sind voll und\nes kann kein Pokémon mehr\labgelegt werden!"



str_0x1a8ac7:
    .string "BUFFER_2 wurde auf den PC\nübertragen.\pEs wurde in Box\nQUOTEBUFFER_1QUOTE abgelegt."



str_0x1a8b4b:
    .string "Box QUOTEBUFFER_3QUOTE\nauf dem PC ist voll.\pBUFFER_2 wurde in Box\nQUOTEBUFFER_1QUOTE übertragen."



str_0x1a8a83:
    .string "BUFFER_2 wurde auf den PC\nübertragen.\pEs wurde in Box\nQUOTEBUFFER_1QUOTE abgelegt."



str_0x1a8b08:
    .string "Box QUOTEBUFFER_3QUOTE\nauf dem PC ist voll.\pBUFFER_2 wurde in Box\nQUOTEBUFFER_1QUOTE übertragen."



str_0x8dcba5:
    .string "Oh, du siehst aus wie ein Trainer!\nEiner dieser Schurken von Team\lViolet hat mich kurzerhand aller\lmeiner gezüchteten Bibor beraubt.\pIch selbst bin kein Trainer, wärst\ndu also so freundlichen, sie mir\lwiederzuholen?"



str_0x8dcb0a:
    .string "Wie überaus rühmlich von dir! Ich\nbin auf deine Hilfe angewiesen!"



str_0x8dcb58:
    .string "Wie jammerschade! Was soll ich\ndenn als Imker nun tun, so ganz\lohne Bibor?"



str_0x8fcddd:
    .string "Bist du gekommen, um das Bibor in\ndein Team aufzunehmen?"



str_0x8dc958:
    .string "Das ist aber schade! Solltest du\ndeine Meinung ändern, komm einfach\lzu mir."



str_0x8dcd4c:
    .string "Ich möchte dir vielmals danken,\ndass du mir meine Bibor\lzurückgebracht hast.\pSie sind mein ganzer Stolz, musst\ndu wissen!"


.elseif LANG_EN

.endif


ow_script_map_3_41_trainer_12:
checkflag ROUTE_2_LINKCABLE
gotoif EQUAL ow_script_0x8aaf95
lock
faceplayer
loadpointer 0x0 str_0x8abe1c
callstd MSG
copyvarifnotzero 0x8000 ITEM_LINKKABEL
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
loadpointer 0x0 str_0x8ab77f
callstd MSG
setflag ROUTE_2_LINKCABLE
release
end


ow_script_0x8aaf95:
loadpointer 0x0 str_0x8ab6bf
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8abe1c:
    .string "Acht lange Jahre habe ich für die\nLaz.Corp geschuftet. Acht lange\lJahre habe ich mich der\lEntwicklung von Software gewidmet.\lAcht lange Jahre habe ich\lkaltherzig Pokémon ausgebeutet,\lnur des Fortschritt wegens.\lJetzt endlich habe ich meine\lFehler eingesehen. Es ist falsch,\lPokémon für kommerzielle Zwecke\lauszunutzen.\lHier, nimm das. Ich habe dafür\lkeine Verwendung mehr."



str_0x8ab77f:
    .string "Das Linkkabel simuliert einen\nechten Pokémon Tausch, sodass\ljene, die sich erst im Tausch\lentwickeln, auf diese Weise zu\lihrer Evolution gelangen können.\lIst es nicht grotesk, wozu unsere\lTechnik fähig ist? Pokémon zur\lEvolution zwingen? DOTS\lAber nicht mit mirDOTS Soll die\lLaz.Corp doch machen, was sie für\lrichtig hält. Ich halte mich da ab\ljetzt raus!"



str_0x8ab6bf:
    .string "Mein Boss wollte, dass ich ein\nRaum-Zeit-Portal konstruiere, dass\ldie Lebensenergie von Pokémon als\lEnergiequelle nutztDOTS Ab diesem\lPunkt war mir klar, dass es so\lnicht weitergehen kannDOTS"


.elseif LANG_EN

.endif


ow_script_movs_0x8dea30:
.byte FACE_DOWN
.byte STOP


ow_script_map_3_41_trainer_19:
lock
faceplayer
draw_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
loadpointer 0x0 str_0x8e225d
callstd MSG_KEEPOPEN
multichoice 8 8 0 1
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x947e76
closeonkeypress
hide_mugshot
special 0x113
applymovement 0x7F mov_cam
waitmovement 0

fadesong MUS_REVOLUTION
applymovement 0x800f ow_script_movs_0x8dea30
waitmovement 0x0
loadpointer 0x0 str_0x8e1e69
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
applymovement 0x7F mov_cam_back
waitmovement 0
special 0x114
faceplayer
loadpointer 0x0 str_0x8de830
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
fadesong MUS_ROUTE_24_25
release
end


ow_script_0x947e76:
loadpointer 0x0 str_0x9312b4
callstd MSG_FACE
hide_mugshot
end

mov_cam:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP

mov_cam_back:
	.byte STEP_UP, STEP_UP, STEP_UP, STOP


.ifdef LANG_GER

str_0x8e225d:
	.autostring 35 2 "Hallo, junger Trainer.\pBist du auch gekommen, um den Blick aufs Meer zu genießen?\pHast du vielleicht die Zeit, ein wenig dem Schwachsinn eines alten Mannes zu lauschen?"


str_0x8e1e69:
	.autostring 35 2 "Weißt du, wie das Regierungssystem in Theto entstanden ist?\pVor einiger Zeit taten sich drei äußerst starke Trainer zusammen und begannen den Kontinent gewaltsam zu erobern.\pEs dauerte nicht lange, da hatten sie die Herrschaft über Theto errungen.\pZwischenzeitlich hatten sich aber einige andere Trainer dem Trio angeschlossen, sodass der Kontinent schließlich unter den Stärksten von ihnen aufgeteilt wurde.\pAn ihrer Spitze stand der mächtigste Trainer, der sich fortan Champion nannte.\pTheto selbst unterteilte man in vier Gebiete, jedes von einem enorm mächtigen Trainer regiert, dessen Aufgabe es war, der Region Schutz zu bieten.\pDiese vier Trainer nennen wir heute die Top Vier und zusammen mit dem Champion bilden sie die Pokémon-Liga.\pSpäter installierte man Instiutionen wie die Landespolizei, die als Arm der Top Vier für Recht und Ordnung sorgen sollten.\pDoch im Laufe der Zeit DOTS DOTS DOTS\pAls neue Trainertalente die Posten der Top Vier besetzten, geriet das System langsam aber sicher außer Kontrolle.\pKorruption und Machtgier sowie Konflikte unter den Top Vier brachten den Bürgern viel Leid.\pDie Missstände in Theto werden von Tag zu Tag untragbarerDOTS DOTS\pUnd darum haben die Menschen irgendwann begonnen, gegen die Top Vier aufzubegehren.\pAus diesem Aufbegehren enstand schließlich die Revolutionsbewegung."



str_0x8de830:
	.autostring 35 2 "Wir alle müssen irgendwann entscheiden, wem wir unsere Treue leisten.\pDen Top Vier, deren Stärke der Region Stabilität sichert, oder den Bürgern, die ihn bewohnen.\pEgal, wie du dich entscheidest, Kind, lass es eine Entscheidung des Gewissens sein.\pDOTS DOTS DOTS\pNun habe ich aber genug sinniert, ich lasse dich nun wieder in Ruhe.\pVielleicht begnenen wir uns noch einmal, das kann man nie wissen."


str_0x9312b4:
    .autostring 35 2 "DOTS DOTS DOTS\pDas kann ich dir natürlich nicht verübeln.\pGeh nur, ich werde es einem Kind schon nachsehenDOTS"


.elseif LANG_EN

.endif

ow_script_0x93d5cd:
setvar 0x8000 POKEMON_ELEKID
call ow_script_find_egg
end
