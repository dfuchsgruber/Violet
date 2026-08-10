.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "items.s"
.include "ordinals.s"

.global ow_script_silvania_clouds_person_0
.global ow_script_silvania_clouds_person_1
.global ow_script_kranzberg_clouds_gear

ow_script_silvania_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_silvania_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_kranzberg_clouds_gear:
    copyvarifnotzero 0x8000 ITEM_GRUENES_ZAHNRAD
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    hidesprite LASTTALKED
    loadpointer 0 str_return_gear_to_sonnaufeld
    callstd MSG_KEEPOPEN
    releaseall
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier hat wohl einst ein Tempel gestandenDOTS\pIch frage mich, was damit passiert istDOTS"
str_1:
    .autostring 34 2 "Autsch!\pIch habe mir vorhin an dieser Fackel die Finger verbrannt!"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Once a temple was standing hereDOTS\pI wonder what happened to itDOTS"
str_1:
    .autostring 34 2 "Ouch!\pJust a minute ago I burned my fingers at this torch!"

.endif