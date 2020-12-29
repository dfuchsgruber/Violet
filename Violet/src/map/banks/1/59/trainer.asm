.include "overworld_script.s"
.include "callstds.s"

.global ow_script_tafelberg_trainer_0
.global ow_script_tafelberg_trainer_1
.global ow_script_tafelberg_trainer_2
.global ow_script_tafelberg_trainer_3
.global ow_script_tafelberg_trainer_4
.global ow_script_tafelberg_trainer_5
.global ow_script_tafelberg_trainer_6
.global ow_script_tafelberg_trainer_7
.global ow_script_tafelberg_trainer_8
.global ow_script_tafelberg_trainer_9
.global ow_script_tafelberg_trainer_10

ow_script_tafelberg_trainer_0:
    trainerbattlestd 0 0x6c 0 str_before_0 str_after_0
    loadpointer 0 str_after_0
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_1:
    trainerbattlestd 0 0x6d 0 str_before_1 str_after_1
    loadpointer 0 str_after_1
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_2:
    trainerbattlestd 0 0x6e 0 str_before_2 str_after_2
    loadpointer 0 str_after_2
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_3:
    trainerbattlestd 0 0x6f 0 str_before_3 str_after_3
    loadpointer 0 str_after_3
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_4:
    trainerbattlestd 0 0x70 0 str_before_4 str_after_4
    loadpointer 0 str_after_4
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_5:
    trainerbattlestd 0 0x1ba 0 str_before_5 str_after_5
    loadpointer 0 str_after_5
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_6:
    trainerbattlestd 0 0x1bb 0 str_before_6 str_after_6
    loadpointer 0 str_after_6
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_7:
    trainerbattlestd 0 0x1bc 0 str_before_7 str_after_7
    loadpointer 0 str_after_7
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_8:
    trainerbattlestd 0 0x1bd 0 str_before_8 str_after_8
    loadpointer 0 str_after_8
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_9:
    trainerbattledouble 4 0x1be 0 str_before_9 str_after_9 str_cant_battle_9
    loadpointer 0 str_after_9
    callstd MSG_FACE
    end
ow_script_tafelberg_trainer_10:
    trainerbattlestd 0 0x1bf 0 str_before_10 str_after_10
    loadpointer 0 str_after_10
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Wir kämpfen für eine freie Welt.\pUnd dieses Ziel rechtfertigt doch die Mittel, derer wir uns bedienen!"
str_after_0:
    .autostring 34 2 "Du siehst nicht das große Ganze.\pSonst würdest du dich uns nicht in den Weg stellenDOTS"
str_before_1:
    .autostring 34 2 "Wieso stellst du dich gegen uns?\pWir kämpfen für die Freiheit aller Menschen in dieser Region!"
str_after_1:
    .autostring 34 2 "Wann begreifen die Menschen endlich, dass wir nicht ihre Feinde sindDOTS"
str_before_2:
    .autostring 34 2 "Albus wird diese Welt aus den Fängen der Top Vier befreien.\pDafür werde ich bis zum Letzten kämpfen!"
str_after_2:
    .autostring 34 2 "Sei es drumDOTS\pGegen jemanden wie Albus hast du keine ChanceDOTS"
str_before_3:
    .autostring 34 2 "Eine schöne Blume kann jeden Menschen entzücken.\pDu glaubst mir nicht?\nPass auf!"
str_after_3:
    .autostring 34 2 "Du bist sowas von grobDOTS\pEinfach auf meinen Blumen herumzutrampelnDOTS"
str_before_4:
    .autostring 34 2 "Einem Mechaniker wird in eine so modernen Welt nie langweilig.\pEs gibt immer Maschinen, die repariert werden wollen!"
str_after_4:
    .autostring 34 2 "Ich muss wohl jetzt erst einmal an meinem eigenen Team tüftelnDOTS"
str_before_5:
    .autostring 34 2 "Gegen unsere Revolutionsbewegung wird eine mächtige Schmutzkampange gefahren.\pAber wir scheren uns nicht um so etwas!\pWir kämpfen für ein höheres Ziel!"
str_after_5:
    .autostring 34 2 "Du bist wohl auch nur ein Sklave des Systems, nicht wahr?"
str_before_6:
    .autostring 34 2 "Käferpokémon werden oft unterschätzt, musst du wissen.\pIch zeige den Leuten dann immer liebend gerne, wie stark diese Pokémon-Art eigentlich werden kann!"
str_after_6:
    .autostring 34 2 "Versteh das bloß nicht falschDOTS\pKäfer-Pokémon sind noch immer sehr starkDOTS"
str_before_7:
    .autostring 34 2 "Ich habe mein Pokémon groß gezogen, seit es noch ein Baby war!\pWir haben noch nie einen Kampf verloren!"
str_after_7:
    .autostring 34 2 "Was?\nAber mein Pokémon und ich sind unschlagbar!\pDu hast geschummelt!"
str_before_8:
    .autostring 34 2 "Kaskada soll einer Legende nach das schönste aller Pokémon beherrbergen.\pEs ist nur passend, dass ich an einem solchen Ort trainiere!"
str_after_8:
    .autostring 34 2 "Was?\nHaben dir meine Anmut und Grazie gar nichts bedeutet?"
str_before_9:
    .autostring 34 2 "Meine Schwester weiß immer genau, was ich gerade denke.\pUnd das hilft uns natürlich auch beim Kämpfen!"
str_after_9:
    .autostring 34 2 "Schwesterherz?\nGeht es dir gut?"
str_cant_battle_9:
    .autostring 34 2 "Schwesterchen und ich kämpfen nur zu zweitDOTS\pDa musst du dich leider nach uns richten!"
str_before_10:
    .autostring 34 2 "Der Angelsport wird von vielen als sehr öde empfunden.\pDabei ist das Kämpfen mit geangelten Pokémon doch so aufregend!"
str_after_10:
    .autostring 34 2 "So einen Kampf kann man doch wahrlich nicht als langweilig bezeichnen, oder?"
.elseif LANG_EN
.endif