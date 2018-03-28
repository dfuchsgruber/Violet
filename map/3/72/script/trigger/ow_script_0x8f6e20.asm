.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"


.global ow_script_movs_0x89d6a8
ow_script_movs_0x89d6a8:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8f6e20
ow_script_0x8f6e20:
loadpointer 0x0 str_0x89d64f
callstd MSG
applymovement 0xff ow_script_movs_0x89d6a8
waitmovement 0x0
end


.ifdef LANG_GER
.global str_0x89d64f

str_0x89d64f:
    .string "Die praktische Prüfung wird jeden\nMoment beginnen. Ich sollte auf\lden Pausenhof gehen."
        
        
.elseif LANG_EN

.endif
