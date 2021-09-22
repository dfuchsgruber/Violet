.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_desert_village_person_0
.global ow_script_desert_village_person_1
.global ow_script_desert_village_person_2
.global ow_script_desert_village_person_3
.global ow_script_desert_village_person_4
.global ow_script_desert_village_person_5
.global ow_script_desert_village_person_6
.global ow_script_desert_village_person_7

ow_script_desert_village_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_desert_village_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_desert_village_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_desert_village_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_desert_village_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_desert_village_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_desert_village_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end

ow_script_desert_village_person_7:
    checkflag FLAG_EP_TEILER
    gotoif EQUAL person_7_done
    checkflag FLAG_GLUECKSMUENZE_RETURNED
    gotoif EQUAL person_7_get_reward
    lock
    faceplayer
    loadpointer 0 str_7_lost
    callstd MSG
    checkitem ITEM_GLUECKSMUENZE 1
    compare LASTRESULT 1
    gotoif EQUAL person_7_found_coin
    releaseall
    end
person_7_get_reward:
    lock
    faceplayer
    loadpointer 0 str_7_recollect_reward
    callstd MSG_KEEPOPEN
    goto person_7_add_item

person_7_found_coin:
    sound 0x15
    applymovement LASTTALKED mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_7_found
    callstd MSG
    fanfare 0x13e
    loadpointer 0 str_7_hand_over_coin
    callstd MSG_KEEPOPEN
    waitfanfare
    removeitem ITEM_GLUECKSMUENZE 1
    setflag FLAG_GLUECKSMUENZE_RETURNED
    loadpointer 0 str_7_reward
    callstd MSG_KEEPOPEN
person_7_add_item:
    copyvarifnotzero 0x8000 ITEM_EP_TEILER
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    setflag FLAG_EP_TEILER
person_7_done:
    loadpointer 0 str_7_done
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_7_lost:
    .autostring 34 2 "Es ist schrecklich!\pIch habe meine Glücksmünze verlorenDOTS\pIch dachte, ich hätte sie hier an diesem Brunnen gelassen, aber sie ist nirgendwo zu findenDOTS\pOb ich sie an einem anderen Brunnen verloren habe?"
str_7_found:
    .autostring 34 2 "Wie?\nDu hast meine Glücksmünze bei einem Brunnen im Kaktuslabyrinth gefunden?\pKann ich sie wiederhaben?"
str_7_hand_over_coin:
    .autostring 34 2 "PLAYER übergibt die Glücksmünze."
str_7_reward:
    .autostring 34 2 "Das ist wirklich fantastisch!\pAls Gegenleistung möchte ich dir das hier geben."
str_7_done:
    .autostring 34 2 "Ich bin wirklich froh, dass du mir meine Glücksmünze wiedergegeben hast.\pIch hatte schon Angst, sie versehentlich in einen der Brunnen geworfen zu habenDOTS"
str_7_recollect_reward:
    .autostring 34 2 "Oh, du bist zurück!\pWillst du jetzt mein Geschenk annehmen als Gegenleistung dafür, dass du mir meine Glücksmünze wiedergebracht hast?"
str_0:
    .autostring 34 2 "Wusstest du, dass dieser Ort ursprünglich nur eine Basis für Pokémon-Ranger war, um sich von der Wüstenhitze zu erholen?\pNach und nach haben dann immer mehr Trainer diese Basis mitbenutzt und schließlich hat der Pinke Faun sie kurzerhand zu einem Dorf erklärt!"
str_1:
    .autostring 34 2 "Autsch!\nEiner dieser Kakteen hat mich gestochen!\pIch könnte schwören, dass er sich bewegt hatDOTS\pW-War das etwa ein Pokémon?"
str_2:
    .autostring 34 2 "Ich wäre fast vertrocknet in diesem elendigen Kaktus-LabyrinthDOTS\pAber zum Glück gibt es diese Basis hier.\pDa kann man sich und seine Pokémon erfrischen!"
str_3:
    .autostring 34 2 "Mein Freund und ich haben gerade einen kleinen Streit, welches der beiden Zelte uns besser gefällt.\pEr hält irrsinnigerweise daran fest, das blaue Zelt sei das bessereDOTS"
str_4:
    .autostring 34 2 "Meine Freundin hat einfach keine Ahnung!\pNatürlich ist hier das blaue Zelt das schönere.\pDas behaupten auch alle, die sich darin befindenDOTS"
str_5:
    .autostring 34 2 "Kannst du dir vorstellen, wie schlimm es gewesen sein muss, von Kranzdorf nach Kaskada zu gelangen, bevor die Pokémon-Ranger diese Basis ins Leben gerufen haben?\pEs erstaunt mich, dass die Top Vier hier so lange nichts errichtet haben, um den Trainern in Theto zu helfenDOTS"
str_6:
    .autostring 34 2 "Dieser Ort ist vermutlich das einzige Dorf, in dem niemand lebt.\pAber sind wir einmal ehrlichDOTS\pWer würde schon gerne hierher ziehen?"
.elseif LANG_EN
.endif