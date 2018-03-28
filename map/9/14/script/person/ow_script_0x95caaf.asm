.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95caaf
ow_script_0x95caaf:
loadpointer 0x0 str_0x95cab9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95cab9

str_0x95cab9:
    .string "Wusstest du, dass das Pokémon\nLagerunssystem entscheidend durch\ldie Laz.Corp voran gebracht wurde?\pAbteilungsleiter Bill aus Kanto\nist ein Genie!"
        
        
.elseif LANG_EN

.endif
