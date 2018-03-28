.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810e25
ow_script_0x810e25:
loadpointer 0x0 str_0x810ec2
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x810ec2

str_0x810ec2:
    .string "Hey! Verschwinde du Balg!"
        
        
.elseif LANG_EN

.endif
