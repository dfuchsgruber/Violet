.include "overworld_script.s"
.include "species.s"

.global ow_script_0x8fb3c3
ow_script_0x8fb3c3:
setvar 0x8000 POKEMON_RABAUZ
call ow_script_find_egg
end
