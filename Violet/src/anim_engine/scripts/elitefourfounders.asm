.include "anim_engine.s"

.global elite_four_founders



.align 4
elite_four_founders:

frame 0
    fadescreen 0 0 512 128 0 16
    endframe

frame 128
    maintain
    @dma3_reset
    endframe

frame 129
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
    endframe

frame 130
    fadescreen 0 0 512 128 16 0
    endframe

frame 300
    text_init 0x8000 0 4 15 30 4 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL str_anim_engine_elitefounders_0 0 0x10
    endframe

frame 500
    text_event 0x8001 EVENT_PARAGRAPH
    endframe

frame 700
    text_event 0x8001 EVENT_ENDTEXT
    endframe

frame 701
    text_clear 0x8000
    fadescreen 0 0 16 32 0 12
    endframe

frame 764
    sound 6
    bg_scroll 1 0 256 0
    bg_override 1 gfx_faunfrontalMap 0x1000 0 COPYMAP
    loadpal gfx_faunfrontalPal 16 32 UNCOMP RESTORE
    fadescreen 0 16 16 32 16 0
    bg_scroll 1 32 180 0
    endframe

frame 786
    bg_scroll 1 400 8 0
    text_init 0x8000 0 2 5 16 12 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL str_anim_engine_elitefounders_1 0 0x10
    endframe

frame 999
    text_event 0x8001 EVENT_ENDTEXT
    endframe

frame 1000
    text_clear 0x8000
    bg_scroll 1 32 0xFF38 0
    fadescreen 0 16 16 32 0 16
    endframe

frame 1064
    sound 6
    set_io_to_val 194 0x14
    bg_override 1 gfx_albusfrontalTiles 0x3000 0 COPYSET
    bg_override 1 gfx_albusfrontalMap 0x1000 0 COPYMAP
    loadpal gfx_albusfrontalPal 16 32 UNCOMP RESTORE
    fadescreen 0 16 16 32 16 0
    bg_scroll 1 32 0xFF4C 0
    endframe

frame 1086
    bg_scroll 1 400 0xFFF8 0
    text_init 0x8000 0 16 5 16 12 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL str_anim_engine_elitefounders_2 0 0x10
    endframe

frame 1299
    text_event 0x8001 EVENT_ENDTEXT
    endframe

frame 1300
    text_clear 0x8000
    bg_scroll 1 32 190 0
    fadescreen 0 16 16 32 0 16
    endframe

frame 1364
    text_init 0x8000 0 6 5 20 4 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL str_anim_engine_elitefounders_3 0 0x10
    endframe


frame 1499
    text_clear 0x8000
    set_io_to_val 256 0x14
    bg_override 1 gfx_luciusfrontalTiles 0x3000 0 COPYSET
    bg_override 1 gfx_luciusfrontalMap 0x1000 0 COPYMAP
    loadpal gfx_luciusfrontalPal 16 32 UNCOMP RESTORE
    endframe

frame 1500
    sound 6
    fadescreen 0 16 16 32 16 0
    set_io_to_val 0 0x14
    bg_scroll 1 999 0 0xFFeC
    endframe

frame 1564
    text_init 0x8000 0 2 3 10 14 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL str_anim_engine_elitefounders_4 0 0x10
    endframe


frame 1800
    text_init 0x8002 0 22 3 10 14 14 200
    text_render 0x8003 0x8002 4 2 0 0 0 0 fmap DISPLAYALL str_anim_engine_elitefounders_5 0 0x10
    endframe

frame 2100
    text_event 0x8001 EVENT_ENDTEXT
    text_event 0x8003 EVENT_ENDTEXT
    endframe

frame 2164
    text_clear 0x8000
    text_clear 0x8000
    bg_scroll 1 32 0xFF00 0
    fadescreen 0 16 16 32 0 16
    endframe

frame 2200
    fadescreen 0 0 16 32 12 0
    endframe

frame 2264
    text_init 0x8000 0 4 15 30 4 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL str_anim_engine_elitefounders_6 0 0x10
    endframe

frame 2400
    text_event 0x8001 EVENT_PARAGRAPH
    endframe

frame 2600
    text_event 0x8001 EVENT_PARAGRAPH
    endframe

frame 2800
    text_event 0x8001 EVENT_PARAGRAPH
    endframe


frame 2900
    mapreload
    script_notify
    end
    endframe


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
		.autostring 32 2 "Vor vielen Jahren kamen drei Trainer nach Theto DOTS\pIhre Ankunft läutete eine neue Ära ein DOTS"


	.global str_anim_engine_elitefounders_1

	str_anim_engine_elitefounders_1:
		.string "Faun,\ndie Pinke\nFaust.\nÄltester\nder Top Vier."


	.global str_anim_engine_elitefounders_2

	str_anim_engine_elitefounders_2:
		.string "Albus,\nder Weiße Ritter.\nBegründer der\nRevolution."


	.global str_anim_engine_elitefounders_3

	str_anim_engine_elitefounders_3:
		.autostring 32 4 "Einer aber war ihnen allen überlegen DOTS"


	.global str_anim_engine_elitefounders_4

	str_anim_engine_elitefounders_4:
		.string "Lucius, der\nGraue\nDrachen-\njäger,\nder lange\nunbesiegt\nwar\nDOTS"


	.global str_anim_engine_elitefounders_5

	str_anim_engine_elitefounders_5:
		.string "Der einst\n stärkste\n Trainer\n Thetos,\n der\n ehemalige\n DOTS DOTS \n Champion!"


	.global str_anim_engine_elitefounders_6

	str_anim_engine_elitefounders_6:
		.string "Sie gründeten in Theto die\nPokémon-Liga und brachten\pder Region lange Jahre des\nFriedens DOTS DOTS DOTS\pEhe sie ihren Differenzen nicht\nlänger beiligen konnten.\pUnd schließlich gingen alle\ndrei ihrer Wege DOTS"
.elseif LANG_EN
.endif


