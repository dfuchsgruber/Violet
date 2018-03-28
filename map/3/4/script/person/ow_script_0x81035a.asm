.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81035a
ow_script_0x81035a:
loadpointer 0x0 str_0x8c8eab
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c8eab

str_0x8c8eab:
    .string "Wir wurden angewiesen, die Stadt\nabzuriegeln, solange Lord Faun\lsich den Revolutionären annimmt."
        
        
.elseif LANG_EN

.endif
