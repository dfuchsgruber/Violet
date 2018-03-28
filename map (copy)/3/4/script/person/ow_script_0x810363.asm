.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810363
ow_script_0x810363:
loadpointer 0x0 str_0x8c8f0d
callstd MSG_FACE
end

.global str_0x8c8f0d

str_0x8c8f0d:
    .string "Lord Faun wird den Revolutionären\nzeigen, wie stark ein Mitglied der\lTop Vier ist!"
        
        