.include "overworld_script.s"

.include "std.s"

.global ow_script_0x899eec
ow_script_0x899eec:
loadpointer 0x0 str_0x8a2858
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a2858

str_0x8a2858:
    .string "Der Wassertunnel ist eingstürzt.\nDer Arenaleiter Manus\larbeitet derzeit an seiner\lReperatur, bitte gedulde dich."
        
        
.elseif LANG_EN

.endif
