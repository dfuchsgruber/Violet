.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x84c6b9
ow_script_0x84c6b9:
loadpointer 0x0 str_0x84c6c3
callstd MSG
end


.ifdef LANG_GER
.global str_0x84c6c3

str_0x84c6c3:
    .string "ZzzDOTS Schnarch DOTS\nGraaähDOTS ZzzDOTS ZzzDOTS"
        
        
.elseif LANG_EN

.endif
