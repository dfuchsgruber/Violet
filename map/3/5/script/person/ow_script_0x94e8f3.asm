.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e8f3
ow_script_0x94e8f3:
loadpointer 0x0 str_0x94e8fd
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e8fd

str_0x94e8fd:
    .string "Kennst du die Tochter von\nProfessor Primus?\pSie ist ein wirklich bezauberndes\nMädchen...\pAber ich traue mich nicht, ihr\nmeine Bewunderung zu gestehen..."
        
        
.elseif LANG_EN

.endif
