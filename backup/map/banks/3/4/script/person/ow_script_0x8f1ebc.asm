.include "flags.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8f1ebc
ow_script_0x8f1ebc:
checkflag KASKADA_EVOLITHE
gotoif EQUAL ow_script_0x8f218b
lock
faceplayer
loadpointer 0x0 str_0x8f1fda
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_EVOLITH
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8f1f5c
callstd MSG
setflag KASKADA_EVOLITHE
release
end



.global ow_script_0x8f218b
ow_script_0x8f218b:
loadpointer 0x0 str_0x8f1f5c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f1fda

str_0x8f1fda:
    .autostring 34 2 "Auch ein schwaches Pokémon kann stark sein.\pDiesen Ratschlag möchte ich dir ans Herz legen."
        
        
.global str_0x8f1f5c

str_0x8f1f5c:
    .string "Der Evolith kann die Stärken eines scheinbar schwachen Pokémon hervorbringen, sofern es sich noch entwickeln kann."
        
.elseif LANG_EN

.endif
