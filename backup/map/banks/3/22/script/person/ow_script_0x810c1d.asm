.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x810c1d
ow_script_0x810c1d:
loadpointer 0x0 str_0x9367ce
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9367ce

str_0x9367ce:
    .string "Hast du je von der Königin der\nFinsternis gehört?\pEin berühmtes Kindermärchen, das\nvon einer Hexe handelt, welche\lSeelen vertilgt."
        
        
.elseif LANG_EN

.endif
