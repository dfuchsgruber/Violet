.include "overworld_script.s"

.include "std.s"

.global ow_script_0x955382
ow_script_0x955382:
loadpointer 0x0 str_0x955818
callstd MSG_KEEPOPEN
goto ow_script_0x9554da


.global ow_script_0x9554da
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


.global ow_script_0x955527
ow_script_0x955527:
call ow_script_0x8e63f4
loadpointer 0x0 str_0x95553d
callstd MSG
special 0x7
goto ow_script_0x9554da


.global ow_script_0x9555df
ow_script_0x9555df:
call ow_script_0x955687
loadpointer 0x0 str_0x9555f5
callstd MSG
special 0x7
goto ow_script_0x9554da


.global ow_script_0x955687
ow_script_0x955687:
setvar 0x8000 0x1
setvar 0x8001 0x1a
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x9555c9
ow_script_0x9555c9:
call ow_script_0x936c1c
loadpointer 0x0 str_0x95569b
callstd MSG
special 0x7
goto ow_script_0x9554da


.global ow_script_0x9555b3
ow_script_0x9555b3:
call ow_script_0x8f4d18
loadpointer 0x0 str_0x955726
callstd MSG
special 0x7
goto ow_script_0x9554da


.ifdef LANG_GER
.global str_0x955818

str_0x955818:
    .string "Am Brett hängen Steckbriefe von\ngesuchten Personen aus."
        
        
.global str_0x955852

str_0x955852:
    .string "Wessen Steckbrief möchtest du\nbetrachten?"
        
        
.global str_orina_city_bounties_0

str_orina_city_bounties_0:
    .string "Violet Vors. Rin"
        
        
.global str_orina_city_bounties_1

str_orina_city_bounties_1:
    .string "Violet Vors. Mistral"
        
        
.global str_orina_city_bounties_2

str_orina_city_bounties_2:
    .string "Blackbeard"
        
        
.global str_orina_city_bounties_3

str_orina_city_bounties_3:
    .string "Revolutionsführer Albus"
        
        
.global str_0x95553d

str_0x95553d:
    .string "Anführer der Revolutionsbewegung,\nder Weiße Albus.\lGesucht wegen Hochverrat.\lBelohnung für die Ergreifung:\l999.999POKEDOLLAR"
        
        
.global str_0x9555f5

str_0x9555f5:
    .string "Kommandant der Blackbeard Piraten,\nBlackbeard.\pGesucht wegen schwerem Raub,\nMenschen- und Pokémonhandel.\pBelohnung für die Ergreifung:\n200.000POKEDOLLAR"
        
        
.global str_0x95569b

str_0x95569b:
    .string "Kommandant der zweiten Division\nvon Team Violet, Mistral.\lGesucht wegen schwerem Raub,\lHochverrat.\lBelohnung für die Ergreifung:\l75.000POKEDOLLAR"
        
        
.global str_0x955726

str_0x955726:
    .string "Kommandant der dritten Division\nvon Team Violet, Rin.\pGesucht wegen Raub, Nötigung,\nEntführung, Mord.\pBelohnung für die Ergreifung:\n125.000POKEDOLLAR."
        
        
.elseif LANG_EN

.endif
