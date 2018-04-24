.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x915104
ow_script_0x915104:
trainerbattlestd 0x0 0x6f 0x0 str_0x92ddd7 str_0x92de26
loadpointer 0x0 str_0x92de26
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x92ddd7

str_0x92ddd7:
    .string "Wärst du eine Blume, würde ich\ndich pflücken, du bist so hübsch\lanzusehen..."
        
        
.global str_0x92de26

str_0x92de26:
    .string "Unglücklicherweise aber hast du\nnun mich gepflückt... Findest du\lmich etwa auch anziehend?"
        
        
.elseif LANG_EN

.endif
