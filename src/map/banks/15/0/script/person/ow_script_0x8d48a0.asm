.include "overworld_script.s"
.include "species.s"

.global ow_script_0x8d48a0
ow_script_0x8d48a0:
setvar 0x8000 POKEMON_PIKACHU
call ow_script_find_egg
end
