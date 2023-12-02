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
.global str_move_tutor_ask
.global str_move_tutor_select

say_exclam:
    .byte SAY_EXCLAM, STOP


ow_script_move_tutor_pay_items:
    setvar 0x8000 ITEM_RIESENPILZ
    setvar 0x8001 MOVE_TUTOR_NUM_BIG_MUSHROOMS
    checkitem ITEM_MINIPILZ MOVE_TUTOR_NUM_TINY_MUSHROOMS
    compare LASTRESULT 0x1
    gotoif LESS pay_large_mushroom
    setvar 0x8000 ITEM_MINIPILZ
    setvar 0x8001 MOVE_TUTOR_NUM_TINY_MUSHROOMS
    removeitem ITEM_MINIPILZ MOVE_TUTOR_NUM_TINY_MUSHROOMS
    bufferitem 0x0 0x8000
    buffernumber MOVE_TUTOR_NUM_BIG_MUSHROOMS 0x8001
    return

pay_large_mushroom:
    removeitem ITEM_RIESENPILZ MOVE_TUTOR_NUM_BIG_MUSHROOMS
    bufferitem 0x0 0x8000
    buffernumber MOVE_TUTOR_NUM_BIG_MUSHROOMS 0x8001
    return

ow_script_move_tutor_do:
    special SPECIAL_MOVE_TUTOR_SELECT_POKEMON
    waitstate
    lock
    faceplayer
    return

move_tutor_item_check:
    setvar 0x8000 ITEM_MINIPILZ
    setvar 0x8001 MOVE_TUTOR_NUM_TINY_MUSHROOMS
    checkitem ITEM_MINIPILZ MOVE_TUTOR_NUM_TINY_MUSHROOMS
    compare LASTRESULT 0x1
    gotoif EQUAL buffer_move_tutor_item
    setvar 0x8000 ITEM_RIESENPILZ
    setvar 0x8001 MOVE_TUTOR_NUM_BIG_MUSHROOMS
    checkitem ITEM_RIESENPILZ MOVE_TUTOR_NUM_BIG_MUSHROOMS
    compare LASTRESULT 0x1
    gotoif EQUAL buffer_move_tutor_item
    setvar LASTRESULT 0x0
item_check_return:
    return


buffer_move_tutor_item:
    bufferitem 0x0 0x8000
    buffernumber MOVE_TUTOR_NUM_BIG_MUSHROOMS 0x8001
    setvar LASTRESULT 0x1
    goto item_check_return


.ifdef LANG_GER
str_move_tutor_pay_items:
    .string "PLAYER übergibt\nBUFFER_2x BUFFER_1."
str_move_tutor_ask:
    .autostring 34 2 "Fantastisch!\nDu hast BUFFER_2-mal\lBUFFER_1!\pSoll ich einem deiner Pokémon BUFFER_3 beibringen?"
str_move_tutor_select:
    .autostring 34 2 "Welchem Pokémon soll ich BUFFER_3 beibringen?"
.elseif LANG_EN
str_move_tutor_pay_items:
    .string "PLAYER hands over\nBUFFER_2x BUFFER_1."
str_move_tutor_ask:
    .autostring 34 2 "Fantastic!\nYou have BUFFER_2\lBUFFER_1!\pShould I teach one of your Pokémon BUFFER_3?"
str_move_tutor_select:
    .autostring 34 2 "Which Pokémon should I teach BUFFER_3?"
.endif