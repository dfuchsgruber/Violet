.include "overworld_script.s"
.include "flags.s"
.include "vars.s"
.include "callstds.s"
.include "attacks.s"
.include "ordinals.s"
.include "species.s"
.include "items.s"

.global ow_script_battle_test
ow_script_battle_test:
    lock
    faceplayer
    setflag PLAYER_ABLE_TO_MEGA_EVOLVE
    loadpointer 0x0 start_text
    callstd MSG_YES_NO
    compare LASTRESULT 0x1
    callif EQUAL give
    loadpointer 0x0 teach_text
    callstd MSG_YES_NO
    compare LASTRESULT 0x1
    callif EQUAL teach
    setwildbattle POKEMON_GROUDON 0x64 ITEM_MAGMAHERZ
    dowildbattle
    release
    end

give:
    givepokemon POKEMON_GROUDON 0x64 ITEM_MAGMAHERZ 0x0 0x0 0x0
    return

teach:
    setvar 0x8005 0x12
    call ow_script_move_tutor_do
    return

start_text:
    .autostring 35 2 "Brauchst du ein Pokémon für den Kampf?"

teach_text:
    .autostring 35 2 "Soll ich einem Pokémon Donnerwelle beibringen?"