.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_ceometria_indoor_2_person_0
.global ow_script_ceometria_indoor_2_person_1
.global ow_script_ceometria_indoor_2_person_2

ow_script_ceometria_indoor_2_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_ceometria_indoor_2_person_1:
    checkflag FLAG_CEOMETRIA_DUESTERUMHANG
    gotoif 1 duesterumhang_received
    lock
    faceplayer
    loadpointer 0 str_duesterumhang_intro
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_DUESTERUMHANG
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL no_space
    setflag FLAG_CEOMETRIA_DUESTERUMHANG
duesterumhang_received:
    lock
    faceplayer
    loadpointer 0 str_duesterumhang_received
    callstd MSG_KEEPOPEN
    end
no_space:
    lock
    faceplayer
    loadpointer 0 str_no_space
    callstd MSG_KEEPOPEN
    release
    end

ow_script_ceometria_indoor_2_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier zu leben ist doof.\pIch darf auf dem Friedhof nicht spielen, und das macht mich sauer!"
str_duesterumhang_intro:
    .autostring 34 2 "Mein Sohn liebt es sich zu verkleiden.\pAllerdings ist dieses Item mir unheimlich.\pSeit mein Sohn es besitzt, geschehen seltsame Dinge hier im Haus.\pIch bringe es nicht über mich, es wegzuwerfen, also kannst du es haben."
str_duesterumhang_received:
    .autostring 34 2 "Ich habe gehört, dass vor allem das Pokémon Zwirrklop den Düsterumhang mag."
str_no_space:
    .autostring 34 2 "Oh, es sieht so aus, als hättest du keinen Platz mehr für das Item."
str_2:
    .autostring 34 2 "Seit ich eine Familie habe, ist mein Leben bedeutend interessanter geworden."

.elseif LANG_EN
str_0:
    .autostring 34 2 "I don't like living here.\pI can't even play on the cemeteray and that makes me angry!"
str_duesterumhang_intro:
    .autostring 34 2 "My son loves disguising himself.\pHowever this item is uncanny to me.\pSince my son owns it, strange things have happend in this house.\pI can't bring my self to dump it so I will give it you."
str_duesterumhang_received:
    .autostring 34 2 "I heard that Dusclops likes the Reaper Cloth."
str_no_space:
    .autostring 34 2 "Oh, it looks like you don't have any room for this item."
str_2:
    .autostring 34 2 "Since I have a family my life has become significantly more interesting."
.endif