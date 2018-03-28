.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x87e9d3
ow_script_0x87e9d3:
loadpointer 0x0 str_0x87f23e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x87f23e

str_0x87f23e:
    .string "Es genügt nicht, Gutes zu tun,\nwenn man selbst keine\lBeeinträchtung erfährt.\pTrotz des eigenen Nachteils im\nSinne anderer zu handeln, das ist\lwahre Güte."
        
        
.elseif LANG_EN

.endif
