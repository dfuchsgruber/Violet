.include "overworld_script.s"

.include "std.s"

.global ow_script_0x83344d
ow_script_0x83344d:
loadpointer 0x0 str_0x87f9d5
callstd MSG_FACE
end

.global str_0x87f9d5

str_0x87f9d5:
    .string "Im Fernsehen laufen oft sehr\nspannende Berichte!\pErst kürzlich habe ich eine\nDokumentation über das seltene\lPokémon Barschwa gesehen."
        
        