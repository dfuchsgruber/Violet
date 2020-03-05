.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94e610
ow_script_0x94e610:
loadpointer 0x0 str_0x94e61a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e61a

str_0x94e61a:
    .string "Aber sicher doch! Es wundert mich,\ndass ein Junge in deinem Alter\lüberhaupt Interesse an soetwas\lzeigtDOTS"
        
        
.elseif LANG_EN

.endif
