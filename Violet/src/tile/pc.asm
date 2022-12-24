@//All changes for the pc

.include "callstds.s"
.include "ordinals.s"
.include "vars.s"
.include "flags.s"
.include "overworld_script.s"

.global owscript_pc_turn_on
.global owscript_pc_turn_on2

owscript_pc_turn_on:
special 0x187
compare LASTRESULT 0x2
gotoif 1 none
lockall
setvar 0x8004 0x20
special 0x17D
setvar 0x8004 0x1
special 0xD6
sound 0x4
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
loadpointer 0 str_pc_turn_on
callstd MSG_KEEPOPEN
special 0xF9
waitstate
special 0x190
releaseall
clearflag TRANS_DISABLE
end

none:
release
clearflag TRANS_DISABLE
end

owscript_pc_turn_on2:

special 0x187
compare LASTRESULT 0x2
gotoif EQUAL none
lockall
sound 0x4
setvar 0x8004 0x20
special 0x17D
setvar 0x8004 0x0
special 0xD6
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
loadpointer 0 str_pc_turn_on
callstd MSG_KEEPOPEN
access:
loadpointer 0 str_pc_access
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x3
loadpointer 0 pc_choice
multichoice 0x0 0x0 0x0 0x0
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL storage
compare LASTRESULT 0x1
gotoif EQUAL playerpc
@//logout -> 0x2 was chosen
setvar 0x8004 0x0
sound 0x3
special 0xD7
special 0x190
releaseall
clearflag TRANS_DISABLE
end

storage:
loadpointer 0 str_pc_opened_storage
callstd MSG_KEEPOPEN
special 0x3C
waitstate
setvar 0x8004 0x1B
special 0x17D
goto access

playerpc:
sound 0x2
loadpointer 0 str_pc_connection
callstd MSG_KEEPOPEN
special 0xFA
waitstate
goto access


.align 4
pc_choice:
    .word str_pc_lagerungssystem, 0
    .word str_pc_player, 0
    .word str_pc_ausloggen, 0
