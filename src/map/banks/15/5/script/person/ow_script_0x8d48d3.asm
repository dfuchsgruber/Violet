.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "species.s"

.global ow_script_0x8d48d3
ow_script_0x8d48d3:
checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif LESS ow_script_0x8d48b1
loadpointer 0x0 str_0x8d48e6
callstd MSG
end


.global ow_script_0x8d48b1
ow_script_0x8d48b1:
setvar NEXT_POKEMON_SHINY 0x1
setvar 0x8000 POKEMON_WABLU
call ow_script_find_egg
setvar NEXT_POKEMON_SHINY 0x0
end


.ifdef LANG_GER
.global str_0x8d48e6

str_0x8d48e6:
    .string "Das Ei eines goldenen Altarias."
        
.elseif LANG_EN

.endif
