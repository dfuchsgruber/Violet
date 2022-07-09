

.include "overworld_script.s"
.include "callstds.s"
.include "ordinals.s"
.include "flags.s"
.include "items.s"
.include "vars.s"

.global ow_script_kaskada_clouds_person_0
.global ow_script_kaskada_clouds_person_1
.global ow_script_kaskada_clouds_person_fisher_good_rod

ow_script_kaskada_clouds_person_fisher_good_rod:
    checkflag FLAG_GOOD_ROD
    gotoif 1 done
    lock
    faceplayer
    loadpointer 0 str_ask
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL said_no
    loadpointer 0 str_said_yes
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_PROFIANGEL
    copyvarifnotzero 0x8001 0x1
    callstd ITEM_OBTAIN
    loadpointer 0 str_given_good_rod
    callstd MSG_KEEPOPEN
    setflag FLAG_GOOD_ROD
    release
    end
said_no:
    loadpointer 0 str_said_no
    callstd MSG_KEEPOPEN
    release
    end
done:
    loadpointer 0 str_done
    callstd MSG_FACE
    end

ow_script_kaskada_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_kaskada_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
    str_0:
        .autostring 34 2 "Viele Menschen wissen nicht, dass ein erheblicher Teil des Wassers in Kaskada aus den Wolken fällt.\pIst das nicht interessant?"
    str_1:
        .autostring 34 2 "Die Ruinen hier erwecken den Eindruck, dass eine antike Zivilisation über eine Art Aquädukte verfügt haben muss.\pDiese schwebenden Inseln sind wirklich immer für eine Überraschung gut."
    str_ask:
        .autostring 34 2 "Es herrschen oft Uneinigkeiten darüber, welche Trainer die besseren Wasser-Pokémon besitzen.\pFindest du nicht auch, dass die Schwimmer den Anglern unterlegen sind?"
    str_said_no:
        .autostring 34 2 "Wie ignorant von dir!\pEs besteht gar kein Zweifel darüber, dass die Pokémon unter der Wasseroberfläche stärker sind!"
    str_said_yes:
        .autostring 34 2 "Gut geantwortet!\pIch sehe, du hast das Zeug dazu, ein großartiger Angler zu werden!"
    str_given_good_rod:
        .autostring 34 2 "Mit der Profiangel beißen noch stärkere Pokémon, als sie es an der gewöhnlichen Angel taten.\pEin Schwimmer kann damit natürlich nicht mithalten!"
    str_done:
        .autostring 34 2 "Die Art der Angel macht beim Fischen einen großen Unterschied.\pDie Profiangel ist der Angel in jeder Hinsicht überlegen."
.elseif LANG_EN
    str_0:
        .autostring 34 2 "Many people don't know that a significant part of the water in Cascada falls down from the clouds.\pIsn't that interesting?"
    str_1:
        .autostring 34 2 "Because of the arrid conditions in the Rocky Desolation there are not many clouds.\pTherefore, people once built a giant bridge."
    str_ask:
        .autostring 34 2 "There often are disagreements about which trainers raise the better water Pokémon.\pDon't you think that swimmers are inferior to fishermen?"
    str_said_no:
        .autostring 34 2 "How ignorant of you!\pThere is no doubt about the fact that the Pokémon below the ocean surface are stronger!"
    str_said_yes:
        .autostring 34 2 "Well said!\pI see you have what it takes to become a great fisherman!"
    str_given_good_rod:
        .autostring 34 2 "With the Good Rod the Pokémon you encounter will be even stronger compared to a common Rod.\pNothing any swimmer ever could compare to!"
    str_done:
        .autostring 34 2 "The kind of rod one uses when fishing makes a huge difference.\pThe Good Rod for example is superior to the Rod in every aspect!"
.endif


