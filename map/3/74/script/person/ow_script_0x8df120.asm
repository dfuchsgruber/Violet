.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8df120
ow_script_0x8df120:
loadpointer 0x0 str_0x8e1081
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e1081

str_0x8e1081:
    .string "Dieser Ort trägt den Namen\n\Felsige Ödnis\ zurecht.\lIn dieser Savanne findet man\linteressante Pokémon."
        
        
.elseif LANG_EN

.endif
