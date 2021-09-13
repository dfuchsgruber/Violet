.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_sonnauenfeld_person_0
.global ow_script_sonnauenfeld_person_1
.global ow_script_sonnauenfeld_person_2
.global ow_script_sonnauenfeld_person_3
.global ow_script_sonnauenfeld_person_4
.global ow_script_sonnauenfeld_person_5
.global ow_script_sonnauenfeld_person_6
.global ow_script_sonnauenfeld_person_7
.global ow_script_sonnauenfeld_person_8
.global ow_script_sonnauenfeld_person_9
.global ow_script_map_sonnaufeld_apple_gift

ow_script_sonnauenfeld_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_sonnauenfeld_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_sonnauenfeld_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_sonnauenfeld_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_sonnauenfeld_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_sonnauenfeld_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_sonnauenfeld_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_sonnauenfeld_person_7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end
ow_script_sonnauenfeld_person_8:
    loadpointer 0 str_8
    callstd MSG_FACE
    end
ow_script_sonnauenfeld_person_9:
    loadpointer 0 str_9
    callstd MSG_FACE
    end
ow_script_map_sonnaufeld_apple_gift:
    lock
    faceplayer
    checkflag FLAG_SONNAUFELD_APPLE_GIFT
    gotoif EQUAL after_receiving_apple
    loadpointer 0x0 str_intro_apple
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_RIESENAPFEL
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    loadpointer 0x0 str_after_receiving_apple
    callstd MSG_KEEPOPEN
    closeonkeypress
    release
    setflag FLAG_SONNAUFELD_APPLE_GIFT
    end

after_receiving_apple:
    loadpointer 0x0 str_after_receiving_apple
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich frage mich, was es mit diesen kleinen Höhlen in der Wand auf sich hat.\pSie sind zu klein, als dass man hindurchschlüpfen könnteDOTS\pEs sei denn, man wäre ein Kind, natürlich."
str_1:
    .autostring 34 2 "Professor Tann hat hier kürzlich einige Fossilien ausgegraben.\pEines von ihnen scheint ein sehr altes Wasser-Pokémon zu sein, von dem man bis vor kurzem noch dachte, es sei ausgestorben.\pDas macht diesen Fund natürlich umso interessanter!"
str_2:
    .autostring 34 2 "Ich versuche, meinem Pokémon Tricks beizubringen.\pAber irgendwie will es nicht so recht auf mich hörenDOTS"
str_3:
    .autostring 34 2 "Sonnenaufeld ist ein wirklich schönes Fleckchen in Theto.\pHier hat man sowohl Berge als auch Küste direkt vor der Haustür."
str_4:
    .autostring 34 2 "Ich finde es unglaublich spannend, dass Professor Tann sein Labor hier in Sonnauenfeld hat.\pEr hat schon so viele aufregende Dinge entdeckt!\pDa wird man direkt neidischDOTS"
str_5:
    .autostring 34 2 "Wusstest du, dass manche Leute die Frechheit besitzen, den Müll anderer zu durchwühlen?\pEinmal abgesehen davon, dass es sich nicht gehört, ist das auch ganz schön gefährlich.\pIch habe gehört, dass jemand dabei mal von einem Pokémon angegriffen wurde, das sich in der Mülltonne versteckt hatte."
str_6:
    .autostring 34 2 "Ich komme oft hierher, um eine Tante zu besuchen.\pEigentlich lebe ich in Orina City, aber es tut mir sehr gut, hin und wieder einmal aus der Großstadt herauszukommen."
str_7:
    .autostring 34 2 "Sind die Sonnenblumen hier in Sonnaufeld nicht fantastisch?\pDas einzig nervige daran ist, dass sie eine Menge Bibor anlocken, wenn sie in Blüte stehenDOTS"
str_8:
    .autostring 34 2 "Die Küsten hier gefallen mir besonders gut.\pWann immer es mich in den Fingern juckt, werfe ich hier meinen Köder aus!"
str_9:
    .autostring 34 2 "Was geht schon über einen Strandspaziergang?\pEin Strandspaziergang im Sonneruntergang vielleichtDOTS"
str_intro_apple:
    .autostring 34 2 "Auf meine hohen Tage gehe ich oft im Kranzwald ein paar Äpfel pflücken.\pDie halten einen gesund und fit.\pHier, du kannst gerne einen haben."
str_after_receiving_apple:
    .autostring 34 2 "Ein Apfel kann einen schon einmal wieder auf die Beine bringen, wenn man etwas niedergeschlagen ist.\pDas gilt für Trainer gleichermaßen wie für Pokémon."
.elseif LANG_EN
.endif