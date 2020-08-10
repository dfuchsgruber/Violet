.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_2_cave_trainer_0
.global ow_script_route_2_cave_trainer_1
.global ow_script_route_2_cave_trainer_2


ow_script_route_2_cave_trainer_0:
    trainerbattlestd 0x0 0x19c 0x0 str_challange_0 str_defeat_0
    loadpointer 0x0 str_defeat_0
    callstd MSG_FACE
    end
    
ow_script_route_2_cave_trainer_1:
    trainerbattlestd 0x0 0x19d 0x0 str_challange_1 str_defeat_1
    loadpointer 0x0 str_defeat_1
    callstd MSG_FACE
    end
ow_script_route_2_cave_trainer_2:
    trainerbattlestd 0x0 0x19e 0x0 str_challange_2 str_defeat_2
    loadpointer 0x0 str_defeat_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_challange_0:
    .autostring 34 2 "Als Kind bin ich einmal barfuß von Kaskada bis nach Blütenbach gewandert!\pIch bin zäh, Kindchen!"
str_defeat_0:
    .autostring 34 2 "Aua!\nMeine Füße schmerzen mirDOTS"
str_challange_1:
    .autostring 34 2 "Mein Klassenkamerad hat mich hierher gebrachtDOTS\pSolange er bei mir ist, habe ich keine Angst!"
str_defeat_1:
    .autostring 34 2 "UffDOTS\nHast du gar keine Angst im Dunkeln?"
str_challange_2:
    .autostring 34 2 "Ich hätte wirklich nicht gedacht, dass ein Mädchen den Mut hat, mit mir hierherzukommen.\pJetzt muss ich in den sauren Apfel beißen und gegen dich kämpfen!"
str_defeat_2:
    .autostring 34 2 "Was fällt dir ein, mich so zu blamieren?"
.elseif LANG_EN
str_challange_0:
    .autostring 34 2 "When I was a child I once walked all the way from Cascada to Petal Creek!\pI am more tougth than you think, kiddo!"
str_defeat_0:
    .autostring 34 2 "Ouch!\pMy legs hurt so muchDOTS"
str_challange_1:
    .autostring 34 2 "My class mate led me hereDOTS\pBut as long as he is here I am not at all afraid!"
str_defeat_1:
    .autostring 34 2 "UffDOTS\nAren't you even scared a little by the darkness?"
str_challange_2:
    .autostring 34 2 "I really didn't think a girl would be brave enough to come hereDOTS\pNow I have no choice but to fight you!"
str_defeat_2:
    .autostring 34 2 "How dare you make me look this bad?"

.endif