.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95ce02
ow_script_0x95ce02:
loadpointer 0x0 str_0x95ce0c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95ce0c

str_0x95ce0c:
    .string "Bücher sind der Weg, einen Geist\nauch über den Tod hinweg am Leben\lzu erhalten."
        
        
.elseif LANG_EN

.endif
