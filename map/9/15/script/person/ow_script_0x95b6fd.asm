.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95b6fd
ow_script_0x95b6fd:
loadpointer 0x0 str_0x95c7d2
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95c7d2

str_0x95c7d2:
    .string "Fossilien häufen sich dort, wo\neine hohe Mineralkonzentration\lvorherrscht.\pAuf diese Weise können wir\neffizienter antike Pokémon\lrestaurieren."
        
        
.elseif LANG_EN

.endif
