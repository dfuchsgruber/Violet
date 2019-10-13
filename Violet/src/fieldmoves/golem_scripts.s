.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "movements.s"
.include "flags.s"
.include "attacks.s"
.include "callstds.s"
.include "specials.s"

.global ow_script_field_move_golem_regirock
.global ow_script_field_move_golem_regirock_open_cave

ow_script_field_move_golem_regirock:
    setanimation 0x0 LASTRESULT
    bufferpartypokemon 0x0 LASTRESULT
    bufferattack 0x1 ATTACK_BLITZ
    doanimation 0x2
    nop
    waitstate
    setvar 0x8004 0x2
    setvar 0x8005 0x2
    setvar 0x8006 0xA
    setvar 0x8007 0x3
    special SPECIAL_EARTHQUAKE
    pause 0x3C
    call ow_script_field_move_golem_regirock_open_cave
    special SPECIAL_MAP_UPDATE_BLOCKS
    sound 0x21
    checksound
    setflag FLAG_REGIROCK_PUZZLE_SOLVED
    release
end_script:
    end

ow_script_field_move_golem_regirock_open_cave:
    setmaptile 0x8 0x17 0x2c4 0x1
    setmaptile 0x9 0x17 0x2c4 0x1
    setmaptile 0xa 0x17 0x2c4 0x1
    setmaptile 0x8 0x18 0x28b 0x1
    setmaptile 0x9 0x18 0x28c 0x1
    setmaptile 0xa 0x18 0x28d 0x1
    setmaptile 0x8 0x19 0x293 0x1
    setmaptile 0x9 0x19 0x294 0x0
    setmaptile 0xa 0x19 0x295 0x1
    return
