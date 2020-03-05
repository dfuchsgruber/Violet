.include "overworld_script.s"
.include "callstds.s"
.include "items.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"

.global ow_script_orina_city_inside_0_person_0
.global ow_script_orina_city_inside_0_person_1

ow_script_orina_city_inside_0_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_orina_city_inside_0_person_1:
    checkflag FLAG_ORINA_CITY_TM_LIGHT_SCREEN
    gotoif 1 done
    lock
    faceplayer
    loadpointer 0 str_receive_tm_16
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_TM16
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL no_space
    setflag FLAG_ORINA_CITY_TM_LIGHT_SCREEN
done:
    lock
    faceplayer
    loadpointer 0 str_received_tm_16
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



.ifdef LANG_GER
str_0:
    .autostring 34 2 "Oft finden Menschen, wenn man ihnen von unserem Haus erzählt, nicht hierher.\pIch kann mir wirklich nicht erklären, woran das liegtDOTS"
str_receive_tm_16:
    .autostring 34 2 "Hier in der Stadt wohnt ein Wissenschaftler, der total besessen von den Eigenschaften des Lichts ist.\pWas er aber nicht weiß, ist, dass man es auch zu defensiven Zwecken benutzen kann."
str_received_tm_16:
    .autostring 34 2 "Die Attacke Lichtschild verstärkt für fünf Runden die spezielle Verteidigung deiner Pokémon.\pIst es nicht wunderbar, zu was Licht alles im Stande ist?"
str_no_space:
    .autostring 34 2 "Du scheinst gar keinen Platz dafür zu haben.\pKomm wieder, wenn sich das geändert hat."

.elseif LANG_EN
str_0:
    .autostring 34 2 "Often people don't find this place when you tell them about it.\pI can't explain why this happensDOTS"
str_receive_tm_16:
    .autostring 34 2 "A scientist lives in this city who is most fascinated by the attributes of light.\pWhat he doesn't know is, that you can also use it for defensive purposes."
str_received_tm_16:
    .autostring 34 2 "The attack light screen increases the special defense of your pokémon for five turns.\pIsn't it wonderful, what light is capable of?"
str_no_space:
    .autostring 34 2 "You seem to have no space for it at all!\pCome back once this fact has changed."
.endif