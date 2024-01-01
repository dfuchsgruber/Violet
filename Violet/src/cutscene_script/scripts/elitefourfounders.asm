.include "cutscene_script.s"

.global cutscene_script_elite_four_founders

.align 4
cutscene_script_elite_four_founders:
    fadescreen 0 0 512 128 0 16
    pause 128
    maintain
    @dma3_reset
    pause 1
    song 353 0
    oam_reset
    callback_reset
    bg_reset 0
    bg_disp_reset
    bg_setup 0 bgcnfgs 3
    bg_sync_and_show 0
    bg_sync_and_show 1
    bg_sync_and_show 2
    bg_sync
    bg_vmap_init 0 0x800
    bg_vmap_init 1 0x1000
    bg_vmap_init 2 0x800
    bg_override 2 gfx_efounder_backgroundTiles 0x3000 0 COPYSET
    bg_override 1 gfx_faunfrontalTiles 0x3000 0 COPYSET
    bg_override 2 gfx_efounder_backgroundMap 0x800 0 COPYMAP
    loadpal gfx_efounder_backgroundPal 0 32 UNCOMP RESTORE
    loadpal tbox_palette_transparent, 14 * 16, 32, COPY, RESTORE
    pause 1
    fadescreen 0 0 512 128 16 0
    pause 170
frame 300
    text_init 0x8000 0 2 15 30 4 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_cutscene_script_elitefounders_0 proceed_boxes=0
    pause 1
    text_clear 0x8000
    fadescreen 0 0 16 32 0 12
    pause 64
    sound 6
    bg_scroll 1 0 256 0
    bg_override 1 gfx_faunfrontalMap 0x1000 0 COPYMAP
    loadpal gfx_faunfrontalPal 16 32 UNCOMP RESTORE
    fadescreen 0 16 16 32 16 0
    bg_scroll 1 32 180 0
    pause 24
    bg_scroll 1 400 8 0
    text_init 0x8000 0 2 5 16 12 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_cutscene_script_elitefounders_1 proceed_boxes=0
    pause 1
    text_clear 0x8000
    bg_scroll 1 32 0xFF38 0
    fadescreen 0 16 16 32 0 16
    pause 64
    sound 6
    set_io_to_val 194 0x14
    bg_override 1 gfx_albusfrontalTiles 0x3000 0 COPYSET
    bg_override 1 gfx_albusfrontalMap 0x1000 0 COPYMAP
    loadpal gfx_albusfrontalPal 16 32 UNCOMP RESTORE
    fadescreen 0 16 16 32 16 0
    bg_scroll 1 32 0xFF4C 0
    pause 24
    bg_scroll 1 400 0xFFF8 0
    text_init 0x8000 0 16 5 16 12 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_cutscene_script_elitefounders_2 proceed_boxes=0
    pause 1
    text_clear 0x8000
    bg_scroll 1 32 190 0
    fadescreen 0 16 16 32 0 16
    pause 64
    text_init 0x8000 0 10 6 20 6 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_cutscene_script_elitefounders_3 proceed_boxes=0
    pause 1
    text_clear 0x8000
    set_io_to_val 256 0x14
    bg_override 1 gfx_luciusfrontalTiles 0x3000 0 COPYSET
    bg_override 1 gfx_luciusfrontalMap 0x1000 0 COPYMAP
    loadpal gfx_luciusfrontalPal 16 32 UNCOMP RESTORE
    pause 1
    sound 6
    fadescreen 0 16 16 32 16 0
    set_io_to_val 0 0x14
    bg_scroll 1 999 0 0xFFeC
    text_init 0x8000 0 2 2 12 14 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_cutscene_script_elitefounders_4 proceed_boxes=0
    pause 1
    text_init 0x8002 0 18 2 12 14 14 200
    tbox_and_interrupt 0x8002 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_cutscene_script_elitefounders_5 proceed_boxes=0
    pause 1

    text_init 0x8003 0 2 15 28 4 14 380
    tbox_and_interrupt 0x8003 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_cutscene_script_elitefounders_5_2 proceed_boxes=0
    

    text_clear 0x8000
    text_clear 0x8002
    text_clear 0x8003
    bg_scroll 1 32 0xFF00 0
    fadescreen 0 16 16 32 0 16
    pause 64
    fadescreen 0 0 16 32 12 0
    pause 64
    text_init 0x8000 0 2 15 30 4 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_cutscene_script_elitefounders_6 proceed_boxes=0
    pause 64
    mapreload
    script_notify
    end


.align 4
bgcnfgs:
    bg_setup_cnfg 0 0 31 0 0 0
    bg_setup_cnfg 1 1 28 1 0 1
    bg_setup_cnfg 2 2 30 0 0 2

.align 4
fmap:
    fontmap 0 2 1
    

@ // Strings

.ifdef LANG_GER
	.global str_cutscene_script_elitefounders_0
	.global str_cutscene_script_elitefounders_1
	.global str_cutscene_script_elitefounders_3
	.global str_cutscene_script_elitefounders_4
	.global str_cutscene_script_elitefounders_5
	.global str_cutscene_script_elitefounders_6

	str_cutscene_script_elitefounders_0:
		.autostring 34 2 "Vor vielen Jahren kamen drei Trainer nach Theto DOTS\pIhre Ankunft läutete eine neue Ära ein DOTSPAUSE_UNTIL_PRESS"
	str_cutscene_script_elitefounders_1:
        .autostring 16 8 "Faun, die Pinke Faust.\nDer älteste der Top Vier\pMan sagt ihm Frohsinn und Gutmütigkeit nach.PAUSE_UNTIL_PRESS"
	str_cutscene_script_elitefounders_2:
		.autostring 16 8 "Albus, der Weise.\nSein Verstand und seine Weitsicht sind berüchtigt.\pUnter allen Trainern ist er der größte Taktiker.\pHeute führt er eine Revolution an und stellt sich gegen die Pokémon-LigaDOTSPAUSE_UNTIL_PRESS"
	str_cutscene_script_elitefounders_3:
		.autostring 16 8 "Einer aber war der Stärkste unter allenDOTSPAUSE_UNTIL_PRESS"
	str_cutscene_script_elitefounders_4:
		.autostring 15 8 "Lucius, der Erbarmungslose.\nEr wurde als unbesiegbarer Drachenjäger bekannt.\pSeine Stärke ist legendärDOTSPAUSE_UNTIL_PRESS"
	str_cutscene_script_elitefounders_5:
        .autostring 14 8 "DOTSEr war einst der stärkste Trainer der RegionDOTSPAUSE_UNTIL_PRESS"
    str_cutscene_script_elitefounders_5_2:
        .autostring 34 2 "Der ehemalige Champion!\pNachdem er besiegt wurde, verschwand er und niemand weiß, was aus ihm geworden istDOTSPAUSE_UNTIL_PRESS"
    str_cutscene_script_elitefounders_6:
        .autostring 34 2 "Gemeinsam eroberten sie die Region und gründeten die Pokémon-Liga.\pSie brachten der Region lange Jahre des FriedensDOTS DOTS DOTS\pEhe sie ihren Differenzen schließlich nicht länger beiliegen konnten.\pSie gingen allesamt ihrer WegeDOTSPAUSE_UNTIL_PRESS"
.elseif LANG_EN
.endif


