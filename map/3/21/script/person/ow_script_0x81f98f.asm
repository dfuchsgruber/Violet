.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81f98f
ow_script_0x81f98f:
loadpointer 0x0 str_0x8ffd29
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8ffd29

str_0x8ffd29:
    .string "Vor vielen Jahren herrschte in\ndieser Region ein schrecklicher\lKrieg.\lDrei engagierte Trainer aber\lbezwangen die Unruhen und riefen\ldie Pokémon-Liga und das System\lder Top Vier ins Leben."
        
        
.elseif LANG_EN

.endif
