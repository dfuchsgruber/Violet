.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c856b
ow_script_0x8c856b:
loadpointer 0x0 str_0x93155a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93155a

str_0x93155a:
	.autostring 35 2 "Sei gegrüßt!\pMeine Wenigkeit verkauft leistungsfähige Supermagneten.\pDOTS DOTS DOTS\pDu weißt wohl gar nicht, von was ich spreche, was?"
        
.elseif LANG_EN

.endif
