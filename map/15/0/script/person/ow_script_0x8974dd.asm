.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8974dd
ow_script_0x8974dd:
trainerbattlestd 0x0 0x1b 0x0 str_0x8998d3 str_0x899949
loadpointer 0x0 str_0x899949
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8998d3

str_0x8998d3:
    .string "Wahre Schönheit kommt von Innen.\nEine Naturdame wie ich verzichtet\ldeshalb ganz auf\lumweltverschmutzende Kosmetika!"
        
        
.global str_0x899949

str_0x899949:
    .string "Mein Gesicht ist von Natur aus\nschön!"
        
        
.elseif LANG_EN

.endif
