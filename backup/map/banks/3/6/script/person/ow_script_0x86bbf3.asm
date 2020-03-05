.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86bbf3
ow_script_0x86bbf3:
loadpointer 0x0 str_0x86f08d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x86f08d

str_0x86f08d:
    .string "Ob wir Angst vor einem\nVulkanausbruch haben?\pFürchten sich die Leute an der\nKüste vor einem Tsunami?"
        
        
.elseif LANG_EN

.endif
