.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x898622
ow_script_0x898622:
trainerbattlestd 0x0 0x24 0x0 str_0x899a49 str_0x899ac7
loadpointer 0x0 str_0x899ac7
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x899a49

str_0x899a49:
    .string "Joggen ist gut für Herz und\nKreislauf! Die Waldluft, die vom\lZeitwald hierher gelangt, befreit\ldie Atemwege meiner Pokémon!"
        
        
.global str_0x899ac7

str_0x899ac7:
    .string "Dann muss ich mein Training wohl\netwas verschärfen!"
        
        
.elseif LANG_EN

.endif
