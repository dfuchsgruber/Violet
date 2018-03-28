.include "overworld_script.s"

.include "std.s"

.global ow_script_0x803dab
ow_script_0x803dab:
loadpointer 0x0 str_0x80f654
callstd MSG_FACE
end

.global str_0x80f654

str_0x80f654:
    .string "In dem Haus dort oben wohnt\nProfessor Tann. Du solltest ihn\lunbedingt mal besuchen!"
        
        