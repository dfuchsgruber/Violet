.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a9625
ow_script_0x8a9625:
trainerbattlestd 0x0 0x9 0x0 str_0x8a9d7f str_0x8aaf13
loadpointer 0x0 str_0x8aaf13
callstd MSG_FACE
end

.global str_0x8a9d7f

str_0x8a9d7f:
    .string "Was ist berauschender als der\nKlang eines Baches oder der Duft\lvon frischem Laub?"
        
        
.global str_0x8aaf13

str_0x8aaf13:
    .string "Natur und Mensch sind keine\nFeinde, sondern brauchen einander.\pMerk dir das. Bitte."
        
        