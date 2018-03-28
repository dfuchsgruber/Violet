.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87e9e5
ow_script_0x87e9e5:
loadpointer 0x0 str_0x87f361
callstd MSG_FACE
end

.global str_0x87f361

str_0x87f361:
    .string "Hunger! Hunger!\nIch will essen!"
        
        