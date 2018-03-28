.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95da57
ow_script_0x95da57:
loadpointer 0x0 str_0x95da61
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95da61

str_0x95da61:
    .string "Haus des Attacken-Erinnerers"
        
        
.elseif LANG_EN

.endif
