.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95834f
ow_script_0x95834f:
loadpointer 0x0 str_0x958ef0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x958ef0

str_0x958ef0:
    .string "Die Pinselführung, die der\nKünstler hier an den Tag gelegt\lhat, ist wirklich einmalig."
        
        
.elseif LANG_EN

.endif
