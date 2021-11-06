.include "overworld_script.s"
.include "callstds.s"
.include "movements.s"
.include "flags.s"
.include "ordinals.s" 
.include "vars.s"

.global ow_script_route_2_clouds_cave_eg_person_0
.global ow_script_route_2_clouds_cave_eg_person_1

ow_script_route_2_clouds_cave_eg_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_2_clouds_cave_eg_person_1:
    checkflag FLAG_ROUTE_2_CLOUDS_ICE_CAVE_ENTRANCE
    gotoif 1 cave_open
    lock
    faceplayer
    loadpointer 0 str_1
    callstd MSG
    applymovement LASTTALKED mov_1l
    waitmovement 0
    applymovement LASTTALKED mov_fr
    waitmovement 0
    setflag FLAG_ROUTE_2_CLOUDS_ICE_CAVE_ENTRANCE
    release
    end
cave_open:
    loadpointer 0 str_cave_open
    callstd MSG
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Findest du nicht, dass es hier irgendwie kalt ist?\pAls würde von irgendwo aus dieser Höhle ein eisiger Windzug kommenDOTS"
str_1:
    .autostring 34 2 "D-Du bist doch ein Trainer, ja?\pUnd du siehst so aus, als hättest du etwas auf dem K-KastenDOTS\pA-Aber lass mich dich warnenDOTS\pI-I d-dieser Höhle ist es eisig k-kaltDOTS\pI-Ich komme selbst a-aus dem Z-Zittern g-gar nicht mehr h-herausDOTS\pS-sag nachher n-nicht ich h-hätte d-dich nicht gewarntDOTS"
str_cave_open:
    .autostring 34 2 "P-pass a-auf dich auf, w-wenn du d-diese H-Höhle betrittstDOTS\pEs i-ist w-wirklich b-b-bitterkalt da d-drinDOTS"
.elseif LANG_EN
.endif