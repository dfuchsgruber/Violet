.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ceometria_person_0
.global ow_script_ceometria_person_1
.global ow_script_ceometria_person_2
.global ow_script_ceometria_person_3
.global ow_script_ceometria_person_4
.global ow_script_ceometria_person_5
.global ow_script_ceometria_person_6
.global ow_script_ceometria_person_7
.global ow_script_ceometria_person_8

ow_script_ceometria_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_ceometria_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_ceometria_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

ow_script_ceometria_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

ow_script_ceometria_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

ow_script_ceometria_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end

ow_script_ceometria_person_6:
    loadpointer 0 str_6
    callstd MSG_KEEPOPEN
    release
    end

ow_script_ceometria_person_7:
    loadpointer 0 str_7
    callstd MSG_KEEPOPEN
    release
    end

ow_script_ceometria_person_8:
    loadpointer 0 str_8
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ceometria ist für viele ein Ort der Trauer.\pIch empfinde nicht so.\pFür mich gibt es keinen Ort, an dem ich meinen verstorbenen Pokémon näher sein kann."
str_1:
    .autostring 34 2 "Teah kümmert sich um den Waldfriedhof.\pSie ist eine wirklich ruhige Persönlichkeit."
str_2:
    .autostring 34 2 "Für viele ist es eine Mutprobe, eine Nacht auf dem Waldfriedhof zu verbringen."
str_3:
    .autostring 34 2 "Blackbeard und seine Piratenbande legen hier oft Anker.\pTeah tolleriert ihre Anwesenheit, solange sie dem Friedhof gegenüber Respekt erweisen."
str_4:
    .autostring 34 2 "Teah hat erstaunliche Fähigkeiten.\pViele kommen zu ihr, um sich ihre Zukunft vorhersagen zu lassen."
str_5:
    .autostring 34 2 "Blackbeard ist der Schrecken aller ehrenhaften Matrosen.\pEr kennt keine Skrupel, weder vor Mensch noch vor Pokémon."
str_6:
    .autostring 34 2 "SchatzDOTS\nWieso hast du denn diesen schrecklich düsteren Ort für unser Date ausgesucht?"
str_7:
    .autostring 34 2 "Der Tod ist das wohl romantischste am Leben.\pErst in der Ewigkeit kann sich die Liebe beweisenDOTS"
str_8:
    .autostring 34 2 "Es heißt, dass die Königin der Nacht hier irgendwo ihr Ende gefunden hat.\pWir Hexen versuchen alle, sie wiederzuerwecken."
.elseif LANG_EN
str_0:
    .autostring 34 2 "For many Ceometria is a sad place.\pI don't feel so.\pIn my opinion, there is no better place to be close to my Pokémon that have passed already."
str_1:
    .autostring 34 2 "Teah takes care of the Forest Cemeteray.\pShe really is a calm person."
str_2:
    .autostring 34 2 "For many it is a dring to stay one night at the Forest Cemetary."
str_3:
    .autostring 34 2 "Blackbeard and his pirate crew come here quite often.\pTeah tollerates them as long as they are respectful towards the Cemeteray."
str_4:
    .autostring 34 2 "Teah has really astonishing abilities.\pMany people visit her to be told their future."
str_5:
    .autostring 34 2 "Blackbeard is the terror of all honest sailors.\pHe knows no scruple in face of men and Pokémon alike."
str_6:
    .autostring 34 2 "HoneyDOTS\pWhy of all places did you pick this sinister one for our date?"
str_7:
    .autostring 34 2 "Death above all is the most romantic aspects of life.\pOnly through eternity love can prove itselfDOTS"
str_8:
    .autostring 34 2 "Legend has it that the Queen Of Darkness found her end in this place.\pWe witches crave to reawaken her."
.endif