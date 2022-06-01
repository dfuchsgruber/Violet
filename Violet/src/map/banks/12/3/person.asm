
.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "move_tutor.s"
.include "movements.s"

.global ow_script_laubdorf_indoor_1_person_0
ow_script_laubdorf_indoor_1_person_0:
lock
faceplayer
setvar 0x8004 MOVE_TUTOR_ENERGIEBALL
callasm move_tutor_set_flag
loadpointer 0x0 str_0
callstd MSG_KEEPOPEN
call move_tutor_item_check
compare LASTRESULT 0
gotoif NOT_EQUAL has_mushrooms
closeonkeypress
release
end

has_mushrooms:
applymovement LASTTALKED mov_exclam
waitmovement 0x0
lock
faceplayer
loadpointer 0x0 str_1
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif LESS ow_script_0x94610c
loadpointer 0x0 str_select
callstd MSG
setvar 0x8005 MOVE_TUTOR_ENERGIEBALL
call ow_script_move_tutor_do
compare LASTRESULT 0x0
gotoif EQUAL selection_exited
call ow_script_move_tutor_pay_items
loadpointer 0x0 str_move_tutor_pay_items
callstd MSG
end

selection_exited:
loadpointer 0x0 str_aborted
callstd MSG_KEEPOPEN
release
end

mov_exclam:
    .byte SAY_EXCLAM, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier in der Natur kann man die Energie, die einen umgibt, förmlich spüren.\pWenn du möchtest, kann ich einem deiner Pokémon die Attacke Energieball beibringen.\pAls Gegenleistung verlange ich dafür aber entweder einen Riesenpilz oder drei Minipilze."
str_1:
    .autostring 34 2 "Fantastisch!\nDu hast BUFFER_2-mal\lBUFFER_1!\pSoll ich einem deiner Pokémon Energieball beibringen?"
str_select:
    .autostring 34 2 "Welchem deiner Pokémon soll ich Energieball beibringen?"
str_aborted:
    .autostring 34 2 "Wie schade.\nWenn du deine Meinung ändern solltest, weißt du ja, wo du mich findest."

.elseif LANG_EN
str_0:
    .autostring 34 2 "Out here in the nature one can really feel the energy that surrounds us.\pIf you want, I can teach one of your Pokémon the move Energy Ball.\pIn return however, I would like to have one Big Mushroom or three Tiny Mushrooms."
str_1:
    .autostring 34 2 "Fantastic!\nYou got BUFFER_2-times\lBUFFER_1!\pShould I teach one of your Pokémon Energy Ball?"
str_select:
    .autostring 34 2 "Which of your Pokémon should be taught Energy Ball?"
str_aborted:
    .autostring 34 2 "What a pity.\nIf you ever come to change your mind, you know where to find me, right?"
.endif