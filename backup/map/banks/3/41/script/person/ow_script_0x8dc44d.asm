.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8dc44d
ow_script_0x8dc44d:
loadpointer 0x0 str_0x8de6b0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8de6b0

str_0x8de6b0:
    .string "Krieg den Top Vier, Krieg dem\nChampion! Friede dem Volk!"
        
        
.elseif LANG_EN

.endif
