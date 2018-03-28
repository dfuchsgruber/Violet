.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8d48d3
ow_script_0x8d48d3:
checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif LESS ow_script_0x8d48b1
loadpointer 0x0 str_0x8d48e6
callstd MSG
end


.global ow_script_0x8d48b1
ow_script_0x8d48b1:
bufferstring 0x0 str_0x8d48cd
setvar 0x8000 0x166
setvar NEXT_POKEMON_SHINY 0x1
call ow_script_0x8d421d
setvar NEXT_POKEMON_SHINY 0x0
end

.global str_0x8d48e6

str_0x8d48e6:
    .string "Das Ei eines goldenen Altarias."
        
        
.global str_0x8d48cd

str_0x8d48cd:
    .string "Flug"
        
        