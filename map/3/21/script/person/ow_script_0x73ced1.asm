.include "overworld_script.s"

.include "std.s"

.global ow_script_0x73ced1
ow_script_0x73ced1:
trainerbattlestd 0x0 0x1c7 0x0 str_0x743d3a str_0x743d7f
loadpointer 0x0 str_0x743d7f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x743d3a

str_0x743d3a:
    .string "Was eine Exorzistin in der Wüste zu\nsuchen hat? Ich weiß es nicht!"
        
        
.global str_0x743d7f

str_0x743d7f:
    .string "Hinterfrage nie die Gedanken\nunseres Schöfpers!"
        
        
.elseif LANG_EN

.endif
