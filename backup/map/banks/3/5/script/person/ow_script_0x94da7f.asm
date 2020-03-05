.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94da7f
ow_script_0x94da7f:
loadpointer 0x0 str_0x94e1bd
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e1bd

str_0x94e1bd:
    .string "Hast du schon vom Poképad gehört?\nEs soll ein Entwicklungsprojekt\lder Laz.Corp sein und das\lTrainerdasein für immer\lrevolutionieren!"
        
        
.elseif LANG_EN

.endif
