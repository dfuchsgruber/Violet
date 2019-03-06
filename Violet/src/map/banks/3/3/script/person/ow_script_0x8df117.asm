.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8df117
ow_script_0x8df117:
loadpointer 0x0 str_0x8e0932
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e0932

str_0x8e0932:
    .string "Der amtierende Champion soll\näußert bescheiden sein. Niemand\lweiß, wer er oder sie istDOTS"
        
        
.elseif LANG_EN

.endif
