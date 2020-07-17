.include "ordinals.s"
.include "vars.s"
.include "attacks.s"
.include "move_tutor.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "specials.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"


.global ow_script_move_tutor_pay_items
.global move_tutor_item_check
.global ow_script_move_tutor_do
.global str_move_tutor_pay_items

say_exclam:
    .byte SAY_EXCLAM, STOP


ow_script_move_tutor_pay_items:
    setvar 0x8000 ITEM_RIESENPILZ
    setvar 0x8001 0x1
    checkitem ITEM_MINIPILZ 0x3
    compare LASTRESULT 0x1
    gotoif LESS pay_large_mushroom
    setvar 0x8000 ITEM_MINIPILZ
    setvar 0x8001 0x3
    removeitem ITEM_MINIPILZ 0x3
    bufferitem 0x0 0x8000
    buffernumber 0x1 0x8001
    return

pay_large_mushroom:
    removeitem ITEM_RIESENPILZ 0x1
    bufferitem 0x0 0x8000
    buffernumber 0x1 0x8001
    return

ow_script_move_tutor_do:
    special SPECIAL_MOVE_TUTOR_SELECT_POKEMON
    waitstate
    lock
    faceplayer
    return

move_tutor_item_check:
    setvar 0x8000 ITEM_MINIPILZ
    setvar 0x8001 0x3
    checkitem ITEM_MINIPILZ 0x3
    compare LASTRESULT 0x1
    gotoif EQUAL buffer_move_tutor_item
    setvar 0x8000 ITEM_RIESENPILZ
    setvar 0x8001 0x1
    checkitem ITEM_RIESENPILZ 0x1
    compare LASTRESULT 0x1
    gotoif EQUAL buffer_move_tutor_item
    setvar LASTRESULT 0x0
    item_check_return:
    return


buffer_move_tutor_item:
    bufferitem 0x0 0x8000
    buffernumber 0x1 0x8001
    setvar LASTRESULT 0x1
    goto item_check_return


.ifdef LANG_GER
str_move_tutor_pay_items:
    .string "PLAYER übergibt\nBUFFER_2-mal BUFFER_1."
.elseif LANG_EN
str_move_tutor_pay_items:
    .string "PLAYER hands over\nBUFFER_2-times BUFFER_1."
.endif