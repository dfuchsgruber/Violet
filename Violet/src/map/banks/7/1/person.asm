.include "ordinals.s"
.include "vars.s"
.include "map_adjacency_types.s"
.include "callstds.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_map_7_1_person_1
.global ow_script_0x8deb07
.global ow_script_0x71d7cf
.global ow_script_0x8deafd
.global ow_script_map_7_1_person_0
.global ow_script_map_7_1_person_2

ow_script_map_7_1_person_0:
loadpointer 0x0 str_0x8dec30
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8dec30:
    .string "Ich bin für mein Leben gern\nGärtnerin. Die Beerenzucht ist ein\läußerst spannendes Hobby."


.elseif LANG_EN

.endif


ow_script_map_7_1_person_1:
checkflag SILVANIA_BERRY_JUICE
gotoif EQUAL ow_script_0x8deb07
lock
faceplayer
loadpointer 0x0 str_0x8dee30
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8deafd
loadpointer 0x0 str_0x8deadb
callstd MSG
copyvarifnotzero 0x8000 ITEM_BEERENSAFT
copyvarifnotzero 0x8001 5
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_no_room_for_giveitem
loadpointer 0x0 str_0x8dec8a
callstd MSG
setflag SILVANIA_BERRY_JUICE
release
end


ow_script_0x8deafd:
loadpointer 0x0 str_0x8decc8
callstd MSG_FACE
end


ow_script_0x8deb07:
loadpointer 0x0 str_0x8dec8a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8dee30:
    .string "Beeren sind auf viele Arten\nnützlich. Während einige von ihnen\lbei Statusproblemen helfen, kann\lman aus anderen Beerensaft\lgewinnen.\pFindest du Beeren nicht auch\neinfach toll?"



str_0x8deadb:
    .string "Gut geantwortet! Nimm das hier!"



str_0x8dec8a:
    .string "Beerensaft füllt die Kraftpunkte\neines Pokémons wieder auf."



str_0x8decc8:
    .string "Das ist ein Jammer! Jeder Trainer\nsollte das Potenzial einer Beere\lzu schätzen wissen."


.elseif LANG_EN

.endif


ow_script_mart0x71d78d:
.hword ITEM_AMRENABEERE
.hword ITEM_MARONBEERE
.hword ITEM_PIRSIFBEERE
.hword ITEM_FRAGIABEERE
.hword ITEM_WILBIRBEERE
.hword ITEM_SINELBEERE
.hword ITEM_PERSIMBEERE
.hword ITEM_NONE


ow_script_map_7_1_person_2:
loadpointer 0x0 str_0x721f5f
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x71d7cf
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
preparemsg str_0x71d79e
waitmsg
pokemart ow_script_mart0x71d78d
loadpointer 0x0 str_0x71d3f1
callstd MSG_KEEPOPEN
closeonkeypress
clearflag TRANS_DISABLE
end


ow_script_0x71d7cf:
loadpointer 0x0 str_0x721ed1
callstd MSG
end


.ifdef LANG_GER

str_0x721f5f:
    .string "Hallo! Ich bin der Beerenverkäufer\nvon Theto. Wie mein Name schon\lsagt, verkaufe ich Beeren. Willst\ldu ein paar Beeren kaufen?"



str_0x71d79e:
    .string "Such dir etwas aus, mein Sortiment\nist riesig!"



str_0x71d3f1:
    .string "Danke für deinen Einkauf. Beehre\nmich bald wieder!"



str_0x721ed1:
    .string "Wirklich? Das ist schade, denn\nBeeren können genauso nützlich sein\lwie Tränke oder Pokebälle. Komm\lwieder, wenn du Beeren kaufen\lwillst."


.elseif LANG_EN

.endif