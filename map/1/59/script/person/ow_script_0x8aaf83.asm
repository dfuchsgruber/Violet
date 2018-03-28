.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8aaf83
ow_script_0x8aaf83:
loadpointer 0x0 str_0x928010
callstd MSG
end


.ifdef LANG_GER
.global str_0x928010

str_0x928010:
    .string "Wenn wir nicht für eine bessere\nWelt kämpfen, wer dann?"
        
        
.elseif LANG_EN

.endif
