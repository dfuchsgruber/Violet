.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e192f
ow_script_0x8e192f:
trainerbattlestd 0x0 0x30 0x0 str_0x8e1c76 str_0x8e1cdd
loadpointer 0x0 str_0x8e1cdd
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e1c76

str_0x8e1c76:
    .string "Es heißt, der Champion der Region\nsei ein junger Mann. Andere\lsprechen von einer wunderschönen\lLady."
        
        
.global str_0x8e1cdd

str_0x8e1cdd:
    .string "Wer auch immer der Champion Thetos\nist, er muss unglaublich stark\lsein."
        
        
.elseif LANG_EN

.endif
