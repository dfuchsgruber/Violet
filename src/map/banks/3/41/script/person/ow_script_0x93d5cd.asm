.include "overworld_script.s"
.include "species.s"

.global ow_script_0x93d5cd
ow_script_0x93d5cd:
setvar 0x8000 POKEMON_ELEKID
call ow_script_find_egg
end

