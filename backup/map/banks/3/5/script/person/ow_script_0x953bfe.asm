.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x953bfe
ow_script_0x953bfe:
loadpointer 0x0 str_0x953c08
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x953c08

str_0x953c08:
    .string "Der Architekt dieses Gebäudes\ngehört wahrlich ausgezeichnet.\lUnd das sage ich nicht nur, weil\lich zufällig eben dieser bin!"
        
        
.elseif LANG_EN

.endif
