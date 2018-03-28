.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95f5e5
ow_script_0x95f5e5:
trainerbattlestd 0x0 0x99 0x0 str_0x95f5fd str_0x95f646
loadpointer 0x0 str_0x95f646
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95f5fd

str_0x95f5fd:
    .string "Ah, du willst gegen mich kämpfen?\nIch habe noch keinen Kampf\lverloren!"
        
        
.global str_0x95f646

str_0x95f646:
    .string "Für alles gibt es ein erstes Mal."
        
        
.elseif LANG_EN

.endif
