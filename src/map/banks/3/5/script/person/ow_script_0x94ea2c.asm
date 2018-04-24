.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94ea2c
ow_script_0x94ea2c:
loadpointer 0x0 str_0x953aa8
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x953aa8

str_0x953aa8:
    .string "Wenn ich erwachsen bin, werde ich\nmich der Physik widmen, wie\lProfessor Primus.\lEr ist so klug! So toll!\lJa, Professor Primus!"
        
        
.elseif LANG_EN

.endif
