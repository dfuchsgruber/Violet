.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8533
ow_script_0x8c8533:
loadpointer 0x0 str_0x8c8c3d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c8c3d

str_0x8c8c3d:
    .string "Der Schwarzmarkt floriert, während\ndie Top Vier ihre Augen\lverschließen.\pIst es nicht ironisch, dass selbst\nRevolutionäre hier verkehren?"
        
        
.elseif LANG_EN

.endif
