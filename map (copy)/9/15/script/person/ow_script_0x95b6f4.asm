.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95b6f4
ow_script_0x95b6f4:
loadpointer 0x0 str_0x95c769
callstd MSG_FACE
end

.global str_0x95c769

str_0x95c769:
    .string "Ist dir der Name Lester ein\nBegriff?\pEr ist ein großer Unterstützer des\nFossilienprojekts der Laz.Corp."
        
        