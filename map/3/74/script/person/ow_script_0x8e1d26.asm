.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e1d26
ow_script_0x8e1d26:
trainerbattlestd 0x0 0x31 0x0 str_0x8e1d3e str_0x8e2ad4
loadpointer 0x0 str_0x8e2ad4
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e1d3e

str_0x8e1d3e:
    .string "Mein Herz gehört einem Jungen, der\nmich vor langer Zeit allein\lgelassen hat."
        
        
.global str_0x8e2ad4

str_0x8e2ad4:
    .string "In einem Vergnügungspark habe ich\nihn das letzte Mal gesehen..."
        
        
.elseif LANG_EN

.endif
