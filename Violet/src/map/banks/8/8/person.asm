.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_8_8_person_0
.global ow_script_map_8_8_person_1

ow_script_map_8_8_person_1:
loadpointer 0x0 str_0x87f9d5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f9d5:
    .autostring 34 2 "Im Fernsehen laufen immer ganz spannende Sendungen.\pErst letztens habe ich den legendären Angler über das Milotic hier in Kaskada reden hören.\pEr bezweifelt aber leider, ob die Legende um das Milotic wirklich wahr istDOTS"
.elseif LANG_EN
.endif


ow_script_map_8_8_person_0:
loadpointer 0x0 str_0x87fa5c
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x87fa5c:
    .autostring 34 2 "Den ganzen Tag läuft bei uns die Flimmerkiste.\pIch kann diese permanente Geräuschkulisse langsam nicht mehr ab, ehrlich!"
.elseif LANG_EN

.endif