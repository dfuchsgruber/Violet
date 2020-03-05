.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ceometria_trainer_0

ow_script_ceometria_trainer_0:
    trainerbattlestd 0 0x12f 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Ich werde eines Tages zu einer ebenso großen Hexe, wie einst die Königin der Nacht es war!"
str_trainer0_defeat:
    .autostring 34 2 "Bis ich so stark werde, wie die Königin der Nacht, wird es wohl noch etwas dauernDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "One day I will be as strong as the queen of the night once has been!"
str_trainer0_defeat:
    .autostring 34 2 "Until I get so strong it probably will take some timeDOTS"
.endif