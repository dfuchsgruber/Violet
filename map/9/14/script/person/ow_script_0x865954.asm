.include "overworld_script.s"

.include "std.s"

.global ow_script_0x865954
ow_script_0x865954:
loadpointer 0x0 str_0x947ab3
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x947ab3

str_0x947ab3:
    .string "Professor Primus ist eine Koryphäe\nauf dem Gebiet der Physik.\pSeine Abhandlungen zur Raum-Zeit-\nStruktur sind hochspannend."
        
        
.elseif LANG_EN

.endif
