.include "flags.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x955d90
ow_script_0x955d90:
checkflag ORINA_CITY_UP_GRADE
gotoif EQUAL ow_script_0x95809d
compare KARMA_VALUE 0x7fff
gotoif HIGHER ow_script_0x958032
lock
faceplayer
loadpointer 0x0 str_0x957fcc
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_UP_GRADE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x9580a7
callstd MSG
setflag ORINA_CITY_UP_GRADE
release
end


.global ow_script_0x958032
ow_script_0x958032:
loadpointer 0x0 str_0x95803c
callstd MSG_FACE
end


.global ow_script_0x95809d
ow_script_0x95809d:
loadpointer 0x0 str_0x9580a7
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x957fcc

str_0x957fcc:
    .string "Eben habe ich eine Software\nfertiggestellt, welche das\lvirtuelle Pokémon Porygon noch\lverbessert."
        
        
.global str_0x9580a7

str_0x9580a7:
    .string "Benutze ein Linkkabel, um das\nUp-Grade auf einem Porygon zu\linstallieren.\pEs wird seine Fähigkeiten deutlich\nverbessern."
        
        
.global str_0x95803c

str_0x95803c:
    .string "Das virtuelle Pokémon, an dem wir\narbeiten, wird sicherlich noch um\leiniges verbessert werden."
        
        
.elseif LANG_EN

.endif
