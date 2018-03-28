.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a0ae8
ow_script_0x8a0ae8:
loadpointer 0x0 str_0x927e54
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x927e54

str_0x927e54:
    .string "Argh! So viele von diesen\nverfluchten Revolutionären...\pAber der große Lord Faun wird\ndiesen rebellischen Verbrechern\leinen Denkzettel verpassen!"
        
        
.elseif LANG_EN

.endif
