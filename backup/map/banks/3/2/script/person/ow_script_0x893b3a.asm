.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x893b3a
ow_script_0x893b3a:
loadpointer 0x0 str_0x8cb5ae
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8cb5ae

str_0x8cb5ae:
    .string "Was würde ich nur für einen\nRegenschirm gebenDOTS"
        
        
.elseif LANG_EN

.endif
