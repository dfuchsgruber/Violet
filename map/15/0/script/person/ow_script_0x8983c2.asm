.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8983c2
ow_script_0x8983c2:
trainerbattlestd 0x0 0x22 0x0 str_0x8999f3 str_0x899a36
loadpointer 0x0 str_0x899a36
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8999f3

str_0x8999f3:
    .string "Du Einfaltspinsel! Lass mich dir\netwas von meinem Karate zeigen!"
        
        
.global str_0x899a36

str_0x899a36:
    .string "Ka! Ra! Te! Buhu!"
        
        
.elseif LANG_EN

.endif
