.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8ac1aa
ow_script_0x8ac1aa:
pause 0x20
goto ow_script_0x8cb3c8


.global ow_script_0x8cb3c8
ow_script_0x8cb3c8:
checkflag POKERADAR_POKEMON_SPAWNED
gotoif LESS ow_script_0x8ac1e8
goto ow_script_0x8ac281


.global ow_script_0x8ac281
ow_script_0x8ac281:
fadescreen 0x1
sound 0x27
checksound
sound 0x27
checksound
sound 0x27
checksound
callasm 0x919a201
compare POKERADAR_EMENY_SPECIES 0xffff
gotoif EQUAL ow_script_0x8ac33f
callasm 0x9199e31
compare 0x8002 0x0
gotoif EQUAL ow_script_0x8ac33f
callasm 0x9199de1
hidesprite 0xfe
showsprite 0xfe
clearflag POKERADAR_POKEMON_SPAWNED
fadescreen 0x0
callasm 0x9199c01
cry 0x8000 0x0
call ow_script_0x8ac217
waitcry
loadpointer 0x0 str_0x8ac2ec
callstd MSG
setvar POKERADAR_ENEMY_STATE 0x0
end


.global ow_script_0x8ac217
ow_script_0x8ac217:
random 0x4
addvar LASTRESULT 0x52
singlemovement 0xfe 0x800d
waitmovement 0x0
singlemovement 0xfe 0x800d
waitmovement 0x0
singlemovement 0xfe 0x63
waitmovement 0x0
return


.global ow_script_0x8ac33f
ow_script_0x8ac33f:
fadescreen 0x0
loadpointer 0x0 str_0x8ac34b
callstd MSG
end


.global ow_script_0x8ac1e8
ow_script_0x8ac1e8:
loadpointer 0x0 str_0x8ac381
callstd MSG
end


.ifdef LANG_GER
.global str_0x8ac2ec

str_0x8ac2ec:
    .string "Ein Pokémon scheint hier in der\nNähe zu sein! Lass dich nicht von\lihm erwischen!"
        
        
.global str_0x8ac34b

str_0x8ac34b:
    .string "Der Pokeradar konnte keine Pokémon\nausfindig machen."
        
        
.global str_0x8ac381

str_0x8ac381:
    .string "Aber der Pokeradar hat doch schon\nein Pokémon entdeckt!"
        
        
.elseif LANG_EN

.endif
