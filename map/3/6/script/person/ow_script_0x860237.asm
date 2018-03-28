.include "overworld_script.s"

.include "std.s"

.global ow_script_0x860237
ow_script_0x860237:
loadpointer 0x0 str_0x860241
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x860241

str_0x860241:
    .string "Mistral wird das Fragment des\nZeitsteins sicherstellen.\pSolange er beschäftigt ist, halten\nwir die Stadt in Schach."
        
        
.elseif LANG_EN

.endif
