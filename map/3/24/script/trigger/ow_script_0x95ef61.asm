.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ef61
ow_script_0x95ef61:
lockall
clearflag PKMNMENU
showsprite 0x3
setflag PKMNMENU
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
setvar 0x8004 0x3
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x89ba6e
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x95efaa
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x95efbe
trainerbattlecont 0x1 0x14e 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


.global ow_script_0x95f001
ow_script_0x95f001:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x95f255
callstd MSG_KEEPOPEN
special 0x7
copyvarifnotzero 0x8000 ITEM_VM03
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
call ow_script_0x89ba6e
loadpointer 0x0 str_0x95f051
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x3
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x95efbe
ow_script_0x95efbe:
trainerbattlecont 0x1 0x14d 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


.global ow_script_0x95efaa
ow_script_0x95efaa:
trainerbattlecont 0x1 0x14c 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001
