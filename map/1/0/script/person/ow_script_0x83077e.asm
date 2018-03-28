.include "overworld_script.s"

.include "std.s"

.global ow_script_0x83077e
ow_script_0x83077e:
loadpointer 0x0 str_0x8ef577
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8ef577

str_0x8ef577:
    .string "Freddies Musik soll einer Legende\nnach sogar legendäre Pokémon\lvernichten können."
        
        
.elseif LANG_EN

.endif
