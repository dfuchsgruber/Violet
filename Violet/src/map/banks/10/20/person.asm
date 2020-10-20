.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_10_20_person_1
.global ow_script_map_10_20_person_0

ow_script_map_10_20_person_1:
loadpointer 0x0 str_0x965b49
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965b49:
    .string "Feuerpokémon haben in diesem Haus\nkeinen Zutritt.\pWas soll sonst aus der\nHolzmöblierung werden?"


.elseif LANG_EN

.endif


ow_script_map_10_20_person_0:
loadpointer 0x0 str_0x965baa
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965baa:
    .string "Eines meiner wertvollsten Bücher\nhandelt von dem Landmassen-Pokémon\lGroudon.\pDer Legende nach schuf es in einem\nKrieg mit seinem ewigen Rivalen\lalle Landmasse dieser Welt."


.elseif LANG_EN

.endif