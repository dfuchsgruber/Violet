.include "overworld_script.s"

.include "std.s"

.global ow_script_0x88d214
ow_script_0x88d214:
goto ow_script_0x8d05cb


.global ow_script_mart0x88d39e
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


.global ow_script_0x8d05cb
ow_script_0x8d05cb:
setflag TRANS_DISABLE
lock
faceplayer
preparemsg str_0x1a908b
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


.global ow_script_0x88d2db
ow_script_0x88d2db:
goto ow_script_0x8d0696


.global ow_script_0x8d0696
ow_script_0x8d0696:
loadpointer 0x0 str_0x1a7e77
callstd MSG_KEEPOPEN
clearflag TRANS_DISABLE
release
end


.global ow_script_mart0x88d379
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


.global ow_script_0x88d2d0
ow_script_0x88d2d0:
pokemart ow_script_mart0x88d379
goto ow_script_0x88d2db


.global ow_script_mart0x88d352
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


.global ow_script_0x88d2c5
ow_script_0x88d2c5:
pokemart ow_script_mart0x88d352
goto ow_script_0x88d2db


.global ow_script_mart0x88d32b
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


.global ow_script_0x88d2ba
ow_script_0x88d2ba:
pokemart ow_script_mart0x88d32b
goto ow_script_0x88d2db


.global ow_script_0x88d2af
ow_script_0x88d2af:
pokemart ow_script_mart0x88d32b
goto ow_script_0x88d2db


.global ow_script_0x88d2a4
ow_script_0x88d2a4:
pokemart ow_script_mart0x88d32b
goto ow_script_0x88d2db


.global ow_script_mart0x88d30e
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


.global ow_script_0x88d299
ow_script_0x88d299:
pokemart ow_script_mart0x88d30e
goto ow_script_0x88d2db


.global ow_script_0x88d28e
ow_script_0x88d28e:
pokemart ow_script_mart0x88d30e
goto ow_script_0x88d2db


.global ow_script_mart0x88d2f9
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


.global ow_script_0x88d283
ow_script_0x88d283:
pokemart ow_script_mart0x88d2f9
goto ow_script_0x88d2db


.global ow_script_mart0x88d2e6
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


.global ow_script_0x88d278
ow_script_0x88d278:
pokemart ow_script_mart0x88d2e6
goto ow_script_0x88d2db


.ifdef LANG_GER
.global str_0x1a908b

str_0x1a908b:
    .string "Hallo!\nKann ich dir behilflich sein?"
        
        
.global str_0x1a7e77

str_0x1a7e77:
    .string "Bitte komm bald wieder!"
        
        
.elseif LANG_EN

.endif
