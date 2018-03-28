.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95e697
ow_script_0x95e697:
loadpointer 0x0 str_0x95eb56
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95eb56

str_0x95eb56:
    .string "Hui! Schau mal, ich wirble Asche\nauf, indem ich renne! Hui!"
        
        
.elseif LANG_EN

.endif
