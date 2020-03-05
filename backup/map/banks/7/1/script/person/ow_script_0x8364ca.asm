.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8364ca
ow_script_0x8364ca:
loadpointer 0x0 str_0x8dec30
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8dec30

str_0x8dec30:
    .string "Ich bin für mein Leben gern\nGärtnerin. Die Beerenzucht ist ein\läußerst spannendes Hobby."
        
        
.elseif LANG_EN

.endif
