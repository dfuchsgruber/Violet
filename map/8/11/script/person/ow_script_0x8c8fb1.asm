.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8fb1
ow_script_0x8c8fb1:
loadpointer 0x0 str_0x931b2f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x931b2f

str_0x931b2f:
    .string "Ich eine Schwester des Pokéstops?\nDas ist ein Irrtum!\pDas Pokéstop-Franchise steht in\nkeiner Verbindung zu diesem\lSchwarzmarkt! Ehrlich!"
        
        
.elseif LANG_EN

.endif
