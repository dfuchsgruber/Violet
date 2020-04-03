.include "vars.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"

.global ow_script_map_15_5_trainer_1
.global ow_script_map_15_5_trainer_0
.global ow_script_0x8d48b1

ow_script_map_15_5_trainer_0:
trainerbattlestd 0x0 0x27 0x0 str_0x8d441f str_0x8d43b9
loadpointer 0x0 str_0x8d43b9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8d441f:
    .string "Bist du auch gekommen, um\nVogelpokemon zu fangen?"



str_0x8d43b9:
    .string "Hier in dieser Mühle leben sehr\nviele Flug-Pokémon. Als\lVogelfänger ist das für mich sehr\lnützlich."


.elseif LANG_EN

.endif

ow_script_map_15_5_trainer_1:
checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif LESS ow_script_0x8d48b1
loadpointer 0x0 str_0x8d48e6
callstd MSG
end


ow_script_0x8d48b1:
setvar NEXT_POKEMON_SHINY 0x1
setvar 0x8000 POKEMON_WABLU
call ow_script_find_egg
setvar NEXT_POKEMON_SHINY 0x0
end


.ifdef LANG_GER

str_0x8d48e6:
    .string "Das Ei eines goldenen Altarias."

.elseif LANG_EN

.endif