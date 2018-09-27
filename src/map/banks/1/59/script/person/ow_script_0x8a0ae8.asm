.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a0ae8
ow_script_0x8a0ae8:
loadpointer 0x0 str_0x927e54
callstd MSG_FACE
end


.ifdef LANG_GER

str_police:
.global str_0x927e54

str_0x927e54:
	.autostring 35 2 "Argh!\pDiese verdammten Revolutionäre!\pAber Lord Faun wird diesen Regierungsfeinden einen Denkzettel verpassen!"
        
        
.elseif LANG_EN

.endif
