.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8364ca
ow_script_0x8364ca:
loadpointer 0x0 str_0x8dec30
callstd MSG_FACE
end

.global str_0x8dec30

str_0x8dec30:
    .string "Ich bin für mein Leben gern\nGärtnerin. Die Beerenzucht ist ein\läußerst spannendes Hobby."
        
        