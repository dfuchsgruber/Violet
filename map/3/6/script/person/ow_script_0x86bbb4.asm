.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86bbb4
ow_script_0x86bbb4:
loadpointer 0x0 str_0x86bd85
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x86bd85

str_0x86bd85:
    .string "Mistrals Division in Team Violet\nüberragt die von Rin bei weitem.\pWir sind eine gefährliche Macht,\ndie alles niederstampft!"
        
        
.elseif LANG_EN

.endif
