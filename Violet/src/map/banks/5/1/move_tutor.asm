.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "move_tutor.s"
.include "movements.s"


make_move_tutor_std move_tutor str_0 str_bye

.global ow_script_bluetenbach_clouds_move_tutor
ow_script_bluetenbach_clouds_move_tutor:
    call move_tutor
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 ".TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\n.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\pAn diesem Ort gelingt es mir, mich ganz und gar zu fokussieren.\pDie Kraft, die einem ein solcher Fokus gibtDOTS\pIch kann sie einem deiner Pokémon zeigen.\pIm Gegenzug für BUFFER_1x Minipiliz oder BUFFER_2x Riesenpilz bringe ich einem deiner Pokémon den Angriff BUFFER_3 bei."
str_bye:
    .autostring 34 2 "Ganz wie du meinst.\pDu unterschätzt wohl die Kraft, die ein BUFFER_3 aufbringen kann.\pAber das ist dein Problem."
.elseif LANG_EN
str_0:
    .autostring 34 2 ".TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\n.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\pThis place allows me to focus completely.\pThe power that such a focus givesDOTS\pI can show it to one of your Pokémon.\pIn exchange for BUFFER_1x Tiny Mushroom or BUFFER_2x Big Mushroom, I can teach one of your Pokémon the move BUFFER_3."
str_bye:
    .autostring 34 2 "As you wish.\pYou underestimate the power that BUFFER_3 can bring.\pBut that's your problem."
.endif
