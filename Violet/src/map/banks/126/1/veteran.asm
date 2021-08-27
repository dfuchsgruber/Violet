.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "items.s"

.global ow_script_dungeon_forest_veteran

ow_script_dungeon_forest_veteran:
    checkflag FLAG_DUNGEON_GP
    gotoif EQUAL veteran_forest_done
    lockall
    faceplayer
    compare VAR_DUNGEON_MASTER_ENCOUNTERS 0
    gotoif EQUAL forest_veteran_0
    compare VAR_DUNGEON_MASTER_ENCOUNTERS 1
    gotoif EQUAL forest_veteran_1
    compare VAR_DUNGEON_MASTER_ENCOUNTERS 2
    gotoif EQUAL forest_veteran_2
    compare VAR_DUNGEON_MASTER_ENCOUNTERS 3
    gotoif EQUAL forest_veteran_3
    compare VAR_DUNGEON_MASTER_ENCOUNTERS 4
    gotoif EQUAL forest_veteran_4
veteran_forest_done:
    loadpointer 0 str_done
    callstd MSG_FACE
    end

forest_veteran_0:
    checkflag (FLAG_DUNGEON_GP + 1)
    gotoif EQUAL later_0
    loadpointer 0 str_intro
    callstd MSG_KEEPOPEN
    trainerbattlecont 1 0x1e4 0 str_before_first str_after later_0
later_0:
    setflag (FLAG_DUNGEON_GP + 1)
    lock
    faceplayer
    loadpointer 0 str_reward
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_SONDERBONBON
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    setflag FLAG_DUNGEON_GP
    addvar VAR_DUNGEON_MASTER_ENCOUNTERS 1
    loadpointer 0 str_exit
    callstd MSG_KEEPOPEN
    releaseall
    end

forest_veteran_1:
    checkflag (FLAG_DUNGEON_GP + 1)
    gotoif EQUAL later_0
    trainerbattlecont 1 0x1e5 0 str_before str_after later_1
later_1:
    setflag (FLAG_DUNGEON_GP + 1)
    lock
    faceplayer
    loadpointer 0 str_reward
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_SCOPE_LINSE
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    setflag FLAG_DUNGEON_GP
    addvar VAR_DUNGEON_MASTER_ENCOUNTERS 1
    loadpointer 0 str_exit
    callstd MSG_KEEPOPEN
    releaseall
    end

forest_veteran_2:
    checkflag (FLAG_DUNGEON_GP + 1)
    gotoif EQUAL later_0
    trainerbattlecont 1 0x1e6 0 str_before str_after later_2
later_2:
    setflag (FLAG_DUNGEON_GP + 1)
    lock
    faceplayer
    loadpointer 0 str_reward
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_LINKKABEL
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    setflag FLAG_DUNGEON_GP
    addvar VAR_DUNGEON_MASTER_ENCOUNTERS 1
    loadpointer 0 str_exit
    callstd MSG_KEEPOPEN
    releaseall
    end

forest_veteran_3:
    checkflag (FLAG_DUNGEON_GP + 1)
    gotoif EQUAL later_0
    trainerbattlecont 1 0x1e7 0 str_before str_after later_3
later_3:
    setflag (FLAG_DUNGEON_GP + 1)
    lock
    faceplayer
    loadpointer 0 str_reward
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_TM02
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    setflag FLAG_DUNGEON_GP
    addvar VAR_DUNGEON_MASTER_ENCOUNTERS 1
    loadpointer 0 str_exit
    callstd MSG_KEEPOPEN
    releaseall
    end

forest_veteran_4:
    checkflag (FLAG_DUNGEON_GP + 1)
    gotoif EQUAL later_0
    trainerbattlecont 1 0x1e8 0 str_before str_after later_4
later_4:
    setflag (FLAG_DUNGEON_GP + 1)
    lock
    faceplayer
    loadpointer 0 str_reward
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_SONDERBONBON
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    setflag FLAG_DUNGEON_GP
    loadpointer 0 str_exit
    callstd MSG_KEEPOPEN
    releaseall
    end



.ifdef LANG_GER
str_done:
    .autostring 34 2 "Du hast mich fair besiegt, Kindchen.\pDas hat mich wirklich schwer beeindruckt.\pAber bei unserem nächsten Treffen kriegst du mich nicht so leicht klein, verstanden?"
str_intro:
    .autostring 34 2 "W-Was?\nWie hast du mich gefunden?\pDOTS DOTS DOTS\pMit einem Kind hatte ich wirklich nicht gerechnet.\pWer ich bin?\pIch benutze Geheimpower schon seit vielen Jahrzehnten, um die Region zu erkunden.\pNiemand sonst in Theto hat mehr Erfahrung mit Geheimpower als ich."
str_before_first:
    .autostring 34 2 "Ich treffe nicht viele Trainer in diesen Gebieten.\pLass mich einmal sehen, aus welchem Holz du geschnitzt bist!"
str_before:
    .autostring 34 2 "Du schon wieder!\pBei unserer letzten Begegnung habe ich dir noch nicht vollständig gezeigt, zu was ich im Stande bin.\pDenkst du, deine Geheimpower ist immer noch stärker als meine?"
str_after:
    .autostring 34 2 "Das war eine starke Vorstellung!"
str_reward:
    .autostring 34 2 "Nicht übel!\nObwohl du noch so jung bist, scheinst du die Geheimpower bereits bestens zu beherrschen.\pAls Zeichen meiner Anerkennung möchte ich dir das hier geben."
str_exit:
    .autostring 34 2 "Ich sehne mich zurück nach meinen jungen TagenDOTS\pLass das Feuer, das in dir brennt, niemals erlöschen, ja?\pWenn wir uns das nächste Mal treffen, werde ich dich nicht schonen, Kindchen."
.elseif LANG_EN
.endif


    