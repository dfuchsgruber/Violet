.include "overworld_script.s"
.include "species.s"

.global ow_script_0x95edfb
ow_script_0x95edfb:
setvar 0x8000 POKEMON_FEURIGEL
call ow_script_find_egg
end
