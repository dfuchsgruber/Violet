.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x88c428
ow_script_0x88c428:
loadpointer 0x0 str_0x8a0763
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a0763

str_0x8a0763:
    .string "Der Angriff eines Pokémons bestimmt\nüber die Stärke seiner physischen\lAngriffe. Der Spezial-Angriff\ldagegen stärkt die speziellen\lAttacken. Ähnlich verhält es sich\lmit den Verteidigungswerten."
        
        
.elseif LANG_EN

.endif
