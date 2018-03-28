.include "overworld_script.s"

.include "std.s"

.global ow_script_0x918308
ow_script_0x918308:
trainerbattlestd 0x0 0x77 0x0 str_0x935d84 str_0x93679b
loadpointer 0x0 str_0x93679b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x935d84

str_0x935d84:
    .string "Etikette und Anstand sind zeichen\neines guten Charakters."
        
        
.global str_0x93679b

str_0x93679b:
    .string "Nur wer sich auch zu benehmen\nweiß, kann kämpfen."
        
        
.elseif LANG_EN

.endif
