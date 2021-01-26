.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"
.include "items.s"

.global ow_script_desert_red_tent_fire_stone_gift
.global ow_script_desert_red_tent_person_0

ow_script_desert_red_tent_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_desert_red_tent_fire_stone_gift:
    lock
    faceplayer
    checkflag FLAG_DESERT_RED_BLUE_TENT_ITEM
    gotoif EQUAL done
    loadpointer 0x0 str_intro_fire_stone
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL dont_like
    loadpointer 0 str_give_fire_stone
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_FEUERSTEIN
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    loadpointer 0x0 str_after_receiving_fire_stone
    callstd MSG_KEEPOPEN
    closeonkeypress
    releaseall
    setflag FLAG_DESERT_RED_BLUE_TENT_ITEM
    end

done:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end
dont_like:
    loadpointer 0 str_dont_like
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_intro_fire_stone:
    .autostring 34 2 "Verrückt muss man sein, ein Zelt in der Wüste aufzuschlagen, oder?\pAber so sind wir hier!\pWer ins rote Zelt kommt, lässt sich von niemandem etwas sagen.\pDeswegen bist du hierher gekommen oder?\pDu findest doch auch das rote Zelt im Welten besser als das blaue, ja?"
str_dont_like:
    .autostring 34 2 "J-Ja was?\pWillst du mir ernsthaft weiß machen, dass du das blaue Zelt vorziehst?\pNa dann geh' doch zu den Banausen im blauen Zelt, ja?"
str_give_fire_stone:
    .autostring 34 2 "Das ist die richtige Antwort, Kindchen!\pHier, das ist für dich.\pEine Belohnung für deinen ausgezeichneten Geschmack!"
str_after_receiving_fire_stone:
    .autostring 34 2 "Dieser Stein ist in den Händen eines so aufmerksamen jungen Trainers bestens aufgehoben, findest du nicht?\pDa sieht das blaue Zelt ganz schön alt aus, oder?"
str_0:
    .autostring 34 2 "Das rote Zelt ist dem blauen einfach haushoch überlegen.\pAllein farblich ist ein blaues Zelt für eine Wüste doch schon total ungeeignet, oder?"
str_1:
    .autostring 34 2 "Jemand mit echtem Feuer im Blut, der kann nicht anders, als in unser rotes Zelt zu kommen!\pWir lassen uns von der Sonne nicht unterkriegen, ja?"
.elseif LANG_EN
.endif