.include "anim_engine.s"
.include "std.s"

.global ae_script_aktania_meteor
.global ae_script_aktania_beam
.global ae_script_aktania_sky

ae_script_aktania_meteor:
frame 0
    pal_restore_snapshot 1
    fadescreen 0 0 512 16 0 16
    endframe


frame 28
    setflag MAP_BGN_AUTO_ALIGN_OFF 1
    setflag TILESET_ANIM_DISABLE 1
    endframe
    

frame 29
    song MUS_SPIELHALLE_VERSION_3 0
    oam_reset
    //callback_reset
    maintain
    bg_override 1 gfx_intro_spaceTiles 0x2000 0 COPYSET
    bg_override 1 gfx_intro_spaceMap 0x800 0 COPYMAP
    loadpal gfx_intro_spacePal 0 32 UNCOMP RESTORE
    setflag MAP_BGN_AUTO_ALIGN_OFF 1
    endframe

frame 30
    set_io_to_val 0 0x14
    set_io_to_val 0 0x16
    set_io_to_val 0 0x18
    set_io_to_val 0 0x1A
    set_io_to_val 0 0x1C
    set_io_to_val 0 0x1E
    fadescreen 0 0 512 16 16 0
    endframe


//frame 1001
frame 50
    obj_vram_load graphic_intro_meteor
    load_obj_pal 0xADE3 gfx_intro_meteorPal UNCOMP FORCE
    oam_new oam_template_intro_meteor 130 170 0 0x8002
    sound 158
    endframe

//frame 1065
frame 120
    sound 171
    fadescreen 0x7FFF 0 512 2 0 16
    endframe
    
//frame 1076
frame 132
    fadescreen 0x7FFF 0 512 4 16 0
    oam_despawn 0x8002
    spawn_big_cb anim_intro_earthquake 0 3
    .hword 0, 4, 0
    endframe

frame 182
    fadescreen 0 0 512 16 0 16
    endframe


//frame 1797
frame 199
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
    bg_override 1 gfx_intro_beamTiles 0x1000 0 COPYSET
    loadpal gfx_intro_beamPal 16 32 UNCOMP RESTORE
    bg_override 2 gfx_intro_waves_backTiles 0x1000 0 COPYSET
    bg_override 2 gfx_intro_waves_backMap 0x800 0 COPYMAP
    loadpal gfx_intro_waves_backPal 0 32 UNCOMP RESTORE
    bg_override 3 gfx_intro_cloudsTiles 0x2000 0 COPYSET
    bg_override 3 gfx_intro_cloudsMap 0x800 0 COPYMAP
    loadpal gfx_intro_cloudsPal 32 32 UNCOMP RESTORE
    spawn_big_cb anim_intro_waves_back_scroll 0 1
    .hword 0
    

    load_obj_pal 0xADE8 gfx_intro_wavesPal UNCOMP RESTORE
    load_obj_pal 0xADE9 gfx_intro_waves_backPal UNCOMP RESTORE
    obj_vram_load graphic_intro_waves
    oam_new oam_template_intro_waves_front 32 128 0 0x8002
    oam_new oam_template_intro_waves_front 160 128 0 0x8003
    oam_new oam_template_intro_waves_front 288 128 0 0x8004
    sound 76
    endframe

//frame 1798
frame 200
    fadescreen 0 0 512 16 16 0
    endframe


frame 300
    sound 81
    fadescreen 0x7FFF 0 512 2 0 16
    endframe

//frame 1910
frame 310
    fadescreen 0x7FFF 0 512 6 16 0
    endframe

//frame 2100
frame 500
    sound 80
    fadescreen 0x7FFF 0x0 512 2 0 16
    endframe

//frame 2110
frame 510
    fadescreen 0x7FFF 0 512 6 16 0
    endframe

//frame 2260
frame 560
    sound 206
    set_io_to_val 0xFFB0 0x16
    set_io_to_val 0x1F3F 0x48 //WININ all into WIN0 and enable FX;
    set_io_to_val 0x3F43 0x50 //BG0, BG1 in 1st and other in 2nd
    set_io_to_val 0x0602 0x52 //coefficients
    bg_override 1 gfx_intro_beamMap 0x800 0 COPYMAP
    endframe

//frame 2268
frame 568
    set_io_to_val 0xFFC4 0x16
    endframe

frame 576
    set_io_to_val 0xFFD8 0x16
    endframe

frame 584
    set_io_to_val 0xFFEC 0x16
    set_io_to_val 0x0604 0x52 //coefficients
    endframe

frame 592
    set_io_to_val 0 0x16
    set_io_to_val 0x0607 0x52 //coefficients
    endframe

frame 600
    set_io_to_val 0x0608 0x52 //coefficients
    endframe

frame 608
    set_io_to_val 0x060A 0x52 //coefficients
    endframe

frame 616
    set_io_to_val 0x060C 0x52 //coefficients
    endframe
    
frame 680
    obj_vram_load graphic_intro_deoxys_head
    obj_vram_load graphic_intro_deoxys_body
    obj_vram_load graphic_intro_deoxys_bottom
    obj_vram_load graphic_intro_deoxys_arm
    load_obj_pal 0xADE4 gfx_intro_deoxys_headPal UNCOMP FORCE
    endframe

frame 681
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
    endframe
    
frame 740
    sound 81
    endframe

frame 1480
    sound 80
    endframe

frame 1600
//frame 3880
    cry POKEMON_DEOXYS 0
    fade_obj_pal 0 0xADE4 15 1 64 16 8
    endframe



frame 1700
    fade_obj_pal 0 0xADE4 0 15 32 16 10
    oam_move 0x8004 32 0 0xFFF8 //-8
    oam_move 0x8003 32 0 4
    oam_move 0x8005 32 0 4
    oam_move 0x8006 32 0 4
    oam_move 0x8002 32 0 12
    endframe

frame 1750
    pal_restore_force_current 0 512
    endframe


frame 1800
    sound 80
    fadescreen 0x7FFF 0x0 512 2 0 16
    endframe

frame 1850
    fadescreen 0x7FFF 0 512 6 16 0
    endframe

frame 1900
    cry POKEMON_DEOXYS 0
    endframe

frame 1950
    sound 80
    fadescreen 0x7FFF 0x0 512 2 0 16
    endframe

frame 1970
    fadescreen 0x7FFF 0 512 6 16 0
    endframe

frame 2099
    setflag MAP_BGN_AUTO_ALIGN_OFF 0
    setflag TILESET_ANIM_DISABLE 0 
    endframe

frame 2100
    pal_restore_snapshot 0
    mapreload
    script_notify
    end
    endframe



ae_script_aktania_beam:
frame 0
    pal_restore_snapshot 1
    fadescreen 0 0 512 16 0 16
    endframe


frame 28
    setflag MAP_BGN_AUTO_ALIGN_OFF 1
    setflag TILESET_ANIM_DISABLE 1
    endframe
    

frame 29
    oam_reset
    //callback_reset
    maintain
    bg_reset 0
    bg_setup 0 bgcnfgs2 3
    bg_sync_and_show 0
    bg_sync_and_show 1
    bg_sync_and_show 2
    bg_sync
    bg_vmap_init 0 0x800
    bg_vmap_init 1 0x800
    bg_vmap_init 2 0x1000
    set_io_to_val 0 0x10
    set_io_to_val 0 0x12
    set_io_to_val 0 0x14
    set_io_to_val 0 0x16
    set_io_to_val 0 0x18
    set_io_to_val 0x28 0x1C
    bg_override 2 gfx_anim_dark_aktania_back_0Tiles 0x6000 0 COPYSET
    bg_override 2 gfx_anim_dark_aktania_back_0Map 0x1000 0 COPYMAP
    bg_override 1 gfx_anim_dark_aktania_waves_backTiles 0x1000 0 COPYSET
    bg_override 1 gfx_anim_dark_aktania_waves_backMap 0x800 0 COPYMAP
    bg_override 0 gfx_anim_dark_aktania_waves_frontTiles 0x1000 0 COPYSET
    bg_override 0 gfx_anim_dark_aktania_waves_frontMap 0x800 0 COPYMAP
    loadpal gfx_anim_dark_aktania_back_0Pal 0 32 UNCOMP RESTORE
    loadpal gfx_anim_dark_aktania_waves_backPal 16 32 UNCOMP RESTORE
    endframe

frame 30
    bg_scroll 0 1000 0xF830 0
    bg_scroll 1 1000 0xFC18 0
    fadescreen 0 0 512 16 16 0
    endframe

frame 100
    bg_scroll 0 0x28 0 0xFFD8
    bg_scroll 1 0x28 0 0xFFD8
    bg_scroll 2 0x28 0 0xFFD8
    endframe

frame 160
    sound 100
    endframe

frame 168
    bg_override 2 gfx_anim_dark_aktania_back_1Tiles 0x6000 0 COPYSET
    bg_override 2 gfx_anim_dark_aktania_back_1Map 0x1000 0 COPYMAP
    endframe

frame 176
    bg_override 2 gfx_anim_dark_aktania_back_2Tiles 0x6000 0 COPYSET
    bg_override 2 gfx_anim_dark_aktania_back_2Map 0x1000 0 COPYMAP
    endframe
    
frame 184
    bg_override 2 gfx_anim_dark_aktania_back_3Tiles 0x6000 0 COPYSET
    bg_override 2 gfx_anim_dark_aktania_back_3Map 0x1000 0 COPYMAP
    endframe

frame 260
    setflag MAP_BGN_AUTO_ALIGN_OFF 0
    setflag TILESET_ANIM_DISABLE 0
    pal_restore_snapshot 0
    mapreload
    script_notify
    end
    endframe
    

ae_script_aktania_sky:
frame 0
    pal_restore_snapshot 1
    fadescreen 0 0 512 16 0 16
    endframe


frame 28
    setflag MAP_BGN_AUTO_ALIGN_OFF 1
    setflag TILESET_ANIM_DISABLE 1
    endframe
    

frame 29
    oam_reset
    callback_reset
    maintain
    bg_reset 0
    bg_setup 0 bgcnfgs2 3
    bg_sync_and_show 0
    bg_sync_and_show 1
    bg_sync_and_show 2
    bg_sync
    bg_vmap_init 0 0x800
    bg_vmap_init 1 0x800
    bg_vmap_init 2 0x800
    set_io_to_val 0 0x10
    set_io_to_val 0 0x12
    set_io_to_val 0 0x14
    set_io_to_val 0 0x16
    set_io_to_val 0 0x18
    set_io_to_val 0 0x1A
    set_io_to_val 0 0x1C
    set_io_to_val 0 0x1E
    bg_override 2 gfx_anim_aktania_sky_bg2Tiles 0x6000 0 COPYSET
    bg_override 2 gfx_anim_aktania_sky_bg2Map 0x800 0 COPYMAP
    bg_override 1 gfx_anim_aktania_sky_bg1Tiles 0x2000 0 COPYSET
    bg_override 1 gfx_anim_aktania_sky_bg1Map 0x800 0 COPYMAP
    bg_override 0 gfx_anim_aktania_sky_bg0Tiles 0x2000 0 COPYSET
    bg_override 0 gfx_anim_aktania_sky_bg0Map 0x800 0 COPYMAP
    loadpal gfx_anim_aktania_sky_bg0Pal 0 32 UNCOMP RESTORE
    obj_vram_load pokemon_frontsprites + 8 * POKEMON_REGIROCK
    obj_vram_load pokemon_frontsprites + 8 * POKEMON_REGICE
    obj_vram_load pokemon_frontsprites + 8 * POKEMON_REGISTEEL
    obj_vram_load pokemon_backsprites + 8 * POKEMON_DEOXYS
    load_obj_pal_from_struct pokemon_pals + 8 * POKEMON_REGIROCK UNCOMP RESTORE
    load_obj_pal_from_struct pokemon_pals + 8 * POKEMON_REGICE UNCOMP RESTORE
    load_obj_pal_from_struct pokemon_pals + 8 * POKEMON_REGISTEEL UNCOMP RESTORE
    load_obj_pal_from_struct pokemon_pals + 8 * POKEMON_DEOXYS UNCOMP RESTORE
    oam_new oam_template_aktania_sky_regirock 160 78 0 0x8000
    oam_new oam_template_aktania_sky_regice 200 78 0 0x8001
    oam_new oam_template_aktania_sky_registeel 180 78 1 0x8002
    oam_new oam_template_aktania_sky_deoxys 80 116 0 0x8003
    oam_move_trace 0x8000 9999 SINE
        .byte YAXIS
        .hword 1, 64
    oam_move_trace 0x8003 9999 SINE
        .byte YAXIS
        .hword 2, 40
    oam_move 0x8000 128 24 0
    oam_move 0x8001 128 24 0
    oam_move 0x8002 128 24 0
    oam_move 0x8003 128 0xFFE0 0

    endframe


frame 30
    bg_scroll 2 128 0xFFF0 0
    bg_scroll 1 3000 1000 0
    bg_scroll 0 1000 1000 0
    fadescreen 0 0 512 16 16 0
    endframe

frame 32
    oam_move_trace 0x8001 9999 SINE
        .byte YAXIS
        .hword 1, 64
    oam_move_trace 0x8002 9999 SINE
        .byte YAXIS
        .hword 1, 64
    endframe

//frame 2100
frame 80
    sound 80
    fadescreen 0x7FFF 0x0 512 2 0 16
    endframe

//frame 2110
frame 90
    fadescreen 0x7FFF 0 512 6 16 0
    endframe

//frame 2100
frame 210
    sound 80
    fadescreen 0x7FFF 0x0 512 2 0 16
    endframe

//frame 2110
frame 220
    fadescreen 0x7FFF 0 512 6 16 0
    endframe

frame 260
    setflag MAP_BGN_AUTO_ALIGN_OFF 0
    setflag TILESET_ANIM_DISABLE 0
    pal_restore_snapshot 0
    mapreload
    script_notify
    end
    endframe
    




.align 4
bgcnfgs:
    bg_setup_cnfg 0 2 0x1C 0 0 0
    bg_setup_cnfg 1 1 0x1D 0 0 1
    bg_setup_cnfg 2 3 0x1E 0 0 2
    bg_setup_cnfg 3 0 0x1F 0 0 3


.align 4
bgcnfgs2:
    bg_setup_cnfg 0 3 0x1C 0 0 0
    bg_setup_cnfg 1 2 0x1D 0 0 1
    bg_setup_cnfg 2 0 0x1E 0 0 2
