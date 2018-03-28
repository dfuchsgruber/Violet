.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8aaf68
ow_script_0x8aaf68:
loadpointer 0x0 str_0x927ee7
callstd MSG
end


.ifdef LANG_GER
.global str_0x927ee7

str_0x927ee7:
    .string "Nimm das, du Schurke!\pWir wollen keine Revolution hier,\nwir brauchen keinen Krieg!"
        
        
.elseif LANG_EN

.endif
