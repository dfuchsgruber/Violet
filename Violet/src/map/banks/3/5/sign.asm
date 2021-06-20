.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "overworld_script.s"

.global ow_script_0x9555c9
.global ow_script_map_3_5_sign_0
.global ow_script_0x9555df
.global ow_script_0x9555b3
.global ow_script_map_3_5_sign_3
.global ow_script_map_3_5_sign_1
.global ow_script_map_3_5_sign_6
.global ow_script_map_3_5_sign_2
.global ow_script_map_3_5_sign_4
.global ow_script_0x955527
.global ow_script_map_3_5_sign_5
.global ow_script_0x9554da

ow_script_map_3_5_sign_1:
loadpointer 0x0 str_0x95587d
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95587d:
    .autostring 34 2 "Orina City.\pHier überragen Häuser die Wolken."


.elseif LANG_EN

.endif


ow_script_map_3_5_sign_0:
loadpointer 0x0 str_0x955818
callstd MSG_KEEPOPEN
goto ow_script_0x9554da


ow_script_0x9554da:
loadpointer 0x0 str_0x955852
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x4
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x0
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x9555b3
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x9555c9
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x9555df
compare LASTRESULT 0x3
gotoif EQUAL ow_script_0x955527
closeonkeypress
releaseall
end

.align 4
choice:
    .word str_orina_city_bounties_0, 0
    .word str_orina_city_bounties_1, 0
    .word str_orina_city_bounties_2, 0
    .word str_orina_city_bounties_3, 0


ow_script_0x955527:
loadpointer 0x0 str_0x95553d
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
goto ow_script_0x9554da


ow_script_0x9555df:
loadpointer 0x0 str_0x9555f5
show_mugshot MUGSHOT_BLACKBEARD MUGSHOT_RIGHT
goto ow_script_0x9554da


ow_script_0x9555c9:
loadpointer 0x0 str_0x95569b
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
goto ow_script_0x9554da


ow_script_0x9555b3:
loadpointer 0x0 str_0x955726
show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT
goto ow_script_0x9554da


.ifdef LANG_GER

str_0x955818:
    .string "Am Brett hängen Steckbriefe von\ngesuchten Personen aus."



str_0x955852:
    .string "Wessen Steckbrief möchtest du\nbetrachten?"



str_orina_city_bounties_0:
    .string "Violet Vors. Rin"



str_orina_city_bounties_1:
    .string "Violet Vors. Mistral"



str_orina_city_bounties_2:
    .string "Blackbeard"



str_orina_city_bounties_3:
    .string "Revolutionsführer Albus"



str_0x95553d:
    .string "Anführer der Revolutionsbewegung,\nder Weiße Albus.\lGesucht wegen Hochverrat.\lBelohnung für die Ergreifung:\l999.999POKEDOLLAR"



str_0x9555f5:
    .string "Kommandant der Blackbeard Piraten,\nBlackbeard.\pGesucht wegen schwerem Raub,\nMenschen- und Pokémonhandel.\pBelohnung für die Ergreifung:\n200.000POKEDOLLAR"



str_0x95569b:
    .string "Kommandant der zweiten Division\nvon Team Violet, Mistral.\lGesucht wegen schwerem Raub,\lHochverrat.\lBelohnung für die Ergreifung:\l75.000POKEDOLLAR"



str_0x955726:
    .string "Kommandant der dritten Division\nvon Team Violet, Rin.\pGesucht wegen Raub, Nötigung,\nEntführung, Mord.\pBelohnung für die Ergreifung:\n125.000POKEDOLLAR."


.elseif LANG_EN

.endif


ow_script_map_3_5_sign_2:
loadpointer 0x0 str_0x9553f8
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x9553f8:
    .string "Orina City Museum"


.elseif LANG_EN

.endif


ow_script_map_3_5_sign_3:
loadpointer 0x0 str_0x955429
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x955429:
    .autostring 34 2 "Orina City Bank"


.elseif LANG_EN

.endif


ow_script_map_3_5_sign_4:
loadpointer 0x0 str_0x9558a6
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x9558a6:
    .autostring 34 2 "Laz. Corp.\pWir machen Zukunft zur Gegenwart"


.elseif LANG_EN

.endif


ow_script_map_3_5_sign_5:
loadpointer 0x0 str_0x95547f
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95547f:
    .string "Ein Briefkasten"


.elseif LANG_EN

.endif


ow_script_map_3_5_sign_6:
    loadpointer 0x0 str_0x95da61
    callstd MSG_SIGN
    end


.ifdef LANG_GER

str_0x95da61:
    .autostring 34 2 "Haus des Attacken-Erinnerers"


.elseif LANG_EN

.endif