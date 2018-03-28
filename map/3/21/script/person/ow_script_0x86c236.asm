.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86c236
ow_script_0x86c236:
trainerbattlestd 0x0 0x6a 0x0 str_0x926c12 str_0x926c67
loadpointer 0x0 str_0x926c67
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x926c12

str_0x926c12:
    .string "Oh, ich verdurste hier noch in\ndieser trockenen Ödnis!"
        
        
.global str_0x926c67

str_0x926c67:
    .string "Wo, wo ist nur ein Brunnen!"
        
        
.elseif LANG_EN

.endif
