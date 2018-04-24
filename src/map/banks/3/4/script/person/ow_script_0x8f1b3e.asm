.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8f1b3e
ow_script_0x8f1b3e:
loadpointer 0x0 str_0x8f1b48
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f1b48

str_0x8f1b48:
    .string "Willst du mich verurteilen, dass\nich mir mein Essen in Mülltonnen\lsuche?\pVerurteile lieber das System, das\neinem alten Mann nicht genug zu\lEssen gibt!"
        
        
.elseif LANG_EN

.endif
