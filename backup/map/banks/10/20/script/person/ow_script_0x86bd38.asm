.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86bd38
ow_script_0x86bd38:
loadpointer 0x0 str_0x965baa
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x965baa

str_0x965baa:
    .string "Eines meiner wertvollsten Bücher\nhandelt von dem Landmassen-Pokémon\lGroudon.\pDer Legende nach schuf es in einem\nKrieg mit seinem ewigen Rivalen\lalle Landmasse dieser Welt."
        
        
.elseif LANG_EN

.endif
