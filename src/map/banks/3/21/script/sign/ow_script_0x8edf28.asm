.include "map_connections.s"
.include "items.s"
.include "callstds.s"
.include "species.s"
.include "map_adjacency_types.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8edf28
ow_script_0x8edf28:
loadpointer 0x0 str_0x926b9d
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8ffcc2
random 0x4
compare LASTRESULT 0x1
gotoif LESS_OR_EQUAL ow_script_0x926c09
random 0x19
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x8ffc8a
setwildbattle POKEMON_TUSKA 0x19 ITEM_NONE
dowildbattle
end


.global ow_script_0x8ffc8a
ow_script_0x8ffc8a:
random 0x3
compare LASTRESULT 0x1
callif EQUAL ow_script_0x8ffcbb
setwildbattle POKEMON_NOKTUSKA 0x1e ITEM_NONE
dowildbattle
setvar NEXT_POKEMON_SHINY 0x0
end


.global ow_script_0x8ffcbb
ow_script_0x8ffcbb:
setvar NEXT_POKEMON_SHINY 0x1
return


.global ow_script_0x926c09
ow_script_0x926c09:
loadpointer 0x0 str_0x926c53
callstd MSG
end


.global ow_script_0x8ffcc2
ow_script_0x8ffcc2:
loadpointer 0x0 str_0x926beb
callstd MSG
end


.ifdef LANG_GER
.global str_0x926b9d

str_0x926b9d:
    .string "Der Katkus schimmert golden in der\nWüstensonne. Möchtest du an ihm\lrütteln?"
        
        
.global str_0x926c53

str_0x926c53:
    .string "Nichts passiertDOTS"
        
        
.global str_0x926beb

str_0x926beb:
    .string "PLAYER lässt den Kaktus in\nRuhe."
        
        
.elseif LANG_EN

.endif
