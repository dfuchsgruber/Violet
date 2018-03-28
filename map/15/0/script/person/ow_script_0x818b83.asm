.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x818b83
ow_script_0x818b83:
trainerbattlestd 0x0 0x18 0x0 str_0x818b9b str_0x818bd9
loadpointer 0x0 str_0x818bd9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x818b9b

str_0x818b9b:
    .string "Vögel sind zwar schwer zu fangen,\naber die Mühe lohnt sich!"
        
        
.global str_0x818bd9

str_0x818bd9:
    .string "Vögel zu fangen, würde sich auch\nfür dich lohnen."
        
        
.elseif LANG_EN

.endif
