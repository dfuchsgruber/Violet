.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x9603c0
ow_script_0x9603c0:
loadpointer 0x0 str_0x961de7
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x961de7

str_0x961de7:
    .string "Inferior - Die Höllenpforte"
        
        
.elseif LANG_EN

.endif
