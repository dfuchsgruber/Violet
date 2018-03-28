.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ee2d
ow_script_0x95ee2d:
loadpointer 0x0 str_0x95ee37
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95ee37

str_0x95ee37:
    .string "Ich würde mir gut überlegen, ob\nich weiter nach Westen gehe...\pEs heißt, dass die Hitze des\nVulcano einem das Hirn versengt..."
        
        
.elseif LANG_EN

.endif
