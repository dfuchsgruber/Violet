.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a3c95
ow_script_0x8a3c95:
loadpointer 0x0 str_0x8a538f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a538f

str_0x8a538f:
    .string "Viele Leute nennen Route 2 auch\ndie Birkenstraße. Ich muss wohl\lnicht erklären, wieso, oder?"
        
        
.elseif LANG_EN

.endif
