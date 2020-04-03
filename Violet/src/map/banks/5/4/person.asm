.include "vars.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "specials.s"
.include "callstds.s"
.include "ordinals.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"
.include "items.s"

.global str_mart_ask
.global str_mart_exit
.global ow_script_map_5_4_person_5
.global ow_script_0x8d05cb
.global ow_script_0x88d2d0
.global ow_script_0x88d2a4
.global ow_script_0x1a94e7
.global ow_script_0x88d2af
.global ow_script_0x949710
.global ow_script_0x88d2ba
.global ow_script_0x88d2c5
.global ow_script_0x1a94ce
.global ow_script_0x877467
.global ow_script_0x88d28e
.global ow_script_map_5_4_person_3
.global ow_script_map_5_4_person_4
.global ow_script_0x88d278
.global ow_script_map_5_4_person_1
.global ow_script_0x88d283
.global ow_script_0x949719
.global ow_script_0x88d2db
.global ow_script_0x1a947f
.global ow_script_map_5_4_person_0
.global ow_script_0x1a9429
.global ow_script_map_5_4_person_2
.global ow_script_0x8d0696
.global ow_script_0x1a949d
.global ow_script_0x88d299

ow_script_map_5_4_person_1:
loadpointer 0x0 str_0x192a92
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x192a92:
    .autostring 35 2 "In der Ecke steht der PC.\pDort kannst du Pokémon lagern, solltest du keinen Platz in deinem Team haben."


.elseif LANG_EN

.endif


ow_script_map_5_4_person_4:
cry POKEMON_CHANEIRA 0x0
loadpointer 0x0 str_0x80ebe5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x80ebe5:
    .string "Chaneira! Chaneira!"


.elseif LANG_EN

.endif


ow_script_map_5_4_person_0:
goto ow_script_0x1a9429


ow_script_0x1a9429:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x1aa912
preparemsg str_0x1a8188
waitmsg
multichoice 0x13 0x8 0x0 0x2
copyvar 0x8000 LASTRESULT
compare 0x8000 0x0
gotoif EQUAL ow_script_0x877467
compare 0x8000 0x1
gotoif EQUAL ow_script_0x949710
compare 0x8000 0x7f
gotoif EQUAL ow_script_0x949710
end


ow_script_0x949710:
loadpointer 0x0 str_0x1a8219
callstd MSG
end


ow_script_0x877467:
savincrementkey 0xf
loadpointer 0x0 str_0x1a81da
callstd MSG_KEEPOPEN
closeonkeypress
call ow_script_0x1a947f
pause 0x5
special 0x169
pause 0x5
goto ow_script_0x1a949d


ow_script_0x1a949d:
special2 0x800d 0x1b1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x1a94ce
special2 0x800d 0x183
copyvar 0x8008 LASTRESULT
compare 0x8008 0x0
gotoif EQUAL ow_script_0x1a94ce
compare 0x8008 0x1
gotoif EQUAL ow_script_0x1a94e7
end


ow_script_movs_0x1a951d:
.byte 0x5b
.byte 0x1a
.byte STOP


ow_script_0x1a94e7:
checkflag 0x842
gotoif EQUAL ow_script_0x949719
loadpointer 0x0 str_0x1a8237
callstd MSG_KEEPOPEN
setflag 0x842
preparemsg str_0x1c067a
waitmsg
applymovement 0x800f ow_script_movs_0x1a951d
waitmovement 0x0
loadpointer 0x0 str_0x1a8219
callstd MSG_KEEPOPEN
end


ow_script_0x949719:
preparemsg str_0x1a8237
waitmsg
applymovement 0x800f ow_script_movs_0x1a951d
waitmovement 0x0
loadpointer 0x0 str_0x1a8219
callstd MSG
end


ow_script_0x1a94ce:
preparemsg str_0x1a8237
waitmsg
applymovement 0x800f ow_script_movs_0x1a951d
waitmovement 0x0
loadpointer 0x0 str_0x1a8219
callstd MSG
end


ow_script_movs_0x1aa419:
.byte LOOK_LEFT_DELAYED
.byte STOP


ow_script_movs_0x1aa41f:
.byte LOOK_DOWN_DELAYED
.byte STOP


ow_script_0x1a947f:
applymovement 0x800f ow_script_movs_0x1aa419
waitmovement 0x0
doanimation 0x19
nop
checkanimation 0x19
applymovement 0x800f ow_script_movs_0x1aa41f
waitmovement 0x0
special SPECIAL_HEAL
return


.ifdef LANG_GER

str_0x1a8188:
    .string "Willkommen im Pokéstop!\pWir heilen deine Pokémon und\nmachen sie wieder fit!"



str_0x1a8219:
    .string "Komm jederzeit wieder vorbei!"



str_0x1a81da:
    .string "Okay, ich nehme deine Pokémon für\neinen Moment in meine Obhut."



str_0x1a8237:
    .string "Danke!\nDeine Pokémon sind wieder topfit!"



str_0x1c067a:
    .string "Es scheint, als ob BUFFER_1 gerade\nspielt.\lLos!"


.elseif LANG_EN

.endif


ow_script_map_5_4_person_3:
loadpointer 0x0 str_0x880e00
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x880e00:
    .string "Im Pokéstop kannst du sowohl deine\nPokémon heilen lassen, als auch\lnützliche Items für dein Inventar\lkaufen."


.elseif LANG_EN

.endif


ow_script_map_5_4_person_2:
loadpointer 0x0 str_0x880f63
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x880f63:
    .string "Es gibt in jeder Stadt einen\nPokéstop. Ich hörte, dass in allen\lPokéstops das Sortiment zwar\lgleich ist, aber laufend erweitert\lwird."


.elseif LANG_EN

.endif


ow_script_map_5_4_person_5:
goto ow_script_0x8d05cb


ow_script_mart0x88d39e:
.hword ITEM_HYPERBALL
.hword ITEM_NETZBALL
.hword ITEM_TAUCHBALL
.hword ITEM_NESTBALL
.hword ITEM_WIEDERBALL
.hword ITEM_TIMERBALL
.hword ITEM_LUXUSBALL
.hword ITEM_PREMIERBALL
.hword ITEM_TOP_GENESUNG
.hword ITEM_TOP_TRANK
.hword ITEM_HYPERTRANK
.hword ITEM_HYPERHEILER
.hword ITEM_BELEBER
.hword ITEM_TOP_BELEBER
.hword ITEM_SCHUTZ
.hword ITEM_FLUCHTSEIL
.hword ITEM_ENECO_RUTE
.hword ITEM_ELIXIER
.hword ITEM_TOP_ELIXIER
.hword ITEM_NONE


ow_script_0x8d05cb:
setflag TRANS_DISABLE
lock
faceplayer
preparemsg str_mart_ask
waitmsg
checkflag POKEDEX
gotoif LESS ow_script_0x88d278
checkflag FRBADGE_1
gotoif LESS ow_script_0x88d283
checkflag FRBADGE_2
gotoif LESS ow_script_0x88d28e
checkflag FRBADGE_3
gotoif LESS ow_script_0x88d299
checkflag FRBADGE_4
gotoif LESS ow_script_0x88d2a4
checkflag FRBADGE_5
gotoif LESS ow_script_0x88d2af
checkflag FRBADGE_6
gotoif LESS ow_script_0x88d2ba
checkflag FRBADGE_7
gotoif LESS ow_script_0x88d2c5
checkflag FRBADGE_8
gotoif LESS ow_script_0x88d2d0
pokemart ow_script_mart0x88d39e
goto ow_script_0x88d2db


ow_script_0x88d2db:
goto ow_script_0x8d0696


ow_script_0x8d0696:
loadpointer 0x0 str_mart_exit
callstd MSG_KEEPOPEN
clearflag TRANS_DISABLE
release
end


ow_script_mart0x88d379:
.hword ITEM_HYPERBALL
.hword ITEM_NETZBALL
.hword ITEM_TAUCHBALL
.hword ITEM_NESTBALL
.hword ITEM_WIEDERBALL
.hword ITEM_TIMERBALL
.hword ITEM_LUXUSBALL
.hword ITEM_PREMIERBALL
.hword ITEM_TOP_GENESUNG
.hword ITEM_TOP_TRANK
.hword ITEM_HYPERTRANK
.hword ITEM_HYPERHEILER
.hword ITEM_BELEBER
.hword ITEM_SCHUTZ
.hword ITEM_FLUCHTSEIL
.hword ITEM_ENECO_RUTE
.hword ITEM_ELIXIER
.hword ITEM_NONE


ow_script_0x88d2d0:
pokemart ow_script_mart0x88d379
goto ow_script_0x88d2db


ow_script_mart0x88d352:
.hword ITEM_SUPERBALL
.hword ITEM_HYPERBALL
.hword ITEM_HYPERTRANK
.hword ITEM_SUPERTRANK
.hword ITEM_TOP_TRANK
.hword ITEM_GEGENGIFT
.hword ITEM_FEUERHEILER
.hword ITEM_EISHEILER
.hword ITEM_AUFWECKER
.hword ITEM_PARA_HEILER
.hword ITEM_HYPERHEILER
.hword ITEM_BELEBER
.hword ITEM_AETHER
.hword ITEM_TOP_AETHER
.hword ITEM_FLUCHTSEIL
.hword ITEM_SCHUTZ
.hword ITEM_SUPERSCHUTZ
.hword ITEM_TOP_SCHUTZ
.hword ITEM_NONE


ow_script_0x88d2c5:
pokemart ow_script_mart0x88d352
goto ow_script_0x88d2db


ow_script_mart0x88d32b:
.hword ITEM_POKEBALL
.hword ITEM_SUPERBALL
.hword ITEM_HYPERBALL
.hword ITEM_TRANK
.hword ITEM_HYPERTRANK
.hword ITEM_SUPERTRANK
.hword ITEM_GEGENGIFT
.hword ITEM_FEUERHEILER
.hword ITEM_EISHEILER
.hword ITEM_AUFWECKER
.hword ITEM_PARA_HEILER
.hword ITEM_HYPERHEILER
.hword ITEM_BELEBER
.hword ITEM_AETHER
.hword ITEM_FLUCHTSEIL
.hword ITEM_SCHUTZ
.hword ITEM_SUPERSCHUTZ
.hword ITEM_TOP_SCHUTZ
.hword ITEM_NONE


ow_script_0x88d2ba:
pokemart ow_script_mart0x88d32b
goto ow_script_0x88d2db


ow_script_0x88d2af:
pokemart ow_script_mart0x88d32b
goto ow_script_0x88d2db


ow_script_0x88d2a4:
pokemart ow_script_mart0x88d32b
goto ow_script_0x88d2db


ow_script_mart0x88d30e:
.hword ITEM_POKEBALL
.hword ITEM_SUPERBALL
.hword ITEM_TRANK
.hword ITEM_SUPERTRANK
.hword ITEM_GEGENGIFT
.hword ITEM_FEUERHEILER
.hword ITEM_EISHEILER
.hword ITEM_AUFWECKER
.hword ITEM_PARA_HEILER
.hword ITEM_AETHER
.hword ITEM_FLUCHTSEIL
.hword ITEM_SCHUTZ
.hword ITEM_SUPERSCHUTZ
.hword ITEM_NONE


ow_script_0x88d299:
pokemart ow_script_mart0x88d30e
goto ow_script_0x88d2db


ow_script_0x88d28e:
pokemart ow_script_mart0x88d30e
goto ow_script_0x88d2db


ow_script_mart0x88d2f9:
.hword ITEM_POKEBALL
.hword ITEM_TRANK
.hword ITEM_GEGENGIFT
.hword ITEM_FEUERHEILER
.hword ITEM_EISHEILER
.hword ITEM_AUFWECKER
.hword ITEM_PARA_HEILER
.hword ITEM_FLUCHTSEIL
.hword ITEM_SCHUTZ
.hword ITEM_NONE


ow_script_0x88d283:
pokemart ow_script_mart0x88d2f9
goto ow_script_0x88d2db


ow_script_mart0x88d2e6:
.hword ITEM_TRANK
.hword ITEM_GEGENGIFT
.hword ITEM_FEUERHEILER
.hword ITEM_EISHEILER
.hword ITEM_AUFWECKER
.hword ITEM_PARA_HEILER
.hword ITEM_FLUCHTSEIL
.hword ITEM_SCHUTZ
.hword ITEM_NONE


ow_script_0x88d278:
pokemart ow_script_mart0x88d2e6
goto ow_script_0x88d2db


.ifdef LANG_GER

str_mart_ask:
    .string "Hallo!\nKann ich dir behilflich sein?"



str_mart_exit:
    .string "Bitte komm bald wieder!"


.elseif LANG_EN

.endif