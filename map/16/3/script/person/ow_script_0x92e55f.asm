.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x92e55f
ow_script_0x92e55f:
loadpointer 0x0 str_0x93ba54
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93ba54

str_0x93ba54:
    .string "Die Wanderung entlang des\nWasserpfades ist sehr beliebt\lunter Wanderern.\pAllein die Vorstellung unter einem\ngewaltigen Fluss zu marschieren...\pUnfassbar, nicht?"
        
        
.elseif LANG_EN

.endif
