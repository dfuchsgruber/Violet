.include "overworld_script.s"
.include "callstds.s"

.global ow_script_ardeal_person_0
.global ow_script_ardeal_person_1
.global ow_script_ardeal_person_2

ow_script_ardeal_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_ardeal_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_ardeal_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Seit Generationen arbeitet meine Familie nun schon in dieser Burg.\pEs ist meine Pflicht, dieser Tradition nachzukommen."
str_1:
    .autostring 34 2 "Der Burgherr Lucius war einst der Champion der Region.\pSeit er geschlagen wurde, haben sich viele Dinge verändertDOTS"
str_2:
    .autostring 34 2 "Einer Legende nach wurde diese Burg von einer finsteren Königin erbaut.\pIst es nicht geradezu ironisch, wer nun darin lebt?"

.elseif LANG_EN
str_0:
    .autostring 34 2 "For generations my family has been working in this castle.\pIt is my duty to live up to that tradition."
str_1:
    .autostring 34 2 "Lucius, the lord of this castle, once has been the campion of this region.\pEver since he was defeated, a great many things have changedDOTS"
str_2:
    .autostring 34 2 "According to the legend this castle was built by a dark queen.\pIsn't it almost ironic considering who lives in it now?"

.endif