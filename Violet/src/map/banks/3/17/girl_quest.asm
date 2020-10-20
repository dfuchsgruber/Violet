.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "movements.s"
.include "ordinals.s"
.include "items.s"
.include "vars.s"

.global ow_script_haweiland_litle_girl
.global ow_script_haweiland_father
.global ow_script_haweiland_mother

ow_script_haweiland_litle_girl:
    checkflag FLAG_HAWEILAND_QUEST_LITTLE_GIRL
    gotoif EQUAL girl_back
    loadpointer 0 str_1
    callstd MSG_FACE
    setflag FLAG_HAWEILAND_QUEST_FOUND_LITTLE_GIRL
    end
girl_back:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

ow_script_haweiland_mother:
    loadpointer 0 str_3
parent:
    lock
    faceplayer
    checkflag FLAG_HAWEILAND_QUEST_LITTLE_GIRL
    gotoif EQUAL quest_done
    callstd MSG_KEEPOPEN
    checkflag FLAG_HAWEILAND_QUEST_FOUND_LITTLE_GIRL
    gotoif EQUAL found_girl
    release
    end

ow_script_haweiland_father:
    loadpointer 0 str_7
    goto parent

found_girl:
    sound 0x15
    applymovement 9 mov_exclam
    applymovement 10 mov_exclam
    waitmovement 0
    checksound
    pause 32
    loadpointer 0 str_4
    callstd MSG_KEEPOPEN
    closeonkeypress
    pause 64
    fadescreen 1
    setflag FLAG_HAWEILAND_QUEST_LITTLE_GIRL
    hidesprite 9
    hidesprite 10
    fadescreen 0
    release
    end

quest_done:
    checkflag FLAG_HAWEILAND_QUEST_RECEIVED_REWARD
    gotoif EQUAL all_done
    @ Receive the reward item
    loadpointer 0 str_6
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_SEEGESANG
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL no_space
    loadpointer 0 str_explain
    callstd MSG_KEEPOPEN
    setflag FLAG_HAWEILAND_QUEST_RECEIVED_REWARD
    release
    end

no_space:
    loadpointer 0 str_no_space
    callstd MSG_KEEPOPEN
    release
    end

all_done:
    loadpointer 0 str_5
    callstd MSG_FACE
    end


mov_exclam:
    .byte SAY_EXCLAM, STOP

.ifdef LANG_GER
str_1:
    .autostring 34 2 "Meine Eltern sind hier mit mir im Urlaub.\pAber ich kann sie nicht mehr findenDOTS"
str_2:
    .autostring 34 2 "Ich bin so glücklich, dass ich meine Eltern wieder gefunden habe!"
str_3:
    .autostring 34 2 "Eigentlich wollten mein Mann und ich hier einen entspannten Tag am Strand verbringen, aber jetzt können wir unsere Tochter nicht mehr findenDOTS"
str_4:
    .autostring 34 2 "Wie bitte?\pDu hast sie gefunden?\pWo!?"
str_5:
    .autostring 34 2 "Wir sind so glücklich, unsere Tochter wiedergefunden zu haben."
str_6:
    .autostring 34 2 "Vielen Dank, dass du unsere Tochter gefunden hast.\pWir waren krank vor Sorge.\pZum Dank möchten wir dir das hier geben."
str_no_space:
    .autostring 34 2 "Oh, es scheint, dass du keinen Platz dafür hast.\pKomm doch wieder, wenn du Platz für unser Dankeschön im Beutel hast."
str_explain:
    .autostring 34 2 "Dieses Item ist sehr nützlich.\pIch habe es vor einigen Tagen am Strand gefundenDOTS"
str_7:
    .autostring 34 2 "GäähnDOTS\pIch bin wohl eingenickt und habe meine Tochter aus den Augen gelassen.\pMeine Frau ist schon ganz krank vor SorgeDOTS"
.elseif LANG_EN
str_1:
    .autostring 34 2 "Me and my parents are on a vacation here.\pBut somehow I can't find them anymoreDOTS"
str_2:
    .autostring 34 2 "I am so happy that I found my parents again!"
str_3:
    .autostring 34 2 "Actually my husband and me wanted to spend a nice day here on the beach, but now we can't find our daughter anymoreDOTS"
str_4:
    .autostring 34 2 "Pardon?\pYou found her?\pWhere!?"
str_5:
    .autostring 34 2 "We are so happy to finally have our daughter back!"
str_6:
    .autostring 34 2 "Thank you so much for finding our daughter.\pWir were so worried!\pTo thank you we want to make you a little gift."
str_no_space:
    .autostring 34 2 "Oh, it appears that you don't have space for that.\pCome back once you have space for our little present in your bag."
str_explain:
    .autostring 34 2 "This item is very useful.\pI found it the other day on the beachDOTS"
str_7:
    .autostring 34 2 "YaaawnDOTS\pI must have fallen asleep and lost my daughter in the process.\pMy wife is totally worriedDOTS"

.endif