.include "overworld_script.s"
.include "callstds.s"

.global ow_script_blackbeard_ship_canon_room_person0
.global ow_script_blackbeard_ship_canon_room_person1
.global ow_script_blackbeard_ship_canon_room_person2


ow_script_blackbeard_ship_canon_room_person0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_blackbeard_ship_canon_room_person1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_blackbeard_ship_canon_room_person2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Dienst auf dem Kanonendeck ist öde.\pWas meinst du, wie oft wir in seine Seeschlacht geraten?\pLass es mich dir sagen!\pNicht sehr oft, Kindchen!"
str_1:
    .autostring 34 2 "Das Gute als Kanonier ist, dass man die meiste Zeit hier mit den Würfeln verbringen kann."
str_2:
    .autostring 34 2 "Vom ganzen Schwarzpulver hier muss man ständig hustenDOTS\pEs ist überall, vor allem auf den KanonenDOTS"
.elseif LANG_EN
.endif