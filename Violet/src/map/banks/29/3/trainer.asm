.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_7_trainer_0
.global ow_script_route_7_trainer_1
.global ow_script_route_7_trainer_2

ow_script_route_7_trainer_0:
    trainerbattlestd 0x0 0x13f 0 str_before_0 str_after_0
    loadpointer 0x0 str_after_0
    callstd MSG_FACE
    end
ow_script_route_7_trainer_1:
    trainerbattlestd 0x0 0x140 0 str_before_1 str_after_1
    loadpointer 0x0 str_after_1
    callstd MSG_FACE
    end
ow_script_route_7_trainer_2:
    trainerbattlestd 0x0 0x141 0 str_before_2 str_after_2
    loadpointer 0x0 str_after_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Mein Kopf raucht!\pZur Abkühlung, brauche ich jetzt einen Kampf!"
str_after_0:
    .autostring 34 2 "Ja, das ist schon besser!\pMein Blut ist etwas abgekühltDOTS"
str_before_1:
    .autostring 34 2 "Ich bin durch den ganzen Kontinent gewandert.\pAber nichts hat mich so geschlaucht, wie diese ekelhafte Hitze!"
str_after_1:
    .autostring 34 2 "Wie soll ich denn bei solchen Temperaturen mithalten?"
str_before_2:
    .autostring 34 2 "Mein Beruf bringt mich an die verschiedensten Orte.\pIch treffe allerlei Menschen.\pMal sehen, ob du meiner Weltgewandheit gewachsen bist!"
str_after_2:
    .autostring 34 2 "Jetzt muss ich erst einmal meine Pokémon reparieren."


.elseif LANG_EN
str_before_0:
    .autostring 34 2 "My head is smoking hot!\pI need a battle to cool down!"
str_after_0:
    .autostring 34 2 "Yes, that is better!\pMy blood cooled down somewhatDOTS"
str_before_1:
    .autostring 34 2 "I wandered the entire continent.\pBut nothing bothered me as much as this terrible heat!"
str_after_1:
    .autostring 34 2 "How am I supposed to keep up with that temperatures?"
str_before_2:
    .autostring 34 2 "My job brings me to various places.\pI meet the most different kinds of people.\pLet's see if you are any match for my experience!"
str_after_2:
    .autostring 34 2 "Now I have to fix my Pokémon."

.endif
