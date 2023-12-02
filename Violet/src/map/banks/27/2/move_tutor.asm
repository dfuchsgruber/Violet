.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "move_tutor.s"
.include "movements.s"

make_move_tutor_std move_tutor str_0 str_bye

.global ow_script_beach_house_move_tutor
ow_script_beach_house_move_tutor:
    call move_tutor
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wenn meine Frau wüsste, dass ich mich hier herumtreibeDOTS\pAber ich habe einfach einen Delegator zuhause zurück gelassen.\pWenn du mir BUFFER_1x Minipilze oder BUFFER_2x Riesenpilz bringst, kann ich einem deiner Pokémon die Attacke Delegator beibringen."
str_bye:
    .autostring 34 2 "Ganz wie du meinst.\pMir hat der Delegator schon viele glückliche Stunden im Strandhaus beschertDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "If my wife knew I was lurking arround hereDOTS\pBut I simply left a substitute back at home and sneaked in here.\pIf you can bring me three Tiny Mushroom or one Big Mushroom I can teach one of your Pokémon Substitute."
str_bye:
    .autostring 34 2 "As you like.\pFor me, Substitute gave me many happy hours here in the beach houseDOTS"
.endif
