.include "overworld_script.s"

.include "std.s"

.global ow_script_0x958a81
ow_script_0x958a81:
trainerbattlestd 0x0 0x8e 0x0 str_0x959139 str_0x959100
loadpointer 0x0 str_0x959100
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x959139

str_0x959139:
    .string "Du willst dich mit uns anlegen?\pWenn Mistral erst das Magmaherz\nin seinem Besitz hat, wird das\lniemandem mehr gelingen!"
        
        
.global str_0x959100

str_0x959100:
    .string "Erfreu dich an deinem Sieg,\nsolange du es noch kannst!"
        
        
.elseif LANG_EN

.endif
