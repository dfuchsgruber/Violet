.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x819199
ow_script_0x819199:
loadpointer 0x0 str_0x8471be
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8471be

str_0x8471be:
    .string "Mia aus Silvania kommt oft hierher\nund überwacht die Vegetation. Ohne\lsie würde die Umwelt hier\lzusammenbrechen."
        
        
.elseif LANG_EN

.endif
