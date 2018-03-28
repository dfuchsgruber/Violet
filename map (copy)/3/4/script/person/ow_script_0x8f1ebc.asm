.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f1ebc
ow_script_0x8f1ebc:
checkflag KASKADA_EVOLITHE
gotoif EQUAL ow_script_0x8f218b
compare KARMA_VALUE 0x7fff
gotoif HIGHER ow_script_0x8f20c9
compare KARMA_VALUE 0x40
gotoif LESS ow_script_0x8f2059
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


.global ow_script_0x8f2059
ow_script_0x8f2059:
loadpointer 0x0 str_0x8f2063
callstd MSG_FACE
end


.global ow_script_0x8f20c9
ow_script_0x8f20c9:
loadpointer 0x0 str_0x8f20d3
callstd MSG_FACE
end


.global ow_script_0x8f218b
ow_script_0x8f218b:
loadpointer 0x0 str_0x8f211b
callstd MSG_FACE
end

.global str_0x8f1fda

str_0x8f1fda:
    .string "Ich sehe ein Licht in deinem\nHerzen, das dem der Sonne gleicht.\lJemand deines Charakters hat es\lverdient, belohnt zu werden."
        
        
.global str_0x8f1f5c

str_0x8f1f5c:
    .string "Der Evolith stärkt schwache\nPokémon, so wie die Starken auch\lin unserer Gesellschaft die\lSchwachen in Schutz nehmen müssen."
        
        
.global str_0x8f2063

str_0x8f2063:
    .string "Tust du Gutes, wird dir Gutes\nwiderfahren. Dieser Grundsatz wird\ldir ein erfülltes Leben bescheren."
        
        
.global str_0x8f20d3

str_0x8f20d3:
    .string "Dein Herz ist voller Hass...\nBefreie den Herz, es wird dich\lbefreien!"
        
        
.global str_0x8f211b

str_0x8f211b:
    .string "Wenn eigennützige Taten sich\nzunächst lohnen mögen, so sind\lgute Handlungen auf lange Sicht\limmer sinnvoller."
        
        