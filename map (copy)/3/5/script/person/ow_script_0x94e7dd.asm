.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e7dd
ow_script_0x94e7dd:
loadpointer 0x0 str_0x94e7e7
callstd MSG_FACE
end

.global str_0x94e7e7

str_0x94e7e7:
    .string "Die Orina City Bank ist gerissen.\nNimmst du dir einen Kredit,\lverlangen sie ein Fünftel als\lZinssatz.\pUnd sie kapseln es klammheimlich\nvon deinem gewonnen Preisgeld ab!\lUnverschämtheit!"
        
        