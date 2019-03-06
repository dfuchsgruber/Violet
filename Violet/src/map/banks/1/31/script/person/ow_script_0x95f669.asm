.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95f669
ow_script_0x95f669:
trainerbattlestd 0x0 0x9a 0x0 str_0x95f681 str_0x95f6f4
loadpointer 0x0 str_0x95f6f4
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95f681

str_0x95f681:
    .string "Ein Wanderer muss jede Wanderung\nauf sich nehmen.\lSelbst bei der Aussicht zu\lverbrennen, kann ich nicht\lkneifen!"
        
        
.global str_0x95f6f4

str_0x95f6f4:
    .string "Deine Herausforderung ist wohl das\nEnde meiner WanderschaftDOTS"
        
        
.elseif LANG_EN

.endif
