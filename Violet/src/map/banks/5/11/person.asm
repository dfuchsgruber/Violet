.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_5_11_person_1
.global ow_script_map_5_11_person_0

ow_script_map_5_11_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_map_5_11_person_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich erinnere mich noch, als unser Arenaleiter Manuel ein kleiner Junge war.\pEr hat nichts anderes getan, als den ganzen Tag trainiert.\pJetzt ist er einer der stärksten Männer der Region.\pIch bewundere jemanden, der mit solcher Entschlossenheit an seinen Zielen festhält."
str_1:
    .autostring 34 2 "Blütenbach mag ja ganz nett seinDOTS\pAber es ist so öde hier!\pWer will schon den ganzen Tag Ruhe haben?\pWenn ich älter bin, werde ich nach Orina City ziehen.\pDa ist man immer im Zentrum des Geschehens!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "I still remember when your gym leader Manuel was just a boy.\pAll day would do nothing but to train.\pNow he is one of the strongest men in this region.\pI really admire people who pursue their goals with that much determination."
str_1:
    .autostring 34 2 "Sure, Petal Creek may be a nice place to liveDOTS\pBut it is so boring here!\pWho wants no action all day anyway?\pWhen I am older I will move to Orina City.\pThere, you are always in the middle of everything!"
.endif