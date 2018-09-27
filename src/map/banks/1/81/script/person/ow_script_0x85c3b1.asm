.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x85c3b1
ow_script_0x85c3b1:
trainerbattlestd 0x0 0xa3 0x0 str_0x864425 str_0x86444f
loadpointer 0x0 str_0x86444f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x864425

str_0x864425:
    .string "Eindringling.. IchDOTS schwitze..\nKampf!"
        
        
.global str_0x86444f

str_0x86444f:
    .string "Die Hitze hier ist unerträglich!\nWieso sind wir überhaupt in einem\lVulkan?"
        
        
.elseif LANG_EN

.endif
