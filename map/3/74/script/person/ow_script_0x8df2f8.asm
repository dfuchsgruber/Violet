.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8df2f8
ow_script_0x8df2f8:
trainerbattlestd 0x0 0x2e 0x0 str_0x8e1843 str_0x8e18b9
loadpointer 0x0 str_0x8e18b9
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e1843

str_0x8e1843:
    .string "Das Wetter in dieser Gegend ist\ngrauenvoll. In dieser ariden\lUmgebung können meine Pflanzen-\lPokémon nicht wachsen!"
        
        
.global str_0x8e18b9

str_0x8e18b9:
    .string "Ich sollte zurück in den\nSilvania-Wald gehen."
        
        
.elseif LANG_EN

.endif
