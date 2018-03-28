.include "overworld_script.s"

.include "std.s"

.global ow_script_0x16b3a8
ow_script_0x16b3a8:
loadpointer 0x0 str_0x196800
callstd MSG_FACE
end

.global str_0x196800

str_0x196800:
    .string "Ich kann dir nur dringed davon\nabraten, ein Darlehn bei der Orina\lCity aufzunehmen.\pEin Großteil deines Preisgelds\nverschwindet im Handumdrehen und\lehe du dich versiehst, besitzt du\lkein Geld mehr."
        
        