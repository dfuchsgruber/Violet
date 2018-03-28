.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb44c
ow_script_0x8fb44c:
loadpointer 0x0 str_0x928e02
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x928e02

str_0x928e02:
    .string "Kaskada wurde am Fuß des\nKüstenbergs erbaut und benutzt die\lEnergie der Wasserfälle, um eine\lStromversorgung zu garantieren."
        
        
.elseif LANG_EN

.endif
