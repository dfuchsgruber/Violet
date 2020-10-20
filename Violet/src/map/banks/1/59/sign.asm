.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_1_59_sign_0

ow_script_map_1_59_sign_0:
loadpointer 0x0 str_0x8ffff2
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8ffff2:
    .string "Küstenberg"


.elseif LANG_EN

.endif