.include "overworld_script.s"
.include "species.s"


.global ow_script_0x8dce51
ow_script_0x8dce51:
setvar 0x8000 POKEMON_ENECO
call ow_script_find_egg
end

