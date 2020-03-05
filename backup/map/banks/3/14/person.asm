.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "items.s"

.global ow_script_forest_cemetery_person_0
.global ow_script_forest_cemetery_person_1
.global ow_script_forest_cemetery_person_2
.global ow_script_forest_cemetery_person_3
.global ow_script_forest_cemetery_person_4
.global ow_script_forest_cemetery_person_5
.global ow_script_forest_cemetery_person_6
.global ow_script_forest_cemetery_person_7

ow_script_forest_cemetery_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_forest_cemetery_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_forest_cemetery_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_forest_cemetery_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_forest_cemetery_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_forest_cemetery_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_forest_cemetery_person_6:
    checkflag FLAG_FOREST_CEMETERY_SPELL_TAG
    gotoif 1 spell_tag_received
    lock
    faceplayer
    loadpointer 0 str_receive_spell_tag
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_BANNSTICKER
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL no_space
    setflag FLAG_FOREST_CEMETERY_SPELL_TAG
spell_tag_received:
    lock
    faceplayer
    loadpointer 0 str_spell_tag_received
    callstd MSG_KEEPOPEN
    release
    end
no_space:
    lock
    faceplayer
    loadpointer 0 str_no_space
    callstd MSG_KEEPOPEN
    release
    end
ow_script_forest_cemetery_person_7:
    checkflag FLAG_FOREST_CEMETERY_CLEANSE_TAG
    gotoif 1 cleanse_tag_received
    lock
    faceplayer
    loadpointer 0 str_receive_cleanse_tag
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_SCHUTZBAND
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL no_space2
    setflag FLAG_FOREST_CEMETERY_CLEANSE_TAG
cleanse_tag_received:
    lock
    faceplayer
    loadpointer 0 str_cleanse_tag_received
    callstd MSG_KEEPOPEN
    release
    end
no_space2:
    lock
    faceplayer
    loadpointer 0 str_no_space2
    callstd MSG_KEEPOPEN
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Teah, die Arenaleiterin von Ceometria kommt oft hierher, um zu beten.\pSie sorgt sich um die Seelen der Ruhelosen."
str_1:
    .autostring 34 2 "Viele empfinden in diesen Wäldern Angst.\pDoch Geist-Pokémon sind nicht per se bösartig.\pViel eher sollte man diejenigen, welche keine Ruhe finden durften, bemitleiden."
str_2:
    .autostring 34 2 "In dem Haus dort wohnt Teah.\pSie hält den Waldfriedhof in Stand.\pAußerdem ist sie eine Hellseherin, sagt man sich."
str_3:
    .autostring 34 2 "Jede Lichtung in diesem Wald ist eine wahre Erlösung.\pIch fürchte michDOTS"
str_4:
    .autostring 34 2 "Auf diesem Friedhof liegen Menschen und Pokémon begraben.\pAuch im Tod noch, können so Trainer und Pokémon zusammen bleiben."
str_5:
    .autostring 34 2 "Vor einiger Zeit ist mein Kangama verstorben.\pIch besuche sein Grab jeden Tag."
str_receive_spell_tag:
    .autostring 34 2 "Diese Wälder sind ein mysteriöser Ort.\pVor einigen Jahren habe ich einen Baum gesehen, welcher sich bewegt hat.\pAn einem seiner Äste hing das hier."
str_spell_tag_received:
    .autostring 34 2 "Der Bannsticker hat den Baum verzaubert.\pAls ich ihn entfernt habe, ist der Baum wieder erstarrt."
str_no_space:
    .autostring 34 2 "Oh, es sieht so aus, als hättest du dafür keinen Platz!"
str_receive_cleanse_tag:
    .autostring 34 2 "Wenn man einen Geliebten verloren hat, muss man aufpassen, dass dessen Seele nicht als bösartiger Geist wiederkehrt.\pUm dich vor bösen Geistern zu schützen, kann ich dir das hier geben."
str_cleanse_tag_received:
    .autostring 34 2 "Das Schutzband verringert die Wahrscheinlichkeit, auf wilde Pokémon zu treffen, wenn das Pokémon an der Spitze deines Teams es trägt."
str_no_space2:
    .autostring 34 2 "Du hast dafür keinen Platz!\pWenn du das Schutzband möchtest, komm wieder, sobald du Platz geschaffen hast."

.elseif LANG_EN
str_0:
    .autostring 34 2 "Teah, the Gymleader of Ceometria often visits this place.\pShe cares about the souls of the restless."
str_1:
    .autostring 34 2 "Many feel fear in these kinds of forests.\pBut Ghost Pokémon are not neccesarily wicked.\pYou should rather pity those who were not able to find rest."
str_2:
    .autostring 34 2 "In this house over there lives Teah.\pShe takes care of the Forest-Cemetery.\pAlso, she is said to be a fortune teller."
str_3:
    .autostring 34 2 "Each glade in this forest is a relief.\pI am frightenedDOTS"
str_4:
    .autostring 34 2 "On this cemetery men and Pokémon are burried next to one another.\pEven in death trainer and Pokémon can be united this way."
str_5:
    .autostring 34 2 "Some while ago my Kangaskhan died.\pI visit its grave every day."
str_receive_spell_tag:
    .autostring 34 2 "These woods are mysterious.\pOnce I saw a tree moving arround.\pOn one of his branches there was this."
str_spell_tag_received:
    .autostring 34 2 "The Spell Tag has enchanted this tree.\pAfter I removed it, it became still again."
str_no_space:
    .autostring 34 2 "Oh, it looks like you don't have room for this."
str_receive_cleanse_tag:
    .autostring 34 2 "When you lost a beloved one, you have to prevent his soul from returning as an evil spirit.\pTo protect you for malevolent spirits I will give you this."
str_cleanse_tag_received:
    .autostring 34 2 "The Cleanse Tag decreases the probability of encountering wild Pokémon when your party leader holds its."
str_no_space2:
    .autostring 34 2 "You don't have room for this item.\pIf you want to get the Cleanse Tag you have to return after you made room."
.endif