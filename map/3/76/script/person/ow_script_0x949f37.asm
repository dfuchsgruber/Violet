.include "overworld_script.s"

.include "std.s"

.global ow_script_0x949f37
ow_script_0x949f37:
trainerbattlestd 0x0 0x8c 0x0 str_0x94db4f str_0x94dba2
loadpointer 0x0 str_0x94dba2
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94db4f

str_0x94db4f:
    .string "Ein neues Gesicht unter den\nWolkenreitern?\pZeig mir, was du auf dem Kasten\nhast!"
        
        
.global str_0x94dba2

str_0x94dba2:
    .string "Ah! Du scheinst etwas vom Fliegen\nzu verstehen!"
        
        
.elseif LANG_EN

.endif
