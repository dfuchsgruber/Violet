.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95ceb6
ow_script_0x95ceb6:
loadpointer 0x0 str_0x95cec0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95cec0

str_0x95cec0:
    .string "Seit Tagen nun leidet meine\nTochter an schrecklichen\lAlbträumen..."
        
        
.elseif LANG_EN

.endif
