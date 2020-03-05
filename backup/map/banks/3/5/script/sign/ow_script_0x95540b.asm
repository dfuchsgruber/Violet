.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95540b
ow_script_0x95540b:
loadpointer 0x0 str_0x9558a6
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x9558a6

str_0x9558a6:
    .string "Laz.Corp - Wir machen Zukunft zur\nGegenwart"
        
        
.elseif LANG_EN

.endif
