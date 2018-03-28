.include "overworld_script.s"

.include "std.s"

.global ow_script_0x955d2e
ow_script_0x955d2e:
loadpointer 0x0 str_0x955d38
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x955d38

str_0x955d38:
    .string "Das Up-Grade ist eine Software,\nwelche die Kanten des virtuellen\lPokémon glätten kann."
        
        
.elseif LANG_EN

.endif
