.ifdef LANG_GER
.global str_trainer_tipp_mushroom

str_trainer_tipp_mushroom:
	.string "Trainer-Tipp!\nWo Pilze wachsen, können Pilze\lgefunden werden.\pSelbst der Detektor kann Pilze nicht\nfinden.\pPilze können im Wochentakt\nnachwachsen."


.global str_trainer_tipp_shell

str_trainer_tipp_shell:
	.string "Trainer-Tipp!\nIn Muscheln versteckten sich\lItems, die vom Detektor nicht\lgefunden werden können.\pWöchentlich werden neue Items\nangespült."


.global str_trainer_tipp_detektor

str_trainer_tipp_detektor:
	.string "Trainer-Tipp!\nDer Detektor kann in den Optionen\lausgeschaltet werden!"


.global str_trainer_tipp_wondertrade

str_trainer_tipp_wondertrade:
	.string "Trainer-Tipp!\nJe öfter du den Wundertausch\lbenutzt, desto seltenere Pokémon\lwerden dir zugesandt!"


.global str_trainer_tipp_pokeradar

str_trainer_tipp_pokeradar:
	.string "Trainer-Tipp!\nJe öfter du den Pokéradar\lbenutzt, desto seltenere Pokémon\lspürt er auf!"


.global str_trainer_tipp_fp_menu

str_trainer_tipp_fp_menu:
	.string "Trainer-Tipp!\nIm Pokémon-Menü findet sich\lder Fleiß-Punkte Manager.\pDort kannst du die im Kampf\nverdienten Fleiß-Punkte auf\ldeine Pokémon verteilen!"


.global str_trainer_tipp_dns

str_trainer_tipp_dns:
	.string "Trainer-Tipp!\nDu kannst die Darstellung\ldes Tag-Nacht Rythmus (DNS)\lin den Optionen abschalten.\pZeitbasierte Events werden\ntrotzdem noch ausgeführt!"


.global str_trainer_tipp_cloud

str_trainer_tipp_cloud:
	.string "Trainer-Tipp!\nWenn du tieffliegende Wolken\lsiehst, kannst du auf deiner\lgewobenen Wolke emporsteigen!"


.global str_trainer_tipp_habitat

str_trainer_tipp_habitat:
	.string "Trainer-Tipp!\nBezüglich der Habitats-Funktion\ldes Pokédex fallen Höhlen und\ldergleichen unter die\lKategorie Natur.\pUnter der Kategorie Angel\nstehen jeweils S für\lSuperangel, P für Profiangel\lund A für Angel."


.elseif LANG_EN
	.global str_trainer_tipp_mushroom

	str_trainer_tipp_mushroom:
		.string "Trainer-Tipp!\nWhere mushrooms grow mushrooms\ncan be found!\pEven the detector can not\ntrace mushrooms!\pThey also regrow weekly!"

	.global str_trainer_tipp_shell

	str_trainer_tipp_shell:
		.string "Trainer-Tipp!\nItems can hide inside shells.\pThose can not be traced by\nthe detector and are washed\lup weekly."

	.global str_trainer_tipp_detektor

	str_trainer_tipp_detektor:
		.string "Trainer-Tipp!\nYou can turn off the detector\lin the options!"

	.global str_trainer_tipp_wondertrade

	str_trainer_tipp_wondertrade:
		.string "Trainer-Tipp!\nThe more often you use the\lwondertrade the rarer Pokémon\lyou will receive."

	.global str_trainer_tipp_pokeradar

	str_trainer_tipp_pokeradar:
		.string "Trainer-Tipp!\nThe more often you use the\lPokéradar the rarer the traced\nPokémon will be."

	.global str_trainer_tipp_fp_menu

	str_trainer_tipp_fp_menu:
		.string "Trainer-Tipp!\nIn your Pokémon-Menu you can find\lthe Effort Value managing system.\pThere you can distribute\nthe Effort Values your Pokémon\learned during battle."

	.global str_trainer_tipp_dns

	str_trainer_tipp_dns:
		.string "Trainer-Tipp!\nYou can change the display of\lthe colors via DNS inside\linside the options.\pTime-based events will be triggered\nnonetheless."

	.global str_trainer_tipp_cloud

	str_trainer_tipp_cloud:
		.string "When you encounter clouds\nfloating low you may ride\lyour cloud to ascend!"

	.global str_trainer_tipp_habitat

	str_trainer_tipp_habitat:
		.string "Trainer-Tipp!\nRegarding the habitat-function\lof the Pokédex: Caves and likes\lare also listed under Nature.\pThe symbols S resembles Super Rod,\nP the Good Rod and\lA the Old Rod."

.endif
