.include "overworld_script.s"

.global script_trainer_tipp_fp_menu
.global script_trainer_tipp_wondertrade
.global script_trainer_tipp_pokeradar
.global script_trainer_tipp_habitat
.global script_trainer_tipp_dns
.global script_trainer_tipp_cloud


script_trainer_tipp_cloud:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_cloud
    callstd 3
    releaseall
    end

script_trainer_tipp_wondertrade:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_wondertrade
    callstd 3
    releaseall
    end
    

script_trainer_tipp_fp_menu:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_fp_menu
    callstd 3
    releaseall
    end

script_trainer_tipp_pokeradar:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_pokeradar
    callstd 3
    releaseall
    end

script_trainer_tipp_habitat:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_habitat
    callstd 3
    releaseall
    end

script_trainer_tipp_dns:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_dns
    callstd 3
    releaseall
    end

.ifdef LANG_GER

	str_trainer_tipp_wondertrade:
		.string "Trainer-Tipp!\nJe öfter du den Wundertausch\lbenutzt, desto seltenere Pokémon\lwerden dir zugesandt!"

	str_trainer_tipp_pokeradar:
		.string "Trainer-Tipp!\nJe öfter du den Pokéradar\lbenutzt, desto seltenere Pokémon\lspürt er auf!"

	str_trainer_tipp_fp_menu:
		.string "Trainer-Tipp!\nIm Pokémon-Menü findet sich\lder Fleiß-Punkte Manager.\pDort kannst du die im Kampf\nverdienten Fleiß-Punkte auf\ldeine Pokémon verteilen!"

	str_trainer_tipp_dns:
		.string "Trainer-Tipp!\nDu kannst die Darstellung\ldes Tag-Nacht Rythmus (DNS)\lin den Optionen abschalten.\pZeitbasierte Events werden\ntrotzdem noch ausgeführt!"

	str_trainer_tipp_cloud:
		.string "Trainer-Tipp!\nWenn du tieffliegende Wolken\lsiehst, kannst du auf deiner\lgewobenen Wolke emporsteigen!"

	str_trainer_tipp_habitat:
		.string "Trainer-Tipp!\nBezüglich der Habitats-Funktion\ldes Pokédex fallen Höhlen und\ldergleichen unter die\lKategorie Natur.\pPokémon, die geangelt werden, sind entsprechend des notwendingen Angeltyps kategorisiert.\pJe mehr Pokébälle eine Kategorie aufweist, desto besser muss die Angel sein."


.elseif LANG_EN

	str_trainer_tipp_wondertrade:
		.string "Trainer-Tipp!\nThe more often you use the\lwondertrade the rarer Pokémon\lyou will receive."

	str_trainer_tipp_pokeradar:
		.string "Trainer-Tipp!\nThe more often you use the\lPokéradar the rarer the traced\nPokémon will be."

	str_trainer_tipp_fp_menu:
		.string "Trainer-Tipp!\nIn your Pokémon-Menu you can find\lthe Effort Value managing system.\pThere you can distribute\nthe Effort Values your Pokémon\learned during battle."

	str_trainer_tipp_dns:
		.string "Trainer-Tipp!\nYou can change the display of\lthe colors via DNS inside\linside the options.\pTime-based events will be triggered\nnonetheless."

	str_trainer_tipp_cloud:
		.string "When you encounter clouds\nfloating low you may ride\lyour cloud to ascend!"

	str_trainer_tipp_habitat:
		.string "Trainer-Tipp!\nRegarding the habitat-function\lof the Pokédex: Caves and likes\lare also listed under Nature.\pThe symbols S resembles Super Rod,\nP the Good Rod and\lA the Old Rod."

.endif
