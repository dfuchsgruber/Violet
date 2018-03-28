.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a3c22
ow_script_0x8a3c22:
loadpointer 0x0 str_0x8a3c2c
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8a3c2c

str_0x8a3c2c:
    .string "Eingang zum Wassertunnel\nNorden: Kaskada"
        
        
.elseif LANG_EN

.endif
