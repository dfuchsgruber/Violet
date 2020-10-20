.include "ordinals.s"
.include "vars.s"
.include "map_adjacency_types.s"
.include "callstds.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "items.s"
.include "ordinals.s"
.include "specials.s"

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




ow_script_map_7_1_person_2:
    checkflag FLAG_COMPOSTER
    gotoif EQUAL composter_received
    loadpointer 0 str_2_1
    callstd MSG_KEEPOPEN
    setflag FLAG_COMPOSTER
composter_received:
    loadpointer 0 str_2_0
    callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif EQUAL dont_compost
    loadpointer 0 str_2_3
    callstd MSG_KEEPOPEN
    special SPECIAL_COMPOSTER
    waitstate
    pause 16
dont_compost:
    loadpointer 0 str_2_2
    callstd MSG_KEEPOPEN
    release
    end


.ifdef LANG_GER
str_2_1:
    .autostring 34 2 "Hallo, junger Trainer!\pIn diesem Haus dreht sich alles um die Gärtnerei!\pIch kann dir helfen, mit Mulch die Erträge deiner gepflanzten Beeren noch zu steigern!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pHuh?\nWas Mulch denn überhaupt ist?\pGut, dass du fragst!\pIndem man alte Beeren kompostiert, kann man Mulch gewinnen, den man auf unbepflanzten Beerenfeldern ausbringen kann.\pWenn du dann ein neuen Beerenstrauch anpflanzst, wird dieser viel ertragreicher sein.\pToll, nicht wahr?\pUnd ich kann dir helfen, Mulch aus Beeren herzustellen."
str_2_0:
    .autostring 34 2 "Möchtest du Beeren zu Mulch kompostieren?"
str_2_2:
    .autostring 34 2 "Wenn du Mulch herstellen willst, komm einfach zu mir."
str_2_3:
    .autostring 34 2 "Welche Beeren möchtest du zu Mulch kompostieren?"
.elseif LANG_EN

.endif