.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a683c
ow_script_0x8a683c:
trainerbattlestd 0x0 0xa 0x0 str_0x8a8910 str_0x8a896a
loadpointer 0x0 str_0x8a896a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a8910

str_0x8a8910:
    .string "Ein Kampf ist im Grunde wie Strom.\nUnd wir Trainer stehen dabei\lgehörig unter Spannung!"
        
        
.global str_0x8a896a

str_0x8a896a:
    .string "Oh je. Ich glaube, da hab ich wohl\neinen Kurzschluss verursacht..."
        
        
.elseif LANG_EN

.endif
