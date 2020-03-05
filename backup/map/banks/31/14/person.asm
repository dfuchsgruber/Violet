.include "overworld_script.s"
.include "callstds.s"
.include "mugshot.s"

.global ow_script_ardeal_tower_center_3_person_0
.global ow_script_ardeal_tower_center_3_person_1
.global ow_script_ardeal_tower_center_3_person_2
.global ow_script_ardeal_tower_center_3_person_3
.global ow_script_ardeal_tower_center_3_person_4

ow_script_ardeal_tower_center_3_person_0:
    loadpointer 0 str_0
    show_mugshot MUGSHOT_HARRENFELD alignment=MUGSHOT_LEFT message_type=MSG_FACE mask_name=0
    end
ow_script_ardeal_tower_center_3_person_1:
    loadpointer 0 str_1
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_LEFT message_type=MSG_FACE mask_name=0
    end
ow_script_ardeal_tower_center_3_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_ardeal_tower_center_3_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_ardeal_tower_center_3_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "PLAYER!\nEs ist schrecklich!\pDer Kommandant der ersten Division von Team VioletDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEr hat Narzissa besiegt!\pEin Mitglied der Top Vier, geschlagen von Team Violet!\pDu solltest dich unbedingt zurückziehen!"
str_1:
    .autostring 34 2 "Kindchen!\nLauf lieber wegDOTS\pDem, was da oben auf dich wartet, bist du nicht gewachsenDOTS"
str_2:
    .autostring 34 2 "Wenn selbst ein Mitglied der Top Vier geschlagen wurdeDOTS\pWie können wir es da mit Team Violet aufnehmen?"
str_3:
    .autostring 34 2 "Dass so jemand Kommandant der ersten Division bei Team Violet istDOTS\pDamit konnte niemand rechnen!"
str_4:
    .autostring 34 2 "Oberkomissar Harrenfeld hat den Rückzug angeordnet.\pWir müssen eine Strategie erarbeiten, wie wir es mit diesem ersten Kommandanten von Team Violet aufnehmen können."

.elseif LANG_EN
str_0:
    .autostring 34 2 "PLAYER!\nIt's terrible!\pThe commander of the first division of Team VioletDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pHe defeated Narcissa!\pA member of the Elite Fout, defeated by Team Violet!\pYou definitely have to retreat!"
str_1:
    .autostring 34 2 "You brat!\nBetter run awayDOTS\pYou're no match for what awaits you on top of this towerDOTS"
str_2:
    .autostring 34 2 "If even a member of the Elite Four was defeatedDOTS\pHow could we possibly face Team Violet?"
str_3:
    .autostring 34 2 "That somebody like this becomes commander of the first divisionDOTs\pNobody could have guessed that!"
str_4:
    .autostring 34 2 "Detective Harrenfeld ordered to retreat.\pWe have to come up with a strategy to face the commander of Team Violet's first division!"

.endif