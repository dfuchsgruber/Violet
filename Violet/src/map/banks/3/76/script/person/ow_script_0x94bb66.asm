.include "overworld_script.s"
.include "species.s"

.global ow_script_0x94bb66
ow_script_0x94bb66:
setvar 0x8000 POKEMON_PANZAERON
call ow_script_find_egg
end

