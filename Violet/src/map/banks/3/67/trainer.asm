.include "callstds.s"
.include "overworld_script.s"

.global ow_script_felsige_oednis_east_caves_trainer_0
.global ow_script_felsige_oednis_east_caves_trainer_1
.global ow_script_felsige_oednis_east_caves_trainer_2
.global ow_script_felsige_oednis_east_caves_trainer_3

ow_script_felsige_oednis_east_caves_trainer_0:
    trainerbattlestd 0 0x1b2 0 str_before0 str_after0
    loadpointer 0 str_before0
    callstd MSG_FACE
    end
ow_script_felsige_oednis_east_caves_trainer_1:
    trainerbattlestd 0 0x1b3 0 str_before1 str_after1
    loadpointer 0 str_before1
    callstd MSG_FACE
    end
ow_script_felsige_oednis_east_caves_trainer_2:
    trainerbattlestd 0 0x1b4 0 str_before2 str_after2
    loadpointer 0 str_before2
    callstd MSG_FACE
    end
ow_script_felsige_oednis_east_caves_trainer_3:
    trainerbattlestd 0 0x1b5 0 str_before3 str_after3
    loadpointer 0 str_before2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Ich trainiere jeden Tag hier, um eines Tages mit meinen bloßen Fäusten sogar Felsen zertrümmern zu können!"
str_after0:
    .autostring 34 2 "W-Was?\nDu hast meine Pokémon einfach so geschlagen?"
str_before1:
    .autostring 34 2 "Diese verflixte DunkelheitDOTS\pW-Wer ist da?"
str_after1:
    .autostring 34 2 "Entschuldige bitteDOTS\pDu hast dich im Dunkeln so an mich herangeschlichenDOTS"
str_before2:
    .autostring 34 2 "Ich bin von Pokémon regelrecht besessen!\pNiemand weiß mehr über Pokémon als ich!"
str_after2:
    .autostring 34 2 "ÄhmDOTS\nNa gut, du bist wohl wirklich etwas besser als ichDOTS"
str_before3:
    .autostring 34 2 "Ich mache gerne Picknicks am Tafelberg.\pDu wirst mir meinen Lieblingsplatz nicht streitig machen!"
str_after3:
    .autostring 34 2 "Jetzt muss ich mir einen anderen Platz für mein Picknick suchenDOTS"
.elseif LANG_EN
.endif