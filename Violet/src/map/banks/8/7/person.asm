.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x87f3b7
.global ow_script_map_8_7_person_1
.global ow_script_map_8_7_person_0
.global ow_script_map_8_7_person_2

ow_script_map_8_7_person_0:
loadpointer 0x0 str_0x87f2d9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f2d9:
    .autostring 34 2 "Manchmal, wenn ich morgens vor dem Spiegel stehe, kommen mir einige Fragen.\pBist du zufrieden mit dem, was du erreicht hast?\pUnd wenn du könntest, was würdest du anders machen?"
.elseif LANG_EN

.endif


ow_script_map_8_7_person_1:
loadpointer 0x0 str_0x87f361
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f361:
    .string "Hunger!\nIch habe Hunger!\pEssen!\nIch will jetzt essen!"


.elseif LANG_EN

.endif


ow_script_map_8_7_person_2:
checkflag KADKADA_ZAUBERWASSER
gotoif EQUAL ow_script_0x87f3b7
lock
faceplayer
loadpointer 0x0 str_0x87f432
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_ZAUBERWASSER
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_no_room_for_giveitem
loadpointer 0x0 str_0x87f4bb
callstd MSG
setflag KADKADA_ZAUBERWASSER
release
end


ow_script_0x87f3b7:
loadpointer 0x0 str_0x87f4bb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f432:
    .autostring 34 2 "Wusstest du, dass in dem See hier ein Milotic leben soll?\pDas verleiht dem Wasser magische Kräfte!\pIch werde dir eine Kostprobe davon geben."
str_0x87f4bb:
    .autostring 34 2 "Das Zauberwasser verstärkt Wasser-Angriffe, wenn ein Pokémon es trägt.\pDas ist die Magie des sagenumwobenen Milotics von Kaskada.\pDu bist davon sicher ganz überwältigt, was?"


.elseif LANG_EN

.endif