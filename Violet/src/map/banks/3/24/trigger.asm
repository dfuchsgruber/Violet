.include "ordinals.s"
.include "vars.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "pathfinding.s"

.global ow_script_map_3_24_trigger_0

ow_script_map_3_24_trigger_0:
    lockall
    clearflag PKMNMENU
    showsprite 0x3
    sound 9
    applymovement 3 mov_1d
    waitmovement 0
    checksound
    setflag PKMNMENU
    playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
    npc_move_to_player 0x3
    faceplayer
    draw_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
    compare STARTER_SELECTED 0x0
    gotoif EQUAL ow_script_0x95efaa
    compare STARTER_SELECTED 0x1
    gotoif EQUAL ow_script_0x95efbe
    trainerbattlecont 0x1 0xbe 0x0 str_0 str_after ow_script_0x95f001
ow_script_0x95f001:
    lockall
    loadpointer 0x0 str_1
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN hide_mugshot=0
    loadpointer 0 str_2
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_3
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_4
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    hide_mugshot
    copyvarifnotzero 0x8000 ITEM_DETEKTOR
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    setflag FLAG_DETECTOR
    loadpointer 0x0 str_5
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN hide_mugshot=0
    loadpointer 0 str_6
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_7
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_8
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_9
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    pause 16
    npc_move_to 0x3 0x4f 0x1a
    applymovement 0x3 mov_2r
    waitmovement 0
    hidesprite 0x3
    setvar VAR_ROUTE_6_RIVAL 0x1
    releaseall
    end

ow_script_0x95efbe:
    trainerbattlecont 0x1 0xbd 0x0 str_0 str_after ow_script_0x95f001
ow_script_0x95efaa:
    trainerbattlecont 0x1 0xbc 0x0 str_0 str_after ow_script_0x95f001


.ifdef LANG_GER
str_0:
    .autostring 34 2 "PLAYER!\pDas ist aber ein Zufall!\pIch komme gerade aus Inferior und habe die Arenaleiterin dort besiegt.\pDas war vielleicht ein heißer Kampf!\pMal sehen, ob du so einer Hitze standhalten kannst!"
str_after:
    .autostring 34 2 "Was?\nIch habe verloren?\pDu hast wirklich eine Glückssträhne, PLAYER!"
str_1:
    .autostring 34 2 "Alle Achtung!\pDu hast gut gekämpft, PLAYER!"
str_2:
    .autostring 34 2 "Aber wenn ich von meinem Arenakampf nicht so erschöpft gewesen wäre, dann sähe die Sache jetzt ganz anders aus!"
str_3:
    .autostring 34 2 "Du bist viel zu schwach, um es mit der Arenaleiterin dort aufzunehmen."
str_4:
    .autostring 34 2 "Aber ich helfe dir natürlich wie immer gerne aus der Patsche!"
str_5:
    .autostring 34 2 "Das ist ein Detektor.\pDer hilft dir, Items aufzuspüren, die man mit dem bloßen Auge nicht sehen kann.\pEs ist wirklich erstaunlich, was man einfach so herumliegen findet."
str_6:
    .autostring 34 2 "Vielleicht findest du ja ein brauchbares Item, das dir gegen die Arenaleiterin von Inferior hilft."
str_7:
    .autostring 34 2 "Mehr kann ich leider nicht für dich tun.\pAber wenn du dich anstrengstDOTS"
str_8:
    .autostring 34 2 "Na, dann bin ich mir sicher, dass du eine Chance gegen die Arenaleiterin von Inferior hast."
str_9:
    .autostring 34 2 "Man sieht sich, PLAYER!"
.elseif LANG_EN

.endif