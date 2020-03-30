.include "anim_engine.s"

.global ae_script_elite_four_founders

.align 4
ae_script_elite_four_founders:
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
    pause 1
    fadescreen 0 0 512 128 16 0
    pause 170
frame 300
    text_init 0x8000 0 4 15 30 4 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_anim_engine_elitefounders_0 proceed_boxes=0
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
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_anim_engine_elitefounders_1 proceed_boxes=0
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
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_anim_engine_elitefounders_2 proceed_boxes=0
    pause 1
    text_clear 0x8000
    bg_scroll 1 32 190 0
    fadescreen 0 16 16 32 0 16
    pause 64
    text_init 0x8000 0 6 5 20 4 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_anim_engine_elitefounders_3 proceed_boxes=0
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
    text_init 0x8000 0 2 3 10 14 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_anim_engine_elitefounders_4 proceed_boxes=0
    pause 1
    text_init 0x8002 0 22 3 10 14 14 200
    tbox_and_interrupt 0x8002 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_anim_engine_elitefounders_5 proceed_boxes=0
    pause 1

    text_clear 0x8000
    text_clear 0x8002
    bg_scroll 1 32 0xFF00 0
    fadescreen 0 16 16 32 0 16
    pause 64
    fadescreen 0 0 16 32 12 0
    pause 64
    text_init 0x8000 0 4 15 30 4 14 4
    tbox_and_interrupt 0x8000 2 0 0 0 0 fmap TBOX_SPEED_FROM_SETTINGS str_anim_engine_elitefounders_6 proceed_boxes=0
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
	.global str_anim_engine_elitefounders_0

	str_anim_engine_elitefounders_0:
		.autostring 32 2 "Vor vielen Jahren kamen drei Trainer nach Theto DOTS\pIhre Ankunft läutete eine neue Ära ein DOTSPAUSE_UNTIL_PRESS"


	.global str_anim_engine_elitefounders_1

	str_anim_engine_elitefounders_1:
		.string "Faun,\ndie Pinke\nFaust.\nÄltester\nder Top Vier.PAUSE_UNTIL_PRESS"


	.global str_anim_engine_elitefounders_2

	str_anim_engine_elitefounders_2:
		.string "Albus,\nder Weiße Ritter.\nBegründer der\nRevolution.PAUSE_UNTIL_PRESS"


	.global str_anim_engine_elitefounders_3

	str_anim_engine_elitefounders_3:
		.autostring 32 4 "Einer aber war ihnen allen überlegen DOTSPAUSE_UNTIL_PRESS"


	.global str_anim_engine_elitefounders_4

	str_anim_engine_elitefounders_4:
		.string "Lucius, der\nGraue\nDrachen-\njäger,\nder lange\nunbesiegt\nwar\nDOTSPAUSE_UNTIL_PRESS"


	.global str_anim_engine_elitefounders_5

	str_anim_engine_elitefounders_5:
		.string "Der einst\n stärkste\n Trainer\n Thetos,\n der\n ehemalige\n DOTS DOTS \n Champion!PAUSE_UNTIL_PRESS"


	.global str_anim_engine_elitefounders_6

	str_anim_engine_elitefounders_6:
		.string "Sie gründeten in Theto die\nPokémon-Liga und brachten\pder Region lange Jahre des\nFriedens DOTS DOTS DOTS\pEhe sie ihren Differenzen nicht\nlänger beiligen konnten.\pUnd schließlich gingen alle\ndrei ihrer Wege DOTSPAUSE_UNTIL_PRESS"
.elseif LANG_EN
.endif


