.include "callstds.s"
.include "overworld_script.s"

.global ow_script_tafelberg_south_trainer_0
.global ow_script_tafelberg_south_trainer_1
.global ow_script_tafelberg_south_trainer_2
.global ow_script_tafelberg_south_trainer_3
.global ow_script_tafelberg_south_trainer_4
.global ow_script_tafelberg_south_trainer_5
.global ow_script_tafelberg_south_trainer_6

ow_script_tafelberg_south_trainer_0:
    trainerbattlestd 0 0x1ab 0 str_before0 str_after0
    loadpointer 0 str_after0
    callstd MSG_FACE
    end
ow_script_tafelberg_south_trainer_1:
    trainerbattlestd 0 0x1ac 0 str_before1 str_after1
    loadpointer 0 str_after1
    callstd MSG_FACE
    end
ow_script_tafelberg_south_trainer_2:
    trainerbattlestd 0 0x1ad 0 str_before2 str_after2
    loadpointer 0 str_after2
    callstd MSG_FACE
    end
ow_script_tafelberg_south_trainer_3:
    trainerbattlestd 0 0x1ae 0 str_before3 str_after3
    loadpointer 0 str_after3
    callstd MSG_FACE
    end
ow_script_tafelberg_south_trainer_4:
    trainerbattlestd 0 0x1af 0 str_before4 str_after4
    loadpointer 0 str_after0
    callstd MSG_FACE
    end
ow_script_tafelberg_south_trainer_5:
    trainerbattlestd 0 0x1b0 0 str_before5 str_after5
    loadpointer 0 str_after5
    callstd MSG_FACE
    end
ow_script_tafelberg_south_trainer_6:
    trainerbattledouble 0x4 0x1b1 0 str_before6 str_after5 str_one_poke
    loadpointer 0x0 str_after6
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Ich habe meine Käfer-Pokémon durch eine Wüste geschleppt!\pDa kannst du uns jetzt auch nichts mehr anhaben!"
str_after0:
    .autostring 34 2 "BuhuDOTS\nDu bist gemein!"
str_before1:
    .autostring 34 2 "Meine Pokémon sind steinhart!\pSie können jeden noch so starken Angriff wegstecken."
str_after1:
    .autostring 34 2 "Du hast meine Verteidigung zum Bröckeln gebrachtDOTS"
str_before2:
    .autostring 34 2 "Von oben auf dem Plateau kannst du über die ganze Wüste sehen.\pMeinen Adleraugen entgeht gar nichts!"
str_after2:
    .autostring 34 2 "W-Wie geht das denn?\nIch habe deinen Sieg gar nicht kommen sehen."
str_before3:
    .autostring 34 2 "Es ist gefährlich für ein Kind an so steilen Abhängen zu spielen.\pIch bringe dich nach Hause zu einen Eltern!"
str_after3:
    .autostring 34 2 "Na gut, du bist wohl stark genug, auch alleine zurechtzukommenDOTS"
str_before4:
    .autostring 34 2 "Ich habe meinen Job bei der Laz. Corp gegründet, als wir ein antikes Fossil wieder zum Leben erweckt hatten.\pMit diesem prähistorischen Pokémon bin ich unschlagbar!"
str_after4:
    .autostring 34 2 "Warte mal!\nWofür habe ich denn meinen Job gekündigt, wenn ich jetzt trotzdem gegen so eine Rotznase wie dich verliere?"
str_before5:
    .autostring 34 2 "Ich lasse mir von niemandem etwas sagen.\pPass ja auf, dass du mir nicht dumm kommst!"
str_after5:
    .autostring 34 2 "Auszeit!\nIch verliere nicht, verstanden?"
str_before6:
    .autostring 34 2 "Mein Schatzi und ich sind diese steilen Felsen hochgekraxelt.\pAlleine hätten wir das niemals geschafft."
str_after6:
    .autostring 34 2 "Das macht nichts!\nMein Schatzi und ich haben bereits gewonnen.\pIm Spiel der Liebe sind wir die Sieger!"
str_one_poke:
    .autostring 34 2 "Wie?\nDu hast nur ein kampffähiges Pokémon bei dir?\pMein Schatzi und ich kämpfen nur als Paar!"
.elseif LANG_EN
.endif