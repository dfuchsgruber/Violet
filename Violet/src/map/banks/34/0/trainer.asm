.include "overworld_script.s"
.include "callstds.s"

.global ow_script_power_plant_inside_trainer_0
.global ow_script_power_plant_inside_trainer_1
.global ow_script_power_plant_inside_trainer_2

ow_script_power_plant_inside_trainer_0:
    trainerbattlestd 0 0x1db 0 str_before_0 str_after_0
    loadpointer 0 str_later_0
    callstd MSG_FACE
    end
ow_script_power_plant_inside_trainer_1:
    trainerbattlestd 0 0x1dc 0 str_before_1 str_after_1
    loadpointer 0 str_later_1
    callstd MSG_FACE
    end
ow_script_power_plant_inside_trainer_2:
    trainerbattlestd 0 0x1dd 0 str_before_2 str_after_2
    loadpointer 0 str_later_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Es ist ganz schön zermürbend, sich den ganzen Tag um das Kraftwerk zu kümmern.\pWie gut, dass ich gerade Pause habe.\pDa ist genug Zeit für einen kleinen Kampf!"
str_after_0:
    .autostring 34 2 "Ist die Pause schon vorbei?"
str_later_0:
    .autostring 34 2 "Ich schätze, ich sollte wieder zurück an die Arbeit gehenDOTS"
str_before_1:
    .autostring 34 2 "Als Mechaniker muss man hier alles geben.\pSonst behält man seinen Job nicht lange!"
str_after_1:
    .autostring 34 2 "Mist!\nDa hab ich mich wohl blöd angestellt."
str_later_1:
    .autostring 34 2 "Sowas blödes aber auch!\pDa hab ich wohl irgendwo Mist gebaut und den Kampf verloren.\pHoffentlich feuert man mich dafür nichtDOTS"
str_before_2:
    .autostring 34 2 "In diesem Kraftwerk solltest du keine Angst vor Stromschlägen haben!\pPass auf!\nIch zeige dir 'mal, wie sehr das britzelt!"
str_after_2:
    .autostring 34 2 "Autsch!\nIch hab' wohl einen Stromschlag bekommenDOTS"
str_later_2:
    .autostring 34 2 "Autsch!\nAutsch autsch!\pIch habe mir wohl einen Stromschlag geholtDOTS"
.elseif LANG_EN
.endif
