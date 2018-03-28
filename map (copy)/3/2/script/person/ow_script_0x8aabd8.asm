.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8aabd8
ow_script_0x8aabd8:
loadpointer 0x0 str_0x8c0ff2
callstd MSG_FACE
end

.global str_0x8c0ff2

str_0x8c0ff2:
    .string "Aktania, die Insel der ewigen\nSonne!\l...\pKaum zu glauben, dass dieser Ort\nmal ein Strandresort war, oder?"
        
        