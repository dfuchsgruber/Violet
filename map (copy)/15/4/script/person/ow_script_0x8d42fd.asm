.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d42fd
ow_script_0x8d42fd:
trainerbattlestd 0x0 0x15 0x0 str_0x8d433f str_0x8d4315
loadpointer 0x0 str_0x8d433f
callstd MSG_FACE
end

.global str_0x8d433f

str_0x8d433f:
    .string "Es heißt, in dieser Mühle würde\nein goldenes Altaria nisten.\lOb an den Gerüchten etwas dran\list?"
        
        
.global str_0x8d4315

str_0x8d4315:
    .string "Oho! Du hast da ein paar nette\nPokémon!"
        
        