.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e367
ow_script_0x94e367:
loadpointer 0x0 str_0x94e371
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e371

str_0x94e371:
    .string "Faun setzt sich für die Sauberkeit\nauf den Straßen von Orina City\lein.\pErst durch seine Herrschaft ist\ndieser Ort wirklich schön\lgeworden."
        
        
.elseif LANG_EN

.endif
