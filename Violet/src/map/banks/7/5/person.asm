
.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "mugshot.s"

.global ow_script_map_7_5_trainer_2
.global ow_script_0x830ee4
.global ow_script_map_7_5_trainer_0
.global ow_script_map_7_5_trainer_3
.global ow_script_map_7_5_trainer_1
.global ow_script_map_7_5_trainer_4
.global ow_script_silvania_gym_referee

ow_script_silvania_gym_referee:
    checkflag FRBADGE_2
    gotoif EQUAL gym_beaten
    loadpointer 0 str_silvania_gym_referee
    callstd MSG_FACE
    end
gym_beaten:
    loadpointer 0 str_beaten
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_beaten:
    .autostring 34 2 "Wahnsinn!\nDu hast Rosalie tatsächlich besiegt.\pDu hast wirklich das Zeug, es weit zu bringen!"
.elseif LANG_EN
.endif

ow_script_map_7_5_trainer_0:
trainerbattlestd 0x0 0x3f 0x0 str_0x81aff5 str_0x81b06e
loadpointer 0x0 str_0x81b06e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81aff5:
    .autostring 34 2 "Macht das Heckenlabyrinth dich verrückt?\pIch schicke dich gerne auf direktem Weg wieder nach Hause!"
str_0x81b06e:
    .autostring 34 2 "ÄhmDOTS\nDas war so aber nicht geplant."

.elseif LANG_EN

.endif


ow_script_map_7_5_trainer_4:
trainerbattlestd 0x0 0x3e 0x0 str_0x81b0bb str_0x81b0f6
loadpointer 0x0 str_0x81b0f6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81b0bb:
    .autostring 34 2 "Alles in dieser Arena duftet so wunderbar!\pDas ist der Duft des Sieges!"
str_0x81b0f6:
    .autostring 34 2 "Habe ich mich etwa getäuscht und meine Niederlage gerochen?"

.elseif LANG_EN

.endif


ow_script_map_7_5_trainer_3:
trainerbattlestd 0x0 0x3d 0x0 str_0x81b151 str_0x81b1b1
loadpointer 0x0 str_0x81b1b1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81b151:
    .autostring 34 2 "Rosalie ist wirklich fanatisch, wenn es um Natürlichkeit geht.\pSelbst die Wände sind mit Bäumen bemalt."
str_0x81b1b1:
    .autostring 34 2 "Alles ist grün in dieser ArenaDOTS"

.elseif LANG_EN

.endif


ow_script_map_7_5_trainer_2:
trainerbattlestd 0x0 0x3a 0x0 str_0x81b250 str_0x81b289
loadpointer 0x0 str_0x81b289
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81b250:
    .autostring 34 2 "Glaubst du etwa, nur weil Rosalie einen so ruhigen Eindruck erweckt, dass du eine Chance gegen sie hast?\pWeit gefehlt!\nIch werde dich in die Schranken weisen!"
str_0x81b289:
    .autostring 34 2 "Nicht übel!\pAber mit einem so hektischen Kampfstil kannst du Rosalie niemals besiegenDOTS"

.elseif LANG_EN

.endif


ow_script_movs_0x830eef:
.byte LOOK_UP
.byte FACE_DOWN
.byte LOOK_LEFT
.byte LOOK_RIGHT
.byte STOP


ow_script_map_7_5_trainer_1:
    lock
    faceplayer
    checkflag FRBADGE_2
    gotoif EQUAL mia_done
    loadpointer 0 str_0
    // callstd MSG_KEEPOPEN
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG
    warpmuted 0x7 0xa 0 0xff 0xff
    release
    end

mia_done:
    loadpointer 0 str_1
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG
    release
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "PLAYER!\pIch möchte mich noch einmal bei dir für das, was du im Kranzwald geleistet hast, bedanken.\pIch bin dir wirklich etwas schuldig.\pAber du bist hier, um gegen mich zu kämpfen.\pUnd es wäre respektlos, wenn ich dir aus Dankbarkeit den Sieg überlasse.\pLass mich dir stattdessen also einen Kampf liefern, der dir alles abverlangt."
str_1:
    .autostring 34 2 "Du bist wirklich sehr talentiert, PLAYER.\pEs überrascht mich nicht im Geringsten, dass du es mit einer Kommandantin von Team Violet aufnehmen konntest.\pViel wichtiger ist aber, dass du das Herz am rechten Fleck hast.\pDas solltest du dir vor allem bewahren, PLAYER."

.elseif LANG_EN

.endif