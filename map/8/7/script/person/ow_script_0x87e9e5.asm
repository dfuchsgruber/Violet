.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x87e9e5
ow_script_0x87e9e5:
loadpointer 0x0 str_0x87f361
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x87f361

str_0x87f361:
    .string "Hunger! Hunger!\nIch will essen!"
        
        
.elseif LANG_EN

.endif
