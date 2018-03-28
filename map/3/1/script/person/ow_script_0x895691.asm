.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x895691
ow_script_0x895691:
loadpointer 0x0 str_0x8a1f57
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a1f57

str_0x8a1f57:
    .string "Die Stadt der Berge, nennt man\nMeriana City mancherorts. Es\lheißt, dass hier der Arenaleiter\lKamillo aus Hoenn ausgebildet\lwurde. Seit dem zieht dieser Ort\lviele Kampf-Trainer an."
        
        
.elseif LANG_EN

.endif
