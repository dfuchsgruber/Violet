.include "overworld_script.s"
.include "species.s"

.global ow_script_0x8e6853
ow_script_0x8e6853:
setvar 0x8000 POKEMON_FLUFFELUFF
call ow_script_find_egg
end
