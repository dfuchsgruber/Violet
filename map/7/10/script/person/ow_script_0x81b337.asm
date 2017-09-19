.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81b337
ow_script_0x81b337:
checkflag FRBADGE_2
gotoif EQUAL ow_script_0x81b34a
loadpointer 0x0 str_0x81b37f
callstd MSG_FACE
end


.global ow_script_0x81b34a
ow_script_0x81b34a:
loadpointer 0x0 str_0x81b354
callstd MSG_FACE
end
