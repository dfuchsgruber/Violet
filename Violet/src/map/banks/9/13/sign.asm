.include "overworld_script.s"
.include "callstds.s"

.global ow_script_flavor_text_laz_corp_cybernetics_machine_0
.global ow_script_flavor_text_laz_corp_cybernetics_machine_1
.global ow_script_flavor_text_laz_corp_cybernetics_machine_2

ow_script_flavor_text_laz_corp_cybernetics_machine_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_flavor_text_laz_corp_cybernetics_machine_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end
ow_script_flavor_text_laz_corp_cybernetics_machine_2:
    loadpointer 0x0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "An der Maschine sind viele Kabel angebracht.\pOb sie mit einem Computer-System verbunden ist?"
str_1:
    .autostring 34 2 "Ein Bildschirm an der Maschine zeigt eine Menge von Polygonen.\pBei genauerem Hinsehen, wirken sie fast wie ein PokémonDOTS"
str_2:
    .autostring 34 2 "Die Maschine ist abgeschaltet.\pOb sie nicht wichtig für Elises Experimente ist?"
.elseif LANG_EN
str_0:
    .autostring 34 2 "There are many cables attached to the machine.\pCould it be connected to a computer system?"
str_1:
    .autostring 34 2 "A screen on the machine displays a large number of polygons.\pUpon closer inspection, they look almost like a PokémonDOTS"
str_2:
    .autostring 34 2 "The machine is powered off.\pIs it not important for Elise's experiments?"
.endif
