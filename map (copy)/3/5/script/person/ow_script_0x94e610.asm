.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e610
ow_script_0x94e610:
loadpointer 0x0 str_0x94e61a
callstd MSG_FACE
end

.global str_0x94e61a

str_0x94e61a:
    .string "Aber sicher doch! Es wundert mich,\ndass ein Junge in deinem Alter\lüberhaupt Interesse an soetwas\lzeigt..."
        
        