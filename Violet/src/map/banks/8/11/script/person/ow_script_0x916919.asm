.include "overworld_script.s"
.include "species.s"

.global ow_script_0x916919
ow_script_0x916919:
setvar 0x8000 POKEMON_SHUPPET
call ow_script_find_egg
end
