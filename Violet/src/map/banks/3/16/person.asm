.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"

.global ow_script_route_12_person_1
.global ow_script_route_12_person_2
.global ow_script_route_12_person_3

ow_script_route_12_person_1:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_12_person_2:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_12_person_3:
    checkflag ROUTE_12_PUDERSAND
    gotoif 1 pudersand_received
    lock
    faceplayer
    loadpointer 0 str_give_pudersand
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_PUDERSAND
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    setflag ROUTE_12_PUDERSAND
    loadpointer 0 str_pudersand_received
    callstd MSG_KEEPOPEN
    release
    end
pudersand_received:
    loadpointer 0 str_pudersand_received
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Strandurlaub mit meiner Frau ist wirklich kein Spaß.\pSie muss immerzu in Bewegung bleibenDOTS"
str_1:
    .autostring 34 2 "Aua!\nMeine BeineDOTS\pIch bin wohl zu viel geschwommen."
str_give_pudersand:
    .autostring 34 2 "Sieh mal, was ich für interessanten Sand gefunden habe!"
str_pudersand_received:
    .autostring 34 2 "Wenn der Pudersand durch die Hände gleitet, fühlt er sich so weich anDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Beach holiday with my wife really is no fun.\pShe has to keep moving all the timeDOTS"
str_1:
    .autostring 34 2 "Ouch!\nMy legsDOTS\pProbably I did swim too much."
str_give_pudersand:
    .autostring 34 2 "Look what interesting sand I did find here!"
str_pudersand_received:
    .autostring 34 2 "If you let the sand glide through your fingers it feels so softDOTS"


.endif