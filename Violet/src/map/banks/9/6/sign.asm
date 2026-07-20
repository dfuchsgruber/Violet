.include "overworld_script.s"
.include "callstds.s"

.global ow_script_flavor_text_laz_corp_clouds_lab_cloud
.global ow_script_flavor_text_laz_corp_clouds_lab_feathers
.global ow_script_flavor_text_laz_corp_screens_balloons

ow_script_flavor_text_laz_corp_clouds_lab_cloud:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_flavor_text_laz_corp_clouds_lab_feathers:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end
ow_script_flavor_text_laz_corp_screens_balloons:
    loadpointer 0x0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Das Knistern von elektrischen Ladungen erfüllt den Raum.\pIch sollte diesen Wolken nicht zu nahe kommen.\pWie sie wohl erzeugt werden?"
str_1:
    .autostring 34 2 "Auf dem Tisch liegen bunte Federn verteilt.\pVon welchen Pokémon sie wohl stammen?"
str_2:
    .autostring 34 2 "Warum hat man hier Luftballons an den Tisch angebunden?\pSie scheinen von selbst zu schwebenDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "The crackling of electrical charges fills the room.\pI should not get too close to these clouds.\pHow are they generated?"
str_1:
    .autostring 34 2 "On the table lie colorful feathers scattered.\pFrom which Pokémon do they probably come?"
str_2:
    .autostring 34 2 "Why did someone attach helium balloons to the table here?\pThey seem to float on their ownDOTS"
.endif
