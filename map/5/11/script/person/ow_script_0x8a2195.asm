.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a2195
ow_script_0x8a2195:
loadpointer 0x0 str_0x8a33ff
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a33ff

str_0x8a33ff:
    .string "Mein Großvater ist ein\nGeschichtsfanatiker. Er kennt\lviele Lengenden und Mythen. Dafür\lkann ich mich allerdings nicht\lbegeistern. Mich interessiert nur\ldie neuste Mode!"
        
        
.elseif LANG_EN

.endif
