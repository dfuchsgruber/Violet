.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81112e
ow_script_0x81112e:
loadpointer 0x0 str_0x811138
callstd MSG_FACE
end

.global str_0x811138

str_0x811138:
    .string "Aktania war einst eine schöne Stadt\nam Strand. Jedes Jahr hatten wir\ltausende Besucher hier, aber dann\lkam der schwarze Nebel und hat den\lganzen Strand vernebelt und die\lStadt verdunkelt... "
        
        