.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"
.include "items.s"

.global ow_script_desert_blue_tent_water_stone_gift
.global ow_script_desert_blue_tent_person_0

ow_script_desert_blue_tent_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_desert_blue_tent_water_stone_gift:
    lock
    faceplayer
    checkflag FLAG_DESERT_RED_BLUE_TENT_ITEM
    gotoif EQUAL done
    loadpointer 0x0 str_intro_water_stone
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL dont_like
    loadpointer 0 str_give_water_stone
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_WASSERSTEIN
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    loadpointer 0x0 str_after_receiving_water_stone
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
str_intro_water_stone:
    .autostring 34 2 "In dieser Wüste ist es so unterträglich heißDOTS\pDa ist es doch nur passend, ein blaues Zelt zu beziehen, oder?\pDas erinnert einen nämlich an WasserDOTS"
str_dont_like:
    .autostring 34 2 "D-Du musst scherzen!\pDann geh doch in das rote Zelt, ja?\pKeiner wird doch davon abhalten, eine schlechte Wahl zu treffen.\pMit den Konsequenzen deiner Fehlentscheidungen musst letztendlich auch nur du leben."
str_give_water_stone:
    .autostring 34 2 "Gut gesprochen!\pSo ein gutes Einschätzungsvermögen will belohnt sein."
str_after_receiving_water_stone:
    .autostring 34 2 "Spürst du, wie kühl dieser Wasserstein ist?\pDarüber ist man in einer brütend heiße Wüste doch froh, oder?"
str_0:
    .autostring 34 2 "Ein rotes Zelt inmitten einer WüsteDOTS\pDas ist doch wirklich grotesk, oder?\pWenn es so heiß hergeht, dann heißt es, einen kühlen Kopf zu bewahren.\pUnd deshalb ist das blaue Zelt auch die richtige Wahl, wenn man sich keinen Sonnenstich zuziehen möchte, meinst du nicht auch?"
str_1:
    .autostring 34 2 "Wer eine echte Verschnaufpause von dieser Hitze da draußen brauchtDOTS\pNa, der wird seinen Weg in unser blaues Zelt finden, meinst du nicht?"
.elseif LANG_EN
.endif