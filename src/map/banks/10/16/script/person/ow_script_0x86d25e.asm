.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86d25e
ow_script_0x86d25e:
trainerbattlestd 0x0 0xab 0x0 str_0x86d276 str_0x86d2a0
loadpointer 0x0 str_0x86d2a0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x86d276

str_0x86d276:
    .string "In dieser Arena ist es wahnsinnig\nheiß!"
        
        
.global str_0x86d2a0

str_0x86d2a0:
    .string "Die Hitze macht einem echt zu\nschaffen."
        
        
.elseif LANG_EN

.endif
