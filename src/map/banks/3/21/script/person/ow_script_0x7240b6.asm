.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x7240b6
ow_script_0x7240b6:
trainerbattlestd 0x0 0x61 0x0 str_0x8ede71 str_0x8edee6
loadpointer 0x0 str_0x8edee6
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8ede71

str_0x8ede71:
    .string "Wie kann es hier so trocken sein,\nwährend Kaskada die Stadt der\lWasserquellen genannt wird?"
        
        
.global str_0x8edee6

str_0x8edee6:
    .string "Kaskada und diese Wüste liegen\nnahezu unmittelbar nebeneinander."
        
        
.elseif LANG_EN

.endif
