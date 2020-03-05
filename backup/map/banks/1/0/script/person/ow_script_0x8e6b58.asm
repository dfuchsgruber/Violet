.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8e6b58
ow_script_0x8e6b58:
trainerbattlestd 0x0 0x45 0x0 str_0x8efa78 str_0x8efb78
loadpointer 0x0 str_0x8efb78
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8efa78

str_0x8efa78:
    .string "Ich muss in der Region für Ordnung\nund Sicherheit sorgen. Freiwillige\lRanger sind im Gegensatz zur\lPolizei nicht korrupt."
        
        
.global str_0x8efb78

str_0x8efb78:
    .string "Team Violet ist sowohl der Polizei\nals auch den Rangern ein Dorn im\lAuge!"
        
        
.elseif LANG_EN

.endif
