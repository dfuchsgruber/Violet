.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x955dc7
ow_script_0x955dc7:
loadpointer 0x0 str_0x958121
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x958121

str_0x958121:
    .string "So ein MistDOTS\nEiner von diesen Team Violet\lRüpeln hat mir doch glatt meine\lDubiosdisc geklautDOTS\pDie Software ist noch\nunvollständigDOTS\pIch will mir gar nicht ausmalen,\nwas sie mit Porygon anstellen\lkannDOTS"
        
        
.elseif LANG_EN

.endif
