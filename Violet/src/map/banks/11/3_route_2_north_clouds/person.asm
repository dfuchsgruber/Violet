.include "overworld_script.s"
.include "callstds.s"
.include "items.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_2_clouds_person_5
.global ow_script_route_2_clouds_person_6
.global ow_script_route_2_clouds_person_7
.global ow_script_route_2_clouds_person_8
.global ow_script_route_2_clouds_person_9
.global ow_script_route_2_clouds_person_10
.global ow_script_route_2_clouds_person_11
.global ow_script_route_3_clouds_gift

ow_script_route_2_clouds_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_8:
    loadpointer 0 str_8
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_9:
    loadpointer 0 str_9
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_10:
    loadpointer 0 str_10
    callstd MSG_FACE
    end
ow_script_route_2_clouds_person_11:
    loadpointer 0 str_11
    callstd MSG_FACE
    end
ow_script_route_3_clouds_gift:
    lock
    faceplayer
    checkflag FLAG_ROUTE_3_CLOUDS_ITEM_GIFT
    gotoif EQUAL after_receiving_gift
    loadpointer 0x0 str_intro_gift
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_KAEFERJUWEL
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    loadpointer 0x0 str_after_receiving_gift
    callstd MSG_KEEPOPEN
    closeonkeypress
    release
    setflag FLAG_ROUTE_3_CLOUDS_ITEM_GIFT
    end
after_receiving_gift:
    loadpointer 0x0 str_after_receiving_gift
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_intro_gift:
    .autostring 34 2 "Siehst du den Kristall da auf dem See?\pHeute morgen bin ich dorthin geschwommen und habe ein Stück davon abgebrochen.\pDu kannst es gerne haben, ich weiß sowieso nichts damit anzufangen."
str_after_receiving_gift:
    .autostring 34 2 "Dieses Juwel scheint wohl auf Käfer-Angriffe zu reagierenDOTS\pOb sich das im Kampf lohnt?"
str_5:
    .autostring 34 2 "Ich erinnere mich an einen Burschen namens Lucius.\pEr hat sich das Wolkenreiten selbst beigebracht."
str_6:
    .autostring 34 2 "Als Kind hat mir mein Vater oft von den Ruinen hier oben erzählt.\pJetzt kann ich sie endlich selbst erkunden!"
str_7:
    .autostring 34 2 "Meine Käfer-Pokémon fühlen sich zu diesem See hingezogen.\pIch vermute, der Kristall dort zieht sie irgendwie anDOTS"
str_8:
    .autostring 34 2 "Ist es nicht fantastisch, dass es mittlerweile für viele Trainer möglich ist, diese Himmels-Inseln zu erkunden?\pDas Wolkenweben hat uns wirklich eine neue Welt eröffnet!"
str_9:
    .autostring 34 2 "Mein Freund und ich erkunden diese schwebenden Inseln schon seit einiger Zeit.\pAngeblich war es der ehemalige Champion, der sie zuerst wiederentdeckt hat!"
str_10:
    .autostring 34 2 "MhmDOTS\pIst es nicht seltsam, dass die Blumen hier oben anders reichen als auf dem Boden?"
str_11:
    .autostring 34 2 "Dieser Teich ist wirklich faszinierend.\pSiehst du den Kristall in seiner Mitte?\pIch frage mich, was es damit auf sich hatDOTS"
.elseif LANG_EN
str_5:
    .autostring 34 2 "I remember the boy Lucius, who later became champion.\pHe taught the cloud riding to himself."
str_6:
    .autostring 34 2 "When I was a child my father used to tell me about the ruins up here.\pNow I can explore them myself!"
.endif