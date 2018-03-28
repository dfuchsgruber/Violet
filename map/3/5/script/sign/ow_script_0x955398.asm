.include "overworld_script.s"

.include "std.s"

.global ow_script_0x955398
ow_script_0x955398:
loadpointer 0x0 str_0x955429
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x955429

str_0x955429:
    .string "Orina City Mauzi Bank"
        
        
.elseif LANG_EN

.endif
