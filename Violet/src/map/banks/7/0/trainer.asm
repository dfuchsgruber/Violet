.include "overworld_script.s"
.include "callstds.s"
.include "treasure_map.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_silvania_clouds_trainer_0
.global ow_script_silvania_clouds_treasure_hunter_0

ow_script_silvania_clouds_trainer_0:
    trainerbattlestd 0 0x123 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

ow_script_silvania_clouds_treasure_hunter_0:
    lock
    faceplayer
    checkflag (FLAG_TREASURE_MAP_BASE + 2)
    gotoif EQUAL treasure_hunter_done
    trainerbattlecont 0x1 0x215 0x0 str_treasure_hunter_0_challange str_treasure_hunter_0_defeat cont
cont:
    loadpointer 0 str_treasure_hunter_0_after
    callstd MSG_FACE
    give_treasure_map treasure_map_idx=2 give_type=TREASURE_MAP_OBTAIN
    release
    end
treasure_hunter_done:
    loadpointer 0 str_treasure_hunter_0_done
    callstd MSG_KEEPOPEN
    release
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Die Waldluft von Kranzdorf reicht bis hier hinauf.\pDas heißtDOTS DOTS DOTS\pIch bin unschlagbar!"
str_trainer0_defeat:
    .autostring 34 2 "Ach, ich habe ganz vergessen, dass wir die gleiche Luft atmenDOTS"
str_treasure_hunter_0_challange:
    .autostring 34 2 "Ich bin auf der Suche nach den Reichtümern, die hier oben versteckt sind!"
str_treasure_hunter_0_defeat:
    .autostring 34 2 "Oh, ich habe ganz vergessen, dass wir die gleiche Luft atmenDOTS"
str_treasure_hunter_0_after:
    .autostring 34 2 "Du hast ehrlich gewonnen!\pAlso steht dir nun meine Schatzkarte zuDOTS"
str_treasure_hunter_0_done:
    .autostring 34 2 "Ich hoffe, du hast erfolg dabei, Schätze hier oben zu findenDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "The forest air of Kranzdorf is also up here.\pThat meansDOTS DOTS DOTS\pI am invincible!"
str_trainer0_defeat:
    .autostring 34 2 "Oh, seems like I forgot that we breathe the same airDOTS"
str_treasure_hunter_0_challange:
    .autostring 34 2 "I am searching for the riches that are hidden up here!"
str_treasure_hunter_0_defeat:
    .autostring 34 2 "Oh, seems like I forgot that we breathe the same airDOTS"
str_treasure_hunter_0_after:
    .autostring 34 2 "You honestly won!\pSo now my treasure map is yoursDOTS"
str_treasure_hunter_0_done:
    .autostring 34 2 "I hope you have success in finding treasures up hereDOTS"
.endif