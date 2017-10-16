.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8e07eb
ow_script_movs_0x8e07eb:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8e1e30
ow_script_0x8e1e30:
checkflag MERIANA_CITY_REVOLUTIONARIES
gotoif LESS ow_script_0x8de301
checkflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
gotoif EQUAL ow_script_0x8de4b5
loadpointer 0x0 str_0x8e07ee
callstd MSG_KEEPOPEN
sound 0x15
faceplayer
applymovement 0x800f ow_script_movs_0x8e07eb
waitmovement 0x0
loadpointer 0x0 str_0x8e066f
callstd MSG_KEEPOPEN
clearflag MERIANA_CITY_REVOLUTIONARIES
addvar MERIANA_CITY_REVOLUTIONARY 0x1
closeonkeypress
end


.global ow_script_0x8de4b5
ow_script_0x8de4b5:
compare STORY_PROGRESS 0x7f
gotoif EQUAL ow_script_0x8de66e
loadpointer 0x0 str_0x8de630
callstd MSG_FACE
end


.global ow_script_0x8de66e
ow_script_0x8de66e:
loadpointer 0x0 str_0x8e1de2
callstd MSG_FACE
end


.global ow_script_0x8de301
ow_script_0x8de301:
checkflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
gotoif EQUAL ow_script_0x8de4b5
loadpointer 0x0 str_0x8de430
callstd MSG_FACE
end
