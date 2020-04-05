.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ceometria_trainer_0
.global ow_script_ceometria_trainer_1
.global ow_script_ceometria_trainer_2
.global ow_script_ceometria_trainer_3

ow_script_ceometria_trainer_0:
    trainerbattlestd 0 0x12f 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end
ow_script_ceometria_trainer_1:
    trainerbattlestd 0 0x17e 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end
ow_script_ceometria_trainer_2:
    trainerbattlestd 0 0x17f 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end
ow_script_ceometria_trainer_3:
    trainerbattlestd 0 0x180 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Ich werde eines Tages zu einer ebenso großen Hexe, wie einst die Königin der Nacht es war!"
str_trainer0_defeat:
    .autostring 34 2 "Bis ich so stark werde, wie die Königin der Nacht, wird es wohl noch etwas dauernDOTS"
str_trainer1_challange:
    .autostring 34 2 "Was treibst du denn hier?\pDas hier ist ein heiliger Ort für Hexen!\pKinder haben hier nichts zu suchen!"
str_trainer1_defeat:
    .autostring 34 2 "Das Heiligtum von einem Kind entweihtDOTS"
str_trainer2_challange:
    .autostring 34 2 "In der Nähe des Dunklen Turms kann eine Hexe gar nicht verlieren!"
str_trainer2_defeat:
    .autostring 34 2 "Der Dunkle TurmDOTS\pEr hat mich im Stich gelassenDOTS"
str_trainer3_challange:
    .autostring 34 2 "Dieser sogenannte Dunkle Turm ist archäologisch gesehen höchst interessant.\pIch kann dir nicht erlauben, meine Arbeiten zu stören."
str_trainer3_defeat:
    .autostring 34 2 "Na gut, wenn du dir den Turm unbedingt ansehehn möchtestDOTS\pAber kommm mir nicht in die Quere, ja?"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "One day I will be as strong as the queen of the night once has been!"
str_trainer0_defeat:
    .autostring 34 2 "Until I get so strong it probably will take some timeDOTS"
.endif