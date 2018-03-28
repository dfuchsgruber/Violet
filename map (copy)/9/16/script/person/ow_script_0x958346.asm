.include "overworld_script.s"

.include "std.s"

.global ow_script_0x958346
ow_script_0x958346:
loadpointer 0x0 str_0x958a43
callstd MSG_FACE
end

.global str_0x958a43

str_0x958a43:
    .string "Sieh dir nur mal dieses Pokémon\nan!\pSein Skelett ist riesig!"
        
        