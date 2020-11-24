.include "overworld_script.s"
.include "callstds.s"

.global ow_script_felsige_oednis_cave_trainer_0
.global ow_script_felsige_oednis_cave_trainer_1
.global ow_script_felsige_oednis_cave_trainer_2
.global ow_script_felsige_oednis_cave_trainer_3
.global ow_script_felsige_oednis_cave_trainer_4

ow_script_felsige_oednis_cave_trainer_0:
    trainerbattledouble 0x4 0x1a6 0 str_challange_0 str_defeat_0 trainer_0_one_poke
    loadpointer 0x0 str_defeat_0
    callstd MSG_FACE
    end
ow_script_felsige_oednis_cave_trainer_1:
    trainerbattlestd 0 0x1a7 0 str_before_1 str_after_1
    loadpointer 0 str_after_1
    callstd MSG_FACE
    end
ow_script_felsige_oednis_cave_trainer_2:
    trainerbattlestd 0 0x1a8 0 str_before_2 str_after_2
    loadpointer 0 str_after_2
    callstd MSG_FACE
    end
ow_script_felsige_oednis_cave_trainer_3:
    trainerbattlestd 0 0x1a9 0 str_before_3 str_after_3
    loadpointer 0 str_after_3
    callstd MSG_FACE
    end
ow_script_felsige_oednis_cave_trainer_4:
    trainerbattlestd 0 0x1aa 0 str_before_4 str_after_4
    loadpointer 0 str_after_4
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_challange_0:
    .autostring 34 2 "Ein verliebtes Pärchen in einer dunklen Höhle?\pKomm ja nicht auf falsche Gedanken, Kindchen!"
trainer_0_one_poke:
    .autostring 34 2 "Ohne meine bessere Hälfte trete ich nicht gegen dich an.\pUnd du hast nur ein einziges Pokémon, das du in den Kampf schicken könntestDOTS"
str_defeat_0:
    .autostring 34 2 "Na gut, dann haben wir also verloren.\pAber wir haben ja immer noch uns beide.\pNicht wahr, Schatz?"
str_before_1:
    .autostring 34 2 "Ich habe mich nicht verirrt!\pIch wollte genau hier in dieser finsteren Höhle landen, hast du mich verstanden?"
str_after_1:
    .autostring 34 2 "Ähm, na gut, vielleicht habe ich mich doch verirrtDOTS"
str_before_2:
    .autostring 34 2 "W-Wer bist du?\pIch dachte, hier in dieser Höhle findet mich die Polizei nicht!"
str_after_2:
    .autostring 34 2 "M-Moment!\nDu bist gar kein Polizist, oder?"
str_before_3:
    .autostring 34 2 "Einen Mechaniker in die Wüste bestellen!\pSieh nur, wo ich gelandet bin.\pDas musst du jetzt ausbaden, Kindchen!"
str_after_3:
    .autostring 34 2 "Kann dieser Tag noch schlimmer werden?"
str_before_4:
    .autostring 34 2 "Ich bin hierher gekommen, um in der Dunkelheit meine Kräfte zu stärken.\pDu wirst gar nicht wissen, wie dir geschieht!"
str_after_4:
    .autostring 34 2 "Unmöglich!\pNach all der Zeit in der Finsternis habe ich trotzdem verloren?"
.elseif LANG_EN
.endif
