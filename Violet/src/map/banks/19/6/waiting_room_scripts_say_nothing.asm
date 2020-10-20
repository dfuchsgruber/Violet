.include "overworld_script.s"
.include "specials.s"
.include "callstds.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_ceometria_gym_say_nothing_variant_0
.global ow_script_ceometria_gym_say_nothing_variant_1
.global ow_script_ceometria_gym_say_nothing_variant_2
.global ow_script_ceometria_gym_say_nothing_variant_3
.global ow_script_ceometria_gym_say_nothing_variant_4
.global ow_script_ceometria_gym_say_nothing_variant_5
.global ow_script_ceometria_gym_say_nothing_variant_6
.global ow_script_ceometria_gym_say_nothing_variant_7

ow_script_ceometria_gym_say_nothing_variant_0:
    loadpointer 0 str_say_nothing_0
    callstd MSG_FACE
    end
ow_script_ceometria_gym_say_nothing_variant_1:
    loadpointer 0 str_say_nothing_1
    callstd MSG_FACE
    end
ow_script_ceometria_gym_say_nothing_variant_2:
    loadpointer 0 str_say_nothing_2
    callstd MSG_FACE
    end
ow_script_ceometria_gym_say_nothing_variant_3:
    loadpointer 0 str_say_nothing_3
    callstd MSG_FACE
    end
ow_script_ceometria_gym_say_nothing_variant_4:
    loadpointer 0 str_say_nothing_4
    callstd MSG_FACE
    end
ow_script_ceometria_gym_say_nothing_variant_5:
    loadpointer 0 str_say_nothing_5
    callstd MSG_FACE
    end
ow_script_ceometria_gym_say_nothing_variant_6:
    loadpointer 0 str_say_nothing_6
    callstd MSG_FACE
    end
ow_script_ceometria_gym_say_nothing_variant_7:
    loadpointer 0 str_say_nothing_7
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_say_nothing_0:
    .autostring 34 2 "Dieses Zelt ist verluchtDOTS\pEgal, welchen Weg ich wähle, ich erreiche stets diesen RaumDOTS"
str_say_nothing_1:
    .autostring 34 2 "Man braucht schon hellseherische Fähigkeiten, um sagen zu können, was hinter diesen roten Vorhängen wartetDOTS"
str_say_nothing_2:
    .autostring 34 2 "Hörst du das Geflüster?\pEs scheint von überall zu kommenDOTS"
str_say_nothing_3:
    .autostring 34 2 "Irgendetwas stimmt mit diesem Ort nicht.\pIrgendetwas ist ganz und gar falsch!"
str_say_nothing_4:
    .autostring 34 2 "Die meisten Räume in diesem Zelt bringen großes Unheil.\pEs soll aber auch wohlwollende Räume geben."
str_say_nothing_5:
    .autostring 34 2 "Das Schicksal hat bereits darüber entschieden, welchen Weg du wählst.\pNenn es Glück oder Pech, doch dein Pfad steht bereits fest."
str_say_nothing_6:
    .autostring 34 2 "Glaubst du den Menschen, die der Überzeugung sind, dass die Arenaleiterin Teah in der Lage ist, stets den richtigen Pfad zu wählen?"
str_say_nothing_7:
    .autostring 34 2 "Hast du auch das Gefühl, nicht recht voranzukommen an diesem sonderbaren Ort?"

.elseif LANG_EN
str_say_nothing_0:
    .autostring 34 2 "This tent is cursedDOTS\pNo matter which path I take, I always end up in this roomDOTS"
str_say_nothing_1:
    .autostring 34 2 "You would need supernatural abilities to tell what was behind these red curtainsDOTS"
str_say_nothing_2:
    .autostring 34 2 "Do you hear the whispers?\pThey seem to come from everywhereDOTS"
str_say_nothing_3:
    .autostring 34 2 "Something is not right with this place.\pSomething is totally off!"
str_say_nothing_4:
    .autostring 34 2 "Most of the rooms in this tent bring great mischief.\pIt is said that there are also benevolent however."
str_say_nothing_5:
    .autostring 34 2 "Destiniy has already decided which way you will choose.\pCall it luck or lack of it, but your path is already determined."
str_say_nothing_6:
    .autostring 34 2 "Do you believe the people that are convinced, that Teah is able to always pick the right path?"
str_say_nothing_7:
    .autostring 34 2 "Do you also have the feeling to not make progress in this strange place?"

.endif