.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x938384
ow_script_0x938384:
loadpointer 0x0 str_0x93c0e4
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93c0e4

str_0x93c0e4:
    .string "Manus legt großen Wert auf\nDisziplin.\lNur wer sich im griff hat, wird\lgewinnen."
        
        
.elseif LANG_EN

.endif
