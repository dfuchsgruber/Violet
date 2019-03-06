.include "overworld_script.s"
.include "species.s"

.global ow_script_route_2_east_egg_0
ow_script_route_2_east_egg_0:
setvar 0x8000 POKEMON_PHANPY
call ow_script_find_egg
end
