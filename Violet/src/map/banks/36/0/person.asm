.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_3_house_inside_person_0
.global ow_script_route_3_house_inside_person_1
.global ow_script_route_3_house_inside_blendpuder

ow_script_route_3_house_inside_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_3_house_inside_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_3_house_inside_blendpuder:
    lock
    faceplayer
    checkflag FLAG_ROUTE_3_BLENDPUDER
    gotoif EQUAL after_receiving_powder
    loadpointer 0x0 str_intro_powder
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_BLENDPUDER
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    loadpointer 0x0 str_after_receiving_powder
    callstd MSG_KEEPOPEN
    closeonkeypress
    release
    setflag FLAG_SONNAUFELD_APPLE_GIFT
    end

after_receiving_powder:
    loadpointer 0x0 str_after_receiving_powder
    callstd MSG_FACE
    end
    
.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich frage mich, warum wir überhaupt noch zusammen essen, wenn dann trotzdem jeder nur Augen für den Fernseher hatDOTS"
str_1:
    .autostring 34 2 "Pssst!\nSei bitte leise!\pMeine Lieblingsserie fängt gleich an.\pDas darf ich nicht verpassen!"
str_intro_powder:
    .autostring 34 2 "Schau mal, was mein Pokémon heute Morgen aufgesammelt hat.\pIch weiß nicht so wirklich, was ich damit anfangen soll, also kannst du es haben."
str_after_receiving_powder:
    .autostring 34 2 "Diese Puder blendet einen irgendwie, wenn man ihn ansieht.\pWirklich seltsam, oder?"
.elseif LANG_EN
.endif