.include "callstds.s"
.include "overworld_script.s"

.global ow_script_amonia_person_0
.global ow_script_amonia_person_1

ow_script_amonia_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_amonia_person_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end


.ifdef LANG_GER

str_0:
    .autostring 34 2 "Sieh mal, ich habe ein Pokémon.\pLos, Azurill!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEs kuschelt lieber mit mir als zu kämpfenDOTS"
str_1:
    .autostring 34 2 "Ich bin RIVAL's Schwester.\pDieser Garten ist mein Rückzugsort.\pAls RIVAL jünger war, hat er oft hier Zeit verbracht, aber seit er dich kennengelernt hat, war er von einem Feuer erfüllt, bis er nicht mehr ruhig sitzen konnte.\pIch frage mich, ob du diesen Charakter in ihm zum Vorschein gebracht, oder ihn sogar geformt hastDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Look, I have a pokémon!\pGo, Azurill!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIt would rather cuddle than fightDOTS"
str_1:
    .autostring 34 2 "I am RIVAL's sister.\pThis garden is my resort.\pWhen RIVAL was younger he used to spend a lot of time here, but when he met you, a fire has been burning inside him ever since, so that he couldn't sit still even.\pI wonder if you brought out this trait of his or even made him the person he is todayDOTS"

.endif
