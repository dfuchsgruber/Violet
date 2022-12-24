.include "anim_engine.s"
.include "songs.s"
.include "species.s"

.global ae_script_intro

ae_script_intro:
    @fadescreen 0 0 512 128 16 8
    @pause 200
    fadescreen 0 0 512 128 8 16
    pause 128
    song MUS_SPIELHALLE_VERSION_3 0
    maintain
    pause 1
    oam_reset
    bg_override 1 gfx_intro_spaceTiles 0x2000 0 COPYSET
    bg_override 1 gfx_intro_spaceMap 0x800 0 COPYMAP
    loadpal gfx_intro_spacePal 0 32 UNCOMP RESTORE
    loadpal tbox_palette_transparent, 14 * 16, 32, COPY, RESTORE
    pause 1
    set_io_to_val 0 0x14
    set_io_to_val 0 0x16
    set_io_to_val 0 0x18
    set_io_to_val 0 0x1A
    set_io_to_val 0 0x1C
    set_io_to_val 0 0x1E
    fadescreen 0 0 512 16 16 0
    pause 10
    text_init 0x8000 0 6 2 18 8 14 4
    tbox_and_interrupt box_idx=0x8000 font=2 x=0 y=0 letter_spacing=0 line_spacing=0 font_colormap=fmap speed=TBOX_SPEED_FROM_SETTINGS text=str_intro_0
    //text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL str_intro_0 0 0x10    
    pause 1
    text_clear 0x8000
    obj_vram_load graphic_intro_meteor
    load_obj_pal 0xADE3 gfx_intro_meteorPal UNCOMP FORCE
    oam_new oam_template_intro_meteor 130 170 0 0x8002
    sound 158
    pause 64
    sound 171
    fadescreen 0x7FFF 0 512 2 0 16
    pause 6
    fadescreen 0x7FFF 0 512 4 16 0
    oam_despawn 0x8002
    spawn_big_cb anim_intro_earthquake 0 3
    .hword 0, 4, 0
    pause 64
    text_init 0x8000 0 6 2 19 8 14 4
    tbox_and_interrupt box_idx=0x8000 font=2 x=0 y=0 letter_spacing=0 line_spacing=0 font_colormap=fmap speed=TBOX_SPEED_FROM_SETTINGS text=str_intro_1
    pause 1
    pause 32
    fadescreen 0 0 512 16 0 16
    pause 16
    text_clear 0x8001
    pause 1
    bg_reset 0
    bg_setup 0 bgcnfgs 4
    bg_sync_and_show 0
    bg_sync_and_show 1
    bg_sync_and_show 2
    bg_sync_and_show 3
    bg_sync
    bg_vmap_init 0 0x800
    bg_vmap_init 1 0xC00
    bg_vmap_init 2 0x800
    bg_vmap_init 3 0x800
    pause 1
    bg_override 1 gfx_intro_beamTiles 0x1000 0 COPYSET
    loadpal gfx_intro_beamPal 16 32 UNCOMP RESTORE
    bg_override 2 gfx_intro_waves_backTiles 0x1000 0 COPYSET
    bg_override 2 gfx_intro_waves_backMap 0x800 0 COPYMAP
    loadpal gfx_intro_waves_backPal 0 32 UNCOMP RESTORE
    bg_override 3 gfx_intro_cloudsTiles 0x2000 0 COPYSET
    bg_override 3 gfx_intro_cloudsMap 0x800 0 COPYMAP
    loadpal gfx_intro_cloudsPal 32 32 UNCOMP RESTORE
    pause 1
    spawn_big_cb anim_intro_waves_back_scroll 0 1
    .hword 0
    load_obj_pal 0xADE8 gfx_intro_wavesPal UNCOMP RESTORE
    load_obj_pal 0xADE9 gfx_intro_waves_backPal UNCOMP RESTORE
    obj_vram_load graphic_intro_waves
    oam_new oam_template_intro_waves_front 32 128 0 0x8002
    oam_new oam_template_intro_waves_front 160 128 0 0x8003
    oam_new oam_template_intro_waves_front 288 128 0 0x8004
    sound 76
    pause 1
    fadescreen 0 0 512 16 16 0
    pause 16
    sound 81
    fadescreen 0x7FFF 0 512 2 0 16
    pause 8
    fadescreen 0x7FFF 0 512 6 16 0
    pause 3 * 64
    sound 80
    fadescreen 0x7FFF 0x0 512 2 0 16
    pause 8
    fadescreen 0x7FFF 0 512 6 16 0
    pause 64
    sound 206
    set_io_to_val 0xFFB0 0x16
    set_io_to_val 0x1F3F 0x48 //WININ all into WIN0 and enable FX;
    set_io_to_val 0x3F43 0x50 //BG0, BG1 in 1st and other in 2nd
    set_io_to_val 0x0602 0x52 //coefficients
    bg_override 1 gfx_intro_beamMap 0x800 0 COPYMAP
    pause 8
    set_io_to_val 0xFFC4 0x16
    pause 8
    set_io_to_val 0xFFD8 0x16
    pause 8
    set_io_to_val 0xFFEC 0x16
    set_io_to_val 0x0604 0x52 //coefficients
    pause 8
    set_io_to_val 0 0x16
    set_io_to_val 0x0607 0x52 //coefficients
    pause 8
    set_io_to_val 0x0608 0x52 //coefficients
    pause 8
    set_io_to_val 0x060A 0x52 //coefficients
    pause 8
    set_io_to_val 0x060C 0x52 //coefficients
    pause 64
    obj_vram_load graphic_intro_deoxys_head
    obj_vram_load graphic_intro_deoxys_body
    obj_vram_load graphic_intro_deoxys_bottom
    obj_vram_load graphic_intro_deoxys_arm
    load_obj_pal 0xADE4 gfx_intro_deoxys_headPal UNCOMP FORCE
    pause 1
    fade_obj_pal 0 0xADE4 0 16 1 0 16
    oam_new oam_template_intro_deoxys_arm_right 92 202 0 0x8005
    oam_new oam_template_intro_deoxys_arm_left 149 202 1 0x8006
    oam_new oam_template_intro_deoxys_head 120 160 2 0x8002
    oam_new oam_template_intro_deoxys_body 121 176 3 0x8003
    oam_new oam_template_intro_deoxys_bottom 121 212 4 0x8004
    oam_move 0x8002 560 0 0xFF74 //-140
    oam_move 0x8003 560 0 0xFF74 //-140
    oam_move 0x8004 560 0 0xFF74 //-140
    oam_move 0x8005 560 0 0xFF74 //-140
    oam_move 0x8006 560 0 0xFF74 //-140
    pause 128
    sound 81
    pause 3 * 64
    sound 80
    pause 64
    text_init 0x8000 0 0 2 30 6 14 4
    tbox_flush 0x8000 0x11
    tbox_and_interrupt box_idx=0x8000 font=2 x=32 y=8 letter_spacing=0 line_spacing=0 font_colormap=fmap speed=TBOX_SPEED_FROM_SETTINGS text=str_intro_2
    // text_render 0x8001 0x8000 4 2 32 8 0 0 fmap DISPLAYALL str_intro_2 0 0x10    
    pause 1
    text_clear 0x8001
    pause 64
    cry POKEMON_DEOXYS 0
    fade_obj_pal 0 0xADE4 15 1 64 16 0
    pause 64
    pal_restore_force_current 0 512
    pause 64
    oam_move 0x8004 32 0 0xFFF8 //-8
    oam_move 0x8003 32 0 4
    oam_move 0x8005 32 0 4
    oam_move 0x8006 32 0 4
    oam_move 0x8002 32 0 12
    pause 64
    sound 80
    fadescreen 0x7FFF 0x0 512 2 0 16
    pause 10
    fadescreen 0x7FFF 0 512 6 16 0
    pause 128
    cry POKEMON_DEOXYS 0
    pause 10
    sound 80
    fadescreen 0x7FFF 0x0 512 2 0 16
    pause 10
    fadescreen 0x7FFF 0 512 6 16 0
    pause 64
    text_init 0x8000 0 0 2 30 6 14 4
    tbox_flush 0x8000 0x11
    tbox_and_interrupt box_idx=0x8000 font=2 x=32 y=8 letter_spacing=0 line_spacing=0 font_colormap=fmap speed=TBOX_SPEED_FROM_SETTINGS text=str_intro_3
    //text_render 0x8001 0x8000 4 2 32 8 0 0 fmap DISPLAYALL str_intro_3 0 0x10    
    pause 1
    text_clear 0x8001
    pause 32
    mapreload
    script_notify
    end
    endframe



.align 4
fmap:
    fontmap 0 2 1


.align 4
bgcnfgs:
    bg_setup_cnfg 0 2 0x1C 0 0 0
    bg_setup_cnfg 1 1 0x1D 0 0 1
    bg_setup_cnfg 2 3 0x1E 0 0 2
    bg_setup_cnfg 3 0 0x1F 0 0 3


.ifdef LANG_GER
    str_intro_0:
        .string "Kannst du mich hören?\nDOTS DOTS DOTS\nLass es mich dir zeigen!\nEs kam von weit herDOTSPAUSE_UNTIL_PRESS"
    str_intro_1:
        .string "Mit einem Meteoriten fiel\nes herab auf die Erde mit\ndem Ziel, Lebensraum\nzu finden.PAUSE_UNTIL_PRESS"
    str_intro_2:
        .string "Es war bereit, Mensch und\nPokémon zu vernichten.PAUSE_UNTIL_PRESS"
    str_intro_3:
        .string "Und bald wird diese Gefahr\nwiederkehrenDOTSPAUSE_UNTIL_PRESS"
        
.elseif LANG_GER
    str_intro_0:
        .string "Can you hear me?\nDOTS DOTS DOTS\pLet me show it to you!\pIt came from far awayDOTS DOTS DOTS"
    str_intro_1:
        .string "With a meteorite it fell\ndown to earth and wanted\nto find a place to live.PAUSE_UNTIL_PRESS"
    str_intro_2:
        .string "It was willing to destroy\nboth men and Pokémon."
    str_intro_3:
        .string "And soon this danger will\nreturn once againDOTSPAUSE_UNTIL_PRESS"
.endif        