.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x9591b3
ow_script_0x9591b3:
trainerbattlestd 0x0 0x8f 0x0 str_0x959205 str_0x9591cb
loadpointer 0x0 str_0x9591cb
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x959205

str_0x959205:
    .string "Mistrals Division ist zweifellos\ndie mächtigste innerhalb von Team\lViolet.\pDu bist chancenlos!"
        
        
.global str_0x9591cb

str_0x9591cb:
    .string "Was? Du hast mich besiegt?\nDu hast \'was auf dem Kasten!"
        
        
.elseif LANG_EN

.endif
