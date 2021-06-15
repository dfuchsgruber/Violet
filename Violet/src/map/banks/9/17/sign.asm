.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"

.global ow_script_0x955420
.global ow_script_0x9554d7
.global ow_script_map_9_17_sign_0

ow_script_map_9_17_sign_0:
setflag TRANS_DISABLE
loadpointer 0x0 str_0x9553a2
callstd MSG_KEEPOPEN
special 0x2e
waitstate
compare LASTRESULT 0x7f
gotoif EQUAL ow_script_0x9554d7
special 0x2f
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x955420
closeonkeypress
special 0x111
waitstate
releaseall
clearflag TRANS_DISABLE
end


ow_script_0x955420:
loadpointer 0x0 str_0x95544f
callstd MSG
clearflag TRANS_DISABLE
end


ow_script_0x9554d7:
closeonkeypress
releaseall
clearflag TRANS_DISABLE
end


.ifdef LANG_GER

str_0x9553a2:
    .string "PLAYER nutzt die Zugangskarte.\nWähle ein Stockwerk."



str_0x95544f:
    .string "Du befindest dich bereits in\ndiesem Stockwerk."


.elseif LANG_EN

.endif