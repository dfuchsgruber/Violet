.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x844895
ow_script_0x844895:
lock
faceplayer
checkflag FLAG_ROUTE_2_QUICKCLAW
gotoif EQUAL ow_script_0x8448c2
loadpointer 0x0 str_0x8448cd
callstd MSG_FACE
copyvarifnotzero 0x8000 ITEM_FLINKKLAUE
copyvarifnotzero 0x8001 1
lock
callstd ITEM_OBTAIN
lock
setflag FLAG_ROUTE_2_QUICKCLAW
loadpointer 0x0 str_0x844937
callstd MSG_FACE
release
end


.global ow_script_0x8448c2
ow_script_0x8448c2:
loadpointer 0x0 str_0x844937
callstd MSG_FACE
release
end


.ifdef LANG_GER
.global str_0x8448cd

str_0x8448cd:
    .string "Oh sieh mal, was ich dort auf dem\nBoden gefunden habe! Eine\lmerkwürdige KlaueDOTS Willst du sie\lhaben?"
        
        
.global str_0x844937

str_0x844937:
    .string "Sie sieht wirklich ziemlich\nmerkwürdig aus, nicht?"
        
        
.elseif LANG_EN

.endif
