.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c852a
ow_script_0x8c852a:
loadpointer 0x0 str_0x8c8b6b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c8b6b

str_0x8c8b6b:
    .string "Wieso ich mich Team Violet\nangeschlossen habe?\pMein Leben war bedeutungslos, bis\nman mir die Chance gegeben hat,\ldie Welt zu einem besseren Ort zu\lmachen.\pViele sehen nicht, dass wir der\nWelt Frieden bringen."
        
        
.elseif LANG_EN

.endif
