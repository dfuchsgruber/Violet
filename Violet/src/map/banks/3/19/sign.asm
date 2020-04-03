.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_19_sign_0
@ ToDo: Investigate the letter-casing

ow_script_map_3_19_sign_0:
loadpointer 0x0 str_0x823a89
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x823a89:
    .string "Route 1: Verbindungsstrecke\nAmonia - Meriana City"


.elseif LANG_EN

.endif