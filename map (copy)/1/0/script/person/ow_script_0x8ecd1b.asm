.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ecd1b
ow_script_0x8ecd1b:
loadpointer 0x0 str_0x8f4419
callstd MSG_FACE
end

.global str_0x8f4419

str_0x8f4419:
    .string "Es heißt, dass es einen Stein\ngeben soll, der das Herz der Zeit\lrepräsentiert. Seine Energie soll\lgrenzenlos sein."
        
        