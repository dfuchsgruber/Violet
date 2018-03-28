.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8f1f22
ow_script_0x8f1f22:
loadpointer 0x0 str_0x926d9d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x926d9d

str_0x926d9d:
    .string "Wenn ich groß bin, möchte ich eine\nMillion POKEDOLLAR haben!\pDann kann ich mir endlich eine\nTour mit dem Kanu leisten!"
        
        
.elseif LANG_EN

.endif
