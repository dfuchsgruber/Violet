.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95a7e5
ow_script_0x95a7e5:
loadpointer 0x0 str_0x95a7ef
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95a7ef

str_0x95a7ef:
    .string "Auf dem Gemälde ist ein monströses\nFischwesen zu sehen, das scheinbar\lmit unergründlicher Stille am\lMeeresboden wandert."
        
        
.elseif LANG_EN

.endif
