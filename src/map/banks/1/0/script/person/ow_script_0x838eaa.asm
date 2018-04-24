.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x838eaa
ow_script_0x838eaa:
trainerbattlestd 0x0 0x41 0x0 str_0x88ae2e str_0x8e6b0e
loadpointer 0x0 str_0x8e6b0e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x88ae2e

str_0x88ae2e:
    .string "Ich will nicht in die Schule\ngehen! Unterricht ist so öde!"
        
        
.global str_0x8e6b0e

str_0x8e6b0e:
    .string "In der Schule hätte ich bestimmt\ngelernt, dich zu besiegen!"
        
        
.elseif LANG_EN

.endif
