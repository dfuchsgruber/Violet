.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_24_sign_0

ow_script_map_3_24_sign_0:
loadpointer 0x0 str_0x95ef3e
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95ef3e:
    .string "Westen: Route 6\nOsten: Orina City"


.elseif LANG_EN

.endif