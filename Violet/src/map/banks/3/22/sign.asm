.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_22_sign_0

ow_script_map_3_22_sign_0:
loadpointer 0x0 str_0x91831f
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x91831f:
    .string "Wasserpfad"


.elseif LANG_EN

.endif