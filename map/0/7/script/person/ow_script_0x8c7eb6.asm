.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c7eb6
ow_script_0x8c7eb6:
trainerbattlestd 0x0 0x6b 0x0 str_0x8c7ece str_0x8c7efc
loadpointer 0x0 str_0x8c7efc
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c7ece

str_0x8c7ece:
    .string "Dieser Ort ist wirklich\nwunderschön, nicht?"
        
        
.global str_0x8c7efc

str_0x8c7efc:
    .string "Dieses bläulich leuchtende Gestein\nist faszinierend."
        
        
.elseif LANG_EN

.endif
