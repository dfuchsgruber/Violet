.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x82a1c4
ow_script_0x82a1c4:
loadpointer 0x0 str_0x847089
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x847089

str_0x847089:
    .string "Einst war dieser Ort ein\nFerienparadies. Jeden Tag\lSonnenschein und Schwärme von\lWingull an den Stränden."
        
        
.elseif LANG_EN

.endif
