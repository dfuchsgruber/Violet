
.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "move_tutor.s"
.include "movements.s"

make_move_tutor_std move_tutor str_intro str_aborted

.global ow_script_laubdorf_indoor_1_person_0
ow_script_laubdorf_indoor_1_person_0:
    call move_tutor
    end

.ifdef LANG_GER
str_intro:
    .autostring 34 2 "Hier in der Natur kann man die Energie, die einen umgibt, förmlich spüren.\pWenn du möchtest, kann ich einem deiner Pokémon die Attacke BUFFER_3 beibringen.\pAls Gegenleistung verlange ich dafür aber entweder BUFFER_1x Riesenpilz oder BUFFER_2x Minipilz."
str_aborted:
    .autostring 34 2 "Wie schade.\nWenn du deine Meinung ändern solltest, weißt du ja, wo du mich findest."

.elseif LANG_EN
str_0:
    .autostring 34 2 "Out here in the nature one can really feel the energy that surrounds us.\pIf you want, I can teach one of your Pokémon the move BUFFER_3.\pIn return, I demand either BUFFER_1x Big Mushroom or BUFFER_2x Tiny Mushroom."
str_1:
    .autostring 34 2 "Fantastic!\nYou got BUFFER_2-times\lBUFFER_1!\pShould I teach one of your Pokémon BUFFER_3?"
str_select:
    .autostring 34 2 "Which of your Pokémon should be taught BUFFER_3?"
str_aborted:
    .autostring 34 2 "What a pity.\nIf you ever come to change your mind, you know where to find me, right?"
.endif