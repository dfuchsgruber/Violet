.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95e564
ow_script_0x95e564:
trainerbattlestd 0x0 0x96 0x0 str_0x95e57c str_0x95e5cf
loadpointer 0x0 str_0x95e5cf
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95e57c

str_0x95e57c:
    .string "Ich bin nicht begeistert von\ndiesem Ort, aber mein Pokémon\lliebt ihn über alles."
        
        
.global str_0x95e5cf

str_0x95e5cf:
    .string "Mit einem Hundemon am\nHöllenschlund spazieren gehen..."
        
        
.elseif LANG_EN

.endif
