.include "overworld_script.s"
.include "callstds.s"

.global ow_script_bluetenbach_gym_trainer_0
.global ow_script_bluetenbach_gym_trainer_1
.global ow_script_bluetenbach_gym_trainer_2
.global ow_script_bluetenbach_gym_trainer_3
.global ow_script_bluetenbach_gym_trainer_4
.global ow_script_bluetenbach_gym_trainer_5
.global ow_script_bluetenbach_gym_trainer_6
.global ow_script_bluetenbach_gym_trainer_7

ow_script_bluetenbach_gym_trainer_0:
    trainerbattlestd 0 0x80 0 str_before_0 str_after_0
    loadpointer 0 str_after_0
    callstd MSG_FACE
    end
ow_script_bluetenbach_gym_trainer_1:
    trainerbattlestd 0 0x81 0 str_before_1 str_after_1
    loadpointer 0 str_after_1
    callstd MSG_FACE
    end
ow_script_bluetenbach_gym_trainer_2:
    trainerbattlestd 0 0x82 0 str_before_2 str_after_2
    loadpointer 0 str_after_2
    callstd MSG_FACE
    end
ow_script_bluetenbach_gym_trainer_3:
    trainerbattlestd 0 0x83 0 str_before_3 str_after_3
    loadpointer 0 str_after_3
    callstd MSG_FACE
    end
ow_script_bluetenbach_gym_trainer_4:
    trainerbattlestd 0 0x1cd 0 str_before_4 str_after_4
    loadpointer 0 str_after_4
    callstd MSG_FACE
    end
ow_script_bluetenbach_gym_trainer_5:
    trainerbattlestd 0 0x1ce 0 str_before_5 str_after_5
    loadpointer 0 str_after_5
    callstd MSG_FACE
    end
ow_script_bluetenbach_gym_trainer_6:
    trainerbattlestd 0 0x1cf 0 str_before_6 str_after_6
    loadpointer 0 str_after_6
    callstd MSG_FACE
    end
ow_script_bluetenbach_gym_trainer_7:
    trainerbattlestd 0 0x1d0 0 str_before_7 str_after_7
    loadpointer 0 str_after_7
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Du glaubst wohl, du kannst hier machen, was du willst, oder?\pAber bevor du den Gong schlagen kannst, musst du erst mich besiegen!"
str_after_0:
    .autostring 34 2 "Na gut, dann kannst du eben auf den Gong schlagenDOTS"
str_before_1:
    .autostring 34 2 "Siehst du meine Armmuskulatur?\pDas sind regelrechte Muskelberge, was?"
str_after_1:
    .autostring 34 2 "Was?\pVon so einem Schwächling wurde ich besiegt?"
str_before_2:
    .autostring 34 2 "Ich weiß schon, was du denkstDOTS\pEine Frau, in dieser Arena?\pAber ich bin mindestens so stark wie alle Muskelprotze hier!"
str_after_2:
    .autostring 34 2 "Aua!\pDavon bekomme ich morgen sicherlich einen MuskelkaterDOTS"
str_before_3:
    .autostring 34 2 "Meine wahre Stärke geben mir nicht meine eisernen Muskeln, sondern mein gestählter Geist.\pPass auf!"
str_after_3:
    .autostring 34 2 "Ganz klar!\pDeine Willenskraft hat meine eigene Entschlossenheit übermannt."
str_before_4:
    .autostring 34 2 "Wir alle hier haben hart trainiert, um von Manuel lernen zu dürfen.\pUnd jetzt will ein Kind wie du ihn herausfordern?\pDas könnte dir so passen!"
str_after_4:
    .autostring 34 2 "Wie erniedrigendDOTS\pVon einem Kind so gedemütigt zu werdenDOTS"
str_before_5:
    .autostring 34 2 "Für einen Kämpfer ist die vollständige Kontrolle über den eigenen Körper essentiell.\pUnd ich habe darüber hinaus auch meine Pokémon voll im Griff!"
str_after_5:
    .autostring 34 2 "W-Warte!\pHabe ich etwa die Kontrolle über den Kampf verloren?"
str_before_6:
    .autostring 34 2 "Über Jahre hinweg habe ich meine Technik perfektioniert.\pIch kann dich mit einem einzigen Handgriff ausschalten, Kindchen!"
str_after_6:
    .autostring 34 2 "Deine Kampftechnik ist sehr beachtlich, das muss ich zugebenDOTS"
str_before_7:
    .autostring 34 2 "Dein übermütiges Grinsen ist völlig ungebracht, ja?\pAn mir wirst du nicht vorbeikommen, das garantiere ich dirDOTS"
str_after_7:
    .autostring 34 2 "Dieses freche GrinsenDOTS\pEs hat mich vollkommen abgelenktDOTS"
.elseif LANG_EN
.endif