.include "overworld_script.s"
.include "callstds.s"

.global ow_script_sonnaufeld_clouds_trainer_0
.global ow_script_sonnaufeld_clouds_trainer_1
.global ow_script_sonnaufeld_clouds_trainer_2

ow_script_sonnaufeld_clouds_trainer_0:
    trainerbattlestd 0 0x1f7 0 str_before_0 str_after_0
    loadpointer 0 str_later_0
    callstd MSG_FACE
    end
ow_script_sonnaufeld_clouds_trainer_1:
    trainerbattlestd 0 0x1f8 0 str_before_1 str_after_1
    loadpointer 0 str_later_1
    callstd MSG_FACE
    end
ow_script_sonnaufeld_clouds_trainer_2:
    trainerbattlestd 0 0x1f9 0 str_before_2 str_after_2
    loadpointer 0 str_later_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Das Seltsamste hier oben ist, dass man oft keine Wolken über sich hat und das Wetter immer sonnig scheint.\pAber ich kann das ändern!"
str_after_0:
    .autostring 34 2 "Nicht schlecht.\nDas Wetter macht dir nicht zu schaffenDOTS"
str_later_0:
    .autostring 34 2 "Ich bin wirklich beeindruckt.\pSo wechselhaftem Wetter derart standhaft gegenüber zu tretenDOTS"
str_before_1:
    .autostring 34 2 "Mein Mitbewohner hat mich rausgeworfen, weil ihm meine Musik nicht gefallen hat.\pJetzt musst du dir meinen neuen Song anhören!"
str_after_1:
    .autostring 34 2 "Aus meiner Niederlage schöpfe ich neue InspirationDOTS"
str_later_1:
    .autostring 34 2 "Das ist schon ok.\pZu verlieren schmerzt mich zwar, aber aus solchen Gemütszuständen zieht man bekanntermaßen die größte Inspiration!"
str_before_2:
    .autostring 34 2 "Wir Ranger zeigen hier oben auf den Himmelsinseln wirklich zu wenig Präsenz.\pIch bin gewissermaßen ein Pionier!"
str_after_2:
    .autostring 34 2 "E-Erzähle bitte niemandem hiervonDOTS"
str_later_2:
    .autostring 34 2 "Mist!\nWenn herauskommt, dass die ersten Pokémon-Ranger auf den Himmelsinseln so kläglich besiegt werdenDOTS\pErzähl das bitte nicht weiter, ja?\pWir haben immerhin einen guten Ruf zu verlieren!"
.elseif LANG_EN
.endif