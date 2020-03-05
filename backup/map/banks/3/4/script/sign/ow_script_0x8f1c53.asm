.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8f1c53
ow_script_0x8f1c53:
loadpointer 0x0 str_0x8f1c5d
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8f1c5d

str_0x8f1c5d:
    .string "Eingang: Felsige Ödnis\nSüden: Wasserpfad"
        
        
.elseif LANG_EN

.endif
