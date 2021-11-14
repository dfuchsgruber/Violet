.include "callstds.s"
.include "overworld_script.s"

.global ow_script_amonia_person_0
.global ow_script_amonia_person_1
.global ow_script_amonia_person_2
.global ow_script_amonia_person_3
.global ow_script_amonia_person_4

ow_script_amonia_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_amonia_person_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end
ow_script_amonia_person_2:
    loadpointer 0x0 str_2
    callstd MSG_FACE
    end
ow_script_amonia_person_3:
    loadpointer 0x0 str_3
    callstd MSG_FACE
    end
ow_script_amonia_person_4:
    loadpointer 0x0 str_4
    callstd MSG_FACE
    end

.ifdef LANG_GER

str_0:
    .autostring 34 2 "Sieh mal, ich habe ein Pokémon.\pLos, Azurill!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEs kuschelt lieber mit mir als zu kämpfenDOTS"
str_1:
    .autostring 34 2 "Ich bin RIVAL's Schwester.\pDieser Garten ist mein Rückzugsort.\pAls RIVAL jünger war, hat er oft hier Zeit verbracht, aber seit er dich kennengelernt hat, war er von einem Feuer erfüllt, bis er nicht mehr ruhig sitzen konnte.\pIch frage mich, ob du diesen Charakter in ihm zum Vorschein gebracht, oder ihn sogar geformt hastDOTS"
str_2:
    .autostring 34 2 "Ich bin in Anemoia aufgewachsen, musst du wissen.\pUnd immer noch immer bin ich dieses schönen Sees nicht müde."
str_3:
    .autostring 34 2 "Meine Freunde sagen, dass Anemonia öde ist.\pAber wusstest du, dass an diesem See ein Kappa-Pokémon leben soll?"
str_4:
    .autostring 34 2 "RIVAL, bist du das?\pNein, du hast ja ganz blondes Haar.\pDas Haar von meinem Enkel RIVAL ist feuerrot!\pGenauso wie das von meinem Sohn.\pUnd auch ich hatte in meiner Jugend einmal eine rote MähneDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Look, I have a pokémon!\pGo, Azurill!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIt would rather cuddle than fightDOTS"
str_1:
    .autostring 34 2 "I am RIVAL's sister.\pThis garden is my resort.\pWhen RIVAL was younger he used to spend a lot of time here, but when he met you, a fire has been burning inside him ever since, so that he couldn't sit still even.\pI wonder if you brought out this trait of his or even made him the person he is todayDOTS"
str_2:
    .autostring 34 2 "You must know, I grew up in Anemonia.\pBut still I am not yet bored by this magnificent lake."
str_3:
    .autostring 34 2 "My friends think that Anemonia is boring.\pBut did you know that a Kappa-Pokémon is supposed to live right at this lake?"

.endif
