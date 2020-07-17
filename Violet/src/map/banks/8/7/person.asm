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
    .string "Bist du mit den Entscheidungen,\ndie du getroffen hast, zufrieden?\lStehst du hinter dem, was du getan\lhast? Hättest du mehr tun sollen?"


.elseif LANG_EN

.endif


ow_script_map_8_7_person_1:
loadpointer 0x0 str_0x87f361
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f361:
    .string "Hunger! Hunger!\nIch will essen!"


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
    .string "Es heißt, das Quellwasser vom\nKüstenberg habe magische\lFähigkeiten. Seine bloße Präsenz\lsoll das Wasser in seiner\lUmgebung verstärken."



str_0x87f4bb:
    .string "Wenn du der Legende glauben\nschenkst, wird das Zauberwasser\lseine Wirkung entfalten,\lversprochen!"


.elseif LANG_EN

.endif