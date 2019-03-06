.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8dc594
ow_script_0x8dc594:
loadpointer 0x0 str_0x8dea32
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8dea32

str_0x8dea32:
    .string "Wende dich gegen deine\nUnterdrücker, Junge! Sei kein\lSklave der Top Vier!"
        
        
.elseif LANG_EN

.endif
