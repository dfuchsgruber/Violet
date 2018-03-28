.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e697
ow_script_0x95e697:
loadpointer 0x0 str_0x95eb56
callstd MSG_FACE
end

.global str_0x95eb56

str_0x95eb56:
    .string "Hui! Schau mal, ich wirble Asche\nauf, indem ich renne! Hui!"
        
        