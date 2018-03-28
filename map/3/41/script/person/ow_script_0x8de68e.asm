.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8de68e
ow_script_0x8de68e:
loadpointer 0x0 str_0x8e6508
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e6508

str_0x8e6508:
    .string "Südlich von hier liegt Ceometria,\ndie Insel der Toten.\pWann immer ein Trainer einen\nVerlust betrauern muss, besucht er\ldiesen Ort..."
        
        
.elseif LANG_EN

.endif
