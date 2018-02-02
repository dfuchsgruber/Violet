.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x91fece
ow_script_movs_0x91fece:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8ffe00
ow_script_0x8ffe00:
loadpointer 0x0 str_0x91fed1
callstd MSG
lock
sound 0x15
applymovement 0x800f ow_script_movs_0x91fece
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x91fcc4
callstd MSG
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x90fdce
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x90fd48
callstd MSG
special 0x7
trainerbattlecont 0x1 0x64 0x0 str_0x8fff26 str_0x8fff9c ow_script_0x8ffe63

.align 4
choice:
    .word str_violet_grunt_choice_0, 0
    .word str_violet_grunt_choice_1, 0

.global ow_script_0x8ffe63
ow_script_0x8ffe63:
lock
faceplayer
loadpointer 0x0 str_0x8ffe77
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.global ow_script_0x90fdce
ow_script_0x90fdce:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x90fe3d
callstd MSG
special 0x7
loadpointer 0x0 str_0x90fdef
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
end
