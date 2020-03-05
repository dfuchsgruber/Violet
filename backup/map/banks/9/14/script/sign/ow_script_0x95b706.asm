.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95b706
ow_script_0x95b706:
loadpointer 0x0 str_0x95c862
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95c862

str_0x95c862:
    .string "Herzlich willkommen bei der\nLaz.Corp.\pUnser Motto lautet: Wir machen\nZukunft zur Gegenwart."
        
        
.elseif LANG_EN

.endif
