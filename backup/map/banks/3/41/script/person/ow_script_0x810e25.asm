.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x810e25
ow_script_0x810e25:
loadpointer 0 str_violet_grunt
special 0xE
loadpointer 0x0 str_0x810ec2
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER
.global str_0x810ec2

str_violet_grunt:
	.string "Team Violet Rüpel"

str_0x810ec2:
    .string "Hey! Verschwinde du Balg!"
        
        
.elseif LANG_EN

.endif
