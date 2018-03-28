.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87f51e
ow_script_0x87f51e:
loadpointer 0x0 str_0x9272eb
callstd MSG_FACE
end

.global str_0x9272eb

str_0x9272eb:
    .string "Mein Papa sagt immer, dass ein\nguter Trainer auch ein guter\lMensch sein sollte."
        
        