.include "overworld_script.s"

.include "std.s"

.global ow_script_0x948cfa
ow_script_0x948cfa:
loadpointer 0x0 str_0x94c2dd
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94c2dd

str_0x94c2dd:
    .string "Besitzt du auch eine Detektor?\pIn den Optionen kannst du\neinstellen, ob du benachricht\lwerden willst, wenn du dich in die\lNähe eines versteckten Items\lbegibst."
        
        
.elseif LANG_EN

.endif
