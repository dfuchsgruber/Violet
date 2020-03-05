.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8fb602
ow_script_0x8fb602:
checkflag FELSIGE_ODNIS_TM_STEEL_WING
gotoif EQUAL ow_script_0x8fb752
lock
faceplayer
loadpointer 0x0 str_0x8fb630
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM47
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8fb6cf
callstd MSG_KEEPOPEN
closeonkeypress
setflag FELSIGE_ODNIS_TM_STEEL_WING
release
end


.global ow_script_0x8fb752
ow_script_0x8fb752:
loadpointer 0x0 str_0x8fb75c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8fb630

str_0x8fb630:
    .string "Kennst du das? Du liebst es,\nFlug-Pokémon zu trainieren und\lwirst ständig von Gestein-Pokémon\lausgebremst?\pDann habe ich hier die perfekte\nAbhilfe für dich!"
        
        
.global str_0x8fb6cf

str_0x8fb6cf:
    .string "Stahlflügel ist eine Attacke, die\nvon fliegenden Pokémon ausgeführt\lwerden kann und selbst\lGestein-Pokémon sehr effektiv\ltrifft."
        
        
.global str_0x8fb75c

str_0x8fb75c:
    .string "Mit Stahlflügel kannst selbst\nlästige Gestein-Pokémon effektiv\ltreffen."
        
        
.elseif LANG_EN

.endif
