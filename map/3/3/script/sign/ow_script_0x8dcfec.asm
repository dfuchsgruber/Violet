.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8dcfec
ow_script_0x8dcfec:
loadpointer 0x0 str_0x8de313
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8de313

str_0x8de313:
    .string "Haus von Mia"
        
        
.elseif LANG_EN

.endif
