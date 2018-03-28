.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x71cf79
ow_script_0x71cf79:
trainerbattlestd 0x0 0x52 0x0 str_0x7287d7 str_0x72880b
loadpointer 0x0 str_0x72880b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x7287d7

str_0x7287d7:
    .string "Ich frage mich, wie viele Ebenen\ndiese Höhle hat!"
        
        
.global str_0x72880b

str_0x72880b:
    .string "Ich hoffe, es sind nicht mehr als\nzwei Ebenen!"
        
        
.elseif LANG_EN

.endif
