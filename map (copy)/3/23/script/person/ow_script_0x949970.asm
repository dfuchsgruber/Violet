.include "overworld_script.s"

.include "std.s"

.global ow_script_0x949970
ow_script_0x949970:
compare KARMA_VALUE 0x7fff
gotoif HIGHER ow_script_0x949a7f
checkflag ROUTE_5_SANFTGLOCKE
gotoif EQUAL ow_script_0x949a37
lock
faceplayer
loadpointer 0x0 str_0x9499a7
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_SANFTGLOCKE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x949a41
callstd MSG_FACE
setflag ROUTE_5_SANFTGLOCKE
end


.global ow_script_0x949a37
ow_script_0x949a37:
loadpointer 0x0 str_0x949a41
callstd MSG_FACE
end


.global ow_script_0x949a7f
ow_script_0x949a7f:
loadpointer 0x0 str_0x949a89
callstd MSG_FACE
end

.global str_0x9499a7

str_0x9499a7:
    .string "Du siehst mir aus wie jemand, der\nsich darum bemüht, ein enges Band\lzu seinen Pokémon aufzubauen.\pNimm dieses Item, es wird dir\ndabei helfen."
        
        
.global str_0x949a41

str_0x949a41:
    .string "Trägt ein Pokémon die Sanftglocke,\nso wird es zutraulicher."
        
        
.global str_0x949a89

str_0x949a89:
    .string "Du siehst mir nicht wie jemand\naus, der viel auf seine Pokémon\lgibt.\lLass dir das sein gut gemeinter\lRatschlag sein und achte nicht nur\lauf dein eigenes Wohlbefinden."
        
        