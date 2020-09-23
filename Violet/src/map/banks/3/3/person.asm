.include "callstds.s"
.include "overworld_script.s"
.include "species.s"
.include "flags.s"
.include "mugshot.s"
.include "movements.s"

.global ow_script_map_3_3_person_3
.global ow_script_map_3_3_person_5
.global ow_script_map_3_3_person_2
.global ow_script_map_3_3_person_6
.global ow_script_map_3_3_person_7
.global ow_script_map_3_3_person_1
.global ow_script_map_3_3_person_8
.global ow_script_0x8f08aa
.global ow_script_map_3_3_person_4
.global ow_script_0x8f08a1
.global ow_script_map_3_3_person_0
.global ow_script_silvania_felix_rosalie

ow_script_silvania_felix_rosalie:
    loadpointer 0 str_0
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED hide_mugshot=0
    applymovement 21 mov_fu
    waitmovement 0
    loadpointer 0 str_1
    callstd MSG_KEEPOPEN
    hide_mugshot
    applymovement 21 mov_fd
    applymovement 20 mov_fd
    waitmovement 0
    loadpointer 0 str_2
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    loadpointer 0 str_3
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN hide_mugshot=0
    applymovement 20 mov_fr
    waitmovement 0
    loadpointer 0 str_4
    callstd MSG_KEEPOPEN
    hide_mugshot
    loadpointer 0 str_5
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_HAPPY hide_mugshot=0
    loadpointer 0 str_6
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    applymovement 20 mov_fu
    applymovement 21 mov_fl
    waitmovement 0
    pause 32
    sound 121
    applymovement 7 mov_cut_tree
    waitmovement 0x0
    hidesprite 7
    checksound
    pause 24
    applymovement 20 mov_2u
    applymovement 21 mov_2u
    waitmovement 0
	pause 32
	sound 9
    hidesprite 20
    hidesprite 21
    checksound 
    pause 16
    releaseall
    end

mov_fu:
    .byte LOOK_UP, STOP
mov_fl:
    .byte LOOK_LEFT, STOP
mov_fd:
    .byte LOOK_DOWN, STOP
mov_fr:
    .byte LOOK_RIGHT, STOP
mov_1u:
    .byte STEP_UP, STOP
mov_2u:
    .byte STEP_UP, STEP_UP, STOP
mov_cut_tree:
    .byte 0x69, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Das ist typischDOTS"
str_1:
    .autostring 34 2 "Sieht wohl ganz so aus, als wäre RIVAL schon hier gewesenDOTS\pWas denkt er sich nur dabei, allein in solche Gefahren hineinzurennenDOTS"
str_2:
    .autostring 34 2 "PLAYER!\nDa bist du ja.\pWir haben schon auf dich gewartet."
str_3:
    .autostring 34 2 "Jetzt bist du ja endlich da!\pAlso können wir loslegen!"
str_4:
    .autostring 34 2 "Wir wissen nicht genau, was uns hier erwartet.\pAber wir können davon ausgehen, dass der Team Violet Kommandant uns einigen Widerstand leisten wird.\pDas hier wird bestimmt kein Kinderspiel werdenDOTS\pWir sollten also zusammenbleiben, so weit es geht, ja?\pGemeinsam haben wir bessere Chancen, diese Leute für ihre Verbrechen zur Rechenschaft zu ziehen."
str_5:
    .autostring 34 2 "Wie viel Anführer in einem so jungen Polizisten stecken kann!"
str_6:
    .autostring 34 2 "Aber dein Plan klingt sehr vernünftig.\pSo machen wir es!\pLasst uns keine Zeit verlieren.\pNicht, dass diese Rüpel meinem geliebten Wald einen Schaden zufügen."
.elseif LANG_EN
.endif


ow_script_map_3_3_person_0:
loadpointer 0x0 str_0x81aafa
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81aafa:
    .string "Ich trainere mein Pokémon um Rosalie\nherauszufordern."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_3:
loadpointer 0x0 str_0x81ab2c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81ab2c:
    .autostring 34 2 "Kranzdorf wurde in der Lichtung eines Waldes erbaut.\pAlles hier ist durchströmt vom Geist der Natur."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_1:
loadpointer 0x0 str_0x81ab8e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81ab8e:
    .autostring 34 2 "Mein Hausarzt hat mir verordnet, hier einen Urlaub zu machen.\pIch muss sagen, dass die Waldluft mir sehr gut tut."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_2:
loadpointer 0x0 str_0x8e1ba8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e1ba8:
    .autostring 34 2 "Der Zeitwald hat schon immer etwas Mysteriöses an sich gehabt.\pKennst du schon den geweihten Schrein, der sich dort befindet?"

.elseif LANG_EN

.endif



ow_script_map_3_3_person_7:
loadpointer 0x0 str_0x8df298
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8df298:
    .autostring 34 2 "Rosalie, die Arenaleiterin dieses Dorfes hat ihr Leben diesem Wald gewidmet.\pMan merkt ihr die Leidenschaft für die Natur sehr an, finde ich."


.elseif LANG_EN

.endif


ow_script_map_3_3_person_8:
loadpointer 0x0 str_0x8e0932
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8e0932:
    .autostring 34 2 "Hast du es mitbekommen?\pDer alte Champion Lucius wurde besiegt!\pIch habe gehört, dass es ein Mädchen gewesen sein sollDOTS"

.elseif LANG_EN

.endif


ow_script_0x8f08a1:
goto ow_script_0x8f08aa


ow_script_0x8f08aa:
loadpointer 0x0 str_0x8f4688
callstd MSG_KEEPOPEN
callasm 0x91a44c1
pause 0x1
end


.ifdef LANG_GER

str_0x8f4688:
    .string "  Wählst du dieses Pokémon?\nA : Bestätigen  B : Abbruch"


.elseif LANG_EN

.endif