
.include "overworld_script.s"
.include "flags.s"
.include "items.s"
.include "callstds.s"

.global ow_script_beach_house_vendor
.global ow_script_beach_house_person_0
.global ow_script_beach_house_person_1
.global ow_script_beach_house_person_2

ow_script_beach_house_vendor:
    setflag TRANS_DISABLE
    lock
    faceplayer
    preparemsg str_0
    waitmsg
    pokemart3 mart sell_default_items=0
    loadpointer 0x0 str_1
    callstd MSG_KEEPOPEN
    clearflag TRANS_DISABLE
    release
    end

mart:
    .hword ITEM_CO_MIX, ITEM_C_SAFT, ITEM_C_SERUM, 0

ow_script_beach_house_person_0:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_beach_house_person_1:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_beach_house_person_2:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hey du!\pEine Erfrischung gefällig?"
str_1:
    .autostring 34 2 "Wenn du eine Erfrischung nötig hast, komm zu mir!"
str_2:
    .autostring 34 2 "Mir war so heiß, aber dank meinem C-Saft geht es mir schon viel besser!"
str_3:
    .autostring 34 2 "Ich habe zu viel C-Serum getrunkenDOTS\pJetzt ist mir ganz übelDOTS"
str_4:
    .autostring 34 2 "Dieses Strandhaus ist der Grund, warum ich immer wieder nach Haweiland komme.\pDie Atmosphäre ist einfach so entspannend."

.elseif LANG_EN
str_0:
    .autostring 34 2 "Hey you!\pNeed a refreshment?"
str_1:
    .autostring 34 2 "If you crave a refreshment you know where to find me!"
str_2:
    .autostring 34 2 "Mir war so heiß, aber dank meinem C-Saft geht es mir schon viel besser!"
str_3:
    .autostring 34 2 "Ich habe zu viel C-Serum getrunkenDOTS\pJetzt ist mir ganz übelDOTS"
str_4:
    .autostring 34 2 "Dieses Strandhaus ist der Grund, warum ich immer wieder nach Haweiland komme.\pDie Atmosphäre ist einfach so entspannend."

.endif