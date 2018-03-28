.include "overworld_script.s"

.include "std.s"

.global ow_script_0x71ab07
ow_script_0x71ab07:
trainerbattlestd 0x0 0x4f 0x0 str_0x71ab1f str_0x8fb233
loadpointer 0x0 str_0x71ab61
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x71ab1f

str_0x71ab1f:
    .string "Vorhin war ein hübsches Mädchen\nmit rotem Kopftuch hier!"
        
        
.global str_0x8fb233

str_0x8fb233:
    .string "Sie war vielleicht hübsch aber\nebenso stark!"
        
        
.global str_0x71ab61

str_0x71ab61:
    .string "Sie war stark!"
        
        
.elseif LANG_EN

.endif
