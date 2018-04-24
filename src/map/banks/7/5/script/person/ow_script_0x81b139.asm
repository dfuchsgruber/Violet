.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81b139
ow_script_0x81b139:
trainerbattlestd 0x0 0x3d 0x0 str_0x81b151 str_0x81b1b1
loadpointer 0x0 str_0x81b1b1
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x81b151

str_0x81b151:
    .string "Ich liebe diese Arena! Der Geruch\nvon frischen Planzen lässt mich auf\lWolke sieben schweben."
        
        
.global str_0x81b1b1

str_0x81b1b1:
    .string "Ahh! Dieser Duft!\nWas? Nein ich bin nicht verrückt!"
        
        
.elseif LANG_EN

.endif
