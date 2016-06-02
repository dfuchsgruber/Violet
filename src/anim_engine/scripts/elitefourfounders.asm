.include "anim_engine.s"

.global elite_four_founders

.equ dstring1, 0x89279FB

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
    bg_scroll_reset
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

frame 358
    text_init 0x8000 0 4 15 30 4 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL dstring1 0 0x10
    endframe

frame 800
    text_event 0x8001 EVENT_PARAGRAPH
    endframe

frame 1279
    text_event 0x8001 EVENT_ENDTEXT
    endframe

frame 1280
    text_clear 0x8000
    fadescreen 0 0 16 32 0 12
    endframe

frame 1312
    sound 6
    bg_scroll 1 0 256 0
    bg_override 1 gfx_faunfrontalMap 0x1000 0 COPYMAP
    loadpal gfx_faunfrontalPal 16 32 UNCOMP RESTORE
    fadescreen 0 16 16 32 16 0
    bg_scroll 1 32 180 0
    endframe

frame 1344
    bg_scroll 1 400 8 0
    text_init 0x8000 0 2 5 16 12 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL 0x88F6D3C 0 0x10
    endframe

frame 1799
    text_event 0x8001 EVENT_ENDTEXT
    endframe

frame 1800
    text_clear 0x8000
    bg_scroll 1 32 0xFF38 0
    fadescreen 0 16 16 32 0 16
    endframe

frame 1833
    sound 6
    set_io_to_val 194 0x14
    bg_override 1 gfx_albusfrontalTiles 0x3000 0 COPYSET
    bg_override 1 gfx_albusfrontalMap 0x1000 0 COPYMAP
    loadpal gfx_albusfrontalPal 16 32 UNCOMP RESTORE
    fadescreen 0 16 16 32 16 0
    bg_scroll 1 32 0xFF4C 0
    endframe

frame 1866
    bg_scroll 1 400 0xFFF8 0
    text_init 0x8000 0 16 5 16 12 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL 0x8927A7C 0 0x10
    endframe

frame 2299
    text_event 0x8001 EVENT_ENDTEXT
    endframe

frame 2300
    text_clear 0x8000
    bg_scroll 1 32 190 0
    fadescreen 0 16 16 32 0 16
    endframe

frame 2400
    text_init 0x8000 0 6 5 20 4 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL 0x887F382 0 0x10
    endframe


frame 2699
    text_clear 0x8000
    set_io_to_val 256 0x14
    bg_override 1 gfx_luciusfrontalTiles 0x3000 0 COPYSET
    bg_override 1 gfx_luciusfrontalMap 0x1000 0 COPYMAP
    loadpal gfx_luciusfrontalPal 16 32 UNCOMP RESTORE
    endframe

frame 2700
    sound 6
    fadescreen 0 16 16 32 16 0
    set_io_to_val 0 0x14
    bg_scroll 1 999 0 0xFFeC
    endframe

frame 2740
    text_init 0x8000 0 2 3 10 14 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL 0x8927B71 0 0x10
    endframe


frame 3100
    text_init 0x8002 0 22 3 10 14 14 200
    text_render 0x8003 0x8002 4 2 0 0 0 0 fmap DISPLAYALL 0x8927C34 0 0x10
    endframe

frame 3699
    text_event 0x8001 EVENT_ENDTEXT
    text_event 0x8003 EVENT_ENDTEXT
    endframe

frame 3700
    text_clear 0x8000
    text_clear 0x8000
    bg_scroll 1 32 0xFF00 0
    fadescreen 0 16 16 32 0 16
    endframe

frame 3750
    fadescreen 0 0 16 32 12 0
    endframe

frame 3800
    text_init 0x8000 0 4 15 30 4 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL 0x8927C88 0 0x10
    endframe

frame 4150
    text_event 0x8001 EVENT_PARAGRAPH
    endframe

frame 4500
    text_event 0x8001 EVENT_PARAGRAPH
    endframe

frame 4800
    text_event 0x8001 EVENT_PARAGRAPH
    endframe


frame 5100
    mapreload
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
    
